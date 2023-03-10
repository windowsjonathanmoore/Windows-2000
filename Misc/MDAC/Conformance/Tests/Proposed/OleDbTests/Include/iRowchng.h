//--------------------------------------------------------------------
// Microsoft OLE DB Test
//
// Copyright 1995-1999 Microsoft Corporation.  
//
// @doc
//
// @module IROWCHANGE.H | Header file for IRowsetchange test module.
//
// @rev 01 | 02-04-96 | Microsoft | Created
// @rev 02 | 12-01-96 | Microsoft | Updated
//

#ifndef _IROWCHANGE_H_
#define _IROWCHANGE_H_

// Must be defined to initialize constants in oledb.h
						  
#include "oledb.h" 			// OLE DB Header Files
#include "oledberr.h"
#include "msdasql.h"
//#include "msdaguid.h"

#include "privlib.h"		//include private library, which includes
							//the "transact.h"
//-----------------------------------------------------------------------------
// constants
//-----------------------------------------------------------------------------
#define TABLE_ROW_COUNT		31
#define TABLE_ROW_MIN		10
#define TABLE_ROW_MAX		70
           
//-----------------------------------------------------------------------------
// ENUM
//-----------------------------------------------------------------------------
enum	EACCESSORLOCATION
{
	NO_ACCESSOR,				// no accessor to be created
	ON_ROWSET_ACCESSOR,			// the accessor is created on the rowset
	ON_COMMAND_ACCESSOR,		// the accessor is created on the command
	ON_ROWSET_FETCH_ACCESSOR	// the accessori s created on the rowset object
								// after a row handle is fetched.
};							

enum	ECURSOR
{
	FORWARD_ONLY_CURSOR,		//the cursor is forward only
	STATIC_CURSOR,				//the cursor is static
	KEYSET_DRIVEN_CURSOR,		//the cursor is key set driven
	DYNAMIC_CURSOR				//the cursor is dynamic
};		

//-----------------------------------------------------------------------------
// String constants
//-----------------------------------------------------------------------------
const WCHAR	wszCreateTableFailed[] =L"Create table failed!\n";
const WCHAR wszIRowsetChangeNotSupported[] = L"IRowsetChange interface is not supported by the provider.  No test will be run.\n";
const WCHAR	wszExcuteCommandFailed[] = L"Execute command failed!\n";

#endif 	//_IROWCHNG_H_
