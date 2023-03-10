//--------------------------------------------------------------------
// Microsoft OLE DB Test
//
// Copyright 1995-1999 Microsoft Corporation.  
//
// @doc 
//
// @module PRIVSTD.H | Headers to be precompiled for Private Library
//
// @comm
// Special Notes...:	(OPTIONAL NOTES FOR SPECIAL CIRCUMSTANCES)
//
// <nl><nl>
// Revision History:<nl>
//	
//	[00] MM-DD-YY	EMAIL_NAME	ACTION PERFORMED... <nl>
//	[01] 10-16-95	Microsoft	Created <nl>
//	[02] 12-01-96	Microsoft	Updated for release <nl>
//
// @head3 PRIVSTD Elements|
//
//---------------------------------------------------------------------------

#ifndef _PRIVSTD_H_
#define _PRIVSTD_H_

#include <wtypes.h>		// IID definition, must be before cguid.h
#include <cguid.h>		// GUID_NULL definition
#include <wchar.h>		// Wide Character Functions 
#include <fstream.h>	// Stream


#include <oledb.h>		// OLE DB Header
#include <oledberr.h>	// OLE DB Errors 
#include <transact.h>	
#include <msdadc.h>
#include <oleauto.h>	// Variant APIs

#include <ctype.h>
#include <stdlib.h>
#include <stddef.h> 	// For offsetof macro
#include <crtdbg.h>		// _ASSERT

#include <winnt.h>
#include <objbase.h>
#include <process.h>	// _getpid
 

#include "eclcommon.hpp"// OLE DB Test Public Library
#include "prvtrace.h"
#include "privcnst.h"	// All Private Library constants, enums, and defines
#include "List.h"		// CList implementation without MFC

// For Temp Table 
#ifdef DBINITCONSTANTS
	extern const GUID CLSID_MSDATT = {0xc8b522ceL,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
#else // !DBINITCONSTANTS
	extern const GUID CLSID_MSDATT;
#endif // DBINITCONSTANTS

#include "svcprov.h"

// For Active Data
#ifdef ACTIVE_DATA
	const GUID DBGUID_LIKE_SQL  = {0xc8b521f6,0x5cf3,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}};
#endif

#endif // _PRIVSTD_H_

