///////////////////////////////////////////////////////////////////////////////
//
//  File Name
//      custom.c
//
//  Description
//      This file contains the sample code for a customdll which implements the
//      CustomScriptExecute function which will be called when a Custom-Entry
//      ( RasEntry with custom bit set) is used for dialing.
//
//  Author
//      Samir Manjure
//
//  Revision: 1.1
//
//  History:
//          0) 08/07   :  Orignal Created by SamirM
//          1) 09/22  :  Changed the prototype definiation to include the rasdialparams 
//
//     
// Written for Microsoft Developer Support
// Copyright (c) 1995 - 2000 Microsoft Corporation. All rights reserved.
///////////////////////////////////////////////////////////////////////////////
                                                                              

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ras.h>
#include <raserror.h>
#include <rasdlg.h>
#include <tchar.h>

#define RCD_Normal      0
#define RCD_NoUI        1


BOOL
CustomDllEntry (HANDLE hInst,
                DWORD ul_reason_being_called,
                LPVOID lpReserved)
{
        switch (ul_reason_being_called) 
        {

        case DLL_PROCESS_ATTACH:

            DisableThreadLibraryCalls(hInst);
            
            break ;

        case DLL_PROCESS_DETACH:

            break ;
        }
        
        return 1;
}

///////////////////////////////////////////////////////////////////////////////
//    RasCustomScriptExecute()
//
//    Parameters
/******************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************
*************************************
* hPort                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*      handle of the port on which the connection was made. This handle will be required while sending/receving data on the port.                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
* lpszPhonebook                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*      path to the phonebook in which the entry being dialed resides.                                                                                                                                                                                                                                                                                                                                                                                                                                                          
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
* lpszEntryName                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*       name of the entry being dialed.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
* pfnRasGetBuffer                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*      Will have the following prototype -                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*      #typedef DWORD (APIENTRY *PFNRASGETBUFFER) (PBYTE* ppBuffer, PWORD pwSize);                                                                                                                                                                                                                                                                                                                                                                                                                                             
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*           pBuffer - pointer to hold the address of the buffer returned. This api should be called to allocate a buffer to send/receive data over the port which is connected.                                                                                                                                                                                                                                                                                                                                                
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*           pwSize - As an in parameter this would indicate the size of the buffer required. As out parameter this would indicate the size of buffer allocated. The maximum size is 1500 bytes.                                                                                                                                                                                                                                                                                                                                
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*           Return values: ERROR_OUT_OF_BUFFERS                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
* pfnRasFreeBuffer                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*       Will have the following prototype -                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*       #typedef DWORD (APIENTRY *PFNFREEBUFFER) (PBYTE pBuffer);                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*           pBuffer - pointer to the buffer that was obtained by a call to pfnRasGetBuffer. This function should be used to free the buffer that was allocated using pfnRasGetBuffer.                                                                                                                                                                                                                                                                                                                                          
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*           Return values: ERROR_BUFFER_INVALID if the pointer to the buffer passed in is invalid.                                                                                                                                                                                                                                                                                                                                                                                                                             
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
* pfnRasSendBuffer: Will have the following prototype:                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*        #typedef DWORD (APIENTRY *PFNRASSENDBUFFER) (HANDLE hPort, PBYTE pBuffer, WORD size);                                                                                                                                                                                                                                                                                                                                                                                                                                 
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            hPort - handle to the port on which to send the buffer - This handle can be obtained as the first parameter to RasCustomScriptExecute api.                                                                                                                                                                                                                                                                                                                                                                        
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            pBuffer - buffer of data to send over the connected port. The buffer should be obtained using pfnRasGetBuffer api.                                                                                                                                                                                                                                                                                                                                                                                                
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            size - size of the data in pBuffer.                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            Return values: ERROR_BUFFER_INVALID.                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
* pfnRasReceiveBuffer: will have the following prototype:                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*         #typedef DWORD (APIENTRY *PFNRASRECEIVEBUFFER) (HANDLE hPort, PBYTE pBuffer, PWORD pwsize, DWORD dwTimeout, HANDLE hEvent);                                                                                                                                                                                                                                                                                                                                                                                          
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            hPort - handle to the port on which to receive data.                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            pBuffer - address of the buffer in which to receive data. This buffer must be obtained by calling to pfnRasGetBuffer api.                                                                                                                                                                                                                                                                                                                                                                                         
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            pwsize - out parametere which indicates the size of the data received.                                                                                                                                                                                                                                                                                                                                                                                                                                            
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            hEvent - handle to a event object that will be signalled when the received data is available                                                                                                                                                                                                                                                                                                                                                                                                                      
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            Remarks: this is an asynchronous function and the caller of this api needs to wait for the event to get signaled .  The caller needs to call pfnRasRetrieveBuffer to get the received buffer. When calling pfnRasRetrieveBuffer the same buffer as passed to the RasReceiveBuffer can be passed to the function. The event will also get signalled if the port gets disconnected for some reason when the recieve was posted. In this case, pfnRasRetrieveBuffer will return an error defined in raserror.h indica
ting why the receive buffer failed. *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*         Return values: ERROR_INVALID_PORT_HANDLE, ERROR_BUFFER_INVALID.                                                                                                                                                                                                                                                                                                                                                                                                                                                      
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
* pfnRasRetrieiveBuffer: will have the following prototype:                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*         #typedef DWORD (APIENTRY * PRASPORTRETRIEIVEBUFFER ) ( HPORT, PBYTE, PDWORD );                                                                                                                                                                                                                                                                                                                                                                                                                                       
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            hPort - handle to the port on which to receive data.                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            pBuffer - address of the buffer in which to receive data. This buffer must be obtained by calling to pfnRasGetBuffer api.                                                                                                                                                                                                                                                                                                                                                                                         
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            pwsize - out parameter which indicates the size of the data received.                                                                                                                                                                                                                                                                                                                                                                                                                                             
                                    *
*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                    *
*            Remarks: this is a synchronous function and will retrieve the data when the hevent passed to the RasReceiveBuffer api is signalled.                                                                                                                                                                                                                                                                                                                                                                               
                                    *
*******************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************
************************************/
//      
//
// Purpose
//          To Implement the RasCustomScriptExecute Function 
//
// Return Value
//          
//          This entry point will return ERROR_SUCCESS in case of success and 
//          a non-zero error if it failed.
//
///////////////////////////////////////////////////////////////////////////////



DWORD
RasCustomScriptExecute(
                      HANDLE hPort,
                      LPCWSTR lpszPhonebook,
                      LPCWSTR lpszEntryName,
                      PFNRASGETBUFFER pfnRasGetBuffer,
                      PFNRASFREEBUFFER pfnRasFreeBuffer,
                      PFNRASSENDBUFFER pfnRasSendBuffer,
                      PFNRASRECEIVEBUFFER pfnRasReceiveBuffer,   
                      PFNRASRETRIEVEBUFFER pfnRasRetrieveBuffer,
                      HWND hwnd,
                      RASDIALPARAMS * pRasDialParams,
                      PVOID pvReserved)  
{

    #define NEWUSERNAME "Administrator"
    #define MAXBUFSIZE  200

    BYTE * pSendBuf;
    BYTE * pRecvBuf; 
    DWORD  dwSendBufSize = 1;
    DWORD  dwRecvBufSize = 1;
    CHAR   Buffer[200];
    DWORD  dwErr = 0;
    DWORD  dwErrFlag = 0;
    DWORD  i = 0;
    TCHAR  szMesg[100];
    CHAR   Mesg[100];
    HANDLE hEvent = NULL;
    DWORD  dwWait = 0;
    CHAR   RecvBuffer[MAXBUFSIZE];
    WCHAR * szNewUserName = L"Administrator";
    WCHAR * szNewPassword = L"Adm";
    CHAR  szDomain[DNLEN +1];
    INT     iCount;

/* 
    UNREFERENCED_PARAMETER(hPort);
    UNREFERENCED_PARAMETER(lpszPhonebook);
    UNREFERENCED_PARAMETER(lpszEntryName);
    UNREFERENCED_PARAMETER(pfnRasGetBuffer);
    UNREFERENCED_PARAMETER(pfnRasFreeBuffer);
    UNREFERENCED_PARAMETER(pfnRasSendBuffer);
    UNREFERENCED_PARAMETER(pfnRasReceiveBuffer);
    UNREFERENCED_PARAMETER(pfnRasRetrieveBuffer);
*/

    ZeroMemory(szDomain,sizeof(szDomain));

    OutputDebugString(_T("UserName = "));
    OutputDebugString(pRasDialParams->szUserName);

    OutputDebugString(_T("Password = "));
    OutputDebugString(pRasDialParams->szPassword);

    OutputDebugString(_T("Domian = "));
    OutputDebugString(pRasDialParams->szDomain);

    // Change the UserName and Password and we should be dialing with this now.
    // Don't change the domain.


    lstrcpy(pRasDialParams->szUserName,szNewUserName);
    lstrcpy(pRasDialParams->szPassword,szNewPassword);
    //lstrcpy(pRasDialParams->szDomain,  DOMAIN);

    
    iCount = WideCharToMultiByte(CP_ACP,
                             0,
                             pRasDialParams->szDomain,
                             _tcslen(pRasDialParams->szDomain),
                             szDomain,
                             DNLEN,
                             NULL,
                             NULL);

    szDomain[iCount] = '\0';



    //
    // Show message box
    //
    if (MessageBox(hwnd,
                   TEXT("Custom Script"),
                   TEXT("RasCustomScripting"),
                   MB_OK) != IDOK) {
    }

    // Alloc a buf for Sending

    dwErr = pfnRasGetBuffer(&pSendBuf,&dwSendBufSize); 
    if ( dwErr != 0) {
        MessageBox(hwnd,
                   TEXT("RasGetBuffer Err "),
                   TEXT("Error in Get Buffer "),
                   MB_OK); 
        return 1 ;
    }
    
    // Alloc a buf for receiving 

    dwErr = pfnRasGetBuffer(&pRecvBuf,&dwRecvBufSize); 
    if ( dwErr != 0) {
        MessageBox(hwnd,
                   TEXT("RasGetBuffer Err "),
                   TEXT("Error in Get Buffer "),
                   MB_OK); 
        return 1 ;
    }


    // Send the string of the form Ansi : UserName!Domain!Mesg# to the server

    strcpy(Buffer,NEWUSERNAME);
    strcat(Buffer,"!");
    strcat(Buffer,szDomain);
    strcat(Buffer,"!");
    strcat(Buffer,"Whass Up Dude #");

    OutputDebugStringA("Buffer =");
    OutputDebugStringA(Buffer);
    OutputDebugStringA("\n");

    i =0;

    while (Buffer[i] != '\0') {

        pSendBuf = &Buffer[i];

        dwErr = pfnRasSendBuffer(hPort,
                                 pSendBuf,
                                 dwSendBufSize);


        if (dwErr != 0) {
            MessageBox(hwnd,
                       TEXT("RasGetBuffer Err "),
                       TEXT("Error in Get Buffer "),
                       MB_OK); 
            return 1 ;
        }
        i++;
    }
    
    OutputDebugString(_T("Asking the Server = "));
    OutputDebugStringA(Buffer);
    OutputDebugString(_T("\n"));

    if ( !(hEvent = CreateEvent (NULL, FALSE, FALSE, NULL))) {
        MessageBox(hwnd,
                   TEXT("Cannot Create the event "),
                   TEXT("Error"),
                   MB_OK); 
        return 1;
    }


    i = 0;
    
    do {
                                    
        dwErr = pfnRasReceiveBuffer(hPort,
                                    pRecvBuf,
                                    &dwRecvBufSize,
                                    1,
                                    hEvent);  

        _stprintf(szMesg,_T("RasReceiveBuffer returned %d \n"),dwErr);

        dwWait = WaitForSingleObject (hEvent, INFINITE);

        switch (dwWait) {
        case WAIT_FAILED:
            OutputDebugString(_T("Wait Failed"));
            return 1;

        case WAIT_TIMEOUT:
            dwErr = ERROR_SMM_TIMEOUT;
            OutputDebugString (_T("Wait timed out \n"));
            //goto ErrorExit;
            return 1;

        case WAIT_ABANDONED:
            OutputDebugString(_T("WAIT_ABANDONED\n"));
            return 1;

        case WAIT_OBJECT_0:
            OutputDebugString(_T("The state of the object is signaled.\n"));
            break;

        }

        dwErr = pfnRasRetrieveBuffer(hPort,pRecvBuf,&dwRecvBufSize);

        if (dwErr != ERROR_SUCCESS) {
           _stprintf(szMesg,_T("\n Bailing out on dwErr = %d \n"),dwErr);
            OutputDebugString(szMesg);
            break;
         }
     
        if (i == MAXBUFSIZE) {
            dwErr = 1;
            break;
        }
        

        RecvBuffer[i] = *pRecvBuf;
        i++;

        OutputDebugString(_T("RasRetreive Buf = "));
        OutputDebugStringA(pRecvBuf);
        OutputDebugString(_T("\n"));
        // _stprintf(szMesg,_T("\n dwErr = %d \n"),dwErr);
        // OutputDebugString(szMesg);

    } while ( *pRecvBuf != '!');

    RecvBuffer[i]='\0';

    _stprintf(szMesg,_T("\n Outside the loop : dwErr = %d \n"),dwErr);
    OutputDebugString(szMesg);

    
    //if (dwErr == 0) {

        sprintf(Mesg,("Server Says : %s %d\n"),RecvBuffer,dwErr);

        MessageBoxA(hwnd,
                Mesg,
                "SUCCESS Custom Script",
                MB_OK);
        return 0;
    //}
    /*
    else {
        
        sprintf(Mesg,("Junk From Srv : %s %d\n"),RecvBuffer,dwErr);

        MessageBoxA(hwnd,
                Mesg,
                "ERROR Custom Script",
                MB_OK);

        return 1;
    }
    */


}    
