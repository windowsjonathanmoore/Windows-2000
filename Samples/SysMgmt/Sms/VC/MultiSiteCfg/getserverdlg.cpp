// GetServerDlg.cpp : implementation file
//

#include "stdpch.h"
#include "MultiSiteCfg.h"
#include "GetServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetServerDlg dialog


CGetServerDlg::CGetServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetServerDlg)
	m_csServer = _T("");
	//}}AFX_DATA_INIT
}


void CGetServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetServerDlg)
	DDX_Text(pDX, IDC_EDIT_SERVER, m_csServer);
	//}}AFX_DATA_MAP
	DDV_MaxChars(pDX, m_csServer, MAX_COMPUTERNAME_LENGTH);

}


BEGIN_MESSAGE_MAP(CGetServerDlg, CDialog)
	//{{AFX_MSG_MAP(CGetServerDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetServerDlg message handlers

BOOL CGetServerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CWnd* pWnd = GetDlgItem(IDC_EDIT_SERVER);
	if (pWnd)
		pWnd->SetFocus();
	
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
