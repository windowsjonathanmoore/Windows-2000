/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1996 - 2000.  Microsoft Corporation.  All rights reserved.


Module Name:

    SCardAgg

Abstract:

    This file contains the outline implementation of the DLL exports
    for this in-process server (DLL) for example aggregate object.

Environment:

    Win32, C++ w/Exceptions, ATL, COM/OLE

Revision History:

Notes:

    1)  This code is NOT specific to any one ICC. It only supports those methods
        that map directly to a low-level ICC COM interface/method.

    2)  You will need the NT SUR Beta 2 SDK or VC 4.2 in order to build this
        project.  This is because you will need MIDL 3.00.15 or higher and
        new headers and libs.  If you have VC 4.2 installed, then everything
        should already be configured correctly.

    Proxy/Stub Information -

    To merge the proxy/stub code into the object DLL, add the file
    dlldatax.c to the project.  Make sure precompiled headers
    are turned off for this file, and add _MERGE_PROXYSTUB to the
    defines for the project.

    Modify the custom build rule for SCardCOM.idl by adding the
    following files to the Outputs.  You can select all of the .IDL
    files by expanding each project and holding Ctrl while clicking
    on each of them.

            SCardAgg_p.c
            dlldata.c

    To build a separate proxy/stub DLL, run:

            nmake -f SCardAggps.mak

    in the project directory.
--*/

/////////////////////////////////////////////////////////////////////////////
//
// Includes
//

#include "preagg.h"
#include "resagg.h"
#include "initguid.h"
#include "ScardAgg.h"
#include "SCardNI.h"
#include "dllaggx.h"

///////////////////////////////////////////////////////////////////////////
// Macros
//
#ifdef _DEBUG
    #define TRACE_STR(name,sz) \
                TRACE(_T("SCardAgg.DLL: CSCardAggApp::%s: %s\n"), name, sz)
    #define TRACE_CODE(name,code) \
                TRACE(_T("SCardAgg.DLL: CSCardAggApp::%s: error = 0x%x\n"), name, code)
    #define TRACE_CATCH(name,code)      TRACE_CODE(name,code)
    #define TRACE_CATCH_UNKNOWN(name)   TRACE_STR(name,_T("An unidentified exception has occurred!"))
#else
    #define TRACE_STR(name,sz)          ((void)0)
    #define TRACE_CODE(name,code)       ((void)0)
    #define TRACE_CATCH(name,code)      ((void)0)
    #define TRACE_CATCH_UNKNOWN(name)   ((void)0)
#endif  // _DEBUG

/////////////////////////////////////////////////////////////////////////////
//
// ActiveX Template Library (ATL)
//

#define IID_DEFINED
#include "ScardAgg_i.c"

#ifdef _MERGE_PROXYSTUB
extern "C" HINSTANCE hProxyDll;
#endif

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
    OBJECT_ENTRY(CLSID_CSCardNewInterface, CSCardNewInterface)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
//
// DLL Entry Point
//

class CScardAggApp : public CWinApp
{
public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();
};

CScardAggApp theApp;

/*++

CSCardDatApp::InitInstance:

    Override to perform Windows instance initialization, such as
    creating your window objects.

Arguments:

    None

Return Value:

    Nonzero if initialization is successful; otherwise 0.

Author:

    Chris Dudley (cdudley) 2/22/1997

--*/

BOOL CScardAggApp::InitInstance()
{
#ifdef _MERGE_PROXYSTUB
    // Initialize the DLL's COM interfaces.
    hProxyDll = m_hInstance;
    // Initialize the MFC part of this object.
#endif
    _Module.Init(ObjectMap, m_hInstance);
    return CWinApp::InitInstance();
}


/*++

CSCardDatApp::ExitInstance:

    Override to clean up when your application terminates.

Arguments:

    None

Return Value:

    The application’s exit code; 0 indicates no errors, and values greater
    than 0 indicate an error. This value is used as the return value from
    WinMain.

Author:

    Chris Dudley (cdudley) 2/22/1997

--*/
int CScardAggApp::ExitInstance()
{
    _Module.Term();
    return CWinApp::ExitInstance();
}

/*++

DllCanUnloadNow:

    This routine determines whether the DLL that implements this function
    is in use. If not, the caller can safely unload the DLL from memory.

Arguments:

    None

Return Value:

    A HRESULT value indicating the status of the requested action.

        Return          Meaning
        ======          =======
        S_OK            The DLL can be unloaded.
        S_FALSE         The DLL cannot be unloaded now.

Author:

    Chris Dudley (cdudley) 2/22/1997

Notes:

    1. Remarks
        A call to DllCanUnloadNow determines whether the DLL from which
        it is exported is still in use. A DLL is no longer in use when
        it is not managing any existing objects (the reference count on
        all of its objects is 0).

    2. Notes to Callers
        You should not have to call DllCanUnloadNow directly. OLE calls
        it only through a call to the CoFreeUnusedLibraries function.
        When it returns S_OK, CoFreeUnusedLibraries safely frees the DLL.

    3. Notes to Implementers
        You need to implement DllCanUnloadNow in, and export it from,
        DLLs that are to be dynamically loaded through a call to the
        CoGetClassObject function. (You also need to implement and export
        the DllGetClassObject function in the same DLL).

        If a DLL loaded through a call to CoGetClassObject fails to export
        DllCanUnloadNow, the DLL will not be unloaded until the application
        calls the CoUninitialize function to release the OLE libraries.

        If the DLL links to another DLL, returning S_OK from DllCanUnloadNow
        will also cause the second, dependent DLL to be unloaded. To
        eliminate the possibility of a crash, the primary DLL should call
        the CoLoadLibrary function, specifying the path to the second DLL
        as the first parameter, and setting the auto free parameter to TRUE.
        This forces the COM library to reload the second DLL and set it up
        for a call to CoFreeUnusedLibraries to free it separately when
        appropriate.

        DllCanUnloadNow should return S_FALSE if there are any existing
        references to objects that the DLL manages.

--*/
STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllCanUnloadNow() != S_OK)
        return S_FALSE;
#endif
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return(AfxDllCanUnloadNow()==S_OK && _Module.GetLockCount()==0) ? S_OK : S_FALSE;
}


/*++

DllGetClassObject:

    This routine returns a class factory to create an object of the
        requested type.

Arguments:

    rclsid - CLSID for the class object.

    riid - Reference to the identifier of the interface that communicates
            with the class object. Usually, this is IID_IClassFactory
            (defined in the OLE headers as the interface identifier for
            IClassFactory).

    ppv - Indirect pointer to the communicating interface.

Return Value:

    A HRESULT value indicating the status of the requested action.

        Return                      Meaning
        ======                      =======
        E_INVALIDARG                An argument was invalid or unrecognizable.
        E_OUTOFMEMORY               No free memory in process address space
                                    to create requested object.
        E_UNEXPECTED                One of the parameters was of an unexpected
                                    type or value.
        S_OK                        The object was retrieved successfully.
        CLASS_E_CLASSNOTAVAILABLE   The DLL does not support the class
                                    (object definition).


Author:

    Chris Dudley (cdudley) 2/22/1997

Notes:

        1. Remarks
            If a call to the CoGetClassObject function finds the class object
            that is to be loaded in a DLL, CoGetClassObject uses the DLL's
            exported DllGetClassObject function.

        2. Notes to Callers
            You should not call DllGetClassObject directly. When an object
            is defined in a DLL, CoGetClassObject calls the CoLoadLibrary
            function to load the DLL, which, in turn, calls DllGetClassObject.

        3. Notes to Implementers
            You need to implement DllGetClassObject in (and export it from)
            DLLs that support the OLE Component Object Model.

--*/
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
        return S_OK;
#endif
    return _Module.GetClassObject(rclsid, riid, ppv);
}


/*++

DllRegisterServer:

    This routine instructs an in-process server to create its registry
    entries for all classes supported in this server module. If this
    function fails, the state of the registry for all its classes is
    indeterminate.

Arguments:

    None

Return Value:

    A HRESULT value indicating the status of the requested action.

        Return              Meaning
        ======              =======
        E_OUTOFMEMORY       No free memory in process address space to
                            create requested object.
        E_UNEXPECTED        One of the parameters was of an unexpected
                            type or value.
        S_OK                The registry entries were created successfully.
        SELFREG_E_TYPELIB   The server was unable to complete the
                            registration of all the type libraries used
                            by its classes.
        SELFREG_E_CLASS     The server was unable to complete the
                            registration of all the object classes.

Author:

    Chris Dudley (cdudley) 2/22/1997

--*/
STDAPI DllRegisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
    HRESULT hRes = PrxDllRegisterServer();
    if (FAILED(hRes))
        return hRes;
#endif
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}


/*++

DllUnregisterServer:

    This routine instructs an in-process server to remove only those
    entries created through DllRegisterServer.

Arguments:

    None

Return Value:

    A HRESULT value indicating the status of the requested action.

        Return          Meaning
        ======          =======
        E_OUTOFMEMORY   No free memory in process address space to create
                        requested object.
        E_UNEXPECTED    One of the parameters was of an unexpected type
                        or value.
        S_OK            The registry entries were created successfully.
        S_FALSE         Unregistration of this server's known entries
                        was successful, but other entries still exist
                        for this server's classes.

Author:

    Chris Dudley (cdudley) 2/22/1997

Notes:

    The server must not disturb any entries that it did not create
    which currently exist for its object classes. For example, between
    registration and unregistration, the user may have specified a
    TreatAs relationship between this class and another. In that case,
    unregistration can remove all entries except the TreatAs key and
    any others that were not explicitly created in DllRegisterServer.
    The Win32 registry functions specifically disallow the deletion
    of an entire populated tree in the registry. The server can attempt,
    as the last step, to remove the CLSID key, but if other entries
    still exist, the key will remain.

--*/
STDAPI DllUnregisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
    PrxDllUnregisterServer();
#endif
    _Module.UnregisterServer();
    return S_OK;
}

