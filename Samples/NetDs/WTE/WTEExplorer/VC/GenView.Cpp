/**************************************************************************
 *
 * Copyright (c) 1999 - 2000 Microsoft Corporation.  All rights reserved.
 *
 * This is sample software and is provided as is and Microsoft
 * makes no warranties, either express or implied.  The entire risk of
 * the use or the results of the use of this sample software
 * remains with the user.
 **************************************************************************/

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "stdafx.h"

extern LPCTSTR lineDevStateText[];
extern int sizeOfLineDevStateText;
extern LPCTSTR lineFeatureText[];
extern int sizeOfLineFeatureText;
extern LPCTSTR lineMediaModeText[];
extern int sizeOfLineMediaModeText;

/////////////////////////////////////////////////////////////////////////////
// CGeneralView

IMPLEMENT_DYNCREATE(CGeneralView, CListView)

CGeneralView::CGeneralView()
{
    m_uNumTextLines = 0;
    m_uCurrentWidth = 100;
}

CGeneralView::~CGeneralView()
{
}


BEGIN_MESSAGE_MAP(CGeneralView, CListView)
    //{{AFX_MSG_MAP(CGeneralView)
    ON_WM_CREATE()
        ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
        ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
        ON_WM_PAINT()
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeneralView drawing

void CGeneralView::OnDraw(CDC* pDC)
{
    // CDocument* pDoc = GetDocument();
}


/////////////////////////////////////////////////////////////////////////////
// CGeneralView diagnostics

#ifdef _DEBUG
void CGeneralView::AssertValid() const
{
    CListView::AssertValid();
}

void CGeneralView::Dump(CDumpContext& dc) const
{
    CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGeneralView message handlers

int CGeneralView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    CString     csLoadString;
    CListCtrl&  listCtrl = GetListCtrl();

    //
    // Change the style to REPORT without headers.
    //
    lpCreateStruct->style |= LVS_REPORT | LVS_NOCOLUMNHEADER | LBS_EXTENDEDSEL;
    if (CListView::OnCreate(lpCreateStruct) == -1)
        return -1;

    //
    // Add some colors to the background.
    //
    listCtrl.SetBkColor(0x00808000); // 0x00bbggrr
    listCtrl.SetTextBkColor(0x00808000);

    //
    // Create one column.
    //
    listCtrl.InsertColumn(
        0,              // index
        "details",   // heading
        LVCFMT_LEFT,    // alignment
        m_uCurrentWidth,// width in pixels (can be changed in AddLine)
        -1);            // subitem
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
// Add a line of text to the view window.
HRESULT
CGeneralView::Connect(LPSTR szAppName)
{
    GetDocument()->SetTitle(szAppName);

    CString cs;
    cs = "starting";
    AddLine(&cs);


    //
    // Create the application.
    //


    //
    // Connect to the connection point.
    //
	
	return 0;

}

void CGeneralView::AddLine(CString *pCString)
{
    CListCtrl&  listCtrl = GetListCtrl();
    ULONG       uWidth;
    CWTEExplorerApp *pApp = (CWTEExplorerApp*)AfxGetApp();
    //
    // Adjust the column width.
    //
    uWidth = listCtrl.GetStringWidth(*pCString) + 15;    // 15 -> icon ?
    if (uWidth > m_uCurrentWidth)
    {
        m_uCurrentWidth = uWidth;
        listCtrl.SetColumnWidth(0, m_uCurrentWidth);
    }

    //
    // Don't overflow.
    //
    while (m_uNumTextLines >= (pApp->GetNumberOfRows()))
    {
        listCtrl.DeleteItem(0);
        m_uNumTextLines--;
    }
    //
    // Add the text.
    //
    listCtrl.InsertItem(m_uNumTextLines, *pCString);
    listCtrl.EnsureVisible(m_uNumTextLines++, FALSE);
}

void CGeneralView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
    CWTEExplorerApp *pApp = (CWTEExplorerApp*)AfxGetApp();
    CListCtrl&  listCtrl = GetListCtrl();

    while (m_uNumTextLines >= (pApp->GetNumberOfRows()))
    {
        listCtrl.DeleteItem(0);
        m_uNumTextLines--;
    }
}

//
// Enable/disable the Copy item when the Edit menu is selected
//
void CGeneralView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
    CListCtrl&  listCtrl = GetListCtrl();
    if (listCtrl.GetSelectedCount() == 0)
        pCmdUI->Enable(FALSE);
    else
        pCmdUI->Enable(TRUE);
}

//
// Copy selected lines to clipboard
//
void CGeneralView::OnEditCopy() 
{
    CListCtrl&  listCtrl = GetListCtrl();
    int         i;
    CString     csLogLine;
    CString     csAllSelected;
    BOOL        r;
    CWTEExplorerApp    *pApp = (CWTEExplorerApp*)AfxGetApp();
    CString     csLoadString;
    HGLOBAL     hglbCopy;
    LPTSTR      lptstrCopy;
    UINT        uLength;

    r = OpenClipboard();
    if (r == FALSE)
    {
        return;
    }
    r = EmptyClipboard();
    if (r == FALSE)
    {
        CloseClipboard();
        return;
    }
    for(i = -1; (i = listCtrl.GetNextItem(i, LVNI_SELECTED)) != -1;)
    {
        csLogLine = listCtrl.GetItemText(i, 0);
        csAllSelected += csLogLine;
        csAllSelected += _T("\r\n");
    }
    uLength = csAllSelected.GetLength();
    hglbCopy =  GlobalAlloc(GMEM_DDESHARE, 
            ((uLength + 1) * sizeof(TCHAR)));
    if (hglbCopy == NULL) 
    {
        CloseClipboard();
        return; 
    } 
    lptstrCopy = (LPTSTR)GlobalLock(hglbCopy); 
    memcpy(lptstrCopy, (LPCTSTR)csAllSelected, 
            (uLength * sizeof(TCHAR))); 
    lptstrCopy[uLength] = (TCHAR) 0;    // null character 
    GlobalUnlock(hglbCopy); 
 
    // Place the handle on the clipboard. 
    SetClipboardData(CF_UNICODETEXT, hglbCopy); 
    CloseClipboard();
}
