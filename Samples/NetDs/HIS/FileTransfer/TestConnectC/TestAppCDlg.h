// TestAppCDlg.h : header file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

//{{AFX_INCLUDES()
#include "eigfiletransferctl.h"
//}}AFX_INCLUDES

#if !defined(AFX_TESTAPPCDLG_H__3966992D_3785_4204_AFEF_619BCAB1FE22__INCLUDED_)
#define AFX_TESTAPPCDLG_H__3966992D_3785_4204_AFEF_619BCAB1FE22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestAppCDlg dialog

class CTestAppCDlg : public CDialog
{
private:
	bool	m_bConnected;
private:
	void InitUpload();
	bool Connect();
// Construction
public:
	CTestAppCDlg(CWnd* pParent = NULL);	// standard constructor
public:
	enum{APPC, TCPIP} m_ConnectionType;
	enum{OVERWRITE, APPEND, CREATE} m_UpOption;
// Dialog Data
	//{{AFX_DATA(CTestAppCDlg)
	enum { IDD = IDD_TESTAPPC_DIALOG };
	CButton	m_btnConnect;
	CEIGFileTransferCtl	m_ctlEIGFT;
	CString	m_strHostFile;
	CString	m_strLocalFile;
	CString	m_strLocalLU;
	CString	m_strMode;
	CString	m_strPasswd;
	CString	m_strRemoteLU;
	CString	m_strRDB;
	CString	m_strUser;
	CString	m_strStatus;
	CString	m_strSMode;
	CString	m_strSRemoteLU;
	CString	m_strSLocalLU;
	short	m_nCodePage;
	short	m_nCCSID;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestAppCDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestAppCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBrowse();
	afx_msg void OnConnect();
	afx_msg void OnDownload();
	afx_msg void OnUpload();
	afx_msg void OnAppc();
	afx_msg void OnTcpip();
	afx_msg void OnOverwrite();
	afx_msg void OnAppend();
	afx_msg void OnCreate();
	afx_msg void OnConnectionStateChangeEigfiletransferctl1(long constate);
	afx_msg void OnTransferProgressEigfiletransferctl1(short PercentageDone);
	afx_msg void OnReportErrorEigfiletransferctl1(long hr, LPCTSTR Text);
	afx_msg void OnTransferCompleteEigfiletransferctl1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTAPPCDLG_H__3966992D_3785_4204_AFEF_619BCAB1FE22__INCLUDED_)
