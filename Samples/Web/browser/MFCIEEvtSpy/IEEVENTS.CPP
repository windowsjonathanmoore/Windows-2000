/**************************************************************************
   THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
   ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
   PARTICULAR PURPOSE.

   Copyright 1999 - 2000 Microsoft Corporation.  All Rights Reserved.
**************************************************************************/




// IEEvents.cpp : implementation file
//
// This source code is provided as-is, without warranty.
//
// Created by S. R.
// Microsoft Developer Support - Internet Client SDK
/////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCIEEvtSpy.h"
#include "IEEvents.h"
#include "MFCIEEvtSpyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIEEvents

IMPLEMENT_DYNCREATE(CIEEvents, CCmdTarget)

CIEEvents::CIEEvents(CMFCIEEvtSpyDlg* pParent /* = NULL */) : m_pParent(pParent)
{
   ASSERT(m_pParent);

   EnableAutomation();  // Needed in order to sink events.
}

CIEEvents::~CIEEvents()
{
}


BEGIN_MESSAGE_MAP(CIEEvents, CCmdTarget)
	//{{AFX_MSG_MAP(CIEEvents)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CIEEvents, CCmdTarget)
	DISP_FUNCTION_ID(CIEEvents, "BeforeNavigate2", DISPID_BEFORENAVIGATE2,
                    OnBeforeNavigate2, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT
                    VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PBOOL)

	DISP_FUNCTION_ID(CIEEvents, "CommandStateChange", DISPID_COMMANDSTATECHANGE,
                    OnCommandStateChange, VT_EMPTY, VTS_I4 VTS_BOOL)

   DISP_FUNCTION_ID(CIEEvents, "DocumentComplete", DISPID_DOCUMENTCOMPLETE,
                    OnDocumentComplete, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT)

	DISP_FUNCTION_ID(CIEEvents, "DownloadComplete", DISPID_DOWNLOADCOMPLETE,
                    OnDownloadComplete, VT_EMPTY, VTS_NONE)

	DISP_FUNCTION_ID(CIEEvents, "NavigateComplete2", DISPID_NAVIGATECOMPLETE2,
                    OnNavigateComplete2, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT)

	DISP_FUNCTION_ID(CIEEvents, "NewWindow2", DISPID_NEWWINDOW2, 
                    OnNewWindow2, VT_EMPTY, VTS_DISPATCH VTS_PBOOL)

	DISP_FUNCTION_ID(CIEEvents, "OnQuit", DISPID_ONQUIT, OnQuit, VT_EMPTY, VTS_NONE)

	DISP_FUNCTION_ID(CIEEvents, "ProgressChange", DISPID_PROGRESSCHANGE,
                    OnProgressChange, VT_EMPTY, VTS_I4 VTS_I4)

	DISP_FUNCTION_ID(CIEEvents, "StatusTextChange", DISPID_STATUSTEXTCHANGE,
                    OnStatusTextChange, VT_EMPTY, VTS_BSTR)

	DISP_FUNCTION_ID(CIEEvents, "TitleChange", DISPID_TITLECHANGE,
                    OnTitleChange, VT_EMPTY, VTS_BSTR)
END_DISPATCH_MAP()

//
// Add DIID_DWebBrowserEvents2 to the interface map to tell
// IE that we support this event sink.  IE will QI for 
// this interface when we call AfxConnectionAdvise.  If IE
// does not find this interface, it will then QI for IDispatch.
//
BEGIN_INTERFACE_MAP(CIEEvents, CCmdTarget)
	INTERFACE_PART(CIEEvents, DIID_DWebBrowserEvents2, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIEEvents event handlers
void CIEEvents::OnBeforeNavigate2(LPDISPATCH pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers, BOOL* Cancel)
{
   USES_CONVERSION;

   CString strEvt("BeforeNavigate2: ");
   strEvt += OLE2T(URL->bstrVal);

   m_pParent->AddEventToList(CMFCIEEvtSpyDlg::IEListBox, strEvt);
}

void CIEEvents::OnCommandStateChange(long lCommand, BOOL bEnable)
{
   CString strEvt;
   strEvt.Format("CommandStateChange: Command = %ld  Enable = %d", lCommand, bEnable);

   m_pParent->AddEventToList(CMFCIEEvtSpyDlg::IEListBox, strEvt);
}

void CIEEvents::OnDocumentComplete(LPDISPATCH pDisp, VARIANT* URL)
{
   USES_CONVERSION;

   CString strEvt("DocumentComplete: ");
   strEvt += OLE2T(URL->bstrVal);

   m_pParent->AddEventToList(CMFCIEEvtSpyDlg::IEListBox, strEvt);
}

void CIEEvents::OnDownloadComplete() 
{
   m_pParent->AddEventToList(CMFCIEEvtSpyDlg::IEListBox, "OnDownloadComplete");
}

void CIEEvents::OnNavigateComplete2(LPDISPATCH pDisp, VARIANT* URL)
{
   USES_CONVERSION;

   CString strEvt("NavigateComplete2: ");
   strEvt += OLE2T(URL->bstrVal);

   m_pParent->AddEventToList(CMFCIEEvtSpyDlg::IEListBox, strEvt);
}

void CIEEvents::OnNewWindow2(LPDISPATCH* ppDisp, BOOL* Cancel)
{
	m_pParent->AddEventToList(CMFCIEEvtSpyDlg::IEListBox, "NewWindow2");
}

void CIEEvents::OnProgressChange(long lProgress, long lProgressMax)
{
   CString strEvt;
   strEvt.Format("ProgressChange: Progress = %ld  ProgressMax = %ld", lProgress, lProgressMax);

	m_pParent->AddEventToList(CMFCIEEvtSpyDlg::IEListBox, strEvt);
}

void CIEEvents::OnStatusTextChange(LPCTSTR lpszText) 
{
   CString strEvt("StatusTextChange: ");
   strEvt += lpszText;

   m_pParent->AddEventToList(CMFCIEEvtSpyDlg::IEListBox, strEvt);
}

void CIEEvents::OnTitleChange(LPCTSTR lpszText) 
{
   CString strEvt("TitleChange: ");
   strEvt += lpszText;

   m_pParent->AddEventToList(CMFCIEEvtSpyDlg::IEListBox, strEvt);
}

void CIEEvents::OnQuit()
{
	m_pParent->AddEventToList(CMFCIEEvtSpyDlg::IEListBox, "Quit");
   m_pParent->OnIEQuit();
}
