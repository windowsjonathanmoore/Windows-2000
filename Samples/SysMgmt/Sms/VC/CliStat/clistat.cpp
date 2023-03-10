// *************************************************************
//  Copyright (c)2000 Microsoft Corporation, All Rights Reserved
// *************************************************************
// CliStat - Version 1.0
//
// CliStat demonstrates using the Client Status Message 
// generation functions in the SMSCStat.DLL library. This library
// is located in the %windir%\ms\sms\core\bin directory on
// all SMS 2.0 SP1 or greater Clients.  This sample application
// first loads the SMSCStat.dll library with a Win32 LoadLibrary()
// call.  Next, CliStat Uses GetProcAddress() to retrieve pointers
// to the C-Style functions in the library.  Once the function
// pointers are loaded, it begins making the Status Message.  First,
// CreateSMSStatusMessage() is called to begin making a status
// message.  The Parameters for the Message (MessageID, Component, etc)
// are taken from the command line and used in the call to 
// CreateSMSStatusMessage().  Next, the sample calls 
// AddAttributeToSMSStatusMessage() to add any specified attributes.
// Once the Status Message is complete, the sample calls 
// ReportSMSStatusMessage() to send the message to the parent site
// Last, the sample Unloads the SMSCStat.dll library and exits
//
// Note: The machine running this sample must be an SMS Client
// for the status message to get created.
// *************************************************************

#include <stdio.h>
#include <windows.h>
#include "smscstat.h"

// ********************************************************
// Global Variables:
// These will store command line parameters
// ********************************************************

char	*gpszaInsStrings[10];	// The Insertion Strings
int		giNumInsStrings=0;		// The number of strings in the pszaInsStrings[] array
char	*gpszaAttributes[5];	// The Attributes (400-404)
char	*gpszModuleName;		// Status Message DLL Module containing our message ID
char	*gpszCompName;			// The Component raising the status message
ULONG	gulMessageID=0;			// The Message ID
ULONG	gulWin32Error=0;		// The Win32 Error code of the status message

// **************************************************************************
// ParseCommandLine : Parses the command line.
//
// [in] int argc
// [in] WCHAR *argv[]
// Returns : 
//      true  = continue with execution.
//      false = stop.  An error was encountered, or the help info was displayed.
// Parsed commands are stored in global variables.
// **************************************************************************
bool ParseCommandLine(int argc, char *argv[]) 
{
	int iArg;
	int iLoop;

	// Initialize all the global strings
	int iIndex;
	gpszModuleName = NULL;
	gpszCompName = NULL;
	for(iIndex = 0; iIndex < 10; iIndex ++)
		gpszaInsStrings[iIndex] = NULL;
	for(iIndex = 0; iIndex < 5; iIndex ++)
		gpszaAttributes[iIndex] = NULL;
	

	for( iLoop = iArg = 1; iLoop < argc; iLoop++ ) 
	{
		if( (*argv[iLoop] != L'-') && (*argv[iLoop] != L'/') ) 
		{
			switch( iArg++ ) 
			{
			case 1:
				gulMessageID = atol(argv[iLoop]);	// Message ID
				break;
			case 2:
				gpszModuleName = argv[iLoop];		// Module Name
				break;
			default:
				return false;
			}
		}
		else 
		{
			if( !strnicmp(argv[iLoop] + 1, "E:", 2) ) 
			{
				gulWin32Error = atol(argv[iLoop] + 3);			// Win32 Error Code
			}

			else if ( !strnicmp(argv[iLoop] + 1, "C:", 2) )
			{
				gpszCompName = argv[iLoop] + 3;			// Component Name
			}

			else if ( !strnicmp(argv[iLoop] + 1, "I:", 2) )
			{
				// This section parses out all the insertion strings
				// a common command line argument would be "-I:String1,String2,String3"
				int iInsLoop = 0;
				int iOffset = 0;
				bool bLoopFinished = false;
				argv[iLoop] += 3; // move past the "-I:"

				while( !bLoopFinished )
				{
					if( (*(argv[iLoop] + iOffset) == ',') && (iInsLoop < 10))
					{
						*(argv[iLoop] + iOffset) = 0;
						gpszaInsStrings[iInsLoop] = argv[iLoop];

						argv[iLoop] += (iOffset + 1);
						iInsLoop++;
						iOffset = 0;
					}
					else if( (*(argv[iLoop] + iOffset) == 0) && (iInsLoop < 12))
					{
						gpszaInsStrings[iInsLoop] = argv[iLoop];
						bLoopFinished = true;
					}
					else
						iOffset++;
				}
				giNumInsStrings = iInsLoop + 1;
			}

			else if ( !strnicmp(argv[iLoop] + 1, "A:", 2) )
			{
				// This section parses out the Attributes
				// a common attribute param would be "-A:401,String1"
				char *pszFindComma;
				int nAttrID;
				argv[iLoop] += 3;
				
				pszFindComma = strchr(argv[iLoop], ',');
				*pszFindComma = 0;

				nAttrID = atol(argv[iLoop]);
				if(nAttrID < 400 || nAttrID > 404)
					return false;

				gpszaAttributes[nAttrID - 400] = pszFindComma + 1;
			}
		}
	}

	if( iArg != 3 ) return false;

	// Set any non-user-defined variables to their defaults
	if( gpszCompName == NULL )
		gpszCompName = "Unknown Application";

	return true;
}

// **************************************************************************
// main 
// **************************************************************************
void main(int argc, char *argv[])
{
	char szPathToSMSCSTATDLL[MAX_PATH+1];
	HINSTANCE hSMSCSTATDLL = NULL;
	PROC_CREATESMSSTATUSMESSAGE pfnCreateSMSStatusMessage = NULL;
    PROC_ADDATTRIBUTETOSMSSTATUSMESSAGE pfnAddAttributeToSMSStatusMessage = NULL;
    PROC_REPORTSMSSTATUSMESSAGE pfnReportSMSStatusMessage = NULL;
	HANDLE hStatusMessage = NULL;
	DWORD dwRet = 0;

	if( !ParseCommandLine(argc, argv) ) 
	{
		printf(
			"\nCLISTAT -- Raises Status Messages via the SMS Client DLL - SMSCStat.dll\n"
			"-----------------------------------------------------------------------\n\n"
			"Usage:  CliStat <Message ID> <Module Name> [options]\n\n"
			"Where:\n"
			"  Message ID  :  The ID of the status message string\n"
			"  Module Name :  The Module Name of the DLL containing the status message string\n\n"
			"Options: [-VAR:setting]\n"
			"  -C:<componentname>     :  The component raising the status message\n"
			"  -E:<win32 error code>  :  The error code\n"
			"  -I:<ins string 1>,<ins string 2>,...,<ins string 10>\n"
			"                         :  Specifies the insertion strings for\n"
			"                         :  the raised status message\n"
			"  -A:<attrib id>,<value> :  Sets the status message attribute for <attrib id> \n"
			"                            to <value>  (attrib id range: 400-404)\n"
		);
		return;
	}

	printf("\nStarting...\n");

	// Get the path to the SMSCStat.dll file
	if (GetWindowsDirectory(szPathToSMSCSTATDLL, MAX_PATH) == 0) 
	{
        printf("ERROR: Win32 GetWindowsDirectory() failed.  GetLastError() returned %li.\n", GetLastError());
        return;
    }
    strcat(szPathToSMSCSTATDLL, "\\ms\\sms\\core\\bin\\smscstat.dll");
    printf("The path to SMSCSTAT.DLL is \"%s\".\n", szPathToSMSCSTATDLL);

	// Load the DLL
	if ((hSMSCSTATDLL = LoadLibrary(szPathToSMSCSTATDLL)) == NULL) 
	{
        printf("ERROR: Win32 LoadLibrary(\"%s\") failed.  GetLastError() returned %li.\n       This error often means this machine is not an SMS Client.\n", szPathToSMSCSTATDLL, GetLastError());
        return;
    }
    printf("Loaded \"%s\"; the module handle is 0x%08X.\n", szPathToSMSCSTATDLL, hSMSCSTATDLL);

	// Get the function pointers using GetProcAddress()
	if ((pfnCreateSMSStatusMessage = (PROC_CREATESMSSTATUSMESSAGE) GetProcAddress(hSMSCSTATDLL, PROCNAME_CREATESMSSTATUSMESSAGE)) == NULL) 
	{
        printf("ERROR: Win32 GetProcAddress(0x%08X, \"%s\") failed.  GetLastError() returned %li.\n", hSMSCSTATDLL, PROCNAME_CREATESMSSTATUSMESSAGE, GetLastError());
		FreeLibrary(hSMSCSTATDLL);
        return;
    }

    printf("The address to the \"%s\" function is 0x%08X.\n", PROCNAME_CREATESMSSTATUSMESSAGE, pfnCreateSMSStatusMessage);

    if ((pfnAddAttributeToSMSStatusMessage = (PROC_ADDATTRIBUTETOSMSSTATUSMESSAGE) GetProcAddress(hSMSCSTATDLL, PROCNAME_ADDATTRIBUTETOSMSSTATUSMESSAGE)) == NULL)
	{
        printf("ERROR: Win32 GetProcAddress(0x%08X, \"%s\") failed.  GetLastError() returned %li.\n", hSMSCSTATDLL, PROCNAME_ADDATTRIBUTETOSMSSTATUSMESSAGE, GetLastError());
		FreeLibrary(hSMSCSTATDLL);
        return;
    }

    printf("The address to the \"%s\" function is 0x%08X.\n", PROCNAME_ADDATTRIBUTETOSMSSTATUSMESSAGE, pfnAddAttributeToSMSStatusMessage);

    if ((pfnReportSMSStatusMessage = (PROC_REPORTSMSSTATUSMESSAGE) GetProcAddress(hSMSCSTATDLL, PROCNAME_REPORTSMSSTATUSMESSAGE)) == NULL)
	{
        printf("ERROR: Win32 GetProcAddress(0x%08X, \"%s\") failed.  GetLastError() returned %li.\n", hSMSCSTATDLL, PROCNAME_REPORTSMSSTATUSMESSAGE, GetLastError());
		FreeLibrary(hSMSCSTATDLL);
        return;
    }

    printf("The address to the \"%s\" function is 0x%08X.\n", PROCNAME_REPORTSMSSTATUSMESSAGE, pfnReportSMSStatusMessage);
	
	// Create the Status Message object.
	dwRet = (*pfnCreateSMSStatusMessage)(&hStatusMessage, 
										 gpszModuleName,
										 gulMessageID,
										 gulWin32Error,
										 gpszaInsStrings[0],
										 gpszaInsStrings[1],
										 gpszaInsStrings[2],
										 gpszaInsStrings[3],
										 gpszaInsStrings[4],
										 gpszaInsStrings[5],
										 gpszaInsStrings[6],
										 gpszaInsStrings[7],
										 gpszaInsStrings[8],
										 gpszaInsStrings[9]);

	if (dwRet != SMSSTATMSG_SUCCESS)
	{
		printf("ERROR: CreateSMSStatusMessage() failed and returned error code %lu.\n", dwRet);
		FreeLibrary(hSMSCSTATDLL);
		return;
	}
	printf("CreateSMSStatusMessage() succeeded; the status message object handle is 0x%08X.\n", hStatusMessage);

	// Add any attributes that were specified on the command line
	for(int nAttrIndex=0; nAttrIndex<5; nAttrIndex++)
	{
		if(gpszaAttributes[nAttrIndex] != NULL)
		{
			dwRet = (*pfnAddAttributeToSMSStatusMessage)(hStatusMessage, nAttrIndex+400, gpszaAttributes[nAttrIndex]);

			if (dwRet != SMSSTATMSG_SUCCESS)
			{
				printf("ERROR: AddAttributeToSMSStatusMessage() failed and returned error code %lu.\n", dwRet);
				FreeLibrary(hSMSCSTATDLL);
				return;
			}
			printf("AddAttributeToSMSStatusMessage() succeeded   ID=%d, Value=%s.\n", nAttrIndex+400, gpszaAttributes[nAttrIndex]);
		}
	}

	// Report the Status Message to the client's Parent Site
	dwRet = (*pfnReportSMSStatusMessage)(hStatusMessage, gpszCompName, NULL, NULL);

	if (dwRet != SMSSTATMSG_SUCCESS) 
	{
		printf("ERROR: ReportSMSStatusMessage() failed and returned error code %lu.\n", dwRet);
		FreeLibrary(hSMSCSTATDLL);
		return;
	}

	printf("ReportSMSStatusMessage() succeeded.\n");

	// Unload SMSCSTAT.DLL.
	FreeLibrary(hSMSCSTATDLL);
	printf("Unloaded \"%s\"; the module handle %08X is now closed.\n", szPathToSMSCSTATDLL, hSMSCSTATDLL);

	// Exit.
	printf("Exiting.\n");
}