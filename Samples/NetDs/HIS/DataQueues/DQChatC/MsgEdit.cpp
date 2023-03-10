// MsgEdit.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DQChatC.h"
#include "MsgEdit.h"
#include "eigdataqueue.h"
#include "eigdataqueuectl.h"
#include "eigdataqueueitemW.h"
#include "DQChatCDlg.h"

#include <stddef.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsgEdit

CMsgEdit::CMsgEdit()
{
}

CMsgEdit::~CMsgEdit()
{
}


BEGIN_MESSAGE_MAP(CMsgEdit, CEdit)
	//{{AFX_MSG_MAP(CMsgEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsgEdit message handlers

BOOL CMsgEdit::OnCommand(WPARAM wParam, LPARAM lParam) 
{
		
	return CEdit::OnCommand(wParam, lParam);
}

void CMsgEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	static size_t nSize = offsetof(CDQChatCDlg, m_edSend);
	static CDQChatCDlg *pDlg = reinterpret_cast<CDQChatCDlg*>(reinterpret_cast<byte*>(this) - nSize);
	if(13 == nChar)
	{
		pDlg->OnSend();
		return;
	}
	CEdit::OnChar(nChar, nRepCnt, nFlags);
}
