//-----------------------------------------------------------------------------
// Microsoft Local Test Manager (LTM)
// Copyright (C) 1997 - 1999 By Microsoft Corporation.
//	  
// @doc
//												  
// @module CSUPERLOG.HPP
//
//-----------------------------------------------------------------------------------


///////////////////////////////////////////////////////////////////////////
// Defines
//
//////////////////////////////////////////////////////////////////////////
#ifndef __CSuperLog_hpp_
#define __CSuperLog_hpp_

/////////////////////////////////////////////////////////////////////////////
// Includes
//
/////////////////////////////////////////////////////////////////////////////
#include <strstrea.h>
#include "MODError.hpp"


/////////////////////////////////////////////////////////////////////////////
// Externs
//
/////////////////////////////////////////////////////////////////////////////
class CSuperLog;
extern CSuperLog odtLog;


/////////////////////////////////////////////////////////////////////////////
// CSuperLog
//
/////////////////////////////////////////////////////////////////////////////
class /*DLL_EXPORT*/ CSuperLog
{
public:
	CSuperLog(void);
	virtual ~CSuperLog();

	void SetTabLevel(int);

	CSuperLog & operator << (const BYTE);

	CSuperLog & operator << (const ULONGLONG);
	CSuperLog & operator << (const LONGLONG);

	CSuperLog & operator << (const unsigned long);
	CSuperLog & operator << (const signed long);

	CSuperLog & operator << (const unsigned short);
	CSuperLog & operator << (const signed short);

	CSuperLog & operator << (const unsigned);
	CSuperLog & operator << (const signed);

	CSuperLog & operator << (char const *);
	CSuperLog & operator << (wchar_t const *);
	CSuperLog & operator << (const double);

	CSuperLog & operator << (const VARIANT);

	int ScreenLogging(BOOL fScreen);

	HRESULT	SetErrorInterface(IError* pIError);
	HRESULT	GetErrorInterface(IError** ppIError);

private:
	LONG			m_nTabLevel;
	HRESULT			OutputText(WCHAR* pwszText);
	
	BOOL			m_fTriedErrorAlready;
	IError*			m_pIError;
};


#endif // __CSuperLog_hpp_
