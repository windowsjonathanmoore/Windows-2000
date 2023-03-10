// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (C) 1999 - 2000  Microsoft Corporation.  All Rights Reserved.
//
// Module Name: spi.cpp
//
// Description:
//
//    This sample illustrates how to develop a layered service provider that is
//    capable of counting all bytes transmitted through an IP socket. The application
//    reports when sockets are created and reports how many bytes were sent and
//    received when a socket closes. The results are reported using the OutputDebugString
//    API which will allow you to intercept the I/O by using a debugger such as cdb.exe
//    or you can monitor the I/O using dbmon.exe.
//
//    This file contains the 30 SPI functions you are required to implement in a
//    service provider. It also contains the two functions that must be exported
//    from the DLL module DllMain and WSPStartup.
//    

#include "provider.h"
#include "install.h"

//
// Globals used across files
//
CRITICAL_SECTION    gCriticalSection,
                    gOverlappedCS;
WSPUPCALLTABLE      MainUpCallTable;
HINSTANCE           hDllInstance = NULL;

LPPROVIDER          gBaseInfo = NULL;
INT                 gLayerCount=0;      // Number of base providers we're layered over

HANDLE              hLspHeap=NULL;


void FreeSocketsAndMemory(int *lpErrno);

//
// Need to keep track of which PROVIDERs that are currently executing
//  a blocking Winsock call on a per thread basis.
//
#define SetBlockingProvider(Provider)       \
    (TlsIndex!=0xFFFFFFFF)                  \
        ? TlsSetValue (TlsIndex, Provider)  \
        : NULL

//
// Globals local to this file
//
static DWORD               TlsIndex=0xFFFFFFFF;
static DWORD               gEntryCount = 0;    // how many times WSPStartup has been called
static DWORD               gLayerCatId = 0;    // Catalog ID of our dummy entry
static WSPDATA             gWSPData;
static WSPPROC_TABLE       gProcTable;
static BOOL                bDetached=FALSE;

static TCHAR Msg[512];                         // For outputting debug messages

//
// External variables for extension functions (defined in extension.cpp)
//
extern LPFN_TRANSMITFILE lpfnProviderTransmitFile;
extern LPFN_ACCEPTEX     lpfnProviderAcceptEx;

void PrintProcTable(LPWSPPROC_TABLE lpProcTable)
{
    wsprintf(Msg, TEXT("WSPAccept = 0x%X\r\n"),
        lpProcTable->lpWSPAccept);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPAddressToString = 0x%X\r\n"),
        lpProcTable->lpWSPAddressToString);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPAsyncSelect = 0x%X\r\n"),
        lpProcTable->lpWSPAsyncSelect);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPBind = 0x%X\r\n"),
        lpProcTable->lpWSPBind);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPCancelBlockingCall = 0x%X\r\n"),
        lpProcTable->lpWSPCancelBlockingCall);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPCleanup = 0x%X\r\n"),
        lpProcTable->lpWSPCleanup);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPCloseSocket = 0x%X\r\n"),
        lpProcTable->lpWSPCloseSocket);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPConnect = 0x%X\r\n"),
        lpProcTable->lpWSPConnect);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPDuplicateSocket = 0x%X\r\n"),
        lpProcTable->lpWSPDuplicateSocket);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPAccept = 0x%X\r\n"),
        lpProcTable->lpWSPEnumNetworkEvents);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPEventSelect = 0x%X\r\n"),
        lpProcTable->lpWSPEventSelect);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPGetOverlappedResult = 0x%X\r\n"),
        lpProcTable->lpWSPGetOverlappedResult);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPGetPeerName = 0x%X\r\n"),
        lpProcTable->lpWSPGetPeerName);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPGetSockOpt = 0x%X\r\n"),
        lpProcTable->lpWSPGetSockOpt);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPGetSockName = 0x%X\r\n"),
        lpProcTable->lpWSPGetSockName);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPGetQOSByName = 0x%X\r\n"),
        lpProcTable->lpWSPGetQOSByName);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPIoctl = 0x%X\r\n"),
        lpProcTable->lpWSPIoctl);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPJoinLeaf = 0x%X\r\n"),
        lpProcTable->lpWSPJoinLeaf);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPListen = 0x%X\r\n"),
        lpProcTable->lpWSPListen);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPRecv = 0x%X\r\n"),
        lpProcTable->lpWSPRecv);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPRecvDisconnect = 0x%X\r\n"),
        lpProcTable->lpWSPRecvDisconnect);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPRecvFrom = 0x%X\r\n"),
        lpProcTable->lpWSPRecvFrom);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPSelect = 0x%X\r\n"),
        lpProcTable->lpWSPSelect);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPSend = 0x%X\r\n"),
        lpProcTable->lpWSPSend);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPSendDisconnect = 0x%X\r\n"),
        lpProcTable->lpWSPSendDisconnect);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPSendTo = 0x%X\r\n"),
        lpProcTable->lpWSPSendTo);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPSetSockOpt = 0x%X\r\n"),
        lpProcTable->lpWSPSetSockOpt);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPShutdown = 0x%X\r\n"),
        lpProcTable->lpWSPShutdown);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPSocket = 0x%X\r\n"),
        lpProcTable->lpWSPSocket);
    OutputDebugString(Msg);
    wsprintf(Msg, TEXT("WSPStringToAddress = 0x%X\r\n"),
        lpProcTable->lpWSPStringToAddress);
    OutputDebugString(Msg);
}

int VerifyProcTable(LPWSPPROC_TABLE lpProcTable)
{
   if ( lpProcTable->lpWSPAccept &&
        lpProcTable->lpWSPAddressToString &&
        lpProcTable->lpWSPAsyncSelect &&
        lpProcTable->lpWSPBind &&
        lpProcTable->lpWSPCancelBlockingCall &&
        lpProcTable->lpWSPCleanup &&
        lpProcTable->lpWSPCloseSocket &&
        lpProcTable->lpWSPConnect &&
        lpProcTable->lpWSPDuplicateSocket &&
        lpProcTable->lpWSPEnumNetworkEvents &&
        lpProcTable->lpWSPEventSelect &&
        lpProcTable->lpWSPGetOverlappedResult &&
        lpProcTable->lpWSPGetPeerName &&
        lpProcTable->lpWSPGetSockOpt &&
        lpProcTable->lpWSPGetSockName &&
        lpProcTable->lpWSPGetQOSByName &&
        lpProcTable->lpWSPIoctl &&
        lpProcTable->lpWSPJoinLeaf &&
        lpProcTable->lpWSPListen &&
        lpProcTable->lpWSPRecv &&
        lpProcTable->lpWSPRecvDisconnect &&
        lpProcTable->lpWSPRecvFrom &&
        lpProcTable->lpWSPSelect &&
        lpProcTable->lpWSPSend &&
        lpProcTable->lpWSPSendDisconnect &&
        lpProcTable->lpWSPSendTo &&
        lpProcTable->lpWSPSetSockOpt &&
        lpProcTable->lpWSPShutdown &&
        lpProcTable->lpWSPSocket &&
        lpProcTable->lpWSPStringToAddress)
    {
        return NO_ERROR;
    }
    return SOCKET_ERROR;
}

//
// Function: DllMain
//
// Description:
//    Provides initialization when the LSP DLL is loaded. In our case we simply,
//    initialize some critical sections used throughout the DLL.
//
BOOL WINAPI DllMain(IN HINSTANCE hinstDll, IN DWORD dwReason, LPVOID lpvReserved)
{
    switch (dwReason)
    {

        case DLL_PROCESS_ATTACH:
            hDllInstance = hinstDll;
            //
            // Initialize some critical section objects 
            //
            InitializeCriticalSection(&gCriticalSection);
            InitializeCriticalSection(&gOverlappedCS);

            TlsIndex = TlsAlloc();
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;

        case DLL_PROCESS_DETACH:
            bDetached = TRUE;

            EnterCriticalSection(&gCriticalSection);
            if (gBaseInfo)
            {
                int Error;

                FreeSocketsAndMemory(&Error);
            }
            LeaveCriticalSection(&gCriticalSection);

            DeleteCriticalSection(&gCriticalSection);
            DeleteCriticalSection(&gOverlappedCS);

            if (lpvReserved == NULL)
            {
                if (TlsIndex != 0xFFFFFFFF)
                {
                    TlsFree(TlsIndex);
                    TlsIndex = 0xFFFFFFFF;
                }
            }
            break;
    }

    return TRUE;
}

//
// Function: WSPAccept
//
// Description:
//    Handle the WSAAccept function. The only special consideration here is the
//    conditional accept callback. You can choose to intercept this by substituting
//    your own callback (you'll need to keep track of the user supplied callback so
//    you can trigger that once your substituted function is triggered).
//
SOCKET WSPAPI WSPAccept (
    SOCKET          s,                      
    struct sockaddr FAR * addr,  
    LPINT           addrlen,                 
    LPCONDITIONPROC lpfnCondition,  
    DWORD_PTR       dwCallbackData,          
    LPINT           lpErrno)
{
    SOCKET     NewProviderSocket;
    SOCKET     NewSocket = INVALID_SOCKET;
    SOCK_INFO *NewSocketContext;
    SOCK_INFO *SocketContext;

    // Query for our per socket info
    //
    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
                s, 
                (PDWORD_PTR) &SocketContext, 
                lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPAccept: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        return INVALID_SOCKET;
    }

    //
    // Note: You can subsitute your own conditional accept callback function
    //       in order to intercept this callback. You would have to keep track
    //       of the user's callback function so that you can call that when
    //       your intermediate function executes.
    //
    SetBlockingProvider(SocketContext->Provider);
    NewProviderSocket = SocketContext->Provider->NextProcTable.lpWSPAccept(
                            SocketContext->ProviderSocket, 
                            addr, 
                            addrlen,
                            lpfnCondition, 
                            dwCallbackData, 
                            lpErrno);
    SetBlockingProvider(NULL);
    if (NewProviderSocket != INVALID_SOCKET)
    {
        // The underlying provider received a new connection so lets create our own
        //  socket to pass back up to the application.
        //
        if ((NewSocketContext = CreateSockInfo(SocketContext->Provider,
                                              NewProviderSocket,
                                              SocketContext)) == NULL)
        {
            *lpErrno = WSAENOBUFS;
        }
        else
        {
            if ((NewSocket = MainUpCallTable.lpWPUCreateSocketHandle(
                    SocketContext->Provider->LayeredProvider.ProtocolChain.ChainEntries[0], 
                    (DWORD_PTR) NewSocketContext, 
                    lpErrno)) == INVALID_SOCKET)
            {
                wsprintf(Msg, TEXT("WSPAccept(): WPUCreateSocketHandle() failed: %d\r\n"),
                    *lpErrno);
                OutputDebugString(Msg);
            }

            NewSocketContext->LayeredSocket = NewSocket;

            #ifdef DEBUG
            wsprintf(Msg, TEXT("Creating socket %d\r\n"), NewSocket);
            OutputDebugString(Msg);
            #endif
        }
    }

    return NewSocket;
}

//
// Function: WSPAdressToString
//
// Description:
//    Convert an address to string. We simly pass this to the lower provider.
//
int WSPAPI WSPAddressToString(
    LPSOCKADDR          lpsaAddress,            
    DWORD               dwAddressLength,               
    LPWSAPROTOCOL_INFOW lpProtocolInfo,   
    LPWSTR              lpszAddressString,            
    LPDWORD             lpdwAddressStringLength,   
    LPINT               lpErrno)
{
    WSAPROTOCOL_INFOW *pInfo=NULL;
    PROVIDER          *Provider=NULL;
    INT                i, ret;

    // First find the appropriate provider
    //
    for(i=0; i < gLayerCount ;i++)
    {
        if ((gBaseInfo[i].NextProvider.iAddressFamily == lpProtocolInfo->iAddressFamily) &&
            (gBaseInfo[i].NextProvider.iSocketType == lpProtocolInfo->iSocketType) && 
            (gBaseInfo[i].NextProvider.iProtocol   == lpProtocolInfo->iProtocol))
        {
            Provider = &gBaseInfo[i];
            pInfo = &gBaseInfo[i].NextProvider;
            break;
        }
    }
    if (Provider == NULL)
    {
        *lpErrno = WSAEINVAL;
        return SOCKET_ERROR;
    }
    // Of course if the next layer isn't a base just pass down lpProtocolInfo.
    //
    if (pInfo->ProtocolChain.ChainLen != BASE_PROTOCOL)
    {
        pInfo = lpProtocolInfo;
    }
   
    SetBlockingProvider(Provider);
    ret = Provider->NextProcTable.lpWSPAddressToString(lpsaAddress, 
                                                       dwAddressLength,               
                                                       pInfo, 
                                                       lpszAddressString, 
                                                       lpdwAddressStringLength, 
                                                       lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPAsyncSelect
//
// Description:
//    Register specific Winsock events with a socket. We need to substitute
//    the app socket with the provider socket and use our own hidden window.
//
int WSPAPI WSPAsyncSelect (
    SOCKET       s,
    HWND         hWnd,
    unsigned int wMsg,
    long         lEvent,
    LPINT        lpErrno)
{
    SOCK_INFO *SocketContext;
    HWND       hWorkerWindow;
    INT        ret;

    // Make sure the window handle is valid
    //
    ret = SOCKET_ERROR;
    if (IsWindow(hWnd))
    {
        // Verify only valid events have been set
        //
        if ( (lEvent & ~FD_ALL_EVENTS) == 0)
        {
            // Find our provider socket corresonding to this one
            //
            if (MainUpCallTable.lpWPUQuerySocketHandleContext(
                s, 
                (PDWORD_PTR)&SocketContext, 
                lpErrno) != SOCKET_ERROR)
            {
                SocketContext->hWnd = hWnd;
                SocketContext->uMsg = wMsg;

                // Get the handle to our hidden window
                //
                if ((hWorkerWindow = GetWorkerWindow()) != NULL)
                {
                    SetBlockingProvider(SocketContext->Provider);
                    ret = SocketContext->Provider->NextProcTable.lpWSPAsyncSelect(
                               SocketContext->ProviderSocket, 
                               hWorkerWindow, 
                               WM_SOCKET, 
                               lEvent, 
                               lpErrno);
                    SetBlockingProvider(NULL);
                }
                else
                {
                    *lpErrno = WSAEINVAL;
                }
            }
            else
            {
                wsprintf(Msg, TEXT("WSPAsyncSelect: WPUQuerySocketHandleContext() failed: %d\r\n"),
                    *lpErrno);
                OutputDebugString(Msg);

                *lpErrno = WSAENOTSOCK;
            }
        }
        else
        {
            *lpErrno = WSAEINVAL;
        }
    }
    else
    {
        *lpErrno = WSAEINVAL;
    }

    return ret;
}

//
// Function: WSPBind
//
// Description:
//    Bind the socket to a local address. We just map socket handles and
//    call the lower provider.
//
int WSPAPI WSPBind(
    SOCKET                s,
    const struct sockaddr FAR * name,
    int                   namelen,
    LPINT                 lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPBind: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }
    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPBind(
        SocketContext->ProviderSocket, 
        name, 
        namelen, 
        lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPCancelBlockingCall
//
// Description:
//    This call cancels any blocking Winsock call in the current thread only.
//    For every Winsock call that blocks we use thread local storage (TLS) to
//    store a pointer to the provider on which the blocking call was issued.
//    This is necessary since WSACancelBlockingCall takes no arguments (i.e.
//    the LSP needs to keep track of what calls are blocking).
//
int WSPAPI WSPCancelBlockingCall(
    LPINT lpErrno)
{
    PROVIDER *Provider=NULL;
    INT       ret = NO_ERROR;

    Provider = (PROVIDER *)TlsGetValue(TlsIndex);
    if (!Provider)
    {
        ret = Provider->NextProcTable.lpWSPCancelBlockingCall(lpErrno);
    }
    return ret;
}

// 
// Function: WSPCleanup
//
// Description:
//    Decrement the entry count. If equal to zero then we can prepare to have us
//    unloaded. Close any outstanding sockets and free up allocated memory.
//
int WSPAPI WSPCleanup (
    LPINT lpErrno  
    )
{
    int        ret=NO_ERROR;

    if (bDetached)
        return NO_ERROR;

    EnterCriticalSection(&gCriticalSection);

    if (!gEntryCount)
    {
        *lpErrno = WSANOTINITIALISED;
        OutputDebugString(TEXT("WSPCleanup returning WSAENOTINITIALISED\r\n"));
        LeaveCriticalSection(&gCriticalSection);
        return SOCKET_ERROR;
    }
    // Decrement the entry count
    //
    gEntryCount--;

    #ifdef DEBUG
    wsprintf(Msg, TEXT("WSPCleanup: %d\n"), gEntryCount);
    OutputDebugString(Msg);
    #endif

    if (gEntryCount == 0)
    {
        OutputDebugString("WSPCleanup: gEntryCount == 0; cleaning up\r\n");
        StopAsyncWindowManager();
        StopOverlappedManager();

        Sleep(200);

        FreeSocketsAndMemory(lpErrno);
    }
    LeaveCriticalSection(&gCriticalSection);

    return ret;
}

//
// Function: WSPCloseSocket
//
// Description:
//    Close the socket handle of the app socket as well as the provider socket.
//    However, if there are outstanding async IO requests on the app socket
//    we only close the provider socket. Only when all the IO requests complete
//    (with error) will we then close the app socket (this will occur in
//    the overlapped manager - overlapp.cpp).
//
int WSPAPI WSPCloseSocket(  
    SOCKET s,        
    LPINT  lpErrno
)
{
    SOCK_INFO *SocketContext;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR)&SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPCloseSocket: WPUQuerySocketHandle() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }
    //
    // If we there are outstanding async calls on this handle don't close the app
    //  socket handle...only close the provider's handle.  Therefore any errors
    //  incurred can be propogated back to the app socket.
    //
    if (SocketContext->dwOutstandingAsync != 0)
    {
        SocketContext->bClosing = TRUE;

        if (SocketContext->Provider->NextProcTable.lpWSPCloseSocket(
                SocketContext->ProviderSocket, 
                lpErrno) == SOCKET_ERROR) 
        {
            *lpErrno = WSAENOTSOCK;
            return SOCKET_ERROR;
        }
        return NO_ERROR;
    }
    //
    // Close the provider socket
    //
    SetBlockingProvider(SocketContext->Provider);
    if (SocketContext->Provider->NextProcTable.lpWSPCloseSocket(
            SocketContext->ProviderSocket, 
            lpErrno) == SOCKET_ERROR) 
    {
        SetBlockingProvider(NULL);
        return SOCKET_ERROR;
    }
    SetBlockingProvider(NULL);

    //
    // Remove the socket info
    //
    RemoveSocketInfo(SocketContext->Provider, SocketContext);
    //
    // Close the app socket
    //
    if (MainUpCallTable.lpWPUCloseSocketHandle(s, lpErrno) == SOCKET_ERROR)
        return SOCKET_ERROR;

    
    #ifdef DEBUG
    wsprintf(Msg, TEXT("Closing socket %d Bytes Sent [%lu] Bytes Recv [%lu]\r\n"), 
        s, SocketContext->BytesSent, SocketContext->BytesRecv);
    OutputDebugString(Msg);
    #endif

    DeleteCriticalSection(&SocketContext->SockCritSec);
    HeapFree(hLspHeap, 0, SocketContext);

    return NO_ERROR;
}

//
// Function: WSPConnect
//
// Description:
//    Performs a connect call. The only thing we need to do is translate
//    the socket handle.
//
int WSPAPI WSPConnect (
    SOCKET                s,
    const struct sockaddr FAR * name,
    int                   namelen,
    LPWSABUF              lpCallerData,
    LPWSABUF              lpCalleeData,
    LPQOS                 lpSQOS,
    LPQOS                 lpGQOS,
    LPINT                 lpErrno
)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext
            (s, 
             (PDWORD_PTR) &SocketContext, 
             lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPConnect: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPConnect(
                SocketContext->ProviderSocket, 
                name, 
                namelen, 
                lpCallerData, 
                lpCalleeData,
                lpSQOS, 
                lpGQOS, 
                lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPDuplicateSocket
//
// Description:
//    This function provides a WSAPROTOCOL_INFOW structure which can be passed
//    to another process to open a handle to the same socket. First we need
//    to translate the user socket into the provider socket and call the underlying
//    WSPDuplicateSocket. Note that the lpProtocolInfo structure passed into us
//    is an out parameter only!
//
int WSPAPI WSPDuplicateSocket(
    SOCKET              s,
    DWORD               dwProcessId,                      
    LPWSAPROTOCOL_INFOW lpProtocolInfo,   
    LPINT               lpErrno)
{
    PROVIDER          *Provider=NULL;
    SOCK_INFO         *SocketContext=NULL;
    DWORD              dwReserved;
    int                ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext
            (s, 
             (PDWORD_PTR) &SocketContext, 
             lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPDuplicateSocket: WPUQuerySocketHandle() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }
    // Find the underlying provider
    //
    Provider = SocketContext->Provider;

    SetBlockingProvider(Provider);
    ret = Provider->NextProcTable.lpWSPDuplicateSocket(
                SocketContext->ProviderSocket,
                dwProcessId,
                lpProtocolInfo,
                lpErrno);
    SetBlockingProvider(NULL);
    if (ret == NO_ERROR)
    {
        // We want to return the WSAPROTOCOL_INFOW structure of the underlying
        // provider but we need to preserve the reserved info returned by the
        // WSPDuplicateSocket call.
        //
        dwReserved = lpProtocolInfo->dwProviderReserved;
        memcpy(lpProtocolInfo, &Provider->NextProvider, sizeof(WSAPROTOCOL_INFOW));
        lpProtocolInfo->dwProviderReserved = dwReserved;
    }
    return ret;    
}

//
// Function: WSPEnumNetworkEvents
//
// Description:
//    Enumerate the network events for a socket. We only need to translate the
//    socket handle.
//
int WSPAPI WSPEnumNetworkEvents(  
    SOCKET             s,
    WSAEVENT           hEventObject,
    LPWSANETWORKEVENTS lpNetworkEvents,
    LPINT              lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPEnumNetworkEvents: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPEnumNetworkEvents(
                SocketContext->ProviderSocket,                             
                hEventObject, 
                lpNetworkEvents, 
                lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPEventSelect
//
// Description:
//    Register the specified events on the socket with the given event handle.
//    All we need to do is translate the socket handle.
//
int WSPAPI WSPEventSelect(
    SOCKET   s,
    WSAEVENT hEventObject,
    long     lNetworkEvents,
    LPINT    lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPEventSelect: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }
    
    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPEventSelect(
                SocketContext->ProviderSocket, 
                hEventObject,
                lNetworkEvents, 
                lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPGetOverlappedResult
//
// Description:
//    This function reports whether the specified overlapped call has
//    completed. If it has, return the requested information. If not,
//    and fWait is true, wait until completion. Otherwise return an
//    error immediately.
//
BOOL WSPAPI WSPGetOverlappedResult (
    SOCKET          s,
    LPWSAOVERLAPPED lpOverlapped,
    LPDWORD         lpcbTransfer,
    BOOL            fWait,
    LPDWORD         lpdwFlags,
    LPINT           lpErrno)
{
    DWORD ret;

    s;
    if (lpOverlapped->Internal != WSS_OPERATION_IN_PROGRESS) 
    {
        // Operation has completed, update the parameters and return 
        //
        *lpcbTransfer = (DWORD)lpOverlapped->InternalHigh;
        *lpdwFlags = (DWORD)lpOverlapped->OffsetHigh;
        *lpErrno = (INT)lpOverlapped->Offset;

        return (lpOverlapped->Offset == 0 ? TRUE : FALSE);
    }
    else
    {
        // Operation is still in progress
        //
        if (fWait) 
        {
            // Wait on the app supplied event handle. Once the operation
            //  is completed the IOCP or completion routine will fire.
            //  Once that is handled, WPUCompleteOverlappedRequest will
            //  be called which will signal the app event.
            //
            ret = WaitForSingleObject(lpOverlapped->hEvent, INFINITE);
            if ( (ret == WAIT_OBJECT_0) &&
                 (lpOverlapped->Internal != WSS_OPERATION_IN_PROGRESS) )
            {
                *lpcbTransfer = (DWORD)lpOverlapped->InternalHigh;
                *lpdwFlags = (DWORD)lpOverlapped->OffsetHigh;
                *lpErrno = (INT)lpOverlapped->Offset;
                    
                return(lpOverlapped->Offset == 0 ? TRUE : FALSE);
            }
            else if (lpOverlapped->Internal == WSS_OPERATION_IN_PROGRESS)
                *lpErrno = WSA_IO_PENDING;
            else 
                *lpErrno = WSASYSCALLFAILURE;
        }
        else 
            *lpErrno = WSA_IO_INCOMPLETE;
    }
    return FALSE;
}

//
// Function: WSPGetPeerName
//
// Description:
//    Returns the address of the peer. The only thing we need to do is translate
//    the socket handle.
//
int WSPAPI WSPGetPeerName(  
    SOCKET          s,
    struct sockaddr FAR * name,
    LPINT           namelen,
    LPINT           lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPGetPeerName: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPGetPeerName(
                SocketContext->ProviderSocket, 
                name,
                namelen, 
                lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPGetSockName
//
// Description:
//    Returns the local address of a socket. All we need to do is translate
//    the socket handle.
//
int WSPAPI WSPGetSockName(
    SOCKET          s,
    struct sockaddr FAR * name,
    LPINT           namelen,
    LPINT           lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPGetSockName: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPGetSockName(
                SocketContext->ProviderSocket, 
                name,
                namelen, 
                lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPGetSockOpt
//
// Description:
//    Get the specified socket option. All we need to do is translate the
//    socket handle.
//
int WSPAPI WSPGetSockOpt(
    SOCKET     s,
    int        level,
    int        optname,
    char FAR * optval,
    LPINT      optlen,
    LPINT      lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret=NO_ERROR;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPGetSockOpt: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }
    //
    // We need to capture this and return our own WSAPROTOCOL_INFO structure.
    // Otherwise, if we translate the handle and pass it to the lower provider
    // we'll return the lower provider's protocol info!
    //
    if ((level == SOL_SOCKET) && ((optname == SO_PROTOCOL_INFO) ||
                                  (optname == SO_PROTOCOL_INFOA) ||
                                  (optname == SO_PROTOCOL_INFOW) ))
    {
        if ((optname == SO_PROTOCOL_INFOW) && (*optlen >= sizeof(WSAPROTOCOL_INFOW)))
        {
            // No conversion necessary, just copy the data
            memcpy(optval, 
                   &SocketContext->Provider->LayeredProvider, 
                   sizeof(WSAPROTOCOL_INFOW));
        }
        else if ((optname == SO_PROTOCOL_INFOA) && (*optval >= sizeof(WSAPROTOCOL_INFOA)))
        {
            // Copy everything but the string
            memcpy(optval,
                   &SocketContext->Provider->LayeredProvider,
                   sizeof(WSAPROTOCOL_INFOW)-WSAPROTOCOL_LEN+1);
            // Convert our saved UNICODE string to ASCII
            WideCharToMultiByte(CP_ACP,
                                0,
                                SocketContext->Provider->LayeredProvider.szProtocol,
                                -1,
                                ((WSAPROTOCOL_INFOA *)optval)->szProtocol,
                                WSAPROTOCOL_LEN+1,
                                NULL,
                                NULL);
        }
        else
        {
            *lpErrno = WSAEFAULT;
            ret = SOCKET_ERROR;
        }
    }
    else
    {
        SetBlockingProvider(SocketContext->Provider);
        ret = SocketContext->Provider->NextProcTable.lpWSPGetSockOpt(
                    SocketContext->ProviderSocket, 
                    level,
                    optname, 
                    optval, 
                    optlen, 
                    lpErrno);
        SetBlockingProvider(NULL);
    }

    return ret;
}

//
// Function: WSPGetQOSByName
//
// Description:
//    Get a QOS template by name. All we need to do is translate the socket
//    handle.
//
BOOL WSPAPI WSPGetQOSByName(
    SOCKET   s,
    LPWSABUF lpQOSName,
    LPQOS    lpQOS,
    LPINT    lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPGetQOSByName: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPGetQOSByName(
                SocketContext->ProviderSocket, 
                lpQOSName,
                lpQOS, 
                lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPIoctl
//
// Description:
//    Invoke an ioctl. In most cases, we just need to translate the socket
//    handle. However, if the dwIoControlCode is SIO_GET_EXTENSION_FUNCTION_POINTER,
//    we'll need to intercept this and return our own function pointers when
//    they're requesting either TransmitFile or AcceptEx. This is necessary so
//    we can trap these calls. Also for PnP OS's (Win2k) we need to trap calls
//    to SIO_QUERY_TARGET_PNP_HANDLE. For this ioctl we simply have to return 
//    the provider socket.
//
int WSPAPI WSPIoctl(
    SOCKET          s,
    DWORD           dwIoControlCode,
    LPVOID          lpvInBuffer,
    DWORD           cbInBuffer,
    LPVOID          lpvOutBuffer,
    DWORD           cbOutBuffer,
    LPDWORD         lpcbBytesReturned,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
    LPWSATHREADID   lpThreadId,
    LPINT           lpErrno)
{
    LPWSAOVERLAPPEDPLUS ProviderOverlapped;
    SOCK_INFO          *SocketContext;
    GUID                AcceptExGuid = WSAID_ACCEPTEX;
    GUID                TransmitFileGuid = WSAID_TRANSMITFILE;
    GUID                GetAcceptExSockAddrsGuid = WSAID_GETACCEPTEXSOCKADDRS;
    int                 ret=NO_ERROR;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext,
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPIoctl: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    if (dwIoControlCode == SIO_GET_EXTENSION_FUNCTION_POINTER)
    {
        // Check to see which extension function is being requested.
        //
        if (memcmp (lpvInBuffer, &TransmitFileGuid, sizeof (GUID)) == 0)
        {
            // Return a pointer to our intermediate extesion function
            //
            *((LPFN_TRANSMITFILE *)lpvOutBuffer) = ExtTransmitFile;
            //
            // Attempt to load the lower provider's extension function
            //
            if (!lpfnProviderTransmitFile)
            {
                SetBlockingProvider(SocketContext->Provider);
                ret = SocketContext->Provider->NextProcTable.lpWSPIoctl(
                        SocketContext->ProviderSocket,
                        SIO_GET_EXTENSION_FUNCTION_POINTER,
                        &TransmitFileGuid,
                        sizeof(GUID),
                        (LPVOID) &lpfnProviderTransmitFile,
                        sizeof(LPFN_TRANSMITFILE),
                        lpcbBytesReturned,
                        NULL, 
                        NULL, 
                        NULL,
                        lpErrno);
                SetBlockingProvider(NULL);
                return ret;
            }
            else
                return NO_ERROR;
        }
        else if (memcmp(lpvInBuffer, &AcceptExGuid, sizeof(GUID)) == 0)
        {
            // Return a pointer to our intermediate extension function
            //
            *((LPFN_ACCEPTEX *)lpvOutBuffer) = ExtAcceptEx;
            //
            // Attempt to load the lower provider's extension function
            //
            if (!lpfnProviderAcceptEx)
            {
                SetBlockingProvider(SocketContext->Provider);
                ret = SocketContext->Provider->NextProcTable.lpWSPIoctl(
                        SocketContext->ProviderSocket,
                        SIO_GET_EXTENSION_FUNCTION_POINTER,
                        &AcceptExGuid,
                        sizeof(GUID),
                        (LPVOID) &lpfnProviderAcceptEx,
                        sizeof(LPFN_ACCEPTEX),
                        lpcbBytesReturned,
                        NULL,
                        NULL,
                        NULL,
                        lpErrno);
                SetBlockingProvider(NULL);
                return ret;
            }
            else
                return NO_ERROR;
        }
        else if (memcmp (lpvInBuffer, &GetAcceptExSockAddrsGuid, sizeof (GUID)) == 0)
        {
            // No socket handle translation needed, let the call pass through below
            // (i.e. we really don't have any need to intercept this call)
        }
        else 
        {
            *lpErrno = WSAEINVAL;
            return SOCKET_ERROR;
        }
    }
    else if (dwIoControlCode == SIO_QUERY_TARGET_PNP_HANDLE)
    {
        #ifdef DEBUG
        OutputDebugString(TEXT("SIO_QUERY_PNP_HANDLE requested\r\n"));
        #endif

        *((SOCKET *)lpvOutBuffer) = SocketContext->ProviderSocket;
        *lpcbBytesReturned = sizeof(SocketContext->ProviderSocket);

        if (lpOverlapped)
        {
            ProviderOverlapped = GetOverlappedStructure(SocketContext);

            ProviderOverlapped->lpCallerOverlapped = lpOverlapped;
            CopyOffset(&ProviderOverlapped->ProviderOverlapped, lpOverlapped);
            ProviderOverlapped->SockInfo           = SocketContext;
            ProviderOverlapped->CallerSocket       = s;
            ProviderOverlapped->ProviderSocket     = SocketContext->ProviderSocket;
            ProviderOverlapped->Error              = NO_ERROR;
            ProviderOverlapped->Operation          = LSP_OP_IOCTL;
            ProviderOverlapped->lpCallerThreadId   = lpThreadId;
            ProviderOverlapped->lpCallerCompletionRoutine   = lpCompletionRoutine;
            ProviderOverlapped->Provider = SocketContext->Provider;

            lpOverlapped->Internal = (DWORD_PTR)lpCompletionRoutine;
            lpOverlapped->InternalHigh = *lpcbBytesReturned;

            //
            // Call the completion routine immediately since there is nothing
            //  else to do. For this ioctl all we do is return the provider
            //  socket. If it was called overlapped just complete the operation.
            //

            #ifdef DEBUG
            OutputDebugString(TEXT("SIO_QUERY_PNP_HANDLE overlapped\r\n"));
            #endif

            IntermediateCompletionRoutine(0,
                                         *lpcbBytesReturned,
                                         (WSAOVERLAPPED *)ProviderOverlapped,
                                          0);
        }

        return NO_ERROR;
    }
    //
    // Check for overlapped I/O
    // 
    if (lpOverlapped)
    {
        ProviderOverlapped = GetOverlappedStructure(SocketContext);
        if (!ProviderOverlapped)
            OutputDebugString(TEXT("WSPIoctl: GetOverlappedStructure() returned NULL\r\n"));

        ProviderOverlapped->lpCallerOverlapped = lpOverlapped;
        CopyOffset(&ProviderOverlapped->ProviderOverlapped, lpOverlapped);
        ProviderOverlapped->SockInfo           = SocketContext;
        ProviderOverlapped->CallerSocket       = s;
        ProviderOverlapped->ProviderSocket     = SocketContext->ProviderSocket;
        ProviderOverlapped->Error              = NO_ERROR;
        ProviderOverlapped->Operation          = LSP_OP_IOCTL;
        ProviderOverlapped->lpCallerThreadId   = lpThreadId;
        ProviderOverlapped->lpCallerCompletionRoutine   = lpCompletionRoutine;
        ProviderOverlapped->IoctlArgs.dwIoControlCode   = dwIoControlCode;
        ProviderOverlapped->IoctlArgs.lpvInBuffer       = lpvInBuffer;
        ProviderOverlapped->IoctlArgs.cbInBuffer        = cbInBuffer;
        ProviderOverlapped->IoctlArgs.lpvOutBuffer      = lpvOutBuffer;
        ProviderOverlapped->IoctlArgs.cbOutBuffer       = cbOutBuffer;
        ProviderOverlapped->IoctlArgs.lpcbBytesReturned = lpcbBytesReturned;
        ProviderOverlapped->Provider = SocketContext->Provider;

        ret = QueueOverlappedOperation(ProviderOverlapped, SocketContext);

        if (ret != NO_ERROR)
        {
            *lpErrno = ret;
        }
    }
    else
    {
        SetBlockingProvider(SocketContext->Provider);
        ret = SocketContext->Provider->NextProcTable.lpWSPIoctl(
                SocketContext->ProviderSocket, 
                dwIoControlCode, 
                lpvInBuffer,
                cbInBuffer, 
                lpvOutBuffer, 
                cbOutBuffer, 
                lpcbBytesReturned, 
                lpOverlapped, 
                lpCompletionRoutine, 
                lpThreadId, 
                lpErrno);
        SetBlockingProvider(NULL);
    }

    return ret;
}

//
// Function: WSPJoinLeaf
//
// Description:
//    This function joins a socket to a multipoint session. For those providers
//    that support multipoint semantics there are 2 possible behaviors. First,
//    for IP, WSAJoinLeaf always returns the same socket handle which was passed
//    into it. In this case there is no new socket so we don't want to create
//    any socket context once the lower provider WSPJoinLeaf is called. In the
//    second case, for ATM, a new socket IS created when we call the lower
//    provider. In this case we do want to create a new user socket and create
//    a socket context.
//
SOCKET WSPAPI WSPJoinLeaf(
    SOCKET       s,
    const struct sockaddr FAR * name,
    int          namelen,
    LPWSABUF     lpCallerData,
    LPWSABUF     lpCalleeData,
    LPQOS        lpSQOS,
    LPQOS        lpGQOS,
    DWORD        dwFlags,
    LPINT        lpErrno)
{
    SOCK_INFO *SocketContext;
    SOCKET     NextProviderSocket = INVALID_SOCKET,
               NewSocket = INVALID_SOCKET;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPJoinLeaf: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return INVALID_SOCKET;
    }

    SetBlockingProvider(SocketContext->Provider);
    NextProviderSocket = SocketContext->Provider->NextProcTable.lpWSPJoinLeaf(
            SocketContext->ProviderSocket,                           
            name, 
            namelen, 
            lpCallerData, 
            lpCalleeData, 
            lpSQOS, 
            lpGQOS, 
            dwFlags,                        
            lpErrno);
    SetBlockingProvider(NULL);
    //    
    // If the socket returned from the lower provider is the same as the socket
    //  passed into it then there really isn't a new socket - just return. 
    //  Otherwise, a new socket has been created and we need to create the socket
    //  context and create a user socket to pass back.
    //
    if (NextProviderSocket != SocketContext->ProviderSocket)
    {
        SOCK_INFO *NewSocketContext;

        // Create a new socket context structure
        //
        if ((NewSocketContext = CreateSockInfo(SocketContext->Provider,
                                               NextProviderSocket,
                                               SocketContext)) == NULL)
        {
            *lpErrno = WSAENOBUFS;
        }
        else
        {
            // Create a socket handle to pass to app
            //
            NewSocket = MainUpCallTable.lpWPUCreateSocketHandle(
                        SocketContext->Provider->LayeredProvider.ProtocolChain.ChainEntries[0],
                        (DWORD_PTR)NewSocketContext,
                        lpErrno);
            if (NewSocket == INVALID_SOCKET)
            {
                wsprintf(Msg, TEXT("WSPJoinLeaf: WPUCreateSocketHandle() failed: %d\r\n"),
                    *lpErrno);
                OutputDebugString(Msg);
                HeapFree(hLspHeap, 0, NewSocketContext);

                *lpErrno = WSAENOBUFS;
                return INVALID_SOCKET;
            }
            NewSocketContext->LayeredSocket = NewSocket;
        }
        return NewSocket;
    }
    else
    {
        return s;
    }
}

//
// Function: WSPListen
//
// Description:
//    This function sets the backlog value on a listening socket. All we need to
//    do is translate the socket handle to the correct provider.
//
int WSPAPI WSPListen(
    SOCKET s,        
    int    backlog,     
    LPINT  lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPListen: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPListen(
                SocketContext->ProviderSocket, 
                backlog, 
                lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPRecv
//
// Description:
//    This function receives data on a given socket and also allows for asynchronous
//    (overlapped) operation. First translate the socket handle to the lower provider
//    handle and then make the receive call. If called with overlap, post the operation
//    to our IOCP or completion routine.
//
int WSPAPI WSPRecv(
    SOCKET          s,
    LPWSABUF        lpBuffers,
    DWORD           dwBufferCount,
    LPDWORD         lpNumberOfBytesRecvd,
    LPDWORD         lpFlags,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
    LPWSATHREADID   lpThreadId,
    LPINT           lpErrno)
{
    LPWSAOVERLAPPEDPLUS ProviderOverlapped;
    SOCK_INFO          *SocketContext;
    int                 ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPRecv: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }
    //
    // Check for overlapped I/O
    //
    if (lpOverlapped)
    {
        ProviderOverlapped = GetOverlappedStructure(SocketContext);
        if (!ProviderOverlapped)
            OutputDebugString(TEXT("WSPRecv: GetOverlappedStructure() returned NULL\r\n"));

        ProviderOverlapped->lpCallerOverlapped = lpOverlapped;
        CopyOffset(&ProviderOverlapped->ProviderOverlapped, lpOverlapped);
        ProviderOverlapped->SockInfo           = SocketContext;
        ProviderOverlapped->CallerSocket       = s;
        ProviderOverlapped->ProviderSocket     = SocketContext->ProviderSocket;
        ProviderOverlapped->Error              = NO_ERROR;
        ProviderOverlapped->Operation          = LSP_OP_RECV;
        ProviderOverlapped->lpCallerThreadId   = lpThreadId;
        ProviderOverlapped->lpCallerCompletionRoutine     = lpCompletionRoutine;
        ProviderOverlapped->RecvArgs.lpBuffers            = lpBuffers;
        ProviderOverlapped->RecvArgs.dwBufferCount        = dwBufferCount;
        ProviderOverlapped->RecvArgs.lpNumberOfBytesRecvd = lpNumberOfBytesRecvd;
        ProviderOverlapped->RecvArgs.lpFlags              = lpFlags;
        ProviderOverlapped->Provider = SocketContext->Provider;

        ret = QueueOverlappedOperation(ProviderOverlapped, SocketContext);

        if (ret != NO_ERROR)
        {
            *lpErrno = ret;
        }
    }
    else
    {
        SetBlockingProvider(SocketContext->Provider);
        ret = SocketContext->Provider->NextProcTable.lpWSPRecv(
                SocketContext->ProviderSocket, 
                lpBuffers, 
                dwBufferCount,
                lpNumberOfBytesRecvd, 
                lpFlags, 
                lpOverlapped, 
                lpCompletionRoutine, 
                lpThreadId,
                lpErrno);
        SetBlockingProvider(NULL);
        if (ret != SOCKET_ERROR)
        {
            SocketContext->BytesRecv += *lpNumberOfBytesRecvd;
        }
    }

    return ret;
}

//
// Function: WSPRecvDisconnect
//
// Description:
//    Receive data and disconnect. All we need to do is translate the socket
//    handle to the lower provider.
//
int WSPAPI WSPRecvDisconnect(
    SOCKET   s,
    LPWSABUF lpInboundDisconnectData,
    LPINT    lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPRecvDisconnect: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPRecvDisconnect(
                SocketContext->ProviderSocket,                           
                lpInboundDisconnectData, 
                lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPRecvFrom
//
// Description:
//    This function receives data on a given socket and also allows for asynchronous
//    (overlapped) operation. First translate the socket handle to the lower provider
//    handle and then make the receive call. If called with overlap, post the operation
//    to our IOCP or completion routine.
//
int WSPAPI WSPRecvFrom(
    SOCKET          s,
    LPWSABUF        lpBuffers,
    DWORD           dwBufferCount,
    LPDWORD         lpNumberOfBytesRecvd,
    LPDWORD         lpFlags,
    struct sockaddr FAR * lpFrom,
    LPINT           lpFromLen,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
    LPWSATHREADID   lpThreadId,
    LPINT           lpErrno)
{
    LPWSAOVERLAPPEDPLUS ProviderOverlapped;
    SOCK_INFO          *SocketContext;
    int                 ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPRecvFrom: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    // Check for overlapped I/O
    
    if (lpOverlapped)
    {
        ProviderOverlapped = GetOverlappedStructure(SocketContext);
        if (!ProviderOverlapped)
            OutputDebugString(TEXT("WSPRecvFrom: GetOverlappedStructure() returned NULL\r\n"));

        ProviderOverlapped->lpCallerOverlapped = lpOverlapped;
        CopyOffset(&ProviderOverlapped->ProviderOverlapped, lpOverlapped);
        ProviderOverlapped->SockInfo           = SocketContext;
        ProviderOverlapped->CallerSocket       = s;
        ProviderOverlapped->ProviderSocket     = SocketContext->ProviderSocket;
        ProviderOverlapped->Error              = NO_ERROR;
        ProviderOverlapped->Operation          = LSP_OP_RECVFROM;
        ProviderOverlapped->lpCallerThreadId   = lpThreadId;
        ProviderOverlapped->lpCallerCompletionRoutine         = lpCompletionRoutine;
        ProviderOverlapped->RecvFromArgs.lpBuffers            = lpBuffers;
        ProviderOverlapped->RecvFromArgs.dwBufferCount        = dwBufferCount;
        ProviderOverlapped->RecvFromArgs.lpNumberOfBytesRecvd = lpNumberOfBytesRecvd;
        ProviderOverlapped->RecvFromArgs.lpFlags              = lpFlags;
        ProviderOverlapped->RecvFromArgs.lpFrom               = lpFrom;
        ProviderOverlapped->RecvFromArgs.lpFromLen            = lpFromLen;
        ProviderOverlapped->Provider = SocketContext->Provider;

        ret = QueueOverlappedOperation(ProviderOverlapped, SocketContext);

        if (ret != NO_ERROR)
        {
            *lpErrno = ret;
        }
    }
    else
    {
        // Make a blocking WSPRecvFrom call
        //
        SetBlockingProvider(SocketContext->Provider);
        ret = SocketContext->Provider->NextProcTable.lpWSPRecvFrom(
                SocketContext->ProviderSocket, 
                lpBuffers, 
                dwBufferCount,
                lpNumberOfBytesRecvd, 
                lpFlags, 
                lpFrom, 
                lpFromLen, 
                lpOverlapped, 
                lpCompletionRoutine, 
                lpThreadId, 
                lpErrno);
        SetBlockingProvider(NULL);
        if (ret != SOCKET_ERROR)
        {
            SocketContext->BytesRecv += *lpNumberOfBytesRecvd;
        }
    }
    return ret;
}

//
// Function: WSPSelect
//
// Description:
//    This function tests a set of sockets for readability, writeability, and
//    exceptions. We must translate each handle in the fd_set structures to
//    their underlying provider handles before calling the next provider's
//    WSPSelect.
//
int WSPAPI WSPSelect(
    int          nfds,
    fd_set FAR * readfds,
    fd_set FAR * writefds,
    fd_set FAR * exceptfds,
    const struct timeval FAR * timeout,
    LPINT        lpErrno)
{
    SOCK_INFO *SocketContext=NULL;
    u_int      count,
               i;
    int        HandleCount,
               ret;

    struct
    {
        SOCKET ClientSocket;
        SOCKET ProvSocket;

    } Read[FD_SETSIZE], Write[FD_SETSIZE], Except[FD_SETSIZE];

    fd_set ReadFds, WriteFds, ExceptFds;
    //
    // Translate all handles contained in the fd_set structures.
    //  For each fd_set go through and build another fd_set which contains
    //  their lower provider socket handles.
    //
    if (readfds)
    {
        FD_ZERO(&ReadFds);

        if (readfds->fd_count > FD_SETSIZE)
        {
            *lpErrno = WSAENOBUFS;
            return SOCKET_ERROR;
        }
        for (i = 0; i < readfds->fd_count; i++)
        {
            if (MainUpCallTable.lpWPUQuerySocketHandleContext(
                (Read[i].ClientSocket = readfds->fd_array[i]), 
                (PDWORD_PTR) &SocketContext, 
                lpErrno) == SOCKET_ERROR)
            {
                wsprintf(Msg, TEXT("WSPSelect(1): WPUQuerySocketHandleContext() failed: %d\n"),
                    *lpErrno);
                OutputDebugString(Msg);

                *lpErrno = WSAENOTSOCK;
                return SOCKET_ERROR;
            }
            Read[i].ProvSocket = SocketContext->ProviderSocket;
            FD_SET(Read[i].ProvSocket, &ReadFds);
        }
    }

    if (writefds)
    {
        FD_ZERO(&WriteFds);

        if (writefds->fd_count > FD_SETSIZE)
        {
            *lpErrno = WSAENOBUFS;
            return SOCKET_ERROR;
        }
        for (i = 0; i < writefds->fd_count; i++)
        {
            if (MainUpCallTable.lpWPUQuerySocketHandleContext(
                (Write[i].ClientSocket = writefds->fd_array[i]), 
                (PDWORD_PTR) &SocketContext, 
                lpErrno) == SOCKET_ERROR)
            {
                wsprintf(Msg, TEXT("WSPSelect(2): WPUQuerySocketHandleContext() failed: %d\r\n"),
                    *lpErrno);
                OutputDebugString(Msg);

                *lpErrno = WSAENOTSOCK;
                return SOCKET_ERROR;
            }
            Write[i].ProvSocket = SocketContext->ProviderSocket;
            FD_SET(Write[i].ProvSocket, &WriteFds);
        }
    }

    if (exceptfds)
    {
        FD_ZERO(&ExceptFds);

        if (exceptfds->fd_count > FD_SETSIZE)
        {
            *lpErrno = WSAENOBUFS;
            return SOCKET_ERROR;
        }
        for (i = 0; i < exceptfds->fd_count; i++)
        {
            if (MainUpCallTable.lpWPUQuerySocketHandleContext(
                (Except[i].ClientSocket = exceptfds->fd_array[i]), 
                (PDWORD_PTR) &SocketContext, 
                lpErrno) == SOCKET_ERROR)
            {
                wsprintf(Msg, TEXT("WSPSelect(3): WPUQuerySocketHandleContext() failed: %d\r\n"),
                    *lpErrno);
                OutputDebugString(Msg);

                *lpErrno = WSAENOTSOCK;
                return SOCKET_ERROR;
            }
            Except[i].ProvSocket = SocketContext->ProviderSocket;
            FD_SET(Except[i].ProvSocket, &ExceptFds);
        }
    }
    //
    // Now call the lower provider's WSPSelect with the fd_set structures we built
    //  containing the lower provider's socket handles.
    //
    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPSelect(
            nfds, 
            (readfds ? &ReadFds : NULL), 
            (writefds ? &WriteFds : NULL), 
            (exceptfds ? &ExceptFds : NULL), 
            timeout, 
            lpErrno);
    SetBlockingProvider(NULL);
    if (ret != SOCKET_ERROR)
    {
        // Once we complete we now have to go through the fd_sets we passed and
        //  map them BACK to the application socket handles. Fun!
        //
        HandleCount = ret;

        if (readfds)
        {
            count = readfds->fd_count;
            FD_ZERO(readfds);

            for(i = 0; (i < count) && HandleCount; i++)
            {
                if (MainUpCallTable.lpWPUFDIsSet(Read[i].ProvSocket, &ReadFds))
                {
                    FD_SET(Read[i].ClientSocket, readfds);
                    HandleCount--;
                }
            }
        }

        if (writefds)
        {
            count = writefds->fd_count;
            FD_ZERO(writefds);

            for(i = 0; (i < count) && HandleCount; i++)
            {
                if (MainUpCallTable.lpWPUFDIsSet(Write[i].ProvSocket, &WriteFds))
                {
                    FD_SET(Write[i].ClientSocket, writefds);
                    HandleCount--;
                }
            }
        }

        if (exceptfds)
        {
            count = exceptfds->fd_count;
            FD_ZERO(exceptfds);

            for(i = 0; (i < count) && HandleCount; i++)
            {
                if (MainUpCallTable.lpWPUFDIsSet(Except[i].ProvSocket, &ExceptFds))
                {
                    FD_SET(Except[i].ClientSocket, exceptfds);
                    HandleCount--;
                }
            }
        }
    }
    return ret;
}

//
// Function: WSPSend
//
// Description:
//    This function sends data on a given socket and also allows for asynchronous
//    (overlapped) operation. First translate the socket handle to the lower provider
//    handle and then make the send call. If called with overlap, post the operation
//    to our IOCP or completion routine.
//
int WSPAPI WSPSend (
    SOCKET          s,
    LPWSABUF        lpBuffers,
    DWORD           dwBufferCount,
    LPDWORD         lpNumberOfBytesSent,
    DWORD           dwFlags,
    LPWSAOVERLAPPED lpOverlapped,                             
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,   
    LPWSATHREADID   lpThreadId,                                 
    LPINT           lpErrno                                             
    )
{
    INT                 ret;
    SOCK_INFO          *SocketContext;
    LPWSAOVERLAPPEDPLUS ProviderOverlapped;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPSend: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }
    //
    // Check for overlapped I/O
    // 
    if (lpOverlapped)
    {
        ProviderOverlapped = GetOverlappedStructure(SocketContext);
        if (!ProviderOverlapped)
            OutputDebugString(TEXT("WSPSend: GetOverlappedStructure() returned NULL\r\n"));

        ProviderOverlapped->lpCallerOverlapped = lpOverlapped;
        CopyOffset(&ProviderOverlapped->ProviderOverlapped, lpOverlapped);
        ProviderOverlapped->SockInfo           = SocketContext;
        ProviderOverlapped->CallerSocket       = s;
        ProviderOverlapped->ProviderSocket     = SocketContext->ProviderSocket;
        ProviderOverlapped->Error              = NO_ERROR;
        ProviderOverlapped->Operation          = LSP_OP_SEND;
        ProviderOverlapped->lpCallerThreadId   = lpThreadId;
        ProviderOverlapped->lpCallerCompletionRoutine    = lpCompletionRoutine;
        ProviderOverlapped->SendArgs.lpBuffers           = lpBuffers;
        ProviderOverlapped->SendArgs.dwBufferCount       = dwBufferCount;
        ProviderOverlapped->SendArgs.lpNumberOfBytesSent = lpNumberOfBytesSent;
        ProviderOverlapped->SendArgs.dwFlags             = dwFlags;
        ProviderOverlapped->Provider = SocketContext->Provider;

        ret = QueueOverlappedOperation(ProviderOverlapped, SocketContext);

        if (ret != NO_ERROR)
        {
            *lpErrno = ret;
        }

    }
    else
    {
        // Make a blocking send call
        //
        SetBlockingProvider(SocketContext->Provider);
        ret = SocketContext->Provider->NextProcTable.lpWSPSend(
                SocketContext->ProviderSocket, 
                lpBuffers, 
                dwBufferCount,
                lpNumberOfBytesSent, 
                dwFlags, 
                lpOverlapped, 
                lpCompletionRoutine, 
                lpThreadId, 
                lpErrno);
        SetBlockingProvider(NULL);
        if (ret != SOCKET_ERROR)
        {
            SocketContext->BytesSent += *lpNumberOfBytesSent;
        }
    }
    return ret;
}

//
// Function: WSPSendDisconnect
//
// Description:
//    Send data and disconnect. All we need to do is translate the socket
//    handle to the lower provider.
//
int WSPAPI WSPSendDisconnect(
    SOCKET   s,
    LPWSABUF lpOutboundDisconnectData,
    LPINT    lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPSendDisconnect: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPSendDisconnect(
            SocketContext->ProviderSocket,
            lpOutboundDisconnectData, 
            lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPSendTo
//
// Description:
//    This function sends data on a given socket and also allows for asynchronous
//    (overlapped) operation. First translate the socket handle to the lower provider
//    handle and then make the send call. If called with overlap, post the operation
//    to our IOCP or completion routine.
//
int WSPAPI WSPSendTo(
    SOCKET          s,
    LPWSABUF        lpBuffers,
    DWORD           dwBufferCount,
    LPDWORD         lpNumberOfBytesSent,
    DWORD           dwFlags,
    const struct sockaddr FAR * lpTo,
    int             iToLen,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
    LPWSATHREADID   lpThreadId,
    LPINT           lpErrno)
{
    int                 ret;
    SOCK_INFO          *SocketContext;
    LPWSAOVERLAPPEDPLUS ProviderOverlapped;

    // Check for overlapped I/O
    //    
    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPSendTo: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    if (lpOverlapped)
    {
        ProviderOverlapped = GetOverlappedStructure(SocketContext);
        if (!ProviderOverlapped)
            OutputDebugString(TEXT("WSPSendto: GetOverlappedStructure() returned NULL\r\n"));

        ProviderOverlapped->lpCallerOverlapped = lpOverlapped;
        CopyOffset(&ProviderOverlapped->ProviderOverlapped, lpOverlapped);
        ProviderOverlapped->SockInfo           = SocketContext;
        ProviderOverlapped->CallerSocket       = s;
        ProviderOverlapped->ProviderSocket     = SocketContext->ProviderSocket;
        ProviderOverlapped->Error              = NO_ERROR;
        ProviderOverlapped->Operation          = LSP_OP_SENDTO;
        ProviderOverlapped->lpCallerThreadId   = lpThreadId;
        ProviderOverlapped->lpCallerCompletionRoutine      = lpCompletionRoutine;
        ProviderOverlapped->SendToArgs.lpBuffers           = lpBuffers;
        ProviderOverlapped->SendToArgs.dwBufferCount       = dwBufferCount;
        ProviderOverlapped->SendToArgs.lpNumberOfBytesSent = lpNumberOfBytesSent;
        ProviderOverlapped->SendToArgs.dwFlags             = dwFlags;
        ProviderOverlapped->SendToArgs.lpTo                = (SOCKADDR *)lpTo;
        ProviderOverlapped->SendToArgs.iToLen              = iToLen;
        ProviderOverlapped->Provider = SocketContext->Provider;

        ret = QueueOverlappedOperation(ProviderOverlapped, SocketContext);

        if (ret != NO_ERROR)
        {
            *lpErrno = ret;
        }
    }
    else
    {
        SetBlockingProvider(SocketContext->Provider);
        ret = SocketContext->Provider->NextProcTable.lpWSPSendTo(
                SocketContext->ProviderSocket, 
                lpBuffers, 
                dwBufferCount,
                lpNumberOfBytesSent, 
                dwFlags, 
                lpTo, 
                iToLen, 
                lpOverlapped, 
                lpCompletionRoutine, 
                lpThreadId, 
                lpErrno);
        SetBlockingProvider(NULL);
        if (ret != SOCKET_ERROR)
        {
            SocketContext->BytesSent += *lpNumberOfBytesSent;
        }
    }

    return ret;
}

//
// Function: WSPSetSockOpt
//
// Description:
//    Set a socket option. For most all options we just have to translate the
//    socket option and call the lower provider. The only special case is for
//    SO_UPDATE_ACCEPT_CONTEXT in which case a socket handle is passed as the
//    argument which we need to translate before calling the lower provider.
//
int WSPAPI WSPSetSockOpt(
    SOCKET     s,
    int        level,
    int        optname,
    const char FAR * optval,   
    int        optlen,
    LPINT      lpErrno)
{
    SOCK_INFO *SocketContext,
              *AcceptContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
        s, 
        (PDWORD_PTR) &SocketContext, 
        lpErrno) == SOCKET_ERROR)
    {
        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    if (optname == SO_UPDATE_ACCEPT_CONTEXT)
    {
        // We need to intercept this (and any other options) that pass
        //  a socket handle as an argument so we can replace it with the
        //  correct underlying provider's socket handle.
        //
        if (MainUpCallTable.lpWPUQuerySocketHandleContext(
                *((SOCKET *)optval), 
                (PDWORD_PTR)&AcceptContext,
                lpErrno) == SOCKET_ERROR)
        {
            wsprintf(Msg, TEXT("WSPSetSockOpt: WPUQuerySocketHandleContext() failed: %d\r\n"),
                *lpErrno);
            OutputDebugString(Msg);

            *lpErrno = WSAENOTSOCK;
            return SOCKET_ERROR;
        }
        SetBlockingProvider(SocketContext->Provider);
        ret = SocketContext->Provider->NextProcTable.lpWSPSetSockOpt(
                    SocketContext->ProviderSocket, 
                    level,
                    optname, 
                    (char *)&AcceptContext->ProviderSocket, 
                    optlen, 
                    lpErrno);
        SetBlockingProvider(NULL);
    }
    else
    {
        SetBlockingProvider(SocketContext->Provider);
        ret = SocketContext->Provider->NextProcTable.lpWSPSetSockOpt(
                    SocketContext->ProviderSocket, 
                    level,                 
                    optname, 
                    optval, 
                    optlen, 
                    lpErrno);
        SetBlockingProvider(NULL);
    }
    return ret;
}

//
// Function: WSPShutdown
//
// Description:
//    This function performs a shutdown on the socket. All we need to do is 
//    translate the socket handle to the lower provider.
//
int WSPAPI WSPShutdown (
    SOCKET s,
    int    how,
    LPINT  lpErrno)
{
    SOCK_INFO *SocketContext;
    INT        ret;

    if (MainUpCallTable.lpWPUQuerySocketHandleContext(
            s, 
            (PDWORD_PTR) &SocketContext, 
            lpErrno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("WSPShutdown: WPUQuerySocketHandleContext() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);

        *lpErrno = WSAENOTSOCK;
        return SOCKET_ERROR;
    }

    SetBlockingProvider(SocketContext->Provider);
    ret = SocketContext->Provider->NextProcTable.lpWSPShutdown(
                SocketContext->ProviderSocket, 
                how, 
                lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPStringToAddress
//
// Description:
//    Convert a string to an address (SOCKADDR structure).  We need to translate
//    the socket handle as well as possibly substitute the lpProtocolInfo structure
//    passed to the next provider. 
//
int WSPAPI WSPStringToAddress(
    LPWSTR              AddressString,
    INT                 AddressFamily,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,   
    LPSOCKADDR          lpAddress,
    LPINT               lpAddressLength,
    LPINT               lpErrno)
{
    WSAPROTOCOL_INFOW   *pInfo=NULL;
    PROVIDER            *Provider=NULL;
    INT                  i, ret;

    for(i=0; i < gLayerCount ;i++)
    {
        if ((gBaseInfo[i].NextProvider.iAddressFamily == lpProtocolInfo->iAddressFamily) &&
            (gBaseInfo[i].NextProvider.iSocketType == lpProtocolInfo->iSocketType) && 
            (gBaseInfo[i].NextProvider.iProtocol   == lpProtocolInfo->iProtocol))
        {
            Provider = &gBaseInfo[i];
            pInfo = &gBaseInfo[i].NextProvider;
            break;
        }
    }
    if (Provider == NULL)
    {
        *lpErrno = WSAEINVAL;
        return SOCKET_ERROR;
    }
    // If we're not immediately above the base then pass the lpProtocolInfo passed
    // into us.
    //
    if (pInfo->ProtocolChain.ChainLen != BASE_PROTOCOL)
    {
        pInfo = lpProtocolInfo;
    }

    SetBlockingProvider(Provider);
    ret = Provider->NextProcTable.lpWSPStringToAddress(
                AddressString, 
                AddressFamily,
                pInfo, 
                lpAddress, 
                lpAddressLength, 
                lpErrno);
    SetBlockingProvider(NULL);

    return ret;
}

//
// Function: WSPSocket
//
// Description:
//    This function creates a socket. There are two sockets created. The first
//    socket is created by calling the lower providers WSPSocket. This is the
//    handle that we use internally within our LSP. We then create a second
//    socket with WPUCreateSocketHandle which will be returned to the calling
//    application. We will also create a socket context structure which will
//    maintain information on each socket. This context is associated with the
//    socket handle passed to the application.
//
SOCKET WSPAPI WSPSocket(
    int                 af,
    int                 type,
    int                 protocol,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    GROUP               g,
    DWORD               dwFlags,
    LPINT               lpErrno)
{
    SOCKET              NextProviderSocket = INVALID_SOCKET;
    SOCKET              NewSocket = INVALID_SOCKET;
    SOCK_INFO          *SocketContext;
    LPWSAPROTOCOL_INFOW pInfo=NULL;
    PROVIDER           *Provider=NULL;
    BOOL                bAddressFamilyOkay=FALSE,
                        bSockTypeOkay=FALSE,
                        bProtocolOkay=FALSE;
    INT                 iAddressFamily,
                        iSockType, 
                        iProtocol, 
                        i;

    *lpErrno = NO_ERROR;
    //
    // If a WSAPROTOCOL_INFO structure was passed in, use those socket/protocol
    //  values. Then find the underlying provider's WSAPROTOCOL_INFO structure.
    //
    iAddressFamily = (lpProtocolInfo ? lpProtocolInfo->iAddressFamily : af);
    iProtocol      = (lpProtocolInfo ? lpProtocolInfo->iProtocol   : protocol);
    iSockType      = (lpProtocolInfo ? lpProtocolInfo->iSocketType : type);

    for(i=0; i < gLayerCount ;i++)
    {
        if ((iAddressFamily == AF_UNSPEC) ||
            (iAddressFamily == gBaseInfo[i].NextProvider.iAddressFamily))
        {
            bAddressFamilyOkay = TRUE;
        }
        if (iSockType == gBaseInfo[i].NextProvider.iSocketType)
        {
            bSockTypeOkay = TRUE;
        }
        if ((iProtocol == 0) || (iProtocol == gBaseInfo[i].NextProvider.iProtocol) ||
            (iProtocol == IPPROTO_RAW) || (iSockType == SOCK_RAW))
        {
            bProtocolOkay = TRUE;
        }
    }
    if (!bAddressFamilyOkay)
    {
        *lpErrno = WSAEAFNOSUPPORT;
        return INVALID_SOCKET;
    }
    if (!bSockTypeOkay)
    {
        *lpErrno = WSAESOCKTNOSUPPORT;
        return INVALID_SOCKET;
    }
    if (!bProtocolOkay)
    {
        *lpErrno = WSAEPROTONOSUPPORT;
        return INVALID_SOCKET;
    }
    // If AF_UNSPEC was passed in we need to go by the socket type and protocol
    //  if possible.
    //
    if ((iAddressFamily == AF_UNSPEC) && (iProtocol == 0))
    {
        for(i=0; i < gLayerCount ;i++)
        {
            if (gBaseInfo[i].NextProvider.iSocketType == iSockType) 
            {
                Provider = &gBaseInfo[i];
                pInfo = &gBaseInfo[i].NextProvider;
                if (lpProtocolInfo)
                    pInfo->dwProviderReserved = lpProtocolInfo->dwProviderReserved;
                break;
            }
        }
    }
    else if ((iAddressFamily == AF_UNSPEC) && (iProtocol != 0))
    {
        for(i=0; i < gLayerCount ;i++)
        {
            if ((gBaseInfo[i].NextProvider.iProtocol == iProtocol) &&
                (gBaseInfo[i].NextProvider.iSocketType == iSockType) )
            {
                Provider = &gBaseInfo[i];
                pInfo = &gBaseInfo[i].NextProvider;
                if (lpProtocolInfo)
                    pInfo->dwProviderReserved = lpProtocolInfo->dwProviderReserved;
                break;
            }
        }
        if (pInfo == NULL)
        {
            *lpErrno = WSAEPROTOTYPE;
            return INVALID_SOCKET;
        }
    }
    else if ((iProtocol != 0) && (iProtocol != IPPROTO_RAW) && (iSockType != SOCK_RAW))
    {
        for(i=0; i < gLayerCount ;i++)
        {
            if ((gBaseInfo[i].NextProvider.iAddressFamily == iAddressFamily) &&
                (gBaseInfo[i].NextProvider.iSocketType == iSockType) &&
                (gBaseInfo[i].NextProvider.iProtocol == iProtocol))
            {
                Provider = &gBaseInfo[i];
                pInfo = &gBaseInfo[i].NextProvider;
                if (lpProtocolInfo)
                    pInfo->dwProviderReserved = lpProtocolInfo->dwProviderReserved;
                break;
            }
        }
    }
    else
    {
        for(i=0; i < gLayerCount ;i++)
        {
            if ((gBaseInfo[i].NextProvider.iAddressFamily == iAddressFamily) &&
                (gBaseInfo[i].NextProvider.iSocketType == iSockType) )
            {
                Provider = &gBaseInfo[i];
                pInfo = &gBaseInfo[i].NextProvider;
                if (lpProtocolInfo)
                    pInfo->dwProviderReserved = lpProtocolInfo->dwProviderReserved;
                break;
            }
        }
    }
    if (!Provider)
    {
        *lpErrno = WSAEAFNOSUPPORT;
        return INVALID_SOCKET;
    }

    if (pInfo->ProtocolChain.ChainLen != BASE_PROTOCOL)
    {
        OutputDebugString("Not over base protocol!\r\n");
        pInfo = lpProtocolInfo;
    }
    //
    // Create the underlying provider's socket.
    //
    SetBlockingProvider(Provider);
    NextProviderSocket = Provider->NextProcTable.lpWSPSocket(
                            af, 
                            type, 
                            protocol, 
                            pInfo,
                            g, 
                            dwFlags, 
                            lpErrno);
    SetBlockingProvider(NULL);

    if (NextProviderSocket != INVALID_SOCKET)
    {
        // Create the context informatin to be associated with this socket
        //
        if ((SocketContext = CreateSockInfo(Provider,
                                            NextProviderSocket,
                                            NULL)) == NULL)
        {
            *lpErrno = WSAENOBUFS;
        }
        else
        {
            // Create a socket handle to pass back to app
            //  
            NewSocket = MainUpCallTable.lpWPUCreateSocketHandle(
                        Provider->LayeredProvider.ProtocolChain.ChainEntries[0], 
                        (DWORD_PTR) SocketContext, 
                        lpErrno);
            if (NewSocket == INVALID_SOCKET)
            {
                wsprintf(Msg, TEXT("WSPSocket: WPUCreateSocketHandle() failed: %d\r\n"),
                    *lpErrno);
                OutputDebugString(Msg);
                HeapFree(hLspHeap, 0, SocketContext);
            }

            SocketContext->LayeredSocket = NewSocket;

            pInfo->dwProviderReserved = 0;
        }

        return NewSocket;
    }
    else
    {
        wsprintf(Msg, TEXT("WSPSocket: NextProcTable.WSPSocket() failed: %d\r\n"),
            *lpErrno);
        OutputDebugString(Msg);
    }

    return INVALID_SOCKET;
}

//
// Function: WSPStartup
//
// Description:
//    This function intializes our LSP. We maintain a ref count to keep track
//    of how many times this function has been called. On the first call we'll
//    look at the Winsock catalog to find our catalog ID and find which entries
//    we are layered over. We'll create a number of structures to keep this 
//    information handy.
//
int WSPAPI WSPStartup(
    WORD                wVersion,
    LPWSPDATA           lpWSPData,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    WSPUPCALLTABLE      UpCallTable,
    LPWSPPROC_TABLE     lpProcTable)
{
    LPWSAPROTOCOL_INFOW ProtocolInfo, 
                        pInfo;
    UINT                iBaseId;
    INT                 ret = NO_ERROR,
                        TotalProtocols,
                        Error,
                        idx,
                        i, x, z;

    EnterCriticalSection(&gCriticalSection);

    MainUpCallTable = UpCallTable;

    //
    // Load Next Provider in chain if this is the first time called
    //
    if (gEntryCount == 0)
    {
        hLspHeap = HeapCreate(0, 128000, 0);
        if (hLspHeap == NULL)
        {
            wsprintf(Msg, TEXT("WSPStartup: HeapCreate() failed: %d\r\n"), 
                GetLastError());
            OutputDebugString(Msg);
        }

        #ifdef DEBUG
        OutputDebugString(TEXT("Layered Service Provider\r\n"));
        #endif

        //
        //  Get all protocol information in database
        //
        if ((ProtocolInfo = GetProviders(&TotalProtocols)) == NULL)
        {
            LeaveCriticalSection(&gCriticalSection);
            OutputDebugString(TEXT("GetProviders failed\r\n"));
            return  WSAEPROVIDERFAILEDINIT;
        }
        // Find out what our layered protocol catalog ID entry is
        //
        for (i = 0; i < TotalProtocols; i++)
        {
            if (memcmp (&ProtocolInfo[i].ProviderId, &ProviderGuid, sizeof (GUID))==0)
            {
                gLayerCatId = ProtocolInfo[i].dwCatalogEntryId;
                break;
            }
        }
        //
        // Find out how many protocol entries we're layered over
        //
        gLayerCount=0;
        for(x=0; x < TotalProtocols ;x++)
        {
            if (gLayerCatId == ProtocolInfo[x].ProtocolChain.ChainEntries[0])
            {
                gLayerCount++;
            }
        }

        wsprintf(Msg, TEXT("Layered over %d protocols\r\n"), gLayerCount);
        OutputDebugString(Msg);

        //
        // Allocate some space to save off the WSAPROTOCOL_INFO structures of the 
        //  underlying providers. We'll need these throughout execution.
        //
        gBaseInfo = (LPPROVIDER)HeapAlloc(hLspHeap,
                                          HEAP_ZERO_MEMORY,
                                          sizeof(PROVIDER)*gLayerCount);
        if (!gBaseInfo)
        {
            LeaveCriticalSection(&gCriticalSection);
            OutputDebugString(TEXT("WSPStartup: HeapAlloc() failed on gBaseInfo\r\n"));
            return WSAENOBUFS;
        }
        //
        // Now copy the WSAPROTOCOL_INFO structures into our storage space
        //
        idx=0;
        for(x=0; x < TotalProtocols ;x++)
        {
            if (gLayerCatId == ProtocolInfo[x].ProtocolChain.ChainEntries[0])
            {
                memcpy(&gBaseInfo[idx].LayeredProvider,
                       &ProtocolInfo[x],
                       sizeof(WSAPROTOCOL_INFOW));

                OutputDebugString(TEXT("Layer is "));
                OutputDebugStringW(gBaseInfo[idx].LayeredProvider.szProtocol);
                OutputDebugString(TEXT("\r\n"));

                //
                // Our LSP exists in this entries chain so grab the entry
                //  after ours (i.e. the next provider in the chain)
                //
                iBaseId = ProtocolInfo[x].ProtocolChain.ChainEntries[1];
                for(z=0; z < TotalProtocols ;z++)
                {
                    if (ProtocolInfo[z].dwCatalogEntryId == iBaseId)
                    {
                        memcpy(&gBaseInfo[idx++].NextProvider, 
                               &ProtocolInfo[z], 
                                sizeof(WSAPROTOCOL_INFOW));
                        #ifdef DEBUG
                        OutputDebugStringW(gBaseInfo[idx-1].NextProvider.szProtocol);
                        OutputDebugString(TEXT("\r\n"));
                        #endif
                        break;
                    }
                }
            }
        }
        for(x=0; x < gLayerCount ;x++)
        {
            gBaseInfo[x].ProviderPathLen = MAX_PATH;
            if (WSCGetProviderPath(&gBaseInfo[x].NextProvider.ProviderId,
                                    gBaseInfo[x].ProviderPathW,
                                   &gBaseInfo[x].ProviderPathLen,
                                   &Error) == SOCKET_ERROR)
            {
                LeaveCriticalSection(&gCriticalSection);
                return WSAEPROVIDERFAILEDINIT;
            }

            if (ExpandEnvironmentStringsW(gBaseInfo[x].ProviderPathW,
                                          gBaseInfo[x].LibraryPathW,
                                          MAX_PATH))
            {
                if ((gBaseInfo[x].hProvider = LoadLibraryW(gBaseInfo[x].LibraryPathW)) == NULL)
                {
                    LeaveCriticalSection(&gCriticalSection);
                    return WSAEPROVIDERFAILEDINIT;
                }

                #ifdef DEBUG
                OutputDebugString(TEXT("LoadLibrary on "));
                OutputDebugStringW(gBaseInfo[x].LibraryPathW);
                OutputDebugString(TEXT("\r\n"));
                #endif
            }
            else
            {
                // We must be on Win9x
                //
                WideCharToMultiByte(
                    CP_ACP, 
                    0, 
                    gBaseInfo[x].ProviderPathW, 
                    gBaseInfo[x].ProviderPathLen,
                    gBaseInfo[x].ProviderPathA, 
                    gBaseInfo[x].ProviderPathLen, 
                    NULL, 
                    NULL);
                if ((gBaseInfo[x].hProvider = LoadLibraryA(gBaseInfo[x].ProviderPathA)) == NULL)
                {
                    LeaveCriticalSection(&gCriticalSection);
                    return  WSAEPROVIDERFAILEDINIT;
                }
            }
            //
            // Call the WSPStartup function on the lower provider's DLL
            //
            if ((gBaseInfo[x].lpWSPStartup = (LPWSPSTARTUP)
                GetProcAddress(gBaseInfo[x].hProvider, "WSPStartup")) == NULL)
            {
                LeaveCriticalSection(&gCriticalSection);
                OutputDebugString(TEXT("GetProcAddress failed!\r\n"));
                return  WSAEPROVIDERFAILEDINIT;
            }
            pInfo = lpProtocolInfo;
            if (gBaseInfo[x].NextProvider.ProtocolChain.ChainLen == BASE_PROTOCOL)
            {
                pInfo = &gBaseInfo[x].NextProvider;
            }

            ret = gBaseInfo[x].lpWSPStartup(wVersion,
                                            lpWSPData,
                                            pInfo,
                                            UpCallTable,
                                            &gBaseInfo[x].NextProcTable);
            if (ret != 0)
            {
                wsprintf(Msg, TEXT("%s->WSPStartup() failed: %d\r\n"),
                    gBaseInfo[x].NextProvider.szProtocol,
                    ret);
                OutputDebugString(Msg);
            }
            #ifdef DEBUG
            wsprintf(Msg, TEXT("NextProcTable.WSPStartup = 0x%X [%S]\r\n"),
                gBaseInfo[x].lpWSPStartup,
                gBaseInfo[x].NextProvider.szProtocol);
            OutputDebugString(Msg);
            PrintProcTable(&gBaseInfo[x].NextProcTable);
            #endif

            if (VerifyProcTable(&gBaseInfo[x].NextProcTable) == SOCKET_ERROR)
            {
                wsprintf(Msg, TEXT("Provider '%S' returned bad proc table!\r\n"),
                    &gBaseInfo[x].NextProvider.szProtocol);
                OutputDebugString(Msg);
                return  WSAEPROVIDERFAILEDINIT;
            }
        }
        //
        // Remap service provider functions here
        //
        lpProcTable->lpWSPAccept = WSPAccept;
        lpProcTable->lpWSPAddressToString = WSPAddressToString;
        lpProcTable->lpWSPAsyncSelect = WSPAsyncSelect;
        lpProcTable->lpWSPBind = WSPBind;
        lpProcTable->lpWSPCancelBlockingCall = WSPCancelBlockingCall;
        lpProcTable->lpWSPCleanup = WSPCleanup;
        lpProcTable->lpWSPCloseSocket = WSPCloseSocket;
        lpProcTable->lpWSPConnect = WSPConnect;
        lpProcTable->lpWSPDuplicateSocket = WSPDuplicateSocket;
        lpProcTable->lpWSPEnumNetworkEvents = WSPEnumNetworkEvents;
        lpProcTable->lpWSPEventSelect = WSPEventSelect;
        lpProcTable->lpWSPGetOverlappedResult = WSPGetOverlappedResult;
        lpProcTable->lpWSPGetPeerName = WSPGetPeerName;
        lpProcTable->lpWSPGetSockOpt = WSPGetSockOpt;
        lpProcTable->lpWSPGetSockName = WSPGetSockName;
        lpProcTable->lpWSPGetQOSByName = WSPGetQOSByName;
        lpProcTable->lpWSPIoctl = WSPIoctl;
        lpProcTable->lpWSPJoinLeaf = WSPJoinLeaf;
        lpProcTable->lpWSPListen = WSPListen;
        lpProcTable->lpWSPRecv = WSPRecv;
        lpProcTable->lpWSPRecvDisconnect = WSPRecvDisconnect;
        lpProcTable->lpWSPRecvFrom = WSPRecvFrom;
        lpProcTable->lpWSPSelect = WSPSelect;
        lpProcTable->lpWSPSend = WSPSend;
        lpProcTable->lpWSPSendDisconnect = WSPSendDisconnect;
        lpProcTable->lpWSPSendTo = WSPSendTo;
        lpProcTable->lpWSPSetSockOpt = WSPSetSockOpt;
        lpProcTable->lpWSPShutdown = WSPShutdown;
        lpProcTable->lpWSPSocket = WSPSocket;
        lpProcTable->lpWSPStringToAddress = WSPStringToAddress;
        //
        // Save off the proc table and WSP data structures for use later
        //
        memcpy(&gWSPData, lpWSPData, sizeof(WSPDATA));
        memcpy(&gProcTable, lpProcTable, sizeof(WSPPROC_TABLE));

        InitOverlappedManager();

        FreeProviders(ProtocolInfo);
    }
    else
    {
        memcpy(lpWSPData, &gWSPData, sizeof(WSPDATA));
        memcpy(lpProcTable, &gProcTable, sizeof(WSPPROC_TABLE));
        ret = 0;
    }
    //
    // Keep track of how many times we've been loaded
    //
    gEntryCount++;

    #ifdef DEBUG
    wsprintf(Msg, TEXT("WSPStartup: %d\r\n"), gEntryCount);
    OutputDebugString(Msg);
    #endif

    LeaveCriticalSection(&gCriticalSection);

    return ret;
}

void CopyOffset(WSAOVERLAPPED *ProviderOverlapped, WSAOVERLAPPED *UserOverlapped)
{
    ProviderOverlapped->Offset     = UserOverlapped->Offset;
    ProviderOverlapped->OffsetHigh = UserOverlapped->OffsetHigh;
    #ifdef DEBUG
    wsprintf(Msg, TEXT("User Offset %d High %d; Provider Offset %d High %d\r\n"),
        UserOverlapped->Offset,
        UserOverlapped->OffsetHigh,
        ProviderOverlapped->Offset,
        ProviderOverlapped->OffsetHigh
        );
    OutputDebugString(Msg);
    #endif
}

void FreeSocketsAndMemory(int *lpErrno)
{
    int     ret;

    for(int i=0; i < gLayerCount ;i++)
    {
        CloseAndFreeSocketInfo(&gBaseInfo[i]);
    }
    for(i=0; i < gLayerCount ;i++)
    {
        gBaseInfo[i].SocketList = NULL;
        //
        // Call the WSPCleanup of the provider's were layered over.
        //
        ret = gBaseInfo[i].NextProcTable.lpWSPCleanup(lpErrno);
        if (ret == SOCKET_ERROR)
        {
            wsprintf(Msg, TEXT("FreeSocketsAndMemory: WSPCleanup() failed: %d\r\n"),
                *lpErrno);
            OutputDebugString(Msg);
        }
        #ifdef DEBUG
        else
        {
            wsprintf(Msg, TEXT("Successfully called WSPCleanup [%S]\r\n"),
                gBaseInfo[i].NextProvider.szProtocol);
            OutputDebugString(Msg);
        }
        #endif

        FreeLibrary(gBaseInfo[i].hProvider);
        gBaseInfo[i].hProvider = NULL;
    }
    HeapFree(hLspHeap, 0, gBaseInfo);
    gBaseInfo = NULL;

    HeapDestroy(hLspHeap);
    hLspHeap = NULL;
}
