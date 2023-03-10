
//=--------------------------------------------------------------------------=
//  (C) Copyright 1996 - 2000 Microsoft Corporation. All Rights Reserved.
//=--------------------------------------------------------------------------=
#include "stdafx.h"
#include "afxcview.h"
#include "wab.h"

class CWAB
{
public:
    CWAB(CString * pszFileName);
    ~CWAB();
    
    HRESULT LoadWABContents(CListCtrl * pListView);
    void ClearWABLVContents(CListCtrl * pListView);

    void LoadPropTags(CListBox * pList);
    void SetPropString(CEdit * pEdit, ULONG ulPropTag);

    void    ShowSelectedItemDetails(HWND hWndParent);
    HRESULT ShowNewEntryDialog(HWND hWndParent);
    HRESULT DeleteEntry();

    void GetSelectedItemPropArray();

    BOOL GetStringPropVal(HWND hWnd, ULONG ulPropTag, LPTSTR sz, ULONG cbsz);
    BOOL SetSingleStringProp(HWND hWnd, ULONG ulPropTag, LPTSTR sz);

    void SetSelection(CListCtrl * pListView);

private:
    BOOL        m_bInitialized;
    HINSTANCE   m_hinstWAB;
    LPWABOPEN   m_lpfnWABOpen;
    LPADRBOOK   m_lpAdrBook; 
    LPWABOBJECT m_lpWABObject;
    
    // Cache Proparray of currently selected item in the list view
    LPSPropValue m_lpPropArray;
    ULONG       m_ulcValues;
    
    // Cache entry id of currently selected item in the listview
    SBinary     m_SB;

    void FreeProws(LPSRowSet prows);
    HRESULT HrGetWABTemplateID(ULONG   ulObjectType, ULONG * lpcbEID, LPENTRYID * lppEID);

};


