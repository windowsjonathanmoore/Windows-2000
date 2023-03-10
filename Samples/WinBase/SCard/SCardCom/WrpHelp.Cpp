/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1996 - 2000.  Microsoft Corporation.  All rights reserved.

Module Name:

    WrpHelp

Abstract:

    This file contains wrapper class implementations.


Environment:

    Win32, C++ w/Exceptions, ATL, COM/OLE

Notes:

--*/

/////////////////////////////////////////////////////////////////////////////
//
// Includes
//

#include "stdafx.h"
#include "wrphelp.h"
#include "scarddef.h"

///////////////////////////////////////////////////////////////////////////
// Macros
//
#ifdef _DEBUG
    #define TRACE_STR(name,sz) \
                TRACE(_T("WrpHelp Classes::%s: %s\n"), name, sz)
    #define TRACE_CODE(name,code) \
                TRACE(_T("WrpHelp Classes::%s: error = 0x%x\n"), name, code)
    #define TRACE_CATCH(name,code)      TRACE_CODE(name,code)
    #define TRACE_CATCH_UNKNOWN(name)   TRACE_STR(name,_T("An unidentified exception has occurred!"))
#else
    #define TRACE_STR(name,sz)          ((void)0)
    #define TRACE_CODE(name,code)       ((void)0)
    #define TRACE_CATCH(name,code)      ((void)0)
    #define TRACE_CATCH_UNKNOWN(name)   ((void)0)
#endif  // _DEBUG


///////////////////////////////////////////////////////////////////////////////
//
// Construction and Destruction
//

/*++

CCriticalSection::CCriticalSection

    This method implements the constructor for CCriticalSection

Arguments:

    None

Return Value:

    None

Author:

--*/

CCriticalSection::CCriticalSection()
{
    // locals

    // Initialize the internal critical section object
    try
    {
        ::InitializeCriticalSection(&m_CriticalSection);
    }

    catch (...)
    {
        TRACE_CATCH_UNKNOWN(_T("CCriticalSection"));
    }
}


/*++

CCriticalSection::~CCriticalSection

    This method implements the destructor for CCriticalSection

Arguments:

    None

Return Value:

    None

Author:

--*/
CCriticalSection::~CCriticalSection()
{
    // locals

    try
    {
        ::DeleteCriticalSection(&m_CriticalSection);
    }

    catch (...)
    {
        TRACE_CATCH_UNKNOWN(_T("~CriticalSection"));
    }
}


/////////////////////////////////////////////////////////////////////////////////////
//
// CCriticalSection
//

/*++

CCriticalSection::EnterCriticalSection

    This routines puts the internal critical section
    object into the non-signaled state

Arguments:

    None

Return Value:

    None

Author:

--*/
CCriticalSection::EnterCriticalSection()
{
    // Locals
    BOOL    fResult = FALSE;

    try
    {
        ::EnterCriticalSection(&m_CriticalSection);

        // Ok...
        fResult = TRUE;
    }

    catch (...)
    {
        TRACE_CATCH_UNKNOWN(_T("EnterCriticalSection"));
    }

    return fResult;
}


/*++

CCriticalSection::ExitCriticalSection

    This routines puts the internal critical section
    object into the signaled state

Arguments:

    None

Return Value:

    None

Author:

    Chris Dudley (cdudley) 2/6/1997

--*/
CCriticalSection::ExitCriticalSection()
{
    // Locals
    BOOL        fResult = FALSE;

    try
    {
        ::LeaveCriticalSection(&m_CriticalSection);

        // Ok...
        fResult = TRUE;
    }

    catch (...)
    {
        TRACE_CATCH_UNKNOWN(_T("EnterCriticalSection"));
    }

    return fResult;
}


///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// CGrabData
//

/*++

CGrabData::GetExtraData

    This routine calls the ISO7816-4 command GetResponse to get additional
    data from the card and return it in the IByteBuffer (aka IStream)

Arguments:

    ppDataOut - pointer to a pointer to an IByteBuffer. If this pointer is
                NULL, the IStream will be created but MUST be release in caller's
                code.
    pwCmdStatus - (IN) The status word (SW1/SW2) returned from the initial smart card
                command.
                 (OUT) the final status word.
    pdwDataLength - (OUT) Total number of bytes written into the buffer.

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return                      Meaning
    ======                      =======
    E_INVALIDARG                An argument was invalid or unrecognizable.
    E_OUTOFMEMORY               No free memory in process address space
                                to create requested object.
    E_UNEXPECTED                One of the parameters was of an unexpected
                                type or value.
    S_OK                        Command successful.

Author:

Notes:

    This routine expects (*pwCmdStatus) to contain a 0x61xx response code where
    xx is the number of bytes to be retrieved by the GetResponse.

--*/
HRESULT CGrabData::GetExtraData(LPBYTEBUFFER *ppDataOut,
                                WORD *pwCmdStatus,
                                LONG *plDataLength)
{
    // Locals
    HRESULT         hresult = S_OK;
    LONG            lSize;
    LPBYTEBUFFER    pBuffer = NULL;
    ULARGE_INTEGER  liBytesToCopy,
        liBytesRead,
        liBytesWritten,
        liLength;

    try
    {
        // clear length
        (*plDataLength) = 0;
        // Create buffers if needed...1 for GetResponse, another to copy into
        if ((*ppDataOut) == NULL)
        {
            hresult = SspCreateByteBuffer((ULONG) 1, ppDataOut);
            if (FAILED(hresult))
                throw (hresult);
        };// if
        hresult = SspCreateByteBuffer((ULONG) 1, &pBuffer);
        if (FAILED(hresult))
            throw (hresult);
        // Check status
        m_wReplyStatus = (*pwCmdStatus);
        while (HIBYTE(m_wReplyStatus) == SC_STATUS_MOREDATA)
        {
            lSize = LOBYTE( m_wReplyStatus );
            // Build the command
            hresult = m_pISCardISO7816->GetResponse((BYTE) 0,
                                                    (BYTE) 0,
                                                    lSize,
                                                    &m_pISCardCmd);
            if (FAILED(hresult))
                throw (hresult);

            // Force correct class id for the vendor's card
            hresult = m_pISCardCmd->put_ClassId(VENDOR_CLASS_ID);
            if (FAILED(hresult))
                throw (hresult);

            // Do transaction
            hresult = m_pISCard->LockSCard();
            if (FAILED(hresult))
                throw (hresult);
            hresult = m_pISCard->Transaction(&m_pISCardCmd);
            if (FAILED(hresult))
                throw (hresult);
            hresult = m_pISCard->UnlockSCard(LEAVE);
            if (FAILED(hresult))
                throw (hresult);
            // Interpret response
            hresult = m_pISCardCmd->get_ApduReplyLength(&m_lReplyLength);
            if (FAILED(hresult))
                throw (hresult);
            hresult = m_pISCardCmd->get_ReplyStatus( &m_wReplyStatus );
            if (FAILED(hresult))
                throw (hresult);
            if ((m_wReplyStatus != SC_STATUS_SUCCESS) &&
                (HIBYTE(m_wReplyStatus) != SC_STATUS_MOREDATA ))
                throw ( (HRESULT) E_FAIL);

            // Get reply data
            hresult = m_pISCardCmd->get_ApduReply( &pBuffer );
            if (FAILED(hresult))
                throw (hresult);

            // Copy it into given Internal IStream. First set new Length.
            // Don't REALLY have to do this. The IStream Copy would take care of it...
            (*plDataLength) += m_lReplyLength;
            LISet32 (liLength, (*plDataLength));
            hresult = (*ppDataOut)->SetSize((LONG) liLength.LowPart);
            if (FAILED(hresult))
                throw (hresult);
            LISet32 (liBytesToCopy, m_lReplyLength );
            hresult = (pBuffer)->CopyTo(ppDataOut,
                                        (LONG) liBytesToCopy.LowPart,
                                        (LONG*) &(liBytesRead.LowPart),
                                        (LONG*) &(liBytesWritten.LowPart));
            if (FAILED(hresult))
                throw (hresult);
        }; //while
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("GetResultData"),hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("GetResultData"));
    }

    // Release resources...Cleanup
    if (pBuffer != NULL)
        while (pBuffer->Release()>0);

    (*pwCmdStatus) = m_wReplyStatus;

    return hresult;
}


//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
//
//  Various Useful routines
//

/*++

SspCreateByteArray:

    This routine creates an array of bytes.

Arguments:

    dwAllocSize - Size in bytes of the memory to be allocated for the array.

    ppbyArray - Points to the created byte array to be returned.

    pExceptInfo - Points to an OLE exception block which contains extended
        information about any failure that might occur. Can be set to
        NULL if the exception information is not desired.

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            The byte array was created successfully.
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

HRESULT
    SspCreateByteArray(
                      IN DWORD dwAllocSize,
                      OUT LPBYTE *ppbyArray,
                      OUT OPTIONAL EXCEPINFO* pExceptInfo)
{
    // Locals.
    HRESULT hr = S_OK;
    HGLOBAL hMem = NULL;
    LPBYTE pObj = NULL;
    DWORD dwErr = NO_ERROR;

    try
    {
        // Initialize the parameters.
        (*ppbyArray) = NULL;

        // Is caller asking for a reasonable array size?
        if (dwAllocSize <= 0)
            throw ( (HRESULT) E_INVALIDARG);

        // Allocate the memory for the array from the system.
        hMem = ::GlobalAlloc(GHND, dwAllocSize);
        if (hMem == NULL)
        {
            dwErr = ::GetLastError();
            throw (HRESULT_FROM_WIN32(dwErr));
        }

        // Map the memory for use.
        pObj = (LPBYTE) GlobalLock(hMem);
        if (pObj == NULL)
        {
            dwErr = ::GetLastError();
            throw (HRESULT_FROM_WIN32(dwErr));
        }
        ASSERT(pObj != NULL);

        // Ok, pack for return.
        (*ppbyArray) = pObj;
    }

    catch (HRESULT hrStatus)
    {
        hr = hrStatus;
        TRACE_CATCH(_T("SspCreateByteArray"),hrStatus);
        if (pObj!=NULL)
            ::GlobalUnlock(hMem);
        if (hMem!=NULL)
            ::GlobalFree(hMem);
        switch (hr)
        {
        case E_UNEXPECTED:
        case E_POINTER:
        case E_INVALIDARG:
            ::SetLastError( (DWORD) ERROR_INVALID_PARAMETER);
            break;

        case S_FALSE:
        case E_FAIL:
            ::SetLastError((DWORD) ERROR_NOT_SUPPORTED);
            break;

        case E_ACCESSDENIED:
            ::SetLastError((DWORD)ERROR_ACCESS_DENIED);
            break;

        case E_HANDLE:
            ::SetLastError((DWORD) ERROR_INVALID_HANDLE);
            break;

        case E_OUTOFMEMORY:
            ::SetLastError((DWORD) ERROR_OUTOFMEMORY);
            break;

        default:
            ::SetLastError(dwErr);
            break;
        }
    }

    catch (...)
    {
        TRACE_CATCH_UNKNOWN(_T("SspCreateByteArray"));
        if (pObj != NULL)
            ::GlobalUnlock(hMem);
        if (hMem != NULL)
            ::GlobalFree(hMem);
        ::SetLastError( (DWORD) ERROR_INVALID_PARAMETER);
        hr = (HRESULT) E_UNEXPECTED;
    }

    return(hr);
}


/*++

SspConvertDwordToByte:

    This function will convert a DWORD to an array of BYTEs.

Arguments:

    dwNum - DWORD number to be converted.

    ppbyArray - Points to the byte array created to hold the converted
        DWORD if successful; else, NULL!

    pdwByteArraySize - Optional pointer to how big was the byte array
        created to hold the DWORD is.

    pExceptInfo - Points to an OLE exception block which contains extended
        information about any failure that might occur. Can be set to
        NULL if the exception information is not desired.

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return              Meaning
    ======              =======
    S_OK                Operation completed successfully.
    S_FALSE             Unknown error.
    E_OUTOFMEMORY       There is not enough memory in this process to
                        satisfy the request.
    E_FAIL              Unspecified error.
    E_INVALIDARG        One or more arguments are invalid.
    E_POINTER           Invalid pointer.
    E_UNEXPECTED        Unexpected event occurred in this function.
    E_HANDLE            Invalid handle.
    E_ACCESSDENIED      Access to resource is denied.

Author:

--*/

HRESULT
    SspConvertDwordToByte(
                         IN DWORD dwNum,
                         OUT LPBYTE *ppbyArray,
                         OUT LPDWORD pdwByteArraySize,
                         OUT OPTIONAL EXCEPINFO* pExceptInfo)
{
    // Locals.
    LPBYTE pbyBuff = NULL;
    HRESULT hr = S_OK;
    DWORD dwSize = 0;

    try
    {
        // Initialize...
        if ((*ppbyArray))
            (*ppbyArray) = NULL;
        if (pdwByteArraySize)
            (*pdwByteArraySize) = 0;

        // Determine the appropriately sized byte array needed
        // to hold DWORD.
        if (dwNum <= 0xFF)
            dwSize = 1;
        else if (dwNum <= 0xFFFF)
            dwSize = 2;
        else if (dwNum <= 0xFFFFFF)
            dwSize = 3;
        else
            throw ( (HRESULT) E_INVALIDARG);

        // Create the byte array.
        hr = SspCreateByteArray(dwSize,
                                &pbyBuff,
                                NULL);
        if (FAILED(hr))
            throw (hr);
        if (pbyBuff == NULL)
            throw ( (HRESULT) E_OUTOFMEMORY);
        ASSERT(pbyBuff != NULL);

        // Copy it!
        ::CopyMemory( (LPVOID) pbyBuff,
                      (CONST VOID*) &dwNum,
                      (DWORD) sizeof(DWORD) );

        // Package for return.
        *ppbyArray = pbyBuff;
        if (pdwByteArraySize != NULL)
            (*pdwByteArraySize) = dwSize;
    }

    catch (HRESULT hrStatus)
    {
        hr = hrStatus;
        TRACE_CATCH(_T("SspConvertDwordToByte"),hrStatus);
        switch (hr)
        {
        case E_UNEXPECTED:
        case E_POINTER:
        case E_INVALIDARG:
            ::SetLastError((DWORD) ERROR_INVALID_PARAMETER);
            break;

        case S_FALSE:
        case E_FAIL:
            ::SetLastError((DWORD) ERROR_NOT_SUPPORTED);
            break;

        case E_ACCESSDENIED:
            ::SetLastError((DWORD) ERROR_ACCESS_DENIED);
            break;

        case E_HANDLE:
            ::SetLastError((DWORD) ERROR_INVALID_HANDLE);
            break;

        case E_OUTOFMEMORY:
            ::SetLastError((DWORD) ERROR_OUTOFMEMORY);
            break;
        }
    }

    catch (...)
    {
        TRACE_CATCH_UNKNOWN(_T("SspConvertDwordToByte"));
        ::SetLastError((DWORD) ERROR_INVALID_PARAMETER);
        hr = (HRESULT) E_UNEXPECTED;
    }

    return(hr);
}


/*++

SspFreeByteArray:

    This routine frees a byte array (aka a block of HGLOBAL memory).

Arguments:

    pbyArray - Points to the byte array to be freed.

    pExceptInfo - Points to an OLE exception block which contains extended
        information about any failure that might occur. Can be set to
        NULL if the exception information is not desired.

Return Value:

    A HRESULT value indicating the status of the requested action.

    Return          Meaning
    ======          =======
    S_OK            The byte array was created freed.
    S_FALSE         Unknown error.
    E_OUTOFMEMORY   There is not enough memory in this process to
                    satisfy the request.
    E_FAIL          Unspecified error.
    E_INVALIDARG    One or more arguments are invalid.
    E_UNEXPECTED    Unexpected fault has occurred.
    E_POINTER       Invalid pointer.
    E_HANDLE        Invalid handle.
    E_ACCESSDENIED  Access to resource is denied.

Author:

--*/

HRESULT
    SspFreeByteArray(
                    IN LPBYTE pbyArray,
                    OUT OPTIONAL EXCEPINFO* pExceptInfo)
{
    // Locals.
    DWORD dwErr = NO_ERROR;
    HGLOBAL hMem = NULL;
    HRESULT hr = S_OK;

    try
    {
        // Is the parameter-list ok?
        if (pbyArray == NULL)
            throw ( (HRESULT) E_POINTER);

        // Get access to the string's memory block.
        hMem = ::GlobalHandle((LPCVOID) pbyArray);
        if (hMem == NULL)
        {
            dwErr = ::GetLastError();
            throw (HRESULT_FROM_WIN32(dwErr));
        }
        ASSERT(hMem != NULL);

        // Decrement the memory block's reference count.
        while (::GlobalUnlock(hMem));
        dwErr = ::GetLastError();
        if (dwErr != NO_ERROR)
            throw (HRESULT_FROM_WIN32(dwErr));

        // Free the memory!
        hMem = ::GlobalFree(hMem);
        if (hMem == NULL)
        {
            dwErr = ::GetLastError();
            throw (HRESULT_FROM_WIN32(dwErr));
        }
        ASSERT(hMem == NULL);
    }

    catch (HRESULT hrStatus)
    {
        hr = hrStatus;
        TRACE_CATCH(_T("SspFreeByteArray"),hrStatus);
        switch (hr)
        {
        case E_UNEXPECTED:
        case E_POINTER:
        case E_INVALIDARG:
            ::SetLastError((DWORD) ERROR_INVALID_PARAMETER);
            break;

        case S_FALSE:
        case E_FAIL:
            ::SetLastError((DWORD) ERROR_NOT_SUPPORTED);
            break;

        case E_ACCESSDENIED:
            ::SetLastError((DWORD) ERROR_ACCESS_DENIED);
            break;

        case E_HANDLE:
            ::SetLastError((DWORD) ERROR_INVALID_HANDLE);
            break;

        case E_OUTOFMEMORY:
            ::SetLastError((DWORD) ERROR_OUTOFMEMORY);
            break;

        default:
            ::SetLastError(dwErr);
            break;
        }
    }

    catch (...)
    {
        TRACE_CATCH_UNKNOWN(_T("SspFreeByteArray"));
        ::SetLastError((DWORD) ERROR_INVALID_PARAMETER);
        hr = (HRESULT) E_UNEXPECTED;
    }

    return(hr);
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
        TRACE_CATCH(_T("SspCreateByteBuffer"),hrStatus);
    }

    catch (...)
    {
        TRACE_CATCH_UNKNOWN(_T("SspCreateByteBuffer"));
        hr = E_UNEXPECTED;
    }

    // Clean up
    if (lpClassFactory!=NULL)
        lpClassFactory->Release();

    return (hr);
}

