// IHVUtilDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IHVUtil.h"
#include "IHVUtilDlg.h"
#include <msi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IHV_SUPPORT_REGISTRY_KEY     TEXT("SYSTEM\\CurrentControlSet\\Services\\SnaBase\\IHVSupport")

void CIHVUtilDlg::EnumerateIHVLinks(void)
{
	HKEY        hRootKey               = HKEY_LOCAL_MACHINE;
	HKEY        hEnumKey               = HKEY_LOCAL_MACHINE;
	TCHAR       szKeyBuf[MAX_PATH]     = TEXT("");
	DWORD       dKeyBufSize            = sizeof(szKeyBuf);
	DWORD       dCurrentKey            = 0;
	TCHAR       szValueBuf[MAX_PATH]   = TEXT("");
	DWORD       dValueBufSize          = sizeof(szValueBuf);
	DWORD       dCurrentValue          = 0;
	TCHAR       szDataBuf[MAX_PATH]    = TEXT("");
	DWORD       dDataBufSize           = sizeof(szDataBuf);
	CString*    pcsItemData            = NULL;
	HTREEITEM   htiIHV;
	HTREEITEM   htiCurrentIHVLink;

	// Open the root key
	if (ERROR_SUCCESS == RegOpenKeyEx( HKEY_LOCAL_MACHINE,
	                                   IHV_SUPPORT_REGISTRY_KEY,
	                                   0,
	                                   KEY_ALL_ACCESS,
	                                   &hRootKey ))
	{
		// Set the current value index
		dCurrentValue = 0;

		while (ERROR_NO_MORE_ITEMS != RegEnumKeyEx( hRootKey,
		                                            dCurrentKey,
		                                            szKeyBuf,
		                                            &dKeyBufSize,
		                                            NULL,
		                                            NULL,
		                                            NULL,
		                                            NULL))
		{
			// Add the item to the tree
			htiIHV = m_ihvtree.InsertItem(szKeyBuf, TVI_ROOT, TVI_LAST);

			pcsItemData = new(CString);
			*pcsItemData = szKeyBuf;

			m_ihvtree.SetItemData( htiIHV, (unsigned long)pcsItemData );

			// Open the current key
			if (ERROR_SUCCESS == RegOpenKeyEx( hRootKey,
			                                   szKeyBuf,
			                                   0,
											   KEY_ALL_ACCESS,
			                                   &hEnumKey ))
			{
				// Enumerate all values
				while (ERROR_NO_MORE_ITEMS != RegEnumValue( hEnumKey,
				                                            dCurrentValue,
				                                            szValueBuf,
				                                            &dValueBufSize,
															0,
				                                            NULL,
				                                            (unsigned char *)szDataBuf,
				                                            &dDataBufSize ))
				{
					// Add the value to the tree
					htiCurrentIHVLink = m_ihvtree.InsertItem(szValueBuf, htiIHV, TVI_LAST);

					// Set the data
					pcsItemData = new(CString);
					*pcsItemData = szDataBuf;

					m_ihvtree.SetItemData( htiCurrentIHVLink, (unsigned long)pcsItemData );

					// Reset buffer sizes
					dValueBufSize  = sizeof(szValueBuf);
					dDataBufSize   = sizeof(szDataBuf);

					// Next value
					dCurrentValue++;
				}

				// Reset current value
				dCurrentValue = 0;

				// close the key
				RegCloseKey( hEnumKey );
			}

			// Expand the key
			m_ihvtree.Expand(htiIHV, TVE_EXPAND);

			// Reset buffer size
			dKeyBufSize = sizeof(szKeyBuf);

			// Next Key
			dCurrentKey++;
		}
	}
	
	// All finished...
}

void CIHVUtilDlg::FreeAllCStrings(void)
{
	HTREEITEM htiRootIHVLink;
	HTREEITEM htiChildIHVLink;
	CString*  pcsItemData;

	// Get the first parent item
	htiRootIHVLink = m_ihvtree.GetNextItem( NULL, TVGN_ROOT );

	while (NULL != htiRootIHVLink)
	{
		// Get the child
		htiChildIHVLink = m_ihvtree.GetNextItem( htiRootIHVLink, TVGN_CHILD );

		while (NULL != htiChildIHVLink)
		{
			// Get the data
			pcsItemData = (CString*)m_ihvtree.GetItemData(htiChildIHVLink);

			// Release the CString
			delete(pcsItemData);

			// Get the next child
			htiChildIHVLink = m_ihvtree.GetNextItem( htiChildIHVLink, TVGN_NEXT );
		}

		// Get the data
		pcsItemData = (CString*)m_ihvtree.GetItemData(htiRootIHVLink);

		// Release the CString
		delete(pcsItemData);

		// Get the next parent item
		htiRootIHVLink = m_ihvtree.GetNextItem( htiRootIHVLink, TVGN_NEXT );
	}

	// All finished...
}


/////////////////////////////////////////////////////////////////////////////
// CIHVUtilDlg dialog

CIHVUtilDlg::CIHVUtilDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIHVUtilDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIHVUtilDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIHVUtilDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIHVUtilDlg)
	DDX_Control(pDX, IDC_IHVTREE, m_ihvtree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIHVUtilDlg, CDialog)
	//{{AFX_MSG_MAP(CIHVUtilDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DISPLAY, OnDisplay)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_REFRESH, OnRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIHVUtilDlg message handlers

BOOL CIHVUtilDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// Update the style
	// m_ihvtree.ModifyStyle(0,TVS_HASLINES, 0);

	// Enumerate the IHVLinks
	EnumerateIHVLinks();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIHVUtilDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIHVUtilDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CIHVUtilDlg::OnDisplay() 
{
	CString*    pcsItemData;
	CString     pcsItemText;
	HTREEITEM   htiCurrentItem;

	// Check for root item
	htiCurrentItem = m_ihvtree.GetSelectedItem();

	if (NULL != htiCurrentItem)
	{
		// Get the Current Item Text
		pcsItemText = m_ihvtree.GetItemText(htiCurrentItem);

		// Get the Current Item data
		pcsItemData = (CString*)m_ihvtree.GetItemData(htiCurrentItem);

		// Popup the Message
		MessageBox( pcsItemData->GetBuffer(MAX_PATH), pcsItemText.GetBuffer(MAX_PATH), MB_OK );
	}

	// All finished...
}

void CIHVUtilDlg::OnRemove() 
{
	CString*    pcsItemData               = NULL;
	CString     pcsItemText               = TEXT("");
	TCHAR       szFeature[MAX_PATH]       = TEXT("");
	TCHAR       szProductCode[MAX_PATH]   = TEXT("");
	MSIHANDLE   hMSIHandle                = NULL;
	HTREEITEM   htiCurrentItem;

	// Check for root item
	htiCurrentItem = m_ihvtree.GetSelectedItem();

	if (NULL != m_ihvtree.GetNextItem( htiCurrentItem, TVGN_PARENT ))
	{
		// Get the Current Item Text
		pcsItemText = m_ihvtree.GetItemText(m_ihvtree.GetSelectedItem());
		lstrcpy( szFeature, pcsItemText.GetBuffer(MAX_PATH) );

		// Get the Current Item data
		pcsItemData = (CString*)m_ihvtree.GetItemData(m_ihvtree.GetSelectedItem());
		lstrcpy( szProductCode, pcsItemData->GetBuffer(MAX_PATH) );

		// Open an MSI Handle
		MsiConfigureFeature( szProductCode,
							 szFeature,
							 INSTALLSTATE_ABSENT );
	}

	// Free all the CStrings
	FreeAllCStrings();

	// Refresh the IHVLinks
	m_ihvtree.DeleteAllItems();

	EnumerateIHVLinks();

	// All finished...
}

void CIHVUtilDlg::OnOK() 
{
	// Free all the CStrings
	FreeAllCStrings();
	
	CDialog::OnOK();
}

void CIHVUtilDlg::OnCancel() 
{
	// Free all the CStrings
	FreeAllCStrings();
	
	CDialog::OnCancel();
}

void CIHVUtilDlg::OnRefresh() 
{
	// Free all the CStrings
	FreeAllCStrings();

	// Refresh the IHVLinks
	m_ihvtree.DeleteAllItems();

	EnumerateIHVLinks();

	// All finished...
}
