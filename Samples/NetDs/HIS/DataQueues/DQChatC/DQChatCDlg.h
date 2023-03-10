// DQChatCDlg.h : header file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

//{{AFX_INCLUDES()
#include "eigdataqueuectl.h"
//}}AFX_INCLUDES

#if !defined(AFX_DQCHATCDLG_H__6CD82558_E911_4511_825B_5DFB0B57DA43__INCLUDED_)
#define AFX_DQCHATCDLG_H__6CD82558_E911_4511_825B_5DFB0B57DA43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDQChatCDlg dialog

class CDQChatCDlg : public CDialog
{
// Construction
public:
	CDQChatCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDQChatCDlg)
	enum { IDD = IDD_CHAT };
	CMsgEdit	m_edSend;
	CListBox	m_lstReceive;
	CEIGDataQueueCtl	m_ctlDQ;
	CString	m_strUser;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDQChatCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
	bool m_bStart;
	HANDLE m_hEvtExit;
	CEIGDataQueue m_TheDQ ;
	bool m_bSetUser;
	
// Implementation
public:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDQChatCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnSetuser();
	virtual void OnCancel() ;
	afx_msg void OnConnectionStateChangeEigdataqueuectl1(long constate);
	afx_msg void OnReportErrorEigdataqueuectl1(long hr, LPCTSTR Text);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DQCHATCDLG_H__6CD82558_E911_4511_825B_5DFB0B57DA43__INCLUDED_)
