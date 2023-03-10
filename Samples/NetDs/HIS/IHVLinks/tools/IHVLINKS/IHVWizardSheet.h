// IHVWizardSheet.h: interface for the CIHVWizardSheet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IHVWIZARDSHEET_H__04B12846_22D0_4EF7_B79A_01D9C6C2FE89__INCLUDED_)
#define AFX_IHVWIZARDSHEET_H__04B12846_22D0_4EF7_B79A_01D9C6C2FE89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CIHVWizardSheet : public CPropertySheetEx  
{
	DECLARE_DYNAMIC(CIHVWizardSheet)
public:
	CIHVWizardSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0, HBITMAP hbmWaterMark = NULL, HBITMAP hbmHeader = NULL);
	CIHVWizardSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0, HBITMAP hbmWaterMark = NULL, HBITMAP hbmHeader = NULL);
	virtual ~CIHVWizardSheet();

	CTreeCtrl *m_pIHVTree;
	
protected:
	DECLARE_MESSAGE_MAP()

};

#endif // !defined(AFX_IHVWIZARDSHEET_H__04B12846_22D0_4EF7_B79A_01D9C6C2FE89__INCLUDED_)
