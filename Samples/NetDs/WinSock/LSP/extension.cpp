// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (C) 1998 - 2000  Microsoft Corporation.  All Rights Reserved.
//
// Module Name: extension.cpp
//
// Description:
//
//    This sample illustrates how to develop a layered service provider that is
//    capable of counting all bytes transmitted through a TCP/IP socket.
//
//    This file contains all of the Winsock extension functions that can
//    be monitored by a service provider. This is done by intercepting any
//    WSAIoctl calls with the SIO_GET_EXTENSION_FUNCTION_POINTER (see spi.cpp
//    and WSPIoctl for more info). We substitute our own function pointer so
//    that an application calls into us. Currently we intercept only TransmitFile
//    and AcceptEx.
//

#include "provider.h"

//
// Global definitions of function pointers to our own TransmitFile and AcceptEx.
//
LPFN_TRANSMITFILE lpfnProviderTransmitFile = NULL;
LPFN_ACCEPTEX     lpfnProviderAcceptEx = NULL;

//
// Used to output debug messages
//
static TCHAR Msg[512];

//
// Function: ExtTransmitFile
//
// Description:
//    This is our provider's TransmitFile function. When an app calls WSAIoctl
//    to request the function pointer to TransmitFile, we intercept the call
//    and return a pointer to our extension function instead.
//
BOOL PASCAL FAR ExtTransmitFile (
    IN SOCKET hSocket,
    IN HANDLE hFile,
    IN DWORD nNumberOfBytesToWrite,
    IN DWORD nNumberOfBytesPerSend,
    IN LPOVERLAPPED lpOverlapped,
    IN LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers,
    IN DWORD dwFlags)
{
	SOCK_INFO          *SocketContext;
	LPWSAOVERLAPPEDPLUS ProviderOverlapped;
	int                 Errno,
                        ret;

    #ifdef DEBUG
    if (lpOverlapped)
    {
        wsprintf(Msg, TEXT("lpOverlapped.Offset = %d .OffsetHigh = %d\n"),
            lpOverlapped->Offset,
            lpOverlapped->OffsetHigh);
        OutputDebugString(Msg);
    }
    #endif

	if (MainUpCallTable.lpWPUQuerySocketHandleContext(
            hSocket,
		    (PDWORD_PTR)&SocketContext,
		    &Errno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("ExtTransmitFile: WPUQuerySocketHandleContext() failed: %d\n"),
            Errno);
        WSASetLastError(Errno);
        OutputDebugString(Msg);

		return FALSE;
    }

    if (!lpfnProviderTransmitFile)
    {
        OutputDebugString(TEXT("lpfnProviderTransmitFile == NULL!\n"));
        WSASetLastError(Errno);
	    return FALSE;
    }

	// Check for overlapped I/O
	
	if (lpOverlapped)
	{
		ProviderOverlapped = GetOverlappedStructure(SocketContext);
        if (!ProviderOverlapped)
        {
            OutputDebugString(TEXT("ExtTransmitFile: GetOverlappedStructure() returned NULL!\n"));
        }
        //
        // Save off the arguments and setup the overlapped structure
        //
        ProviderOverlapped->lpCallerOverlapped = lpOverlapped;
        CopyOffset(&ProviderOverlapped->ProviderOverlapped, lpOverlapped);
        ProviderOverlapped->SockInfo           = SocketContext;
        ProviderOverlapped->CallerSocket       = hSocket;
        ProviderOverlapped->ProviderSocket     = SocketContext->ProviderSocket;
        ProviderOverlapped->Error              = NO_ERROR;
        ProviderOverlapped->Operation          = LSP_OP_TRANSMITFILE;
        ProviderOverlapped->lpCallerThreadId   = NULL;
        ProviderOverlapped->lpCallerCompletionRoutine              = NULL;
        ProviderOverlapped->TransmitFileArgs.hFile                 = hFile;
        ProviderOverlapped->TransmitFileArgs.nNumberOfBytesToWrite = nNumberOfBytesToWrite;
        ProviderOverlapped->TransmitFileArgs.nNumberOfBytesPerSend = nNumberOfBytesPerSend;
        ProviderOverlapped->TransmitFileArgs.lpTransmitBuffers     = lpTransmitBuffers;
        ProviderOverlapped->TransmitFileArgs.dwFlags               = dwFlags;
        ProviderOverlapped->Provider = SocketContext->Provider;

        ret = QueueOverlappedOperation(ProviderOverlapped, SocketContext);

        if (ret != NO_ERROR)
        {
            WSASetLastError(ret);
            ret = FALSE;
        }
        else
            ret = TRUE;


        return ret;
	}
	else
	{
		return lpfnProviderTransmitFile(
			SocketContext->ProviderSocket,
			hFile,
			nNumberOfBytesToWrite,
			nNumberOfBytesPerSend,
			NULL,
			lpTransmitBuffers,
			dwFlags);
	}
}

//
// Function: ExtAcceptEx
//
// Description:
//    This is our provider's AcceptEx function. When an app calls WSAIoctl
//    to request the function pointer to AcceptEx, we intercept the call
//    and return a pointer to our extension function instead.
//
BOOL PASCAL FAR ExtAcceptEx(
	IN SOCKET sListenSocket,
	IN SOCKET sAcceptSocket,
	IN PVOID lpOutputBuffer,
	IN DWORD dwReceiveDataLength,
	IN DWORD dwLocalAddressLength,
	IN DWORD dwRemoteAddressLength,
	OUT LPDWORD lpdwBytesReceived,
	IN LPOVERLAPPED lpOverlapped)
{
	LPWSAOVERLAPPEDPLUS ProviderOverlapped;
	SOCK_INFO          *ListenSocketContext=NULL,
	                   *AcceptSocketContext=NULL;
	int                 Errno,
                        ret;


    //
    // Query the socket context for the listening socket
    //
	if (MainUpCallTable.lpWPUQuerySocketHandleContext(
            sListenSocket,
		    (PDWORD_PTR) &ListenSocketContext,
		    &Errno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("AcceptExExt: WPUQuerySocketHandleContext "
                           "on listen socket failed: %d\n"), Errno);
        OutputDebugString(Msg);
        Errno = WSAENOTSOCK;
        WSASetLastError(Errno);
		return FALSE;
    }
    // Also need to query the socket context for the accept socket
    //
	if (MainUpCallTable.lpWPUQuerySocketHandleContext(
            sAcceptSocket,
		    (PDWORD_PTR) &AcceptSocketContext,
		    &Errno) == SOCKET_ERROR)
    {
        wsprintf(Msg, TEXT("AcceptExExt: WPUQuerySocketHandleContext "
                           "on accept socket failed: %d\n"), Errno);
        OutputDebugString(Msg);
        Errno = WSAENOTSOCK;
        WSASetLastError(Errno);
		return FALSE;
    }

    if (!lpfnProviderAcceptEx)
    {
        OutputDebugString(TEXT("lpfnProviderAcceptEx == NULL!\n"));
		return FALSE;
    }
	// Check for overlapped I/O
    //	
	if (lpOverlapped)
	{
		ProviderOverlapped = GetOverlappedStructure(ListenSocketContext);
        if (!ProviderOverlapped)
        {
            OutputDebugString(TEXT("ExtAcceptEx: GetOverlappedStructre() returne NULL!\n"));
        }
        // Save off the paramters and initalize the overlapped structure
        //
        ProviderOverlapped->lpCallerOverlapped = lpOverlapped;
        CopyOffset(&ProviderOverlapped->ProviderOverlapped, lpOverlapped);
        ProviderOverlapped->SockInfo           = ListenSocketContext;
        ProviderOverlapped->CallerSocket       = sListenSocket;
        ProviderOverlapped->ProviderSocket     = ListenSocketContext->ProviderSocket;
        ProviderOverlapped->Error              = NO_ERROR;
        ProviderOverlapped->Operation          = LSP_OP_ACCEPTEX;
        ProviderOverlapped->lpCallerThreadId   = NULL;
        ProviderOverlapped->lpCallerCompletionRoutine          = NULL;
        ProviderOverlapped->AcceptExArgs.sAcceptSocket         = sAcceptSocket;
        ProviderOverlapped->AcceptExArgs.sProviderAcceptSocket = AcceptSocketContext->ProviderSocket;
        ProviderOverlapped->AcceptExArgs.lpOutputBuffer        = lpOutputBuffer;
        ProviderOverlapped->AcceptExArgs.dwReceiveDataLength   = dwReceiveDataLength;
        ProviderOverlapped->AcceptExArgs.dwLocalAddressLength  = dwLocalAddressLength;
        ProviderOverlapped->AcceptExArgs.dwRemoteAddressLength = dwRemoteAddressLength;
        ProviderOverlapped->AcceptExArgs.lpdwBytesReceived     = lpdwBytesReceived;
        ProviderOverlapped->Provider = AcceptSocketContext->Provider;

        ret = QueueOverlappedOperation(ProviderOverlapped, ListenSocketContext);

        if (ret != NO_ERROR)
        {
            WSASetLastError(ret);
            ret = FALSE;
        }
        else
            ret = TRUE;

  
        return ret;
	}
	else
	{
		return lpfnProviderAcceptEx(
			ListenSocketContext->ProviderSocket,
			AcceptSocketContext->ProviderSocket,
			lpOutputBuffer,
			dwReceiveDataLength,
			dwLocalAddressLength,
			dwRemoteAddressLength,
			lpdwBytesReceived,
			NULL);
	}
}
