// MultiSiteCfgDlg.h : header file
//

#if !defined(AFX_MULTISITECFGDLG_H__74962DD3_A69B_11D2_877A_00C04F96DE59__INCLUDED_)
#define AFX_MULTISITECFGDLG_H__74962DD3_A69B_11D2_877A_00C04F96DE59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiSiteCfgDlg dialog
class CConfigApp;

class CMultiSiteCfgDlg : public CDialog
{
// Construction
public:
	void UpdateButtons();
	CMultiSiteCfgDlg(CWnd* pParent = NULL);	// standard constructor
	void SetCfgAppOb(CConfigApp* pCfg) { m_pCfg=pCfg; }
	void SetNamespace(const CString& csNamespace) { m_csNamespace=csNamespace; }
	void SetServer(const CString& csServer) 
	{ 
		if (csServer.Left(2) == "\\\\")
			m_csServer = csServer.Mid(2);
		else
			m_csServer=csServer;
	}

// Dialog Data
	//{{AFX_DATA(CMultiSiteCfgDlg)
	enum { IDD = IDD_MULTISITECFG_DIALOG };
	CButton	m_btnExport;
	CStatic	m_stStatus;
	CStatic	m_stNamespace;
	CButton	m_btnDelSite;
	CButton	m_btnDelProp;
	CButton	m_btnAddSite;
	CButton	m_btnAddProp;
	CButton	m_btnOK;
	CListBox	m_lbTargetSites;
	CListBox	m_lbTargetProps;
	CListBox	m_lbAvailSites;
	CListBox	m_lbAvailProps;
	CComboBox	m_cbSourceSites;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiSiteCfgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CStringArray m_csarrSites;
	HICON m_hIcon;
	CConfigApp* m_pCfg;
	CString m_csNamespace;
	CString m_csServer;
	CString m_csSrcSite;


	// Generated message map functions
	//{{AFX_MSG(CMultiSiteCfgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtnAddSite();
	afx_msg void OnBtnDelProp();
	afx_msg void OnBtnDelSite();
	afx_msg void OnBtnAddProp();
	afx_msg void OnSelchangeCbSourceSites();
	afx_msg void OnDblclkLbAprops();
	afx_msg void OnDblclkLbAsites();
	afx_msg void OnDblclkLbTprops();
	afx_msg void OnDblclkLbTsites();
	afx_msg void OnBtnExport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTISITECFGDLG_H__74962DD3_A69B_11D2_877A_00C04F96DE59__INCLUDED_)
