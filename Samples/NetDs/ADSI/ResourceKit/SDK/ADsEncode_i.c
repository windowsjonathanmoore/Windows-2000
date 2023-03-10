/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Sep 27 13:59:14 1999
 */
/* Compiler settings for D:\Projects\ADsEncode\ADsEncode.idl:
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

const IID IID_IADsEncode = {0x42AC9C8E,0x7CCC,0x40A4,{0xA4,0xD3,0x6C,0x4A,0xD6,0x39,0x1E,0x5B}};


const IID LIBID_ADSENCODELib = {0x1B60681D,0xF4C9,0x4D8A,{0xB5,0xD7,0x56,0x53,0x96,0xD6,0xD4,0x4E}};


const CLSID CLSID_ADsEncode = {0x69F8B370,0x4B3C,0x49D5,{0xBB,0x5E,0x35,0x58,0x00,0x02,0x79,0xDA}};


#ifdef __cplusplus
}
#endif

