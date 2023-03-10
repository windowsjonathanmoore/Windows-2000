// IHVLinksDlg.cpp : implementation file
//
#include "stdafx.h"
#include "IHVLinks.h"
#include "IHVLinksDlg.h"
#include "IHVWizardSheet.h"
#include <msi.h>
#include <msiquery.h>
#include <windowsx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BOOL CIHVLinksDlg::GetPackageInfo( IHVData* psIHVData )
{
	BOOL        bReturnCode      = FALSE;
	MSIHANDLE   hMSIHandle       = NULL;
	DWORD       dBufSize         = MAX_PATH;

	// Open the package handle
	if (ERROR_SUCCESS == MsiOpenPackage( psIHVData->szPackage, 
	                                     &hMSIHandle ))
	{
		// Get the Manufacturer Property value
		dBufSize = MAX_PATH;

		MsiGetProperty( hMSIHandle,
		                TEXT("Manufacturer"),
						psIHVData->szManufacturer,
						&dBufSize );

		// Get the Product Name Property value
		dBufSize = MAX_PATH;

		MsiGetProperty( hMSIHandle,
		                TEXT("ProductName"),
						psIHVData->szProductName,
						&dBufSize );

		// Get the Product Name Property value
		dBufSize = MAX_PATH;

		lstrcpy( psIHVData->szProductDescription,
		         TEXT("Product description not available"));

		MsiGetProperty( hMSIHandle,
		                TEXT("ProductDescription"),
						psIHVData->szProductDescription,
						&dBufSize );

		MsiCloseHandle( hMSIHandle );
	}

	// All finished...
	return bReturnCode;
}

DWORD CIHVLinksDlg::GetManufacturerItem( LPSTR pszManufacturer,
                                         HTREEITEM* htiManufacturer )
{
	DWORD       dReturnCode    = ERROR_SUCCESS;
	HTREEITEM   htiIHV         = {0};
	BOOL        bFound         = FALSE;

	// Get the first parent item
	htiIHV = m_ihvtree.GetNextItem( NULL, TVGN_ROOT );

	while ((NULL != htiIHV) &&
	       (!bFound))
	{
		if (pszManufacturer == m_ihvtree.GetItemText(htiIHV))
		{
			*htiManufacturer = htiIHV;
			bFound = TRUE;
		}

		// Next item
		htiIHV = m_ihvtree.GetNextItem( htiIHV, TVGN_NEXT );
	}

	if (!bFound)
	{
		// Manufacturer doesn't exist, create a new item
		*htiManufacturer = m_ihvtree.InsertItem( pszManufacturer,
		                                         TVI_ROOT,
		                                         TVI_LAST );

		// Set the data to NULL (manufacturers only)
		m_ihvtree.SetItemData( *htiManufacturer,
		                       0 );

	}

	// All finished...
	return dReturnCode;
}

/////////////////////////////////////////////////////////////////////////////
// CIHVLinksDlg dialog

CIHVLinksDlg::CIHVLinksDlg(UINT nIDD, UINT nIdHeaderTitle, UINT nIdSubTitle)
	: CPropertyPageEx(nIDD, 0, nIdHeaderTitle, nIdSubTitle)
{
	//{{AFX_DATA_INIT(CIHVLinksDlg)
	m_productdescription = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIHVLinksDlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPageEx::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIHVLinksDlg)
	DDX_Control(pDX, IDC_IHV_TREE, m_ihvtree);
	DDX_Text(pDX, IDC_DESCRIPTION, m_productdescription);
	DDV_MaxChars(pDX, m_productdescription, 255);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIHVLinksDlg, CPropertyPageEx)
	//{{AFX_MSG_MAP(CIHVLinksDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_IHV_TREE, OnSelchangedIhvTree)
	ON_NOTIFY(NM_CLICK, IDC_IHV_TREE, OnClickIhvTree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//ON_NOTIFY(NM_CLICK,IDC_IHV_TREE,OnItemClicked)
	
/////////////////////////////////////////////////////////////////////////////
// CIHVLinksDlg message handlers

BOOL CIHVLinksDlg::OnInitDialog()
{
	LPSTR            pszTemp                   = NULL;
	TCHAR            szBuff[MAX_PATH]          = TEXT("");
	IHVData*         psIHVData                 = NULL;
	WIN32_FIND_DATA  stFindFileData            = {0};
	HANDLE           hFileHandle               = INVALID_HANDLE_VALUE;
	HTREEITEM        htiCurrentIHVLink;
	HTREEITEM        htiManufacturer;

	CPropertyPageEx::OnInitDialog();

	CIHVWizardSheet* psheet = (CIHVWizardSheet*) GetParent();
	psheet->m_pIHVTree = &m_ihvtree;

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Initialize the Launch Path
	GetModuleFileName( NULL, szLaunchPath, MAX_PATH );

	// Remove Executable Filename
	pszTemp = szLaunchPath + lstrlen( szLaunchPath ) - 1;

	while ((*pszTemp != '\\') &&
	       (pszTemp != szLaunchPath))
	{
		pszTemp--;
	}

	// Append Format specifiers
	if (*pszTemp == '\\')
	{
		lstrcpy( pszTemp, TEXT("\\IHVLinks\\%s") );
	}
	
	// Format the enumeration string
	wsprintf( szBuff,
			  szLaunchPath,
			  TEXT("*.msi") );

	// Locate the first file
	hFileHandle = FindFirstFile( szBuff,
	                             &stFindFileData );

	if (hFileHandle)
	{
		do
		{
			// Allocate a new product structure
			psIHVData   = new(IHVData);

			// Full path to MSI file
			wsprintf( szBuff,
					  szLaunchPath,
					  stFindFileData.cFileName );

			// Add to product structure
			lstrcpy( psIHVData->szPackage,
			         szBuff );

			// Get the package information
			GetPackageInfo( psIHVData );

			// Get the Manufacture tree item
			GetManufacturerItem( psIHVData->szManufacturer,
			                     &htiManufacturer );

			// Insert item into Manufacturer tree
			htiCurrentIHVLink = m_ihvtree.InsertItem( psIHVData->szProductName, 
			                                          htiManufacturer,
			                                          TVI_LAST );

			// Set the path to the MSI file.
			m_ihvtree.SetItemData( htiCurrentIHVLink, 
			                       (unsigned long)psIHVData );

			// Sort the manufacture's tree
			m_ihvtree.SortChildren( htiManufacturer );
		}
		while (FindNextFile( hFileHandle, &stFindFileData ));
	}

	// Sort the tree
	m_ihvtree.SortChildren( TVI_ROOT );

	// All finished...
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIHVLinksDlg::OnPaint() 
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
		CPropertyPageEx::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIHVLinksDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CIHVLinksDlg::OnSelchangedIhvTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	HTREEITEM    htiCurrentIHVLink;
	IHVData*     psIHVData                 = NULL;

	// Get the MSI Filename and update the description
	htiCurrentIHVLink = m_ihvtree.GetSelectedItem();

	if (NULL != m_ihvtree.GetItemData( htiCurrentIHVLink ))
	{
		psIHVData = (IHVData*)m_ihvtree.GetItemData( htiCurrentIHVLink );
		
		// Update the description
		m_productdescription = psIHVData->szProductDescription;
	}
	else
	{
		m_productdescription = TEXT("");
	}

	UpdateData( FALSE );

	// All finished...
	*pResult = 0;
}

void CIHVLinksDlg::OnClickIhvTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
    DWORD dwpos;
    TV_HITTESTINFO tvhti;
	HTREEITEM    htiCurrentIHVLink;
    POINT point;

    // Find out where the click occurred
    dwpos = GetMessagePos();
    point.x = GET_X_LPARAM(dwpos);
    point.y = GET_Y_LPARAM(dwpos);
    m_ihvtree.ScreenToClient(&point);
    tvhti.pt = point;

	//retrieve the corresponding tree ctrl item
    htiCurrentIHVLink = m_ihvtree.HitTest(&tvhti);

    if ((tvhti.flags & TVHT_ONITEMSTATEICON) && (htiCurrentIHVLink !=NULL))
    {
		m_ihvtree.SelectItem(htiCurrentIHVLink);  //select (highlight) the item being clicked

		//if the item has children, select all of those
		if (m_ihvtree.ItemHasChildren(htiCurrentIHVLink))
		{
		   HTREEITEM hNextItem;
		   HTREEITEM hChildItem = m_ihvtree.GetChildItem(htiCurrentIHVLink);

		   while (hChildItem != NULL)
		   {
			  hNextItem = m_ihvtree.GetNextItem(hChildItem, TVGN_NEXT);
			  m_ihvtree.SetCheck(hChildItem,!(m_ihvtree.GetCheck( htiCurrentIHVLink)));
			  hChildItem = hNextItem;
		   }

		}
	}
		
	*pResult = 0;
}
