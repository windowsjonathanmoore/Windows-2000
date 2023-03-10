// TestAppC.h : main header file for the TESTAPPC application
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

#if !defined(AFX_TESTAPPC_H__0DE52DEC_EE3B_4A55_92E7_00D032B161C2__INCLUDED_)
#define AFX_TESTAPPC_H__0DE52DEC_EE3B_4A55_92E7_00D032B161C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestAppCApp:
// See TestAppC.cpp for the implementation of this class
//

class CTestAppCApp : public CWinApp
{
public:
	CTestAppCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestAppCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestAppCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTAPPC_H__0DE52DEC_EE3B_4A55_92E7_00D032B161C2__INCLUDED_)
