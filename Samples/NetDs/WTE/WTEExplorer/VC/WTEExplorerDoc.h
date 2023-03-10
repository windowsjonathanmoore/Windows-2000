/**************************************************************************
 *
 * Copyright (c) 1999 - 2000 Microsoft Corporation.  All rights reserved.
 *
 * This is sample software and is provided as is and Microsoft
 * makes no warranties, either express or implied.  The entire risk of
 * the use or the results of the use of this sample software
 * remains with the user.
 **************************************************************************/

// WTEExplorerDoc.h : interface of the CWTEExplorerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WTEEXPLORERDOC_H__848B68E4_AB7D_11D2_A419_006094EB33FB__INCLUDED_)
#define AFX_WTEEXPLORERDOC_H__848B68E4_AB7D_11D2_A419_006094EB33FB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CWTEExplorerDoc : public CDocument
{
protected: // create from serialization only
	CWTEExplorerDoc();
	DECLARE_DYNCREATE(CWTEExplorerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWTEExplorerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWTEExplorerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWTEExplorerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WTEEXPLORERDOC_H__848B68E4_AB7D_11D2_A419_006094EB33FB__INCLUDED_)
