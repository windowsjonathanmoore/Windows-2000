
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0266 */
/* at Thu Dec 09 09:06:13 1999
 */
/* Compiler settings for traceprovider.idl:
    Oicf (OptLev=i2), W1, Zp2, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
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

#ifndef __traceprovider_h__
#define __traceprovider_h__

/* Forward Declarations */ 

#ifndef __IDBTraceProvider_FWD_DEFINED__
#define __IDBTraceProvider_FWD_DEFINED__
typedef interface IDBTraceProvider IDBTraceProvider;
#endif 	/* __IDBTraceProvider_FWD_DEFINED__ */


#ifndef __IDBTraceProviderEnumerator_FWD_DEFINED__
#define __IDBTraceProviderEnumerator_FWD_DEFINED__
typedef interface IDBTraceProviderEnumerator IDBTraceProviderEnumerator;
#endif 	/* __IDBTraceProviderEnumerator_FWD_DEFINED__ */


#ifndef __IDBTraceProviderManager_FWD_DEFINED__
#define __IDBTraceProviderManager_FWD_DEFINED__
typedef interface IDBTraceProviderManager IDBTraceProviderManager;
#endif 	/* __IDBTraceProviderManager_FWD_DEFINED__ */


#ifndef __IDBTraceReceiverControl_FWD_DEFINED__
#define __IDBTraceReceiverControl_FWD_DEFINED__
typedef interface IDBTraceReceiverControl IDBTraceReceiverControl;
#endif 	/* __IDBTraceReceiverControl_FWD_DEFINED__ */


#ifndef __IDBTraceReceiverEnumerator_FWD_DEFINED__
#define __IDBTraceReceiverEnumerator_FWD_DEFINED__
typedef interface IDBTraceReceiverEnumerator IDBTraceReceiverEnumerator;
#endif 	/* __IDBTraceReceiverEnumerator_FWD_DEFINED__ */


#ifndef __IDBTraceReceiverManager_FWD_DEFINED__
#define __IDBTraceReceiverManager_FWD_DEFINED__
typedef interface IDBTraceReceiverManager IDBTraceReceiverManager;
#endif 	/* __IDBTraceReceiverManager_FWD_DEFINED__ */


#ifndef __IDBTraceReceiver_FWD_DEFINED__
#define __IDBTraceReceiver_FWD_DEFINED__
typedef interface IDBTraceReceiver IDBTraceReceiver;
#endif 	/* __IDBTraceReceiver_FWD_DEFINED__ */


#ifndef __IDBTraceNotify_FWD_DEFINED__
#define __IDBTraceNotify_FWD_DEFINED__
typedef interface IDBTraceNotify IDBTraceNotify;
#endif 	/* __IDBTraceNotify_FWD_DEFINED__ */


#ifndef __IDBTraceEnumParameters_FWD_DEFINED__
#define __IDBTraceEnumParameters_FWD_DEFINED__
typedef interface IDBTraceEnumParameters IDBTraceEnumParameters;
#endif 	/* __IDBTraceEnumParameters_FWD_DEFINED__ */


#ifndef __IDBTracePackage_FWD_DEFINED__
#define __IDBTracePackage_FWD_DEFINED__
typedef interface IDBTracePackage IDBTracePackage;
#endif 	/* __IDBTracePackage_FWD_DEFINED__ */


#ifndef __IDBTraceParameter_FWD_DEFINED__
#define __IDBTraceParameter_FWD_DEFINED__
typedef interface IDBTraceParameter IDBTraceParameter;
#endif 	/* __IDBTraceParameter_FWD_DEFINED__ */


#ifndef __IDBTraceInterpreter_FWD_DEFINED__
#define __IDBTraceInterpreter_FWD_DEFINED__
typedef interface IDBTraceInterpreter IDBTraceInterpreter;
#endif 	/* __IDBTraceInterpreter_FWD_DEFINED__ */


#ifndef __IProviderEnum_FWD_DEFINED__
#define __IProviderEnum_FWD_DEFINED__
typedef interface IProviderEnum IProviderEnum;
#endif 	/* __IProviderEnum_FWD_DEFINED__ */


#ifndef __TraceControl_FWD_DEFINED__
#define __TraceControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class TraceControl TraceControl;
#else
typedef struct TraceControl TraceControl;
#endif /* __cplusplus */

#endif 	/* __TraceControl_FWD_DEFINED__ */


#ifndef __Tracer_FWD_DEFINED__
#define __Tracer_FWD_DEFINED__

#ifdef __cplusplus
typedef class Tracer Tracer;
#else
typedef struct Tracer Tracer;
#endif /* __cplusplus */

#endif 	/* __Tracer_FWD_DEFINED__ */


#ifndef __TraceReceiver_FWD_DEFINED__
#define __TraceReceiver_FWD_DEFINED__

#ifdef __cplusplus
typedef class TraceReceiver TraceReceiver;
#else
typedef struct TraceReceiver TraceReceiver;
#endif /* __cplusplus */

#endif 	/* __TraceReceiver_FWD_DEFINED__ */


#ifndef __TraceInterpreter_FWD_DEFINED__
#define __TraceInterpreter_FWD_DEFINED__

#ifdef __cplusplus
typedef class TraceInterpreter TraceInterpreter;
#else
typedef struct TraceInterpreter TraceInterpreter;
#endif /* __cplusplus */

#endif 	/* __TraceInterpreter_FWD_DEFINED__ */


#ifndef __ProviderEnum_FWD_DEFINED__
#define __ProviderEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class ProviderEnum ProviderEnum;
#else
typedef struct ProviderEnum ProviderEnum;
#endif /* __cplusplus */

#endif 	/* __ProviderEnum_FWD_DEFINED__ */


/* header files for imported files */
#include "oledb.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_traceprovider_0000 */
/* [local] */ 

typedef struct tagDBTRACEINFO
    {
    DOUBLE perfTime;
    HRESULT hResult;
    DBORDINAL dwProviderID;
    DBORDINAL dwCotypeID;
    DBORDINAL dwInterfaceID;
    DBORDINAL dwMethodID;
    DBORDINAL dwUniqueID;
    DWORD dwInterpreterVersion;
    DWORD dwProcessID;
    DWORD dwThreadID;
    DBCOUNTITEM cbParameterCount;
    DWORD dwTraceLevel;
    DBLENGTH cbPackageSize;
    DWORD dwPackageType;
    DWORD dwIntAddr;
    DWORD dwCotypeAddr;
    }	DBTRACEINFO;

typedef struct tagDBTRACEPARAMINFO
    {
    DWORD argValue;
    DBORDINAL dwInterfaceID;
    DBORDINAL dwParamIndex;
    DBORDINAL dwTypeID;
    DBLENGTH cbDataSize;
    BYTE bInputOrOutput;
    BYTE fIsConst;
    BYTE fHasBrackets;
    LPWSTR type;
    BYTE bLevelsOfIndirection;
    LPWSTR indexOfArraySize;
    }	DBTRACEPARAMINFO;

typedef 
enum tagScopeFlags
    {	FLAG_LOCAL	= 0,
	FLAG_GLOBAL	= 1
    }	ScopeFlags;

typedef 
enum tagTraceState
    {	TRACE_OFF	= 1,
	TRACE_ON	= 2
    }	TraceState;















extern RPC_IF_HANDLE __MIDL_itf_traceprovider_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_traceprovider_0000_v0_0_s_ifspec;

#ifndef __IDBTraceProvider_INTERFACE_DEFINED__
#define __IDBTraceProvider_INTERFACE_DEFINED__

/* interface IDBTraceProvider */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e068db70-5743-11d3-b314-00c04f611c75")
    IDBTraceProvider : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProgId( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrProgId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetState( 
            /* [retval][out] */ TraceState __RPC_FAR *plState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetState( 
            /* [in] */ TraceState lState,
            /* [in] */ ScopeFlags lFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFilter( 
            /* [in] */ BSTR bstrInterfaceName,
            /* [retval][out] */ TraceState __RPC_FAR *plState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFilter( 
            /* [in] */ BSTR bstrInterfaceName,
            /* [in] */ TraceState lState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceProvider __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceProvider __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProgId )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrProgId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetState )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [retval][out] */ TraceState __RPC_FAR *plState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetState )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [in] */ TraceState lState,
            /* [in] */ ScopeFlags lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFilter )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [in] */ BSTR bstrInterfaceName,
            /* [retval][out] */ TraceState __RPC_FAR *plState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFilter )( 
            IDBTraceProvider __RPC_FAR * This,
            /* [in] */ BSTR bstrInterfaceName,
            /* [in] */ TraceState lState);
        
        END_INTERFACE
    } IDBTraceProviderVtbl;

    interface IDBTraceProvider
    {
        CONST_VTBL struct IDBTraceProviderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceProvider_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDBTraceProvider_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDBTraceProvider_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDBTraceProvider_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDBTraceProvider_GetName(This,pbstrName)	\
    (This)->lpVtbl -> GetName(This,pbstrName)

#define IDBTraceProvider_GetProgId(This,pbstrProgId)	\
    (This)->lpVtbl -> GetProgId(This,pbstrProgId)

#define IDBTraceProvider_GetState(This,plState)	\
    (This)->lpVtbl -> GetState(This,plState)

#define IDBTraceProvider_SetState(This,lState,lFlags)	\
    (This)->lpVtbl -> SetState(This,lState,lFlags)

#define IDBTraceProvider_GetFilter(This,bstrInterfaceName,plState)	\
    (This)->lpVtbl -> GetFilter(This,bstrInterfaceName,plState)

#define IDBTraceProvider_SetFilter(This,bstrInterfaceName,lState)	\
    (This)->lpVtbl -> SetFilter(This,bstrInterfaceName,lState)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProvider_GetName_Proxy( 
    IDBTraceProvider __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrName);


void __RPC_STUB IDBTraceProvider_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProvider_GetProgId_Proxy( 
    IDBTraceProvider __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrProgId);


void __RPC_STUB IDBTraceProvider_GetProgId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProvider_GetState_Proxy( 
    IDBTraceProvider __RPC_FAR * This,
    /* [retval][out] */ TraceState __RPC_FAR *plState);


void __RPC_STUB IDBTraceProvider_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProvider_SetState_Proxy( 
    IDBTraceProvider __RPC_FAR * This,
    /* [in] */ TraceState lState,
    /* [in] */ ScopeFlags lFlags);


void __RPC_STUB IDBTraceProvider_SetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProvider_GetFilter_Proxy( 
    IDBTraceProvider __RPC_FAR * This,
    /* [in] */ BSTR bstrInterfaceName,
    /* [retval][out] */ TraceState __RPC_FAR *plState);


void __RPC_STUB IDBTraceProvider_GetFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProvider_SetFilter_Proxy( 
    IDBTraceProvider __RPC_FAR * This,
    /* [in] */ BSTR bstrInterfaceName,
    /* [in] */ TraceState lState);


void __RPC_STUB IDBTraceProvider_SetFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceProvider_INTERFACE_DEFINED__ */


#ifndef __IDBTraceProviderEnumerator_INTERFACE_DEFINED__
#define __IDBTraceProviderEnumerator_INTERFACE_DEFINED__

/* interface IDBTraceProviderEnumerator */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceProviderEnumerator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e0adffa2-5743-11d3-b314-00c04f611c75")
    IDBTraceProviderEnumerator : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ long lToFetch,
            /* [length_is][length_is][size_is][size_is][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp,
            /* [out] */ long __RPC_FAR *plFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ long lToSkip) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceProviderEnumeratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceProviderEnumerator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceProviderEnumerator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceProviderEnumerator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDBTraceProviderEnumerator __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDBTraceProviderEnumerator __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDBTraceProviderEnumerator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDBTraceProviderEnumerator __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IDBTraceProviderEnumerator __RPC_FAR * This,
            /* [in] */ long lToFetch,
            /* [length_is][length_is][size_is][size_is][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp,
            /* [out] */ long __RPC_FAR *plFetched);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IDBTraceProviderEnumerator __RPC_FAR * This,
            /* [in] */ long lToSkip);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IDBTraceProviderEnumerator __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IDBTraceProviderEnumerator __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);
        
        END_INTERFACE
    } IDBTraceProviderEnumeratorVtbl;

    interface IDBTraceProviderEnumerator
    {
        CONST_VTBL struct IDBTraceProviderEnumeratorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceProviderEnumerator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceProviderEnumerator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceProviderEnumerator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceProviderEnumerator_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDBTraceProviderEnumerator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDBTraceProviderEnumerator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDBTraceProviderEnumerator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDBTraceProviderEnumerator_Next(This,lToFetch,ppDisp,plFetched)	\
    (This)->lpVtbl -> Next(This,lToFetch,ppDisp,plFetched)

#define IDBTraceProviderEnumerator_Skip(This,lToSkip)	\
    (This)->lpVtbl -> Skip(This,lToSkip)

#define IDBTraceProviderEnumerator_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IDBTraceProviderEnumerator_Clone(This,ppDisp)	\
    (This)->lpVtbl -> Clone(This,ppDisp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProviderEnumerator_Next_Proxy( 
    IDBTraceProviderEnumerator __RPC_FAR * This,
    /* [in] */ long lToFetch,
    /* [length_is][length_is][size_is][size_is][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp,
    /* [out] */ long __RPC_FAR *plFetched);


void __RPC_STUB IDBTraceProviderEnumerator_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProviderEnumerator_Skip_Proxy( 
    IDBTraceProviderEnumerator __RPC_FAR * This,
    /* [in] */ long lToSkip);


void __RPC_STUB IDBTraceProviderEnumerator_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProviderEnumerator_Reset_Proxy( 
    IDBTraceProviderEnumerator __RPC_FAR * This);


void __RPC_STUB IDBTraceProviderEnumerator_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProviderEnumerator_Clone_Proxy( 
    IDBTraceProviderEnumerator __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);


void __RPC_STUB IDBTraceProviderEnumerator_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceProviderEnumerator_INTERFACE_DEFINED__ */


#ifndef __IDBTraceProviderManager_INTERFACE_DEFINED__
#define __IDBTraceProviderManager_INTERFACE_DEFINED__

/* interface IDBTraceProviderManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceProviderManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e0f0c17a-5743-11d3-b314-00c04f611c75")
    IDBTraceProviderManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Lookup( 
            /* [in] */ BSTR bstrProgId,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEnumerator( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFilter( 
            /* [in] */ BSTR bstrInterfaceName,
            /* [retval][out] */ TraceState __RPC_FAR *plState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFilter( 
            /* [in] */ BSTR bstrInterfaceName,
            /* [in] */ TraceState lState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceProviderManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceProviderManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceProviderManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceProviderManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDBTraceProviderManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDBTraceProviderManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDBTraceProviderManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDBTraceProviderManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Lookup )( 
            IDBTraceProviderManager __RPC_FAR * This,
            /* [in] */ BSTR bstrProgId,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumerator )( 
            IDBTraceProviderManager __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFilter )( 
            IDBTraceProviderManager __RPC_FAR * This,
            /* [in] */ BSTR bstrInterfaceName,
            /* [retval][out] */ TraceState __RPC_FAR *plState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFilter )( 
            IDBTraceProviderManager __RPC_FAR * This,
            /* [in] */ BSTR bstrInterfaceName,
            /* [in] */ TraceState lState);
        
        END_INTERFACE
    } IDBTraceProviderManagerVtbl;

    interface IDBTraceProviderManager
    {
        CONST_VTBL struct IDBTraceProviderManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceProviderManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceProviderManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceProviderManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceProviderManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDBTraceProviderManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDBTraceProviderManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDBTraceProviderManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDBTraceProviderManager_Lookup(This,bstrProgId,ppDisp)	\
    (This)->lpVtbl -> Lookup(This,bstrProgId,ppDisp)

#define IDBTraceProviderManager_GetEnumerator(This,ppDisp)	\
    (This)->lpVtbl -> GetEnumerator(This,ppDisp)

#define IDBTraceProviderManager_GetFilter(This,bstrInterfaceName,plState)	\
    (This)->lpVtbl -> GetFilter(This,bstrInterfaceName,plState)

#define IDBTraceProviderManager_SetFilter(This,bstrInterfaceName,lState)	\
    (This)->lpVtbl -> SetFilter(This,bstrInterfaceName,lState)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProviderManager_Lookup_Proxy( 
    IDBTraceProviderManager __RPC_FAR * This,
    /* [in] */ BSTR bstrProgId,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);


void __RPC_STUB IDBTraceProviderManager_Lookup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProviderManager_GetEnumerator_Proxy( 
    IDBTraceProviderManager __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);


void __RPC_STUB IDBTraceProviderManager_GetEnumerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProviderManager_GetFilter_Proxy( 
    IDBTraceProviderManager __RPC_FAR * This,
    /* [in] */ BSTR bstrInterfaceName,
    /* [retval][out] */ TraceState __RPC_FAR *plState);


void __RPC_STUB IDBTraceProviderManager_GetFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceProviderManager_SetFilter_Proxy( 
    IDBTraceProviderManager __RPC_FAR * This,
    /* [in] */ BSTR bstrInterfaceName,
    /* [in] */ TraceState lState);


void __RPC_STUB IDBTraceProviderManager_SetFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceProviderManager_INTERFACE_DEFINED__ */


#ifndef __IDBTraceReceiverControl_INTERFACE_DEFINED__
#define __IDBTraceReceiverControl_INTERFACE_DEFINED__

/* interface IDBTraceReceiverControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceReceiverControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e13aaa60-5743-11d3-b314-00c04f611c75")
    IDBTraceReceiverControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProgId( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrProgId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetState( 
            /* [retval][out] */ TraceState __RPC_FAR *plState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetState( 
            /* [in] */ TraceState lState,
            /* [in] */ ScopeFlags lFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLogFileName( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrLogFileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLogFileName( 
            /* [in] */ BSTR bstrLogFileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceReceiverControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceReceiverControl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceReceiverControl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProgId )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrProgId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetState )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [retval][out] */ TraceState __RPC_FAR *plState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetState )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [in] */ TraceState lState,
            /* [in] */ ScopeFlags lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLogFileName )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrLogFileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLogFileName )( 
            IDBTraceReceiverControl __RPC_FAR * This,
            /* [in] */ BSTR bstrLogFileName);
        
        END_INTERFACE
    } IDBTraceReceiverControlVtbl;

    interface IDBTraceReceiverControl
    {
        CONST_VTBL struct IDBTraceReceiverControlVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceReceiverControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceReceiverControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceReceiverControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceReceiverControl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDBTraceReceiverControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDBTraceReceiverControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDBTraceReceiverControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDBTraceReceiverControl_GetName(This,pbstrName)	\
    (This)->lpVtbl -> GetName(This,pbstrName)

#define IDBTraceReceiverControl_GetProgId(This,pbstrProgId)	\
    (This)->lpVtbl -> GetProgId(This,pbstrProgId)

#define IDBTraceReceiverControl_GetState(This,plState)	\
    (This)->lpVtbl -> GetState(This,plState)

#define IDBTraceReceiverControl_SetState(This,lState,lFlags)	\
    (This)->lpVtbl -> SetState(This,lState,lFlags)

#define IDBTraceReceiverControl_GetLogFileName(This,pbstrLogFileName)	\
    (This)->lpVtbl -> GetLogFileName(This,pbstrLogFileName)

#define IDBTraceReceiverControl_SetLogFileName(This,bstrLogFileName)	\
    (This)->lpVtbl -> SetLogFileName(This,bstrLogFileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverControl_GetName_Proxy( 
    IDBTraceReceiverControl __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrName);


void __RPC_STUB IDBTraceReceiverControl_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverControl_GetProgId_Proxy( 
    IDBTraceReceiverControl __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrProgId);


void __RPC_STUB IDBTraceReceiverControl_GetProgId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverControl_GetState_Proxy( 
    IDBTraceReceiverControl __RPC_FAR * This,
    /* [retval][out] */ TraceState __RPC_FAR *plState);


void __RPC_STUB IDBTraceReceiverControl_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverControl_SetState_Proxy( 
    IDBTraceReceiverControl __RPC_FAR * This,
    /* [in] */ TraceState lState,
    /* [in] */ ScopeFlags lFlags);


void __RPC_STUB IDBTraceReceiverControl_SetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverControl_GetLogFileName_Proxy( 
    IDBTraceReceiverControl __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrLogFileName);


void __RPC_STUB IDBTraceReceiverControl_GetLogFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverControl_SetLogFileName_Proxy( 
    IDBTraceReceiverControl __RPC_FAR * This,
    /* [in] */ BSTR bstrLogFileName);


void __RPC_STUB IDBTraceReceiverControl_SetLogFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceReceiverControl_INTERFACE_DEFINED__ */


#ifndef __IDBTraceReceiverEnumerator_INTERFACE_DEFINED__
#define __IDBTraceReceiverEnumerator_INTERFACE_DEFINED__

/* interface IDBTraceReceiverEnumerator */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceReceiverEnumerator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e17d6c38-5743-11d3-b314-00c04f611c75")
    IDBTraceReceiverEnumerator : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ long lToFetch,
            /* [length_is][length_is][size_is][size_is][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp,
            /* [out] */ long __RPC_FAR *plFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ long lToSkip) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceReceiverEnumeratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This,
            /* [in] */ long lToFetch,
            /* [length_is][length_is][size_is][size_is][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp,
            /* [out] */ long __RPC_FAR *plFetched);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This,
            /* [in] */ long lToSkip);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IDBTraceReceiverEnumerator __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);
        
        END_INTERFACE
    } IDBTraceReceiverEnumeratorVtbl;

    interface IDBTraceReceiverEnumerator
    {
        CONST_VTBL struct IDBTraceReceiverEnumeratorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceReceiverEnumerator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceReceiverEnumerator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceReceiverEnumerator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceReceiverEnumerator_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDBTraceReceiverEnumerator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDBTraceReceiverEnumerator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDBTraceReceiverEnumerator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDBTraceReceiverEnumerator_Next(This,lToFetch,ppDisp,plFetched)	\
    (This)->lpVtbl -> Next(This,lToFetch,ppDisp,plFetched)

#define IDBTraceReceiverEnumerator_Skip(This,lToSkip)	\
    (This)->lpVtbl -> Skip(This,lToSkip)

#define IDBTraceReceiverEnumerator_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IDBTraceReceiverEnumerator_Clone(This,ppDisp)	\
    (This)->lpVtbl -> Clone(This,ppDisp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverEnumerator_Next_Proxy( 
    IDBTraceReceiverEnumerator __RPC_FAR * This,
    /* [in] */ long lToFetch,
    /* [length_is][length_is][size_is][size_is][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp,
    /* [out] */ long __RPC_FAR *plFetched);


void __RPC_STUB IDBTraceReceiverEnumerator_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverEnumerator_Skip_Proxy( 
    IDBTraceReceiverEnumerator __RPC_FAR * This,
    /* [in] */ long lToSkip);


void __RPC_STUB IDBTraceReceiverEnumerator_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverEnumerator_Reset_Proxy( 
    IDBTraceReceiverEnumerator __RPC_FAR * This);


void __RPC_STUB IDBTraceReceiverEnumerator_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverEnumerator_Clone_Proxy( 
    IDBTraceReceiverEnumerator __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);


void __RPC_STUB IDBTraceReceiverEnumerator_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceReceiverEnumerator_INTERFACE_DEFINED__ */


#ifndef __IDBTraceReceiverManager_INTERFACE_DEFINED__
#define __IDBTraceReceiverManager_INTERFACE_DEFINED__

/* interface IDBTraceReceiverManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceReceiverManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e1cc19d2-5743-11d3-b314-00c04f611c75")
    IDBTraceReceiverManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Lookup( 
            /* [in] */ BSTR bstrProgId,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEnumerator( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IDispatch __RPC_FAR *piDisp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceReceiverManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceReceiverManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceReceiverManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceReceiverManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDBTraceReceiverManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDBTraceReceiverManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDBTraceReceiverManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDBTraceReceiverManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Lookup )( 
            IDBTraceReceiverManager __RPC_FAR * This,
            /* [in] */ BSTR bstrProgId,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumerator )( 
            IDBTraceReceiverManager __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IDBTraceReceiverManager __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *piDisp);
        
        END_INTERFACE
    } IDBTraceReceiverManagerVtbl;

    interface IDBTraceReceiverManager
    {
        CONST_VTBL struct IDBTraceReceiverManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceReceiverManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceReceiverManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceReceiverManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceReceiverManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDBTraceReceiverManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDBTraceReceiverManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDBTraceReceiverManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDBTraceReceiverManager_Lookup(This,bstrProgId,ppDisp)	\
    (This)->lpVtbl -> Lookup(This,bstrProgId,ppDisp)

#define IDBTraceReceiverManager_GetEnumerator(This,ppDisp)	\
    (This)->lpVtbl -> GetEnumerator(This,ppDisp)

#define IDBTraceReceiverManager_Add(This,piDisp)	\
    (This)->lpVtbl -> Add(This,piDisp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverManager_Lookup_Proxy( 
    IDBTraceReceiverManager __RPC_FAR * This,
    /* [in] */ BSTR bstrProgId,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);


void __RPC_STUB IDBTraceReceiverManager_Lookup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverManager_GetEnumerator_Proxy( 
    IDBTraceReceiverManager __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDisp);


void __RPC_STUB IDBTraceReceiverManager_GetEnumerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiverManager_Add_Proxy( 
    IDBTraceReceiverManager __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *piDisp);


void __RPC_STUB IDBTraceReceiverManager_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceReceiverManager_INTERFACE_DEFINED__ */


#ifndef __IDBTraceReceiver_INTERFACE_DEFINED__
#define __IDBTraceReceiver_INTERFACE_DEFINED__

/* interface IDBTraceReceiver */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceReceiver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29d82de3-2bdb-11d2-90e1-00805fc752eb")
    IDBTraceReceiver : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ LPUNKNOWN pUnknown) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Uninitialize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCLSID( 
            /* [retval][out] */ LPVARIANT pvCLSIDString) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceReceiverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceReceiver __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceReceiver __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceReceiver __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDBTraceReceiver __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDBTraceReceiver __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDBTraceReceiver __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDBTraceReceiver __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            IDBTraceReceiver __RPC_FAR * This,
            /* [in] */ LPUNKNOWN pUnknown);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Uninitialize )( 
            IDBTraceReceiver __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCLSID )( 
            IDBTraceReceiver __RPC_FAR * This,
            /* [retval][out] */ LPVARIANT pvCLSIDString);
        
        END_INTERFACE
    } IDBTraceReceiverVtbl;

    interface IDBTraceReceiver
    {
        CONST_VTBL struct IDBTraceReceiverVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceReceiver_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceReceiver_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceReceiver_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceReceiver_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDBTraceReceiver_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDBTraceReceiver_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDBTraceReceiver_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDBTraceReceiver_Initialize(This,pUnknown)	\
    (This)->lpVtbl -> Initialize(This,pUnknown)

#define IDBTraceReceiver_Uninitialize(This)	\
    (This)->lpVtbl -> Uninitialize(This)

#define IDBTraceReceiver_GetCLSID(This,pvCLSIDString)	\
    (This)->lpVtbl -> GetCLSID(This,pvCLSIDString)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiver_Initialize_Proxy( 
    IDBTraceReceiver __RPC_FAR * This,
    /* [in] */ LPUNKNOWN pUnknown);


void __RPC_STUB IDBTraceReceiver_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiver_Uninitialize_Proxy( 
    IDBTraceReceiver __RPC_FAR * This);


void __RPC_STUB IDBTraceReceiver_Uninitialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceReceiver_GetCLSID_Proxy( 
    IDBTraceReceiver __RPC_FAR * This,
    /* [retval][out] */ LPVARIANT pvCLSIDString);


void __RPC_STUB IDBTraceReceiver_GetCLSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceReceiver_INTERFACE_DEFINED__ */


#ifndef __IDBTraceNotify_INTERFACE_DEFINED__
#define __IDBTraceNotify_INTERFACE_DEFINED__

/* interface IDBTraceNotify */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29d82de4-2bdb-11d2-90e1-00805fc752eb")
    IDBTraceNotify : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnPackageReady( 
            /* [in] */ DBLENGTH cbPackageDataLen,
            /* [size_is][in] */ BYTE __RPC_FAR *pPackageData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceNotify __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceNotify __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceNotify __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPackageReady )( 
            IDBTraceNotify __RPC_FAR * This,
            /* [in] */ DBLENGTH cbPackageDataLen,
            /* [size_is][in] */ BYTE __RPC_FAR *pPackageData);
        
        END_INTERFACE
    } IDBTraceNotifyVtbl;

    interface IDBTraceNotify
    {
        CONST_VTBL struct IDBTraceNotifyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceNotify_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceNotify_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceNotify_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceNotify_OnPackageReady(This,cbPackageDataLen,pPackageData)	\
    (This)->lpVtbl -> OnPackageReady(This,cbPackageDataLen,pPackageData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceNotify_OnPackageReady_Proxy( 
    IDBTraceNotify __RPC_FAR * This,
    /* [in] */ DBLENGTH cbPackageDataLen,
    /* [size_is][in] */ BYTE __RPC_FAR *pPackageData);


void __RPC_STUB IDBTraceNotify_OnPackageReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceNotify_INTERFACE_DEFINED__ */


#ifndef __IDBTraceEnumParameters_INTERFACE_DEFINED__
#define __IDBTraceEnumParameters_INTERFACE_DEFINED__

/* interface IDBTraceEnumParameters */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceEnumParameters;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29d82ded-2bdb-11d2-90e1-00805fc752eb")
    IDBTraceEnumParameters : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cParameters,
            /* [size_is][out] */ IDBTraceParameter __RPC_FAR *__RPC_FAR *rgpParameters,
            /* [out] */ ULONG __RPC_FAR *pcFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cParameters) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IDBTraceEnumParameters __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceEnumParametersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceEnumParameters __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceEnumParameters __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceEnumParameters __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IDBTraceEnumParameters __RPC_FAR * This,
            /* [in] */ ULONG cParameters,
            /* [size_is][out] */ IDBTraceParameter __RPC_FAR *__RPC_FAR *rgpParameters,
            /* [out] */ ULONG __RPC_FAR *pcFetched);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IDBTraceEnumParameters __RPC_FAR * This,
            /* [in] */ ULONG cParameters);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IDBTraceEnumParameters __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IDBTraceEnumParameters __RPC_FAR * This,
            /* [out] */ IDBTraceEnumParameters __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IDBTraceEnumParametersVtbl;

    interface IDBTraceEnumParameters
    {
        CONST_VTBL struct IDBTraceEnumParametersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceEnumParameters_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceEnumParameters_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceEnumParameters_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceEnumParameters_Next(This,cParameters,rgpParameters,pcFetched)	\
    (This)->lpVtbl -> Next(This,cParameters,rgpParameters,pcFetched)

#define IDBTraceEnumParameters_Skip(This,cParameters)	\
    (This)->lpVtbl -> Skip(This,cParameters)

#define IDBTraceEnumParameters_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IDBTraceEnumParameters_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceEnumParameters_Next_Proxy( 
    IDBTraceEnumParameters __RPC_FAR * This,
    /* [in] */ ULONG cParameters,
    /* [size_is][out] */ IDBTraceParameter __RPC_FAR *__RPC_FAR *rgpParameters,
    /* [out] */ ULONG __RPC_FAR *pcFetched);


void __RPC_STUB IDBTraceEnumParameters_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceEnumParameters_Skip_Proxy( 
    IDBTraceEnumParameters __RPC_FAR * This,
    /* [in] */ ULONG cParameters);


void __RPC_STUB IDBTraceEnumParameters_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceEnumParameters_Reset_Proxy( 
    IDBTraceEnumParameters __RPC_FAR * This);


void __RPC_STUB IDBTraceEnumParameters_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceEnumParameters_Clone_Proxy( 
    IDBTraceEnumParameters __RPC_FAR * This,
    /* [out] */ IDBTraceEnumParameters __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDBTraceEnumParameters_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceEnumParameters_INTERFACE_DEFINED__ */


#ifndef __IDBTracePackage_INTERFACE_DEFINED__
#define __IDBTracePackage_INTERFACE_DEFINED__

/* interface IDBTracePackage */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDBTracePackage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29d82de5-2bdb-11d2-90e1-00805fc752eb")
    IDBTracePackage : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ DBLENGTH cbPackageDataLen,
            /* [size_is][in] */ BYTE __RPC_FAR *pPackageData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Detach( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPackageContext( 
            /* [in] */ DBTRACEINFO __RPC_FAR *pTraceInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumParameters( 
            /* [out] */ IDBTraceEnumParameters __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParameterAt( 
            /* [in] */ DBORDINAL iParameter,
            /* [out] */ IDBTraceParameter __RPC_FAR *__RPC_FAR *ppIParameter) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Persist( 
            /* [in] */ IStream __RPC_FAR *pIStream) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NameFromID( 
            /* [in] */ DBORDINAL dwInfoID,
            /* [out] */ BSTR __RPC_FAR *bstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResultString( 
            /* [in] */ DBORDINAL dwMethodID,
            /* [in] */ HRESULT hr,
            /* [out] */ BSTR __RPC_FAR *bstrResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTracePackageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTracePackage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTracePackage __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTracePackage __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Attach )( 
            IDBTracePackage __RPC_FAR * This,
            /* [in] */ DBLENGTH cbPackageDataLen,
            /* [size_is][in] */ BYTE __RPC_FAR *pPackageData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Detach )( 
            IDBTracePackage __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPackageContext )( 
            IDBTracePackage __RPC_FAR * This,
            /* [in] */ DBTRACEINFO __RPC_FAR *pTraceInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumParameters )( 
            IDBTracePackage __RPC_FAR * This,
            /* [out] */ IDBTraceEnumParameters __RPC_FAR *__RPC_FAR *ppEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParameterAt )( 
            IDBTracePackage __RPC_FAR * This,
            /* [in] */ DBORDINAL iParameter,
            /* [out] */ IDBTraceParameter __RPC_FAR *__RPC_FAR *ppIParameter);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Persist )( 
            IDBTracePackage __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *pIStream);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NameFromID )( 
            IDBTracePackage __RPC_FAR * This,
            /* [in] */ DBORDINAL dwInfoID,
            /* [out] */ BSTR __RPC_FAR *bstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResultString )( 
            IDBTracePackage __RPC_FAR * This,
            /* [in] */ DBORDINAL dwMethodID,
            /* [in] */ HRESULT hr,
            /* [out] */ BSTR __RPC_FAR *bstrResult);
        
        END_INTERFACE
    } IDBTracePackageVtbl;

    interface IDBTracePackage
    {
        CONST_VTBL struct IDBTracePackageVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTracePackage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTracePackage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTracePackage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTracePackage_Attach(This,cbPackageDataLen,pPackageData)	\
    (This)->lpVtbl -> Attach(This,cbPackageDataLen,pPackageData)

#define IDBTracePackage_Detach(This)	\
    (This)->lpVtbl -> Detach(This)

#define IDBTracePackage_GetPackageContext(This,pTraceInfo)	\
    (This)->lpVtbl -> GetPackageContext(This,pTraceInfo)

#define IDBTracePackage_EnumParameters(This,ppEnum)	\
    (This)->lpVtbl -> EnumParameters(This,ppEnum)

#define IDBTracePackage_GetParameterAt(This,iParameter,ppIParameter)	\
    (This)->lpVtbl -> GetParameterAt(This,iParameter,ppIParameter)

#define IDBTracePackage_Persist(This,pIStream)	\
    (This)->lpVtbl -> Persist(This,pIStream)

#define IDBTracePackage_NameFromID(This,dwInfoID,bstrName)	\
    (This)->lpVtbl -> NameFromID(This,dwInfoID,bstrName)

#define IDBTracePackage_GetResultString(This,dwMethodID,hr,bstrResult)	\
    (This)->lpVtbl -> GetResultString(This,dwMethodID,hr,bstrResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTracePackage_Attach_Proxy( 
    IDBTracePackage __RPC_FAR * This,
    /* [in] */ DBLENGTH cbPackageDataLen,
    /* [size_is][in] */ BYTE __RPC_FAR *pPackageData);


void __RPC_STUB IDBTracePackage_Attach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTracePackage_Detach_Proxy( 
    IDBTracePackage __RPC_FAR * This);


void __RPC_STUB IDBTracePackage_Detach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTracePackage_GetPackageContext_Proxy( 
    IDBTracePackage __RPC_FAR * This,
    /* [in] */ DBTRACEINFO __RPC_FAR *pTraceInfo);


void __RPC_STUB IDBTracePackage_GetPackageContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTracePackage_EnumParameters_Proxy( 
    IDBTracePackage __RPC_FAR * This,
    /* [out] */ IDBTraceEnumParameters __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDBTracePackage_EnumParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTracePackage_GetParameterAt_Proxy( 
    IDBTracePackage __RPC_FAR * This,
    /* [in] */ DBORDINAL iParameter,
    /* [out] */ IDBTraceParameter __RPC_FAR *__RPC_FAR *ppIParameter);


void __RPC_STUB IDBTracePackage_GetParameterAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTracePackage_Persist_Proxy( 
    IDBTracePackage __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *pIStream);


void __RPC_STUB IDBTracePackage_Persist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTracePackage_NameFromID_Proxy( 
    IDBTracePackage __RPC_FAR * This,
    /* [in] */ DBORDINAL dwInfoID,
    /* [out] */ BSTR __RPC_FAR *bstrName);


void __RPC_STUB IDBTracePackage_NameFromID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTracePackage_GetResultString_Proxy( 
    IDBTracePackage __RPC_FAR * This,
    /* [in] */ DBORDINAL dwMethodID,
    /* [in] */ HRESULT hr,
    /* [out] */ BSTR __RPC_FAR *bstrResult);


void __RPC_STUB IDBTracePackage_GetResultString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTracePackage_INTERFACE_DEFINED__ */


#ifndef __IDBTraceParameter_INTERFACE_DEFINED__
#define __IDBTraceParameter_INTERFACE_DEFINED__

/* interface IDBTraceParameter */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceParameter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29d82de6-2bdb-11d2-90e1-00805fc752eb")
    IDBTraceParameter : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParameterContext( 
            /* [in] */ DBTRACEPARAMINFO __RPC_FAR *pTraceParamInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumStructElements( 
            /* [out] */ IDBTraceEnumParameters __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsStruct( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR __RPC_FAR *bstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLinkedName( 
            /* [in] */ DBORDINAL paramNumber,
            /* [out] */ BSTR __RPC_FAR *bstrName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceParameterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceParameter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceParameter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceParameter __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParameterContext )( 
            IDBTraceParameter __RPC_FAR * This,
            /* [in] */ DBTRACEPARAMINFO __RPC_FAR *pTraceParamInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumStructElements )( 
            IDBTraceParameter __RPC_FAR * This,
            /* [out] */ IDBTraceEnumParameters __RPC_FAR *__RPC_FAR *ppEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsStruct )( 
            IDBTraceParameter __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IDBTraceParameter __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *bstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLinkedName )( 
            IDBTraceParameter __RPC_FAR * This,
            /* [in] */ DBORDINAL paramNumber,
            /* [out] */ BSTR __RPC_FAR *bstrName);
        
        END_INTERFACE
    } IDBTraceParameterVtbl;

    interface IDBTraceParameter
    {
        CONST_VTBL struct IDBTraceParameterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceParameter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceParameter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceParameter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceParameter_GetParameterContext(This,pTraceParamInfo)	\
    (This)->lpVtbl -> GetParameterContext(This,pTraceParamInfo)

#define IDBTraceParameter_EnumStructElements(This,ppEnum)	\
    (This)->lpVtbl -> EnumStructElements(This,ppEnum)

#define IDBTraceParameter_IsStruct(This)	\
    (This)->lpVtbl -> IsStruct(This)

#define IDBTraceParameter_GetName(This,bstrName)	\
    (This)->lpVtbl -> GetName(This,bstrName)

#define IDBTraceParameter_GetLinkedName(This,paramNumber,bstrName)	\
    (This)->lpVtbl -> GetLinkedName(This,paramNumber,bstrName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceParameter_GetParameterContext_Proxy( 
    IDBTraceParameter __RPC_FAR * This,
    /* [in] */ DBTRACEPARAMINFO __RPC_FAR *pTraceParamInfo);


void __RPC_STUB IDBTraceParameter_GetParameterContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceParameter_EnumStructElements_Proxy( 
    IDBTraceParameter __RPC_FAR * This,
    /* [out] */ IDBTraceEnumParameters __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDBTraceParameter_EnumStructElements_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceParameter_IsStruct_Proxy( 
    IDBTraceParameter __RPC_FAR * This);


void __RPC_STUB IDBTraceParameter_IsStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceParameter_GetName_Proxy( 
    IDBTraceParameter __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *bstrName);


void __RPC_STUB IDBTraceParameter_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceParameter_GetLinkedName_Proxy( 
    IDBTraceParameter __RPC_FAR * This,
    /* [in] */ DBORDINAL paramNumber,
    /* [out] */ BSTR __RPC_FAR *bstrName);


void __RPC_STUB IDBTraceParameter_GetLinkedName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceParameter_INTERFACE_DEFINED__ */


#ifndef __IDBTraceInterpreter_INTERFACE_DEFINED__
#define __IDBTraceInterpreter_INTERFACE_DEFINED__

/* interface IDBTraceInterpreter */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDBTraceInterpreter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29d82de7-2bdb-11d2-90e1-00805fc752eb")
    IDBTraceInterpreter : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NameFromID( 
            /* [in] */ DWORD dwProcessID,
            /* [in] */ DWORD dwThreadID,
            /* [in] */ DBORDINAL dwInfoID,
            /* [out] */ BSTR __RPC_FAR *bstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SubItemCount( 
            /* [in] */ DBORDINAL dwInfoID,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pdwCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateNewPackage( 
            /* [out] */ IDBTracePackage __RPC_FAR *__RPC_FAR *ppIDBTracePackage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEnumString( 
            /* [in] */ LONG lEnumTypeID,
            /* [in] */ LONG lEnumNumericalValue,
            /* [out] */ BSTR __RPC_FAR *pbstrEnumString) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDBTraceInterpreterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDBTraceInterpreter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDBTraceInterpreter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDBTraceInterpreter __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NameFromID )( 
            IDBTraceInterpreter __RPC_FAR * This,
            /* [in] */ DWORD dwProcessID,
            /* [in] */ DWORD dwThreadID,
            /* [in] */ DBORDINAL dwInfoID,
            /* [out] */ BSTR __RPC_FAR *bstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SubItemCount )( 
            IDBTraceInterpreter __RPC_FAR * This,
            /* [in] */ DBORDINAL dwInfoID,
            /* [out] */ DBCOUNTITEM __RPC_FAR *pdwCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateNewPackage )( 
            IDBTraceInterpreter __RPC_FAR * This,
            /* [out] */ IDBTracePackage __RPC_FAR *__RPC_FAR *ppIDBTracePackage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumString )( 
            IDBTraceInterpreter __RPC_FAR * This,
            /* [in] */ LONG lEnumTypeID,
            /* [in] */ LONG lEnumNumericalValue,
            /* [out] */ BSTR __RPC_FAR *pbstrEnumString);
        
        END_INTERFACE
    } IDBTraceInterpreterVtbl;

    interface IDBTraceInterpreter
    {
        CONST_VTBL struct IDBTraceInterpreterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDBTraceInterpreter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDBTraceInterpreter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDBTraceInterpreter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDBTraceInterpreter_NameFromID(This,dwProcessID,dwThreadID,dwInfoID,bstrName)	\
    (This)->lpVtbl -> NameFromID(This,dwProcessID,dwThreadID,dwInfoID,bstrName)

#define IDBTraceInterpreter_SubItemCount(This,dwInfoID,pdwCount)	\
    (This)->lpVtbl -> SubItemCount(This,dwInfoID,pdwCount)

#define IDBTraceInterpreter_CreateNewPackage(This,ppIDBTracePackage)	\
    (This)->lpVtbl -> CreateNewPackage(This,ppIDBTracePackage)

#define IDBTraceInterpreter_GetEnumString(This,lEnumTypeID,lEnumNumericalValue,pbstrEnumString)	\
    (This)->lpVtbl -> GetEnumString(This,lEnumTypeID,lEnumNumericalValue,pbstrEnumString)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceInterpreter_NameFromID_Proxy( 
    IDBTraceInterpreter __RPC_FAR * This,
    /* [in] */ DWORD dwProcessID,
    /* [in] */ DWORD dwThreadID,
    /* [in] */ DBORDINAL dwInfoID,
    /* [out] */ BSTR __RPC_FAR *bstrName);


void __RPC_STUB IDBTraceInterpreter_NameFromID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceInterpreter_SubItemCount_Proxy( 
    IDBTraceInterpreter __RPC_FAR * This,
    /* [in] */ DBORDINAL dwInfoID,
    /* [out] */ DBCOUNTITEM __RPC_FAR *pdwCount);


void __RPC_STUB IDBTraceInterpreter_SubItemCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceInterpreter_CreateNewPackage_Proxy( 
    IDBTraceInterpreter __RPC_FAR * This,
    /* [out] */ IDBTracePackage __RPC_FAR *__RPC_FAR *ppIDBTracePackage);


void __RPC_STUB IDBTraceInterpreter_CreateNewPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDBTraceInterpreter_GetEnumString_Proxy( 
    IDBTraceInterpreter __RPC_FAR * This,
    /* [in] */ LONG lEnumTypeID,
    /* [in] */ LONG lEnumNumericalValue,
    /* [out] */ BSTR __RPC_FAR *pbstrEnumString);


void __RPC_STUB IDBTraceInterpreter_GetEnumString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDBTraceInterpreter_INTERFACE_DEFINED__ */


#ifndef __IProviderEnum_INTERFACE_DEFINED__
#define __IProviderEnum_INTERFACE_DEFINED__

/* interface IProviderEnum */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IProviderEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29d82ddf-2bdb-11d2-90e1-00805fc752eb")
    IProviderEnum : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRegisteredProviders( 
            /* [retval][out] */ LPVARIANT pvProviders) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTraceProviderCLSID( 
            /* [retval][out] */ LPVARIANT pvCLSIDString) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProviderEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IProviderEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IProviderEnum __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IProviderEnum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IProviderEnum __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IProviderEnum __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IProviderEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IProviderEnum __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRegisteredProviders )( 
            IProviderEnum __RPC_FAR * This,
            /* [retval][out] */ LPVARIANT pvProviders);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTraceProviderCLSID )( 
            IProviderEnum __RPC_FAR * This,
            /* [retval][out] */ LPVARIANT pvCLSIDString);
        
        END_INTERFACE
    } IProviderEnumVtbl;

    interface IProviderEnum
    {
        CONST_VTBL struct IProviderEnumVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProviderEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProviderEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProviderEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProviderEnum_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IProviderEnum_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IProviderEnum_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IProviderEnum_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IProviderEnum_GetRegisteredProviders(This,pvProviders)	\
    (This)->lpVtbl -> GetRegisteredProviders(This,pvProviders)

#define IProviderEnum_GetTraceProviderCLSID(This,pvCLSIDString)	\
    (This)->lpVtbl -> GetTraceProviderCLSID(This,pvCLSIDString)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IProviderEnum_GetRegisteredProviders_Proxy( 
    IProviderEnum __RPC_FAR * This,
    /* [retval][out] */ LPVARIANT pvProviders);


void __RPC_STUB IProviderEnum_GetRegisteredProviders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IProviderEnum_GetTraceProviderCLSID_Proxy( 
    IProviderEnum __RPC_FAR * This,
    /* [retval][out] */ LPVARIANT pvCLSIDString);


void __RPC_STUB IProviderEnum_GetTraceProviderCLSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IProviderEnum_INTERFACE_DEFINED__ */



#ifndef __TraceProviderLib_LIBRARY_DEFINED__
#define __TraceProviderLib_LIBRARY_DEFINED__

/* library TraceProviderLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TraceProviderLib;

EXTERN_C const CLSID CLSID_TraceControl;

#ifdef __cplusplus

class DECLSPEC_UUID("29d82de9-2bdb-11d2-90e1-00805fc752eb")
TraceControl;
#endif

EXTERN_C const CLSID CLSID_Tracer;

#ifdef __cplusplus

class DECLSPEC_UUID("29d82dea-2bdb-11d2-90e1-00805fc752eb")
Tracer;
#endif

EXTERN_C const CLSID CLSID_TraceReceiver;

#ifdef __cplusplus

class DECLSPEC_UUID("29d82deb-2bdb-11d2-90e1-00805fc752eb")
TraceReceiver;
#endif

EXTERN_C const CLSID CLSID_TraceInterpreter;

#ifdef __cplusplus

class DECLSPEC_UUID("29d82dec-2bdb-11d2-90e1-00805fc752eb")
TraceInterpreter;
#endif

EXTERN_C const CLSID CLSID_ProviderEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("29d82de1-2bdb-11d2-90e1-00805fc752eb")
ProviderEnum;
#endif
#endif /* __TraceProviderLib_LIBRARY_DEFINED__ */

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


