/******************************************************************************\
*       This is a part of the Microsoft Source Code Samples. 
*       Copyright 1993 - 2000 Microsoft Corporation.
*       All rights reserved. 
*       This source code is only intended as a supplement to 
*       Microsoft Development Tools and/or WinHelp documentation.
*       See these sources for detailed information regarding the 
*       Microsoft samples programs.
\******************************************************************************/

/*
*		RasGetConnectionStatistics.c
*		
*		Usage:
*		RasGetConnectionStatistics
*
*		RAS API's used:
*			RasEnumConnections
*			RasGetConnectionStatistics
*
*		Created by:  Mazahir Poonawala
*		Date:		 11/11/99
*/

#define WINVER 0x500 // RasGetConnectionStatistics supported only on Win 2000 or later

#include <windows.h>
#include <stdio.h>
#include <ras.h>
#include <raserror.h>

int main(void)
{
	DWORD		nRet;
	LPRASCONN	lpRasConn;
	DWORD		lpcb = sizeof(RASCONN);
	DWORD		lpcConnections;
	RAS_STATS	*lpStatistics;

	// Allocate buffer with default value
	lpRasConn = (LPRASCONN) GlobalAlloc(GPTR, sizeof(RASCONN));
	if (lpRasConn == NULL)
	{
		printf("GlobalAlloc failed.\n");
		return -1;
	}
	lpRasConn->dwSize = sizeof(RASCONN);

	// Call RasEnumConnections to obtain the handle of the current active RAS connection
	nRet = RasEnumConnections(lpRasConn, &lpcb, &lpcConnections);
	
	if(nRet != 0) // RasEnumconnections returned an error
	{
		printf("RasEnumConnections failed: Error = %d\n", nRet);
		GlobalFree(lpRasConn); // Free up the buffer
		return -1;
	}

	// Allocate buffer to obtain the RAS statistics
	lpStatistics = (PRAS_STATS)GlobalAlloc(GPTR, sizeof(RAS_STATS));

	if (lpStatistics == NULL)
	{
		printf("GlobalAlloc failed.\n");
		return -1;
	}

	lpStatistics->dwSize = sizeof(RAS_STATS);

	// Call RasGetConnectionStatistics
	nRet = RasGetConnectionStatistics(lpRasConn->hrasconn, lpStatistics);
	
	if(nRet != 0) // RasGetConnectionStatistics returned an error
	{
		if (nRet == E_INVALIDARG) // Error invalid argument
		{
			printf("RasGetConnectionStatistics failed: Error Invalid Argument\n");
			printf("\nAt least one of the following is true:\n");
			printf("\t1. The hRasConn parameter is zero.\n");
			printf("\t2. The lpStatistics parameter is NULL.\n");
			printf("\t3. The value specified by the dwSize member of the RAS_STATS structure\n");
			printf("\t   specifies a version of the structure that is not supported by the \n");
			printf("\t   operating system in use.\n");
		}
		else
		if (nRet == ERROR_NOT_ENOUGH_MEMORY) // Error not enough memory
		{
			printf("RasGetConnectionStatistics failed: ERROR_NOT_ENOUGH_MEMORY\n");
			printf("\n\tThe function could not allocate sufficient memory to complete the operation.\n");
		}
		else // Unknown error
			printf("RasGetConnectionStatistics failed: Error = %d\n", nRet);
		
		GlobalFree(lpStatistics); // Free up the buffer
		return -1;
	}

	// Print the results obtained
	printf("Statistics for %s connection\n\n", lpRasConn->szEntryName);
		
	printf("Bytes Xmited\t\t\t%d\n", lpStatistics->dwBytesXmited);
	printf("Bytes Received\t\t\t%d\n", lpStatistics->dwBytesRcved);
	printf("Frames Xmited\t\t\t%d\n", lpStatistics->dwFramesXmited);
	printf("Frames Received\t\t\t%d\n", lpStatistics->dwFramesRcved);
	printf("Crc Error\t\t\t%d\n", lpStatistics->dwCrcErr);
	printf("Timeout Error\t\t\t%d\n", lpStatistics->dwTimeoutErr);
	printf("Alignment Error\t\t\t%d\n", lpStatistics->dwAlignmentErr);
	printf("Hardware Overrun Error\t\t%d\n", lpStatistics->dwHardwareOverrunErr);
	printf("Framing Error\t\t\t%d\n", lpStatistics->dwFramingErr);
	printf("Buffer Overrun Error\t\t%d\n", lpStatistics->dwBufferOverrunErr);
	printf("Compression Ratio [In]\t\t%d\n", lpStatistics->dwCompressionRatioIn);
	printf("Compression Ratio [Out]\t\t%d\n", lpStatistics->dwCompressionRatioOut);
	printf("Baud Rate [bps]\t\t\t%d\n", lpStatistics->dwBps);
	printf("Connection Duration [mili sec]\t%d\n", lpStatistics->dwConnectDuration);

	// Clean up
	GlobalFree(lpRasConn);
	GlobalFree(lpStatistics);
	
	return 0;
}