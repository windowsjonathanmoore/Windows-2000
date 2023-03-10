// IHVWizardSheet.cpp: implementation of the CIHVWizardSheet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IHVLinks.h"
#include "IHVWizardSheet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC(CIHVWizardSheet, CPropertySheetEx)

CIHVWizardSheet::CIHVWizardSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage, HBITMAP hbmWaterMark, HBITMAP hbmHeader)
	:CPropertySheetEx(nIDCaption, pParentWnd, iSelectPage, hbmWaterMark, NULL, hbmHeader)
{
	// set the WIZARD97 flag so we'll get the new look
	m_psh.dwFlags |= PSH_WIZARD97;
}

CIHVWizardSheet::CIHVWizardSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage, HBITMAP hbmWaterMark, HBITMAP hbmHeader)
	:CPropertySheetEx(pszCaption, pParentWnd, iSelectPage, hbmWaterMark, NULL, hbmHeader)
{
	// set the WIZARD97 flag so we'll get the new look
	m_psh.dwFlags |= PSH_WIZARD97;
}

CIHVWizardSheet::~CIHVWizardSheet()
{

}

BEGIN_MESSAGE_MAP(CIHVWizardSheet, CPropertySheetEx)

END_MESSAGE_MAP()