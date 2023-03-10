/*
 * NOTE: The Microsoft Host Integration Server 2000 AFTP services use a buffer
 *       size defined in an earlier version of AFTP. You *must* use this header
 *       file to ensure compatibility. The aftpapi.h file #included below defines
 *       the current AFTP version. The constants specific to the Microsoft implementation
 *       are redefined to appropriate values in this file.
 * Copyright (c) Microsoft Corporation.  All rights reserved.
 */

#include aftpapi.h

/*
 * The appropriate system value must be defined for your platform.
 * The following system values are supported:
 *     CM_OS2
 *     CM_DOS
 *     CM_AIX
 *     CM_MVS
 *     CM_VM
 *     CM_OS400
 *     CM_WINNT                                                          *W32*
 *
 * This is necessary for the proper setting of
 * AFTP_ENTRY and AFTP_PTR below.
 */

#if defined (CM_WINNT)                                                  /*W32*/
                                                                        /*W32*/
#define WINSNA                                                          /*W32*/
#define AFTP_ENTRY extern void WINAPI                                   /*W32*/
#define AFTP_PTR *                                                      /*W32*/

#endif

/**********************************************************************
 * AFTP Type Definitions
 **********************************************************************/
#undef AFTP_DATA_TYPE_TYPE
#if defined (CM_WINNT)                                                  /*W32*/
typedef signed long AFTP_DATA_TYPE_TYPE;                                /*W32*/
#else                                                                   /*W32*/
typedef unsigned long AFTP_DATA_TYPE_TYPE;
#endif

#define AFTP_DEFAULT_DATA_TYPE   ((AFTP_DATA_TYPE_TYPE)3)               /*W32*/

#undef AFTP_FILE_NAME_SIZE
#undef AFTP_FQLU_NAME_SIZE
#undef AFTP_MODE_NAME_SIZE
#undef AFTP_PASSWORD_SIZE
#undef AFTP_TP_NAME_SIZE
#undef AFTP_USERID_SIZE
#undef AFTP_MESSAGE_SIZE
#undef AFTP_DATA_TYPE_SIZE
#undef AFTP_DATE_MODE_SIZE
#undef AFTP_RECORD_FORMAT_SIZE
#undef AFTP_WRITE_MODE_SIZE
#undef AFTP_INI_MESSAGE_SIZE
#undef AFTP_SYSTEM_INFO_SIZE


#define AFTP_FILE_NAME_SIZE     ((AFTP_LENGTH_TYPE)512)
#define AFTP_FQLU_NAME_SIZE     ((AFTP_LENGTH_TYPE)64)
#define AFTP_MODE_NAME_SIZE     ((AFTP_LENGTH_TYPE)8)
#define AFTP_PASSWORD_SIZE      ((AFTP_LENGTH_TYPE)10)
#define AFTP_TP_NAME_SIZE       ((AFTP_LENGTH_TYPE)64)
#define AFTP_USERID_SIZE        ((AFTP_LENGTH_TYPE)10)
#define AFTP_MESSAGE_SIZE       ((AFTP_LENGTH_TYPE)2048)
#define AFTP_DATA_TYPE_SIZE     ((AFTP_LENGTH_TYPE)64)
#define AFTP_DATE_MODE_SIZE     ((AFTP_LENGTH_TYPE)64)
#define AFTP_RECORD_FORMAT_SIZE ((AFTP_LENGTH_TYPE)64)
#define AFTP_WRITE_MODE_SIZE    ((AFTP_LENGTH_TYPE)64)
#define AFTP_INI_MESSAGE_SIZE   ((AFTP_LENGTH_TYPE)1024)
#define AFTP_SYSTEM_INFO_SIZE   ((AFTP_LENGTH_TYPE)512)
