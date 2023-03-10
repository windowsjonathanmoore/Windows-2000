/*++

Copyright (c) 1997 - 2000  Microsoft Corporation

Module Name:

    tracelog.c

Abstract:

    Sample trace control program. Allows user to start, stop event tracing

Author:

    Jee Fung Pang (jeepang) 03-Dec-1997

Revision History:

--*/

#define _UNICODE
#define UNICODE
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <shellapi.h>
#include <tchar.h>
#include <wmistr.h>
#include <initguid.h>
#include <guiddef.h>
#include <evntrace.h>

#define MAXSTR                          1024
#define DEFAULT_LOGFILE_NAME            _T("C:\\LogFile.Etl")
#define NT_LOGGER                       _T("NT Kernel Logger")
#define MAXIMUM_LOGGERS                  32
#define MAXGUIDS                        128

#define ACTION_QUERY                    0
#define ACTION_START                    1
#define ACTION_STOP                     2
#define ACTION_UPDATE                   3
#define ACTION_LIST                     4
#define ACTION_ENABLE                   5
#define ACTION_HELP                     6

#define IsEqualGUID(rguid1, rguid2) (!memcmp(rguid1, rguid2, sizeof(GUID)))


void
PrintLoggerStatus(
    IN PEVENT_TRACE_PROPERTIES LoggerInfo,
    IN ULONG Status
    );

LPTSTR
DecodeStatus(
    IN ULONG Status
    );

ULONG
GetGuids(LPTSTR GuidFile, LPGUID *GuidArray);

ULONG ahextoi(TCHAR *s);

TCHAR ErrorMsg[MAXSTR];

void PrintHelpMessage();

__cdecl main(argc, argv)
	int argc;
	char **argv;
{
    ULONG GuidCount, i, j;
    USHORT Action = ACTION_HELP;
    ULONG Status = 0;
    LPTSTR LoggerName;
    LPTSTR LogFileName;
    TCHAR GuidFile[MAXSTR];
    PEVENT_TRACE_PROPERTIES pLoggerInfo;
    TRACEHANDLE LoggerHandle = 0;
    LPTSTR *targv;
    LPGUID *GuidArray;
    char *Space;
    char *save;
    BOOL bKill = FALSE;
    BOOL bEnable = TRUE;
    ULONG iLevel = 0;
    ULONG iFlags = 0;
    ULONG SizeNeeded = 0;

    BOOL bProcess = TRUE;
    BOOL bThread  = TRUE;
    BOOL bDisk    = TRUE;
    BOOL bNetwork = TRUE;

    TCHAR tstrLogFileName[MAXSTR];

    // Very important!!!
    // Initialize structure first
    //
    SizeNeeded = sizeof(EVENT_TRACE_PROPERTIES) + 2 * MAXSTR * sizeof(TCHAR);
    pLoggerInfo = (PEVENT_TRACE_PROPERTIES) malloc(SizeNeeded);
    if (pLoggerInfo == NULL) {
        return(ERROR_OUTOFMEMORY);
    }
    

    RtlZeroMemory(pLoggerInfo, SizeNeeded);

    pLoggerInfo->Wnode.BufferSize = SizeNeeded;
    pLoggerInfo->Wnode.Flags = WNODE_FLAG_TRACED_GUID; 
    pLoggerInfo->LoggerNameOffset = sizeof(EVENT_TRACE_PROPERTIES);
    pLoggerInfo->LogFileNameOffset = pLoggerInfo->LoggerNameOffset 
                                     + MAXSTR * sizeof(TCHAR);

    LoggerName = (LPTSTR)((char*)pLoggerInfo + pLoggerInfo->LoggerNameOffset);
    LogFileName = (LPTSTR)((char*)pLoggerInfo + pLoggerInfo->LogFileNameOffset);
    _tcscpy(LoggerName, NT_LOGGER);

    Space = (char*) malloc( (MAXGUIDS * sizeof(GuidArray)) +
                            (MAXGUIDS * sizeof(GUID) ));
    if (Space == NULL) {
        free(pLoggerInfo);
        return(ERROR_OUTOFMEMORY);
    }
    save = Space;
    GuidArray = (LPGUID *) Space;
    Space += MAXGUIDS * sizeof(GuidArray);

    for (GuidCount=0; GuidCount<MAXGUIDS; GuidCount++) {
        GuidArray[GuidCount] = (LPGUID) Space;
        Space += sizeof(GUID);
    }
    GuidCount = 0;

#ifdef UNICODE
    if ((targv = CommandLineToArgvW(
                      GetCommandLineW(),	// pointer to a command-line string
                      &argc                 // receives the argument count
                      )) == NULL)
    {
        return(GetLastError());
    };
#else
    targv = argv;
#endif

    //
    // Add default flags. Should consider options to control this independently
    //
    while (--argc > 0) {
        ++targv;
        if (**targv == '-' || **targv == '/') {  // argument found
            if(targv[0][0] == '/' ) targv[0][0] = '-';
            if (!_tcsicmp(targv[0], _T("-start"))) {
                Action = ACTION_START;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-enable"))) {
                Action = ACTION_ENABLE;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-disable"))) {
                Action = ACTION_ENABLE;
                bEnable = FALSE;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-stop"))) {
                Action = ACTION_STOP;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-update"))) {
                Action = ACTION_UPDATE;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-q"))) {
                Action = ACTION_QUERY;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-f"))) {
                if (argc > 1) {
                    _tfullpath(LogFileName, targv[1], MAXSTR);
                    _tcscpy(tstrLogFileName, LogFileName);
                    ++targv; --argc;
                    _tprintf(_T("Setting log file to: %s\n"), LogFileName);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-guid"))) {
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        _tfullpath(GuidFile, targv[1], MAXSTR);
                        ++targv; --argc;
                        _tprintf(_T("Getting guids from %s\n"), GuidFile);
                        GuidCount = GetGuids(GuidFile, GuidArray);
                        if( !GuidCount ){
                            _tprintf( _T("Error: %s is invalid\n"), GuidFile );
                            return(0);
                        }
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-seq"))) {
                if (argc > 1) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_FILE_MODE_SEQUENTIAL;
                    pLoggerInfo->MaximumFileSize = _ttoi(targv[1]);
                    ++targv; --argc;
                    _tprintf(_T("Setting maximum sequential logfile size to: %d\n"),
                        pLoggerInfo->MaximumFileSize);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-cir"))) {
                if (argc > 1) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_FILE_MODE_CIRCULAR;
                    pLoggerInfo->MaximumFileSize = _ttoi(targv[1]);
                    ++targv; --argc;
                    _tprintf(_T("Setting maximum circular logfile size to: %d\n"),
                        pLoggerInfo->MaximumFileSize);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-b"))) {
                if (argc > 1) {
                    pLoggerInfo->BufferSize = _ttoi(targv[1]);
                    ++targv; --argc;
                    _tprintf(_T("Changing buffer size to %d\n"),
                        pLoggerInfo->BufferSize);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-flag"))) {
                if (argc > 1) {
                    pLoggerInfo->EnableFlags |= _ttoi(targv[1]);
                    ++targv; --argc;
                    _tprintf(_T("Setting logger flags to %d\n"),
                        pLoggerInfo->EnableFlags );
                }
            }
            else if (!_tcsicmp(targv[0], _T("-min"))) {
                if (argc > 1) {
                    pLoggerInfo->MinimumBuffers = _ttoi(targv[1]);
                    ++targv; --argc;
                    _tprintf(_T("Changing Minimum Number of Buffers to %d\n"),
                        pLoggerInfo->MinimumBuffers);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-max"))) {
                if (argc > 1) {
                    pLoggerInfo->MaximumBuffers = _ttoi(targv[1]);
                    ++targv; --argc;
                    _tprintf(_T("Changing Maximum Number of Buffers to %d\n"),
                        pLoggerInfo->MaximumBuffers);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-level"))) {
                if (argc > 1) {
                    iLevel = _ttoi(targv[1]);
                    ++targv; --argc;
                    _tprintf(_T("Setting tracing level to %d\n"), iLevel);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-flags"))) {
                if (argc > 1) {
                    iFlags = _ttoi(targv[1]);
                    ++targv; --argc;
                    _tprintf(_T("Setting command to %d\n"), iFlags);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-ft"))) {
                if (argc > 1) {
                    pLoggerInfo->FlushTimer = _ttoi(targv[1]);
                    ++targv; --argc;
                    _tprintf(_T("Setting buffer flush timer to %d seconds\n"),
                        pLoggerInfo->FlushTimer);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-um"))) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_PRIVATE_LOGGER_MODE;
                    _tprintf(_T("Setting Private Logger Flags\n"));
            }
            else if (!_tcsicmp(targv[0], _T("-rt"))) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_REAL_TIME_MODE;
                    _tprintf(_T("Setting real time mode\n"));
               if (argc > 1) {
                   if (targv[1][0] != '-' && targv[1][0] != '/') {
                       ++targv; --argc;
                       if (targv[0][0] == 'b')
                           pLoggerInfo->LogFileMode |= EVENT_TRACE_BUFFERING_MODE;
                   }
               }
            }
            else if (!_tcsicmp(targv[0], _T("-age"))) {
                if (argc > 1) {
                    pLoggerInfo->AgeLimit = _ttoi(targv[1]);
                    ++targv; --argc;
                    _tprintf(_T("Changing Aging Decay Time to %d\n"),
                        pLoggerInfo->AgeLimit);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-l"))) {
        		Action  = ACTION_LIST;
                bKill   = FALSE;
            }
            else if (!_tcsicmp(targv[0], _T("-x"))) {
        		Action  = ACTION_LIST;
        		bKill   = TRUE;
            }
            else if (!_tcsicmp(targv[0], _T("-noprocess"))) {
                bProcess = FALSE;
            }
            else if (!_tcsicmp(targv[0], _T("-nothread"))) {
                bThread = FALSE;
            }
            else if (!_tcsicmp(targv[0], _T("-nodisk"))) {
                bDisk = FALSE;
            }
            else if (!_tcsicmp(targv[0], _T("-nonet"))) {
                bNetwork = FALSE;
            }
            else if (!_tcsicmp(targv[0], _T("-fio"))) {
                pLoggerInfo->EnableFlags |= EVENT_TRACE_FLAG_DISK_FILE_IO;
            }
            else if (!_tcsicmp(targv[0], _T("-pf"))) {
                pLoggerInfo->EnableFlags |= EVENT_TRACE_FLAG_MEMORY_PAGE_FAULTS;
            }
            else if (!_tcsicmp(targv[0], _T("-hf"))) {
                pLoggerInfo->EnableFlags |= EVENT_TRACE_FLAG_MEMORY_HARD_FAULTS;
            }
            else if (!_tcsicmp(targv[0], _T("-img"))) {
                pLoggerInfo->EnableFlags |= EVENT_TRACE_FLAG_IMAGE_LOAD;
            }
            else if (!_tcsicmp(targv[0], _T("-cm"))) {
                pLoggerInfo->EnableFlags |= EVENT_TRACE_FLAG_REGISTRY;
            }
            else if ( targv[0][1] == 'h' || targv[0][1] == 'H' || targv[0][1] == '?'){
                PrintHelpMessage();
                return 0;
            }
            else Action = ACTION_HELP;
        }
        else { // get here if "-" or "/" given
            _tprintf(_T("Invalid option given: %s\n"), targv[0]);
            return 0;
        }
    }
    if (!_tcscmp(LoggerName, NT_LOGGER)) {
        if (bProcess)
            pLoggerInfo->EnableFlags |= EVENT_TRACE_FLAG_PROCESS;
        if (bThread)
            pLoggerInfo->EnableFlags |= EVENT_TRACE_FLAG_THREAD;
        if (bDisk)
            pLoggerInfo->EnableFlags |= EVENT_TRACE_FLAG_DISK_IO;
        if (bNetwork)
            pLoggerInfo->EnableFlags |= EVENT_TRACE_FLAG_NETWORK_TCPIP;

        pLoggerInfo->Wnode.Guid = SystemTraceControlGuid;   // default to OS tracing
    }

    if ( !(pLoggerInfo->LogFileMode & EVENT_TRACE_REAL_TIME_MODE) ) {
        if (_tcslen(LogFileName) <= 0 && Action == ACTION_START) {
            _tcscpy(LogFileName, DEFAULT_LOGFILE_NAME); // for now...
            _tcscpy(tstrLogFileName, DEFAULT_LOGFILE_NAME);
        }
    }

    switch (Action) {
        case  ACTION_START:
        {

           if (pLoggerInfo->LogFileMode & EVENT_TRACE_PRIVATE_LOGGER_MODE) {
               if (GuidCount != 1) {
                   _tprintf(_T("Need exactly one GUID for PRIVATE loggers\n"));
                   return 0;
               }
               pLoggerInfo->Wnode.Guid = *GuidArray[0];
           }

            Status = StartTrace(&LoggerHandle, LoggerName, pLoggerInfo);

            if (Status != ERROR_SUCCESS) {
                _tprintf(_T("Could not start logger: %s\n") 
                         _T("Operation Status:       %uL\n")
                         _T("%s\n"),
                         LoggerName,
                         Status,
                         DecodeStatus(Status));

                return Status;
            }
            _tprintf(_T("Logger Started...\n"));


        case ACTION_ENABLE:

            if (Action == ACTION_ENABLE ){

                if (pLoggerInfo->LogFileMode & EVENT_TRACE_PRIVATE_LOGGER_MODE)
                {
                    if (GuidCount != 1)
                    {
                        _tprintf(_T("Need one GUID for PRIVATE loggers\n"));
                        return 0;
                    }
                    pLoggerInfo->Wnode.Guid = *GuidArray[0];
                }

                Status = QueryTrace((TRACEHANDLE) 0, LoggerName, pLoggerInfo);
                if( Status != ERROR_SUCCESS ){
                    _tprintf( _T("ERROR: Logger not started\n")
                              _T("Operation Status:    %uL\n")
                              _T("%s\n"),
                              Status,
                              DecodeStatus(Status));
                    return(0);
                }
                LoggerHandle = pLoggerInfo->Wnode.HistoricalContext;
            }

            if ( (GuidCount > 0) && 
                 (!IsEqualGUID(&pLoggerInfo->Wnode.Guid, &SystemTraceControlGuid))
               ) {

                _tprintf(_T("Enabling trace to logger %d\n"), LoggerHandle);
                for (i=0; i<GuidCount; i++) {
                    Status = EnableTrace (
                                    bEnable,
                                    iFlags,
                                    iLevel,
                                    GuidArray[i], 
                                    LoggerHandle);

                    //
                    // If the Guid can not be enabled, it is a benign 
                    // failure. Print Warning message and continue. 
                    //
                    if (Status == 4317) {
                       _tprintf(_T("WARNING: Could not enable some guids.\n")); 
                       _tprintf(_T("Check your Guids file\n")); 
                        Status = ERROR_SUCCESS;
                    }

                    if (Status != ERROR_SUCCESS) {
                        _tprintf(_T("ERROR: Failed to enable Guid [%d]...\n"), i);
                        _tprintf(_T("Operation Status:       %uL\n"), Status);
                        _tprintf(_T("%s\n"),DecodeStatus(Status));
                        return Status;
                    }
                }
            }
            else {
                if (GuidCount > 0)
                    _tprintf(_T("ERROR: System Logger does not accept application guids...\n"));
            }
        }
        break;

        case ACTION_STOP :

            if (pLoggerInfo->LogFileMode & EVENT_TRACE_PRIVATE_LOGGER_MODE) {
                if (GuidCount != 1) {
                    _tprintf(_T("Need exactly one GUID for PRIVATE loggers\n"));
                    return 0;
                }
                pLoggerInfo->Wnode.Guid = *GuidArray[0];
            }

            if (!IsEqualGUID(&pLoggerInfo->Wnode.Guid, &SystemTraceControlGuid)) {
                if ((pLoggerInfo->LogFileMode & EVENT_TRACE_PRIVATE_LOGGER_MODE)) {
                    Status = QueryTrace(
                            (TRACEHANDLE) 0, LoggerName, pLoggerInfo);
                    LoggerHandle = pLoggerInfo->Wnode.HistoricalContext;
                    Status = EnableTrace( FALSE,
                                          EVENT_TRACE_PRIVATE_LOGGER_MODE,
                                          0,
                                          GuidArray[0],
                                          LoggerHandle );
                }
                else {
                    Status = QueryTrace( (TRACEHANDLE)0, LoggerName, pLoggerInfo );
                    LoggerHandle = pLoggerInfo->Wnode.HistoricalContext;

                    for (i=0; i<GuidCount; i++) {
                    Status = EnableTrace( FALSE,
                                              0,
                                              0,
                                              GuidArray[i],
                                              LoggerHandle);
                    }

                }
            }

            Status = StopTrace((TRACEHANDLE)0, LoggerName, pLoggerInfo);
            break;

	case ACTION_LIST :
	{
        ULONG i, returnCount ;
        ULONG SizeNeeded;
        PEVENT_TRACE_PROPERTIES pLoggerInfo[MAXIMUM_LOGGERS];
        PEVENT_TRACE_PROPERTIES pStorage;
        PVOID Storage;

        SizeNeeded = MAXIMUM_LOGGERS * (sizeof(EVENT_TRACE_PROPERTIES)
                                      + 2 * MAXSTR * sizeof(TCHAR));

        Storage =  malloc(SizeNeeded);
        if (Storage == NULL) 
            return ERROR_OUTOFMEMORY;
        RtlZeroMemory(Storage, SizeNeeded);

        pStorage = (PEVENT_TRACE_PROPERTIES)Storage;
        for (i=0; i<MAXIMUM_LOGGERS; i++) {
            pStorage->Wnode.BufferSize = sizeof(EVENT_TRACE_PROPERTIES)
                                         + 2 * MAXSTR * sizeof(TCHAR);
            pStorage->LogFileNameOffset = sizeof(EVENT_TRACE_PROPERTIES)
                                        + MAXSTR * sizeof(TCHAR);
            pStorage->LoggerNameOffset = sizeof(EVENT_TRACE_PROPERTIES);
            pLoggerInfo[i] = pStorage;
            pStorage = (PEVENT_TRACE_PROPERTIES) (
                                 (char*)pStorage + 
                                  pStorage->Wnode.BufferSize);
        }
        
        Status = QueryAllTraces(pLoggerInfo,
                                MAXIMUM_LOGGERS,
                                & returnCount);
    
        if (Status == ERROR_SUCCESS)
        {
            for (j= 0; j < returnCount; j++)
            {
                if (bKill)
                {
                    LPTSTR LoggerName;
                    LoggerName = (LPTSTR) ((char*)pLoggerInfo[j] + 
                                  pLoggerInfo[j]->LoggerNameOffset);

                    if (!IsEqualGUID(& pLoggerInfo[j]->Wnode.Guid,
                                     & SystemTraceControlGuid))
                    {
                        LoggerHandle = pLoggerInfo[j]->Wnode.HistoricalContext;
                        Status = EnableTrace(
                                      FALSE,
                                      (pLoggerInfo[j]->LogFileMode &
                                              EVENT_TRACE_PRIVATE_LOGGER_MODE)
                                          ? (EVENT_TRACE_PRIVATE_LOGGER_MODE)
                                          : (0),
                                      0,
                                      & pLoggerInfo[j]->Wnode.Guid,
                                      LoggerHandle);
                    }
                    Status = StopTrace((TRACEHANDLE) 0,
                                        LoggerName,
                                        pLoggerInfo[j]);
	            }
                PrintLoggerStatus(pLoggerInfo[j], Status);
                printf("\n");
            }
        }
        else 
            printf("Error: Query failed with Status %d\n", Status);

        i = 0;
        free(Storage);
        return 0;
    }

        case ACTION_UPDATE :
        case ACTION_QUERY:
            if (pLoggerInfo->LogFileMode & EVENT_TRACE_PRIVATE_LOGGER_MODE) {
                if (GuidCount != 1) {
                    _tprintf(_T("Need exactly one GUID for PRIVATE loggers\n"));
                    return 0;
                }
                pLoggerInfo->Wnode.Guid = *GuidArray[0];
            }
            if (Action == ACTION_QUERY) {
                Status = QueryTrace(LoggerHandle, LoggerName, pLoggerInfo);
            }

            if (Action == ACTION_UPDATE) {
                Status = UpdateTrace(LoggerHandle, LoggerName, pLoggerInfo);
            }
            break;

        case ACTION_HELP:
        default :
            PrintHelpMessage();
            break;
    }
    
    if (Action != ACTION_HELP) 
        PrintLoggerStatus(pLoggerInfo, Status);


    GlobalFree(targv);
    free(pLoggerInfo);
    free(save);
    return(Status);
}

void
PrintLoggerStatus(
    IN PEVENT_TRACE_PROPERTIES LoggerInfo,
    IN ULONG Status
    )
{
    LPTSTR LoggerName, LogFileName;
    
    if ((LoggerInfo->LoggerNameOffset > 0) &&
        (LoggerInfo->LoggerNameOffset  < LoggerInfo->Wnode.BufferSize)) {
        LoggerName = (LPTSTR) ((char*)LoggerInfo +
                                LoggerInfo->LoggerNameOffset);
    }
    else LoggerName = NULL;

    if ((LoggerInfo->LogFileNameOffset > 0) &&
        (LoggerInfo->LogFileNameOffset  < LoggerInfo->Wnode.BufferSize)) {
        LogFileName = (LPTSTR) ((char*)LoggerInfo +
                                LoggerInfo->LogFileNameOffset);
    }
    else LogFileName = NULL;

    _tprintf(_T("Operation Status:       %uL\n"), Status);
    _tprintf(_T("%s\n"), DecodeStatus(Status));

    _tprintf(_T("Logger Name:            %s\n"),
        (LoggerName == NULL) ?
            _T(" ") : LoggerName);
    _tprintf(_T("Logger Id:              %I64x\n"), LoggerInfo->Wnode.HistoricalContext);
    _tprintf(_T("Logger Thread Id:       %d\n"), LoggerInfo->LoggerThreadId);
    if (Status != 0)
        return;

    _tprintf(_T("Buffer Size:            %d Kb\n"), LoggerInfo->BufferSize);
    _tprintf(_T("Maximum Buffers:        %d\n"), LoggerInfo->MaximumBuffers);
    _tprintf(_T("Minimum Buffers:        %d\n"), LoggerInfo->MinimumBuffers);
    _tprintf(_T("Number of Buffers:      %d\n"), LoggerInfo->NumberOfBuffers);
    _tprintf(_T("Free Buffers:           %d\n"), LoggerInfo->FreeBuffers);
    _tprintf(_T("Buffers Written:        %d\n"), LoggerInfo->BuffersWritten);
    _tprintf(_T("Events Lost:            %d\n"), LoggerInfo->EventsLost);
    _tprintf(_T("Log Buffers Lost:       %d\n"), LoggerInfo->LogBuffersLost);
    _tprintf(_T("Real Time Buffers Lost: %d\n"), LoggerInfo->RealTimeBuffersLost);

    if (LogFileName == NULL) {
        _tprintf(_T("Buffering Mode:         "));
    }
    else {
        _tprintf(_T("Log File Mode:          "));
    }
    if (LoggerInfo->LogFileMode & EVENT_TRACE_FILE_MODE_CIRCULAR) {
        _tprintf(_T("Circular\n"));
    }
    else if (LoggerInfo->LogFileMode & EVENT_TRACE_FILE_MODE_SEQUENTIAL) {
        _tprintf(_T("Sequential\n"));
    }
    else {
        _tprintf(_T("Sequential\n"));
    }
    if (LoggerInfo->LogFileMode & EVENT_TRACE_REAL_TIME_MODE) {
        _tprintf(_T("Real Time mode enabled"));
        if (LoggerInfo->LogFileMode & EVENT_TRACE_BUFFERING_MODE) {
            _tprintf(_T(": buffering only"));
        }
        _tprintf(_T("\n"));
    }

    if (LoggerInfo->MaximumFileSize > 0)
        _tprintf(_T("Maximum File Size:      %d Mb\n"), LoggerInfo->MaximumFileSize);

    if (LoggerInfo->FlushTimer > 0)
        _tprintf(_T("Buffer Flush Timer:     %d secs\n"), LoggerInfo->FlushTimer);

    if (LoggerInfo->EnableFlags != 0) {
        _tprintf(_T("Enabled tracing:        "));

        if ((LoggerName != NULL) && (!_tcscmp(LoggerName,NT_LOGGER))) {

            if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_PROCESS)
                _tprintf(_T("Process "));
            if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_THREAD)
                _tprintf(_T("Thread "));
            if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_DISK_IO)
                _tprintf(_T("Disk "));
            if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_DISK_FILE_IO)
                _tprintf(_T("File "));
            if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_MEMORY_PAGE_FAULTS)
                _tprintf(_T("PageFaults "));
            if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_MEMORY_HARD_FAULTS)
                _tprintf(_T("HardFaults "));
            if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_IMAGE_LOAD)
                _tprintf(_T("ImageLoad "));
            if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_NETWORK_TCPIP)
                _tprintf(_T("TcpIp "));
            if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_REGISTRY)
                _tprintf(_T("Registry "));
        }else{
            _tprintf(_T("0x%08x"), LoggerInfo->EnableFlags );
        }
        _tprintf(_T("\n"));
    }
    if (LogFileName != NULL) {
        _tprintf(_T("Log Filename:           %s\n"), LogFileName);
    }
}

LPTSTR
DecodeStatus(
    IN ULONG Status
    )
{
    memset( ErrorMsg, 0, MAXSTR );
    FormatMessage(     
        FORMAT_MESSAGE_FROM_SYSTEM |     
        FORMAT_MESSAGE_IGNORE_INSERTS,    
        NULL,
        Status,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
        (LPTSTR) ErrorMsg,
        MAXSTR,
        NULL );

    return ErrorMsg;
}

ULONG
GetGuids(LPTSTR GuidFile, LPGUID *GuidArray)
{
    FILE *f;
    TCHAR line[MAXSTR], arg[MAXSTR];
    LPGUID Guid;
    int i, n;

    f = _tfopen((TCHAR*)GuidFile, _T("r"));

    if (f == NULL)
        return 0;

    n = 0;
    while ( _fgetts(line, MAXSTR, f) != NULL ) {
        if (_tcslen(line) < 36)
            continue;
        if (line[0] == ';'  || 
            line[0] == '\0' || 
            line[0] == '#' || 
            line[0] == '/')
            continue;
        Guid = (LPGUID) GuidArray[n];
        n ++;

        _tcsncpy(arg, line, 8);
        arg[8] = 0;
        Guid->Data1 = ahextoi(arg);
        _tcsncpy(arg, &line[9], 4);
        arg[4] = 0;
        Guid->Data2 = (USHORT) ahextoi(arg);
        _tcsncpy(arg, &line[14], 4);
        arg[4] = 0;
        Guid->Data3 = (USHORT) ahextoi(arg);

        for (i=0; i<2; i++) {
            _tcsncpy(arg, &line[19 + (i*2)], 2);
            arg[2] = 0;
            Guid->Data4[i] = (UCHAR) ahextoi(arg);
        }
        for (i=2; i<8; i++) {
            _tcsncpy(arg, &line[20 + (i*2)], 2);
            arg[2] = 0;
            Guid->Data4[i] = (UCHAR) ahextoi(arg);
        }
    }
    return (ULONG)n;
}

ULONG ahextoi(TCHAR *s)
{
    int len;
    ULONG num, base, hex;

    len = _tcslen(s);
    hex = 0; base = 1; num = 0;
    while (--len >= 0) {
        if ( (s[len] == 'x' || s[len] == 'X') &&
             (s[len-1] == '0') )
            break;
        if (s[len] >= '0' && s[len] <= '9')
            num = s[len] - '0';
        else if (s[len] >= 'a' && s[len] <= 'f')
            num = (s[len] - 'a') + 10;
        else if (s[len] >= 'A' && s[len] <= 'F')
            num = (s[len] - 'A') + 10;
        else 
            continue;

        hex += num * base;
        base = base * 16;
    }
    return hex;
}

void PrintHelpMessage()
{
    _tprintf(
        _T("Usage: tracelog [options] | [-h | -help | -?]\n")
        _T("\t-start  [LoggerName] Starts up the [LoggerName] trace session\n")
        _T("\t-stop   [LoggerName] Stops the [LoggerName] trace session\n")
        _T("\t-update [LoggerName] Updates the [LoggerName] trace session\n")
        _T("\t-b   <n>             Sets buffer size to <n> Kbytes\n")
        _T("\t-min <n>             Sets minimum buffers\n")
        _T("\t-max <n>             Sets maximum buffers\n")
        _T("\t-l                   List all trace sessions\n")
        _T("\t-x                   Stops all active trace sessions\n")
        _T("\t-q [LoggerName]      Query status of [LoggerName] trace session\n")
        _T("\t-f <name>            Log to file <name>\n")
        _T("\t-seq <n>             Sequential logfile of up to n Mbytes\n")
        _T("\t-cir <n>             Circular logfile of n Mbytes\n")
        _T("\t-ft <n>              Set flush timer to n seconds\n")
        _T("\t-noprocess           Disable Process Start/End tracing\n")
        _T("\t-nothread            Disable Thread Start/End tracing\n")
        _T("\t-nodisk              Disable Disk I/O tracing\n")
        _T("\t-nonet               Disable Network TCP/IP tracing\n")
        _T("\t-fio                 Enable file I/O tracing\n")
        _T("\t-pf                  Enable page faults tracing\n")
        _T("\t-hf                  Enable hard faults tracing\n")
        _T("\t-img                 Enable image load tracing\n")
        _T("\t-cm                  Enable registry calls tracing\n")
        _T("\t-um                  Enable Process Private tracing\n")
        _T("\t-guid <file>         Start tracing for providers in file\n")
        _T("\t-rt                  Enable tracing in real time mode\n")
        _T("\t-age <n>             Modify aging decay time to n minutes\n")
        _T("\t-level <n>           Enable Level passed to the providers\n")
        _T("\t-flags <n>           Enable Flags passed to the providers\n")
        _T("\t-h\n")
        _T("\t-help\n")
        _T("\t-?                   Display usage information\n")
        );
}
