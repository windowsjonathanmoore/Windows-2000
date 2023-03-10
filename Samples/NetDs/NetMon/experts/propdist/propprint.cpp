//=============================================================================
//  Microsoft (R) Network Monitor (tm). 
//  Copyright (C) 1997 - 2000. All rights reserved.
//
//  MODULE: propprint.cpp
//
//  Property Distribution expert printing routines
//=============================================================================

#include <windows.h>
#include <netmon.h>
#include "propdist.h"

inline DWORD CalculatePercentage( DWORD dwActualItems, DWORD dwTotalItems);

char g_szExpertName[MAX_PATH];
char g_szCol0Name[MAX_PATH];
char g_szCol1Name[MAX_PATH];
char g_szCol2Name[MAX_PATH];
char g_szCol3Name[MAX_PATH];
char g_szCol4Name[MAX_PATH];
char g_szCol5Name[MAX_PATH];
char g_szCol6Name[MAX_PATH];
char g_szCol7Name[MAX_PATH];

//////////////////////////////////////////////////////////////////////////////
// PrintDefaultReport
BOOL PrintDefaultReport( HEXPERTKEY       hExpertKey,
                         PPROPERTYTOFIND  pPropertyToFind,
                         DWORD            TotalFramesInCapture,
                         DWORD            FramesContainingProperty,
                         PEXPERTSTATUS    pStatus,
                         PPROPERTYTRACKER PPROPERTYTRACKER)
{
    PNMEVENTDATA pEvent;
    DWORD        rc = NMERR_SUCCESS;
    BOOL         OurRC = TRUE;
    BYTE         TotalColumns = 4;

    // -----------------------------------------------------------------------
    // allocate the Event we will use to send
    pEvent = (PNMEVENTDATA)ExpertAllocMemory( hExpertKey,
                                              sizeof(NMEVENTDATA) +
                                              TotalColumns * sizeof(NMCOLUMNINFO), 
                                              &rc );
    if( pEvent == NULL )
    {
        LoadString(g_hInstance, IDS_ERRORELEVEN, g_StatusString, MAX_PATH);
        HandleError( hExpertKey, 
                     pStatus, 
                     g_StatusString,
                     rc);
        return FALSE;
    }

    try
    {
        // -----------------------------------------------------------------------
        // prefill the event
        memset( (char*)pEvent, 0, 
            sizeof(NMEVENTDATA) + TotalColumns * sizeof(NMCOLUMNINFO));
        pEvent->Flags = NMEVENTFLAG_DO_NOT_DISPLAY_FIXED_COLUMNS | 
                        NMEVENTFLAG_EXPERT; 
        LoadString(g_hInstance, IDS_NAME, g_szExpertName, MAX_PATH);
        pEvent->szSourceName = g_szExpertName;
        // let the rest of the header stay null...    

        // set the header names and types
        pEvent->EventIdent = 1;
        LoadString(g_hInstance, IDS_PROTOCOL_NAME, g_szCol0Name, MAX_PATH);
        pEvent->Column[0].szColumnName = g_szCol0Name;
        pEvent->Column[0].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_PROPERTY_NAME, g_szCol1Name, MAX_PATH);
        pEvent->Column[1].szColumnName = g_szCol1Name;
        pEvent->Column[1].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_NUMFRAMES_NAME, g_szCol2Name, MAX_PATH);
        pEvent->Column[2].szColumnName = g_szCol2Name;
        pEvent->Column[2].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_PERFRAMES_NAME, g_szCol3Name, MAX_PATH);
        pEvent->Column[3].szColumnName = g_szCol3Name;
        pEvent->Column[3].VariantData.Type = NMCOLUMNTYPE_UINT32;

        // -----------------------------------------------------------------------
        // spit the summary line
        pEvent->NumColumns = TotalColumns;
        // protocol
        pEvent->Column[0].VariantData.Value.pStringVal = 
            (char*)(pPropertyToFind->lpProtocolInfo->ProtocolName);
        // property
        pEvent->Column[1].VariantData.Value.pStringVal = 
            pPropertyToFind->lpPropertyInfo->Label;
        // # of Frames
        pEvent->Column[2].VariantData.Value.Uint32Val = FramesContainingProperty;
        // % of Frames
        pEvent->Column[3].VariantData.Value.Uint32Val = 
            CalculatePercentage( FramesContainingProperty, TotalFramesInCapture);
        rc = ExpertSubmitEvent( hExpertKey, pEvent );
        if( rc != NMERR_SUCCESS )
        {
            // we failed to post an event
            LoadString(g_hInstance, IDS_ERRORTEN, g_StatusString, MAX_PATH);
            HandleError( hExpertKey, 
                         pStatus, 
                         g_StatusString,
                         rc);
            OurRC = FALSE;
            throw 1;
        }

    }
    catch(...)
    {
        // something bad happened
    }

    // free up the event
    ExpertFreeMemory( hExpertKey, pEvent);

    return OurRC;
}

//////////////////////////////////////////////////////////////////////////////
// PrintNumericReport
BOOL PrintNumericReport( HEXPERTKEY       hExpertKey,
                         PPROPERTYTOFIND  pPropertyToFind,
                         DWORD            TotalFramesInCapture,
                         DWORD            FramesContainingProperty,
                         PEXPERTSTATUS    pStatus,
                         PPROPERTYTRACKER pTracker)
{
    PNMEVENTDATA pEvent;
    DWORD        rc = NMERR_SUCCESS;
    BOOL         OurRC = TRUE;
    BYTE         TotalColumns = 7;
    DWORD        dwMax = 0;
    DWORD        dwMin = 0;
    DWORD        dwMean= 0;

    // -----------------------------------------------------------------------
    // allocate the Event we will use to send
    pEvent = (PNMEVENTDATA)ExpertAllocMemory( hExpertKey,
                                              sizeof(NMEVENTDATA) +
                                              TotalColumns * sizeof(NMCOLUMNINFO), 
                                              &rc );
    if( pEvent == NULL )
    {
        LoadString(g_hInstance, IDS_ERRORELEVEN, g_StatusString, MAX_PATH);
        HandleError( hExpertKey, 
                     pStatus, 
                     g_StatusString,
                     rc);
        return FALSE;
    }

    try
    {
        // -----------------------------------------------------------------------
        // prefill the event
        memset( (char*)pEvent, 0, 
            sizeof(NMEVENTDATA) + TotalColumns * sizeof(NMCOLUMNINFO));

        pEvent->EventIdent = 1;
        pEvent->Flags = NMEVENTFLAG_DO_NOT_DISPLAY_FIXED_COLUMNS | 
                        NMEVENTFLAG_EXPERT; 
        LoadString(g_hInstance, IDS_NAME, g_szExpertName, MAX_PATH);
        pEvent->szSourceName = g_szExpertName;
        // let the rest of the header stay null...    

        // set the header names and types
        LoadString(g_hInstance, IDS_PROTOCOL_NAME, g_szCol0Name, MAX_PATH);
        pEvent->Column[0].szColumnName = g_szCol0Name;
        pEvent->Column[0].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_PROPERTY_NAME, g_szCol1Name, MAX_PATH);
        pEvent->Column[1].szColumnName = g_szCol1Name;
        pEvent->Column[1].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_NUMFRAMES_NAME, g_szCol2Name, MAX_PATH);
        pEvent->Column[2].szColumnName = g_szCol2Name;
        pEvent->Column[2].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_PERFRAMES_NAME, g_szCol3Name, MAX_PATH);
        pEvent->Column[3].szColumnName = g_szCol3Name;
        pEvent->Column[3].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_MAX_NAME, g_szCol4Name, MAX_PATH);
        pEvent->Column[4].szColumnName = g_szCol4Name;
        pEvent->Column[4].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_MIN_NAME, g_szCol5Name, MAX_PATH);
        pEvent->Column[5].szColumnName = g_szCol5Name;
        pEvent->Column[5].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_MEAN_NAME, g_szCol6Name, MAX_PATH);
        pEvent->Column[6].szColumnName = g_szCol6Name;
        pEvent->Column[6].VariantData.Type = NMCOLUMNTYPE_UINT32;

        // -----------------------------------------------------------------------
        // get the data
        rc = pTracker->GetNumericValue( &dwMax,
                                        &dwMin,
                                        &dwMean);
        // note: we do not care if this call fails, 
        // all the values are just zero then...

        // -----------------------------------------------------------------------
        // spit the summary line
        pEvent->NumColumns = TotalColumns;
        // protocol
        pEvent->Column[0].VariantData.Value.pStringVal = 
            (char*)(pPropertyToFind->lpProtocolInfo->ProtocolName);
        // property
        pEvent->Column[1].VariantData.Value.pStringVal = 
            pPropertyToFind->lpPropertyInfo->Label;
        // # of Frames
        pEvent->Column[2].VariantData.Value.Uint32Val = FramesContainingProperty;
        // % of Frames
        pEvent->Column[3].VariantData.Value.Uint32Val = 
            CalculatePercentage( FramesContainingProperty, TotalFramesInCapture);
        // Max
        pEvent->Column[4].VariantData.Value.Uint32Val = dwMax;
        // Min
        pEvent->Column[5].VariantData.Value.Uint32Val = dwMin;
        // Mean
        pEvent->Column[6].VariantData.Value.Uint32Val = dwMean;

        rc = ExpertSubmitEvent( hExpertKey, pEvent );
        if( rc != NMERR_SUCCESS )
        {
            // we failed to post an event
          LoadString(g_hInstance, IDS_ERRORTEN, g_StatusString, MAX_PATH);
          HandleError( hExpertKey, 
                         pStatus, 
                         g_StatusString,
                         rc);
            OurRC = FALSE;
            throw 1;
        }

    }
    catch(...)
    {
        // something bad happened
    }

    // free up the event
    ExpertFreeMemory( hExpertKey, pEvent);

    return OurRC;
}

//////////////////////////////////////////////////////////////////////////////
// PrintStringReport
BOOL PrintStringReport(  HEXPERTKEY       hExpertKey,
                         PPROPERTYTOFIND  pPropertyToFind,
                         DWORD            TotalFramesInCapture,
                         DWORD            FramesContainingProperty,
                         PEXPERTSTATUS    pStatus,
                         PPROPERTYTRACKER pTracker)
{
    PNMEVENTDATA pEvent;
    DWORD        rc = NMERR_SUCCESS;
    BOOL         OurRC = TRUE;
    char *       pCurrentString;
    DWORD        CurrentStringCount;
    BYTE         TotalColumns = 6;
    DWORD        RestartKey = (DWORD)-1;

    // -----------------------------------------------------------------------
    // allocate the Event we will use to send
    pEvent = (PNMEVENTDATA)ExpertAllocMemory( hExpertKey,
                                              sizeof(NMEVENTDATA) +
                                              TotalColumns * sizeof(NMCOLUMNINFO), 
                                              &rc );
    if( pEvent == NULL )
    {
        LoadString(g_hInstance, IDS_ERRORELEVEN, g_StatusString, MAX_PATH);
        HandleError( hExpertKey, 
                     pStatus, 
                     g_StatusString,
                     rc);
        return FALSE;
    }

    try
    {
        // -----------------------------------------------------------------------
        // prefill the event
        memset( (char*)pEvent, 0, 
            sizeof(NMEVENTDATA) + TotalColumns * sizeof(NMCOLUMNINFO));
        pEvent->Flags = NMEVENTFLAG_DO_NOT_DISPLAY_FIXED_COLUMNS | 
                        NMEVENTFLAG_EXPERT; 
        LoadString(g_hInstance, IDS_NAME, g_szExpertName, MAX_PATH);
        pEvent->szSourceName = g_szExpertName;
        // let the rest of the header stay null...    

        // set the header names and types
        pEvent->EventIdent = 1;
        LoadString(g_hInstance, IDS_PROTOCOL_NAME, g_szCol0Name, MAX_PATH);
        pEvent->Column[0].szColumnName = g_szCol0Name;
        pEvent->Column[0].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_PROPERTY_NAME, g_szCol1Name, MAX_PATH);
        pEvent->Column[1].szColumnName = g_szCol1Name;
        pEvent->Column[1].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_NUMFRAMES_NAME, g_szCol2Name, MAX_PATH);
        pEvent->Column[2].szColumnName = g_szCol2Name;
        pEvent->Column[2].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_PERFRAMES_NAME, g_szCol3Name, MAX_PATH);
        pEvent->Column[3].szColumnName = g_szCol3Name;
        pEvent->Column[3].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_VALUE_NAME, g_szCol4Name, MAX_PATH);
        pEvent->Column[4].szColumnName = g_szCol4Name;
        pEvent->Column[4].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_PERSET_NAME, g_szCol5Name, MAX_PATH);
        pEvent->Column[5].szColumnName = g_szCol5Name;
        pEvent->Column[5].VariantData.Type = NMCOLUMNTYPE_UINT32;

        // the first two columns will not change value
        pEvent->Column[0].VariantData.Value.pStringVal = 
            (char*)(pPropertyToFind->lpProtocolInfo->ProtocolName);
        pEvent->Column[1].VariantData.Value.pStringVal = 
            pPropertyToFind->lpPropertyInfo->Label;

        // -----------------------------------------------------------------------
        // spit the summary line
        pEvent->NumColumns = 4; // only use the first 4
        // # of Frames
        pEvent->Column[2].VariantData.Value.Uint32Val = FramesContainingProperty;
        // % of Frames
        pEvent->Column[3].VariantData.Value.Uint32Val = 
            CalculatePercentage( FramesContainingProperty, TotalFramesInCapture);
        rc = ExpertSubmitEvent( hExpertKey, pEvent );
        if( rc != NMERR_SUCCESS )
        {
            // we failed to post an event
            LoadString(g_hInstance, IDS_ERRORTEN, g_StatusString, MAX_PATH);
            HandleError( hExpertKey, 
                         pStatus, 
                         g_StatusString,
                         rc);
            OurRC = FALSE;
            throw 1;
        }

        // -------------------------------------------------------------------
        // for each value stored in the Tracking array, spit an entry
        pEvent->NumColumns = TotalColumns; // now we use all columns

        // get the first entry
        rc = pTracker->GetNextStringValue( &pCurrentString, 
                                           &CurrentStringCount, 
                                           &RestartKey);
        while( rc == NMERR_SUCCESS )
        {
            // make an event for this one
            // # of Frames
            pEvent->Column[2].VariantData.Value.Uint32Val = CurrentStringCount;
            // % of Frames
            pEvent->Column[3].VariantData.Value.Uint32Val = 
                CalculatePercentage( CurrentStringCount, TotalFramesInCapture);
            // value
            pEvent->Column[4].VariantData.Value.pStringVal = 
                pCurrentString;
            // % of Set
            pEvent->Column[5].VariantData.Value.Uint32Val = 
                CalculatePercentage( CurrentStringCount, FramesContainingProperty);

            // submit it
            rc = ExpertSubmitEvent( hExpertKey, pEvent );
            if( rc != NMERR_SUCCESS )
            {
                // we failed to post an event
              LoadString(g_hInstance, IDS_ERRORTEN, g_StatusString, MAX_PATH);
              HandleError( hExpertKey, 
                             pStatus, 
                             g_StatusString,
                             rc);
                OurRC = FALSE;
                throw 1;
            }

            // get the next one
            rc = pTracker->GetNextStringValue( &pCurrentString, 
                                               &CurrentStringCount, 
                                               &RestartKey);
        } // while (more entries)
    }
    catch(...)
    {
        // something bad happened
    }

    // free up the event
    ExpertFreeMemory( hExpertKey, pEvent);

    return OurRC;
}

//////////////////////////////////////////////////////////////////////////////
// PrintLabeledReport
BOOL PrintLabeledReport( HEXPERTKEY       hExpertKey,
                         PPROPERTYTOFIND  pPropertyToFind,
                         DWORD            TotalFramesInCapture,
                         DWORD            FramesContainingProperty,
                         PEXPERTSTATUS    pStatus,
                         PPROPERTYTRACKER pTracker)
{
    PNMEVENTDATA pEvent;
    DWORD        rc = NMERR_SUCCESS;
    BOOL         OurRC = TRUE;
    DWORD        dwCurrentValue;
    DWORD        CurrentValueCount;
    BYTE         TotalColumns = 7;
    DWORD        RestartKey = (DWORD)-1;

    // -----------------------------------------------------------------------
    // allocate the Event we will use to send
    pEvent = (PNMEVENTDATA)ExpertAllocMemory( hExpertKey,
                                              sizeof(NMEVENTDATA) +
                                              TotalColumns * sizeof(NMCOLUMNINFO), 
                                              &rc );
    if( pEvent == NULL )
    {
        LoadString(g_hInstance, IDS_ERRORELEVEN, g_StatusString, MAX_PATH);
        HandleError( hExpertKey, 
                     pStatus, 
                     g_StatusString,
                     rc);
        return FALSE;
    }

    try
    {
        // -----------------------------------------------------------------------
        // prefill the event
        memset( (char*)pEvent, 0, 
            sizeof(NMEVENTDATA) + TotalColumns * sizeof(NMCOLUMNINFO));
        pEvent->Flags = NMEVENTFLAG_DO_NOT_DISPLAY_FIXED_COLUMNS | 
                        NMEVENTFLAG_EXPERT; 
        LoadString(g_hInstance, IDS_NAME, g_szExpertName, MAX_PATH);
        pEvent->szSourceName = g_szExpertName;
        // let the rest of the header stay null...    

        // set the header names and types
        pEvent->EventIdent = 1;
        LoadString(g_hInstance, IDS_PROTOCOL_NAME, g_szCol0Name, MAX_PATH);
        pEvent->Column[0].szColumnName = g_szCol0Name;
        pEvent->Column[0].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_PROPERTY_NAME, g_szCol1Name, MAX_PATH);
        pEvent->Column[1].szColumnName = g_szCol1Name;
        pEvent->Column[1].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_NUMFRAMES_NAME, g_szCol2Name, MAX_PATH);
        pEvent->Column[2].szColumnName = g_szCol2Name;
        pEvent->Column[2].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_PERFRAMES_NAME, g_szCol3Name, MAX_PATH);
        pEvent->Column[3].szColumnName = g_szCol3Name;
        pEvent->Column[3].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_VALUE_NAME, g_szCol4Name, MAX_PATH);
        pEvent->Column[4].szColumnName = g_szCol4Name;
        pEvent->Column[4].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_LABEL_NAME, g_szCol5Name, MAX_PATH);
        pEvent->Column[5].szColumnName = g_szCol5Name;
        pEvent->Column[5].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_PERSET_NAME, g_szCol6Name, MAX_PATH);
        pEvent->Column[6].szColumnName = g_szCol6Name;
        pEvent->Column[6].VariantData.Type = NMCOLUMNTYPE_UINT32;

        // the first two columns will not change value
        pEvent->Column[0].VariantData.Value.pStringVal = 
            (char*)(pPropertyToFind->lpProtocolInfo->ProtocolName);
        pEvent->Column[1].VariantData.Value.pStringVal = 
            pPropertyToFind->lpPropertyInfo->Label;

        // -----------------------------------------------------------------------
        // spit the summary line
        pEvent->NumColumns = 4; // only use the first 4
        // # of Frames
        pEvent->Column[2].VariantData.Value.Uint32Val = FramesContainingProperty;
        // % of Frames
        pEvent->Column[3].VariantData.Value.Uint32Val = 
            CalculatePercentage( FramesContainingProperty, TotalFramesInCapture);
        rc = ExpertSubmitEvent( hExpertKey, pEvent );
        if( rc != NMERR_SUCCESS )
        {
            LoadString(g_hInstance, IDS_ERRORTEN, g_StatusString, MAX_PATH);
            // we failed to post an event
            HandleError( hExpertKey, 
                         pStatus, 
                         g_StatusString,
                         rc);
            OurRC = FALSE;
            throw 1;
        }

        // -------------------------------------------------------------------
        // for each value stored in the Tracking array, spit an entry
        pEvent->NumColumns = TotalColumns; // now we use all columns

        // get the first entry
        rc = pTracker->GetNextLabeledValue( &dwCurrentValue, 
                                            &CurrentValueCount, 
                                            &RestartKey);
        while( rc == NMERR_SUCCESS )
        {
            // make an event for this one
            // # of Frames
            pEvent->Column[2].VariantData.Value.Uint32Val = 
                CurrentValueCount;
            // % of Frames
            pEvent->Column[3].VariantData.Value.Uint32Val = 
                CalculatePercentage( CurrentValueCount, TotalFramesInCapture);
            // value
            pEvent->Column[4].VariantData.Value.Uint32Val = 
                dwCurrentValue;
            // % of Set
            pEvent->Column[6].VariantData.Value.Uint32Val = 
                CalculatePercentage( CurrentValueCount, FramesContainingProperty);

            // find the label
            pEvent->Column[5].VariantData.Value.pStringVal = 
                FindLabel( dwCurrentValue, pPropertyToFind->lpPropertyInfo);

            // submit it
            rc = ExpertSubmitEvent( hExpertKey, pEvent );
            if( rc != NMERR_SUCCESS )
            {
                // we failed to post an event
                LoadString(g_hInstance, IDS_ERRORTEN, g_StatusString, MAX_PATH);
                HandleError( hExpertKey, 
                             pStatus, 
                             g_StatusString,
                             rc);
                OurRC = FALSE;
                throw 1;
            }

            // get the next one
            rc = pTracker->GetNextLabeledValue( &dwCurrentValue, 
                                                &CurrentValueCount, 
                                                &RestartKey);
        } // while (more entries)
    }
    catch(...)
    {
        // something bad happened
    }

    // free up the event
    ExpertFreeMemory( hExpertKey, pEvent);

    return OurRC;
}

//////////////////////////////////////////////////////////////////////////////
// PrintFlagsReport
BOOL PrintFlagsReport(   HEXPERTKEY       hExpertKey,
                         PPROPERTYTOFIND  pPropertyToFind,
                         DWORD            TotalFramesInCapture,
                         DWORD            FramesContainingProperty,
                         PEXPERTSTATUS    pStatus,
                         PPROPERTYTRACKER pTracker)
{
    PNMEVENTDATA pEvent;
    DWORD        rc = NMERR_SUCCESS;
    BOOL         OurRC = TRUE;
    DWORD        CurrentValueCount;
    BYTE         TotalColumns = 8;

    // -----------------------------------------------------------------------
    // allocate the Event we will use to send
    pEvent = (PNMEVENTDATA)ExpertAllocMemory( hExpertKey,
                                              sizeof(NMEVENTDATA) +
                                              TotalColumns * sizeof(NMCOLUMNINFO), 
                                              &rc );
    if( pEvent == NULL )
    {
        LoadString(g_hInstance, IDS_ERRORELEVEN, g_StatusString, MAX_PATH);
        HandleError( hExpertKey, 
                     pStatus, 
                     g_StatusString,
                     rc);
        return FALSE;
    }

    try
    {
        // -----------------------------------------------------------------------
        // prefill the event
        memset( (char*)pEvent, 0, 
            sizeof(NMEVENTDATA) + TotalColumns * sizeof(NMCOLUMNINFO));
        pEvent->Flags = NMEVENTFLAG_DO_NOT_DISPLAY_FIXED_COLUMNS | 
                        NMEVENTFLAG_EXPERT; 
        LoadString(g_hInstance, IDS_NAME, g_szExpertName, MAX_PATH);
        pEvent->szSourceName = g_szExpertName;
        // let the rest of the header stay null...    

        // set the header names and types
        pEvent->EventIdent = 1;
        LoadString(g_hInstance, IDS_PROTOCOL_NAME, g_szCol0Name, MAX_PATH);
        pEvent->Column[0].szColumnName = g_szCol0Name;
        pEvent->Column[0].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_PROPERTY_NAME, g_szCol1Name, MAX_PATH);
        pEvent->Column[1].szColumnName = g_szCol1Name;
        pEvent->Column[1].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_NUMFRAMES_NAME, g_szCol2Name, MAX_PATH);
        pEvent->Column[2].szColumnName = g_szCol2Name;
        pEvent->Column[2].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_PERFRAMES_NAME, g_szCol3Name, MAX_PATH);
        pEvent->Column[3].szColumnName = g_szCol3Name;
        pEvent->Column[3].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_BITNUM_NAME, g_szCol4Name, MAX_PATH);
        pEvent->Column[4].szColumnName = g_szCol4Name;
        pEvent->Column[4].VariantData.Type = NMCOLUMNTYPE_UINT32;
        LoadString(g_hInstance, IDS_VALUE_NAME, g_szCol5Name, MAX_PATH);
        pEvent->Column[5].szColumnName = g_szCol5Name;
        pEvent->Column[5].VariantData.Type = NMCOLUMNTYPE_ONOFF;
        LoadString(g_hInstance, IDS_LABEL_NAME, g_szCol6Name, MAX_PATH);
        pEvent->Column[6].szColumnName = g_szCol6Name;
        pEvent->Column[6].VariantData.Type = NMCOLUMNTYPE_STRING;
        LoadString(g_hInstance, IDS_PERSET_NAME, g_szCol7Name, MAX_PATH);
        pEvent->Column[7].szColumnName = g_szCol7Name;
        pEvent->Column[7].VariantData.Type = NMCOLUMNTYPE_UINT32;

        // the first two columns will not change value
        pEvent->Column[0].VariantData.Value.pStringVal = 
            (char*)(pPropertyToFind->lpProtocolInfo->ProtocolName);
        pEvent->Column[1].VariantData.Value.pStringVal = 
            pPropertyToFind->lpPropertyInfo->Label;

        // -----------------------------------------------------------------------
        // spit the summary line
        pEvent->NumColumns = 4; // only use the first 4
        // # of Frames
        pEvent->Column[2].VariantData.Value.Uint32Val = FramesContainingProperty;
        // % of Frames
        pEvent->Column[3].VariantData.Value.Uint32Val = 
            CalculatePercentage( FramesContainingProperty, TotalFramesInCapture);
        rc = ExpertSubmitEvent( hExpertKey, pEvent );
        if( rc != NMERR_SUCCESS )
        {
            // we failed to post an event
            LoadString(g_hInstance, IDS_ERRORTEN, g_StatusString, MAX_PATH);
            HandleError( hExpertKey, 
                         pStatus, 
                         g_StatusString,
                         rc);
            OurRC = FALSE;
            throw 1;
        }

        // -------------------------------------------------------------------
        // for each value stored in the Tracking array, spit an entry
        pEvent->NumColumns = TotalColumns; // now we use all columns

        // Loop through both possible values
        for( DWORD i = 0; i <= 1; i++ )
        {
            BOOL FlagValue = (BOOL)i;

            // get this value
            rc = pTracker->GetFlagValue( FlagValue,
                                         &CurrentValueCount);

            // make an event for this one
            // # of Frames
            pEvent->Column[2].VariantData.Value.Uint32Val = 
                CurrentValueCount;
            // % of Frames
            pEvent->Column[3].VariantData.Value.Uint32Val = 
                CalculatePercentage( CurrentValueCount, TotalFramesInCapture);
            // Bit number
            pEvent->Column[4].VariantData.Value.Uint32Val = 
                pPropertyToFind->nBitNumber;
            // value
            pEvent->Column[5].VariantData.Value.OnOffVal = 
                FlagValue;
            // find the label
            pEvent->Column[6].VariantData.Value.pStringVal = 
                FindFlagLabel( pPropertyToFind->nBitNumber,
                               FlagValue,
                               pPropertyToFind->lpPropertyInfo);
            // % of Set
            pEvent->Column[7].VariantData.Value.Uint32Val = 
                CalculatePercentage( CurrentValueCount, FramesContainingProperty);

            // submit it
            rc = ExpertSubmitEvent( hExpertKey, pEvent );
            if( rc != NMERR_SUCCESS )
            {
                LoadString(g_hInstance, IDS_ERRORTEN, g_StatusString, MAX_PATH);
                // we failed to post an event
                HandleError( hExpertKey, 
                             pStatus, 
                             g_StatusString,
                             rc);
                OurRC = FALSE;
                throw 1;
            }

        } // for
    }
    catch(...)
    {
        // something bad happened
    }

    // free up the event
    ExpertFreeMemory( hExpertKey, pEvent);

    return OurRC;
}

//////////////////////////////////////////////////////////////////////////////
// FindLabel
char * FindLabel( DWORD dwValue, LPPROPERTYINFO lpPropertyInfo)
{
    DWORD i;
    LPSET lpSet = lpPropertyInfo->lpSet;

    // double check that this is a labeled set
    if( lpPropertyInfo->DataQualifier != PROP_QUAL_LABELED_SET )
        return NULL;

    // what type of data is this
    switch( lpPropertyInfo->DataType )
    {
        case PROP_TYPE_BYTE:
            for( i = 0; i < lpSet->nEntries; i++)
            {
                if( dwValue == (DWORD)(lpSet->lpLabeledByteTable[i].Value))
                {
                    // found it
                    return lpSet->lpLabeledByteTable[i].Label;
                }
            }
            break;

        case PROP_TYPE_BYTESWAPPED_WORD:
        case PROP_TYPE_WORD:
            for( i = 0; i < lpSet->nEntries; i++)
            {
                if( dwValue == (DWORD)(lpSet->lpLabeledWordTable[i].Value))
                {
                    // found it
                    return lpSet->lpLabeledWordTable[i].Label;
                }
            }
            break;

        case PROP_TYPE_VAR_LEN_SMALL_INT:
        case PROP_TYPE_BYTESWAPPED_DWORD:
        case PROP_TYPE_DWORD:
            for( i = 0; i < lpSet->nEntries; i++)
            {
                if( dwValue == lpSet->lpLabeledDwordTable[i].Value)
                {
                    // found it
                    return lpSet->lpLabeledDwordTable[i].Label;
                }
            }
            break;

        default:
            // we do not handle any others
            break;
    }

    // if we broke out of the switch above, then either we did not find the
    // value or it is of a data type that we do not handle
    return NULL;
}

//////////////////////////////////////////////////////////////////////////////
// FindFlagLabel
char * FindFlagLabel( BYTE  BitNumber,
                      BOOL  FlagValue,
                      LPPROPERTYINFO lpPropertyInfo)
{
    DWORD i;
    LPSET lpSet = lpPropertyInfo->lpSet;

    // double check that this is a Flags
    if( lpPropertyInfo->DataQualifier != PROP_QUAL_FLAGS )
        return NULL;

    // what type of data is this
    switch( lpPropertyInfo->DataType )
    {
        case PROP_TYPE_BYTE:
        case PROP_TYPE_WORD:
        case PROP_TYPE_DWORD:
            // we handle these
            for( i = 0; i < lpSet->nEntries; i++)
            {
                if( BitNumber == lpSet->lpLabeledBit[i].BitNumber )
                {
                    // this is the guy that we want
                    if( FlagValue == FALSE )
                    {
                        // they want the off case
                        return lpSet->lpLabeledBit[i].LabelOff;
                    }
                    else
                    {
                        // they wnat the on case
                        return lpSet->lpLabeledBit[i].LabelOn;
                    }
                }
            }
            break;

        default:
            // we do not handle any others
            break;
    }

    // if we broke out of the switch above, then either we did not find the
    // value or it is of a data type that we do not handle
    return NULL;
}
    
//////////////////////////////////////////////////////////////////////////////
// CalculatePercentage
// This will calculate a normal percentage but if the percentage is between 
// 0 and 1 it will substitute a 1
DWORD CalculatePercentage( DWORD dwActualItems, DWORD dwTotalItems)
{
    DWORD dwPercentage = 0;

    // first calculate the raw percentage
    dwPercentage = (dwActualItems*100)/dwTotalItems;

    // Now if the percentage is 0 BUT the number of items is not 
    // zero, then we have a <one fractional percentage
    if( dwPercentage == 0 &&
        dwActualItems > 0 )
    {
        // in this case round the percentage UP to 1
        dwPercentage = 1;
    }

    return dwPercentage;
}



