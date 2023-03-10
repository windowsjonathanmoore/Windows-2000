// SimpleFileReceiver.h: Header for the simple file receiver object.
//
//-----------------------------------------------------------------------------
// DAG - OLEDB Core Development	Copyright (C) 1998 - 2000 Microsoft Corporation
//
// @doc
// @module SimpleFileReceiver.h | <c <class name}> Definition.
//
//
// @comm
//
// <nl><nl>
// Special Notes:	
//
//----------------------------------------------------------------------------------------


#ifndef __SIMPLEFILERECEIVER_H__
#define __SIMPLEFILERECEIVER_H__

#pragma once

#include "stdio.h"

#include "TraceProvider.h"
#include "resource.h"       // main symbols


//----------------------------------------------------------------------------
// Constants ----------------------------------------------------------------
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// Classes ----------------------------------------------------------------
//----------------------------------------------------------------------------
class CSimpleFileReceiver;
class CImpSimpleFileReceiver;
class CImpSimpleFileNotify;


typedef enum {TAG_START, TAG_END} TAGTYPE;

/**************************************************************************
		Interface CImpSimpleFileReceiver : Definition Begins
**************************************************************************/
class CImpSimpleFileReceiver : public IDBTraceReceiver
{
	public : //@access public
		CImpSimpleFileReceiver( CSimpleFileReceiver *pObj, IUnknown *pUnkOuter )				
		{																	
//			DEBUGCODE(m_cRef = 1L);											
			m_pObj		= pObj;												
			m_pUnkOuter	= pUnkOuter;										
		};																	
		~CImpSimpleFileReceiver() {};

		virtual STDMETHODIMP_(ULONG)   AddRef(void);
		virtual STDMETHODIMP_(ULONG)   Release(void);
		virtual STDMETHODIMP           QueryInterface(REFIID riid, LPVOID *ppv);
				STDMETHODIMP		   Initialize(LPUNKNOWN pTracer);
				STDMETHODIMP		   Uninitialize(void);
				STDMETHODIMP           GetCLSID(LPVARIANT pvCLSIDString);
				STDMETHODIMP		   Invoke
											(
											DISPID dispIdMember,
											REFIID riid,
											LCID lcid,
											WORD wFlags,
											DISPPARAMS  *pDispParams,
											VARIANT		*pVarResult,
											EXCEPINFO	*pExcepInfo,
											UINT		*puArgErr
											);
				STDMETHODIMP			GetIDsOfNames
											( 
											REFIID riid,
											LPOLESTR __RPC_FAR *rgszNames,
											UINT cNames,
											LCID lcid,
											DISPID __RPC_FAR *rgDispId
											);
				STDMETHODIMP			GetTypeInfoCount(UINT *pctinfo);
				STDMETHODIMP			GetTypeInfo
											(
											UINT iTInfo,
											LCID lcid,
											ITypeInfo  **ppTInfo
											);

	private:
		CSimpleFileReceiver*	m_pObj;											
		LPUNKNOWN				m_pUnkOuter;										
//		DEBUGCODE(ULONG m_cRef);

		// @cmember internal reference count
		ULONG							m_cRef;


};


/**************************************************************************
		Interface CImpSimpleFileNotify : Definition Begins
**************************************************************************/
class CImpSimpleFileNotify : public IDBTraceNotify
{
	public : //@access public
		CImpSimpleFileNotify( CSimpleFileReceiver *pObj, IUnknown *pUnkOuter )				
		{																	
//			DEBUGCODE(m_cRef = 1L);											
			m_pObj		= pObj;												
			m_pUnkOuter	= pUnkOuter;										
		};																	
		~CImpSimpleFileNotify() {};

		virtual STDMETHODIMP_(ULONG)   AddRef(void);
		virtual STDMETHODIMP_(ULONG)   Release(void);
		virtual STDMETHODIMP           QueryInterface(REFIID riid, LPVOID *ppv);
				STDMETHODIMP		   OnPackageReady(DBLENGTH cbPackageDataLen, BYTE* pPackageData);
				STDMETHODIMP		   Invoke
											(
											DISPID dispIdMember,
											REFIID riid,
											LCID lcid,
											WORD wFlags,
											DISPPARAMS  *pDispParams,
											VARIANT		*pVarResult,
											EXCEPINFO	*pExcepInfo,
											UINT		*puArgErr
											);
				STDMETHODIMP			GetIDsOfNames
											( 
											REFIID riid,
											LPOLESTR __RPC_FAR *rgszNames,
											UINT cNames,
											LCID lcid,
											DISPID __RPC_FAR *rgDispId
											);
				STDMETHODIMP			GetTypeInfoCount(UINT *pctinfo);
				STDMETHODIMP			GetTypeInfo
											(
											UINT iTInfo,
											LCID lcid,
											ITypeInfo  **ppTInfo
											);

	private:
		CSimpleFileReceiver*	m_pObj;											
		LPUNKNOWN				m_pUnkOuter;										
//		DEBUGCODE(ULONG m_cRef);

		// @cmember internal reference count
		ULONG							m_cRef;

};



/**************************************************************************
		Interface CSimpleFileReceiver : Definition Begins
**************************************************************************/
class CSimpleFileReceiver : public IUnknown				//@base public | IUnknown
{
	public:	 
			// @access public member functions
		CSimpleFileReceiver(LPUNKNOWN pUnkOuter);
		~CSimpleFileReceiver();

		virtual STDMETHODIMP_(ULONG) AddRef(void)
											{
												return DoAddRef(NULL);
											};
				STDMETHODIMP_(ULONG) DoAddRef(IUnknown* pUnk);
		virtual STDMETHODIMP_(ULONG) Release(void)
											{
												return DoRelease(NULL);
											};
				STDMETHODIMP_(ULONG) DoRelease(IUnknown* pUnk);

		virtual STDMETHODIMP         QueryInterface(REFIID riid, LPVOID *ppv);

				STDMETHODIMP		 Initialize(LPUNKNOWN pTracer);
				STDMETHODIMP		 Uninitialize(void);
				STDMETHODIMP		 OnPackageReady(DBLENGTH cbPackageDataLen, BYTE* pPackageData);
				STDMETHODIMP		 Invoke(DISPID dispIdMember,
										REFIID riid,
										LCID lcid,
										WORD wFlags,
										DISPPARAMS  *pDispParams,
										VARIANT		*pVarResult,
										EXCEPINFO	*pExcepInfo,
										UINT		*puArgErr);
				STDMETHODIMP		GetIDsOfNames( REFIID riid,
										LPOLESTR __RPC_FAR *rgszNames,
										UINT cNames,
										LCID lcid,
										DISPID __RPC_FAR *rgDispId);
				STDMETHODIMP		GetTypeInfoCount(UINT *pctinfo);
				STDMETHODIMP		GetTypeInfo(UINT iTInfo,
										LCID lcid,
										ITypeInfo  **ppTInfo);


				void VInit(void);

			// @access protected member functions

			void VTerminate(void);
			IDispatch*	m_pIDispatch;

			// @cmember Contained ImpSimpleFileReceiver
			CImpSimpleFileReceiver          m_ISimpleFileReceiver;

			// @cmember Contained ImpSimpleFileNotify
			CImpSimpleFileNotify            m_ISimpleFileNotify;

			// @cmember Contained dwCookie
			DWORD							m_dwCookie;

			// @cmember Contained dwCookie
			LONG							m_cObj;

			// @cmember internal reference count
			ULONG							m_cRef;

			// @cmember Contained Connection Point
			IConnectionPoint*				m_pCP;

			// @cmember Contained Outer Unknown
			LPUNKNOWN						m_pUnkOuter;

			// Output Stream
			FILE	*						m_fstream;

			// Trace Interpreter for Interpreting values
			IDBTraceInterpreter *			m_pIDBTraceInterpreter;

			// Package for Getting Data
			IDBTracePackage *				m_pIDBTracePackage;


			inline 		BOOL initlog(CHAR *filename)
			{
				if (NULL != m_fstream)
				{
					closelog();
				}

				m_fstream = fopen( filename, "w"); 
				
				return m_fstream ? TRUE: FALSE;
			}

			inline		BOOL closelog()
			{
				int rc = 0;

				if (NULL != m_fstream)
				{
					rc = fclose(m_fstream);
					m_fstream = NULL;
				}

				return rc;
			}
			inline		BOOL log(WCHAR *pwszString) 
			{
				if (NULL == m_fstream)
					return FALSE;

				if (WEOF != fputws(pwszString, m_fstream))
				{
					fflush(m_fstream);
					return TRUE;
				}
				else
				{
					fflush(m_fstream);
					return FALSE;
				}
			}

			STDMETHODIMP PrintParameter(
							IDBTraceParameter * pIDBTraceParameter);	

			STDMETHODIMP PrintParameterInfo(
							IDBTraceParameter * pIDBTraceParameter);

			STDMETHODIMP PrintTraceContext(DBTRACEINFO *  TraceInfo,
			                               TAGTYPE tgType);

			BOOL IsReferenceTypeOrString(LPWSTR pwstrType);
			HRESULT	GetLogFileName(BSTR* pbstrLogFileName);
};

#endif // __SIMPLEFILEREC__
