///////////////////////////////////////////////////////////////////////////////
//
//  File Name
//      customsrv.cpp
//
//  Description
//      This file contains the initialization functions for the DLL library
//      and for the Security Host protocol. The NT RAS manager will call into
//      our DLL when a dialing user needs to be validated.
//
//  Author
//      SamirM
//
//  Revision: 1.1
//            09/23 - Made some miscelleous changes.
//
//  History:
//          Adopted the code from rashost.cpp for 3rd party security and
//          added hacks for it here and there.      
//
//  Purpose :
//          This file is to be used with the customdial dll to 
//          demonstrate the data exchange between the client and
//          server ( Custom Stuff) before PPP kicks in.
//
// Written for Microsoft Developer Support
// Copyright (c) 1995 - 2000 Microsoft Corporation. All rights reserved.
//

#include "customsrv.H"
#include <stdio.h>


HINSTANCE                       ghLibHandle = NULL;
RASSECURITYDIALOGSENDPROC       gpfnSendProc = NULL;
RASSECURITYDIALOGRECEIVEPROC    gpfnReceiveProc = NULL;

///////////////////////////////////////////////////////////////////////////////
//    DllMain()
//
//    Parameters
//      { Refer to the Win32 SDK documentation for DLL entry points }
//
//    Purpose
//      Entry point of this DLL
//
//    Return Value
//      TRUE if the DLL should proceed with the dwReason case, FALSE otherwise.
//
BOOL APIENTRY DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    if (DLL_PROCESS_DETACH == dwReason && ghLibHandle)
    {
        FreeLibrary (ghLibHandle);
    }
    return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
//    RasSecurityDialogBegin()
//
//    Parameters
//      hPort       Handle to the COM port where the user is logging in
//                  (A RAS handle, not a standard handle)
//      pSendBuf    Pointer to a buffer where we can copy stuff to be sent
//                  over the wire
//      SendBufSize Size of the outgoing buffer
//      pRecvBuf    Pointer a buffer where stuff is received from the
//                  remote client machine
//      RecvBufSize Size of the incoming buffer
//      RasSecurityDialogComplete   Pointer to a callback function we must
//                  call after we have completed our validation, indicating
//                  the RAS manager weather or not we granted access to the
//                  caller.
//
//    Purpose
//      This is the entry point for our security DLL. When the RAS manager
//      receives a call from a user, after it does its user validation, it
//      will call into us at this entry point to allow us to do extra
//      validation.
//      NOTE: It is very important that this function does not BLOCK. If
//            it does, the RAS manager will be block and no other calls
//            will be accepted. That is why we copy the incoming
//            parameters into a private structure and then spawn a thread
//            to do the actual validation work.
//            The passed parameters will be valid until we call the
//            ending function.
//
//    Return Value
//      ERROR_SUCCESS is we were able to start the validation. Otherwise
//      return and error from WINERROR.H or RASERROR.H
//
DWORD WINAPI RasSecurityDialogBegin (HPORT hPort,
                                     PBYTE pSendBuf,
                                     DWORD SendBufSize,
                                     PBYTE pRecvBuf,
                                     DWORD RecvBufSize,
                                     VOID  (WINAPI *RasSecurityDialogComplete)(SECURITY_MESSAGE*))
{
    OutputDebugString("RasSecurityDialogBegin\n");

    // Initialize the global pointer to the entry points in the RAS manager
    // DLL. I use these entry points to send and receive data to the remote
    // client machine. These functions will send and receive RAW buffers of
    // data to the other machine just before PPP-framing starts.
    // These functions have not been exported in any publish import library
    // so we must do a dynamic binding to them.
    if (NULL == ghLibHandle)
    {
        ghLibHandle = LoadLibrary ("RASMAN.DLL");
        if (NULL == ghLibHandle)
        {
            return ERROR_DLL_NOT_FOUND;
        }
    }
    // Obtain the send and received entry points from the RAS manager DLL.
    if (NULL == gpfnSendProc)
    {
        gpfnSendProc = (RASSECURITYDIALOGSENDPROC)GetProcAddress (ghLibHandle, TEXT("RasSecurityDialogSend"));
        if (NULL == gpfnSendProc)
        {
            return ERROR_PROC_NOT_FOUND;
        }
    }
    if (NULL == gpfnReceiveProc)
    {
        gpfnReceiveProc = (RASSECURITYDIALOGRECEIVEPROC)GetProcAddress (ghLibHandle, TEXT("RasSecurityDialogReceive"));
        if (NULL == gpfnReceiveProc)
        {
            return ERROR_PROC_NOT_FOUND;
        }
    }


    // Save the parameters passed and give them to the working thread
    // that will handle the authentication of the caller. The thread
    // should release this memory.
    // The parameters passed to use should be valid until we call the
    // dialog end function or until we get call in the termination
    // dialog entry point by the RAS system supervisor (the RAS manager)
    PWORK_THREAD_DATA pCallData = (PWORK_THREAD_DATA)HeapAlloc (GetProcessHeap(),
                                                                HEAP_ZERO_MEMORY,
                                                                sizeof(WORK_THREAD_DATA));
    if (NULL == pCallData)
    {
        return ERROR_OUTOFMEMORY;
    }
    // Initialize the members.
    pCallData->hPort = hPort;
    pCallData->pSendBuf = pSendBuf;
    pCallData->SendBufSize = SendBufSize;
    pCallData->pRecvBuf = pRecvBuf;
    pCallData->RecvBufSize = RecvBufSize;
    pCallData->pfnSecurityDialogEnd = RasSecurityDialogComplete;

    // For each call, spawn a working thread that will make the neccesary
    // authentication of the dial-up caller. We should never block the call
    // to RasSecurityDialogBegin(). If we do so, RAS will also block and no
    // more call would be accepted.
    DWORD dwThreadID;
    HANDLE hThread = CreateThread (NULL,
                                   0,
                                   (LPTHREAD_START_ROUTINE)CallWorkerThread,
                                   (LPVOID)pCallData,
                                   0,
                                   &dwThreadID);
    if (NULL == hThread)
    {
        // Call GetLastError() before calling HeapFree().
        DWORD dwError = GetLastError();
        HeapFree (GetProcessHeap(), 0, pCallData);
        return dwError;
    }

    OutputDebugString("Returning ERROR_SUCCESS from RasSecurityDialogBegin\n");
    return ERROR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
//    RasSecurityDialogEnd()
//
//    Parameters
//      hPort   Handle to the COM port (A RAS handle, not a standard handle)
//
//    Purpose
//      Stub function. Need to export this by the security DLL even if
//      not needed. We need to return non-zero to indicate RAS we are no
//      longer responsible for the port connection. It will take care
//      of the rest.
//
//    Return Value
//      ERROR_PORT_DISCONNECTED always
//
DWORD WINAPI RasSecurityDialogEnd (HPORT hPort)
{
    OutputDebugString("RasSecurityDialogEnd\n");
    return ERROR_PORT_DISCONNECTED;
}

///////////////////////////////////////////////////////////////////////////////
//    CallWorkerThread()
//
//    Parameters
//      pCallData   Pointer to the data structure with the data for the
//                  instance we are handling.
//
//    Purpose
//      This is the function for the thread that interacts with a dialing RAS
//      user. Here we query the user for its identity and based on it we
//      compute a challenge to for it. Once the response from the client
//      is received, we validate it and decide wether or not we allow access.
//
//    Return Value
//      None
//
void WINAPI CallWorkerThread (PWORK_THREAD_DATA pCallData)
{
    // Initialize the appropiate structures
    CHAR                szTemp [256];       // Needed for OutputDebugString only
    SECURITY_MESSAGE    smResult = { 0 };
    RASHOST_DATA        HostData = { 0 };
    DWORD i =0;
    DWORD j =0;

    OutputDebugString("CallWorkerThread.\n");

    smResult.hPort = pCallData->hPort;
    smResult.dwError =  0;

    // Set UserName to something which will fail validation in case they don't
    // enter anything at all.
    lstrcpy (smResult.UserName, TEXT("(RASHOST - Unknown)"));

    ZeroMemory (pCallData->pRecvBuf, pCallData->RecvBufSize);
    //dwBytes = sizeof(RASHOST_DATA);

    // Set size value
    HostData.dwSize = sizeof(RASHOST_DATA);

    // Create an event to wait for client responses
    if ( !(hEvent = CreateEvent (NULL, FALSE, FALSE, NULL)))
    {
        wsprintf (szTemp, "CreateEvent failed: %d\n", GetLastError());
        OutputDebugString (szTemp);
        return;
    }
    else {
        wsprintf(szTemp, "Event %d created.\n", hEvent);
        OutputDebugString (szTemp);
    }

    /***** Commented all the above *****/

    // Fetch the user's input.  Return will be non-zero if the user enters a string.
    pCallData->RecvBufSize = GetClientResponse(pCallData->hPort, pCallData->pRecvBuf);

    if(pCallData->RecvBufSize > 0) {
        // Copy the client data from the incoming buffer to the data structure
        //CopyMemory (HostData.szUserName, pCallData->pRecvBuf, pCallData->RecvBufSize);

        i=0;
        j=0;

        // Copy the userName
        while (pCallData->pRecvBuf[i] != '!') {
            smResult.UserName[j] = pCallData->pRecvBuf[i];
            i++;
            j++;
            
        }
        smResult.UserName[j]='\0';
        OutputDebugString("UserName = ");
        OutputDebugString(smResult.UserName);
        // Copy the domain
        j = 0;
        i++;
        while (pCallData->pRecvBuf[i] != '!') {
            smResult.Domain[j] = pCallData->pRecvBuf[i];
            i++;
            j++;
        }
        smResult.Domain[j]='\0';
        OutputDebugString("Domain= ");
        OutputDebugString(smResult.Domain);
    }
    else {
        // This will cause the RAS server to fail the authentication.
        lstrcpy (smResult.UserName, TEXT("(RASHOST - Unknown)"));
    }

    // Now send back the string "nothin much".
    // pCallData->SendBufSize = sizeof("Nothin Much Dude !");

    CopyMemory (pCallData->pSendBuf, "Nothin Much Dude !", pCallData->SendBufSize);

    // Send the prompt to the user
    gpfnSendProc (pCallData->hPort, pCallData->pSendBuf, (WORD)pCallData->SendBufSize);
    OutputDebugString ("Sending the data to client");

 
    //lstrcpy (smResult.Domain, TEXT(""));
    OutputDebugString("UserName = ");
    OutputDebugString(smResult.UserName);

    OutputDebugString("Domain = ");
    OutputDebugString(smResult.Domain);

    smResult.dwMsgId = SECURITYMSG_SUCCESS;

    // Release the synchronization objects
    CloseHandle (hEvent);

    // Tell the RAS manager we are finished by calling the END dialog funcition.
    pCallData->pfnSecurityDialogEnd (&smResult);

    // Free the memory of this call instance before exiting the thread
    HeapFree (GetProcessHeap(), 0, pCallData);
}


///////////////////////////////////////////////////////////////////////////////
//    ValidateCallingUser()
//
//    Parameters
//      pData               Pointer to the host data structure
//      pfAccessGranted     We return TRUE here is access is granted.
//                          FALSE otherwise.
//
//    Purpose
//      Here we validate the answer to the challenge sent to the client.
//
//    Return Value
//      ERROR_SUCCESS if successful. Otherwiser an error code from WINERROR.H
//      or RASERROR.H
//
//    THIS FUNCION IS NOT BEING CALLED ANYWHERE CURRENTLY BUT PROVIDED
//    JUST SO THAT 3rd party can write custom authentication mechanism

DWORD WINAPI ValidateCallingUser (PRASHOST_DATA       pData,
                                  BOOL *              pfAccessGranted)
{
    DWORD dwResult = ERROR_SUCCESS;
    *pfAccessGranted = FALSE;


    // Do stuff here

    // Increased security wouldn't hurt.  Currently, if username starts with 'e',
    // they get in.  Wouldn't be too hard to read from a file or registry to validate
    // users.
    if(pData->szUserName[0] == 'e') {
        *pfAccessGranted = TRUE;
    }

    return dwResult;
}




/*
 *  Common code to handle fetching user input.  We need to have the reponse return from
 *  the terminal window every byte, since we don't know exactly how long the input
 *  will be.  With each character returned, check for a '\n' to see if the user is
 *  finished.  If they are, get a count of the total number of characters entered and
 *  return that, after setting Buffer.  If we don't read a '\n', add the character to
 *  the end of the buffer we're building up.
 *
 *  gpfnReceiveProc has a non-obvious feature(?).  It is the value for dwBytes.
 *  You need to set this when you call the routine.  Set it to the number of bytes
 *  you want back from RAS.  You don't set this to the buffer size.  After WaitForSingleObject
 *  returns, dwBytes will have the number of bytes copied into the buffer.  My guess is
 *  dwBytes should always be sent as 1, and will always be 1 upon return.
 *
 *  Improvements for those with free time:
 *      - Echo back the letters as the user types them
 *
 *  History:
 *      24-Jan-97   EricCh  Original.
 *      9/22        Samirm  Made Miscellenous Changes.
 */
DWORD GetClientResponse(HPORT hPort, PBYTE Buffer)
{
    static int     iChar;                   // Count of characters in user's entry.
    static DWORD   dwBytes;
    static DWORD   dwWait;
    static DWORD   dwError;
    static char    szTemp[256] = {0};       // Used for OutputDebugString only
    static char    szHoldBuffer[256] = {0}; // Holds the user input string as it's built up.


    iChar = 0;
    szHoldBuffer[0] = '\0';

    do {
        // Reset dwBytes so we only get 1 byte back
        dwBytes = 1;

        // Wait for an answer from the client responder
        dwError = gpfnReceiveProc (hPort,
                                   Buffer,
                                   (WORD *)&dwBytes,
                                   0,
                                   hEvent);

        wsprintf(szTemp, "gpfnReceiveProc returned: %d\n", dwError);
        OutputDebugString(szTemp);

        OutputDebugString("Calling WaitForSingleObject.\n");
        dwWait = WaitForSingleObject (hEvent, INFINITE);

        switch (dwWait) {
            case WAIT_FAILED:
                wsprintf (szTemp, "WaitForSingleObject failed: %d\n", GetLastError());
                OutputDebugString (szTemp);
                return 0;

            case WAIT_TIMEOUT:
                dwError = ERROR_SMM_TIMEOUT;
                OutputDebugString ( "Wait timed out \n");
                //goto ErrorExit;
                return 0;

            case WAIT_ABANDONED:
                OutputDebugString("WAIT_ABANDONED\n");
                return 0;

            case WAIT_OBJECT_0:
                OutputDebugString("The state of the object is signaled.\n");
                break;

        }

        // Save this character 
        szHoldBuffer[iChar++] = Buffer[0];

        wsprintf(szTemp, "Buffer= %c\n", Buffer[0]);
        OutputDebugString(szTemp);

    } while(Buffer[0] != '#');

    // Null terminate the string
    szHoldBuffer[iChar] = '\0';

    // Now copy the string back into the buffer
    CopyMemory (Buffer, &szHoldBuffer, iChar);

    wsprintf(szTemp, "Returning Buffer: %s\n", Buffer);
    OutputDebugString(szTemp);

    wsprintf(szTemp, "Returning size: %d\n", iChar);
    OutputDebugString(szTemp);

    return iChar;

}   /* End of 'GetClientResponse' */
