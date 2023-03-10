/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

stdafx.h : include file for standard system include files,
     or project specific include files that are used frequently,
     but are changed infrequently
----------------------------------------------------------------------------*/


#if !defined(AFX_STDAFX_H__410100D5_B80D_11D0_B893_00C04FD424B9__INCLUDED_)
    #define AFX_STDAFX_H__410100D5_B80D_11D0_B893_00C04FD424B9__INCLUDED_

    #if _MSC_VER >= 1000
        #pragma once
    #endif // _MSC_VER >= 1000

    #define STRICT

    #include <afxwin.h>
    #include <afxdisp.h>
// Include the template class(s)
    #include <afxtempl.h>

    #define _WIN32_WINNT 0x0400
    #define _ATL_APARTMENT_THREADED

    #ifndef __LOWLEVEL_SSP_COM__
        #define __LOWLEVEL_SSP_COM__
        #include <scardssp.h>
    #endif

// Include the COM types
    #include <sspsidl.h>
    #include <sspserr.h>

// Include Helpers
    #include "wrphelp.h"


    #include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
    #include <atlcom.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__410100D5_B80D_11D0_B893_00C04FD424B9__INCLUDED)

