//****************************************************************************
//  Module:     PLUGTRANSPORT.EXE     
//  File:       UI.CPP
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


#include "precomp.h"


//*******************
// DEFINITIONS
//*******************

#define MAX_SZ          200
#define DEFAULTCOMPORT  "Com1"


//*******************
// GLOBALS
//*******************

HINSTANCE ghInst;


//**********************
//FUNCTION DECLARATIONS
//**********************

BOOL CALLBACK MainDlgProc(HWND hWnd,UINT uMsg, WPARAM wParam, LPARAM lParam);


//****************************************************************************
//
//    FUNCTION:   int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst, LPSTR szCmdLine, INT nCmdShow)
//
//    PURPOSE:    calls initialization function

//    COMMENTS:   Windows recognizes this function by name as the initial entry point 
//                for the program.  This function calls the application initialization 
//                routine.  
//      
//****************************************************************************

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst, LPSTR szCmdLine, INT nCmdShow)
{
    int iRes = 0;
    WSADATA wsa_data;
    WORD version_requested = MAKEWORD (1,1);

    // Initialize COM
    CoInitialize(NULL);
 
    ghInst = hInst;

    // Initialize windows sockets
    int error = ::WSAStartup(version_requested, &wsa_data);
    if (error) 
    {
        MessageBox(NULL, "WSAStartup failed", "Error", MB_OK);
        return -1;
    }

    // Load UI
    iRes = DialogBox(hInst,MAKEINTRESOURCE(IDD_PLUGTRANSPORT),NULL,(DLGPROC)MainDlgProc);

    // Terminate use of Windows sockets
    WSACleanup();

    // Uninitialize COM
    CoUninitialize();

    return iRes;
}


//****************************************************************************
//
//    FUNCTION:   BOOL CALLBACK MainDlgProc(HWND hWnd,UINT uMsg, WPARAM wParam, LPARAM lParam)
//
//    PURPOSE:    This function is called when the Main Dialog initializes.  
//                It sets up the initial interface pointers and updates 
//                the dialog accordingly
//    COMMENTS:
//
//        

//****************************************************************************

BOOL CALLBACK MainDlgProc(HWND hWnd,UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    static Conf *pConf = NULL;
    static CPluggableTransport *pPlugTrans = NULL;
    HRESULT hr = S_OK;

    switch (uMsg)
    {
    case WM_INITDIALOG:
    {
        pConf=new Conf(hWnd);

        if (!pConf)
        {
 	        MessageBox(NULL,"Not enough memory","Error",MB_OK);
	        EndDialog(hWnd,0);
	        return false;  
        }

        pPlugTrans = new CPluggableTransport();
        if (!pPlugTrans)
        {
 	        MessageBox(NULL,"Not enough memory","Error",MB_OK);
	        EndDialog(hWnd,0);
	        return false;  
        }

        // Initialize the NM part of the Conf object
        if (FAILED(pConf->Initialize()))
        {
 	        MessageBox(NULL,"NetMeeting cannot start","Error",MB_OK);
	        EndDialog(hWnd,0);
	        return false;
        }

        // Initialize the PluggableTransport part of the Conf object
        if (FAILED(pPlugTrans->Initialize(pConf->GetNmManager())))
        {
            MessageBox(NULL,"Plug cannot be initialized","Error",MB_OK);
	        EndDialog(hWnd,0);
	        return false;
        }

        // update UI
        SetDlgItemText(hWnd, ID_CALL, "&Call");
        SetDlgItemText(hWnd, ID_CONNECT, "Co&nnect");
        EnableWindow(GetDlgItem(hWnd, ID_CALL), false);
        EnableWindow(GetDlgItem(hWnd, ID_CONNECT), true);
        EnableWindow(GetDlgItem(hWnd, IDC_LISTEN), false);
        EnableWindow(GetDlgItem(hWnd, IDC_CONNECT), false);
        return true;
    }

    case WM_CLOSE:
    {
        // Hangup if in a call
        if (pConf->InCall())
        {
            pConf->HangUp();
        }

        // Close any connections of any kind that are still there
        if (pPlugTrans->InConnection())
        {
            pPlugTrans->CloseConnection(FRAMING_LEGACY_PSTN);
            pPlugTrans->CloseConnection(FRAMING_X224);
        }

        // Clear and delete Conf object
        pConf->Uninitialize();
        pPlugTrans->Uninitialize();
        delete pConf;
        delete pPlugTrans;
        EndDialog(hWnd, 0);
        return true;
    }

    case WM_CONNECTING:
    case WM_CONNECTED:
    {
	    // Message from Conf object that a user is connected
	    SetDlgItemText(hWnd,ID_CALL,"Han&gup");
	    return true;
    }

    case WM_DISCONNECTED:
    {
        // Message from Conf object that a user disconnected or rejected call
	    SetDlgItemText(hWnd,ID_CALL,"C&all");
        EnableWindow(GetDlgItem(hWnd, ID_CALL), false);
        EnableWindow(GetDlgItem(hWnd, IDC_LISTEN), false);
        EnableWindow(GetDlgItem(hWnd, IDC_CONNECT), false);
    
        // Close the connection
        SendMessage(hWnd, WM_COMMAND, ID_CONNECT, 0);
	    return true;
    }

    case WM_PLUGABLE_SOCKET:
    {
        ULONG event = WSAGETSELECTEVENT(lParam);
        // we don't need for this application but I leave it there for easy
        // access if anybody needs to handle these notifications

        // We get FD_CLOSE when the socket is closed by the remote site
        if (event & FD_CLOSE)
        {}
	
        //We get FD_READ when there is data available for us to read
	    if (event & FD_READ)
        {}

	    // We get FD_WRITE when there is space available to write data to WinSock
	    if (event & FD_WRITE)
	    {}

        // We get FD_CONNECT when connecting to a remote site
	    if (event & FD_CONNECT)
	    {}

        // We get FD_ACCEPT when a remote site is connecting with us
	    if (event & FD_ACCEPT)
	    {
            if (FAILED(pPlugTrans->AcceptConnection(hWnd)))
            {
                MessageBox(NULL, "Accept connection failed", "Error", MB_OK);
                return false;
            }
     
            // update UI
            SetDlgItemText(hWnd,ID_CONNECT,"&Disconnect");
            EnableWindow(GetDlgItem(hWnd, ID_CALL), true);
        }
        return true;
    }

    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDC_PSTN:
        {
            EnableWindow(GetDlgItem(hWnd, IDC_LISTEN), true);
            EnableWindow(GetDlgItem(hWnd, IDC_CONNECT), true);
            return true;
        }
        case IDC_X224:
        {
            EnableWindow(GetDlgItem(hWnd, IDC_LISTEN), true);
            EnableWindow(GetDlgItem(hWnd, IDC_CONNECT), true);
            // It seems that user wants to use X224. Let's create the listen socket 
            // in order to be ready to accept new connections
            if (BST_CHECKED == SendDlgItemMessage(hWnd, IDC_LISTEN, BM_GETCHECK, 0, 0))
            {
                if (FAILED(pPlugTrans->m_pX224->CreateListenSocket(hWnd)))
                {
                    MessageBox(hWnd, "Create listen socket failed", "Error", MB_OK);
                    return false;
                }
            }
            return true;
        }

        case ID_CALL:
        {
	        // If not in a call, then make a call, otherwise hang up.
	        if (!pConf->InCall()) 
            {
	            pConf->Call(pPlugTrans);
	            return true;
            }
	        else
            {
                // TO DO: Do I have to check for hr ???
	            pConf->HangUp();
	            return true;
            }
        }
        case ID_CONNECT:
        {
            // If not in a connection, then make a connection. otherwise close the connections
            if (!pPlugTrans->InConnection())
            {
                // get the machine name or the com port you are gonna use
                // It must always be something there
	            char szName[MAX_SZ];
	            GetDlgItemText(hWnd,IDC_NAME,szName,MAX_SZ);
                if (!lstrcmp(szName, ""))
                {
                    MessageBox(hWnd, "Enter a machine name to connect to or a com port to use", "Error", MB_OK);
                    return false;
                }
       
                if (BST_CHECKED == SendDlgItemMessage(hWnd, IDC_PSTN, BM_GETCHECK, 0, 0))
                {
                    if (BST_CHECKED == SendDlgItemMessage(hWnd, IDC_LISTEN, BM_GETCHECK, 0, 0))
                    {
                        // This is the case in which we use PSTN stack 
                        //and we are going to accept a connection
                        if (SUCCEEDED(pPlugTrans->AcceptConnection(szName)))
                        { 
                            SetDlgItemText(hWnd,ID_CONNECT,"&Disconnect");
                            EnableWindow(GetDlgItem(hWnd, ID_CALL), true);
                            return true;
                        }
                        return false;
                    }
 
                    if (BST_CHECKED == SendDlgItemMessage(hWnd, IDC_CONNECT, BM_GETCHECK, 0, 0))
                    {
                        // This is the case in which we use PSTN stack 
                        //and we are going to make a connection
                        if (SUCCEEDED(pPlugTrans->CreateConnection(szName)))
                        {
                            SetDlgItemText(hWnd,ID_CONNECT,"&Disconnect");
                            EnableWindow(GetDlgItem(hWnd, ID_CALL), true);
                            return true;
                        }
                        return false;
                    } 
                }

                if (BST_CHECKED == SendDlgItemMessage(hWnd, IDC_X224, BM_GETCHECK, 0, 0))
                {
                    if (BST_CHECKED == SendDlgItemMessage(hWnd, IDC_CONNECT, BM_GETCHECK, 0, 0))
                    {
                        // This is the case in which we use X224 stack 
                        //and we are going to create a connection

                        // Create the connect socket
                        if (FAILED(pPlugTrans->m_pX224->CreateConnectSocket(hWnd, szName)))
                        {
                            MessageBox(hWnd, "Create connect socket failed", "Error", MB_OK);
                            return false;
                        }

                        // Create the connection
                        if (SUCCEEDED(pPlugTrans->CreateConnection()))
                        {
                            SetDlgItemText(hWnd,ID_CONNECT,"&Disconnect");
                            EnableWindow(GetDlgItem(hWnd, ID_CALL), true);
                            return true;
                        }
                        return false;
                    } 
                }       
            }
            else
            {
                // close any connections of any kind
                pPlugTrans->CloseConnection(FRAMING_LEGACY_PSTN);
                pPlugTrans->CloseConnection(FRAMING_X224);
                SetDlgItemText(hWnd,ID_CONNECT,"&Connect");
                EnableWindow(GetDlgItem(hWnd, ID_CALL), false);
                EnableWindow(GetDlgItem(hWnd, IDC_LISTEN), false);
                EnableWindow(GetDlgItem(hWnd, IDC_CONNECT), false);
                return true;
            }      
      
        return false;
        }

        case IDC_LISTEN:
        {
            if (BST_CHECKED == SendDlgItemMessage(hWnd, IDC_X224, BM_GETCHECK, 0, 0))
            {
                // It seems that the user wants to use X224. Let's create the listen socket 
                // in order to be ready to accept new connections
                SendDlgItemMessage (hWnd, IDC_NAME, WM_SETTEXT, 0, (LPARAM)(LPSTR) pPlugTrans->m_pX224->SetAndGetHostName());
                if (FAILED(pPlugTrans->m_pX224->CreateListenSocket(hWnd)))
                {
                    MessageBox(hWnd, "Create listen socket failed", "Error", MB_OK);
                    return false;
                }
            }

            if (BST_CHECKED == SendDlgItemMessage(hWnd, IDC_PSTN, BM_GETCHECK, 0, 0))
            {
                // It seems that the user wants to use PSTN. Let's show him the default 
                // com port
                SendDlgItemMessage (hWnd, IDC_NAME, WM_SETTEXT, 0, (LPARAM)(LPSTR) DEFAULTCOMPORT);
            }

            return true;
        }
        }
     }
    default:
    {
        return false;
    }
    }
}