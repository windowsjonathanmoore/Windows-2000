// IHVUtilDlg.h : header file
//

#if !defined(AFX_IHVUTILDLG_H__ED6B5F18_3BBB_479D_AEA9_006227FD3722__INCLUDED_)
#define AFX_IHVUTILDLG_H__ED6B5F18_3BBB_479D_AEA9_006227FD3722__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIHVUtilDlg dialog

class CIHVUtilDlg : public CDialog
{
// Construction
public:
	CIHVUtilDlg(CWnd* pParent = NULL);	// standard constructor

	void EnumerateIHVLinks(void);
	void FreeAllCStrings(void);

// Dialog Data
	//{{AFX_DATA(CIHVUtilDlg)
	enum { IDD = IDD_IHVUTIL_DIALOG };
	CTreeCtrl	m_ihvtree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIHVUtilDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIHVUtilDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDisplay();
	afx_msg void OnRemove();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IHVUTILDLG_H__ED6B5F18_3BBB_479D_AEA9_006227FD3722__INCLUDED_)
