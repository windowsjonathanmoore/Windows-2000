/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

SCardAth.cpp : Implementation of CSCardAuth
----------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////////////////////
//
// Includes
//
#include "stdafx.h"
#include "SCardCom.h"
#include "SCardAth.h"
#include "SCardDef.h"

///////////////////////////////////////////////////////////////////////////
// Macros
//
#ifdef _DEBUG
    #define TRACE_STR(name,sz) \
                                TRACE(_T("SCardCom.DLL: CSCardAuth::%s: %s\n"), name, sz)
    #define TRACE_CODE(name,code) \
                                TRACE(_T("SCardCom.DLL: CSCardAuth::%s: error = 0x%x\n"), name, code)
    #define TRACE_CATCH(name,code)      TRACE_CODE(name,code)
    #define TRACE_CATCH_UNKNOWN(name)   TRACE_STR(name,_T("An unidentified exception has occurred!"))
#else
    #define TRACE_STR(name,sz)          ((void)0)
    #define TRACE_CODE(name,code)       ((void)0)
    #define TRACE_CATCH(name,code)      ((void)0)
    #define TRACE_CATCH_UNKNOWN(name)   ((void)0)
#endif  // _DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSCardAuth

/*++

CSCardAuth::FinalConstruct:

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

HRESULT CSCardAuth::FinalConstruct()
{
    // Locals.
    HRESULT hresult = S_OK;

    try
    {
        m_Manage = NULL;
    }

    catch (...)
    {
        hresult = E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("GetChallenge"));
    }

    return(hresult);
}


/*++

CSCardAuth::FinalRelease:

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

HRESULT CSCardAuth::FinalRelease()
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


/////////////////////////////////////////////////////////////////////////////
//
// ISCardAuth Methods
//


/*++

CSCardAuth::APP_Auth

    This method allows an application to athenticate itself to the ICC
    using a Challange/signature protocol.

Arguments:

    lAlogID - specifies the algorithm to be used in the authentcation
        process

    pParam - IByteBuffer containing vendor specific parameters of the
        authentication process

    pBuffer - contains data required for authentication.

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

STDMETHODIMP CSCardAuth::APP_Auth(
                                 long lAlgorID,
                                 LPBYTEBUFFER pParam,
                                 LPBYTEBUFFER pBuffer)
{
    //locals
    HRESULT     hresult = S_OK;
    LPSCARDCMD  pCmd = NULL;

    try
    {
        m_lAlgorID = lAlgorID;

        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        // Must have valid pointer...
        if (pBuffer == NULL)
            throw ( (HRESULT) E_POINTER );

        // Create cmd object
        hresult = m_Manage->CreateCmdObject(&pCmd);
        if (FAILED(hresult))
            throw (hresult);

        // Do internal Authenticate
        hresult = m_Manage->m_pISCardISO7816->ExternalAuthenticate((BYTE)lAlgorID,
                                                                   NULL,
                                                                   pBuffer,
                                                                   &pCmd);
        if (FAILED(hresult))
            throw (hresult);
        // Force correct class id
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
            throw(hresult);

        //interpret results and return
        hresult = pCmd->get_ApduReplyLength(&m_lReplyLength);
        if (FAILED(hresult))
            throw (hresult);
        hresult = pCmd->get_ReplyStatus( &m_wReplyStatus );
        if (FAILED(hresult))
            throw (hresult);
        if (m_wReplyStatus != 0x9000)
            throw (E_FAIL);
    }

    catch (HRESULT hr)
    {
        hresult=hr;
        TRACE_CATCH(_T("APP_Auth"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("APP_AUTH"));
    }

    // Release cmd interface
    if (pCmd != NULL)
        pCmd->Release();

    return hresult;
}


/*++

CSCardAuth::GetChallenge

    Returns a challenge from the ICC.

Arguments:

    lAlgorID - specifies the algorithm the challenge will be used with.

    pParam - Contains vendor specific parameters used in the
        authentication process.

    lpLengthOfChallenge - indicates length of ppBuffer

    ppBuffer - contains the challenge to be used in subsequent
        application authentication

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

STDMETHODIMP CSCardAuth::GetChallenge(
                                     LONG lAlgorID,
                                     LPBYTEBUFFER pParam,
                                     LONG* lpLengthOfChallenge,
                                     LPBYTEBUFFER *ppBuffer)
{
    //locals
    HRESULT     hresult = S_OK;
    LPSCARDCMD  pCmd = NULL;

    try
    {
        m_lAlgorID = lAlgorID;

        // CheckLength
        if (*lpLengthOfChallenge<0)
            throw ( (HRESULT) E_INVALIDARG );

        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        // Check pointer...Will create it later if needed.
        if (ppBuffer == NULL)
            throw ( (HRESULT) E_POINTER );

        // Create a command object
        hresult = m_Manage->CreateCmdObject(&pCmd);
        if (FAILED(hresult))
            throw (hresult);

        // Do challenge
        hresult = m_Manage->m_pISCardISO7816->GetChallenge(*lpLengthOfChallenge,
                                                           &pCmd);
        if (FAILED(hresult))
            throw (hresult);
        // Force correct class id for the the CryptoFlex card
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
            throw(hresult);

        //interpret results and return
        hresult = pCmd->get_ApduReplyLength(&m_lReplyLength);
        if (FAILED(hresult))
            throw (hresult);
        hresult = pCmd->get_ReplyStatus( &m_wReplyStatus );
        if (FAILED(hresult))
            throw (hresult);
        if (m_wReplyStatus != 0x9000)
            throw (E_FAIL);
        hresult = pCmd->get_ApduReply( ppBuffer );
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("GetChallenge"),hr);
    }

    catch (...)
    {
        hresult = E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("GetChallenge"));
    }

    // Release cmd interface
    if (pCmd != NULL)
        pCmd->Release();

    return hresult;
}


/*++

CSCardAuth::ICC_Auth

    Allows application to authenticate the ICC

Arguments:

    lAlgorID - specifies the algorithm to be used in the authentication
        process.

    pParam - Contains vendor specific parameters used in the
        authentication process.

    lpLength - contains the length of the valid data in ppBuffer.

    ppBuffer - (in) cotains the data to be used in the authentication process;
        (out) contins the result of the signation process

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

STDMETHODIMP CSCardAuth::ICC_Auth(
                                 long lAlgorID,
                                 LPBYTEBUFFER pParam,
                                 LONG* lpLength,
                                 LPBYTEBUFFER *ppBuffer)
{
    //locals
    HRESULT     hresult = S_OK;
    LPSCARDCMD  pCmd = NULL;

    try
    {
        m_lAlgorID = lAlgorID;

        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        // Must have valid pointer...
        if (ppBuffer == NULL)
            throw ( (HRESULT) E_POINTER );

        // create buffer if needed
        if ((*ppBuffer) == NULL)
        {
            hresult = SspCreateByteBuffer((ULONG) 0, ppBuffer);
            if (FAILED(hresult))
                throw (hresult);
        };// if

        // Create Cmd Object
        hresult = m_Manage->CreateCmdObject(&pCmd);
        if (FAILED(hresult))
            throw (hresult);

        // Do internal Authenticate
        hresult = m_Manage->m_pISCardISO7816->InternalAuthenticate((BYTE)lAlgorID,
                                                                   NULL,
                                                                   (*ppBuffer),
                                                                   0,
                                                                   &pCmd);
        if (FAILED(hresult))
            throw (hresult);
        // Force correct class id for the the CryptoFlex card
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
            throw(hresult);

        //interpret results and return
        hresult = pCmd->get_ApduReplyLength(&m_lReplyLength);
        if (FAILED(hresult))
            throw (hresult);
        hresult = pCmd->get_ReplyStatus( &m_wReplyStatus );
        if (FAILED(hresult))
            throw (hresult);
        if (m_wReplyStatus != 0x9000)
            throw (E_FAIL);
        hresult = pCmd->get_ApduReply( ppBuffer );
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult=hr;
        TRACE_CATCH(_T("ICC_Auth"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("ICC_AUTH"));
    }

    // Release cmd interface
    if (pCmd != NULL)
        pCmd->Release();

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
STDMETHODIMP CSCardAuth::Initialize( LONG *lp)
{
    // Locals
    HRESULT hresult = S_OK;

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

CSCardAuth::User_Auth

    Allows a remote app to authenticate the Client

Arguments:

    lAlgorID - specifies the algorithm to be used in the authentication
        process.

    pParam - Contains vendor specific parameters used in the
        authentication process.

    lpLength - contains the length of the valid data in pBuffer.

    ppBuffer - contains the challenge data on input and the authentication
        data on output.

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

STDMETHODIMP CSCardAuth::User_Auth(
                                  LONG lAlgorID,
                                  LPBYTEBUFFER pParam,
                                  LONG* lpLength,
                                  LPBYTEBUFFER* ppBuffer)
{
    //locals
    HRESULT         hresult = E_NOTIMPL;

    try
    {
        // Todo: Add code if ICC supports
    }

    catch (HRESULT hr)
    {
        hresult=hr;
        TRACE_CATCH(_T("User_Auth"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("USER_AUTH"));
    }

    return hresult;
}

