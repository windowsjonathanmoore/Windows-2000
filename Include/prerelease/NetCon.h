
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0345 */
/* Compiler settings for netcon.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __netcon_h__
#define __netcon_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IEnumNetConnection_FWD_DEFINED__
#define __IEnumNetConnection_FWD_DEFINED__
typedef interface IEnumNetConnection IEnumNetConnection;
#endif 	/* __IEnumNetConnection_FWD_DEFINED__ */


#ifndef __INetConnection_FWD_DEFINED__
#define __INetConnection_FWD_DEFINED__
typedef interface INetConnection INetConnection;
#endif 	/* __INetConnection_FWD_DEFINED__ */


#ifndef __INetConnectionManager_FWD_DEFINED__
#define __INetConnectionManager_FWD_DEFINED__
typedef interface INetConnectionManager INetConnectionManager;
#endif 	/* __INetConnectionManager_FWD_DEFINED__ */


#ifndef __INetConnectionConnectUi_FWD_DEFINED__
#define __INetConnectionConnectUi_FWD_DEFINED__
typedef interface INetConnectionConnectUi INetConnectionConnectUi;
#endif 	/* __INetConnectionConnectUi_FWD_DEFINED__ */


#ifndef __INetConnectionPropertyUi_FWD_DEFINED__
#define __INetConnectionPropertyUi_FWD_DEFINED__
typedef interface INetConnectionPropertyUi INetConnectionPropertyUi;
#endif 	/* __INetConnectionPropertyUi_FWD_DEFINED__ */


#ifndef __INetConnectionCommonUi_FWD_DEFINED__
#define __INetConnectionCommonUi_FWD_DEFINED__
typedef interface INetConnectionCommonUi INetConnectionCommonUi;
#endif 	/* __INetConnectionCommonUi_FWD_DEFINED__ */


#ifndef __IEnumNetSharingPortMapping_FWD_DEFINED__
#define __IEnumNetSharingPortMapping_FWD_DEFINED__
typedef interface IEnumNetSharingPortMapping IEnumNetSharingPortMapping;
#endif 	/* __IEnumNetSharingPortMapping_FWD_DEFINED__ */


#ifndef __INetSharingPortMappingProps_FWD_DEFINED__
#define __INetSharingPortMappingProps_FWD_DEFINED__
typedef interface INetSharingPortMappingProps INetSharingPortMappingProps;
#endif 	/* __INetSharingPortMappingProps_FWD_DEFINED__ */


#ifndef __INetSharingPortMapping_FWD_DEFINED__
#define __INetSharingPortMapping_FWD_DEFINED__
typedef interface INetSharingPortMapping INetSharingPortMapping;
#endif 	/* __INetSharingPortMapping_FWD_DEFINED__ */


#ifndef __IEnumNetSharingApplicationDefinition_FWD_DEFINED__
#define __IEnumNetSharingApplicationDefinition_FWD_DEFINED__
typedef interface IEnumNetSharingApplicationDefinition IEnumNetSharingApplicationDefinition;
#endif 	/* __IEnumNetSharingApplicationDefinition_FWD_DEFINED__ */


#ifndef __INetSharingApplicationDefinitionResponseRangeProps_FWD_DEFINED__
#define __INetSharingApplicationDefinitionResponseRangeProps_FWD_DEFINED__
typedef interface INetSharingApplicationDefinitionResponseRangeProps INetSharingApplicationDefinitionResponseRangeProps;
#endif 	/* __INetSharingApplicationDefinitionResponseRangeProps_FWD_DEFINED__ */


#ifndef __INetSharingApplicationDefinitionProps_FWD_DEFINED__
#define __INetSharingApplicationDefinitionProps_FWD_DEFINED__
typedef interface INetSharingApplicationDefinitionProps INetSharingApplicationDefinitionProps;
#endif 	/* __INetSharingApplicationDefinitionProps_FWD_DEFINED__ */


#ifndef __INetSharingApplicationDefinition_FWD_DEFINED__
#define __INetSharingApplicationDefinition_FWD_DEFINED__
typedef interface INetSharingApplicationDefinition INetSharingApplicationDefinition;
#endif 	/* __INetSharingApplicationDefinition_FWD_DEFINED__ */


#ifndef __IEnumNetSharingEveryConnection_FWD_DEFINED__
#define __IEnumNetSharingEveryConnection_FWD_DEFINED__
typedef interface IEnumNetSharingEveryConnection IEnumNetSharingEveryConnection;
#endif 	/* __IEnumNetSharingEveryConnection_FWD_DEFINED__ */


#ifndef __IEnumNetSharingPublicConnection_FWD_DEFINED__
#define __IEnumNetSharingPublicConnection_FWD_DEFINED__
typedef interface IEnumNetSharingPublicConnection IEnumNetSharingPublicConnection;
#endif 	/* __IEnumNetSharingPublicConnection_FWD_DEFINED__ */


#ifndef __IEnumNetSharingPrivateConnection_FWD_DEFINED__
#define __IEnumNetSharingPrivateConnection_FWD_DEFINED__
typedef interface IEnumNetSharingPrivateConnection IEnumNetSharingPrivateConnection;
#endif 	/* __IEnumNetSharingPrivateConnection_FWD_DEFINED__ */


#ifndef __INetSharingPortMappingCollection_FWD_DEFINED__
#define __INetSharingPortMappingCollection_FWD_DEFINED__
typedef interface INetSharingPortMappingCollection INetSharingPortMappingCollection;
#endif 	/* __INetSharingPortMappingCollection_FWD_DEFINED__ */


#ifndef __INetConnectionProps_FWD_DEFINED__
#define __INetConnectionProps_FWD_DEFINED__
typedef interface INetConnectionProps INetConnectionProps;
#endif 	/* __INetConnectionProps_FWD_DEFINED__ */


#ifndef __INetSharingConfiguration_FWD_DEFINED__
#define __INetSharingConfiguration_FWD_DEFINED__
typedef interface INetSharingConfiguration INetSharingConfiguration;
#endif 	/* __INetSharingConfiguration_FWD_DEFINED__ */


#ifndef __INetSharingEveryConnectionCollection_FWD_DEFINED__
#define __INetSharingEveryConnectionCollection_FWD_DEFINED__
typedef interface INetSharingEveryConnectionCollection INetSharingEveryConnectionCollection;
#endif 	/* __INetSharingEveryConnectionCollection_FWD_DEFINED__ */


#ifndef __INetSharingPublicConnectionCollection_FWD_DEFINED__
#define __INetSharingPublicConnectionCollection_FWD_DEFINED__
typedef interface INetSharingPublicConnectionCollection INetSharingPublicConnectionCollection;
#endif 	/* __INetSharingPublicConnectionCollection_FWD_DEFINED__ */


#ifndef __INetSharingPrivateConnectionCollection_FWD_DEFINED__
#define __INetSharingPrivateConnectionCollection_FWD_DEFINED__
typedef interface INetSharingPrivateConnectionCollection INetSharingPrivateConnectionCollection;
#endif 	/* __INetSharingPrivateConnectionCollection_FWD_DEFINED__ */


#ifndef __INetSharingApplicationDefinitionCollection_FWD_DEFINED__
#define __INetSharingApplicationDefinitionCollection_FWD_DEFINED__
typedef interface INetSharingApplicationDefinitionCollection INetSharingApplicationDefinitionCollection;
#endif 	/* __INetSharingApplicationDefinitionCollection_FWD_DEFINED__ */


#ifndef __INetSharingManager_FWD_DEFINED__
#define __INetSharingManager_FWD_DEFINED__
typedef interface INetSharingManager INetSharingManager;
#endif 	/* __INetSharingManager_FWD_DEFINED__ */


#ifndef __NetSharingManager_FWD_DEFINED__
#define __NetSharingManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingManager NetSharingManager;
#else
typedef struct NetSharingManager NetSharingManager;
#endif /* __cplusplus */

#endif 	/* __NetSharingManager_FWD_DEFINED__ */


#ifndef __NetSharingConfiguration_FWD_DEFINED__
#define __NetSharingConfiguration_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingConfiguration NetSharingConfiguration;
#else
typedef struct NetSharingConfiguration NetSharingConfiguration;
#endif /* __cplusplus */

#endif 	/* __NetSharingConfiguration_FWD_DEFINED__ */


#ifndef __NetSharingPortMapping_FWD_DEFINED__
#define __NetSharingPortMapping_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingPortMapping NetSharingPortMapping;
#else
typedef struct NetSharingPortMapping NetSharingPortMapping;
#endif /* __cplusplus */

#endif 	/* __NetSharingPortMapping_FWD_DEFINED__ */


#ifndef __NetSharingApplicationDefinition_FWD_DEFINED__
#define __NetSharingApplicationDefinition_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingApplicationDefinition NetSharingApplicationDefinition;
#else
typedef struct NetSharingApplicationDefinition NetSharingApplicationDefinition;
#endif /* __cplusplus */

#endif 	/* __NetSharingApplicationDefinition_FWD_DEFINED__ */


#ifndef __EnumNetSharingPortMapping_FWD_DEFINED__
#define __EnumNetSharingPortMapping_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumNetSharingPortMapping EnumNetSharingPortMapping;
#else
typedef struct EnumNetSharingPortMapping EnumNetSharingPortMapping;
#endif /* __cplusplus */

#endif 	/* __EnumNetSharingPortMapping_FWD_DEFINED__ */


#ifndef __EnumNetSharingApplicationDefinition_FWD_DEFINED__
#define __EnumNetSharingApplicationDefinition_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumNetSharingApplicationDefinition EnumNetSharingApplicationDefinition;
#else
typedef struct EnumNetSharingApplicationDefinition EnumNetSharingApplicationDefinition;
#endif /* __cplusplus */

#endif 	/* __EnumNetSharingApplicationDefinition_FWD_DEFINED__ */


#ifndef __EnumNetSharingPublicConnection_FWD_DEFINED__
#define __EnumNetSharingPublicConnection_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumNetSharingPublicConnection EnumNetSharingPublicConnection;
#else
typedef struct EnumNetSharingPublicConnection EnumNetSharingPublicConnection;
#endif /* __cplusplus */

#endif 	/* __EnumNetSharingPublicConnection_FWD_DEFINED__ */


#ifndef __EnumNetSharingPrivateConnection_FWD_DEFINED__
#define __EnumNetSharingPrivateConnection_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumNetSharingPrivateConnection EnumNetSharingPrivateConnection;
#else
typedef struct EnumNetSharingPrivateConnection EnumNetSharingPrivateConnection;
#endif /* __cplusplus */

#endif 	/* __EnumNetSharingPrivateConnection_FWD_DEFINED__ */


#ifndef __NetSharingEveryConnectionCollection_FWD_DEFINED__
#define __NetSharingEveryConnectionCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingEveryConnectionCollection NetSharingEveryConnectionCollection;
#else
typedef struct NetSharingEveryConnectionCollection NetSharingEveryConnectionCollection;
#endif /* __cplusplus */

#endif 	/* __NetSharingEveryConnectionCollection_FWD_DEFINED__ */


#ifndef __NetSharingPublicConnectionCollection_FWD_DEFINED__
#define __NetSharingPublicConnectionCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingPublicConnectionCollection NetSharingPublicConnectionCollection;
#else
typedef struct NetSharingPublicConnectionCollection NetSharingPublicConnectionCollection;
#endif /* __cplusplus */

#endif 	/* __NetSharingPublicConnectionCollection_FWD_DEFINED__ */


#ifndef __NetSharingPrivateConnectionCollection_FWD_DEFINED__
#define __NetSharingPrivateConnectionCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingPrivateConnectionCollection NetSharingPrivateConnectionCollection;
#else
typedef struct NetSharingPrivateConnectionCollection NetSharingPrivateConnectionCollection;
#endif /* __cplusplus */

#endif 	/* __NetSharingPrivateConnectionCollection_FWD_DEFINED__ */


#ifndef __NetSharingApplicationDefinitionCollection_FWD_DEFINED__
#define __NetSharingApplicationDefinitionCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingApplicationDefinitionCollection NetSharingApplicationDefinitionCollection;
#else
typedef struct NetSharingApplicationDefinitionCollection NetSharingApplicationDefinitionCollection;
#endif /* __cplusplus */

#endif 	/* __NetSharingApplicationDefinitionCollection_FWD_DEFINED__ */


#ifndef __NetSharingPortMappingCollection_FWD_DEFINED__
#define __NetSharingPortMappingCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingPortMappingCollection NetSharingPortMappingCollection;
#else
typedef struct NetSharingPortMappingCollection NetSharingPortMappingCollection;
#endif /* __cplusplus */

#endif 	/* __NetSharingPortMappingCollection_FWD_DEFINED__ */


#ifndef __NetSharingApplicationDefinitionResponseRangeProps_FWD_DEFINED__
#define __NetSharingApplicationDefinitionResponseRangeProps_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingApplicationDefinitionResponseRangeProps NetSharingApplicationDefinitionResponseRangeProps;
#else
typedef struct NetSharingApplicationDefinitionResponseRangeProps NetSharingApplicationDefinitionResponseRangeProps;
#endif /* __cplusplus */

#endif 	/* __NetSharingApplicationDefinitionResponseRangeProps_FWD_DEFINED__ */


#ifndef __NetSharingApplicationDefinitionProps_FWD_DEFINED__
#define __NetSharingApplicationDefinitionProps_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingApplicationDefinitionProps NetSharingApplicationDefinitionProps;
#else
typedef struct NetSharingApplicationDefinitionProps NetSharingApplicationDefinitionProps;
#endif /* __cplusplus */

#endif 	/* __NetSharingApplicationDefinitionProps_FWD_DEFINED__ */


#ifndef __NetSharingPortMappingProps_FWD_DEFINED__
#define __NetSharingPortMappingProps_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingPortMappingProps NetSharingPortMappingProps;
#else
typedef struct NetSharingPortMappingProps NetSharingPortMappingProps;
#endif /* __cplusplus */

#endif 	/* __NetSharingPortMappingProps_FWD_DEFINED__ */


#ifndef __NetConnectionProps_FWD_DEFINED__
#define __NetConnectionProps_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetConnectionProps NetConnectionProps;
#else
typedef struct NetConnectionProps NetConnectionProps;
#endif /* __cplusplus */

#endif 	/* __NetConnectionProps_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "prsht.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_netcon_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992-1999.
//
//--------------------------------------------------------------------------
#if ( _MSC_VER >= 800 )
#pragma warning(disable:4201)
#endif

EXTERN_C const CLSID CLSID_ConnectionManager;
EXTERN_C const CLSID CLSID_ConnectionCommonUi;
EXTERN_C const CLSID CLSID_EAPOLManager;
EXTERN_C const CLSID CLSID_NetSharingManager;

//These strings reference the HKEY_CURRENT_USER registry which
//retains whether shortcuts are created on the desktop.
#define NETCON_HKEYCURRENTUSERPATH      TEXT("Software\\Microsoft\\Windows NT\\CurrentVersion\\Network\\Network Connections")
#define NETCON_DESKTOPSHORTCUT          TEXT("DesktopShortcut")
#define NETCON_MAX_NAME_LEN 246



















extern RPC_IF_HANDLE __MIDL_itf_netcon_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netcon_0000_v0_0_s_ifspec;

#ifndef __IEnumNetConnection_INTERFACE_DEFINED__
#define __IEnumNetConnection_INTERFACE_DEFINED__

/* interface IEnumNetConnection */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956A0-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ INetConnection **rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumNetConnection **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumNetConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumNetConnection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumNetConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumNetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumNetConnection * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ INetConnection **rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumNetConnection * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumNetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumNetConnection * This,
            /* [out] */ IEnumNetConnection **ppenum);
        
        END_INTERFACE
    } IEnumNetConnectionVtbl;

    interface IEnumNetConnection
    {
        CONST_VTBL struct IEnumNetConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumNetConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumNetConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumNetConnection_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumNetConnection_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumNetConnection_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumNetConnection_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumNetConnection_Next_Proxy( 
    IEnumNetConnection * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ INetConnection **rgelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumNetConnection_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetConnection_Skip_Proxy( 
    IEnumNetConnection * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumNetConnection_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetConnection_Reset_Proxy( 
    IEnumNetConnection * This);


void __RPC_STUB IEnumNetConnection_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetConnection_Clone_Proxy( 
    IEnumNetConnection * This,
    /* [out] */ IEnumNetConnection **ppenum);


void __RPC_STUB IEnumNetConnection_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumNetConnection_INTERFACE_DEFINED__ */


#ifndef __INetConnection_INTERFACE_DEFINED__
#define __INetConnection_INTERFACE_DEFINED__

/* interface INetConnection */
/* [unique][uuid][object] */ 

typedef 
enum tagNETCON_CHARACTERISTIC_FLAGS
    {	NCCF_NONE	= 0,
	NCCF_ALL_USERS	= 0x1,
	NCCF_ALLOW_DUPLICATION	= 0x2,
	NCCF_ALLOW_REMOVAL	= 0x4,
	NCCF_ALLOW_RENAME	= 0x8,
	NCCF_SHOW_ICON	= 0x10,
	NCCF_INCOMING_ONLY	= 0x20,
	NCCF_OUTGOING_ONLY	= 0x40,
	NCCF_BRANDED	= 0x80,
	NCCF_SHARED	= 0x100,
	NCCF_BRIDGED	= 0x200,
	NCCF_FIREWALLED	= 0x400,
	NCCF_DEFAULT	= 0x800
    } 	NETCON_CHARACTERISTIC_FLAGS;

typedef 
enum tagNETCON_STATUS
    {	NCS_DISCONNECTED	= 0,
	NCS_CONNECTING	= NCS_DISCONNECTED + 1,
	NCS_CONNECTED	= NCS_CONNECTING + 1,
	NCS_DISCONNECTING	= NCS_CONNECTED + 1,
	NCS_HARDWARE_NOT_PRESENT	= NCS_DISCONNECTING + 1,
	NCS_HARDWARE_DISABLED	= NCS_HARDWARE_NOT_PRESENT + 1,
	NCS_HARDWARE_MALFUNCTION	= NCS_HARDWARE_DISABLED + 1,
	NCS_MEDIA_DISCONNECTED	= NCS_HARDWARE_MALFUNCTION + 1,
	NCS_AUTHENTICATING	= NCS_MEDIA_DISCONNECTED + 1,
	NCS_AUTHENTICATION_SUCCEEDED	= NCS_AUTHENTICATING + 1,
	NCS_AUTHENTICATION_FAILED	= NCS_AUTHENTICATION_SUCCEEDED + 1,
	NCS_INVALID_ADDRESS	= NCS_AUTHENTICATION_FAILED + 1
    } 	NETCON_STATUS;

typedef 
enum tagNETCON_TYPE
    {	NCT_DIRECT_CONNECT	= 0,
	NCT_INBOUND	= NCT_DIRECT_CONNECT + 1,
	NCT_INTERNET	= NCT_INBOUND + 1,
	NCT_LAN	= NCT_INTERNET + 1,
	NCT_PHONE	= NCT_LAN + 1,
	NCT_TUNNEL	= NCT_PHONE + 1,
	NCT_BRIDGE	= NCT_TUNNEL + 1
    } 	NETCON_TYPE;

typedef 
enum tagNETCON_MEDIATYPE
    {	NCM_NONE	= 0,
	NCM_DIRECT	= NCM_NONE + 1,
	NCM_ISDN	= NCM_DIRECT + 1,
	NCM_LAN	= NCM_ISDN + 1,
	NCM_PHONE	= NCM_LAN + 1,
	NCM_TUNNEL	= NCM_PHONE + 1,
	NCM_PPPOE	= NCM_TUNNEL + 1,
	NCM_BRIDGE	= NCM_PPPOE + 1,
	NCM_SHAREDACCESSHOST_LAN	= NCM_BRIDGE + 1,
	NCM_SHAREDACCESSHOST_RAS	= NCM_SHAREDACCESSHOST_LAN + 1
    } 	NETCON_MEDIATYPE;

typedef struct tagNETCON_PROPERTIES
    {
    GUID guidId;
    /* [string] */ LPWSTR pszwName;
    /* [string] */ LPWSTR pszwDeviceName;
    NETCON_STATUS Status;
    NETCON_MEDIATYPE MediaType;
    DWORD dwCharacter;
    CLSID clsidThisObject;
    CLSID clsidUiObject;
    } 	NETCON_PROPERTIES;

#define S_OBJECT_NO_LONGER_VALID ((HRESULT)0x00000002L)

EXTERN_C const IID IID_INetConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956A1-1CD3-11D1-B1C5-00805FC1270E")
    INetConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Duplicate( 
            /* [string][in] */ LPCWSTR pszwDuplicateName,
            /* [out] */ INetConnection **ppCon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ NETCON_PROPERTIES **ppProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUiObjectClassId( 
            /* [ref][out] */ CLSID *pclsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rename( 
            /* [string][in] */ LPCWSTR pszwNewName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetConnection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            INetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            INetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            INetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Duplicate )( 
            INetConnection * This,
            /* [string][in] */ LPCWSTR pszwDuplicateName,
            /* [out] */ INetConnection **ppCon);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            INetConnection * This,
            /* [out] */ NETCON_PROPERTIES **ppProps);
        
        HRESULT ( STDMETHODCALLTYPE *GetUiObjectClassId )( 
            INetConnection * This,
            /* [ref][out] */ CLSID *pclsid);
        
        HRESULT ( STDMETHODCALLTYPE *Rename )( 
            INetConnection * This,
            /* [string][in] */ LPCWSTR pszwNewName);
        
        END_INTERFACE
    } INetConnectionVtbl;

    interface INetConnection
    {
        CONST_VTBL struct INetConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetConnection_Connect(This)	\
    (This)->lpVtbl -> Connect(This)

#define INetConnection_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define INetConnection_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define INetConnection_Duplicate(This,pszwDuplicateName,ppCon)	\
    (This)->lpVtbl -> Duplicate(This,pszwDuplicateName,ppCon)

#define INetConnection_GetProperties(This,ppProps)	\
    (This)->lpVtbl -> GetProperties(This,ppProps)

#define INetConnection_GetUiObjectClassId(This,pclsid)	\
    (This)->lpVtbl -> GetUiObjectClassId(This,pclsid)

#define INetConnection_Rename(This,pszwNewName)	\
    (This)->lpVtbl -> Rename(This,pszwNewName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE INetConnection_Connect_Proxy( 
    INetConnection * This);


void __RPC_STUB INetConnection_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnection_Disconnect_Proxy( 
    INetConnection * This);


void __RPC_STUB INetConnection_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnection_Delete_Proxy( 
    INetConnection * This);


void __RPC_STUB INetConnection_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnection_Duplicate_Proxy( 
    INetConnection * This,
    /* [string][in] */ LPCWSTR pszwDuplicateName,
    /* [out] */ INetConnection **ppCon);


void __RPC_STUB INetConnection_Duplicate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnection_GetProperties_Proxy( 
    INetConnection * This,
    /* [out] */ NETCON_PROPERTIES **ppProps);


void __RPC_STUB INetConnection_GetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnection_GetUiObjectClassId_Proxy( 
    INetConnection * This,
    /* [ref][out] */ CLSID *pclsid);


void __RPC_STUB INetConnection_GetUiObjectClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnection_Rename_Proxy( 
    INetConnection * This,
    /* [string][in] */ LPCWSTR pszwNewName);


void __RPC_STUB INetConnection_Rename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetConnection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_netcon_0113 */
/* [local] */ 


STDAPI_(VOID) NcFreeNetconProperties (NETCON_PROPERTIES* pProps);


STDAPI_(BOOL) NcIsValidConnectionName (PCWSTR pszwName);



extern RPC_IF_HANDLE __MIDL_itf_netcon_0113_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netcon_0113_v0_0_s_ifspec;

#ifndef __INetConnectionManager_INTERFACE_DEFINED__
#define __INetConnectionManager_INTERFACE_DEFINED__

/* interface INetConnectionManager */
/* [unique][uuid][object] */ 

typedef 
enum tagNETCONMGR_ENUM_FLAGS
    {	NCME_DEFAULT	= 0
    } 	NETCONMGR_ENUM_FLAGS;


EXTERN_C const IID IID_INetConnectionManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956A2-1CD3-11D1-B1C5-00805FC1270E")
    INetConnectionManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumConnections( 
            /* [in] */ NETCONMGR_ENUM_FLAGS Flags,
            /* [out] */ IEnumNetConnection **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetConnectionManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetConnectionManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetConnectionManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetConnectionManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumConnections )( 
            INetConnectionManager * This,
            /* [in] */ NETCONMGR_ENUM_FLAGS Flags,
            /* [out] */ IEnumNetConnection **ppEnum);
        
        END_INTERFACE
    } INetConnectionManagerVtbl;

    interface INetConnectionManager
    {
        CONST_VTBL struct INetConnectionManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetConnectionManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetConnectionManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetConnectionManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetConnectionManager_EnumConnections(This,Flags,ppEnum)	\
    (This)->lpVtbl -> EnumConnections(This,Flags,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE INetConnectionManager_EnumConnections_Proxy( 
    INetConnectionManager * This,
    /* [in] */ NETCONMGR_ENUM_FLAGS Flags,
    /* [out] */ IEnumNetConnection **ppEnum);


void __RPC_STUB INetConnectionManager_EnumConnections_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetConnectionManager_INTERFACE_DEFINED__ */


#ifndef __INetConnectionConnectUi_INTERFACE_DEFINED__
#define __INetConnectionConnectUi_INTERFACE_DEFINED__

/* interface INetConnectionConnectUi */
/* [unique][uuid][object][local] */ 

typedef 
enum tagNETCONUI_CONNECT_FLAGS
    {	NCUC_DEFAULT	= 0,
	NCUC_NO_UI	= 0x1
    } 	NETCONUI_CONNECT_FLAGS;


EXTERN_C const IID IID_INetConnectionConnectUi;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956A3-1CD3-11D1-B1C5-00805FC1270E")
    INetConnectionConnectUi : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetConnection( 
            /* [in] */ INetConnection *pCon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ HWND hwndParent,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [in] */ HWND hwndParent,
            /* [in] */ DWORD dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetConnectionConnectUiVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetConnectionConnectUi * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetConnectionConnectUi * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetConnectionConnectUi * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetConnection )( 
            INetConnectionConnectUi * This,
            /* [in] */ INetConnection *pCon);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            INetConnectionConnectUi * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            INetConnectionConnectUi * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ DWORD dwFlags);
        
        END_INTERFACE
    } INetConnectionConnectUiVtbl;

    interface INetConnectionConnectUi
    {
        CONST_VTBL struct INetConnectionConnectUiVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetConnectionConnectUi_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetConnectionConnectUi_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetConnectionConnectUi_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetConnectionConnectUi_SetConnection(This,pCon)	\
    (This)->lpVtbl -> SetConnection(This,pCon)

#define INetConnectionConnectUi_Connect(This,hwndParent,dwFlags)	\
    (This)->lpVtbl -> Connect(This,hwndParent,dwFlags)

#define INetConnectionConnectUi_Disconnect(This,hwndParent,dwFlags)	\
    (This)->lpVtbl -> Disconnect(This,hwndParent,dwFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE INetConnectionConnectUi_SetConnection_Proxy( 
    INetConnectionConnectUi * This,
    /* [in] */ INetConnection *pCon);


void __RPC_STUB INetConnectionConnectUi_SetConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnectionConnectUi_Connect_Proxy( 
    INetConnectionConnectUi * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB INetConnectionConnectUi_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnectionConnectUi_Disconnect_Proxy( 
    INetConnectionConnectUi * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB INetConnectionConnectUi_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetConnectionConnectUi_INTERFACE_DEFINED__ */


#ifndef __INetConnectionPropertyUi_INTERFACE_DEFINED__
#define __INetConnectionPropertyUi_INTERFACE_DEFINED__

/* interface INetConnectionPropertyUi */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_INetConnectionPropertyUi;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956A4-1CD3-11D1-B1C5-00805FC1270E")
    INetConnectionPropertyUi : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetConnection( 
            /* [in] */ INetConnection *pCon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPages( 
            /* [in] */ HWND hwndParent,
            /* [in] */ LPFNADDPROPSHEETPAGE pfnAddPage,
            /* [in] */ LPARAM lParam) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetConnectionPropertyUiVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetConnectionPropertyUi * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetConnectionPropertyUi * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetConnectionPropertyUi * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetConnection )( 
            INetConnectionPropertyUi * This,
            /* [in] */ INetConnection *pCon);
        
        HRESULT ( STDMETHODCALLTYPE *AddPages )( 
            INetConnectionPropertyUi * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ LPFNADDPROPSHEETPAGE pfnAddPage,
            /* [in] */ LPARAM lParam);
        
        END_INTERFACE
    } INetConnectionPropertyUiVtbl;

    interface INetConnectionPropertyUi
    {
        CONST_VTBL struct INetConnectionPropertyUiVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetConnectionPropertyUi_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetConnectionPropertyUi_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetConnectionPropertyUi_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetConnectionPropertyUi_SetConnection(This,pCon)	\
    (This)->lpVtbl -> SetConnection(This,pCon)

#define INetConnectionPropertyUi_AddPages(This,hwndParent,pfnAddPage,lParam)	\
    (This)->lpVtbl -> AddPages(This,hwndParent,pfnAddPage,lParam)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE INetConnectionPropertyUi_SetConnection_Proxy( 
    INetConnectionPropertyUi * This,
    /* [in] */ INetConnection *pCon);


void __RPC_STUB INetConnectionPropertyUi_SetConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnectionPropertyUi_AddPages_Proxy( 
    INetConnectionPropertyUi * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ LPFNADDPROPSHEETPAGE pfnAddPage,
    /* [in] */ LPARAM lParam);


void __RPC_STUB INetConnectionPropertyUi_AddPages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetConnectionPropertyUi_INTERFACE_DEFINED__ */


#ifndef __INetConnectionCommonUi_INTERFACE_DEFINED__
#define __INetConnectionCommonUi_INTERFACE_DEFINED__

/* interface INetConnectionCommonUi */
/* [unique][uuid][object][local] */ 

typedef 
enum tagNETCON_CHOOSEFLAGS
    {	NCCHF_CONNECT	= 0x1,
	NCCHF_CAPTION	= 0x2,
	NCCHF_OKBTTNTEXT	= 0x4,
	NCCHF_DISABLENEW	= 0x8,
	NCCHF_AUTOSELECT	= 0x10
    } 	NETCON_CHOOSEFLAGS;

typedef 
enum tagNETCON_CHOOSETYPE
    {	NCCHT_DIRECT_CONNECT	= 0x1,
	NCCHT_LAN	= 0x2,
	NCCHT_PHONE	= 0x4,
	NCCHT_TUNNEL	= 0x8,
	NCCHT_ISDN	= 0x10,
	NCCHT_ALL	= 0x1f
    } 	NETCON_CHOOSETYPE;

typedef struct tagNETCON_CHOOSECONN
    {
    DWORD lStructSize;
    HWND hwndParent;
    DWORD dwFlags;
    DWORD dwTypeMask;
    LPCWSTR lpstrCaption;
    LPCWSTR lpstrOkBttnText;
    } 	NETCON_CHOOSECONN;


EXTERN_C const IID IID_INetConnectionCommonUi;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956A5-1CD3-11D1-B1C5-00805FC1270E")
    INetConnectionCommonUi : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ChooseConnection( 
            /* [in] */ NETCON_CHOOSECONN *pChooseConn,
            /* [out] */ INetConnection **ppCon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowConnectionProperties( 
            /* [in] */ HWND hwndParent,
            /* [in] */ INetConnection *pCon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartNewConnectionWizard( 
            /* [in] */ HWND hwndParent,
            /* [out] */ INetConnection **ppCon) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetConnectionCommonUiVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetConnectionCommonUi * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetConnectionCommonUi * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetConnectionCommonUi * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChooseConnection )( 
            INetConnectionCommonUi * This,
            /* [in] */ NETCON_CHOOSECONN *pChooseConn,
            /* [out] */ INetConnection **ppCon);
        
        HRESULT ( STDMETHODCALLTYPE *ShowConnectionProperties )( 
            INetConnectionCommonUi * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ INetConnection *pCon);
        
        HRESULT ( STDMETHODCALLTYPE *StartNewConnectionWizard )( 
            INetConnectionCommonUi * This,
            /* [in] */ HWND hwndParent,
            /* [out] */ INetConnection **ppCon);
        
        END_INTERFACE
    } INetConnectionCommonUiVtbl;

    interface INetConnectionCommonUi
    {
        CONST_VTBL struct INetConnectionCommonUiVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetConnectionCommonUi_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetConnectionCommonUi_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetConnectionCommonUi_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetConnectionCommonUi_ChooseConnection(This,pChooseConn,ppCon)	\
    (This)->lpVtbl -> ChooseConnection(This,pChooseConn,ppCon)

#define INetConnectionCommonUi_ShowConnectionProperties(This,hwndParent,pCon)	\
    (This)->lpVtbl -> ShowConnectionProperties(This,hwndParent,pCon)

#define INetConnectionCommonUi_StartNewConnectionWizard(This,hwndParent,ppCon)	\
    (This)->lpVtbl -> StartNewConnectionWizard(This,hwndParent,ppCon)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE INetConnectionCommonUi_ChooseConnection_Proxy( 
    INetConnectionCommonUi * This,
    /* [in] */ NETCON_CHOOSECONN *pChooseConn,
    /* [out] */ INetConnection **ppCon);


void __RPC_STUB INetConnectionCommonUi_ChooseConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnectionCommonUi_ShowConnectionProperties_Proxy( 
    INetConnectionCommonUi * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ INetConnection *pCon);


void __RPC_STUB INetConnectionCommonUi_ShowConnectionProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE INetConnectionCommonUi_StartNewConnectionWizard_Proxy( 
    INetConnectionCommonUi * This,
    /* [in] */ HWND hwndParent,
    /* [out] */ INetConnection **ppCon);


void __RPC_STUB INetConnectionCommonUi_StartNewConnectionWizard_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetConnectionCommonUi_INTERFACE_DEFINED__ */


#ifndef __IEnumNetSharingPortMapping_INTERFACE_DEFINED__
#define __IEnumNetSharingPortMapping_INTERFACE_DEFINED__

/* interface IEnumNetSharingPortMapping */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetSharingPortMapping;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B0-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetSharingPortMapping : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumNetSharingPortMapping **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumNetSharingPortMappingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumNetSharingPortMapping * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumNetSharingPortMapping * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumNetSharingPortMapping * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumNetSharingPortMapping * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumNetSharingPortMapping * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumNetSharingPortMapping * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumNetSharingPortMapping * This,
            /* [out] */ IEnumNetSharingPortMapping **ppenum);
        
        END_INTERFACE
    } IEnumNetSharingPortMappingVtbl;

    interface IEnumNetSharingPortMapping
    {
        CONST_VTBL struct IEnumNetSharingPortMappingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetSharingPortMapping_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumNetSharingPortMapping_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumNetSharingPortMapping_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumNetSharingPortMapping_Next(This,celt,rgVar,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgVar,pceltFetched)

#define IEnumNetSharingPortMapping_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumNetSharingPortMapping_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumNetSharingPortMapping_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumNetSharingPortMapping_Next_Proxy( 
    IEnumNetSharingPortMapping * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ VARIANT *rgVar,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumNetSharingPortMapping_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingPortMapping_Skip_Proxy( 
    IEnumNetSharingPortMapping * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumNetSharingPortMapping_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingPortMapping_Reset_Proxy( 
    IEnumNetSharingPortMapping * This);


void __RPC_STUB IEnumNetSharingPortMapping_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingPortMapping_Clone_Proxy( 
    IEnumNetSharingPortMapping * This,
    /* [out] */ IEnumNetSharingPortMapping **ppenum);


void __RPC_STUB IEnumNetSharingPortMapping_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumNetSharingPortMapping_INTERFACE_DEFINED__ */


#ifndef __INetSharingPortMappingProps_INTERFACE_DEFINED__
#define __INetSharingPortMappingProps_INTERFACE_DEFINED__

/* interface INetSharingPortMappingProps */
/* [unique][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingPortMappingProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("24B7E9B5-E38F-4685-851B-00892CF5F940")
    INetSharingPortMappingProps : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IPProtocol( 
            /* [retval][out] */ UCHAR *pucIPProt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Port( 
            /* [retval][out] */ long *pusPort) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Options( 
            /* [retval][out] */ long *pdwOptions) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TargetName( 
            /* [retval][out] */ BSTR *pbstrTargetName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TargetIPAddress( 
            /* [retval][out] */ BSTR *pbstrTargetIPAddress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingPortMappingPropsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingPortMappingProps * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingPortMappingProps * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingPortMappingProps * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingPortMappingProps * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingPortMappingProps * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingPortMappingProps * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingPortMappingProps * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            INetSharingPortMappingProps * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IPProtocol )( 
            INetSharingPortMappingProps * This,
            /* [retval][out] */ UCHAR *pucIPProt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Port )( 
            INetSharingPortMappingProps * This,
            /* [retval][out] */ long *pusPort);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Options )( 
            INetSharingPortMappingProps * This,
            /* [retval][out] */ long *pdwOptions);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TargetName )( 
            INetSharingPortMappingProps * This,
            /* [retval][out] */ BSTR *pbstrTargetName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TargetIPAddress )( 
            INetSharingPortMappingProps * This,
            /* [retval][out] */ BSTR *pbstrTargetIPAddress);
        
        END_INTERFACE
    } INetSharingPortMappingPropsVtbl;

    interface INetSharingPortMappingProps
    {
        CONST_VTBL struct INetSharingPortMappingPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingPortMappingProps_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingPortMappingProps_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingPortMappingProps_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingPortMappingProps_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingPortMappingProps_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingPortMappingProps_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingPortMappingProps_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingPortMappingProps_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define INetSharingPortMappingProps_get_IPProtocol(This,pucIPProt)	\
    (This)->lpVtbl -> get_IPProtocol(This,pucIPProt)

#define INetSharingPortMappingProps_get_Port(This,pusPort)	\
    (This)->lpVtbl -> get_Port(This,pusPort)

#define INetSharingPortMappingProps_get_Options(This,pdwOptions)	\
    (This)->lpVtbl -> get_Options(This,pdwOptions)

#define INetSharingPortMappingProps_get_TargetName(This,pbstrTargetName)	\
    (This)->lpVtbl -> get_TargetName(This,pbstrTargetName)

#define INetSharingPortMappingProps_get_TargetIPAddress(This,pbstrTargetIPAddress)	\
    (This)->lpVtbl -> get_TargetIPAddress(This,pbstrTargetIPAddress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPortMappingProps_get_Name_Proxy( 
    INetSharingPortMappingProps * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB INetSharingPortMappingProps_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPortMappingProps_get_IPProtocol_Proxy( 
    INetSharingPortMappingProps * This,
    /* [retval][out] */ UCHAR *pucIPProt);


void __RPC_STUB INetSharingPortMappingProps_get_IPProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPortMappingProps_get_Port_Proxy( 
    INetSharingPortMappingProps * This,
    /* [retval][out] */ long *pusPort);


void __RPC_STUB INetSharingPortMappingProps_get_Port_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPortMappingProps_get_Options_Proxy( 
    INetSharingPortMappingProps * This,
    /* [retval][out] */ long *pdwOptions);


void __RPC_STUB INetSharingPortMappingProps_get_Options_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPortMappingProps_get_TargetName_Proxy( 
    INetSharingPortMappingProps * This,
    /* [retval][out] */ BSTR *pbstrTargetName);


void __RPC_STUB INetSharingPortMappingProps_get_TargetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPortMappingProps_get_TargetIPAddress_Proxy( 
    INetSharingPortMappingProps * This,
    /* [retval][out] */ BSTR *pbstrTargetIPAddress);


void __RPC_STUB INetSharingPortMappingProps_get_TargetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingPortMappingProps_INTERFACE_DEFINED__ */


#ifndef __INetSharingPortMapping_INTERFACE_DEFINED__
#define __INetSharingPortMapping_INTERFACE_DEFINED__

/* interface INetSharingPortMapping */
/* [unique][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingPortMapping;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B1-1CD3-11D1-B1C5-00805FC1270E")
    INetSharingPortMapping : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disable( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Enable( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Properties( 
            /* [retval][out] */ INetSharingPortMappingProps **ppNSPMP) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingPortMappingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingPortMapping * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingPortMapping * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingPortMapping * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingPortMapping * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingPortMapping * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingPortMapping * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingPortMapping * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Disable )( 
            INetSharingPortMapping * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Enable )( 
            INetSharingPortMapping * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Properties )( 
            INetSharingPortMapping * This,
            /* [retval][out] */ INetSharingPortMappingProps **ppNSPMP);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            INetSharingPortMapping * This);
        
        END_INTERFACE
    } INetSharingPortMappingVtbl;

    interface INetSharingPortMapping
    {
        CONST_VTBL struct INetSharingPortMappingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingPortMapping_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingPortMapping_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingPortMapping_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingPortMapping_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingPortMapping_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingPortMapping_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingPortMapping_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingPortMapping_Disable(This)	\
    (This)->lpVtbl -> Disable(This)

#define INetSharingPortMapping_Enable(This)	\
    (This)->lpVtbl -> Enable(This)

#define INetSharingPortMapping_get_Properties(This,ppNSPMP)	\
    (This)->lpVtbl -> get_Properties(This,ppNSPMP)

#define INetSharingPortMapping_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingPortMapping_Disable_Proxy( 
    INetSharingPortMapping * This);


void __RPC_STUB INetSharingPortMapping_Disable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingPortMapping_Enable_Proxy( 
    INetSharingPortMapping * This);


void __RPC_STUB INetSharingPortMapping_Enable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPortMapping_get_Properties_Proxy( 
    INetSharingPortMapping * This,
    /* [retval][out] */ INetSharingPortMappingProps **ppNSPMP);


void __RPC_STUB INetSharingPortMapping_get_Properties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingPortMapping_Delete_Proxy( 
    INetSharingPortMapping * This);


void __RPC_STUB INetSharingPortMapping_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingPortMapping_INTERFACE_DEFINED__ */


#ifndef __IEnumNetSharingApplicationDefinition_INTERFACE_DEFINED__
#define __IEnumNetSharingApplicationDefinition_INTERFACE_DEFINED__

/* interface IEnumNetSharingApplicationDefinition */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetSharingApplicationDefinition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B2-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetSharingApplicationDefinition : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumNetSharingApplicationDefinition **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumNetSharingApplicationDefinitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumNetSharingApplicationDefinition * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumNetSharingApplicationDefinition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumNetSharingApplicationDefinition * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumNetSharingApplicationDefinition * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumNetSharingApplicationDefinition * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumNetSharingApplicationDefinition * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumNetSharingApplicationDefinition * This,
            /* [out] */ IEnumNetSharingApplicationDefinition **ppenum);
        
        END_INTERFACE
    } IEnumNetSharingApplicationDefinitionVtbl;

    interface IEnumNetSharingApplicationDefinition
    {
        CONST_VTBL struct IEnumNetSharingApplicationDefinitionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetSharingApplicationDefinition_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumNetSharingApplicationDefinition_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumNetSharingApplicationDefinition_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumNetSharingApplicationDefinition_Next(This,celt,rgVar,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgVar,pceltFetched)

#define IEnumNetSharingApplicationDefinition_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumNetSharingApplicationDefinition_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumNetSharingApplicationDefinition_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumNetSharingApplicationDefinition_Next_Proxy( 
    IEnumNetSharingApplicationDefinition * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ VARIANT *rgVar,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumNetSharingApplicationDefinition_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingApplicationDefinition_Skip_Proxy( 
    IEnumNetSharingApplicationDefinition * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumNetSharingApplicationDefinition_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingApplicationDefinition_Reset_Proxy( 
    IEnumNetSharingApplicationDefinition * This);


void __RPC_STUB IEnumNetSharingApplicationDefinition_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingApplicationDefinition_Clone_Proxy( 
    IEnumNetSharingApplicationDefinition * This,
    /* [out] */ IEnumNetSharingApplicationDefinition **ppenum);


void __RPC_STUB IEnumNetSharingApplicationDefinition_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumNetSharingApplicationDefinition_INTERFACE_DEFINED__ */


#ifndef __INetSharingApplicationDefinitionResponseRangeProps_INTERFACE_DEFINED__
#define __INetSharingApplicationDefinitionResponseRangeProps_INTERFACE_DEFINED__

/* interface INetSharingApplicationDefinitionResponseRangeProps */
/* [unique][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingApplicationDefinitionResponseRangeProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60E2567B-4F90-41DE-AA2E-6AA619E4BD88")
    INetSharingApplicationDefinitionResponseRangeProps : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IPProtocol( 
            /* [retval][out] */ UCHAR *pucIPProt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartPort( 
            /* [retval][out] */ long *pusStartPort) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EndPort( 
            /* [retval][out] */ long *pusEndPort) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingApplicationDefinitionResponseRangePropsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingApplicationDefinitionResponseRangeProps * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingApplicationDefinitionResponseRangeProps * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingApplicationDefinitionResponseRangeProps * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingApplicationDefinitionResponseRangeProps * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingApplicationDefinitionResponseRangeProps * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingApplicationDefinitionResponseRangeProps * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingApplicationDefinitionResponseRangeProps * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IPProtocol )( 
            INetSharingApplicationDefinitionResponseRangeProps * This,
            /* [retval][out] */ UCHAR *pucIPProt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartPort )( 
            INetSharingApplicationDefinitionResponseRangeProps * This,
            /* [retval][out] */ long *pusStartPort);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EndPort )( 
            INetSharingApplicationDefinitionResponseRangeProps * This,
            /* [retval][out] */ long *pusEndPort);
        
        END_INTERFACE
    } INetSharingApplicationDefinitionResponseRangePropsVtbl;

    interface INetSharingApplicationDefinitionResponseRangeProps
    {
        CONST_VTBL struct INetSharingApplicationDefinitionResponseRangePropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingApplicationDefinitionResponseRangeProps_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingApplicationDefinitionResponseRangeProps_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingApplicationDefinitionResponseRangeProps_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingApplicationDefinitionResponseRangeProps_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingApplicationDefinitionResponseRangeProps_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingApplicationDefinitionResponseRangeProps_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingApplicationDefinitionResponseRangeProps_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingApplicationDefinitionResponseRangeProps_get_IPProtocol(This,pucIPProt)	\
    (This)->lpVtbl -> get_IPProtocol(This,pucIPProt)

#define INetSharingApplicationDefinitionResponseRangeProps_get_StartPort(This,pusStartPort)	\
    (This)->lpVtbl -> get_StartPort(This,pusStartPort)

#define INetSharingApplicationDefinitionResponseRangeProps_get_EndPort(This,pusEndPort)	\
    (This)->lpVtbl -> get_EndPort(This,pusEndPort)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionResponseRangeProps_get_IPProtocol_Proxy( 
    INetSharingApplicationDefinitionResponseRangeProps * This,
    /* [retval][out] */ UCHAR *pucIPProt);


void __RPC_STUB INetSharingApplicationDefinitionResponseRangeProps_get_IPProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionResponseRangeProps_get_StartPort_Proxy( 
    INetSharingApplicationDefinitionResponseRangeProps * This,
    /* [retval][out] */ long *pusStartPort);


void __RPC_STUB INetSharingApplicationDefinitionResponseRangeProps_get_StartPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionResponseRangeProps_get_EndPort_Proxy( 
    INetSharingApplicationDefinitionResponseRangeProps * This,
    /* [retval][out] */ long *pusEndPort);


void __RPC_STUB INetSharingApplicationDefinitionResponseRangeProps_get_EndPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingApplicationDefinitionResponseRangeProps_INTERFACE_DEFINED__ */


#ifndef __INetSharingApplicationDefinitionProps_INTERFACE_DEFINED__
#define __INetSharingApplicationDefinitionProps_INTERFACE_DEFINED__

/* interface INetSharingApplicationDefinitionProps */
/* [unique][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingApplicationDefinitionProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7771C052-5DE9-4C27-BA75-EA6A09B34E7B")
    INetSharingApplicationDefinitionProps : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IPProtocol( 
            /* [retval][out] */ UCHAR *pucIPProt) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IPProtocol( 
            /* [in] */ UCHAR ucIPProt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutgoingPort( 
            /* [retval][out] */ long *pusPort) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutgoingPort( 
            /* [in] */ long usPort) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Options( 
            /* [retval][out] */ long *pdwOptions) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Options( 
            /* [in] */ long dwOptions) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *plCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ResponseRange( 
            /* [in] */ long lIndex,
            /* [retval][out] */ INetSharingApplicationDefinitionResponseRangeProps **ppSADRRP) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteAllResponseRanges( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddResponseRange( 
            /* [in] */ UCHAR ucIPProtocol,
            /* [in] */ USHORT usStartPort,
            /* [in] */ USHORT usEndPort) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingApplicationDefinitionPropsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingApplicationDefinitionProps * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingApplicationDefinitionProps * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingApplicationDefinitionProps * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingApplicationDefinitionProps * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingApplicationDefinitionProps * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingApplicationDefinitionProps * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingApplicationDefinitionProps * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            INetSharingApplicationDefinitionProps * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IPProtocol )( 
            INetSharingApplicationDefinitionProps * This,
            /* [retval][out] */ UCHAR *pucIPProt);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IPProtocol )( 
            INetSharingApplicationDefinitionProps * This,
            /* [in] */ UCHAR ucIPProt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutgoingPort )( 
            INetSharingApplicationDefinitionProps * This,
            /* [retval][out] */ long *pusPort);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutgoingPort )( 
            INetSharingApplicationDefinitionProps * This,
            /* [in] */ long usPort);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Options )( 
            INetSharingApplicationDefinitionProps * This,
            /* [retval][out] */ long *pdwOptions);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Options )( 
            INetSharingApplicationDefinitionProps * This,
            /* [in] */ long dwOptions);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            INetSharingApplicationDefinitionProps * This,
            /* [retval][out] */ long *plCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResponseRange )( 
            INetSharingApplicationDefinitionProps * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ INetSharingApplicationDefinitionResponseRangeProps **ppSADRRP);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteAllResponseRanges )( 
            INetSharingApplicationDefinitionProps * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddResponseRange )( 
            INetSharingApplicationDefinitionProps * This,
            /* [in] */ UCHAR ucIPProtocol,
            /* [in] */ USHORT usStartPort,
            /* [in] */ USHORT usEndPort);
        
        END_INTERFACE
    } INetSharingApplicationDefinitionPropsVtbl;

    interface INetSharingApplicationDefinitionProps
    {
        CONST_VTBL struct INetSharingApplicationDefinitionPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingApplicationDefinitionProps_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingApplicationDefinitionProps_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingApplicationDefinitionProps_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingApplicationDefinitionProps_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingApplicationDefinitionProps_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingApplicationDefinitionProps_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingApplicationDefinitionProps_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingApplicationDefinitionProps_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define INetSharingApplicationDefinitionProps_get_IPProtocol(This,pucIPProt)	\
    (This)->lpVtbl -> get_IPProtocol(This,pucIPProt)

#define INetSharingApplicationDefinitionProps_put_IPProtocol(This,ucIPProt)	\
    (This)->lpVtbl -> put_IPProtocol(This,ucIPProt)

#define INetSharingApplicationDefinitionProps_get_OutgoingPort(This,pusPort)	\
    (This)->lpVtbl -> get_OutgoingPort(This,pusPort)

#define INetSharingApplicationDefinitionProps_put_OutgoingPort(This,usPort)	\
    (This)->lpVtbl -> put_OutgoingPort(This,usPort)

#define INetSharingApplicationDefinitionProps_get_Options(This,pdwOptions)	\
    (This)->lpVtbl -> get_Options(This,pdwOptions)

#define INetSharingApplicationDefinitionProps_put_Options(This,dwOptions)	\
    (This)->lpVtbl -> put_Options(This,dwOptions)

#define INetSharingApplicationDefinitionProps_get_Count(This,plCount)	\
    (This)->lpVtbl -> get_Count(This,plCount)

#define INetSharingApplicationDefinitionProps_get_ResponseRange(This,lIndex,ppSADRRP)	\
    (This)->lpVtbl -> get_ResponseRange(This,lIndex,ppSADRRP)

#define INetSharingApplicationDefinitionProps_DeleteAllResponseRanges(This)	\
    (This)->lpVtbl -> DeleteAllResponseRanges(This)

#define INetSharingApplicationDefinitionProps_AddResponseRange(This,ucIPProtocol,usStartPort,usEndPort)	\
    (This)->lpVtbl -> AddResponseRange(This,ucIPProtocol,usStartPort,usEndPort)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_get_Name_Proxy( 
    INetSharingApplicationDefinitionProps * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB INetSharingApplicationDefinitionProps_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_get_IPProtocol_Proxy( 
    INetSharingApplicationDefinitionProps * This,
    /* [retval][out] */ UCHAR *pucIPProt);


void __RPC_STUB INetSharingApplicationDefinitionProps_get_IPProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_put_IPProtocol_Proxy( 
    INetSharingApplicationDefinitionProps * This,
    /* [in] */ UCHAR ucIPProt);


void __RPC_STUB INetSharingApplicationDefinitionProps_put_IPProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_get_OutgoingPort_Proxy( 
    INetSharingApplicationDefinitionProps * This,
    /* [retval][out] */ long *pusPort);


void __RPC_STUB INetSharingApplicationDefinitionProps_get_OutgoingPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_put_OutgoingPort_Proxy( 
    INetSharingApplicationDefinitionProps * This,
    /* [in] */ long usPort);


void __RPC_STUB INetSharingApplicationDefinitionProps_put_OutgoingPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_get_Options_Proxy( 
    INetSharingApplicationDefinitionProps * This,
    /* [retval][out] */ long *pdwOptions);


void __RPC_STUB INetSharingApplicationDefinitionProps_get_Options_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_put_Options_Proxy( 
    INetSharingApplicationDefinitionProps * This,
    /* [in] */ long dwOptions);


void __RPC_STUB INetSharingApplicationDefinitionProps_put_Options_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_get_Count_Proxy( 
    INetSharingApplicationDefinitionProps * This,
    /* [retval][out] */ long *plCount);


void __RPC_STUB INetSharingApplicationDefinitionProps_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_get_ResponseRange_Proxy( 
    INetSharingApplicationDefinitionProps * This,
    /* [in] */ long lIndex,
    /* [retval][out] */ INetSharingApplicationDefinitionResponseRangeProps **ppSADRRP);


void __RPC_STUB INetSharingApplicationDefinitionProps_get_ResponseRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_DeleteAllResponseRanges_Proxy( 
    INetSharingApplicationDefinitionProps * This);


void __RPC_STUB INetSharingApplicationDefinitionProps_DeleteAllResponseRanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionProps_AddResponseRange_Proxy( 
    INetSharingApplicationDefinitionProps * This,
    /* [in] */ UCHAR ucIPProtocol,
    /* [in] */ USHORT usStartPort,
    /* [in] */ USHORT usEndPort);


void __RPC_STUB INetSharingApplicationDefinitionProps_AddResponseRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingApplicationDefinitionProps_INTERFACE_DEFINED__ */


#ifndef __INetSharingApplicationDefinition_INTERFACE_DEFINED__
#define __INetSharingApplicationDefinition_INTERFACE_DEFINED__

/* interface INetSharingApplicationDefinition */
/* [unique][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingApplicationDefinition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B3-1CD3-11D1-B1C5-00805FC1270E")
    INetSharingApplicationDefinition : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disable( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Enable( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Properties( 
            /* [retval][out] */ INetSharingApplicationDefinitionProps **ppSADP) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Properties( 
            /* [in] */ INetSharingApplicationDefinitionProps *pSADP) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingApplicationDefinitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingApplicationDefinition * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingApplicationDefinition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingApplicationDefinition * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingApplicationDefinition * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingApplicationDefinition * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingApplicationDefinition * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingApplicationDefinition * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Disable )( 
            INetSharingApplicationDefinition * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Enable )( 
            INetSharingApplicationDefinition * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Properties )( 
            INetSharingApplicationDefinition * This,
            /* [retval][out] */ INetSharingApplicationDefinitionProps **ppSADP);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Properties )( 
            INetSharingApplicationDefinition * This,
            /* [in] */ INetSharingApplicationDefinitionProps *pSADP);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            INetSharingApplicationDefinition * This);
        
        END_INTERFACE
    } INetSharingApplicationDefinitionVtbl;

    interface INetSharingApplicationDefinition
    {
        CONST_VTBL struct INetSharingApplicationDefinitionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingApplicationDefinition_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingApplicationDefinition_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingApplicationDefinition_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingApplicationDefinition_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingApplicationDefinition_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingApplicationDefinition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingApplicationDefinition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingApplicationDefinition_Disable(This)	\
    (This)->lpVtbl -> Disable(This)

#define INetSharingApplicationDefinition_Enable(This)	\
    (This)->lpVtbl -> Enable(This)

#define INetSharingApplicationDefinition_get_Properties(This,ppSADP)	\
    (This)->lpVtbl -> get_Properties(This,ppSADP)

#define INetSharingApplicationDefinition_put_Properties(This,pSADP)	\
    (This)->lpVtbl -> put_Properties(This,pSADP)

#define INetSharingApplicationDefinition_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinition_Disable_Proxy( 
    INetSharingApplicationDefinition * This);


void __RPC_STUB INetSharingApplicationDefinition_Disable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinition_Enable_Proxy( 
    INetSharingApplicationDefinition * This);


void __RPC_STUB INetSharingApplicationDefinition_Enable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinition_get_Properties_Proxy( 
    INetSharingApplicationDefinition * This,
    /* [retval][out] */ INetSharingApplicationDefinitionProps **ppSADP);


void __RPC_STUB INetSharingApplicationDefinition_get_Properties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinition_put_Properties_Proxy( 
    INetSharingApplicationDefinition * This,
    /* [in] */ INetSharingApplicationDefinitionProps *pSADP);


void __RPC_STUB INetSharingApplicationDefinition_put_Properties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinition_Delete_Proxy( 
    INetSharingApplicationDefinition * This);


void __RPC_STUB INetSharingApplicationDefinition_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingApplicationDefinition_INTERFACE_DEFINED__ */


#ifndef __IEnumNetSharingEveryConnection_INTERFACE_DEFINED__
#define __IEnumNetSharingEveryConnection_INTERFACE_DEFINED__

/* interface IEnumNetSharingEveryConnection */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetSharingEveryConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B8-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetSharingEveryConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumNetSharingEveryConnection **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumNetSharingEveryConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumNetSharingEveryConnection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumNetSharingEveryConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumNetSharingEveryConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumNetSharingEveryConnection * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumNetSharingEveryConnection * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumNetSharingEveryConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumNetSharingEveryConnection * This,
            /* [out] */ IEnumNetSharingEveryConnection **ppenum);
        
        END_INTERFACE
    } IEnumNetSharingEveryConnectionVtbl;

    interface IEnumNetSharingEveryConnection
    {
        CONST_VTBL struct IEnumNetSharingEveryConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetSharingEveryConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumNetSharingEveryConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumNetSharingEveryConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumNetSharingEveryConnection_Next(This,celt,rgVar,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgVar,pceltFetched)

#define IEnumNetSharingEveryConnection_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumNetSharingEveryConnection_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumNetSharingEveryConnection_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumNetSharingEveryConnection_Next_Proxy( 
    IEnumNetSharingEveryConnection * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ VARIANT *rgVar,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumNetSharingEveryConnection_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingEveryConnection_Skip_Proxy( 
    IEnumNetSharingEveryConnection * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumNetSharingEveryConnection_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingEveryConnection_Reset_Proxy( 
    IEnumNetSharingEveryConnection * This);


void __RPC_STUB IEnumNetSharingEveryConnection_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingEveryConnection_Clone_Proxy( 
    IEnumNetSharingEveryConnection * This,
    /* [out] */ IEnumNetSharingEveryConnection **ppenum);


void __RPC_STUB IEnumNetSharingEveryConnection_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumNetSharingEveryConnection_INTERFACE_DEFINED__ */


#ifndef __IEnumNetSharingPublicConnection_INTERFACE_DEFINED__
#define __IEnumNetSharingPublicConnection_INTERFACE_DEFINED__

/* interface IEnumNetSharingPublicConnection */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetSharingPublicConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B4-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetSharingPublicConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumNetSharingPublicConnection **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumNetSharingPublicConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumNetSharingPublicConnection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumNetSharingPublicConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumNetSharingPublicConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumNetSharingPublicConnection * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumNetSharingPublicConnection * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumNetSharingPublicConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumNetSharingPublicConnection * This,
            /* [out] */ IEnumNetSharingPublicConnection **ppenum);
        
        END_INTERFACE
    } IEnumNetSharingPublicConnectionVtbl;

    interface IEnumNetSharingPublicConnection
    {
        CONST_VTBL struct IEnumNetSharingPublicConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetSharingPublicConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumNetSharingPublicConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumNetSharingPublicConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumNetSharingPublicConnection_Next(This,celt,rgVar,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgVar,pceltFetched)

#define IEnumNetSharingPublicConnection_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumNetSharingPublicConnection_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumNetSharingPublicConnection_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumNetSharingPublicConnection_Next_Proxy( 
    IEnumNetSharingPublicConnection * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ VARIANT *rgVar,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumNetSharingPublicConnection_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingPublicConnection_Skip_Proxy( 
    IEnumNetSharingPublicConnection * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumNetSharingPublicConnection_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingPublicConnection_Reset_Proxy( 
    IEnumNetSharingPublicConnection * This);


void __RPC_STUB IEnumNetSharingPublicConnection_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingPublicConnection_Clone_Proxy( 
    IEnumNetSharingPublicConnection * This,
    /* [out] */ IEnumNetSharingPublicConnection **ppenum);


void __RPC_STUB IEnumNetSharingPublicConnection_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumNetSharingPublicConnection_INTERFACE_DEFINED__ */


#ifndef __IEnumNetSharingPrivateConnection_INTERFACE_DEFINED__
#define __IEnumNetSharingPrivateConnection_INTERFACE_DEFINED__

/* interface IEnumNetSharingPrivateConnection */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetSharingPrivateConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B5-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetSharingPrivateConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pCeltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumNetSharingPrivateConnection **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumNetSharingPrivateConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumNetSharingPrivateConnection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumNetSharingPrivateConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumNetSharingPrivateConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumNetSharingPrivateConnection * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pCeltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumNetSharingPrivateConnection * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumNetSharingPrivateConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumNetSharingPrivateConnection * This,
            /* [out] */ IEnumNetSharingPrivateConnection **ppenum);
        
        END_INTERFACE
    } IEnumNetSharingPrivateConnectionVtbl;

    interface IEnumNetSharingPrivateConnection
    {
        CONST_VTBL struct IEnumNetSharingPrivateConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetSharingPrivateConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumNetSharingPrivateConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumNetSharingPrivateConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumNetSharingPrivateConnection_Next(This,celt,rgVar,pCeltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgVar,pCeltFetched)

#define IEnumNetSharingPrivateConnection_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumNetSharingPrivateConnection_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumNetSharingPrivateConnection_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumNetSharingPrivateConnection_Next_Proxy( 
    IEnumNetSharingPrivateConnection * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ VARIANT *rgVar,
    /* [out] */ ULONG *pCeltFetched);


void __RPC_STUB IEnumNetSharingPrivateConnection_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingPrivateConnection_Skip_Proxy( 
    IEnumNetSharingPrivateConnection * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumNetSharingPrivateConnection_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingPrivateConnection_Reset_Proxy( 
    IEnumNetSharingPrivateConnection * This);


void __RPC_STUB IEnumNetSharingPrivateConnection_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumNetSharingPrivateConnection_Clone_Proxy( 
    IEnumNetSharingPrivateConnection * This,
    /* [out] */ IEnumNetSharingPrivateConnection **ppenum);


void __RPC_STUB IEnumNetSharingPrivateConnection_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumNetSharingPrivateConnection_INTERFACE_DEFINED__ */


#ifndef __INetSharingPortMappingCollection_INTERFACE_DEFINED__
#define __INetSharingPortMappingCollection_INTERFACE_DEFINED__

/* interface INetSharingPortMappingCollection */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingPortMappingCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("02E4A2DE-DA20-4E34-89C8-AC22275A010B")
    INetSharingPortMappingCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingPortMappingCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingPortMappingCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingPortMappingCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingPortMappingCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingPortMappingCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingPortMappingCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingPortMappingCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingPortMappingCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            INetSharingPortMappingCollection * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            INetSharingPortMappingCollection * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } INetSharingPortMappingCollectionVtbl;

    interface INetSharingPortMappingCollection
    {
        CONST_VTBL struct INetSharingPortMappingCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingPortMappingCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingPortMappingCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingPortMappingCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingPortMappingCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingPortMappingCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingPortMappingCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingPortMappingCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingPortMappingCollection_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define INetSharingPortMappingCollection_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPortMappingCollection_get__NewEnum_Proxy( 
    INetSharingPortMappingCollection * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB INetSharingPortMappingCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPortMappingCollection_get_Count_Proxy( 
    INetSharingPortMappingCollection * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB INetSharingPortMappingCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingPortMappingCollection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_netcon_0128 */
/* [local] */ 

// properties for INetConnection (wraps NETCON_PROPERTIES)


extern RPC_IF_HANDLE __MIDL_itf_netcon_0128_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netcon_0128_v0_0_s_ifspec;

#ifndef __INetConnectionProps_INTERFACE_DEFINED__
#define __INetConnectionProps_INTERFACE_DEFINED__

/* interface INetConnectionProps */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetConnectionProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F4277C95-CE5B-463D-8167-5662D9BCAA72")
    INetConnectionProps : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Guid( 
            /* [retval][out] */ BSTR *pbstrGuid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceName( 
            /* [retval][out] */ BSTR *pbstrDeviceName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ NETCON_STATUS *pStatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MediaType( 
            /* [retval][out] */ NETCON_MEDIATYPE *pMediaType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetConnectionPropsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetConnectionProps * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetConnectionProps * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetConnectionProps * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetConnectionProps * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetConnectionProps * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetConnectionProps * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetConnectionProps * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Guid )( 
            INetConnectionProps * This,
            /* [retval][out] */ BSTR *pbstrGuid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            INetConnectionProps * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            INetConnectionProps * This,
            /* [retval][out] */ BSTR *pbstrDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            INetConnectionProps * This,
            /* [retval][out] */ NETCON_STATUS *pStatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaType )( 
            INetConnectionProps * This,
            /* [retval][out] */ NETCON_MEDIATYPE *pMediaType);
        
        END_INTERFACE
    } INetConnectionPropsVtbl;

    interface INetConnectionProps
    {
        CONST_VTBL struct INetConnectionPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetConnectionProps_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetConnectionProps_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetConnectionProps_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetConnectionProps_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetConnectionProps_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetConnectionProps_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetConnectionProps_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetConnectionProps_get_Guid(This,pbstrGuid)	\
    (This)->lpVtbl -> get_Guid(This,pbstrGuid)

#define INetConnectionProps_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define INetConnectionProps_get_DeviceName(This,pbstrDeviceName)	\
    (This)->lpVtbl -> get_DeviceName(This,pbstrDeviceName)

#define INetConnectionProps_get_Status(This,pStatus)	\
    (This)->lpVtbl -> get_Status(This,pStatus)

#define INetConnectionProps_get_MediaType(This,pMediaType)	\
    (This)->lpVtbl -> get_MediaType(This,pMediaType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetConnectionProps_get_Guid_Proxy( 
    INetConnectionProps * This,
    /* [retval][out] */ BSTR *pbstrGuid);


void __RPC_STUB INetConnectionProps_get_Guid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetConnectionProps_get_Name_Proxy( 
    INetConnectionProps * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB INetConnectionProps_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetConnectionProps_get_DeviceName_Proxy( 
    INetConnectionProps * This,
    /* [retval][out] */ BSTR *pbstrDeviceName);


void __RPC_STUB INetConnectionProps_get_DeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetConnectionProps_get_Status_Proxy( 
    INetConnectionProps * This,
    /* [retval][out] */ NETCON_STATUS *pStatus);


void __RPC_STUB INetConnectionProps_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetConnectionProps_get_MediaType_Proxy( 
    INetConnectionProps * This,
    /* [retval][out] */ NETCON_MEDIATYPE *pMediaType);


void __RPC_STUB INetConnectionProps_get_MediaType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetConnectionProps_INTERFACE_DEFINED__ */


#ifndef __INetSharingConfiguration_INTERFACE_DEFINED__
#define __INetSharingConfiguration_INTERFACE_DEFINED__

/* interface INetSharingConfiguration */
/* [unique][dual][oleautomation][uuid][object] */ 

typedef 
enum tagSHARINGCONNECTIONTYPE
    {	ICSSHARINGTYPE_PUBLIC	= 0,
	ICSSHARINGTYPE_PRIVATE	= ICSSHARINGTYPE_PUBLIC + 1
    } 	SHARINGCONNECTIONTYPE;

typedef enum tagSHARINGCONNECTIONTYPE *LPSHARINGCONNECTIONTYPE;

typedef 
enum tagSHARINGCONNECTION_ENUM_FLAGS
    {	ICSSC_DEFAULT	= 0,
	ICSSC_ENABLED	= ICSSC_DEFAULT + 1
    } 	SHARINGCONNECTION_ENUM_FLAGS;

typedef 
enum tagICS_TARGETTYPE
    {	ICSTT_NAME	= 0,
	ICSTT_IPADDRESS	= ICSTT_NAME + 1
    } 	ICS_TARGETTYPE;


EXTERN_C const IID IID_INetSharingConfiguration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B6-1CD3-11D1-B1C5-00805FC1270E")
    INetSharingConfiguration : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SharingEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pbEnabled) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SharingConnectionType( 
            /* [retval][out] */ SHARINGCONNECTIONTYPE *pType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisableSharing( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableSharing( 
            /* [in] */ SHARINGCONNECTIONTYPE Type) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InternetFirewallEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pbEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisableInternetFirewall( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableInternetFirewall( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumPortMappings( 
            /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [retval][out] */ INetSharingPortMappingCollection **ppColl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddPortMapping( 
            /* [in] */ BSTR bstrName,
            /* [in] */ UCHAR ucIPProtocol,
            /* [in] */ USHORT usPort,
            /* [in] */ DWORD dwOptions,
            /* [in] */ BSTR bstrTargetNameOrIPAddress,
            /* [in] */ ICS_TARGETTYPE eTargetType,
            /* [retval][out] */ INetSharingPortMapping **ppMapping) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemovePortMapping( 
            /* [in] */ INetSharingPortMapping *pMapping) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NetConnectionProps( 
            /* [retval][out] */ INetConnectionProps **ppProps) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingConfigurationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingConfiguration * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingConfiguration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingConfiguration * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingConfiguration * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingConfiguration * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingConfiguration * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingConfiguration * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SharingEnabled )( 
            INetSharingConfiguration * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SharingConnectionType )( 
            INetSharingConfiguration * This,
            /* [retval][out] */ SHARINGCONNECTIONTYPE *pType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisableSharing )( 
            INetSharingConfiguration * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableSharing )( 
            INetSharingConfiguration * This,
            /* [in] */ SHARINGCONNECTIONTYPE Type);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InternetFirewallEnabled )( 
            INetSharingConfiguration * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisableInternetFirewall )( 
            INetSharingConfiguration * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableInternetFirewall )( 
            INetSharingConfiguration * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumPortMappings )( 
            INetSharingConfiguration * This,
            /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [retval][out] */ INetSharingPortMappingCollection **ppColl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddPortMapping )( 
            INetSharingConfiguration * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ UCHAR ucIPProtocol,
            /* [in] */ USHORT usPort,
            /* [in] */ DWORD dwOptions,
            /* [in] */ BSTR bstrTargetNameOrIPAddress,
            /* [in] */ ICS_TARGETTYPE eTargetType,
            /* [retval][out] */ INetSharingPortMapping **ppMapping);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemovePortMapping )( 
            INetSharingConfiguration * This,
            /* [in] */ INetSharingPortMapping *pMapping);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetConnectionProps )( 
            INetSharingConfiguration * This,
            /* [retval][out] */ INetConnectionProps **ppProps);
        
        END_INTERFACE
    } INetSharingConfigurationVtbl;

    interface INetSharingConfiguration
    {
        CONST_VTBL struct INetSharingConfigurationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingConfiguration_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingConfiguration_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingConfiguration_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingConfiguration_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingConfiguration_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingConfiguration_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingConfiguration_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingConfiguration_get_SharingEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> get_SharingEnabled(This,pbEnabled)

#define INetSharingConfiguration_get_SharingConnectionType(This,pType)	\
    (This)->lpVtbl -> get_SharingConnectionType(This,pType)

#define INetSharingConfiguration_DisableSharing(This)	\
    (This)->lpVtbl -> DisableSharing(This)

#define INetSharingConfiguration_EnableSharing(This,Type)	\
    (This)->lpVtbl -> EnableSharing(This,Type)

#define INetSharingConfiguration_get_InternetFirewallEnabled(This,pbEnabled)	\
    (This)->lpVtbl -> get_InternetFirewallEnabled(This,pbEnabled)

#define INetSharingConfiguration_DisableInternetFirewall(This)	\
    (This)->lpVtbl -> DisableInternetFirewall(This)

#define INetSharingConfiguration_EnableInternetFirewall(This)	\
    (This)->lpVtbl -> EnableInternetFirewall(This)

#define INetSharingConfiguration_get_EnumPortMappings(This,Flags,ppColl)	\
    (This)->lpVtbl -> get_EnumPortMappings(This,Flags,ppColl)

#define INetSharingConfiguration_AddPortMapping(This,bstrName,ucIPProtocol,usPort,dwOptions,bstrTargetNameOrIPAddress,eTargetType,ppMapping)	\
    (This)->lpVtbl -> AddPortMapping(This,bstrName,ucIPProtocol,usPort,dwOptions,bstrTargetNameOrIPAddress,eTargetType,ppMapping)

#define INetSharingConfiguration_RemovePortMapping(This,pMapping)	\
    (This)->lpVtbl -> RemovePortMapping(This,pMapping)

#define INetSharingConfiguration_get_NetConnectionProps(This,ppProps)	\
    (This)->lpVtbl -> get_NetConnectionProps(This,ppProps)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_get_SharingEnabled_Proxy( 
    INetSharingConfiguration * This,
    /* [retval][out] */ VARIANT_BOOL *pbEnabled);


void __RPC_STUB INetSharingConfiguration_get_SharingEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_get_SharingConnectionType_Proxy( 
    INetSharingConfiguration * This,
    /* [retval][out] */ SHARINGCONNECTIONTYPE *pType);


void __RPC_STUB INetSharingConfiguration_get_SharingConnectionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_DisableSharing_Proxy( 
    INetSharingConfiguration * This);


void __RPC_STUB INetSharingConfiguration_DisableSharing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_EnableSharing_Proxy( 
    INetSharingConfiguration * This,
    /* [in] */ SHARINGCONNECTIONTYPE Type);


void __RPC_STUB INetSharingConfiguration_EnableSharing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_get_InternetFirewallEnabled_Proxy( 
    INetSharingConfiguration * This,
    /* [retval][out] */ VARIANT_BOOL *pbEnabled);


void __RPC_STUB INetSharingConfiguration_get_InternetFirewallEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_DisableInternetFirewall_Proxy( 
    INetSharingConfiguration * This);


void __RPC_STUB INetSharingConfiguration_DisableInternetFirewall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_EnableInternetFirewall_Proxy( 
    INetSharingConfiguration * This);


void __RPC_STUB INetSharingConfiguration_EnableInternetFirewall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_get_EnumPortMappings_Proxy( 
    INetSharingConfiguration * This,
    /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
    /* [retval][out] */ INetSharingPortMappingCollection **ppColl);


void __RPC_STUB INetSharingConfiguration_get_EnumPortMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_AddPortMapping_Proxy( 
    INetSharingConfiguration * This,
    /* [in] */ BSTR bstrName,
    /* [in] */ UCHAR ucIPProtocol,
    /* [in] */ USHORT usPort,
    /* [in] */ DWORD dwOptions,
    /* [in] */ BSTR bstrTargetNameOrIPAddress,
    /* [in] */ ICS_TARGETTYPE eTargetType,
    /* [retval][out] */ INetSharingPortMapping **ppMapping);


void __RPC_STUB INetSharingConfiguration_AddPortMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_RemovePortMapping_Proxy( 
    INetSharingConfiguration * This,
    /* [in] */ INetSharingPortMapping *pMapping);


void __RPC_STUB INetSharingConfiguration_RemovePortMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingConfiguration_get_NetConnectionProps_Proxy( 
    INetSharingConfiguration * This,
    /* [retval][out] */ INetConnectionProps **ppProps);


void __RPC_STUB INetSharingConfiguration_get_NetConnectionProps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingConfiguration_INTERFACE_DEFINED__ */


#ifndef __INetSharingEveryConnectionCollection_INTERFACE_DEFINED__
#define __INetSharingEveryConnectionCollection_INTERFACE_DEFINED__

/* interface INetSharingEveryConnectionCollection */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingEveryConnectionCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("33C4643C-7811-46FA-A89A-768597BD7223")
    INetSharingEveryConnectionCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingEveryConnectionCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingEveryConnectionCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingEveryConnectionCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingEveryConnectionCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingEveryConnectionCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingEveryConnectionCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingEveryConnectionCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingEveryConnectionCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            INetSharingEveryConnectionCollection * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            INetSharingEveryConnectionCollection * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } INetSharingEveryConnectionCollectionVtbl;

    interface INetSharingEveryConnectionCollection
    {
        CONST_VTBL struct INetSharingEveryConnectionCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingEveryConnectionCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingEveryConnectionCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingEveryConnectionCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingEveryConnectionCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingEveryConnectionCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingEveryConnectionCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingEveryConnectionCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingEveryConnectionCollection_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define INetSharingEveryConnectionCollection_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingEveryConnectionCollection_get__NewEnum_Proxy( 
    INetSharingEveryConnectionCollection * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB INetSharingEveryConnectionCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingEveryConnectionCollection_get_Count_Proxy( 
    INetSharingEveryConnectionCollection * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB INetSharingEveryConnectionCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingEveryConnectionCollection_INTERFACE_DEFINED__ */


#ifndef __INetSharingPublicConnectionCollection_INTERFACE_DEFINED__
#define __INetSharingPublicConnectionCollection_INTERFACE_DEFINED__

/* interface INetSharingPublicConnectionCollection */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingPublicConnectionCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7D7A6355-F372-4971-A149-BFC927BE762A")
    INetSharingPublicConnectionCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingPublicConnectionCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingPublicConnectionCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingPublicConnectionCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingPublicConnectionCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingPublicConnectionCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingPublicConnectionCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingPublicConnectionCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingPublicConnectionCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            INetSharingPublicConnectionCollection * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            INetSharingPublicConnectionCollection * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } INetSharingPublicConnectionCollectionVtbl;

    interface INetSharingPublicConnectionCollection
    {
        CONST_VTBL struct INetSharingPublicConnectionCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingPublicConnectionCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingPublicConnectionCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingPublicConnectionCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingPublicConnectionCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingPublicConnectionCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingPublicConnectionCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingPublicConnectionCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingPublicConnectionCollection_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define INetSharingPublicConnectionCollection_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPublicConnectionCollection_get__NewEnum_Proxy( 
    INetSharingPublicConnectionCollection * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB INetSharingPublicConnectionCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPublicConnectionCollection_get_Count_Proxy( 
    INetSharingPublicConnectionCollection * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB INetSharingPublicConnectionCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingPublicConnectionCollection_INTERFACE_DEFINED__ */


#ifndef __INetSharingPrivateConnectionCollection_INTERFACE_DEFINED__
#define __INetSharingPrivateConnectionCollection_INTERFACE_DEFINED__

/* interface INetSharingPrivateConnectionCollection */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingPrivateConnectionCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38AE69E0-4409-402A-A2CB-E965C727F840")
    INetSharingPrivateConnectionCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingPrivateConnectionCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingPrivateConnectionCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingPrivateConnectionCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingPrivateConnectionCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingPrivateConnectionCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingPrivateConnectionCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingPrivateConnectionCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingPrivateConnectionCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            INetSharingPrivateConnectionCollection * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            INetSharingPrivateConnectionCollection * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } INetSharingPrivateConnectionCollectionVtbl;

    interface INetSharingPrivateConnectionCollection
    {
        CONST_VTBL struct INetSharingPrivateConnectionCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingPrivateConnectionCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingPrivateConnectionCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingPrivateConnectionCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingPrivateConnectionCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingPrivateConnectionCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingPrivateConnectionCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingPrivateConnectionCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingPrivateConnectionCollection_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define INetSharingPrivateConnectionCollection_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPrivateConnectionCollection_get__NewEnum_Proxy( 
    INetSharingPrivateConnectionCollection * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB INetSharingPrivateConnectionCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingPrivateConnectionCollection_get_Count_Proxy( 
    INetSharingPrivateConnectionCollection * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB INetSharingPrivateConnectionCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingPrivateConnectionCollection_INTERFACE_DEFINED__ */


#ifndef __INetSharingApplicationDefinitionCollection_INTERFACE_DEFINED__
#define __INetSharingApplicationDefinitionCollection_INTERFACE_DEFINED__

/* interface INetSharingApplicationDefinitionCollection */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingApplicationDefinitionCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("64669F21-E808-4833-A82D-4F52ABC3BCBB")
    INetSharingApplicationDefinitionCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingApplicationDefinitionCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingApplicationDefinitionCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingApplicationDefinitionCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingApplicationDefinitionCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingApplicationDefinitionCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingApplicationDefinitionCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingApplicationDefinitionCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingApplicationDefinitionCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            INetSharingApplicationDefinitionCollection * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            INetSharingApplicationDefinitionCollection * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } INetSharingApplicationDefinitionCollectionVtbl;

    interface INetSharingApplicationDefinitionCollection
    {
        CONST_VTBL struct INetSharingApplicationDefinitionCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingApplicationDefinitionCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingApplicationDefinitionCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingApplicationDefinitionCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingApplicationDefinitionCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingApplicationDefinitionCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingApplicationDefinitionCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingApplicationDefinitionCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingApplicationDefinitionCollection_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define INetSharingApplicationDefinitionCollection_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionCollection_get__NewEnum_Proxy( 
    INetSharingApplicationDefinitionCollection * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB INetSharingApplicationDefinitionCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingApplicationDefinitionCollection_get_Count_Proxy( 
    INetSharingApplicationDefinitionCollection * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB INetSharingApplicationDefinitionCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingApplicationDefinitionCollection_INTERFACE_DEFINED__ */


#ifndef __INetSharingManager_INTERFACE_DEFINED__
#define __INetSharingManager_INTERFACE_DEFINED__

/* interface INetSharingManager */
/* [unique][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B7-1CD3-11D1-B1C5-00805FC1270E")
    INetSharingManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SharingInstalled( 
            /* [retval][out] */ VARIANT_BOOL *pbInstalled) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumPublicConnections( 
            /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [retval][out] */ INetSharingPublicConnectionCollection **ppColl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumPrivateConnections( 
            /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [retval][out] */ INetSharingPrivateConnectionCollection **ppColl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumApplicationDefinitions( 
            /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [retval][out] */ INetSharingApplicationDefinitionCollection **ppColl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateBlankApplicationDefinition( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ INetSharingApplicationDefinition **ppSAD) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_INetSharingConfigurationForINetConnection( 
            /* [in] */ INetConnection *pNetConnection,
            /* [retval][out] */ INetSharingConfiguration **ppNetSharingConfiguration) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumEveryConnection( 
            /* [retval][out] */ INetSharingEveryConnectionCollection **ppColl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetSharingManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetSharingManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetSharingManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetSharingManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetSharingManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetSharingManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetSharingManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SharingInstalled )( 
            INetSharingManager * This,
            /* [retval][out] */ VARIANT_BOOL *pbInstalled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumPublicConnections )( 
            INetSharingManager * This,
            /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [retval][out] */ INetSharingPublicConnectionCollection **ppColl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumPrivateConnections )( 
            INetSharingManager * This,
            /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [retval][out] */ INetSharingPrivateConnectionCollection **ppColl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumApplicationDefinitions )( 
            INetSharingManager * This,
            /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [retval][out] */ INetSharingApplicationDefinitionCollection **ppColl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateBlankApplicationDefinition )( 
            INetSharingManager * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ INetSharingApplicationDefinition **ppSAD);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_INetSharingConfigurationForINetConnection )( 
            INetSharingManager * This,
            /* [in] */ INetConnection *pNetConnection,
            /* [retval][out] */ INetSharingConfiguration **ppNetSharingConfiguration);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumEveryConnection )( 
            INetSharingManager * This,
            /* [retval][out] */ INetSharingEveryConnectionCollection **ppColl);
        
        END_INTERFACE
    } INetSharingManagerVtbl;

    interface INetSharingManager
    {
        CONST_VTBL struct INetSharingManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetSharingManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetSharingManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetSharingManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetSharingManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetSharingManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetSharingManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetSharingManager_get_SharingInstalled(This,pbInstalled)	\
    (This)->lpVtbl -> get_SharingInstalled(This,pbInstalled)

#define INetSharingManager_get_EnumPublicConnections(This,Flags,ppColl)	\
    (This)->lpVtbl -> get_EnumPublicConnections(This,Flags,ppColl)

#define INetSharingManager_get_EnumPrivateConnections(This,Flags,ppColl)	\
    (This)->lpVtbl -> get_EnumPrivateConnections(This,Flags,ppColl)

#define INetSharingManager_get_EnumApplicationDefinitions(This,Flags,ppColl)	\
    (This)->lpVtbl -> get_EnumApplicationDefinitions(This,Flags,ppColl)

#define INetSharingManager_CreateBlankApplicationDefinition(This,bstrName,ppSAD)	\
    (This)->lpVtbl -> CreateBlankApplicationDefinition(This,bstrName,ppSAD)

#define INetSharingManager_get_INetSharingConfigurationForINetConnection(This,pNetConnection,ppNetSharingConfiguration)	\
    (This)->lpVtbl -> get_INetSharingConfigurationForINetConnection(This,pNetConnection,ppNetSharingConfiguration)

#define INetSharingManager_get_EnumEveryConnection(This,ppColl)	\
    (This)->lpVtbl -> get_EnumEveryConnection(This,ppColl)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingManager_get_SharingInstalled_Proxy( 
    INetSharingManager * This,
    /* [retval][out] */ VARIANT_BOOL *pbInstalled);


void __RPC_STUB INetSharingManager_get_SharingInstalled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingManager_get_EnumPublicConnections_Proxy( 
    INetSharingManager * This,
    /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
    /* [retval][out] */ INetSharingPublicConnectionCollection **ppColl);


void __RPC_STUB INetSharingManager_get_EnumPublicConnections_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingManager_get_EnumPrivateConnections_Proxy( 
    INetSharingManager * This,
    /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
    /* [retval][out] */ INetSharingPrivateConnectionCollection **ppColl);


void __RPC_STUB INetSharingManager_get_EnumPrivateConnections_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingManager_get_EnumApplicationDefinitions_Proxy( 
    INetSharingManager * This,
    /* [in] */ SHARINGCONNECTION_ENUM_FLAGS Flags,
    /* [retval][out] */ INetSharingApplicationDefinitionCollection **ppColl);


void __RPC_STUB INetSharingManager_get_EnumApplicationDefinitions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetSharingManager_CreateBlankApplicationDefinition_Proxy( 
    INetSharingManager * This,
    /* [in] */ BSTR bstrName,
    /* [retval][out] */ INetSharingApplicationDefinition **ppSAD);


void __RPC_STUB INetSharingManager_CreateBlankApplicationDefinition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingManager_get_INetSharingConfigurationForINetConnection_Proxy( 
    INetSharingManager * This,
    /* [in] */ INetConnection *pNetConnection,
    /* [retval][out] */ INetSharingConfiguration **ppNetSharingConfiguration);


void __RPC_STUB INetSharingManager_get_INetSharingConfigurationForINetConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INetSharingManager_get_EnumEveryConnection_Proxy( 
    INetSharingManager * This,
    /* [retval][out] */ INetSharingEveryConnectionCollection **ppColl);


void __RPC_STUB INetSharingManager_get_EnumEveryConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetSharingManager_INTERFACE_DEFINED__ */



#ifndef __NETCONLib_LIBRARY_DEFINED__
#define __NETCONLib_LIBRARY_DEFINED__

/* library NETCONLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_NETCONLib;

EXTERN_C const CLSID CLSID_NetSharingManager;

#ifdef __cplusplus

class DECLSPEC_UUID("5C63C1AD-3956-4FF8-8486-40034758315B")
NetSharingManager;
#endif

EXTERN_C const CLSID CLSID_NetSharingConfiguration;

#ifdef __cplusplus

class DECLSPEC_UUID("BD9010E2-806F-4B95-A67F-E1A0E2312BC5")
NetSharingConfiguration;
#endif

EXTERN_C const CLSID CLSID_NetSharingPortMapping;

#ifdef __cplusplus

class DECLSPEC_UUID("151A1A4C-6D62-448D-8627-90D51711AAA8")
NetSharingPortMapping;
#endif

EXTERN_C const CLSID CLSID_NetSharingApplicationDefinition;

#ifdef __cplusplus

class DECLSPEC_UUID("32020348-2A84-4BDE-BC65-CAA898EC8B2B")
NetSharingApplicationDefinition;
#endif

EXTERN_C const CLSID CLSID_EnumNetSharingPortMapping;

#ifdef __cplusplus

class DECLSPEC_UUID("FB1302CC-896A-46C1-BC96-0BCE304B714F")
EnumNetSharingPortMapping;
#endif

EXTERN_C const CLSID CLSID_EnumNetSharingApplicationDefinition;

#ifdef __cplusplus

class DECLSPEC_UUID("94AF8F7F-56E6-4E24-A718-EE581BED3805")
EnumNetSharingApplicationDefinition;
#endif

EXTERN_C const CLSID CLSID_EnumNetSharingPublicConnection;

#ifdef __cplusplus

class DECLSPEC_UUID("21D82EC2-394F-4EE8-9FCB-AD913F6330FF")
EnumNetSharingPublicConnection;
#endif

EXTERN_C const CLSID CLSID_EnumNetSharingPrivateConnection;

#ifdef __cplusplus

class DECLSPEC_UUID("E7F5C229-D58C-4719-9FA0-519E533CEF23")
EnumNetSharingPrivateConnection;
#endif

EXTERN_C const CLSID CLSID_NetSharingEveryConnectionCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("3E286992-F071-47D9-B92E-584BCB5D632F")
NetSharingEveryConnectionCollection;
#endif

EXTERN_C const CLSID CLSID_NetSharingPublicConnectionCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("F7988491-3B8E-45C0-BDA3-4C5AE31AA01E")
NetSharingPublicConnectionCollection;
#endif

EXTERN_C const CLSID CLSID_NetSharingPrivateConnectionCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("1C2F4E26-3164-497B-85BD-ECD43B5B0A36")
NetSharingPrivateConnectionCollection;
#endif

EXTERN_C const CLSID CLSID_NetSharingApplicationDefinitionCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("6C029107-B63A-4195-B30D-D6DE008E4504")
NetSharingApplicationDefinitionCollection;
#endif

EXTERN_C const CLSID CLSID_NetSharingPortMappingCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("833B3202-44C1-409F-A1CF-0045564FCF69")
NetSharingPortMappingCollection;
#endif

EXTERN_C const CLSID CLSID_NetSharingApplicationDefinitionResponseRangeProps;

#ifdef __cplusplus

class DECLSPEC_UUID("21939025-D5EF-4BBC-9D5F-61CCC67D8A29")
NetSharingApplicationDefinitionResponseRangeProps;
#endif

EXTERN_C const CLSID CLSID_NetSharingApplicationDefinitionProps;

#ifdef __cplusplus

class DECLSPEC_UUID("8E308A4A-6EE2-4E89-8115-92924A7AF994")
NetSharingApplicationDefinitionProps;
#endif

EXTERN_C const CLSID CLSID_NetSharingPortMappingProps;

#ifdef __cplusplus

class DECLSPEC_UUID("46812708-ADC1-4AC3-9120-5ACF0DE84326")
NetSharingPortMappingProps;
#endif

EXTERN_C const CLSID CLSID_NetConnectionProps;

#ifdef __cplusplus

class DECLSPEC_UUID("5A3E4638-67DF-490C-B91C-96AA22BC2C4A")
NetConnectionProps;
#endif
#endif /* __NETCONLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


