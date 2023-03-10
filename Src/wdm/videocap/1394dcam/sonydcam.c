//===========================================================================
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
// PURPOSE.
//
// Copyright (c) 1996 - 1998  Microsoft Corporation.  All Rights Reserved.
//
//===========================================================================
/*++

Module Name:

    sonydcam.c

Abstract:

    This is a driver for the Sony Desktop Camera (CCM-DS250 V1.0x).
    This driver fits under the WDM stream class.

Author:
    
    Shaun Pierce 25-May-96

Modified:

    Yee J. Wu 15-Oct-97

Environment:

    Kernel mode only

Revision History:


--*/

#include "strmini.h"
#include "1394.h"
#include "dbg.h"
#include "ksmedia.h"
#include "dcamdef.h"
#include "sonydcam.h"
#include "dcampkt.h"
#include "capprop.h"   // Video and camera property function prototype


CHAR szUnknownVendorName[] = "UnknownVendor";


#ifdef ALLOC_PRAGMA
    // #pragma alloc_text(INIT, DriverEntry)
    #pragma alloc_text(PAGE, DCamHwUnInitialize)
    #pragma alloc_text(PAGE, InitializeDeviceExtension)
    #pragma alloc_text(PAGE, DCamHwInitialize)
#endif


NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    )

/*++

Routine Description:

    This where life begins for a driver.  The stream class takes care
    of alot of stuff for us, but we still need to fill in an initialization
    structure for the stream class and call it.

Arguments:

    DriverObject - Pointer to the driver object created by the system.
    RegistryPath - unused.

Return Value:

    The function value is the final status from the initialization operation.

--*/

{

    HW_INITIALIZATION_DATA HwInitData;
    
    PAGED_CODE();
    DbgMsg1(("SonyDCam DriverEntry: DriverObject=%x; RegistryPath=%x\n",
        DriverObject, RegistryPath));

#if DBG
    DCamDebugLevel = 0;
#endif

    //
    // Fill in the HwInitData structure
    //
    RtlZeroMemory( &HwInitData, sizeof(HW_INITIALIZATION_DATA) );

    HwInitData.HwInitializationDataSize = sizeof(HwInitData);
    HwInitData.HwInterrupt              = NULL;
    HwInitData.HwReceivePacket          = DCamReceivePacket;
    HwInitData.HwCancelPacket           = DCamCancelOnePacket;
    HwInitData.HwRequestTimeoutHandler  = DCamTimeoutHandler;
    HwInitData.DeviceExtensionSize      = sizeof(DCAM_EXTENSION);
    HwInitData.PerStreamExtensionSize   = sizeof(STREAMEX); 
    HwInitData.PerRequestExtensionSize  = sizeof(IRB);
    HwInitData.FilterInstanceExtensionSize = 0;
    HwInitData.BusMasterDMA             = FALSE;
    HwInitData.Dma24BitAddresses        = FALSE;
    HwInitData.BufferAlignment          = sizeof(ULONG) - 1;
    HwInitData.TurnOffSynchronization   = TRUE;
    HwInitData.DmaBufferSize            = 0;

    return (StreamClassRegisterAdapter(DriverObject, RegistryPath, &HwInitData));

}



#define DEQUEUE_SETTLE_TIME      (ULONG)(-1 * MAX_BUFFERS_SUPPLIED * 10000) 

NTSTATUS
DCamHwUnInitialize(
    IN PHW_STREAM_REQUEST_BLOCK Srb
    )
/*++

Routine Description:

    Device is asked to be unloaded.
       
    Note: this can be called BEFORE CloseStream in the situation when a DCam 
    is unplugged while streaming in any state (RUN,PAUSE or STOP).  So if we 
    are here and the stream is not yet close, we will stop, close stream and then
    free resource.

Arguments:

    Srb - Pointer to stream request block

Return Value:

    Nothing

--*/
{
    NTSTATUS Status;
    PIRP pIrp;
    PIRB pIrb;    
    PDCAM_EXTENSION pDevExt = (PDCAM_EXTENSION) Srb->HwDeviceExtension;

    PAGED_CODE();

    DCAM_ASSERT(pDevExt->PendingReadCount == 0);


    //
    // Host controller could be disabled which will cause us to be uninitialized.
    //
    if(DCamAllocateIrbAndIrp(&pIrb, &pIrp, pDevExt->BusDeviceObject->StackSize)) {

        //
        // un-register a bus reset callback notification
        //
        pIrb->FunctionNumber = REQUEST_BUS_RESET_NOTIFICATION;
        pIrb->Flags = 0;
        pIrb->u.BusResetNotification.fulFlags = DEREGISTER_NOTIFICATION_ROUTINE;
        pIrb->u.BusResetNotification.ResetRoutine = (PBUS_BUS_RESET_NOTIFICATION) DCamBusResetNotification;
        pIrb->u.BusResetNotification.ResetContext = 0; 
        Status = DCamSubmitIrpSynch(pDevExt, pIrp, pIrb);
        if(Status) {
            ERROR_LOG(("DCamHwUnInitialize: Error (Status %x) while trying to deregister nus reset callback routine.\n", Status));
        } 

        DbgMsg1(("DCamHwUnInitialize: DeRegister bus reset notification done; status %x.\n", Status));

        DCamFreeIrbIrpAndContext(0, pIrb, pIrp);
    } else {
        ERROR_LOG(("DCamBusResetNotification: DcamAllocateIrbAndIrp has failed!!\n\n\n"));
        DCAM_ASSERT(FALSE);   
    }

    // Free resource (from below)
    if(pDevExt->UnitDirectory) {
        ExFreePool(pDevExt->UnitDirectory);
        pDevExt->UnitDirectory = 0;
    }

    if(pDevExt->UnitDependentDirectory) {
        ExFreePool(pDevExt->UnitDependentDirectory);
        pDevExt->UnitDependentDirectory = 0;
    }

    if(pDevExt->ModelLeaf) {
        ExFreePool(pDevExt->ModelLeaf);
        pDevExt->ModelLeaf = 0;
    }

    if (pDevExt->ConfigRom) {
        ExFreePool(pDevExt->ConfigRom);
        pDevExt->ConfigRom = 0;
    }

    if (pDevExt->VendorLeaf) {
        ExFreePool(pDevExt->VendorLeaf);
        pDevExt->VendorLeaf = 0;
    }
      
    return STATUS_SUCCESS;
}




VOID 
InitializeDeviceExtension(
    PPORT_CONFIGURATION_INFORMATION ConfigInfo
    )
{
    PDCAM_EXTENSION pDevExt;

    pDevExt = (PDCAM_EXTENSION) ConfigInfo->HwDeviceExtension;
    pDevExt->SharedDeviceObject = ConfigInfo->ClassDeviceObject;
    pDevExt->BusDeviceObject = ConfigInfo->PhysicalDeviceObject;  // Used in IoCallDriver()
    pDevExt->PhysicalDeviceObject = ConfigInfo->RealPhysicalDeviceObject;  // Used in PnP API
    // In case sonydcam is used with old stream.sys, 
    // which has not implemented RealPhysicalDeviceObject.   
    if(!pDevExt->PhysicalDeviceObject)
        pDevExt->PhysicalDeviceObject = pDevExt->BusDeviceObject;
    DCAM_ASSERT(pDevExt->PhysicalDeviceObject != 0);
    pDevExt->BaseRegister = 0;
    pDevExt->FrameRate = DEFAULT_FRAME_RATE;
    InitializeListHead(&pDevExt->IsochDescriptorList);
    KeInitializeSpinLock(&pDevExt->IsochDescriptorLock);
    pDevExt->bNeedToListen = FALSE;
    pDevExt->hResource = NULL;
    pDevExt->hBandwidth = NULL;
    pDevExt->IsochChannel = ISOCH_ANY_CHANNEL;
    pDevExt->PendingReadCount = 0; 
    pDevExt->pStrmEx = 0;

    InitializeListHead(&pDevExt->IsochWaitingList);
    KeInitializeSpinLock(&pDevExt->IsochWaitingLock);

    pDevExt->bDevRemoved = FALSE;

    pDevExt->CurrentPowerState = PowerDeviceD0;  // full power state.
}


NTSTATUS
DCamHwInitialize(
    IN PHW_STREAM_REQUEST_BLOCK Srb
    )

/*++

Routine Description:

    This where we perform the necessary initialization tasks.

Arguments:

    Srb - Pointer to stream request block

Return Value:

    Nothing

--*/

{

    PIRB pIrb;
    PIRP pIrp;
    CCHAR StackSize;
    ULONG i;
    ULONG DirectoryLength;
    NTSTATUS status;
    PDCAM_EXTENSION pDevExt;
    PPORT_CONFIGURATION_INFORMATION ConfigInfo;  
         

    PAGED_CODE();

    ConfigInfo = Srb->CommandData.ConfigInfo;
    pIrb = (PIRB) Srb->SRBExtension;
    pDevExt = (PDCAM_EXTENSION) ConfigInfo->HwDeviceExtension;

    //
    // Initialize DeviceExtension
    //
    InitializeDeviceExtension(ConfigInfo); 

    StackSize = pDevExt->BusDeviceObject->StackSize;
    pIrp = IoAllocateIrp(StackSize, FALSE);
    if (!pIrp) {

        DCAM_ASSERT(FALSE);
        return (STATUS_INSUFFICIENT_RESOURCES);
    }

    //
    // find what the host adaptor below us supports...
    //
    pIrb->FunctionNumber = REQUEST_GET_LOCAL_HOST_INFO;
    pIrb->Flags = 0;
    pIrb->u.GetLocalHostInformation.nLevel = GET_HOST_CAPABILITIES;
    pIrb->u.GetLocalHostInformation.Information = &pDevExt->HostControllerInfomation;
    status = DCamSubmitIrpSynch(pDevExt, pIrp, pIrb);
    if (status) {

        ERROR_LOG(("DCamHwInitialize: Error (Status=%x) while trying to get local hsot info.\n", status));
        IoFreeIrp(pIrp);
        return (STATUS_UNSUCCESSFUL);
    }        


    //
    // Make a call to determine what the generation # is on the bus,
    // followed by a call to find out about ourself (config rom info)
    //
    //
    // Get the current generation count first
    //

    pIrb->FunctionNumber = REQUEST_GET_GENERATION_COUNT;
    pIrb->Flags = 0;

    status = DCamSubmitIrpSynch(pDevExt, pIrp, pIrb);

    if (status) {

        ERROR_LOG(("\'DCamHwInitialize: Error %x while trying to get generation number\n", status));
        IoFreeIrp(pIrp);
        return (STATUS_UNSUCCESSFUL);
    }

    pDevExt->CurrentGeneration = pIrb->u.GetGenerationCount.GenerationCount;

    //
    // Now that we have the current generation count, find out how much
    // configuration space we need by setting lengths to zero.
    //

    pIrb->FunctionNumber = REQUEST_GET_CONFIGURATION_INFO;
    pIrb->Flags = 0;
    pIrb->u.GetConfigurationInformation.UnitDirectoryBufferSize = 0;
    pIrb->u.GetConfigurationInformation.UnitDependentDirectoryBufferSize = 0;
    pIrb->u.GetConfigurationInformation.VendorLeafBufferSize = 0;
    pIrb->u.GetConfigurationInformation.ModelLeafBufferSize = 0;

    status = DCamSubmitIrpSynch(pDevExt, pIrp, pIrb);

    if (status) {

        ERROR_LOG(("\'DCamHwInitialize: Error %x while trying to get configuration info (1)\n", status));
        IoFreeIrp(pIrp);
        return (STATUS_UNSUCCESSFUL);

    }

    //
    // Now go thru and allocate what we need to so we can get our info.
    //

    pDevExt->ConfigRom = ExAllocatePoolWithTag(PagedPool, sizeof(CONFIG_ROM), 'macd');
    if (!pDevExt->ConfigRom) {

        ERROR_LOG(("\'DCamHwInitialize: Couldn't allocate memory for the Config Rom\n"));
        IoFreeIrp(pIrp);
        return (STATUS_INSUFFICIENT_RESOURCES);
    }


    pDevExt->UnitDirectory = ExAllocatePoolWithTag(PagedPool, pIrb->u.GetConfigurationInformation.UnitDirectoryBufferSize, 'macd');
    if (!pDevExt->UnitDirectory) {

        ERROR_LOG(("\'DCamHwInitialize: Couldn't allocate memory for the UnitDirectory\n"));
        IoFreeIrp(pIrp);
        return (STATUS_INSUFFICIENT_RESOURCES);
    }


    if (pIrb->u.GetConfigurationInformation.UnitDependentDirectoryBufferSize) {

        pDevExt->UnitDependentDirectory = ExAllocatePoolWithTag(PagedPool, pIrb->u.GetConfigurationInformation.UnitDependentDirectoryBufferSize, 'macd');
        if (!pDevExt->UnitDependentDirectory) {

            ERROR_LOG(("\'DCamHwInitialize: Couldn't allocate memory for the UnitDependentDirectory\n"));
            IoFreeIrp(pIrp);
            return (STATUS_INSUFFICIENT_RESOURCES);
        }
    }


    if (pIrb->u.GetConfigurationInformation.VendorLeafBufferSize) {

        // From NonPaged pool since vendor name can be used in a func with DISPATCH level
        pDevExt->VendorLeaf = ExAllocatePoolWithTag(NonPagedPool, pIrb->u.GetConfigurationInformation.VendorLeafBufferSize, 'macd');
        if (!pDevExt->VendorLeaf) {

            ERROR_LOG(("\'DCamHwInitialize: Couldn't allocate memory for the VendorLeaf\n"));
            IoFreeIrp(pIrp);
            return (STATUS_INSUFFICIENT_RESOURCES);
        }
    }

    if (pIrb->u.GetConfigurationInformation.ModelLeafBufferSize) {

        pDevExt->ModelLeaf = ExAllocatePoolWithTag(NonPagedPool, pIrb->u.GetConfigurationInformation.ModelLeafBufferSize, 'macd');
        if (!pDevExt->ModelLeaf) {

            ERROR_LOG(("\'DCamHwInitialize: Couldn't allocate memory for the ModelLeaf\n"));
            IoFreeIrp(pIrp);
            return (STATUS_INSUFFICIENT_RESOURCES);
        }
    }

    //
    // Now resubmit the pIrb with the appropriate pointers inside
    //

    pIrb->FunctionNumber = REQUEST_GET_CONFIGURATION_INFO;
    pIrb->Flags = 0;
    pIrb->u.GetConfigurationInformation.ConfigRom = pDevExt->ConfigRom;
    pIrb->u.GetConfigurationInformation.UnitDirectory = pDevExt->UnitDirectory;
    pIrb->u.GetConfigurationInformation.UnitDependentDirectory = pDevExt->UnitDependentDirectory;
    pIrb->u.GetConfigurationInformation.VendorLeaf = pDevExt->VendorLeaf;
    pIrb->u.GetConfigurationInformation.ModelLeaf = pDevExt->ModelLeaf;

    status = DCamSubmitIrpSynch(pDevExt, pIrp, pIrb);

    if (status) {

        ERROR_LOG(("DCamHwInitialize: Error %x while trying to get configuration info (2)\n", status));
        IoFreeIrp(pIrp);
        return (STATUS_UNSUCCESSFUL);

    }

    //
    // We might be able to return strings about a Device
    //

    if (pDevExt->VendorLeaf) {

        DbgMsg1(("\'DCamHwInitialize: BufSize %d (byte); VendorLeaf %x; Len %d (Quad)\n", 
            pIrb->u.GetConfigurationInformation.VendorLeafBufferSize, 
            pDevExt->VendorLeaf, 
            pDevExt->VendorLeaf->TL_Length));

        if(pDevExt->VendorLeaf->TL_Length >= 1) {
            pDevExt->pchVendorName = &pDevExt->VendorLeaf->TL_Data;
        } else {
            pDevExt->pchVendorName = szUnknownVendorName;
        }

        DbgMsg1(("\'DCamHwInitialize: VendorName %s, strLen %d\n", pDevExt->pchVendorName, strlen(pDevExt->pchVendorName)));
    }

    //
    // Now we chew thru the Unit Dependent Directory looking for our command
    // base register key.
    //

    DirectoryLength = pIrb->u.GetConfigurationInformation.UnitDependentDirectoryBufferSize >> 2;
    for (i=1; i < DirectoryLength; i++) {

        if ((*(((PULONG) pDevExt->UnitDependentDirectory)+i) & CONFIG_ROM_KEY_MASK) == COMMAND_BASE_KEY_SIGNATURE) {

            //
            // Found the command base offset.  This is a quadlet offset from
            // the initial register space.  (Should come out to 0xf0f00000)
            //

            pDevExt->BaseRegister = bswap(*(((PULONG) pDevExt->UnitDependentDirectory)+i) & CONFIG_ROM_OFFSET_MASK);
            pDevExt->BaseRegister <<= 2;
            pDevExt->BaseRegister |= INITIAL_REGISTER_SPACE_LO;
            break;

        }
        
    }

    DCAM_ASSERT( pDevExt->BaseRegister );

    if(!DCamDeviceInUse(pIrb, pDevExt)) {
        //
        // Now let's actually do a write request to initialize the device
        //
        pDevExt->RegisterWorkArea.AsULONG = 0;
        pDevExt->RegisterWorkArea.Initialize.Initialize = TRUE;
        pDevExt->RegisterWorkArea.AsULONG = bswap(pDevExt->RegisterWorkArea.AsULONG);

        Srb->Status = DCamWriteRegister ((PIRB) Srb->SRBExtension, pDevExt, 
                  FIELDOFFSET(CAMERA_REGISTER_MAP, Initialize), pDevExt->RegisterWorkArea.AsULONG);

        if(Srb->Status) {

            ERROR_LOG(("DCamHwInitialize: Error %x while trying to write to Initialize register\n", status));
            IoFreeIrp(pIrp);
            return (STATUS_UNSUCCESSFUL);      
        }
    }

    //
    // Now we initialize the size of stream descriptor information.
    // We have one stream descriptor, and we attempt to dword align the
    // structure.
    //

    ConfigInfo->StreamDescriptorSize = 
        1 * (sizeof (HW_STREAM_INFORMATION)) +      // 1 stream descriptor
        sizeof(HW_STREAM_HEADER);                   // and 1 stream header


    //
    // register a bus reset callback notification
    //
    // The controller driver will call (at DPC level)
    // if and only if the device is STILL attach.
    //
    // The device that has been removed, its
    // driver will get SRB_SURPRISE_REMOVAL instead.
    //
    
    pIrb->FunctionNumber = REQUEST_BUS_RESET_NOTIFICATION;
    pIrb->Flags = 0;
    pIrb->u.BusResetNotification.fulFlags = REGISTER_NOTIFICATION_ROUTINE;
    pIrb->u.BusResetNotification.ResetRoutine = (PBUS_BUS_RESET_NOTIFICATION) DCamBusResetNotification;
    pIrb->u.BusResetNotification.ResetContext = pDevExt;
    status = DCamSubmitIrpSynch(pDevExt, pIrp, pIrb);
    if (status) {

        ERROR_LOG(("DCamHwInitialize: Error (Status=%x) while trying to get local host info.\n", status));
        IoFreeIrp(pIrp);
        return (STATUS_UNSUCCESSFUL);
    }


    // This Irp is used locally only.
    IoFreeIrp(pIrp);

    DbgMsg1(("#### %s DCam loaded. ClassDO %x, PhyDO %x, BusDO %x, pDevExt %x, Gen# %d\n", 
        pDevExt->pchVendorName, pDevExt->SharedDeviceObject, pDevExt->PhysicalDeviceObject, pDevExt->BusDeviceObject, pDevExt, pDevExt->CurrentGeneration));

    return (STATUS_SUCCESS);

}


NTSTATUS
DCamSubmitIrpSynch(
    PDCAM_EXTENSION pDevExt,
    PIRP Irp,
    PIRB pIrb
    )

/*++

Routine Description:

    This routine submits an Irp synchronously to the bus driver.  We'll
    wait here til the Irp comes back

Arguments:

    pDevExt - Pointer to my local device extension

    Irp - Pointer to Irp we're sending down to the port driver synchronously

    pIrb - Pointer to Irb we're submitting to the port driver

Return Value:

    Status is returned from Irp

--*/

{


    ULONG Retries=RETRY_COUNT;
    KEVENT Event;
    NTSTATUS status;
    LARGE_INTEGER deltaTime;
    PIO_STACK_LOCATION NextIrpStack;
    BOOL bWait = KeGetCurrentIrql() < DISPATCH_LEVEL;

    

    do {

        NextIrpStack = IoGetNextIrpStackLocation(Irp);
        NextIrpStack->MajorFunction = IRP_MJ_INTERNAL_DEVICE_CONTROL;
        NextIrpStack->Parameters.DeviceIoControl.IoControlCode = IOCTL_1394_CLASS;
        NextIrpStack->Parameters.Others.Argument1 = pIrb;

        KeInitializeEvent(&Event, SynchronizationEvent, FALSE);

        IoSetCompletionRoutine(
            Irp,
            DCamSynchCR,
           &Event,
            TRUE,
            TRUE,
            TRUE
            );

        status = IoCallDriver(
                    pDevExt->BusDeviceObject,
                    Irp
                    );


        DbgMsg3(("\'DCamSubmitIrpSynch: Irp is pending(%s); will wait(%s)\n", 
                   status == STATUS_PENDING?"Y":"N", bWait?"Y":"N"));

        if (bWait &&
            status == STATUS_PENDING) {

            //
            // Still pending, wait for the IRP to complete
            //

            KeWaitForSingleObject(  // Only in <= IRQL_DISPATCH_LEVEL; can only in DISPATCH if Timeout is 0
               &Event,
                Executive,
                KernelMode,
                FALSE,
                NULL
                );

        }

        if (bWait &&
            Irp->IoStatus.Status == STATUS_TIMEOUT) {

            //
            // Camera isn't fast enough to respond to us sometimes, so
            // we'll delay a little bit in order for it to recover
            //
            DbgMsg3(("\'DCamSubmitIrpSynch: KeDelayExecutionThread().\n"));

            deltaTime.LowPart = DCAM_DELAY_VALUE;
            deltaTime.HighPart = -1;
            KeDelayExecutionThread(KernelMode, TRUE, &deltaTime);  // Only in IRQL_PASSIVE_LEVEL !!

        }


    } while (bWait && (Irp->IoStatus.Status == STATUS_TIMEOUT) && (Retries--));

#if DBG
    if(Irp->IoStatus.Status != STATUS_SUCCESS) {
        ERROR_LOG(("DCamSubmitIrpSynch: Irp->IoStatus.Status = %x\n", Irp->IoStatus.Status)); 
    }
#endif

    return (Irp->IoStatus.Status);

}


NTSTATUS
DCamSynchCR(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
    IN PKEVENT Event
    )

/*++

Routine Description:

    This routine is for use with synchronous IRP processing.  
    All it does is signal an event, so the driver knows it
    can continue.

Arguments:

    DriverObject - Pointer to driver object created by system.

    Irp - Irp that just completed

    Event - Event we'll signal to say Irp is done

Return Value:

    None.

--*/

{

    KeSetEvent((PKEVENT) Event, 0, FALSE);
    return (STATUS_MORE_PROCESSING_REQUIRED);

}

