/**************************************************************************
 *
 * Copyright (c) 1999 - 2000 Microsoft Corporation.  All rights reserved.
 *
 * This is sample software and is provided as is and Microsoft
 * makes no warranties, either express or implied.  The entire risk of
 * the use or the results of the use of this sample software
 * remains with the user.
 **************************************************************************/

// WTEExplorerView.h : interface of the CWTEExplorerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WTEEXPLORERVIEW_H__848B68E6_AB7D_11D2_A419_006094EB33FB__INCLUDED_)
#define AFX_WTEEXPLORERVIEW_H__848B68E6_AB7D_11D2_A419_006094EB33FB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CWTEExplorerView : public CListView
{
protected: // create from serialization only
	CWTEExplorerView();
	DECLARE_DYNCREATE(CWTEExplorerView)

// Attributes
public:
    ULONG   m_uNumTextLines;
    ULONG   m_uCurrentWidth;

// Operations
public:

    void AddLine(CString *pCString);
    HRESULT Connect(LPTSTR szAppName);
    IWTEActiveConnection *GetApp(void) { return m_pApp; }


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWTEExplorerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWTEExplorerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

    
// Generated message map functions
protected:
	//{{AFX_MSG(CWTEExplorerView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

    IWTEActiveConnection *m_pApp;
    IConnectionPoint   *m_pEventCP;
    DWORD               m_dwCookie;
    DEventsClass        m_DEvents;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WTEEXPLORERVIEW_H__848B68E6_AB7D_11D2_A419_006094EB33FB__INCLUDED_)
