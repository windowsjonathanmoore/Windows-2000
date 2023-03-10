/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

wrapper for dlldata.c

----------------------------------------------------------------------------*/
#ifdef _MERGE_PROXYSTUB // merge proxy stub DLL

    #define REGISTER_PROXY_DLL //DllRegisterServer, etc.

    #pragma comment(lib, "rpcndr.lib")
    #pragma comment(lib, "rpcns4.lib")
    #pragma comment(lib, "rpcrt4.lib")

    #define DllMain             PrxDllMain
    #define DllRegisterServer   PrxDllRegisterServer
    #define DllUnregisterServer PrxDllUnregisterServer
    #define DllGetClassObject   PrxDllGetClassObject
    #define DllCanUnloadNow     PrxDllCanUnloadNow

    #include "dlldata.c"
    #include "SCardssp_p.c"

    #ifdef _NOPROXY //no midl generated dlldata.c

        #define STRICT 1
        #include <ole2.h>

BOOL WINAPI PrxDllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    return TRUE;
}

STDAPI PrxDllCanUnloadNow(void)
{
    return S_OK;
}

STDAPI PrxDllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return CLASS_E_CLASSNOTAVAILABLE;
}

STDAPI PrxDllRegisterServer(void)
{
    return S_OK;
}

STDAPI PrxDllUnregisterServer(void)
{
    return S_OK;
}

    #endif //!PROXY_DELEGATION

#endif //_MERGE_PROXYSTUB
