//=============================================================================
//  Microsoft (R) Network Monitor (tm). 
//  Copyright (C) 1997 - 2000. All rights reserved.
//
//  MODULE: trackerRA.h
//
//  Property Distribution expert generic data tracker
//=============================================================================

#ifndef _TRACKERRA_H_
#define _TRACKERRA_H_

#include <windows.h>
#include <netmon.h>

//////////////////////////////////////////////////////////////////////////////
// DATA STRUCTURES
typedef struct
{
    union
    {
        DWORD Offset; // used for strings
        DWORD Value;  // used for labeled sets
    };
    DWORD Count;
} TRACKARRAYENTRY;
typedef TRACKARRAYENTRY *PTRACKARRAYENTRY;

//////////////////////////////////////////////////////////////////////////////
// TRACKERRA class
class TRACKERRA
{
    public:
        TRACKERRA(HEXPERTKEY hExpertKey, BOOL fStrings, DWORD *pRc);
        ~TRACKERRA();

        DWORD AddString( char *pNewString, DWORD StringLength );
        DWORD AddValue( DWORD dwNewValue );

        DWORD GetString( DWORD Index, char **pString, DWORD *pCount );
        DWORD GetValue(  DWORD Index, DWORD *pValue, DWORD *pCount );

    private:
        HEXPERTKEY m_hExpertKey;
        BOOL m_fStrings;

        // for both values and strings
        PTRACKARRAYENTRY m_TrackArray;
        DWORD            m_TrackArrayUsed;
        DWORD            m_TrackArrayAllocated;

        // just for strings
        char *  m_StringMemory;
        DWORD   m_StringMemoryAllocated;
        DWORD   m_StringMemoryUsed;

        // workers
        DWORD MakeRoom( );

};
typedef TRACKERRA *PTRACKERRA;


#endif // _TRACKERRA_H_