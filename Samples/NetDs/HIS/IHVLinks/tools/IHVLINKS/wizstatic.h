#if !defined(AFX_WIZSTATIC_H__93ECC8B4_F0D1_11D1_8C39_006008199131__INCLUDED_)
#define AFX_WIZSTATIC_H__93ECC8B4_F0D1_11D1_8C39_006008199131__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WizStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWizStatic window

class CWizStatic : public CStatic
{
// Construction
public:
	CWizStatic();

// Attributes
public:
    void SetBitmapTitle(const UINT nResourceID,
                        const CPoint& pt = CPoint(20, 10));
    void SetBitmapTitle(const CString& strTitle,
                        const CPoint& pt = CPoint(20, 10));

    void SetBitmapText(const UINT nResourceID,
                       const CRect& rect);
    void SetBitmapText(const CString& strText,
                        const CRect& rect);

    void SetTitleFont(CFont* pFont);
    void SetTextFont(CFont* pFont);

// Operations
public:
    int AddBitmapBullets(const UINT nIDHeading,
                         const CStringArray& astrText,
                         const CPoint& pt);
    int AddBitmapBullets(const CString& strHeading,
                         const CStringArray& astrText,
                         const CPoint& pt);
    void RemoveAllBitmapBullets();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWizStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWizStatic();

	// Generated message map functions
protected:
	UINT m_nBitmapResourceID;

    CFont* m_pTitleFont;
    CFont* m_pTextFont;

    CString m_strBitmapTitle;
    CPoint m_ptBitmapTitle;

    CString m_strBitmapText;
    CRect m_rectBitmapText;

    CString m_strBitmapBulletsHeading;
    CStringArray m_astrBitmapBullets;
    CPoint m_ptBitmapBullets;

	
	//{{AFX_MSG(CWizStatic)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WIZSTATIC_H__93ECC8B4_F0D1_11D1_8C39_006008199131__INCLUDED_)
