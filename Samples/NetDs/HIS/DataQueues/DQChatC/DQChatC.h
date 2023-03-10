// DQChatC.h : main header file for the DQCHATC application
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

#if !defined(AFX_DQCHATC_H__864EC5C5_09E1_4588_A8ED_2292C3AE54CB__INCLUDED_)
#define AFX_DQCHATC_H__864EC5C5_09E1_4588_A8ED_2292C3AE54CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDQChatCApp:
// See DQChatC.cpp for the implementation of this class
//

class CDQChatCApp : public CWinApp
{
public:
	CDQChatCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDQChatCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDQChatCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DQCHATC_H__864EC5C5_09E1_4588_A8ED_2292C3AE54CB__INCLUDED_)
