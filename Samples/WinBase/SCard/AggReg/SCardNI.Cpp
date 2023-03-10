/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1996 - 2000.  Microsoft Corporation.  All rights reserved.


Module Name:

    SCardNI

Abstract:

    This file contains the outline implementation of the CSCardNewInterface
    class showing aggregation example.

Environment:

    Win32, C++ w/Exceptions, ATL, COM/OLE

Revision History:

Notes:

--*/

//////////////////////////////////////////////////////////////////////////
//
// Includes
//

#include "preagg.h"
#include "ScardAgg.h"
#include "SCardNI.h"
#include <sspguid.h>


///////////////////////////////////////////////////////////////////////////
// Macros
//
#ifdef _DEBUG
    #define TRACE_STR(name,sz) \
                TRACE(_T("SCardAgg.DLL: CSCardNewInterface::%s: %s\n"), name, sz)
    #define TRACE_CODE(name,code) \
                TRACE(_T("SCardAgg.DLL: CSCardNewInterface::%s: error = 0x%x\n"), name, code)
    #define TRACE_CATCH(name,code)      TRACE_CODE(name,code)
    #define TRACE_CATCH_UNKNOWN(name)   TRACE_STR(name,_T("An unidentified exception has occurred!"))
#else
    #define TRACE_STR(name,sz)          ((void)0)
    #define TRACE_CODE(name,code)       ((void)0)
    #define TRACE_CATCH(name,code)      ((void)0)
    #define TRACE_CATCH_UNKNOWN(name)   ((void)0)
#endif  // _DEBUG

/*++

CSCardNewInterface::FinalConstruct:

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

    Chris Dudley (cdudley) 2/22/1997

Notes:

    This routine uses the NT4.0+ function CoCreateInstance to create
    the ISCardISO7816 object. In WIN95+, use CoGetClassObject returning
    the IClassFactory for the object, then use IClassFactory->CreateInstance.

    To create an aggregate object, the Controlling IUnknown is passed
    in during creation of the object to be aggregated. Is this example,
    the ATL function GetControllingUnknown is used. This is ATL only and will
    work for aggregate and non-aggregate classes.

    Also, changes must be made to the ATL COM map to support the Aggregation.
    See scardni.h.

--*/

HRESULT CSCardNewInterface::FinalConstruct()
{
    // Locals.
    HRESULT hresult = S_OK;
    IUnknown* pUnkOuter = GetControllingUnknown();

    try
    {
        // Create ISCardISO7816 as aggregate. Only valid IID is IUnknown!!
        hresult = CoCreateInstance( CLSID_CSCardISO7816,
                                    pUnkOuter,      // Controlling Unknown
                                    CLSCTX_LOCAL,
                                    IID_IUnknown,
                                    (LPVOID*) &m_pUnkISCardISO7816);
        if (FAILED(hresult))
            throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("FinalConstruct"),hresult);
    }

    catch (...)
    {
        hresult = E_UNEXPECTED;
        TRACE_CATCH(_T("FinalConstruct"), hresult);
    }

    return(hresult);
}


/*++

CSCardNewInterface::FinalRelease:

    This routine defines a final Release.

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

    Chris Dudley (cdudley) 2/22/1997

--*/

HRESULT CSCardNewInterface::FinalRelease()
{
    // Locals.
    HRESULT hresult = S_OK;

    try
    {
        // Release interface completely!!
        if (m_pUnkISCardISO7816 != NULL)
        {
            m_pUnkISCardISO7816->Release();
            m_pUnkISCardISO7816 = NULL;
        }
    }

    catch (...)
    {
    }

    return(hresult);
}

/////////////////////////////////////////////////////////////////////////////
//
// ISupportsErrorInfo Methods
//

/*++

CSCardNewInterface::InterfaceSupportsErrorInfo:

    This routine retrieves a IErrorInfo interface for this object.

Arguments:

    riid - Interface ID.

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

    Chris Dudley (cdudley) 2/22/1997

--*/

STDMETHODIMP CSCardNewInterface::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] =
    {
        &IID_ISCardNewInterface,
    };

    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if (IsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}


/////////////////////////////////////////////////////////////////////////////
//
// ISCardNewInterface Methods
//

/*++

CSCardNewInterface::NewInterface:

    This method implements some new interface.

Arguments:

    wParameters - P1 and P2 encapsulated

    dwLength - Length of reply

    pParam - IByteBuffer (a.k.a. IStream)

    ppCmd - pointer->pointer->ISCardCmd interface

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

    Chris Dudley (cdudley) 2/22/1997

Notes:

--*/
HRESULT CSCardNewInterface::NewInterface(   WORD wParameters,   // =0
                                            DWORD dwLength,     // =0
                                            LPBYTEBUFFER pParam,
                                            LPSCARDCMD *ppCmd)
{
    // Locals
    HRESULT     hresult = S_OK;

    try
    {
        // Check parameters...
        if ((pParam == NULL) || (ppCmd == NULL ))
            throw ( (HRESULT) E_FAIL );

        // ToDo: Build a new command and return
        // Example:
        //hresult = (*ppCmd)->BuildCmd(m_byClassId,
        //                      (BYTE) INS_SOME_NEW_INSTRUCTION),
        //                      (BYTE) HIBYTE(wParameters)),    // P1
        //                      (BYTE) LOBYTE(wParameters)),    // P2
        //                      pParam,                         // P3+data
        //                      &dwLength);                     // Le
        //if (FAILED(hresult))
        //  throw (hresult);
    }

    catch (HRESULT hr)
    {
        hresult = hr;
        TRACE_CATCH(_T("NewInterface"),hr);
    }

    catch (...)
    {
        hresult = (HRESULT) E_UNEXPECTED;
        TRACE_CATCH_UNKNOWN(_T("NewInterface"));
    }

    return hresult;
}

