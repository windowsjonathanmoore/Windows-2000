/*
 * Copyright (c) Microsoft Corporation.  All rights reserved.
 */

/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Dec 09 10:51:59 1999
 */
/* Compiler settings for AtlBehave.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IFactory = {0x140D550C,0x2290,0x11D2,{0xAF,0x61,0x00,0xA0,0xC9,0xC9,0xE6,0xC5}};


const IID IID_IBehavior = {0x140D550E,0x2290,0x11D2,{0xAF,0x61,0x00,0xA0,0xC9,0xC9,0xE6,0xC5}};


const IID IID_IEventSink = {0x5B3517FB,0x306F,0x11D2,{0xAF,0x62,0x00,0xA0,0xC9,0xC9,0xE6,0xC5}};


const IID LIBID_ATLBEHAVELib = {0x140D54FF,0x2290,0x11D2,{0xAF,0x61,0x00,0xA0,0xC9,0xC9,0xE6,0xC5}};


const CLSID CLSID_Factory = {0x140D550D,0x2290,0x11D2,{0xAF,0x61,0x00,0xA0,0xC9,0xC9,0xE6,0xC5}};


const CLSID CLSID_Behavior = {0x140D550F,0x2290,0x11D2,{0xAF,0x61,0x00,0xA0,0xC9,0xC9,0xE6,0xC5}};


const CLSID CLSID_EventSink = {0x5B3517FC,0x306F,0x11D2,{0xAF,0x62,0x00,0xA0,0xC9,0xC9,0xE6,0xC5}};


#ifdef __cplusplus
}
#endif

