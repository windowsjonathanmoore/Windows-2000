// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__74962DD5_A69B_11D2_877A_00C04F96DE59__INCLUDED_)
#define AFX_STDAFX_H__74962DD5_A69B_11D2_877A_00C04F96DE59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define _WIN32_DCOM
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//

#pragma warning( disable : 4018 ) // '<' : signed/unsigned mismatch
#pragma warning( disable : 4786 ) // identifier was truncated to 'number' characters in the debug information
#pragma warning( disable : 4355 ) // 'this' : used in base member initializer list
#pragma warning( disable : 4503 ) // decorated name length exceeded, name was truncated

// STL
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <vector>

// ATL
#include <atlbase.h>

// COM helper classes
#include <comdef.h>

// WBEM
#include <wbemidl.h>
#include <SshWbemHelpers.h>

#define NO_EXP_TEMPLATES // remove if you use the templates in a DLL and want to export them
#include <T_SafeVector.h>

#define EXTASSERT(param) if(!(param)) { printf("%s Assert in wbem helpers\n",__FILE__); printf("...line %d",__LINE__); }



//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__74962DD5_A69B_11D2_877A_00C04F96DE59__INCLUDED_)
