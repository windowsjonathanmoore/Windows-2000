/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1996 - 2000.  Microsoft Corporation.  All rights reserved.


Module Name:

    SCardNI

Abstract:

    This file contains the CSCardNewInterface class showing aggregation
    example.

Environment:

    Win32, C++ w/Exceptions, ATL, COM/OLE

Revision History:

Notes:

--*/


#ifndef __SCARDNI_H__
    #define __SCARDNI_H__

/////////////////////////////////////////////////////////////////////////////
//
// Includes
//
    #include "resagg.h"       // main symbols
    #include <scardssp.h>

/////////////////////////////////////////////////////////////////////////////
//
// Class Declaration
//
class CSCardNewInterface :
    public CComDualImpl<ISCardNewInterface, &IID_ISCardNewInterface, &LIBID_SCARDAGGLib>,
    public ISupportErrorInfo,
    public CComObjectRoot,
    public CComCoClass<CSCardNewInterface,&CLSID_CSCardNewInterface>
{
    // Members:
private:
    BYTE        m_byClassId;
    // Pointer to Aggregated interface
    LPUNKNOWN   m_pUnkISCardISO7816;
    //        CComPtr<IUnknown> m_pUnkISCardISO7816;

public:
    // Construction:
    CSCardNewInterface()
    {
    }

    ~CSCardNewInterface()
    {
    }

    HRESULT FinalConstruct();

    HRESULT FinalRelease();

    // COM inteface(s) map

    BEGIN_COM_MAP(CSCardNewInterface)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(ISCardNewInterface)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
        // Add the interface for Aggregation below
    COM_INTERFACE_ENTRY_AGGREGATE(  IID_ISCardISO7816, m_pUnkISCardISO7816)
    END_COM_MAP()
    //
    //DECLARE_NOT_AGGREGATABLE(CSCardFileAccess)
    // Note:
    // Remove the comment from the line above if you don't want your object to
    // support aggregation.  The default is to support it
    //

    //Registry:

    //Simple ALL 1.0 based registry entry
    DECLARE_REGISTRY(CSCardNewInterface,
                     _T("ScardAgg.SCardNewInterface.1"),
                     _T("ScardAgg.SCardNewInterface"),
                     IDS_SCARDNEWINTERFACE_DESC,
                     THREADFLAGS_BOTH)
    // Note: Enters the standard class registration into the system
    //               registry.
    //
    // Script based...
    //

    // Allows support for GetControllingUnknown() function call.
    DECLARE_GET_CONTROLLING_UNKNOWN()

    // ISupportsErrorInfo
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

public:
    // ISCardNewInterface
    STDMETHOD(NewInterface)(WORD wParameters,       // =0
                            DWORD dwLength,         // =0
                            LPBYTEBUFFER pParam,
                            LPSCARDCMD *ppCmd);
};

///////////////////////////////////////////////////////////////////////

#endif //__SCARDNI_H__

