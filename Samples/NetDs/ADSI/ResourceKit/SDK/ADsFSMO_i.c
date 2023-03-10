/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Oct 23 16:50:55 1999
 */
/* Compiler settings for D:\PROJECTS\ADsFSMO\ADsFSMO.idl:
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

const IID IID_IADsFSMO = {0x85E84C1E,0x174F,0x4143,{0x98,0x68,0xBA,0x52,0xAF,0xFF,0x53,0xFB}};


const IID LIBID_ADSFSMOLib = {0x15A91F2B,0x0295,0x4247,{0x8F,0xBD,0x69,0xE2,0xCD,0x5D,0x34,0xC9}};


const CLSID CLSID_ADsFSMO = {0x2405C2CE,0x3C6B,0x4D81,{0x8E,0x0F,0xD9,0xEE,0xDD,0x34,0xA5,0x1C}};


#ifdef __cplusplus
}
#endif

