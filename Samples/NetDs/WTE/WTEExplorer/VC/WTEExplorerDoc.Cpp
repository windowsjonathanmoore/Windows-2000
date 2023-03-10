/**************************************************************************
 *
 * Copyright (c) 1999 - 2000 Microsoft Corporation.  All rights reserved.
 *
 * This is sample software and is provided as is and Microsoft
 * makes no warranties, either express or implied.  The entire risk of
 * the use or the results of the use of this sample software
 * remains with the user.
 **************************************************************************/

// WTEExplorerDoc.cpp : implementation of the CWTEExplorerDoc class
//

#include "stdafx.h"
#include "WTEExplorerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWTEExplorerDoc

IMPLEMENT_DYNCREATE(CWTEExplorerDoc, CDocument)

BEGIN_MESSAGE_MAP(CWTEExplorerDoc, CDocument)
	//{{AFX_MSG_MAP(CWTEExplorerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWTEExplorerDoc construction/destruction

CWTEExplorerDoc::CWTEExplorerDoc()
{
	// TODO: add one-time construction code here

}

CWTEExplorerDoc::~CWTEExplorerDoc()
{
}

BOOL CWTEExplorerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWTEExplorerDoc serialization

void CWTEExplorerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWTEExplorerDoc diagnostics

#ifdef _DEBUG
void CWTEExplorerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWTEExplorerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWTEExplorerDoc commands
