/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

SCardFil.h : Declaration of the CSCardFileAccess
----------------------------------------------------------------------------*/

#ifndef __SCARDFILEACCESS_H_
    #define __SCARDFILEACCESS_H_

    #include "resource.h"       // main symbols
    #include "scardman.h"

/////////////////////////////////////////////////////////////////////////////
// CSCardFileAccess
class ATL_NO_VTABLE CSCardFileAccess :
public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CSCardFileAccess, &CLSID_SCardFileAccess>,
    public IDispatchImpl<ISCardFileAccess, &IID_ISCardFileAccess, &LIBID_SCARDCOMLib>
{
    // Members
private:
    LPCSCARDMANAGE          m_Manage;
    // Struct and map used for holding file information for open files, etc.
    typedef struct tagfile_info
    {
        HSCARD_FILE fileHandle;
        SCARD_FLAGS fileStatus;
        FILETYPE    fileType;
        WORD        wfileName;
        LONG        lSeekOffset;
        LPCSTR      szRFU;
    } FILE_INFORMATION;
    CMap<HSCARD_FILE, HSCARD_FILE, FILE_INFORMATION, FILE_INFORMATION&> m_FileInfoMap;

    int         m_iOpenFiles;
    HSCARD_FILE m_hfileNextHandle;
    WORD        m_wCurrentFileID;
    LONG        m_lReplyLength;
    WORD        m_wReplyStatus;

    CCriticalSection m_CriticalSection;

public:
    CSCardFileAccess()
    {
    }

    ~CSCardFileAccess()
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
    DECLARE_REGISTRY(CSCardFileAccess,
                     _T("SCardCOM.SCardFileAccess.1"),
                     _T("SCardCOM.SCardFileAccess"),
                     IDS_SCARDFIL_DESC,
                     THREADFLAGS_APARTMENT)
    // Note: Enters the standard class registration into the system
    //               registry.
    //
    // Script based...
    // DECLARE_REGISTRY_RESOURCEID(IDR_SCARDFILEACCESS)

    BEGIN_COM_MAP(CSCardFileAccess)
    COM_INTERFACE_ENTRY(ISCardFileAccess)
    COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

    private:
    // ISCardFileAccess Methods
    WORD ConvertFilename(BSTR bstrFilename);
    HSCARD_FILE CreateFileHandle();
    HRESULT FileSelect(WORD wFileName);

public:
    // ISCardFileAccess Methods
    STDMETHOD(ChangeDir)(
                        REFTYPE refType,
                        BSTR bstrNewDir);
    STDMETHOD(Close)(
                    HSCARD_FILE hFile);
    STDMETHOD(Create)(
                     REFTYPE refType,
                     BSTR bstrPathSpec,
                     LPTLV_TABLE* ppTLVs,
                     LONG* lpcTLVs,
                     SCARD_FLAGS Flags,
                     LPBYTEBUFFER pDataBuffer);
    STDMETHOD(Delete)(
                     REFTYPE refType,
                     BSTR bstrPathSpec,
                     SCARD_FLAGS Flag);
    STDMETHOD(Directory)(
                        FILETYPE fileType,
                        LPSAFEARRAY *ppFileList);
    STDMETHOD(GetCurrentDir)(
                            BSTR* pbstrPathSpec);
    STDMETHOD(GetFileCapabilities)(
                                  LPTLV_TABLE* ppProperties,
                                  LONG* plProperties,
                                  SCARD_FLAGS Flags);
    STDMETHOD(GetProperties)(
                            REFTYPE refType,
                            BSTR bstrPathSpec,
                            LPTLV_TABLE *ppTLV,
                            LONG* plcTLV,
                            SCARD_FLAGS Flags);
    STDMETHOD(Initialize)(
                         LONG* lp);
    STDMETHOD(Invalidate)(
                         BSTR bstrPathSpec,
                         SCARD_FLAGS Flags);
    STDMETHOD(Open)(
                   REFTYPE refType,
                   BSTR bstrPathSpec,
                   HSCARD_FILE *phFile);
    STDMETHOD(Read)(
                   HSCARD_FILE hFile,
                   LONG *lBytesToRead,
                   LPBYTEBUFFER* ppBuffer,
                   SCARD_FLAGS Flags);
    STDMETHOD(Rehabilitate)(
                           BSTR bstrPathSpec,
                           SCARD_FLAGS Flags);
    STDMETHOD(Seek)(
                   HSCARD_FILE hFile,
                   LONG lOffset,
                   SEEKTYPE Seek);
    STDMETHOD(SetProperties)(
                            REFTYPE refType,
                            BSTR bstrPathSpec,
                            LPTLV_TABLE pTLV,
                            LONG lcTLV,
                            SCARD_FLAGS Flags);
    STDMETHOD(Write)(
                    HSCARD_FILE hFile,
                    LONG lLength,
                    LPBYTEBUFFER pData,
                    SCARD_FLAGS Flags);
};

#endif //__SCARDFILEACCESS_H_

