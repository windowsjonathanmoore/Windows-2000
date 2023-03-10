// MultiSiteCfgDlg.cpp : implementation file
//
#define _USE_AUTOSYMBOLS  // must be defined before the include

#include "stdpch.h"
#include "MultiSiteCfg.h"
#include "MultiSiteCfgDlg.h"
#include "ProgressDlg.h"
#include "configapp.h"
#include "smsprov.h"
#include "cmdfile.h"


using namespace SMSSDK;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiSiteCfgDlg dialog

CMultiSiteCfgDlg::CMultiSiteCfgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiSiteCfgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiSiteCfgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pCfg = NULL;
}

void CMultiSiteCfgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiSiteCfgDlg)
	DDX_Control(pDX, IDC_BTN_EXPORT, m_btnExport);
	DDX_Control(pDX, IDC_TB_STATUS, m_stStatus);
	DDX_Control(pDX, IDC_TB_NAMESPACE, m_stNamespace);
	DDX_Control(pDX, IDC_BTN_DEL_SITE, m_btnDelSite);
	DDX_Control(pDX, IDC_BTN_DEL_PROP, m_btnDelProp);
	DDX_Control(pDX, IDC_BTN_ADD_SITE, m_btnAddSite);
	DDX_Control(pDX, IDC_BTN_ADD_PROP, m_btnAddProp);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDC_LB_TSITES, m_lbTargetSites);
	DDX_Control(pDX, IDC_LB_TPROPS, m_lbTargetProps);
	DDX_Control(pDX, IDC_LB_ASITES, m_lbAvailSites);
	DDX_Control(pDX, IDC_LB_APROPS, m_lbAvailProps);
	DDX_Control(pDX, IDC_CB_SOURCE_SITES, m_cbSourceSites);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiSiteCfgDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiSiteCfgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD_SITE, OnBtnAddSite)
	ON_BN_CLICKED(IDC_BTN_DEL_PROP, OnBtnDelProp)
	ON_BN_CLICKED(IDC_BTN_DEL_SITE, OnBtnDelSite)
	ON_BN_CLICKED(IDC_BTN_ADD_PROP, OnBtnAddProp)
	ON_CBN_SELCHANGE(IDC_CB_SOURCE_SITES, OnSelchangeCbSourceSites)
	ON_LBN_DBLCLK(IDC_LB_APROPS, OnDblclkLbAprops)
	ON_LBN_DBLCLK(IDC_LB_ASITES, OnDblclkLbAsites)
	ON_LBN_DBLCLK(IDC_LB_TPROPS, OnDblclkLbTprops)
	ON_LBN_DBLCLK(IDC_LB_TSITES, OnDblclkLbTsites)
	ON_BN_CLICKED(IDC_BTN_EXPORT, OnBtnExport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiSiteCfgDlg message handlers

BOOL CMultiSiteCfgDlg::OnInitDialog()
{
	CWaitCursor cws;
	int i;
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CString csStatus;
	SetWindowText(AfxGetAppName());
	csStatus.LoadString(IDS_CONNECTING);
	m_stStatus.SetWindowText(csStatus);
    
	if (m_csNamespace.IsEmpty())
	{
		try
		{
		    m_csServer.MakeUpper();
			m_csNamespace = (LPCTSTR)m_pCfg->GetProvNamespaceForServer(_bstr_t(m_csServer));
		}
		catch (CWbemException e)
		{
			CString csMsg;
			csMsg.LoadString(IDS_ERRCONNSERVER);
			AfxMessageBox(csMsg + m_csServer,MB_OK|MB_ICONSTOP);
			EnableWindow(FALSE);
			PostQuitMessage(0);
			return TRUE;
		}
	}
	else
	{
		m_csNamespace.MakeUpper();
		m_csServer = m_csNamespace.Mid(2,m_csNamespace.Mid(2).Find(_T('\\')));
	}


	try
	{
		m_pCfg->Connect(_bstr_t(m_csNamespace));
	}
	catch (CWbemException e)
	{
		CString csMsg;
		csMsg.LoadString(IDS_ERRCONNNAMESPACE);
		AfxMessageBox(csMsg + m_csNamespace,MB_OK|MB_ICONSTOP);
		EnableWindow(FALSE);
		PostQuitMessage(0);
		return TRUE;
	}
	
	m_stNamespace.SetWindowText(m_csNamespace);

	// TODO: need to check for permissions here

	csStatus.LoadString(IDS_CONNECTED);
	m_stStatus.SetWindowText(csStatus);

	// load list of available sites
	bstrVector vsSites;
	m_pCfg->GetSiteCodes(vsSites);


	if (vsSites.size()<2)
	{
		AfxMessageBox(IDS_ERRNOREADSITES,MB_OK|MB_ICONSTOP);
		OnCancel();
// warn, but proceed with no target sites available
//		return TRUE;
	}

	for (i=0; i < vsSites.size(); i++)
	{
		m_cbSourceSites.AddString(vsSites[i]);
	}

	vsSites.clear();
	m_pCfg->GetSiteCodes(vsSites,true); // check for modify rights

	if (vsSites.size()<1)
	{
		AfxMessageBox(IDS_ERRNOWRITESITES,MB_OK|MB_ICONSTOP);
		OnCancel();
// warn, but proceed "read only".
//		return TRUE;
	}

	for (i=0; i < vsSites.size(); i++)
	{
		m_csarrSites.Add(vsSites[i]);
	}

	int iUS = m_csNamespace.ReverseFind(_T('_'));
	m_cbSourceSites.SetCurSel(m_cbSourceSites.FindString(0,m_csNamespace.Mid(iUS+1)));


	OnSelchangeCbSourceSites();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMultiSiteCfgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMultiSiteCfgDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMultiSiteCfgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMultiSiteCfgDlg::OnOK() 
{
	CWaitCursor cws;
	CString csTemp;
	int cSites, cConfigs, i;
	bstrVector vsSites, vsConfigs;
	CString csOldStatus;
	CString csNewStatus;
	_bstr_t sTList;

	EnableWindow(FALSE);

	m_stStatus.GetWindowText(csOldStatus);
	csNewStatus.LoadString(IDS_TRANSFERING);
	m_stStatus.SetWindowText(csNewStatus);

	sTList = m_pCfg->GetSelectedSite() + L" --> "; // transfer list for logging

	cSites = m_lbTargetSites.GetCount();
	cConfigs = m_lbTargetProps.GetCount();

	for (i=0; i < cSites; i++)
	{
		m_lbTargetSites.GetText(i,csTemp);
		vsSites.push_back(_bstr_t(csTemp));

		if (i==0)
			sTList += _bstr_t(csTemp.Left(3));
		else
			sTList += L", " + _bstr_t(csTemp.Left(3));
	}

	for (i=0; i < cConfigs; i++)
	{
		m_lbTargetProps.GetText(i,csTemp);
		vsConfigs.push_back(_bstr_t(csTemp));
	}

	try
	{
		CProgressDlg dlgProgress;
   
		dlgProgress.SetItemCount(cConfigs*cSites);
		m_pCfg->SetProgressCallback(&dlgProgress);
		VERIFY(dlgProgress.Create(this));

		CString csMsg;

		csMsg.LoadString(IDS_STAT_CYCLE_BEGIN);
		m_pCfg->RaiseStatusMessage(_bstr_t(csMsg) + sTList,
			SMS_StatusMessage::MessageType::ENUM_Milestone,SMS_StatusMessage::Severity::ENUM_Informational);

		m_pCfg->TransferSettings(vsConfigs,vsSites);

		csMsg.LoadString(IDS_STAT_CYCLE_OK);
		m_pCfg->RaiseStatusMessage(_bstr_t(csMsg) + sTList,
			SMS_StatusMessage::MessageType::ENUM_Milestone,SMS_StatusMessage::Severity::ENUM_Informational);

		m_pCfg->SetProgressCallback(NULL);
		AfxMessageBox(IDS_COMPLETE,MB_OK|MB_ICONINFORMATION);
	}
	catch(CWbemException e)
	{
		CString csMsg,csMsg2;
		m_pCfg->SetProgressCallback(NULL);

		try
		{
		}
		catch(...)
		{
		}
		csMsg.LoadString(IDS_TRANSFERERROR);
		csMsg2.Format(csMsg, (LPCTSTR)e.GetDescription());
		AfxMessageBox(csMsg2,MB_OK|MB_ICONSTOP);
	}

	m_stStatus.SetWindowText(csOldStatus);

	EnableWindow(TRUE);
	SetFocus();
}

void CMultiSiteCfgDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CMultiSiteCfgDlg::OnBtnAddSite() 
{
	CString csItemText;
	int nItems;
	int iNewItem;
	
	nItems = m_lbAvailSites.GetCount();

	for (int i=nItems-1; i >= 0 ; i--)
	{
		if (m_lbAvailSites.GetSel(i))
		{
			m_lbAvailSites.GetText(i,csItemText);
			iNewItem = m_lbTargetSites.AddString(csItemText);
			m_lbTargetSites.SetSel(iNewItem);
			m_lbAvailSites.DeleteString(i);
		}
	}

	UpdateButtons();
}

void CMultiSiteCfgDlg::OnBtnDelProp() 
{
	CString csItemText;
	int nItems;
	int iNewItem;
	
	nItems = m_lbTargetProps.GetCount();

	for (int i=nItems-1; i >= 0 ; i--)
	{
		if (m_lbTargetProps.GetSel(i))
		{
			m_lbTargetProps.GetText(i,csItemText);
			iNewItem = m_lbAvailProps.AddString(csItemText);
			m_lbAvailProps.SetSel(iNewItem);
			m_lbTargetProps.DeleteString(i);
		}
	}

	UpdateButtons();
}

void CMultiSiteCfgDlg::OnBtnDelSite() 
{
	CString csItemText;
	int nItems;
	int iNewItem;
	
	nItems = m_lbTargetSites.GetCount();

	for (int i=nItems-1; i >= 0 ; i--)
	{
		if (m_lbTargetSites.GetSel(i))
		{
			m_lbTargetSites.GetText(i,csItemText);
			iNewItem = m_lbAvailSites.AddString(csItemText);
			m_lbAvailSites.SetSel(iNewItem);
			m_lbTargetSites.DeleteString(i);
		}
	}

	UpdateButtons();

}

void CMultiSiteCfgDlg::OnBtnAddProp() 
{
	CString csItemText;
	int nItems;
	int iNewItem;
	
	nItems = m_lbAvailProps.GetCount();

	for (int i=nItems-1; i >= 0 ; i--)
	{
		if (m_lbAvailProps.GetSel(i))
		{
			m_lbAvailProps.GetText(i,csItemText);

			iNewItem = m_lbTargetProps.AddString(csItemText);
			m_lbTargetProps.SetSel(iNewItem);
			m_lbAvailProps.DeleteString(i);
		}
	}

	UpdateButtons();

}

void CMultiSiteCfgDlg::OnSelchangeCbSourceSites() 
{
	CWaitCursor cws;
	CString csOldStatus;
	CString csNewStatus;
	int i;

	m_cbSourceSites.GetWindowText(m_csSrcSite);
	if (m_csSrcSite.IsEmpty())
		return;

	m_stStatus.GetWindowText(csOldStatus);
	csNewStatus.LoadString(IDS_REFRESHING);
	m_stStatus.SetWindowText(csNewStatus);

	m_lbAvailProps.ResetContent();
	m_lbTargetProps.ResetContent();
	m_lbAvailSites.ResetContent();
	m_lbTargetSites.ResetContent();

	// fill list with possible target sites	
	for (i=0; i < m_csarrSites.GetSize(); i++)
	{
		if (m_csarrSites[i]!=m_csSrcSite)
			m_lbAvailSites.AddString(m_csarrSites[i]);
	}

	// if we only have one, move it over to list of target sites
	if (m_lbAvailSites.GetCount()==1)
	{
		CString csItemText;
		m_lbAvailSites.GetText(0,csItemText);
		m_lbAvailSites.DeleteString(0);
		m_lbTargetSites.AddString(csItemText);
		m_lbTargetSites.SetSel(0);
	}

	// load list of avail congigurations
	bstrVector vsConfigs;

	m_pCfg->SetSiteAndGetAvailConfigs((LPCTSTR)m_csSrcSite,vsConfigs);


	for (i=0; i < vsConfigs.size(); i++)
	{
		m_lbAvailProps.AddString(vsConfigs[i]);
	}

	UpdateButtons();

	m_stStatus.SetWindowText(csOldStatus);

	if (vsConfigs.size()==0)
		AfxMessageBox(IDS_NOCONFIGS,MB_OK|MB_ICONSTOP);

}

void CMultiSiteCfgDlg::OnDblclkLbAprops() 
{
	CPoint  ptClick(GetMessagePos());
	BOOL    bOutside;
	UINT    iNewItem;
	CString  csItemText;

	m_lbAvailProps.ScreenToClient(&ptClick);
	UINT    iSel = m_lbAvailProps.ItemFromPoint(ptClick,bOutside);

	if (!bOutside)
	{
		m_lbAvailProps.GetText(iSel,csItemText);
		iNewItem = m_lbTargetProps.AddString(csItemText);
		m_lbTargetProps.SetSel(iNewItem);
		m_lbAvailProps.DeleteString(iSel);
	}

	UpdateButtons();

}

void CMultiSiteCfgDlg::OnDblclkLbAsites() 
{
	CPoint  ptClick(GetMessagePos());
	BOOL    bOutside;
	UINT    iNewItem;
	CString  csItemText;

	m_lbAvailSites.ScreenToClient(&ptClick);
	UINT    iSel = m_lbAvailSites.ItemFromPoint(ptClick,bOutside);

	if (!bOutside)
	{
		m_lbAvailSites.GetText(iSel,csItemText);
		iNewItem = m_lbTargetSites.AddString(csItemText);
		m_lbTargetSites.SetSel(iNewItem);
		m_lbAvailSites.DeleteString(iSel);
	}

	UpdateButtons();
}

void CMultiSiteCfgDlg::OnDblclkLbTprops() 
{
	CPoint  ptClick(GetMessagePos());
	BOOL    bOutside;
	UINT    iNewItem;
	CString  csItemText;

	m_lbTargetProps.ScreenToClient(&ptClick);
	UINT    iSel = m_lbTargetProps.ItemFromPoint(ptClick,bOutside);

	if (!bOutside)
	{
		m_lbTargetProps.GetText(iSel,csItemText);
		iNewItem = m_lbAvailProps.AddString(csItemText);
		m_lbAvailProps.SetSel(iNewItem);
		m_lbTargetProps.DeleteString(iSel);
	}
	
	UpdateButtons();
}

void CMultiSiteCfgDlg::OnDblclkLbTsites() 
{
	CPoint  ptClick(GetMessagePos());
	BOOL    bOutside;
	UINT    iNewItem;
	CString  csItemText;

	m_lbTargetSites.ScreenToClient(&ptClick);
	UINT    iSel = m_lbTargetSites.ItemFromPoint(ptClick,bOutside);

	if (!bOutside)
	{
		m_lbTargetSites.GetText(iSel,csItemText);
		iNewItem = m_lbAvailSites.AddString(csItemText);
		m_lbAvailSites.SetSel(iNewItem);
		m_lbTargetSites.DeleteString(iSel);
	}

	UpdateButtons();
}

void CMultiSiteCfgDlg::UpdateButtons()
{
	m_btnOK.EnableWindow(m_lbTargetProps.GetCount()>0 && m_lbTargetSites.GetCount()>0);
	m_btnAddSite.EnableWindow(m_lbAvailSites.GetCount()>0);
	m_btnDelSite.EnableWindow(m_lbTargetSites.GetCount()>0);
	m_btnAddProp.EnableWindow(m_lbAvailProps.GetCount()>0);
	m_btnDelProp.EnableWindow(m_lbTargetProps.GetCount()>0);
	m_btnExport.EnableWindow(m_lbTargetProps.GetCount()>0);

}

void CMultiSiteCfgDlg::OnBtnExport() 
{
   CFileDialog stddlgSaveFile(FALSE, _T(".cfg"), _T("Untitled"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
	   _T("CopySiteCfg Script Files (*.cfg)|*.cfg"), this);

   if (stddlgSaveFile.DoModal()==IDOK)
   {
		CCfgCmdFile cmdFile;	

		cmdFile.SetSiteServer(m_csServer);
		cmdFile.SetSourceSite(m_csSrcSite);

		int cSites = m_lbTargetSites.GetCount();
		int cConfigs = m_lbTargetProps.GetCount();
		CStringArray csaDstSites;
		CStringArray csaSettings;
		CString csTemp;

		for (int i=0; i < cSites; i++)
		{
			m_lbTargetSites.GetText(i,csTemp);
			csaDstSites.Add(csTemp);
		}

		for (i=0; i < cConfigs; i++)
		{
			m_lbTargetProps.GetText(i,csTemp);
			csaSettings.Add(csTemp);
		}

		cmdFile.SetDestSites(csaDstSites);
		cmdFile.SetSettings(csaSettings);
		cmdFile.SaveSetting(stddlgSaveFile.GetPathName());

   }
}
