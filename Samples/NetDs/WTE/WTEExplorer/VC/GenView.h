/**************************************************************************
 *
 * Copyright (c) 1999 - 2000 Microsoft Corporation.  All rights reserved.
 *
 * This is sample software and is provided as is and Microsoft
 * makes no warranties, either express or implied.  The entire risk of
 * the use or the results of the use of this sample software
 * remains with the user.
 **************************************************************************/

#ifndef GENVIEW_H_INCLUDED
#define GENVIEW_H_INCLUDED

/////////////////////////////////////////////////////////////////////////////
// CGeneralView view

class CGeneralView : public CListView
{
protected:
    CGeneralView();           // protected constructor used by dynamic creation
    DECLARE_DYNCREATE(CGeneralView)

// Attributes
public:
    ULONG   m_uNumTextLines;
    ULONG   m_uCurrentWidth;

// Operations
public:
    void AddLine(CString *pCString);
    HRESULT Connect(LPSTR szAppName);

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CGeneralView)
    protected:
    virtual void OnDraw(CDC* pDC);      // overridden to draw this view
    virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
    //}}AFX_VIRTUAL

// Implementation
protected:
    virtual ~CGeneralView();

#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

    // Generated message map functions
protected:
    //{{AFX_MSG(CGeneralView)
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif // GENVIEW_H_INCLUDED
