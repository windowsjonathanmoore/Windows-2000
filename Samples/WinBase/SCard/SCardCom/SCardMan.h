/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

SCardMan.h : Declaration of the CSCardManage

----------------------------------------------------------------------------*/

#ifndef __SCARDMANAGE_H_
    #define __SCARDMANAGE_H_

    #include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSCardManage
class ATL_NO_VTABLE CSCardManage :
public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CSCardManage, &CLSID_SCardManage>,
    public IDispatchImpl<ISCardManage, &IID_ISCardManage, &LIBID_SCARDCOMLib>
{
public:
    // Members

    // Pointers to low level SSP
    LPSCARD m_pISCard;
    LPSCARDDATABASE m_pISCardDatabase;
    LPSCARDLOCATE m_pISCardLocate;
    LPSCARDISO7816 m_pISCardISO7816;

    CCriticalSection m_CriticalSection;

public:
    CSCardManage()
    {
    }

    ~CSCardManage()
    {
    }

    HRESULT FinalConstruct();

    HRESULT FinalRelease();

    //
    //DECLARE_NOT_AGGREGATABLE(CSCardManage)
    // Note:
    // Remove the comment from the line above if you don't want your object to
    // support aggregation.  The default is to support it
    //

    //Registry:

    //Simple ALL 1.0 based registry entry
    DECLARE_REGISTRY(   CSCardManage,
                        _T("SCardCOM.SCardManage.1"),
                        _T("SCardCOM.SCardManage"),
                        IDS_SCARDMAN_DESC,
                        THREADFLAGS_APARTMENT)
    // Note: Enters the standard class registration into the system
    //       registry.
    //
    // Script based...
    // DECLARE_REGISTRY_RESOURCEID(IDR_SCARDMANAGE)

    BEGIN_COM_MAP(CSCardManage)
    COM_INTERFACE_ENTRY(ISCardManage)
    COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

    public: // ISCardManage
    HRESULT CreateCmdObject(LPSCARDCMD* ppCMD);

public:
    // ISCardManage
    STDMETHOD(AttachByHandle)(
                             HSCARD hICC);
    STDMETHOD(AttachByIFD)(
                          BSTR bstrIFDName,
                          SCARD_SHARE_MODES Flags );
    STDMETHOD(CreateFileAccess)( LPSCARDFILEACCESS* ppISCardFileAccess );
    STDMETHOD(CreateCardAuth)( LPSCARDAUTH* ppISCardAuth );
    STDMETHOD(CreateInterface)( LPGUID pguidInterface,
                                BSTR bstrName,
                                LONG *pUserData,
                                LPUNKNOWN *ppInterface);
    STDMETHOD(CreateCHVerification)( LPSCARDVERIFY* ppISCardVerify );
    STDMETHOD(Detach)();
    STDMETHOD(SCardLock)();
    STDMETHOD(Reconnect)();
    STDMETHOD(Status)(  SCARD_STATES    *pStatus,
                        SCARD_PROTOCOLS *pProtocol);
    STDMETHOD(SCardUnlock)(SCARD_DISPOSITIONS Disposition=LEAVE);
};

typedef CSCardManage* LPCSCARDMANAGE;

#endif //__SCARDMANAGE_H_

