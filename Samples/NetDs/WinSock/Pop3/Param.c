
/*----------------------------------------------------------------------------
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1992 - 2000.  Microsoft Corporation.  All rights reserved.

This source code is only intended as a supplement to
Microsoft Development Tools and/or WinHelp documentation.
See these sources for detailed information regarding the
Microsoft samples programs.

File:       param.c

----------------------------------------------------------------------------*/

#include "pop3srvp.h"
#pragma hdrstop

WCHAR   szParamPath[] = TEXT("System\\CurrentControlSet\\Services\\Pop3Srv\\Parameters");
WCHAR   szMailDirValue[] = TEXT("Mail Directory");
WCHAR   szLoggingValue[] = TEXT("Logging Level");

//+---------------------------------------------------------------------------
//
//  Function:   ReadParameters
//
//  Synopsis:   Read parameters from registry
//
//  Arguments:  (none)
//
//  History:    1-11-95   RichardW   Created
//
//  Notes:
//
//----------------------------------------------------------------------------
BOOL
ReadParameters(VOID)
{
    HKEY    hKey;
    LONG    err;
    DWORD   ValueType;
    DWORD   SizeOfBuffer;

    if (err = RegOpenKey(HKEY_LOCAL_MACHINE, szParamPath, &hKey))
    {
        ReportServiceEvent(
            EVENTLOG_ERROR_TYPE,
            POP3EVENT_PARAMETER_MISSING,
            0, NULL, 1, szParamPath);
        DebugLog((DEB_ERROR, "Could not open key, %d\n", err));
        return(FALSE);
    }

    //
    // Now, read the parameters from the key:
    //

    SizeOfBuffer = MAX_PATH;
    err = RegQueryValueEx(  hKey,               // Key that we opened
                            szMailDirValue,     // Value that we want
                            NULL,
                            &ValueType,         // Receives value type
                            (PUCHAR) BaseDirectory,      // Receives value
                            &SizeOfBuffer );    // Size of buffer

    if (err || (ValueType != REG_SZ))
    {
        DebugLog((DEB_ERROR, "Error %d reading value\n", err));
        ReportServiceEvent(
            EVENTLOG_ERROR_TYPE,
            POP3EVENT_PARAMETER_MISSING,
            0, NULL, 1, szMailDirValue);
        RegCloseKey(hKey);
        return(FALSE);
    }

    //
    // Add a backslash, so life is easier later:
    //
    SizeOfBuffer = (DWORD) wcslen(BaseDirectory);
    if (BaseDirectory[SizeOfBuffer - 1] != L'\\')
    {
        BaseDirectory[SizeOfBuffer++] = L'\\';
        BaseDirectory[SizeOfBuffer] = L'\0';
    }

    SizeOfBuffer = sizeof(DWORD);
    err = RegQueryValueEx(  hKey,
                            szLoggingValue,
                            NULL,
                            &ValueType,
                            (PUCHAR) &LoggingLevel,
                            &SizeOfBuffer );

    if (err || ValueType != REG_DWORD)
    {
        DebugLog((DEB_ERROR, "Error %d reading value\n", err));
        ReportServiceEvent(
            EVENTLOG_ERROR_TYPE,
            POP3EVENT_PARAMETER_MISSING,
            0, NULL, 1, szLoggingValue);
        RegCloseKey(hKey);
        return(FALSE);
    }

    RegCloseKey(hKey);
    return(TRUE);
}
