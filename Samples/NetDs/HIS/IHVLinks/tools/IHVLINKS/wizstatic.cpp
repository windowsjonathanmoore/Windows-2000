// WizStatic.cpp : implementation file
//

#include "stdafx.h"
#include "WizStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWizStatic

CWizStatic::CWizStatic() :
    m_nBitmapResourceID(0),
    m_pTitleFont(NULL),
    m_pTextFont(NULL)
{
}

CWizStatic::~CWizStatic()
{
	if (m_pTitleFont)
    {
        m_pTitleFont->DeleteObject();
    }

    if (m_pTextFont)
    {
        m_pTextFont->DeleteObject();
    }

    RemoveAllBitmapBullets();
}


BEGIN_MESSAGE_MAP(CWizStatic, CStatic)
	//{{AFX_MSG_MAP(CWizStatic)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWizStatic attributes

/////////////////////////////////////////////////////////////////////////////

void CWizStatic::SetTitleFont(CFont* pFont)
{
    m_pTitleFont = pFont;
}

/////////////////////////////////////////////////////////////////////////////
void CWizStatic::SetTextFont(CFont* pFont)
{
    m_pTextFont = pFont;
}

/////////////////////////////////////////////////////////////////////////////
void CWizStatic::SetBitmapTitle(const UINT nResourceID,
                               const CPoint& pt /*= CPoint(20, 10)*/)
{
    ASSERT(nResourceID);

    m_strBitmapTitle.LoadString(nResourceID);
    m_ptBitmapTitle = pt;
}

/////////////////////////////////////////////////////////////////////////////
void CWizStatic::SetBitmapTitle(const CString& strTitle,
                               const CPoint& pt /*= CPoint(20, 10)*/)
{
    m_strBitmapTitle = strTitle;
    m_ptBitmapTitle = pt;
}

/////////////////////////////////////////////////////////////////////////////
void CWizStatic::SetBitmapText(const UINT nResourceID,
                              const CRect& rect)
{
    ASSERT(nResourceID);

    m_strBitmapText.LoadString(nResourceID);
    m_rectBitmapText = rect;
}

/////////////////////////////////////////////////////////////////////////////
void CWizStatic::SetBitmapText(const CString& strText,
                               const CRect& rect)
{
    m_strBitmapText = strText;
    m_rectBitmapText = rect;
}

/////////////////////////////////////////////////////////////////////////////
// CWizStatic operations

/////////////////////////////////////////////////////////////////////////////
int CWizStatic::AddBitmapBullets(const UINT nIDHeading,
                                const CStringArray& astrText,
                                const CPoint& pt)
{
    _ASSERTE(nIDHeading);

    m_strBitmapBulletsHeading.LoadString(nIDHeading);
    m_ptBitmapBullets = pt;

    return m_astrBitmapBullets.Append(astrText);
}

/////////////////////////////////////////////////////////////////////////////
int CWizStatic::AddBitmapBullets(const CString& strHeading,
                                const CStringArray& astrText,
                                const CPoint& pt)
{
    m_strBitmapBulletsHeading = strHeading;
    m_ptBitmapBullets = pt;

    return m_astrBitmapBullets.Append(astrText);
}

/////////////////////////////////////////////////////////////////////////////
void CWizStatic::RemoveAllBitmapBullets()
{
    m_astrBitmapBullets.RemoveAll();
}

/////////////////////////////////////////////////////////////////////////////
// CWizStatic message handlers

void CWizStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
    
    if ((m_pTitleFont) && (!m_strBitmapTitle.IsEmpty()))
    {
        int modeOld = dc.SetBkMode(TRANSPARENT);
        CFont* pOldFont = dc.SelectObject(m_pTitleFont);

        dc.TextOut(m_ptBitmapTitle.x,
                   m_ptBitmapTitle.y,
                   m_strBitmapTitle);

        dc.SetBkMode(modeOld);
        dc.SelectObject(pOldFont);
    }
    
    if (m_pTextFont)
    {
        int modeOld = dc.SetBkMode(TRANSPARENT);
        CFont* pOldFont = dc.SelectObject(m_pTextFont);

        if (!m_strBitmapText.IsEmpty())
        {
            dc.DrawText(m_strBitmapText,
                        -1,
                        m_rectBitmapText,
                        DT_LEFT | DT_NOPREFIX | DT_WORDBREAK);
        }

        int c = m_astrBitmapBullets.GetSize();
        if (c)
        {
            dc.TextOut(m_ptBitmapBullets.x,
                       m_ptBitmapBullets.y,
                       m_strBitmapBulletsHeading);

            TEXTMETRIC tm;
            dc.GetTextMetrics(&tm);

            int y = m_ptBitmapBullets.y + tm.tmHeight + tm.tmDescent;

            int xText = m_ptBitmapBullets.x + (tm.tmAveCharWidth * 2);

            CBrush brush;
            brush.CreateSolidBrush(RGB(0,0,0));
            CBrush* pOldBrush = dc.SelectObject(&brush);

            for (int i = 0; i != c; ++i)
            {
                dc.TextOut(xText,
                           y,
                           m_astrBitmapBullets.GetAt(i));

                y += ((tm.tmHeight + tm.tmDescent) / 2) - (tm.tmAveCharWidth * 3/4);

                dc.Ellipse(m_ptBitmapBullets.x,
                           y,
                           m_ptBitmapBullets.x + tm.tmAveCharWidth,
                           y + tm.tmAveCharWidth);

                y += tm.tmHeight - tm.tmDescent;

            }

            dc.SelectObject(pOldBrush);
            brush.DeleteObject();
        }

        dc.SetBkMode(modeOld);
        dc.SelectObject(pOldFont);
    }

    // Do not call CStatic::OnPaint() for painting messages

}
