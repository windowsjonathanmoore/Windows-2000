/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

----------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////////////////////
//
// Includes
//

#include "stdafx.h"
#include "SCardCOM.h"
#include "SCardFil.h"

#include "scarddef.h"

///////////////////////////////////////////////////////////////////////////
// Macros
//
#ifdef _DEBUG
    #define TRACE_STR(name,sz) \
                TRACE(_T("SCardCOM.DLL: CSCardFileAccess::%s: %s\n"), name, sz)
    #define TRACE_CODE(name,code) \
                TRACE(_T("SCardCOM.DLL: CSCardFileAccess::%s: error = 0x%x\n"), name, code)
    #define TRACE_CATCH(name,code)      TRACE_CODE(name,code)
    #define TRACE_CATCH_UNKNOWN(name)   TRACE_STR(name,_T("An unidentified exception has occurred!"))
#else
    #define TRACE_STR(name,sz)          ((void)0)
    #define TRACE_CODE(name,code)       ((void)0)
    #define TRACE_CATCH(name,code)      ((void)0)
    #define TRACE_CATCH_UNKNOWN(name)   ((void)0)
#endif  // _DEBUG

/*++

CSCardFileAccess::FinalConstruct:

    This routine defines a final constructor that is called after the constructor
    for the template class is called.

Arguments:

    None

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

--*/

HRESULT CSCardFileAccess::FinalConstruct()
{
    // Locals.
    HRESULT hresult = S_OK;

    try
    {
        m_iOpenFiles = 0;
        m_FileInfoMap.InitHashTable(13);
        m_hfileNextHandle = 1;
        m_wCurrentFileID = 0x3f00;
        m_Manage = NULL;
    }

    catch (...)
    {
        hresult = E_UNEXPECTED;
        TRACE_CATCH(_T("FinalConstruct"), hresult);
    }

    return(hresult);
}


/*++

CSCardFileAccess::FinalRelease:

    This routine defines a final release.

Arguments:

    None

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

--*/

HRESULT CSCardFileAccess::FinalRelease()
{
    // Locals.
    HRESULT hresult = S_OK;

    try
    {
        // Decrement the reference count on the "creation" object
        if (m_Manage != NULL)
            m_Manage->Release();
    }

    catch (...)
    {
    }

    return(hresult);
}


/*++

CSCardFileAccess::ConvertFilename

    This routine converts a filename (BSTR) to a word for internal use
    as the file ID. BSTR MUST be in hex!

Arguments:

    bstrFilename - filename as BSTR

Return Value:

    A word containing the filename or 0 if failed.

Author:

Note:

--*/

WORD CSCardFileAccess::ConvertFilename( BSTR bstrFilename)
{
    //locals
    WORD    wFileID = 0;
    int     nStringLength = ::SysStringLen(bstrFilename);
    LPTSTR  pszBuffer,
            pszEndBuffer;
    HLOCAL  hMem = NULL;
    DWORD   dwErr;
#ifdef _UNICODE
    int     nNewStrLen = sizeof(WCHAR);
#else
    int     nNewStrLen = sizeof(char);
#endif

    m_CriticalSection.EnterCriticalSection();

    try
    {
        if ((nStringLength > SC_FILE_ID_STR_LENGTH) || (nStringLength <=0))
            throw ( (HRESULT) E_INVALIDARG );
        // Alloc mem for BSTR to LPTSTR conversion if required
        nNewStrLen *= nStringLength;
        nNewStrLen++;  //For NULL termination
#ifdef _UNICODE
        pszBuffer = (LPTSTR) bstrFileName;
#else
        hMem = ::LocalAlloc(LPTR, (UINT) nNewStrLen);
        if (hMem == NULL)
        {
            dwErr = ::GetLastError();
            throw (HRESULT_FROM_WIN32(dwErr));
        };
        pszBuffer = (LPTSTR) ::LocalLock(hMem);
        if (pszBuffer == NULL)
        {
            dwErr = ::GetLastError();
            throw (HRESULT_FROM_WIN32(dwErr));
        };
        // Convert wide char to ansi string
        WideCharToMultiByte(    CP_ACP,
                                0,
                                bstrFilename,
                                nStringLength,
                                pszBuffer,
                                nNewStrLen,
                                NULL,
                                NULL );
#endif
        // Now convert to WORD...
        pszEndBuffer = pszBuffer + nStringLength;
        // Use correct conversion per UNICODE
#ifdef _UNICODE
        wFileID = (WORD) wcstol( pszBuffer , &pszEndBuffer, 16);
#else
        wFileID = (WORD) strtol( pszBuffer , &pszEndBuffer, 16);
#endif
    }

    catch (...)
    {
        wFileID = 0;
        TRACE_CATCH(_T("ConvertFilename"), wFileID);
    }

    // Eliminate the temp buffer
    while (::LocalUnlock(hMem));
    // At this point, ::GetLastError() should equal NO_ERROR!
    if (::LocalFree(hMem) != NULL)
    {
        wFileID = 0;
    }

    m_CriticalSection.ExitCriticalSection();

    return wFileID;
}


/*++

CSCardFileAccess::CreateFileHandle

    This routine creates a file handle.

Arguments:

    None

Return Value:

    A HSCARD_FILE handle or 0 if call failed.

Author:

--*/
HSCARD_FILE CSCardFileAccess::CreateFileHandle()
{
    // locals
    HSCARD_FILE hFile = 0;

    m_CriticalSection.EnterCriticalSection();

    try
    {
        // Simple generation based on successive HSCARD_FILE values.
        if (m_hfileNextHandle == MAX_HANDLE_VALUE)
            throw(hFile = 0);
        hFile = m_hfileNextHandle;
        m_hfileNextHandle++;
    }

    catch (HSCARD_FILE handle)
    {
        hFile = handle;
        TRACE_CATCH(_T("CreateFileHandle"), hFile);
    }

    catch (...)
    {
        hFile = 0;
        TRACE_CATCH_UNKNOWN(_T("CreateFileHandle"));
    }

    m_CriticalSection.ExitCriticalSection();

    return hFile;
}

/*++

CSCardFileAccess::FileSelect

    This routine selects file/changes directory on the ICC.

Arguments:

    sFilePath - 2-byte file ID of file to be selected

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

    FCI is requested but NOT stored within this object. To store
    the FCI data, create a IByteBuffer (aka IStream) and call
    ISCard->get_ReplyApdu(..).

--*/

HRESULT CSCardFileAccess::FileSelect( WORD wFilePath )
{
    HRESULT         hresult = S_OK;
    LPBYTEBUFFER    pData = NULL,
                    pResultData = NULL;
    ULONG           ulLength = 1L,
                    ulBytesWritten = 0;
    BYTE            byID = 0,
                    byP1 = 0,
                    byP2 = 0;
    LPSCARDCMD      pCmd = NULL;

    m_CriticalSection.EnterCriticalSection();

    try
    {
        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        if (ulLength>MAX_PATH_LEN)
            throw ( (HRESULT) E_INVALIDARG );

        // Create Cmd Object
        hresult = m_Manage->CreateCmdObject(&pCmd);
        if (FAILED(hresult))
            throw (hresult);

        // Create Data grabber
        CGrabData   GrabData(pCmd,
                             m_Manage->m_pISCard,
                             m_Manage->m_pISCardISO7816);

        // Create a byte buffer for ISO call
        hresult = SspCreateByteBuffer(ulLength, &pData);
        if (FAILED(hresult))
            throw (hresult);

        // Write data to the buffer - High byte of file ID first!
        byID = HIBYTE(wFilePath);
        pData->Write( (BYTE*) &byID, (LONG) ulLength, (LONG*) &ulBytesWritten );
        byID = LOBYTE(wFilePath);
        pData->Write( (BYTE*) &byID, (LONG) ulLength, (LONG*) &ulBytesWritten );

        // Create the p1-p2 paramters
        byP1 = SC_ID_MF_DF_EF;
        byP2 = (SC_ONLY_OCCUR | SC_RETURN_FCI);
        // ISO7186 COM builds command
        hresult = m_Manage->m_pISCardISO7816->SelectFile(byP1,
                                                         byP2,
                                                         pData,
                                                         0,
                                                         &pCmd);


        if (FAILED(hresult))
            throw hresult;

        // Force correct class id for the vendor's card
        hresult = pCmd->put_ClassId(VENDOR_CLASS_ID);
        if (FAILED(hresult))
            throw (hresult);

        hresult = m_Manage->m_pISCard->LockSCard();
        if (FAILED(hresult))
            throw (hresult);
        hresult = m_Manage->m_pISCard->Transaction(&pCmd);
        if (FAILED(hresult))
            throw (hresult);
        hresult = m_Manage->m_pISCard->UnlockSCard(LEAVE);
        if (FAILED(hresult))
            throw (hresult);

        //interpret return APDU
        hresult = pCmd->get_ApduReplyLength(&m_lReplyLength);
        if (FAILED(hresult))
            throw (hresult);
        hresult = pCmd->get_ReplyStatus( &m_wReplyStatus );
        if (FAILED(hresult))
            throw (hresult);
        if (HIBYTE(m_wReplyStatus)==SC_STATUS_MOREDATA)
        {
            hresult = GrabData.GetExtraData(&pResultData,
                                            &m_wReplyStatus,
                                            &m_lReplyLength);
            if (FAILED(hresult))
                throw (hresult);
            // Todo: Store returned file specfic data??
        }
        else if (m_wReplyStatus!=SC_STATUS_SUCCESS)
            throw ( (HRESULT) E_FAIL );
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("FileSelect"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("FileSelect"));
    }

    // Free the ByteBuffer
    if (pData != NULL)
        pData->Release();
    if (pResultData != NULL)
        pResultData->Release();
    // Release cmd interface
    if (pCmd != NULL)
        pCmd->Release();

    m_CriticalSection.ExitCriticalSection();

    return hresult;
}


/////////////////////////////////////////////////////////////////////////////
//
// ISCardFileAccess Methods
//


/*++

CSCardFileAccess::ChangeDir:

    This method changing the current smartcard directory to the new
    specified directory.

Arguments:

    refType - specifies the type of reference used in PathSpec as follows
                SC_TYPE_BY_NAME
                SC_TYPE_BY_ID
                SC_TYPE_BY_SHORT_ID
                SC_TYPE_BY_ANY
              in this example code we are only supporting SC_TYPE_BY_ID

    NewDir - Specifies an File to select. (It must be < 4 for this example.)

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

    This example code and assumes a ISO7816 supported file structure on
    the ICC and passes the given bstrNewDir directly too the corresponding ISO7816
    command as an absolute path only (i.e. beginning from MF).

--*/

STDMETHODIMP CSCardFileAccess::ChangeDir(
                                        REFTYPE refType,
                                        BSTR bstrNewDir)
{
    //locals
    HRESULT hresult = S_OK;
    WORD    wFileID;

    try
    {
        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        // only supporting SC_TYPE_BY_ID
        if (refType != SC_TYPE_BY_ID)
            throw ( (HRESULT) E_INVALIDARG );
        // convert and store
        wFileID = ConvertFilename(bstrNewDir);
        hresult = FileSelect(wFileID);
        if (FAILED(hresult))
            throw (hresult);
        // success...store the path
        m_wCurrentFileID = wFileID;
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("ChangeDir"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("ChangeDir"));
    }

    return hresult;
}

/*++

CSCardFileAccess::Close:

        This method closes the specified file. No further access to file is
        allowed.

Arguments:

    hFile - An HSCARD_FILE to the file to be closed.

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

    Use of Open or Close methods involves updating an internal CMap object which
    tracks the current open file information (handle, name, etc).

--*/

STDMETHODIMP CSCardFileAccess::Close(
                                    HSCARD_FILE hFile)
{
    //locals
    HRESULT                         hresult = S_OK;
    FILE_INFORMATION        FileInfo;


    try
    {
        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        m_CriticalSection.EnterCriticalSection();
        // Lookup the handle in the file map
        if (!m_FileInfoMap.Lookup(hFile, FileInfo))
            throw ( (HRESULT) E_HANDLE);

        if (!m_FileInfoMap.RemoveKey(hFile))
            throw ( (HRESULT) E_FAIL);
        m_CriticalSection.ExitCriticalSection();
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Close"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Close"));
    }

    return hresult;
}


/*++

CSCardFileAccess::Create:

        The method creates a file at a given location within the smartcard file
        system.

Arguments:

    refType - Specifies the type of file to be created (directory, fixed length,
        etc.)

    bstrPathSpec - specifies file to be created within current context

    ppTLVs - list of TLV structures, with file properties that have to be set.

    lpcTLVs -- number of entries in TLV

    Flags - specifies whether Secure Messaging should be used and data
    pre-allocated

    pDataBuffer - pointer to pre-allocated data

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

--*/

STDMETHODIMP CSCardFileAccess::Create(
                                     REFTYPE refType,
                                     BSTR bstrPathSpec,
                                     LPTLV_TABLE* ppTLVs,
                                     LONG* lpcTLVs,
                                     SCARD_FLAGS Flags,
                                     LPBYTEBUFFER pDataBuffer)
{
    //locals
    HRESULT         hresult = E_NOTIMPL;

    // to do
    // This method should be implemented if the ICC supports this command.

    return hresult;
}


/*++

CSCardFileAccess::Delete:

    The method deletes a file at a given location.

Arguments:

    refType - references filename type (ID, short ID, etc) used in
        bstrPathSpec.

    bstrPathSpec - specifies file to be deleted

    Flags - specifies whether secure messaging should be used. In the case of a
        directory file(DF), this parameter specifies whether complete tree below the
        dir should be deleted

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

Note:

    This is an EXAMPLE of using ISO7816 Erase Binary to remove a file. This should
    be updated to support your specific ICC and file type(s).

--*/

STDMETHODIMP CSCardFileAccess::Delete(
                                     REFTYPE refType,
                                     BSTR bstrPathSpec,
                                     SCARD_FLAGS Flag)
{
    //locals
    HRESULT         hresult = E_NOTIMPL;

    try
    {
        // Todo:
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Delete"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Delete"));
    }

    return hresult;
}


/*++

CSCardFileAccess::Directory:

        Retrieve a list of files of the specified type.

Arguments:

    fileType - specifies the type of files to be listed

    ppFileList - returned list of specified files as array of BSTRs

    Part 6 of the PC/SC Interoperability Specification for ICCs and Personal
    Computer Systems calls for a variable describing the length of ppFileList;
    as BSTRs include their length, this variable is excluded from this
    example implementation.

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

--*/

STDMETHODIMP CSCardFileAccess::Directory(
                                        FILETYPE fileType,
                                        LPSAFEARRAY *ppFileList)
{
    //locals
    HRESULT         hresult = E_NOTIMPL;

    // to do
    // This method should be implemented if the ICC supports this command.

    return hresult;
}


/*++

CSCardFileAccess::GetCurrentDirectory:

    This method returns an absolute path to the currently selected directory

Arguments:

    pbstrPathSpec - pointer to a BSTR containing the path

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

    1)  The calling application MUST free this global memory allocated for
        the BSTR.

--*/

STDMETHODIMP CSCardFileAccess::GetCurrentDir(
                                            BSTR* pbstrPathSpec)
{
    //locals
    HRESULT         hresult = E_NOTIMPL;

    // Todo:
    // Add return directory code.

    return hresult;
}


/*++

CSCardFileAccess::GetFileCapabilities

    Retrieve list of file capabilities.

Arguments:

    ppProperties - list of TLV_TABLE structures indicating the files for which
        to get properties on input, and containing those properties on output.

    plProperties - pointer to LONG containing the number of elements in
        pProperties

    Flags - flags

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

--*/
STDMETHODIMP CSCardFileAccess::GetFileCapabilities(
                                                  LPTLV_TABLE* ppProperties,
                                                  LONG *plProperties,
                                                  SCARD_FLAGS Flags)
{
    //locals
    HRESULT         hresult = E_NOTIMPL;

    // to do
    return hresult;
}


/*++

CSCardFileAccess::GetProperties

    Retrieve the primitive data refered by tags (TLV) for the specified
    object

Arguments:

    refType - specifies the type of reference to the file

    bstrPathSpec - specifies the file to use.

    ppTLV - point to TLV structs whose value has been retrieved.

    plcTLV - number of entries in ppTLV

    Flags - specifies whether Secure Messaging has to be used.

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

--*/

STDMETHODIMP CSCardFileAccess::GetProperties(
                                            REFTYPE refType,
                                            BSTR bstrPathSpec,
                                            LPTLV_TABLE* ppTLV,
                                            LONG* plcTLV,
                                            SCARD_FLAGS Flags)
{
    //locals
    HRESULT         hresult = E_NOTIMPL;

    // to do
    return hresult;
}


/*++

CSCardAuth::Initialize

    Initializes the object for use.

Arguments:

    lp - a long pointer to the "controlling" ISCardManage object.

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

--*/
STDMETHODIMP CSCardFileAccess::Initialize( LONG *lp)
{
    // Locals
    HRESULT         hresult = S_OK;

    try
    {
        // Check Params, etc..
        if (lp == NULL)
            throw ( (HRESULT) E_INVALIDARG );

        if (m_Manage != NULL)
            throw ( (HRESULT) E_FAIL );

        // Ok...
        m_Manage = (LPCSCARDMANAGE) lp;
    }

    catch (HRESULT hr)
    {
        hresult=hr;
        TRACE_CATCH(_T("Initialize"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Initialize"));
    }

    return(hresult);
}


/*++

CSCardFileAccess::Invalidate:

    Invalidate the specified file (EF or DF). An invalidated file cannot
    be accessed by other methods prior to using rehabilitate

Arguments:

    bstrPathSpec - specifies file to be invalidated (relative path)

    Flag - specifies whether Secure Messaging is to be used

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

--*/

STDMETHODIMP CSCardFileAccess::Invalidate(
                                         BSTR bstrPathSpec,
                                         SCARD_FLAGS Flags)
{
    //locals
    HRESULT         hresult = E_NOTIMPL;

    // to do
    // This method should be implemented if the ICC supports this command.

    return hresult;
}


/*++

CSCardFileAccess::Open

    Opens the specified file for further use

Arguments:

    refType - Specifies the type of reference to the file

    bstrPathSpec - specifies the file to open.

    hFile - HSCARD_FILE to file if successful, NULL otherwise.

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

    This method DOES NOT read file headers. It defaults to setting the
    class type as transparent EF.

--*/

STDMETHODIMP CSCardFileAccess::Open(
                                   REFTYPE refType,
                                   BSTR bstrPathSpec,
                                   HSCARD_FILE *phFile)
{
    //locals
    HRESULT                         hresult = E_NOTIMPL;
    FILE_INFORMATION        FileInfo;
    WORD                            wFileID;

    try
    {
        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        if ((bstrPathSpec == NULL) || (phFile == NULL))
            throw ( (HRESULT) E_INVALIDARG );
        // Does file exist?
        wFileID = ConvertFilename(bstrPathSpec);
        if (wFileID == 0)
            throw ( (HRESULT) E_FAIL );

        hresult = FileSelect( wFileID );
        if (FAILED(hresult))
            throw (hresult);

        *phFile = CreateFileHandle();
        if (*phFile == 0)
            throw ( (HRESULT) E_FAIL);

        m_CriticalSection.EnterCriticalSection();
        // Create file info struct and add to map
        FileInfo.fileHandle = *phFile;
        FileInfo.fileStatus     = SC_FL_STAT_DEFAULT;
        FileInfo.wfileName = wFileID;
        // Assume transparent EF for this example.
        FileInfo.fileType = SC_TYPE_TRANSPARENT_EF;
        FileInfo.lSeekOffset = 0;
        m_FileInfoMap.SetAt(*phFile,FileInfo);
        m_CriticalSection.ExitCriticalSection();

    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Open"),hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Open"));
    }

    return hresult;
}


/*++

CSCardFileAccess::Read

    This method reads and returns the specifed data from a given file

Arguments:

    HSCARD_FILE - contains the handle of the file to access

    lBytesToRead - length of the data object to be read from file

    ppBuffer - if successful, contains the read data

    Flags - specifies whether Secure Messaging is to be used

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

    As is this routine mainly supports the write to a transparent EF. This
    is the default given to the file type on Open within this class.

--*/

STDMETHODIMP CSCardFileAccess::Read(
                                   HSCARD_FILE hFile,
                                   LONG *lBytesToRead,
                                   LPBYTEBUFFER *ppBuffer,
                                   SCARD_FLAGS Flags)
{
    //locals
    HRESULT             hresult = S_OK;
    FILE_INFORMATION    FileInfo;
    LPBYTEBUFFER        pData = NULL;
    LPSCARDCMD          pCmd = NULL;
    LONG                cbBufferSize = 0,
                        cbToRead = 0;
    BYTE                rgbyReadData[MAX_READ_LEN],
                        byP1 = 0,
                        byP2 = 0;
    WORD                wOffset = 0;
    LONG                lReplyLength = 0;
    LARGE_INTEGER       li;

    try
    {
        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        // Check Params...
        if (*lBytesToRead == NULL)
            throw ( (HRESULT) E_POINTER);
        if (*lBytesToRead <=0)
            throw ( (HRESULT) E_INVALIDARG );

        // Create return buffer if required
        if (*ppBuffer == NULL)
        {
            // Create z new buffer
            hresult = SspCreateByteBuffer((ULONG) *lBytesToRead, ppBuffer);
            if (FAILED(hresult))
                throw (hresult);
        };


        m_CriticalSection.EnterCriticalSection();
        // Check for valid handle
        if (!m_FileInfoMap.Lookup(hFile, FileInfo))
            throw ( (HRESULT) E_HANDLE );
        m_CriticalSection.ExitCriticalSection();
        // Change directory
        hresult = FileSelect(FileInfo.wfileName);
        if (FAILED(hresult))
            throw (hresult);

        // Create Cmd Object
        hresult = m_Manage->CreateCmdObject(&pCmd);
        if (FAILED(hresult))
            throw (hresult);

        // Set the size for amount of data to be read from file
        cbBufferSize = (*lBytesToRead);

        // set Seek position to the head of buffer where return data will be read
        LISet32 (li, BYTE_BUFFER_HEAD );
        hresult = (*ppBuffer)->Seek((LONG) li.LowPart,
                                    (LONG) STREAM_SEEK_SET,
                                    NULL);
        if (FAILED(hresult))
            throw hresult;

        // Loop to read complete file into retur buffer
        while (cbBufferSize > 0)
        {
            // Determine amount of data to write
            if (cbBufferSize <= MAX_READ_LEN)
            {
                // Set bytes to read
                cbToRead = cbBufferSize;
                // Last time through, clear it
                cbBufferSize = 0;
            }
            else
            {
                // Read max bytes
                cbToRead = MAX_READ_LEN;
                // Decrement total number bytes remaining to read
                cbBufferSize -= MAX_READ_LEN;
            };

            // Build correct command based on file type
            switch (FileInfo.fileType)
            {
            case SC_TYPE_TRANSPARENT_EF:
                byP1 = HIBYTE(wOffset);
                byP2 = LOBYTE(wOffset);
                // Build Update command for TRANSPARENT (i.e. Binary) file
                hresult = m_Manage->m_pISCardISO7816->ReadBinary(   byP1,
                                                                    byP2,
                                                                    cbToRead,
                                                                    &pCmd);
                if (FAILED(hresult))
                    throw (hresult);
                // Calculate the new offset for the command
                wOffset += (WORD) cbToRead;
                break;
            default:
                break;
            };// switch


            // Force correct class id for the vendor's card
            hresult = pCmd->put_ClassId(VENDOR_CLASS_ID);
            if (FAILED(hresult))
                throw (hresult);

            // Do complete transaction
            hresult = m_Manage->m_pISCard->LockSCard();
            if (FAILED(hresult))
                throw (hresult);
            hresult = m_Manage->m_pISCard->Transaction(&pCmd);
            if (FAILED(hresult))
                throw (hresult);
            hresult = m_Manage->m_pISCard->UnlockSCard(LEAVE);
            if (FAILED(hresult))
                throw (hresult);

            // Get status of command
            hresult = pCmd->get_ReplyStatus( &m_wReplyStatus );
            if (FAILED(hresult))
                throw (hresult);
            if (m_wReplyStatus != SC_STATUS_SUCCESS)
                throw ( (HRESULT) E_FAIL );

            // Get reply data (i.e. the data that was read from file) and length
            hresult = pCmd->get_ApduReply( &pData );
            if (FAILED(hresult))
                throw (hresult);
            hresult = pCmd->get_ApduReplyLength(&lReplyLength);
            if (FAILED(hresult))
                throw (hresult);
            if (lReplyLength<0)
                throw ((HRESULT) E_FAIL);


            // Set Seek pointer of return buffer
            hresult = pData->Seek(  (LONG) li.LowPart,
                                    (LONG) STREAM_SEEK_SET,
                                    NULL);
            if (FAILED(hresult))
                throw hresult;
            // Read reply data into temp buffer
            hresult = pData->Read(  (LPBYTE) rgbyReadData,
                                    (LONG) (lReplyLength-2), //Read reply data-status bytes
                                    NULL);
            if (FAILED(hresult))
                throw (hresult);
            // Write temp buffer back into return buffer
            hresult = (*ppBuffer)->Write(   (LPBYTE) rgbyReadData,
                                            (LONG) (lReplyLength-2), //Read reply data-status bytes
                                            NULL);
            if (FAILED(hresult))
                throw (hresult);
            // Release the Reply buffer
            if (pData != NULL)
                pData->Release();
        }; //while - write buffer
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Read"),hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Read"));
    }

    // Clean Up
    if (pCmd != NULL)
        pCmd->Release();

    return hresult;
}


/*++

CSCardFileAccess::Rehabilitate

    Makes a file (EF or DF), which has been previously invalidated with the
    invalidate command, accessable by the application.

Arguments:

    bstrPathSpec - specifies the file to be invalidated (relative path)

    Flag - specifies whether Secure Messaging is to be used

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

--*/

STDMETHODIMP CSCardFileAccess::Rehabilitate(
                                           BSTR bstrPathSpec,
                                           SCARD_FLAGS Flags)
{
    //locals
    HRESULT         hresult = E_NOTIMPL;

    // to do
    // This method should be implemented if the ICC supports this command.

    return hresult;
}


/*++

CSCardFileAccess::Seek

    Selects the object form which (read/write) access will be done

Arguments:

    hFile - contains the handle of the file to access

    lOffset - is the number of data objects from the reference object

    Seek - specifies the type of seek access on the file

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

STDMETHODIMP CSCardFileAccess::Seek(
                                   HSCARD_FILE hFile,
                                   LONG lOffset,
                                   SEEKTYPE Seek)
{
    //locals
    HRESULT             hresult = S_OK;
    FILE_INFORMATION    FileInfo;

    try
    {
        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        // Check Params...
        if (lOffset <0)
            throw ( (HRESULT) E_INVALIDARG);
        // We are only seeking from beginning of the file
        if (Seek != SC_SEEK_FROM_BEGINNING)
            throw ( (HRESULT) E_INVALIDARG );

        m_CriticalSection.EnterCriticalSection();
        // Check for valid handle
        if (!m_FileInfoMap.Lookup(hFile, FileInfo))
            throw ( (HRESULT) E_HANDLE );
        // Store the seek/record position
        FileInfo.lSeekOffset = lOffset;
        m_FileInfoMap.SetAt(hFile, FileInfo);
        m_CriticalSection.ExitCriticalSection();

    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Seek"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Seek"));
    }

    return hresult;
}


/*++

CSCardFileAccess::SetProperties

    Set the primitive data refered by tags (TLV) for the specified
    object

Arguments:

    refType - specifies the type of reference to the file

    bstrPathSpec - specifies the file to use (relative or absolute path).

    pTLV - point to TLV structs whose values have to set

    lcTLV - number of entries in ppTLV

    Flags - specifies whether Secure Messaging has to be used.

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

--*/

STDMETHODIMP CSCardFileAccess::SetProperties(
                                            REFTYPE refType,
                                            BSTR bstrPathSpec,
                                            LPTLV_TABLE pTLV,
                                            LONG lcTLV,
                                            SCARD_FLAGS Flags)
{
    //locals
    HRESULT hresult = E_NOTIMPL;

    // to do
    return hresult;
}


/*++

CSCardFileAccess::Write

    This method writes data to the specified file.

Arguments:

    HSCARD_FILE - contains the handle of the file to access

    lLength - length of the data object to write

    pData - contains the object/data to be written

    Flags - specifies whether Secure Messaging is to be used

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


Revision History


Note:

    As is this routine mainly supports the write to a transparent EF. This
    is the default given to the file type on Open within this class.

--*/

STDMETHODIMP CSCardFileAccess::Write(
                                    HSCARD_FILE hFile,
                                    LONG lLength,
                                    LPBYTEBUFFER pData,
                                    SCARD_FLAGS Flags)
{
    //locals
    HRESULT             hresult = S_OK;
    FILE_INFORMATION    FileInfo;
    LPBYTEBUFFER        pBuffer = NULL;
    LPSCARDCMD          pCmd = NULL;
    LONG                cbBufferSize = 0,
                        cbToWrite = 0;
    BYTE                rgbyWriteData[MAX_WRITE_LEN],
                        byP1 = 0,
                        byP2 = 0;
    STATSTRUCT          statstruct;
    WORD                wOffset = 0;
    LARGE_INTEGER       li;

    try
    {
        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        // Check Params...
        if (pData == NULL)
            throw ( (HRESULT) E_POINTER);

        m_CriticalSection.EnterCriticalSection();
        // Check for valid handle
        if (!m_FileInfoMap.Lookup(hFile, FileInfo))
            throw ( (HRESULT) E_HANDLE );
        m_CriticalSection.ExitCriticalSection();
        // Change directory
        hresult = FileSelect(FileInfo.wfileName);
        if (FAILED(hresult))
            throw (hresult);

        // Create Cmd Object
        hresult = m_Manage->CreateCmdObject(&pCmd);
        if (FAILED(hresult))
            throw (hresult);

        // Get the write buffer statistics
        hresult = pData->Stat(  &statstruct, 0L );
        if (FAILED(hresult))
            throw (hresult);
        if (statstruct.cbSize <= 0)
            throw ( (HRESULT) E_FAIL );
        cbBufferSize = statstruct.cbSize;

        // set Seek position/Read challenge to buffer's head
        LISet32 (li, BYTE_BUFFER_HEAD );
        hresult = pData->Seek(  (LONG) li.LowPart,
                                (LONG) STREAM_SEEK_SET,
                                NULL);
        if (FAILED(hresult))
            throw hresult;

        // Create new buffer for use in holding portion of data to be written to ICC
        hresult = SspCreateByteBuffer(1L, &pBuffer);
        if (FAILED(hresult))
            throw (hresult);

        // Loop to write complete buffer
        while (cbBufferSize > 0)
        {
            // Determine amount of data to write
            if (cbBufferSize <= MAX_WRITE_LEN)
            {
                // Set bytes to write
                cbToWrite = cbBufferSize;
                // Last time through, clear it
                cbBufferSize = 0;
            }
            else
            {
                // Write max bytes
                cbToWrite = MAX_WRITE_LEN;
                // Decrement total number bytes remaining to write
                cbBufferSize -= MAX_WRITE_LEN;
            };

            // Read information from parameter write buffer
            hresult = pData->Read(  (LPBYTE) rgbyWriteData,
                                    cbToWrite,
                                    NULL);
            if (FAILED(hresult))
                throw (hresult);

            // Set Seek pointer to write into temp buffer at its head
            hresult = pBuffer->Seek((LONG) li.LowPart,
                                    (LONG) STREAM_SEEK_SET,
                                    NULL);
            if (FAILED(hresult))
                throw hresult;

            // Set buffer size and write information
            hresult = pBuffer->SetSize( cbToWrite );
            hresult = pBuffer->Write(       (LPBYTE) rgbyWriteData,
                                            cbToWrite,
                                            NULL);
            if (FAILED(hresult))
                throw (hresult);

            // Build correct command based on file type
            switch (FileInfo.fileType)
            {
            case SC_TYPE_TRANSPARENT_EF:
                byP1 = HIBYTE(wOffset);
                byP2 = LOBYTE(wOffset);
                // Build Update command for TRANSPARENT (i.e. Binary) file
                hresult = m_Manage->m_pISCardISO7816->UpdateBinary( byP1,
                                                                    byP2,
                                                                    pBuffer,
                                                                    &pCmd);
                if (FAILED(hresult))
                    throw (hresult);
                // Calculate the new offset for the command
                wOffset += (WORD) cbToWrite;
                break;
            default:
                break;
            };// switch


            // Force correct class id for the vendor's card
            hresult = pCmd->put_ClassId(VENDOR_CLASS_ID);
            if (FAILED(hresult))
                throw (hresult);

            // Do complete transaction
            hresult = m_Manage->m_pISCard->LockSCard();
            if (FAILED(hresult))
                throw (hresult);
            hresult = m_Manage->m_pISCard->Transaction(&pCmd);
            if (FAILED(hresult))
                throw (hresult);
            hresult = m_Manage->m_pISCard->UnlockSCard(LEAVE);
            if (FAILED(hresult))
                throw (hresult);

            //interpret return APDU
            hresult = pCmd->get_ReplyStatus( &m_wReplyStatus );
            if (FAILED(hresult))
                throw (hresult);
            if (m_wReplyStatus != SC_STATUS_SUCCESS)
                throw ( (HRESULT) E_FAIL );
        }; //while - write buffer
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

    // Clean UP
    if (pBuffer != NULL)
        pBuffer->Release();

    if (pCmd != NULL)
        pCmd->Release();

    return hresult;
}

