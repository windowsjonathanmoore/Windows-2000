//=============================================================================
//  Microsoft (R) Network Monitor (tm). 
//  Copyright (C) 1997 - 2000. All rights reserved.
//
//  MODULE: trackerRA.cpp
//
//  Property Distribution expert generic data tracker data structure
//=============================================================================

#include "TrackerRA.h"

//////////////////////////////////////////////////////////////////////////////
// constructor
TRACKERRA::TRACKERRA( HEXPERTKEY hExpertKey, BOOL fStrings, DWORD *pRC)
{
    // save off the expert key
    m_hExpertKey = hExpertKey;

    // do we want strings?
    m_fStrings = fStrings;
    m_StringMemory = NULL;

    // allocate an arbitrarily large array
    m_TrackArrayUsed = 0; 
    m_TrackArrayAllocated = 100;
    m_TrackArray = (PTRACKARRAYENTRY)ExpertAllocMemory(
                        m_hExpertKey,
                        m_TrackArrayAllocated * sizeof(TRACKARRAYENTRY),
                        pRC);
    if( m_TrackArray == NULL )
    {
        m_StringMemory = NULL;
        return;
    }

    if( fStrings != FALSE)
    {
        // allocate an arbitrarily large string space
        m_StringMemoryUsed = 0;
        m_StringMemoryAllocated = 1000;
        m_StringMemory = (char *)ExpertAllocMemory(hExpertKey,
                                  m_StringMemoryAllocated,
                                  pRC);
        if( m_StringMemory == NULL )
        {
            ExpertFreeMemory( hExpertKey, m_TrackArray);
            m_TrackArray = NULL;
            return;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
// Destructor
TRACKERRA::~TRACKERRA()
{
    // free up the arrays
    if( m_TrackArray != NULL )
    {
        ExpertFreeMemory( m_hExpertKey, m_TrackArray);
    }

    if( m_StringMemory != NULL )
    {
        ExpertFreeMemory( m_hExpertKey, m_StringMemory);
    }
}

//////////////////////////////////////////////////////////////////////////////
// AddString
DWORD TRACKERRA::AddString( char *pNewString, DWORD StringLength )
{
    DWORD rc;

    // are we a strings guy?
    if( m_fStrings == FALSE )
    {
        // we don't do strings
        return 1;
    }

    // do we already have it?
    for( DWORD i = 0; i < m_TrackArrayUsed; i++)
    {
        // is this it?
        if( !strncmp( pNewString, 
                     &(m_StringMemory[m_TrackArray[i].Offset]),
                     StringLength) )
        {
            // yes this is the same string
            m_TrackArray[i].Count++;
            return NMERR_SUCCESS;
        }
    }

    // do we have room in the array for another
    rc = MakeRoom();
    if( rc != NMERR_SUCCESS)
    {
        return rc;
    }

    // do we have room in the string area for this guy?
    // (note: the +1 is for the null terminator )
    if( m_StringMemoryUsed + StringLength +1 >= m_StringMemoryAllocated )
    {
        // grow the string table (double its size)
        char * pTempMemory;
        m_StringMemoryAllocated *= 2;
        pTempMemory = (char *)ExpertReallocMemory(
                            m_hExpertKey,
                            m_StringMemory,
                            m_StringMemoryAllocated * sizeof(TRACKARRAYENTRY),
                            &rc); 
        if( pTempMemory == NULL )
        {
            return rc;
        }
        m_StringMemory = pTempMemory;
    }

    //  count it and copy the string in
    m_TrackArray[m_TrackArrayUsed].Count++;
    m_TrackArray[m_TrackArrayUsed].Offset = m_StringMemoryUsed;
    m_TrackArrayUsed++;

    // copy in only the number of bytes indicated
    memcpy( &(m_StringMemory[m_StringMemoryUsed]),
            pNewString,
            StringLength);
    m_StringMemoryUsed += StringLength;

    // null terminate it
    m_StringMemory[m_StringMemoryUsed] = '\0';
    m_StringMemoryUsed++;

    return NMERR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AddValue
DWORD TRACKERRA::AddValue( DWORD dwNewValue )
{
    DWORD rc;

    // are we a value guy?
    if( m_fStrings != FALSE )
    {
        // we don't do values
        return 1;
    }

    // do we already have it?
    for( DWORD i = 0; i < m_TrackArrayUsed; i++)
    {
        // is this it?
        if( dwNewValue == m_TrackArray[i].Value )
        {
            // yes this is the same string
            m_TrackArray[i].Count++;
            return NMERR_SUCCESS;
        }
    }

    // do we have room in the array for another
    rc = MakeRoom();
    if( rc != NMERR_SUCCESS)
    {
        return rc;
    }

    //  count it and record it
    m_TrackArray[m_TrackArrayUsed].Count++;
    m_TrackArray[m_TrackArrayUsed].Value = dwNewValue;
    m_TrackArrayUsed++;
    return NMERR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// GetString
DWORD TRACKERRA::GetString( DWORD Index, char **pString, DWORD *pCount )
{
    // are we a strings guy?
    if( m_fStrings == FALSE )
    {
        // we don't do strings
        return 1;
    }

    // is the index in range?
    if( Index >= m_TrackArrayUsed )
    {
        // index out of range 
        return 1;
    }

    // return the string and its count
    *pString = &(m_StringMemory[m_TrackArray[Index].Offset]);
    *pCount = m_TrackArray[Index].Count;
    return NMERR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// GetValue
DWORD TRACKERRA::GetValue( DWORD Index, DWORD *pValue, DWORD *pCount )
{
    // are we a value guy?
    if( m_fStrings != FALSE )
    {
        // we don't do values
        return 1;
    }

    // is the index in range?
    if( Index >= m_TrackArrayUsed )
    {
        // index out of range 
        return 1;
    }

    // return the string and its count
    *pValue = m_TrackArray[Index].Value;
    *pCount = m_TrackArray[Index].Count;
    return NMERR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// MakeRoom
DWORD TRACKERRA::MakeRoom( )
{
    PTRACKARRAYENTRY pTempTrack;
    DWORD rc;

    // do we have room in the array?
    if( m_TrackArrayUsed >= m_TrackArrayAllocated )
    {
        // no, grow it (double its size)
        m_TrackArrayAllocated *= 2;
        pTempTrack = (PTRACKARRAYENTRY)ExpertReallocMemory(
                            m_hExpertKey,
                            m_TrackArray,
                            m_TrackArrayAllocated * sizeof(TRACKARRAYENTRY),
                            &rc); 
        if( pTempTrack == NULL )
        {
            return rc;
        }
        m_TrackArray = pTempTrack;
    }

    // we now have enough room...
    return NMERR_SUCCESS;
}













