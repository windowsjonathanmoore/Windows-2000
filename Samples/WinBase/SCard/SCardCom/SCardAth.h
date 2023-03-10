/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

SCardAth.h : Declaration of the CSCardAuth
----------------------------------------------------------------------------*/

#ifndef __SCARDAUTH_H_
    #define __SCARDAUTH_H_

    #include "resource.h"       // main symbols
    #include "scardman.h"

/////////////////////////////////////////////////////////////////////////////
// CSCardAuth
class ATL_NO_VTABLE CSCardAuth :
public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CSCardAuth, &CLSID_SCardAuth>,
    public IDispatchImpl<ISCardAuth, &IID_ISCardAuth, &LIBID_SCARDCOMLib>
{
private:
    // Members
    LPCSCARDMANAGE  m_Manage;
    long            m_lAlgorID;
    LONG            m_lReplyLength;
    WORD            m_wReplyStatus;

public:
    CSCardAuth()
    {
    }

    ~CSCardAuth()
    {
    }

    HRESULT FinalConstruct();

    HRESULT FinalRelease();

    //
    //DECLARE_NOT_AGGREGATABLE(CSCardFileAccess)
    // Note:
    // Remove the comment from the line above if you don't want your object to
    // support aggregation.  The default is to support it
    //

    //Registry:

    //Simple ALL 1.0 based registry entry
    DECLARE_REGISTRY(CSCardAuth,
                     _T("SCardCOM.SCardAuth.1"),
                     _T("SCardCOM.SCardAuth"),
                     IDS_SCARDATH_DESC,
                     THREADFLAGS_APARTMENT)
        // To use script base registration use the line below
        // DECLARE_REGISTRY_RESOURCEID(IDR_SCARDAUTH)

    BEGIN_COM_MAP(CSCardAuth)
    COM_INTERFACE_ENTRY(ISCardAuth)
    COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

        // ISCardAuth
    private:

    public:
    STDMETHOD(APP_Auth)(
                       LONG lAlgorID,
                       LPBYTEBUFFER pParam,
                       LPBYTEBUFFER pBuffer);
    STDMETHOD(GetChallenge)(
                           LONG lAlgorID,
                           LPBYTEBUFFER pParam,
                           LONG* lpLengthOfChallenge,
                           LPBYTEBUFFER *ppBuffer);
    STDMETHOD(ICC_Auth)(
                       LONG lAlgorID,
                       LPBYTEBUFFER pParam,
                       LONG* lpLength,
                       LPBYTEBUFFER *ppBuffer);
    STDMETHOD(Initialize)(
                         LONG* lp);
    STDMETHOD(User_Auth)(
                        LONG lAlgorID,
                        LPBYTEBUFFER pParam,
                        LONG* lpLength,
                        LPBYTEBUFFER *ppBuffer);
};

#endif //__SCARDAUTH_H_

