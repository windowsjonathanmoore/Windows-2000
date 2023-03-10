/*****************************************************************************/
/*                                                                           */
/* mrcvio.h - /*  Copyright (c) Microsoft Corporation.  All rights reserved. */
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
/* Standard Macro                                                            */
/*****************************************************************************/
#define STRMATCH(x,y)      !strncmp(x,y, strlen(y))

/*****************************************************************************/
/* Internal Tracing                                                          */
/*****************************************************************************/
BOOL internalTracing;
FILE *t = NULL;

#define SRTROPEN(X) if (internalTracing) {t = fopen(X,"w");}
#define SRTRFLUSH() if (internalTracing) {fflush(t);}
#define SRTRCLOSE() if (internalTracing) {fclose(t);}
#define SRTRACE     (internalTracing == FALSE) ? (void) 0 : fprintf

/*****************************************************************************/
/* User and SNA Configuration Global variables                               */
/*****************************************************************************/
int NumRcvThreads;
int NumRcvConvs;
int Duration;
unsigned short RcvSize;
char TPName[64];
char IntTraceFile[255];

char LocalLUAlias[8];
char RemoteLUAlias[8];
char ModeName[8];

unsigned long TotalBytesRcvd;

/*****************************************************************************/
/* IOCP: Global Completion Port and Completion keys                          */
/*****************************************************************************/
HANDLE RcvThreadCompletionPort;
#define MAX_IOCP_THREADS 32

#define IOCP_START_CONVERSATION 1
#define IOCP_VERB_COMPLETE      2
#define IOCP_END_CONVERSATION   3
#define IOCP_TERMINATE_THREAD   4

/*****************************************************************************/
/* APPC verb control block and macros for manipulation of vcb, and structure */
/* for doing ASCII<-->EBCDIC conversion                                      */
/*****************************************************************************/
#define WinAPPCVERSION  0x0001

#define P_TPE(X)    ((struct tp_ended *)X)
#define P_RAL(X)    ((struct receive_allocate *)X)
#define P_M_CFD(X)  ((struct mc_confirmed *)X)
#define P_M_DAL(X)  ((struct mc_deallocate *)X)
#define P_M_RAW(X)  ((struct mc_receive_and_wait *)X)

typedef struct vcb
{
  union
  {
    struct appc_hdr             hdr;
    struct receive_allocate     rcvalloc;
    struct tp_ended             tpend;
    struct mc_confirmed         confirmed;
    struct mc_deallocate        deallocate;
    struct mc_receive_and_wait  rcvwait;

  } U_VCB;

} VCB;

struct convert cnvt;

/*****************************************************************************/
/* conversation control block - one per conversation                         */
/*****************************************************************************/
typedef struct convcb
{
  char           tp_id[8];
  unsigned long  conv_id;
  char *         dataPtr;
  BOOL           deallocated;
  APPC_IOCP_INFO IOCPInfo;
  VCB            vcb;

} CONVCB;

/*****************************************************************************/
/* Function Prototypes                                                       */
/*****************************************************************************/
int __cdecl main (int, char **);
DWORD WINAPI ReceiveThread(DWORD);
BOOL IssueFirstVerb(CONVCB*);
BOOL IssueNextVerb(CONVCB*);
void ProcessReturnCodes(CONVCB*, BOOL*);
void Build_RECEIVE_ALLOCATE(CONVCB*);
void Build_TP_ENDED(CONVCB*);
void Build_MC_CONFIRMED(CONVCB*);
void Build_MC_RECEIVE_AND_WAIT(CONVCB*);
void CONV_A_TO_E(char*, unsigned short);

