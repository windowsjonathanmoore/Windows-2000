//=============================================================================
//  Microsoft (R) Network Monitor (tm). 
//  Copyright (C) 1997 - 2000. All rights reserved.
//
//  MODULE: tracker.h
//
//  Property Distribution expert generic data tracker
//=============================================================================

#ifndef _TRACKER_H_
#define _TRACKER_H_

#include <windows.h>
#include <netmon.h>
#include "TrackerRA.h"

//////////////////////////////////////////////////////////////////////////////
// DATA STRUCTURES
typedef enum
{
    REPORTTYPE_DEFAULT = 0,
    REPORTTYPE_NUMERIC,
    REPORTTYPE_STRING,
    REPORTTYPE_LABELED,
    REPORTTYPE_FLAGS

} REPORTTYPE;
typedef REPORTTYPE *PREPORTTYPE;

//////////////////////////////////////////////////////////////////////////////
// PROPERTYTRACKER class
class PROPERTYTRACKER
{
    public:
        PROPERTYTRACKER();
        ~PROPERTYTRACKER();

        // initialization functions
        DWORD Initialize( HEXPERTKEY hExpertKey,
                          BYTE DataType,
                          BYTE DataQualifier,
                          BYTE BitNumber,
                          PREPORTTYPE pReportType );

        // input functions
        DWORD AddNumericValue( DWORD dwNewValue );
        DWORD AddStringValue( char *pNewString, DWORD StringLength );
        DWORD AddLabeledValue( DWORD dwNewValue );
        DWORD AddFlagValue( BOOL fNewState );

        // output functions
        DWORD GetNumericValue( DWORD * pMax,
                               DWORD * pMin,
                               DWORD * pMean);
        DWORD GetNextStringValue( char ** ppReturnedString,
                                  DWORD * pReturnedCount,
                                  DWORD * pRestartKey);
        DWORD GetNextLabeledValue( DWORD *  pReturnedValue, 
                                   DWORD *  pReturnedCount, 
                                   DWORD *  pRestartKey);
        DWORD GetFlagValue( BOOL    FlagValue,
                            DWORD * CurrentValueCount);

    private:
        // configuration variables
        HEXPERTKEY m_hExpertKey;
        BOOL m_fInitialized;
        BYTE m_DataType;
        BYTE m_DataQualifier;
        BYTE m_BitNumber;
        REPORTTYPE m_ReportType;

        // strings and labels
        PTRACKERRA  m_pTrackerRA;

        // flags storage
        DWORD m_FlagCount[2];

        // numeric variables
        DWORD m_TotalEntries;
        DWORD m_RunningTotal;
        DWORD m_Minimum;
        DWORD m_Maximum;

        // helper functions
        DWORD FetchNumericValue(LPPROPERTYINST lpInst);
        char* FetchStringValue(LPPROPERTYINST lpInst);
        BOOL  FetchFlagState(LPPROPERTYINST lpInst, BYTE m_BitNumber);
};
typedef PROPERTYTRACKER * PPROPERTYTRACKER;

#endif // _TRACKER_H_