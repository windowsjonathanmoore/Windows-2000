/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Sep 27 13:59:14 1999
 */
/* Compiler settings for D:\Projects\ADsEncode\ADsEncode.idl:
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

#ifndef __ADsEncode_h__
#define __ADsEncode_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IADsEncode_FWD_DEFINED__
#define __IADsEncode_FWD_DEFINED__
typedef interface IADsEncode IADsEncode;
#endif 	/* __IADsEncode_FWD_DEFINED__ */


#ifndef __ADsEncode_FWD_DEFINED__
#define __ADsEncode_FWD_DEFINED__

#ifdef __cplusplus
typedef class ADsEncode ADsEncode;
#else
typedef struct ADsEncode ADsEncode;
#endif /* __cplusplus */

#endif 	/* __ADsEncode_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IADsEncode_INTERFACE_DEFINED__
#define __IADsEncode_INTERFACE_DEFINED__

/* interface IADsEncode */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IADsEncode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("42AC9C8E-7CCC-40A4-A4D3-6C4AD6391E5B")
    IADsEncode : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EncodeBinary( 
            /* [in] */ VARIANT varData,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecodeBinary( 
            /* [in] */ BSTR bstData,
            /* [out][retval] */ VARIANT __RPC_FAR *pVarResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADsEncodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IADsEncode __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IADsEncode __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IADsEncode __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IADsEncode __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IADsEncode __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IADsEncode __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IADsEncode __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EncodeBinary )( 
            IADsEncode __RPC_FAR * This,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DecodeBinary )( 
            IADsEncode __RPC_FAR * This,
            /* [in] */ BSTR bstData,
            /* [out][retval] */ VARIANT __RPC_FAR *pVarResult);
        
        END_INTERFACE
    } IADsEncodeVtbl;

    interface IADsEncode
    {
        CONST_VTBL struct IADsEncodeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADsEncode_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADsEncode_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADsEncode_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADsEncode_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADsEncode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADsEncode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADsEncode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADsEncode_EncodeBinary(This,varData,pbstrData)	\
    (This)->lpVtbl -> EncodeBinary(This,varData,pbstrData)

#define IADsEncode_DecodeBinary(This,bstData,pVarResult)	\
    (This)->lpVtbl -> DecodeBinary(This,bstData,pVarResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsEncode_EncodeBinary_Proxy( 
    IADsEncode __RPC_FAR * This,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrData);


void __RPC_STUB IADsEncode_EncodeBinary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADsEncode_DecodeBinary_Proxy( 
    IADsEncode __RPC_FAR * This,
    /* [in] */ BSTR bstData,
    /* [out][retval] */ VARIANT __RPC_FAR *pVarResult);


void __RPC_STUB IADsEncode_DecodeBinary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADsEncode_INTERFACE_DEFINED__ */



#ifndef __ADSENCODELib_LIBRARY_DEFINED__
#define __ADSENCODELib_LIBRARY_DEFINED__

/* library ADSENCODELib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ADSENCODELib;

EXTERN_C const CLSID CLSID_ADsEncode;

#ifdef __cplusplus

class DECLSPEC_UUID("69F8B370-4B3C-49D5-BB5E-3558000279DA")
ADsEncode;
#endif
#endif /* __ADSENCODELib_LIBRARY_DEFINED__ */

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
