// IHVLinks.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "IHVIntro.h"
#include "IHVWizardSheet.h"
#include "IHVLinks.h"
#include "IHVLinksDlg.h"
#include "IHVFinish.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIHVLinksApp

BEGIN_MESSAGE_MAP(CIHVLinksApp, CWinApp)
	//{{AFX_MSG_MAP(CIHVLinksApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIHVLinksApp construction

CIHVLinksApp::CIHVLinksApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CIHVLinksApp object

CIHVLinksApp theApp;

static BOOL Is256ColorSupported()
{
	BOOL bRetval = FALSE;

	// return TRUE if screen deivce supports 256 colors or better

	HDC hdc = GetDC(NULL);
	if (hdc != NULL)
	{
		if(GetDeviceCaps(hdc, BITSPIXEL) >= 8)
			bRetval = TRUE;
		ReleaseDC(NULL, hdc);
	}

	return bRetval;
}


/////////////////////////////////////////////////////////////////////////////
// CIHVLinksApp initialization

BOOL CIHVLinksApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CBitmap bmpWatermark;
	CBitmap bmpHeader;

	if (Is256ColorSupported())
	{
		VERIFY(bmpWatermark.LoadBitmap(IDB_WELCOME256));
		VERIFY(bmpHeader.LoadBitmap(IDB_HEADER256));
	}
	else
	{
		VERIFY(bmpWatermark.LoadBitmap(IDB_WELCOME16));
		VERIFY(bmpHeader.LoadBitmap(IDB_HEADER16));
	}

	CIHVWizardSheet ps(IDS_WIZARD_SHEET, NULL, 0, bmpWatermark, bmpHeader);
	
	ps.m_psh.hInstance = ::GetModuleHandle(NULL);
	ps.m_psh.dwFlags |= PSH_WIZARD97 | PSH_STRETCHWATERMARK | PSH_WATERMARK | PSH_HEADER;
	//hide help
	ps.m_psh.dwFlags &= ~(PSH_HASHELP);

	CIHVIntro pageIntro(IDD_WELCOME, IDS_WELCOME_TEXT, IDS_WELCOME_TEXT2);
	CIHVLinksDlg pageLinks(IDD_IHVLINKS_DIALOG, IDS_HEADER_LINKS, IDS_SUBHEADER_LINKS);
	CIHVFinish pageFinish(IDD_FINISH, IDS_FINISH_TEXT, IDS_FINISH_TEXT2);
	
	ps.AddPage(&pageIntro);
	ps.AddPage(&pageLinks);
	ps.AddPage(&pageFinish);
	
	ps.SetWizardMode();

	int nResponse = /*dlg.DoModal();*/ps.DoModal();

	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the wizard is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the wizard is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
