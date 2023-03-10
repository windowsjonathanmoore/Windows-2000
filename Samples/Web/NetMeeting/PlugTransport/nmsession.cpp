//****************************************************************************
//  Module:     PLUGTRANSPORT.EXE     
//  File:       NMSESSION.CPP
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


//***********************
//FUNCTION DECLARATIONS
//***********************

BSTR LPSTR2BSTR(LPSTR pszString);
BOOL BSTR2LPSTR(BSTR bstrConnID, LPSTR pszConnID);


//**********************************
//
// CLASS Conf
//
//**********************************

//****************************************************************************
//
//    FUNCTION:   Conf::Conf(HWND hWnd)
//
//    PURPOSE:    Construction

//    COMMENTS:
//       
//        
//
//****************************************************************************

Conf::Conf(HWND hWnd)
{
    // Create Sink Objects.
    // During construction, AddRef occurs
    m_pMgrNotify = new CMgrNotify(this);  
    m_pCallNotify = new CCallNotify(this);
    m_pConfNotify = new CConfNotify(this);

    // NULL all other variables
    m_pINmMgr = NULL;
    m_pINmConf = NULL;
    m_pINmCall = NULL;
    m_bInCall = FALSE;

    // Get the handler to the application window
    m_hWnd = hWnd;
}


//****************************************************************************
//
//    FUNCTION:   Conf::~Conf()
//
//    PURPOSE:    Destruction

//    COMMENTS:
//      
//        
//
//****************************************************************************

Conf::~Conf()
{
    //clean up the notification sink objects
    // everything else will be cleaned in the Uninitialize function
    m_pMgrNotify->Release();  
    m_pCallNotify->Release();
    m_pConfNotify->Release();
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::Initialize()
//
//    PURPOSE:    Initiate NetMeeting, obtain a pointer to INmManager, 
//                connect the MgrNotify sink object and initialize INmManager.
//
//    COMMENTS:
//                      
//
//****************************************************************************

HRESULT Conf::Initialize()
{
    if (FAILED(CoCreateInstance(CLSID_NmManager,NULL,CLSCTX_INPROC_SERVER,IID_INmManager,(VOID **)&m_pINmMgr)))
        return E_FAIL;
	
    // Don't display the NetMeeting UI
    ULONG uOptions = NM_INIT_CONTROL;
    // data only conference
    ULONG uCaps = NMCH_DATA | NMCH_FT | NMCH_SHARE;
	
    if (FAILED(m_pMgrNotify->Connect(m_pINmMgr)))
        return E_FAIL;
 
    if (FAILED(m_pINmMgr->Initialize(&uOptions,&uCaps)))
	    return E_FAIL;

    return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::Uninitialize()
//
//    PURPOSE:    Disconnect MgrNotify sink object and release the interface INmManager
//
//    COMMENTS:
//
//        
//        
//        
//
//****************************************************************************

HRESULT Conf::Uninitialize()
{
    if (m_pMgrNotify)
	    m_pMgrNotify->Disconnect();

    if (m_pINmMgr)
	    m_pINmMgr->Release();

    return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::Call(CPluggableTransport *pPlugTrans)
//
//    PURPOSE:    Make the call using the already created transport connection
//
//    COMMENTS:
//    
//
//****************************************************************************

HRESULT Conf::Call(CPluggableTransport *pPlugTrans)
{
    if (!pPlugTrans)
        return E_FAIL;

    if (!pPlugTrans->InConnection())
        return E_FAIL;

    // get the BSTR form of the connection ID
    BSTR bstrName = NULL;
    bstrName = LPSTR2BSTR(pPlugTrans->GetConnectionID());
    
    // make the call
	if (FAILED(m_pINmMgr->CreateCall(&m_pINmCall, NM_CALL_DEFAULT, NM_ADDR_T120_TRANSPORT, bstrName, NULL)))
	{
		// Call object sometimes needs to be released.
		if (m_pINmCall)
		{
			m_pCallNotify->Disconnect();
			m_pINmCall->Release();
		}
        return E_FAIL;
	}
	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::HangUp()
//
//    PURPOSE:   Leave the conference

//    COMMENTS:
//       
//
//****************************************************************************

HRESULT Conf::HangUp()
{
	HRESULT hr = S_OK;

	// if call hungup before Call accepted or rejected, release INmCall and 
	// disconnect CallNotify sink
	if (m_pINmCall)
	{
		hr = m_pINmCall->Cancel();
		m_pCallNotify->Disconnect();
		m_pINmCall->Release();
		m_pINmCall=NULL;
	}
	else
		if (m_pINmConf)
			hr = m_pINmConf->Leave();


	// Release INmConf and disconnect the ConfNotify sink
	if (m_pINmConf)
	{
		m_pINmConf->Release();
		m_pINmConf=NULL;
		m_pConfNotify->Disconnect();
	}
	
	m_bInCall = false;

    // update the UI
	if (m_hWnd)
		SendMessage(m_hWnd,WM_DISCONNECTED,0,0);

	return hr;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::CallCreated(INmCall * pCall)
//
//    PURPOSE:    Callback from the MgrNotify sink object

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT Conf::CallCreated(INmCall * pCall)
{
	m_pINmCall = pCall;
	m_pINmCall->AddRef();
	m_pCallNotify->Connect(pCall);
	m_bInCall = true;

    // update the UI
	if (m_hWnd)
		SendMessage(m_hWnd,WM_CONNECTING,0,0);

	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::AcceptCall()
//
//    PURPOSE:    Accept the incoming call

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT Conf::AcceptCall()
{
	return m_pINmCall->Accept();
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::RejectCall()  
//
//    PURPOSE:    Reject the incoming call

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT Conf::RejectCall()  
{
	return m_pINmCall->Reject();
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::ConferenceCreated(INmConference *pINmConf)
//
//    PURPOSE:    Callback from the MgrNotify sink object that 
//                a new conference has been created
//
//    COMMENTS:
//      
//
//****************************************************************************

HRESULT Conf::ConferenceCreated(INmConference *pINmConf)
{	
	//Add Conference notification sink to handle channels.
	m_pINmConf=pINmConf;
	m_pINmConf->AddRef();
	m_pConfNotify->Connect(pINmConf);
	m_bInCall = true;

	if (m_hWnd)
		SendMessage(m_hWnd,WM_CONNECTED,0,0);

	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::CallAccepted()  
//
//    PURPOSE:    Callback from the CallNotify sink object that 
//                the new call has been accepted

//    COMMENTS:
//       
//
//****************************************************************************

HRESULT Conf::CallAccepted()  
{
	// Release INmCall, and let send window message that a user has connected
	if (m_pINmCall)
		m_pINmCall->Release();

	m_pINmCall=NULL;
	m_pCallNotify->Disconnect();
	m_bInCall = true;

	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::CallRejected() 
//
//    PURPOSE:    Callback from the CallNotify sink object that 
//                the new call has been rejected

//    COMMENTS:
//       
//
//****************************************************************************

HRESULT Conf::CallRejected() 
{					
	// Release INmCall, INmConf, disconnect CallNotify and ConfNotify
	// sink objects, and send message to main window that the user has 
	// disconnected.	
	if (m_pINmCall)
	{
		m_pCallNotify->Disconnect();
		m_pINmCall->Release();
		m_pINmCall=NULL;
	}

	if (m_pINmConf)
	{
		m_pINmConf->Release();
		m_pINmConf=NULL;
	}
	m_pConfNotify->Disconnect();
	m_bInCall = false;

	if (m_hWnd)
		SendMessage(m_hWnd,WM_DISCONNECTED,0,0);

	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT Conf::RemoteHungup()
//
//    PURPOSE:    Callback from the ConfNotify sink object 
//                that a member has left the conference

//    COMMENTS:
//       
//        
//
//****************************************************************************

HRESULT Conf::RemoteHungup()
{	

	// Release INmConf, disconnect ConfNotify sink object, and send message to 
	// main window that the remote node has disconnected.
	m_pINmConf->Release();
	m_pINmConf = NULL;
	m_pConfNotify->Disconnect();
	m_bInCall = false;

	if (m_hWnd)
		SendMessage(m_hWnd,WM_DISCONNECTED,0,0);
	
	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   BOOL Conf::InCall()
//
//    PURPOSE: 
//
//    COMMENTS:
//       
//
//****************************************************************************

BOOL Conf::InCall()
{	
	return m_bInCall;
}


//****************************************************************************
//
//    FUNCTION:   INmManager * Conf::GetNmManager()
//
//    PURPOSE: 
//
//    COMMENTS:
//      
//        
//
//****************************************************************************

INmManager * Conf::GetNmManager()
{
    return m_pINmMgr;
}



//****************************************************************************
//
// CLASS CCallNotify
//
//****************************************************************************

//****************************************************************************
//
//    FUNCTION:   CCallNotify::CCallNotify()
//
//    PURPOSE:    Construction

//    COMMENTS:     
//
//****************************************************************************

CCallNotify::CCallNotify()
{}


//****************************************************************************
//
//    FUNCTION:   CCallNotify::CCallNotify(Conf *pConf)
//
//    PURPOSE:    Construction

//    COMMENTS:       
//
//****************************************************************************

CCallNotify::CCallNotify(Conf *pConf)
{
	m_pConf = pConf;
}

//****************************************************************************
//
//    FUNCTION:   CCallNotify::~CCallNotify()
//
//    PURPOSE:    Destruction

//    COMMENTS:
//
//        
//****************************************************************************

CCallNotify::~CCallNotify()
{}


//****************************************************************************
//
//    FUNCTION:   ULONG STDMETHODCALLTYPE CCallNotify::AddRef()
//
//    PURPOSE:    method from IUnknown
//
//    COMMENTS:
//              
//
//****************************************************************************

ULONG STDMETHODCALLTYPE CCallNotify::AddRef()
{
	return RefCount::AddRef();
}


//****************************************************************************
//
//    FUNCTION:   ULONG STDMETHODCALLTYPE CCallNotify::Release()
//
//    PURPOSE:    Method from IUnknown
//
//    COMMENTS:
//      
//
//****************************************************************************

ULONG STDMETHODCALLTYPE CCallNotify::Release()
{
	return RefCount::Release();
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CCallNotify::QueryInterface(REFIID riid, PVOID * ppvObject)
//
//    PURPOSE:    Method from IUnknown

//    COMMENTS:
//       
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CCallNotify::QueryInterface(REFIID riid, PVOID * ppvObject)
{
	*ppvObject = NULL;
	
	if (riid == IID_IUnknown)
		*ppvObject = (PVOID *)this;
	else if (riid == IID_INmCallNotify)
		*ppvObject = (PVOID *)this;
	else
		return E_NOINTERFACE;

	AddRef();
	return S_OK;
}

//****************************************************************************
//
//    FUNCTION:   HRESULT CCallNotify::Connect(IUnknown * pUnkOuter)
//
//    PURPOSE:    Sink connect method
//
//    COMMENTS:
//       
//
//****************************************************************************

HRESULT CCallNotify::Connect(IUnknown * pUnkOuter)
{
	return CNotify::Connect(pUnkOuter, IID_INmCallNotify, (IUnknown *)this);
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CCallNotify::Disconnect()
//
//    PURPOSE:    Sink disconnect method
//
//    COMMENTS:
//      
//
//****************************************************************************

HRESULT CCallNotify::Disconnect()
{
	return CNotify::Disconnect();
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CCallNotify::Failed(ULONG uError)
//
//    PURPOSE:    Sink notification method

//    COMMENTS:   
//
//    
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CCallNotify::Failed(ULONG uError)
{
	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:  HRESULT STDMETHODCALLTYPE CCallNotify::Accepted(INmConference *pConference) 
//
//    PURPOSE:   Sink notification method
//
//    COMMENTS:
//      
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CCallNotify::Accepted(INmConference *pConference)
{
	return S_OK;
}

//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CCallNotify::NmUI(CONFN uNotify)
//
//    PURPOSE:    Sink notification method

//    COMMENTS:
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CCallNotify::NmUI(CONFN uNotify)
{
	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CCallNotify::StateChanged(NM_CALL_STATE uState)
//
//    PURPOSE:    Sink notification method

//    COMMENTS:
//       
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CCallNotify::StateChanged(NM_CALL_STATE uState)
{
	switch (uState)
	{
	case NM_CALL_RING:
	
		// Query whether to accept the call and notify my Conf object the result.
		if (MessageBox(NULL,"Accept incoming call?","Call",MB_YESNO|MB_TASKMODAL)== IDYES)
			m_pConf->AcceptCall();
		else
			m_pConf->RejectCall();
		break;

	case NM_CALL_REJECTED:

		// Notify my Conf object that the call was rejected.
		m_pConf->CallRejected();
		break;

	case NM_CALL_ACCEPTED:

		// Notify my Conf object that the call was accepted
		m_pConf->CallAccepted();
		break;
	}
	return S_OK;
}



//****************************************************************************
//
// CLASS CConfNotify
//
//****************************************************************************

//****************************************************************************
//
//    FUNCTION:   CConfNotify::CConfNotify()
//
//    PURPOSE:    Construction
//
//    COMMENTS:
//      
//
//****************************************************************************

CConfNotify::CConfNotify()
{}


//****************************************************************************
//
//    FUNCTION:   CConfNotify::CConfNotify(Conf *pConf)
//
//    PURPOSE:    Construction

//    COMMENTS:
//      
//
//****************************************************************************

CConfNotify::CConfNotify(Conf *pConf)
{
	m_pConf = pConf;
}


//****************************************************************************
//
//    FUNCTION:   CConfNotify::~CConfNotify()
//
//    PURPOSE:    Destruction

//    COMMENTS:
//
//        
//        
//        
//
//****************************************************************************

CConfNotify::~CConfNotify()
{}


//****************************************************************************
//
//    FUNCTION:   ULONG STDMETHODCALLTYPE CConfNotify::AddRef()
//
//    PURPOSE:    Method from IUnknown

//    COMMENTS:
//
//****************************************************************************

ULONG STDMETHODCALLTYPE CConfNotify::AddRef()
{
	return RefCount::AddRef();
}


//****************************************************************************
//
//    FUNCTION:   ULONG STDMETHODCALLTYPE CConfNotify::Release()
//
//    PURPOSE:    Method from IUnknown

//    COMMENTS:
//
//****************************************************************************

ULONG STDMETHODCALLTYPE CConfNotify::Release()
{
	return RefCount::Release();
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CConfNotify::QueryInterface(REFIID riid, PVOID * ppvObject)
//
//    PURPOSE:    Method from IUnknown

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CConfNotify::QueryInterface(REFIID riid, PVOID * ppvObject)
{
	*ppvObject = NULL;
	
	if (riid == IID_IUnknown)
		*ppvObject = (PVOID *)this;
	else if (riid == IID_INmConferenceNotify)
		*ppvObject = (PVOID *)this;
	else
		return E_NOINTERFACE;

	AddRef();

	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CConfNotify::Connect(IUnknown * pUnkOuter)
//
//    PURPOSE:    Sink connect method

//    COMMENTS:       
//
//****************************************************************************

HRESULT CConfNotify::Connect(IUnknown * pUnkOuter)
{
	return CNotify::Connect(pUnkOuter, IID_INmConferenceNotify, (IUnknown *)this);
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CConfNotify::Disconnect()
//
//    PURPOSE:    Sink disconnect method 

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT CConfNotify::Disconnect()
{
	return CNotify::Disconnect();
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CConfNotify::ChannelChanged(NM_CHANNEL_NOTIFY uNotify, INmChannel * pChannel)
//
//    PURPOSE:    Sink notification method
//
//    COMMENTS:
//      
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CConfNotify::ChannelChanged(NM_CHANNEL_NOTIFY uNotify, INmChannel * pChannel)
{
	ULONG uCh;

    pChannel->AddRef();

	// When notified that a channel has been added add code to handle it.
    // We don't need the code below for this app. I keep it to make it easier
    // if somebody needs to handle a channel
	if (uNotify == NM_CHANNEL_ADDED)
		{
			pChannel->GetNmch(&uCh);
		}

	pChannel->Release();
	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CConfNotify::MemberChanged(NM_MEMBER_NOTIFY uNotify, INmMember * pMember)
//
//    PURPOSE:    Sink notification method
//
//    COMMENTS:
//
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CConfNotify::MemberChanged(NM_MEMBER_NOTIFY uNotify, INmMember * pMember)
{
	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CConfNotify::NmUI(CONFN uNotify)
//
//    PURPOSE:    Sink notification method

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CConfNotify::NmUI(CONFN uNotify)
{
	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CConfNotify::StateChanged(NM_CONFERENCE_STATE uState)
//
//    PURPOSE:    Sink notification method
//
//    COMMENTS:
//     
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CConfNotify::StateChanged(NM_CONFERENCE_STATE uState)
{
	// Notify my Conf object that the remote hungup.
	if (uState == NM_CONFERENCE_IDLE)
		m_pConf->RemoteHungup();

	return S_OK;
}



//****************************************************************************
//
// CLASS CMgrNotify
//
//****************************************************************************

//****************************************************************************
//
//    FUNCTION:   CMgrNotify::CMgrNotify()
//
//    PURPOSE:    Construction

//    COMMENTS:
//    
//
//****************************************************************************

CMgrNotify::CMgrNotify()
{}


//****************************************************************************
//
//    FUNCTION:   CMgrNotify::CMgrNotify(Conf * pConf)
// 
//    PURPOSE:    Construction

//    COMMENTS:
//      
//
//****************************************************************************

CMgrNotify::CMgrNotify(Conf * pConf)
{
	m_pConf = pConf;
}


//****************************************************************************
//
//    FUNCTION:   CMgrNotify::~CMgrNotify()
//
//    PURPOSE:    Destruction

//    COMMENTS:
//       
//
//****************************************************************************

CMgrNotify::~CMgrNotify()
{}


//****************************************************************************
//
//    FUNCTION:   ULONG STDMETHODCALLTYPE CMgrNotify::AddRef()
//
//    PURPOSE:    Method from IUnknown 

//    COMMENTS:
//      
//
//****************************************************************************

ULONG STDMETHODCALLTYPE CMgrNotify::AddRef()
{
	return RefCount::AddRef();
}


//****************************************************************************
//
//    FUNCTION:   ULONG STDMETHODCALLTYPE CMgrNotify::Release()
//
//    PURPOSE:    Method from IUnknown 

//    COMMENTS:
//     
//
//****************************************************************************

ULONG STDMETHODCALLTYPE CMgrNotify::Release()
{
	return RefCount::Release();
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CMgrNotify::QueryInterface(REFIID riid, PVOID * ppvObject)
//
//    PURPOSE:    Method from IUnknown 

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CMgrNotify::QueryInterface(REFIID riid, PVOID * ppvObject)
{
	*ppvObject = NULL;
	
	if (riid == IID_IUnknown)
		*ppvObject = (PVOID *)this;
	else if (riid == IID_INmManagerNotify)
		*ppvObject = (PVOID *)this;
	else
		return E_NOINTERFACE;

	AddRef();
	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CMgrNotify::Connect(IUnknown * pUnkOuter)
//
//    PURPOSE:    Sink connect method

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT CMgrNotify::Connect(IUnknown * pUnkOuter)
{
	return CNotify::Connect(pUnkOuter, IID_INmManagerNotify, (IUnknown *)this);
}


//****************************************************************************
//
//    FUNCTION:   HRESULT CMgrNotify::Disconnect()
//
//    PURPOSE:    Sink disconnect method

//    COMMENTS:
//       
//
//****************************************************************************

HRESULT CMgrNotify::Disconnect()
{
	return CNotify::Disconnect();
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CMgrNotify::CallCreated(INmCall * pCall)
//
//    PURPOSE:    Sink notification method

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CMgrNotify::CallCreated(INmCall * pCall)
{
	// Notify my Conf object that a Call object was created
	m_pConf->CallCreated(pCall);
	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CMgrNotify::ConferenceCreated(INmConference * pConference)
//
//    PURPOSE:    Sink notification method

//    COMMENTS:
//      
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CMgrNotify::ConferenceCreated(INmConference * pConference)
{
	// Notify my Conf object that a Conference object was created
	m_pConf->ConferenceCreated(pConference); 
	return S_OK;
}


//****************************************************************************
//
//    FUNCTION:   HRESULT STDMETHODCALLTYPE CMgrNotify::NmUI(CONFN uNotify)
//
//    PURPOSE:    Sink notification method

//    COMMENTS:
//     
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CMgrNotify::NmUI(CONFN uNotify)
{
	return S_OK;
}
