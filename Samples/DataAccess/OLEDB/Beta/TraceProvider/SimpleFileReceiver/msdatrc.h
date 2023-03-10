//-----------------------------------------------------------------------------------
// @PRODUCT:	Microsoft OLE DB Trace Provider
// @CPYRGHT:	Copyright (C) Microsoft Corporation, 1998 - 2000
//
// @module MSDATRC.H | Providers CLSIDs
//
//

#ifndef __TRACEGUIDS__
#define __TRACEGUIDS__

typedef enum {
	eOpUnknown	= 1,
	eOpPre		= 2,
	eOpPost		= 3,
	eOpGUID		= 4		// this code is provided for collection of informational packages containing GUIDs
} EOPTIME;


#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}


MIDL_DEFINE_GUID(IID, IID_IDBTraceProvider,0xe068db70,0x5743,0x11d3,0xb3,0x14,0x00,0xc0,0x4f,0x61,0x1c,0x75);


MIDL_DEFINE_GUID(IID, IID_IDBTraceProviderEnumerator,0xe0adffa2,0x5743,0x11d3,0xb3,0x14,0x00,0xc0,0x4f,0x61,0x1c,0x75);


MIDL_DEFINE_GUID(IID, IID_IDBTraceProviderManager,0xe0f0c17a,0x5743,0x11d3,0xb3,0x14,0x00,0xc0,0x4f,0x61,0x1c,0x75);


MIDL_DEFINE_GUID(IID, IID_IDBTraceReceiverControl,0xe13aaa60,0x5743,0x11d3,0xb3,0x14,0x00,0xc0,0x4f,0x61,0x1c,0x75);


MIDL_DEFINE_GUID(IID, IID_IDBTraceReceiverEnumerator,0xe17d6c38,0x5743,0x11d3,0xb3,0x14,0x00,0xc0,0x4f,0x61,0x1c,0x75);


MIDL_DEFINE_GUID(IID, IID_IDBTraceReceiverManager,0xe1cc19d2,0x5743,0x11d3,0xb3,0x14,0x00,0xc0,0x4f,0x61,0x1c,0x75);


MIDL_DEFINE_GUID(IID, IID_IDBTraceReceiver,0x29d82de3,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(IID, IID_IDBTraceNotify,0x29d82de4,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(IID, IID_IDBTraceEnumParameters,0x29d82ded,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(IID, IID_IDBTracePackage,0x29d82de5,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(IID, IID_IDBTraceParameter,0x29d82de6,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(IID, IID_IDBTraceInterpreter,0x29d82de7,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(IID, IID_IProviderEnum,0x29d82ddf,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(IID, LIBID_TraceProviderLib,0x29d82de8,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(CLSID, CLSID_TraceControl,0x29d82de9,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(CLSID, CLSID_Tracer,0x29d82dea,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(CLSID, CLSID_TraceReceiver,0x29d82deb,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(CLSID, CLSID_TraceInterpreter,0x29d82dec,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(CLSID, CLSID_ProviderEnum,0x29d82de1,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);


MIDL_DEFINE_GUID(CLSID, CLSID_SimpleFileReceiver,0x29d82dee,0x2bdb,0x11d2,0x90,0xe1,0x00,0x80,0x5f,0xc7,0x52,0xeb);

#undef MIDL_DEFINE_GUID

#endif