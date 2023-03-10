
//=--------------------------------------------------------------------------=
//  (C) Copyright 1996 - 2000 Microsoft Corporation. All Rights Reserved.
//=--------------------------------------------------------------------------=
// driller.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "driller.h"
#include "drillDlg.h"
// NOTE: This line is a hardcoded reference to an MFC header file
//  this path may need to be changed to refer to the location of VC5 install
//  for successful compilation.
#include <..\src\occimpl.h>
#include "custsite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrillerApp

BEGIN_MESSAGE_MAP(CDrillerApp, CWinApp)
	//{{AFX_MSG_MAP(CDrillerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

// The one and only CDrillerApp object
CDrillerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDrillerApp construction

CDrillerApp::CDrillerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

CDrillerApp::~CDrillerApp()
{
	if ( m_pDispOM != NULL)
	{
		delete m_pDispOM;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDrillerApp initialization

BOOL CDrillerApp::InitInstance()
{
	// Create a custom control manager class so we can overide the site
	CCustomOccManager *pMgr = new CCustomOccManager;

	// Create an IDispatch class for extending the Dynamic HTML Object Model 
	m_pDispOM = new CImpIDispatch;

	// Set our control containment up but using our control container 
	// management class instead of MFC's default
	AfxEnableControlContainer(pMgr);

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();                     // Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();       // Call this when linking to MFC statically
#endif

	CDrillerDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

