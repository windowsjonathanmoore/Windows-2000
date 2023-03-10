
//=--------------------------------------------------------------------------=
//  (C) Copyright 1996 - 2000 Microsoft Corporation. All Rights Reserved.
//=--------------------------------------------------------------------------=
// drillerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDrillerDlg dialog

class CDrillerDlg : public CDialog
{
// Construction
public:
	CDrillerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDrillerDlg)
	enum { IDD = IDD_DRILLER_DIALOG };
	CListBox	m_listTags;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrillerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDrillerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnGo();
	afx_msg void OnBtnDrill();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};
