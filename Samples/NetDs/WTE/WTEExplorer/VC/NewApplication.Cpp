/**************************************************************************
 *
 * Copyright (c) 1999 - 2000 Microsoft Corporation.  All rights reserved.
 *
 * This is sample software and is provided as is and Microsoft
 * makes no warranties, either express or implied.  The entire risk of
 * the use or the results of the use of this sample software
 * remains with the user.
 **************************************************************************/

// NewApplication.cpp : implementation file
//

#include "stdafx.h"
#include "NewApplication.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewApplication dialog


CNewApplication::CNewApplication(CWnd* pParent /*=NULL*/)
	: CDialog(CNewApplication::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewApplication)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
    m_appName[0] = 0;
}


void CNewApplication::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewApplication)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewApplication, CDialog)
	//{{AFX_MSG_MAP(CNewApplication)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewApplication message handlers

void CNewApplication::OnOK() 
{
	// TODO: Add extra validation here
	
    CWnd *pCAppName = GetDlgItem(IDC_APPNAME_EDIT);

    pCAppName->GetWindowText(m_appName, 256);

	CDialog::OnOK();
}

