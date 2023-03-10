// IHVIntro.h: interface for the CIHVIntro class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IHVINTRO_H__39356D3A_2012_4039_8A74_44C19A5CD2F5__INCLUDED_)
#define AFX_IHVINTRO_H__39356D3A_2012_4039_8A74_44C19A5CD2F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"
#include "stdafx.h"
#include "wizstatic.h"

class CIHVIntro : public CPropertyPageEx  
{
	DECLARE_DYNCREATE(CIHVIntro)

public:
	CIHVIntro(UINT nIDD=IDD_WELCOME,UINT nIdHeaderTitle = 0, UINT nIdSubTitle = 0);
	virtual ~CIHVIntro();

	enum { IDD = IDD_WELCOME};
	
public:
	virtual BOOL OnSetActive();
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	CFont* GetWizardTitleFont();

// Implementation
protected:
	CFont m_fontWizardTitle;
	CWizStatic	m_staticBitmap2;
	CWizStatic	m_staticBitmap;
	
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_IHVINTRO_H__39356D3A_2012_4039_8A74_44C19A5CD2F5__INCLUDED_)
