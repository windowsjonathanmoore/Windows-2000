/*++

Copyright (c) 1990-2000 Microsoft Corporation All Rights Reserved

Module Name:

    WMI.C

Abstract:

    This module handle all the WMI Irps.

Environment:

    Kernel mode

Revision History:

    Eliyas Yakub Oct 26, 1998


--*/


#include "toaster.h"
#include <initguid.h>
#include <wdmguid.h>
#include <wmistr.h>
#include <wmilib.h>

PCHAR
WMIMinorFunctionString (
    UCHAR MinorFunction
);

#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE,ToasterWmiRegistration)
#pragma alloc_text(PAGE,ToasterWmiDeRegistration)
#pragma alloc_text(PAGE,ToasterSystemControl)
#pragma alloc_text(PAGE,ToasterSetWmiDataItem)
#pragma alloc_text(PAGE,ToasterSetWmiDataBlock)
#pragma alloc_text(PAGE,ToasterQueryWmiDataBlock)
#pragma alloc_text(PAGE,ToasterQueryWmiRegInfo)
#endif

#define MOFRESOURCENAME L"MofResourceName"

#define WMI_TOASTER_DRIVER_INFORMATION 0

DEFINE_GUID (TOASTER_WMI_STD_DATA_GUID, 
0xBBA21300, 0x6DD3, 0x11d2, 0xB8, 0x44, 0x00, 0xC0, 0x4F, 0xAD, 0x51, 0x71);

WMIGUIDREGINFO ToasterWmiGuidList[1] =
{
    {
        &TOASTER_WMI_STD_DATA_GUID, 1, 0 // driver information
    }
};

//
// Global debug error level 
//

extern ULONG DebugLevel;

NTSTATUS
ToasterWmiRegistration(
    PFDO_DATA               FdoData
)
/*++
Routine Description

    Registers with WMI as a data provider for this
    instance of the device

--*/
{
    NTSTATUS status;
    
    PAGED_CODE();

    FdoData->WmiLibInfo.GuidCount = sizeof (ToasterWmiGuidList) /
                                 sizeof (WMIGUIDREGINFO);
    ASSERT (1 == FdoData->WmiLibInfo.GuidCount);
    FdoData->WmiLibInfo.GuidList = ToasterWmiGuidList;
    FdoData->WmiLibInfo.QueryWmiRegInfo = ToasterQueryWmiRegInfo;
    FdoData->WmiLibInfo.QueryWmiDataBlock = ToasterQueryWmiDataBlock;
    FdoData->WmiLibInfo.SetWmiDataBlock = ToasterSetWmiDataBlock;
    FdoData->WmiLibInfo.SetWmiDataItem = ToasterSetWmiDataItem;
    FdoData->WmiLibInfo.ExecuteWmiMethod = NULL;
    FdoData->WmiLibInfo.WmiFunctionControl = NULL;

    //
    // Register with WMI
    //
    
    status = IoWMIRegistrationControl(FdoData->Self,
                             WMIREG_ACTION_REGISTER
                             );

    //
    // Initialize the Std device data structure
    //
                    
    FdoData->StdDeviceData.ConnectorType = TOASTER_WMI_STD_USB;
    FdoData->StdDeviceData.Capacity = 2000;
    FdoData->StdDeviceData.ErrorCount = 0; 
    FdoData->StdDeviceData.Controls = 5;
    FdoData->StdDeviceData.DebugPrintLevel = DebugLevel;

    return status;
    
}

NTSTATUS
ToasterWmiDeRegistration(
    PFDO_DATA               FdoData
)
/*++
Routine Description

     Inform WMI to remove this DeviceObject from its 
     list of providers. This function also 
     decrements the reference count of the deviceobject.

--*/
{

    PAGED_CODE();

    return IoWMIRegistrationControl(FdoData->Self,
                                 WMIREG_ACTION_DEREGISTER
                                 );

}

NTSTATUS
ToasterSystemControl (
    IN  PDEVICE_OBJECT  DeviceObject,
    IN  PIRP            Irp
    )
/*++
Routine Description

    We have just received a System Control IRP.

    Assume that this is a WMI IRP and
    call into the WMI system library and let it handle this IRP for us.

--*/
{
    PFDO_DATA               fdoData;
    SYSCTL_IRP_DISPOSITION  disposition;
    NTSTATUS                status;
    PIO_STACK_LOCATION      stack;
    
    PAGED_CODE();

    stack = IoGetCurrentIrpStackLocation (Irp);

    ToasterDebugPrint((2, "%s\n", 
                WMIMinorFunctionString(stack->MinorFunction)));

    fdoData = (PFDO_DATA) DeviceObject->DeviceExtension;

    ToasterIoIncrement (fdoData);
    
    if (fdoData->DevicePnPState == Deleted) {
        Irp->IoStatus.Status = status = STATUS_DELETE_PENDING;
        IoCompleteRequest (Irp, IO_NO_INCREMENT);
        ToasterIoDecrement (fdoData);
        return status;
    }
    
    status = WmiSystemControl(&fdoData->WmiLibInfo, 
                                 DeviceObject, 
                                 Irp,
                                 &disposition);
    switch(disposition)
    {
        case IrpProcessed:
        {
            //
            // This irp has been processed and may be completed or pending.
            break;
        }
        
        case IrpNotCompleted:
        {
            //
            // This irp has not been completed, but has been fully processed.
            // we will complete it now
            IoCompleteRequest(Irp, IO_NO_INCREMENT);                
            break;
        }
        
        case IrpForward:
        case IrpNotWmi:
        {
            //
            // This irp is either not a WMI irp or is a WMI irp targeted
            // at a device lower in the stack.
            IoSkipCurrentIrpStackLocation (Irp);
            status = IoCallDriver (fdoData->NextLowerDriver, Irp);
            break;
        }
                                    
        default:
        {
            //
            // We really should never get here, but if we do just forward....
            ASSERT(FALSE);
            IoSkipCurrentIrpStackLocation (Irp);
            status = IoCallDriver (fdoData->NextLowerDriver, Irp);
            break;
        }        
    }

    ToasterIoDecrement(fdoData);

    return(status);
}

//
// WMI System Call back functions
//

NTSTATUS
ToasterSetWmiDataItem(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN ULONG GuidIndex,
    IN ULONG InstanceIndex,
    IN ULONG DataItemId,
    IN ULONG BufferSize,
    IN PUCHAR Buffer
    )
/*++

Routine Description:

    This routine is a callback into the driver to set for the contents of
    a data block. When the driver has finished filling the data block it
    must call WmiCompleteRequest to complete the irp. The driver can
    return STATUS_PENDING if the irp cannot be completed immediately.

Arguments:

    DeviceObject is the device whose data block is being queried

    Irp is the Irp that makes this request

    GuidIndex is the index into the list of guids provided when the
        device registered

    InstanceIndex is the index that denotes which instance of the data block
        is being queried.
            
    DataItemId has the id of the data item being set

    BufferSize has the size of the data item passed

    Buffer has the new values for the data item


Return Value:

    status

--*/
{
    PFDO_DATA    fdoData;
    NTSTATUS status;
    
    PAGED_CODE();

    ToasterDebugPrint ((3, "Entered ToasterSetWmiDataItem\n"));

    fdoData = (PFDO_DATA) DeviceObject->DeviceExtension;

    switch(GuidIndex) {
    
    case WMI_TOASTER_DRIVER_INFORMATION:
        if(DataItemId == 5)
        {
           DebugLevel = fdoData->StdDeviceData.DebugPrintLevel = 
                                    *((PULONG)Buffer);
           status = STATUS_SUCCESS;
        }
        else
            status = STATUS_WMI_READ_ONLY;
        break;

    default:

        status = STATUS_WMI_GUID_NOT_FOUND;
    }

    status = WmiCompleteRequest(  DeviceObject,
                                  Irp,
                                  status,
                                  0,
                                  IO_NO_INCREMENT);

    return status;
}

NTSTATUS
ToasterSetWmiDataBlock(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN ULONG GuidIndex,
    IN ULONG InstanceIndex,
    IN ULONG BufferSize,
    IN PUCHAR Buffer
    )
/*++

Routine Description:

    This routine is a callback into the driver to set the contents of
    a data block. When the driver has finished filling the data block it
    must call WmiCompleteRequest to complete the irp. The driver can
    return STATUS_PENDING if the irp cannot be completed immediately.

Arguments:

    DeviceObject is the device whose data block is being queried

    Irp is the Irp that makes this request

    GuidIndex is the index into the list of guids provided when the
        device registered

    InstanceIndex is the index that denotes which instance of the data block
        is being queried.
            
    BufferSize has the size of the data block passed

    Buffer has the new values for the data block


Return Value:

    status

--*/
{
    PFDO_DATA   fdoData;
    NTSTATUS status;

    PAGED_CODE();

    fdoData = (PFDO_DATA) DeviceObject->DeviceExtension;

    ToasterDebugPrint ((3, "Entered ToasterSetWmiDataBlock\n"));

    switch(GuidIndex) {
    case WMI_TOASTER_DRIVER_INFORMATION:

       //
       // We will update only writable elements.
       //
       
       DebugLevel = fdoData->StdDeviceData.DebugPrintLevel = 
                    ((PTOASTER_WMI_STD_DATA)Buffer)->DebugPrintLevel;
                    
       status = STATUS_SUCCESS;

        //status = STATUS_WMI_READ_ONLY;
        break;

    default:

        status = STATUS_WMI_GUID_NOT_FOUND;
    }

    status = WmiCompleteRequest(  DeviceObject,
                                  Irp,
                                  status,
                                  0,
                                  IO_NO_INCREMENT);

    return(status);
}

NTSTATUS
ToasterQueryWmiDataBlock(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN ULONG GuidIndex,
    IN ULONG InstanceIndex,
    IN ULONG InstanceCount,
    IN OUT PULONG InstanceLengthArray,
    IN ULONG OutBufferSize,
    OUT PUCHAR Buffer
    )
/*++

Routine Description:

    This routine is a callback into the driver to query for the contents of
    a data block. When the driver has finished filling the data block it
    must call WmiCompleteRequest to complete the irp. The driver can
    return STATUS_PENDING if the irp cannot be completed immediately.

Arguments:

    DeviceObject is the device whose data block is being queried

    Irp is the Irp that makes this request

    GuidIndex is the index into the list of guids provided when the
        device registered

    InstanceIndex is the index that denotes which instance of the data block
        is being queried.
            
    InstanceCount is the number of instances expected to be returned for
        the data block.
            
    InstanceLengthArray is a pointer to an array of ULONG that returns the 
        lengths of each instance of the data block. If this is NULL then
        there was not enough space in the output buffer to fulfill the request
        so the irp should be completed with the buffer needed.        
            
    BufferAvail on has the maximum size available to write the data
        block.

    Buffer on return is filled with the returned data block


Return Value:

    status

--*/
{
    PFDO_DATA               fdoData;    
    NTSTATUS    status;
    ULONG       size = 0;
    WCHAR       modelName[]=L"Aishverya\0\0";
    USHORT      modelNameLen = (wcslen(modelName) + 1) * sizeof(WCHAR);

    PAGED_CODE();

    ToasterDebugPrint ((3, "Entered ToasterQueryWmiDataBlock\n"));

    //
    // Only ever registers 1 instance per guid
    ASSERT((InstanceIndex == 0) &&
           (InstanceCount == 1));
    
    fdoData = (PFDO_DATA) DeviceObject->DeviceExtension;

    switch (GuidIndex) {
    case WMI_TOASTER_DRIVER_INFORMATION:

        size = sizeof (TOASTER_WMI_STD_DATA) + modelNameLen + sizeof(USHORT);
        if (OutBufferSize < size ) {
            status = STATUS_BUFFER_TOO_SMALL;
            break;
        }

        * (PTOASTER_WMI_STD_DATA) Buffer = fdoData->StdDeviceData;
        Buffer += sizeof (TOASTER_WMI_STD_DATA);
        *((PUSHORT)Buffer) = modelNameLen ;// put length of string ahead of string
        Buffer = (PUCHAR)Buffer + sizeof(USHORT);   // advance past string length
        RtlCopyBytes((PVOID)Buffer, (PVOID)modelName, modelNameLen);
        *InstanceLengthArray = size ;
        status = STATUS_SUCCESS;
        break;

    default:

        status = STATUS_WMI_GUID_NOT_FOUND;
    }

    status = WmiCompleteRequest(  DeviceObject,
                                  Irp,
                                  status,
                                  size,
                                  IO_NO_INCREMENT);

    return status;
}

NTSTATUS
ToasterQueryWmiRegInfo(
    IN PDEVICE_OBJECT DeviceObject,
    OUT ULONG *RegFlags,
    OUT PUNICODE_STRING InstanceName,
    OUT PUNICODE_STRING *RegistryPath,
    OUT PUNICODE_STRING MofResourceName,
    OUT PDEVICE_OBJECT *Pdo	    
    )
/*++

Routine Description:

    This routine is a callback into the driver to retrieve the list of
    guids or data blocks that the driver wants to register with WMI. This
    routine may not pend or block. Driver should NOT call
    WmiCompleteRequest.

Arguments:

    DeviceObject is the device whose data block is being queried

    *RegFlags returns with a set of flags that describe the guids being
        registered for this device. If the device wants enable and disable
        collection callbacks before receiving queries for the registered
        guids then it should return the WMIREG_FLAG_EXPENSIVE flag. Also the
        returned flags may specify WMIREG_FLAG_INSTANCE_PDO in which case
        the instance name is determined from the PDO associated with the
        device object. Note that the PDO must have an associated devnode. If
        WMIREG_FLAG_INSTANCE_PDO is not set then Name must return a unique
        name for the device.

    InstanceName returns with the instance name for the guids if
        WMIREG_FLAG_INSTANCE_PDO is not set in the returned *RegFlags. The
        caller will call ExFreePool with the buffer returned.

    *RegistryPath returns with the registry path of the driver

    *MofResourceName returns with the name of the MOF resource attached to
        the binary file. If the driver does not have a mof resource attached
        then this can be returned as NULL.

    *Pdo returns with the device object for the PDO associated with this
        device if the WMIREG_FLAG_INSTANCE_PDO flag is returned in 
        *RegFlags.

Return Value:

    status

--*/
{
    PFDO_DATA fdoData;

    PAGED_CODE();

    ToasterDebugPrint ((3, "Entered ToasterQueryWmiRegInfo\n"));

    fdoData = DeviceObject->DeviceExtension;

    *RegFlags = WMIREG_FLAG_INSTANCE_PDO;
    *RegistryPath = &Globals.RegistryPath;
    *Pdo = fdoData->UnderlyingPDO;
    RtlInitUnicodeString(MofResourceName, MOFRESOURCENAME);
    
    return STATUS_SUCCESS;
}

#if DBG

PCHAR
WMIMinorFunctionString (
    UCHAR MinorFunction
)
{
    switch (MinorFunction)
    {
        case IRP_MN_CHANGE_SINGLE_INSTANCE:
            return "IRP_MN_CHANGE_SINGLE_INSTANCE";
        case IRP_MN_CHANGE_SINGLE_ITEM:
            return "IRP_MN_CHANGE_SINGLE_ITEM";
        case IRP_MN_DISABLE_COLLECTION:
            return "IRP_MN_DISABLE_COLLECTION";
        case IRP_MN_DISABLE_EVENTS:
            return "IRP_MN_DISABLE_EVENTS";
        case IRP_MN_ENABLE_COLLECTION:
            return "IRP_MN_ENABLE_COLLECTION";
        case IRP_MN_ENABLE_EVENTS:
            return "IRP_MN_ENABLE_EVENTS";
        case IRP_MN_EXECUTE_METHOD:
            return "IRP_MN_EXECUTE_METHOD";
        case IRP_MN_QUERY_ALL_DATA:
            return "IRP_MN_QUERY_ALL_DATA";
        case IRP_MN_QUERY_SINGLE_INSTANCE:
            return "IRP_MN_QUERY_SINGLE_INSTANCE";
        case IRP_MN_REGINFO:
            return "IRP_MN_REGINFO";
        default:
            return "IRP_MN_?????";
    }
}

#endif



