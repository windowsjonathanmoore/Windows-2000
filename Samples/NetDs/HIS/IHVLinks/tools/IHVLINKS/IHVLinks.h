// IHVLinks.h : main header file for the IHVLINKS application
//

#if !defined(AFX_IHVLINKS_H__A16D835D_5A85_4B34_8CD8_88A9C00189C9__INCLUDED_)
#define AFX_IHVLINKS_H__A16D835D_5A85_4B34_8CD8_88A9C00189C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIHVLinksApp:
// See IHVLinks.cpp for the implementation of this class
//

class CIHVLinksApp : public CWinApp
{
public:
	CIHVLinksApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIHVLinksApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIHVLinksApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IHVLINKS_H__A16D835D_5A85_4B34_8CD8_88A9C00189C9__INCLUDED_)
