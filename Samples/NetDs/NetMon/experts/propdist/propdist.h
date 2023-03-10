//=============================================================================
//  Microsoft (R) Network Monitor (tm). 
//  Copyright (C) 1997 - 2000. All rights reserved.
//
//  MODULE: propdist.h
//
//  Property Distribution expert module
//=============================================================================

#ifndef _PROPDIST_H_
#define _PROPDIST_H_

#include <windows.h>
#include <netmon.h>
#include "tracker.h"
#include "dialogs.h"

#pragma warning(disable:4200)

//////////////////////////////////////////////////////////////////////////////
// Global Variables
extern HINSTANCE g_hInstance;
extern char g_StatusString[];

//////////////////////////////////////////////////////////////////////////////
// Data Structures

// PROPERTYTOFIND
typedef struct
{
    // raw part
    HPROTOCOL   hProtocol;
    HPROPERTY   hProperty;
    BYTE        nBitNumber;

    // decoded part for convenience
    LPPROTOCOLINFO lpProtocolInfo;
    LPPROPERTYINFO lpPropertyInfo;
} PROPERTYTOFIND;
typedef PROPERTYTOFIND * PPROPERTYTOFIND;

// PROPDISTCONFIG
typedef struct _PROPDISTCONFIG
{
    DWORD nTotalLength;
    BOOL  fBitNumberSet;
    BYTE  nBitNumber;
    char  szProtocolName[16];
    char  szPropertyName[0];
} PROPDISTCONFIG;
typedef PROPDISTCONFIG *PPROPDISTCONFIG;


//////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// In PropDist.cpp
BOOL WINAPI DllMain(HINSTANCE hInstance, ULONG ulReason, LPVOID pvReserved);
BOOL WINAPI Register( PEXPERTENUMINFO lpExpertInfo);
BOOL WINAPI Run( HEXPERTKEY hExpertKey, PEXPERTCONFIG lpConfig, HWND hwnd);
BOOL DoPropertySearchAndReport( HEXPERTKEY      hExpertKey,
                                PEXPERTSTATUS   pStatus,
                                PPROPERTYTOFIND pPropertyToFind,
                                HFILTER         hFilter);
DWORD AddThisInstance( HEXPERTKEY       hExpertKey,
                       LPPROPERTYINST   lpInst, 
                       REPORTTYPE       ReportType,                   
                       BYTE             BitNumber,
                       PPROPERTYTRACKER pTracker);
void OIDToString( HEXPERTKEY hExpertKey, 
                  LPVOID pData, 
                  DWORD DataLen, 
                  char* pString,
                  DWORD*pStringLength);
void HandleError( HEXPERTKEY hExpertKey, 
                  PEXPERTSTATUS pStatus, 
                  char *szText, 
                  DWORD rc );

// in PropPrint.cpp
BOOL PrintDefaultReport( HEXPERTKEY       hExpertKey,
                         PPROPERTYTOFIND  pPropertyToFind,
                         DWORD            TotalFramesInCapture,
                         DWORD            FramesContainingProperty,
                         PEXPERTSTATUS    pStatus,
                         PPROPERTYTRACKER PPROPERTYTRACKER);
BOOL PrintNumericReport( HEXPERTKEY       hExpertKey,
                         PPROPERTYTOFIND  pPropertyToFind,
                         DWORD            TotalFramesInCapture,
                         DWORD            FramesContainingProperty,
                         PEXPERTSTATUS    pStatus,
                         PPROPERTYTRACKER PPROPERTYTRACKER);
BOOL PrintStringReport(  HEXPERTKEY       hExpertKey,
                         PPROPERTYTOFIND  pPropertyToFind,
                         DWORD            TotalFramesInCapture,
                         DWORD            FramesContainingProperty,
                         PEXPERTSTATUS    pStatus,
                         PPROPERTYTRACKER PPROPERTYTRACKER);
BOOL PrintLabeledReport( HEXPERTKEY       hExpertKey,
                         PPROPERTYTOFIND  pPropertyToFind,
                         DWORD            TotalFramesInCapture,
                         DWORD            FramesContainingProperty,
                         PEXPERTSTATUS    pStatus,
                         PPROPERTYTRACKER PPROPERTYTRACKER);
BOOL PrintFlagsReport(   HEXPERTKEY       hExpertKey,
                         PPROPERTYTOFIND  pPropertyToFind,
                         DWORD            TotalFramesInCapture,
                         DWORD            FramesContainingProperty,
                         PEXPERTSTATUS    pStatus,
                         PPROPERTYTRACKER PPROPERTYTRACKER);
char * FindLabel( DWORD dwValue, LPPROPERTYINFO lpPropertyInfo);
char * FindFlagLabel( BYTE  BitNumber,
                      BOOL  FlagValue,
                      LPPROPERTYINFO lpPropertyInfo);

// in PropConf.cpp
BOOL ConfigPropDistDlg_Do(HWND hwnd, 
                          PPROPDISTCONFIG *ppPropDistConfig, 
                          HCAPTURE hCapture, 
                          HEXPERTKEY hExpertKey);
BOOL SizeConfigBuffer( HEXPERTKEY hExpertKey, 
                       PPROPDISTCONFIG *ppPropDistConfig,
                       DWORD BufferSize );


#pragma warning(default:4200)

#endif // _PROPDIST_H_