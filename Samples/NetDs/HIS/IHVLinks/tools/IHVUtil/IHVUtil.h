// IHVUtil.h : main header file for the IHVUTIL application
//

#if !defined(AFX_IHVUTIL_H__74B765B8_8484_4D69_94DC_224616FD37E0__INCLUDED_)
#define AFX_IHVUTIL_H__74B765B8_8484_4D69_94DC_224616FD37E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIHVUtilApp:
// See IHVUtil.cpp for the implementation of this class
//

class CIHVUtilApp : public CWinApp
{
public:
	CIHVUtilApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIHVUtilApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIHVUtilApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IHVUTIL_H__74B765B8_8484_4D69_94DC_224616FD37E0__INCLUDED_)
