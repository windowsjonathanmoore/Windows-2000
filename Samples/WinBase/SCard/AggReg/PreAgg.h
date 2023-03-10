/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1996 - 2000.  Microsoft Corporation.  All rights reserved.

Module Name:

    StdAfx

Abstract:

        Include file for standard system include files, or project
        specific include files that are used frequently, but are
        changed infrequently for this in-process server (DLL) for
        the Smartcard Vendor Wrapper Service Provider (SSP).

Environment:

    Win32, ATL

Revision History:

--*/

#ifndef __STDAFX_H__
    #define __STDAFX_H__

    #include <afxwin.h>
    #include <afxdisp.h>

    #include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
    #include <atlcom.h>

//////////////////////////////////////////////////////////////////////////
#endif //__STDAFX_H__

