// ----------------------------------------------------------------------------
// 
// This file is part of the Microsoft COM+ Samples.
// 
// Copyright (C) 1995-2000 Microsoft Corporation. All rights reserved.
// 
// This source code is intended only as a supplement to Microsoft
// Development Tools and/or on-line documentation. See these other
// materials for detailed information regarding Microsoft code samples.
// 
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
// 
// ----------------------------------------------------------------------------
#include "stdafx.h"			
#include <comsvcs.h>		
#include <comadmin.h>		

#include "ComSpyCtl.h"
#include "ComSpyAudit.h"

#include "CComSpy.h"				
#include "AppInfo.h"				
#include "SelectEventsDlg.h"	
#include <algorithm>
#include <comdef.h>		// For _bstr_t and _variant_t


// A simple macro used to set the checked state of a ListView item.
#ifndef ListView_SetCheckState
   #define ListView_SetCheckState(hwndLV, i, fCheck) \
      ListView_SetItemState(hwndLV, i, INDEXTOSTATEIMAGEMASK((fCheck)+1),\
								    LVIS_STATEIMAGEMASK)
#endif


// #DEFINES
#define MAX_APPNAME_SIZE 256


// CONSTANTS
const _bstr_t g_bstrAllApps(_T("All Applications"));
const _bstr_t g_bstrAppType_Application(_T("Application:"));
const _bstr_t g_bstrAppType_Process(_T("Process:"));


// TYPEDEFS
typedef struct _EVENT_SINK_INFO
{
	TCHAR * sDisplayName;
	EventEnum eEvent;
} EVENT_SINK_INFO;


// Module level EventInfo array containing all possible Publishing 
// interfaces from COM+.
EVENT_SINK_INFO EventInfo[] =
{
	_T("Activity"),		Activity,
	_T("Object Pool"),	ObjectPool,
	_T("Pool Mgmt"),	ObjectPool2,
	_T("Application"),	Application,
	_T("Construction"),	ObjectConstruction,	
	_T("Thread"),		Thread,
	_T("Instance"),		Instance,
	_T("Transaction"),	Transaction,
	_T("Method"),		Method,
	_T("Object"),		Object,
	_T("Resource"),		Resource,
	_T("UserDefined"),	User,
	_T("Security"),		Security,
	_T("Identity"),		Identity,
	_T("Queued"),		QC,
	_T("Exception"),	Exception,	
	_T("CRM"),			CRM,
};

//System events 
EVENT_SINK_INFO SystemEventInfo[] =
{
	_T("Event Store"),	EventStore,
	_T("Load Balancing"), LoadBalancing,
};


// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::CSelectEventsDlg(...)
// Params:  spMap:			Pointer to a MapStringToAppInfo that contains a STL
//							map of all CAppInfo structures and their names.
//							Each CAppInfo manages the events it subscribes to.
//			pSysAppInfo:	Pointer to AppInfo that manages the system events it 
//							subscribe to. Should have only one instance per COM+ system. 
//			pSpyObj:		Polymorphic pointer to the CComSpy-derived subscription
//							object for various COM+ Events.
// Returns: (None)
// Purpose:	Parameterized Constructor for the CSelectEventsDlg class.
// -----------------------------------------------------------------------------
CSelectEventsDlg::CSelectEventsDlg(MapStringToAppInfo* spMap, CAppInfo * pSysAppInfo, CComSpy* pSpyObj)
{
	m_map = spMap;
	m_pSysAppInfo = pSysAppInfo;  
	m_pSpyObj = pSpyObj;
}



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::OnInitDialog(...)
// Params:  All params are standard for ATL's MESSAGE_HANDLER mapping.
// Returns: Always 1 to ensure that the system sets focus 
// Purpose:	Called when Dialog sends WM_INITDIALOG message.  Does following:
//				1. Modifies the ListView to add CheckBox support.
//				2. Sets the Delete flag on all current Applications.
//				3. Gets a list of all Apps from the Catalog.
//				4. Gets a list of all running apps from COM+.
//				5. Fill the Event ListView with the available events.
//				6. Create the special AllApps object if necessary.
//				7. Parse the list of apps and delete those with Delete flag True
//				8. Select the first row in the Apps List Box.
//				9. Update the Event checkboxes for the current App or AllApps
// -----------------------------------------------------------------------------
LRESULT CSelectEventsDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, 
													BOOL& bHandled)
{
	// Set the window to have Check Box support.
	ListView_SetExtendedListViewStyle(GetDlgItem(IDC_LISTVIEWEVENTS), LVS_EX_CHECKBOXES);	


	ListView_SetExtendedListViewStyle(GetDlgItem(IDC_LISTVIEWSYSEVENTS), LVS_EX_CHECKBOXES);

	// Mark all Apps as ready for deletion until proven otherwise.
	MarkAllAppsForDelete(false);

	// Now populate the current Catalog applications.
	GetCatalogApps();

	// Now populate the current Running applications.
	GetRunningApps();	

	// Populate the list of possible App events.	
	PopulateEventList();

	//Populate the list of possible system events.  
	PopulateSysEventList();

	// Now create the AllApps CAppInfo.
	CAppInfo* pInfo = (*m_map)[(char*)g_bstrAllApps];
	if (!pInfo)
	{
		pInfo = new CAppInfo((TCHAR*)g_bstrAllApps, m_pSpyObj);
		(*m_map)[(char*)g_bstrAllApps] = pInfo;
	}
	else
		pInfo->SetDeleteFlag(false);

	// Do garbage collection on the apps that are no longer valid.
	MarkAllAppsForDelete(true);

	// Select the first Application in the listbox.
	SendDlgItemMessage(IDC_LIST_APPS, LB_SETCURSEL, 0);

	// If they are using any event in the special AllApps object, then display 
	// the check box and disable the ListBox.
	if (pInfo->IsSubscribedToAny())
	{
		CheckDlgButton(IDC_CHECK_ALLAPPS, 1);
		SelectAllApps(true);
	}
	else
		SelectApplication(0);

	ShowSelectedSystemEvents(); 

	return 1;
}



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::OnOK(...)
// Params:  All params for the standard ATL COMMAND_ID_HANDLER map.
// Returns: Returns 0 always.
// Purpose:	Handler for the OK button.  Simply ends the Dialog.
// -----------------------------------------------------------------------------
LRESULT CSelectEventsDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, 
							   BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::OnDestroyDlg(...)
// Params:  All params for the standard ATL COMMAND_ID_HANDLER map.
// Returns: Returns 0 always.
// Purpose:	Handler for the Destory Window message.  Ends the Dialog.
// -----------------------------------------------------------------------------
LRESULT CSelectEventsDlg::OnDestroyDlg(UINT uMsg, WPARAM wParam, 
													LPARAM lParam, BOOL& bHandled)
{
	bHandled = FALSE;
	return 0;
}



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::MarkAllAppsForDelete()
// Params:  bDeleteUnused: If true, this will actually delete the CAppInfo
//									instances with the delete flag set.
// Returns: (None)
// Purpose: To iterate through the STL map of applications and to set the delete 
//				flag for each one. Every app that is later found again will be 
//				cleared. Finally, the ones remaining will be garbaged.
// -----------------------------------------------------------------------------
void CSelectEventsDlg::MarkAllAppsForDelete(bool bDeleteUnused)
{
	MapStringToAppInfo::iterator item;
	CAppInfo * pInfo = NULL;

	item = m_map->begin();
	while (item != m_map->end())
	{
		pInfo = (*item).second;
		_ASSERTE(pInfo);

		// If Delete Unsued flag is set, we purge.
		if (bDeleteUnused)
		{
			if (pInfo->IsReadyForDelete()) 
			{
				delete pInfo;
				item = m_map->erase(item);
			}
			else
			{
				item++;
			}
		}
		else // We just set everything to delete.
		{
			pInfo->SetDeleteFlag(true);
			item++;
		};
	};
//for (item = m_map->begin(); item != m_map->end(); ++item)
}



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::GetCatalogApps()
// Params:  (None)
// Returns: True if successfully added the apps, otherwise False.
//	Purpose:	To list all COM+ apps in the Catalog, create a CAppInfo for each
//				one that does not yet exist, add the AppName to the list box, and
//				add the new app to the Application MAP.
// Steps:	1. Get a reference to the COMAdminCatalog object.
//				2. Get it to get "Applications" Collection as ICatalogCollection.
//				3. Populate() the collection to actually retrieve the data.
//				4. Iterate through the collection for every Item (ICatalogObject)
//				5. Use the interface to pull AppName, AppID (guid), etc.
//				6. If necessary, create a new CAppInfo object for this instance.
//					and add it to the global m_map STL MAP.
//				7. Set the Delete flag for the app to False (it still exists).
//				8. Add the App name to the App ListBox control.
//				9. Clean up references and get out.
// -----------------------------------------------------------------------------
bool CSelectEventsDlg::GetCatalogApps()
{
	USES_CONVERSION;

	HRESULT hr = E_FAIL;
	ICOMAdminCatalog* pCOMAdminCatalog = NULL;
	IDispatch* pDisp;
	ICatalogCollection* pCatalogCollection = NULL;
	ICatalogObject* pCatalog = NULL;
	CComBSTR bstrApplications("Applications");

	hr = CoCreateInstance(CLSID_COMAdminCatalog, NULL, CLSCTX_ALL, 
                         IID_ICOMAdminCatalog, (void **)&pCOMAdminCatalog);
	if (hr || (!pCOMAdminCatalog))
	{
		_ASSERTE(0);
		return false;
	}

	hr = pCOMAdminCatalog->GetCollection(bstrApplications, &pDisp);
	if (hr || (!pDisp))
	{
		_ASSERTE(0);
		return false;
	}
	SafeRelease(pCOMAdminCatalog);

	hr = pDisp->QueryInterface(IID_ICatalogCollection, 
							   (void **)&pCatalogCollection);
	if (hr || (!pCatalogCollection))
	{
		_ASSERTE(0);
		return false;
	}
	SafeRelease(pDisp);

	// Populate the Catalog collection.  The collection is empty 
	//	until this is called.
	hr = pCatalogCollection->Populate();
	if (hr)
	{
		_ASSERTE(0);
		return false;
	}
	
	// Now we can iterate through the Catalog apps.
	long lApplications;
	int dIndex;
	pCatalogCollection->get_Count(&lApplications);
	for (int i = 0; i < lApplications; i++)
	{
		pDisp = NULL;
		pCatalog = NULL;

		// Get the next Catalog in the collection.
		pCatalogCollection->get_Item(i, &pDisp);
		if (pDisp) pDisp->QueryInterface(IID_ICatalogObject, 
										 (void **)&pCatalog);

		// Get the Application name into a _bstr_t from the Catalog 
		// object for easier conversion.
		_variant_t vName;
		if (pCatalog) pCatalog->get_Name(&vName);
		_bstr_t sName = vName;
		LPSTR p = (char*)sName;
		_variant_t vKey;
		if (pCatalog) pCatalog->get_Key(&vKey);
		_bstr_t sKey = vKey;

		// Now get the pointer to the CAppInfo for this one.
		CAppInfo * pInfo = NULL;			
		pInfo = (*m_map)[p];
		if (!pInfo)
		{
			pInfo = new CAppInfo((TCHAR*)sName, m_pSpyObj, (TCHAR*)sKey); 
			_ASSERTE(pInfo);
			(*m_map)[p] = pInfo;
		};

		// Ensure we don't delete this app during Garbage Collection.
		pInfo->SetDeleteFlag(false);	

		// Add the item to the List Box.
		dIndex = SendDlgItemMessage(IDC_LIST_APPS, LB_ADDSTRING, 
									0, (LPARAM)(TCHAR*)sName);
		SafeRelease(pDisp);
		SafeRelease(pCatalog);
	};
	SafeRelease(pCatalogCollection);

	return true;
};



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::GetRunningApps()
// Params:  (None)
// Returns: True if successfully added the apps, False otherwise.
// Purpose:	To iterate through the currently running COM+ processes.  This can 
//				be either standard Applications or other processes via Libraries.
//				For each new Process, create a CAppInfo object for it and add it
//				to the Application MAP.  Also, add the name to App ListBox.
// Steps:	1. Get a reference to the MtsGrp object.
//				2. Get count of active applications.
//				3. For every app, get a IUnknown pointer to it.
//				4. QI for IMtsEvents to pull AppName, AppID (guid), etc.
//				5. If necessary, create a new CAppInfo object for this instance.
//					and add it to the global m_map STL MAP.
//				6. Set the Delete flag for the app to False (it still exists).
//				7. Add the App name to the App ListBox control.
//				8. Clean up references and get out.
// -----------------------------------------------------------------------------
bool CSelectEventsDlg::GetRunningApps()
{
	USES_CONVERSION;

	long lApplications;
	int dIndex;
	HRESULT hr = E_FAIL;
	IMtsGrp * pMtsGrp = NULL;
	IUnknown * pUnk = NULL;
	IMtsEvents * pEvents = NULL;

	hr = CoCreateInstance (CLSID_MtsGrp, NULL, CLSCTX_ALL, IID_IMtsGrp, (void **)&pMtsGrp);
	if (!pMtsGrp)
	{
		return false;
	}

	pMtsGrp->get_Count(&lApplications);

	// For each running Application, get the name and stuff it in LB.
	for (int i=0; i < lApplications; i++)
	{
		pMtsGrp->Item(i, &pUnk);
		pEvents = NULL;

		if (pUnk) pUnk->QueryInterface(IID_IMtsEvents, (void **)&pEvents);
		_ASSERTE(pEvents);		

		// Get the Application name into a _bstr_t for easier conversion.
		CComBSTR sName;
		CAppInfo * pInfo = NULL;			
		long lPID;
		if (pEvents) pEvents->get_PackageName(&sName);					
		if (pEvents) pEvents->GetProcessID(&lPID);
		_bstr_t bstrApplicationName((BSTR)sName);

		// Now get the pointer to the CAppInfo for this one.
		TCHAR szExtendedName[255];
		wsprintf( szExtendedName, _T(" [PID=%d (0x%08X)]"), lPID, lPID);
		bstrApplicationName += szExtendedName;
		LPSTR p = (char*)bstrApplicationName;
		pInfo = (*m_map)[p];
		if (!pInfo)
		{
			pInfo = new CAppInfo((TCHAR*)bstrApplicationName, m_pSpyObj, lPID); 
			_ASSERTE(pInfo);
			(*m_map)[p] = pInfo;
		};

		// Ensure we don't delete this app during Garbage Collection.
		pInfo->SetDeleteFlag(false);	

		// Add the AppName (with PID info) to the Apps ListBox.
		dIndex = SendDlgItemMessage(IDC_LIST_APPS, LB_ADDSTRING, 0, 
											 (LPARAM)((TCHAR*)bstrApplicationName));

		SafeRelease(pEvents);
		SafeRelease(pUnk);
	}
	
	SafeRelease(pMtsGrp);
	
	return true;
};



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::PopulateEventList()
// Params:  (None)
// Returns: (None)
// Purpose:	Empties and then fills the Event ListView with possible events.
//				All events are set to non-checked initially.  This basically uses
//				some macros to insert into the ListView.
// -----------------------------------------------------------------------------
void CSelectEventsDlg::PopulateEventList()
{
	LVITEM lvItem;
	int nIndex;
	int i;
	HWND	hEvents = GetDlgItem(IDC_LISTVIEWEVENTS);

	lvItem.state = 0;
	lvItem.iItem = 0;
	lvItem.stateMask = 0;
	lvItem.mask = LVIF_TEXT | LVIF_PARAM;
	lvItem.iSubItem = 0;

	// fill the Possible Events list
	for (i = 0; i < sizeof(EventInfo)/sizeof(EventInfo[0]); i++)
	{
		lvItem.pszText = EventInfo[i].sDisplayName;
		lvItem.lParam = (long)EventInfo[i].eEvent;
		lvItem.mask = LVIF_TEXT | LVIF_PARAM;
		nIndex = ListView_InsertItem(hEvents, &lvItem);
	}
}



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::PopulateSysEventList()
// Params:  (None)
// Returns: (None)
// Purpose:	Empties and then fills the System Event ListView with possible system events.
//			All events are set to non-checked initially.  This basically uses
//			some macros to insert into the ListView.
// -----------------------------------------------------------------------------
void CSelectEventsDlg::PopulateSysEventList()
{

	LVITEM lvItem;
	int nIndex;
	int i;
    
	HWND	hSysEvents = GetDlgItem(IDC_LISTVIEWSYSEVENTS);

	lvItem.state = 0;
	lvItem.iItem = 0;
	lvItem.stateMask = 0;
	lvItem.mask = LVIF_TEXT | LVIF_PARAM;
	lvItem.iSubItem = 0;

	//fill the possilbe System Events list
	for (i = 0; i < sizeof(SystemEventInfo)/sizeof(SystemEventInfo[0]); i++)
	{
		lvItem.pszText = SystemEventInfo[i].sDisplayName;
		lvItem.lParam = (long)SystemEventInfo[i].eEvent;
		lvItem.mask = LVIF_TEXT | LVIF_PARAM;
		nIndex = ListView_InsertItem(hSysEvents, &lvItem);
	}

}


// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::AppsListHandler(...)
// Params:  All params for the standard ATL COMMAND_ID_HANDLER map.
// Returns: Always returns 0
// Purpose:	If the Selection was changed, then update the GUI to display events
//				for the new Application.  Also, this may take some time so we need
//				to throw up the HourGlass.
// -----------------------------------------------------------------------------
LRESULT CSelectEventsDlg::AppsListHandler(WORD wNotifyCode, WORD wID, 
														HWND hWndCtl, BOOL& bHandled)
{
	bool bResult;
	int nIndex;
	HCURSOR hOldCursor;
	switch(wNotifyCode)
	{
	case LBN_SELCHANGE:
		hOldCursor = ::SetCursor(LoadCursor(NULL, IDC_WAIT));
		nIndex = SendDlgItemMessage(IDC_LIST_APPS, LB_GETCURSEL, 0, (LPARAM)0);
		bResult = SelectApplication(nIndex); // See below...
		::SetCursor(hOldCursor);
		break;
	default:
		break;
	};
	bHandled = TRUE;
	return 0;
}



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::OnSelectAllApps(...)
// Params:	Standard COMMAND_HANDLER() params.
// Returns: 0 always.
// Purpose:	Handle the toggling of the checkbox for Selecting All Apps.
// -----------------------------------------------------------------------------
LRESULT CSelectEventsDlg::OnSelectAllApps(WORD wNotifyCode, WORD wID, 
														HWND hWndCtl, BOOL& bHandled)
{
	UINT nChecked = IsDlgButtonChecked(IDC_CHECK_ALLAPPS);
	bool bResult = SelectAllApps(nChecked ? true : false);
	return 0;
};



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::SelectAllApps()
// Params:	bSelectAll: True says to SelectAll, False says Un-Select All.
// Returns: True always.
// Purpose:	Handle the toggling of the checkbox for Selecting All Apps.
//				If the checkbox is set, then we do the following:
//				1. Remove all Subscriptions for every App (expect AllApps object).
//				2. Disable Apps ListBox and update the static text caption.
//				3. Show current event mapping for the AllApps object.
//				In the Un-Select case, we simply reverse this. We also use 
//				Hourglass because this can take some time.
// -----------------------------------------------------------------------------
bool CSelectEventsDlg::SelectAllApps(bool bSelectAll)
{
	CAppInfo* pAllAppsInfo = (*m_map)[(char*)g_bstrAllApps];

	// Modify the cursor.
	HCURSOR hOldCursor = ::SetCursor(LoadCursor(NULL, IDC_WAIT));

	// Now remove all events for every app.
	MapStringToAppInfo::iterator item;
	CAppInfo* pAppInfo;
	for (item = m_map->begin(); item != m_map->end(); ++item)
	{
		pAppInfo = (*item).second;
		if ((pAppInfo) && (pAppInfo != pAllAppsInfo))
			pAppInfo->RemoveAllSubscriptions();
	};

	if (!bSelectAll)	
	{
		::EnableWindow(GetDlgItem(IDC_LIST_APPS), TRUE);
		int nItem = SendDlgItemMessage(IDC_LIST_APPS, LB_GETCURSEL, 0, 0);
		// Since we are unselecting AllApps, we need to remove its subscriptions 
		pAllAppsInfo->RemoveAllSubscriptions();
		bool bResult = SelectApplication(nItem);
	}
	else					
	{
		::EnableWindow(GetDlgItem(IDC_LIST_APPS), FALSE);
		SetDlgItemText(IDC_STATIC_CURRENTAPP, (TCHAR*)g_bstrAllApps);
	};

	// Re-fresh the event list for this CAppInfo
	ShowSelectedEvents((*m_map)[(char*)g_bstrAllApps]);

	// Update the static text for the application type.
	SetDlgItemText(IDC_STATIC_TYPE, (TCHAR*)g_bstrAppType_Application);

	::SetCursor(hOldCursor);
	return true;
};



// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::LVEventItemChanged(...)
// Params:  All params for the standard ATL COMMAND_ID_HANDLER map.
// Returns: Always returns 0
// Purpose:	
// -----------------------------------------------------------------------------
LRESULT CSelectEventsDlg::LVEventItemChanged(int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
{
	NM_LISTVIEW* pnmList = (NM_LISTVIEW*)pnmh;
	LVITEM lvItem;
	BOOL bResult;
	TCHAR sz[MAX_APPNAME_SIZE];		
	
	UINT nItemNumber = pnmList->iItem;
	UINT nCurrentState = pnmList->uNewState;
	UINT nOldState = pnmList->uOldState;

	lvItem.iItem = nItemNumber;
	lvItem.iSubItem = 0;
	lvItem.mask = LVIF_PARAM;
	memset(&sz[0], NULL, MAX_APPNAME_SIZE * sizeof(TCHAR));

	// If we toggled check box state, do this.
	if (((nCurrentState & 8192) && (nOldState & 4096)) || 
		 ((nOldState & 8192) && (nCurrentState & 4096)))
	{
		EventEnum nEvent;
		bResult = ListView_GetItem(GetDlgItem(IDC_LISTVIEWEVENTS), &lvItem);
		_ASSERTE(bResult);
		nEvent = (EventEnum)lvItem.lParam;

		// Get App Name.  If Checkbox enabled, then use the AllApps string.
		if (IsDlgButtonChecked(IDC_CHECK_ALLAPPS) == 0)
		{
			int nAppIndex = SendDlgItemMessage(IDC_LIST_APPS, LB_GETCURSEL, 0, (LPARAM)0);
			SendDlgItemMessage(IDC_LIST_APPS, LB_GETTEXT, nAppIndex, (LPARAM)sz);
		}
		else
			_tcscpy(sz, (TCHAR*)g_bstrAllApps);

		CAppInfo * pInfo = NULL;			
		_bstr_t bstrApplicationName(sz);
		LPSTR p = (char*)bstrApplicationName;
		pInfo = (*m_map)[p];
		_ASSERTE(pInfo);

		// If we have checked a previously unchecked box, do this:
		if ((nCurrentState & 8192) && (nOldState & 4096))
		{	
			// Install this event handler.
			if (!pInfo->IsSubscribed(nEvent))
			{
				HCURSOR hOldCursor = ::SetCursor(LoadCursor(NULL, IDC_WAIT));
				bResult = pInfo->AddSubscription(nEvent);				
				::SetCursor(hOldCursor);
			};
		}
		else if ((nOldState & 8192) && (nCurrentState & 4096))
		{
			// Remove this event handler.
			if (pInfo->IsSubscribed(nEvent))
			{
				HCURSOR hOldCursor = ::SetCursor(LoadCursor(NULL, IDC_WAIT));
				bResult = pInfo->RemoveSubscription(nEvent);
				::SetCursor(hOldCursor);
			};
		}
	};

	return 0;
};


// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::LVSystemEventItemChanged(...)
// Params:  All params for the standard ATL COMMAND_ID_HANDLER map.
// Returns: Always returns 0
// Purpose:	
// -----------------------------------------------------------------------------
LRESULT CSelectEventsDlg::LVSystemEventItemChanged(int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
{
	NM_LISTVIEW* pnmList = (NM_LISTVIEW*)pnmh;
	LVITEM lvItem;
	BOOL bResult;
	TCHAR sz[MAX_APPNAME_SIZE];		
	
	UINT nItemNumber = pnmList->iItem;
	UINT nCurrentState = pnmList->uNewState;
	UINT nOldState = pnmList->uOldState;

	lvItem.iItem = nItemNumber;
	lvItem.iSubItem = 0;
	lvItem.mask = LVIF_PARAM;
	memset(&sz[0], NULL, MAX_APPNAME_SIZE * sizeof(TCHAR));

	// If we toggled check box state, do this.
	if (((nCurrentState & 8192) && (nOldState & 4096)) || 
		 ((nOldState & 8192) && (nCurrentState & 4096)))
	{
		EventEnum nEvent;
		bResult = ListView_GetItem(GetDlgItem(IDC_LISTVIEWSYSEVENTS), &lvItem);
		_ASSERTE(bResult);
		nEvent = (EventEnum)lvItem.lParam;

		// If we have checked a previously unchecked box, do this:
		if ((nCurrentState & 8192) && (nOldState & 4096))
		{	
			// Install this event handler.
			if (!m_pSysAppInfo->IsSubscribed(nEvent))
			{
				HCURSOR hOldCursor = ::SetCursor(LoadCursor(NULL, IDC_WAIT));
				bResult = m_pSysAppInfo->AddSubscription(nEvent);				
				::SetCursor(hOldCursor);
			};
		}
		else if ((nOldState & 8192) && (nCurrentState & 4096))
		{
			// Remove this event handler.
			if (m_pSysAppInfo->IsSubscribed(nEvent))
			{
				HCURSOR hOldCursor = ::SetCursor(LoadCursor(NULL, IDC_WAIT));
				bResult = m_pSysAppInfo->RemoveSubscription(nEvent);
				::SetCursor(hOldCursor);
			};
		}
	};

	return 0;
};


// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::ShowSelectedEvents(...)
// Params:  pInfo: Pointer to the CAppInfo object to display.
// Returns: (None)
// Purpose:	This will update the Event ListView for the specified CAppInfo
//				object, based on the subscriptions the object contains.
// -----------------------------------------------------------------------------
void CSelectEventsDlg::ShowSelectedEvents(CAppInfo* pInfo)
{
	_ASSERTE(pInfo);
	LVITEM lvItem;
	BOOL bResult;
	bool bIsChecked;
	EventEnum nEvent;
	
	lvItem.iSubItem = 0;
	lvItem.mask = LVIF_PARAM;	// Get the the EventEnum value from lParam.

	for (int i = 0; i < sizeof(EventInfo)/sizeof(EventInfo[0]); i++)
	{
		// First, get the EventEnum for this item.
		lvItem.iItem = i;
		bResult = ListView_GetItem(GetDlgItem(IDC_LISTVIEWEVENTS), &lvItem);
		_ASSERTE(bResult);
		nEvent = (EventEnum)lvItem.lParam;

		// Now determine whether or not it should be checked.
		bIsChecked = pInfo->IsSubscribed(nEvent);

		// Next, update the ListView accordingly.
		ListView_SetCheckState(GetDlgItem(IDC_LISTVIEWEVENTS), i, bIsChecked);
	};
};


// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::ShowSelectedSystemEvents(...)
// Returns: (None)
// Purpose:	This will update the System Event ListView based on the 
//			subscriptions of the object that m_pSysAppInfo points to contains.
// -----------------------------------------------------------------------------
void CSelectEventsDlg::ShowSelectedSystemEvents()
{
	_ASSERTE(m_pSysAppInfo);
	LVITEM lvItem;
	BOOL bResult;
	bool bIsChecked;
	EventEnum nEvent;
	
	lvItem.iSubItem = 0;
	lvItem.mask = LVIF_PARAM;	// Get the the EventEnum value from lParam.

	for (int i = 0; i < sizeof(SystemEventInfo)/sizeof(SystemEventInfo[0]); i++)
	{
		// First, get the EventEnum for this item.
		lvItem.iItem = i;
		bResult = ListView_GetItem(GetDlgItem(IDC_LISTVIEWSYSEVENTS), &lvItem);
		_ASSERTE(bResult);
		nEvent = (EventEnum)lvItem.lParam;

		// Now determine whether or not it should be checked.
		bIsChecked = m_pSysAppInfo->IsSubscribed(nEvent);

		// Next, update the ListView accordingly.
		ListView_SetCheckState(GetDlgItem(IDC_LISTVIEWSYSEVENTS), i, bIsChecked);
	};
};


// -----------------------------------------------------------------------------
// Method:	CSelectEventsDlg::SelectApplication(...)
// Params:  nItem: Application index in listbox.
// Returns: Always returns true
// Purpose:	Select the Application with index nItem. This will update the
//				ListBox control with the proper highlight. It also gets the 
//				CAppInfo pointer for the given item. It updates some label text
//				on the Dialog to respect Process or Application.  Finally, this
//				method will update the list of events registered for this CAppInfo.
// -----------------------------------------------------------------------------
bool CSelectEventsDlg::SelectApplication(int nItem)
{
	USES_CONVERSION;
	TCHAR sz[MAX_APPNAME_SIZE];		
	memset(&sz[0], NULL, MAX_APPNAME_SIZE * sizeof(TCHAR));
	SendDlgItemMessage(IDC_LIST_APPS, LB_GETTEXT, nItem, (LPARAM)sz);
	SetDlgItemText(IDC_STATIC_CURRENTAPP, sz);

	// If this is a Process, use the special name.
	int nAppIndex = SendDlgItemMessage(IDC_LIST_APPS, LB_GETCURSEL, 0, (LPARAM)0);
	SendDlgItemMessage(IDC_LIST_APPS, LB_GETTEXT, nAppIndex, (LPARAM)sz);

	// Now get the pointer to the CAppInfo for this one.
	CAppInfo* pInfo = (*m_map)[T2A(sz)];
	_ASSERTE(pInfo);
	if (pInfo->GetFilterType() == ProcessID)
		SetDlgItemText(IDC_STATIC_TYPE, (TCHAR*)g_bstrAppType_Process);
	else
		SetDlgItemText(IDC_STATIC_TYPE, (TCHAR*)g_bstrAppType_Application);

	// Re-fresh the event list for this CAppInfo
	ShowSelectedEvents(pInfo);

	return true;
};
