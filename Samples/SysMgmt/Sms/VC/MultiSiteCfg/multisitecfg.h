// MultiSiteCfg.h : main header file for the MULTISITECFG application
//

#if !defined(AFX_MULTISITECFG_H__74962DD1_A69B_11D2_877A_00C04F96DE59__INCLUDED_)
#define AFX_MULTISITECFG_H__74962DD1_A69B_11D2_877A_00C04F96DE59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiSiteCfgApp:
// See MultiSiteCfg.cpp for the implementation of this class
//
class CConfigApp;

class CMultiSiteCfgApp : public CWinApp
{
private:
	CConfigApp* m_pCfg;
public:
	CMultiSiteCfgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiSiteCfgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiSiteCfgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	void RunCommandFile(const CString& csCmdFile);
};


class CThisAppCommandLineInfo : public CCommandLineInfo
{
public:
	CString m_csNamespace;
	CString m_csServer;
	CString m_csCmdFile;

public:
	CThisAppCommandLineInfo() {}
	virtual void ParseParam( LPCTSTR lpszParam, BOOL bFlag, BOOL bLast );
};
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTISITECFG_H__74962DD1_A69B_11D2_877A_00C04F96DE59__INCLUDED_)
