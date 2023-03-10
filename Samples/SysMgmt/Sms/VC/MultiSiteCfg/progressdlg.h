#if !defined(AFX_PROGRESSDLG_H__F9819497_0318_11D3_8552_00105AA6844E__INCLUDED_)
#define AFX_PROGRESSDLG_H__F9819497_0318_11D3_8552_00105AA6844E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "configapp.h"
// ProgressDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog

class CProgressDlg : public CDialog, public CConfigApp::IProgressCallback
{
// Construction
public:
	void SetItemCount(int nItems);
	CProgressDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProgressDlg)
	enum { IDD = IDD_PROGRESS_DIALOG };
	CProgressCtrl	m_ProgressBar;
	CString	m_csSetting;
	CString	m_csSite;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressDlg)
	public:
	virtual BOOL Create(CWnd* pParentWnd);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProgressDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	bool TransferItemCompleted(const _bstr_t& sSite, const _bstr_t& sItemName, LPARAM lParam);
	bool TransferItemError(const _bstr_t& sSite, const _bstr_t& sItemName, LPARAM lParam);

private:
	int m_nTransferItems;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESSDLG_H__F9819497_0318_11D3_8552_00105AA6844E__INCLUDED_)
