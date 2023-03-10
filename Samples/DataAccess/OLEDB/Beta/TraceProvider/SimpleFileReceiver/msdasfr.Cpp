//-----------------------------------------------------------------------------------
// @PRODUCT:	Microsoft OLE DB Trace Provider Simple File Receiver
// @CPYRGHT:	Copyright (C) Microsoft Corporation, 1998 - 2000
//
// @module MSDASFR.CPP | The module contains the DLL Entry and Exit 
// points, plus the OLE ClassFactory class.
//
//

//-----------------------------------------------------------------------------
// Includes 
//-----------------------------------------------------------------------------
#pragma hdrstop
#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "msdasfr.h"
#include "msdatrc.h"

#include "SimpleFileReceiver.h"

//-----------------------------------------------------------------------------
// Forward Declarations.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------
HINSTANCE			ghDllInstance;
BOOL				g_fAnsiRegistry;
CRITICAL_SECTION	g_BaseObjListCriticalSection;
LONG				g_cLock = 0;
LONG				g_cObj = 0;

//-----------------------------------------------------------------------------
// Static vars 
//-----------------------------------------------------------------------------
typedef struct tagREGENTRIES
{
	LPSTR strRegKey;
	LPSTR strValueName;
	LPSTR strValue;
} REGENTRIES;

static const REGENTRIES s_rgRegInfo[] = 
{
	{ "MSDASFR", NULL, "Microsoft OLE DB Trace Provider Simple File Receiver" },
	{ "MSDASFR\\Clsid", NULL, "{29d82dee-2bdb-11d2-90e1-00805fc752eb}" },
	{ "CLSID\\{29d82dee-2bdb-11d2-90e1-00805fc752eb}", NULL, "MSDASFR" },
	{ "CLSID\\{29d82dee-2bdb-11d2-90e1-00805fc752eb}\\ProgID", NULL, "MSDASFR.1" },
	{ "CLSID\\{29d82dee-2bdb-11d2-90e1-00805fc752eb}\\VersionIndependentProgID", NULL, "MSDASFR" },
	{ "CLSID\\{29d82dee-2bdb-11d2-90e1-00805fc752eb}\\InprocServer32", NULL, "%s" },
	{ "CLSID\\{29d82dee-2bdb-11d2-90e1-00805fc752eb}\\InprocServer32", "ThreadingModel", "Both" },
	//Now more gritty - Finish registering Classes
	{"CLSID\\{29d82dee-2bdb-11d2-90e1-00805fc752eb}\\TypeLib", NULL, "{29d82dee-2bdb-11d2-90e1-00805fc752eb}"},
	{"CLSID\\{29d82dee-2bdb-11d2-90e1-00805fc752eb}\\Programmable", NULL, ""},
	//Now even more gritty - Registering a type library
	{"TypeLib\\{29d82dee-2bdb-11d2-90e1-00805fc752eb}", NULL, ""},
};

static const REGENTRIES s_rgRegInfoCurrentUser[] = 
{
	{ "Software\\Microsoft\\OLE DB\\Tracing\\Receivers\\MSDASFR", 
		"CLSID", "{29d82dee-2bdb-11d2-90e1-00805fc752eb}" },
	{ "Software\\Microsoft\\OLE DB\\Tracing\\Receivers\\MSDASFR",
		"STATUS", "DISABLED" },
};

#define INCREMENT_SIZE	5

CSimpleFileReceiver**	g_ppSFR;
LONG					g_lCur;
LONG					g_lMaxSize;
CRITICAL_SECTION		g_csSFR;


extern BOOL g_fAnsiRegistry;

//-----------------------------------------------------------------------------
// OnUnicodeSystem
//
// @func Determine if the OS that we are on, actually supports the unicode verion
// of the win32 API.  If YES, then g_fAnsiRegistry == FALSE.
//
// @rdesc True of False
//-----------------------------------------------------------------------------------
BOOL OnUnicodeSystem()
{
	BOOL	fUnicode = TRUE;
	HKEY	hkJunk = HKEY_CURRENT_USER;

	// Check to see if we have win95's broken registry, thus
	// do not have Unicode support in the OS
	if ((RegOpenKeyExW(HKEY_LOCAL_MACHINE,
					 L"SOFTWARE",
					 0,
					 KEY_READ,
					 &hkJunk) == ERROR_SUCCESS) &&
		hkJunk == HKEY_CURRENT_USER)
	{

	   // Try the ANSI version
		if ((RegOpenKeyExA(HKEY_LOCAL_MACHINE,
							 "SOFTWARE",
							 0,
							KEY_READ,
							&hkJunk) == ERROR_SUCCESS) &&
			(hkJunk != HKEY_CURRENT_USER))

		{
			fUnicode = FALSE;
		}
	}

	if (hkJunk != HKEY_CURRENT_USER)
		RegCloseKey(hkJunk);

	return fUnicode;
}


HRESULT ExpandReceiverArray()
{

	CSimpleFileReceiver**	ppSFR = new CSimpleFileReceiver*[g_lMaxSize + INCREMENT_SIZE];

	if (NULL == ppSFR)
	{
		return E_OUTOFMEMORY;
	}

	memset(ppSFR, 0, sizeof(CSimpleFileReceiver*)*(g_lMaxSize + INCREMENT_SIZE));
	memcpy(ppSFR, g_ppSFR, sizeof(CSimpleFileReceiver*)*g_lMaxSize);

	delete [] g_ppSFR;
	g_ppSFR = ppSFR;
	g_lMaxSize += INCREMENT_SIZE;

	return S_OK;
}

//-----------------------------------------------------------------------------
// DllMain
//
// @func DLL Entry point where Instance and Thread attach/detach notifications
// takes place.  Some current activity is OLE is being initialized and the
// IMalloc Interface pointer is obtained.
//
// @rdesc Boolean Flag
//		@flag TRUE | Successful initialization
//		@flag FALSE | Failure to intialize
//-----------------------------------------------------------------------------------
BOOL WINAPI DllMain
	(
	HINSTANCE	hInst,		//@parm IN | Application Instance Handle         
	DWORD		dwReason,	//@parm IN | Indicated Process or Thread activity
	LPVOID		lbv			//@parm IN | Reserved...                         
	)
{
	LONG l = 0;
    switch (dwReason)
    {
	    case DLL_PROCESS_ATTACH:
			ghDllInstance = hInst;
	        OnUnicodeSystem();
			DisableThreadLibraryCalls (hInst);

			g_ppSFR = NULL;
			g_lCur = 0;
			g_lMaxSize = 0;
			InitializeCriticalSection(&g_csSFR);

			break;

		case DLL_PROCESS_DETACH:
			for (l = 0; l < g_lCur; l++)
			{
				if (g_ppSFR[l] != NULL)
				{
					try
					{
						g_ppSFR[l]->Uninitialize();
					}
					catch( ... )
					{
					}
				}
			}
			g_lCur = 0;
			DeleteCriticalSection(&g_csSFR);
			break;
    }
    return TRUE;
}

//-----------------------------------------------------------------------------
// DllCanUnloadNow 
//
// @func Indicates whether the DLL is no longer in use and 
// can be unloaded.
//
// @rdesc HResult indicating status of routine
//		@flag S_OK | DLL can be unloaded now.
//	 	@flag S_FALSE | DLL cannot be unloaded now.
//-----------------------------------------------------------------------------------

STDAPI DllCanUnloadNow(void)
{
	return ResultFromScode((!g_cObj && !g_cLock) ? S_OK : S_FALSE);
}

//-----------------------------------------------------------------------------
// DllGetClassObject
//
// @func This function is exposed to OLE so that the classfactory can
// be obtained.
//
// @rdesc HResult indicating status of routine
//		@flag S_OK | The object was retrieved successfully.
//		@flag CLASS_E_CLASSNOTAVAILABLE	| DLL does not support class.
//		@flag E_OUTOFMEMORY	| Out of memory.
//		@flag E_INVALIDARG	| One or more arguments are invalid. 
//		@flag E_UNEXPECTED | An unexpected error occurred.
//-----------------------------------------------------------------------------------
STDAPI DllGetClassObject
	(
	REFCLSID    rclsid,			//@parm IN | CLSID of the object class to be loaded     
	REFIID      riid,			//@parm IN | Interface on object to be instantiated     
	LPVOID *	ppvObj			//@parm OUT | Pointer to interface that was instantiated
	)
{
	SCODE	sc = S_OK;

	// Note that QueryInterface does most of the checks for us.
	if (ppvObj)
		*ppvObj = NULL;

	try
	{
	    // Service CLSID_SimpleFileReceiver
		if (rclsid == CLSID_SimpleFileReceiver)
		{
			// We only support the IUnknown and IClassFactory interfaces
			if (riid != IID_IUnknown &&
				riid != IID_IClassFactory)
				return E_NOINTERFACE;

			// Create our ClassFactory object
			CSFRClassFactory* pClassFactory = new CSFRClassFactory(&g_cLock, &g_cObj);
			if (!pClassFactory)
				return E_OUTOFMEMORY;

			// Get the desired interface on this object
			if (FAILED(sc = pClassFactory->QueryInterface( riid, ppvObj )))
				throw(sc);

			pClassFactory->Release();
		}
	}
	catch ( ... )
	{
	}

	return sc;
}



//---------------------------------------------------------------------------
// @func	Removes keys from the registry.
//
// @rdesc Returns NOERROR
//
// @comm
// Special Notes:	This allows us to avoid using a .reg file.
//
// EJ 26-may-95: Note that a more robust method would be to trace existing
// CLSID and ProgID, and trace each from the other.  This would handle the
// case where either changed.  Then should probably enumerate all keys under
// the ProgID and CLSID, then delete them.
//
// @comm
// Revision History:
//
//	[00] MM-DD-YY	EMAIL_NAME	ACTION PERFORMED... <nl>
//	[01] 05-10-95	Kristib		Grabbed/munged from catcf <nl>
//  [02] 05-26-95   EricJ       Rewrote table-driven method
//---------------------------------------------------------------------------
HRESULT UnRegisterServer
	(
	const HKEY			hKey,
	const ULONG 		cEntries,
	const REGENTRIES	rgEntries[]
	)
{
	ULONG	i;
	int		iNumErrors = 0;
	LONG	stat;

	// Delete all table entries.  Loop in reverse order, since they
	// are entered in a basic-to-complex order.
	//
	// Win95: RegDeleteKey deletes key and all descendents.
	// WinNT: RegDeleteKey deletes specified key only.
	//        Cannot delete a key that has subkeys.
	//
	// What we really need is a function to delete all subkeys.
	// Ignore errors.
	
	for (i=cEntries; i > 0; i--)
	{
		stat = RegDeleteKeyA( hKey, rgEntries[i-1].strRegKey );
		if (stat != ERROR_SUCCESS && stat != ERROR_FILE_NOT_FOUND)
		{
			iNumErrors++;
		}
	}

	// We fail on error, since that gives proper message to end user.
	// DllRegisterServer should ignore these errors.
	return ResultFromScode( iNumErrors ? E_FAIL : S_OK );
}


//---------------------------------------------------------------------------
// @func	Adds necessary keys to the registry.
//
// @rdesc Returns one of the following
// @flag NOERROR	| Registration succeeded
// @flag E_FAIL		| Something didn't work
//
// 
// @comm
// Revision History:
//
//	[00] MM-DD-YY	EMAIL_NAME	ACTION PERFORMED... <nl>
//	[01] 05-10-95	KristiB		Grabbed/munged from catcf.cpp <nl>
//  [02] 05-25-95   EricJ       Rewrote table-driven method.
//---------------------------------------------------------------------------
HRESULT RegisterServer
	(
	const HINSTANCE		hInstance,
	const HKEY			hKey,
	const ULONG 		cEntries,
	const REGENTRIES	rgEntries[]
	)
{
	ULONG		i;
	HKEY		hk;
	DWORD		dwDisposition;
	LONG		stat;
	CHAR		strFileName[MAX_PATH+1];
	CHAR		szBuff[MAX_REGENTRY_LEN+1];
	int			cch;


	// Get the full path name for this DLL.
	// We recorded the hinstance upon DLL load.
//	Win4Assert(hInstance);

	if (0 == GetModuleFileNameA( hInstance, strFileName, NUMELEM(strFileName) ))
		return E_FAIL;

	// Make a clean start.
	// We ignore errors here.
	UnRegisterServer(hKey, cEntries, rgEntries);

	// Loop through s_rgRegInfo, and put everything in it.
	// Every entry is based on HKEY_CLASSES_ROOT.
	for (i=0; i < cEntries; i++)
	{
		// Create the Key.  If it exists, we open it.
		// Thus we can still change the value below.
		stat = RegCreateKeyExA(
				hKey,
				rgEntries[i].strRegKey,
				0,		// dwReserved
				NULL,	// lpszClass
				REG_OPTION_NON_VOLATILE,
				KEY_ALL_ACCESS,		// security access mask
				NULL,				// lpSecurityAttributes
				&hk,				// phkResult
				&dwDisposition );
		if (stat != ERROR_SUCCESS )
		{
			return ResultFromScode(E_FAIL);
		}

		// Assign a value, if we have one.
		if (rgEntries[i].strValue)
		{
			// Fill in any "%s" arguments with the name of this DLL.
			cch = wsprintfA( szBuff, rgEntries[i].strValue, strFileName );

			stat = RegSetValueExA(
					hk,							// created above
					rgEntries[i].strValueName,	// lpszValueName
					0,							// dwReserved
					REG_SZ,						// fdwType
					(BYTE *) szBuff,			// value
					cch + 1);					// cbData, including null terminator
			if (stat != ERROR_SUCCESS )
			{
				return ResultFromScode(E_FAIL);
			}
		}

		RegCloseKey( hk );
	}

	return ResultFromScode(S_OK);
}


//---------------------------------------------------------------------------
// @func	Removes keys from the registry.
//
// @rdesc Returns NOERROR
//
// @comm
// Special Notes:	This allows us to avoid using a .reg file.
//
// EJ 26-may-95: Note that a more robust method would be to trace existing
// CLSID and ProgID, and trace each from the other.  This would handle the
// case where either changed.  Then should probably enumerate all keys under
// the ProgID and CLSID, then delete them.
//
// @comm
// Revision History:
//
//	[00] MM-DD-YY	EMAIL_NAME	ACTION PERFORMED... <nl>
//	[01] 05-10-95	Kristib		Grabbed/munged from catcf <nl>
//  [02] 05-26-95   EricJ       Rewrote table-driven method
//---------------------------------------------------------------------------
STDAPI DllUnregisterServer( void )
{
	HRESULT hr = UnRegisterServer(HKEY_CLASSES_ROOT, 
	                              NUMELEM(s_rgRegInfo), 
								  s_rgRegInfo);

	if (FAILED(hr))
		UnRegisterServer(HKEY_CURRENT_USER, 
		                 NUMELEM(s_rgRegInfoCurrentUser), 
						 s_rgRegInfoCurrentUser);
	else
		hr = UnRegisterServer(HKEY_CURRENT_USER, 
		                      NUMELEM(s_rgRegInfoCurrentUser), 
							  s_rgRegInfoCurrentUser);

	return hr;
}


//---------------------------------------------------------------------------
// @func	Adds necessary keys to the registry.
//
// @rdesc Returns one of the following
// @flag NOERROR	| Registration succeeded
// @flag E_FAIL		| Something didn't work
//
// 
// @comm
// Revision History:
//
//	[00] MM-DD-YY	EMAIL_NAME	ACTION PERFORMED... <nl>
//	[01] 05-10-95	KristiB		Grabbed/munged from catcf.cpp <nl>
//  [02] 05-25-95   EricJ       Rewrote table-driven method.
//---------------------------------------------------------------------------

STDAPI DllRegisterServer(void)
{
	HRESULT hr = RegisterServer(ghDllInstance, 
	                            HKEY_CLASSES_ROOT, 
								NUMELEM(s_rgRegInfo), 
								s_rgRegInfo);
	if (SUCCEEDED(hr))
		hr = RegisterServer(ghDllInstance, 
		                    HKEY_CURRENT_USER, 
							NUMELEM(s_rgRegInfoCurrentUser), 
							s_rgRegInfoCurrentUser);

	return hr;
}




//-----------------------------------------------------------------------------
// CSFRClassFactory
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// CClassFactory 
//
// @mfunc Constructor for this class
//
// @rdesc NONE
//-----------------------------------------------------------------------------------
CSFRClassFactory::CSFRClassFactory
	(
	LONG				*pcLock,		// @parm IN | Lock pointer
	LONG				*pcObj			// @parm IN | Object Count pointer
	)
	: m_cRef(1),
	  m_pcLock(pcLock),
	  m_pcObj(pcObj)

{
//	Win4Assert(m_pcLock && m_pcObj);

	// Create the free-threaded marshaler for apartment-model support --
	// ignore errors for the sake of Win95
	(void)CoCreateFreeThreadedMarshaler(this, (IUnknown**)&m_pUnkFTM);

	// Increment global object count
	InterlockedIncrement(m_pcObj);
}


//-----------------------------------------------------------------------------
// ~CSFRClassFactory 
//
// @mfunc Destructor for this class
//
// @rdesc NONE
//-----------------------------------------------------------------------------------
CSFRClassFactory::~CSFRClassFactory(void)
{
	// Decrement global object count
	InterlockedDecrement(m_pcObj);

	if (m_pUnkFTM)
	{
		m_pUnkFTM->Release();
	}
}


// CreateInstance ------------------------------------------------------------
//
// @mfunc Creates an uninitialized instance of an object class.
// Initialization is subsequently performed using another
// interface-specific method
//
// @rdesc HRESULT indicating the status of the method
//      @flag S_OK          | Interface is supported and ppvObject is set.
//      @flag E_NOINTERFACE | Interface is not supported by the object
//      @flag E_INVALIDARG  | One or more arguments are invalid.
//      @flag E_OUTOFMEMORY | Memory could not be allocated
//      @flag OTHER         | Other HRESULTs returned by called functions
//
STDMETHODIMP CSFRClassFactory::CreateInstance
    (
    LPUNKNOWN   pUnkOuter,  //@parm IN | Points to the controlling IUnknown interface
    REFIID      riid,       //@parm IN | Interface ID of the interface being queried for.
    LPVOID *    ppvObj      //@parm OUT | Pointer to interface that was instantiated
    )
{
	CSimpleFileReceiver* pObj;
	HRESULT hr = E_OUTOFMEMORY;

	if(!ppvObj)
		return E_INVALIDARG;

	*ppvObj = NULL;

	if(pUnkOuter && (riid != IID_IUnknown))
		return CLASS_E_NOAGGREGATION;

	pObj = new CSimpleFileReceiver(NULL);

	if (pObj)
	{
		pObj->VInit();

		hr = pObj->QueryInterface(riid, ppvObj);

		if (SUCCEEDED(hr))
		{
			EnterCriticalSection(&g_csSFR);
			if (g_lCur >= g_lMaxSize)
			{
				hr = ExpandReceiverArray();
				if (FAILED(hr))
				{
					pObj->Release();
					*ppvObj = NULL;

					LeaveCriticalSection(&g_csSFR);
					return hr;
				}
			}

			g_ppSFR[g_lCur] = pObj;
			pObj->AddRef();
			InterlockedIncrement(&g_lCur);

			LeaveCriticalSection(&g_csSFR);
		}

		pObj->Release();

	}
	return hr;
}


//-----------------------------------------------------------------------------
// QueryInterface 
//
// @mfunc Returns a pointer to a specified interface. Callers use 
// QueryInterface to determine which interfaces the called object 
// supports. 
//
// @rdesc HResult indicating the status of the method
//		@flag S_OK | Interface is supported and ppvObject is set.
//		@flag E_NOINTERFACE | Interface is not supported by the object
//		@flag E_INVALIDARG | One or more arguments are invalid. 
//-----------------------------------------------------------------------------------

STDMETHODIMP CSFRClassFactory::QueryInterface
	(
	REFIID		riid,			//@parm IN | Interface ID of the interface being queried for.
	LPVOID *	ppvObj			//@parm OUT | Pointer to interface that was instantiated     
	)
{
	// Check for valid ppvObj pointer
	if( ppvObj )
	{
 		// Do we support this interface?
		if( riid == IID_IUnknown ||
			riid == IID_IClassFactory )
			*ppvObj = (LPVOID)this;
		else if(m_pUnkFTM)
		{
			SCODE sc;

			if( SUCCEEDED(sc = m_pUnkFTM->QueryInterface(riid, ppvObj)) )
				return sc;
			*ppvObj = NULL;
		}
		else
			*ppvObj = NULL;

		// If we're going to return an interface, AddRef it first
		if( *ppvObj )
		{
			((LPUNKNOWN)*ppvObj)->AddRef();
			return S_OK;
		}

		return E_NOINTERFACE;
	}

	return E_INVALIDARG;

}


//-----------------------------------------------------------------------------
// AddRef 
//
// @mfunc Increments a persistence count for the object
//
// @rdesc Current reference count
//-----------------------------------------------------------------------------------

STDMETHODIMP_(ULONG) CSFRClassFactory::AddRef (void)
{
	return InterlockedIncrement( (long*) &m_cRef);
}


//-----------------------------------------------------------------------------
// Release 
//
// @mfunc Decrements a persistence count for the object and if
// persistence count is 0, the object destroys itself.
//
// @rdesc Current reference count
//-----------------------------------------------------------------------------------

STDMETHODIMP_(ULONG) CSFRClassFactory::Release (void)
{
	ULONG	cRef;

	if( !(cRef = InterlockedDecrement( (long*) &m_cRef)) )
	{
		delete this;
		return 0;
	}

	return cRef;
}


//-----------------------------------------------------------------------------
// LockServer 
//
// @mfunc Controls whether an object application is kept in memory. 
// Keeping the application alive in memory allows instances of this 
// class to be created more quickly.
//
// @rdesc HResult indicating the status of the method
//		@flag S_OK | Interface is supported and ppvObject is set.
//-----------------------------------------------------------------------------------

STDMETHODIMP CSFRClassFactory::LockServer
	(
	BOOL fLock					//@parm IN | TRUE or FALSE to lock or unlock
	)
{
	if( fLock )
		InterlockedIncrement(m_pcLock);
	else
		InterlockedDecrement(m_pcLock);

	return NOERROR;
}

