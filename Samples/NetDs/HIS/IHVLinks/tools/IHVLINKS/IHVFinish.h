// IHVFinish.h: interface for the CIHVFinish class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IHVFINISH_H__ACF7FFFB_F299_4F6A_A07B_7D07152001A4__INCLUDED_)
#define AFX_IHVFINISH_H__ACF7FFFB_F299_4F6A_A07B_7D07152001A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"
#include "stdafx.h"
#include "wizstatic.h"

class CIHVFinish : public CPropertyPageEx  
{
public:
	CIHVFinish(UINT nIDD=IDD_WELCOME,UINT nIdHeaderTitle = 0, UINT nIdSubTitle = 0);
	virtual ~CIHVFinish();

	enum { IDD = IDD_FINISH};
	
public:
	virtual BOOL OnSetActive();
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnWizardFinish();
	CFont* GetWizardTitleFont();

// Implementation
protected:
	CFont m_fontWizardTitle;
	CWizStatic	m_staticBitmap2;
	CWizStatic	m_staticBitmap;
	
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_IHVFINISH_H__ACF7FFFB_F299_4F6A_A07B_7D07152001A4__INCLUDED_)
