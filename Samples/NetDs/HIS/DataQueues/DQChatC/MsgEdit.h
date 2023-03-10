#if !defined(AFX_MSGEDIT_H__C985F616_AA86_4031_96C9_4151B290294E__INCLUDED_)
#define AFX_MSGEDIT_H__C985F616_AA86_4031_96C9_4151B290294E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsgEdit.h : header file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

/////////////////////////////////////////////////////////////////////////////
// CMsgEdit window

class CMsgEdit : public CEdit
{
// Construction
public:
	CMsgEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgEdit)
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMsgEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMsgEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGEDIT_H__C985F616_AA86_4031_96C9_4151B290294E__INCLUDED_)
