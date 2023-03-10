
//=--------------------------------------------------------------------------=
//  (C) Copyright 1996 - 2000 Microsoft Corporation. All Rights Reserved.
//=--------------------------------------------------------------------------=
// drillerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "driller.h"
#include "drillDlg.h"
#include "WebBro.h"
#include <mshtml.h>

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
// CDrillerDlg dialog

CDrillerDlg::CDrillerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDrillerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDrillerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrillerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDrillerDlg)
	DDX_Control(pDX, IDC_LIST1, m_listTags);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDrillerDlg, CDialog)
	//{{AFX_MSG_MAP(CDrillerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_GO, OnBtnGo)
	ON_BN_CLICKED(IDC_BTN_DRILL, OnBtnDrill)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrillerDlg message handlers

BOOL CDrillerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	if (!strAboutMenu.IsEmpty())
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDrillerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDrillerDlg::OnPaint() 
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
HCURSOR CDrillerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDrillerDlg::OnBtnGo() 
{
	CWebBrowser2* pBrowser = (CWebBrowser2*)GetDlgItem( IDC_EXPLORER1 );
	CString strURL;
	GetDlgItemText( IDC_EDIT1, strURL );
	COleVariant* pvarURL = new COleVariant( strURL );
	COleVariant* pvarEmpty = new COleVariant;
	pBrowser->Navigate2( pvarURL, pvarEmpty, pvarEmpty, pvarEmpty, pvarEmpty );
	delete pvarURL;
	delete pvarEmpty;
}

void CDrillerDlg::OnBtnDrill() 
{
	m_listTags.ResetContent();

	CWebBrowser2* pBrowser = (CWebBrowser2*)GetDlgItem( IDC_EXPLORER1 );
	
	IDispatch* pDisp = pBrowser->GetDocument();

	if (pDisp != NULL )
	{
		IHTMLDocument2* pHTMLDocument2;
		HRESULT hr;
		hr = pDisp->QueryInterface( IID_IHTMLDocument2, (void**)&pHTMLDocument2 );
		if (hr == S_OK)
		{

			IHTMLElementCollection* pColl;
			hr = pHTMLDocument2->get_all( &pColl );
			if (hr == S_OK)
			{
				LONG celem;
				hr = pColl->get_length( &celem );

				if ( hr == S_OK )
				{
					for ( int i=0; i< celem; i++ )
					{
						VARIANT varIndex;
						varIndex.vt = VT_UINT;
						varIndex.lVal = i;
						VARIANT var2;
						VariantInit( &var2 );
						IDispatch* pDisp; 

						hr = pColl->item( varIndex, var2, &pDisp );

						if ( hr == S_OK )
						{

							IHTMLElement* pElem;

							hr = pDisp->QueryInterface( IID_IHTMLElement, (void **)&pElem );
							if ( hr == S_OK )
							{

								BSTR bstr;
								hr = pElem->get_tagName(&bstr);
								CString strTag = bstr;

								IHTMLImgElement* pImgElem;
								hr = pDisp->QueryInterface( IID_IHTMLImgElement, (void **)&pImgElem );
								if ( hr == S_OK )
								{
									pImgElem->get_href(&bstr);
									strTag += " - ";
									strTag += bstr;
									pImgElem->Release();
								}
								else
								{
									IHTMLAnchorElement* pAnchElem;
									hr = pDisp->QueryInterface( IID_IHTMLAnchorElement, (void **)&pAnchElem );
									if ( hr == S_OK )
									{
										pAnchElem->get_href(&bstr);
										strTag += " - ";
										strTag += bstr;
										pAnchElem->Release();
									}
								}

								m_listTags.AddString( strTag );
								
								pElem->Release();
							}
							pDisp->Release();
						}
					}
				}

				pColl->Release();
			}
			pHTMLDocument2->Release();
		}
		pDisp->Release();
	}

}


