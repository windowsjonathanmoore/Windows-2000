/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1996 - 2000.  Microsoft Corporation.  All rights reserved.

Module Name:

    scdtest

Abstract:

    Simple brute force test SSP application. Usage: "test <# of iterations>".
    Contains good examples for calling low-level SSPs.

Environment:

    Win32, C++ w/Exceptions, COM/OLE

Notes:

        CLSCTX_LOCAL is defined and used throughout instead of CLSCTX_ALL,
        so that projects built on NT5 platforms can run on Win95.
        CLSCTX_LOCAL does not include CLSCTX_REMOTE_SERVER, a flag intended
        for use only with DCOM, which is not supported by Win95.

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

#include <scardssp.h>
#include <sspguid.h>

/////////////////////////////////////////////////////////////////////////////
//
// Globals
//
LPSCARD g_pISCard = NULL;
LPSCARDDATABASE g_pISCardDatabase = NULL;
LPSCARDLOCATE g_pISCardLocate = NULL;
LPSCARDISO7816 g_pISCardISO7816 = NULL;
LPSCARDCMD g_pISCardCmd = NULL;
LPBYTEBUFFER g_pIByteBuffer = NULL;

/////////////////////////////////////////////////////////////////////////////
//
// Macros
//

#ifndef SafeCast
    #define SafeCast(cast,pt)       ((cast)(pt))
#endif

#ifndef ASSERT
    #define ASSERT      _ASSERTE
#endif

#ifndef IN
    #define IN
#endif


////////////////////////////////////////////////////////////////////////////
//
// Defines
//

#define BYTE_BUFFER_HEAD    (0)

#ifndef CLSCTX_LOCAL
#define CLSCTX_LOCAL            (CLSCTX_INPROC_SERVER| \
                                 CLSCTX_INPROC_HANDLER| \
                                 CLSCTX_LOCAL_SERVER)
#endif

STDAPI
SspCreateByteBuffer(
                   IN DWORD dwAllocSize,
                   OUT LPBYTEBUFFER *ppbyBuff,
                   OUT OPTIONAL EXCEPINFO* pExceptInfo = NULL);


/////////////////////////////////////////////////////////////////////////////
//
// Functions
//


/*++

ConTrace:

    Simply Tracing function to dump text to standard output.

Arguments:

    lpszFormat - String to dump to standard output

--*/

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


/*++

DumpAPDU:

    Dumps the ReplyADPU of the current CardCmd object.

Arguments:

    None.

--*/
void _cdecl
DumpAPDU( void )
{
#ifdef _DEBUG
    // Locals
    HRESULT     hresult = S_OK;
    ULONG       ulBytesRead = 0;
    BYTE        pbyIStreamData[10];
    LPBYTEBUFFER pBuffer = NULL;
    TCHAR       pCharBuffer[10];
    LARGE_INTEGER   li;
    STATSTRUCT  statstruct;

    // Get the Command APDU
    hresult = g_pISCardCmd->get_Apdu(&pBuffer);
    if (FAILED(hresult)) {
        ConTrace(_T("Failed to get command apdu."));
        return;
    };// if

    // set seek position
    LISet32 (li, BYTE_BUFFER_HEAD );
    hresult = pBuffer->Seek((LONG) li.LowPart,
                            (LONG) STREAM_SEEK_SET,
                            NULL);
    if (FAILED(hresult)){
        ConTrace(_T("Unable to seek in IStream."));
        return;
    };
    // Seek
    hresult = pBuffer->Stat(&statstruct, (LONG) 0);
    if (FAILED(hresult))
        throw (hresult);

    // Set buffer size
    hresult = pBuffer->SetSize(statstruct.cbSize);
    if (FAILED(hresult)) {
        ConTrace(_T("Unable to set IStream size."));
        return;
    };

    // Read Data
    hresult = pBuffer->Read((BYTE*) pbyIStreamData,
                            (LONG) statstruct.cbSize,  // APDU header
                            (LONG*) &ulBytesRead);
    if (FAILED(hresult)) {
        ConTrace(_T("Unable to read IStream."));
        return;
    };


    // "Quick" not best way to do this...
    switch (statstruct.cbSize) {
        case 5:
            sprintf(pCharBuffer, "%d %d %d %d %d\n",
                    (int) pbyIStreamData[0], (int) pbyIStreamData[1],
                    (int) pbyIStreamData[2], (int) pbyIStreamData[3],
                    (int) pbyIStreamData[4]);
            break;
        case 4:
            sprintf(pCharBuffer, "%d %d %d %d\n",
                    (int) pbyIStreamData[0], (int) pbyIStreamData[1],
                    (int) pbyIStreamData[2], (int) pbyIStreamData[3]);
            break;
        default:
            // Sending data with command...Just display APDU.
            sprintf(pCharBuffer, "%d %d %d %d %d\n",
                    (int) pbyIStreamData[0], (int) pbyIStreamData[1],
                    (int) pbyIStreamData[2], (int) pbyIStreamData[3],
                    (int) pbyIStreamData[4]);
            break;
            break;
    }; //switch

    ConTrace( (LPCTSTR) pCharBuffer );

    // Eliminate the temp buffer(s)...Clean up
    if (pBuffer != NULL)
        while (pBuffer->Release()>0);
#endif // _DEBUG
}


/*++

CallServer:

    Routine creates an instance of each low-level com object.

Arguments:

    lpszFormat - String to dump to standard output

--*/
void _cdecl
CallServer(
    void)
{
    // locals
    HRESULT     hresult;

    ConTrace(_T("\nSTARTING Object Creation\n=============================\n"));
    ConTrace(_T("Calling CoCreateInstance()...\n"));

    hresult = CoCreateInstance( CLSID_CSCard,
                                NULL,
                                CLSCTX_LOCAL,
                                IID_ISCard,
                                (LPVOID*) &g_pISCard);
    if (FAILED(hresult)) {
        ConTrace(_T("Failed to create CSCard object\n"));
        return;
    }
    ConTrace(_T("Object CSCard created\n"));

    hresult = CoCreateInstance( CLSID_CSCardISO7816,
                                NULL,
                                CLSCTX_LOCAL,
                                IID_ISCardISO7816,
                                (LPVOID*) &g_pISCardISO7816);
    if (FAILED(hresult)) {
        ConTrace(_T("Failed to create CSCardISO7816 object\n"));
        return;
    }
    ConTrace(_T("Object CSCardISO7816 created\n"));

    hresult = CoCreateInstance( CLSID_CSCardCmd,
                                NULL,
                                CLSCTX_LOCAL,
                                IID_ISCardCmd,
                                (LPVOID*) &g_pISCardCmd);
    if (FAILED(hresult)) {
        ConTrace(_T("Failed to create CSCardCmd object\n"));
        return;
    }
    ConTrace(_T("Object CSCardCmd created\n"));

    hresult = CoCreateInstance( CLSID_CSCardLocate,
                                NULL,
                                CLSCTX_LOCAL,
                                IID_ISCardLocate,
                                (LPVOID*) &g_pISCardLocate);
    if (FAILED(hresult)) {
        ConTrace(_T("Failed to create CSCardLocate object\n"));
        return;
    }
    ConTrace(_T("Object CSCardLocate created\n"));

    hresult = CoCreateInstance( CLSID_CSCardDatabase,
                                NULL,
                                CLSCTX_LOCAL,
                                IID_ISCardDatabase,
                                (LPVOID*) &g_pISCardDatabase);
    if (FAILED(hresult)) {
        ConTrace(_T("Failed to create CSCardDatabase object\n"));
        return;
    }
    ConTrace(_T("Object CSCardDatabase created\n"));

    hresult = CoCreateInstance( CLSID_CByteBuffer,
                                NULL,
                                CLSCTX_LOCAL,
                                IID_IByteBuffer,
                                (LPVOID*) &g_pIByteBuffer);
    if (FAILED(hresult)) {
        ConTrace(_T("Failed to create CSCardDatabase object\n"));
        return;
    }
    ConTrace(_T("Object CByteBuffer created\n"));

    ConTrace(_T("\nDONE!!! with Object Creation\n=============================\n"));
}


/*++

CallISOFunctions:

    Routine calls all the low level ISO build commands.

Arguments:

    lpszFormat - String to dump to standard output

Notes:

    1. This function does not actually send the command to a smartcard. It only
    builds the apdu. In order to send the command to a card, the card/reader must be
    attached:
        hresult = g_pISCard->AttachByReader(bstrReaderName,
                                            EXCLUSIVE,
                                            T0);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on AttachByReader\n"));
            return;
        }
    Transactions must be performed:
        hresult = g_pISCard->Transaction(&g_pISCardCmd);
    And the card finally released.

--*/
void _cdecl
CallISOFunctions( long  lLoops )
{
    // Locals
    HRESULT         hresult = S_OK;
    LPBYTEBUFFER    pBuffer1 = NULL,
                    pBuffer2 = NULL;
    TCHAR           szBuffer[200];

    ConTrace(_T("\nSTARTING Call Testing\n=============================\n"));
    ConTrace(_T("Calling ISO Functions...\n"));

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

    // Loop through the build/execute ISO commands
    while (lLoops != 0) {
        sprintf(szBuffer,"Iteration Number: %d\n", (int) lLoops);
        ConTrace( (LPCTSTR) szBuffer );
        // Appendrecord
        ConTrace(_T("Build/Execute: AppendRecord\n"));
        hresult = g_pISCardISO7816->AppendRecord(   0,
                                                    pBuffer1,
                                                    &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on AppendRecord\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: AppendRecord successful\n"));


        // EraseBinary
        ConTrace(_T("Build/Execute: EraseBinary\n"));
        hresult = g_pISCardISO7816->EraseBinary(0,
                                                0,
                                                pBuffer1,
                                                &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on EraseBinary\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: EraseBinary successful\n"));


        // ExternalAuthenticate
        ConTrace(_T("Build/Execute: ExternalAuthenticate\n"));
        hresult = g_pISCardISO7816->ExternalAuthenticate(0,
                                                        0,
                                                        pBuffer2,
                                                        &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on ExternalAuthenticate\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: ExternalAuthenticate successful\n"));


        // GetChallenge
        ConTrace(_T("Build/Execute: GetChallenge\n"));
        hresult = g_pISCardISO7816->GetChallenge(   10,
                                                    &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on GetChallenge\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: GetChallenge successful\n"));


        // GetData
        ConTrace(_T("Build/Execute: GetData\n"));
        hresult = g_pISCardISO7816->GetData(0,
                                            0,
                                            10,
                                            &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on GetData\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: GetData successful\n"));


        // GetResponse
        ConTrace(_T("Build/Execute: GetResponse\n"));
        hresult = g_pISCardISO7816->GetResponse(0,
                                                0,
                                                0,
                                                &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on GetResponse\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: GetResponse successful\n"));


        // InternalAuthenticate
        ConTrace(_T("Build/Execute: InternalAuthenticate\n"));
        hresult = g_pISCardISO7816->InternalAuthenticate(   0,
                                                            0,
                                                            pBuffer1,
                                                            10,
                                                            &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on InternalAuthenticate\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: InternalAuthenticate successful\n"));


        // ManageChannel
        ConTrace(_T("Build/Execute: ManageChannel\n"));
        hresult = g_pISCardISO7816->ManageChannel(  0x00,
                                                    0x80,
                                                    &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on ManageChannel\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: ManageChannel successful\n"));


        // PutData
        ConTrace(_T("Build/Execute: PutData\n"));
        hresult = g_pISCardISO7816->PutData(0,
                                            0,
                                            pBuffer1,
                                            &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on PutData\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: PutData successful\n"));


        // ReadBinary
        ConTrace(_T("Build/Execute: ReadBinary\n"));
        hresult = g_pISCardISO7816->ReadBinary( 0,
                                                0,
                                                20,
                                                &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on ReadBinary\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: ReadBinary successful\n"));


        // ReadRecord
        ConTrace(_T("Build/Execute: ReadRecord\n"));
        hresult = g_pISCardISO7816->ReadRecord( 10,
                                                5,
                                                100,
                                                &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on ReadRecord\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: ReadRecord successful\n"));


        // SelectFile
        ConTrace(_T("Build/Execute: SelectFile\n"));
        hresult = g_pISCardISO7816->SelectFile( 0,
                                                0,
                                                pBuffer1,
                                                20,
                                                &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on SelectFile\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: SelectFile successful\n"));


        // SetDefaultClassID
        ConTrace(_T("Build/Execute: SetDefaultClassID\n"));
        hresult = g_pISCardISO7816->SetDefaultClassId(  20  );
        if (FAILED(hresult)){
            ConTrace(_T("Failed on SetDefaultClassID\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: SetDefaultClassID successful\n"));


        // UpdateBinary
        ConTrace(_T("Build/Execute: UpdateBinary\n"));
        hresult = g_pISCardISO7816->UpdateBinary(   0,
                                                    0,
                                                    pBuffer1,
                                                    &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on UpdateBinary\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: UpdateBinary successful\n"));


        // UpdateRecord
        ConTrace(_T("Build/Execute: UpdateRecord\n"));
        hresult = g_pISCardISO7816->UpdateRecord(   10,
                                                    1,
                                                    pBuffer2,
                                                    &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on UpdateRecord\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: UpdateRecord successful\n"));


        // Verify
        ConTrace(_T("Build/Execute: Verify\n"));
        hresult = g_pISCardISO7816->Verify( 1,
                                            pBuffer2,
                                            &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on Verify\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: Verify successful\n"));


        // WriteBinary
        ConTrace(_T("Build/Execute: WriteBinary\n"));
        hresult = g_pISCardISO7816->WriteBinary(    0,
                                                    0,
                                                    pBuffer1,
                                                    &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on WriteBinary\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: WriteBinary successful\n"));


        // WriteRecord
        ConTrace(_T("Build/Execute: WriteRecord\n"));
        hresult = g_pISCardISO7816->WriteRecord(    1,
                                                    1,
                                                    pBuffer1,
                                                    &g_pISCardCmd);
        if (FAILED(hresult)){
            ConTrace(_T("Failed on WriteRecord\n"));
            //return;
        }
        DumpAPDU();
        ConTrace(_T("Build/Execute: WriteRecord successful\n"));

        // Decrement count
        --lLoops;
    };//while
    // Clean up
    if (pBuffer1 != NULL)
        while (pBuffer1->Release());
    if (pBuffer2 != NULL)
        while (pBuffer2->Release());

    ConTrace(_T("\nDONE!!! with Call Testing\n=============================\n"));
}


/*++

CallLocateFunctions:

    Calls the ISCardLocate functions (i.e. common dialog).

Arguments:

    lpszFormat - String to dump to standard output

--*/
void _cdecl
CallLocateFunctions( long lLoops)
{
    // Locals
    HRESULT     hresult = S_OK;
    LPSAFEARRAY rgCardName = NULL;
    LPSAFEARRAY rgGroupName = NULL;
    SCARDINFO   scardinfo;
    LPSCARDINFO pscardinfo = &scardinfo;
    SAFEARRAYBOUND Bounds[] = {2,0},
                   Bounds2[] = {1,0};
    long        lIndex[] = {0};         // Access only 1 element
    BSTR        bstrCardName = ::SysAllocString(L"Cryptoflex"),
                bstrCardName2 = ::SysAllocString(L"Sicrypt"),
                bstrGroupName = ::SysAllocString(L"SCard$DefaultReaders");

    ConTrace(_T("\nSTARTING Call Testing\n=============================\n"));
    ConTrace(_T("Calling Locate Functions...\n"));

    // Clear memory
    ::ZeroMemory(   (LPVOID) pscardinfo, (DWORD) sizeof(SCARDINFO) );

    // Create a SAFEARRAY of type BSTR (contains
    rgCardName = ::SafeArrayCreate(VT_BSTR,     // BSTRs
                                    (UINT) 1,           // 1 dimensional array
                                    Bounds);        // That dimension contains 2 element

    if (rgCardName == NULL) {
        ConTrace(_T("\nUnable to create SAFEARRAY."));
        return;
    }
    // Create a SAFEARRAY of type BSTR (contains
    rgGroupName = ::SafeArrayCreate(VT_BSTR,        // BSTRs
                                    (UINT) 1,           // 1 dimensional array
                                    Bounds2);       // That dimension contains 1 element

    if (rgGroupName == NULL) {
        ConTrace(_T("\nUnable to create SAFEARRAY."));
        return;
    }

    // Add an element...
    // lIndex is does not really have to be declared as an array since
    // both SAFEARRAYs are 1 dimensional. An array is, however, required
    // for multi dimensional arrays.
    hresult = SafeArrayPutElement(rgCardName, lIndex, (LPVOID) bstrCardName);
    if (FAILED(hresult)) {
        ConTrace(_T("\nSafearray put element failed."));
        return;
    }
    lIndex[0]= 1;
    hresult = SafeArrayPutElement(rgCardName, lIndex, (LPVOID) bstrCardName2);
    if (FAILED(hresult)) {
        ConTrace(_T("\nSafearray put element failed."));
        return;
    }
    lIndex[0] = 0;
    hresult = SafeArrayPutElement(rgGroupName, lIndex, (LPVOID) bstrGroupName);
    if (FAILED(hresult)) {
        ConTrace(_T("\nSafearray put element failed."));
        return;
    }

    // Setup for search
    hresult = g_pISCardLocate->ConfigureCardNameSearch( rgCardName,
                                                        rgGroupName,
                                                        NULL,
                                                        0);
    if (FAILED(hresult)) {
        ConTrace(_T("\nConfigureCardSearch failed."));
        return;
    }

    // Setup for common dialog..This actually displays the dialog for user input
    //hresult = g_pISCardLocate->FindCard(bstrCardName,
    //                                  EXCLUSIVE,
    //                                  T0,
    //                                  &pscardinfo);
    //if (FAILED(hresult)) {
    //  ConTrace(_T("\nFindCard failed."));
    //  return;
    //}

    ConTrace(_T("\nDONE!!! with Call Testing\n=============================\n"));

    // Cleanup
    if (rgCardName != NULL)
        ::SafeArrayDestroy(rgCardName);
    if (rgGroupName != NULL)
        ::SafeArrayDestroy(rgGroupName);
    if (bstrGroupName != NULL)
        ::SysFreeString(bstrGroupName);
    if (bstrCardName != NULL)
        ::SysFreeString(bstrCardName);
    if (bstrCardName != NULL)
        ::SysFreeString(bstrCardName2);
}


/*++

CallDbFunctions:

    Calls the ISCardDatabase functions.

Arguments:

    lpszFormat - String to dump to standard output

--*/
void _cdecl
CallDbFunctions( long lLoops)
{
    // Locals
    GUID        guidProviderID;
    LPGUID      lpguidProviderID = &guidProviderID;
    HRESULT     hresult = S_OK;
    BSTR        bstrCardName = ::SysAllocString(L"Cryptoflex");
    LPSAFEARRAY lpSafeArray = NULL;
    LPBYTEBUFFER pBuffer = NULL;
    LARGE_INTEGER   li;
    BYTE        bAtr[] = {0x3b,0x00};
    ULONG       ulBytesWritten = 0;

    // GetProviderCardId
    hresult = g_pISCardDatabase->GetProviderCardId( bstrCardName,
                                                    &lpguidProviderID);
    if (FAILED(hresult)) {
        ConTrace(_T("\nGetProviderCardId failed."));
    }

    //ListCardInterfaces...NOT SUPPORTED IN THIS RELEASE!!

    // ListCards
    // Create a bytebuffer for use in call
    hresult = SspCreateByteBuffer((ULONG) 2, &pBuffer);
    if (FAILED(hresult)) {
        ConTrace(_T("Failed to create IByteBuffer\n"));
    };// if
    // set seek position
    LISet32 (li, BYTE_BUFFER_HEAD );
    hresult = pBuffer->Seek((LONG) li.LowPart,
                            (LONG) STREAM_SEEK_SET,
                            NULL);
    if (FAILED(hresult)){
        ConTrace(_T("Unable to seek in IStream."));
    };
    // Fill in an ATR to search
    hresult = pBuffer->Write(   (BYTE*) bAtr,
                                (LONG) 2,
                                (LONG*) &ulBytesWritten);
    if (FAILED(hresult)) {
        ConTrace(_T("Unable to write to IStream."));
    };
    // Call it
    hresult = g_pISCardDatabase->ListCards( pBuffer,
                                            NULL,
                                            (long) 0,
                                            &lpSafeArray);
    if (FAILED(hresult)) {
        ConTrace(_T("\nListCards failed."));
    }
    if (lpSafeArray != NULL) {
        ::SafeArrayDestroy(lpSafeArray);
        lpSafeArray = NULL;
    }

    // ListReaderGroups
    hresult = g_pISCardDatabase->ListReaderGroups(      (long) 0,
                                                        &lpSafeArray);
    if (FAILED(hresult)) {
        ConTrace(_T("\nListReaderGroups failed."));
    }
    if (lpSafeArray != NULL) {
        ::SafeArrayDestroy(lpSafeArray);
        lpSafeArray = NULL;
    }

    // ListReaders
    hresult = g_pISCardDatabase->ListReaders(   (long) 0,
                                                &lpSafeArray);
    if (FAILED(hresult)) {
        ConTrace(_T("\nListReaders failed."));
    }
    if (lpSafeArray != NULL) {
        ::SafeArrayDestroy(lpSafeArray);
        lpSafeArray = NULL;
    }
}


/*++

Cleanup:

    Release all the interfaces/memory.

Arguments:

    lpszFormat - String to dump to standard output

--*/
void _cdecl
CleanUp(
void)
{
    while (g_pISCard->Release()>0);
    while (g_pISCardISO7816->Release()>0);
    while (g_pISCardCmd->Release()>0);
    // If required...
    while (g_pISCardDatabase->Release()>0);
    while (g_pISCardLocate->Release()>0);
    while (g_pIByteBuffer->Release()>0);
}


/*++

main:

    Entry point.

Arguments:

    lpszFormat - String to dump to standard output

--*/
int __cdecl
main(
    IN int argc,
    IN char *argv[ ])
{
    int nRet = 0;
    long lIterations;

    try
    {
        // Check command line arguments
        if (argc==1)
            lIterations = 1;
        else if (argc==2)
            lIterations = atol(argv[1]);
        else {
            printf ("\nCorrect Usage: test [#iterations]\n");
            throw;
        }

        if (FAILED(CoInitialize(NULL)))
            throw;

        // Create Objects...
        CallServer();
        // Call Various Functions
        CallISOFunctions(lIterations);
        //CallLocateFunctions(lIterations);
        //CallDbFunctions(lIterations);
        // Clean Up...
        CleanUp();

        CoUninitialize();

        #ifdef _DEBUG
            _CrtDumpMemoryLeaks();
        #endif


        nRet = 0;
    }

    catch (...)
    {
        printf(_T("Unhandled exception!!!\n"));
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

