/**************************************************************************
   THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
   ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
   PARTICULAR PURPOSE.

   Copyright 1999 - 2000 Microsoft Corporation.  All Rights Reserved.
**************************************************************************/



// IEEvents.h: declaration of CIEEvents class
//
// This source code is provided as-is, without warranty.
//
// Created by S. R.
// Microsoft Developer Support - Internet Client SDK
/////////////////////////////////////////////////////////

#if !defined(AFX_IEEVENTS_H__66425985_9D94_11D1_ABEE_00D049C10000__INCLUDED_)
#define AFX_IEEVENTS_H__66425985_9D94_11D1_ABEE_00D049C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// IEEvents.h : header file
//

class CMFCIEEvtSpyDlg;

/////////////////////////////////////////////////////////////////////////////
// CIEEvents command target

class CIEEvents : public CCmdTarget
{
	DECLARE_DYNCREATE(CIEEvents)

	CIEEvents(CMFCIEEvtSpyDlg* pParent = NULL);           // protected constructor used by dynamic creation
	virtual ~CIEEvents();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIEEvents)
	//}}AFX_VIRTUAL

// Implementation
protected:
   CMFCIEEvtSpyDlg* m_pParent;

   // IE Events
	void OnBeforeNavigate2(LPDISPATCH pDisp, VARIANT* URL, VARIANT* Flags,
                          VARIANT* TargetFrameName, VARIANT* PostData,
                          VARIANT* Headers, BOOL* Cancel);
   void OnCommandStateChange(long lCommand, BOOL bEnable);
   void OnDocumentComplete(LPDISPATCH pDisp, VARIANT* URL);
   void OnDownloadComplete();
   void OnNavigateComplete2(LPDISPATCH pDisp, VARIANT* URL);
	void OnNewWindow2(LPDISPATCH* ppDisp, BOOL* Cancel);
   void OnProgressChange(long lProgress, long lProgressMax);
   void OnStatusTextChange(LPCTSTR lpszText);
   void OnTitleChange(LPCTSTR lpszText);
   void OnQuit();

	// Generated message map functions
	//{{AFX_MSG(CIEEvents)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

   // Dispatch map declaration for Internet Explorer events.
   DECLARE_DISPATCH_MAP()

   // Interface Map declaration
   DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IEEVENTS_H__66425985_9D94_11D1_ABEE_00D049C10000__INCLUDED_)
