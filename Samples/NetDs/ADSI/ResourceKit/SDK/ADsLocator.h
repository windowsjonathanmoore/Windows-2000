/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Oct 27 15:32:19 1999
 */
/* Compiler settings for D:\Projects\ADsLocator\ADsLocator.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
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

#ifndef __ADsLocator_h__
#define __ADsLocator_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IADsLocator_FWD_DEFINED__
#define __IADsLocator_FWD_DEFINED__
typedef interface IADsLocator IADsLocator;
#endif 	/* __IADsLocator_FWD_DEFINED__ */


#ifndef __IADsDCInfo_FWD_DEFINED__
#define __IADsDCInfo_FWD_DEFINED__
typedef interface IADsDCInfo IADsDCInfo;
#endif 	/* __IADsDCInfo_FWD_DEFINED__ */


#ifndef __IADsDomainTrust_FWD_DEFINED__
#define __IADsDomainTrust_FWD_DEFINED__
typedef interface IADsDomainTrust IADsDomainTrust;
#endif 	/* __IADsDomainTrust_FWD_DEFINED__ */


#ifndef __IADsDomainTrustEnum_FWD_DEFINED__
#define __IADsDomainTrustEnum_FWD_DEFINED__
typedef interface IADsDomainTrustEnum IADsDomainTrustEnum;
#endif 	/* __IADsDomainTrustEnum_FWD_DEFINED__ */


#ifndef __IADsDsRoleInfo_FWD_DEFINED__
#define __IADsDsRoleInfo_FWD_DEFINED__
typedef interface IADsDsRoleInfo IADsDsRoleInfo;
#endif 	/* __IADsDsRoleInfo_FWD_DEFINED__ */


#ifndef __ADsLocator_FWD_DEFINED__
#define __ADsLocator_FWD_DEFINED__

#ifdef __cplusplus
typedef class ADsLocator ADsLocator;
#else
typedef struct ADsLocator ADsLocator;
#endif /* __cplusplus */

#endif 	/* __ADsLocator_FWD_DEFINED__ */


#ifndef __ADsDCInfo_FWD_DEFINED__
#define __ADsDCInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class ADsDCInfo ADsDCInfo;
#else
typedef struct ADsDCInfo ADsDCInfo;
#endif /* __cplusplus */

#endif 	/* __ADsDCInfo_FWD_DEFINED__ */


#ifndef __ADsDomainTrust_FWD_DEFINED__
#define __ADsDomainTrust_FWD_DEFINED__

#ifdef __cplusplus
typedef class ADsDomainTrust ADsDomainTrust;
#else
typedef struct ADsDomainTrust ADsDomainTrust;
#endif /* __cplusplus */

#endif 	/* __ADsDomainTrust_FWD_DEFINED__ */


#ifndef __ADsDomainTrustEnum_FWD_DEFINED__
#define __ADsDomainTrustEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class ADsDomainTrustEnum ADsDomainTrustEnum;
#else
typedef struct ADsDomainTrustEnum ADsDomainTrustEnum;
#endif /* __cplusplus */

#endif 	/* __ADsDomainTrustEnum_FWD_DEFINED__ */


#ifndef __ADsDsRoleInfo_FWD_DEFINED__
#define __ADsDsRoleInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class ADsDsRoleInfo ADsDsRoleInfo;
#else
typedef struct ADsDsRoleInfo ADsDsRoleInfo;
#endif /* __cplusplus */

#endif 	/* __ADsDsRoleInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IADsLocator_INTERFACE_DEFINED__
#define __IADsLocator_INTERFACE_DEFINED__

/* interface IADsLocator */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IADsLocator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C3CECC33-E82E-4CCB-8589-194A0D1C3ADF")
    IADsLocator : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DsGetDcName( 
            /* [optional][in] */ VARIANT ComputerName,
            /* [optional][in] */ VARIANT DomainName,
            /* [optional][in] */ VARIANT SiteName,
            /* [defaultvalue][in] */ long Flags,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DsGetSiteName( 
            /* [optional][in] */ VARIANT ComputerName,
            /* [retval][out] */ BSTR __RPC_FAR *SiteName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DsValidateSubnetName( 
            /* [in] */ BSTR SubnetName,
            /* [retval][out] */ BOOL __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DsGetDcSiteCoverage( 
            /* [optional][in] */ VARIANT ServerName,
            /* [retval][out] */ VARIANT __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DsEnumerateDomainTrusts( 
            /* [optional][in] */ VARIANT ServerName,
            /* [defaultvalue][in] */ long Flags,
            /* [retval][out] */ VARIANT __RPC_FAR *pResults) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DsGetDCNamesInDomain( 
            /* [optional][in] */ VARIANT DomainName,
            /* [retval][out] */ VARIANT __RPC_FAR *DcNames) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DsRoleGetPrimaryDomainInformation( 
            /* [optional][in] */ VARIANT ServerName,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADsLocatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IADsLocator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IADsLocator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IADsLocator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IADsLocator __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IADsLocator __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IADsLocator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IADsLocator __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DsGetDcName )( 
            IADsLocator __RPC_FAR * This,
            /* [optional][in] */ VARIANT ComputerName,
            /* [optional][in] */ VARIANT DomainName,
            /* [optional][in] */ VARIANT SiteName,
            /* [defaultvalue][in] */ long Flags,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DsGetSiteName )( 
            IADsLocator __RPC_FAR * This,
            /* [optional][in] */ VARIANT ComputerName,
            /* [retval][out] */ BSTR __RPC_FAR *SiteName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DsValidateSubnetName )( 
            IADsLocator __RPC_FAR * This,
            /* [in] */ BSTR SubnetName,
            /* [retval][out] */ BOOL __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DsGetDcSiteCoverage )( 
            IADsLocator __RPC_FAR * This,
            /* [optional][in] */ VARIANT ServerName,
            /* [retval][out] */ VARIANT __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DsEnumerateDomainTrusts )( 
            IADsLocator __RPC_FAR * This,
            /* [optional][in] */ VARIANT ServerName,
            /* [defaultvalue][in] */ long Flags,
            /* [retval][out] */ VARIANT __RPC_FAR *pResults);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DsGetDCNamesInDomain )( 
            IADsLocator __RPC_FAR * This,
            /* [optional][in] */ VARIANT DomainName,
            /* [retval][out] */ VARIANT __RPC_FAR *DcNames);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DsRoleGetPrimaryDomainInformation )( 
            IADsLocator __RPC_FAR * This,
            /* [optional][in] */ VARIANT ServerName,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pResult);
        
        END_INTERFACE
    } IADsLocatorVtbl;

    interface IADsLocator
    {
        CONST_VTBL struct IADsLocatorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADsLocator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADsLocator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADsLocator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADsLocator_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADsLocator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADsLocator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADsLocator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADsLocator_DsGetDcName(This,ComputerName,DomainName,SiteName,Flags,pResult)	\
    (This)->lpVtbl -> DsGetDcName(This,ComputerName,DomainName,SiteName,Flags,pResult)

#define IADsLocator_DsGetSiteName(This,ComputerName,SiteName)	\
    (This)->lpVtbl -> DsGetSiteName(This,ComputerName,SiteName)

#define IADsLocator_DsValidateSubnetName(This,SubnetName,pResult)	\
    (This)->lpVtbl -> DsValidateSubnetName(This,SubnetName,pResult)

#define IADsLocator_DsGetDcSiteCoverage(This,ServerName,pResult)	\
    (This)->lpVtbl -> DsGetDcSiteCoverage(This,ServerName,pResult)

#define IADsLocator_DsEnumerateDomainTrusts(This,ServerName,Flags,pResults)	\
    (This)->lpVtbl -> DsEnumerateDomainTrusts(This,ServerName,Flags,pResults)

#define IADsLocator_DsGetDCNamesInDomain(This,DomainName,DcNames)	\
    (This)->lpVtbl -> DsGetDCNamesInDomain(This,DomainName,DcNames)

#define IADsLocator_DsRoleGetPrimaryDomainInformation(This,ServerName,pResult)	\
    (This)->lpVtbl -> DsRoleGetPrimaryDomainInformation(This,ServerName,pResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsLocator_DsGetDcName_Proxy( 
    IADsLocator __RPC_FAR * This,
    /* [optional][in] */ VARIANT ComputerName,
    /* [optional][in] */ VARIANT DomainName,
    /* [optional][in] */ VARIANT SiteName,
    /* [defaultvalue][in] */ long Flags,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pResult);


void __RPC_STUB IADsLocator_DsGetDcName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsLocator_DsGetSiteName_Proxy( 
    IADsLocator __RPC_FAR * This,
    /* [optional][in] */ VARIANT ComputerName,
    /* [retval][out] */ BSTR __RPC_FAR *SiteName);


void __RPC_STUB IADsLocator_DsGetSiteName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsLocator_DsValidateSubnetName_Proxy( 
    IADsLocator __RPC_FAR * This,
    /* [in] */ BSTR SubnetName,
    /* [retval][out] */ BOOL __RPC_FAR *pResult);


void __RPC_STUB IADsLocator_DsValidateSubnetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsLocator_DsGetDcSiteCoverage_Proxy( 
    IADsLocator __RPC_FAR * This,
    /* [optional][in] */ VARIANT ServerName,
    /* [retval][out] */ VARIANT __RPC_FAR *pResult);


void __RPC_STUB IADsLocator_DsGetDcSiteCoverage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsLocator_DsEnumerateDomainTrusts_Proxy( 
    IADsLocator __RPC_FAR * This,
    /* [optional][in] */ VARIANT ServerName,
    /* [defaultvalue][in] */ long Flags,
    /* [retval][out] */ VARIANT __RPC_FAR *pResults);


void __RPC_STUB IADsLocator_DsEnumerateDomainTrusts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsLocator_DsGetDCNamesInDomain_Proxy( 
    IADsLocator __RPC_FAR * This,
    /* [optional][in] */ VARIANT DomainName,
    /* [retval][out] */ VARIANT __RPC_FAR *DcNames);


void __RPC_STUB IADsLocator_DsGetDCNamesInDomain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsLocator_DsRoleGetPrimaryDomainInformation_Proxy( 
    IADsLocator __RPC_FAR * This,
    /* [optional][in] */ VARIANT ServerName,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pResult);


void __RPC_STUB IADsLocator_DsRoleGetPrimaryDomainInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADsLocator_INTERFACE_DEFINED__ */


#ifndef __IADsDCInfo_INTERFACE_DEFINED__
#define __IADsDCInfo_INTERFACE_DEFINED__

/* interface IADsDCInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IADsDCInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9065F093-16B8-401E-B209-80182F1F5762")
    IADsDCInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainControllerName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainControllerAddress( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainControllerAddressType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainGuid( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DnsForestName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DcSiteName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClientSiteName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADsDCInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IADsDCInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IADsDCInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IADsDCInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IADsDCInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IADsDCInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IADsDCInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IADsDCInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainControllerName )( 
            IADsDCInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainControllerAddress )( 
            IADsDCInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainControllerAddressType )( 
            IADsDCInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainGuid )( 
            IADsDCInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainName )( 
            IADsDCInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DnsForestName )( 
            IADsDCInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Flags )( 
            IADsDCInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DcSiteName )( 
            IADsDCInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClientSiteName )( 
            IADsDCInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        END_INTERFACE
    } IADsDCInfoVtbl;

    interface IADsDCInfo
    {
        CONST_VTBL struct IADsDCInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADsDCInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADsDCInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADsDCInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADsDCInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADsDCInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADsDCInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADsDCInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADsDCInfo_get_DomainControllerName(This,pVal)	\
    (This)->lpVtbl -> get_DomainControllerName(This,pVal)

#define IADsDCInfo_get_DomainControllerAddress(This,pVal)	\
    (This)->lpVtbl -> get_DomainControllerAddress(This,pVal)

#define IADsDCInfo_get_DomainControllerAddressType(This,pVal)	\
    (This)->lpVtbl -> get_DomainControllerAddressType(This,pVal)

#define IADsDCInfo_get_DomainGuid(This,pVal)	\
    (This)->lpVtbl -> get_DomainGuid(This,pVal)

#define IADsDCInfo_get_DomainName(This,pVal)	\
    (This)->lpVtbl -> get_DomainName(This,pVal)

#define IADsDCInfo_get_DnsForestName(This,pVal)	\
    (This)->lpVtbl -> get_DnsForestName(This,pVal)

#define IADsDCInfo_get_Flags(This,pVal)	\
    (This)->lpVtbl -> get_Flags(This,pVal)

#define IADsDCInfo_get_DcSiteName(This,pVal)	\
    (This)->lpVtbl -> get_DcSiteName(This,pVal)

#define IADsDCInfo_get_ClientSiteName(This,pVal)	\
    (This)->lpVtbl -> get_ClientSiteName(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDCInfo_get_DomainControllerName_Proxy( 
    IADsDCInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDCInfo_get_DomainControllerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDCInfo_get_DomainControllerAddress_Proxy( 
    IADsDCInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDCInfo_get_DomainControllerAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDCInfo_get_DomainControllerAddressType_Proxy( 
    IADsDCInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IADsDCInfo_get_DomainControllerAddressType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDCInfo_get_DomainGuid_Proxy( 
    IADsDCInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDCInfo_get_DomainGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDCInfo_get_DomainName_Proxy( 
    IADsDCInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDCInfo_get_DomainName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDCInfo_get_DnsForestName_Proxy( 
    IADsDCInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDCInfo_get_DnsForestName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDCInfo_get_Flags_Proxy( 
    IADsDCInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IADsDCInfo_get_Flags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDCInfo_get_DcSiteName_Proxy( 
    IADsDCInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDCInfo_get_DcSiteName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDCInfo_get_ClientSiteName_Proxy( 
    IADsDCInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDCInfo_get_ClientSiteName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADsDCInfo_INTERFACE_DEFINED__ */


#ifndef __IADsDomainTrust_INTERFACE_DEFINED__
#define __IADsDomainTrust_INTERFACE_DEFINED__

/* interface IADsDomainTrust */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IADsDomainTrust;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F2EB4AF3-8217-4BB8-B97F-1DD0EF1F1CF1")
    IADsDomainTrust : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NetbiosDomainName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DnsDomainName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParentIndex( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TrustType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TrustAttributes( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainSid( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainGuid( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADsDomainTrustVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IADsDomainTrust __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IADsDomainTrust __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NetbiosDomainName )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DnsDomainName )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Flags )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ParentIndex )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TrustType )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TrustAttributes )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainSid )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainGuid )( 
            IADsDomainTrust __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        END_INTERFACE
    } IADsDomainTrustVtbl;

    interface IADsDomainTrust
    {
        CONST_VTBL struct IADsDomainTrustVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADsDomainTrust_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADsDomainTrust_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADsDomainTrust_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADsDomainTrust_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADsDomainTrust_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADsDomainTrust_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADsDomainTrust_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADsDomainTrust_get_NetbiosDomainName(This,pVal)	\
    (This)->lpVtbl -> get_NetbiosDomainName(This,pVal)

#define IADsDomainTrust_get_DnsDomainName(This,pVal)	\
    (This)->lpVtbl -> get_DnsDomainName(This,pVal)

#define IADsDomainTrust_get_Flags(This,pVal)	\
    (This)->lpVtbl -> get_Flags(This,pVal)

#define IADsDomainTrust_get_ParentIndex(This,pVal)	\
    (This)->lpVtbl -> get_ParentIndex(This,pVal)

#define IADsDomainTrust_get_TrustType(This,pVal)	\
    (This)->lpVtbl -> get_TrustType(This,pVal)

#define IADsDomainTrust_get_TrustAttributes(This,pVal)	\
    (This)->lpVtbl -> get_TrustAttributes(This,pVal)

#define IADsDomainTrust_get_DomainSid(This,pVal)	\
    (This)->lpVtbl -> get_DomainSid(This,pVal)

#define IADsDomainTrust_get_DomainGuid(This,pVal)	\
    (This)->lpVtbl -> get_DomainGuid(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDomainTrust_get_NetbiosDomainName_Proxy( 
    IADsDomainTrust __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDomainTrust_get_NetbiosDomainName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDomainTrust_get_DnsDomainName_Proxy( 
    IADsDomainTrust __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDomainTrust_get_DnsDomainName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDomainTrust_get_Flags_Proxy( 
    IADsDomainTrust __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IADsDomainTrust_get_Flags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDomainTrust_get_ParentIndex_Proxy( 
    IADsDomainTrust __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IADsDomainTrust_get_ParentIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDomainTrust_get_TrustType_Proxy( 
    IADsDomainTrust __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IADsDomainTrust_get_TrustType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDomainTrust_get_TrustAttributes_Proxy( 
    IADsDomainTrust __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IADsDomainTrust_get_TrustAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDomainTrust_get_DomainSid_Proxy( 
    IADsDomainTrust __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDomainTrust_get_DomainSid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDomainTrust_get_DomainGuid_Proxy( 
    IADsDomainTrust __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDomainTrust_get_DomainGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADsDomainTrust_INTERFACE_DEFINED__ */


#ifndef __IADsDomainTrustEnum_INTERFACE_DEFINED__
#define __IADsDomainTrustEnum_INTERFACE_DEFINED__

/* interface IADsDomainTrustEnum */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IADsDomainTrustEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9A819E46-A473-4D99-A6A5-DD6C0234CD40")
    IADsDomainTrustEnum : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pUnk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADsDomainTrustEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IADsDomainTrustEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IADsDomainTrustEnum __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IADsDomainTrustEnum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IADsDomainTrustEnum __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IADsDomainTrustEnum __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IADsDomainTrustEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IADsDomainTrustEnum __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            IADsDomainTrustEnum __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pUnk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IADsDomainTrustEnum __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        END_INTERFACE
    } IADsDomainTrustEnumVtbl;

    interface IADsDomainTrustEnum
    {
        CONST_VTBL struct IADsDomainTrustEnumVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADsDomainTrustEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADsDomainTrustEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADsDomainTrustEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADsDomainTrustEnum_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADsDomainTrustEnum_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADsDomainTrustEnum_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADsDomainTrustEnum_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADsDomainTrustEnum_get__NewEnum(This,pUnk)	\
    (This)->lpVtbl -> get__NewEnum(This,pUnk)

#define IADsDomainTrustEnum_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsDomainTrustEnum_get__NewEnum_Proxy( 
    IADsDomainTrustEnum __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pUnk);


void __RPC_STUB IADsDomainTrustEnum_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDomainTrustEnum_get_Count_Proxy( 
    IADsDomainTrustEnum __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IADsDomainTrustEnum_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADsDomainTrustEnum_INTERFACE_DEFINED__ */


#ifndef __IADsDsRoleInfo_INTERFACE_DEFINED__
#define __IADsDsRoleInfo_INTERFACE_DEFINED__

/* interface IADsDsRoleInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IADsDsRoleInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5ACB4D8-91E1-4C71-BF14-966FBEDB500F")
    IADsDsRoleInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MachineRole( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainNameFlat( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainNameDns( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainForestName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainGuid( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADsDsRoleInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IADsDsRoleInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IADsDsRoleInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MachineRole )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Flags )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainNameFlat )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainNameDns )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainForestName )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainGuid )( 
            IADsDsRoleInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        END_INTERFACE
    } IADsDsRoleInfoVtbl;

    interface IADsDsRoleInfo
    {
        CONST_VTBL struct IADsDsRoleInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADsDsRoleInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADsDsRoleInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADsDsRoleInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADsDsRoleInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADsDsRoleInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADsDsRoleInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADsDsRoleInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADsDsRoleInfo_get_MachineRole(This,pVal)	\
    (This)->lpVtbl -> get_MachineRole(This,pVal)

#define IADsDsRoleInfo_get_Flags(This,pVal)	\
    (This)->lpVtbl -> get_Flags(This,pVal)

#define IADsDsRoleInfo_get_DomainNameFlat(This,pVal)	\
    (This)->lpVtbl -> get_DomainNameFlat(This,pVal)

#define IADsDsRoleInfo_get_DomainNameDns(This,pVal)	\
    (This)->lpVtbl -> get_DomainNameDns(This,pVal)

#define IADsDsRoleInfo_get_DomainForestName(This,pVal)	\
    (This)->lpVtbl -> get_DomainForestName(This,pVal)

#define IADsDsRoleInfo_get_DomainGuid(This,pVal)	\
    (This)->lpVtbl -> get_DomainGuid(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDsRoleInfo_get_MachineRole_Proxy( 
    IADsDsRoleInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IADsDsRoleInfo_get_MachineRole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDsRoleInfo_get_Flags_Proxy( 
    IADsDsRoleInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IADsDsRoleInfo_get_Flags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDsRoleInfo_get_DomainNameFlat_Proxy( 
    IADsDsRoleInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDsRoleInfo_get_DomainNameFlat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDsRoleInfo_get_DomainNameDns_Proxy( 
    IADsDsRoleInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDsRoleInfo_get_DomainNameDns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDsRoleInfo_get_DomainForestName_Proxy( 
    IADsDsRoleInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDsRoleInfo_get_DomainForestName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsDsRoleInfo_get_DomainGuid_Proxy( 
    IADsDsRoleInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsDsRoleInfo_get_DomainGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADsDsRoleInfo_INTERFACE_DEFINED__ */



#ifndef __ADSLOCATORLib_LIBRARY_DEFINED__
#define __ADSLOCATORLib_LIBRARY_DEFINED__

/* library ADSLOCATORLib */
/* [helpstring][version][uuid] */ 


enum ADS_DSGETDC_ENUM
    {	ADS_FORCE_REDISCOVERY	= 0x1,
	ADS_DIRECTORY_SERVICE_REQUIRED	= 0x10,
	ADS_DIRECTORY_SERVICE_PREFERRED	= 0x20,
	ADS_GC_SERVER_REQUIRED	= 0x40,
	ADS_PDC_REQUIRED	= 0x80,
	ADS_IP_REQUIRED	= 0x200,
	ADS_KDC_REQUIRED	= 0x400,
	ADS_TIMESERV_REQUIRED	= 0x800,
	ADS_WRITABLE_REQUIRED	= 0x1000,
	ADS_GOOD_TIMESERV_PREFERRED	= 0x2000,
	ADS_AVOID_SELF	= 0x4000,
	ADS_ONLY_LDAP_NEEDED	= 0x8000,
	ADS_IS_FLAT_NAME	= 0x10000,
	ADS_IS_DNS_NAME	= 0x20000,
	ADS_RETURN_DNS_NAME	= 0x40000000,
	ADS_RETURN_FLAT_NAME	= 0x80000000
    };

enum ADS_DC_ADDRESS_ENUM
    {	ADS_INET_ADDRESS	= 1,
	ADS_NETBIOS_ADDRESS	= 2
    };

enum ADS_DSGETDC_FLAG_ENUM
    {	ADS_PDC_FLAG	= 0x1,
	ADS_GC_FLAG	= 0x4,
	ADS_LDAP_FLAG	= 0x8,
	ADS_DS_FLAG	= 0x10,
	ADS_KDC_FLAG	= 0x20,
	ADS_TIMESERV_FLAG	= 0x40,
	ADS_CLOSEST_FLAG	= 0x80,
	ADS_WRITABLE_FLAG	= 0x100,
	ADS_GOOD_TIMESERV_FLAG	= 0x200,
	ADS_PING_FLAGS	= 0xffff,
	ADS_DNS_CONTROLLER_FLAG	= 0x20000000,
	ADS_DNS_DOMAIN_FLAG	= 0x40000000,
	ADS_DNS_FOREST_FLAG	= 0x80000000
    };

enum ADS_DOMAIN_TRUST_ENUM
    {	ADS_DOMAIN_IN_FOREST	= 0x1,
	ADS_DOMAIN_DIRECT_TRUST	= 0x2,
	ADS_DOMAIN_DIRECT_OUTBOUND	= 0x2,
	ADS_DOMAIN_TREE_ROOT	= 0x4,
	ADS_DOMAIN_PRIMARY	= 0x8,
	ADS_DOMAIN_NATIVE_MODE	= 0x10,
	ADS_DOMAIN_DIRECT_INBOUND	= 0x20
    };

enum ADS_TRUST_DIRECTION_ENUM
    {	ADS_TRUST_DIRECTION_DISABLED	= 0,
	ADS_TRUST_DIRECTION_INBOUND	= 0x1,
	ADS_TRUST_DIRECTION_OUTBOUND	= 0x2,
	ADS_TRUST_DIRECTION_BIDIRECTIONAL	= 0x3
    };

enum ADS_TRUST_TYPE_ENUM
    {	ADS_TRUST_TYPE_DOWNLEVEL	= 0x1,
	ADS_TRUST_TYPE_UPLEVEL	= 0x2,
	ADS_TRUST_TYPE_MIT	= 0x3,
	ADS_TRUST_TYPE_DCE	= 0x4
    };

enum ADS_TRUST_ATTRIBUTE_ENUM
    {	ADS_TRUST_ATTRIBUTE_NON_TRANSITIVE	= 0x1,
	ADS_TRUST_ATTRIBUTE_UPLEVEL_ONLY	= 0x2,
	ADS_TRUST_ATTRIBUTE_TREE_PARENT	= 0x400000,
	ADS_TRUST_ATTRIBUTE_TREE_ROOT	= 0x800000,
	ADS_TRUST_ATTRIBUTES_VALID	= 0xff02ffff,
	ADS_TRUST_ATTRIBUTES_USER	= 0xff000000
    };

enum ADS_MACHINE_ROLE_ENUM
    {	ADS_ROLE_STANDALONE_WORKSTATION	= 0,
	ADS_ROLE_MEMBER_WORKSTATION	= 1,
	ADS_ROLE_STANDALONE_SERVER	= 2,
	ADS_ROLE_MEMBER_SERVER	= 3,
	ADS_ROLE_BACKUP_DOMAIN_CONTROLLER	= 4,
	ADS_ROLE_PRIMARY_DOMAIN_CONTROLLER	= 5
    };

enum ADS_ROLE_FLAG_ENUM
    {	ADS_ROLE_PRIMARY_DS_RUNNING	= 0x1,
	ADS_ROLE_PRIMARY_DS_MIXED_MODE	= 0x2,
	ADS_ROLE_PRIMARY_DOMAIN_GUID_PRESENT	= 0x1000000,
	ADS_ROLE_UPGRADE_IN_PROGRESS	= 0x1
    };

EXTERN_C const IID LIBID_ADSLOCATORLib;

EXTERN_C const CLSID CLSID_ADsLocator;

#ifdef __cplusplus

class DECLSPEC_UUID("107409E3-39AC-4656-BA73-323783C72735")
ADsLocator;
#endif

EXTERN_C const CLSID CLSID_ADsDCInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("5F30E30D-6F34-4701-9BDB-995ECD1D70AF")
ADsDCInfo;
#endif

EXTERN_C const CLSID CLSID_ADsDomainTrust;

#ifdef __cplusplus

class DECLSPEC_UUID("78D1374C-0873-46E7-820B-9FE7B318C6EE")
ADsDomainTrust;
#endif

EXTERN_C const CLSID CLSID_ADsDomainTrustEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("28BE2362-4438-42FA-BF6E-50B3A4FE2E61")
ADsDomainTrustEnum;
#endif

EXTERN_C const CLSID CLSID_ADsDsRoleInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("8260DD75-451C-47E7-9D7E-919CCCD1DAD8")
ADsDsRoleInfo;
#endif
#endif /* __ADSLOCATORLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
