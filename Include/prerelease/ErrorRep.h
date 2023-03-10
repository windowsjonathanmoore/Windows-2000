/******************************************************************************

Copyright (c) 2000 Microsoft Corporation

Module Name:
    errorrep.h

Abstract:
    contains functions used to report errors to Microsoft

******************************************************************************/	

#ifndef __ERRORREP_H__
#define __ERRORREP_H__

typedef enum tagEFaultRepRetVal
{
    frrvOk = 0,
    frrvOkManifest,
    frrvErr,
    frrvErrNoDW,
    frrvErrTimeout,
    frrvLaunchDebugger,
} EFaultRepRetVal;

EFaultRepRetVal APIENTRY ReportFault(LPEXCEPTION_POINTERS pep, DWORD dwOpt);

typedef EFaultRepRetVal (APIENTRY *pfn_REPORTFAULT)(LPEXCEPTION_POINTERS, DWORD);

#endif