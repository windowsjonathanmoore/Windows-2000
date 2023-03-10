// IHVIntro.cpp: implementation of the CIHVIntro class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IHVLinks.h"
#include "IHVIntro.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CIHVIntro, CPropertyPageEx)

CIHVIntro::CIHVIntro(UINT nIDD, UINT nIdHeaderTitle, UINT nIdSubTitle) : CPropertyPageEx(nIDD, 0, nIdHeaderTitle, nIdSubTitle)
{

	m_psp.dwFlags  |= PSP_HIDEHEADER;

}

CIHVIntro::~CIHVIntro()
{

}

void CIHVIntro::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPageEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WELCOMETITLE2, m_staticBitmap2);
	DDX_Control(pDX, IDC_WELCOMETITLE, m_staticBitmap);
	
}

BEGIN_MESSAGE_MAP(CIHVIntro, CPropertyPageEx)
	//{{AFX_MSG_MAP(CIHVIntro)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIHVIntro message handlers

BOOL CIHVIntro::OnSetActive() 
{
	CPropertySheetEx* psheet = (CPropertySheetEx*) GetParent();
	psheet->SetWizardButtons(PSWIZB_NEXT);

	return CPropertyPageEx::OnSetActive();
}

BOOL CIHVIntro::OnInitDialog() 
{
	CPropertyPageEx::OnInitDialog();

	m_staticBitmap.SetTitleFont(GetWizardTitleFont());
    m_staticBitmap.SetBitmapTitle(IDS_WELCOME_TEXT);
	m_staticBitmap2.SetTitleFont(GetWizardTitleFont());
    m_staticBitmap2.SetBitmapTitle(IDS_WELCOME_TEXT2);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

CFont* CIHVIntro::GetWizardTitleFont()
{
    if (!m_fontWizardTitle.m_hObject)
    {
        // To support non-localized versions running on operating systems
        // of another language always use the best possible font.
        LOGFONT lfDlg;
        ::ZeroMemory(&lfDlg, sizeof(lfDlg));

        // Default font settings if none can be determined.
        ::lstrcpy(lfDlg.lfFaceName, _T("System"));
        lfDlg.lfCharSet = DEFAULT_CHARSET;

        CString strHeight;
        strHeight.LoadString(IDS_WIZARD_TITLE_TEXT_FONT_SIZE);
        lfDlg.lfHeight = _ttol(strHeight);

        lfDlg.lfWeight = FW_HEAVY;
        // Leave other values as zero for defaults. 

        // Determine new font settings.
        BOOL bReturn;

        CFont font;
        bReturn = font.CreateStockObject(DEFAULT_GUI_FONT);
        if (!bReturn)
        {
            bReturn = font.CreateStockObject(SYSTEM_FONT);
        }

        if (bReturn)
        {
            LOGFONT lfGUI;
            ::ZeroMemory(&lfGUI, sizeof(lfGUI));

            if (font.GetObject(sizeof(lfGUI), &lfGUI))
            {
                ::lstrcpy(lfDlg.lfFaceName, lfGUI.lfFaceName);
            }
        }

        BOOL b;
        b = m_fontWizardTitle.CreateFontIndirect(&lfDlg);

        ASSERT(b);
    }
    
    return &m_fontWizardTitle;
}
