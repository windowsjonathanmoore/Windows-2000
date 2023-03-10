//****************************************************************************
//  Module:     NMUI.EXE
//  File:       CDATA.CPP
//  Content:    INmChannelData Routines
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

INmChannelAppShare * g_pChannelAppShare;
CAppShareNotify * g_pNotifyAppShare;

static BOOL fRobCheck = FALSE;

// From CKIM
VOID DoEnumApps(void)
{
	HRESULT hr;
	ULONG cFetched;
	IEnumNmSharableApp * pEnum;
	INmSharableApp * pApp;


	if (NULL == g_pChannelAppShare)
		return;

	if(fRobCheck != FALSE)
	{
		MessageBox(NULL, "Hey! bozo!!!", "Error!!!", MB_OK);
	}

	fRobCheck = TRUE;

	hr = g_pChannelAppShare->EnumSharableApp(&pEnum); 

	if (FAILED(hr))
		return;

	while (1)
	{
		hr = pEnum->Next(1, &pApp, &cFetched);
		if (S_OK != hr)
			break;
		pApp->Release();
	}

	pEnum->Release();

	fRobCheck = FALSE;

}


//****************************************************************************
//
// HRESULT HookAppShare(INmChannel * pChannel)
//
//****************************************************************************




HRESULT HookAppShare(INmChannel * pChannel)
{
	HRESULT hr;
	CAppShareNotify * pNotify;

	ASSERT(NULL != pChannel);
	if (NULL != g_pChannelAppShare)
	{
		ERROR_MSG("HookAppShare: replacing existing g_pChannelAppShare");
	}

	hr = pChannel->QueryInterface(IID_INmChannelAppShare, (void **)&g_pChannelAppShare);
	if (FAILED(hr))
	{
		ERROR_MSG("HookAppShare:Unable to get Application Sharing Channel");
		return hr;
	}
	// keep QI ref around

    // Connect to the channel object
    pNotify = new CAppShareNotify();
    if (pNotify == NULL)
    {
        hr = E_OUTOFMEMORY;
    }
    else
    {
		hr = pNotify->Connect(g_pChannelAppShare);
		if (FAILED(hr))
		{
			ERROR_MSG("CConfNotify Failed (%s)", GetHrSz(hr));
			pNotify->Release();
		}
		else
		{
			OBJECT_MSG("AppSharing Connection point established successfully");
			g_pNotifyAppShare = pNotify;
		}
	}

	if (FAILED(hr))
	{
		g_pChannelAppShare->Release();
		g_pChannelAppShare = NULL;
	}

	return hr;
}


//****************************************************************************
//
// VOID FreeAs(void)
//
//****************************************************************************

VOID FreeAs(void)
{
	if(NULL != g_pNotifyAppShare)
	{
		g_pNotifyAppShare->Disconnect();
		g_pNotifyAppShare->Release();
		g_pNotifyAppShare = NULL;
	}

	if (NULL != g_pChannelAppShare)
	{
		g_pChannelAppShare->Release();
		g_pChannelAppShare = NULL;
	}
}



//****************************************************************************
//
// CLASS CAppShareNotify
//
//****************************************************************************

CAppShareNotify::CAppShareNotify() : RefCount(), CNotify()
{
	OBJECT_MSG("CAppShareNotify created");
}

CAppShareNotify::~CAppShareNotify()
{
	OBJECT_MSG("CAppShareNotify destroyed");
}


//****************************************************************************
//
// Methods from IUnknown
//
//****************************************************************************

ULONG STDMETHODCALLTYPE CAppShareNotify::AddRef(void)
{
	return RefCount::AddRef();
}


ULONG STDMETHODCALLTYPE CAppShareNotify::Release(void)
{
	return RefCount::Release();
}

HRESULT STDMETHODCALLTYPE CAppShareNotify::QueryInterface(REFIID riid, PVOID *ppvObject)
{
	HRESULT hr = S_OK;

	if (riid == IID_IUnknown)
	{
		*ppvObject = (IUnknown *)this;
		OBJECT_MSG("CAppShareNotify::QueryInterface(): Returning IUnknown.");
	}
	else if (riid == IID_INmChannelAppShareNotify)
	{
		*ppvObject = (INmChannelAppShareNotify *)this;
		OBJECT_MSG("CAppShareNotify::QueryInterface(): Returning INmChannelAppShareNotify.");
	}
	else
	{
		hr = E_NOINTERFACE;
		*ppvObject = NULL;
		OBJECT_MSG("CAppShareNotify::QueryInterface(): Called on unknown interface.");
	}

	if (S_OK == hr)
	{
		AddRef();
	}

	return hr;
}


//****************************************************************************
//
// Methods from ICNotify
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CAppShareNotify::Connect(IUnknown *pUnk)
{
	return CNotify::Connect(pUnk, IID_INmChannelAppShareNotify, (IUnknown *)this);
}

HRESULT STDMETHODCALLTYPE CAppShareNotify::Disconnect(void)
{
	return CNotify::Disconnect();
}


//****************************************************************************
//
// HRESULT STDMETHODCALLTYPE CAppShareNotify::NmUI(CONFN uNotify)
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CAppShareNotify::NmUI(CONFN uNotify)
{
	NOTIFY_MSG("CAppShareNotify::NmUI uNotify=%08X, pChannel=%08X", uNotify, CNotify::GetPunk());
	return S_OK;
}


//****************************************************************************
//
// HRESULT STDMETHODCALLTYPE CAppShareNotify::MemberChanged(NM_MEMBER_NOTIFY uNotify, INmMember *pMember)
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CAppShareNotify::MemberChanged(NM_MEMBER_NOTIFY uNotify, INmMember *pMember)
{
	NOTIFY_MSG("CAppShareNotify::MemberChanged uNotify=%d pMember=%08X, pChannel=%08X", uNotify, pMember, CNotify::GetPunk());

	PUSER pUser = PUserFromINmMember(pMember);
	if (NULL != pUser)
	{
		UpdateUserChannel(pUser, (INmChannel *) (CNotify::GetPunk()), uNotify);
	}

	return S_OK;
}



//****************************************************************************
//
// HRESULT STDMETHODCALLTYPE CAppShareNotify::StateChanged(NM_SHAPP_STATE uState, INmSharableApp *pApp)
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CAppShareNotify::StateChanged(NM_SHAPP_STATE uState, INmSharableApp *pApp)
{
	TCHAR szState[MAX_PATH];
	BSTR bstrApp;
	LPTSTR pszApp;

	HRESULT hr;

	// Get the new share state
	wsprintf(szState, "%s", ((uState == NM_SHAPP_SHARED) ? "shared" : "not shared"));

	// Get the application information
	hr = pApp->GetName(&bstrApp);
	if(SUCCEEDED(hr))
	{
		pszApp = PszFromBstr(bstrApp);
		SysFreeString(bstrApp);
	}

	STATE_MSG("CAppShareNotify::StateChanged received.");
	STATE_MSG("New state for [%s] is %s", pszApp, szState);

	return S_OK;
}


