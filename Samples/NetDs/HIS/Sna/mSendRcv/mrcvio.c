/*****************************************************************************/
/*                                                                           */
/* mrcvio.c - /*  Copyright (c) Microsoft Corporation.  All rights reserved. */
/*                                                                           */
/*                                                                           */
/*   RECEIVE using I/O completion port event completion                      */
/*   ==================================================                      */
/*                                                                           */
/*                                                                           */
/* Usage                                                                     */
/* -----                                                                     */
/*                                                                           */
/* mrcvio  [-n numRcvThreads] [-c numRcvConvs] [-d duration] [-r rcvSize]    */
/*         [-t TPName] [-i IntTraceFile]                                     */
/*                                                                           */
/* NumRcvThreads - number of Completion Port threads, default 4, max 32      */
/* NumRcvConvs   - Maximum number of conversations, default 8, max 64        */
/* Duration      - number of seconds for which the application should run,   */
/*                 default 60.  A value of 0 means run indefinitely          */
/* RcvSize       - size in bytes of the buffer supplied on each              */
/*                 RECEIVE_ALLOCATE, default 4096, max 65535                 */
/* TPName        - name supplied on RECEIVE_ALLOCATES, default "MRCVTP"      */
/* IntTraceFile  - Internal trace file                                       */
/*                                                                           */
/*                                                                           */
/* Operation                                                                 */
/* ---------                                                                 */
/*                                                                           */
/* This file contains the routines for a multi-threaded console application  */
/* which uses asynchronous APPC calls on a single I/O completion port to     */
/* receive data.                                                             */
/*                                                                           */
/* It runs with one of:                                                      */
/* - the single-threaded version of send (sendtp)                            */
/* - the multi-threaded event-based versions of send (msend, msendrcv)       */
/*                                                                           */
/* This program uses a "server" model which continues to accept              */
/* conversations via RECEIVE_ALLOCATE until the application is manually      */
/* terminated, or a specified timer expires.  The conversations do not       */
/* belong to any particular RECEIVE thread.                                  */
/*                                                                           */
/* Each receive thread issues GetQueuedCompletionStatus calls to wait for    */
/* completion of an APPC verb (on any conversation).  Each conversation      */
/* issues MC_RECEIVE_AND_WAIT verbs to receive data.  If confirmation is     */
/* requested, an MC_CONFIRM verb is issued.                                  */
/*                                                                           */
/*                                                                           */
/* Change History                                                            */
/* --------------                                                            */
/*                                                                           */
/* -----  30/06/99  MB   Created as test tool                                */
/* -----  05/01/00  PH   Update for use as sample code                       */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* include source                                                            */
/*****************************************************************************/
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winappc.h>
#include <wincsv.h>
#include "mrcvio.h"

/*****************************************************************************/
/*                                                                           */
/*   Main                                                                    */
/*                                                                           */
/*****************************************************************************/
int __cdecl main (int argc, char *argv[])
{
  WAPPCDATA APPCData;
  HANDLE    threadHandle[MAX_IOCP_THREADS];
  DWORD     waitOutcome;
  DWORD     lastError;
  DWORD     dummyThreadId;
  int       ii;
  unsigned long seconds;

  /***************************************************************************/
  /* Set default values for Configuration                                    */
  /***************************************************************************/
  NumRcvThreads = 4;
  NumRcvConvs = 8;
  Duration = 60;
  RcvSize = 4096;
  memset(TPName, ' ', 64);
  memcpy(TPName, "MRCVTP", 6);
  internalTracing = FALSE;

  TotalBytesRcvd = 0;

  /***************************************************************************/
  /* Parse the command line                                                  */
  /***************************************************************************/
  for (ii = 1; ii < argc; ii++)
  {
    /* Help :Display usage info                                              */
    if ((STRMATCH(argv[ii], "-h")) || (STRMATCH(argv[ii], "/h")) ||
        (STRMATCH(argv[ii], "-H")) || (STRMATCH(argv[ii], "/H")) ||
        (STRMATCH(argv[ii], "-?")) || (STRMATCH(argv[ii], "/?")))
    {
      printf("\n");
      printf("\nUSAGE: mrcvio  [-n numRcvThreads] [-c numRcvConvs] [-d duration] [-r rcvSize]");
      printf("\n               [-t TPName] [-i IntTraceFile]");
      printf("\n");
      printf("\nNumRcvThreads - number of Completion Port threads, default 4, max 32");
      printf("\nNumRcvConvs   - Maximum number of conversations, default 8, max 64");
      printf("\nDuration      - number of seconds for which the application should run,");
      printf("\n                default 60. A value of 0 means run indefinitely");
      printf("\nRcvSize       - size in bytes of the buffer supplied on each RECEIVE_ALLOCATE,");
      printf("\n                default 4096");
      printf("\nTPName        - name supplied on RECEIVE_ALLOCATES, default \"MRCVTP\"");
      printf("\nIntTraceFile  - Internal trace file, default none");
      printf("\n");

      goto EXIT_Main;
    }
    /* -n :Next argument is NumRcvThreads                                    */
    else if ((ii < argc - 1) &&
             ((STRMATCH(argv[ii], "-n")) || (STRMATCH(argv[ii], "-N"))))
    {
      ii++;
      sscanf(argv[ii], "%d", &NumRcvThreads);
      if (NumRcvThreads > MAX_IOCP_THREADS)
      {
        NumRcvThreads = MAX_IOCP_THREADS;
      }
    }
    /* -c :Next argument is NumRcvConvs                                      */
    else if ((ii < argc - 1) &&
             ((STRMATCH(argv[ii], "-c")) || (STRMATCH(argv[ii], "-C"))))
    {
      ii++;
      sscanf(argv[ii], "%d", &NumRcvConvs);
      if (NumRcvConvs > 64)
      {
        NumRcvConvs = 64;
      }
    }
    /* -d :Next argument is Duration                                         */
    else if ((ii < argc - 1) &&
             ((STRMATCH(argv[ii], "-d")) || (STRMATCH(argv[ii], "-D"))))
    {
      ii++;
      sscanf(argv[ii], "%d", &Duration);
    }
    /* -d :Next argument is RcvSize                                          */
    else if ((ii < argc - 1) &&
             ((STRMATCH(argv[ii], "-r")) || (STRMATCH(argv[ii], "-R"))))
    {
      ii++;
      sscanf(argv[ii], "%d", &RcvSize);
    }
    /* -t :Next argument is TPName                                           */
    else if ((ii < argc - 1) &&
             ((STRMATCH(argv[ii], "-t")) || (STRMATCH(argv[ii], "-T"))))
    {
      ii++;
      memcpy(TPName, argv[ii], strlen(argv[ii]));
    }
    /* -t :Next argument is IntTraceFile                                     */
    else if ((ii < argc - 1) &&
             ((STRMATCH(argv[ii], "-i")) || (STRMATCH(argv[ii], "-I"))))
    {
      ii++;
      internalTracing = TRUE;
      strcpy(IntTraceFile, argv[ii]);
    }
  }

  SRTROPEN(IntTraceFile);
  SRTRACE(t,"Internal trace started");

  /***************************************************************************/
  /* Display Configuration values to be used                                 */
  /***************************************************************************/
  printf("\nNumRcvThreads - %d", NumRcvThreads);
  printf("\nNumRcvConvs   - %d", NumRcvConvs);
  printf("\nDuration      - %d seconds", Duration);
  printf("\nRcvSize       - %d bytes", RcvSize);
  printf("\nTPName        - %64.64s", TPName);
  printf("\nIntTraceFile  - %s", internalTracing ? IntTraceFile : "NONE");
  printf("\n");

  CONV_A_TO_E(TPName, 64);

  /***************************************************************************/
  /* Initialize the APPC Library                                             */
  /***************************************************************************/
  if (WinAPPCStartup(WinAPPCVERSION,&APPCData))
  {
    SRTRACE(t,"\nERROR: WinAPPCStartup failed");
    printf("\nERROR: WinAPPCStartup failed");
    goto EXIT_Main;
  }

  /***************************************************************************/
  /* Create a completion port for the receive threads.                       */
  /***************************************************************************/
  RcvThreadCompletionPort = CreateIoCompletionPort(
    INVALID_HANDLE_VALUE, /* file handle to associate with completion port   */
    NULL,                 /* optional handle to existing completion port     */
    0,                    /* per-file completion key for completion packets  */
    0);                   /* no. of threads allowed to execute concurrently  */

  if (!RcvThreadCompletionPort)
  {
    lastError = GetLastError();
    SRTRACE(t,"\nERROR: CreateIoCompletionPort failed (%d)", lastError);
    printf("\nERROR: CreateIoCompletionPort failed (%d)", lastError);
    goto EXIT_Main;
  }

  /***************************************************************************/
  /* Create receive threads                                                  */
  /***************************************************************************/
  for (ii = 0; ii < NumRcvThreads; ii++)
  {
    threadHandle[ii] = CreateThread(NULL,
                                    16000,
                                    (LPTHREAD_START_ROUTINE)ReceiveThread,
                                    (void*)ii,
                                    0,
                                    &dummyThreadId);
    if (threadHandle[ii] == NULL)
    {
      lastError = GetLastError();
      SRTRACE(t,"\nERROR: CreateThread failed, lastError %d", lastError);
      printf("\nERROR: CreateThread failed, lastError %d", lastError);
      goto EXIT_Main;
    }

    SetThreadPriority(threadHandle[ii],THREAD_PRIORITY_LOWEST);
    SRTRACE(t,"\nCreated receive thread %d with priority %d",
            ii, GetThreadPriority(threadHandle[ii]));
  }

  /***************************************************************************/
  /* Kick off the specified number of conversations                          */
  /***************************************************************************/
  for (ii = 1; ii <= NumRcvConvs; ii++)
  {
    SRTRACE(t,"\nKick off conversation %d", ii);
    if (!PostQueuedCompletionStatus(RcvThreadCompletionPort,
                                    0,
                                    IOCP_START_CONVERSATION,
                                    (LPOVERLAPPED)NULL))
    {
      lastError = GetLastError();
      SRTRACE(t,"\nERROR: PostQueueCompletionStatus failed (%d)", lastError);
      printf("\nERROR: PostQueueCompletionStatus failed (%d)", lastError);
      goto EXIT_Main;
    }
  }

  /***************************************************************************/
  /* Wait for the Specified amount of time                                   */
  /***************************************************************************/
  printf("\n");
  seconds = Duration;
  do
  {
    Sleep(1000);
    if (Duration)
    {
      seconds--;
    }
    else
    {
      seconds++;
    }
    printf("%2.2d:%2.2d:%2.2d  Bytes Received = %10.10d\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
           seconds/3600, (seconds/60)%60, seconds%60, TotalBytesRcvd);

  } while (seconds > 0);

  SRTRACE(t,"\nTimer expired");
  printf("\n");
  printf("\nCommand completed");
  printf("\n");

  /***************************************************************************/
  /* EXIT and cleanup                                                        */
  /***************************************************************************/
EXIT_Main:

  /***************************************************************************/
  /* Signal the IO Threads to self-destruct, give them some time to do so,   */
  /* and if they don't, close their handles anyway.                          */
  /***************************************************************************/
  if (RcvThreadCompletionPort)
  {
    for (ii = 0; ii < NumRcvThreads; ii++)
    {
      SRTRACE(t,"\nSend off terminate request %d", ii);

      if (!PostQueuedCompletionStatus(RcvThreadCompletionPort,
                                      0,        /* lpNumberOfBytesTranferred */
                                      IOCP_TERMINATE_THREAD,
                                      NULL))    /* lpOverlapped              */
      {
        lastError = GetLastError();
        SRTRACE(t,"\nERROR: PostQueueCompletionStatus failed (%d)", lastError);
        printf("\nERROR: PostQueueCompletionStatus failed (%d)", lastError);
      }
    }

    for (ii = 0; ii < NumRcvThreads; ii++)
    {
      SRTRACE(t,"\nWait for termination %d", ii);
      if (threadHandle[ii])
      {
        waitOutcome = WaitForSingleObject(threadHandle[ii], 2000);
        if (waitOutcome != WAIT_OBJECT_0)
        {
          lastError = GetLastError();
          SRTRACE(t,"\nERROR: Problem waiting for thread to die (%d, %d)",
                  waitOutcome, lastError);
          printf("\nERROR: Problem waiting for thread to die (%d, %d)",
                 waitOutcome, lastError);
        }

        CloseHandle(threadHandle[ii]);
        threadHandle[ii] = NULL;
      }
    }

    CloseHandle(RcvThreadCompletionPort);
    RcvThreadCompletionPort = NULL;
  }

  /***************************************************************************/
  /* Terminate the APPC Library                                              */
  /***************************************************************************/
  WinAPPCCleanup();

  SRTRACE(t,"\nInternal trace ending");
  SRTRFLUSH();
  SRTRCLOSE();

  return(0);
}


/*****************************************************************************/
/*                                                                           */
/*   ReceiveThread - Service thread which processes multiple conversations.  */
/*                   This routine is the main routine for each IOCP thread.  */
/*                                                                           */
/*****************************************************************************/
DWORD WINAPI ReceiveThread(DWORD threadNo)
{
  /***************************************************************************/
  /* Separate variables for each instance of this thread                     */
  /***************************************************************************/
  DWORD        lastError;
  BOOL         gotQueuedRequest;
  DWORD        dummyBytes;
  DWORD        CompletionKey;
  LPOVERLAPPED Overlapped;
  CONVCB      *convptr;

  SRTRACE(t,"\nThread%d: IOCP thread started", threadNo);

  /***************************************************************************/
  /* Loop round until we get a request for the thread to terminate or hit a  */
  /* serious internal error (e.g. a system call failure)                     */
  /***************************************************************************/
  while (TRUE)
  {
    /*************************************************************************/
    /* Wait on I/O completion port for event, then act dependent upon the    */
    /* Completion Key.                                                       */
    /*************************************************************************/
    gotQueuedRequest =
      GetQueuedCompletionStatus(RcvThreadCompletionPort,
                                &dummyBytes,
                                &CompletionKey,
                                &Overlapped,
                                INFINITE);
    if (gotQueuedRequest)
    {
      SRTRACE(t,"\nThread%d: Got queued req, key %d", threadNo, CompletionKey);
      SRTRFLUSH();

      switch (CompletionKey)
      {
        /*********************************************************************/
        /* IOCP_START_CONVERSATION - Create a conversation control block and */
        /*                           data storage area, and issue the first  */
        /*                           RCVALLOC.                               */
        /*********************************************************************/
        case IOCP_START_CONVERSATION:
        {
          SRTRACE(t,"\nThread%d: Issue 1st RCVALLOC", threadNo);

          convptr = malloc (sizeof(CONVCB));
          if (convptr != NULL)
          {
            convptr->dataPtr = malloc(RcvSize);
          }
          if ((convptr == NULL) || (convptr->dataPtr == NULL))
          {
            SRTRACE(t,"\nERROR: Memory allocation failed");
            printf("\nERROR: Memory allocation failed");
            goto EXIT_ReceiveThread;
          }

          SRTRACE(t,"\nThread%d: Conv 0x%8.8X: Set up cb (data at 0x%8.8X)",
                     threadNo, convptr, convptr->dataPtr);

          if (!IssueFirstVerb(convptr))
          {
            SRTRACE(t,"\nERROR: IssueFirstVerb failed");
            printf("\nERROR: IssueFirstVerb failed");
            goto EXIT_ReceiveThread;
          }
          break;
        }

        /*********************************************************************/
        /* IOCP_VERB_COMPLETE - Verb has completed, so issue the next verb.  */
        /*                      (Overlapped is control block pointer.)       */
        /*********************************************************************/
        case IOCP_VERB_COMPLETE:
        {
          convptr = (CONVCB *)Overlapped;
          SRTRACE(t,"\nThread%d: Conv 0x%8.8X: Verb complete",
                  threadNo, convptr);

          if (!IssueNextVerb(convptr))
          {
            SRTRACE(t,"\nThread%d: Conv 0x%8.8X: ERROR: IssueNextVerb failed",
                    threadNo, convptr);
            printf("\nERROR: IssueNextVerb failed");
            goto EXIT_ReceiveThread;
          }
          break;
        }

        /*********************************************************************/
        /* IOCP_END_CONVERSATION - The conversation has been ended - free    */
        /*                         resources then kick off a new             */
        /*                         conversation (Overlapped is the control   */
        /*                         block pointer).                           */
        /*********************************************************************/
        case IOCP_END_CONVERSATION:
        {
          convptr = (CONVCB *)Overlapped;
          SRTRACE(t,"\nThread%d: Conv 0x%8.8X: Ending.", threadNo, convptr);

          free(convptr->dataPtr);
          free(convptr);

          if (!PostQueuedCompletionStatus(RcvThreadCompletionPort,
                                          0,
                                          IOCP_START_CONVERSATION,
                                          (LPOVERLAPPED)NULL))
          {
            lastError = GetLastError();
            SRTRACE(t,"\nThread%d: ERROR: PQCS failed (%d)",
                    threadNo, lastError);
            printf("\nERROR: PostQueueCompletionStatus failed (%d)",lastError);
            goto EXIT_ReceiveThread;
          }

          SRTRFLUSH();
          break;
        }

        /*********************************************************************/
        /* IOCP_TERMINATE_THREAD - Thread termination requested              */
        /*********************************************************************/
        case IOCP_TERMINATE_THREAD:
        {
          SRTRACE(t,"\nThread%d: Thread termination requested", threadNo);
          goto EXIT_ReceiveThread;
          break;
        }

        /*********************************************************************/
        /* DEFAULT - Unexpected key                                          */
        /*********************************************************************/
        default:
        {
          convptr = (CONVCB *)Overlapped;
          SRTRACE(t,"\nThread%d: Conv 0x%8.8X: ERROR: Unexpected key",
                  threadNo, convptr);
          printf("\nERROR: Unexpected completion key %d", CompletionKey);
          goto EXIT_ReceiveThread;
        }
      }
    }
    else
    {
      /***********************************************************************/
      /* Failure while getting a request from the IOCP                       */
      /***********************************************************************/
      lastError = GetLastError();
      SRTRACE(t,"\nThread%d: Conv 0x%8.8X: ERROR: GQCS failed (%d)",
              threadNo, convptr, lastError);
      printf("\nERROR: GetQueuedCompletionStatus failed (%d)", lastError);
      goto EXIT_ReceiveThread;
    }

  } /* while (TRUE)                                                          */

  /***************************************************************************/
  /* Exit and return - Either we've encountered an error, or the original    */
  /* thread has requested that this thread terminate. This function was      */
  /* called via CreateThread, so this is the end of the thread.              */
  /***************************************************************************/
EXIT_ReceiveThread:

  SRTRACE(t,"\nThread%d: IOCP thread exiting", threadNo);
  return(0);
}


/*****************************************************************************/
/*                                                                           */
/*   IssueFirstVerb                                                          */
/*                                                                           */
/*****************************************************************************/
BOOL IssueFirstVerb(CONVCB* convptr)
{
  HANDLE  AppcHandle;
  BOOL    retcode = TRUE;

  /***************************************************************************/
  /* Initialize the conversation control block                               */
  /***************************************************************************/
  convptr->tp_id[0]     = '\0';
  convptr->conv_id      = 0;
  convptr->deallocated  = FALSE;
  convptr->IOCPInfo.APPC_CompletionPort           = RcvThreadCompletionPort;
  convptr->IOCPInfo.APPC_NumberOfBytesTransferred = 0;
  convptr->IOCPInfo.APPC_CompletionKey            = IOCP_VERB_COMPLETE;
  convptr->IOCPInfo.APPC_pOverlapped              = (LPOVERLAPPED)convptr;

  /***************************************************************************/
  /* Build a RECEIVE_ALLOCATE and issue it using IOCP notification.          */
  /***************************************************************************/
  Build_RECEIVE_ALLOCATE(convptr);
  AppcHandle = WinAsyncAPPCIOCP(&(convptr->IOCPInfo),
                                (long)((char *)&(convptr->vcb)));

  SRTRACE(t,"\nFirstVerb: Conv 0x%8.8X: RCVALLOC issued", convptr);
  SRTRFLUSH();

  if (AppcHandle == NULL)
  {
    SRTRACE(t,"\nFirstVerb: Conv 0x%8.8X: WinAsyncAPPCIOCP failed", convptr);
    retcode = FALSE;
  }

  return(retcode);
}


/*****************************************************************************/
/*                                                                           */
/*   IssueNextVerb - looks at the verb which has just completed and does the */
/*                   next one                                                */
/*                                                                           */
/*****************************************************************************/
BOOL IssueNextVerb(CONVCB * convptr)
{
  BOOL              abendRequired = FALSE;
  BOOL              conversationEnded = FALSE;
  DWORD             lastError;
  HANDLE            AppcHandle;
  struct appc_hdr * vcbptr;
  BOOL              retcode = TRUE;

  vcbptr = (struct appc_hdr *) &convptr->vcb;

  /***************************************************************************/
  /* Process the return codes of the verb which just completed - if we've    */
  /* hit a serious problem, abend the conversation with a TP_ENDED           */
  /***************************************************************************/
  ProcessReturnCodes(convptr, &abendRequired);

  /***************************************************************************/
  /* If we are issue the next verb dependent on the verb that has completed  */
  /***************************************************************************/
  if (!abendRequired)
  {
    switch (vcbptr->opcode)
    {
      /***********************************************************************/
      /* RECEIVE_ALLOCATE: continue with the newly allocated conversation.   */
      /***********************************************************************/
      case AP_RECEIVE_ALLOCATE:
      {
        SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: RCVALLOC completed", convptr);
        Build_MC_RECEIVE_AND_WAIT(convptr);
        break;
      }

      /***********************************************************************/
      /* MC_RECEIVE_AND_WAIT: If the conversation has been deallocated,      */
      /*                      issue a TP_ENDED, otherwise if confirmation    */
      /*                      is requested send it, otherwise issue another  */
      /*                      RECEIVE_AND_WAIT.                              */
      /***********************************************************************/
      case AP_M_RECEIVE_AND_WAIT:
      {
        SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: RCV&WAIT completed (what_rcvd 0x%X, %d bytes)",
                convptr, P_M_RAW(vcbptr)->what_rcvd, P_M_RAW(vcbptr)->dlen);

        /* Use thread safe, atomic add to update global count                */
        InterlockedExchangeAdd(&TotalBytesRcvd, P_M_RAW(vcbptr)->dlen);

        if ((P_M_RAW(vcbptr)->primary_rc == AP_DEALLOC_NORMAL))
        {
          SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: RCV&WAIT got DEALLOC-norm",
                  convptr);
          Build_TP_ENDED(convptr);
        }
        else if ((P_M_RAW(vcbptr)->what_rcvd == AP_CONFIRM_WHAT_RECEIVED) ||
                 (P_M_RAW(vcbptr)->what_rcvd == AP_DATA_COMPLETE_CONFIRM))
        {
          SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: RCV&WAIT got CONFIRM-reqd",
                  convptr);
          Build_MC_CONFIRMED(convptr);
          convptr->deallocated = FALSE;
        }
        else if ((P_M_RAW(vcbptr)->what_rcvd == AP_CONFIRM_DEALLOCATE) ||
                 (P_M_RAW(vcbptr)->what_rcvd ==AP_DATA_COMPLETE_CONFIRM_DEALL))
        {
          SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: RCV&WAIT got DEALLOC-conf",
                  convptr);
          Build_MC_CONFIRMED(convptr);
          convptr->deallocated = TRUE;
        }
        else
        {
          Build_MC_RECEIVE_AND_WAIT(convptr);
        }
        break;
      }

      /***********************************************************************/
      /* AP_M_CONFIRMED: If the conversation has been deallocated, always    */
      /*                 issue a TP_ENDED, otherwise just continue with      */
      /*                 another RECEIVE_AND_WAIT                            */
      /***********************************************************************/
      case AP_M_CONFIRMED:
      {
        SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: CONFIRMED completed",convptr);
        if (convptr->deallocated)
        {
          Build_TP_ENDED(convptr);
        }
        else
        {
          Build_MC_RECEIVE_AND_WAIT(convptr);
        }
        break;
      }

      /***********************************************************************/
      /* AP_TP_ENDED: the conversation has ended                             */
      /***********************************************************************/
      case AP_TP_ENDED:
      {
        SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: TPENDED completed", convptr);
        conversationEnded = TRUE;
        break;
      }

      /***********************************************************************/
      /* DEFAULT: We don't recognise this verb - we'll abend the             */
      /* conversation to be on the safe side.                                */
      /***********************************************************************/
      default:
      {
        abendRequired = TRUE;
        SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: ERROR: Bad Verb (0x%8.8X)",
                convptr, vcbptr->opcode);
        printf("\nERROR: Unknown Verb received, opcode 0x%8.8X",
               vcbptr->opcode);
        break;
      }
    }

    SRTRFLUSH();
  }

  /***************************************************************************/
  /* If we need to Abend the conversation, issue a TP_ENDED                  */
  /***************************************************************************/
  if (abendRequired)
  {
    SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: Abend required",convptr);
    Build_TP_ENDED(convptr);
  }

  /***************************************************************************/
  /* If we're finished then post to the completion port to do cleanup and    */
  /* kick off a new conversation.                                            */
  /***************************************************************************/
  if (conversationEnded)
  {
    SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: conversation ended", convptr);
    if (!PostQueuedCompletionStatus(RcvThreadCompletionPort,
                                    0,
                                    IOCP_END_CONVERSATION,
                                    (LPOVERLAPPED)convptr))
    {
      lastError = GetLastError();

      SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: ERROR: PQCS failed (%d)",
              convptr, lastError);
      printf("\nERROR:PostQueueCompletionStatus failed (%d)", lastError);
    }
  }
  /***************************************************************************/
  /* Else go ahead and issue the next verb.                                  */
  /***************************************************************************/
  else
  {
    SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: WinAsyncAPPCIOCP (verb 0x%8.8X)",
            vcbptr->opcode, convptr);
    AppcHandle = WinAsyncAPPCIOCP(&(convptr->IOCPInfo), (long)(char *)vcbptr);
    SRTRFLUSH();

    if (AppcHandle == NULL)
    {
      SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: WinAsyncAPPCIOCP failed",
              convptr, vcbptr->opcode);

      if (!PostQueuedCompletionStatus(RcvThreadCompletionPort,
                                      0,
                                      IOCP_END_CONVERSATION,
                                      (LPOVERLAPPED)convptr))
      {
        lastError = GetLastError();

        SRTRACE(t,"\nNextVerb: Conv 0x%8.8X: ERROR: PQCS failed (%d)",
                convptr, lastError);
        printf("\nERROR:PostQueueCompletionStatus failed (%d)", lastError);
        retcode = FALSE;
      }
    }
  }

  SRTRFLUSH();
  return(retcode);
}


/*****************************************************************************/
/*                                                                           */
/*   ProcessReturnCodes - Checks return codes from the last verb to complete */
/*                        and saves conversation id and tp id in the         */
/*                        conversation cb. If there is a serious error set   */
/*                        the supplied abendRequired parameter to TRUE.      */
/*                                                                           */
/*****************************************************************************/
void ProcessReturnCodes(CONVCB* convptr, BOOL* pAbendRequired)
{
  struct appc_hdr* vcbptr;

  *pAbendRequired = FALSE;
  vcbptr = (struct appc_hdr *) &(convptr->vcb);
  SRTRACE(t,"\nRetCodes: Conv 0x%8.8X: verb 0x%8.8X, prc %4.4x src %8.8x",
          convptr,
          vcbptr->opcode,
          APPC_FLIPI(vcbptr->primary_rc),
          APPC_FLIPL(vcbptr->secondary_rc));

  /***************************************************************************/
  /* MC_RECEIVE_AND_WAIT is allowed to fail with DEALLOC_NORMAL              */
  /***************************************************************************/
  if ((vcbptr->opcode == AP_M_RECEIVE_AND_WAIT) &&
      (vcbptr->primary_rc == AP_DEALLOC_NORMAL))
  {
    SRTRACE(t,"\nRetCodes: Conv 0x%8.8X: RCV&WAIT completed (DEALLOC_NORMAL)",
            convptr);
  }
  /***************************************************************************/
  /* MC_CONFIRM is allowed to fail with ALLOCATION_ERROR                     */
  /***************************************************************************/
  else if ((vcbptr->opcode == AP_M_CONFIRM) &&
           (vcbptr->primary_rc == AP_ALLOCATION_ERROR))
  {
    SRTRACE(t,"\nRetCodes: Conv 0x%8.8X: CONFIRM completed (ALLOC_ERROR)",
            convptr);
  }
  /***************************************************************************/
  /* Any other failure is serious                                            */
  /***************************************************************************/
  else if (vcbptr->primary_rc != AP_OK)
  {
    SRTRACE(t,"\nRetCodes: Conv 0x%8.8X: Unexpected Error - request TP_ENDED",
            convptr);
    *pAbendRequired = TRUE;
  }
  /***************************************************************************/
  /* If this is a RECEIVE_ALLOCATE successfully completing, we need to       */
  /* record the tp_id and conv_id for subsequent verbs to use                */
  /***************************************************************************/
  else if (vcbptr->opcode == AP_RECEIVE_ALLOCATE)
  {
    SRTRACE(t,"\nRetCodes: Conv 0x%8.8X: RCVALLOC - record tp_id/conv_id");
    memcpy(convptr->tp_id,&(P_RAL(vcbptr)->tp_id),8);
    convptr->conv_id = P_RAL(vcbptr)->conv_id;
  }

  SRTRFLUSH();
}


/*****************************************************************************/
/*                                                                           */
/*   Build_RECEIVE_ALLOCATE                                                  */
/*                                                                           */
/*****************************************************************************/
void Build_RECEIVE_ALLOCATE(CONVCB * convptr)
{
  RECEIVE_ALLOCATE * vcbptr;
  SRTRACE(t,"\nBuild RCVALLOC: Conv 0x%8.8X", convptr);

  vcbptr = (RECEIVE_ALLOCATE *) &(convptr->vcb);
  memset(vcbptr,0,sizeof(VCB));
  vcbptr->opcode = AP_RECEIVE_ALLOCATE;
  memcpy(vcbptr->tp_name, TPName, 64);
}


/*****************************************************************************/
/*                                                                           */
/*   Build_TP_ENDED                                                          */
/*                                                                           */
/*****************************************************************************/
void Build_TP_ENDED(CONVCB * convptr)
{
  TP_ENDED * vcbptr;
  SRTRACE(t,"\nBuild TPENDED: Conv 0x%8.8X", convptr);

  vcbptr = (TP_ENDED *) &(convptr->vcb);
  memset(vcbptr,0,sizeof(VCB));
  vcbptr->opcode = AP_TP_ENDED;
  memcpy(&(vcbptr->tp_id), convptr->tp_id, 8);
  vcbptr->type = AP_SOFT;
}


/*****************************************************************************/
/*                                                                           */
/*   Build_MC_CONFIRMED                                                      */
/*                                                                           */
/*****************************************************************************/
void Build_MC_CONFIRMED(CONVCB * convptr)
{
  MC_CONFIRMED * vcbptr;
  SRTRACE(t,"\nBuild CONFIRMED: Conv 0x%8.8X", convptr);

  vcbptr = (MC_CONFIRMED *) &(convptr->vcb);
  memset(vcbptr,0,sizeof(VCB));
  vcbptr->opcode = AP_M_CONFIRMED;
  vcbptr->opext = AP_MAPPED_CONVERSATION;
  memcpy(&(vcbptr->tp_id),convptr->tp_id, 8);
  vcbptr->conv_id = convptr->conv_id;
}


/*****************************************************************************/
/*                                                                           */
/*   Build_MC_RECEIVE_AND_WAIT                                               */
/*                                                                           */
/*****************************************************************************/
void Build_MC_RECEIVE_AND_WAIT(CONVCB * convptr)
{
  MC_RECEIVE_AND_WAIT * vcbptr;
  SRTRACE(t,"\nBuild RCV&WAIT: Conv 0x%8.8X", convptr);

  vcbptr = (MC_RECEIVE_AND_WAIT *) &(convptr->vcb);
  memset(vcbptr,0,sizeof(VCB));
  vcbptr->opcode = AP_M_RECEIVE_AND_WAIT;
  vcbptr->opext = AP_MAPPED_CONVERSATION;
  memcpy(&(vcbptr->tp_id),convptr->tp_id, 8);
  vcbptr->conv_id = convptr->conv_id;
  vcbptr->rtn_status = AP_YES;
  vcbptr->max_len = RcvSize;
  vcbptr->dptr = convptr->dataPtr;
}


/*****************************************************************************/
/*                                                                           */
/*   CONV_A_TO_E - ASCII to EBCDIC conversion routine                        */
/*                                                                           */
/*****************************************************************************/
void CONV_A_TO_E(char * string, unsigned short length)
{
  SRTRACE(t,"\nCONV_A_TO_E: string at 0x%8.8X, length %d", string, length);
  memset((char *)&cnvt,0,sizeof(cnvt));

  cnvt.opcode       = SV_CONVERT;
  cnvt.direction    = SV_ASCII_TO_EBCDIC;
  cnvt.char_set     = SV_AE;

  cnvt.len          = length;
  cnvt.source       = string;
  cnvt.target       = string;

  ACSSVC_C((long)((char *)&cnvt));
}

