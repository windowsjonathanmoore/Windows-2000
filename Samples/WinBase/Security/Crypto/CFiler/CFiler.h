/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1996 - 2000.  Microsoft Corporation.  All rights reserved.

CFILER.H
----------------------------------------------------------------------------*/

#ifndef CRYPTFILER_INCLUDED
#define CRYPTFILER_INCLUDED

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <cderr.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>
#include <wincrypt.h>
#include "GLOBALS.H"
#include "ENUMDRV.H"
#include "DRVPROC.H"
#include "EXPDIR.H"
#include "CFILER.H"
#include "RESOURCE.H"
#include "CRP.H"
#include "TABLE.H"
#include "FILLFILE.H"

#ifdef UNICODE
        #include <TCHAR.H>
#else
        #include <STRING.H>
#endif

BOOL    InitializeApp           (VOID);
VOID    ErrorMsg                (LPTSTR);
LRESULT WINAPI MainWndProc      (HWND, UINT, WPARAM, LPARAM);
LRESULT WINAPI AboutProc        (HWND, UINT, WPARAM, LPARAM);
LRESULT WINAPI DriveBarProc     (HWND, UINT, WPARAM, LPARAM);
INT            GetDriveBitmap   (LPBINFO);
BOOL    ChangeDrive             (LPTSTR, DWORD);
BOOL    UpdateDrivesMenu        (HMENU, HANDLE);

#endif // #ifndef CRYPTFILER_INCLUDED
