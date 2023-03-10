//-----------------------------------------------------------------------------------
// @PRODUCT:	Microsoft OLE DB Trace Provider Simple File Receiver
// @CPYRGHT:	Copyright (C) Microsoft Corporation, 1998 - 2000
//
// @module MSDASFR.H | Class Definitions for CClassFactory and 
// DLL Entry Points
//
//
#ifndef __MSDASFR__
#define __MSDASFR__

#define MAX_REGENTRY_LEN 300

#define NUMELEM(p1) (sizeof(p1) / sizeof(p1[0]))

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// Classes 
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// @class CClassFactory | ClassFactory for the Simple File Receiver CLSID
//----------------------------------------------------------------------------
class CSFRClassFactory : public IClassFactory		//@base public | IClassFactory
{
	public: // @access public
		//	IClassFactory members
		//@cmember Overloaded constructor
		CSFRClassFactory(LONG *pcLock, LONG *pcObj);
		~CSFRClassFactory();

		//	IUnknown members
		//@cmember Request an Interface
		STDMETHODIMP			QueryInterface(REFIID, LPVOID *);
		//@cmember Increments the Reference count
		STDMETHODIMP_(ULONG)	AddRef(void);
		//@cmember Decrements the Reference count
		STDMETHODIMP_(ULONG)	Release(void);

		//	IClassFactory members

	    //@cmember Lock Object so that it can not be unloaded
		STDMETHODIMP			LockServer(BOOL);
		//	IClassFactory members
		//@cmember Instantiates an uninitialized instance of an object
		STDMETHODIMP			CreateInstance(LPUNKNOWN, REFIID, LPVOID *);

	protected: //@access protected
		//@cmember Reference count
		ULONG					m_cRef;

		//@cmember Pointer to buffer for Lock Count
		LONG					*m_pcLock;

		//@cmember Pointer to buffer for Global Object Count
		LONG					*m_pcObj;

		//@cmember Pointer to free-threaded marshaler's IUnknown
		IUnknown*				m_pUnkFTM;
};

#endif	// __MSDASFR__
