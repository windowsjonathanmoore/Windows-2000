/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

SCardVer.h : Declaration of the CSCardVerify
----------------------------------------------------------------------------*/


#ifndef __SCARDVERIFY_H_
    #define __SCARDVERIFY_H_

    #include "resource.h"       // main symbols
    #include "scardman.h"

/////////////////////////////////////////////////////////////////////////////
// CSCardVerify
class ATL_NO_VTABLE CSCardVerify :
public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CSCardVerify, &CLSID_SCardVerify>,
    public IDispatchImpl<ISCardVerify, &IID_ISCardVerify, &LIBID_SCARDCOMLib>
{
private:
    // Attributes:
    LPCSCARDMANAGE          m_Manage;
    long    m_lAlgorID;
    LONG    m_lReplyLength;
    WORD    m_wReplyStatus;
    CCriticalSection        m_CriticalSection;

public:
    CSCardVerify()
    {
    }

    ~CSCardVerify()
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
    DECLARE_REGISTRY(CSCardVerify,
                     _T("SCardCOM.SCardVerify.1"),
                     _T("SCardCOM.SCardVerify"),
                     IDS_SCARDVER_DESC,
                     THREADFLAGS_APARTMENT)
        // Note: Enters the standard class registration into the system
        //               registry.
        //
        // Script based...
        // DECLARE_REGISTRY_RESOURCEID(IDR_SCARDVERIFY)

    BEGIN_COM_MAP(CSCardVerify)
    COM_INTERFACE_ENTRY(ISCardVerify)
    COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

    public:
    // ISCardVerify Methods
    STDMETHOD(ChangeCode)(
                         LPBYTEBUFFER pOldCode,
                         LPBYTEBUFFER pNewCode,
                         SCARD_FLAGS Flags,
                         LONG lRef);
    STDMETHOD(Initialize)(
                         LONG* lp);
    STDMETHOD(Unblock)(
                      LONG lData,
                      SCARD_FLAGS Flags,
                      LONG lRef);
    STDMETHOD(ResetSecurityState)(
                                 SCARD_FLAGS Flags);
    STDMETHOD(Verify)(
                     LPBYTEBUFFER pCode,
                     SCARD_FLAGS Flags,
                     LONG* lpRef);
};

#endif //__SCARDVERIFY_H_

