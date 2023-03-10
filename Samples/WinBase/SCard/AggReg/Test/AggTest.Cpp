/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1996 - 2000.  Microsoft Corporation.  All rights reserved.

Module Name:

    AggTest

Abstract:

    This file builds a console-based executable that functions as a
    simple test harness for SCardAgg.dll.

Environment:

    Win32, C++ w/Exceptions, ATL, COM/OLE

Revision History:

Notes:

--*/

/////////////////////////////////////////////////////////////////////////////
//
// Includes
//

#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <crtdbg.h>
#include <initguid.h>

#include "scardagg.h"
#include "scardssp.h"
#include <sspguid.h>
#include <scardagg_i.c>

/////////////////////////////////////////////////////////////////////////////
//
// Globals
//
LPSCARD g_pISCard = NULL;
LPSCARDDATABASE g_pISCardDatabase = NULL;
LPSCARDLOCATE g_pISCardLocate = NULL;
LPSCARDNEWINTERFACE g_pISCardNewInterface = NULL;
LPSCARDISO7816 g_pISCardISO7816 = NULL;
LPSCARDCMD g_pISCardCmd = NULL;

/////////////////////////////////////////////////////////////////////////////
//
// Macros
//

#ifndef SafeCast
    #define SafeCast(cast,pt) ((cast)(pt))
#endif

#ifndef ASSERT
    #define ASSERT _ASSERTE
#endif

#ifndef IN
    #define IN
#endif

/////////////////////////////////////////////////////////////////////////////
//
// Functions
//

STDAPI
SspCreateByteBuffer(
                   IN DWORD dwAllocSize,
                   OUT LPBYTEBUFFER *ppbyBuff,
                   OUT OPTIONAL EXCEPINFO* pExceptInfo = NULL);

void _cdecl
ConTrace(
    IN LPCTSTR lpszFormat, ...)
{
    //
    // Helper to do print traces...
    //

    va_list args;
    va_start(args, lpszFormat);

    int nBuf;
    TCHAR szBuffer[512];
    ZeroMemory(szBuffer, SafeCast(DWORD,(512*sizeof(TCHAR))));

    nBuf = _vstprintf(szBuffer, lpszFormat, args);
    ASSERT(nBuf < sizeof(szBuffer));

    _tprintf(szBuffer);
    OutputDebugString(szBuffer);
    va_end(args);
}


void _cdecl
CallServer(
    void)
{
    HRESULT     hresult = S_OK;

    ConTrace(_T("\nSTARTING Object Creation\n=========================\n"));
    ConTrace(_T("Calling CoCreateInstance()...SCardDat\n"));


    hresult = CoCreateInstance( CLSID_CSCard,
                                NULL,
                                CLSCTX_LOCAL,
                                IID_ISCard,
                                (LPVOID*) &g_pISCard);
    if (FAILED(hresult))
    {
        ConTrace(_T("Failed to create CSCard object\n"));
        return;
    }
    ConTrace(_T("Object created\n"));


    //***************************************************************
    // Create the New interface and the aggregated interface
    hresult = CoCreateInstance( CLSID_CSCardNewInterface,
                                NULL,
                                CLSCTX_LOCAL,
                                IID_ISCardNewInterface,
                                (LPVOID*) &g_pISCardNewInterface);
    if (FAILED(hresult))
    {
        ConTrace(_T("Failed to create CSCardNewInterface object\n"));
        return;
    }
    ConTrace(_T("Object created\n"));

    hresult = CoCreateInstance( CLSID_CSCardNewInterface,
                                NULL,
                                CLSCTX_LOCAL,
                                IID_ISCardISO7816,
                                (LPVOID*) &g_pISCardISO7816);
    if (FAILED(hresult))
    {
        ConTrace(_T("Failed to create CSCardISO7816 Aggregated object\n"));
        return;
    }
    ConTrace(_T("Object created\n"));
    //
    //******************************************************************

    hresult = CoCreateInstance( CLSID_CSCardCmd,
                                NULL,
                                CLSCTX_LOCAL,
                                IID_ISCardCmd,
                                (LPVOID*) &g_pISCardCmd);
    if (FAILED(hresult))
    {
        ConTrace(_T("Failed to create CSCardCmd object\n"));
        return;
    }
    ConTrace(_T("Object created\n"));

    ConTrace(_T("\nDONE!!! with object Creation\n=========================\n"));
}


void _cdecl
CallAggreg()
{
        // Locals
    HRESULT         hresult = S_OK;
    LPBYTEBUFFER    pBuffer1 = NULL,
                    pBuffer2 = NULL;

    // Create a couple of byte buffers for testing
    hresult = SspCreateByteBuffer((ULONG) 1, &pBuffer1);
    if (FAILED(hresult)) {
        ConTrace(_T("Failed to create IByteBuffer\n"));
        return;
    };// if
    hresult = SspCreateByteBuffer((ULONG) 1, &pBuffer2);
    if (FAILED(hresult)) {
        ConTrace(_T("Failed to create IByteBuffer\n"));
        return;
    };// if

    // Call one of the aggregated methods
    ConTrace(_T("Build/Execute: AppendRecord\n"));
    hresult = g_pISCardISO7816->AppendRecord(0,
                                             pBuffer1,
                                             &g_pISCardCmd);
    if (FAILED(hresult)){
        ConTrace(_T("Failed on AppendRecord\n"));
        return;
    }

    // Call the new interface method
    ConTrace(_T("Build/Execute: NewInterface\n"));
    hresult = g_pISCardNewInterface->NewInterface(  0,
                                                    0,
                                                    pBuffer1,
                                                    &g_pISCardCmd);
    if (FAILED(hresult)){
        ConTrace(_T("Failed on NewInterface\n"));
        return;
    }

}


int __cdecl
main(
    IN int argc,
    IN char *argv[ ])
{
    int nRet = -1;

    try
    {
        if (FAILED(CoInitialize(NULL)))
            throw;

        CallServer();
        CallAggreg();

        #ifdef _DEBUG
            _CrtDumpMemoryLeaks();
        #endif

        CoUninitialize();

        nRet = 0;
    }

    catch (...)
    {
        ConTrace(_T("Unhandled exception!!!"));
    }

    return (nRet);
}


/*++

SspCreateByteBuffer:

    This routine creates a IByteBuffer interface.

Arguments:

    dwAllocSize - Size in bytes of the memory to be allocated for the buffer.

    ppbyBuff - Points to the IStream object to be returned.

    pExceptInfo - Points to an OLE exception block which contains extended
            information about any failure that might occur. Can be set to
            NULL if the exception information is not desired.

Return Value:

    A HRESULT value indicating the status of the requested action.

        Return          Meaning
        ======          =======
        S_OK            The byte buffer object was created successfully.
        S_FALSE         Unknown error.
        E_OUTOFMEMORY   There is not enough memory in this process to
                        satisfy the request.
        E_FAIL          Unspecified error.
        E_INVALIDARG    One or more arguments are invalid.
        E_HANDLE        Invalid handle.
        E_POINTER       Invalid pointer.
        E_UNEXPECTED    Unexpected fault has occurred.

Author:

--*/

STDAPI
SspCreateByteBuffer(
                   IN DWORD dwAllocSize,
                   OUT LPBYTEBUFFER *ppbyBuff,
                   OUT OPTIONAL EXCEPINFO* pExceptInfo)
{
    // Locals.
    HRESULT hr = S_OK;
    LPBYTEBUFFER pObj = NULL;
    LPCLASSFACTORY lpClassFactory = NULL;

    try
    {
        // Initialize the parameters.
        *ppbyBuff = NULL;

        // Not supporting OLE exception struct.
        if (NULL != pExceptInfo)
            ::ZeroMemory(pExceptInfo, sizeof(EXCEPINFO));

        // Do WIN 95 safe creation of the IByteBuffer IStream wrapper
        hr = CoGetClassObject(  CLSID_CByteBuffer,
                                CLSCTX_INPROC_SERVER,
                                NULL,
                                IID_IClassFactory,
                                (LPVOID*) &lpClassFactory );
        if (FAILED(hr))
            throw (hr);
        ASSERT(lpClassFactory != NULL);

        // Create instance of class
        hr = lpClassFactory->CreateInstance(NULL,
                                            IID_IByteBuffer,
                                            (LPVOID*) &pObj);
        if (FAILED(hr))
            throw (hr);
        ASSERT(pObj != NULL);

        // Initialize the IStream wrapper
        hr = pObj->Initialize(dwAllocSize, NULL);
        if (FAILED(hr))
            throw (hr);

        // Ok, pack for return.
        *ppbyBuff = pObj;
    }

    catch (HRESULT hrStatus)
    {
        hr = hrStatus;
        ConTrace(_T("SspCreateByteBuffer Failure\n"));
    }

    catch (...)
    {
        ConTrace(_T("SspCreateByteBuffer Exception\n"));
        hr = E_UNEXPECTED;
    }

    // Clean up
    if (lpClassFactory!=NULL)
        lpClassFactory->Release();

    return (hr);
}

/////////////////////////////////////////////////////////////////////////////

