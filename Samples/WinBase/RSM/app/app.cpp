/*
 *  This is a part of the Microsoft Source Code Samples.
 *  Copyright 1996 - 2000 Microsoft Corporation.
 *  All rights reserved.
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
 * Copyright 1997 - 2000 Microsoft Corporation.  All Rights Reserved. *
 */
#define _UNICODE
#define UNICODE
#include <stdio.h>
#include <windows.h>
#include <iostream.h>
#include <NtmsApi.h>
#include "..\inc\stlabel.h"

#define NO_CONTAINER	NULL
#define SIZE_FOR_FIRST_TRY	5
#define NULL_PARTID	((LPNTMS_NULLGUID)0)
#define ALLOCATE_WAIT	0
#define	MOUNT_WAIT	INFINITE
#define	REQUESTING_ONE_MOUNT	1
#define REQUESTING_ONE_DISMOUNT	REQUESTING_ONE_MOUNT
#define LABEL_BUFFER_SIZE	1024

#define ADD_ACE_MASK_BITS 1
#define REMOVE_ACE_MASK_BITS 2
#define DELETE_ACE 3

void writeOmid(HANDLE, STL_LABEL *);
void persistPoolID(NTMS_GUID);
NTMS_GUID recallPoolID();
void persistMediaID(NTMS_GUID);
NTMS_GUID recallMediaID();


// Go through the DACL on the media pool and add or remove  permissions
	DWORD
SetPoolDACL(HANDLE hSession, NTMS_GUID &gMediaPool,	DWORD dwSubAuthority, 
			DWORD dwAction, DWORD dwMask)
{
	PSID psidAccount;
	PSECURITY_DESCRIPTOR psdRePoolSd;
	SID_IDENTIFIER_AUTHORITY ntauth = SECURITY_NT_AUTHORITY;
	DWORD dwRetCode, dwSizeTry, dwSizeReturned;
	PACL paclDis;
	BOOL OK;
	DWORD i;
	ACCESS_ALLOWED_ACE *pAce;
	BOOL bDaclPresent, bDaclDefaulted;


	// Get a SID for the well known, domain-relative account or group
	if(AllocateAndInitializeSid(
						&ntauth,
						2,
						SECURITY_BUILTIN_DOMAIN_RID,
						dwSubAuthority,
						0,
						0,
						0,
						0,
						0,
						0,
						&psidAccount
						) == 0)
		return GetLastError();

	// Get the security descriptor for the pool
	dwSizeTry = 5;
	psdRePoolSd = NULL;
	for(;;)
	{
		if(psdRePoolSd != NULL)
			free(psdRePoolSd);
		psdRePoolSd = (PSID)malloc(dwSizeTry);

		dwRetCode = GetNtmsObjectSecurity(hSession, &gMediaPool, NTMS_MEDIA_POOL, DACL_SECURITY_INFORMATION, 
			psdRePoolSd, dwSizeTry, &dwSizeReturned);

		if(dwRetCode == ERROR_SUCCESS) break;
		if(dwRetCode == ERROR_INSUFFICIENT_BUFFER)
		{
			dwSizeTry = dwSizeReturned;
			continue;
		}
		return ERROR_INVALID_FUNCTION;
	}

	//Get a pointer to the DACL
	OK = GetSecurityDescriptorDacl(psdRePoolSd, &bDaclPresent, &paclDis, &bDaclDefaulted);

	// Go through the DACL and change the mask of the ACE that matches the SID
	for(i=0; i < paclDis->AceCount; ++i)
	{
		OK = GetAce(paclDis, i, (LPVOID *)&pAce);
		if( EqualSid(psidAccount, &(pAce->SidStart)))
			if (dwAction == ADD_ACE_MASK_BITS)
				pAce->Mask |= dwMask;
			else if (dwAction == REMOVE_ACE_MASK_BITS)
				pAce->Mask &= ~dwMask;
			else if (dwAction == DELETE_ACE)
				DeleteAce(paclDis, i);
	}

	dwRetCode = SetNtmsObjectSecurity(hSession, &gMediaPool, NTMS_MEDIA_POOL, DACL_SECURITY_INFORMATION, 
			psdRePoolSd);
	
	FreeSid(psidAccount);

	return ERROR_SUCCESS;
}

	BOOL
EnumerateObjectType(HANDLE hSession, LPNTMS_GUID gContainer, 
				 DWORD dwType, LPNTMS_GUID &gList, DWORD &dwCount)
{
	DWORD dwRetCode;


	// Enumerate the libraries
	gList = NULL;
	dwCount = SIZE_FOR_FIRST_TRY;
	for(;;)
	{
		if(gList != NULL)
			free(gList);
		gList = (LPNTMS_GUID)malloc(dwCount*sizeof(NTMS_GUID));

		dwRetCode = EnumerateNtmsObject(hSession,
			gContainer,
			gList,
			&dwCount,
			dwType,
			0);

		if(dwRetCode == ERROR_INSUFFICIENT_BUFFER) continue;
		if(dwRetCode == ERROR_SUCCESS)
			return TRUE;
		else
		{
			free(gList);
			return FALSE;
		}
	}
}

	void
GetOfflineLoc(HANDLE hSession, NTMS_GUID &gLibID)
{
	DWORD dwSize, i;
	NTMS_GUID *gLibList = NULL;
	NTMS_OBJECTINFORMATION oiLibraryInfo;
	DWORD dwRetCode;


	// Enumerate the libraries
	EnumerateObjectType(hSession, NO_CONTAINER, NTMS_LIBRARY, gLibList, dwSize);

	// Find the offline library 
	oiLibraryInfo.dwSize = sizeof(oiLibraryInfo);
	oiLibraryInfo.dwType = NTMS_LIBRARY;
	for(i=0; i < dwSize; ++i)
	{
		dwRetCode = GetNtmsObjectInformation( hSession,
			&(gLibList[i]),
			&oiLibraryInfo);
		if((oiLibraryInfo.Info.Library.LibraryType == NTMS_LIBRARYTYPE_OFFLINE) &&
			(oiLibraryInfo.Info.Library.dwFlags == NTMS_LIBRARYFLAG_FIXEDOFFLINE))
		{
			 gLibID = gLibList[i];
			 free(gLibList);
			 return;
		}
	}

	free(gLibList);
	return;
}


// Find the first online library
	bool
findLibrary(HANDLE hSession, NTMS_GUID &gLibID, DWORD &dwRetCode)
{
	DWORD dwSize, i;
	NTMS_GUID *gLibList = NULL;
	NTMS_OBJECTINFORMATION oiLibraryInfo;


	// Enumerate the libraries
	EnumerateObjectType(hSession, NO_CONTAINER, NTMS_LIBRARY, gLibList, dwSize);

	// Find the first online library 
	oiLibraryInfo.dwSize = sizeof(oiLibraryInfo);
	oiLibraryInfo.dwType = NTMS_LIBRARY;
	for(i=0; i < dwSize; ++i)
	{
		dwRetCode = GetNtmsObjectInformation( hSession,
			&(gLibList[i]),
			&oiLibraryInfo);
		if(oiLibraryInfo.Info.Library.LibraryType == NTMS_LIBRARYTYPE_ONLINE)
		{
			 gLibID = gLibList[i];
			 free(gLibList);
			 return(true);
		}
	}

	dwRetCode = ERROR_NOT_FOUND;
	free(gLibList);
	return (false);
}


// Find the first read/write media type supported by this library
	bool
findMediaType(HANDLE hSession, NTMS_GUID &gMediaID, DWORD &dwRetCode)
{
	DWORD dwSize, i;
	bool bRetCode;
	NTMS_GUID *gTypeList = NULL;
	NTMS_GUID gLibrary;
	NTMS_OBJECTINFORMATION oiMediaTypeInfo;


	// Get the GUID for the library
	if((bRetCode = findLibrary(hSession, gLibrary, dwRetCode)) == false)
		return(false);

	// Get the list of media type GUIDS in the library
	EnumerateObjectType(hSession, &gLibrary, NTMS_MEDIA_TYPE, gTypeList, dwSize);

	// Go through the guid list and find a rewritable media type
	oiMediaTypeInfo.dwSize = sizeof(oiMediaTypeInfo);
	oiMediaTypeInfo.dwType = NTMS_MEDIA_TYPE;
	for (i=0; i < dwSize; ++i)
	{
		dwRetCode = GetNtmsObjectInformation( hSession,
			&(gTypeList[i]),
			&oiMediaTypeInfo);
		if(oiMediaTypeInfo.Info.MediaType.ReadWriteCharacteristics == NTMS_MEDIARW_REWRITABLE)
		{
			gMediaID = gTypeList[i];
			free(gTypeList);
			return (true);
		}
	}

	dwRetCode = ERROR_NOT_FOUND;
	free(gTypeList);
	return (false);
}


// Find the import media pool
	bool
findImportPool( HANDLE hSession, NTMS_GUID &gIpID, DWORD &dwRetCode )
{
	DWORD dwSize, i;
	NTMS_GUID *gPoolList = NULL, gTlPool, gMediaType;
	NTMS_OBJECTINFORMATION oiMediaPoolInfo;
	bool bRetCode;


	// Get the GUID of the media type we're interested in
	if((bRetCode = findMediaType(hSession, gMediaType, dwRetCode)) == false)
		return(false);

	// Get the list of pool GUIDS in the library
	EnumerateObjectType(hSession, NO_CONTAINER, NTMS_MEDIA_POOL, gPoolList, dwSize);

	// Go through the guid list and find the top level import pool
	oiMediaPoolInfo.dwSize = sizeof(oiMediaPoolInfo);
	oiMediaPoolInfo.dwType = NTMS_MEDIA_POOL;
	for (i=0; i < dwSize; ++i)
	{
		dwRetCode = GetNtmsObjectInformation( hSession,
			&(gPoolList[i]),
			&oiMediaPoolInfo);
		if(oiMediaPoolInfo.Info.MediaPool.PoolType == NTMS_POOLTYPE_IMPORT)
		{
			gTlPool = gPoolList[i];
			break;
		}
	}
	if(i == dwSize)
	{
		dwRetCode = ERROR_NOT_FOUND;
		free(gPoolList);
		return(false);
	}

	// Now we need to find the media-specific pool beneath the top level pool,
	// so get the list of pool GUIDS in the top level import pool
	EnumerateObjectType(hSession, &gTlPool, NTMS_MEDIA_POOL, gPoolList, dwSize);


	// Go through the guid list and find the proper subpool
	oiMediaPoolInfo.dwSize = sizeof(oiMediaPoolInfo);
	oiMediaPoolInfo.dwType = NTMS_MEDIA_POOL;
	for(i=0; i < dwSize; ++i)
	{
		dwRetCode = GetNtmsObjectInformation( hSession,
			&(gPoolList[i]),
			&oiMediaPoolInfo);
		if(oiMediaPoolInfo.Info.MediaPool.MediaType == gMediaType)
		{
			gIpID = gPoolList[i];
			free(gPoolList);
			return (true);
		}
	}


	dwRetCode = ERROR_NOT_FOUND;
	free(gPoolList);
	return (false);
}


/*************************************************************************
 *
 *       Use Case #1
 *
 *           Shows:
 *             
 *             - Creating a media pool
 *             - Setting properties of a media pool
 *
 *           Note:
 *             
 *             After creating it the first time, every time an application is 
 *             subsequently invoked it could enumerate all the RSM pools and 
 *             find its own pool.  If the app has some persistent data a better
 *             way is to remember the pool GUID from invocation to invocation.
 *
 *************************************************************************/

	void
UseCase1()
{
	HANDLE hSession;
	DWORD dwRetCode;
	bool bRetCode;
	NTMS_GUID gMediaType;
	NTMS_GUID gMediaPool;
	NTMS_OBJECTINFORMATION oiInfoBuffer;


	// Start an RSM session
	hSession = OpenNtmsSession(L"", L"ApiSampleApp", 0);
	if(hSession == INVALID_HANDLE_VALUE)
		dwRetCode = GetLastError();

	// Get a GUID for a read/write media type
	if((bRetCode = findMediaType(hSession, gMediaType, dwRetCode)) == false)
		return;

	// Create a pool for this app, returns a GUID 
	dwRetCode = CreateNtmsMediaPool( hSession,
			L"API_Sample_Pool",
			&gMediaType,
			NTMS_OPEN_ALWAYS,
			NULL,
			&gMediaPool);

	// Set this new pool to automatically draw media from the scratch pool
	// when allocating. Do this by first reading the info associated with the
	// pool GUID, changing the "allocate from scratch" bit and then setting
	// the pool info
	oiInfoBuffer.dwSize = sizeof(oiInfoBuffer);
	oiInfoBuffer.dwType = NTMS_MEDIA_POOL;
	dwRetCode = GetNtmsObjectInformation(hSession,
			&gMediaPool,
			&oiInfoBuffer);

	oiInfoBuffer.Info.MediaPool.AllocationPolicy = 
		 NTMS_ALLOCATE_FROMSCRATCH;

	dwRetCode = SetNtmsObjectInformation(hSession,
			&gMediaPool,
			&oiInfoBuffer);

	// Change the permissions on the pool
	SetPoolDACL(hSession, gMediaPool, DOMAIN_ALIAS_RID_USERS, 
		REMOVE_ACE_MASK_BITS, NTMS_MODIFY_ACCESS | NTMS_CONTROL_ACCESS);

	// Remember the pool GUID for future use
	persistPoolID(gMediaPool);

	CloseNtmsSession(hSession);
}


/*************************************************************************
 *
 *       Use Case #2
 *
 *           Shows:
 *             
 *             - Allocating media
 *             - Mounting media
 *             - Writing an OMID
 *
 *************************************************************************/

	void
UseCase2()
{
	HANDLE hSession, hDrive;
	DWORD dwRetCode, labelBytesWritten = LABEL_BUFFER_SIZE;
	NTMS_GUID gPoolID, gMediaID, gDriveID;
	NTMS_OBJECTINFORMATION oiDriveInfo;
	STL_LABEL labelBuffer;


	// Start an RSM session
	hSession = OpenNtmsSession (L"", L"DemoApp", 0) ;
	if(hSession == INVALID_HANDLE_VALUE)
		dwRetCode = GetLastError();

	// We need to write some data, but don't have a piece of
	// media to write it to yet, so get a piece of media to 
	// use and remember the guid
	gPoolID = recallPoolID();
	dwRetCode = AllocateNtmsMedia(hSession,
		&gPoolID,
		NULL,
		&gMediaID,
		NTMS_ALLOCATE_NEW, 
		ALLOCATE_WAIT,
		NULL);
	persistMediaID(gMediaID);

	// Mount the piece of media in a drive, the mount returns a drive GUID
	dwRetCode = MountNtmsMedia(hSession,
		&gMediaID,
		&gDriveID,
		REQUESTING_ONE_MOUNT,
		NTMS_MOUNT_ERROR_NOT_AVAILABLE,
		NTMS_PRIORITY_NORMAL,
		MOUNT_WAIT,
		NULL);

	// Open the drive the media is in by getting the device name associated
	// with the drive GUID the mount request returned.
	oiDriveInfo.dwSize = sizeof(oiDriveInfo);
	oiDriveInfo.dwType = NTMS_DRIVE;
	dwRetCode = GetNtmsObjectInformation(hSession,
		&gDriveID,
		&oiDriveInfo);

	hDrive = CreateFile(oiDriveInfo.Info.Drive.szDeviceName,
                    GENERIC_READ | GENERIC_WRITE,
                    0,
                    NULL,
                    OPEN_EXISTING,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL);

	// Write the OMID and tell RSM
	writeOmid(hDrive, &labelBuffer);
	dwRetCode = UpdateNtmsOmidInfo(hSession,
		&gMediaID,
		NTMS_OMID_TYPE_RAW_LABEL,
		sizeof(STL_LABEL),
		(void *)&labelBuffer);

	// Write data via Win32 API calls, close device when done.

	// (insert whatever native WWin32 I/O calls here are needed to place
	// data on the media)

	CloseHandle(hDrive);

	// Dismount the media
	dwRetCode = DismountNtmsMedia( hSession,
		&gMediaID,
		REQUESTING_ONE_DISMOUNT,
		0);

	CloseNtmsSession(hSession);
}


/*************************************************************************
 *
 *       Use Case #3
 *
 *           Shows:
 *             
 *             - Mounting already allocated media
 *             - Dismounting media
 *             - Deallocated media no longer needed
 *
 *************************************************************************/

	void
UseCase3()
{
	HANDLE hSession, hDrive;
	DWORD dwRetCode, labelBytesWritten = LABEL_BUFFER_SIZE;
	NTMS_GUID gMediaID, gDriveID;
	NTMS_OBJECTINFORMATION oiDriveInfo;


	// Start an RSM session
	hSession = OpenNtmsSession (L"", L"DemoApp", 0);
	if(hSession == INVALID_HANDLE_VALUE)
		dwRetCode = GetLastError();

	// Mount the piece of media in a drive
	gMediaID = recallMediaID();
	dwRetCode = MountNtmsMedia(hSession,
		&gMediaID,
		&gDriveID,
		REQUESTING_ONE_MOUNT,
		NTMS_MOUNT_ERROR_NOT_AVAILABLE,
		NTMS_PRIORITY_NORMAL,
		MOUNT_WAIT,
		NULL);

	// Open the drive the media is in
	oiDriveInfo.dwSize = sizeof(oiDriveInfo);
	oiDriveInfo.dwType = NTMS_DRIVE;
	dwRetCode = GetNtmsObjectInformation(hSession,
		&gDriveID,
		&oiDriveInfo);

	hDrive = CreateFile(oiDriveInfo.Info.Drive.szDeviceName,
                    GENERIC_READ | GENERIC_WRITE,
                    0,
                    NULL,
                    OPEN_EXISTING,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL);

	// (insert whatever native WWin32 I/O calls here are needed to place
	// data on the media)

	CloseHandle(hDrive);

	// Dismount the media
	dwRetCode = DismountNtmsMedia( hSession,
		&gMediaID,
		REQUESTING_ONE_DISMOUNT,
		0);

	// We've determined that we no longer need this piece of media and
	// the data it contains, so deallocate it.
	dwRetCode = DeallocateNtmsMedia( hSession,
		&gMediaID,
		0);

	CloseNtmsSession(hSession);
}


/*************************************************************************
 *
 *       Use Case #4
 *
 *           Shows:
 *             
 *             - Traversing nested media pools
 *             - Moving media from one pool to another
 *
 *************************************************************************/

	void
UseCase4()
{
	HANDLE hSession;
	DWORD dwRetCode, i;
	NTMS_GUID gIpID, *gSideList = NULL, gPoolID;
	bool bRetCode;
	DWORD dwSize;
	NTMS_OBJECTINFORMATION oiSideInfo;


	// Start an RSM session
	hSession = OpenNtmsSession (L"", L"DemoApp", 0);
	if(hSession == INVALID_HANDLE_VALUE)
		dwRetCode = GetLastError();

	// Get the GUID of the media-specific import pool
	if((bRetCode = findImportPool(hSession, gIpID, dwRetCode)) == false)
		return;

	// Enumerate all the sides in the media-specific import pool
	EnumerateObjectType(hSession, &gIpID, NTMS_PARTITION, gSideList, dwSize);


	gPoolID = recallPoolID();

	// Look at the label on each piece of media & move it
	// to this app's pool if it was written by this 
	// app.
	oiSideInfo.dwSize = sizeof(oiSideInfo);
	oiSideInfo.dwType = NTMS_PARTITION;
	for (i=0; i < dwSize; ++i)
	{
		dwRetCode = GetNtmsObjectInformation( hSession,
			&(gSideList[i]),
			&oiSideInfo);
		if((dwRetCode = wcsncmp(oiSideInfo.Info.Partition.szOmidLabelType, 
			L"Microsoft RSM API Demo", 23)) == 0)
		{
			MoveToNtmsMediaPool(hSession, 
				&(oiSideInfo.Info.Partition.PhysicalMedia), &gPoolID);
		}
	}

	free(gSideList);

	CloseNtmsSession(hSession);
}



/*************************************************************************
 *
 *       Use Case #5
 *
 *           Shows:
 *             
 *             - Finding the CD-ROM drive
 *             - Turning on RSM database update notifications
 *             - Turning on media change detection
 *             - Handling RSM database update notifications
 *
 *************************************************************************/

	void
UseCase5()
{
	HANDLE hSession, hNotificationSession, hDetectSession;
	DWORD dwRetCode, i;
	NTMS_GUID gDriveID, gLibID, *gDriveList = NULL;
	DWORD dwSize;
	NTMS_OBJECTINFORMATION oiDriveInfo, oiDTypeInfo, oiLibInfo;
	NTMS_NOTIFICATIONINFORMATION oiNotificationInfo;


	// Start an RSM session
	hSession = OpenNtmsSession (L"", L"DemoApp", 0);
	if(hSession == INVALID_HANDLE_VALUE)
		dwRetCode = GetLastError();

	// Get a list of all the drives 
	EnumerateObjectType(hSession, NO_CONTAINER, NTMS_DRIVE, gDriveList, dwSize);

	// Find the CD-ROM drive
	oiDriveInfo.dwSize = sizeof(oiDriveInfo);
	oiDriveInfo.dwType = NTMS_DRIVE;
	oiDTypeInfo.dwSize = sizeof(oiDTypeInfo);
	oiDTypeInfo.dwType = NTMS_DRIVE_TYPE;
	oiLibInfo.dwSize = sizeof(oiLibInfo);
	oiLibInfo.dwType = NTMS_LIBRARY;

	for(i=0; i < dwSize; ++i)
	{

		// get the attributes of the drive
		dwRetCode = GetNtmsObjectInformation( hSession,
			&(gDriveList[i]),
			&oiDriveInfo);
		// get the attributes of the type of drive 
		dwRetCode = GetNtmsObjectInformation( hSession,
				&(oiDriveInfo.Info.Drive.DriveType),
				&oiDTypeInfo);
		// get the attributes of the library that holds the drive
		dwRetCode = GetNtmsObjectInformation( hSession,
				&(oiDriveInfo.Info.Drive.Library),
				&oiLibInfo);

		// only continue this use case if we find a stand-alone CD-ROM drive
		if((oiDTypeInfo.Info.DriveType.DeviceType == FILE_DEVICE_CD_ROM) &&
			(oiLibInfo.Info.Library.LibraryType == NTMS_LIBRARYTYPE_STANDALONE))
		{
			 gDriveID = gDriveList[i];
			 gLibID = oiDriveInfo.Info.Drive.Library;
			 free(gDriveList);
			 break;
		}
		else 
			return;
	}

	// Turn on database notifications so we'll be notified when RSM's
	// database is updated
	hNotificationSession = OpenNtmsNotification(hSession, NTMS_DRIVE);

	// Turn on media change detection so the RSM database will be updated
	// when somebody puts media in
	BeginNtmsDeviceChangeDetection(hSession, &hDetectSession);
	SetNtmsDeviceChangeDetection(hSession, hDetectSession, &gLibID, NTMS_LIBRARY, 1);

	// Get the next 5 drive notifications, then quit
	for(i=0; i<5; ++i)
	{

		WaitForNtmsNotification(hNotificationSession,&oiNotificationInfo, INFINITE);

		if(!memcmp(&oiNotificationInfo.ObjectId,&gDriveID, sizeof(NTMS_GUID)))
		{
			switch(oiNotificationInfo.dwOperation)
			{
			case NTMS_OBJ_INSERT:
				break;
			case NTMS_OBJ_DELETE:
				break;
			case NTMS_OBJ_UPDATE:
				MessageBox(NULL, L"The contents of the CD-ROM drive changed!", L"RSM API Sample", MB_OK);
				break;
			}
		}
	}

	// Stop the media change detection and the DB update notifications
	EndNtmsDeviceChangeDetection( hSession, &hDetectSession);
	CloseNtmsNotification( &hNotificationSession);

	free(gDriveList);

	CloseNtmsSession(hSession);

}


/*************************************************************************
 *
 *       Use Case #6
 *
 *           Shows:
 *             
 *             - Finding media in the offline physical location
 *
 *************************************************************************/

	void
UseCase6()
{
	DWORD dwRetCode, i;
	NTMS_GUID gLibID, *gMediaList;
	DWORD dwSize;
	NTMS_OBJECTINFORMATION oiMediaInfo;
	HANDLE hSession;


	// Start an RSM session
	hSession = OpenNtmsSession (L"", L"DemoApp", 0);
	if(hSession == INVALID_HANDLE_VALUE)
		dwRetCode = GetLastError();

	// Get the GUID of the offline media location
	GetOfflineLoc(hSession, gLibID);

	// Get a list of GUIDs for media in offline location
	EnumerateObjectType(hSession, &gLibID, NTMS_PHYSICAL_MEDIA, gMediaList, dwSize);

	// Print the name of each physical media 
	wprintf(L"Media in the offline physical location:\n");
	oiMediaInfo.dwSize = sizeof(oiMediaInfo);
	oiMediaInfo.dwType = NTMS_PHYSICAL_MEDIA;
	for(i=0; i < dwSize; ++i)
	{
		dwRetCode = GetNtmsObjectInformation( hSession,
			&(gMediaList[i]),
			&oiMediaInfo);
		wprintf(L"   %s\n", oiMediaInfo.szName);

	}
}


	void 
main()
{

	/* Each of the following use cases performs a complete set of RSM operations an application
	   might perform during an application invokation.  A backup application, for example, would 
	   do something like UseCase1 when it is installed, UseCase2 when a backup or restore is 
	   performed, UseCase3 when a user indicates that a backup set is to be discarded and so
	   on
	 */

	UseCase1();	// Typical app initialization

	UseCase2(); // Typical media allocation and use scenario

	UseCase3(); // Typical media deallocation scenario

	UseCase4();	// Find each piece of media in the import pool that
				//		belong to this app and move it to this
				//		app's media pool

	UseCase5(); // Announce changes to the contents of the CD-ROM drive

	UseCase6(); // Print the names of all the media in the off-line physical location
}