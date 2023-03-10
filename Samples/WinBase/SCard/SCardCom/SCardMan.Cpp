/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

SCardMan.cpp : Implementation of CSCardManage
----------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////////////////////
//
// Includes
//
#include "stdafx.h"
#include "SCardCom.h"
#include "SCardMan.h"
// Include the SSP GUIDS
#include <sspguid.h>

///////////////////////////////////////////////////////////////////////////
// Macros
//
#ifdef _DEBUG
    #define TRACE_STR(name,sz) \
                TRACE(_T("SMB_SSP.DLL: CSCardManage::%s: %s\n"), name, sz)
    #define TRACE_CODE(name,code) \
                TRACE(_T("SMB_SSP.DLL: CSCardManage::%s: error = 0x%x\n"), name, code)
    #define TRACE_CATCH(name,code)      TRACE_CODE(name,code)
    #define TRACE_CATCH_UNKNOWN(name)   TRACE_STR(name,_T("An unidentified exception has occurred!"))
#else
    #define TRACE_STR(name,sz)          ((void)0)
    #define TRACE_CODE(name,code)       ((void)0)
    #define TRACE_CATCH(name,code)      ((void)0)
    #define TRACE_CATCH_UNKNOWN(name)   ((void)0)
#endif  // _DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSCardManage

/*++

FinalConstruct:

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

HRESULT CSCardManage::FinalConstruct()
{
    // Locals.
    HRESULT hresult = S_OK;

    try
    {
        // Check Params, etc

        ///////////////////////////////////////////////////////////////////////////
        //
        // Create an instance of all the low-level COM objects-interfaces
        //
        //
        hresult = CoCreateInstance( CLSID_CSCard,
                                    NULL,
                                    CLSCTX_LOCAL,
                                    IID_ISCard,
                                    (LPVOID*) &m_pISCard);
        if (FAILED(hresult))
            throw (hresult);
        hresult = CoCreateInstance( CLSID_CSCardISO7816,
                                    NULL,
                                    CLSCTX_LOCAL,
                                    IID_ISCardISO7816,
                                    (LPVOID*) &m_pISCardISO7816);
        if (FAILED(hresult))
            throw (hresult);
        // If Required...
        hresult = CoCreateInstance( CLSID_CSCardDatabase,
                                    NULL,
                                    CLSCTX_LOCAL,
                                    IID_ISCardDatabase,
                                    (LPVOID*) &m_pISCardDatabase);
        if (FAILED(hresult))
            throw (hresult);
        hresult = CoCreateInstance( CLSID_CSCardLocate,
                                    NULL,
                                    CLSCTX_LOCAL,
                                    IID_ISCardLocate,
                                    (LPVOID*) &m_pISCardLocate);
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("FinalConstruct"),hr);
    }

    catch (...)
    {
        hresult = E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("FinalConstruct"));
    }

    return(hresult);
}


/*++

FinalRelease:

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

HRESULT CSCardManage::FinalRelease()
{
    // Locals.
    HRESULT hresult = S_OK;

    try
    {
        // Release the Interfaces
        m_pISCard->Release();
        m_pISCardISO7816->Release();
        // If required...
        m_pISCardDatabase->Release();
        m_pISCardLocate->Release();
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("AttachByIFD"));
    }

    return(hresult);
}

/*++

CreateCmdObject:

    This routine creates an instance of the ISCardCmd object

Arguments:

    ppCmd - pointer to an ISCardCmd pointer

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
HRESULT CSCardManage::CreateCmdObject(LPSCARDCMD *ppCmd)
{
    // Locals
    HRESULT     hresult = S_OK;
    LPSCARDCMD  pObj = NULL;

    try
    {
        // Check Params, etc...
        if (ppCmd==NULL)
            throw ( (HRESULT) E_INVALIDARG );

        // Create the object
        hresult = CoCreateInstance( CLSID_CSCardCmd,
                                    NULL,
                                    CLSCTX_LOCAL,
                                    IID_ISCardCmd,
                                    (LPVOID*) &pObj);
        if (FAILED(hresult))
            throw (hresult);

        ASSERT( (pObj) != NULL );

        // Package for return
        (*ppCmd) = pObj;
    }

    catch (HRESULT hr)
    {
        hresult=hr;
        TRACE_CATCH(_T("CreateCmdObject"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("CreateCmdObject"));
    }

    return hresult;
}


/////////////////////////////////////////////////////////////////////////////
//
// ISCardManage Methods
//


/*++

CSCardManage::AttachByHandle:

    Allows an application to create a communication to an ICC using
    a handle returned by the Resource Manager

Arguments:

    hICC - handle to the ICC

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

STDMETHODIMP CSCardManage::AttachByHandle(
                                         HSCARD hICC)
{
    //locals
    HRESULT     hresult = S_OK;

    try
    {
        if (hICC == 0)
            throw ( (HRESULT) E_INVALIDARG);
        // Make low level COM call
        hresult = m_pISCard->AttachByHandle(hICC);
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("AttachByHandle"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("AttachByHandle"));
    }

    return hresult;
}


/*++

CSCardManage::AttachByIFD:

    Allows an application to request establishment of a context for
    a specific IFD referenced with a friendly name

Arguments:

    bstrIFDName - String containing friendly name

    Flags - desired access mode

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
STDMETHODIMP CSCardManage::AttachByIFD(
                                      BSTR bstrIFDName,
                                      SCARD_SHARE_MODES Flags)
{
    //locals
    HRESULT     hresult = S_OK;

    try
    {
        if (bstrIFDName == NULL)
            throw ( (HRESULT) E_INVALIDARG);
        // make low level COM call...Default to T0 protocol for Cryptoflex
        // Note: In this example code we are grabbing the reader for SHAREd
        // use. This implies we MUST use ISCard->Lock (SCardBeginTransaction) and
        // ISCard->Unlock (SCardEndTransaction) when communicating with the card.
        // The begin/end transaction functions should be called in any case.
        hresult = m_pISCard->AttachByReader(bstrIFDName, SHARED, T0);
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("AttachByIFD"), hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("AttachByIFD"));
    }

    return hresult;
}


/*++

CSCardManage::CreateCardAuth:

    Creates an instance of the ISCardAuth interface and returns
    a pointer to the created interface.

Arguments:

    pISCardAuth - pointer to ISCardAuth

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
STDMETHODIMP CSCardManage::CreateCardAuth( LPSCARDAUTH* ppISCardAuth )
{
    // Locals
    HRESULT     hresult = S_OK;
    LPSCARDAUTH pObj = NULL;

    try
    {
        // Check params, etc..
        if (ppISCardAuth == NULL)
            throw ( (HRESULT) E_INVALIDARG );

        // Create an instance of the interface
        hresult = CoCreateInstance( CLSID_SCardAuth,
                                    NULL,
                                    CLSCTX_LOCAL,
                                    IID_ISCardAuth,
                                    (LPVOID*) &pObj);
        if (FAILED(hresult))
            throw (hresult);

        // Initialize the Interface/Object
        hresult = pObj->Initialize((LONG*) this);
        if (FAILED(hresult))
            throw (hresult);

        // Ok...
        (*ppISCardAuth) = pObj;
        // We are bumping the reference count on this object so we are sure it will
        // remain available. This means each object MUST Release() the count!
        AddRef();
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("CreateCardAuth"),hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("CreateCardAuth"));
    }

    return hresult;
}


/*++

CSCardManage::CreateFileAccess:

    Creates an instance of the ISCardFileAccess interface and returns
    a pointer to the created interface.

Arguments:

    pISCardFileAccess - pointer to ISCardFileAccess

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
STDMETHODIMP CSCardManage::CreateFileAccess( LPSCARDFILEACCESS *ppISCardFileAccess )
{
    // Locals
    HRESULT     hresult = S_OK;
    LPSCARDFILEACCESS pObj = NULL;

    try
    {
        // Check params, etc..
        if (ppISCardFileAccess == NULL)
            throw ( (HRESULT) E_INVALIDARG );

        // Create an instance of the interface
        hresult = CoCreateInstance( CLSID_SCardFileAccess,
                                    NULL,
                                    CLSCTX_LOCAL,
                                    IID_ISCardFileAccess,
                                    (LPVOID*) &pObj);
        if (FAILED(hresult))
            throw (hresult);

        // Initialize the Interface/Object
        hresult = pObj->Initialize((LONG*) this);
        if (FAILED(hresult))
            throw (hresult);

        // Ok...
        (*ppISCardFileAccess) = pObj;
        // We are bumping the reference count on this object so we are sure it will
        // remain available. This means each object MUST Release() the count!
        AddRef();
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("CreateFileAccess"),hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("CreateFileAccess"));
    }

    return hresult;
}


/*++

CSCardManage::CreateInterface

    Creates an instance of an interface supported by this ssp.

Arguments:

    pISCardFileAccess - pointer to ISCardFileAccess

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
STDMETHODIMP CSCardManage::CreateInterface( LPGUID pguidInterface,
                                            BSTR bstrName /*=NULL*/,
                                            LONG *pUserData /*=NULL*/,
                                            LPUNKNOWN *ppInterface)
{
    // Locals
    HRESULT     hresult = E_NOTIMPL;

    try
    {
        // Check params, etc..

        // Todo::Add code to support the creation of non-standard or
        // crypto interfaces
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("CreateInterface"),hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("CreateInterface"));
    }

    return hresult;
}


/*++

CSCardManage::CreateCHVerification:

    Creates an instance of the ISCardVerify interface and returns
    a pointer to the created interface.

Arguments:

    pISCardVerify - pointer to ISCardVerify

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
STDMETHODIMP CSCardManage::CreateCHVerification( LPSCARDVERIFY *ppISCardVerify )
{
    // Locals
    HRESULT     hresult = S_OK;
    LPSCARDVERIFY pObj = NULL;

    try
    {
        // Check params, etc..
        if (ppISCardVerify == NULL)
            throw ( (HRESULT) E_INVALIDARG );

        // Create an instance of the interface
        hresult = CoCreateInstance( CLSID_SCardVerify,
                                    NULL,
                                    CLSCTX_LOCAL,
                                    IID_ISCardVerify,
                                    (LPVOID*) &pObj);
        if (FAILED(hresult))
            throw (hresult);

        // Initialize the Interface/Object
        hresult = pObj->Initialize((LONG*) this);
        if (FAILED(hresult))
            throw (hresult);

        // Ok...
        (*ppISCardVerify) = pObj;
        // We are bumping the reference count on this object so we are sure it will
        // remain available. This means each object MUST Release() the count!
        AddRef();
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("CreateCHVerify"),hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("CreateCHVerify"));
    }

    return hresult;
}


/*++

CSCardManage::Detach

    Releases the attachment to a particular ICC or IFD allocated by
    an AttachByxxx method

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

--*/
STDMETHODIMP CSCardManage::Detach()
{
    //locals
    HRESULT     hresult = S_OK;

    try
    {
        // Make low-level COM call
        hresult = m_pISCard->Detach(LEAVE);
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Detach"),hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Detach"));
    }

    return hresult;
}


/*++

CSCardManage::SCardLock:

    Locks the connected IFD/ICC for exclusive use by this application. Usually
    used for executing mutiple/sequence of commands to the card.

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

--*/
STDMETHODIMP CSCardManage::SCardLock()
{
    //locals
    HRESULT     hresult = S_OK;

    try
    {
        // Call low-level COM
        hresult = m_pISCard->LockSCard();
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("SCardLock"), hr);
    }

    catch (...)
    {
        hresult = E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("SCardLock"));
    }

    return hresult;
}


/*++

CSCardManage::Reconnect:

    Allows an application to reconnect to an ICC or IFD without having
    to issue a Detach then a AttachByxxx method call

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

--*/
STDMETHODIMP CSCardManage::Reconnect()
{
    //locals
    HRESULT     hresult = S_OK;

    try
    {
        // Call low-level COM
        hresult = m_pISCard->ReAttach(SHARED, LEAVE);
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Reconnect"), hr);
    }

    catch (...)
    {
        hresult = E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Reconnect"));
    }

    return hresult;
}


/*++

CSCardManage::Status:

    Allows an application to get the current status of the ICC/IFD.

Arguments:

    pwdStatus - Pointer to DWORD that will contain status
                    ABSENT
                    PRESENT
                    SWALLOWED
                    POWERED
                    NEGOTIABLEMODE
                    SPECIFICMODE
    pwdProtocol - point to DWORD that will contain current protocol in use
                    T0
                    T1
                    RAW

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
STDMETHODIMP CSCardManage::Status(  SCARD_STATES    *pStatus,
                                    SCARD_PROTOCOLS *pProtocol)
{
    //locals
    HRESULT     hresult = S_OK;

    try
    {
        if ((pStatus==NULL) || (pProtocol == NULL))
            throw ( (HRESULT) E_INVALIDARG );

        // Call low-level COM
        hresult = m_pISCard->get_Status(pStatus);
        if (FAILED(hresult))
            throw (hresult);
        hresult = m_pISCard->get_Protocol(pProtocol);
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("Status"), hr);
    }

    catch (...)
    {
        hresult = E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("Status"));
    }

    return hresult;
}


/*++

CSCardManage::SCardUnlock:

    This method releases the connected IFD/ICC from exclusive use.

Arguments:

    Disposition - state to leave card in upon release.
        LEAVE
        RESET
        UNPOWER
        EJECT

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
STDMETHODIMP
    CSCardManage::SCardUnlock(
                             SCARD_DISPOSITIONS  Disposition /*=LEAVE*/)
{
    //locals
    HRESULT     hresult = S_OK;

    try
    {
        // Call low-level COM
        hresult = m_pISCard->UnlockSCard(Disposition);
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("SCardUnlock"), hr);
    }

    catch (...)
    {
        hresult = E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("SCardUnlock"));
    }

    return hresult;
}

