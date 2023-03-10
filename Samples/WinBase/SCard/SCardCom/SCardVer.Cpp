/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

SCardVer.cpp : Implementation of CSCardVerify

----------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////////////////////
//
// Includes
//
#include "stdafx.h"
#include "SCardCom.h"
#include "SCardVer.h"
#include "scarddef.h"

///////////////////////////////////////////////////////////////////////////
// Macros
//
#ifdef _DEBUG
    #define TRACE_STR(name,sz) \
                TRACE(_T("SCardCOM.DLL: CSCardVerify::%s: %s\n"), name, sz)
    #define TRACE_CODE(name,code) \
                TRACE(_T("SCardCOM.DLL: CSCardVerify::%s: error = 0x%x\n"), name, code)
    #define TRACE_CATCH(name,code)      TRACE_CODE(name,code)
    #define TRACE_CATCH_UNKNOWN(name)   TRACE_STR(name,_T("An unidentified exception has occurred!"))
#else
    #define TRACE_STR(name,sz)          ((void)0)
    #define TRACE_CODE(name,code)       ((void)0)
    #define TRACE_CATCH(name,code)      ((void)0)
    #define TRACE_CATCH_UNKNOWN(name)   ((void)0)
#endif  // _DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSCardVerify


/*++

CSCardVerify::FinalConstruct:

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

HRESULT CSCardVerify::FinalConstruct()
{
    // Locals.
    HRESULT hresult = S_OK;

    try
    {
        m_Manage = NULL;
    }

    catch (...)
    {
    }

    return(hresult);
}

/*++

CSCardVerify::FinalRelease:

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

HRESULT CSCardVerify::FinalRelease()
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
// ISCardVerify Methods
//


/*++

CSCardVerify::ChangeCode

    This method changes the current user code.

Arguments:

    pOldCode - contains the user's current code to be presented
        to the ICC in the change process in order to authenticate the user

    pNewCode - contains the NEW code to replace the current code.

    Flags - indicates whether the code is global or local also whether the
        code should be enabled or disabled.

    dwRef - ICC specific reference

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

STDMETHODIMP CSCardVerify::ChangeCode(
                                     LPBYTEBUFFER pOldCode,
                                     LPBYTEBUFFER pNewCode,
                                     SCARD_FLAGS Flags,
                                     LONG lRef)
{
    //locals
    HRESULT hresult = E_NOTIMPL;

    // to do
    return hresult;
}


/*++

CSCardVerify::Initialize

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
STDMETHODIMP CSCardVerify::Initialize( LONG *lp)
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

CSCardVerify::Unblock

    Unblocks a previously blocked IHV.

Arguments:

    dwData - contains vendor specific data to be used in the unblocking
        process.

    Flags - indicates whether the code is a global or local

    dwRef - ICC specific reference

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

STDMETHODIMP CSCardVerify::Unblock(
                                  LONG lData,
                                  SCARD_FLAGS Flags,
                                  LONG lRef)
{
    //locals
    HRESULT hresult = E_NOTIMPL;

    // to do
    return hresult;
}


/*++

CSCardVerify::ResetSecurityState

    Resets either the global or local security context

Arguments:

    Flags - SC_FL_IHV_GLOBAL or SC_FL_IHV_LOCAL

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

STDMETHODIMP CSCardVerify::ResetSecurityState(
                                             SCARD_FLAGS Flags)
{
    //locals
    HRESULT hresult = E_NOTIMPL;

    // to do
    return hresult;
}

/*++

CSCardVerify::Verify

    Authenticate the user

Arguments:

    pCode - contains the Code to be presented to the ICC in the IHV
        process.

    Flags - indicates whether the code is global or local

    lpRef - ICC specific reference

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

STDMETHODIMP CSCardVerify::Verify(
                                 LPBYTEBUFFER pCode,
                                 SCARD_FLAGS Flags,
                                 LONG* lpRef)
{
    //locals
    HRESULT     hresult = S_OK;
    BYTE        byReferenceControl;
    LPSCARDCMD  pCmd = NULL;

    try
    {
        // Is internal pointer to "Creation Class" valid
        if (m_Manage == NULL)
            throw ( (HRESULT) E_FAIL );

        // Check params...
        if (pCode == NULL)
            throw ( (HRESULT) E_POINTER );


        // Create the p1-p2 paramters..In this case assume the verification (i.e. PIN,
        // etc) is to be passed in as pCode
        if (Flags == SC_FL_IHV_GLOBAL)
            byReferenceControl = SC_GLOBAL_REF;
        else
            byReferenceControl = SC_SPECIFIC_REF;

        // ISO7186 COM builds command
        hresult = m_Manage->m_pISCardISO7816->Verify(byReferenceControl,
                                                     pCode,
                                                     &pCmd);

        if (FAILED(hresult))
            throw(hresult);

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

        //interpret results and return
        hresult = pCmd->get_ApduReplyLength(&m_lReplyLength);
        if (FAILED(hresult))
            throw (hresult);
        hresult = pCmd->get_ReplyStatus( &m_wReplyStatus );
        if (FAILED(hresult))
            throw (hresult);
        if (m_wReplyStatus != 0x9000)
            throw ( (HRESULT) E_FAIL);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Verify"), hr);
    }

    catch (...)
    {
        hresult = E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Verify"));
    }

    if (pCmd != NULL)
        pCmd->Release();

    return hresult;
}

