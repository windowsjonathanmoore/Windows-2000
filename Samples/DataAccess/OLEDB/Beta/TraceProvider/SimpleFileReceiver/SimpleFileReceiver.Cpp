// SimpleFileReceiver.cpp : Implementation of CMsdasfrApp and DLL registration.

#include "stdafx.h"

#include "msdasfr.h"
#include "msdatrc.h"
#include "SimpleFileReceiver.h"

const WCHAR* g_pcwszReceiverRoot		= L"Software\\Microsoft\\DataAccess\\Trace Receiver";
const WCHAR* g_pcwszLogFileName			= L"Log File Name";
const WCHAR* g_pcwszDefaultLogFileName	= L"DBTrace.xml";
const WCHAR* g_pcwszProgId				= L"MSDASFR.1";


extern const char * s_strDllName = "MSDASFR";  // used with GetModuleHandle


/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP_(ULONG) CImpSimpleFileReceiver::AddRef(void)
{
	return m_pObj->DoAddRef(m_pUnkOuter != m_pObj ? m_pUnkOuter : NULL);
}

STDMETHODIMP_(ULONG) CImpSimpleFileReceiver::Release(void)
{
	return m_pObj->DoRelease(m_pUnkOuter != m_pObj ? m_pUnkOuter : NULL);
}

STDMETHODIMP CImpSimpleFileReceiver::QueryInterface(REFIID riid, LPVOID *ppv)
{
	return m_pObj->QueryInterface(riid, ppv);
}

STDMETHODIMP CImpSimpleFileReceiver::Initialize(LPUNKNOWN pTracer)
{
	return m_pObj->Initialize(pTracer);
}

STDMETHODIMP CImpSimpleFileReceiver::Uninitialize(void)
{
	return m_pObj->Uninitialize();
}

STDMETHODIMP CImpSimpleFileReceiver::GetCLSID(LPVARIANT pvCLSIDString)
{
	LPOLESTR pwszCLSID;
	if (SUCCEEDED(StringFromCLSID(CLSID_TraceReceiver, &pwszCLSID)))
	{
		if (wcslen(pwszCLSID) > 0)
		{
			pvCLSIDString->bstrVal = pwszCLSID;
			pvCLSIDString->vt = VT_BSTR;
		}

		//
		// if we don't have a string then we should return an error
		if (!pvCLSIDString->pbstrVal)
		{
			return E_OUTOFMEMORY;
		}
	}
	else 
	{
		return E_INVALIDARG;
	}

	return S_OK;
}


STDMETHODIMP CImpSimpleFileReceiver::Invoke
										(
										DISPID dispIdMember,
										REFIID riid,
										LCID lcid,
										WORD wFlags,
										DISPPARAMS  *pDispParams,
										VARIANT		*pVarResult,
										EXCEPINFO	*pExcepInfo,
										UINT		*puArgErr
										)
{
	return m_pObj->Invoke
					(
					dispIdMember,
					riid,
					lcid,
					wFlags,
					pDispParams,
					pVarResult,
					pExcepInfo,
					puArgErr
					);
}

STDMETHODIMP CImpSimpleFileReceiver::GetIDsOfNames
										( 
										REFIID riid,
										LPOLESTR __RPC_FAR *rgszNames,
										UINT cNames,
										LCID lcid,
										DISPID __RPC_FAR *rgDispId
										)
{
	return m_pObj->GetIDsOfNames
					(
					riid,
					rgszNames,
					cNames,
					lcid,
					rgDispId
					);
}

STDMETHODIMP CImpSimpleFileReceiver::GetTypeInfoCount(UINT *pctinfo)
{ 
	return m_pObj->GetTypeInfoCount(pctinfo); 
}

STDMETHODIMP CImpSimpleFileReceiver::GetTypeInfo
										(
										UINT iTInfo,
										LCID lcid,
										ITypeInfo  **ppTInfo
										)
{ 
	return m_pObj->GetTypeInfo
				(iTInfo, lcid, ppTInfo); 
}

STDMETHODIMP_(ULONG) CImpSimpleFileNotify::AddRef(void)
{
	return m_pObj->DoAddRef(m_pUnkOuter != m_pObj ? m_pUnkOuter : NULL);
}

STDMETHODIMP_(ULONG) CImpSimpleFileNotify::Release(void)
{
	return m_pObj->DoRelease(m_pUnkOuter != m_pObj ? m_pUnkOuter : NULL);
}

STDMETHODIMP CImpSimpleFileNotify::QueryInterface(REFIID riid, LPVOID *ppv)
{
	return m_pObj->QueryInterface(riid, ppv);
}

STDMETHODIMP CImpSimpleFileNotify::OnPackageReady(DBLENGTH cbPackageDataLen, BYTE* pPackageData)
{
	return m_pObj->OnPackageReady(cbPackageDataLen, pPackageData);
}

STDMETHODIMP CImpSimpleFileNotify::Invoke
										(
										DISPID dispIdMember,
										REFIID riid,
										LCID lcid,
										WORD wFlags,
										DISPPARAMS  *pDispParams,
										VARIANT		*pVarResult,
										EXCEPINFO	*pExcepInfo,
										UINT		*puArgErr
										)
{
	return m_pObj->Invoke
					(
					dispIdMember,
					riid,
					lcid,
					wFlags,
					pDispParams,
					pVarResult,
					pExcepInfo,
					puArgErr
					);
}

STDMETHODIMP CImpSimpleFileNotify::GetIDsOfNames
										( 
										REFIID riid,
										LPOLESTR __RPC_FAR *rgszNames,
										UINT cNames,
										LCID lcid,
										DISPID __RPC_FAR *rgDispId
										)
{
	return m_pObj->GetIDsOfNames
					(
					riid,
					rgszNames,
					cNames,
					lcid,
					rgDispId
					);
}

STDMETHODIMP CImpSimpleFileNotify::GetTypeInfoCount(UINT *pctinfo)
{ 
	return m_pObj->GetTypeInfoCount(pctinfo); 
}

STDMETHODIMP CImpSimpleFileNotify::GetTypeInfo
										(
										UINT iTInfo,
										LCID lcid,
										ITypeInfo  **ppTInfo
										)
{ 
	return m_pObj->GetTypeInfo
				(iTInfo, lcid, ppTInfo); 
}

CSimpleFileReceiver::CSimpleFileReceiver(LPUNKNOWN pUnkOuter) :
			m_ISimpleFileReceiver(this, pUnkOuter ? pUnkOuter : this),
			m_ISimpleFileNotify(this, pUnkOuter ? pUnkOuter : this)
{ 
	m_cRef = 1;
	m_pCP = NULL;
	m_pIDBTracePackage = NULL;
	m_pIDBTraceInterpreter = NULL;
	m_pIDispatch = NULL;
	m_dwCookie = 0;
	m_fstream = NULL;

	if (pUnkOuter)
	{
		m_pUnkOuter = pUnkOuter;
		m_pUnkOuter->AddRef();
	}
	else
	{
		m_pUnkOuter = this;
	}

}

CSimpleFileReceiver::~CSimpleFileReceiver()
{
	if (m_pUnkOuter)
	{
		m_pUnkOuter->AddRef();

		if (m_pUnkOuter != this)
		{
			m_pUnkOuter->Release();
		}
//		m_pUnkOuter->Release();
	}
	if (m_pCP)
	{
		m_pCP->Release();
		m_pCP = NULL;
	}
}


STDMETHODIMP CSimpleFileReceiver::Initialize(LPUNKNOWN pTracer)
{
	HRESULT hr = S_OK;

	// if the caller doesn't tell us who the tracer is then forget it!
	if (!pTracer)
	{
		return E_INVALIDARG;
	}

	IConnectionPointContainer* pCPC;

	// is this the right thing to do if the pTracer is not a CPC?
	if (FAILED(hr = pTracer->QueryInterface(IID_IConnectionPointContainer, 
													(void**) &pCPC)))
	{
		return hr;
	}

	// now ask for a connection point
	hr = pCPC->FindConnectionPoint(IID_IDBTraceNotify, (IConnectionPoint**) &m_pCP);

	pCPC->Release();

	if(FAILED(hr))
	{
		goto Exit;
	}

	if (FAILED(hr = CoCreateInstance(CLSID_TraceInterpreter, NULL, CLSCTX_INPROC_SERVER, 
						IID_IDBTraceInterpreter, (void **)&m_pIDBTraceInterpreter)))
	{
		goto Error;
	}

	if (FAILED(hr = m_pIDBTraceInterpreter->CreateNewPackage(&m_pIDBTracePackage)))
	{
		goto Error;
	}

	// Now we can advise the connection point
	hr = m_pCP->Advise(&m_ISimpleFileNotify, &m_dwCookie);

	BSTR bstrLogFileName;
	hr = GetLogFileName(&bstrLogFileName);

	if (FAILED(hr))
	{
		goto Error;
	}

	char psz[MAX_PATH];
	memset(psz, 0, MAX_PATH);
	wcstombs(psz, bstrLogFileName, MAX_PATH-1);
	::SysFreeString(bstrLogFileName);

	if(initlog(psz))
	{
		log(L"<?xml version=\"1.0\"?>\n");
		log(L"<Trace_Log>\n");
	}
	else
	{
		hr = E_FAIL;
		goto Error;
	}

	goto Exit;

Error:

	Uninitialize();

Exit:

	return hr;
}

HRESULT	CSimpleFileReceiver::GetLogFileName(BSTR* pbstrLogFileName)
{
	HRESULT	hr				= S_OK;
	LONG	lRet			= 0;
	HKEY	hReceiverRoot	= NULL;
	HKEY	hReceiver		= NULL;
	DWORD	dwType			= REG_SZ;
	DWORD	dwStrSize		= 0;
	WCHAR	pwsz[MAX_PATH];

	if (NULL != pbstrLogFileName)
	{
		*pbstrLogFileName = NULL;

		lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		                    g_pcwszReceiverRoot,
							0,
							KEY_QUERY_VALUE,
							&hReceiverRoot);

		if (ERROR_SUCCESS == lRet)
		{
			lRet = RegOpenKeyEx(hReceiverRoot,
			                    g_pcwszProgId,
								0,
								KEY_QUERY_VALUE,
								&hReceiver);

			if (ERROR_SUCCESS == lRet)
			{
				dwStrSize = MAX_PATH * sizeof(WCHAR);
				lRet = RegQueryValueEx(hReceiver,
				                       g_pcwszLogFileName,
									   NULL,
									   &dwType,
									   (LPBYTE)pwsz,
									   &dwStrSize);

			}
		}

		if (ERROR_SUCCESS == lRet)
		{
			*pbstrLogFileName = ::SysAllocString(pwsz);
		}
		else
		{
			*pbstrLogFileName = ::SysAllocString(g_pcwszDefaultLogFileName);
		}

		if (NULL == *pbstrLogFileName)
		{
			hr = E_OUTOFMEMORY;
		}
	}
	else
	{
		hr = E_INVALIDARG;
	}

	if (NULL != hReceiver)
		RegCloseKey(hReceiver);

	if (NULL != hReceiverRoot)
		RegCloseKey(hReceiverRoot);

	return hr;
}

STDMETHODIMP CSimpleFileReceiver::Uninitialize()
{
	log(L"</Trace_Log>\n");
	closelog();

#if 0
	if (m_dwCookie != 0 && m_pCP)
	{
		m_pCP->Unadvise(m_dwCookie);
		m_dwCookie = 0;

		m_pCP->Release();
		m_pCP = NULL;
	}
#endif

	if(m_pIDBTraceInterpreter)
	{
		m_pIDBTraceInterpreter->Release();
		m_pIDBTraceInterpreter = NULL;
	}
	if (m_pIDBTracePackage)
	{
		m_pIDBTracePackage->Release();
		m_pIDBTracePackage = NULL;
	}

	return S_OK;
}


STDMETHODIMP CSimpleFileReceiver::PrintParameter(IDBTraceParameter * pIDBTraceParameter)	
{
	HRESULT hr = S_OK;
	BSTR bstrBuffer;

	DBTRACEPARAMINFO traceParamInfo;

	if(SUCCEEDED (hr = pIDBTraceParameter->GetParameterContext(&traceParamInfo)))
	{
		WCHAR pwszBuffer[512];

		log (L"<Parameter Name=\"");

		pIDBTraceParameter->GetName(&bstrBuffer);
		wsprintf(pwszBuffer, L"%s\"", bstrBuffer);
		log (pwszBuffer);

		wsprintf(pwszBuffer, L" Ordinal=\"%d\"", traceParamInfo.dwParamIndex);
		log (pwszBuffer);

		wcscpy(pwszBuffer, L" Type=\"");
		if (traceParamInfo.fIsConst)
		{
			wcscat(pwszBuffer, L"const ");
		}
		
		if (traceParamInfo.type)
		{
			wcscat(pwszBuffer, traceParamInfo.type);
		}
		else
		{
			wcscat(pwszBuffer, L"***UNKNOWN TYPE");
		}

		wcscat(pwszBuffer, L" ");

		for (short iAsterisk=0; iAsterisk<traceParamInfo.bLevelsOfIndirection; iAsterisk++)
		{
			wcscat(pwszBuffer, L"*");
		}

		wcscat(pwszBuffer, L"\"");
		log(pwszBuffer);

		wsprintf(pwszBuffer, L" Value=\"");
		log(pwszBuffer);

		if (traceParamInfo.bLevelsOfIndirection > 0)
		{
			wsprintf(pwszBuffer, L"0x%0.8x", traceParamInfo.argValue);
		}
		else
		{
			if (TRUE == IsReferenceTypeOrString(traceParamInfo.type))
				wsprintf(pwszBuffer, L"0x%0.8x", traceParamInfo.argValue);
			else
			{
				if (0 == wcscmp(traceParamInfo.type, L"BOOL") ||
					0 == wcscmp(traceParamInfo.type, L"Boolean"))
					wsprintf(pwszBuffer, 
					         L"%s", 
							 traceParamInfo.argValue == 0? L"FALSE" : L"TRUE");
				else
				{
					if (traceParamInfo.dwTypeID > 0)
					{
						BSTR bstr;
						hr = m_pIDBTraceInterpreter->GetEnumString(traceParamInfo.dwTypeID,
						                                           traceParamInfo.argValue,
																   &bstr);
						if (FAILED(hr))
						{
							wsprintf(pwszBuffer, L"EnumString NOT found, %ld", traceParamInfo.argValue);
						}
						else
						{
							wsprintf(pwszBuffer, L"%s", (wchar_t*)bstr);
						}
					}
					else
						wsprintf(pwszBuffer, L"%ld", traceParamInfo.argValue);
				}
			}
		}

		log(pwszBuffer);

		wsprintf(pwszBuffer, L"\" />\n");
		log(pwszBuffer);

		SysFreeString(bstrBuffer);
	}

	return hr;
}

BOOL CSimpleFileReceiver::IsReferenceTypeOrString(LPWSTR pwstrType)
{
	if (0 == wcscmp(pwstrType, L"REFIID"))
		return TRUE;

	if (0 == wcscmp(pwstrType, L"LPCOLESTR"))
		return TRUE;

	if (0 == wcscmp(pwstrType, L"REFGUID"))
		return TRUE;

	if (0 == wcscmp(pwstrType, L"REFCLSID"))
		return TRUE;

	return FALSE;
}


STDMETHODIMP CSimpleFileReceiver::PrintParameterInfo(IDBTraceParameter * pIDBTraceParameter)	
{
	HRESULT hr = S_OK;
	DBTRACEPARAMINFO TraceParamInfo;
	// Get the Parameter Context

	PrintParameter(pIDBTraceParameter);
	// If the Value is a struct, Print out the Stuct
	if(pIDBTraceParameter->IsStruct() == S_OK)
	{
		IDBTraceEnumParameters * pITraceEnumParameters;
		if(SUCCEEDED(hr = pIDBTraceParameter->EnumStructElements(&pITraceEnumParameters)))
		{
			// Fetch multiple parameters at a time to save time
#define NUM_OF_PARAMS_TO_FETCH 10
			ULONG cFetched = NUM_OF_PARAMS_TO_FETCH;
			pITraceEnumParameters->Reset();
			IDBTraceParameter* rgpParameters[NUM_OF_PARAMS_TO_FETCH];   
			while ( (cFetched == NUM_OF_PARAMS_TO_FETCH)  && (hr = pITraceEnumParameters->Next(NUM_OF_PARAMS_TO_FETCH,
													rgpParameters, &cFetched)) == S_OK)
			{
				for(ULONG cTraceParameter = 0; cTraceParameter < cFetched; cTraceParameter++)
				{
					PrintParameterInfo(rgpParameters[cTraceParameter]);
					rgpParameters[cTraceParameter]->Release();
				}
			}

			pITraceEnumParameters->Release();
		}
	}
	else
	{
		// Not a struct Print Out Value
		// Get Value and Print it Out
		// BYTE buffer 
		// pIDBTraceParameter->GetValueIndirect(
	}
	return hr;
}


STDMETHODIMP CSimpleFileReceiver::PrintTraceContext(DBTRACEINFO *  TraceInfo, TAGTYPE tgType)
{
	HRESULT hr = S_OK;
	BSTR bstrBuffer1;
	BSTR bstrBuffer2;
	WCHAR pwszBuffer[1024];
	WCHAR* pwszColons = L"";
	WCHAR pwszTag[1024];
	LONG lIndex = 0;
	LONG lSize = 0;

	if (m_pIDBTracePackage)
	{
		m_pIDBTracePackage->NameFromID(TraceInfo->dwInterfaceID, &bstrBuffer1);
		m_pIDBTracePackage->NameFromID(TraceInfo->dwMethodID, &bstrBuffer2);

		// Handle Invalid Package
		if ((TraceInfo->dwPackageType != eOpPre) && (TraceInfo->dwPackageType != eOpPost))
		{
			log(L"<UNKNOWN_PACKAGE_TYPE />\n");

			return hr;
		}

		// Handle </XXX> case
		if (TAG_END == tgType)
		{
			wcscpy(pwszTag, L"</");
	
			if (wcscmp(bstrBuffer1, L"CREATE INSTANCE") == 0)
			{
				wcscat(pwszTag, L"Create_Instance");
			}
			else
			{
				wcscat(pwszTag, L"OLEDB_CALL");
			}

			wcscat(pwszTag, L">\n");
			log(pwszTag);

			return hr;
		}

		wcscpy(pwszTag, L"<");

		if (wcscmp(bstrBuffer1, L"CREATE INSTANCE") == 0)
		{
			wcscat(pwszTag, L"Create_Instance");
			log(pwszTag);
		}
		else
		{
			wcscat(pwszTag, L"OLEDB_CALL ");
			log(pwszTag);

			wsprintf(pwszBuffer, L"Interface=\"%s\"", bstrBuffer1);
			log(pwszBuffer);

			wsprintf(pwszBuffer, L" Method=\"%s\"", bstrBuffer2);
			log(pwszBuffer);
		}

		if (TraceInfo->dwPackageType == eOpPre)
		{
			wsprintf(pwszBuffer, L" Type=\"Pre\"");
		}
		else
		{
			wsprintf(pwszBuffer, L" Type=\"Post\"");
		}
		log(pwszBuffer);

		wsprintf(pwszBuffer, L" ObjectAddress=\"0x%0.8x\"", TraceInfo->dwIntAddr);
		log(pwszBuffer);

		wsprintf(pwszBuffer, L" ProcessID=\"0x%0.8x\"", TraceInfo->dwProcessID);
		log(pwszBuffer);

		wsprintf(pwszBuffer, L" ThreadID=\"0x%0.8x\"", TraceInfo->dwThreadID);
		log(pwszBuffer);

		m_pIDBTracePackage->NameFromID(TraceInfo->dwProviderID, &bstrBuffer1);
		lSize = wcslen(bstrBuffer1);
		if (lSize > 0)
		{
			lIndex = lSize -1;
			while (lIndex >= 0)
			{
				if (bstrBuffer1[lIndex] == L'{')
				{
					break;
				}
				lIndex--;
			}

			wcscpy(pwszBuffer, L" ProviderName=\"");
			if (lIndex > 0)
			{
				bstrBuffer1[lIndex] = L'\0';
				wcscat(pwszBuffer, bstrBuffer1);
				wcscat(pwszBuffer, L"\"");
				bstrBuffer1[lIndex] = L'{';
				wcscat(pwszBuffer, L" ProviderCLSID=\"");
				wcscat(pwszBuffer, bstrBuffer1 + lIndex);
				wcscat(pwszBuffer, L"\"");
			}
			else
			{
				wcscat(pwszBuffer, bstrBuffer1);
				wcscat(pwszBuffer, L"\"");
			}

			wcscat(pwszBuffer, L" >\n");
			log(pwszBuffer);
		}
		
		if (TraceInfo->dwPackageType == eOpPost)
		{
			BSTR bstrBuffer3;
			m_pIDBTracePackage->GetResultString(TraceInfo->dwMethodID, TraceInfo->hResult, &bstrBuffer3);
			wsprintf(pwszBuffer, L"<HRESULT> %s </HRESULT>\n", bstrBuffer3);
			log(pwszBuffer);
			SysFreeString(bstrBuffer3);
		}

		SysFreeString(bstrBuffer1);
		SysFreeString(bstrBuffer2);

		if (TraceInfo->dwPackageType == eOpPost)
		{
			// We have to do the execution time the hard way because wsprintf
			// doesn't handle the %f properly
			char pszBuffer[12];
			if (TraceInfo->perfTime * 1000 > 0.009)
			{
				sprintf(pszBuffer, "%#6.2f", TraceInfo->perfTime * 1000);
			}
			else
			{
				strcpy(pszBuffer, "negligible");
			}
			wsprintf(pwszBuffer, L"<Duration msec=\"%S\" />\n", pszBuffer);

			log(pwszBuffer);
		}
	}

	return hr;
}

STDMETHODIMP CSimpleFileReceiver::OnPackageReady(DBLENGTH cbPackageDataLen, BYTE *pPackageData)
{
	HRESULT hr = S_OK;
	WCHAR pwszBuf[256];

	if (!m_pIDBTracePackage)
	{
		return E_FAIL;
	}

	// Attach data to package for use
	if (S_OK != m_pIDBTracePackage->Attach(cbPackageDataLen, pPackageData))
	{
		goto EXIT;
	}
	// GetPackage Context
	DBTRACEINFO  TraceInfo;

	if (SUCCEEDED( hr = m_pIDBTracePackage->GetPackageContext(&TraceInfo)))
	{
		// Write out Trace Context information
		PrintTraceContext(&TraceInfo, TAG_START);
		if (TraceInfo.dwPackageType == eOpPre)
		{

			wsprintf(pwszBuf, L"<InputParameters Total=\"%d\">\n", TraceInfo.cbParameterCount);
		}
		else
		{
			wsprintf(pwszBuf, L"<OutputParameters Total=\"%d\">\n", TraceInfo.cbParameterCount);
		}

		log(pwszBuf);
		
		// Loop Through Parameters Writing out description and value ( if Possible)
		for ( ULONG  ulPIndex = 1 ; ulPIndex <= TraceInfo.cbParameterCount; ulPIndex++)
		{
			IDBTraceParameter* rgpIDBTraceParameter[1];
			// Get the next Paramter and write it out
			if(SUCCEEDED(hr = m_pIDBTracePackage->GetParameterAt(ulPIndex,  rgpIDBTraceParameter)))
			{
				PrintParameterInfo(rgpIDBTraceParameter[0]);
				rgpIDBTraceParameter[0]->Release();
			}
		}

		if (TraceInfo.dwPackageType == eOpPost)
		{
			log(L"</OutputParameters>\n");
		}
		else
		{
			log(L"</InputParameters>\n");
		}

		PrintTraceContext(&TraceInfo, TAG_END);

	}

EXIT:
	// Detach Package
	m_pIDBTracePackage->Detach();

	return hr;
}



//IDispatch Member definitions

//ProviderEnum::GetTypeInfoCount
//
STDMETHODIMP CSimpleFileReceiver::GetTypeInfoCount(UINT *pctinfo)
{
	if(!m_pIDispatch)
		return E_FAIL;

	return m_pIDispatch->GetTypeInfoCount(pctinfo);
}


//ProviderEnum::GetTypeInfo
//
STDMETHODIMP CSimpleFileReceiver::GetTypeInfo(UINT iTInfo,
						 LCID lcid,
						 ITypeInfo  **ppTInfo)
{
	if(!m_pIDispatch)
		return E_FAIL;

	return m_pIDispatch->GetTypeInfo(iTInfo, lcid, ppTInfo);
}

//ProviderEnum::GetIDsOfNames
//
STDMETHODIMP CSimpleFileReceiver::GetIDsOfNames( REFIID riid,
							LPOLESTR __RPC_FAR *rgszNames,
							UINT cNames,
							LCID lcid,
							DISPID __RPC_FAR *rgDispId)
{
	if(!m_pIDispatch)
		return E_FAIL;

	return m_pIDispatch->GetIDsOfNames(riid, rgszNames, cNames, lcid, rgDispId);
}

//ProviderEnum::Invoke
//
STDMETHODIMP CSimpleFileReceiver::Invoke(DISPID dispIdMember,
					REFIID riid,
					LCID lcid,
					WORD wFlags,
					DISPPARAMS  *pDispParams,
					VARIANT		*pVarResult,
					EXCEPINFO	*pExcepInfo,
					UINT		*puArgErr)
{
	if(!m_pIDispatch)
		return E_FAIL;

	return m_pIDispatch->Invoke(dispIdMember, riid, lcid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);

}	


// QueryInterface ------------------------------------------------------------
//
// @mfunc Returns a pointer to a specified interface. Callers use
// QueryInterface to determine which interfaces the called object
// supports.
//
// @rdesc HRESULT indicating the status of the method
//      @flag S_OK          | Interface is supported and ppvObject is set.
//      @flag E_NOINTERFACE | Interface is not supported by the object
//      @flag E_INVALIDARG  | One or more arguments are invalid.
//
STDMETHODIMP CSimpleFileReceiver::QueryInterface
    (
    REFIID      riid,   //@parm IN | Interface ID of the interface being queried for.
    LPVOID *    ppvObj  //@parm OUT | Pointer to interface that was instantiated
    )
{
	//IID_IDispatch

    // Check for valid ppvObj pointer
    if (!ppvObj)
        return ResultFromScode( E_INVALIDARG );

    // In case we fail, we need to zero output arguments
    *ppvObj = NULL;

    // Do we support this interface?
	if (IID_IUnknown.Data1 == riid.Data1)
	{
		if ( memcmp( &IID_IUnknown, &riid, sizeof(riid) ) == 0 )
		{
			*ppvObj = (LPVOID)this;
		}
		else if ( memcmp( &IID_NULL, &riid, sizeof(riid) ) == 0 )
		{
			return S_OK;
		}
	}
	else if (IID_IDBTraceReceiver.Data1 == riid.Data1)
	{
		if ( memcmp( &IID_IDBTraceReceiver, &riid, sizeof(riid) ) == 0 )
		{
			*ppvObj = (LPVOID)&m_ISimpleFileReceiver;
		}
	}
	else if (IID_IDBTraceNotify.Data1 == riid.Data1)
	{
		if ( memcmp( &IID_IDBTraceNotify, &riid, sizeof(riid) ) == 0 )
		{
			*ppvObj = (LPVOID)&m_ISimpleFileNotify;
		}
	}

    // If we're going to return an interface, AddRef it first
    if (*ppvObj)
        {
        ((LPUNKNOWN) *ppvObj)->AddRef();
        return ResultFromScode( S_OK );
        }
    else
        return ResultFromScode( E_NOINTERFACE );
}


void CSimpleFileReceiver::VInit()
{
	HRESULT hr = S_OK;
	m_pIDispatch		= NULL;

	ITypeLib *		pITypeLib;
	ITypeInfo *		pITypeInfo;

	char	szFileName[ MAX_PATH + 1];
	OLECHAR wszFileName[MAX_PATH + 1];

	HMODULE hModule = GetModuleHandleA(s_strDllName);

	if( !hModule || 
		!GetModuleFileNameA(hModule, szFileName, sizeof(szFileName)/sizeof(char)) ||
		!MultiByteToWideChar(CP_ACP, NULL, szFileName, -1, &wszFileName[0], (MAX_PATH+1)))
	{
		return;
	}

	if (SUCCEEDED(hr = LoadTypeLib(wszFileName, &pITypeLib)))
	{
		if (SUCCEEDED(hr = pITypeLib->GetTypeInfoOfGuid(IID_IProviderEnum, &pITypeInfo)))
		{
			hr = CreateStdDispatch(NULL, (void*)this, pITypeInfo, (IUnknown**)&m_pIDispatch);
		}
	}

	return;
}

void CSimpleFileReceiver::VTerminate()
{
	if (m_pIDispatch)
	{
		m_pIDispatch->Release();
	}
}


// CSimpleFileReceiver::DoAddRef ----------------------------------------------------------
//
// @mfunc Increments a persistence count for the object
//
// @rdesc Current reference count
//
STDMETHODIMP_(ULONG) CSimpleFileReceiver::DoAddRef(IUnknown* pUnk)
{
	if (pUnk)
	{
		return pUnk->AddRef();
	}
	else
	{
		return InterlockedIncrement( (long*) &m_cRef);
	}
}


// CSimpleFileReceiver::DoRelease ----------------------------------------------------------
//
// @mfunc Decrements a persistence count for the object and if
//        persistence count is 0, the object destroys itself.
//
// @rdesc Current reference count
//
STDMETHODIMP_(ULONG) CSimpleFileReceiver::DoRelease(IUnknown* pUnk)
{
	ULONG cRef;

	if (pUnk)
	{
		cRef = pUnk->Release();
	}
	else
	{
		if( !(cRef = InterlockedDecrement( (long *) &m_cRef)) )
		{
			delete this;
			return 0;
		}
	}
	return cRef;
}



