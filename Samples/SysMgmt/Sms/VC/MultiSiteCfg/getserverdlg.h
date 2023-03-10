#if !defined(AFX_GETSERVERDLG_H__659736FF_0247_11D3_8551_00105AA6844E__INCLUDED_)
#define AFX_GETSERVERDLG_H__659736FF_0247_11D3_8551_00105AA6844E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GetServerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGetServerDlg dialog

class CGetServerDlg : public CDialog
{
// Construction
public:
	CGetServerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGetServerDlg)
	enum { IDD = IDD_GETSERVER_DIALOG };
	CString	m_csServer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGetServerDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETSERVERDLG_H__659736FF_0247_11D3_8551_00105AA6844E__INCLUDED_)
