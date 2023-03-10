/*
 * Copyright (c) Microsoft Corporation.  All rights reserved.
 */

// Factory.cpp : Implementation of CFactory
#include "stdafx.h"
#include "AtlBehave.h"
#include "Factory.h"

/////////////////////////////////////////////////////////////////////////////
// CFactory
	STDMETHODIMP
CFactory::FindBehavior(
	BSTR pchNameSpace,
	BSTR pchTagName,
	IElementBehaviorSite* pUnkArg,
	IElementBehavior** ppBehavior)
{
HRESULT					hr;
CComObject<CBehavior>*	pBehavior;

	// Create a behavior object
	hr = CComObject<CBehavior>::CreateInstance( &pBehavior );
	if ( SUCCEEDED(hr) )
		return pBehavior->QueryInterface( ppBehavior );
	else
		return hr;
}

