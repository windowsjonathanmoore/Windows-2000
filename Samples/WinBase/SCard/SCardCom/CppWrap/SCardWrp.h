/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.

Module Name:

    scardwrp

Abstract:

    This file contains a simple class implementation for "wrapping" some
    of the Vendor COM Wrapper API functionality.


Environment:

    Win32, C++ w/Exceptions, ATL, COM/OLE

Revision History:

--*/

#ifndef __SCARDWRP_H__
    #define __SCARDWRP_H__

// These are required and taken from SCARDCOM.H
    #ifndef _SCARD_STATES_DEFINED
        #define _SCARD_STATES_DEFINED
typedef /* [version][v1_enum][helpstring] */
    enum tagSCARD_STATES
{
    ABSENT          = 1,
    PRESENT         = 2,
    SWALLOWED       = 3,
    POWERED         = 4,
    NEGOTIABLEMODE  = 5,
    SPECIFICMODE    = 6
}   SCARD_STATES;

    #endif // !_SCARD_STATES_DEFINED
    #ifndef _SCARD_PROTOCOLS_DEFINED
        #define _SCARD_PROTOCOLS_DEFINED
typedef /* [version][v1_enum][helpstring] */
    enum tagSCARD_PROTOCOLS
{
    T0      = 0x1,
    T1      = 0x2,
    RAW     = 0xff
}   SCARD_PROTOCOLS;

    #endif // !_SCARD_PROTOCOLS_DEFINED

    #define BYTE_BUFFER_HEAD        (0)

/////////////////////////////////////////////////////////////////////////////
//
// Includes
//

// Include Vendor COM object
    #include "scardcom.h"

/////////////////////////////////////////////////////////////////////////////
// CSCardWrapper class

class CSCardWrapper
{
    // Member Variables
private:
    // Bit struct used to sequence events, etc.
    typedef struct _SEQUENCE
    {
        unsigned        COMLoad:        1;
        unsigned        Attach:         1;
        unsigned        Other:          6;
    } SEQUENCE;

    SEQUENCE        m_sequence;

    // COM interface pointers
    LPSCARDMANAGE           m_pISCardManage;
    LPSCARDVERIFY           m_pISCardVerify;
    LPSCARDAUTH                     m_pISCardAuth;
    LPSCARDFILEACCESS       m_pISCardFileAccess;

public:
    // Construction/Destruction
    CSCardWrapper()
    {
        m_pISCardManage = NULL;
        m_pISCardVerify = NULL;
        m_pISCardAuth = NULL;
        m_pISCardFileAccess = NULL;

        m_sequence.COMLoad = 0;
        m_sequence.Attach = 0;
        m_sequence.Other = 0;
    }

    ~CSCardWrapper()
    {
    }

private:
    HRESULT CreateByteBuffer(       DWORD   dwSize,
                                    LPBYTEBUFFER* ppBuffer);

public:
    // Implementation
    HRESULT AttachToReaderByName( WCHAR *wszReaderName );

    HRESULT ChangeDirectory( WCHAR *wszDirectory );

    HRESULT Detach();

    HRESULT GetChallenge( LPBYTE lpbyChallenge, LONG* lpLengthOfChal );

    HRESULT LoadCOM();

    HRESULT Open( WCHAR *wszFilename, HSCARD_FILE *phFile );

    HRESULT Status( SCARD_STATES *State, SCARD_PROTOCOLS *Protocol );

    void UnloadCOM();

    HRESULT VerifyPIN( WCHAR *wszPIN );

    HRESULT Write ( HSCARD_FILE hFile, BYTE byRecordID,
                    LONG cbBytes, LPBYTE pbyData);
};

/////////////////////////////////////////////////////////////////////////////

#endif //__SCARDWRP_H__

