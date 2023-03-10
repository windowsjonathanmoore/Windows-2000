

//+============================================================================
//
//  Sample:     enumall.cpp
//
//  To Build:   cl /GX enumall.cpp
//
//  This sample is a program which dumps all the properties in all property
//  sets of a storage file.
//
//+============================================================================

#define UNICODE
#define _UNICODE

#include <stdio.h>
#include <windows.h>

#pragma comment( lib, "ole32.lib" )
#pragma comment( lib, "user32.lib" )


//+----------------------------------------------------------------------------
//
//  ConvertVarTypeToString
//  
//  Generate a string for a given vt.  It is assumed for simplicity that 
//  the pwszType parameter points to a buffer that is at least MAX_PATH
//  in length.
//
//+----------------------------------------------------------------------------

void
ConvertVarTypeToString( VARTYPE vt, WCHAR *pwszType )
{
    switch( vt & VT_TYPEMASK )
    {
    case VT_EMPTY:
        wcscpy( pwszType, L"VT_EMPTY" );
        break;
    case VT_NULL:
        wcscpy( pwszType, L"VT_NULL" );
        break;
    case VT_I2:
        wcscpy( pwszType, L"VT_I2" );
        break;
    case VT_I4:
        wcscpy( pwszType, L"VT_I4" );
        break;
    case VT_I8:
        wcscpy( pwszType, L"VT_I8" );
        break;
    case VT_UI2:
        wcscpy( pwszType, L"VT_UI2" );
        break;
    case VT_UI4:
        wcscpy( pwszType, L"VT_UI4" );
        break;
    case VT_UI8:
        wcscpy( pwszType, L"VT_UI8" );
        break;
    case VT_R4:
        wcscpy( pwszType, L"VT_R4" );
        break;
    case VT_R8:
        wcscpy( pwszType, L"VT_R8" );
        break;
    case VT_CY:
        wcscpy( pwszType, L"VT_CY" );
        break;
    case VT_DATE:
        wcscpy( pwszType, L"VT_DATE" );
        break;
    case VT_BSTR:
        wcscpy( pwszType, L"VT_BSTR" );
        break;
    case VT_ERROR:
        wcscpy( pwszType, L"VT_ERROR" );
        break;
    case VT_BOOL:
        wcscpy( pwszType, L"VT_BOOL" );
        break;
    case VT_VARIANT:
        wcscpy( pwszType, L"VT_VARIANT" );
        break;
    case VT_DECIMAL:
        wcscpy( pwszType, L"VT_DECIMAL" );
        break;
    case VT_I1:
        wcscpy( pwszType, L"VT_I1" );
        break;
    case VT_UI1:
        wcscpy( pwszType, L"VT_UI1" );
        break;
    case VT_INT:
        wcscpy( pwszType, L"VT_INT" );
        break;
    case VT_UINT:
        wcscpy( pwszType, L"VT_UINT" );
        break;
    case VT_VOID:
        wcscpy( pwszType, L"VT_VOID" );
        break;
    case VT_SAFEARRAY:
        wcscpy( pwszType, L"VT_SAFEARRAY" );
        break;
    case VT_USERDEFINED:
        wcscpy( pwszType, L"VT_USERDEFINED" );
        break;
    case VT_LPSTR:
        wcscpy( pwszType, L"VT_LPSTR" );
        break;
    case VT_LPWSTR:
        wcscpy( pwszType, L"VT_LPWSTR" );
        break;
    case VT_RECORD:
        wcscpy( pwszType, L"VT_RECORD" );
        break;
    case VT_FILETIME:
        wcscpy( pwszType, L"VT_FILETIME" );
        break;
    case VT_BLOB:
        wcscpy( pwszType, L"VT_BLOB" );
        break;
    case VT_STREAM:
        wcscpy( pwszType, L"VT_STREAM" );
        break;
    case VT_STORAGE:
        wcscpy( pwszType, L"VT_STORAGE" );
        break;
    case VT_STREAMED_OBJECT:
        wcscpy( pwszType, L"VT_STREAMED_OBJECT" );
        break;
    case VT_STORED_OBJECT:
        wcscpy( pwszType, L"VT_BLOB_OBJECT" );
        break;
    case VT_CF:
        wcscpy( pwszType, L"VT_CF" );
        break;
    case VT_CLSID:
        wcscpy( pwszType, L"VT_CLSID" );
        break;
    default:
        wsprintf( pwszType, L"Unknown (%d)", vt & VT_TYPEMASK );
        break;
    }

    if( vt & VT_VECTOR )
        wcscat( pwszType, L" | VT_VECTOR" );
    if( vt & VT_ARRAY )
        wcscat( pwszType, L" | VT_ARRAY" );
    if( vt & VT_RESERVED )
        wcscat( pwszType, L" | VT_RESERVED" );
}


//+----------------------------------------------------------------------------
//
//  ConvertValueToString
//  
//  Generate a string for the value in a given PROPVARIANT structure.
//  The most common types are supported (i.e., those that can be displayed
//  with printf).  For other types, just a "..." is used.
//
//  It is assumed for simplicity that the pwszValue parameter points to
//  a buffer that is at least MAX_PATH in length.
//
//+----------------------------------------------------------------------------

void
ConvertValueToString( const PROPVARIANT &propvar, WCHAR *pwszValue )
{
    switch( propvar.vt )
    {
    case VT_EMPTY:
        wcscpy( pwszValue, L"" );
        break;
    case VT_NULL:
        wcscpy( pwszValue, L"" );
        break;
    case VT_I2:
        swprintf( pwszValue, L"%i", propvar.iVal );
        break;
    case VT_I4:
    case VT_INT:
        swprintf( pwszValue, L"%li", propvar.lVal );
        break;
    case VT_I8:
        swprintf( pwszValue, L"%I64i", propvar.hVal );
        break;
    case VT_UI2:
        swprintf( pwszValue, L"%u", propvar.uiVal );
        break;
    case VT_UI4:
    case VT_UINT:
        swprintf( pwszValue, L"%lu", propvar.ulVal );
        break;
    case VT_UI8:
        swprintf( pwszValue, L"%I64u", propvar.uhVal );
        break;
    case VT_R4:
        swprintf( pwszValue, L"%f", propvar.fltVal );
        break;
    case VT_R8:
        swprintf( pwszValue, L"%lf", propvar.dblVal );
        break;
    case VT_BSTR:
        swprintf( pwszValue, L"\"%s\"", propvar.bstrVal );
        break;
    case VT_ERROR:
        swprintf( pwszValue, L"0x%08X", propvar.scode );
        break;
    case VT_BOOL:
        swprintf( pwszValue, L"%s", VARIANT_TRUE == propvar.boolVal ? L"True" : L"False" );
        break;
    case VT_I1:
        swprintf( pwszValue, L"%i", propvar.cVal );
        break;
    case VT_UI1:
        swprintf( pwszValue, L"%u", propvar.bVal );
        break;
    case VT_VOID:
        wcscpy( pwszValue, L"" );
        break;
    case VT_LPSTR:
        swprintf( pwszValue, L"\"%hs\"", propvar.pszVal );
        break;
    case VT_LPWSTR:
        swprintf( pwszValue, L"\"%s\"", propvar.pwszVal );
        break;
    case VT_FILETIME:
        swprintf( pwszValue, L"%08x:%08x", propvar.filetime.dwHighDateTime, propvar.filetime.dwLowDateTime );
        break;
    case VT_CLSID:
        pwszValue[0] = L'\0';
        StringFromGUID2( *propvar.puuid, pwszValue, MAX_PATH );
        break;
    default:
        wcscpy( pwszValue, L"..." );
        break;
    }

}


//+----------------------------------------------------------------------------
//
//  DumpProperty
//
//  Dump the ID, name, type, and value of a property.
//
//+----------------------------------------------------------------------------

void
DumpProperty( const PROPVARIANT &propvar, const STATPROPSTG &statpropstg )
{
    WCHAR wsz[ MAX_PATH + 1 ];

    ConvertVarTypeToString( statpropstg.vt, wsz );
    wprintf( L"   ----------------------------------------------------\n"
             L"   PropID = %-5d VarType = %-23s", statpropstg.propid, wsz );

    if( NULL != statpropstg.lpwstrName )
        wprintf( L" Name = %s", statpropstg.lpwstrName );

    ConvertValueToString( propvar, wsz );
    wprintf( L"\n   Value = %s\n", wsz ); 

}


//+----------------------------------------------------------------------------
//
//  DumpPropertySet
//
//  Dump all the properties in a given property set.
//
//+----------------------------------------------------------------------------

void
DumpPropertySet( IPropertyStorage *pPropStg )
{
    IEnumSTATPROPSTG *penum = NULL;
    HRESULT hr = S_OK;
    STATPROPSTG statpropstg;
    PROPVARIANT propvar;
    PROPSPEC propspec;

    PropVariantInit( &propvar );

    try
    {
        // If this property set has a friendly name, display it now.

        PROPID propid = PID_DICTIONARY;
        WCHAR *pwszFriendlyName = NULL;
        hr = pPropStg->ReadPropertyNames( 1, &propid, &pwszFriendlyName );
        if( S_OK == hr )
        {
            wprintf( L" (\"%s\")\n\n", pwszFriendlyName );
            CoTaskMemFree( pwszFriendlyName );
            pwszFriendlyName = NULL;
        }
        else
            wprintf( L"\n" );

        // Get a property enumerator

        hr = pPropStg->Enum( &penum );
        if( FAILED(hr) ) throw L"Failed IPropertyStorage::Enum";

        // Get the first property in the enumeration

        memset( &statpropstg, 0, sizeof(statpropstg) );
        hr = penum->Next( 1, &statpropstg, NULL );
        while( S_OK == hr )
        {

            // Read the property out of the property set

            PropVariantInit( &propvar );
            propspec.ulKind = PRSPEC_PROPID;
            propspec.propid = statpropstg.propid;

            hr = pPropStg->ReadMultiple( 1, &propspec, &propvar );
            if( FAILED(hr) ) throw L"Failed IPropertyStorage::ReadMultiple";

            // Display the property value, type, etc.

            DumpProperty( propvar, statpropstg );

            // Free buffers that were allocated during the read and
            // by the enumerator.

            PropVariantClear( &propvar );
            CoTaskMemFree( statpropstg.lpwstrName );
            statpropstg.lpwstrName = NULL;

            // Move to the next property in the enumeration

            hr = penum->Next( 1, &statpropstg, NULL );
        }
        if( FAILED(hr) ) throw L"Failed IEnumSTATPROPSTG::Next";
    }
    catch( LPCWSTR pwszErrorMessage )
    {
        wprintf( L"Error in DumpPropertySet: %s (hr = %08x)\n", pwszErrorMessage, hr );
    }

    if( NULL != penum )
        penum->Release();
    if( NULL != statpropstg.lpwstrName )
        CoTaskMemFree( statpropstg.lpwstrName );
    PropVariantClear( &propvar );
}


//+----------------------------------------------------------------------------
//
//  DumpPropertySetsInStorage
//
//  Dump the property sets in the top level of a given storage.
//
//+----------------------------------------------------------------------------

void
DumpPropertySetsInStorage( const WCHAR *pwszStorageName, 
                           IPropertySetStorage *pPropSetStg )
{
    IEnumSTATPROPSETSTG *penum = NULL;
    HRESULT hr = S_OK;
    IPropertyStorage *pPropStg = NULL;
    STATPROPSETSTG statpropsetstg;

    try
    {
        // Get a property set enumerator (which only enumerates the property
        // sets at this level of the storage, not its children).

        hr = pPropSetStg->Enum( &penum );
        if( FAILED(hr) ) throw L"failed IPropertySetStorage::Enum";

        // Get the first property set in the enumeration.

        memset( &statpropsetstg, 0, sizeof(statpropsetstg) );
        hr = penum->Next( 1, &statpropsetstg, NULL );
        while( S_OK == hr )
        {
            WCHAR wszFMTID[ CCH_MAX_PROPSTG_NAME + 1 ] = { L"" };

            // Open the property set

            hr = pPropSetStg->Open( statpropsetstg.fmtid,
                                    STGM_READ | STGM_SHARE_EXCLUSIVE,
                                    &pPropStg );
            if( FAILED(hr) ) throw L"failed IPropertySetStorage::Open";

            
            // Display the name of the property set

            StringFromGUID2( statpropsetstg.fmtid,
                             wszFMTID,
                             sizeof(wszFMTID)/sizeof(wszFMTID[0]) );
            wprintf( L"\n Property Set %s in %s:\n",
                     wszFMTID, pwszStorageName );

            // Display the properties in the property set

            DumpPropertySet( pPropStg );

            pPropStg->Release();
            pPropStg = NULL;

            // Get the FMTID of the next property set in the enumeration.

            hr = penum->Next( 1, &statpropsetstg, NULL );
        }
        if( FAILED(hr) ) throw L"Failed IEnumSTATPROPSETSTG::Next";
    }
    catch( LPCWSTR pwszErrorMessage )
    {
        wprintf( L"Error in DumpPropertySetsInStorage: %s (hr = %08x)\n",
                 pwszErrorMessage, hr );
    }

    if( NULL != pPropStg )
        pPropStg->Release();
    if( NULL != penum )
        penum->Release();
}


//+----------------------------------------------------------------------------
//
//  DumpStorageTree
//
//  Dump all the property sets in the given storage and in recursively in
//  all of its children.
//
//+----------------------------------------------------------------------------

void
DumpStorageTree( const WCHAR *pwszStorageName, IStorage *pStg )
{
    IPropertySetStorage *pPropSetStg = NULL;
    IStorage *pStgChild = NULL;
    WCHAR *pwszChildStorageName = NULL;
    IEnumSTATSTG *penum = NULL;
    HRESULT hr = S_OK;
    STATSTG statstg;

    try
    {
        // Dump the property sets at this storage level

        hr = pStg->QueryInterface( IID_IPropertySetStorage, reinterpret_cast<void**>(&pPropSetStg) );
        if( FAILED(hr) ) throw L"Failed IStorage::QueryInterface(IID_IPropertySetStorage)";

        DumpPropertySetsInStorage( pwszStorageName, pPropSetStg );

        // Get an enumerator for this storage.

        hr = pStg->EnumElements( NULL, NULL, NULL, &penum );
        if( FAILED(hr) ) throw L"failed IStorage::Enum";

        // Get the name of the first element (stream/storage) in the enumeration.

        memset( &statstg, 0, sizeof(statstg) );
        hr = penum->Next( 1, &statstg, 0 );
        while( S_OK == hr )
        {
            // Is this a storage that isn't a property set
            // (since we already displayed the property sets above)?

            if( STGTY_STORAGE == statstg.type
                &&
                L'\005' != statstg.pwcsName[0] )
            {
                // Yes, this is a normal storage.
                // Open the storage.

                hr = pStg->OpenStorage( statstg.pwcsName,
                                        NULL,
                                        STGM_READ | STGM_SHARE_EXCLUSIVE,
                                        NULL, 0,
                                        &pStgChild );
                if( FAILED(hr) ) throw L"failed IStorage::OpenStorage";

                // Compose a name of the form "Storage\ChildStorage\..."

                pwszChildStorageName = new WCHAR[ wcslen(pwszStorageName)
                                                  +
                                                  wcslen(statstg.pwcsName) + 2 ];
                if( NULL == pwszChildStorageName )
                {
                    hr = HRESULT_FROM_WIN32(ERROR_NOT_ENOUGH_MEMORY);
                    throw L"couldn't allocate memory";
                }

                wcscpy( pwszChildStorageName, pwszStorageName );
                wcscat( pwszChildStorageName, L"\\" );
                wcscat( pwszChildStorageName, statstg.pwcsName );

                // Dump all the property sets under this child storage.

                DumpStorageTree( pwszChildStorageName, pStgChild );

                pStgChild->Release();
                pStgChild = NULL;

                delete pwszChildStorageName;
                pwszChildStorageName = NULL;
            }

            // Move on to the next element in the enumeration of this storage.

            CoTaskMemFree( statstg.pwcsName );
            statstg.pwcsName = NULL;

            hr = penum->Next( 1, &statstg, 0 );
        }
        if( FAILED(hr) ) throw L"failed IEnumSTATSTG::Next";
    }
    catch( LPCWSTR pwszErrorMessage )
    {
        wprintf( L"Error in DumpStorageTree: %s (hr = %08x)\n",
                 pwszErrorMessage, hr );
    }

    if( NULL != pStgChild )
        pStgChild->Release();
    if( NULL != penum )
        penum->Release();
    if( NULL != pwszChildStorageName )
        delete pwszChildStorageName;
    
}


//+----------------------------------------------------------------------------
//
//  wmain
//
//  Dump all the property sets in a file which is a storage.
//
//+----------------------------------------------------------------------------

extern "C" void wmain( int cArgs, WCHAR *rgwszArgs[] )
{
    HRESULT hr = S_OK;
    IStorage *pStg = NULL;

    // Display usage info if necessary.

    if( 1 == cArgs
        ||
        0 == wcscmp( L"-?", rgwszArgs[1] )
        ||
        0 == wcscmp( L"/?", rgwszArgs[1] ))
    {
        printf( "\n"
                "Purpose:  Enumerate all properties in all property sets for a storage file\n"
                "Usage:    PropDump <filename>\n"
                "E.g.:     PropDump word.doc\n"
                "\n" );
        exit(0);
    }

    // Open the root storage.

    hr = StgOpenStorageEx( rgwszArgs[1],
                           STGM_READ | STGM_SHARE_DENY_WRITE,
                           STGFMT_ANY,
                           0,
                           NULL,
                           NULL,
                           IID_IStorage,
                           reinterpret_cast<void**>(&pStg) );

    // Dump all of the properties in all of the sets within this
    // storage.

    if( FAILED(hr) )
    {
        wprintf( L"Error:  couldn't open file %s (hr = %08x)\n",
                 rgwszArgs[1], hr );
    }
    else
    {
        printf( "\n" );
        DumpStorageTree( rgwszArgs[1], pStg );
    }

    if( NULL != pStg )
        pStg->Release();

}
