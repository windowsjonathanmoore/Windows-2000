// TestAppCDlg.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "TestAppC.h"

#include "MSEIGFT.tlh"

#include "TestAppCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace MSEIGFTLib;
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
// CTestAppCDlg dialog

CTestAppCDlg::CTestAppCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestAppCDlg::IDD, pParent)
{
	m_strLocalLU = _T("LOCAL");
	m_strMode = _T("QPCSUPP");
	m_nCodePage = 437;
	m_nCCSID = 37;

	//{{AFX_DATA_INIT(CTestAppCDlg)

	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bConnected = false;
}

void CTestAppCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestAppCDlg)
	DDX_Control(pDX, IDC_CONNECT, m_btnConnect);
	DDX_Control(pDX, IDC_EIGFILETRANSFERCTL1, m_ctlEIGFT);
	DDX_Text(pDX, IDC_HOSTFILENAME, m_strHostFile);
	DDX_Text(pDX, IDC_LOCALFILENAME, m_strLocalFile);
	DDX_Text(pDX, IDC_LOCALLU, m_strLocalLU);
	DDX_Text(pDX, IDC_MODE, m_strMode);
	DDX_Text(pDX, IDC_PASSWORD, m_strPasswd);
	DDX_Text(pDX, IDC_REMOTELU, m_strRemoteLU);
	DDX_Text(pDX, IDC_RDBNAME, m_strRDB);
	DDX_Text(pDX, IDC_USERID, m_strUser);
	DDX_Text(pDX, IDC_STATUS, m_strStatus);
	DDX_Text(pDX, IDC_SMODE, m_strSMode);
	DDX_Text(pDX, IDC_SREMOTELU, m_strSRemoteLU);
	DDX_Text(pDX, IDC_SLOCALLU, m_strSLocalLU);
	DDX_Text(pDX, IDC_LCPAGE, m_nCodePage);
	DDX_Text(pDX, IDC_HCCSID, m_nCCSID);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestAppCDlg, CDialog)
	//{{AFX_MSG_MAP(CTestAppCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
	ON_BN_CLICKED(IDC_UPLOAD, OnUpload)
	ON_BN_CLICKED(IDC_APPC, OnAppc)
	ON_BN_CLICKED(IDC_TCPIP, OnTcpip)
	ON_BN_CLICKED(IDC_OVERWRITE, OnOverwrite)
	ON_BN_CLICKED(IDC_APPEND, OnAppend)
	ON_BN_CLICKED(IDC_CREATE, OnCreate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestAppCDlg message handlers
//#define _MAINFRAME
BOOL CTestAppCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CoInitialize(NULL);
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
	

	UpdateData(FALSE);

	CWnd *pWnd = GetDlgItem(IDC_UPLOAD);
	pWnd->ShowWindow(FALSE);

	pWnd = GetDlgItem(IDC_DOWNLOAD);
	pWnd->ShowWindow(FALSE);

	m_ConnectionType = TCPIP;
	m_UpOption = APPEND;

	((CButton*)GetDlgItem(IDC_APPC))->SetCheck(1);

	OnAppc();

	((CButton*)GetDlgItem(IDC_APPEND))->SetCheck(1);

	OnAppend();

	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestAppCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestAppCDlg::OnPaint() 
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
HCURSOR CTestAppCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestAppCDlg::OnBrowse() 
{
	UpdateData(TRUE);
	CFileDialog dlg(TRUE);
	dlg.DoModal();
	m_strLocalFile = dlg.GetPathName();
	UpdateData(FALSE);
	
}

bool CTestAppCDlg::Connect()
{
	UpdateData(TRUE);
	if(APPC == m_ConnectionType)
	{
		m_ctlEIGFT.SetLocalLU(m_strLocalLU);
		m_ctlEIGFT.SetRemoteLU(m_strRemoteLU);
		m_ctlEIGFT.SetModeName(m_strMode);
	}
	else
	{
		m_ctlEIGFT.SetNetAddr(m_strLocalLU);
		m_ctlEIGFT.SetNetPort(m_strRemoteLU);
	}

	m_ctlEIGFT.SetRDBName(m_strRDB);
    m_ctlEIGFT.SetUserID(m_strUser);
    m_ctlEIGFT.SetPassword(m_strPasswd);
	m_ctlEIGFT.SetCcsid(m_nCCSID);
    m_ctlEIGFT.SetPCCodePage(m_nCodePage);

	try
	{
		m_ctlEIGFT.Connect();
	}
	catch(...)
	{
		AfxMessageBox("Exception");
		return false;
	}
	return true;
}


void CTestAppCDlg::OnConnect() 
{
	UpdateData(TRUE);

	CWnd *pWnd = GetDlgItem(IDC_UPLOAD);

	CString strTemp;
	if(!m_bConnected)
	{
		m_bConnected =	Connect();
	}
	else
	{
		try
		{
			m_ctlEIGFT.Disconnect();
		}
		catch(...)
		{
			AfxMessageBox("Exception in Close");
		}
		m_bConnected = false;
	}
	
	strTemp.LoadString(m_bConnected?IDS_DISCONNECT:IDS_CONNECT);
	m_btnConnect.SetWindowText(strTemp);
	m_btnConnect.EnableWindow(TRUE);
	
	BOOL bShow = m_bConnected?TRUE:FALSE;

	pWnd->ShowWindow(bShow);
	pWnd = GetDlgItem(IDC_DOWNLOAD);
	pWnd->ShowWindow(bShow);

}

void CTestAppCDlg::OnDownload() 
{
	UpdateData(TRUE);
	CFileFind fp;
	if (fp.FindFile(m_strLocalFile))
	{
		if(IDYES != AfxMessageBox("OverWrite File ?",MB_YESNO))
		{
			return;
		}
	}

	m_ctlEIGFT.GetFile(m_strLocalFile, m_strHostFile);
}

void CTestAppCDlg::OnUpload() 
{
	UpdateData(TRUE);

	m_ctlEIGFT.PutFile(m_strHostFile, m_strLocalFile);	
}

void CTestAppCDlg::OnAppc() 
{
	UpdateData(TRUE);
	if(m_bConnected)
	{
		if(APPC == m_ConnectionType)
		{
			return;
		}
		CButton *pButton = (CButton*)GetDlgItem(IDC_TCPIP);
		pButton->SetCheck(1);

		pButton = (CButton*)GetDlgItem(IDC_APPC);
		pButton->SetCheck(0);

		m_strStatus = "Disconnect and try again";
		UpdateData(FALSE);	
		return;
	}

	m_ConnectionType	= APPC;
	m_ctlEIGFT.SetConnectionType(eigConnTypeAPPC);
	CWnd *pWnd = GetDlgItem(IDC_MODE);
	pWnd->ShowWindow(SW_SHOW);
	pWnd = GetDlgItem(IDC_SMODE);
	pWnd->ShowWindow(SW_SHOW);
	m_strSMode.LoadString(IDS_MODE);
	m_strSLocalLU.LoadString(IDS_LOCALLU);
	m_strSRemoteLU.LoadString(IDS_REMOTELU);
	UpdateData(FALSE);

}

void CTestAppCDlg::OnTcpip() 
{
	UpdateData(TRUE);
	if(m_bConnected)
	{
		if(TCPIP == m_ConnectionType)
		{
			return;
		}
		CButton *pButton = (CButton*)GetDlgItem(IDC_TCPIP);
		pButton->SetCheck(0);

		pButton = (CButton*)GetDlgItem(IDC_APPC);
		pButton->SetCheck(1);

		m_strStatus = "Disconnect and try again";
		UpdateData(FALSE);	
		return;
	}

	m_ConnectionType = TCPIP;
	m_ctlEIGFT.SetConnectionType(eigConnTypeTCPIP);
	CWnd *pWnd = GetDlgItem(IDC_MODE);
	pWnd->ShowWindow(SW_HIDE);
	pWnd = GetDlgItem(IDC_SMODE);
	pWnd->ShowWindow(SW_HIDE);
	m_strSLocalLU.LoadString(IDS_NETWORK);
	m_strSRemoteLU.LoadString(IDS_PORT);
	UpdateData(FALSE);

}

void CTestAppCDlg::OnOverwrite() 
{
	m_UpOption = OVERWRITE;
	InitUpload();
	m_ctlEIGFT.SetOverwriteHostFile(eigAnswerYes);
}

void CTestAppCDlg::OnAppend() 
{
	m_UpOption = APPEND;
	InitUpload();
	m_ctlEIGFT.SetAppendToEnd(eigAnswerYes);

}


void CTestAppCDlg::OnCreate() 
{
	m_UpOption = CREATE;
	InitUpload();
	m_ctlEIGFT.SetCreateIfNonExisting(eigAnswerYes);
}

void CTestAppCDlg::InitUpload()
{
	m_ctlEIGFT.SetCreateIfNonExisting(eigAnswerNo);
	m_ctlEIGFT.SetAppendToEnd(eigAnswerNo);
	m_ctlEIGFT.SetOverwriteHostFile(eigAnswerNo);
}

BOOL CTestAppCDlg::DestroyWindow() 
{
	CoUninitialize();	
	return CDialog::DestroyWindow();
}

BEGIN_EVENTSINK_MAP(CTestAppCDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CTestAppCDlg)
	ON_EVENT(CTestAppCDlg, IDC_EIGFILETRANSFERCTL1, 1 /* ConnectionStateChange */, OnConnectionStateChangeEigfiletransferctl1, VTS_I4)
	ON_EVENT(CTestAppCDlg, IDC_EIGFILETRANSFERCTL1, 2 /* TransferProgress */, OnTransferProgressEigfiletransferctl1, VTS_I2)
	ON_EVENT(CTestAppCDlg, IDC_EIGFILETRANSFERCTL1, 3 /* ReportError */, OnReportErrorEigfiletransferctl1, VTS_I4 VTS_BSTR)
	ON_EVENT(CTestAppCDlg, IDC_EIGFILETRANSFERCTL1, 4 /* TransferComplete */, OnTransferCompleteEigfiletransferctl1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CTestAppCDlg::OnConnectionStateChangeEigfiletransferctl1(long constate) 
{
	m_strStatus = ((constate == eigConnStateConnected) ?"Disconnect":"Connect");

	CString strTemp;
	strTemp.LoadString(IDS_WAIT);
	m_btnConnect.SetWindowText(strTemp);
	m_btnConnect.EnableWindow(FALSE);
	CWnd *pWnd = GetDlgItem(IDC_STATUS);
	pWnd->SetWindowText(m_strStatus);
	

}

void CTestAppCDlg::OnTransferProgressEigfiletransferctl1(short PercentageDone) 
{
	
	m_strStatus.Format("%d",PercentageDone);
	m_strStatus += " % done";
	CWnd *pWnd = GetDlgItem(IDC_STATUS);
	pWnd->SetWindowText(m_strStatus);
}

void CTestAppCDlg::OnReportErrorEigfiletransferctl1(long hr, LPCTSTR Text) 
{
	m_strStatus.Format("Error (%u)", hr);
	m_strStatus += " ";
	m_strStatus += Text;
	CWnd *pWnd = GetDlgItem(IDC_STATUS);
	pWnd->SetWindowText(m_strStatus);

}

void CTestAppCDlg::OnTransferCompleteEigfiletransferctl1() 
{
	m_strStatus = "File Transfer Complete";
	CWnd *pWnd = GetDlgItem(IDC_STATUS);
	pWnd->SetWindowText(m_strStatus);
}
