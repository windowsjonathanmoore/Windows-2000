// ProgressDlg.cpp : implementation file
//

#include "stdpch.h"
#include "MultiSiteCfg.h"
#include "ProgressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog


CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgressDlg)
	m_csSetting = _T("");
	m_csSite = _T("");
	//}}AFX_DATA_INIT
}


void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgressDlg)
	DDX_Control(pDX, IDC_PROGRESS, m_ProgressBar);
	DDX_Text(pDX, IDC_STATIC_SETTING, m_csSetting);
	DDX_Text(pDX, IDC_STATIC_SITE, m_csSite);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialog)
	//{{AFX_MSG_MAP(CProgressDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg message handlers

BOOL CProgressDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ProgressBar.SetStep(1);
	m_ProgressBar.SetRange(0,m_nTransferItems);
	m_ProgressBar.SetPos(0);
	
	return TRUE;  
}

bool CProgressDlg::TransferItemCompleted(const _bstr_t& sSite, const _bstr_t& sItemName, LPARAM lParam)
{
	m_csSetting = (LPCTSTR)sItemName;
	m_csSite = (LPCTSTR)sSite;
	TRACE("Transfered setting " + m_csSetting + " to site " + m_csSite);
	UpdateData(FALSE);
	m_ProgressBar.StepIt();
	return true;
}

bool CProgressDlg::TransferItemError(const _bstr_t& sSite, const _bstr_t& sItemName, LPARAM lParam)
{
	CString csMsg1,csMsg2;

	csMsg1.LoadString(IDS_TRANSFERERRORCONTINUE);
	csMsg2.Format(csMsg1,(LPCTSTR)sItemName,(LPCTSTR)sSite);
	TRACE(csMsg2);
	if (MessageBox(csMsg2,NULL,MB_ICONSTOP|MB_YESNO) == IDYES)
		return true;
	else
		return false;

}

void CProgressDlg::SetItemCount(int nItems)
{
	m_nTransferItems = nItems;
}

BOOL CProgressDlg::Create(CWnd* pParentWnd) 
{
	
	return CDialog::Create(CProgressDlg::IDD, pParentWnd);
}
