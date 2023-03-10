//****************************************************************************
//  Module:     PLUGTRANSPORT.EXE     
//  File:       PLUGXPRT.CPP
//  Content:    
//              
//
//  Copyright (c) Microsoft Corporation 1995 - 2000
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF 
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO 
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A 
// PARTICULAR PURPOSE.
//****************************************************************************


#include "precomp.h"


//**********************
//FUNCTION DECLARATIONS
//**********************

BSTR LPSTR2BSTR(LPSTR pszString);
BOOL BSTR2LPSTR(BSTR bstrConnID, LPSTR pszConnID);


//**********************************
//
// CLASS CPluggableTransport
//
//**********************************

//****************************************************************************
//
//    FUNCTION:   CPluggableTransport::CPluggableTransport()
//
//    PURPOSE:    Construction

//    COMMENTS:
//      
//
//****************************************************************************

CPluggableTransport::CPluggableTransport()
{
    m_pIPlugTrans = NULL;
    m_bInConnection = false;
    m_pX224 = NULL;
    m_pPSTN = NULL;
    m_hEvtRead = NULL;
    m_hEvtWrite = NULL;
    m_hEvtClose = NULL;
    m_szConnID[0] = '\0';
}


//****************************************************************************
//
//    FUNCTION:   CPluggableTransport::~CPluggableTransport()
//
//    PURPOSE:    Destruction

//    COMMENTS:
//      
//
//****************************************************************************

CPluggableTransport::~CPluggableTransport()
{}


//****************************************************************************
//
//    FUNCTION:   HRESULT CPluggableTransport::Initialize(INmManager *pINmManager)
//
//    PURPOSE:    Initializes PluggableTransport and all member variables

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT CPluggableTransport::Initialize(INmManager *pINmManager)
{
    if (pINmManager)
        if (FAILED(pINmManager->QueryInterface(IID_IPluggableTransport, (PVOID *) &m_pIPlugTrans)))
            return E_FAIL;


    m_pX224 = new CX224();
    m_pPSTN = new CPSTN();
    m_hEvtRead = ::CreateEvent(NULL, FALSE, FALSE, NULL);
    m_hEvtWrite = ::CreateEvent(NULL, FALSE, FALSE, NULL);
    m_hEvtClose = ::CreateEvent(NULL, FALSE, FALSE, NULL);

    if (!m_hEvtRead || !m_hEvtWrite || !m_hEvtClose)
        return E_FAIL;

    return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CPluggableTransport::Uninitialize()
//
//    PURPOSE:    Clean up

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT CPluggableTransport::Uninitialize()
{

    if (m_pX224)
    {
        m_pX224->CloseSocket();
        m_pX224->CloseListenSocket();
        delete m_pX224;
    }

    if (m_pPSTN)
    {
        m_pPSTN->CloseComPort();
        delete m_pPSTN;
    }

    if (m_pIPlugTrans)
    {
        m_pIPlugTrans->Release();
    }

    // the handles to the events will be closed automatically
    // no need to call CloseHandle()
    return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   BOOL CPluggableTransport::InConnection()
//
//    PURPOSE: 

//    COMMENTS:
//      
//
//****************************************************************************

BOOL CPluggableTransport::InConnection()
{
    return m_bInConnection;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CPluggableTransport::CreateConnection()
//
//    PURPOSE:    Connect the X224 pluggable transport with the T120 (as a caller)

//    COMMENTS:
//     
//
//****************************************************************************

HRESULT CPluggableTransport::CreateConnection()
{
    HANDLE hCommLink = NULL;
    HRESULT hr = S_OK;

    if (!m_pX224)
        return E_FAIL;

    if (m_pX224->GetSocket() == INVALID_SOCKET)
        return E_FAIL;

    BOOL fRet = DuplicateHandle(GetCurrentProcess(), (HANDLE) m_pX224->GetSocket(),
                          GetCurrentProcess(), &hCommLink,
                          0, FALSE, DUPLICATE_SAME_ACCESS);
                      
    BSTR bstrConnID = NULL;
    PLUGXPRT_PARAMETERS Params;

    ::ZeroMemory(&Params, sizeof(Params));
    Params.cbStructSize = sizeof(Params);

    hr = m_pIPlugTrans->CreateConnection(
                &bstrConnID,
                PLUGXPRT_CALLER, // caller
                GetCurrentProcessId(),
                (HCOMMDEV) hCommLink,
                (HEVENT) m_hEvtRead,
                (HEVENT) m_hEvtWrite,
                (HEVENT) m_hEvtClose,
                FRAMING_X224,
                &Params);

    if (SUCCEEDED(hr))
    {
        BSTR2LPSTR(bstrConnID, m_szConnID);
        m_bInConnection = true;
    }

    return hr;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CPluggableTransport::CreateConnection(LPSTR pszComPort)
//
//    PURPOSE:    Connect the PSTN pluggable transport with the T120 (as a caller)

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT CPluggableTransport::CreateConnection(LPSTR pszComPort)
{
    HANDLE hCommLink = NULL;
    HRESULT hr = S_OK;
    PLUGXPRT_PARAMETERS PluggableParams;

    if (!m_pPSTN)
        return E_FAIL;

    ZeroMemory(&PluggableParams, sizeof(PluggableParams));
    PluggableParams.cbStructSize = sizeof(PluggableParams);
    PluggableParams.dwFlags = PSTN_PARAM__CALL_CONTROL |
                                PSTN_PARAM__READ_FILE_BUFFER_SIZE |
                                PSTN_PARAM__PHYSICAL_LAYER_SEND_BUFFER_SIZE |
                                PSTN_PARAM__PHSYICAL_LAYER_RECV_BUFFER_SIZE |
                                PSTN_PARAM__MAX_T200_TIMEOUT_COUNT_IN_Q922 |
                                PSTN_PARAM__T203_TIMEOUT_IN_Q922;
    PluggableParams.eCallControl = PLUGXPRT_PSTN_CALL_CONTROL_MANUAL;
    PluggableParams.cbReadFileBufferSize = 10240; // 10K
    PluggableParams.cbPhysicalLayerSendBufferSize = 1024; // 1K
    PluggableParams.cbPhysicalLayerReceiveBufferSize = 10240; // 10K
    PluggableParams.cMaximumT200TimeoutsInQ922 = 200;
    PluggableParams.nT203TimeoutInQ922 = 6000;

    // open the com port and get a handle to it
    if (FAILED(m_pPSTN->CreateComPort(1, pszComPort)))
        return E_FAIL;

    if (!m_pPSTN->GetCommLink())
        return E_FAIL;

    BOOL fRet = DuplicateHandle(GetCurrentProcess(), m_pPSTN->GetCommLink(),
                          GetCurrentProcess(), &hCommLink,
                          0, FALSE, DUPLICATE_SAME_ACCESS);
    if (!fRet)
        return E_FAIL;
                      
    BSTR bstrConnID = NULL;

    hr = m_pIPlugTrans->CreateConnection(
                &bstrConnID,
                PLUGXPRT_CALLER, // caller
                GetCurrentProcessId(),
                (HCOMMDEV) hCommLink,
                (HEVENT) m_hEvtRead,
                (HEVENT) m_hEvtWrite,
                (HEVENT) m_hEvtClose,
                FRAMING_LEGACY_PSTN,
                &PluggableParams);

    if (SUCCEEDED(hr))
    {
        BSTR2LPSTR(bstrConnID, m_szConnID);
        m_bInConnection = true;
    }

    return hr;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CPluggableTransport::AcceptConnection(HWND hWnd)
//
//    PURPOSE:    Connects the X224 pluggable transport with the T120 (as a callee)

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT CPluggableTransport::AcceptConnection(HWND hWnd)
{
    HRESULT hr = S_OK;
    HANDLE hCommLink = NULL;

    if (!m_pX224)
        return E_FAIL;

    if (FAILED(m_pX224->CreateAcceptSocket(hWnd)))
        return E_FAIL;

    if (m_pX224->GetSocket() == INVALID_SOCKET)
        return E_FAIL;

    BOOL fRet = ::DuplicateHandle(::GetCurrentProcess(), (HANDLE) m_pX224->GetSocket(),
                     ::GetCurrentProcess(), &hCommLink,
                     0, FALSE, DUPLICATE_SAME_ACCESS);
    if (!fRet)
        return E_FAIL;

    BSTR bstrConnID = NULL;
    PLUGXPRT_PARAMETERS Params;

    ::ZeroMemory(&Params, sizeof(Params));
    Params.cbStructSize = sizeof(Params);

    hr = m_pIPlugTrans->CreateConnection(
            &bstrConnID,
            PLUGXPRT_CALLEE, // callee
            GetCurrentProcessId(),
            (HCOMMDEV) hCommLink,
            (HEVENT) m_hEvtRead,
            (HEVENT) m_hEvtWrite,
            (HEVENT) m_hEvtClose,
            FRAMING_X224,
            &Params);
                
    if (SUCCEEDED(hr))
    {
        BSTR2LPSTR(bstrConnID, m_szConnID);
        m_bInConnection = true;
    }

    return hr;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CPluggableTransport::AcceptConnection(LPSTR pszComPort)
//
//    PURPOSE:    Connects the PSTN pluggable transport with the T120 (as a callee)

//    COMMENTS:
//       
//
//****************************************************************************

HRESULT CPluggableTransport::AcceptConnection(LPSTR pszComPort)
{
    HANDLE hCommLink = NULL;
    HRESULT hr = S_OK;
    PLUGXPRT_PARAMETERS PluggableParams;

    if (!m_pPSTN)
        return E_FAIL;

    ZeroMemory(&PluggableParams, sizeof(PluggableParams));
    PluggableParams.cbStructSize = sizeof(PluggableParams);
    PluggableParams.dwFlags = PSTN_PARAM__CALL_CONTROL |
                                PSTN_PARAM__READ_FILE_BUFFER_SIZE |
                                PSTN_PARAM__PHYSICAL_LAYER_SEND_BUFFER_SIZE |
                                PSTN_PARAM__PHSYICAL_LAYER_RECV_BUFFER_SIZE |
                                PSTN_PARAM__MAX_T200_TIMEOUT_COUNT_IN_Q922 |
                                PSTN_PARAM__T203_TIMEOUT_IN_Q922;
    PluggableParams.eCallControl = PLUGXPRT_PSTN_CALL_CONTROL_MANUAL;
    PluggableParams.cbReadFileBufferSize = 10240; // 10K
    PluggableParams.cbPhysicalLayerSendBufferSize = 1024; // 1K
    PluggableParams.cbPhysicalLayerReceiveBufferSize = 10240; // 10K
    PluggableParams.cMaximumT200TimeoutsInQ922 = 200;
    PluggableParams.nT203TimeoutInQ922 = 6000;

    // open the com port and get a handle to it
    hr = m_pPSTN->CreateComPort(1, pszComPort);
    if (FAILED(hr))
        return E_FAIL;

    if (!m_pPSTN->GetCommLink())
        return E_FAIL;

    BOOL fRet = DuplicateHandle(GetCurrentProcess(), m_pPSTN->GetCommLink(),
                          GetCurrentProcess(), &hCommLink,
                          0, FALSE, DUPLICATE_SAME_ACCESS);
    if (!fRet)
        return E_FAIL;
                      
    BSTR bstrConnID = NULL;

    hr = m_pIPlugTrans->CreateConnection(
                &bstrConnID,
                PLUGXPRT_CALLEE, // caller
                GetCurrentProcessId(),
                (HCOMMDEV) hCommLink,
                (HEVENT) m_hEvtRead,
                (HEVENT) m_hEvtWrite,
                (HEVENT) m_hEvtClose,
                FRAMING_LEGACY_PSTN,
                &PluggableParams);

    if (SUCCEEDED(hr))
    {
        BSTR2LPSTR(bstrConnID, m_szConnID);
        m_bInConnection = true;
    }

    return hr;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CPluggableTransport::CloseConnection(PLUGXPRT_FRAMING eFraming)
//
//    PURPOSE:    Disconnects the pluggable transport from T120

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT CPluggableTransport::CloseConnection(PLUGXPRT_FRAMING eFraming)
{
    HRESULT hr = S_OK;
    BSTR bstrConnID = NULL;

    bstrConnID = LPSTR2BSTR(m_szConnID);

    if (!m_pIPlugTrans)
        return E_FAIL;

    if (lstrcmp(m_szConnID, ""))
    {
        hr = m_pIPlugTrans->CloseConnection(bstrConnID);
        lstrcpy(m_szConnID, "");
    }
    
    if (eFraming == FRAMING_X224)
    {
        m_pX224->CloseSocket();
    }

    if (eFraming == FRAMING_LEGACY_PSTN)
    {
        m_pPSTN->CloseComPort();
    }

    if (SUCCEEDED(hr))
        m_bInConnection = false;

    return hr;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CPluggabletransport::EnableWinsock()
//
//    PURPOSE:

//    COMMENTS:
//     
//
//****************************************************************************

HRESULT CPluggableTransport::EnableWinsock()
{
    HRESULT hr = E_FAIL;

    if (m_pIPlugTrans)
        hr = m_pIPlugTrans->EnableWinsock();

    return hr;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CPluggabletransport::DisableWinsock()
//
//    PURPOSE:

//    COMMENTS:
//     
//
//****************************************************************************

HRESULT CPluggableTransport::DisableWinsock()
{
    HRESULT hr = E_FAIL;

    if (m_pIPlugTrans)
        hr = m_pIPlugTrans->DisableWinsock();

    return hr;
}


//****************************************************************************
//
//    FUNCTION:   LPSTR CPluggableTransport::GetConnectionID()
//
//    PURPOSE: 

//    COMMENTS:
//     
//
//****************************************************************************

LPSTR CPluggableTransport::GetConnectionID()
{
    return m_szConnID;
}