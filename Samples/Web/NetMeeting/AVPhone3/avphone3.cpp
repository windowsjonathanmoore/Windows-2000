//****************************************************************************
//  Module:     AVPHONE3.EXE     
//  File:       AVPHONE3.CPP
//  Content:    
//              
//
//  Copyright (c) Microsoft Corporation 1995 - 2000
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF 
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO 
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A 
// PARTICULAR PURPOSE.
//****************************************************************************

// avphone3.cpp : Defines the entry point for the application.
//

#include "precomp.h"
POINT GetAnchorPoint(HWND hWndDlg, UINT dlgitem);

CComModule _Module;

#define MAX_LOADSTRING 100
#define MAX_SZ 200

HWND g_hwndEdit;
HWND g_hwndBut;
HINSTANCE ghInst;
HWND g_hWndRemote;
HWND g_hWndLocal;

struct NmInitStruct
{
	WORD wSize;
	OLECHAR str[MAX_PATH];
};

	// szMode is the parameter that we pass to the atl host window
	// this is used by ATL to create stream object and the control
	// get's it's initialization from the stream object
	// The possable mode parameter values are:
	// 
	//  Full- The full netmeeting UI
	//	DataOnly- The data-only view of the NetMeeting UI
	//	PreviewOnly- The preview(local) video window only
	//	RemoteOnly- The default remote video window only
	//	PreviewNoPause- The preview(local) video window only with no buttons or frame
	//	RemoteNoPause- The remote video window only with no buttons or frame
	//	Telephone-  The dialpad view of NetMeeting

HWND CreateNetMeetingWindow(HWND hWndParent, int x, int y, LPCTSTR szMode)
{
	USES_CONVERSION;
		
	TCHAR szFormatModeString[MAX_PATH];
	wsprintf(szFormatModeString, _T("MODE=%s"), szMode);

	NmInitStruct nmis;
	nmis.wSize = sizeof(nmis.str);
	wcscpy(nmis.str, T2OLE(szFormatModeString));

	LPOLESTR strGUIDNetMeetingActiveXControl = NULL;
	StringFromCLSID(CLSID_NetMeeting, &strGUIDNetMeetingActiveXControl);

      HWND hWndCtl = 
		::CreateWindow("AtlAxWin",
			// Use ATL's string conversion routine to convert to a LPTSTR from an LPOLESTR
         OLE2T(strGUIDNetMeetingActiveXControl),
         WS_CHILD | WS_VISIBLE | WS_GROUP, 
		 x, 
		 y, 
		 0, 
		 0, 
		 hWndParent, 
		 NULL,
         ::GetModuleHandle(NULL), 
		 &nmis
		 );	

		// Remember to free memory given to you by StringFromCLSID
	CoTaskMemFree(strGUIDNetMeetingActiveXControl );

	if(hWndCtl)
	{
			// get the IUnknown for the video window (we want to get it's size)
		IUnknown* pUnk = NULL;
		HRESULT hr = AtlAxGetControl(hWndCtl, &pUnk);
		if(SUCCEEDED(hr))
		{
				// Now get the IOleObject interface for the netmeeting control
			IOleObject* pOleObjVideoWindow = NULL;
			hr = pUnk->QueryInterface(&pOleObjVideoWindow);
			if(SUCCEEDED(hr))
			{
					// get the Extent
				SIZEL sizel = {0, 0};
				hr = pOleObjVideoWindow->GetExtent(DVASPECT_CONTENT, &sizel);
				if(SUCCEEDED(hr))
				{
						// Convert the Extent from HIMETRIC to pixels.
					SIZEL sizeInPixels = {0, 0};
					AtlHiMetricToPixel(&sizel, &sizeInPixels);
					SetWindowPos(hWndCtl, NULL, 0, 0, sizeInPixels.cx, sizeInPixels.cy, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
				}

					// Don't forget to release interfaces!
				pOleObjVideoWindow->Release();
			}

				// Don't forget to release interfaces!
			pUnk->Release();
		}
	}

	return hWndCtl;
}


// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	ghInst=hInstance;
	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_AVPHONE3, szWindowClass, MAX_LOADSTRING);
	unsigned short i = MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_AVPHONE3);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	_Module.Term();

	CoUninitialize();

	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_AVPHONE3);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_3DFACE+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_AVPHONE3;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

	CoInitialize(NULL);

	// Initialize the ATL module		
	_Module.Init(NULL, hInst);

    //Initialize ATL control containment code.
    AtlAxWinInit();

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      0, 0, 360, 550, NULL, NULL, hInstance, NULL);

   
	TCHAR szBuff[256];
	::LoadString(hInstance, IDS_MACHINENAME, szBuff, 256);
	HWND hwndText = CreateWindowEx(0, _T("STATIC"), szBuff, 
					WS_VISIBLE|WS_CHILD|SS_LEFT,
					50, 5, 100, 20,
					hWnd, NULL, hInstance, NULL);

	::SendMessage(hwndText, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);

	g_hwndEdit = CreateWindowEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL, 
					WS_CHILD|WS_VISIBLE|WS_TABSTOP, 
					50,25,200,23,			//50, 450, 200, 23, 
					hWnd, NULL, hInstance, NULL);
	g_hwndBut = CreateWindowEx(0, _T("BUTTON"), "C&all", 
					WS_CHILD|WS_BORDER|WS_VISIBLE|WS_TABSTOP, 
					270, 20, 75, 30,			//270, 445, 75, 30, 
					hWnd, NULL, hInstance, NULL);
	

   if (!hWnd)
   {
      return FALSE;
   }



   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static Conf *pConf=NULL;

	if (!pConf)
	{
		pConf=new Conf(hWnd);
		
		if (FAILED(pConf->Initialize()))
		{
			MessageBox(NULL,"NetMeeting may not be installed","Initialization Failure",MB_OK);
			PostQuitMessage(0);
			return FALSE;
		}
		
		// Create the video window at the archor spot.		

		POINT pt = {50, 95};
		
		pConf->m_hWndLocal = CreateNetMeetingWindow(hWnd, pt.x, pt.y, _T("PreviewOnly"));

		POINT pt2 = {50,297};
		pConf->m_hWndRemote = CreateNetMeetingWindow(hWnd, pt2.x, pt2.y, _T("RemoteOnly"));
		
		CreateWindowEx(0, _T("STATIC"), "Local Video", 
					WS_VISIBLE|WS_CHILD|SS_LEFT,
					140, 250, 100, 20,
					hWnd, NULL, ghInst, NULL);
		CreateWindowEx(0, _T("STATIC"), "Remote Video", 
					WS_VISIBLE|WS_CHILD|SS_LEFT,
					140, 450, 100, 20,
					hWnd, NULL, ghInst, NULL);
		
	}

	
	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			if (g_hwndBut == (HWND) lParam)
			{
				if (!pConf->InConnection()) 
				{
					char szMachineName[MAX_SZ];
					GetWindowText(g_hwndEdit,szMachineName,MAX_SZ);
					pConf->Call(szMachineName);
					
				}
				else
				{
					pConf->HangUp();
					
				}
			}
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);

			// TODO: Add any drawing code here...

			RECT rt;
			GetClientRect(hWnd, &rt);
			EndPaint(hWnd, &ps);
			break;

		case WM_DESTROY:
			
			// When the last object to be released is an ActiveX object, conf.exe stays
			// around for a short time to ensure that all clients are done and no longer
			// interested in any of the ActiveX objects that NetMeeting serves.  For this
			// reason, we should free the ActiveX objects before we free the manager
			// object so NetMeeting goes away imedeately after we release the
			// manager object.  If we do this step after we free the manager object,
			// NetMeeting 3.0 will remain in memory for a short time. 
						
			if(IsWindow(pConf->m_hWndRemote))
			{
				DestroyWindow(pConf->m_hWndRemote);
			}

			if(IsWindow(pConf->m_hWndLocal))
			{
				DestroyWindow(pConf->m_hWndLocal);
			}


			// Hangup if in a call
			if (pConf->InConnection())
				pConf->HangUp();

			pConf->Uninitialize();
			delete pConf;
				PostQuitMessage(0);
			break;
	case WM_CONNECTING:
	case WM_CONNECTED:

		// Message from Conf object that a user is connected
		SetWindowText(g_hwndBut,"H&ang Up");
		break;
	
	case WM_DISCONNECTED:

		// Message from Conf object that a user disconnected or rejected call
		SetWindowText(g_hwndBut,"C&all");
		break;
	default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

POINT GetAnchorPoint(HWND hWndDlg, UINT dlgitem)
{
	HWND hWindowAnchor = GetDlgItem(hWndDlg, dlgitem);

	RECT rcAnchor = {0, 0, 0, 0};
	GetWindowRect(hWindowAnchor, &rcAnchor);

	POINT ptAnchor = {rcAnchor.left, rcAnchor.top};
	ScreenToClient(hWndDlg, &ptAnchor);

	return ptAnchor;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
