//=============================================================================
//  Microsoft (R) Network Monitor (tm). 
//  Copyright (C) 1997 - 2000. All rights reserved.
//
//  MODULE: propdist.cpp
//
//  Property Distribution expert module
//=============================================================================

#include "propdist.h"

//////////////////////////////////////////////////////////////////////////////
// Global Variables
HINSTANCE g_hInstance;

char g_StatusString[MAX_PATH];

// Magic prototype (in the kernel)
extern "C" DWORD WINAPI HelperFormatUnicodeString ( LPSTR   szOut,
                                                    LPCWSTR szIn,
                                                    WORD    Len );
extern "C" DWORD WINAPI DecodeSNMPObjectIdentifier( LPBYTE lpData, 
                                                    DWORD DataLen,
                                                    LPOBJECT_IDENTIFIER lpOID);

// Global data, used for decoding OIDs
static OBJECT_IDENTIFIER g_OID;
static DWORD             g_IDLength = 0; 

//////////////////////////////////////////////////////////////////////////////
// The DLL entry point
//
BOOL WINAPI DllMain(HINSTANCE hInstance, ULONG ulReason, LPVOID pvReserved)
{
    switch( ulReason )
    {
    case DLL_PROCESS_ATTACH:
        g_hInstance = hInstance;
        break;

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// The Expert Registration entry point
//
BOOL WINAPI Register( PEXPERTENUMINFO lpExpertInfo)
{
    // fill in the expert info data structure
    lpExpertInfo->Flags = EXPERT_ENUM_FLAG_VIEWER_PRIVATE |
                          EXPERT_ENUM_FLAG_CONFIGURABLE |
                          EXPERT_ENUM_FLAG_ADD_ME_TO_RMC_IN_DETAIL;
    lpExpertInfo->Version = 1;
    LoadString(g_hInstance, IDS_NAME, lpExpertInfo->szName, MAX_PATH);
    LoadString(g_hInstance, IDS_COMMENT, lpExpertInfo->szDescription, MAX_PATH);
    LoadString(g_hInstance, IDS_AUTHOR, lpExpertInfo->szVendor, MAX_PATH);
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// The Expert Configuration entry point
//
BOOL WINAPI Configure( HEXPERTKEY ExpertKey, 
                       PEXPERTCONFIG* ppConfig,
                       PEXPERTSTARTUPINFO pStartupInfo,
                       DWORD StartupFlags,
                       HWND hWnd )
{
    LPPROTOCOLINFO pProtocolInfo;
    char *         pProtocolName;
    char *         pPropertyName;
    DWORD          PropertyNameLen;
    BOOL           fBitNumberUsed = FALSE;
    BYTE           BitNumber;
    DWORD          BufferSize;

    PPROPDISTCONFIG pPropDistConfig;

    // did we get startup info?
    if( pStartupInfo == NULL )
    {
        // we need that, if only for the hCapture!
        return FALSE;
    }

    // is the startup info from a right mouse click?
    if( (*ppConfig == NULL) ||
        (StartupFlags & 
        EXPERT_STARTUP_FLAG_USE_STARTUP_DATA_OVER_CONFIG_DATA) )
    {
        // yes, fill in the configuration from the startup info...
        // Get the protocol name
        pProtocolInfo = GetProtocolInfo(pStartupInfo->hProtocol);        
        if( pProtocolInfo == NULL )
        {
            return FALSE;
        }
        pProtocolName = (char*)(pProtocolInfo->ProtocolName);

        // get the property name
        pPropertyName = pStartupInfo->lpPropertyInst->lpPropertyInfo->Label;
        PropertyNameLen = strlen(pPropertyName) + 1;

        // are we going to need the bit number?
        if( pStartupInfo->lpPropertyInst->lpPropertyInfo->DataQualifier == 
            PROP_QUAL_FLAGS )
        {
            fBitNumberUsed = TRUE;
            BitNumber = pStartupInfo->sBitfield.BitNumber;
        }
        
        // how big must the config be?
        BufferSize = sizeof( PROPDISTCONFIG ) + PropertyNameLen;

        // make sure the config is big enough    
        SizeConfigBuffer( ExpertKey, 
                          (PPROPDISTCONFIG *)ppConfig,
                          BufferSize );

        // fill in the config
        pPropDistConfig = (PPROPDISTCONFIG)(*ppConfig);
        pPropDistConfig->nTotalLength =  BufferSize;
        pPropDistConfig->fBitNumberSet = fBitNumberUsed;
        pPropDistConfig->nBitNumber =    BitNumber; 
        strcpy( pPropDistConfig->szProtocolName,
                pProtocolName);
        strcpy( pPropDistConfig->szPropertyName,
                pPropertyName);
    }

    // call the dialog
    return ConfigPropDistDlg_Do(hWnd, 
                          (PPROPDISTCONFIG *)ppConfig, 
                          pStartupInfo->hCapture, 
                          ExpertKey);
}


//////////////////////////////////////////////////////////////////////////////
// The Expert Start entry point
//
BOOL WINAPI Run( HEXPERTKEY hExpertKey, 
                 PEXPERTCONFIG lpConfig, 
                 PEXPERTSTARTUPINFO pStartupInfo,
                 DWORD StartupFlags,
                 HWND hwnd)
{
    DWORD               rc;
    EXPERTSTATUS        Status;

    PROPERTYTOFIND      PropertyToFind;

    HFILTER             hFilter;
    FILTEROBJECT        FilterObj;

    BOOL                WorkerRC;

    REPORTTYPE          ReportType = REPORTTYPE_DEFAULT;
    PPROPDISTCONFIG     pPropDistConfig = (PPROPDISTCONFIG)lpConfig;

    // zero out our OID structure
    memset( (char*)&g_OID, 0, sizeof(OBJECT_IDENTIFIER) );
    
    // -----------------------------------------------------------------------
    // Zero out all of our stack data structures
    memset( &PropertyToFind, 0, sizeof(PROPERTYTOFIND) );
    memset( &Status, 0, sizeof(EXPERTSTATUS) );
    memset( &FilterObj, 0, sizeof(FILTEROBJECT) );

    // -----------------------------------------------------------------------
    // Set up our status structure and tell the world that we are initializing
    Status.Frame       = 0;
    Status.PercentDone = 0;
    Status.Status      = EXPERTSTATUS_STARTING;
    Status.SubStatus   = 0;    
    LoadString(g_hInstance, IDS_INITIALIZING, Status.szStatusText, MAX_PATH);
    rc = ExpertIndicateStatus(hExpertKey, 
                              Status.Status,
                              Status.SubStatus,
                              Status.szStatusText,
                              Status.PercentDone);
    if( rc == NMERR_EXPERT_TERMINATE )
    {
        // we have been asked to terminate
        return TRUE;
    }
    else if( rc != NMERR_SUCCESS )
    {
        // something bad happened
        LoadString(g_hInstance, IDS_ERRORONE, g_StatusString, MAX_PATH);
        HandleError( hExpertKey, &Status, g_StatusString, rc );
        return FALSE;
    }

    // -----------------------------------------------------------------------
    // Figure out which property we are looking for...

    // are supposed to use the configuration
    if( ((StartupFlags & EXPERT_STARTUP_FLAG_USE_STARTUP_DATA_OVER_CONFIG_DATA) == 0) &&
        (pPropDistConfig != NULL) )
    {
        // yes we are supposed to get our info from the config and the config exists
        // pull the configuration out of the one passed...

        // protocol
        PropertyToFind.hProtocol = GetProtocolFromName(
                                        pPropDistConfig->szProtocolName);
        if( PropertyToFind.hProtocol == NULL )
        {
            LoadString(g_hInstance, IDS_ERRORTWO, g_StatusString, MAX_PATH);
            HandleError( hExpertKey, 
                         &Status, 
                         g_StatusString, 
                         0 );
            return FALSE;
        }

        // property
        PropertyToFind.hProperty = GetProperty( PropertyToFind.hProtocol,
                                    pPropDistConfig->szPropertyName);
        if( PropertyToFind.hProperty == NULL )
        {
            LoadString(g_hInstance, IDS_ERRORTHREE, g_StatusString, MAX_PATH);
            HandleError( hExpertKey, 
                         &Status, 
                         g_StatusString, 
                         0 );
            return FALSE;
        }

        // bit number
        PropertyToFind.nBitNumber = pPropDistConfig->nBitNumber;
    }
    else
    {
        // we are supposed to use startup info.
        // (either the flag says so, or the config passed is NULL)

        // protocol
        PropertyToFind.hProtocol = pStartupInfo->hProtocol;

        // property
        PropertyToFind.hProperty = 
            pStartupInfo->lpPropertyInst->lpPropertyInfo->hProperty;
        
        // bit number
        PropertyToFind.nBitNumber = pStartupInfo->sBitfield.BitNumber;
    }

    // fill in the rest of the entries now, cuz everyone is gonna need them
    // fetch the names of the protocol and property
    PropertyToFind.lpProtocolInfo = GetProtocolInfo( PropertyToFind.hProtocol );
    PropertyToFind.lpPropertyInfo = GetPropertyInfo( PropertyToFind.hProperty );

    // ------------------------------------------------------------------------
    // create a filter which will only find frames which contain the property
    hFilter = CreateFilter();
    if( hFilter == NULL )
    {
        // can't make filter
        LoadString(g_hInstance, IDS_ERRORFOUR, g_StatusString, MAX_PATH);
        HandleError( hExpertKey, &Status, g_StatusString, 0);
        return FALSE;
    }

    // Fill the filter
    // first add the property
    FilterObj.Action           = FILTERACTION_PROPERTY;
    FilterObj.hProperty        = PropertyToFind.hProperty;
    rc = FilterAddObject( hFilter, &FilterObj);
    if( rc != NMERR_SUCCESS )
    {
        // can't add to the filter
        LoadString(g_hInstance, IDS_ERRORFIVE, g_StatusString, MAX_PATH);
        HandleError( hExpertKey, &Status, g_StatusString, rc);
        return FALSE;
    }

    // next add the operation (Property Exists)
    FilterObj.Action           = FILTERACTION_PROPERTYEXIST;
    rc = FilterAddObject( hFilter, &FilterObj);
    if( rc != NMERR_SUCCESS )
    {
        // can't add to the filter
        LoadString(g_hInstance, IDS_ERRORFIVE, g_StatusString, MAX_PATH);
        HandleError( hExpertKey, &Status, g_StatusString, rc);
        return FALSE;
    }

    // call the worker to do the actual work
    WorkerRC = DoPropertySearchAndReport( hExpertKey,
                                          &Status,
                                          &PropertyToFind,
                                          hFilter);

    // -----------------------------------------------------------------------
    // we are done, the Worker has done our work for us
    DestroyFilter( hFilter );
    return WorkerRC;
}

//////////////////////////////////////////////////////////////////////////////
// DoPropertySearchAndReport
BOOL DoPropertySearchAndReport( HEXPERTKEY      hExpertKey,
                                PEXPERTSTATUS   pStatus,
                                PPROPERTYTOFIND pPropertyToFind,
                                HFILTER         hFilter)
{
    DWORD                 rc;
    EXPERTFRAMEDESCRIPTOR FrameDescriptor;
    DWORD                 OurRC = TRUE;

    DWORD                 TotalNumFrames;
    DWORD                 CurrentFrameNum;
    DWORD                 CurrentPercentDone;
    LPPROPERTYINST        pCurrentInstance = NULL;

    DWORD                 nFramesWithThisProperty = 0;
    REPORTTYPE            ReportType;

    // -----------------------------------------------------------------------
    // allocate our tracking mechanism
    PROPERTYTRACKER Tracker;

    try
    {
        // initialize out tracking mechanism and get back a report type
        rc = Tracker.Initialize( hExpertKey,
                                 pPropertyToFind->lpPropertyInfo->DataType,
                                 pPropertyToFind->lpPropertyInfo->DataQualifier,
                                 pPropertyToFind->nBitNumber,
                                 &ReportType );
        if( rc != NMERR_SUCCESS )
        {
            LoadString(g_hInstance, IDS_ERRORSIX, g_StatusString, MAX_PATH);
            HandleError( hExpertKey, 
                         pStatus, 
                         g_StatusString,
                         rc);
            OurRC = FALSE;
            throw 1;
        }

        // -------------------------------------------------------------------
        // get the first frame
        rc = ExpertGetFrame( hExpertKey,
                             GET_FRAME_NEXT_FORWARD,
                             FLAGS_DEFER_TO_UI_FILTER | FLAGS_ATTACH_PROPERTIES,
                             -1,  //first frame
                             hFilter,
                             &FrameDescriptor );
        // if( rc == NMERR_OUT_OF_RANGE )
        if( rc != NMERR_SUCCESS )
        {
            // there were no frames
            // OurRC = TRUE;
            throw 1;
        }

        // get number of frames in capture:
        TotalNumFrames = 
            GetCaptureTotalFrames(GetFrameCaptureHandle(FrameDescriptor.hFrame)); 

        // -------------------------------------------------------------------
        // the main loop, 
        // we are stepping through the frames that have this property
        do
        {
            // ---------------------------------------------------------------
            // send status if we need to 
            CurrentFrameNum     = FrameDescriptor.FrameNumber;
            CurrentPercentDone  = (BYTE)((CurrentFrameNum*100)/TotalNumFrames);
            if( CurrentPercentDone > pStatus->PercentDone )
            {
                pStatus->Frame       = CurrentFrameNum + 1;
                pStatus->PercentDone = CurrentPercentDone;
                LoadString(g_hInstance, IDS_RUNNING, pStatus->szStatusText, MAX_PATH);

                // send status message:    
                rc = ExpertIndicateStatus(hExpertKey, 
                                          pStatus->Status,
                                          pStatus->SubStatus,
                                          pStatus->szStatusText,
                                          pStatus->PercentDone);
                if( rc != NMERR_SUCCESS)
                {     
                    // status message failed
                    LoadString(g_hInstance, IDS_ERRORSEVEN, g_StatusString, MAX_PATH);
                    HandleError( hExpertKey, 
                                 pStatus, 
                                 g_StatusString,
                                 rc);
                    OurRC = FALSE;
                    throw 1;
                }
            }

            // ---------------------------------------------------------------
            // find the first instance of the property
            pCurrentInstance = FindPropertyInstanceRestart( FrameDescriptor.hFrame,
                                              pPropertyToFind->hProperty,
                                              &pCurrentInstance,  // restart key
                                              TRUE); // forward
            if( pCurrentInstance == NULL )
            {
                // something is wrong, ExpertGetFrame says that there is one
                // of these properties in this frame but FindPropertyInstanceRestart
                // says that there is not!
                LoadString(g_hInstance, IDS_ERROREIGHT, g_StatusString, MAX_PATH);
                HandleError( hExpertKey, 
                             pStatus, 
                             g_StatusString,
                             0);
                OurRC = FALSE;
                throw 1;
            }

            // account for having found this frame
            nFramesWithThisProperty++;

            // ---------------------------------------------------------------
            // loop through occurances of this property in this frame
            while( pCurrentInstance != NULL )
            {
                // add this property instance to our tracker
                rc = AddThisInstance( hExpertKey,
                                      pCurrentInstance, 
                                      ReportType,
                                      pPropertyToFind->nBitNumber,
                                      &Tracker);
                if( rc != NMERR_SUCCESS )
                {
                    // the add failed
                    LoadString(g_hInstance, IDS_ERRORNINE, g_StatusString, MAX_PATH);
                    HandleError( hExpertKey, 
                                 pStatus, 
                                 g_StatusString,
                                 rc);
                    OurRC = FALSE;
                    throw 1;
                }

                // -----------------------------------------------------------
                // get the next occurrance of this property
                pCurrentInstance = FindPropertyInstanceRestart( 
                                              FrameDescriptor.hFrame,
                                              pPropertyToFind->hProperty,
                                              &pCurrentInstance,
                                              TRUE); // forward

            } // while (there are instances in the frame)

            // ---------------------------------------------------------------
            // get the next frame that passes the filter
            rc = ExpertGetFrame( hExpertKey,
                                 GET_FRAME_NEXT_FORWARD,
                                 FLAGS_DEFER_TO_UI_FILTER | 
                                 FLAGS_ATTACH_PROPERTIES,
                                 CurrentFrameNum,
                                 hFilter,
                                 &FrameDescriptor );

        // loop until we are out of frames
        } while( rc == NMERR_SUCCESS );

    }
    catch(...)
    {
        // if something bad happened quit here
        if( OurRC == FALSE )
        {
            return FALSE;
        }
    }

    // -----------------------------------------------------------------------
    // we have walked all of the frames, create the report

    // call the proper worker
    // check for zero to prevent sending out event with no frame
    if(nFramesWithThisProperty != 0)
    {
        switch( ReportType )
        {
            case REPORTTYPE_DEFAULT:
                OurRC = PrintDefaultReport( hExpertKey,
                                            pPropertyToFind,
                                            TotalNumFrames,
                                            nFramesWithThisProperty,
                                            pStatus,
                                            &Tracker );
                break;

            case REPORTTYPE_NUMERIC:
                OurRC = PrintNumericReport( hExpertKey,
                                            pPropertyToFind,
                                            TotalNumFrames,
                                            nFramesWithThisProperty,
                                            pStatus,
                                            &Tracker );
                break;

            case REPORTTYPE_STRING:
                OurRC = PrintStringReport ( hExpertKey,
                                            pPropertyToFind,
                                            TotalNumFrames,
                                            nFramesWithThisProperty,
                                            pStatus,
                                            &Tracker );
                break;

            case REPORTTYPE_LABELED:
                OurRC = PrintLabeledReport( hExpertKey,
                                            pPropertyToFind,
                                            TotalNumFrames,
                                            nFramesWithThisProperty,
                                            pStatus,
                                            &Tracker );
                break;

            case REPORTTYPE_FLAGS:
                OurRC = PrintFlagsReport(   hExpertKey,
                                            pPropertyToFind,
                                            TotalNumFrames,
                                            nFramesWithThisProperty,
                                            pStatus,
                                            &Tracker );
                break;

        }
    }
    // Free up the OID stuff if we used it
    if( g_OID.lpIdentifier != NULL )
    {
        ExpertFreeMemory( hExpertKey, g_OID.lpIdentifier);
    }


    return OurRC;
}

//////////////////////////////////////////////////////////////////////////////
// AddThisInstance
DWORD AddThisInstance( HEXPERTKEY       hExpertKey,
                       LPPROPERTYINST   lpInst, 
                       REPORTTYPE       ReportType,                   
                       BYTE             BitNumber,
                       PPROPERTYTRACKER pTracker)
{
    DWORD dwValue = 0;
    char* pStringValue = NULL;
    DWORD StringLength = 0;
    BOOL  fFlagState = FALSE; 
    DWORD Mask;
    LPVOID pRawData;
    DWORD  RawLen;
    BOOL  fByteSwapped = FALSE;
    char  ScratchBuffer[MAX_PATH];

    // -----------------------------------------------------------------------
    // figure out the byteswappedness of this entry
    // check the type
    if( lpInst->lpPropertyInfo->DataType == PROP_TYPE_BYTESWAPPED_WORD ||
        lpInst->lpPropertyInfo->DataType == PROP_TYPE_BYTESWAPPED_DWORD )
    {
        // the type says that is is byteswapped
        if( (lpInst->IFlags & IFLAG_SWAPPED) != 0 )
        {
            // the flags also say it is byteswapped,
            // two wrongs do make a right
            fByteSwapped = FALSE;
        }
        else
        {
            // the flags do not say that it is byteswapped,
            // therefore the type saying that it is 
            // wins the day
            fByteSwapped = TRUE;
        }
    }
    else
    {
        // the type does not indicate byteswapped, 
        // lets check the flags
        if( (lpInst->IFlags & IFLAG_SWAPPED) != 0 )
        {
            // the flags say it is byteswapped,
            fByteSwapped = TRUE;
        }
        else
        {
            // no one said that it is byteswapped
            fByteSwapped = FALSE;
        }
    }


    // -----------------------------------------------------------------------
    // is the data in the inst or the instEX
    if( lpInst->DataLength != (WORD)-1 )
    {
        // it is a regular inst
        pRawData = lpInst->lpData;
        RawLen = lpInst->DataLength;
    }
    else
    {
        // it is an instEX
        pRawData = lpInst->lpPropertyInstEx->Byte;
        RawLen = lpInst->lpPropertyInstEx->LengthEx;
    }

    // -----------------------------------------------------------------------
    // Fetch the data
    // what kind of report is this
    switch( ReportType )
    {
        default:
        case REPORTTYPE_DEFAULT:
            // this one has no addition to do
            return NMERR_SUCCESS;

        case REPORTTYPE_FLAGS:
        case REPORTTYPE_NUMERIC:
        case REPORTTYPE_LABELED:
            // these three get their values the same way...
            switch( lpInst->lpPropertyInfo->DataType )
            {
                default:
                    // you should be handled as default
                    return 1;

                case PROP_TYPE_BYTE:
                    dwValue = (DWORD)*((BYTE*)pRawData);
                    break;

                case PROP_TYPE_BYTESWAPPED_WORD:
                    // note that the byteswappedness was taken care of above,
                    // so we can ignore it here
                case PROP_TYPE_WORD:
                    if( fByteSwapped)
                    {
                        // the word is byteswapped
                        dwValue = (DWORD)XCHG(*((WORD*)pRawData));
                    }
                    else
                    {
                        // the word is not byteswapped
                        dwValue = (DWORD)*((WORD*)pRawData);
                    }
                    break;


                case PROP_TYPE_BYTESWAPPED_DWORD:
                    // note that the byteswappedness was taken care of above,
                    // so we can ignore it here
                case PROP_TYPE_DWORD:
                    if( fByteSwapped)
                    {
                        // the word is byteswapped
                        dwValue = DXCHG(*((DWORD*)pRawData));
                    }
                    else
                    {
                        // the word is not byteswapped
                        dwValue = *((DWORD*)pRawData);
                    }
                    break;


                case PROP_TYPE_VAR_LEN_SMALL_INT:
                    // we need to copy the value in, byte by byte up to the number
                    // of bytes given....
                    dwValue =0;
                    memcpy( (LPBYTE)&(dwValue) + (sizeof(DWORD)-RawLen), 
                            pRawData, 
                            RawLen);
                    // this guy should never be byteswapped!
                    break;
            }
            break;

        case REPORTTYPE_STRING:
            switch( lpInst->lpPropertyInfo->DataType )
            {
                case PROP_TYPE_STRING:
                case PROP_TYPE_COMMENT:
                case PROP_TYPE_SRCFRIENDLYNAME:
                case PROP_TYPE_DSTFRIENDLYNAME:
                    // these are all strings,
                    // but are they UNICODE
                    if( (lpInst->IFlags & IFLAG_UNICODE) != 0 )
                    {
                        // why, yes they are UNICODE
                        HelperFormatUnicodeString( ScratchBuffer,
                            (LPCWSTR)pRawData,
                            (WORD)RawLen);
                        pStringValue = ScratchBuffer;
                        StringLength = strlen( ScratchBuffer );
                    }
                    else
                    {
                        // nope, normal strings
                        // these all just point to the data
                        pStringValue = (char*)pRawData;
                        StringLength = RawLen;
                    }
                    break;

                case PROP_TYPE_TYPED_STRING:
                    // is it unicode?
                    if( (lpInst->lpPropertyInstEx->TypedString.StringType & 
                         TYPED_STRING_UNICODE) != 0 )
                    {
                        // it is a unicode string
                        // it needs converting
                        HelperFormatUnicodeString( ScratchBuffer,
                            (LPCWSTR)lpInst->lpPropertyInstEx->TypedString.lpString,
                            lpInst->lpPropertyInstEx->LengthEx);
                        pStringValue = ScratchBuffer;
                        StringLength = strlen( ScratchBuffer );
                    }
                    else
                    {
                        // it is a normal string
                        pStringValue = lpInst->lpPropertyInstEx->TypedString.lpString;
                        StringLength = RawLen;
                    }
                    break;


                case PROP_TYPE_OBJECT_IDENTIFIER:
                    // put the oid into a string to save
                    pStringValue = ScratchBuffer;
                    OIDToString( hExpertKey, 
                                 pRawData, 
                                 RawLen, 
                                 pStringValue, 
                                 &StringLength );
                    break;

                default:
                    // who are you?
                    return 1;
            }
            break;
    } 

    // -----------------------------------------------------------------------
    // store the data
    switch( ReportType )
    {
        default:
        case REPORTTYPE_DEFAULT:
            // you should have been kicked out before!
            return 1;

        case REPORTTYPE_FLAGS:
            // need to see whether the flag is on or off
            Mask = 1;
            Mask = Mask << BitNumber;
            if( (dwValue & Mask) != 0 )
            {
                fFlagState = TRUE;
            }
            else
            {
                fFlagState = FALSE;
            }

            // add the result
            return pTracker->AddFlagValue( fFlagState );

        case REPORTTYPE_NUMERIC:
            // this is easy, just add it
            return pTracker->AddNumericValue( dwValue );

        case REPORTTYPE_LABELED:
            // this is easy, just add it
            return pTracker->AddLabeledValue( dwValue );

        case REPORTTYPE_STRING:
            // this is easy, just add it
            return pTracker->AddStringValue( pStringValue, StringLength );
    }
}

//////////////////////////////////////////////////////////////////////////////
// OIDToString
void OIDToString( HEXPERTKEY hExpertKey, 
                  LPVOID pData, 
                  DWORD DataLen, 
                  char* pString,
                  DWORD*pStringLength)
{
    DWORD rc;
    char *pTemp = pString;
    DWORD RequiredStringLength = (DataLen+1)*sizeof(DWORD);

    // mark the OID size 
    g_OID.Length = g_IDLength;

    // do we need to allocate the identifier array?
    if( g_OID.lpIdentifier == NULL )
    {
        // alloc the identifier
        g_OID.lpIdentifier = (LPDWORD)ExpertAllocMemory( hExpertKey,
                                                         RequiredStringLength,
                                                         &rc);
        if(g_OID.lpIdentifier == NULL)
        {
            // failure
            *pString = '\0';
            *pStringLength = 0;
            return;
        }
        // set the length
        g_OID.Length = RequiredStringLength;
        g_IDLength   = RequiredStringLength;
    }

    // or do we need to grow it?
    else if( g_IDLength < RequiredStringLength )
    {
        LPDWORD pdwTemp;

        // we need to grow it
        pdwTemp =  (LPDWORD)ExpertReallocMemory( hExpertKey,
                                                 g_OID.lpIdentifier,
                                                 RequiredStringLength,
                                                 &rc);
        if(pdwTemp == NULL)
        {
            // failure
            *pString = '\0';
            *pStringLength = 0;
            return;
        }

        // we got it
        g_OID.lpIdentifier = pdwTemp;
        g_OID.Length = RequiredStringLength;
        g_IDLength   = RequiredStringLength;
    }

    // convert it from BER to our internal format
    rc = DecodeSNMPObjectIdentifier((LPBYTE)pData, DataLen, &g_OID);
    if( rc != NMERR_SUCCESS )
    {
        // failure
        *pString = '\0';
        *pStringLength = 0;
        return;
    }

    // spit out the string
    for (DWORD i = 0; i < g_OID.Length; i++)
    {
        // add a digit
        pTemp += wsprintf(pTemp, "%u.", g_OID.lpIdentifier[i]);

        // if this is our last time, 
        // replace the final "." with a NULL
        if (i == (g_OID.Length-1))
        {
            pTemp--;        // back up one
            *pTemp = '\0';  // null it out
        }
    }   

    // we succeeded, set the length
    *pStringLength = RequiredStringLength;

}    

//////////////////////////////////////////////////////////////////////////////
// Error Helper
void HandleError( HEXPERTKEY hExpertKey, 
                  PEXPERTSTATUS pStatus, 
                  char *szText, 
                  DWORD rc )
{
    // set the status to error and submit it
    pStatus->Status = EXPERTSTATUS_PROBLEM;
    pStatus->SubStatus = rc;
    strcpy ( pStatus->szStatusText, szText);
    ExpertIndicateStatus(hExpertKey, 
                         pStatus->Status,
                         pStatus->SubStatus,
                         pStatus->szStatusText,
                         pStatus->PercentDone);

    // if this is a debug build, print out an output message
#ifdef DEBUG
    char DebugText[MAX_PATH];
    wsprintf( DebugText, "%s (%d)\n", 
              szText,
              rc);
    dprintf(DebugText);
#endif
}
    