/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

Module Name:

    SCardDef

Abstract:

        This file contains useful defined constants for use with smart card
        vendor wrapper and low-level COM objects/interfaces

Environment:

    Win32, C++ w/Exceptions, ATL, COM/OLE

Revision History:


--*/

#ifndef __SCARDDEF_H__
    #define __SCARDDEF_H__

////////////////////////////////////////////////////////////////////////////////////
//
// Following used with various ISO7816-4 ICC commands
//

// ISO7816 Select file parameter P1
    #define SC_ID_MF_DF_EF                  0x00
    #define SC_ID_CHILD_DF                  0x01
    #define SC_ID_EF_UNDER_DF               0x02
    #define SC_ID_PARENT_DF                 0x03

    #define SC_NAME_DF                      0x04

    #define SC_PATH_FROM_MF                 0x08
    #define SC_PATH_CURRENT_DF              0x09

// ISO7816 Select File parameter P2
    #define SC_ONLY_OCCUR                   0x00
    #define SC_LAST_OCCUR                   0x01
    #define SC_NEXT_OCCUR                   0x02
    #define SC_PREV_OCCUR                   0x03

    #define SC_RETURN_FCI                   0x00
    #define SC_RETURN_FCP                   0x04
    #define SC_RETURN_FMD                   0x08

// ISO7816 Verify
    #define SC_GLOBAL_REF                   0x00
    #define SC_SPECIFIC_REF                 0x80

// MAX number of open files
    #define MAX_OPEN_FILES                  0x0A
// maximum handle value
    #define MAX_HANDLE_VALUE                0xFFFFFFFF

// Vendor Specific Info
    #define VENDOR_CLASS_ID                 0xC0

// lengths
    #define SC_FILE_ID_LENGTH               2*sizeof(BYTE)
    #define SC_FILE_ID_STR_LENGTH           4
    #define BYTE_BUFFER_HEAD                0

// Status
    #define SC_STATUS_SUCCESS               0x9000
    #define SC_STATUS_MOREDATA              0x61

///////////////////////////////////////////////////////////////////////////////////

#endif   // __SCARDDEF_H__

