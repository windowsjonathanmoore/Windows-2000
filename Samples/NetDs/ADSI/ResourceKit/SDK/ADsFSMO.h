/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Oct 23 16:50:55 1999
 */
/* Compiler settings for D:\PROJECTS\ADsFSMO\ADsFSMO.idl:
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

#ifndef __ADsFSMO_h__
#define __ADsFSMO_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IADsFSMO_FWD_DEFINED__
#define __IADsFSMO_FWD_DEFINED__
typedef interface IADsFSMO IADsFSMO;
#endif 	/* __IADsFSMO_FWD_DEFINED__ */


#ifndef __ADsFSMO_FWD_DEFINED__
#define __ADsFSMO_FWD_DEFINED__

#ifdef __cplusplus
typedef class ADsFSMO ADsFSMO;
#else
typedef struct ADsFSMO ADsFSMO;
#endif /* __cplusplus */

#endif 	/* __ADsFSMO_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IADsFSMO_INTERFACE_DEFINED__
#define __IADsFSMO_INTERFACE_DEFINED__

/* interface IADsFSMO */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IADsFSMO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("85E84C1E-174F-4143-9868-BA52AFFF53FB")
    IADsFSMO : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PDCRoleOwner( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PDCRoleOwner( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SchemaRoleOwner( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SchemaRoleOwner( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ BSTR bstrServerOrDomain,
            /* [optional][in] */ VARIANT varUserName,
            /* [optional][in] */ VARIANT varPassword) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RIDRoleOwner( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RIDRoleOwner( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainRoleOwner( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DomainRoleOwner( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfrastructureRoleOwner( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InfrastructureRoleOwner( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADsFSMOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IADsFSMO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IADsFSMO __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IADsFSMO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IADsFSMO __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IADsFSMO __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IADsFSMO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IADsFSMO __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PDCRoleOwner )( 
            IADsFSMO __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PDCRoleOwner )( 
            IADsFSMO __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SchemaRoleOwner )( 
            IADsFSMO __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SchemaRoleOwner )( 
            IADsFSMO __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IADsFSMO __RPC_FAR * This,
            /* [in] */ BSTR bstrServerOrDomain,
            /* [optional][in] */ VARIANT varUserName,
            /* [optional][in] */ VARIANT varPassword);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RIDRoleOwner )( 
            IADsFSMO __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RIDRoleOwner )( 
            IADsFSMO __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DomainRoleOwner )( 
            IADsFSMO __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DomainRoleOwner )( 
            IADsFSMO __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_InfrastructureRoleOwner )( 
            IADsFSMO __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_InfrastructureRoleOwner )( 
            IADsFSMO __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IADsFSMOVtbl;

    interface IADsFSMO
    {
        CONST_VTBL struct IADsFSMOVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADsFSMO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADsFSMO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADsFSMO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADsFSMO_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADsFSMO_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADsFSMO_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADsFSMO_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADsFSMO_get_PDCRoleOwner(This,pVal)	\
    (This)->lpVtbl -> get_PDCRoleOwner(This,pVal)

#define IADsFSMO_put_PDCRoleOwner(This,newVal)	\
    (This)->lpVtbl -> put_PDCRoleOwner(This,newVal)

#define IADsFSMO_get_SchemaRoleOwner(This,pVal)	\
    (This)->lpVtbl -> get_SchemaRoleOwner(This,pVal)

#define IADsFSMO_put_SchemaRoleOwner(This,newVal)	\
    (This)->lpVtbl -> put_SchemaRoleOwner(This,newVal)

#define IADsFSMO_Connect(This,bstrServerOrDomain,varUserName,varPassword)	\
    (This)->lpVtbl -> Connect(This,bstrServerOrDomain,varUserName,varPassword)

#define IADsFSMO_get_RIDRoleOwner(This,pVal)	\
    (This)->lpVtbl -> get_RIDRoleOwner(This,pVal)

#define IADsFSMO_put_RIDRoleOwner(This,newVal)	\
    (This)->lpVtbl -> put_RIDRoleOwner(This,newVal)

#define IADsFSMO_get_DomainRoleOwner(This,pVal)	\
    (This)->lpVtbl -> get_DomainRoleOwner(This,pVal)

#define IADsFSMO_put_DomainRoleOwner(This,newVal)	\
    (This)->lpVtbl -> put_DomainRoleOwner(This,newVal)

#define IADsFSMO_get_InfrastructureRoleOwner(This,pVal)	\
    (This)->lpVtbl -> get_InfrastructureRoleOwner(This,pVal)

#define IADsFSMO_put_InfrastructureRoleOwner(This,newVal)	\
    (This)->lpVtbl -> put_InfrastructureRoleOwner(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsFSMO_get_PDCRoleOwner_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsFSMO_get_PDCRoleOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IADsFSMO_put_PDCRoleOwner_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IADsFSMO_put_PDCRoleOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsFSMO_get_SchemaRoleOwner_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsFSMO_get_SchemaRoleOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IADsFSMO_put_SchemaRoleOwner_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IADsFSMO_put_SchemaRoleOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsFSMO_Connect_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [in] */ BSTR bstrServerOrDomain,
    /* [optional][in] */ VARIANT varUserName,
    /* [optional][in] */ VARIANT varPassword);


void __RPC_STUB IADsFSMO_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsFSMO_get_RIDRoleOwner_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsFSMO_get_RIDRoleOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IADsFSMO_put_RIDRoleOwner_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IADsFSMO_put_RIDRoleOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsFSMO_get_DomainRoleOwner_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsFSMO_get_DomainRoleOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IADsFSMO_put_DomainRoleOwner_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IADsFSMO_put_DomainRoleOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IADsFSMO_get_InfrastructureRoleOwner_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IADsFSMO_get_InfrastructureRoleOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IADsFSMO_put_InfrastructureRoleOwner_Proxy( 
    IADsFSMO __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IADsFSMO_put_InfrastructureRoleOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADsFSMO_INTERFACE_DEFINED__ */



#ifndef __ADSFSMOLib_LIBRARY_DEFINED__
#define __ADSFSMOLib_LIBRARY_DEFINED__

/* library ADSFSMOLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ADSFSMOLib;

EXTERN_C const CLSID CLSID_ADsFSMO;

#ifdef __cplusplus

class DECLSPEC_UUID("2405C2CE-3C6B-4D81-8E0F-D9EEDD34A51C")
ADsFSMO;
#endif
#endif /* __ADSFSMOLib_LIBRARY_DEFINED__ */

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
