// ConfigDlg.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "dqchatc.h"
#include "ConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfigDlg dialog


CConfigDlg::CConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConfigDlg)
	m_strPasswd = _T("");
	m_strQueue = _T("");
	m_strRemoteLU = _T("");
	m_strUser = _T("");
	m_strScreen = _T("");
	//}}AFX_DATA_INIT
}


void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConfigDlg)
	DDX_Text(pDX, IDC_PASSWD, m_strPasswd);
	DDX_Text(pDX, IDC_QUEUE, m_strQueue);
	DDX_Text(pDX, IDC_REMOTELU, m_strRemoteLU);
	DDX_Text(pDX, IDC_USER, m_strUser);
	DDX_Text(pDX, IDC_SCREEN, m_strScreen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialog)
	//{{AFX_MSG_MAP(CConfigDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfigDlg message handlers

void CConfigDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	CDialog::OnOK();
}
