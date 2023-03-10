// DQChatCDlg.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "eigdataqueue.h"
#include "eigdataqueuectl.h"
#include "eigdataqueueitemW.h"
#include "MsgEdit.h"
#include <afxpriv.h>
#include<time.h>
#include "DQChatC.h"
#include "DQChatCDlg.h"
#include "ConfigDlg.h"

#include "MSEIGDQ.tlh"

using namespace DATAQUEUELib;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString GetTime();
const int MAXNAME = 255;
void GetMsgTimeUser(CString &strMsg, CString &strTime, CString &strUser);
bool IsOld(CString strTime);
bool IsDuplicate(CListBox *pLB, CString str);
UINT ListenThread(LPVOID pVoid);

CEIGDataQueue *g_TheDQ ;
CEIGDataQueue *TheDQ ;
bool g_bStart = false;
HANDLE g_hEvtPut;
HANDLE g_hEvtGet;
const int g_maxsize = 1024;

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
// CDQChatCDlg dialog

CDQChatCDlg::CDQChatCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDQChatCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDQChatCDlg)
	m_strUser = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDQChatCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDQChatCDlg)
	DDX_Control(pDX, IDC_SENDMSG, m_edSend);
	DDX_Control(pDX, IDC_RECEIVE, m_lstReceive);
	DDX_Control(pDX, IDC_EIGDATAQUEUECTL1, m_ctlDQ);
	DDX_Text(pDX, IDC_USER, m_strUser);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDQChatCDlg, CDialog)
	//{{AFX_MSG_MAP(CDQChatCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_BN_CLICKED(IDC_SETUSER, OnSetuser)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDQChatCDlg message handlers

BOOL CDQChatCDlg::OnInitDialog()
{
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
	
	// TODO: Add extra initialization here
	m_bStart = false;
	m_bSetUser = false;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDQChatCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDQChatCDlg::OnPaint() 
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
HCURSOR CDQChatCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


unsigned char EToATable[256] = {

/*  ASCII                       EBCDIC                  */

    0x00,   /*  space           0x00                    */
    0x01,   /*  soh             0x01                    */
    0x02,   /*  stx             0x02                    */
    0x03,   /*  etx             0x03                    */
    0x20,   /*  eot             0x04                    */
    0x09,   /*  enq             0x05                    */
    0x20,   /*  ack             0x06                    */
    0x7F,   /*  bel             0x07                    */
    0x20,   /*  bs              0x08                    */
    0x20,   /*  ht              0x09                    */
    0x20,   /*  lf              0x0A                    */
    0x0B,   /*  vt              0x0B                    */
    0x0C,   /*  ff              0x0C                    */
    0x0D,   /*  cr              0x0D                    */
    0x0E,   /*  so              0x0E                    */
    0x0F,   /*  si              0x0F                    */

    0x10,   /*  dle             0x10                    */
    0x11,   /*  dc1             0x11                    */
    0x12,   /*  dc2             0x12                    */
    0x13,   /*  dc3             0x13                    */
    0x20,   /*  dc4             0x14                    */
    0x20,   /*  nak             0x15                    */
    0x08,   /*  syn             0x16                    */
    0x20,   /*  etb             0x17                    */
    0x18,   /*  can             0x18                    */
    0x19,   /*  em              0x19                    */
    0x20,   /*  sub             0x1A                    */
    0x20,   /*  esc             0x1B                    */
    0x20,   /*  si              0x1C    overscore *     */
    0x1D,   /*  gs              0x1D                    */
    0x20,   /*  rs              0x1E                    */
    0x1F,   /*                  0x1F                    */

    0x20,   /*                  0x20                    */
    0x20,   /*                  0x21                    */
    0x1C,   /*                  0x22                    */
    0x20,   /*                  0x23                    */
    0x20,   /*                  0x24                    */
    0x0A,   /*                  0x25                    */
    0x17,   /*                  0x26                    */
    0x1B,   /*                  0x27                    */
    0x20,   /*                  0x28                    */
    0x20,   /*                  0x29                    */
    0x20,   /*                  0x2A                    */
    0x20,   /*                  0x2B                    */
    0x20,   /*                  0x2C                    */
    0x05,   /*                  0x2D                    */
    0x06,   /*                  0x2E                    */
    0x07,   /*                  0x2F                    */

    0x20,   /*                  0x30                    */
    0x20,   /*                  0x31                    */
    0x16,   /*                  0x32                    */
    0x20,   /*                  0x33                    */
    0x20,   /*                  0x34                    */
    0x1E,   /*                  0x35                    */
    0x20,   /*                  0x36                    */
    0x04,   /*                  0x37                    */
    0x20,   /*                  0x38                    */
    0x20,   /*                  0x39                    */
    0x20,   /*                  0x3A                    */
    0x20,   /*                  0x3B                    */
    0x14,   /*                  0x3C                    */
    0x15,   /*                  0x3D                    */
    0x20,   /*                  0x3E                    */
    0x1A,   /*                  0x3F                    */

    0x20,   /*  space           0x40    space           */
    0x20,   /*  space           0x41    required space  */
    0xE2,   /*  ^a              0x42    ^a              */
    0xE4,   /*  :a              0x43    :a              */
    0xE0,   /*  `a              0x44    `a              */
    0xE1,   /*  'a              0x45    'a              */
    0xE3,   /*  a_              0x46    a_              */
    0xE5,   /*  oa              0x47    oa              */
    0xE7,   /*  c,              0x48    c,              */
    0xF1,   /*  ~n              0x49    ~n              */
    0xA2,   /*  cent            0x4A    cent            */
    0x2E,   /*  .               0x4B    .               */
    0x3C,   /*  <               0x4C    <               */
    0x28,   /*  (               0x4D    (               */
    0x2B,   /*  +               0x4E    +               */
    0x7C,   /*  bar             0x4F    bar             */

    0x26,   /*  &               0x50    &               */
    0xE9,   /*  'e              0x51    'e              */
    0xEA,   /*  ^e              0x52    ^e              */
    0xEB,   /*  :e              0x53    :e              */
    0xE8,   /*  `e              0x54    `e              */
    0xED,   /*  'i              0x55    'i              */
    0xEE,   /*  ^i              0x56    ^i              */
    0xEF,   /*  :i              0x57    :i              */
    0xEC,   /*  `i              0x58    `i              */
    0xDF,   /*  beta            0x59    beta            */
    0x21,   /*  !               0x5A    !               */
    0x24,   /*  $               0x5B    $               */
    0x2A,   /*  *               0x5C    *               */
    0x29,   /*  )               0x5D    )               */
    0x3B,   /*  ;               0x5E    ;               */
    0x5E,   /*  -|              0x5F    -|              */

    0x2D,   /*  -               0x60    -               */
    0x2F,   /*  /               0x61    /               */
    0xC2,   /*  ^a              0x62    ^A              */
    0xC4,   /*  :A              0x63    :A              */
    0xC0,   /*  `a              0x64    `A              */
    0xC1,   /*  'a              0x65    'A              */
    0xC3,   /*  a_              0x66    ~A              */
    0xC5,   /*  oA              0x67    oA              */
    0xC7,   /*  C,              0x68    C,              */
    0xD1,   /*  ~N              0x69    ~N              */
    0x7C,   /*  |               0x6A    |               */
    0x2C,   /*  ,               0x6B    ,               */
    0x25,   /*  %               0x6C    %               */
    0x5F,   /*  _               0x6D    _               */
    0x3E,   /*  >               0x6E    >               */
    0x3F,   /*  ?               0x6F    ?               */

    0xF8,   /*  0/              0x70    0/              */
    0xC9,   /*  'E              0x71    'E              */
    0xCA,   /*  ^e              0x72    ^E              */
    0xCB,   /*  :e              0x73    :E              */
    0xC8,   /*  `e              0x74    `E              */
    0xCD,   /*  'i              0x75    'I              */
    0xCE,   /*  ^i              0x76    ^I              */
    0xCF,   /*  :i              0x77    :I              */
    0xF6,   /*  `i              0x78    `I              */
    0x60,   /*  `               0x79    '               */
    0x3A,   /*  :               0x7A    :               */
    0x23,   /*  #               0x7B    #               */
    0x40,   /*  @               0x7C    @               */
    0x27,   /*  '               0x7D    '               */
    0x3D,   /*  =               0x7E    =               */
    0x22,   /*  "               0x7F    "               */

    0xD8,   /*  0/              0x80    large 0/        */
    0x61,   /*  a               0x81    a               */
    0x62,   /*  b               0x82    b               */
    0x63,   /*  c               0x83    c               */
    0x64,   /*  d               0x84    d               */
    0x65,   /*  e               0x85    e               */
    0x66,   /*  f               0x86    f               */
    0x67,   /*  g               0x87    g               */
    0x68,   /*  h               0x88    h               */
    0x69,   /*  i               0x89    i               */
    0xAB,   /*  <<              0x8A    <<              */
    0xBB,   /*  >>              0x8B    >>              */
    0xF0,   /*  delta           0x8C    delta           */
    0xFD,   /*                  0x8D    c_              */
    0xDE,   /*  block           0x8E                    */
    0xB1,   /*  +-              0x8F    +-              */

    0xB0,   /*  degree          0x90    degree          */
    0x6A,   /*  j               0x91    j               */
    0x6B,   /*  k               0x92    k               */
    0x6C,   /*  l               0x93    l               */
    0x6D,   /*  m               0x94    m               */
    0x6E,   /*  n               0x95    n               */
    0x6F,   /*  o               0x96    o               */
    0x70,   /*  p               0x97    p               */
    0x71,   /*  q               0x98    q               */
    0x72,   /*  r               0x99    r               */
    0xAA,   /*                  0x9A                    */
    0xBA,   /*                  0x9B                    */
    0xE6,   /*                  0x9C                    */
    0xB8,   /*                  0x9D                    */
    0xC6,   /*                  0x9E                    */
    0xA4,   /*                  0x9F                    */

    0xB5,   /*                  0xA0                    */
    0x7E,   /*                  0xA1                    */
    0x73,   /*  s               0xA2    s               */
    0x74,   /*  t               0xA3    t               */
    0x75,   /*  u               0xA4    u               */
    0x76,   /*  v               0xA5    v               */
    0x77,   /*  w               0xA6    w               */
    0x78,   /*  x               0xA7    x               */
    0x79,   /*  y               0xA8    y               */
    0x7A,   /*  z               0xA9    z               */
    0xA1,   /*                  0xAA                    */
    0xBF,   /*                  0xAB                    */
    0xD0,   /*                  0xAC                    */
    0x5B,   /*                  0xAD                    */
    0xFE,   /*                  0xAE                    */
    0xAE,   /*                  0xAF                    */

    0x5E,   /*                  0xB0                    */
    0xA3,   /*                  0xB1                    */
    0xA5,   /*                  0xB2                    */
    0x20,   /*                  0xB3                    */
    0x20,   /*                  0xB4                    */
    0xA7,   /*                  0xB5                    */
    0xB6,   /*                  0xB6                    */
    0xBC,   /*                  0xB7                    */
    0xBD,   /*                  0xB8                    */
    0xBE,   /*                  0xB9                    */
    0x5B,   /*                  0xBA                    */
    0x5D,   /*                  0xBB                    */
    0xAF,   /*                  0xBC                    */
    0x5D,   /*                  0xBD                    */
    0x27,   /*                  0xBE                    */
    0x3D,   /*                  0xBF                    */

    0x7B,   /*                  0xC0    {               */
    0x41,   /*  A               0xC1    A               */
    0x42,   /*  B               0xC2    B               */
    0x43,   /*  C               0xC3    C               */
    0x44,   /*  D               0xC4    D               */
    0x45,   /*  E               0xC5    E               */
    0x46,   /*  F               0xC6    F               */
    0x47,   /*  G               0xC7    G               */
    0x48,   /*  H               0xC8    H               */
    0x49,   /*  I               0xC9    I               */
    0x2D,   /*                  0xCA                    */
    0xF4,   /*                  0xCB                    */
    0xF6,   /*                  0xCC                    */
    0xF2,   /*                  0xCD                    */
    0xF3,   /*                  0xCE                    */
    0xF5,   /*                  0xCF                    */

    0x7D,   /*  }               0xD0    }               */
    0x4A,   /*  J               0xD1    J               */
    0x4B,   /*  K               0xD2    K               */
    0x4C,   /*  L               0xD3    L               */
    0x4D,   /*  M               0xD4    M               */
    0x4E,   /*  N               0xD5    N               */
    0x4F,   /*  O               0xD6    O               */
    0x50,   /*  P               0xD7    P               */
    0x51,   /*  Q               0xD8    Q               */
    0x52,   /*  R               0xD9    R               */
    0xA6,   /*                  0xDA                    */
    0xFB,   /*                  0xDB                    */
    0xFC,   /*                  0xDC                    */
    0xF9,   /*                  0xDD                    */
    0xFA,   /*                  0xDE                    */
    0xFF,   /*                  0xDF                    */

    0x5C,   /*                  0xE0                    */
    0x20,   /*                  0xE1                    */
    0x53,   /*  S               0xE2    S               */
    0x54,   /*  T               0xE3    T               */
    0x55,   /*  U               0xE4    U               */
    0x56,   /*  V               0xE5    V               */
    0x57,   /*  W               0xE6    W               */
    0x58,   /*  X               0xE7    X               */
    0x59,   /*  Y               0xE8    Y               */
    0x5A,   /*  Z               0xE9    Z               */
    0xB2,   /*                  0xEA                    */
    0xD4,   /*                  0xEB                    */
    0xD6,   /*                  0xEC                    */
    0xD2,   /*                  0xED                    */
    0xD3,   /*                  0xEE                    */
    0xD5,   /*                  0xEF                    */

    0x30,   /*  0               0xF0    0               */
    0x31,   /*  1               0xF1    1               */
    0x32,   /*  2               0xF2    2               */
    0x33,   /*  3               0xF3    3               */
    0x34,   /*  4               0xF4    4               */
    0x35,   /*  5               0xF5    5               */
    0x36,   /*  6               0xF6    6               */
    0x37,   /*  7               0xF7    7               */
    0x38,   /*  8               0xF8    8               */
    0x39,   /*  9               0xF9    9               */
    0xB3,   /*                  0xFA                    */
    0xDB,   /*                  0xFB                    */
    0xDC,   /*                  0xFC                    */
    0xD9,   /*                  0xFD                    */
    0xDA,   /*                  0xFE                    */
    0x20    /*  space           0xFF                    */
};

void CConvert( UCHAR *source, UCHAR *target, unsigned int len)
{
	unsigned int i;

	for( i= 0; i < len ; i++ ) *target++=EToATable[*source++];
	return;
}


void CDQChatCDlg::OnSend() 
{
	UpdateData(TRUE);
	if(!m_bSetUser)
	{
		AfxMessageBox("Please Set User");
		return;
	}
	COleVariant vtSend;
	CString strData;
	m_edSend.GetWindowText(strData);
	if(g_maxsize < strData.GetLength())
	{
		return;
	}
	m_edSend.SetWindowText("");
	CString strSend = m_strUser;
	strSend += "+";
	strSend += GetTime();
	strSend += "+";
	strSend += strData;
	vtSend = strSend;
	COleVariant vtNothing;
	CEIGDataQueueItemW Item ;
	Item.CreateDispatch("DataQueue.EIGDataQueueItem.1");
	Item.SetRecord(vtSend);
	g_TheDQ->AddQueueItem(Item, eigAnswerYes);
		
}

void CDQChatCDlg::OnSetuser() 
{
	UpdateData(TRUE);
	CConfigDlg dlg;
	if(IDOK != dlg.DoModal())
	{
		return;
	}

	m_strUser = dlg.GetScreen();
	CString strTemp = dlg.GetUser();
	m_ctlDQ.SetUserID(strTemp);
	strTemp = dlg.GetPasswd();
	m_ctlDQ.SetPassword(strTemp);
	strTemp = dlg.GetQueue();

	CString strQueue = strTemp;
	strTemp = dlg.GetRemoteLU();
	m_ctlDQ.SetRemoteLU(strTemp);

	if(m_strUser.IsEmpty())
	{
		AfxMessageBox("Invalid User");
		return;
	}
	
	m_ctlDQ.Connect();

	m_TheDQ = m_ctlDQ.CreateQueueContainer(strQueue);
	g_TheDQ= &m_TheDQ;	

	g_TheDQ->CreateQueue(255, eigQAuthAll, eigQClassFIFO, eigAnswerYes, m_ctlDQ.GetCcsid(), 0, FALSE, eigRecordLenFixed, "DQChat", eigAnswerNo, 0);

	VARIANT variant = g_TheDQ->QueryAttribute(eigAttributeMaxMsgLen );

	// See if the queue was really created using the record length I asked for.
	if (variant.vt != VT_I4 || variant.uintVal != 255 )
	{
		AfxMessageBox("Queue Creation Problem");
		return;
	}

	m_hEvtExit = ::CreateEvent(NULL, TRUE, FALSE, NULL);
	m_bStart = true;

	m_bSetUser = true;
	CWnd *pWnd = GetDlgItem(IDC_USER);
	pWnd->EnableWindow(FALSE);
	pWnd = GetDlgItem(IDC_SETUSER);
	pWnd->EnableWindow(FALSE);
	UpdateData(FALSE);
	AfxBeginThread(ListenThread,this);
}

void CDQChatCDlg::OnCancel() 
{
	if(!m_bStart)
	{
		CDialog::OnCancel();
		return;
	}
	m_bStart = false;
	m_bSetUser = true;
	m_edSend.SetWindowText("Good Bye");
	OnSend();
	::WaitForSingleObject(m_hEvtExit, INFINITE);

	int nCount = m_lstReceive.GetCount();
	for(int i =0; i < nCount; i++)
	{
		CString *pstr = (CString*)m_lstReceive.GetItemDataPtr(i);
		delete pstr;
	}

	CDialog::OnCancel();
}

CString GetTime()
{
	time_t osBinaryTime;  // C run-time time (defined in <time.h>)
	time( &osBinaryTime );
	CString strTemp;
	strTemp.Format("%u",osBinaryTime);
	return strTemp;
}


void GetMsgTimeUser(CString &strMsg, CString &strTime, CString& strUser)
{
	strUser= strMsg.Mid(0, strMsg.Find("+"));
	strMsg = strMsg.Mid(strMsg.Find("+") + 1);
	strTime = strMsg.Mid(0, strMsg.Find("+"));
	strMsg = strMsg.Mid(strMsg.Find("+")+1);
	strMsg = strUser + ":" +strMsg;
	
}

bool IsOld(CString strTime)
{
	DWORD dwOldTime = _ttol(strTime);
	long lCurrent;
	time( &lCurrent);
	CTime OldTime(dwOldTime);
	CTime CurrentTime(lCurrent);
 	if(lCurrent - dwOldTime > 10)
	{
		return true;
	}

	return false;
}

bool IsDuplicate(CListBox *pLB, CString str)
{
	int nCount = pLB->GetCount();
	for(int i =0; i < nCount; i++)
	{
		CString *pstr = (CString*)(pLB->GetItemDataPtr(i));
		if(*pstr == str)
		{
			return true;
		}
	}
	return false;
}



UINT ListenThread(LPVOID pVoid)
{

	CDQChatCDlg *pDlg = reinterpret_cast<CDQChatCDlg*>(pVoid);
	while(true)
	{
		
		COleVariant vtNothing;
		CEIGDataQueueItemW Item = g_TheDQ->GetQueueItem(eigQItem, eigAnswerYes, eigAnswerNo/*eigAnswerYes*/,eigAnswerYes, INFINITE, eigAnswerNo/*Yes*/, eigAnswerNo/*Yes*/, vtNothing, eigSearchKeyEqual);
		
		if(!pDlg->m_bStart)
		{

			g_TheDQ->GetQueueItem(eigQItem, eigAnswerYes, eigAnswerNo,eigAnswerYes, 2, eigAnswerYes, eigAnswerYes, vtNothing, eigSearchKeyEqual);	
			SetEvent(pDlg->m_hEvtExit);
			return 0;
		}
		
		size_t nSize = Item.GetRecLength();
		if(nSize > g_maxsize)
		{
			continue;
		}
		BYTE *szData = new BYTE[nSize + 1];
		BYTE *lpRecord = new BYTE[nSize + 1];
		memset(szData,0,nSize + 1);
		COleVariant vt = Item.GetRecord();
		SAFEARRAY	*abrecord = vt.parray;
		void HUGEP *pData;
		SafeArrayAccessData(abrecord,&pData);
		memcpy(lpRecord, (UCHAR*)pData,nSize);
		SafeArrayUnaccessData(abrecord);
		CConvert(lpRecord,szData, nSize);
		CString strMsg = szData;
		CString strTime;
		CString strUser;
		GetMsgTimeUser(strMsg, strTime, strUser);
		
		CString *pstrItem = new CString;
		*pstrItem += strTime;
		*pstrItem += strUser;
		
		
		if(!IsDuplicate(&pDlg->m_lstReceive, *pstrItem) )
		{
			int nIndex = pDlg->m_lstReceive.AddString((const char*)strMsg);
			pDlg->m_lstReceive.SetItemDataPtr(nIndex, pstrItem);
			TRACE("%s\n", strMsg);
		}
		else
		{
			delete pstrItem;
		}
		

		
		if((strUser != pDlg->m_strUser) || !IsOld(strTime))
		{
			//g_TheDQ->GetQueueItem(eigQItem, eigAnswerYes, eigAnswerNo,eigAnswerYes, INFINITE, eigAnswerYes, eigAnswerYes, vtNothing, eigSearchKeyEqual);	
			g_TheDQ->AddQueueItem(Item, eigAnswerYes);
			Sleep(1000);
		}
		delete[]szData;
		delete[]lpRecord;
		
	}
}

BEGIN_EVENTSINK_MAP(CDQChatCDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CDQChatCDlg)
	ON_EVENT(CDQChatCDlg, IDC_EIGDATAQUEUECTL1, 1 /* ConnectionStateChange */, OnConnectionStateChangeEigdataqueuectl1, VTS_I4)
	ON_EVENT(CDQChatCDlg, IDC_EIGDATAQUEUECTL1, 2 /* ReportError */, OnReportErrorEigdataqueuectl1, VTS_I4 VTS_BSTR)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CDQChatCDlg::OnConnectionStateChangeEigdataqueuectl1(long constate) 
{
	// TODO: Add your control notification handler code here
	
}

void CDQChatCDlg::OnReportErrorEigdataqueuectl1(long hr, LPCTSTR Text) 
{
	AfxMessageBox("An Error occured");
	OnCancel();
}
