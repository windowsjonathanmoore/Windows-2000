
//=--------------------------------------------------------------------------=
//  (C) Copyright 1996 - 2000 Microsoft Corporation. All Rights Reserved.
//=--------------------------------------------------------------------------=
// driller.h : main header file for the DRILLER application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


/////////////////////////////////////////////////////////////////////////////
// CDrillerApp:
// See driller.cpp for the implementation of this class
//
/////////////////////////////////////////////////////////////////////////////
class CDrillerApp : public CWinApp
{
public:
	CDrillerApp();
	~CDrillerApp();
	class CImpIDispatch* m_pDispOM;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrillerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDrillerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

extern CDrillerApp theApp;
/////////////////////////////////////////////////////////////////////////////
