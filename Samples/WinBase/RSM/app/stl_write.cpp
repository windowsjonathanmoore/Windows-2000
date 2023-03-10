/*
 *  This is a part of the Microsoft Source Code Samples.
 *
 *	This sample code shows the usage of some portions
 *	of the RSM API.
 *	
 *	Return codes are, for the most part, not checked in
 *	this code. See the Programmer's reference for error
 *	return information.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 * ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * Copyright 1997 - 2000 Microsoft Corporation.  All Rights Reserved. 
 */
#include <windows.h>
#include <iostream.h>
#include <stdio.h>
#include <time.h>
#include <rpc.h>
#include <NtmsMli.h>
#include "..\inc\stlabel.h"

void GetTapeGUID(wchar_t * MediaID)
{
	// A real app would have a way of generating these, or at least
	// knowing what one to use
	wcscpy(MediaID, L"{71ebde90-5172-11d2-a0f0-000000000000}");
}

void writeOmid (HANDLE hDevice, STL_LABEL *LabelBuffer) 
{
	time_t CurrentTime;
	struct tm *GMTime;
	BOOL nRetCode, nError ;
	DWORD nBytesWritten;


	// create and fill in the  fields in a STL structure that are used to recognize it as such
	wcsncpy((wchar_t *)LabelBuffer->LabelType, STL_LABEL_LabelType, STL_LABEL_LabelTypeSize);
	wcsncpy((wchar_t *)LabelBuffer->LabelVersion, STL_LABEL_Version, STL_LABEL_VersionSize);
	wcsncpy((wchar_t *)LabelBuffer->Vendor, STL_LABEL_Vendor, STL_LABEL_VendorSize);
	wcsncpy((wchar_t *)LabelBuffer->Application, STL_LABEL_Application, STL_LABEL_ApplicationSize);


	// fill in the other fields
	time(&CurrentTime);
	GMTime = gmtime(&CurrentTime) ;
	wcsftime ((wchar_t *)LabelBuffer->TimeStamp, 10, L"%m/%d/%y%I:%M:%S %p", GMTime);

    wcscpy((wchar_t *)LabelBuffer->TapeName, L"A Tape Written by the RSM Sample APP");

	GetTapeGUID((wchar_t *)&(LabelBuffer->MediaID));


	// write the label on the tape
	nRetCode = WriteFile (hDevice, (void *) LabelBuffer, 512 * ((sizeof(STL_LABEL) / 512) + 1), 
		&nBytesWritten, NULL) ;
	if (nRetCode == FALSE)
	{
		nError = GetLastError() ;
	}


	return;
}

