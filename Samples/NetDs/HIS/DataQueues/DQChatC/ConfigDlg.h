#if !defined(AFX_CONFIGDLG_H__F1E5326B_AE98_4141_A685_F698B7692EF5__INCLUDED_)
#define AFX_CONFIGDLG_H__F1E5326B_AE98_4141_A685_F698B7692EF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConfigDlg.h : header file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

/////////////////////////////////////////////////////////////////////////////
// CConfigDlg dialog

class CConfigDlg : public CDialog
{
// Construction
public:
	CConfigDlg(CWnd* pParent = NULL);   // standard constructor
public:
	CString GetUser() {return m_strUser;};
	CString GetPasswd() {return m_strPasswd;};
	CString GetQueue() {return m_strQueue;};
	CString GetRemoteLU() {return m_strRemoteLU;};
	CString GetScreen(){return m_strScreen;};
// Dialog Data
	//{{AFX_DATA(CConfigDlg)
	enum { IDD = IDD_CONFIGDIALOG };
	CString	m_strPasswd;
	CString	m_strQueue;
	CString	m_strRemoteLU;
	CString	m_strUser;
	CString	m_strScreen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConfigDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIGDLG_H__F1E5326B_AE98_4141_A685_F698B7692EF5__INCLUDED_)
