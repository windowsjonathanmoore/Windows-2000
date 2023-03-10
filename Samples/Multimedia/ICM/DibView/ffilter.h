/*++

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1998 - 2000.  Microsoft Corporation.  All rights reserved.

Module Name:
    
    ffilter.h

Abstract:
    
    Header file for ffilter.c

--*/

#ifndef FFILTER_H
#define FFILTER_H

typedef BOOL (WINAPI* PFNREADFILE)(PCTSTR, PBYTE *, PDWORD, PVOID);

typedef struct _FILEFILTER {

    PTSTR               pExtension;
    PTSTR               pName;
    PFNREADFILE         pfnReadFile;
    PVOID               pData;
    struct _FILEFILTER  *pNext;

} FILEFILTER, *PFILEFILTER;


typedef struct _FILEFILTERSLIST {

    PFILEFILTER m_pHead;
    PTSTR       m_pFiltersStr;

} FILEFILTERSLIST, *PFILEFILTERSLIST;


BOOL
FileFiltersList_Construct(
    PFILEFILTERSLIST pList
);

VOID
FileFiltersList_Destruct(
    PFILEFILTERSLIST pList
);

void
AddToString(
    PTSTR  *ppStr, 
    int    *pcbLeft,
    PCTSTR  pNewStr
);

BOOL
FileFiltersList_FormFiltersStr(
    PFILEFILTER pListHead,
    PTSTR       pStr,
    PINT        pcbStr
);

BOOL
FileFiltersList_ReadImageFile(
    PFILEFILTERSLIST pList,
    PCTSTR           pFileName,
    PBYTE           *ppDIB,
    DWORD           *pdwOffBits
);

BOOL
WINAPI
ReadBMP(
    PCTSTR  pFileName,
    PBYTE  *ppDIB,
    DWORD  *pdwOffBits,
    PVOID   pData
);

BOOL
WINAPI
SaveBMP(
    PCTSTR pFileName,
    PBYTE  pDIB,
    DWORD  dwOffBits,
    PVOID  pData
);

#endif //FFILTER_H
