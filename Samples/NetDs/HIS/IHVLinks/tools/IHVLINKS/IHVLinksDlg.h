// IHVLinksDlg.h : header file
//

#if !defined(AFX_IHVLINKSDLG_H__FCCFA55F_27E1_4B10_9230_04277BC80B0B__INCLUDED_)
#define AFX_IHVLINKSDLG_H__FCCFA55F_27E1_4B10_9230_04277BC80B0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct IHVData
{
	TCHAR     szPackage[MAX_PATH];
	TCHAR     szManufacturer[MAX_PATH];
	TCHAR     szProductName[MAX_PATH];
	TCHAR     szProductDescription[MAX_PATH];
};

/////////////////////////////////////////////////////////////////////////////
// CIHVLinksDlg dialog

class CIHVLinksDlg : public CPropertyPageEx
{
// Construction
public:
	CIHVLinksDlg(UINT nIDD=IDD_WELCOME,UINT nIdHeaderTitle = 0, UINT nIdSubTitle = 0);	// standard constructor

	BOOL GetPackageInfo( IHVData* psIHVData );

	DWORD GetManufacturerItem( LPSTR pszManufacturer,
	                           HTREEITEM* htiManufacturer );

	TCHAR   szLaunchPath[MAX_PATH];

// Dialog Data
	//{{AFX_DATA(CIHVLinksDlg)
	enum { IDD = IDD_IHVLINKS_DIALOG };
	CTreeCtrl	m_ihvtree;
	CString	m_productdescription;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIHVLinksDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIHVLinksDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangedIhvTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickIhvTree(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IHVLINKSDLG_H__FCCFA55F_27E1_4B10_9230_04277BC80B0B__INCLUDED_)
