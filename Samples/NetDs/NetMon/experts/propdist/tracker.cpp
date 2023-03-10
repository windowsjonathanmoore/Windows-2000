//=============================================================================
//  Microsoft (R) Network Monitor (tm). 
//  Copyright (C) 1997 - 2000. All rights reserved.
//
//  MODULE: tracker.cpp
//
//  Property Distribution expert generic data tracker
//=============================================================================

#include "propdist.h"   // for the HandleError function
#include "tracker.h"

//////////////////////////////////////////////////////////////////////////////
// Constructor
PROPERTYTRACKER::PROPERTYTRACKER()
{
    // we have not yet been initialized
    m_hExpertKey = NULL;
    m_DataType = 0;
    m_DataQualifier = 0;
    m_ReportType = REPORTTYPE_DEFAULT;
    m_BitNumber = 0;

    // label and string variables
    m_pTrackerRA = NULL;

    // flags variables
    memset( (char*)m_FlagCount, 0, 2 * sizeof(DWORD) );

    // numeric variables
    m_RunningTotal = 0;
    m_TotalEntries = 0;
    m_Minimum = (DWORD)-1;
    m_Maximum = 0;
}

///////////////////////////////////////////////////////////////////////////////
// Destructor
PROPERTYTRACKER::~PROPERTYTRACKER()
{
    // if we have a tracker array, destroy it
    if( m_pTrackerRA != NULL )
    {
        delete m_pTrackerRA;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Initialize
DWORD PROPERTYTRACKER::Initialize( HEXPERTKEY hExpertKey,
                                   BYTE DataType,
                                   BYTE DataQualifier,
                                   BYTE BitNumber,
                                   PREPORTTYPE pReportType )
{
    DWORD rc;

    // store off the data
    m_DataType = DataType;
    m_DataQualifier = DataQualifier;
    m_BitNumber = BitNumber;

    // -----------------------------------------------------------------------
    // what type of report are we working towards
    switch( DataQualifier )
    {
        // these are actually the normal case
        case PROP_QUAL_NONE:
        case PROP_QUAL_RANGE:
        case PROP_QUAL_SET:
        case PROP_QUAL_CONST:
            switch( DataType )
            {
                // these are numerics
                case PROP_TYPE_BYTE:
                case PROP_TYPE_WORD:
                case PROP_TYPE_DWORD:
                case PROP_TYPE_BYTESWAPPED_WORD:
                case PROP_TYPE_BYTESWAPPED_DWORD:
                case PROP_TYPE_VAR_LEN_SMALL_INT:
                    m_ReportType = REPORTTYPE_NUMERIC;
                    break;

                // these are addresses
                case PROP_TYPE_ADDR:
                case PROP_TYPE_IP_ADDRESS:
                case PROP_TYPE_IPX_ADDRESS:
                case PROP_TYPE_TOKENRING_ADDRESS:
                case PROP_TYPE_FDDI_ADDRESS:
                case PROP_TYPE_ETHERNET_ADDRESS:
                case PROP_TYPE_VINES_IP_ADDRESS:
                    // for now, just default them
                    m_ReportType = REPORTTYPE_DEFAULT;
                    break;

                // these are strings
                case PROP_TYPE_STRING:
                case PROP_TYPE_TYPED_STRING:
                case PROP_TYPE_COMMENT:
                case PROP_TYPE_SRCFRIENDLYNAME:
                case PROP_TYPE_DSTFRIENDLYNAME:
                case PROP_TYPE_OBJECT_IDENTIFIER:
                    m_ReportType = REPORTTYPE_STRING;
                    break;

                // these others just get a total count
                default:
                case PROP_TYPE_VOID:
                case PROP_TYPE_SUMMARY:
                case PROP_TYPE_TIME:
                case PROP_TYPE_LARGEINT:
                    m_ReportType = REPORTTYPE_DEFAULT;
                    break;
            }
            break;

        case PROP_QUAL_FLAGS:
            // this is a flags, numeric flags need to be sent to the Flags handler
            switch( DataType )
            {
                case PROP_TYPE_BYTE: 
                case PROP_TYPE_WORD:
                case PROP_TYPE_DWORD:
                case PROP_TYPE_BYTESWAPPED_WORD:
                case PROP_TYPE_BYTESWAPPED_DWORD:
                case PROP_TYPE_VAR_LEN_SMALL_INT:
                    // call the Flags Worker
                    m_ReportType = REPORTTYPE_FLAGS;
                    break;

                default:
                    // all others just do the minimum
                    m_ReportType = REPORTTYPE_DEFAULT;
                    break;
            }
            break;

        case PROP_QUAL_LABELED_SET:
            // we handle numeric labeled sets specially
            switch( DataType )
            {
                case PROP_TYPE_BYTE:
                case PROP_TYPE_WORD:
                case PROP_TYPE_DWORD:
                case PROP_TYPE_BYTESWAPPED_WORD:
                case PROP_TYPE_BYTESWAPPED_DWORD:
                case PROP_TYPE_VAR_LEN_SMALL_INT:
                    // call the Labeled set Worker
                    m_ReportType = REPORTTYPE_LABELED;
                    break;

                default:
                    // all others just do the minimum
                    m_ReportType = REPORTTYPE_DEFAULT;
                    break;
            }
            break;

        default:
        case PROP_QUAL_ARRAY:
        case PROP_QUAL_BITFIELD:
        case PROP_QUAL_LABELED_BITFIELD:
            // these we just do the minimum
            m_ReportType = REPORTTYPE_DEFAULT;
            break;
    }

    // -----------------------------------------------------------------------
    // allocate the space we will need
    switch( m_ReportType )
    {
        case REPORTTYPE_STRING:
            // need a tracker array for strings
            m_pTrackerRA = new TRACKERRA( hExpertKey, TRUE, &rc);
            if( rc != NMERR_SUCCESS )
            {
                return rc;
            }
            break;

        case REPORTTYPE_LABELED:
            // need a tracker array for values
            m_pTrackerRA = new TRACKERRA( hExpertKey, FALSE, &rc);
            if( rc != NMERR_SUCCESS )
            {
                return rc;
            }
            break;

        default:
            // none of the others require any dynamic allocation
            break;
    }

    // we are all set up
    m_hExpertKey = hExpertKey;
    *pReportType = m_ReportType;

    return NMERR_SUCCESS;
}


//////////////////////////////////////////////////////////////////////////////
// AddNumericValue
DWORD PROPERTYTRACKER::AddNumericValue( DWORD dwNewValue )
{
    if( m_ReportType != REPORTTYPE_NUMERIC )
    {
        // wrong type
        return 1;
    }

    // factor this value in
    if( dwNewValue < m_Minimum )
    {
        // it is the new minimum
         m_Minimum = dwNewValue;
    }
    if( dwNewValue > m_Maximum )
    {
        // it is the new maximum
         m_Maximum = dwNewValue;
    }

    // add this to the mean
    m_RunningTotal += dwNewValue;
    m_TotalEntries ++;
    return NMERR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AddStringValue
DWORD PROPERTYTRACKER::AddStringValue( char *pNewString, DWORD StringLength )
{
    if( m_ReportType != REPORTTYPE_STRING )
    {
        // wrong type
        return 1;
    }

    // shove it into our array
    return m_pTrackerRA->AddString( pNewString, StringLength );
}

//////////////////////////////////////////////////////////////////////////////
// AddLabeledValue
DWORD PROPERTYTRACKER::AddLabeledValue( DWORD dwNewValue )
{
    if( m_ReportType != REPORTTYPE_LABELED )
    {
        // wrong type
        return 1;
    }

    // shove it into our array
    return m_pTrackerRA->AddValue( dwNewValue );
}

//////////////////////////////////////////////////////////////////////////////
// AddFlagValue
DWORD PROPERTYTRACKER::AddFlagValue( BOOL fNewState )
{
    DWORD Index;

    if( m_ReportType != REPORTTYPE_FLAGS )
    {
        // wrong type
        return 1;
    }

    // derive the index from the boolean
    if( fNewState != FALSE )
    {
        // the flag is on
        Index = 1;
    }
    else
    {
        // the flag is off
        Index = 0;
    }

    // increment the proper count
    ( m_FlagCount[Index] )++;
    return NMERR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// GetNumericValue
DWORD PROPERTYTRACKER::GetNumericValue( DWORD * pMax,
                                        DWORD * pMin,
                                        DWORD * pMean)
{
    // make sure that this is a numeric
    if( m_ReportType != REPORTTYPE_NUMERIC )
    {
        return 1;
    }

    // get the values
    *pMax = m_Maximum;

    if( m_Minimum == (DWORD) - 1 )
    {
        m_Minimum = 0;
    }

    *pMin = m_Minimum;
     
    if( m_TotalEntries == 0 )
    {
        *pMean = 0;
    }
    else
    {
        *pMean = m_RunningTotal/m_TotalEntries;
    }

    return NMERR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// GetNextString
DWORD PROPERTYTRACKER::GetNextStringValue( char ** ppReturnedString,
                                           DWORD * pReturnedCount,
                                           DWORD * pRestartKey)
{
    // make sure that this is a string
    if( m_ReportType != REPORTTYPE_STRING )
    {
        return 1;
    }

    // which one do we want?
    (*pRestartKey)++;

    // get it
    return m_pTrackerRA->GetString( (*pRestartKey),
                                    ppReturnedString,
                                    pReturnedCount);
}
    

//////////////////////////////////////////////////////////////////////////////
// GetNextLabeledValue
DWORD PROPERTYTRACKER::GetNextLabeledValue( DWORD *  pReturnedValue, 
                                            DWORD *  pReturnedCount,
                                            DWORD *  pRestartKey)
{
    // make sure that this is a string
    if( m_ReportType != REPORTTYPE_LABELED )
    {
        return 1;
    }

    // which one do we want?
    (*pRestartKey)++;

    // get it
    return m_pTrackerRA->GetValue( (*pRestartKey),
                                    pReturnedValue,
                                    pReturnedCount);
}
    
//////////////////////////////////////////////////////////////////////////////
// GetFlagValue
DWORD PROPERTYTRACKER::GetFlagValue( BOOL    FlagValue,
                                     DWORD * pReturnedCount)
{
    // make sure that this is a string
    if( m_ReportType != REPORTTYPE_FLAGS )
    {
        return 1;
    }

    // which one do we want?
    if( (DWORD)FlagValue > 1)
    {
        // we are beyond the ones saved
        return 1;
    }

    // fetch the count
    *pReturnedCount = m_FlagCount[(DWORD)FlagValue];

    return NMERR_SUCCESS;
}
    
