/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1997 - 2000.  Microsoft Corporation.  All rights reserved.


Module Name:

    WrpHelp

Abstract:

        This file contains the class declarations for wrapper helper classes

Environment:

    Win32, C++ w/Exceptions, ATL, COM/OLE

Notes:

--*/

#ifndef __WRPHELP_H__
    #define __WRPHELP_H__

/////////////////////////////////////////////////////////////////////////////
//
// Includes
//
    #ifndef __LOWLEVEL_SSP_COM__
        #define __LOWLEVEL_SSP_COM__
        #include <scardssp.h>
    #endif

/////////////////////////////////////////////////////////////////////////////
//
// Class Declaration
//
class CCriticalSection
{
    // Members
private:
    CRITICAL_SECTION m_CriticalSection;

public:

    // Construction/Destruction
    public:
    CCriticalSection();
    ~CCriticalSection();

    // Methods
    BOOL EnterCriticalSection();
    BOOL ExitCriticalSection();
};

/////////////////////////////////////////////////////////////////////////////
//
// Class Declaration
//
class CGrabData
{
    // members
private:
    LPSCARDCMD      m_pISCardCmd;
    LPSCARD         m_pISCard;
    LPSCARDISO7816  m_pISCardISO7816;
    LONG            m_lReplyLength;
    WORD            m_wReplyStatus;

public:
    // Construction/Destruction
    CGrabData(LPSCARDCMD pISCardCmd,
              LPSCARD pISCard,
              LPSCARDISO7816 pISCardIso)
    {
        m_pISCardCmd = pISCardCmd;
        m_pISCard = pISCard;
        m_pISCardISO7816 = pISCardIso;
    }

    ~CGrabData()
    {
    }

    // Methods
    HRESULT GetExtraData(   LPBYTEBUFFER *ppDataOut,
                            WORD *pwCmdStatus,
                            LONG *plDataLength);
};

//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
//
// Other helpful routines
//
HRESULT
    SspCreateByteArray(
                      IN DWORD dwAllocSize,
                      OUT LPBYTE *ppbyArray,
                      OUT OPTIONAL EXCEPINFO* pExceptInfo);

HRESULT
    SspConvertDwordToByte(
                         IN DWORD dwNum,
                         OUT LPBYTE *ppbyArray,
                         OUT LPDWORD pdwByteArraySize,
                         OUT OPTIONAL EXCEPINFO* pExceptInfo);

HRESULT
    SspFreeByteArray(
                    IN LPBYTE pbyArray,
                    OUT OPTIONAL EXCEPINFO* pExceptInfo);


STDAPI
    SspCreateByteBuffer(
                       IN DWORD dwAllocSize,
                       OUT LPBYTEBUFFER *ppbyBuff,
                       OUT OPTIONAL EXCEPINFO* pExceptInfo = NULL);

#endif // __CRITSEC_H__

