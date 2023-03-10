//****************************************************************************
//  Module:     NMUI.EXE
//  File:       CCFT.CPP
//  Content:    INmFt Routines
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

INmFt * g_pFt;
INmChannelFt * g_pChannelFt;
CFileTransferNotify * g_pNotifyFileTransfer;

//****************************************************************************
//
// HRESULT HookFileTransfer(INmChannel * pChannel)
//
// Hook into notification callback for the file transfer channel
// 
//****************************************************************************

HRESULT HookFileTransfer(INmChannel * pChannel)
{
	HRESULT hr;
	CFileTransferNotify * pNotify;

	ASSERT(NULL != pChannel);
	if(NULL != g_pChannelFt)
	{
		ERROR_MSG("HookFileTransfer: replacing existing g_pChannelFileTransfer");
	}

	hr = pChannel->QueryInterface(IID_INmChannelFt, (void **)&g_pChannelFt);
	if (FAILED(hr))
	{
		ERROR_MSG("HookFileTransfer:Unable to get File Transfer channel");
		return hr;
	}

	// Connect to the Ft object
	pNotify = new CFileTransferNotify();
	if(NULL == pNotify)
	{
		hr = E_OUTOFMEMORY;
	}
	else
	{
		hr = pNotify->Connect(g_pChannelFt);
		if(FAILED(hr))
		{
			ERROR_MSG("CFileTransferNotify Failed (%s)", GetHrSz(hr));
			pNotify->Release();
		}
		else
		{
			OBJECT_MSG("FileTransfer Connection point established successfully");
			g_pNotifyFileTransfer = pNotify;
		}
	}

	if(FAILED(hr))
	{
		g_pChannelFt->Release();
		g_pChannelFt = NULL;
	}
		
	return hr;
}



//****************************************************************************
//
// CLASS CFileTransferNotify
//
//****************************************************************************

CFileTransferNotify::CFileTransferNotify() : RefCount(), CNotify()
{
	OBJECT_MSG("CFileTransferNotify created");
}

CFileTransferNotify::~CFileTransferNotify()
{
	OBJECT_MSG("CFileTransferNotify destroyed");
}


//****************************************************************************
//
// Methods from IUnknown
//
//****************************************************************************

ULONG STDMETHODCALLTYPE CFileTransferNotify::AddRef(void)
{
	return RefCount::AddRef();
}


ULONG STDMETHODCALLTYPE CFileTransferNotify::Release(void)
{
	return RefCount::Release();
}

HRESULT STDMETHODCALLTYPE CFileTransferNotify::QueryInterface(REFIID riid, PVOID *ppvObject)
{
	HRESULT hr = S_OK;

	if (riid == IID_IUnknown)
	{
		*ppvObject = (IUnknown *)this;
		OBJECT_MSG("CFileTransferNotify::QueryInterface(): Returning IUnknown.");
	}
	else if (riid == IID_INmChannelFtNotify)
	{
		*ppvObject = (INmChannelNotify *)this;
		OBJECT_MSG("CChannelFtNotify::QueryInterface(): Returning INmChannelFtNotify.");
	}
	else
	{
		hr = E_NOINTERFACE;
		*ppvObject = NULL;
		OBJECT_MSG("CFileTransferNotify::QueryInterface(): Called on unknown interface.");
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

HRESULT STDMETHODCALLTYPE CFileTransferNotify::Connect(IUnknown *pUnk)
{
	return CNotify::Connect(pUnk, IID_INmChannelFtNotify, (IUnknown *)this);
}

HRESULT STDMETHODCALLTYPE CFileTransferNotify::Disconnect(void)
{
	return CNotify::Disconnect();
}


//****************************************************************************
//
// Methods from IConfNotify
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CFileTransferNotify::NmUI(CONFN uNotify)
{
	NOTIFY_MSG("CFileTransferNotify::NmUI uNotify=%08X, pChannel=%08X", uNotify, CNotify::GetPunk());
	return S_OK;
}


HRESULT STDMETHODCALLTYPE CFileTransferNotify::MemberChanged(NM_MEMBER_NOTIFY uNotify, INmMember *pMember)
{
	NOTIFY_MSG("CFileTransferNotify::MemberChanged uNotify=%d pMember=%08X, pChannel=%08X", uNotify, pMember, CNotify::GetPunk());

//PATRICK	PUSER pUser = PUserFromINmMember(pMember);
//PATRICK	if (NULL != pUser)
//PATRICK	{
//PATRICK		UpdateUserChannel(pUser, (INmChannel *) (CNotify::GetPunk()), uNotify);
//PATRICK	}

	return S_OK;
}

HRESULT STDMETHODCALLTYPE CFileTransferNotify::FtUpdate(CONFN uNotify, INmFt *pFt)
{
	ULONG ulBytes;
	INmMember *pMember;
	BSTR bstrName;
	LPTSTR psz = NULL;
	TCHAR  sz[MAX_PATH];
	HRESULT hr;

	hr = pFt->GetBytesTransferred(&ulBytes);
	if(FAILED(hr))
	{
		ERROR_MSG("GetBytes Failed hr=%s", GetHrSz(hr));
	}

	// get the Member object of the sender
	hr = pFt->GetMember(&pMember);
	if(FAILED(hr))
	{
		ERROR_MSG("GetMember Failed hr=%s", GetHrSz(hr));
	}
	
	NM_FT_STATE uState;
	pFt->GetState(&uState);

	if(NULL == pMember)
	{
		// file being sent to all members of the conference
		strncpy(sz, "BROADCAST", strlen("BROADCAST"));
		psz = (TCHAR *)&sz;
		
	NOTIFY_MSG("CFileTransferNotify::FtUpdate uNotify=%s, State = %d, pFt=%08X, bytes=%d from %s", 
			GetConfnSz(uNotify), uState, pFt, ulBytes, psz);

	}
	else
	{
		hr = pMember->GetName(&bstrName);
		if(FAILED(hr))
		{
			ERROR_MSG("GetName Failed hr=%s", GetHrSz(hr));
		}

		psz = PszFromBstr(bstrName);

		SysFreeString(bstrName);
		pMember->Release();

	NOTIFY_MSG("CFileTransferNotify::FtUpdate uNotify=%s, State = %d, pFt=%08X, bytes=%d from %s", 
			GetConfnSz(uNotify), uState, pFt, ulBytes, psz);

		FreePlpv(&psz);

	}

	return S_OK;
}


//****************************************************************************
//
// VOID DoFtCancel(void)
//
//****************************************************************************

VOID DoFtCancel(void)
{
	if (NULL == g_pFt)
		return;

	HRESULT hr = g_pFt->Cancel();
}


//****************************************************************************
//
// VOID FreeFt(void)
//
//****************************************************************************

VOID FreeFt(void)
{
	if (NULL != g_pFt)
	{
		g_pFt->Release();
		g_pFt = NULL;
	}
}




//****************************************************************************
//
// VOID SendFile(INmMember * pMember)
//
//****************************************************************************

VOID SendFile(INmMember * pMember)
{
	PUSER pUser = PUserLocal();
	if (NULL == pUser)
	{
		return;
	}

	if (NULL == pUser->m_pChannelFt)
	{
		return;
	}

	INmFt * pFt;
	BSTRING bstrFileName(gPref.pszFileName);
	HRESULT hr = pUser->m_pChannelFt->SendFile(&pFt, pMember, bstrFileName, 0);
	if (SUCCEEDED(hr))
	{
		INmMember *pMember;

		FreeFt();
		g_pFt = pFt;

		// PATRICK -- added for bug 141 in Cayman database
		hr = pFt->GetMember( &pMember );
		if(SUCCEEDED(hr))
		{
			if(NULL == pMember)
			{
				// file was sent to everyone
			}
			else
			{
				BSTR bstrName;
				
				// file was sent to this user
				hr = pMember->GetName(&bstrName);
				pMember->Release();
			}
		}
	}
}

