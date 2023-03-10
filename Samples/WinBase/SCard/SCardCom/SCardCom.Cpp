/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

SCardCom.cpp : Implementation of DLL Exports.

Note: Proxy/Stub Information
             To build a separate proxy/stub DLL,
             run nmake -f SCardComps.mk in the project directory.
----------------------------------------------------------------------------*/

#include "stdafx.h"
#include "resource.h"
#include "initguid.h"
#include "SCardCom.h"

#include "SCardCom_i.c"
#include "SCardAth.h"
#include "SCardFil.h"
#include "SCardMan.h"
#include "SCardVer.h"


CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
    OBJECT_ENTRY(CLSID_SCardAuth, CSCardAuth)
    OBJECT_ENTRY(CLSID_SCardFileAccess, CSCardFileAccess)
    OBJECT_ENTRY(CLSID_SCardManage, CSCardManage)
    OBJECT_ENTRY(CLSID_SCardVerify, CSCardVerify)
END_OBJECT_MAP()

    class CSCardComApp : public CWinApp
{
public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();
};

CSCardComApp theApp;

BOOL CSCardComApp::InitInstance()
{
    _Module.Init(ObjectMap, m_hInstance);
    return CWinApp::InitInstance();
}

int CSCardComApp::ExitInstance()
{
    _Module.Term();
    return CWinApp::ExitInstance();
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return(AfxDllCanUnloadNow()==S_OK && _Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    _Module.UnregisterServer();
    return S_OK;
}

