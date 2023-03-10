/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

Module Name:

    scardwrp

Abstract:

    This file contains a simple class implementation for "wrapping" some
    of the Vendor COM Wrapper API functionality.

Environment:

    Win32, C++ w/Exceptions, ATL, COM/OLE

--*/

/////////////////////////////////////////////////////////////////////////////
//
// Includes
//
#include "preapp.h"   //This include for the app SSP COM example
#include "SCardWrp.h"

// GUIDs
#include <WrpGUID.h>
#include <sspguid.h>

// OLE Specific headers
#include <ole2.h>
#include <objbase.h>
#include <oleauto.h>

#ifdef _DEBUG
    #define new DEBUG_NEW
    #undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

///////////////////////////////////////////////////////////////////////////
// Macros
//
#ifdef _DEBUG
    #define TRACE_STR(name,sz) \
                TRACE(_T("CSCardWrapper::%s: %s\n"), name, sz)
    #define TRACE_CODE(name,code) \
                TRACE(_T("CSCardWrapper::%s: error = 0x%x\n"), name, code)
    #define TRACE_CATCH(name,code)      TRACE_CODE(name,code)
    #define TRACE_CATCH_UNKNOWN(name)   TRACE_STR(name,_T("An unidentified exception has occurred!"))
#else
    #define TRACE_STR(name,sz)          ((void)0)
    #define TRACE_CODE(name,code)       ((void)0)
    #define TRACE_CATCH(name,code)      ((void)0)
    #define TRACE_CATCH_UNKNOWN(name)   ((void)0)
#endif  // _DEBUG


////////////////////////////////////////////////////////////////////////////
//
// CSCardWrapper
//

/*++

CSCardWrapper::CreateByteBuffer

    This routines creates a byte buffer.

Arguments:

    dwSize - size of bytebuffer to create
    ppBuffer - pointer to created buffer

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:

--*/
HRESULT CSCardWrapper::CreateByteBuffer(DWORD dwSize,
                                        LPBYTEBUFFER *ppBuffer)
{
    //locals
    HRESULT     hresult = S_OK;
    LPCLASSFACTORY  lpClassFactory = NULL;

    try
    {
        // Check Parames, etc
        if (ppBuffer == NULL)
            throw ( (HRESULT) E_INVALIDARG );

        // Do WIN 95 safe creation of the IByteBuffer IStream wrapper
        hresult = CoGetClassObject( CLSID_CByteBuffer,
                                    CLSCTX_LOCAL,
                                    NULL,
                                    IID_IClassFactory,
                                    (LPVOID*) &lpClassFactory );
        if (FAILED(hresult))
            throw (hresult);
        ASSERT(lpClassFactory != NULL);
        hresult = lpClassFactory->CreateInstance(NULL,
                                                 IID_IByteBuffer,
                                                 (LPVOID*) ppBuffer);
        if (FAILED(hresult))
            throw (hresult);
        ASSERT( (*ppBuffer) != NULL);

        // Initialize the IStream wrapper
        hresult = (*ppBuffer)->Initialize(dwSize, NULL);
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("CreateByteBuffer"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("CreateByteBuffer"));
    }

    return hresult;
}


/*++

CSCardWrapper::AttachToReaderByName

    This routine attaches to a reader (and the card in that reader)

Arguments:

    szReaderName = a null terminated wide character string
    containing the reader name

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:

--*/
HRESULT CSCardWrapper::AttachToReaderByName( WCHAR  *wszReaderName )
{
    //locals
    HRESULT     hresult = S_OK;
    BSTR        bstrReader = NULL;

    try
    {
        if (!m_sequence.COMLoad)
            throw ( (HRESULT) E_FAIL);
        if (wszReaderName == NULL)
            throw ( (HRESULT) E_INVALIDARG );
        // create the BSTR
        bstrReader = ::SysAllocString(wszReaderName);
        if (bstrReader == NULL)
            throw ( (HRESULT) E_OUTOFMEMORY );
        // Attach to reader
        hresult=m_pISCardManage->AttachByIFD( bstrReader, SHARED );
        if (FAILED(hresult))
            throw(hresult);

        // Ok...
        m_sequence.Attach = 1;
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("AttachToReaderByName"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("AttachToReaderByName"));
    }

    // Free memory
    if (bstrReader != NULL)
        ::SysFreeString(bstrReader);

    return hresult;
}


/*++

CSCardWrapper::ChangeDirectory

    Changes to the specified directory on the ICC.

Arguments:

    wszDirectory = a null terminated wide character string
    containing the Directory

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:

    This method is calling the ISO 7816-4 SelectFile command. The wszDirectory
    should ONLY be a 2-byte file ID (as supported by the vendor com example code).

--*/
HRESULT CSCardWrapper::ChangeDirectory( WCHAR *wszDirectory )
{
    //locals
    HRESULT     hresult = S_OK;
    BSTR        bstrDir = NULL;

    try
    {
        // Are attached?
        if (!m_sequence.Attach)
            throw ( (HRESULT) E_FAIL );
        if (wszDirectory == NULL)
            throw ( (HRESULT) E_INVALIDARG );
        //Create BSTR
        bstrDir = ::SysAllocString(wszDirectory);
        if (bstrDir == NULL)
            throw ( (HRESULT) E_OUTOFMEMORY);
        //ChangeDir
        hresult=m_pISCardFileAccess->ChangeDir( SC_TYPE_BY_ID,
                                                bstrDir);
        if (FAILED(hresult))
            throw(hresult);

        //Ok...
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("ChangeDirectory"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("ChangeDirectory"));
    }

    // Free memory
    if (bstrDir != NULL)
        ::SysFreeString(bstrDir);

    return hresult;
}


/*++

CSCardWrapper::Detach

    This method does a detach from the current card.

Arguments:

    None.

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:

--*/
HRESULT CSCardWrapper::Detach()
{
    // Locals
    HRESULT     hresult = S_OK;

    try
    {
        hresult = m_pISCardManage->Detach();
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Detach"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Detach"));
    }

    return hresult;
}


/*++

CSCardWrapper::GetChallenge

    This method calls gets a challenge from the ICC and returns

Arguments:

    lpbyChallange - long point to a byte array large enough to hold the
    challenge.

    lpLengthOfChal - length of the challenge expected.

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:

--*/
HRESULT CSCardWrapper::GetChallenge( LPBYTE lpbyChallenge, LONG* lpLengthOfChal )
{
    // locals
    HRESULT         hresult = S_OK;
    LPBYTEBUFFER    pOutputBuffer = NULL;
    ULONG           ulBytesRead;
    LARGE_INTEGER   li;

    try
    {
        if (!m_sequence.Attach)
            throw ( (HRESULT) E_FAIL );
        //Get challenge..NOTE Vendor COM will create outputbuffer but we must
        // ->Release!!
        hresult = m_pISCardAuth->GetChallenge(  0L,
                                                NULL,
                                                lpLengthOfChal,
                                                &pOutputBuffer);
        if (FAILED(hresult))
            throw hresult;
        // set seek position/Read challenge head
        LISet32 (li, BYTE_BUFFER_HEAD );
        hresult = pOutputBuffer->Seek(  (LONG) li.LowPart,
                                        (LONG) STREAM_SEEK_SET,
                                        NULL);
        if (FAILED(hresult))
            throw hresult;
        // Read data into return stream
        hresult = pOutputBuffer->Read(  (BYTE*) lpbyChallenge,
                                        (LONG)  *lpLengthOfChal,
                                        (LONG*) &ulBytesRead);
        if (FAILED(hresult))
            throw hresult;
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("GetChallenge"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("GetChallenge"));
    }

    // Release Bytebuffer (IStream) object
    if (pOutputBuffer != NULL)
        while (pOutputBuffer->Release() > 0);

    return hresult;
}


/*++

CSCardWrapper::LoadCOM

    This routine loads the Vendor COM object which, in turn, loads
    the low level COM API's

Arguments:

    none

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:

--*/

HRESULT CSCardWrapper::LoadCOM()
{
    // locals
    HRESULT     hresult = S_OK;

    try
    {
        // Initialize COM
        hresult = CoInitialize(NULL);
        // SCardManage
        hresult = CoCreateInstance( CLSID_SCardManage,
                                    NULL,
                                    CLSCTX_INPROC_SERVER,
                                    IID_ISCardManage,
                                    (void FAR * FAR *) &m_pISCardManage);
        if (FAILED(hresult))
            throw (hresult);

        // Use the SCardManage object to create the others
        hresult = m_pISCardManage->CreateCardAuth(  &m_pISCardAuth );
        if (FAILED(hresult))
            throw (hresult);

        hresult = m_pISCardManage->CreateFileAccess( &m_pISCardFileAccess );
        if (FAILED(hresult))
            throw (hresult);

        hresult = m_pISCardManage->CreateCHVerification( &m_pISCardVerify );
        if (FAILED(hresult))
            throw (hresult);

        //ok...
        m_sequence.COMLoad = 1;
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Initialize"),hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Initialize"));
    }

    //

    return hresult;
}


/*++

CSCardWrapper::Open

    This method opens the requested file.

Arguments:

    wszFilename - 0 terminated, wide character string

    phFile - pointer to an HSCARD_FILE ICC file handle

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:


--*/
HRESULT CSCardWrapper::Open( WCHAR *wszFilename, HSCARD_FILE *phFile )
{
    // locals
    HRESULT     hresult = S_OK;
    BSTR        bstrFilename = NULL;

    try
    {
        if ((wszFilename == NULL) || (phFile == NULL))
            throw ( (HRESULT) E_INVALIDARG);
        bstrFilename = ::SysAllocString( wszFilename );
        if (bstrFilename == NULL)
            throw ( (HRESULT) E_OUTOFMEMORY );
        // Open the file
        hresult = m_pISCardFileAccess->Open(SC_TYPE_BY_ID,
                                            bstrFilename,
                                            phFile);
        if (FAILED(hresult))
            throw (hresult);

        // Ok...
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Open"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Open"));
    }

    // Free memory
    if (bstrFilename != NULL)
        ::SysFreeString(bstrFilename);

    return hresult;
}


/*++

CSCardWrapper::Status

    This method returns status of card.

Arguments:

    pState - State of the card
    pProtocol - Protocol in use on the card

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:

--*/
HRESULT CSCardWrapper::Status( SCARD_STATES *pState, SCARD_PROTOCOLS *pProtocol )
{
    //locals
    HRESULT     hresult = S_OK;

    try
    {
        if (!m_sequence.Attach)
            throw ( (HRESULT) E_FAIL );
        if ((pState == NULL) || (pProtocol == NULL))
            throw ( (HRESULT) E_INVALIDARG );
        // Get Status
        hresult = m_pISCardManage->Status(pState, pProtocol);

        //Ok...
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Status"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Status"));
    }

    return hresult;
}


/*++

CSCardWrapper::UnloadCOM

    This routine unloads the Vendor COM object which, in turn, unloads
    the low level COM API's

Arguments:

    none

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:

--*/
void CSCardWrapper::UnloadCOM()
{
    //locals

    try
    {
        // UninitializeOLE if error has not occured
        if (m_sequence.COMLoad)
        {
            if (m_pISCardFileAccess != NULL)
                while (m_pISCardFileAccess->Release()>0);;
            if (m_pISCardVerify != NULL)
                while (m_pISCardVerify->Release()>0);
            if (m_pISCardAuth != NULL)
                while (m_pISCardAuth->Release()>0);
            if (m_pISCardManage != NULL)
                while (m_pISCardManage->Release()>0);
            CoUninitialize();
        };//if
    }

    catch (...)
    {
        TRACE_CATCH_UNKNOWN(_T("UnloadCOM"));
    }
}


/*++

CSCardWrapper::VerifyPIN

    This method does a PPIN verification with the card.

Arguments:

    wszPIN = a null terminated wide character string
    containing the PIN

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:

--*/
HRESULT CSCardWrapper::VerifyPIN( WCHAR *wszPIN )
{
    //locals
    HRESULT     hresult = S_OK;
    BSTR        bstrPIN = NULL;

    try
    {
        // Are Attached?
        if (!m_sequence.Attach)
            throw ( (HRESULT) E_FAIL );
        if (wszPIN == NULL)
            throw ( (HRESULT) E_INVALIDARG );

        // Todo: convert to byte buffer and pass to vendor wrapper.

        //Ok...
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("VerifyPIN"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("VerifyPIN"));
    }

    // Free memory
    if (bstrPIN != NULL)
        ::SysFreeString(bstrPIN);

    return hresult;
}


/*++

CSCardWrapper::Write

    Write data to an open EF.

Arguments:

    hFile - handle to file.
    cbBytes - number of bytes to write
    pbyData - pointer to data to write.

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            Operation completed successfully.
    S_FALSE         Unknown error occurred.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected event occurred in this function.

Author:

Notes:

--*/

HRESULT CSCardWrapper::Write(   HSCARD_FILE hFile,
                                BYTE byRecordID,
                                LONG cbBytes,
                                LPBYTE pbyData)
{
    //locals
    HRESULT     hresult = S_OK;
    LPBYTEBUFFER pBuffer = NULL;
    LARGE_INTEGER li;
    ULONG       ulBytesWritten = 0;

    try
    {
        // Are Attached?
        if (!m_sequence.Attach)
            throw ( (HRESULT) E_FAIL );
        if (pbyData == NULL)
            throw ( (HRESULT) E_INVALIDARG );
        if (cbBytes <0)
            throw ( (HRESULT) E_INVALIDARG );
        // Create ByteBuffer
        hresult = CreateByteBuffer( (DWORD) cbBytes,
                                    &pBuffer);
        if (FAILED(hresult))
            throw (hresult);
        // set seek position
        LISet32 (li, BYTE_BUFFER_HEAD );
        hresult = pBuffer->Seek((LONG) li.LowPart,
                                (LONG) STREAM_SEEK_SET,
                                NULL);
        if (FAILED(hresult))
            throw hresult;
        // Write data into return stream
        hresult = pBuffer->Write(   (BYTE*) pbyData,
                                    (LONG) cbBytes,
                                    (LONG*) &ulBytesWritten);
        if (FAILED(hresult))
            throw hresult;

        // Do the write...
        hresult = m_pISCardFileAccess->Write(   hFile,
                                                ulBytesWritten,
                                                pBuffer,
                                                SC_FL_REPLACE);
        if (FAILED(hresult))
            throw (hresult);

        //Ok...
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Write"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Write"));
    }

    return hresult;
}

