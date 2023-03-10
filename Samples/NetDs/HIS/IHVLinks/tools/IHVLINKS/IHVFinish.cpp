// IHVFinish.cpp: implementation of the CIHVFinish class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IHVLinks.h"
#include "IHVFinish.h"
#include "IHVWizardSheet.h"
#include "IHVLinksDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIHVFinish::CIHVFinish(UINT nIDD, UINT nIdHeaderTitle, UINT nIdSubTitle) : CPropertyPageEx(nIDD, 0, nIdHeaderTitle, nIdSubTitle)
{
	m_psp.dwFlags  |= PSP_HIDEHEADER;

}

CIHVFinish::~CIHVFinish()
{

}

void CIHVFinish::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPageEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FINISHTITLE2, m_staticBitmap2);
	DDX_Control(pDX, IDC_FINISHTITLE, m_staticBitmap);
	
}

BEGIN_MESSAGE_MAP(CIHVFinish, CPropertyPageEx)
	//{{AFX_MSG_MAP(CIHVFinish)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIHVIntro message handlers

BOOL CIHVFinish::OnSetActive() 
{
	CPropertySheetEx* psheet = (CPropertySheetEx*) GetParent();
	psheet->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);

	return CPropertyPageEx::OnSetActive();
}

BOOL CIHVFinish::OnInitDialog() 
{
	CPropertyPageEx::OnInitDialog();

	m_staticBitmap.SetTitleFont(GetWizardTitleFont());
    m_staticBitmap.SetBitmapTitle(IDS_FINISH_TEXT);
	m_staticBitmap2.SetTitleFont(GetWizardTitleFont());
    m_staticBitmap2.SetBitmapTitle(IDS_FINISH_TEXT2);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CIHVFinish::OnWizardFinish() 
{
	//pick up the selected link services from the links page
	
	HTREEITEM   htiCurrentIHVLink;
	IHVData*    psIHVData                 = NULL;
	CIHVWizardSheet* psheet = (CIHVWizardSheet*) GetParent();

	// Get the first parent item
	htiCurrentIHVLink = psheet->m_pIHVTree->GetNextItem( NULL, TVGN_ROOT );
	
	while (htiCurrentIHVLink != NULL)
	{
		if (psheet->m_pIHVTree->ItemHasChildren(htiCurrentIHVLink))
		{
			HTREEITEM hNextItem;
			HTREEITEM hChildItem = psheet->m_pIHVTree->GetChildItem(htiCurrentIHVLink);

			while (hChildItem != NULL)
			{
				//get next child
				hNextItem = psheet->m_pIHVTree->GetNextItem(hChildItem, TVGN_NEXT);

				//get the data for the current child
				psIHVData = (IHVData*)psheet->m_pIHVTree->GetItemData(hChildItem);
					
				if ((psheet->m_pIHVTree->GetCheck(hChildItem)) && (NULL != psIHVData))  //if the child is selected, launch it
				{
					SHELLEXECUTEINFO seInfo;
					seInfo.cbSize = sizeof(SHELLEXECUTEINFO);
					seInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
					seInfo.hwnd = NULL;
					seInfo.lpVerb = NULL;
					seInfo.lpFile = psIHVData->szPackage;
					seInfo.lpParameters	= NULL;
					seInfo.lpDirectory = NULL;

					ShellExecuteEx(&seInfo);

					//now, we wait for the other process to complete, in order to avoid running two darwin packages at once (which is not recommended)
					WaitForSingleObject(seInfo.hProcess,INFINITE);
				}
				
				//now free up the data memory and delete the child
				if (NULL != psIHVData)
					delete(psIHVData);

				psheet->m_pIHVTree->DeleteItem(hChildItem);

				hChildItem = hNextItem;
			}
			
		}
		//now get the data for the current item
		psIHVData = (IHVData*)psheet->m_pIHVTree->GetItemData(htiCurrentIHVLink);
			
		//now free up the data memory and delete the item
		if (NULL != psIHVData)
			delete(psIHVData);

		psheet->m_pIHVTree->DeleteItem(htiCurrentIHVLink);
			
		//select the next item
		htiCurrentIHVLink = psheet->m_pIHVTree->GetNextItem( NULL, TVGN_ROOT );

	}

	// All finished...
	
	return CPropertyPageEx::OnWizardFinish();

}
CFont* CIHVFinish::GetWizardTitleFont()
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
