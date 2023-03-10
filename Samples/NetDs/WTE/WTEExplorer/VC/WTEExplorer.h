/**************************************************************************
 *
 * Copyright (c) 1999 - 2000 Microsoft Corporation.  All rights reserved.
 *
 * This is sample software and is provided as is and Microsoft
 * makes no warranties, either express or implied.  The entire risk of
 * the use or the results of the use of this sample software
 * remains with the user.
 **************************************************************************/

// WTEExplorer.h : main header file for the WTEEXPLORER application
//

#if !defined(AFX_WTEEXPLORER_H__848B68DC_AB7D_11D2_A419_006094EB33FB__INCLUDED_)
#define AFX_WTEEXPLORER_H__848B68DC_AB7D_11D2_A419_006094EB33FB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "WTEExplorerView.h"

/////////////////////////////////////////////////////////////////////////////
// CWTEExplorerApp:
// See WTEExplorer.cpp for the implementation of this class
//

class CWTEExplorerApp : public CWinApp
{
public:
	CWTEExplorerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWTEExplorerApp)
	public:
	virtual BOOL InitInstance();
    virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

    UINT           GetNumberOfRows() { return m_numberOfRows; };
    IWTEService   *GetWTEService() { return m_pWTEService; };

	//{{AFX_MSG(CWTEExplorerApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	afx_msg void OnFileConnect();
	afx_msg void OnUpdateFileNew(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileConnect(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

    InitWTEService();

private:
        
    UINT           m_numberOfRows;
    IWTEService   *m_pWTEService;
    BOOL           m_fConnected;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WTEEXPLORER_H__848B68DC_AB7D_11D2_A419_006094EB33FB__INCLUDED_)
