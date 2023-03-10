
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0345 */
/* Compiler settings for cluscfgserver.idl:
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

#ifndef __cluscfgserver_h__
#define __cluscfgserver_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IClusCfgServer_FWD_DEFINED__
#define __IClusCfgServer_FWD_DEFINED__
typedef interface IClusCfgServer IClusCfgServer;
#endif 	/* __IClusCfgServer_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgServer_FWD_DEFINED__
#define __AsyncIClusCfgServer_FWD_DEFINED__
typedef interface AsyncIClusCfgServer AsyncIClusCfgServer;
#endif 	/* __AsyncIClusCfgServer_FWD_DEFINED__ */


#ifndef __IClusCfgNodeInfo_FWD_DEFINED__
#define __IClusCfgNodeInfo_FWD_DEFINED__
typedef interface IClusCfgNodeInfo IClusCfgNodeInfo;
#endif 	/* __IClusCfgNodeInfo_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgNodeInfo_FWD_DEFINED__
#define __AsyncIClusCfgNodeInfo_FWD_DEFINED__
typedef interface AsyncIClusCfgNodeInfo AsyncIClusCfgNodeInfo;
#endif 	/* __AsyncIClusCfgNodeInfo_FWD_DEFINED__ */


#ifndef __IEnumClusCfgManagedResources_FWD_DEFINED__
#define __IEnumClusCfgManagedResources_FWD_DEFINED__
typedef interface IEnumClusCfgManagedResources IEnumClusCfgManagedResources;
#endif 	/* __IEnumClusCfgManagedResources_FWD_DEFINED__ */


#ifndef __AsyncIEnumClusCfgManagedResources_FWD_DEFINED__
#define __AsyncIEnumClusCfgManagedResources_FWD_DEFINED__
typedef interface AsyncIEnumClusCfgManagedResources AsyncIEnumClusCfgManagedResources;
#endif 	/* __AsyncIEnumClusCfgManagedResources_FWD_DEFINED__ */


#ifndef __IEnumClusCfgNetworks_FWD_DEFINED__
#define __IEnumClusCfgNetworks_FWD_DEFINED__
typedef interface IEnumClusCfgNetworks IEnumClusCfgNetworks;
#endif 	/* __IEnumClusCfgNetworks_FWD_DEFINED__ */


#ifndef __AsyncIEnumClusCfgNetworks_FWD_DEFINED__
#define __AsyncIEnumClusCfgNetworks_FWD_DEFINED__
typedef interface AsyncIEnumClusCfgNetworks AsyncIEnumClusCfgNetworks;
#endif 	/* __AsyncIEnumClusCfgNetworks_FWD_DEFINED__ */


#ifndef __IClusCfgManagedResourceInfo_FWD_DEFINED__
#define __IClusCfgManagedResourceInfo_FWD_DEFINED__
typedef interface IClusCfgManagedResourceInfo IClusCfgManagedResourceInfo;
#endif 	/* __IClusCfgManagedResourceInfo_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgManagedResourceInfo_FWD_DEFINED__
#define __AsyncIClusCfgManagedResourceInfo_FWD_DEFINED__
typedef interface AsyncIClusCfgManagedResourceInfo AsyncIClusCfgManagedResourceInfo;
#endif 	/* __AsyncIClusCfgManagedResourceInfo_FWD_DEFINED__ */


#ifndef __IEnumClusCfgPartitions_FWD_DEFINED__
#define __IEnumClusCfgPartitions_FWD_DEFINED__
typedef interface IEnumClusCfgPartitions IEnumClusCfgPartitions;
#endif 	/* __IEnumClusCfgPartitions_FWD_DEFINED__ */


#ifndef __AsyncIEnumClusCfgPartitions_FWD_DEFINED__
#define __AsyncIEnumClusCfgPartitions_FWD_DEFINED__
typedef interface AsyncIEnumClusCfgPartitions AsyncIEnumClusCfgPartitions;
#endif 	/* __AsyncIEnumClusCfgPartitions_FWD_DEFINED__ */


#ifndef __IClusCfgPartitionInfo_FWD_DEFINED__
#define __IClusCfgPartitionInfo_FWD_DEFINED__
typedef interface IClusCfgPartitionInfo IClusCfgPartitionInfo;
#endif 	/* __IClusCfgPartitionInfo_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgPartitionInfo_FWD_DEFINED__
#define __AsyncIClusCfgPartitionInfo_FWD_DEFINED__
typedef interface AsyncIClusCfgPartitionInfo AsyncIClusCfgPartitionInfo;
#endif 	/* __AsyncIClusCfgPartitionInfo_FWD_DEFINED__ */


#ifndef __IEnumClusCfgIPAddresses_FWD_DEFINED__
#define __IEnumClusCfgIPAddresses_FWD_DEFINED__
typedef interface IEnumClusCfgIPAddresses IEnumClusCfgIPAddresses;
#endif 	/* __IEnumClusCfgIPAddresses_FWD_DEFINED__ */


#ifndef __AsyncIEnumClusCfgIPAddresses_FWD_DEFINED__
#define __AsyncIEnumClusCfgIPAddresses_FWD_DEFINED__
typedef interface AsyncIEnumClusCfgIPAddresses AsyncIEnumClusCfgIPAddresses;
#endif 	/* __AsyncIEnumClusCfgIPAddresses_FWD_DEFINED__ */


#ifndef __IClusCfgIPAddressInfo_FWD_DEFINED__
#define __IClusCfgIPAddressInfo_FWD_DEFINED__
typedef interface IClusCfgIPAddressInfo IClusCfgIPAddressInfo;
#endif 	/* __IClusCfgIPAddressInfo_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgIPAddressInfo_FWD_DEFINED__
#define __AsyncIClusCfgIPAddressInfo_FWD_DEFINED__
typedef interface AsyncIClusCfgIPAddressInfo AsyncIClusCfgIPAddressInfo;
#endif 	/* __AsyncIClusCfgIPAddressInfo_FWD_DEFINED__ */


#ifndef __IClusCfgNetworkInfo_FWD_DEFINED__
#define __IClusCfgNetworkInfo_FWD_DEFINED__
typedef interface IClusCfgNetworkInfo IClusCfgNetworkInfo;
#endif 	/* __IClusCfgNetworkInfo_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgNetworkInfo_FWD_DEFINED__
#define __AsyncIClusCfgNetworkInfo_FWD_DEFINED__
typedef interface AsyncIClusCfgNetworkInfo AsyncIClusCfgNetworkInfo;
#endif 	/* __AsyncIClusCfgNetworkInfo_FWD_DEFINED__ */


#ifndef __IClusCfgClusterInfo_FWD_DEFINED__
#define __IClusCfgClusterInfo_FWD_DEFINED__
typedef interface IClusCfgClusterInfo IClusCfgClusterInfo;
#endif 	/* __IClusCfgClusterInfo_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgClusterInfo_FWD_DEFINED__
#define __AsyncIClusCfgClusterInfo_FWD_DEFINED__
typedef interface AsyncIClusCfgClusterInfo AsyncIClusCfgClusterInfo;
#endif 	/* __AsyncIClusCfgClusterInfo_FWD_DEFINED__ */


#ifndef __IClusCfgInitialize_FWD_DEFINED__
#define __IClusCfgInitialize_FWD_DEFINED__
typedef interface IClusCfgInitialize IClusCfgInitialize;
#endif 	/* __IClusCfgInitialize_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgInitialize_FWD_DEFINED__
#define __AsyncIClusCfgInitialize_FWD_DEFINED__
typedef interface AsyncIClusCfgInitialize AsyncIClusCfgInitialize;
#endif 	/* __AsyncIClusCfgInitialize_FWD_DEFINED__ */


#ifndef __IClusCfgCallback_FWD_DEFINED__
#define __IClusCfgCallback_FWD_DEFINED__
typedef interface IClusCfgCallback IClusCfgCallback;
#endif 	/* __IClusCfgCallback_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgCallback_FWD_DEFINED__
#define __AsyncIClusCfgCallback_FWD_DEFINED__
typedef interface AsyncIClusCfgCallback AsyncIClusCfgCallback;
#endif 	/* __AsyncIClusCfgCallback_FWD_DEFINED__ */


#ifndef __IClusCfgBaseCluster_FWD_DEFINED__
#define __IClusCfgBaseCluster_FWD_DEFINED__
typedef interface IClusCfgBaseCluster IClusCfgBaseCluster;
#endif 	/* __IClusCfgBaseCluster_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgBaseCluster_FWD_DEFINED__
#define __AsyncIClusCfgBaseCluster_FWD_DEFINED__
typedef interface AsyncIClusCfgBaseCluster AsyncIClusCfgBaseCluster;
#endif 	/* __AsyncIClusCfgBaseCluster_FWD_DEFINED__ */


#ifndef __IClusCfgCredentials_FWD_DEFINED__
#define __IClusCfgCredentials_FWD_DEFINED__
typedef interface IClusCfgCredentials IClusCfgCredentials;
#endif 	/* __IClusCfgCredentials_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgCredentials_FWD_DEFINED__
#define __AsyncIClusCfgCredentials_FWD_DEFINED__
typedef interface AsyncIClusCfgCredentials AsyncIClusCfgCredentials;
#endif 	/* __AsyncIClusCfgCredentials_FWD_DEFINED__ */


#ifndef __IClusCfgCapabilities_FWD_DEFINED__
#define __IClusCfgCapabilities_FWD_DEFINED__
typedef interface IClusCfgCapabilities IClusCfgCapabilities;
#endif 	/* __IClusCfgCapabilities_FWD_DEFINED__ */


#ifndef __IClusCfgManagedResourceCfg_FWD_DEFINED__
#define __IClusCfgManagedResourceCfg_FWD_DEFINED__
typedef interface IClusCfgManagedResourceCfg IClusCfgManagedResourceCfg;
#endif 	/* __IClusCfgManagedResourceCfg_FWD_DEFINED__ */


#ifndef __IClusCfgResourcePreCreate_FWD_DEFINED__
#define __IClusCfgResourcePreCreate_FWD_DEFINED__
typedef interface IClusCfgResourcePreCreate IClusCfgResourcePreCreate;
#endif 	/* __IClusCfgResourcePreCreate_FWD_DEFINED__ */


#ifndef __IClusCfgResourceCreate_FWD_DEFINED__
#define __IClusCfgResourceCreate_FWD_DEFINED__
typedef interface IClusCfgResourceCreate IClusCfgResourceCreate;
#endif 	/* __IClusCfgResourceCreate_FWD_DEFINED__ */


#ifndef __IClusCfgResourcePostCreate_FWD_DEFINED__
#define __IClusCfgResourcePostCreate_FWD_DEFINED__
typedef interface IClusCfgResourcePostCreate IClusCfgResourcePostCreate;
#endif 	/* __IClusCfgResourcePostCreate_FWD_DEFINED__ */


#ifndef __IClusCfgResourceEvict_FWD_DEFINED__
#define __IClusCfgResourceEvict_FWD_DEFINED__
typedef interface IClusCfgResourceEvict IClusCfgResourceEvict;
#endif 	/* __IClusCfgResourceEvict_FWD_DEFINED__ */


#ifndef __IClusCfgGroupCfg_FWD_DEFINED__
#define __IClusCfgGroupCfg_FWD_DEFINED__
typedef interface IClusCfgGroupCfg IClusCfgGroupCfg;
#endif 	/* __IClusCfgGroupCfg_FWD_DEFINED__ */


#ifndef __IClusCfgMemberSetChangeListener_FWD_DEFINED__
#define __IClusCfgMemberSetChangeListener_FWD_DEFINED__
typedef interface IClusCfgMemberSetChangeListener IClusCfgMemberSetChangeListener;
#endif 	/* __IClusCfgMemberSetChangeListener_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgMemberSetChangeListener_FWD_DEFINED__
#define __AsyncIClusCfgMemberSetChangeListener_FWD_DEFINED__
typedef interface AsyncIClusCfgMemberSetChangeListener AsyncIClusCfgMemberSetChangeListener;
#endif 	/* __AsyncIClusCfgMemberSetChangeListener_FWD_DEFINED__ */


#ifndef __IClusCfgResourceTypeInfo_FWD_DEFINED__
#define __IClusCfgResourceTypeInfo_FWD_DEFINED__
typedef interface IClusCfgResourceTypeInfo IClusCfgResourceTypeInfo;
#endif 	/* __IClusCfgResourceTypeInfo_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgResourceTypeInfo_FWD_DEFINED__
#define __AsyncIClusCfgResourceTypeInfo_FWD_DEFINED__
typedef interface AsyncIClusCfgResourceTypeInfo AsyncIClusCfgResourceTypeInfo;
#endif 	/* __AsyncIClusCfgResourceTypeInfo_FWD_DEFINED__ */


#ifndef __IClusCfgResourceTypeCreate_FWD_DEFINED__
#define __IClusCfgResourceTypeCreate_FWD_DEFINED__
typedef interface IClusCfgResourceTypeCreate IClusCfgResourceTypeCreate;
#endif 	/* __IClusCfgResourceTypeCreate_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgResourceTypeCreate_FWD_DEFINED__
#define __AsyncIClusCfgResourceTypeCreate_FWD_DEFINED__
typedef interface AsyncIClusCfgResourceTypeCreate AsyncIClusCfgResourceTypeCreate;
#endif 	/* __AsyncIClusCfgResourceTypeCreate_FWD_DEFINED__ */


#ifndef __IClusCfgEvictCleanup_FWD_DEFINED__
#define __IClusCfgEvictCleanup_FWD_DEFINED__
typedef interface IClusCfgEvictCleanup IClusCfgEvictCleanup;
#endif 	/* __IClusCfgEvictCleanup_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgEvictCleanup_FWD_DEFINED__
#define __AsyncIClusCfgEvictCleanup_FWD_DEFINED__
typedef interface AsyncIClusCfgEvictCleanup AsyncIClusCfgEvictCleanup;
#endif 	/* __AsyncIClusCfgEvictCleanup_FWD_DEFINED__ */


#ifndef __IClusCfgStartupListener_FWD_DEFINED__
#define __IClusCfgStartupListener_FWD_DEFINED__
typedef interface IClusCfgStartupListener IClusCfgStartupListener;
#endif 	/* __IClusCfgStartupListener_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgStartupListener_FWD_DEFINED__
#define __AsyncIClusCfgStartupListener_FWD_DEFINED__
typedef interface AsyncIClusCfgStartupListener AsyncIClusCfgStartupListener;
#endif 	/* __AsyncIClusCfgStartupListener_FWD_DEFINED__ */


#ifndef __IClusCfgStartupNotify_FWD_DEFINED__
#define __IClusCfgStartupNotify_FWD_DEFINED__
typedef interface IClusCfgStartupNotify IClusCfgStartupNotify;
#endif 	/* __IClusCfgStartupNotify_FWD_DEFINED__ */


#ifndef __AsyncIClusCfgStartupNotify_FWD_DEFINED__
#define __AsyncIClusCfgStartupNotify_FWD_DEFINED__
typedef interface AsyncIClusCfgStartupNotify AsyncIClusCfgStartupNotify;
#endif 	/* __AsyncIClusCfgStartupNotify_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_cluscfgserver_0000 */
/* [local] */ 

//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2000 Microsoft Corporation
//
// Remarks:
//     Generated file. See file ClusCfgServer.idl for more details.
//
//////////////////////////////////////////////////////////////////////////////



























typedef /* [public][public][public][public][public][public][public][public][public][public][public][public] */ 
enum __MIDL___MIDL_itf_cluscfgserver_0000_0001
    {	edluDriveLetterUnknown	= 0,
	edluDriveLetterNoRootDirectory	= edluDriveLetterUnknown + 1,
	edluDriveLetterRemovableDisk	= edluDriveLetterNoRootDirectory + 1,
	edluDriveLetterFixedDisk	= edluDriveLetterRemovableDisk + 1,
	edluDriveLetterNetworkDrive	= edluDriveLetterFixedDisk + 1,
	edluDriveLetterCompactDisc	= edluDriveLetterNetworkDrive + 1,
	edluDriveLetterRAMDisk	= edluDriveLetterCompactDisc + 1,
	edluDriveLetterSystem	= edluDriveLetterRAMDisk + 1,
	edluDriveLetterUnused	= edluDriveLetterSystem + 1,
	edluDriveLetterMax	= edluDriveLetterUnused + 1
    } 	EDriveLetterUsage;

typedef struct _DRIVELETTERMAPPING
    {
    EDriveLetterUsage dluDrives[ 26 ];
    } 	SDriveLetterMapping;



extern RPC_IF_HANDLE __MIDL_itf_cluscfgserver_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_cluscfgserver_0000_v0_0_s_ifspec;

#ifndef __IClusCfgServer_INTERFACE_DEFINED__
#define __IClusCfgServer_INTERFACE_DEFINED__

/* interface IClusCfgServer */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C06EAE6-990E-4051-8AA1-AD4B4EAE9CAF")
    IClusCfgServer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetClusterNodeInfo( 
            /* [out] */ IClusCfgNodeInfo **ppClusterNodeInfoOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetManagedResourcesEnum( 
            /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworksEnum( 
            /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitChanges( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgServer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClusterNodeInfo )( 
            IClusCfgServer * This,
            /* [out] */ IClusCfgNodeInfo **ppClusterNodeInfoOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetManagedResourcesEnum )( 
            IClusCfgServer * This,
            /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworksEnum )( 
            IClusCfgServer * This,
            /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut);
        
        HRESULT ( STDMETHODCALLTYPE *CommitChanges )( 
            IClusCfgServer * This);
        
        END_INTERFACE
    } IClusCfgServerVtbl;

    interface IClusCfgServer
    {
        CONST_VTBL struct IClusCfgServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgServer_GetClusterNodeInfo(This,ppClusterNodeInfoOut)	\
    (This)->lpVtbl -> GetClusterNodeInfo(This,ppClusterNodeInfoOut)

#define IClusCfgServer_GetManagedResourcesEnum(This,ppEnumManagedResourcesOut)	\
    (This)->lpVtbl -> GetManagedResourcesEnum(This,ppEnumManagedResourcesOut)

#define IClusCfgServer_GetNetworksEnum(This,ppEnumNetworksOut)	\
    (This)->lpVtbl -> GetNetworksEnum(This,ppEnumNetworksOut)

#define IClusCfgServer_CommitChanges(This)	\
    (This)->lpVtbl -> CommitChanges(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgServer_GetClusterNodeInfo_Proxy( 
    IClusCfgServer * This,
    /* [out] */ IClusCfgNodeInfo **ppClusterNodeInfoOut);


void __RPC_STUB IClusCfgServer_GetClusterNodeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgServer_GetManagedResourcesEnum_Proxy( 
    IClusCfgServer * This,
    /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut);


void __RPC_STUB IClusCfgServer_GetManagedResourcesEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgServer_GetNetworksEnum_Proxy( 
    IClusCfgServer * This,
    /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut);


void __RPC_STUB IClusCfgServer_GetNetworksEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgServer_CommitChanges_Proxy( 
    IClusCfgServer * This);


void __RPC_STUB IClusCfgServer_CommitChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgServer_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgServer_INTERFACE_DEFINED__
#define __AsyncIClusCfgServer_INTERFACE_DEFINED__

/* interface AsyncIClusCfgServer */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A1640AA-4561-4a08-B5D9-0AA38C6BE628")
    AsyncIClusCfgServer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_GetClusterNodeInfo( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetClusterNodeInfo( 
            /* [out] */ IClusCfgNodeInfo **ppClusterNodeInfoOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetManagedResourcesEnum( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetManagedResourcesEnum( 
            /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetNetworksEnum( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetNetworksEnum( 
            /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_CommitChanges( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_CommitChanges( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgServer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetClusterNodeInfo )( 
            AsyncIClusCfgServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetClusterNodeInfo )( 
            AsyncIClusCfgServer * This,
            /* [out] */ IClusCfgNodeInfo **ppClusterNodeInfoOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetManagedResourcesEnum )( 
            AsyncIClusCfgServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetManagedResourcesEnum )( 
            AsyncIClusCfgServer * This,
            /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetNetworksEnum )( 
            AsyncIClusCfgServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetNetworksEnum )( 
            AsyncIClusCfgServer * This,
            /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_CommitChanges )( 
            AsyncIClusCfgServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_CommitChanges )( 
            AsyncIClusCfgServer * This);
        
        END_INTERFACE
    } AsyncIClusCfgServerVtbl;

    interface AsyncIClusCfgServer
    {
        CONST_VTBL struct AsyncIClusCfgServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgServer_Begin_GetClusterNodeInfo(This)	\
    (This)->lpVtbl -> Begin_GetClusterNodeInfo(This)

#define AsyncIClusCfgServer_Finish_GetClusterNodeInfo(This,ppClusterNodeInfoOut)	\
    (This)->lpVtbl -> Finish_GetClusterNodeInfo(This,ppClusterNodeInfoOut)

#define AsyncIClusCfgServer_Begin_GetManagedResourcesEnum(This)	\
    (This)->lpVtbl -> Begin_GetManagedResourcesEnum(This)

#define AsyncIClusCfgServer_Finish_GetManagedResourcesEnum(This,ppEnumManagedResourcesOut)	\
    (This)->lpVtbl -> Finish_GetManagedResourcesEnum(This,ppEnumManagedResourcesOut)

#define AsyncIClusCfgServer_Begin_GetNetworksEnum(This)	\
    (This)->lpVtbl -> Begin_GetNetworksEnum(This)

#define AsyncIClusCfgServer_Finish_GetNetworksEnum(This,ppEnumNetworksOut)	\
    (This)->lpVtbl -> Finish_GetNetworksEnum(This,ppEnumNetworksOut)

#define AsyncIClusCfgServer_Begin_CommitChanges(This)	\
    (This)->lpVtbl -> Begin_CommitChanges(This)

#define AsyncIClusCfgServer_Finish_CommitChanges(This)	\
    (This)->lpVtbl -> Finish_CommitChanges(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgServer_Begin_GetClusterNodeInfo_Proxy( 
    AsyncIClusCfgServer * This);


void __RPC_STUB AsyncIClusCfgServer_Begin_GetClusterNodeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgServer_Finish_GetClusterNodeInfo_Proxy( 
    AsyncIClusCfgServer * This,
    /* [out] */ IClusCfgNodeInfo **ppClusterNodeInfoOut);


void __RPC_STUB AsyncIClusCfgServer_Finish_GetClusterNodeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgServer_Begin_GetManagedResourcesEnum_Proxy( 
    AsyncIClusCfgServer * This);


void __RPC_STUB AsyncIClusCfgServer_Begin_GetManagedResourcesEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgServer_Finish_GetManagedResourcesEnum_Proxy( 
    AsyncIClusCfgServer * This,
    /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut);


void __RPC_STUB AsyncIClusCfgServer_Finish_GetManagedResourcesEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgServer_Begin_GetNetworksEnum_Proxy( 
    AsyncIClusCfgServer * This);


void __RPC_STUB AsyncIClusCfgServer_Begin_GetNetworksEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgServer_Finish_GetNetworksEnum_Proxy( 
    AsyncIClusCfgServer * This,
    /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut);


void __RPC_STUB AsyncIClusCfgServer_Finish_GetNetworksEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgServer_Begin_CommitChanges_Proxy( 
    AsyncIClusCfgServer * This);


void __RPC_STUB AsyncIClusCfgServer_Begin_CommitChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgServer_Finish_CommitChanges_Proxy( 
    AsyncIClusCfgServer * This);


void __RPC_STUB AsyncIClusCfgServer_Finish_CommitChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgServer_INTERFACE_DEFINED__ */


#ifndef __IClusCfgNodeInfo_INTERFACE_DEFINED__
#define __IClusCfgNodeInfo_INTERFACE_DEFINED__

/* interface IClusCfgNodeInfo */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgNodeInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E4B5FA15-DD07-439e-A623-8823524E3D19")
    IClusCfgNodeInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR *pbstrNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR bstrNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMemberOfCluster( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClusterConfigInfo( 
            /* [out] */ IClusCfgClusterInfo **ppClusCfgClusterInfoOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOSVersion( 
            /* [out] */ DWORD *pdwMajorVersionOut,
            /* [out] */ DWORD *pdwMinorVersionOut,
            /* [out] */ WORD *pwSuiteMaskOut,
            /* [out] */ BYTE *pbProductTypeOut,
            /* [out] */ BSTR *pbstrCSDVersionOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClusterVersion( 
            /* [out] */ DWORD *pdwNodeHighestVersion,
            /* [out] */ DWORD *pdwNodeLowestVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDriveLetterMappings( 
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgNodeInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgNodeInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgNodeInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IClusCfgNodeInfo * This,
            /* [out] */ BSTR *pbstrNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IClusCfgNodeInfo * This,
            /* [in] */ BSTR bstrNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *IsMemberOfCluster )( 
            IClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClusterConfigInfo )( 
            IClusCfgNodeInfo * This,
            /* [out] */ IClusCfgClusterInfo **ppClusCfgClusterInfoOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetOSVersion )( 
            IClusCfgNodeInfo * This,
            /* [out] */ DWORD *pdwMajorVersionOut,
            /* [out] */ DWORD *pdwMinorVersionOut,
            /* [out] */ WORD *pwSuiteMaskOut,
            /* [out] */ BYTE *pbProductTypeOut,
            /* [out] */ BSTR *pbstrCSDVersionOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetClusterVersion )( 
            IClusCfgNodeInfo * This,
            /* [out] */ DWORD *pdwNodeHighestVersion,
            /* [out] */ DWORD *pdwNodeLowestVersion);
        
        HRESULT ( STDMETHODCALLTYPE *GetDriveLetterMappings )( 
            IClusCfgNodeInfo * This,
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut);
        
        END_INTERFACE
    } IClusCfgNodeInfoVtbl;

    interface IClusCfgNodeInfo
    {
        CONST_VTBL struct IClusCfgNodeInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgNodeInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgNodeInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgNodeInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgNodeInfo_GetName(This,pbstrNameOut)	\
    (This)->lpVtbl -> GetName(This,pbstrNameOut)

#define IClusCfgNodeInfo_SetName(This,bstrNameIn)	\
    (This)->lpVtbl -> SetName(This,bstrNameIn)

#define IClusCfgNodeInfo_IsMemberOfCluster(This)	\
    (This)->lpVtbl -> IsMemberOfCluster(This)

#define IClusCfgNodeInfo_GetClusterConfigInfo(This,ppClusCfgClusterInfoOut)	\
    (This)->lpVtbl -> GetClusterConfigInfo(This,ppClusCfgClusterInfoOut)

#define IClusCfgNodeInfo_GetOSVersion(This,pdwMajorVersionOut,pdwMinorVersionOut,pwSuiteMaskOut,pbProductTypeOut,pbstrCSDVersionOut)	\
    (This)->lpVtbl -> GetOSVersion(This,pdwMajorVersionOut,pdwMinorVersionOut,pwSuiteMaskOut,pbProductTypeOut,pbstrCSDVersionOut)

#define IClusCfgNodeInfo_GetClusterVersion(This,pdwNodeHighestVersion,pdwNodeLowestVersion)	\
    (This)->lpVtbl -> GetClusterVersion(This,pdwNodeHighestVersion,pdwNodeLowestVersion)

#define IClusCfgNodeInfo_GetDriveLetterMappings(This,pdlmDriveLetterUsageOut)	\
    (This)->lpVtbl -> GetDriveLetterMappings(This,pdlmDriveLetterUsageOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgNodeInfo_GetName_Proxy( 
    IClusCfgNodeInfo * This,
    /* [out] */ BSTR *pbstrNameOut);


void __RPC_STUB IClusCfgNodeInfo_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNodeInfo_SetName_Proxy( 
    IClusCfgNodeInfo * This,
    /* [in] */ BSTR bstrNameIn);


void __RPC_STUB IClusCfgNodeInfo_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNodeInfo_IsMemberOfCluster_Proxy( 
    IClusCfgNodeInfo * This);


void __RPC_STUB IClusCfgNodeInfo_IsMemberOfCluster_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNodeInfo_GetClusterConfigInfo_Proxy( 
    IClusCfgNodeInfo * This,
    /* [out] */ IClusCfgClusterInfo **ppClusCfgClusterInfoOut);


void __RPC_STUB IClusCfgNodeInfo_GetClusterConfigInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNodeInfo_GetOSVersion_Proxy( 
    IClusCfgNodeInfo * This,
    /* [out] */ DWORD *pdwMajorVersionOut,
    /* [out] */ DWORD *pdwMinorVersionOut,
    /* [out] */ WORD *pwSuiteMaskOut,
    /* [out] */ BYTE *pbProductTypeOut,
    /* [out] */ BSTR *pbstrCSDVersionOut);


void __RPC_STUB IClusCfgNodeInfo_GetOSVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNodeInfo_GetClusterVersion_Proxy( 
    IClusCfgNodeInfo * This,
    /* [out] */ DWORD *pdwNodeHighestVersion,
    /* [out] */ DWORD *pdwNodeLowestVersion);


void __RPC_STUB IClusCfgNodeInfo_GetClusterVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNodeInfo_GetDriveLetterMappings_Proxy( 
    IClusCfgNodeInfo * This,
    /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut);


void __RPC_STUB IClusCfgNodeInfo_GetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgNodeInfo_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgNodeInfo_INTERFACE_DEFINED__
#define __AsyncIClusCfgNodeInfo_INTERFACE_DEFINED__

/* interface AsyncIClusCfgNodeInfo */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgNodeInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F3BB40B-DF27-40a0-B31A-BA18324CEB9D")
    AsyncIClusCfgNodeInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_GetName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetName( 
            /* [out] */ BSTR *pbstrNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetName( 
            /* [in] */ BSTR bstrNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_IsMemberOfCluster( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_IsMemberOfCluster( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetClusterConfigInfo( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetClusterConfigInfo( 
            /* [out] */ IClusCfgClusterInfo **ppClusCfgClusterInfoOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetOSVersion( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetOSVersion( 
            /* [out] */ DWORD *pdwMajorVersionOut,
            /* [out] */ DWORD *pdwMinorVersionOut,
            /* [out] */ WORD *pwSuiteMaskOut,
            /* [out] */ BYTE *pbProductTypeOut,
            /* [out] */ BSTR *pbstrCSDVersionOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetClusterVersion( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetClusterVersion( 
            /* [out] */ DWORD *pdwNodeHighestVersion,
            /* [out] */ DWORD *pdwNodeLowestVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetDriveLetterMappings( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetDriveLetterMappings( 
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgNodeInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgNodeInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgNodeInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetName )( 
            AsyncIClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetName )( 
            AsyncIClusCfgNodeInfo * This,
            /* [out] */ BSTR *pbstrNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetName )( 
            AsyncIClusCfgNodeInfo * This,
            /* [in] */ BSTR bstrNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetName )( 
            AsyncIClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_IsMemberOfCluster )( 
            AsyncIClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_IsMemberOfCluster )( 
            AsyncIClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetClusterConfigInfo )( 
            AsyncIClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetClusterConfigInfo )( 
            AsyncIClusCfgNodeInfo * This,
            /* [out] */ IClusCfgClusterInfo **ppClusCfgClusterInfoOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetOSVersion )( 
            AsyncIClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetOSVersion )( 
            AsyncIClusCfgNodeInfo * This,
            /* [out] */ DWORD *pdwMajorVersionOut,
            /* [out] */ DWORD *pdwMinorVersionOut,
            /* [out] */ WORD *pwSuiteMaskOut,
            /* [out] */ BYTE *pbProductTypeOut,
            /* [out] */ BSTR *pbstrCSDVersionOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetClusterVersion )( 
            AsyncIClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetClusterVersion )( 
            AsyncIClusCfgNodeInfo * This,
            /* [out] */ DWORD *pdwNodeHighestVersion,
            /* [out] */ DWORD *pdwNodeLowestVersion);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetDriveLetterMappings )( 
            AsyncIClusCfgNodeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetDriveLetterMappings )( 
            AsyncIClusCfgNodeInfo * This,
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut);
        
        END_INTERFACE
    } AsyncIClusCfgNodeInfoVtbl;

    interface AsyncIClusCfgNodeInfo
    {
        CONST_VTBL struct AsyncIClusCfgNodeInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgNodeInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgNodeInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgNodeInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgNodeInfo_Begin_GetName(This)	\
    (This)->lpVtbl -> Begin_GetName(This)

#define AsyncIClusCfgNodeInfo_Finish_GetName(This,pbstrNameOut)	\
    (This)->lpVtbl -> Finish_GetName(This,pbstrNameOut)

#define AsyncIClusCfgNodeInfo_Begin_SetName(This,bstrNameIn)	\
    (This)->lpVtbl -> Begin_SetName(This,bstrNameIn)

#define AsyncIClusCfgNodeInfo_Finish_SetName(This)	\
    (This)->lpVtbl -> Finish_SetName(This)

#define AsyncIClusCfgNodeInfo_Begin_IsMemberOfCluster(This)	\
    (This)->lpVtbl -> Begin_IsMemberOfCluster(This)

#define AsyncIClusCfgNodeInfo_Finish_IsMemberOfCluster(This)	\
    (This)->lpVtbl -> Finish_IsMemberOfCluster(This)

#define AsyncIClusCfgNodeInfo_Begin_GetClusterConfigInfo(This)	\
    (This)->lpVtbl -> Begin_GetClusterConfigInfo(This)

#define AsyncIClusCfgNodeInfo_Finish_GetClusterConfigInfo(This,ppClusCfgClusterInfoOut)	\
    (This)->lpVtbl -> Finish_GetClusterConfigInfo(This,ppClusCfgClusterInfoOut)

#define AsyncIClusCfgNodeInfo_Begin_GetOSVersion(This)	\
    (This)->lpVtbl -> Begin_GetOSVersion(This)

#define AsyncIClusCfgNodeInfo_Finish_GetOSVersion(This,pdwMajorVersionOut,pdwMinorVersionOut,pwSuiteMaskOut,pbProductTypeOut,pbstrCSDVersionOut)	\
    (This)->lpVtbl -> Finish_GetOSVersion(This,pdwMajorVersionOut,pdwMinorVersionOut,pwSuiteMaskOut,pbProductTypeOut,pbstrCSDVersionOut)

#define AsyncIClusCfgNodeInfo_Begin_GetClusterVersion(This)	\
    (This)->lpVtbl -> Begin_GetClusterVersion(This)

#define AsyncIClusCfgNodeInfo_Finish_GetClusterVersion(This,pdwNodeHighestVersion,pdwNodeLowestVersion)	\
    (This)->lpVtbl -> Finish_GetClusterVersion(This,pdwNodeHighestVersion,pdwNodeLowestVersion)

#define AsyncIClusCfgNodeInfo_Begin_GetDriveLetterMappings(This)	\
    (This)->lpVtbl -> Begin_GetDriveLetterMappings(This)

#define AsyncIClusCfgNodeInfo_Finish_GetDriveLetterMappings(This,pdlmDriveLetterUsageOut)	\
    (This)->lpVtbl -> Finish_GetDriveLetterMappings(This,pdlmDriveLetterUsageOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Begin_GetName_Proxy( 
    AsyncIClusCfgNodeInfo * This);


void __RPC_STUB AsyncIClusCfgNodeInfo_Begin_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Finish_GetName_Proxy( 
    AsyncIClusCfgNodeInfo * This,
    /* [out] */ BSTR *pbstrNameOut);


void __RPC_STUB AsyncIClusCfgNodeInfo_Finish_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Begin_SetName_Proxy( 
    AsyncIClusCfgNodeInfo * This,
    /* [in] */ BSTR bstrNameIn);


void __RPC_STUB AsyncIClusCfgNodeInfo_Begin_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Finish_SetName_Proxy( 
    AsyncIClusCfgNodeInfo * This);


void __RPC_STUB AsyncIClusCfgNodeInfo_Finish_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Begin_IsMemberOfCluster_Proxy( 
    AsyncIClusCfgNodeInfo * This);


void __RPC_STUB AsyncIClusCfgNodeInfo_Begin_IsMemberOfCluster_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Finish_IsMemberOfCluster_Proxy( 
    AsyncIClusCfgNodeInfo * This);


void __RPC_STUB AsyncIClusCfgNodeInfo_Finish_IsMemberOfCluster_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Begin_GetClusterConfigInfo_Proxy( 
    AsyncIClusCfgNodeInfo * This);


void __RPC_STUB AsyncIClusCfgNodeInfo_Begin_GetClusterConfigInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Finish_GetClusterConfigInfo_Proxy( 
    AsyncIClusCfgNodeInfo * This,
    /* [out] */ IClusCfgClusterInfo **ppClusCfgClusterInfoOut);


void __RPC_STUB AsyncIClusCfgNodeInfo_Finish_GetClusterConfigInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Begin_GetOSVersion_Proxy( 
    AsyncIClusCfgNodeInfo * This);


void __RPC_STUB AsyncIClusCfgNodeInfo_Begin_GetOSVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Finish_GetOSVersion_Proxy( 
    AsyncIClusCfgNodeInfo * This,
    /* [out] */ DWORD *pdwMajorVersionOut,
    /* [out] */ DWORD *pdwMinorVersionOut,
    /* [out] */ WORD *pwSuiteMaskOut,
    /* [out] */ BYTE *pbProductTypeOut,
    /* [out] */ BSTR *pbstrCSDVersionOut);


void __RPC_STUB AsyncIClusCfgNodeInfo_Finish_GetOSVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Begin_GetClusterVersion_Proxy( 
    AsyncIClusCfgNodeInfo * This);


void __RPC_STUB AsyncIClusCfgNodeInfo_Begin_GetClusterVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Finish_GetClusterVersion_Proxy( 
    AsyncIClusCfgNodeInfo * This,
    /* [out] */ DWORD *pdwNodeHighestVersion,
    /* [out] */ DWORD *pdwNodeLowestVersion);


void __RPC_STUB AsyncIClusCfgNodeInfo_Finish_GetClusterVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Begin_GetDriveLetterMappings_Proxy( 
    AsyncIClusCfgNodeInfo * This);


void __RPC_STUB AsyncIClusCfgNodeInfo_Begin_GetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNodeInfo_Finish_GetDriveLetterMappings_Proxy( 
    AsyncIClusCfgNodeInfo * This,
    /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut);


void __RPC_STUB AsyncIClusCfgNodeInfo_Finish_GetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgNodeInfo_INTERFACE_DEFINED__ */


#ifndef __IEnumClusCfgManagedResources_INTERFACE_DEFINED__
#define __IEnumClusCfgManagedResources_INTERFACE_DEFINED__

/* interface IEnumClusCfgManagedResources */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IEnumClusCfgManagedResources;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7DBE11EB-A5DF-4534-ABF6-8BAC7B53FC95")
    IEnumClusCfgManagedResources : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cNumberRequestedIn,
            /* [length_is][size_is][out] */ IClusCfgManagedResourceInfo **rgpManagedResourceInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cNumberToSkip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumClusCfgManagedResourcesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumClusCfgManagedResources * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumClusCfgManagedResources * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumClusCfgManagedResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumClusCfgManagedResources * This,
            /* [in] */ ULONG cNumberRequestedIn,
            /* [length_is][size_is][out] */ IClusCfgManagedResourceInfo **rgpManagedResourceInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumClusCfgManagedResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumClusCfgManagedResources * This,
            /* [in] */ ULONG cNumberToSkip);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumClusCfgManagedResources * This,
            /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut);
        
        END_INTERFACE
    } IEnumClusCfgManagedResourcesVtbl;

    interface IEnumClusCfgManagedResources
    {
        CONST_VTBL struct IEnumClusCfgManagedResourcesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumClusCfgManagedResources_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumClusCfgManagedResources_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumClusCfgManagedResources_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumClusCfgManagedResources_Next(This,cNumberRequestedIn,rgpManagedResourceInfoOut,pcNumberFetchedOut)	\
    (This)->lpVtbl -> Next(This,cNumberRequestedIn,rgpManagedResourceInfoOut,pcNumberFetchedOut)

#define IEnumClusCfgManagedResources_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumClusCfgManagedResources_Skip(This,cNumberToSkip)	\
    (This)->lpVtbl -> Skip(This,cNumberToSkip)

#define IEnumClusCfgManagedResources_Clone(This,ppEnumManagedResourcesOut)	\
    (This)->lpVtbl -> Clone(This,ppEnumManagedResourcesOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumClusCfgManagedResources_Next_Proxy( 
    IEnumClusCfgManagedResources * This,
    /* [in] */ ULONG cNumberRequestedIn,
    /* [length_is][size_is][out] */ IClusCfgManagedResourceInfo **rgpManagedResourceInfoOut,
    /* [out] */ ULONG *pcNumberFetchedOut);


void __RPC_STUB IEnumClusCfgManagedResources_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgManagedResources_Reset_Proxy( 
    IEnumClusCfgManagedResources * This);


void __RPC_STUB IEnumClusCfgManagedResources_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgManagedResources_Skip_Proxy( 
    IEnumClusCfgManagedResources * This,
    /* [in] */ ULONG cNumberToSkip);


void __RPC_STUB IEnumClusCfgManagedResources_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgManagedResources_Clone_Proxy( 
    IEnumClusCfgManagedResources * This,
    /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut);


void __RPC_STUB IEnumClusCfgManagedResources_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumClusCfgManagedResources_INTERFACE_DEFINED__ */


#ifndef __AsyncIEnumClusCfgManagedResources_INTERFACE_DEFINED__
#define __AsyncIEnumClusCfgManagedResources_INTERFACE_DEFINED__

/* interface AsyncIEnumClusCfgManagedResources */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIEnumClusCfgManagedResources;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B138483F-9695-4fa6-A98F-0DE2FB355449")
    AsyncIEnumClusCfgManagedResources : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Next( 
            /* [in] */ ULONG cNumberRequestedIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Next( 
            /* [length_is][size_is][out] */ IClusCfgManagedResourceInfo **rgpManagedResourceInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Skip( 
            /* [in] */ ULONG cNumberToSkip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Skip( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Clone( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Clone( 
            /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIEnumClusCfgManagedResourcesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIEnumClusCfgManagedResources * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIEnumClusCfgManagedResources * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIEnumClusCfgManagedResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Next )( 
            AsyncIEnumClusCfgManagedResources * This,
            /* [in] */ ULONG cNumberRequestedIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Next )( 
            AsyncIEnumClusCfgManagedResources * This,
            /* [length_is][size_is][out] */ IClusCfgManagedResourceInfo **rgpManagedResourceInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Reset )( 
            AsyncIEnumClusCfgManagedResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Reset )( 
            AsyncIEnumClusCfgManagedResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Skip )( 
            AsyncIEnumClusCfgManagedResources * This,
            /* [in] */ ULONG cNumberToSkip);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Skip )( 
            AsyncIEnumClusCfgManagedResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Clone )( 
            AsyncIEnumClusCfgManagedResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Clone )( 
            AsyncIEnumClusCfgManagedResources * This,
            /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut);
        
        END_INTERFACE
    } AsyncIEnumClusCfgManagedResourcesVtbl;

    interface AsyncIEnumClusCfgManagedResources
    {
        CONST_VTBL struct AsyncIEnumClusCfgManagedResourcesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIEnumClusCfgManagedResources_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIEnumClusCfgManagedResources_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIEnumClusCfgManagedResources_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIEnumClusCfgManagedResources_Begin_Next(This,cNumberRequestedIn)	\
    (This)->lpVtbl -> Begin_Next(This,cNumberRequestedIn)

#define AsyncIEnumClusCfgManagedResources_Finish_Next(This,rgpManagedResourceInfoOut,pcNumberFetchedOut)	\
    (This)->lpVtbl -> Finish_Next(This,rgpManagedResourceInfoOut,pcNumberFetchedOut)

#define AsyncIEnumClusCfgManagedResources_Begin_Reset(This)	\
    (This)->lpVtbl -> Begin_Reset(This)

#define AsyncIEnumClusCfgManagedResources_Finish_Reset(This)	\
    (This)->lpVtbl -> Finish_Reset(This)

#define AsyncIEnumClusCfgManagedResources_Begin_Skip(This,cNumberToSkip)	\
    (This)->lpVtbl -> Begin_Skip(This,cNumberToSkip)

#define AsyncIEnumClusCfgManagedResources_Finish_Skip(This)	\
    (This)->lpVtbl -> Finish_Skip(This)

#define AsyncIEnumClusCfgManagedResources_Begin_Clone(This)	\
    (This)->lpVtbl -> Begin_Clone(This)

#define AsyncIEnumClusCfgManagedResources_Finish_Clone(This,ppEnumManagedResourcesOut)	\
    (This)->lpVtbl -> Finish_Clone(This,ppEnumManagedResourcesOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgManagedResources_Begin_Next_Proxy( 
    AsyncIEnumClusCfgManagedResources * This,
    /* [in] */ ULONG cNumberRequestedIn);


void __RPC_STUB AsyncIEnumClusCfgManagedResources_Begin_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgManagedResources_Finish_Next_Proxy( 
    AsyncIEnumClusCfgManagedResources * This,
    /* [length_is][size_is][out] */ IClusCfgManagedResourceInfo **rgpManagedResourceInfoOut,
    /* [out] */ ULONG *pcNumberFetchedOut);


void __RPC_STUB AsyncIEnumClusCfgManagedResources_Finish_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgManagedResources_Begin_Reset_Proxy( 
    AsyncIEnumClusCfgManagedResources * This);


void __RPC_STUB AsyncIEnumClusCfgManagedResources_Begin_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgManagedResources_Finish_Reset_Proxy( 
    AsyncIEnumClusCfgManagedResources * This);


void __RPC_STUB AsyncIEnumClusCfgManagedResources_Finish_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgManagedResources_Begin_Skip_Proxy( 
    AsyncIEnumClusCfgManagedResources * This,
    /* [in] */ ULONG cNumberToSkip);


void __RPC_STUB AsyncIEnumClusCfgManagedResources_Begin_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgManagedResources_Finish_Skip_Proxy( 
    AsyncIEnumClusCfgManagedResources * This);


void __RPC_STUB AsyncIEnumClusCfgManagedResources_Finish_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgManagedResources_Begin_Clone_Proxy( 
    AsyncIEnumClusCfgManagedResources * This);


void __RPC_STUB AsyncIEnumClusCfgManagedResources_Begin_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgManagedResources_Finish_Clone_Proxy( 
    AsyncIEnumClusCfgManagedResources * This,
    /* [out] */ IEnumClusCfgManagedResources **ppEnumManagedResourcesOut);


void __RPC_STUB AsyncIEnumClusCfgManagedResources_Finish_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIEnumClusCfgManagedResources_INTERFACE_DEFINED__ */


#ifndef __IEnumClusCfgNetworks_INTERFACE_DEFINED__
#define __IEnumClusCfgNetworks_INTERFACE_DEFINED__

/* interface IEnumClusCfgNetworks */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IEnumClusCfgNetworks;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF3FAED8-1322-4bcb-9923-B5B745A69E36")
    IEnumClusCfgNetworks : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cNumberRequestedIn,
            /* [length_is][size_is][out] */ IClusCfgNetworkInfo **rgpNetworkInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cNumberToSkipIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumClusCfgNetworksVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumClusCfgNetworks * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumClusCfgNetworks * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumClusCfgNetworks * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumClusCfgNetworks * This,
            /* [in] */ ULONG cNumberRequestedIn,
            /* [length_is][size_is][out] */ IClusCfgNetworkInfo **rgpNetworkInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumClusCfgNetworks * This,
            /* [in] */ ULONG cNumberToSkipIn);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumClusCfgNetworks * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumClusCfgNetworks * This,
            /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut);
        
        END_INTERFACE
    } IEnumClusCfgNetworksVtbl;

    interface IEnumClusCfgNetworks
    {
        CONST_VTBL struct IEnumClusCfgNetworksVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumClusCfgNetworks_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumClusCfgNetworks_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumClusCfgNetworks_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumClusCfgNetworks_Next(This,cNumberRequestedIn,rgpNetworkInfoOut,pcNumberFetchedOut)	\
    (This)->lpVtbl -> Next(This,cNumberRequestedIn,rgpNetworkInfoOut,pcNumberFetchedOut)

#define IEnumClusCfgNetworks_Skip(This,cNumberToSkipIn)	\
    (This)->lpVtbl -> Skip(This,cNumberToSkipIn)

#define IEnumClusCfgNetworks_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumClusCfgNetworks_Clone(This,ppEnumNetworksOut)	\
    (This)->lpVtbl -> Clone(This,ppEnumNetworksOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumClusCfgNetworks_Next_Proxy( 
    IEnumClusCfgNetworks * This,
    /* [in] */ ULONG cNumberRequestedIn,
    /* [length_is][size_is][out] */ IClusCfgNetworkInfo **rgpNetworkInfoOut,
    /* [out] */ ULONG *pcNumberFetchedOut);


void __RPC_STUB IEnumClusCfgNetworks_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgNetworks_Skip_Proxy( 
    IEnumClusCfgNetworks * This,
    /* [in] */ ULONG cNumberToSkipIn);


void __RPC_STUB IEnumClusCfgNetworks_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgNetworks_Reset_Proxy( 
    IEnumClusCfgNetworks * This);


void __RPC_STUB IEnumClusCfgNetworks_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgNetworks_Clone_Proxy( 
    IEnumClusCfgNetworks * This,
    /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut);


void __RPC_STUB IEnumClusCfgNetworks_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumClusCfgNetworks_INTERFACE_DEFINED__ */


#ifndef __AsyncIEnumClusCfgNetworks_INTERFACE_DEFINED__
#define __AsyncIEnumClusCfgNetworks_INTERFACE_DEFINED__

/* interface AsyncIEnumClusCfgNetworks */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIEnumClusCfgNetworks;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F56B9B0D-E7B8-49ec-A843-5475076B947D")
    AsyncIEnumClusCfgNetworks : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Next( 
            /* [in] */ ULONG cNumberRequestedIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Next( 
            /* [length_is][size_is][out] */ IClusCfgNetworkInfo **rgpNetworkInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Skip( 
            /* [in] */ ULONG cNumberToSkipIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Skip( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Clone( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Clone( 
            /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIEnumClusCfgNetworksVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIEnumClusCfgNetworks * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIEnumClusCfgNetworks * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIEnumClusCfgNetworks * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Next )( 
            AsyncIEnumClusCfgNetworks * This,
            /* [in] */ ULONG cNumberRequestedIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Next )( 
            AsyncIEnumClusCfgNetworks * This,
            /* [length_is][size_is][out] */ IClusCfgNetworkInfo **rgpNetworkInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Skip )( 
            AsyncIEnumClusCfgNetworks * This,
            /* [in] */ ULONG cNumberToSkipIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Skip )( 
            AsyncIEnumClusCfgNetworks * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Reset )( 
            AsyncIEnumClusCfgNetworks * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Reset )( 
            AsyncIEnumClusCfgNetworks * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Clone )( 
            AsyncIEnumClusCfgNetworks * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Clone )( 
            AsyncIEnumClusCfgNetworks * This,
            /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut);
        
        END_INTERFACE
    } AsyncIEnumClusCfgNetworksVtbl;

    interface AsyncIEnumClusCfgNetworks
    {
        CONST_VTBL struct AsyncIEnumClusCfgNetworksVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIEnumClusCfgNetworks_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIEnumClusCfgNetworks_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIEnumClusCfgNetworks_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIEnumClusCfgNetworks_Begin_Next(This,cNumberRequestedIn)	\
    (This)->lpVtbl -> Begin_Next(This,cNumberRequestedIn)

#define AsyncIEnumClusCfgNetworks_Finish_Next(This,rgpNetworkInfoOut,pcNumberFetchedOut)	\
    (This)->lpVtbl -> Finish_Next(This,rgpNetworkInfoOut,pcNumberFetchedOut)

#define AsyncIEnumClusCfgNetworks_Begin_Skip(This,cNumberToSkipIn)	\
    (This)->lpVtbl -> Begin_Skip(This,cNumberToSkipIn)

#define AsyncIEnumClusCfgNetworks_Finish_Skip(This)	\
    (This)->lpVtbl -> Finish_Skip(This)

#define AsyncIEnumClusCfgNetworks_Begin_Reset(This)	\
    (This)->lpVtbl -> Begin_Reset(This)

#define AsyncIEnumClusCfgNetworks_Finish_Reset(This)	\
    (This)->lpVtbl -> Finish_Reset(This)

#define AsyncIEnumClusCfgNetworks_Begin_Clone(This)	\
    (This)->lpVtbl -> Begin_Clone(This)

#define AsyncIEnumClusCfgNetworks_Finish_Clone(This,ppEnumNetworksOut)	\
    (This)->lpVtbl -> Finish_Clone(This,ppEnumNetworksOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgNetworks_Begin_Next_Proxy( 
    AsyncIEnumClusCfgNetworks * This,
    /* [in] */ ULONG cNumberRequestedIn);


void __RPC_STUB AsyncIEnumClusCfgNetworks_Begin_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgNetworks_Finish_Next_Proxy( 
    AsyncIEnumClusCfgNetworks * This,
    /* [length_is][size_is][out] */ IClusCfgNetworkInfo **rgpNetworkInfoOut,
    /* [out] */ ULONG *pcNumberFetchedOut);


void __RPC_STUB AsyncIEnumClusCfgNetworks_Finish_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgNetworks_Begin_Skip_Proxy( 
    AsyncIEnumClusCfgNetworks * This,
    /* [in] */ ULONG cNumberToSkipIn);


void __RPC_STUB AsyncIEnumClusCfgNetworks_Begin_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgNetworks_Finish_Skip_Proxy( 
    AsyncIEnumClusCfgNetworks * This);


void __RPC_STUB AsyncIEnumClusCfgNetworks_Finish_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgNetworks_Begin_Reset_Proxy( 
    AsyncIEnumClusCfgNetworks * This);


void __RPC_STUB AsyncIEnumClusCfgNetworks_Begin_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgNetworks_Finish_Reset_Proxy( 
    AsyncIEnumClusCfgNetworks * This);


void __RPC_STUB AsyncIEnumClusCfgNetworks_Finish_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgNetworks_Begin_Clone_Proxy( 
    AsyncIEnumClusCfgNetworks * This);


void __RPC_STUB AsyncIEnumClusCfgNetworks_Begin_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgNetworks_Finish_Clone_Proxy( 
    AsyncIEnumClusCfgNetworks * This,
    /* [out] */ IEnumClusCfgNetworks **ppEnumNetworksOut);


void __RPC_STUB AsyncIEnumClusCfgNetworks_Finish_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIEnumClusCfgNetworks_INTERFACE_DEFINED__ */


#ifndef __IClusCfgManagedResourceInfo_INTERFACE_DEFINED__
#define __IClusCfgManagedResourceInfo_INTERFACE_DEFINED__

/* interface IClusCfgManagedResourceInfo */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgManagedResourceInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E0324847-1520-41b0-B960-54198DA5F8AF")
    IClusCfgManagedResourceInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetUID( 
            /* [out] */ BSTR *pbstrUIDOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR *pbstrNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR bstrNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsManaged( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetManaged( 
            /* [in] */ BOOL fIsManagedIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsQuorumDevice( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetQuorumedDevice( 
            /* [in] */ BOOL fIsQuorumDeviceIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsQuorumCapable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDriveLetterMappings( 
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterMappingOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDriveLetterMappings( 
            /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDeviceJoinable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDeviceJoinable( 
            /* [in] */ BOOL joinable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgManagedResourceInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgManagedResourceInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgManagedResourceInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetUID )( 
            IClusCfgManagedResourceInfo * This,
            /* [out] */ BSTR *pbstrUIDOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IClusCfgManagedResourceInfo * This,
            /* [out] */ BSTR *pbstrNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IClusCfgManagedResourceInfo * This,
            /* [in] */ BSTR bstrNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *IsManaged )( 
            IClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetManaged )( 
            IClusCfgManagedResourceInfo * This,
            /* [in] */ BOOL fIsManagedIn);
        
        HRESULT ( STDMETHODCALLTYPE *IsQuorumDevice )( 
            IClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetQuorumedDevice )( 
            IClusCfgManagedResourceInfo * This,
            /* [in] */ BOOL fIsQuorumDeviceIn);
        
        HRESULT ( STDMETHODCALLTYPE *IsQuorumCapable )( 
            IClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDriveLetterMappings )( 
            IClusCfgManagedResourceInfo * This,
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterMappingOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetDriveLetterMappings )( 
            IClusCfgManagedResourceInfo * This,
            /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn);
        
        HRESULT ( STDMETHODCALLTYPE *IsDeviceJoinable )( 
            IClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDeviceJoinable )( 
            IClusCfgManagedResourceInfo * This,
            /* [in] */ BOOL joinable);
        
        END_INTERFACE
    } IClusCfgManagedResourceInfoVtbl;

    interface IClusCfgManagedResourceInfo
    {
        CONST_VTBL struct IClusCfgManagedResourceInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgManagedResourceInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgManagedResourceInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgManagedResourceInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgManagedResourceInfo_GetUID(This,pbstrUIDOut)	\
    (This)->lpVtbl -> GetUID(This,pbstrUIDOut)

#define IClusCfgManagedResourceInfo_GetName(This,pbstrNameOut)	\
    (This)->lpVtbl -> GetName(This,pbstrNameOut)

#define IClusCfgManagedResourceInfo_SetName(This,bstrNameIn)	\
    (This)->lpVtbl -> SetName(This,bstrNameIn)

#define IClusCfgManagedResourceInfo_IsManaged(This)	\
    (This)->lpVtbl -> IsManaged(This)

#define IClusCfgManagedResourceInfo_SetManaged(This,fIsManagedIn)	\
    (This)->lpVtbl -> SetManaged(This,fIsManagedIn)

#define IClusCfgManagedResourceInfo_IsQuorumDevice(This)	\
    (This)->lpVtbl -> IsQuorumDevice(This)

#define IClusCfgManagedResourceInfo_SetQuorumedDevice(This,fIsQuorumDeviceIn)	\
    (This)->lpVtbl -> SetQuorumedDevice(This,fIsQuorumDeviceIn)

#define IClusCfgManagedResourceInfo_IsQuorumCapable(This)	\
    (This)->lpVtbl -> IsQuorumCapable(This)

#define IClusCfgManagedResourceInfo_GetDriveLetterMappings(This,pdlmDriveLetterMappingOut)	\
    (This)->lpVtbl -> GetDriveLetterMappings(This,pdlmDriveLetterMappingOut)

#define IClusCfgManagedResourceInfo_SetDriveLetterMappings(This,dlmDriveLetterMappingIn)	\
    (This)->lpVtbl -> SetDriveLetterMappings(This,dlmDriveLetterMappingIn)

#define IClusCfgManagedResourceInfo_IsDeviceJoinable(This)	\
    (This)->lpVtbl -> IsDeviceJoinable(This)

#define IClusCfgManagedResourceInfo_SetDeviceJoinable(This,joinable)	\
    (This)->lpVtbl -> SetDeviceJoinable(This,joinable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_GetUID_Proxy( 
    IClusCfgManagedResourceInfo * This,
    /* [out] */ BSTR *pbstrUIDOut);


void __RPC_STUB IClusCfgManagedResourceInfo_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_GetName_Proxy( 
    IClusCfgManagedResourceInfo * This,
    /* [out] */ BSTR *pbstrNameOut);


void __RPC_STUB IClusCfgManagedResourceInfo_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_SetName_Proxy( 
    IClusCfgManagedResourceInfo * This,
    /* [in] */ BSTR bstrNameIn);


void __RPC_STUB IClusCfgManagedResourceInfo_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_IsManaged_Proxy( 
    IClusCfgManagedResourceInfo * This);


void __RPC_STUB IClusCfgManagedResourceInfo_IsManaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_SetManaged_Proxy( 
    IClusCfgManagedResourceInfo * This,
    /* [in] */ BOOL fIsManagedIn);


void __RPC_STUB IClusCfgManagedResourceInfo_SetManaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_IsQuorumDevice_Proxy( 
    IClusCfgManagedResourceInfo * This);


void __RPC_STUB IClusCfgManagedResourceInfo_IsQuorumDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_SetQuorumedDevice_Proxy( 
    IClusCfgManagedResourceInfo * This,
    /* [in] */ BOOL fIsQuorumDeviceIn);


void __RPC_STUB IClusCfgManagedResourceInfo_SetQuorumedDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_IsQuorumCapable_Proxy( 
    IClusCfgManagedResourceInfo * This);


void __RPC_STUB IClusCfgManagedResourceInfo_IsQuorumCapable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_GetDriveLetterMappings_Proxy( 
    IClusCfgManagedResourceInfo * This,
    /* [out] */ SDriveLetterMapping *pdlmDriveLetterMappingOut);


void __RPC_STUB IClusCfgManagedResourceInfo_GetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_SetDriveLetterMappings_Proxy( 
    IClusCfgManagedResourceInfo * This,
    /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn);


void __RPC_STUB IClusCfgManagedResourceInfo_SetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_IsDeviceJoinable_Proxy( 
    IClusCfgManagedResourceInfo * This);


void __RPC_STUB IClusCfgManagedResourceInfo_IsDeviceJoinable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceInfo_SetDeviceJoinable_Proxy( 
    IClusCfgManagedResourceInfo * This,
    /* [in] */ BOOL joinable);


void __RPC_STUB IClusCfgManagedResourceInfo_SetDeviceJoinable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgManagedResourceInfo_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgManagedResourceInfo_INTERFACE_DEFINED__
#define __AsyncIClusCfgManagedResourceInfo_INTERFACE_DEFINED__

/* interface AsyncIClusCfgManagedResourceInfo */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgManagedResourceInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("73616028-1243-4749-AD84-0B5EB358FFA0")
    AsyncIClusCfgManagedResourceInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_GetUID( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetUID( 
            /* [out] */ BSTR *pbstrUIDOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetName( 
            /* [out] */ BSTR *pbstrNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetName( 
            /* [in] */ BSTR bstrNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_IsManaged( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_IsManaged( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetManaged( 
            /* [in] */ BOOL fIsManagedIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetManaged( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_IsQuorumDevice( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_IsQuorumDevice( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetQuorumedDevice( 
            /* [in] */ BOOL fIsQuorumDeviceIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetQuorumedDevice( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_IsQuorumCapable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_IsQuorumCapable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetDriveLetterMappings( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetDriveLetterMappings( 
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterMappingOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetDriveLetterMappings( 
            /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetDriveLetterMappings( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_IsDeviceJoinable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_IsDeviceJoinable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetDeviceJoinable( 
            /* [in] */ BOOL joinable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetDeviceJoinable( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgManagedResourceInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgManagedResourceInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetUID )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetUID )( 
            AsyncIClusCfgManagedResourceInfo * This,
            /* [out] */ BSTR *pbstrUIDOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetName )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetName )( 
            AsyncIClusCfgManagedResourceInfo * This,
            /* [out] */ BSTR *pbstrNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetName )( 
            AsyncIClusCfgManagedResourceInfo * This,
            /* [in] */ BSTR bstrNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetName )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_IsManaged )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_IsManaged )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetManaged )( 
            AsyncIClusCfgManagedResourceInfo * This,
            /* [in] */ BOOL fIsManagedIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetManaged )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_IsQuorumDevice )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_IsQuorumDevice )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetQuorumedDevice )( 
            AsyncIClusCfgManagedResourceInfo * This,
            /* [in] */ BOOL fIsQuorumDeviceIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetQuorumedDevice )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_IsQuorumCapable )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_IsQuorumCapable )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetDriveLetterMappings )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetDriveLetterMappings )( 
            AsyncIClusCfgManagedResourceInfo * This,
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterMappingOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetDriveLetterMappings )( 
            AsyncIClusCfgManagedResourceInfo * This,
            /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetDriveLetterMappings )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_IsDeviceJoinable )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_IsDeviceJoinable )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetDeviceJoinable )( 
            AsyncIClusCfgManagedResourceInfo * This,
            /* [in] */ BOOL joinable);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetDeviceJoinable )( 
            AsyncIClusCfgManagedResourceInfo * This);
        
        END_INTERFACE
    } AsyncIClusCfgManagedResourceInfoVtbl;

    interface AsyncIClusCfgManagedResourceInfo
    {
        CONST_VTBL struct AsyncIClusCfgManagedResourceInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgManagedResourceInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgManagedResourceInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgManagedResourceInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgManagedResourceInfo_Begin_GetUID(This)	\
    (This)->lpVtbl -> Begin_GetUID(This)

#define AsyncIClusCfgManagedResourceInfo_Finish_GetUID(This,pbstrUIDOut)	\
    (This)->lpVtbl -> Finish_GetUID(This,pbstrUIDOut)

#define AsyncIClusCfgManagedResourceInfo_Begin_GetName(This)	\
    (This)->lpVtbl -> Begin_GetName(This)

#define AsyncIClusCfgManagedResourceInfo_Finish_GetName(This,pbstrNameOut)	\
    (This)->lpVtbl -> Finish_GetName(This,pbstrNameOut)

#define AsyncIClusCfgManagedResourceInfo_Begin_SetName(This,bstrNameIn)	\
    (This)->lpVtbl -> Begin_SetName(This,bstrNameIn)

#define AsyncIClusCfgManagedResourceInfo_Finish_SetName(This)	\
    (This)->lpVtbl -> Finish_SetName(This)

#define AsyncIClusCfgManagedResourceInfo_Begin_IsManaged(This)	\
    (This)->lpVtbl -> Begin_IsManaged(This)

#define AsyncIClusCfgManagedResourceInfo_Finish_IsManaged(This)	\
    (This)->lpVtbl -> Finish_IsManaged(This)

#define AsyncIClusCfgManagedResourceInfo_Begin_SetManaged(This,fIsManagedIn)	\
    (This)->lpVtbl -> Begin_SetManaged(This,fIsManagedIn)

#define AsyncIClusCfgManagedResourceInfo_Finish_SetManaged(This)	\
    (This)->lpVtbl -> Finish_SetManaged(This)

#define AsyncIClusCfgManagedResourceInfo_Begin_IsQuorumDevice(This)	\
    (This)->lpVtbl -> Begin_IsQuorumDevice(This)

#define AsyncIClusCfgManagedResourceInfo_Finish_IsQuorumDevice(This)	\
    (This)->lpVtbl -> Finish_IsQuorumDevice(This)

#define AsyncIClusCfgManagedResourceInfo_Begin_SetQuorumedDevice(This,fIsQuorumDeviceIn)	\
    (This)->lpVtbl -> Begin_SetQuorumedDevice(This,fIsQuorumDeviceIn)

#define AsyncIClusCfgManagedResourceInfo_Finish_SetQuorumedDevice(This)	\
    (This)->lpVtbl -> Finish_SetQuorumedDevice(This)

#define AsyncIClusCfgManagedResourceInfo_Begin_IsQuorumCapable(This)	\
    (This)->lpVtbl -> Begin_IsQuorumCapable(This)

#define AsyncIClusCfgManagedResourceInfo_Finish_IsQuorumCapable(This)	\
    (This)->lpVtbl -> Finish_IsQuorumCapable(This)

#define AsyncIClusCfgManagedResourceInfo_Begin_GetDriveLetterMappings(This)	\
    (This)->lpVtbl -> Begin_GetDriveLetterMappings(This)

#define AsyncIClusCfgManagedResourceInfo_Finish_GetDriveLetterMappings(This,pdlmDriveLetterMappingOut)	\
    (This)->lpVtbl -> Finish_GetDriveLetterMappings(This,pdlmDriveLetterMappingOut)

#define AsyncIClusCfgManagedResourceInfo_Begin_SetDriveLetterMappings(This,dlmDriveLetterMappingIn)	\
    (This)->lpVtbl -> Begin_SetDriveLetterMappings(This,dlmDriveLetterMappingIn)

#define AsyncIClusCfgManagedResourceInfo_Finish_SetDriveLetterMappings(This)	\
    (This)->lpVtbl -> Finish_SetDriveLetterMappings(This)

#define AsyncIClusCfgManagedResourceInfo_Begin_IsDeviceJoinable(This)	\
    (This)->lpVtbl -> Begin_IsDeviceJoinable(This)

#define AsyncIClusCfgManagedResourceInfo_Finish_IsDeviceJoinable(This)	\
    (This)->lpVtbl -> Finish_IsDeviceJoinable(This)

#define AsyncIClusCfgManagedResourceInfo_Begin_SetDeviceJoinable(This,joinable)	\
    (This)->lpVtbl -> Begin_SetDeviceJoinable(This,joinable)

#define AsyncIClusCfgManagedResourceInfo_Finish_SetDeviceJoinable(This)	\
    (This)->lpVtbl -> Finish_SetDeviceJoinable(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_GetUID_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_GetUID_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This,
    /* [out] */ BSTR *pbstrUIDOut);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_GetName_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_GetName_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This,
    /* [out] */ BSTR *pbstrNameOut);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_SetName_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This,
    /* [in] */ BSTR bstrNameIn);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_SetName_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_IsManaged_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_IsManaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_IsManaged_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_IsManaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_SetManaged_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This,
    /* [in] */ BOOL fIsManagedIn);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_SetManaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_SetManaged_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_SetManaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_IsQuorumDevice_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_IsQuorumDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_IsQuorumDevice_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_IsQuorumDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_SetQuorumedDevice_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This,
    /* [in] */ BOOL fIsQuorumDeviceIn);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_SetQuorumedDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_SetQuorumedDevice_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_SetQuorumedDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_IsQuorumCapable_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_IsQuorumCapable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_IsQuorumCapable_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_IsQuorumCapable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_GetDriveLetterMappings_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_GetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_GetDriveLetterMappings_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This,
    /* [out] */ SDriveLetterMapping *pdlmDriveLetterMappingOut);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_GetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_SetDriveLetterMappings_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This,
    /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_SetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_SetDriveLetterMappings_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_SetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_IsDeviceJoinable_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_IsDeviceJoinable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_IsDeviceJoinable_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_IsDeviceJoinable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Begin_SetDeviceJoinable_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This,
    /* [in] */ BOOL joinable);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Begin_SetDeviceJoinable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgManagedResourceInfo_Finish_SetDeviceJoinable_Proxy( 
    AsyncIClusCfgManagedResourceInfo * This);


void __RPC_STUB AsyncIClusCfgManagedResourceInfo_Finish_SetDeviceJoinable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgManagedResourceInfo_INTERFACE_DEFINED__ */


#ifndef __IEnumClusCfgPartitions_INTERFACE_DEFINED__
#define __IEnumClusCfgPartitions_INTERFACE_DEFINED__

/* interface IEnumClusCfgPartitions */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IEnumClusCfgPartitions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4440BB6A-B0AC-479d-B534-7265A31D6C55")
    IEnumClusCfgPartitions : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cNumberRequestedIn,
            /* [length_is][size_is][out] */ IClusCfgPartitionInfo **rgpPartitionInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cNumberToSkip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumClusCfgPartitions **ppEnumPartitions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumClusCfgPartitionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumClusCfgPartitions * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumClusCfgPartitions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumClusCfgPartitions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumClusCfgPartitions * This,
            /* [in] */ ULONG cNumberRequestedIn,
            /* [length_is][size_is][out] */ IClusCfgPartitionInfo **rgpPartitionInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumClusCfgPartitions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumClusCfgPartitions * This,
            /* [in] */ ULONG cNumberToSkip);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumClusCfgPartitions * This,
            /* [out] */ IEnumClusCfgPartitions **ppEnumPartitions);
        
        END_INTERFACE
    } IEnumClusCfgPartitionsVtbl;

    interface IEnumClusCfgPartitions
    {
        CONST_VTBL struct IEnumClusCfgPartitionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumClusCfgPartitions_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumClusCfgPartitions_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumClusCfgPartitions_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumClusCfgPartitions_Next(This,cNumberRequestedIn,rgpPartitionInfoOut,pcNumberFetchedOut)	\
    (This)->lpVtbl -> Next(This,cNumberRequestedIn,rgpPartitionInfoOut,pcNumberFetchedOut)

#define IEnumClusCfgPartitions_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumClusCfgPartitions_Skip(This,cNumberToSkip)	\
    (This)->lpVtbl -> Skip(This,cNumberToSkip)

#define IEnumClusCfgPartitions_Clone(This,ppEnumPartitions)	\
    (This)->lpVtbl -> Clone(This,ppEnumPartitions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumClusCfgPartitions_Next_Proxy( 
    IEnumClusCfgPartitions * This,
    /* [in] */ ULONG cNumberRequestedIn,
    /* [length_is][size_is][out] */ IClusCfgPartitionInfo **rgpPartitionInfoOut,
    /* [out] */ ULONG *pcNumberFetchedOut);


void __RPC_STUB IEnumClusCfgPartitions_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgPartitions_Reset_Proxy( 
    IEnumClusCfgPartitions * This);


void __RPC_STUB IEnumClusCfgPartitions_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgPartitions_Skip_Proxy( 
    IEnumClusCfgPartitions * This,
    /* [in] */ ULONG cNumberToSkip);


void __RPC_STUB IEnumClusCfgPartitions_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgPartitions_Clone_Proxy( 
    IEnumClusCfgPartitions * This,
    /* [out] */ IEnumClusCfgPartitions **ppEnumPartitions);


void __RPC_STUB IEnumClusCfgPartitions_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumClusCfgPartitions_INTERFACE_DEFINED__ */


#ifndef __AsyncIEnumClusCfgPartitions_INTERFACE_DEFINED__
#define __AsyncIEnumClusCfgPartitions_INTERFACE_DEFINED__

/* interface AsyncIEnumClusCfgPartitions */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIEnumClusCfgPartitions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4440BB6A-B0AC-479d-B534-7265A31D6C56")
    AsyncIEnumClusCfgPartitions : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Next( 
            /* [in] */ ULONG cNumberRequestedIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Next( 
            /* [length_is][size_is][out] */ IClusCfgPartitionInfo **rgpPartitionInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Skip( 
            /* [in] */ ULONG cNumberToSkip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Skip( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Clone( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Clone( 
            /* [out] */ IEnumClusCfgPartitions **ppEnumPartitions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIEnumClusCfgPartitionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIEnumClusCfgPartitions * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIEnumClusCfgPartitions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIEnumClusCfgPartitions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Next )( 
            AsyncIEnumClusCfgPartitions * This,
            /* [in] */ ULONG cNumberRequestedIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Next )( 
            AsyncIEnumClusCfgPartitions * This,
            /* [length_is][size_is][out] */ IClusCfgPartitionInfo **rgpPartitionInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Reset )( 
            AsyncIEnumClusCfgPartitions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Reset )( 
            AsyncIEnumClusCfgPartitions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Skip )( 
            AsyncIEnumClusCfgPartitions * This,
            /* [in] */ ULONG cNumberToSkip);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Skip )( 
            AsyncIEnumClusCfgPartitions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Clone )( 
            AsyncIEnumClusCfgPartitions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Clone )( 
            AsyncIEnumClusCfgPartitions * This,
            /* [out] */ IEnumClusCfgPartitions **ppEnumPartitions);
        
        END_INTERFACE
    } AsyncIEnumClusCfgPartitionsVtbl;

    interface AsyncIEnumClusCfgPartitions
    {
        CONST_VTBL struct AsyncIEnumClusCfgPartitionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIEnumClusCfgPartitions_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIEnumClusCfgPartitions_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIEnumClusCfgPartitions_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIEnumClusCfgPartitions_Begin_Next(This,cNumberRequestedIn)	\
    (This)->lpVtbl -> Begin_Next(This,cNumberRequestedIn)

#define AsyncIEnumClusCfgPartitions_Finish_Next(This,rgpPartitionInfoOut,pcNumberFetchedOut)	\
    (This)->lpVtbl -> Finish_Next(This,rgpPartitionInfoOut,pcNumberFetchedOut)

#define AsyncIEnumClusCfgPartitions_Begin_Reset(This)	\
    (This)->lpVtbl -> Begin_Reset(This)

#define AsyncIEnumClusCfgPartitions_Finish_Reset(This)	\
    (This)->lpVtbl -> Finish_Reset(This)

#define AsyncIEnumClusCfgPartitions_Begin_Skip(This,cNumberToSkip)	\
    (This)->lpVtbl -> Begin_Skip(This,cNumberToSkip)

#define AsyncIEnumClusCfgPartitions_Finish_Skip(This)	\
    (This)->lpVtbl -> Finish_Skip(This)

#define AsyncIEnumClusCfgPartitions_Begin_Clone(This)	\
    (This)->lpVtbl -> Begin_Clone(This)

#define AsyncIEnumClusCfgPartitions_Finish_Clone(This,ppEnumPartitions)	\
    (This)->lpVtbl -> Finish_Clone(This,ppEnumPartitions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgPartitions_Begin_Next_Proxy( 
    AsyncIEnumClusCfgPartitions * This,
    /* [in] */ ULONG cNumberRequestedIn);


void __RPC_STUB AsyncIEnumClusCfgPartitions_Begin_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgPartitions_Finish_Next_Proxy( 
    AsyncIEnumClusCfgPartitions * This,
    /* [length_is][size_is][out] */ IClusCfgPartitionInfo **rgpPartitionInfoOut,
    /* [out] */ ULONG *pcNumberFetchedOut);


void __RPC_STUB AsyncIEnumClusCfgPartitions_Finish_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgPartitions_Begin_Reset_Proxy( 
    AsyncIEnumClusCfgPartitions * This);


void __RPC_STUB AsyncIEnumClusCfgPartitions_Begin_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgPartitions_Finish_Reset_Proxy( 
    AsyncIEnumClusCfgPartitions * This);


void __RPC_STUB AsyncIEnumClusCfgPartitions_Finish_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgPartitions_Begin_Skip_Proxy( 
    AsyncIEnumClusCfgPartitions * This,
    /* [in] */ ULONG cNumberToSkip);


void __RPC_STUB AsyncIEnumClusCfgPartitions_Begin_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgPartitions_Finish_Skip_Proxy( 
    AsyncIEnumClusCfgPartitions * This);


void __RPC_STUB AsyncIEnumClusCfgPartitions_Finish_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgPartitions_Begin_Clone_Proxy( 
    AsyncIEnumClusCfgPartitions * This);


void __RPC_STUB AsyncIEnumClusCfgPartitions_Begin_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgPartitions_Finish_Clone_Proxy( 
    AsyncIEnumClusCfgPartitions * This,
    /* [out] */ IEnumClusCfgPartitions **ppEnumPartitions);


void __RPC_STUB AsyncIEnumClusCfgPartitions_Finish_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIEnumClusCfgPartitions_INTERFACE_DEFINED__ */


#ifndef __IClusCfgPartitionInfo_INTERFACE_DEFINED__
#define __IClusCfgPartitionInfo_INTERFACE_DEFINED__

/* interface IClusCfgPartitionInfo */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgPartitionInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC1EBD9F-5866-4846-8952-EC36C3961EEE")
    IClusCfgPartitionInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetUID( 
            /* [out] */ BSTR *pbstrUIDOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR *pbstrNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR bstrNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ BSTR *pbstrDescriptionOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [in] */ BSTR bstrDescriptionIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDriveLetterMappings( 
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDriveLetterMappings( 
            /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ ULONG *pcMegaBytes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgPartitionInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgPartitionInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgPartitionInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgPartitionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetUID )( 
            IClusCfgPartitionInfo * This,
            /* [out] */ BSTR *pbstrUIDOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IClusCfgPartitionInfo * This,
            /* [out] */ BSTR *pbstrNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IClusCfgPartitionInfo * This,
            /* [in] */ BSTR bstrNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IClusCfgPartitionInfo * This,
            /* [out] */ BSTR *pbstrDescriptionOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IClusCfgPartitionInfo * This,
            /* [in] */ BSTR bstrDescriptionIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetDriveLetterMappings )( 
            IClusCfgPartitionInfo * This,
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetDriveLetterMappings )( 
            IClusCfgPartitionInfo * This,
            /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            IClusCfgPartitionInfo * This,
            /* [out] */ ULONG *pcMegaBytes);
        
        END_INTERFACE
    } IClusCfgPartitionInfoVtbl;

    interface IClusCfgPartitionInfo
    {
        CONST_VTBL struct IClusCfgPartitionInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgPartitionInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgPartitionInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgPartitionInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgPartitionInfo_GetUID(This,pbstrUIDOut)	\
    (This)->lpVtbl -> GetUID(This,pbstrUIDOut)

#define IClusCfgPartitionInfo_GetName(This,pbstrNameOut)	\
    (This)->lpVtbl -> GetName(This,pbstrNameOut)

#define IClusCfgPartitionInfo_SetName(This,bstrNameIn)	\
    (This)->lpVtbl -> SetName(This,bstrNameIn)

#define IClusCfgPartitionInfo_GetDescription(This,pbstrDescriptionOut)	\
    (This)->lpVtbl -> GetDescription(This,pbstrDescriptionOut)

#define IClusCfgPartitionInfo_SetDescription(This,bstrDescriptionIn)	\
    (This)->lpVtbl -> SetDescription(This,bstrDescriptionIn)

#define IClusCfgPartitionInfo_GetDriveLetterMappings(This,pdlmDriveLetterUsageOut)	\
    (This)->lpVtbl -> GetDriveLetterMappings(This,pdlmDriveLetterUsageOut)

#define IClusCfgPartitionInfo_SetDriveLetterMappings(This,dlmDriveLetterMappingIn)	\
    (This)->lpVtbl -> SetDriveLetterMappings(This,dlmDriveLetterMappingIn)

#define IClusCfgPartitionInfo_GetSize(This,pcMegaBytes)	\
    (This)->lpVtbl -> GetSize(This,pcMegaBytes)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgPartitionInfo_GetUID_Proxy( 
    IClusCfgPartitionInfo * This,
    /* [out] */ BSTR *pbstrUIDOut);


void __RPC_STUB IClusCfgPartitionInfo_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgPartitionInfo_GetName_Proxy( 
    IClusCfgPartitionInfo * This,
    /* [out] */ BSTR *pbstrNameOut);


void __RPC_STUB IClusCfgPartitionInfo_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgPartitionInfo_SetName_Proxy( 
    IClusCfgPartitionInfo * This,
    /* [in] */ BSTR bstrNameIn);


void __RPC_STUB IClusCfgPartitionInfo_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgPartitionInfo_GetDescription_Proxy( 
    IClusCfgPartitionInfo * This,
    /* [out] */ BSTR *pbstrDescriptionOut);


void __RPC_STUB IClusCfgPartitionInfo_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgPartitionInfo_SetDescription_Proxy( 
    IClusCfgPartitionInfo * This,
    /* [in] */ BSTR bstrDescriptionIn);


void __RPC_STUB IClusCfgPartitionInfo_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgPartitionInfo_GetDriveLetterMappings_Proxy( 
    IClusCfgPartitionInfo * This,
    /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut);


void __RPC_STUB IClusCfgPartitionInfo_GetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgPartitionInfo_SetDriveLetterMappings_Proxy( 
    IClusCfgPartitionInfo * This,
    /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn);


void __RPC_STUB IClusCfgPartitionInfo_SetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgPartitionInfo_GetSize_Proxy( 
    IClusCfgPartitionInfo * This,
    /* [out] */ ULONG *pcMegaBytes);


void __RPC_STUB IClusCfgPartitionInfo_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgPartitionInfo_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgPartitionInfo_INTERFACE_DEFINED__
#define __AsyncIClusCfgPartitionInfo_INTERFACE_DEFINED__

/* interface AsyncIClusCfgPartitionInfo */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgPartitionInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC1EBD9F-5866-4846-8952-EC36C3961EEF")
    AsyncIClusCfgPartitionInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_GetUID( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetUID( 
            /* [out] */ BSTR *pbstrUIDOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetName( 
            /* [out] */ BSTR *pbstrNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetName( 
            /* [in] */ BSTR bstrNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetDescription( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetDescription( 
            /* [out] */ BSTR *pbstrDescriptionOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetDescription( 
            /* [in] */ BSTR bstrDescriptionIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetDescription( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetDriveLetterMappings( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetDriveLetterMappings( 
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetDriveLetterMappings( 
            /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetDriveLetterMappings( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetSize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetSize( 
            /* [out] */ ULONG *pcMegaBytes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgPartitionInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgPartitionInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgPartitionInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgPartitionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetUID )( 
            AsyncIClusCfgPartitionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetUID )( 
            AsyncIClusCfgPartitionInfo * This,
            /* [out] */ BSTR *pbstrUIDOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetName )( 
            AsyncIClusCfgPartitionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetName )( 
            AsyncIClusCfgPartitionInfo * This,
            /* [out] */ BSTR *pbstrNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetName )( 
            AsyncIClusCfgPartitionInfo * This,
            /* [in] */ BSTR bstrNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetName )( 
            AsyncIClusCfgPartitionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetDescription )( 
            AsyncIClusCfgPartitionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetDescription )( 
            AsyncIClusCfgPartitionInfo * This,
            /* [out] */ BSTR *pbstrDescriptionOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetDescription )( 
            AsyncIClusCfgPartitionInfo * This,
            /* [in] */ BSTR bstrDescriptionIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetDescription )( 
            AsyncIClusCfgPartitionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetDriveLetterMappings )( 
            AsyncIClusCfgPartitionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetDriveLetterMappings )( 
            AsyncIClusCfgPartitionInfo * This,
            /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetDriveLetterMappings )( 
            AsyncIClusCfgPartitionInfo * This,
            /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetDriveLetterMappings )( 
            AsyncIClusCfgPartitionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetSize )( 
            AsyncIClusCfgPartitionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetSize )( 
            AsyncIClusCfgPartitionInfo * This,
            /* [out] */ ULONG *pcMegaBytes);
        
        END_INTERFACE
    } AsyncIClusCfgPartitionInfoVtbl;

    interface AsyncIClusCfgPartitionInfo
    {
        CONST_VTBL struct AsyncIClusCfgPartitionInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgPartitionInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgPartitionInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgPartitionInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgPartitionInfo_Begin_GetUID(This)	\
    (This)->lpVtbl -> Begin_GetUID(This)

#define AsyncIClusCfgPartitionInfo_Finish_GetUID(This,pbstrUIDOut)	\
    (This)->lpVtbl -> Finish_GetUID(This,pbstrUIDOut)

#define AsyncIClusCfgPartitionInfo_Begin_GetName(This)	\
    (This)->lpVtbl -> Begin_GetName(This)

#define AsyncIClusCfgPartitionInfo_Finish_GetName(This,pbstrNameOut)	\
    (This)->lpVtbl -> Finish_GetName(This,pbstrNameOut)

#define AsyncIClusCfgPartitionInfo_Begin_SetName(This,bstrNameIn)	\
    (This)->lpVtbl -> Begin_SetName(This,bstrNameIn)

#define AsyncIClusCfgPartitionInfo_Finish_SetName(This)	\
    (This)->lpVtbl -> Finish_SetName(This)

#define AsyncIClusCfgPartitionInfo_Begin_GetDescription(This)	\
    (This)->lpVtbl -> Begin_GetDescription(This)

#define AsyncIClusCfgPartitionInfo_Finish_GetDescription(This,pbstrDescriptionOut)	\
    (This)->lpVtbl -> Finish_GetDescription(This,pbstrDescriptionOut)

#define AsyncIClusCfgPartitionInfo_Begin_SetDescription(This,bstrDescriptionIn)	\
    (This)->lpVtbl -> Begin_SetDescription(This,bstrDescriptionIn)

#define AsyncIClusCfgPartitionInfo_Finish_SetDescription(This)	\
    (This)->lpVtbl -> Finish_SetDescription(This)

#define AsyncIClusCfgPartitionInfo_Begin_GetDriveLetterMappings(This)	\
    (This)->lpVtbl -> Begin_GetDriveLetterMappings(This)

#define AsyncIClusCfgPartitionInfo_Finish_GetDriveLetterMappings(This,pdlmDriveLetterUsageOut)	\
    (This)->lpVtbl -> Finish_GetDriveLetterMappings(This,pdlmDriveLetterUsageOut)

#define AsyncIClusCfgPartitionInfo_Begin_SetDriveLetterMappings(This,dlmDriveLetterMappingIn)	\
    (This)->lpVtbl -> Begin_SetDriveLetterMappings(This,dlmDriveLetterMappingIn)

#define AsyncIClusCfgPartitionInfo_Finish_SetDriveLetterMappings(This)	\
    (This)->lpVtbl -> Finish_SetDriveLetterMappings(This)

#define AsyncIClusCfgPartitionInfo_Begin_GetSize(This)	\
    (This)->lpVtbl -> Begin_GetSize(This)

#define AsyncIClusCfgPartitionInfo_Finish_GetSize(This,pcMegaBytes)	\
    (This)->lpVtbl -> Finish_GetSize(This,pcMegaBytes)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Begin_GetUID_Proxy( 
    AsyncIClusCfgPartitionInfo * This);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Begin_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Finish_GetUID_Proxy( 
    AsyncIClusCfgPartitionInfo * This,
    /* [out] */ BSTR *pbstrUIDOut);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Finish_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Begin_GetName_Proxy( 
    AsyncIClusCfgPartitionInfo * This);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Begin_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Finish_GetName_Proxy( 
    AsyncIClusCfgPartitionInfo * This,
    /* [out] */ BSTR *pbstrNameOut);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Finish_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Begin_SetName_Proxy( 
    AsyncIClusCfgPartitionInfo * This,
    /* [in] */ BSTR bstrNameIn);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Begin_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Finish_SetName_Proxy( 
    AsyncIClusCfgPartitionInfo * This);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Finish_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Begin_GetDescription_Proxy( 
    AsyncIClusCfgPartitionInfo * This);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Begin_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Finish_GetDescription_Proxy( 
    AsyncIClusCfgPartitionInfo * This,
    /* [out] */ BSTR *pbstrDescriptionOut);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Finish_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Begin_SetDescription_Proxy( 
    AsyncIClusCfgPartitionInfo * This,
    /* [in] */ BSTR bstrDescriptionIn);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Begin_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Finish_SetDescription_Proxy( 
    AsyncIClusCfgPartitionInfo * This);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Finish_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Begin_GetDriveLetterMappings_Proxy( 
    AsyncIClusCfgPartitionInfo * This);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Begin_GetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Finish_GetDriveLetterMappings_Proxy( 
    AsyncIClusCfgPartitionInfo * This,
    /* [out] */ SDriveLetterMapping *pdlmDriveLetterUsageOut);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Finish_GetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Begin_SetDriveLetterMappings_Proxy( 
    AsyncIClusCfgPartitionInfo * This,
    /* [in] */ SDriveLetterMapping dlmDriveLetterMappingIn);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Begin_SetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Finish_SetDriveLetterMappings_Proxy( 
    AsyncIClusCfgPartitionInfo * This);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Finish_SetDriveLetterMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Begin_GetSize_Proxy( 
    AsyncIClusCfgPartitionInfo * This);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Begin_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgPartitionInfo_Finish_GetSize_Proxy( 
    AsyncIClusCfgPartitionInfo * This,
    /* [out] */ ULONG *pcMegaBytes);


void __RPC_STUB AsyncIClusCfgPartitionInfo_Finish_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgPartitionInfo_INTERFACE_DEFINED__ */


#ifndef __IEnumClusCfgIPAddresses_INTERFACE_DEFINED__
#define __IEnumClusCfgIPAddresses_INTERFACE_DEFINED__

/* interface IEnumClusCfgIPAddresses */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IEnumClusCfgIPAddresses;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD5F35BA-0BC0-455f-926D-C3D356419486")
    IEnumClusCfgIPAddresses : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cNumberRequestedIn,
            /* [length_is][size_is][out] */ IClusCfgIPAddressInfo **rgpIPAddressInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cNumberToSkipIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumClusCfgIPAddresses **ppEnumIPAddressesOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumClusCfgIPAddressesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumClusCfgIPAddresses * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumClusCfgIPAddresses * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumClusCfgIPAddresses * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumClusCfgIPAddresses * This,
            /* [in] */ ULONG cNumberRequestedIn,
            /* [length_is][size_is][out] */ IClusCfgIPAddressInfo **rgpIPAddressInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumClusCfgIPAddresses * This,
            /* [in] */ ULONG cNumberToSkipIn);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumClusCfgIPAddresses * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumClusCfgIPAddresses * This,
            /* [out] */ IEnumClusCfgIPAddresses **ppEnumIPAddressesOut);
        
        END_INTERFACE
    } IEnumClusCfgIPAddressesVtbl;

    interface IEnumClusCfgIPAddresses
    {
        CONST_VTBL struct IEnumClusCfgIPAddressesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumClusCfgIPAddresses_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumClusCfgIPAddresses_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumClusCfgIPAddresses_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumClusCfgIPAddresses_Next(This,cNumberRequestedIn,rgpIPAddressInfoOut,pcNumberFetchedOut)	\
    (This)->lpVtbl -> Next(This,cNumberRequestedIn,rgpIPAddressInfoOut,pcNumberFetchedOut)

#define IEnumClusCfgIPAddresses_Skip(This,cNumberToSkipIn)	\
    (This)->lpVtbl -> Skip(This,cNumberToSkipIn)

#define IEnumClusCfgIPAddresses_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumClusCfgIPAddresses_Clone(This,ppEnumIPAddressesOut)	\
    (This)->lpVtbl -> Clone(This,ppEnumIPAddressesOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumClusCfgIPAddresses_Next_Proxy( 
    IEnumClusCfgIPAddresses * This,
    /* [in] */ ULONG cNumberRequestedIn,
    /* [length_is][size_is][out] */ IClusCfgIPAddressInfo **rgpIPAddressInfoOut,
    /* [out] */ ULONG *pcNumberFetchedOut);


void __RPC_STUB IEnumClusCfgIPAddresses_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgIPAddresses_Skip_Proxy( 
    IEnumClusCfgIPAddresses * This,
    /* [in] */ ULONG cNumberToSkipIn);


void __RPC_STUB IEnumClusCfgIPAddresses_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgIPAddresses_Reset_Proxy( 
    IEnumClusCfgIPAddresses * This);


void __RPC_STUB IEnumClusCfgIPAddresses_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumClusCfgIPAddresses_Clone_Proxy( 
    IEnumClusCfgIPAddresses * This,
    /* [out] */ IEnumClusCfgIPAddresses **ppEnumIPAddressesOut);


void __RPC_STUB IEnumClusCfgIPAddresses_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumClusCfgIPAddresses_INTERFACE_DEFINED__ */


#ifndef __AsyncIEnumClusCfgIPAddresses_INTERFACE_DEFINED__
#define __AsyncIEnumClusCfgIPAddresses_INTERFACE_DEFINED__

/* interface AsyncIEnumClusCfgIPAddresses */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIEnumClusCfgIPAddresses;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD5F35BA-0BC0-455f-926D-C3D356419487")
    AsyncIEnumClusCfgIPAddresses : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Next( 
            /* [in] */ ULONG cNumberRequestedIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Next( 
            /* [length_is][size_is][out] */ IClusCfgIPAddressInfo **rgpIPAddressInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Skip( 
            /* [in] */ ULONG cNumberToSkipIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Skip( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Clone( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Clone( 
            /* [out] */ IEnumClusCfgIPAddresses **ppEnumIPAddressesOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIEnumClusCfgIPAddressesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIEnumClusCfgIPAddresses * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIEnumClusCfgIPAddresses * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIEnumClusCfgIPAddresses * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Next )( 
            AsyncIEnumClusCfgIPAddresses * This,
            /* [in] */ ULONG cNumberRequestedIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Next )( 
            AsyncIEnumClusCfgIPAddresses * This,
            /* [length_is][size_is][out] */ IClusCfgIPAddressInfo **rgpIPAddressInfoOut,
            /* [out] */ ULONG *pcNumberFetchedOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Skip )( 
            AsyncIEnumClusCfgIPAddresses * This,
            /* [in] */ ULONG cNumberToSkipIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Skip )( 
            AsyncIEnumClusCfgIPAddresses * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Reset )( 
            AsyncIEnumClusCfgIPAddresses * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Reset )( 
            AsyncIEnumClusCfgIPAddresses * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Clone )( 
            AsyncIEnumClusCfgIPAddresses * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Clone )( 
            AsyncIEnumClusCfgIPAddresses * This,
            /* [out] */ IEnumClusCfgIPAddresses **ppEnumIPAddressesOut);
        
        END_INTERFACE
    } AsyncIEnumClusCfgIPAddressesVtbl;

    interface AsyncIEnumClusCfgIPAddresses
    {
        CONST_VTBL struct AsyncIEnumClusCfgIPAddressesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIEnumClusCfgIPAddresses_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIEnumClusCfgIPAddresses_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIEnumClusCfgIPAddresses_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIEnumClusCfgIPAddresses_Begin_Next(This,cNumberRequestedIn)	\
    (This)->lpVtbl -> Begin_Next(This,cNumberRequestedIn)

#define AsyncIEnumClusCfgIPAddresses_Finish_Next(This,rgpIPAddressInfoOut,pcNumberFetchedOut)	\
    (This)->lpVtbl -> Finish_Next(This,rgpIPAddressInfoOut,pcNumberFetchedOut)

#define AsyncIEnumClusCfgIPAddresses_Begin_Skip(This,cNumberToSkipIn)	\
    (This)->lpVtbl -> Begin_Skip(This,cNumberToSkipIn)

#define AsyncIEnumClusCfgIPAddresses_Finish_Skip(This)	\
    (This)->lpVtbl -> Finish_Skip(This)

#define AsyncIEnumClusCfgIPAddresses_Begin_Reset(This)	\
    (This)->lpVtbl -> Begin_Reset(This)

#define AsyncIEnumClusCfgIPAddresses_Finish_Reset(This)	\
    (This)->lpVtbl -> Finish_Reset(This)

#define AsyncIEnumClusCfgIPAddresses_Begin_Clone(This)	\
    (This)->lpVtbl -> Begin_Clone(This)

#define AsyncIEnumClusCfgIPAddresses_Finish_Clone(This,ppEnumIPAddressesOut)	\
    (This)->lpVtbl -> Finish_Clone(This,ppEnumIPAddressesOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgIPAddresses_Begin_Next_Proxy( 
    AsyncIEnumClusCfgIPAddresses * This,
    /* [in] */ ULONG cNumberRequestedIn);


void __RPC_STUB AsyncIEnumClusCfgIPAddresses_Begin_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgIPAddresses_Finish_Next_Proxy( 
    AsyncIEnumClusCfgIPAddresses * This,
    /* [length_is][size_is][out] */ IClusCfgIPAddressInfo **rgpIPAddressInfoOut,
    /* [out] */ ULONG *pcNumberFetchedOut);


void __RPC_STUB AsyncIEnumClusCfgIPAddresses_Finish_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgIPAddresses_Begin_Skip_Proxy( 
    AsyncIEnumClusCfgIPAddresses * This,
    /* [in] */ ULONG cNumberToSkipIn);


void __RPC_STUB AsyncIEnumClusCfgIPAddresses_Begin_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgIPAddresses_Finish_Skip_Proxy( 
    AsyncIEnumClusCfgIPAddresses * This);


void __RPC_STUB AsyncIEnumClusCfgIPAddresses_Finish_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgIPAddresses_Begin_Reset_Proxy( 
    AsyncIEnumClusCfgIPAddresses * This);


void __RPC_STUB AsyncIEnumClusCfgIPAddresses_Begin_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgIPAddresses_Finish_Reset_Proxy( 
    AsyncIEnumClusCfgIPAddresses * This);


void __RPC_STUB AsyncIEnumClusCfgIPAddresses_Finish_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgIPAddresses_Begin_Clone_Proxy( 
    AsyncIEnumClusCfgIPAddresses * This);


void __RPC_STUB AsyncIEnumClusCfgIPAddresses_Begin_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIEnumClusCfgIPAddresses_Finish_Clone_Proxy( 
    AsyncIEnumClusCfgIPAddresses * This,
    /* [out] */ IEnumClusCfgIPAddresses **ppEnumIPAddressesOut);


void __RPC_STUB AsyncIEnumClusCfgIPAddresses_Finish_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIEnumClusCfgIPAddresses_INTERFACE_DEFINED__ */


#ifndef __IClusCfgIPAddressInfo_INTERFACE_DEFINED__
#define __IClusCfgIPAddressInfo_INTERFACE_DEFINED__

/* interface IClusCfgIPAddressInfo */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgIPAddressInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AAEAF0A5-E310-4604-A55E-2F9DDC4157A8")
    IClusCfgIPAddressInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetUID( 
            /* [out] */ BSTR *pbstrUIDOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIPAddress( 
            /* [out] */ ULONG *pulDottedQuadOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIPAddress( 
            /* [in] */ ULONG ulDottedQuadIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubnetMask( 
            /* [out] */ ULONG *pulDottedQuadOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSubnetMask( 
            /* [in] */ ULONG ulDottedQuadIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgIPAddressInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgIPAddressInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgIPAddressInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgIPAddressInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetUID )( 
            IClusCfgIPAddressInfo * This,
            /* [out] */ BSTR *pbstrUIDOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetIPAddress )( 
            IClusCfgIPAddressInfo * This,
            /* [out] */ ULONG *pulDottedQuadOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetIPAddress )( 
            IClusCfgIPAddressInfo * This,
            /* [in] */ ULONG ulDottedQuadIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubnetMask )( 
            IClusCfgIPAddressInfo * This,
            /* [out] */ ULONG *pulDottedQuadOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetSubnetMask )( 
            IClusCfgIPAddressInfo * This,
            /* [in] */ ULONG ulDottedQuadIn);
        
        END_INTERFACE
    } IClusCfgIPAddressInfoVtbl;

    interface IClusCfgIPAddressInfo
    {
        CONST_VTBL struct IClusCfgIPAddressInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgIPAddressInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgIPAddressInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgIPAddressInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgIPAddressInfo_GetUID(This,pbstrUIDOut)	\
    (This)->lpVtbl -> GetUID(This,pbstrUIDOut)

#define IClusCfgIPAddressInfo_GetIPAddress(This,pulDottedQuadOut)	\
    (This)->lpVtbl -> GetIPAddress(This,pulDottedQuadOut)

#define IClusCfgIPAddressInfo_SetIPAddress(This,ulDottedQuadIn)	\
    (This)->lpVtbl -> SetIPAddress(This,ulDottedQuadIn)

#define IClusCfgIPAddressInfo_GetSubnetMask(This,pulDottedQuadOut)	\
    (This)->lpVtbl -> GetSubnetMask(This,pulDottedQuadOut)

#define IClusCfgIPAddressInfo_SetSubnetMask(This,ulDottedQuadIn)	\
    (This)->lpVtbl -> SetSubnetMask(This,ulDottedQuadIn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgIPAddressInfo_GetUID_Proxy( 
    IClusCfgIPAddressInfo * This,
    /* [out] */ BSTR *pbstrUIDOut);


void __RPC_STUB IClusCfgIPAddressInfo_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgIPAddressInfo_GetIPAddress_Proxy( 
    IClusCfgIPAddressInfo * This,
    /* [out] */ ULONG *pulDottedQuadOut);


void __RPC_STUB IClusCfgIPAddressInfo_GetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgIPAddressInfo_SetIPAddress_Proxy( 
    IClusCfgIPAddressInfo * This,
    /* [in] */ ULONG ulDottedQuadIn);


void __RPC_STUB IClusCfgIPAddressInfo_SetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgIPAddressInfo_GetSubnetMask_Proxy( 
    IClusCfgIPAddressInfo * This,
    /* [out] */ ULONG *pulDottedQuadOut);


void __RPC_STUB IClusCfgIPAddressInfo_GetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgIPAddressInfo_SetSubnetMask_Proxy( 
    IClusCfgIPAddressInfo * This,
    /* [in] */ ULONG ulDottedQuadIn);


void __RPC_STUB IClusCfgIPAddressInfo_SetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgIPAddressInfo_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgIPAddressInfo_INTERFACE_DEFINED__
#define __AsyncIClusCfgIPAddressInfo_INTERFACE_DEFINED__

/* interface AsyncIClusCfgIPAddressInfo */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgIPAddressInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AAEAF0A5-E310-4604-A55E-2F9DDC4157A9")
    AsyncIClusCfgIPAddressInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_GetUID( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetUID( 
            /* [out] */ BSTR *pbstrUIDOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetIPAddress( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetIPAddress( 
            /* [out] */ ULONG *pulDottedQuadOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetIPAddress( 
            /* [in] */ ULONG ulDottedQuadIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetIPAddress( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetSubnetMask( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetSubnetMask( 
            /* [out] */ ULONG *pulDottedQuadOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetSubnetMask( 
            /* [in] */ ULONG ulDottedQuadIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetSubnetMask( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgIPAddressInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgIPAddressInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgIPAddressInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgIPAddressInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetUID )( 
            AsyncIClusCfgIPAddressInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetUID )( 
            AsyncIClusCfgIPAddressInfo * This,
            /* [out] */ BSTR *pbstrUIDOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetIPAddress )( 
            AsyncIClusCfgIPAddressInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetIPAddress )( 
            AsyncIClusCfgIPAddressInfo * This,
            /* [out] */ ULONG *pulDottedQuadOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetIPAddress )( 
            AsyncIClusCfgIPAddressInfo * This,
            /* [in] */ ULONG ulDottedQuadIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetIPAddress )( 
            AsyncIClusCfgIPAddressInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetSubnetMask )( 
            AsyncIClusCfgIPAddressInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetSubnetMask )( 
            AsyncIClusCfgIPAddressInfo * This,
            /* [out] */ ULONG *pulDottedQuadOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetSubnetMask )( 
            AsyncIClusCfgIPAddressInfo * This,
            /* [in] */ ULONG ulDottedQuadIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetSubnetMask )( 
            AsyncIClusCfgIPAddressInfo * This);
        
        END_INTERFACE
    } AsyncIClusCfgIPAddressInfoVtbl;

    interface AsyncIClusCfgIPAddressInfo
    {
        CONST_VTBL struct AsyncIClusCfgIPAddressInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgIPAddressInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgIPAddressInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgIPAddressInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgIPAddressInfo_Begin_GetUID(This)	\
    (This)->lpVtbl -> Begin_GetUID(This)

#define AsyncIClusCfgIPAddressInfo_Finish_GetUID(This,pbstrUIDOut)	\
    (This)->lpVtbl -> Finish_GetUID(This,pbstrUIDOut)

#define AsyncIClusCfgIPAddressInfo_Begin_GetIPAddress(This)	\
    (This)->lpVtbl -> Begin_GetIPAddress(This)

#define AsyncIClusCfgIPAddressInfo_Finish_GetIPAddress(This,pulDottedQuadOut)	\
    (This)->lpVtbl -> Finish_GetIPAddress(This,pulDottedQuadOut)

#define AsyncIClusCfgIPAddressInfo_Begin_SetIPAddress(This,ulDottedQuadIn)	\
    (This)->lpVtbl -> Begin_SetIPAddress(This,ulDottedQuadIn)

#define AsyncIClusCfgIPAddressInfo_Finish_SetIPAddress(This)	\
    (This)->lpVtbl -> Finish_SetIPAddress(This)

#define AsyncIClusCfgIPAddressInfo_Begin_GetSubnetMask(This)	\
    (This)->lpVtbl -> Begin_GetSubnetMask(This)

#define AsyncIClusCfgIPAddressInfo_Finish_GetSubnetMask(This,pulDottedQuadOut)	\
    (This)->lpVtbl -> Finish_GetSubnetMask(This,pulDottedQuadOut)

#define AsyncIClusCfgIPAddressInfo_Begin_SetSubnetMask(This,ulDottedQuadIn)	\
    (This)->lpVtbl -> Begin_SetSubnetMask(This,ulDottedQuadIn)

#define AsyncIClusCfgIPAddressInfo_Finish_SetSubnetMask(This)	\
    (This)->lpVtbl -> Finish_SetSubnetMask(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgIPAddressInfo_Begin_GetUID_Proxy( 
    AsyncIClusCfgIPAddressInfo * This);


void __RPC_STUB AsyncIClusCfgIPAddressInfo_Begin_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgIPAddressInfo_Finish_GetUID_Proxy( 
    AsyncIClusCfgIPAddressInfo * This,
    /* [out] */ BSTR *pbstrUIDOut);


void __RPC_STUB AsyncIClusCfgIPAddressInfo_Finish_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgIPAddressInfo_Begin_GetIPAddress_Proxy( 
    AsyncIClusCfgIPAddressInfo * This);


void __RPC_STUB AsyncIClusCfgIPAddressInfo_Begin_GetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgIPAddressInfo_Finish_GetIPAddress_Proxy( 
    AsyncIClusCfgIPAddressInfo * This,
    /* [out] */ ULONG *pulDottedQuadOut);


void __RPC_STUB AsyncIClusCfgIPAddressInfo_Finish_GetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgIPAddressInfo_Begin_SetIPAddress_Proxy( 
    AsyncIClusCfgIPAddressInfo * This,
    /* [in] */ ULONG ulDottedQuadIn);


void __RPC_STUB AsyncIClusCfgIPAddressInfo_Begin_SetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgIPAddressInfo_Finish_SetIPAddress_Proxy( 
    AsyncIClusCfgIPAddressInfo * This);


void __RPC_STUB AsyncIClusCfgIPAddressInfo_Finish_SetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgIPAddressInfo_Begin_GetSubnetMask_Proxy( 
    AsyncIClusCfgIPAddressInfo * This);


void __RPC_STUB AsyncIClusCfgIPAddressInfo_Begin_GetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgIPAddressInfo_Finish_GetSubnetMask_Proxy( 
    AsyncIClusCfgIPAddressInfo * This,
    /* [out] */ ULONG *pulDottedQuadOut);


void __RPC_STUB AsyncIClusCfgIPAddressInfo_Finish_GetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgIPAddressInfo_Begin_SetSubnetMask_Proxy( 
    AsyncIClusCfgIPAddressInfo * This,
    /* [in] */ ULONG ulDottedQuadIn);


void __RPC_STUB AsyncIClusCfgIPAddressInfo_Begin_SetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgIPAddressInfo_Finish_SetSubnetMask_Proxy( 
    AsyncIClusCfgIPAddressInfo * This);


void __RPC_STUB AsyncIClusCfgIPAddressInfo_Finish_SetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgIPAddressInfo_INTERFACE_DEFINED__ */


#ifndef __IClusCfgNetworkInfo_INTERFACE_DEFINED__
#define __IClusCfgNetworkInfo_INTERFACE_DEFINED__

/* interface IClusCfgNetworkInfo */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgNetworkInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19FC7580-950A-44a6-966E-74B14B20918F")
    IClusCfgNetworkInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetUID( 
            /* [out] */ BSTR *pbstrUIDOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR *pbstrNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR bstrNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ BSTR *pbstrDescriptionOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [in] */ BSTR bstrDescriptionIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrimaryNetworkAddress( 
            /* [out] */ IClusCfgIPAddressInfo **ppIPAddressOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPrimaryNetworkAddress( 
            /* [in] */ IClusCfgIPAddressInfo *pIPAddressIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPublic( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPublic( 
            /* [in] */ BOOL fIsPublicIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPrivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPrivate( 
            /* [in] */ BOOL fIsPrivateIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgNetworkInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgNetworkInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgNetworkInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetUID )( 
            IClusCfgNetworkInfo * This,
            /* [out] */ BSTR *pbstrUIDOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IClusCfgNetworkInfo * This,
            /* [out] */ BSTR *pbstrNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IClusCfgNetworkInfo * This,
            /* [in] */ BSTR bstrNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IClusCfgNetworkInfo * This,
            /* [out] */ BSTR *pbstrDescriptionOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IClusCfgNetworkInfo * This,
            /* [in] */ BSTR bstrDescriptionIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrimaryNetworkAddress )( 
            IClusCfgNetworkInfo * This,
            /* [out] */ IClusCfgIPAddressInfo **ppIPAddressOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrimaryNetworkAddress )( 
            IClusCfgNetworkInfo * This,
            /* [in] */ IClusCfgIPAddressInfo *pIPAddressIn);
        
        HRESULT ( STDMETHODCALLTYPE *IsPublic )( 
            IClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPublic )( 
            IClusCfgNetworkInfo * This,
            /* [in] */ BOOL fIsPublicIn);
        
        HRESULT ( STDMETHODCALLTYPE *IsPrivate )( 
            IClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivate )( 
            IClusCfgNetworkInfo * This,
            /* [in] */ BOOL fIsPrivateIn);
        
        END_INTERFACE
    } IClusCfgNetworkInfoVtbl;

    interface IClusCfgNetworkInfo
    {
        CONST_VTBL struct IClusCfgNetworkInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgNetworkInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgNetworkInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgNetworkInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgNetworkInfo_GetUID(This,pbstrUIDOut)	\
    (This)->lpVtbl -> GetUID(This,pbstrUIDOut)

#define IClusCfgNetworkInfo_GetName(This,pbstrNameOut)	\
    (This)->lpVtbl -> GetName(This,pbstrNameOut)

#define IClusCfgNetworkInfo_SetName(This,bstrNameIn)	\
    (This)->lpVtbl -> SetName(This,bstrNameIn)

#define IClusCfgNetworkInfo_GetDescription(This,pbstrDescriptionOut)	\
    (This)->lpVtbl -> GetDescription(This,pbstrDescriptionOut)

#define IClusCfgNetworkInfo_SetDescription(This,bstrDescriptionIn)	\
    (This)->lpVtbl -> SetDescription(This,bstrDescriptionIn)

#define IClusCfgNetworkInfo_GetPrimaryNetworkAddress(This,ppIPAddressOut)	\
    (This)->lpVtbl -> GetPrimaryNetworkAddress(This,ppIPAddressOut)

#define IClusCfgNetworkInfo_SetPrimaryNetworkAddress(This,pIPAddressIn)	\
    (This)->lpVtbl -> SetPrimaryNetworkAddress(This,pIPAddressIn)

#define IClusCfgNetworkInfo_IsPublic(This)	\
    (This)->lpVtbl -> IsPublic(This)

#define IClusCfgNetworkInfo_SetPublic(This,fIsPublicIn)	\
    (This)->lpVtbl -> SetPublic(This,fIsPublicIn)

#define IClusCfgNetworkInfo_IsPrivate(This)	\
    (This)->lpVtbl -> IsPrivate(This)

#define IClusCfgNetworkInfo_SetPrivate(This,fIsPrivateIn)	\
    (This)->lpVtbl -> SetPrivate(This,fIsPrivateIn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_GetUID_Proxy( 
    IClusCfgNetworkInfo * This,
    /* [out] */ BSTR *pbstrUIDOut);


void __RPC_STUB IClusCfgNetworkInfo_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_GetName_Proxy( 
    IClusCfgNetworkInfo * This,
    /* [out] */ BSTR *pbstrNameOut);


void __RPC_STUB IClusCfgNetworkInfo_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_SetName_Proxy( 
    IClusCfgNetworkInfo * This,
    /* [in] */ BSTR bstrNameIn);


void __RPC_STUB IClusCfgNetworkInfo_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_GetDescription_Proxy( 
    IClusCfgNetworkInfo * This,
    /* [out] */ BSTR *pbstrDescriptionOut);


void __RPC_STUB IClusCfgNetworkInfo_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_SetDescription_Proxy( 
    IClusCfgNetworkInfo * This,
    /* [in] */ BSTR bstrDescriptionIn);


void __RPC_STUB IClusCfgNetworkInfo_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_GetPrimaryNetworkAddress_Proxy( 
    IClusCfgNetworkInfo * This,
    /* [out] */ IClusCfgIPAddressInfo **ppIPAddressOut);


void __RPC_STUB IClusCfgNetworkInfo_GetPrimaryNetworkAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_SetPrimaryNetworkAddress_Proxy( 
    IClusCfgNetworkInfo * This,
    /* [in] */ IClusCfgIPAddressInfo *pIPAddressIn);


void __RPC_STUB IClusCfgNetworkInfo_SetPrimaryNetworkAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_IsPublic_Proxy( 
    IClusCfgNetworkInfo * This);


void __RPC_STUB IClusCfgNetworkInfo_IsPublic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_SetPublic_Proxy( 
    IClusCfgNetworkInfo * This,
    /* [in] */ BOOL fIsPublicIn);


void __RPC_STUB IClusCfgNetworkInfo_SetPublic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_IsPrivate_Proxy( 
    IClusCfgNetworkInfo * This);


void __RPC_STUB IClusCfgNetworkInfo_IsPrivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgNetworkInfo_SetPrivate_Proxy( 
    IClusCfgNetworkInfo * This,
    /* [in] */ BOOL fIsPrivateIn);


void __RPC_STUB IClusCfgNetworkInfo_SetPrivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgNetworkInfo_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgNetworkInfo_INTERFACE_DEFINED__
#define __AsyncIClusCfgNetworkInfo_INTERFACE_DEFINED__

/* interface AsyncIClusCfgNetworkInfo */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgNetworkInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ED71FD2D-AD02-4dfc-B376-5FFA5F5A7C2C")
    AsyncIClusCfgNetworkInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_GetUID( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetUID( 
            /* [out] */ BSTR *pbstrUIDOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetName( 
            /* [out] */ BSTR *pbstrNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetName( 
            /* [in] */ BSTR bstrNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetDescription( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetDescription( 
            /* [out] */ BSTR *pbstrDescriptionOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetDescription( 
            /* [in] */ BSTR bstrDescriptionIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetDescription( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetPrimaryNetworkAddress( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetPrimaryNetworkAddress( 
            /* [out] */ IClusCfgIPAddressInfo **ppIPAddressOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetPrimaryNetworkAddress( 
            /* [in] */ IClusCfgIPAddressInfo *pIPAddressIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetPrimaryNetworkAddress( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_IsPublic( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_IsPublic( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetPublic( 
            /* [in] */ BOOL fIsPublicIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetPublic( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_IsPrivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_IsPrivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetPrivate( 
            /* [in] */ BOOL fIsPrivateIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetPrivate( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgNetworkInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgNetworkInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgNetworkInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetUID )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetUID )( 
            AsyncIClusCfgNetworkInfo * This,
            /* [out] */ BSTR *pbstrUIDOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetName )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetName )( 
            AsyncIClusCfgNetworkInfo * This,
            /* [out] */ BSTR *pbstrNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetName )( 
            AsyncIClusCfgNetworkInfo * This,
            /* [in] */ BSTR bstrNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetName )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetDescription )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetDescription )( 
            AsyncIClusCfgNetworkInfo * This,
            /* [out] */ BSTR *pbstrDescriptionOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetDescription )( 
            AsyncIClusCfgNetworkInfo * This,
            /* [in] */ BSTR bstrDescriptionIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetDescription )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetPrimaryNetworkAddress )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetPrimaryNetworkAddress )( 
            AsyncIClusCfgNetworkInfo * This,
            /* [out] */ IClusCfgIPAddressInfo **ppIPAddressOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetPrimaryNetworkAddress )( 
            AsyncIClusCfgNetworkInfo * This,
            /* [in] */ IClusCfgIPAddressInfo *pIPAddressIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetPrimaryNetworkAddress )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_IsPublic )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_IsPublic )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetPublic )( 
            AsyncIClusCfgNetworkInfo * This,
            /* [in] */ BOOL fIsPublicIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetPublic )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_IsPrivate )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_IsPrivate )( 
            AsyncIClusCfgNetworkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetPrivate )( 
            AsyncIClusCfgNetworkInfo * This,
            /* [in] */ BOOL fIsPrivateIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetPrivate )( 
            AsyncIClusCfgNetworkInfo * This);
        
        END_INTERFACE
    } AsyncIClusCfgNetworkInfoVtbl;

    interface AsyncIClusCfgNetworkInfo
    {
        CONST_VTBL struct AsyncIClusCfgNetworkInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgNetworkInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgNetworkInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgNetworkInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgNetworkInfo_Begin_GetUID(This)	\
    (This)->lpVtbl -> Begin_GetUID(This)

#define AsyncIClusCfgNetworkInfo_Finish_GetUID(This,pbstrUIDOut)	\
    (This)->lpVtbl -> Finish_GetUID(This,pbstrUIDOut)

#define AsyncIClusCfgNetworkInfo_Begin_GetName(This)	\
    (This)->lpVtbl -> Begin_GetName(This)

#define AsyncIClusCfgNetworkInfo_Finish_GetName(This,pbstrNameOut)	\
    (This)->lpVtbl -> Finish_GetName(This,pbstrNameOut)

#define AsyncIClusCfgNetworkInfo_Begin_SetName(This,bstrNameIn)	\
    (This)->lpVtbl -> Begin_SetName(This,bstrNameIn)

#define AsyncIClusCfgNetworkInfo_Finish_SetName(This)	\
    (This)->lpVtbl -> Finish_SetName(This)

#define AsyncIClusCfgNetworkInfo_Begin_GetDescription(This)	\
    (This)->lpVtbl -> Begin_GetDescription(This)

#define AsyncIClusCfgNetworkInfo_Finish_GetDescription(This,pbstrDescriptionOut)	\
    (This)->lpVtbl -> Finish_GetDescription(This,pbstrDescriptionOut)

#define AsyncIClusCfgNetworkInfo_Begin_SetDescription(This,bstrDescriptionIn)	\
    (This)->lpVtbl -> Begin_SetDescription(This,bstrDescriptionIn)

#define AsyncIClusCfgNetworkInfo_Finish_SetDescription(This)	\
    (This)->lpVtbl -> Finish_SetDescription(This)

#define AsyncIClusCfgNetworkInfo_Begin_GetPrimaryNetworkAddress(This)	\
    (This)->lpVtbl -> Begin_GetPrimaryNetworkAddress(This)

#define AsyncIClusCfgNetworkInfo_Finish_GetPrimaryNetworkAddress(This,ppIPAddressOut)	\
    (This)->lpVtbl -> Finish_GetPrimaryNetworkAddress(This,ppIPAddressOut)

#define AsyncIClusCfgNetworkInfo_Begin_SetPrimaryNetworkAddress(This,pIPAddressIn)	\
    (This)->lpVtbl -> Begin_SetPrimaryNetworkAddress(This,pIPAddressIn)

#define AsyncIClusCfgNetworkInfo_Finish_SetPrimaryNetworkAddress(This)	\
    (This)->lpVtbl -> Finish_SetPrimaryNetworkAddress(This)

#define AsyncIClusCfgNetworkInfo_Begin_IsPublic(This)	\
    (This)->lpVtbl -> Begin_IsPublic(This)

#define AsyncIClusCfgNetworkInfo_Finish_IsPublic(This)	\
    (This)->lpVtbl -> Finish_IsPublic(This)

#define AsyncIClusCfgNetworkInfo_Begin_SetPublic(This,fIsPublicIn)	\
    (This)->lpVtbl -> Begin_SetPublic(This,fIsPublicIn)

#define AsyncIClusCfgNetworkInfo_Finish_SetPublic(This)	\
    (This)->lpVtbl -> Finish_SetPublic(This)

#define AsyncIClusCfgNetworkInfo_Begin_IsPrivate(This)	\
    (This)->lpVtbl -> Begin_IsPrivate(This)

#define AsyncIClusCfgNetworkInfo_Finish_IsPrivate(This)	\
    (This)->lpVtbl -> Finish_IsPrivate(This)

#define AsyncIClusCfgNetworkInfo_Begin_SetPrivate(This,fIsPrivateIn)	\
    (This)->lpVtbl -> Begin_SetPrivate(This,fIsPrivateIn)

#define AsyncIClusCfgNetworkInfo_Finish_SetPrivate(This)	\
    (This)->lpVtbl -> Finish_SetPrivate(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_GetUID_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_GetUID_Proxy( 
    AsyncIClusCfgNetworkInfo * This,
    /* [out] */ BSTR *pbstrUIDOut);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_GetUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_GetName_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_GetName_Proxy( 
    AsyncIClusCfgNetworkInfo * This,
    /* [out] */ BSTR *pbstrNameOut);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_SetName_Proxy( 
    AsyncIClusCfgNetworkInfo * This,
    /* [in] */ BSTR bstrNameIn);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_SetName_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_GetDescription_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_GetDescription_Proxy( 
    AsyncIClusCfgNetworkInfo * This,
    /* [out] */ BSTR *pbstrDescriptionOut);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_SetDescription_Proxy( 
    AsyncIClusCfgNetworkInfo * This,
    /* [in] */ BSTR bstrDescriptionIn);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_SetDescription_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_GetPrimaryNetworkAddress_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_GetPrimaryNetworkAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_GetPrimaryNetworkAddress_Proxy( 
    AsyncIClusCfgNetworkInfo * This,
    /* [out] */ IClusCfgIPAddressInfo **ppIPAddressOut);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_GetPrimaryNetworkAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_SetPrimaryNetworkAddress_Proxy( 
    AsyncIClusCfgNetworkInfo * This,
    /* [in] */ IClusCfgIPAddressInfo *pIPAddressIn);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_SetPrimaryNetworkAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_SetPrimaryNetworkAddress_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_SetPrimaryNetworkAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_IsPublic_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_IsPublic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_IsPublic_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_IsPublic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_SetPublic_Proxy( 
    AsyncIClusCfgNetworkInfo * This,
    /* [in] */ BOOL fIsPublicIn);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_SetPublic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_SetPublic_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_SetPublic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_IsPrivate_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_IsPrivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_IsPrivate_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_IsPrivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Begin_SetPrivate_Proxy( 
    AsyncIClusCfgNetworkInfo * This,
    /* [in] */ BOOL fIsPrivateIn);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Begin_SetPrivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgNetworkInfo_Finish_SetPrivate_Proxy( 
    AsyncIClusCfgNetworkInfo * This);


void __RPC_STUB AsyncIClusCfgNetworkInfo_Finish_SetPrivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgNetworkInfo_INTERFACE_DEFINED__ */


#ifndef __IClusCfgClusterInfo_INTERFACE_DEFINED__
#define __IClusCfgClusterInfo_INTERFACE_DEFINED__

/* interface IClusCfgClusterInfo */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgClusterInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("85B4BBC0-DDC4-4ae7-8268-F4850BB2A6EE")
    IClusCfgClusterInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsForming( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsJoining( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEvicted( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetForming( 
            /* [in] */ BOOL fFormingIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetJoining( 
            /* [in] */ BOOL fJoiningIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEvicted( 
            /* [in] */ BOOL fEvictedIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR *pbstrNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR bstrNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIPAddress( 
            /* [out] */ ULONG *pulDottedQuadOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIPAddress( 
            /* [in] */ ULONG ulDottedQuadIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubnetMask( 
            /* [out] */ ULONG *pulDottedQuadOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSubnetMask( 
            /* [in] */ ULONG ulDottedQuadIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkInfo( 
            /* [out] */ IClusCfgNetworkInfo **ppiccniOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNetworkInfo( 
            /* [in] */ IClusCfgNetworkInfo *piccniIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClusterServiceAccountCredentials( 
            /* [out] */ IClusCfgCredentials **ppicccCredentialsOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgClusterInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgClusterInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgClusterInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsForming )( 
            IClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsJoining )( 
            IClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsEvicted )( 
            IClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetForming )( 
            IClusCfgClusterInfo * This,
            /* [in] */ BOOL fFormingIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetJoining )( 
            IClusCfgClusterInfo * This,
            /* [in] */ BOOL fJoiningIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetEvicted )( 
            IClusCfgClusterInfo * This,
            /* [in] */ BOOL fEvictedIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IClusCfgClusterInfo * This,
            /* [out] */ BSTR *pbstrNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IClusCfgClusterInfo * This,
            /* [in] */ BSTR bstrNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetIPAddress )( 
            IClusCfgClusterInfo * This,
            /* [out] */ ULONG *pulDottedQuadOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetIPAddress )( 
            IClusCfgClusterInfo * This,
            /* [in] */ ULONG ulDottedQuadIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubnetMask )( 
            IClusCfgClusterInfo * This,
            /* [out] */ ULONG *pulDottedQuadOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetSubnetMask )( 
            IClusCfgClusterInfo * This,
            /* [in] */ ULONG ulDottedQuadIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkInfo )( 
            IClusCfgClusterInfo * This,
            /* [out] */ IClusCfgNetworkInfo **ppiccniOut);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkInfo )( 
            IClusCfgClusterInfo * This,
            /* [in] */ IClusCfgNetworkInfo *piccniIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetClusterServiceAccountCredentials )( 
            IClusCfgClusterInfo * This,
            /* [out] */ IClusCfgCredentials **ppicccCredentialsOut);
        
        END_INTERFACE
    } IClusCfgClusterInfoVtbl;

    interface IClusCfgClusterInfo
    {
        CONST_VTBL struct IClusCfgClusterInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgClusterInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgClusterInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgClusterInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgClusterInfo_IsForming(This)	\
    (This)->lpVtbl -> IsForming(This)

#define IClusCfgClusterInfo_IsJoining(This)	\
    (This)->lpVtbl -> IsJoining(This)

#define IClusCfgClusterInfo_IsEvicted(This)	\
    (This)->lpVtbl -> IsEvicted(This)

#define IClusCfgClusterInfo_SetForming(This,fFormingIn)	\
    (This)->lpVtbl -> SetForming(This,fFormingIn)

#define IClusCfgClusterInfo_SetJoining(This,fJoiningIn)	\
    (This)->lpVtbl -> SetJoining(This,fJoiningIn)

#define IClusCfgClusterInfo_SetEvicted(This,fEvictedIn)	\
    (This)->lpVtbl -> SetEvicted(This,fEvictedIn)

#define IClusCfgClusterInfo_GetName(This,pbstrNameOut)	\
    (This)->lpVtbl -> GetName(This,pbstrNameOut)

#define IClusCfgClusterInfo_SetName(This,bstrNameIn)	\
    (This)->lpVtbl -> SetName(This,bstrNameIn)

#define IClusCfgClusterInfo_GetIPAddress(This,pulDottedQuadOut)	\
    (This)->lpVtbl -> GetIPAddress(This,pulDottedQuadOut)

#define IClusCfgClusterInfo_SetIPAddress(This,ulDottedQuadIn)	\
    (This)->lpVtbl -> SetIPAddress(This,ulDottedQuadIn)

#define IClusCfgClusterInfo_GetSubnetMask(This,pulDottedQuadOut)	\
    (This)->lpVtbl -> GetSubnetMask(This,pulDottedQuadOut)

#define IClusCfgClusterInfo_SetSubnetMask(This,ulDottedQuadIn)	\
    (This)->lpVtbl -> SetSubnetMask(This,ulDottedQuadIn)

#define IClusCfgClusterInfo_GetNetworkInfo(This,ppiccniOut)	\
    (This)->lpVtbl -> GetNetworkInfo(This,ppiccniOut)

#define IClusCfgClusterInfo_SetNetworkInfo(This,piccniIn)	\
    (This)->lpVtbl -> SetNetworkInfo(This,piccniIn)

#define IClusCfgClusterInfo_GetClusterServiceAccountCredentials(This,ppicccCredentialsOut)	\
    (This)->lpVtbl -> GetClusterServiceAccountCredentials(This,ppicccCredentialsOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_IsForming_Proxy( 
    IClusCfgClusterInfo * This);


void __RPC_STUB IClusCfgClusterInfo_IsForming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_IsJoining_Proxy( 
    IClusCfgClusterInfo * This);


void __RPC_STUB IClusCfgClusterInfo_IsJoining_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_IsEvicted_Proxy( 
    IClusCfgClusterInfo * This);


void __RPC_STUB IClusCfgClusterInfo_IsEvicted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_SetForming_Proxy( 
    IClusCfgClusterInfo * This,
    /* [in] */ BOOL fFormingIn);


void __RPC_STUB IClusCfgClusterInfo_SetForming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_SetJoining_Proxy( 
    IClusCfgClusterInfo * This,
    /* [in] */ BOOL fJoiningIn);


void __RPC_STUB IClusCfgClusterInfo_SetJoining_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_SetEvicted_Proxy( 
    IClusCfgClusterInfo * This,
    /* [in] */ BOOL fEvictedIn);


void __RPC_STUB IClusCfgClusterInfo_SetEvicted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_GetName_Proxy( 
    IClusCfgClusterInfo * This,
    /* [out] */ BSTR *pbstrNameOut);


void __RPC_STUB IClusCfgClusterInfo_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_SetName_Proxy( 
    IClusCfgClusterInfo * This,
    /* [in] */ BSTR bstrNameIn);


void __RPC_STUB IClusCfgClusterInfo_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_GetIPAddress_Proxy( 
    IClusCfgClusterInfo * This,
    /* [out] */ ULONG *pulDottedQuadOut);


void __RPC_STUB IClusCfgClusterInfo_GetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_SetIPAddress_Proxy( 
    IClusCfgClusterInfo * This,
    /* [in] */ ULONG ulDottedQuadIn);


void __RPC_STUB IClusCfgClusterInfo_SetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_GetSubnetMask_Proxy( 
    IClusCfgClusterInfo * This,
    /* [out] */ ULONG *pulDottedQuadOut);


void __RPC_STUB IClusCfgClusterInfo_GetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_SetSubnetMask_Proxy( 
    IClusCfgClusterInfo * This,
    /* [in] */ ULONG ulDottedQuadIn);


void __RPC_STUB IClusCfgClusterInfo_SetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_GetNetworkInfo_Proxy( 
    IClusCfgClusterInfo * This,
    /* [out] */ IClusCfgNetworkInfo **ppiccniOut);


void __RPC_STUB IClusCfgClusterInfo_GetNetworkInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_SetNetworkInfo_Proxy( 
    IClusCfgClusterInfo * This,
    /* [in] */ IClusCfgNetworkInfo *piccniIn);


void __RPC_STUB IClusCfgClusterInfo_SetNetworkInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgClusterInfo_GetClusterServiceAccountCredentials_Proxy( 
    IClusCfgClusterInfo * This,
    /* [out] */ IClusCfgCredentials **ppicccCredentialsOut);


void __RPC_STUB IClusCfgClusterInfo_GetClusterServiceAccountCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgClusterInfo_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgClusterInfo_INTERFACE_DEFINED__
#define __AsyncIClusCfgClusterInfo_INTERFACE_DEFINED__

/* interface AsyncIClusCfgClusterInfo */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgClusterInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8BDBA247-04F5-4114-837E-B263412A4B64")
    AsyncIClusCfgClusterInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_IsForming( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_IsForming( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_IsJoining( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_IsJoining( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_IsEvicted( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_IsEvicted( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetForming( 
            /* [in] */ BOOL fFormingIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetForming( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetJoining( 
            /* [in] */ BOOL fJoiningIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetJoining( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetEvicted( 
            /* [in] */ BOOL fEvictedIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetEvicted( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetName( 
            /* [out] */ BSTR *pbstrNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetName( 
            /* [in] */ BSTR bstrNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetIPAddress( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetIPAddress( 
            /* [out] */ ULONG *pulDottedQuadOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetIPAddress( 
            /* [in] */ ULONG ulDottedQuadIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetIPAddress( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetSubnetMask( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetSubnetMask( 
            /* [out] */ ULONG *pulDottedQuadOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetSubnetMask( 
            /* [in] */ ULONG ulDottedQuadIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetSubnetMask( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetNetworkInfo( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetNetworkInfo( 
            /* [out] */ IClusCfgNetworkInfo **ppiccniOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetNetworkInfo( 
            /* [in] */ IClusCfgNetworkInfo *piccniIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetNetworkInfo( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetClusterServiceAccountCredentials( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetClusterServiceAccountCredentials( 
            /* [out] */ IClusCfgCredentials **ppicccCredentialsOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgClusterInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgClusterInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgClusterInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_IsForming )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_IsForming )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_IsJoining )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_IsJoining )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_IsEvicted )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_IsEvicted )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetForming )( 
            AsyncIClusCfgClusterInfo * This,
            /* [in] */ BOOL fFormingIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetForming )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetJoining )( 
            AsyncIClusCfgClusterInfo * This,
            /* [in] */ BOOL fJoiningIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetJoining )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetEvicted )( 
            AsyncIClusCfgClusterInfo * This,
            /* [in] */ BOOL fEvictedIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetEvicted )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetName )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetName )( 
            AsyncIClusCfgClusterInfo * This,
            /* [out] */ BSTR *pbstrNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetName )( 
            AsyncIClusCfgClusterInfo * This,
            /* [in] */ BSTR bstrNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetName )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetIPAddress )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetIPAddress )( 
            AsyncIClusCfgClusterInfo * This,
            /* [out] */ ULONG *pulDottedQuadOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetIPAddress )( 
            AsyncIClusCfgClusterInfo * This,
            /* [in] */ ULONG ulDottedQuadIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetIPAddress )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetSubnetMask )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetSubnetMask )( 
            AsyncIClusCfgClusterInfo * This,
            /* [out] */ ULONG *pulDottedQuadOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetSubnetMask )( 
            AsyncIClusCfgClusterInfo * This,
            /* [in] */ ULONG ulDottedQuadIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetSubnetMask )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetNetworkInfo )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetNetworkInfo )( 
            AsyncIClusCfgClusterInfo * This,
            /* [out] */ IClusCfgNetworkInfo **ppiccniOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetNetworkInfo )( 
            AsyncIClusCfgClusterInfo * This,
            /* [in] */ IClusCfgNetworkInfo *piccniIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetNetworkInfo )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetClusterServiceAccountCredentials )( 
            AsyncIClusCfgClusterInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetClusterServiceAccountCredentials )( 
            AsyncIClusCfgClusterInfo * This,
            /* [out] */ IClusCfgCredentials **ppicccCredentialsOut);
        
        END_INTERFACE
    } AsyncIClusCfgClusterInfoVtbl;

    interface AsyncIClusCfgClusterInfo
    {
        CONST_VTBL struct AsyncIClusCfgClusterInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgClusterInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgClusterInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgClusterInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgClusterInfo_Begin_IsForming(This)	\
    (This)->lpVtbl -> Begin_IsForming(This)

#define AsyncIClusCfgClusterInfo_Finish_IsForming(This)	\
    (This)->lpVtbl -> Finish_IsForming(This)

#define AsyncIClusCfgClusterInfo_Begin_IsJoining(This)	\
    (This)->lpVtbl -> Begin_IsJoining(This)

#define AsyncIClusCfgClusterInfo_Finish_IsJoining(This)	\
    (This)->lpVtbl -> Finish_IsJoining(This)

#define AsyncIClusCfgClusterInfo_Begin_IsEvicted(This)	\
    (This)->lpVtbl -> Begin_IsEvicted(This)

#define AsyncIClusCfgClusterInfo_Finish_IsEvicted(This)	\
    (This)->lpVtbl -> Finish_IsEvicted(This)

#define AsyncIClusCfgClusterInfo_Begin_SetForming(This,fFormingIn)	\
    (This)->lpVtbl -> Begin_SetForming(This,fFormingIn)

#define AsyncIClusCfgClusterInfo_Finish_SetForming(This)	\
    (This)->lpVtbl -> Finish_SetForming(This)

#define AsyncIClusCfgClusterInfo_Begin_SetJoining(This,fJoiningIn)	\
    (This)->lpVtbl -> Begin_SetJoining(This,fJoiningIn)

#define AsyncIClusCfgClusterInfo_Finish_SetJoining(This)	\
    (This)->lpVtbl -> Finish_SetJoining(This)

#define AsyncIClusCfgClusterInfo_Begin_SetEvicted(This,fEvictedIn)	\
    (This)->lpVtbl -> Begin_SetEvicted(This,fEvictedIn)

#define AsyncIClusCfgClusterInfo_Finish_SetEvicted(This)	\
    (This)->lpVtbl -> Finish_SetEvicted(This)

#define AsyncIClusCfgClusterInfo_Begin_GetName(This)	\
    (This)->lpVtbl -> Begin_GetName(This)

#define AsyncIClusCfgClusterInfo_Finish_GetName(This,pbstrNameOut)	\
    (This)->lpVtbl -> Finish_GetName(This,pbstrNameOut)

#define AsyncIClusCfgClusterInfo_Begin_SetName(This,bstrNameIn)	\
    (This)->lpVtbl -> Begin_SetName(This,bstrNameIn)

#define AsyncIClusCfgClusterInfo_Finish_SetName(This)	\
    (This)->lpVtbl -> Finish_SetName(This)

#define AsyncIClusCfgClusterInfo_Begin_GetIPAddress(This)	\
    (This)->lpVtbl -> Begin_GetIPAddress(This)

#define AsyncIClusCfgClusterInfo_Finish_GetIPAddress(This,pulDottedQuadOut)	\
    (This)->lpVtbl -> Finish_GetIPAddress(This,pulDottedQuadOut)

#define AsyncIClusCfgClusterInfo_Begin_SetIPAddress(This,ulDottedQuadIn)	\
    (This)->lpVtbl -> Begin_SetIPAddress(This,ulDottedQuadIn)

#define AsyncIClusCfgClusterInfo_Finish_SetIPAddress(This)	\
    (This)->lpVtbl -> Finish_SetIPAddress(This)

#define AsyncIClusCfgClusterInfo_Begin_GetSubnetMask(This)	\
    (This)->lpVtbl -> Begin_GetSubnetMask(This)

#define AsyncIClusCfgClusterInfo_Finish_GetSubnetMask(This,pulDottedQuadOut)	\
    (This)->lpVtbl -> Finish_GetSubnetMask(This,pulDottedQuadOut)

#define AsyncIClusCfgClusterInfo_Begin_SetSubnetMask(This,ulDottedQuadIn)	\
    (This)->lpVtbl -> Begin_SetSubnetMask(This,ulDottedQuadIn)

#define AsyncIClusCfgClusterInfo_Finish_SetSubnetMask(This)	\
    (This)->lpVtbl -> Finish_SetSubnetMask(This)

#define AsyncIClusCfgClusterInfo_Begin_GetNetworkInfo(This)	\
    (This)->lpVtbl -> Begin_GetNetworkInfo(This)

#define AsyncIClusCfgClusterInfo_Finish_GetNetworkInfo(This,ppiccniOut)	\
    (This)->lpVtbl -> Finish_GetNetworkInfo(This,ppiccniOut)

#define AsyncIClusCfgClusterInfo_Begin_SetNetworkInfo(This,piccniIn)	\
    (This)->lpVtbl -> Begin_SetNetworkInfo(This,piccniIn)

#define AsyncIClusCfgClusterInfo_Finish_SetNetworkInfo(This)	\
    (This)->lpVtbl -> Finish_SetNetworkInfo(This)

#define AsyncIClusCfgClusterInfo_Begin_GetClusterServiceAccountCredentials(This)	\
    (This)->lpVtbl -> Begin_GetClusterServiceAccountCredentials(This)

#define AsyncIClusCfgClusterInfo_Finish_GetClusterServiceAccountCredentials(This,ppicccCredentialsOut)	\
    (This)->lpVtbl -> Finish_GetClusterServiceAccountCredentials(This,ppicccCredentialsOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_IsForming_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_IsForming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_IsForming_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_IsForming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_IsJoining_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_IsJoining_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_IsJoining_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_IsJoining_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_IsEvicted_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_IsEvicted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_IsEvicted_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_IsEvicted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_SetForming_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [in] */ BOOL fFormingIn);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_SetForming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_SetForming_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_SetForming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_SetJoining_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [in] */ BOOL fJoiningIn);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_SetJoining_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_SetJoining_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_SetJoining_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_SetEvicted_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [in] */ BOOL fEvictedIn);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_SetEvicted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_SetEvicted_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_SetEvicted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_GetName_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_GetName_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [out] */ BSTR *pbstrNameOut);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_SetName_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [in] */ BSTR bstrNameIn);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_SetName_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_GetIPAddress_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_GetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_GetIPAddress_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [out] */ ULONG *pulDottedQuadOut);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_GetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_SetIPAddress_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [in] */ ULONG ulDottedQuadIn);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_SetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_SetIPAddress_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_SetIPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_GetSubnetMask_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_GetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_GetSubnetMask_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [out] */ ULONG *pulDottedQuadOut);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_GetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_SetSubnetMask_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [in] */ ULONG ulDottedQuadIn);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_SetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_SetSubnetMask_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_SetSubnetMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_GetNetworkInfo_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_GetNetworkInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_GetNetworkInfo_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [out] */ IClusCfgNetworkInfo **ppiccniOut);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_GetNetworkInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_SetNetworkInfo_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [in] */ IClusCfgNetworkInfo *piccniIn);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_SetNetworkInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_SetNetworkInfo_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_SetNetworkInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Begin_GetClusterServiceAccountCredentials_Proxy( 
    AsyncIClusCfgClusterInfo * This);


void __RPC_STUB AsyncIClusCfgClusterInfo_Begin_GetClusterServiceAccountCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgClusterInfo_Finish_GetClusterServiceAccountCredentials_Proxy( 
    AsyncIClusCfgClusterInfo * This,
    /* [out] */ IClusCfgCredentials **ppicccCredentialsOut);


void __RPC_STUB AsyncIClusCfgClusterInfo_Finish_GetClusterServiceAccountCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgClusterInfo_INTERFACE_DEFINED__ */


#ifndef __IClusCfgInitialize_INTERFACE_DEFINED__
#define __IClusCfgInitialize_INTERFACE_DEFINED__

/* interface IClusCfgInitialize */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgInitialize;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A0EB82D-F878-492a-951E-AE000918C4A6")
    IClusCfgInitialize : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IUnknown *punkCallbackIn,
            /* [in] */ LCID lcidIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgInitializeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgInitialize * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgInitialize * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgInitialize * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IClusCfgInitialize * This,
            /* [in] */ IUnknown *punkCallbackIn,
            /* [in] */ LCID lcidIn);
        
        END_INTERFACE
    } IClusCfgInitializeVtbl;

    interface IClusCfgInitialize
    {
        CONST_VTBL struct IClusCfgInitializeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgInitialize_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgInitialize_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgInitialize_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgInitialize_Initialize(This,punkCallbackIn,lcidIn)	\
    (This)->lpVtbl -> Initialize(This,punkCallbackIn,lcidIn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgInitialize_Initialize_Proxy( 
    IClusCfgInitialize * This,
    /* [in] */ IUnknown *punkCallbackIn,
    /* [in] */ LCID lcidIn);


void __RPC_STUB IClusCfgInitialize_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgInitialize_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgInitialize_INTERFACE_DEFINED__
#define __AsyncIClusCfgInitialize_INTERFACE_DEFINED__

/* interface AsyncIClusCfgInitialize */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgInitialize;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A0EB82E-F878-492a-951E-AE000918C4A6")
    AsyncIClusCfgInitialize : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Initialize( 
            /* [in] */ IUnknown *punkCallbackIn,
            /* [in] */ LCID lcidIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Initialize( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgInitializeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgInitialize * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgInitialize * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgInitialize * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Initialize )( 
            AsyncIClusCfgInitialize * This,
            /* [in] */ IUnknown *punkCallbackIn,
            /* [in] */ LCID lcidIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Initialize )( 
            AsyncIClusCfgInitialize * This);
        
        END_INTERFACE
    } AsyncIClusCfgInitializeVtbl;

    interface AsyncIClusCfgInitialize
    {
        CONST_VTBL struct AsyncIClusCfgInitializeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgInitialize_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgInitialize_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgInitialize_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgInitialize_Begin_Initialize(This,punkCallbackIn,lcidIn)	\
    (This)->lpVtbl -> Begin_Initialize(This,punkCallbackIn,lcidIn)

#define AsyncIClusCfgInitialize_Finish_Initialize(This)	\
    (This)->lpVtbl -> Finish_Initialize(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgInitialize_Begin_Initialize_Proxy( 
    AsyncIClusCfgInitialize * This,
    /* [in] */ IUnknown *punkCallbackIn,
    /* [in] */ LCID lcidIn);


void __RPC_STUB AsyncIClusCfgInitialize_Begin_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgInitialize_Finish_Initialize_Proxy( 
    AsyncIClusCfgInitialize * This);


void __RPC_STUB AsyncIClusCfgInitialize_Finish_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgInitialize_INTERFACE_DEFINED__ */


#ifndef __IClusCfgCallback_INTERFACE_DEFINED__
#define __IClusCfgCallback_INTERFACE_DEFINED__

/* interface IClusCfgCallback */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("238DCA63-E2EF-4f32-A24D-ACBF975BE842")
    IClusCfgCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SendStatusReport( 
            /* [in] */ BSTR bstrNodeNameIn,
            /* [in] */ CLSID clsidTaskMajorIn,
            /* [in] */ CLSID clsidTaskMinorIn,
            /* [in] */ ULONG ulMinIn,
            /* [in] */ ULONG ulMaxIn,
            /* [in] */ ULONG ulCurrentIn,
            /* [in] */ HRESULT hrStatusIn,
            /* [in] */ BSTR bstrDescriptionIn,
            /* [in] */ FILETIME *pftTimeIn,
            /* [in] */ BSTR bstrReferenceIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *SendStatusReport )( 
            IClusCfgCallback * This,
            /* [in] */ BSTR bstrNodeNameIn,
            /* [in] */ CLSID clsidTaskMajorIn,
            /* [in] */ CLSID clsidTaskMinorIn,
            /* [in] */ ULONG ulMinIn,
            /* [in] */ ULONG ulMaxIn,
            /* [in] */ ULONG ulCurrentIn,
            /* [in] */ HRESULT hrStatusIn,
            /* [in] */ BSTR bstrDescriptionIn,
            /* [in] */ FILETIME *pftTimeIn,
            /* [in] */ BSTR bstrReferenceIn);
        
        END_INTERFACE
    } IClusCfgCallbackVtbl;

    interface IClusCfgCallback
    {
        CONST_VTBL struct IClusCfgCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgCallback_SendStatusReport(This,bstrNodeNameIn,clsidTaskMajorIn,clsidTaskMinorIn,ulMinIn,ulMaxIn,ulCurrentIn,hrStatusIn,bstrDescriptionIn,pftTimeIn,bstrReferenceIn)	\
    (This)->lpVtbl -> SendStatusReport(This,bstrNodeNameIn,clsidTaskMajorIn,clsidTaskMinorIn,ulMinIn,ulMaxIn,ulCurrentIn,hrStatusIn,bstrDescriptionIn,pftTimeIn,bstrReferenceIn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgCallback_SendStatusReport_Proxy( 
    IClusCfgCallback * This,
    /* [in] */ BSTR bstrNodeNameIn,
    /* [in] */ CLSID clsidTaskMajorIn,
    /* [in] */ CLSID clsidTaskMinorIn,
    /* [in] */ ULONG ulMinIn,
    /* [in] */ ULONG ulMaxIn,
    /* [in] */ ULONG ulCurrentIn,
    /* [in] */ HRESULT hrStatusIn,
    /* [in] */ BSTR bstrDescriptionIn,
    /* [in] */ FILETIME *pftTimeIn,
    /* [in] */ BSTR bstrReferenceIn);


void __RPC_STUB IClusCfgCallback_SendStatusReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgCallback_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgCallback_INTERFACE_DEFINED__
#define __AsyncIClusCfgCallback_INTERFACE_DEFINED__

/* interface AsyncIClusCfgCallback */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EBCE8945-AC69-4b3a-865D-E2D4EB33E41B")
    AsyncIClusCfgCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_SendStatusReport( 
            /* [in] */ BSTR bstrNodeNameIn,
            /* [in] */ CLSID clsidTaskMajorIn,
            /* [in] */ CLSID clsidTaskMinorIn,
            /* [in] */ ULONG ulMinIn,
            /* [in] */ ULONG ulMaxIn,
            /* [in] */ ULONG ulCurrentIn,
            /* [in] */ HRESULT hrStatusIn,
            /* [in] */ BSTR bstrDescriptionIn,
            /* [in] */ FILETIME *pftTimeIn,
            /* [in] */ BSTR bstrReferenceIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SendStatusReport( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SendStatusReport )( 
            AsyncIClusCfgCallback * This,
            /* [in] */ BSTR bstrNodeNameIn,
            /* [in] */ CLSID clsidTaskMajorIn,
            /* [in] */ CLSID clsidTaskMinorIn,
            /* [in] */ ULONG ulMinIn,
            /* [in] */ ULONG ulMaxIn,
            /* [in] */ ULONG ulCurrentIn,
            /* [in] */ HRESULT hrStatusIn,
            /* [in] */ BSTR bstrDescriptionIn,
            /* [in] */ FILETIME *pftTimeIn,
            /* [in] */ BSTR bstrReferenceIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SendStatusReport )( 
            AsyncIClusCfgCallback * This);
        
        END_INTERFACE
    } AsyncIClusCfgCallbackVtbl;

    interface AsyncIClusCfgCallback
    {
        CONST_VTBL struct AsyncIClusCfgCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgCallback_Begin_SendStatusReport(This,bstrNodeNameIn,clsidTaskMajorIn,clsidTaskMinorIn,ulMinIn,ulMaxIn,ulCurrentIn,hrStatusIn,bstrDescriptionIn,pftTimeIn,bstrReferenceIn)	\
    (This)->lpVtbl -> Begin_SendStatusReport(This,bstrNodeNameIn,clsidTaskMajorIn,clsidTaskMinorIn,ulMinIn,ulMaxIn,ulCurrentIn,hrStatusIn,bstrDescriptionIn,pftTimeIn,bstrReferenceIn)

#define AsyncIClusCfgCallback_Finish_SendStatusReport(This)	\
    (This)->lpVtbl -> Finish_SendStatusReport(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgCallback_Begin_SendStatusReport_Proxy( 
    AsyncIClusCfgCallback * This,
    /* [in] */ BSTR bstrNodeNameIn,
    /* [in] */ CLSID clsidTaskMajorIn,
    /* [in] */ CLSID clsidTaskMinorIn,
    /* [in] */ ULONG ulMinIn,
    /* [in] */ ULONG ulMaxIn,
    /* [in] */ ULONG ulCurrentIn,
    /* [in] */ HRESULT hrStatusIn,
    /* [in] */ BSTR bstrDescriptionIn,
    /* [in] */ FILETIME *pftTimeIn,
    /* [in] */ BSTR bstrReferenceIn);


void __RPC_STUB AsyncIClusCfgCallback_Begin_SendStatusReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgCallback_Finish_SendStatusReport_Proxy( 
    AsyncIClusCfgCallback * This);


void __RPC_STUB AsyncIClusCfgCallback_Finish_SendStatusReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgCallback_INTERFACE_DEFINED__ */


#ifndef __IClusCfgBaseCluster_INTERFACE_DEFINED__
#define __IClusCfgBaseCluster_INTERFACE_DEFINED__

/* interface IClusCfgBaseCluster */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgBaseCluster;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A8A5C613-2518-47f5-96CA-CAFA7FFBAF68")
    IClusCfgBaseCluster : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetForm( 
            /* [string][in] */ const WCHAR *pcszClusterNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn,
            /* [in] */ const DWORD dwClusterIPAddressIn,
            /* [in] */ const DWORD dwClusterIPSubnetMaskIn,
            /* [string][in] */ const WCHAR *pcszClusterIPNetworkIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetJoin( 
            /* [string][in] */ const WCHAR *pcszClusterNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCleanup( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rollback( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgBaseClusterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgBaseCluster * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgBaseCluster * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetForm )( 
            IClusCfgBaseCluster * This,
            /* [string][in] */ const WCHAR *pcszClusterNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn,
            /* [in] */ const DWORD dwClusterIPAddressIn,
            /* [in] */ const DWORD dwClusterIPSubnetMaskIn,
            /* [string][in] */ const WCHAR *pcszClusterIPNetworkIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetJoin )( 
            IClusCfgBaseCluster * This,
            /* [string][in] */ const WCHAR *pcszClusterNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetCleanup )( 
            IClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            IClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *Rollback )( 
            IClusCfgBaseCluster * This);
        
        END_INTERFACE
    } IClusCfgBaseClusterVtbl;

    interface IClusCfgBaseCluster
    {
        CONST_VTBL struct IClusCfgBaseClusterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgBaseCluster_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgBaseCluster_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgBaseCluster_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgBaseCluster_SetForm(This,pcszClusterNameIn,pcszClusterAccountNameIn,pcszClusterAccountPwdIn,pcszClusterAccountDomainIn,dwClusterIPAddressIn,dwClusterIPSubnetMaskIn,pcszClusterIPNetworkIn)	\
    (This)->lpVtbl -> SetForm(This,pcszClusterNameIn,pcszClusterAccountNameIn,pcszClusterAccountPwdIn,pcszClusterAccountDomainIn,dwClusterIPAddressIn,dwClusterIPSubnetMaskIn,pcszClusterIPNetworkIn)

#define IClusCfgBaseCluster_SetJoin(This,pcszClusterNameIn,pcszClusterAccountNameIn,pcszClusterAccountPwdIn,pcszClusterAccountDomainIn)	\
    (This)->lpVtbl -> SetJoin(This,pcszClusterNameIn,pcszClusterAccountNameIn,pcszClusterAccountPwdIn,pcszClusterAccountDomainIn)

#define IClusCfgBaseCluster_SetCleanup(This)	\
    (This)->lpVtbl -> SetCleanup(This)

#define IClusCfgBaseCluster_Commit(This)	\
    (This)->lpVtbl -> Commit(This)

#define IClusCfgBaseCluster_Rollback(This)	\
    (This)->lpVtbl -> Rollback(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgBaseCluster_SetForm_Proxy( 
    IClusCfgBaseCluster * This,
    /* [string][in] */ const WCHAR *pcszClusterNameIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn,
    /* [in] */ const DWORD dwClusterIPAddressIn,
    /* [in] */ const DWORD dwClusterIPSubnetMaskIn,
    /* [string][in] */ const WCHAR *pcszClusterIPNetworkIn);


void __RPC_STUB IClusCfgBaseCluster_SetForm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgBaseCluster_SetJoin_Proxy( 
    IClusCfgBaseCluster * This,
    /* [string][in] */ const WCHAR *pcszClusterNameIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn);


void __RPC_STUB IClusCfgBaseCluster_SetJoin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgBaseCluster_SetCleanup_Proxy( 
    IClusCfgBaseCluster * This);


void __RPC_STUB IClusCfgBaseCluster_SetCleanup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgBaseCluster_Commit_Proxy( 
    IClusCfgBaseCluster * This);


void __RPC_STUB IClusCfgBaseCluster_Commit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgBaseCluster_Rollback_Proxy( 
    IClusCfgBaseCluster * This);


void __RPC_STUB IClusCfgBaseCluster_Rollback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgBaseCluster_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgBaseCluster_INTERFACE_DEFINED__
#define __AsyncIClusCfgBaseCluster_INTERFACE_DEFINED__

/* interface AsyncIClusCfgBaseCluster */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgBaseCluster;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A8A5C614-2518-47f5-96CA-CAFA7FFBAF68")
    AsyncIClusCfgBaseCluster : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_SetForm( 
            /* [string][in] */ const WCHAR *pcszClusterNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn,
            /* [in] */ const DWORD dwClusterIPAddressIn,
            /* [in] */ const DWORD dwClusterIPSubnetMaskIn,
            /* [string][in] */ const WCHAR *pcszClusterIPNetworkIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetForm( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetJoin( 
            /* [string][in] */ const WCHAR *pcszClusterNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetJoin( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_SetCleanup( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetCleanup( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Commit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Commit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Rollback( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Rollback( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgBaseClusterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgBaseCluster * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgBaseCluster * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetForm )( 
            AsyncIClusCfgBaseCluster * This,
            /* [string][in] */ const WCHAR *pcszClusterNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn,
            /* [in] */ const DWORD dwClusterIPAddressIn,
            /* [in] */ const DWORD dwClusterIPSubnetMaskIn,
            /* [string][in] */ const WCHAR *pcszClusterIPNetworkIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetForm )( 
            AsyncIClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetJoin )( 
            AsyncIClusCfgBaseCluster * This,
            /* [string][in] */ const WCHAR *pcszClusterNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
            /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetJoin )( 
            AsyncIClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetCleanup )( 
            AsyncIClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetCleanup )( 
            AsyncIClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Commit )( 
            AsyncIClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Commit )( 
            AsyncIClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Rollback )( 
            AsyncIClusCfgBaseCluster * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Rollback )( 
            AsyncIClusCfgBaseCluster * This);
        
        END_INTERFACE
    } AsyncIClusCfgBaseClusterVtbl;

    interface AsyncIClusCfgBaseCluster
    {
        CONST_VTBL struct AsyncIClusCfgBaseClusterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgBaseCluster_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgBaseCluster_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgBaseCluster_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgBaseCluster_Begin_SetForm(This,pcszClusterNameIn,pcszClusterAccountNameIn,pcszClusterAccountPwdIn,pcszClusterAccountDomainIn,dwClusterIPAddressIn,dwClusterIPSubnetMaskIn,pcszClusterIPNetworkIn)	\
    (This)->lpVtbl -> Begin_SetForm(This,pcszClusterNameIn,pcszClusterAccountNameIn,pcszClusterAccountPwdIn,pcszClusterAccountDomainIn,dwClusterIPAddressIn,dwClusterIPSubnetMaskIn,pcszClusterIPNetworkIn)

#define AsyncIClusCfgBaseCluster_Finish_SetForm(This)	\
    (This)->lpVtbl -> Finish_SetForm(This)

#define AsyncIClusCfgBaseCluster_Begin_SetJoin(This,pcszClusterNameIn,pcszClusterAccountNameIn,pcszClusterAccountPwdIn,pcszClusterAccountDomainIn)	\
    (This)->lpVtbl -> Begin_SetJoin(This,pcszClusterNameIn,pcszClusterAccountNameIn,pcszClusterAccountPwdIn,pcszClusterAccountDomainIn)

#define AsyncIClusCfgBaseCluster_Finish_SetJoin(This)	\
    (This)->lpVtbl -> Finish_SetJoin(This)

#define AsyncIClusCfgBaseCluster_Begin_SetCleanup(This)	\
    (This)->lpVtbl -> Begin_SetCleanup(This)

#define AsyncIClusCfgBaseCluster_Finish_SetCleanup(This)	\
    (This)->lpVtbl -> Finish_SetCleanup(This)

#define AsyncIClusCfgBaseCluster_Begin_Commit(This)	\
    (This)->lpVtbl -> Begin_Commit(This)

#define AsyncIClusCfgBaseCluster_Finish_Commit(This)	\
    (This)->lpVtbl -> Finish_Commit(This)

#define AsyncIClusCfgBaseCluster_Begin_Rollback(This)	\
    (This)->lpVtbl -> Begin_Rollback(This)

#define AsyncIClusCfgBaseCluster_Finish_Rollback(This)	\
    (This)->lpVtbl -> Finish_Rollback(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgBaseCluster_Begin_SetForm_Proxy( 
    AsyncIClusCfgBaseCluster * This,
    /* [string][in] */ const WCHAR *pcszClusterNameIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn,
    /* [in] */ const DWORD dwClusterIPAddressIn,
    /* [in] */ const DWORD dwClusterIPSubnetMaskIn,
    /* [string][in] */ const WCHAR *pcszClusterIPNetworkIn);


void __RPC_STUB AsyncIClusCfgBaseCluster_Begin_SetForm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgBaseCluster_Finish_SetForm_Proxy( 
    AsyncIClusCfgBaseCluster * This);


void __RPC_STUB AsyncIClusCfgBaseCluster_Finish_SetForm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgBaseCluster_Begin_SetJoin_Proxy( 
    AsyncIClusCfgBaseCluster * This,
    /* [string][in] */ const WCHAR *pcszClusterNameIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountNameIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountPwdIn,
    /* [string][in] */ const WCHAR *pcszClusterAccountDomainIn);


void __RPC_STUB AsyncIClusCfgBaseCluster_Begin_SetJoin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgBaseCluster_Finish_SetJoin_Proxy( 
    AsyncIClusCfgBaseCluster * This);


void __RPC_STUB AsyncIClusCfgBaseCluster_Finish_SetJoin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgBaseCluster_Begin_SetCleanup_Proxy( 
    AsyncIClusCfgBaseCluster * This);


void __RPC_STUB AsyncIClusCfgBaseCluster_Begin_SetCleanup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgBaseCluster_Finish_SetCleanup_Proxy( 
    AsyncIClusCfgBaseCluster * This);


void __RPC_STUB AsyncIClusCfgBaseCluster_Finish_SetCleanup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgBaseCluster_Begin_Commit_Proxy( 
    AsyncIClusCfgBaseCluster * This);


void __RPC_STUB AsyncIClusCfgBaseCluster_Begin_Commit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgBaseCluster_Finish_Commit_Proxy( 
    AsyncIClusCfgBaseCluster * This);


void __RPC_STUB AsyncIClusCfgBaseCluster_Finish_Commit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgBaseCluster_Begin_Rollback_Proxy( 
    AsyncIClusCfgBaseCluster * This);


void __RPC_STUB AsyncIClusCfgBaseCluster_Begin_Rollback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgBaseCluster_Finish_Rollback_Proxy( 
    AsyncIClusCfgBaseCluster * This);


void __RPC_STUB AsyncIClusCfgBaseCluster_Finish_Rollback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgBaseCluster_INTERFACE_DEFINED__ */


#ifndef __IClusCfgCredentials_INTERFACE_DEFINED__
#define __IClusCfgCredentials_INTERFACE_DEFINED__

/* interface IClusCfgCredentials */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgCredentials;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54AA9406-A409-4b49-B314-5F0A0CE4C88E")
    IClusCfgCredentials : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetCredentials( 
            /* [in] */ BSTR bstrUserIn,
            /* [in] */ BSTR bstrDomainIn,
            /* [in] */ BSTR bstrPasswordIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCredentials( 
            /* [out] */ BSTR *pbstrUserOut,
            /* [out] */ BSTR *pbstrDomainOut,
            /* [out] */ BSTR *pbstrPasswordOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgCredentialsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgCredentials * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgCredentials * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgCredentials * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetCredentials )( 
            IClusCfgCredentials * This,
            /* [in] */ BSTR bstrUserIn,
            /* [in] */ BSTR bstrDomainIn,
            /* [in] */ BSTR bstrPasswordIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetCredentials )( 
            IClusCfgCredentials * This,
            /* [out] */ BSTR *pbstrUserOut,
            /* [out] */ BSTR *pbstrDomainOut,
            /* [out] */ BSTR *pbstrPasswordOut);
        
        END_INTERFACE
    } IClusCfgCredentialsVtbl;

    interface IClusCfgCredentials
    {
        CONST_VTBL struct IClusCfgCredentialsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgCredentials_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgCredentials_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgCredentials_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgCredentials_SetCredentials(This,bstrUserIn,bstrDomainIn,bstrPasswordIn)	\
    (This)->lpVtbl -> SetCredentials(This,bstrUserIn,bstrDomainIn,bstrPasswordIn)

#define IClusCfgCredentials_GetCredentials(This,pbstrUserOut,pbstrDomainOut,pbstrPasswordOut)	\
    (This)->lpVtbl -> GetCredentials(This,pbstrUserOut,pbstrDomainOut,pbstrPasswordOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgCredentials_SetCredentials_Proxy( 
    IClusCfgCredentials * This,
    /* [in] */ BSTR bstrUserIn,
    /* [in] */ BSTR bstrDomainIn,
    /* [in] */ BSTR bstrPasswordIn);


void __RPC_STUB IClusCfgCredentials_SetCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgCredentials_GetCredentials_Proxy( 
    IClusCfgCredentials * This,
    /* [out] */ BSTR *pbstrUserOut,
    /* [out] */ BSTR *pbstrDomainOut,
    /* [out] */ BSTR *pbstrPasswordOut);


void __RPC_STUB IClusCfgCredentials_GetCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgCredentials_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgCredentials_INTERFACE_DEFINED__
#define __AsyncIClusCfgCredentials_INTERFACE_DEFINED__

/* interface AsyncIClusCfgCredentials */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgCredentials;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54AA9406-A409-4b49-B314-5F0A0CE4C88F")
    AsyncIClusCfgCredentials : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_SetCredentials( 
            /* [in] */ BSTR bstrUserIn,
            /* [in] */ BSTR bstrDomainIn,
            /* [in] */ BSTR bstrPasswordIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SetCredentials( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetCredentials( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetCredentials( 
            /* [out] */ BSTR *pbstrUserOut,
            /* [out] */ BSTR *pbstrDomainOut,
            /* [out] */ BSTR *pbstrPasswordOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgCredentialsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgCredentials * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgCredentials * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgCredentials * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SetCredentials )( 
            AsyncIClusCfgCredentials * This,
            /* [in] */ BSTR bstrUserIn,
            /* [in] */ BSTR bstrDomainIn,
            /* [in] */ BSTR bstrPasswordIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SetCredentials )( 
            AsyncIClusCfgCredentials * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetCredentials )( 
            AsyncIClusCfgCredentials * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetCredentials )( 
            AsyncIClusCfgCredentials * This,
            /* [out] */ BSTR *pbstrUserOut,
            /* [out] */ BSTR *pbstrDomainOut,
            /* [out] */ BSTR *pbstrPasswordOut);
        
        END_INTERFACE
    } AsyncIClusCfgCredentialsVtbl;

    interface AsyncIClusCfgCredentials
    {
        CONST_VTBL struct AsyncIClusCfgCredentialsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgCredentials_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgCredentials_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgCredentials_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgCredentials_Begin_SetCredentials(This,bstrUserIn,bstrDomainIn,bstrPasswordIn)	\
    (This)->lpVtbl -> Begin_SetCredentials(This,bstrUserIn,bstrDomainIn,bstrPasswordIn)

#define AsyncIClusCfgCredentials_Finish_SetCredentials(This)	\
    (This)->lpVtbl -> Finish_SetCredentials(This)

#define AsyncIClusCfgCredentials_Begin_GetCredentials(This)	\
    (This)->lpVtbl -> Begin_GetCredentials(This)

#define AsyncIClusCfgCredentials_Finish_GetCredentials(This,pbstrUserOut,pbstrDomainOut,pbstrPasswordOut)	\
    (This)->lpVtbl -> Finish_GetCredentials(This,pbstrUserOut,pbstrDomainOut,pbstrPasswordOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgCredentials_Begin_SetCredentials_Proxy( 
    AsyncIClusCfgCredentials * This,
    /* [in] */ BSTR bstrUserIn,
    /* [in] */ BSTR bstrDomainIn,
    /* [in] */ BSTR bstrPasswordIn);


void __RPC_STUB AsyncIClusCfgCredentials_Begin_SetCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgCredentials_Finish_SetCredentials_Proxy( 
    AsyncIClusCfgCredentials * This);


void __RPC_STUB AsyncIClusCfgCredentials_Finish_SetCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgCredentials_Begin_GetCredentials_Proxy( 
    AsyncIClusCfgCredentials * This);


void __RPC_STUB AsyncIClusCfgCredentials_Begin_GetCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgCredentials_Finish_GetCredentials_Proxy( 
    AsyncIClusCfgCredentials * This,
    /* [out] */ BSTR *pbstrUserOut,
    /* [out] */ BSTR *pbstrDomainOut,
    /* [out] */ BSTR *pbstrPasswordOut);


void __RPC_STUB AsyncIClusCfgCredentials_Finish_GetCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgCredentials_INTERFACE_DEFINED__ */


#ifndef __IClusCfgCapabilities_INTERFACE_DEFINED__
#define __IClusCfgCapabilities_INTERFACE_DEFINED__

/* interface IClusCfgCapabilities */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgCapabilities;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D94AB253-36C7-41c1-B52E-26B451975C8D")
    IClusCfgCapabilities : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CanNodeBeClustered( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgCapabilitiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgCapabilities * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgCapabilities * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgCapabilities * This);
        
        HRESULT ( STDMETHODCALLTYPE *CanNodeBeClustered )( 
            IClusCfgCapabilities * This);
        
        END_INTERFACE
    } IClusCfgCapabilitiesVtbl;

    interface IClusCfgCapabilities
    {
        CONST_VTBL struct IClusCfgCapabilitiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgCapabilities_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgCapabilities_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgCapabilities_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgCapabilities_CanNodeBeClustered(This)	\
    (This)->lpVtbl -> CanNodeBeClustered(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgCapabilities_CanNodeBeClustered_Proxy( 
    IClusCfgCapabilities * This);


void __RPC_STUB IClusCfgCapabilities_CanNodeBeClustered_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgCapabilities_INTERFACE_DEFINED__ */


#ifndef __IClusCfgManagedResourceCfg_INTERFACE_DEFINED__
#define __IClusCfgManagedResourceCfg_INTERFACE_DEFINED__

/* interface IClusCfgManagedResourceCfg */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgManagedResourceCfg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60300A0F-77E1-440c-BD94-6BFB0DBFDB3A")
    IClusCfgManagedResourceCfg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PreCreate( 
            IUnknown *punkServicesIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Create( 
            IUnknown *punkServicesIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PostCreate( 
            IUnknown *punkServicesIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Evict( 
            IUnknown *punkServicesIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgManagedResourceCfgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgManagedResourceCfg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgManagedResourceCfg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgManagedResourceCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *PreCreate )( 
            IClusCfgManagedResourceCfg * This,
            IUnknown *punkServicesIn);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            IClusCfgManagedResourceCfg * This,
            IUnknown *punkServicesIn);
        
        HRESULT ( STDMETHODCALLTYPE *PostCreate )( 
            IClusCfgManagedResourceCfg * This,
            IUnknown *punkServicesIn);
        
        HRESULT ( STDMETHODCALLTYPE *Evict )( 
            IClusCfgManagedResourceCfg * This,
            IUnknown *punkServicesIn);
        
        END_INTERFACE
    } IClusCfgManagedResourceCfgVtbl;

    interface IClusCfgManagedResourceCfg
    {
        CONST_VTBL struct IClusCfgManagedResourceCfgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgManagedResourceCfg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgManagedResourceCfg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgManagedResourceCfg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgManagedResourceCfg_PreCreate(This,punkServicesIn)	\
    (This)->lpVtbl -> PreCreate(This,punkServicesIn)

#define IClusCfgManagedResourceCfg_Create(This,punkServicesIn)	\
    (This)->lpVtbl -> Create(This,punkServicesIn)

#define IClusCfgManagedResourceCfg_PostCreate(This,punkServicesIn)	\
    (This)->lpVtbl -> PostCreate(This,punkServicesIn)

#define IClusCfgManagedResourceCfg_Evict(This,punkServicesIn)	\
    (This)->lpVtbl -> Evict(This,punkServicesIn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceCfg_PreCreate_Proxy( 
    IClusCfgManagedResourceCfg * This,
    IUnknown *punkServicesIn);


void __RPC_STUB IClusCfgManagedResourceCfg_PreCreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceCfg_Create_Proxy( 
    IClusCfgManagedResourceCfg * This,
    IUnknown *punkServicesIn);


void __RPC_STUB IClusCfgManagedResourceCfg_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceCfg_PostCreate_Proxy( 
    IClusCfgManagedResourceCfg * This,
    IUnknown *punkServicesIn);


void __RPC_STUB IClusCfgManagedResourceCfg_PostCreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgManagedResourceCfg_Evict_Proxy( 
    IClusCfgManagedResourceCfg * This,
    IUnknown *punkServicesIn);


void __RPC_STUB IClusCfgManagedResourceCfg_Evict_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgManagedResourceCfg_INTERFACE_DEFINED__ */


#ifndef __IClusCfgResourcePreCreate_INTERFACE_DEFINED__
#define __IClusCfgResourcePreCreate_INTERFACE_DEFINED__

/* interface IClusCfgResourcePreCreate */
/* [unique][local][uuid][object] */ 

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("1DAF9692-6662-43b1-AD45-D50F7849B0CD") 
enum EDependencyFlags
    {	dfUNKNOWN	= 0,
	dfSHARED	= 1,
	dfEXCLUSIVE	= 2
    } 	EDependencyFlags;


EXTERN_C const IID IID_IClusCfgResourcePreCreate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4240F6A1-9D49-427e-8F3D-09384E1F59E4")
    IClusCfgResourcePreCreate : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetDependency( 
            LPCLSID pclsidDepResTypeIn,
            DWORD dfIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetType( 
            CLSID *pclsidIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetClassType( 
            CLSID *pclsidIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgResourcePreCreateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgResourcePreCreate * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgResourcePreCreate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgResourcePreCreate * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDependency )( 
            IClusCfgResourcePreCreate * This,
            LPCLSID pclsidDepResTypeIn,
            DWORD dfIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetType )( 
            IClusCfgResourcePreCreate * This,
            CLSID *pclsidIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetClassType )( 
            IClusCfgResourcePreCreate * This,
            CLSID *pclsidIn);
        
        END_INTERFACE
    } IClusCfgResourcePreCreateVtbl;

    interface IClusCfgResourcePreCreate
    {
        CONST_VTBL struct IClusCfgResourcePreCreateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgResourcePreCreate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgResourcePreCreate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgResourcePreCreate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgResourcePreCreate_SetDependency(This,pclsidDepResTypeIn,dfIn)	\
    (This)->lpVtbl -> SetDependency(This,pclsidDepResTypeIn,dfIn)

#define IClusCfgResourcePreCreate_SetType(This,pclsidIn)	\
    (This)->lpVtbl -> SetType(This,pclsidIn)

#define IClusCfgResourcePreCreate_SetClassType(This,pclsidIn)	\
    (This)->lpVtbl -> SetClassType(This,pclsidIn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgResourcePreCreate_SetDependency_Proxy( 
    IClusCfgResourcePreCreate * This,
    LPCLSID pclsidDepResTypeIn,
    DWORD dfIn);


void __RPC_STUB IClusCfgResourcePreCreate_SetDependency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourcePreCreate_SetType_Proxy( 
    IClusCfgResourcePreCreate * This,
    CLSID *pclsidIn);


void __RPC_STUB IClusCfgResourcePreCreate_SetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourcePreCreate_SetClassType_Proxy( 
    IClusCfgResourcePreCreate * This,
    CLSID *pclsidIn);


void __RPC_STUB IClusCfgResourcePreCreate_SetClassType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgResourcePreCreate_INTERFACE_DEFINED__ */


#ifndef __IClusCfgResourceCreate_INTERFACE_DEFINED__
#define __IClusCfgResourceCreate_INTERFACE_DEFINED__

/* interface IClusCfgResourceCreate */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgResourceCreate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0647B41A-C777-443c-9432-02CCCF4FF443")
    IClusCfgResourceCreate : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPropertyBinary( 
            LPCWSTR pcszNameIn,
            const DWORD cbSizeIn,
            const BYTE *pbyteIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyDWORD( 
            LPCWSTR pcszNameIn,
            const DWORD dwDWORDIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyString( 
            LPCWSTR pcszNameIn,
            LPCWSTR pcszStringIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyExpandString( 
            LPCWSTR pcszNameIn,
            LPCWSTR pcszStringIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyMultiString( 
            LPCWSTR pcszNameIn,
            const DWORD cbMultiStringIn,
            LPCWSTR pcszMultiStringIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyUnsignedLargeInt( 
            LPCWSTR pcszNameIn,
            const ULARGE_INTEGER ulIntIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyLong( 
            LPCWSTR pcszNameIn,
            const LONG lLongIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertySecurityDescriptor( 
            LPCWSTR pcszNameIn,
            const SECURITY_DESCRIPTOR *pcsdIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyLargeInt( 
            LPCWSTR pcszNameIn,
            const LARGE_INTEGER lIntIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendResourceControl( 
            DWORD dwControlCode,
            LPVOID lpInBuffer,
            DWORD cbInBufferSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgResourceCreateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgResourceCreate * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgResourceCreate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgResourceCreate * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyBinary )( 
            IClusCfgResourceCreate * This,
            LPCWSTR pcszNameIn,
            const DWORD cbSizeIn,
            const BYTE *pbyteIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyDWORD )( 
            IClusCfgResourceCreate * This,
            LPCWSTR pcszNameIn,
            const DWORD dwDWORDIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            IClusCfgResourceCreate * This,
            LPCWSTR pcszNameIn,
            LPCWSTR pcszStringIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyExpandString )( 
            IClusCfgResourceCreate * This,
            LPCWSTR pcszNameIn,
            LPCWSTR pcszStringIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyMultiString )( 
            IClusCfgResourceCreate * This,
            LPCWSTR pcszNameIn,
            const DWORD cbMultiStringIn,
            LPCWSTR pcszMultiStringIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyUnsignedLargeInt )( 
            IClusCfgResourceCreate * This,
            LPCWSTR pcszNameIn,
            const ULARGE_INTEGER ulIntIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyLong )( 
            IClusCfgResourceCreate * This,
            LPCWSTR pcszNameIn,
            const LONG lLongIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertySecurityDescriptor )( 
            IClusCfgResourceCreate * This,
            LPCWSTR pcszNameIn,
            const SECURITY_DESCRIPTOR *pcsdIn);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyLargeInt )( 
            IClusCfgResourceCreate * This,
            LPCWSTR pcszNameIn,
            const LARGE_INTEGER lIntIn);
        
        HRESULT ( STDMETHODCALLTYPE *SendResourceControl )( 
            IClusCfgResourceCreate * This,
            DWORD dwControlCode,
            LPVOID lpInBuffer,
            DWORD cbInBufferSize);
        
        END_INTERFACE
    } IClusCfgResourceCreateVtbl;

    interface IClusCfgResourceCreate
    {
        CONST_VTBL struct IClusCfgResourceCreateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgResourceCreate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgResourceCreate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgResourceCreate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgResourceCreate_SetPropertyBinary(This,pcszNameIn,cbSizeIn,pbyteIn)	\
    (This)->lpVtbl -> SetPropertyBinary(This,pcszNameIn,cbSizeIn,pbyteIn)

#define IClusCfgResourceCreate_SetPropertyDWORD(This,pcszNameIn,dwDWORDIn)	\
    (This)->lpVtbl -> SetPropertyDWORD(This,pcszNameIn,dwDWORDIn)

#define IClusCfgResourceCreate_SetPropertyString(This,pcszNameIn,pcszStringIn)	\
    (This)->lpVtbl -> SetPropertyString(This,pcszNameIn,pcszStringIn)

#define IClusCfgResourceCreate_SetPropertyExpandString(This,pcszNameIn,pcszStringIn)	\
    (This)->lpVtbl -> SetPropertyExpandString(This,pcszNameIn,pcszStringIn)

#define IClusCfgResourceCreate_SetPropertyMultiString(This,pcszNameIn,cbMultiStringIn,pcszMultiStringIn)	\
    (This)->lpVtbl -> SetPropertyMultiString(This,pcszNameIn,cbMultiStringIn,pcszMultiStringIn)

#define IClusCfgResourceCreate_SetPropertyUnsignedLargeInt(This,pcszNameIn,ulIntIn)	\
    (This)->lpVtbl -> SetPropertyUnsignedLargeInt(This,pcszNameIn,ulIntIn)

#define IClusCfgResourceCreate_SetPropertyLong(This,pcszNameIn,lLongIn)	\
    (This)->lpVtbl -> SetPropertyLong(This,pcszNameIn,lLongIn)

#define IClusCfgResourceCreate_SetPropertySecurityDescriptor(This,pcszNameIn,pcsdIn)	\
    (This)->lpVtbl -> SetPropertySecurityDescriptor(This,pcszNameIn,pcsdIn)

#define IClusCfgResourceCreate_SetPropertyLargeInt(This,pcszNameIn,lIntIn)	\
    (This)->lpVtbl -> SetPropertyLargeInt(This,pcszNameIn,lIntIn)

#define IClusCfgResourceCreate_SendResourceControl(This,dwControlCode,lpInBuffer,cbInBufferSize)	\
    (This)->lpVtbl -> SendResourceControl(This,dwControlCode,lpInBuffer,cbInBufferSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgResourceCreate_SetPropertyBinary_Proxy( 
    IClusCfgResourceCreate * This,
    LPCWSTR pcszNameIn,
    const DWORD cbSizeIn,
    const BYTE *pbyteIn);


void __RPC_STUB IClusCfgResourceCreate_SetPropertyBinary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceCreate_SetPropertyDWORD_Proxy( 
    IClusCfgResourceCreate * This,
    LPCWSTR pcszNameIn,
    const DWORD dwDWORDIn);


void __RPC_STUB IClusCfgResourceCreate_SetPropertyDWORD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceCreate_SetPropertyString_Proxy( 
    IClusCfgResourceCreate * This,
    LPCWSTR pcszNameIn,
    LPCWSTR pcszStringIn);


void __RPC_STUB IClusCfgResourceCreate_SetPropertyString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceCreate_SetPropertyExpandString_Proxy( 
    IClusCfgResourceCreate * This,
    LPCWSTR pcszNameIn,
    LPCWSTR pcszStringIn);


void __RPC_STUB IClusCfgResourceCreate_SetPropertyExpandString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceCreate_SetPropertyMultiString_Proxy( 
    IClusCfgResourceCreate * This,
    LPCWSTR pcszNameIn,
    const DWORD cbMultiStringIn,
    LPCWSTR pcszMultiStringIn);


void __RPC_STUB IClusCfgResourceCreate_SetPropertyMultiString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceCreate_SetPropertyUnsignedLargeInt_Proxy( 
    IClusCfgResourceCreate * This,
    LPCWSTR pcszNameIn,
    const ULARGE_INTEGER ulIntIn);


void __RPC_STUB IClusCfgResourceCreate_SetPropertyUnsignedLargeInt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceCreate_SetPropertyLong_Proxy( 
    IClusCfgResourceCreate * This,
    LPCWSTR pcszNameIn,
    const LONG lLongIn);


void __RPC_STUB IClusCfgResourceCreate_SetPropertyLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceCreate_SetPropertySecurityDescriptor_Proxy( 
    IClusCfgResourceCreate * This,
    LPCWSTR pcszNameIn,
    const SECURITY_DESCRIPTOR *pcsdIn);


void __RPC_STUB IClusCfgResourceCreate_SetPropertySecurityDescriptor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceCreate_SetPropertyLargeInt_Proxy( 
    IClusCfgResourceCreate * This,
    LPCWSTR pcszNameIn,
    const LARGE_INTEGER lIntIn);


void __RPC_STUB IClusCfgResourceCreate_SetPropertyLargeInt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceCreate_SendResourceControl_Proxy( 
    IClusCfgResourceCreate * This,
    DWORD dwControlCode,
    LPVOID lpInBuffer,
    DWORD cbInBufferSize);


void __RPC_STUB IClusCfgResourceCreate_SendResourceControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgResourceCreate_INTERFACE_DEFINED__ */


#ifndef __IClusCfgResourcePostCreate_INTERFACE_DEFINED__
#define __IClusCfgResourcePostCreate_INTERFACE_DEFINED__

/* interface IClusCfgResourcePostCreate */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgResourcePostCreate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72A9BF54-13B6-451f-910D-6913EBF025AB")
    IClusCfgResourcePostCreate : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ChangeName( 
            LPCWSTR pcszNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendResourceControl( 
            DWORD dwControlCode,
            LPVOID lpInBuffer,
            DWORD cbInBufferSize,
            LPVOID lpOutBuffer,
            DWORD cbOutBufferSize,
            LPDWORD lpcbBytesReturned) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgResourcePostCreateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgResourcePostCreate * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgResourcePostCreate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgResourcePostCreate * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChangeName )( 
            IClusCfgResourcePostCreate * This,
            LPCWSTR pcszNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *SendResourceControl )( 
            IClusCfgResourcePostCreate * This,
            DWORD dwControlCode,
            LPVOID lpInBuffer,
            DWORD cbInBufferSize,
            LPVOID lpOutBuffer,
            DWORD cbOutBufferSize,
            LPDWORD lpcbBytesReturned);
        
        END_INTERFACE
    } IClusCfgResourcePostCreateVtbl;

    interface IClusCfgResourcePostCreate
    {
        CONST_VTBL struct IClusCfgResourcePostCreateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgResourcePostCreate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgResourcePostCreate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgResourcePostCreate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgResourcePostCreate_ChangeName(This,pcszNameIn)	\
    (This)->lpVtbl -> ChangeName(This,pcszNameIn)

#define IClusCfgResourcePostCreate_SendResourceControl(This,dwControlCode,lpInBuffer,cbInBufferSize,lpOutBuffer,cbOutBufferSize,lpcbBytesReturned)	\
    (This)->lpVtbl -> SendResourceControl(This,dwControlCode,lpInBuffer,cbInBufferSize,lpOutBuffer,cbOutBufferSize,lpcbBytesReturned)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgResourcePostCreate_ChangeName_Proxy( 
    IClusCfgResourcePostCreate * This,
    LPCWSTR pcszNameIn);


void __RPC_STUB IClusCfgResourcePostCreate_ChangeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourcePostCreate_SendResourceControl_Proxy( 
    IClusCfgResourcePostCreate * This,
    DWORD dwControlCode,
    LPVOID lpInBuffer,
    DWORD cbInBufferSize,
    LPVOID lpOutBuffer,
    DWORD cbOutBufferSize,
    LPDWORD lpcbBytesReturned);


void __RPC_STUB IClusCfgResourcePostCreate_SendResourceControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgResourcePostCreate_INTERFACE_DEFINED__ */


#ifndef __IClusCfgResourceEvict_INTERFACE_DEFINED__
#define __IClusCfgResourceEvict_INTERFACE_DEFINED__

/* interface IClusCfgResourceEvict */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgResourceEvict;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("801CB97D-F45C-40cb-9E8C-6982348BD6CB")
    IClusCfgResourceEvict : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DoSomethingCool( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgResourceEvictVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgResourceEvict * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgResourceEvict * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgResourceEvict * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoSomethingCool )( 
            IClusCfgResourceEvict * This);
        
        END_INTERFACE
    } IClusCfgResourceEvictVtbl;

    interface IClusCfgResourceEvict
    {
        CONST_VTBL struct IClusCfgResourceEvictVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgResourceEvict_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgResourceEvict_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgResourceEvict_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgResourceEvict_DoSomethingCool(This)	\
    (This)->lpVtbl -> DoSomethingCool(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgResourceEvict_DoSomethingCool_Proxy( 
    IClusCfgResourceEvict * This);


void __RPC_STUB IClusCfgResourceEvict_DoSomethingCool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgResourceEvict_INTERFACE_DEFINED__ */


#ifndef __IClusCfgGroupCfg_INTERFACE_DEFINED__
#define __IClusCfgGroupCfg_INTERFACE_DEFINED__

/* interface IClusCfgGroupCfg */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgGroupCfg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB6D3D2-A55F-49e5-A64A-0CCFEB01ED3A")
    IClusCfgGroupCfg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            LPCWSTR pcszNameIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            DWORD *pcbSizeInout,
            LPWSTR pszNameOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgGroupCfgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgGroupCfg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgGroupCfg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgGroupCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IClusCfgGroupCfg * This,
            LPCWSTR pcszNameIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IClusCfgGroupCfg * This,
            DWORD *pcbSizeInout,
            LPWSTR pszNameOut);
        
        END_INTERFACE
    } IClusCfgGroupCfgVtbl;

    interface IClusCfgGroupCfg
    {
        CONST_VTBL struct IClusCfgGroupCfgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgGroupCfg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgGroupCfg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgGroupCfg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgGroupCfg_SetName(This,pcszNameIn)	\
    (This)->lpVtbl -> SetName(This,pcszNameIn)

#define IClusCfgGroupCfg_GetName(This,pcbSizeInout,pszNameOut)	\
    (This)->lpVtbl -> GetName(This,pcbSizeInout,pszNameOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgGroupCfg_SetName_Proxy( 
    IClusCfgGroupCfg * This,
    LPCWSTR pcszNameIn);


void __RPC_STUB IClusCfgGroupCfg_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgGroupCfg_GetName_Proxy( 
    IClusCfgGroupCfg * This,
    DWORD *pcbSizeInout,
    LPWSTR pszNameOut);


void __RPC_STUB IClusCfgGroupCfg_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgGroupCfg_INTERFACE_DEFINED__ */


#ifndef __IClusCfgMemberSetChangeListener_INTERFACE_DEFINED__
#define __IClusCfgMemberSetChangeListener_INTERFACE_DEFINED__

/* interface IClusCfgMemberSetChangeListener */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgMemberSetChangeListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2B64534F-2643-4ABC-A4E5-824D881B7582")
    IClusCfgMemberSetChangeListener : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Notify( 
            /* [in] */ IUnknown *punkClusterInfoIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgMemberSetChangeListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgMemberSetChangeListener * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgMemberSetChangeListener * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgMemberSetChangeListener * This);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            IClusCfgMemberSetChangeListener * This,
            /* [in] */ IUnknown *punkClusterInfoIn);
        
        END_INTERFACE
    } IClusCfgMemberSetChangeListenerVtbl;

    interface IClusCfgMemberSetChangeListener
    {
        CONST_VTBL struct IClusCfgMemberSetChangeListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgMemberSetChangeListener_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgMemberSetChangeListener_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgMemberSetChangeListener_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgMemberSetChangeListener_Notify(This,punkClusterInfoIn)	\
    (This)->lpVtbl -> Notify(This,punkClusterInfoIn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgMemberSetChangeListener_Notify_Proxy( 
    IClusCfgMemberSetChangeListener * This,
    /* [in] */ IUnknown *punkClusterInfoIn);


void __RPC_STUB IClusCfgMemberSetChangeListener_Notify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgMemberSetChangeListener_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgMemberSetChangeListener_INTERFACE_DEFINED__
#define __AsyncIClusCfgMemberSetChangeListener_INTERFACE_DEFINED__

/* interface AsyncIClusCfgMemberSetChangeListener */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgMemberSetChangeListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2B645350-2643-4ABC-A4E5-824D881B7582")
    AsyncIClusCfgMemberSetChangeListener : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Notify( 
            /* [in] */ IUnknown *punkClusterInfoIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Notify( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgMemberSetChangeListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgMemberSetChangeListener * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgMemberSetChangeListener * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgMemberSetChangeListener * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Notify )( 
            AsyncIClusCfgMemberSetChangeListener * This,
            /* [in] */ IUnknown *punkClusterInfoIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Notify )( 
            AsyncIClusCfgMemberSetChangeListener * This);
        
        END_INTERFACE
    } AsyncIClusCfgMemberSetChangeListenerVtbl;

    interface AsyncIClusCfgMemberSetChangeListener
    {
        CONST_VTBL struct AsyncIClusCfgMemberSetChangeListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgMemberSetChangeListener_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgMemberSetChangeListener_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgMemberSetChangeListener_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgMemberSetChangeListener_Begin_Notify(This,punkClusterInfoIn)	\
    (This)->lpVtbl -> Begin_Notify(This,punkClusterInfoIn)

#define AsyncIClusCfgMemberSetChangeListener_Finish_Notify(This)	\
    (This)->lpVtbl -> Finish_Notify(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgMemberSetChangeListener_Begin_Notify_Proxy( 
    AsyncIClusCfgMemberSetChangeListener * This,
    /* [in] */ IUnknown *punkClusterInfoIn);


void __RPC_STUB AsyncIClusCfgMemberSetChangeListener_Begin_Notify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgMemberSetChangeListener_Finish_Notify_Proxy( 
    AsyncIClusCfgMemberSetChangeListener * This);


void __RPC_STUB AsyncIClusCfgMemberSetChangeListener_Finish_Notify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgMemberSetChangeListener_INTERFACE_DEFINED__ */


#ifndef __IClusCfgResourceTypeInfo_INTERFACE_DEFINED__
#define __IClusCfgResourceTypeInfo_INTERFACE_DEFINED__

/* interface IClusCfgResourceTypeInfo */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgResourceTypeInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C649A281-C847-4F5C-9841-D2F73B5AA71D")
    IClusCfgResourceTypeInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CommitChanges( 
            /* [in] */ IUnknown *punkClusterInfoIn,
            /* [in] */ IUnknown *punkResTypeServicesIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTypeName( 
            /* [out] */ BSTR *pbstrTypeNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTypeGUID( 
            /* [out] */ GUID *pguidGUIDOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgResourceTypeInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgResourceTypeInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgResourceTypeInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgResourceTypeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *CommitChanges )( 
            IClusCfgResourceTypeInfo * This,
            /* [in] */ IUnknown *punkClusterInfoIn,
            /* [in] */ IUnknown *punkResTypeServicesIn);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeName )( 
            IClusCfgResourceTypeInfo * This,
            /* [out] */ BSTR *pbstrTypeNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeGUID )( 
            IClusCfgResourceTypeInfo * This,
            /* [out] */ GUID *pguidGUIDOut);
        
        END_INTERFACE
    } IClusCfgResourceTypeInfoVtbl;

    interface IClusCfgResourceTypeInfo
    {
        CONST_VTBL struct IClusCfgResourceTypeInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgResourceTypeInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgResourceTypeInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgResourceTypeInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgResourceTypeInfo_CommitChanges(This,punkClusterInfoIn,punkResTypeServicesIn)	\
    (This)->lpVtbl -> CommitChanges(This,punkClusterInfoIn,punkResTypeServicesIn)

#define IClusCfgResourceTypeInfo_GetTypeName(This,pbstrTypeNameOut)	\
    (This)->lpVtbl -> GetTypeName(This,pbstrTypeNameOut)

#define IClusCfgResourceTypeInfo_GetTypeGUID(This,pguidGUIDOut)	\
    (This)->lpVtbl -> GetTypeGUID(This,pguidGUIDOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgResourceTypeInfo_CommitChanges_Proxy( 
    IClusCfgResourceTypeInfo * This,
    /* [in] */ IUnknown *punkClusterInfoIn,
    /* [in] */ IUnknown *punkResTypeServicesIn);


void __RPC_STUB IClusCfgResourceTypeInfo_CommitChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceTypeInfo_GetTypeName_Proxy( 
    IClusCfgResourceTypeInfo * This,
    /* [out] */ BSTR *pbstrTypeNameOut);


void __RPC_STUB IClusCfgResourceTypeInfo_GetTypeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceTypeInfo_GetTypeGUID_Proxy( 
    IClusCfgResourceTypeInfo * This,
    /* [out] */ GUID *pguidGUIDOut);


void __RPC_STUB IClusCfgResourceTypeInfo_GetTypeGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgResourceTypeInfo_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgResourceTypeInfo_INTERFACE_DEFINED__
#define __AsyncIClusCfgResourceTypeInfo_INTERFACE_DEFINED__

/* interface AsyncIClusCfgResourceTypeInfo */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgResourceTypeInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C649A282-C847-4F5C-9841-D2F73B5AA71D")
    AsyncIClusCfgResourceTypeInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_CommitChanges( 
            /* [in] */ IUnknown *punkClusterInfoIn,
            /* [in] */ IUnknown *punkResTypeServicesIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_CommitChanges( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetTypeName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetTypeName( 
            /* [out] */ BSTR *pbstrTypeNameOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_GetTypeGUID( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_GetTypeGUID( 
            /* [out] */ GUID *pguidGUIDOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgResourceTypeInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgResourceTypeInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgResourceTypeInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgResourceTypeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_CommitChanges )( 
            AsyncIClusCfgResourceTypeInfo * This,
            /* [in] */ IUnknown *punkClusterInfoIn,
            /* [in] */ IUnknown *punkResTypeServicesIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_CommitChanges )( 
            AsyncIClusCfgResourceTypeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetTypeName )( 
            AsyncIClusCfgResourceTypeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetTypeName )( 
            AsyncIClusCfgResourceTypeInfo * This,
            /* [out] */ BSTR *pbstrTypeNameOut);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_GetTypeGUID )( 
            AsyncIClusCfgResourceTypeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_GetTypeGUID )( 
            AsyncIClusCfgResourceTypeInfo * This,
            /* [out] */ GUID *pguidGUIDOut);
        
        END_INTERFACE
    } AsyncIClusCfgResourceTypeInfoVtbl;

    interface AsyncIClusCfgResourceTypeInfo
    {
        CONST_VTBL struct AsyncIClusCfgResourceTypeInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgResourceTypeInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgResourceTypeInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgResourceTypeInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgResourceTypeInfo_Begin_CommitChanges(This,punkClusterInfoIn,punkResTypeServicesIn)	\
    (This)->lpVtbl -> Begin_CommitChanges(This,punkClusterInfoIn,punkResTypeServicesIn)

#define AsyncIClusCfgResourceTypeInfo_Finish_CommitChanges(This)	\
    (This)->lpVtbl -> Finish_CommitChanges(This)

#define AsyncIClusCfgResourceTypeInfo_Begin_GetTypeName(This)	\
    (This)->lpVtbl -> Begin_GetTypeName(This)

#define AsyncIClusCfgResourceTypeInfo_Finish_GetTypeName(This,pbstrTypeNameOut)	\
    (This)->lpVtbl -> Finish_GetTypeName(This,pbstrTypeNameOut)

#define AsyncIClusCfgResourceTypeInfo_Begin_GetTypeGUID(This)	\
    (This)->lpVtbl -> Begin_GetTypeGUID(This)

#define AsyncIClusCfgResourceTypeInfo_Finish_GetTypeGUID(This,pguidGUIDOut)	\
    (This)->lpVtbl -> Finish_GetTypeGUID(This,pguidGUIDOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgResourceTypeInfo_Begin_CommitChanges_Proxy( 
    AsyncIClusCfgResourceTypeInfo * This,
    /* [in] */ IUnknown *punkClusterInfoIn,
    /* [in] */ IUnknown *punkResTypeServicesIn);


void __RPC_STUB AsyncIClusCfgResourceTypeInfo_Begin_CommitChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgResourceTypeInfo_Finish_CommitChanges_Proxy( 
    AsyncIClusCfgResourceTypeInfo * This);


void __RPC_STUB AsyncIClusCfgResourceTypeInfo_Finish_CommitChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgResourceTypeInfo_Begin_GetTypeName_Proxy( 
    AsyncIClusCfgResourceTypeInfo * This);


void __RPC_STUB AsyncIClusCfgResourceTypeInfo_Begin_GetTypeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgResourceTypeInfo_Finish_GetTypeName_Proxy( 
    AsyncIClusCfgResourceTypeInfo * This,
    /* [out] */ BSTR *pbstrTypeNameOut);


void __RPC_STUB AsyncIClusCfgResourceTypeInfo_Finish_GetTypeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgResourceTypeInfo_Begin_GetTypeGUID_Proxy( 
    AsyncIClusCfgResourceTypeInfo * This);


void __RPC_STUB AsyncIClusCfgResourceTypeInfo_Begin_GetTypeGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgResourceTypeInfo_Finish_GetTypeGUID_Proxy( 
    AsyncIClusCfgResourceTypeInfo * This,
    /* [out] */ GUID *pguidGUIDOut);


void __RPC_STUB AsyncIClusCfgResourceTypeInfo_Finish_GetTypeGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgResourceTypeInfo_INTERFACE_DEFINED__ */


#ifndef __IClusCfgResourceTypeCreate_INTERFACE_DEFINED__
#define __IClusCfgResourceTypeCreate_INTERFACE_DEFINED__

/* interface IClusCfgResourceTypeCreate */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgResourceTypeCreate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AFCE3B8-5F3E-4DDF-A8F4-4B4FCBF28F8F")
    IClusCfgResourceTypeCreate : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [string][in] */ const WCHAR *pcszResTypeNameIn,
            /* [string][in] */ const WCHAR *pcszResTypeDisplayNameIn,
            /* [string][in] */ const WCHAR *pcszResDllNameIn,
            /* [in] */ DWORD dwLooksAliveIntervalIn,
            /* [in] */ DWORD dwIsAliveIntervalIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterAdminExtensions( 
            /* [string][in] */ const WCHAR *pcszResTypeNameIn,
            /* [in] */ ULONG cExtClsidCountIn,
            /* [size_is][in] */ const CLSID *rgclsidExtClsidsIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgResourceTypeCreateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgResourceTypeCreate * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgResourceTypeCreate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgResourceTypeCreate * This);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            IClusCfgResourceTypeCreate * This,
            /* [string][in] */ const WCHAR *pcszResTypeNameIn,
            /* [string][in] */ const WCHAR *pcszResTypeDisplayNameIn,
            /* [string][in] */ const WCHAR *pcszResDllNameIn,
            /* [in] */ DWORD dwLooksAliveIntervalIn,
            /* [in] */ DWORD dwIsAliveIntervalIn);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterAdminExtensions )( 
            IClusCfgResourceTypeCreate * This,
            /* [string][in] */ const WCHAR *pcszResTypeNameIn,
            /* [in] */ ULONG cExtClsidCountIn,
            /* [size_is][in] */ const CLSID *rgclsidExtClsidsIn);
        
        END_INTERFACE
    } IClusCfgResourceTypeCreateVtbl;

    interface IClusCfgResourceTypeCreate
    {
        CONST_VTBL struct IClusCfgResourceTypeCreateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgResourceTypeCreate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgResourceTypeCreate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgResourceTypeCreate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgResourceTypeCreate_Create(This,pcszResTypeNameIn,pcszResTypeDisplayNameIn,pcszResDllNameIn,dwLooksAliveIntervalIn,dwIsAliveIntervalIn)	\
    (This)->lpVtbl -> Create(This,pcszResTypeNameIn,pcszResTypeDisplayNameIn,pcszResDllNameIn,dwLooksAliveIntervalIn,dwIsAliveIntervalIn)

#define IClusCfgResourceTypeCreate_RegisterAdminExtensions(This,pcszResTypeNameIn,cExtClsidCountIn,rgclsidExtClsidsIn)	\
    (This)->lpVtbl -> RegisterAdminExtensions(This,pcszResTypeNameIn,cExtClsidCountIn,rgclsidExtClsidsIn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgResourceTypeCreate_Create_Proxy( 
    IClusCfgResourceTypeCreate * This,
    /* [string][in] */ const WCHAR *pcszResTypeNameIn,
    /* [string][in] */ const WCHAR *pcszResTypeDisplayNameIn,
    /* [string][in] */ const WCHAR *pcszResDllNameIn,
    /* [in] */ DWORD dwLooksAliveIntervalIn,
    /* [in] */ DWORD dwIsAliveIntervalIn);


void __RPC_STUB IClusCfgResourceTypeCreate_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgResourceTypeCreate_RegisterAdminExtensions_Proxy( 
    IClusCfgResourceTypeCreate * This,
    /* [string][in] */ const WCHAR *pcszResTypeNameIn,
    /* [in] */ ULONG cExtClsidCountIn,
    /* [size_is][in] */ const CLSID *rgclsidExtClsidsIn);


void __RPC_STUB IClusCfgResourceTypeCreate_RegisterAdminExtensions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgResourceTypeCreate_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgResourceTypeCreate_INTERFACE_DEFINED__
#define __AsyncIClusCfgResourceTypeCreate_INTERFACE_DEFINED__

/* interface AsyncIClusCfgResourceTypeCreate */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgResourceTypeCreate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AFCE3B9-5F3E-4DDF-A8F4-4B4FCBF28F8F")
    AsyncIClusCfgResourceTypeCreate : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Create( 
            /* [string][in] */ const WCHAR *pcszResTypeNameIn,
            /* [string][in] */ const WCHAR *pcszResTypeDisplayNameIn,
            /* [string][in] */ const WCHAR *pcszResDllNameIn,
            /* [in] */ DWORD dwLooksAliveIntervalIn,
            /* [in] */ DWORD dwIsAliveIntervalIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Create( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_RegisterAdminExtensions( 
            /* [string][in] */ const WCHAR *pcszResTypeNameIn,
            /* [in] */ ULONG cExtClsidCountIn,
            /* [size_is][in] */ const CLSID *rgclsidExtClsidsIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_RegisterAdminExtensions( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgResourceTypeCreateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgResourceTypeCreate * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgResourceTypeCreate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgResourceTypeCreate * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Create )( 
            AsyncIClusCfgResourceTypeCreate * This,
            /* [string][in] */ const WCHAR *pcszResTypeNameIn,
            /* [string][in] */ const WCHAR *pcszResTypeDisplayNameIn,
            /* [string][in] */ const WCHAR *pcszResDllNameIn,
            /* [in] */ DWORD dwLooksAliveIntervalIn,
            /* [in] */ DWORD dwIsAliveIntervalIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Create )( 
            AsyncIClusCfgResourceTypeCreate * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_RegisterAdminExtensions )( 
            AsyncIClusCfgResourceTypeCreate * This,
            /* [string][in] */ const WCHAR *pcszResTypeNameIn,
            /* [in] */ ULONG cExtClsidCountIn,
            /* [size_is][in] */ const CLSID *rgclsidExtClsidsIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_RegisterAdminExtensions )( 
            AsyncIClusCfgResourceTypeCreate * This);
        
        END_INTERFACE
    } AsyncIClusCfgResourceTypeCreateVtbl;

    interface AsyncIClusCfgResourceTypeCreate
    {
        CONST_VTBL struct AsyncIClusCfgResourceTypeCreateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgResourceTypeCreate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgResourceTypeCreate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgResourceTypeCreate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgResourceTypeCreate_Begin_Create(This,pcszResTypeNameIn,pcszResTypeDisplayNameIn,pcszResDllNameIn,dwLooksAliveIntervalIn,dwIsAliveIntervalIn)	\
    (This)->lpVtbl -> Begin_Create(This,pcszResTypeNameIn,pcszResTypeDisplayNameIn,pcszResDllNameIn,dwLooksAliveIntervalIn,dwIsAliveIntervalIn)

#define AsyncIClusCfgResourceTypeCreate_Finish_Create(This)	\
    (This)->lpVtbl -> Finish_Create(This)

#define AsyncIClusCfgResourceTypeCreate_Begin_RegisterAdminExtensions(This,pcszResTypeNameIn,cExtClsidCountIn,rgclsidExtClsidsIn)	\
    (This)->lpVtbl -> Begin_RegisterAdminExtensions(This,pcszResTypeNameIn,cExtClsidCountIn,rgclsidExtClsidsIn)

#define AsyncIClusCfgResourceTypeCreate_Finish_RegisterAdminExtensions(This)	\
    (This)->lpVtbl -> Finish_RegisterAdminExtensions(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgResourceTypeCreate_Begin_Create_Proxy( 
    AsyncIClusCfgResourceTypeCreate * This,
    /* [string][in] */ const WCHAR *pcszResTypeNameIn,
    /* [string][in] */ const WCHAR *pcszResTypeDisplayNameIn,
    /* [string][in] */ const WCHAR *pcszResDllNameIn,
    /* [in] */ DWORD dwLooksAliveIntervalIn,
    /* [in] */ DWORD dwIsAliveIntervalIn);


void __RPC_STUB AsyncIClusCfgResourceTypeCreate_Begin_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgResourceTypeCreate_Finish_Create_Proxy( 
    AsyncIClusCfgResourceTypeCreate * This);


void __RPC_STUB AsyncIClusCfgResourceTypeCreate_Finish_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgResourceTypeCreate_Begin_RegisterAdminExtensions_Proxy( 
    AsyncIClusCfgResourceTypeCreate * This,
    /* [string][in] */ const WCHAR *pcszResTypeNameIn,
    /* [in] */ ULONG cExtClsidCountIn,
    /* [size_is][in] */ const CLSID *rgclsidExtClsidsIn);


void __RPC_STUB AsyncIClusCfgResourceTypeCreate_Begin_RegisterAdminExtensions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgResourceTypeCreate_Finish_RegisterAdminExtensions_Proxy( 
    AsyncIClusCfgResourceTypeCreate * This);


void __RPC_STUB AsyncIClusCfgResourceTypeCreate_Finish_RegisterAdminExtensions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgResourceTypeCreate_INTERFACE_DEFINED__ */


#ifndef __IClusCfgEvictCleanup_INTERFACE_DEFINED__
#define __IClusCfgEvictCleanup_INTERFACE_DEFINED__

/* interface IClusCfgEvictCleanup */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgEvictCleanup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6FE3E361-D373-4C5F-A0AF-1DFE8493C655")
    IClusCfgEvictCleanup : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CleanupLocalNode( 
            /* [in] */ DWORD dwDelayIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CleanupRemoteNode( 
            /* [string][in] */ const WCHAR *pcszEvictedNodeNameIn,
            /* [in] */ DWORD dwDelayIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgEvictCleanupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgEvictCleanup * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgEvictCleanup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgEvictCleanup * This);
        
        HRESULT ( STDMETHODCALLTYPE *CleanupLocalNode )( 
            IClusCfgEvictCleanup * This,
            /* [in] */ DWORD dwDelayIn);
        
        HRESULT ( STDMETHODCALLTYPE *CleanupRemoteNode )( 
            IClusCfgEvictCleanup * This,
            /* [string][in] */ const WCHAR *pcszEvictedNodeNameIn,
            /* [in] */ DWORD dwDelayIn);
        
        END_INTERFACE
    } IClusCfgEvictCleanupVtbl;

    interface IClusCfgEvictCleanup
    {
        CONST_VTBL struct IClusCfgEvictCleanupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgEvictCleanup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgEvictCleanup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgEvictCleanup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgEvictCleanup_CleanupLocalNode(This,dwDelayIn)	\
    (This)->lpVtbl -> CleanupLocalNode(This,dwDelayIn)

#define IClusCfgEvictCleanup_CleanupRemoteNode(This,pcszEvictedNodeNameIn,dwDelayIn)	\
    (This)->lpVtbl -> CleanupRemoteNode(This,pcszEvictedNodeNameIn,dwDelayIn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgEvictCleanup_CleanupLocalNode_Proxy( 
    IClusCfgEvictCleanup * This,
    /* [in] */ DWORD dwDelayIn);


void __RPC_STUB IClusCfgEvictCleanup_CleanupLocalNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IClusCfgEvictCleanup_CleanupRemoteNode_Proxy( 
    IClusCfgEvictCleanup * This,
    /* [string][in] */ const WCHAR *pcszEvictedNodeNameIn,
    /* [in] */ DWORD dwDelayIn);


void __RPC_STUB IClusCfgEvictCleanup_CleanupRemoteNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgEvictCleanup_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgEvictCleanup_INTERFACE_DEFINED__
#define __AsyncIClusCfgEvictCleanup_INTERFACE_DEFINED__

/* interface AsyncIClusCfgEvictCleanup */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgEvictCleanup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6FE3E362-D373-4C5F-A0AF-1DFE8493C655")
    AsyncIClusCfgEvictCleanup : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_CleanupLocalNode( 
            /* [in] */ DWORD dwDelayIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_CleanupLocalNode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_CleanupRemoteNode( 
            /* [string][in] */ const WCHAR *pcszEvictedNodeNameIn,
            /* [in] */ DWORD dwDelayIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_CleanupRemoteNode( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgEvictCleanupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgEvictCleanup * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgEvictCleanup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgEvictCleanup * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_CleanupLocalNode )( 
            AsyncIClusCfgEvictCleanup * This,
            /* [in] */ DWORD dwDelayIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_CleanupLocalNode )( 
            AsyncIClusCfgEvictCleanup * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_CleanupRemoteNode )( 
            AsyncIClusCfgEvictCleanup * This,
            /* [string][in] */ const WCHAR *pcszEvictedNodeNameIn,
            /* [in] */ DWORD dwDelayIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_CleanupRemoteNode )( 
            AsyncIClusCfgEvictCleanup * This);
        
        END_INTERFACE
    } AsyncIClusCfgEvictCleanupVtbl;

    interface AsyncIClusCfgEvictCleanup
    {
        CONST_VTBL struct AsyncIClusCfgEvictCleanupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgEvictCleanup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgEvictCleanup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgEvictCleanup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgEvictCleanup_Begin_CleanupLocalNode(This,dwDelayIn)	\
    (This)->lpVtbl -> Begin_CleanupLocalNode(This,dwDelayIn)

#define AsyncIClusCfgEvictCleanup_Finish_CleanupLocalNode(This)	\
    (This)->lpVtbl -> Finish_CleanupLocalNode(This)

#define AsyncIClusCfgEvictCleanup_Begin_CleanupRemoteNode(This,pcszEvictedNodeNameIn,dwDelayIn)	\
    (This)->lpVtbl -> Begin_CleanupRemoteNode(This,pcszEvictedNodeNameIn,dwDelayIn)

#define AsyncIClusCfgEvictCleanup_Finish_CleanupRemoteNode(This)	\
    (This)->lpVtbl -> Finish_CleanupRemoteNode(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgEvictCleanup_Begin_CleanupLocalNode_Proxy( 
    AsyncIClusCfgEvictCleanup * This,
    /* [in] */ DWORD dwDelayIn);


void __RPC_STUB AsyncIClusCfgEvictCleanup_Begin_CleanupLocalNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgEvictCleanup_Finish_CleanupLocalNode_Proxy( 
    AsyncIClusCfgEvictCleanup * This);


void __RPC_STUB AsyncIClusCfgEvictCleanup_Finish_CleanupLocalNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgEvictCleanup_Begin_CleanupRemoteNode_Proxy( 
    AsyncIClusCfgEvictCleanup * This,
    /* [string][in] */ const WCHAR *pcszEvictedNodeNameIn,
    /* [in] */ DWORD dwDelayIn);


void __RPC_STUB AsyncIClusCfgEvictCleanup_Begin_CleanupRemoteNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgEvictCleanup_Finish_CleanupRemoteNode_Proxy( 
    AsyncIClusCfgEvictCleanup * This);


void __RPC_STUB AsyncIClusCfgEvictCleanup_Finish_CleanupRemoteNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgEvictCleanup_INTERFACE_DEFINED__ */


#ifndef __IClusCfgStartupListener_INTERFACE_DEFINED__
#define __IClusCfgStartupListener_INTERFACE_DEFINED__

/* interface IClusCfgStartupListener */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgStartupListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D282CAEF-2EDE-4ab9-A5D5-F7BDE3D23F0F")
    IClusCfgStartupListener : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Notify( 
            /* [in] */ IUnknown *punkIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgStartupListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgStartupListener * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgStartupListener * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgStartupListener * This);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            IClusCfgStartupListener * This,
            /* [in] */ IUnknown *punkIn);
        
        END_INTERFACE
    } IClusCfgStartupListenerVtbl;

    interface IClusCfgStartupListener
    {
        CONST_VTBL struct IClusCfgStartupListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgStartupListener_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgStartupListener_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgStartupListener_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgStartupListener_Notify(This,punkIn)	\
    (This)->lpVtbl -> Notify(This,punkIn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgStartupListener_Notify_Proxy( 
    IClusCfgStartupListener * This,
    /* [in] */ IUnknown *punkIn);


void __RPC_STUB IClusCfgStartupListener_Notify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgStartupListener_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgStartupListener_INTERFACE_DEFINED__
#define __AsyncIClusCfgStartupListener_INTERFACE_DEFINED__

/* interface AsyncIClusCfgStartupListener */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgStartupListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D282CAF0-2EDE-4ab9-A5D5-F7BDE3D23F10")
    AsyncIClusCfgStartupListener : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Notify( 
            /* [in] */ IUnknown *punkIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Notify( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgStartupListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgStartupListener * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgStartupListener * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgStartupListener * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Notify )( 
            AsyncIClusCfgStartupListener * This,
            /* [in] */ IUnknown *punkIn);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Notify )( 
            AsyncIClusCfgStartupListener * This);
        
        END_INTERFACE
    } AsyncIClusCfgStartupListenerVtbl;

    interface AsyncIClusCfgStartupListener
    {
        CONST_VTBL struct AsyncIClusCfgStartupListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgStartupListener_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgStartupListener_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgStartupListener_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgStartupListener_Begin_Notify(This,punkIn)	\
    (This)->lpVtbl -> Begin_Notify(This,punkIn)

#define AsyncIClusCfgStartupListener_Finish_Notify(This)	\
    (This)->lpVtbl -> Finish_Notify(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgStartupListener_Begin_Notify_Proxy( 
    AsyncIClusCfgStartupListener * This,
    /* [in] */ IUnknown *punkIn);


void __RPC_STUB AsyncIClusCfgStartupListener_Begin_Notify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgStartupListener_Finish_Notify_Proxy( 
    AsyncIClusCfgStartupListener * This);


void __RPC_STUB AsyncIClusCfgStartupListener_Finish_Notify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgStartupListener_INTERFACE_DEFINED__ */


#ifndef __IClusCfgStartupNotify_INTERFACE_DEFINED__
#define __IClusCfgStartupNotify_INTERFACE_DEFINED__

/* interface IClusCfgStartupNotify */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IClusCfgStartupNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C2B0D069-6353-4EE1-B253-6B0D75DB2CD3")
    IClusCfgStartupNotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SendNotifications( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClusCfgStartupNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClusCfgStartupNotify * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClusCfgStartupNotify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClusCfgStartupNotify * This);
        
        HRESULT ( STDMETHODCALLTYPE *SendNotifications )( 
            IClusCfgStartupNotify * This);
        
        END_INTERFACE
    } IClusCfgStartupNotifyVtbl;

    interface IClusCfgStartupNotify
    {
        CONST_VTBL struct IClusCfgStartupNotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClusCfgStartupNotify_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClusCfgStartupNotify_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClusCfgStartupNotify_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClusCfgStartupNotify_SendNotifications(This)	\
    (This)->lpVtbl -> SendNotifications(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IClusCfgStartupNotify_SendNotifications_Proxy( 
    IClusCfgStartupNotify * This);


void __RPC_STUB IClusCfgStartupNotify_SendNotifications_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClusCfgStartupNotify_INTERFACE_DEFINED__ */


#ifndef __AsyncIClusCfgStartupNotify_INTERFACE_DEFINED__
#define __AsyncIClusCfgStartupNotify_INTERFACE_DEFINED__

/* interface AsyncIClusCfgStartupNotify */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIClusCfgStartupNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C2B0D06A-6353-4EE1-B253-6B0D75DB2CD3")
    AsyncIClusCfgStartupNotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_SendNotifications( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_SendNotifications( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct AsyncIClusCfgStartupNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIClusCfgStartupNotify * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIClusCfgStartupNotify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIClusCfgStartupNotify * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_SendNotifications )( 
            AsyncIClusCfgStartupNotify * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_SendNotifications )( 
            AsyncIClusCfgStartupNotify * This);
        
        END_INTERFACE
    } AsyncIClusCfgStartupNotifyVtbl;

    interface AsyncIClusCfgStartupNotify
    {
        CONST_VTBL struct AsyncIClusCfgStartupNotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIClusCfgStartupNotify_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define AsyncIClusCfgStartupNotify_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define AsyncIClusCfgStartupNotify_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define AsyncIClusCfgStartupNotify_Begin_SendNotifications(This)	\
    (This)->lpVtbl -> Begin_SendNotifications(This)

#define AsyncIClusCfgStartupNotify_Finish_SendNotifications(This)	\
    (This)->lpVtbl -> Finish_SendNotifications(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE AsyncIClusCfgStartupNotify_Begin_SendNotifications_Proxy( 
    AsyncIClusCfgStartupNotify * This);


void __RPC_STUB AsyncIClusCfgStartupNotify_Begin_SendNotifications_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE AsyncIClusCfgStartupNotify_Finish_SendNotifications_Proxy( 
    AsyncIClusCfgStartupNotify * This);


void __RPC_STUB AsyncIClusCfgStartupNotify_Finish_SendNotifications_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __AsyncIClusCfgStartupNotify_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


