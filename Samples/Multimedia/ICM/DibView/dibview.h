/*++

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1998 - 2000.  Microsoft Corporation.  All rights reserved.

Module Name:
    
    dibview.h

Abstract:
    
    Header file for dibview.c

--*/

#ifndef DIBVIEW_H
#define DIBVIEW_H

//
// Function prototypes
//

BOOL
DetermineOSVersion();

BOOL 
InitInstance(
    HINSTANCE hInstance, 
    int nCmdShow
);

BOOL
ParseCommandLine(
    int nCmdShow
);

BOOL
LoadStringTable();

VOID
UnloadStringTable();

#ifdef TWAIN_ENABLED

BOOL
RegisterSTIApplication();

BOOL
UnregisterSTIApplication();

BOOL
IsLaunchedByEventMonitor(
    int nCmdShow
);

#endif //TWAIN_ENABLED

#endif //DIBVIEW_H

