;****************************************************************************
;                                                                           *
; THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY     *
; KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE       *
; IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR     *
; PURPOSE.                                                                  *
;                                                                           *
; Copyright (C) 1993-95  Microsoft Corporation.  All Rights Reserved.       *
;                                                                           *
;****************************************************************************

NO_ERROR                        EQU    0 
ERROR_INVALID_FUNCTION          EQU    1 
ERROR_FILE_NOT_FOUND            EQU    2 
ERROR_PATH_NOT_FOUND            EQU    3 
ERROR_TOO_MANY_OPEN_FILES       EQU    4 
ERROR_ACCESS_DENIED             EQU    5 
ERROR_INVALID_HANDLE            EQU    6 
ERROR_ARENA_TRASHED             EQU    7 
ERROR_NOT_ENOUGH_MEMORY         EQU    8 
ERROR_INVALID_BLOCK             EQU    9 
ERROR_BAD_ENVIRONMENT           EQU    10 
ERROR_BAD_FORMAT                EQU    11 
ERROR_INVALID_ACCESS            EQU    12 
ERROR_INVALID_DATA              EQU    13 
ERROR_INVALID_DRIVE             EQU    15 
ERROR_CURRENT_DIRECTORY         EQU    16 
ERROR_NOT_SAME_DEVICE           EQU    17 
ERROR_NO_MORE_FILES             EQU    18 
ERROR_WRITE_PROTECT             EQU    19 
ERROR_BAD_UNIT                  EQU    20 
ERROR_NOT_READY                 EQU    21 
ERROR_BAD_COMMAND               EQU    22 
ERROR_CRC                       EQU    23 
ERROR_BAD_LENGTH                EQU    24 
ERROR_SEEK                      EQU    25 
ERROR_NOT_DOS_DISK              EQU    26 
ERROR_SECTOR_NOT_FOUND          EQU    27 
ERROR_OUT_OF_PAPER              EQU    28 
ERROR_WRITE_FAULT               EQU    29 
ERROR_READ_FAULT                EQU    30 
ERROR_GEN_FAILURE               EQU    31 
ERROR_SHARING_VIOLATION         EQU    32 
ERROR_LOCK_VIOLATION            EQU    33 
ERROR_WRONG_DISK                EQU    34 
ERROR_FCB_UNAVAILABLE           EQU    35 
ERROR_SHARING_BUFFER_EXCEEDED   EQU    36 
ERROR_VOLUME_LOCKED             EQU    40
ERROR_NOT_SUPPORTED             EQU    50 
ERROR_REM_NOT_LIST              EQU    51       
ERROR_DUP_NAME                  EQU    52       
ERROR_BAD_NETPATH               EQU    53       
ERROR_NETWORK_BUSY              EQU    54       
ERROR_DEV_NOT_EXIST             EQU    55       
ERROR_TOO_MANY_CMDS             EQU    56       
ERROR_ADAP_HDW_ERR              EQU    57       
ERROR_BAD_NET_RESP              EQU    58       
ERROR_UNEXP_NET_ERR             EQU    59       
ERROR_BAD_REM_ADAP              EQU    60       
ERROR_PRINTQ_FULL               EQU    61       
ERROR_NO_SPOOL_SPACE            EQU    62       
ERROR_PRINT_CANCELLED           EQU    63       
ERROR_NETNAME_DELETED           EQU    64       
ERROR_NETWORK_ACCESS_DENIED     EQU    65       
ERROR_BAD_DEV_TYPE              EQU    66       
ERROR_BAD_NET_NAME              EQU    67       
ERROR_TOO_MANY_NAMES            EQU    68       
ERROR_TOO_MANY_SESS             EQU    69       
ERROR_SHARING_PAUSED            EQU    70       
ERROR_REQ_NOT_ACCEP             EQU    71       
ERROR_REDIR_PAUSED              EQU    72       
ERROR_FILE_EXISTS               EQU    80 
ERROR_DUP_FCB                   EQU    81         
ERROR_CANNOT_MAKE               EQU    82 
ERROR_FAIL_I24                  EQU    83 
ERROR_OUT_OF_STRUCTURES         EQU    84 
ERROR_ALREADY_ASSIGNED          EQU    85 
ERROR_INVALID_PASSWORD          EQU    86 
ERROR_INVALID_PARAMETER         EQU    87 
ERROR_NET_WRITE_FAULT           EQU    88 
ERROR_NO_PROC_SLOTS             EQU    89         
ERROR_NOT_FROZEN                EQU    90 
ERR_TSTOVFL                     EQU    91         
ERR_TSTDUP                      EQU    92         
ERROR_NO_ITEMS                  EQU    93         
ERROR_INTERRUPT                 EQU    95         
ERROR_DEVICE_IN_USE             EQU    99         
ERROR_TOO_MANY_SEMAPHORES       EQU    100 
ERROR_EXCL_SEM_ALREADY_OWNED    EQU    101 
ERROR_SEM_IS_SET                EQU    102 
ERROR_TOO_MANY_SEM_REQUESTS     EQU    103 
ERROR_INVALID_AT_INTERRUPT_TIME EQU    104 
ERROR_SEM_OWNER_DIED            EQU    105        
ERROR_SEM_USER_LIMIT            EQU    106        
ERROR_DISK_CHANGE               EQU    107        
ERROR_DRIVE_LOCKED              EQU    108        
ERROR_BROKEN_PIPE               EQU    109        
ERROR_OPEN_FAILED               EQU    110        
ERROR_BUFFER_OVERFLOW           EQU    111        
ERROR_DISK_FULL                 EQU    112        
ERROR_NO_MORE_SEARCH_HANDLES    EQU    113        
ERROR_INVALID_TARGET_HANDLE     EQU    114        
ERROR_PROTECTION_VIOLATION      EQU    115        
ERROR_VIOKBD_REQUEST            EQU    116 
ERROR_INVALID_CATEGORY          EQU    117        
ERROR_INVALID_VERIFY_SWITCH     EQU    118        
ERROR_BAD_DRIVER_LEVEL          EQU    119        
ERROR_CALL_NOT_IMPLEMENTED      EQU    120        
ERROR_SEM_TIMEOUT               EQU    121        
ERROR_INSUFFICIENT_BUFFER       EQU    122        
ERROR_INVALID_NAME              EQU    123        
ERROR_INVALID_LEVEL             EQU    124        
ERROR_NO_VOLUME_LABEL           EQU    125        
ERROR_MOD_NOT_FOUND             EQU    126        
ERROR_PROC_NOT_FOUND            EQU    127        
ERROR_WAIT_NO_CHILDREN          EQU    128        
ERROR_CHILD_NOT_COMPLETE        EQU    129        
ERROR_DIRECT_ACCESS_HANDLE      EQU    130        
ERROR_NEGATIVE_SEEK             EQU    131        
ERROR_SEEK_ON_DEVICE            EQU    132        
ERROR_IS_JOIN_TARGET            EQU    133 
ERROR_IS_JOINED                 EQU    134 
ERROR_IS_SUBSTED                EQU    135 
ERROR_NOT_JOINED                EQU    136 
ERROR_NOT_SUBSTED               EQU    137 
ERROR_JOIN_TO_JOIN              EQU    138 
ERROR_SUBST_TO_SUBST            EQU    139 
ERROR_JOIN_TO_SUBST             EQU    140 
ERROR_SUBST_TO_JOIN             EQU    141 
ERROR_BUSY_DRIVE                EQU    142 
ERROR_SAME_DRIVE                EQU    143 
ERROR_DIR_NOT_ROOT              EQU    144 
ERROR_DIR_NOT_EMPTY             EQU    145 
ERROR_IS_SUBST_PATH             EQU    146 
ERROR_IS_JOIN_PATH              EQU    147 
ERROR_PATH_BUSY                 EQU    148 
ERROR_IS_SUBST_TARGET           EQU    149 
ERROR_SYSTEM_TRACE              EQU    150      
ERROR_INVALID_EVENT_COUNT       EQU    151      
ERROR_TOO_MANY_MUXWAITERS       EQU    152 
ERROR_INVALID_LIST_FORMAT       EQU    153 
ERROR_LABEL_TOO_LONG            EQU    154 
ERROR_TOO_MANY_TCBS             EQU    155 
ERROR_SIGNAL_REFUSED            EQU    156 
ERROR_DISCARDED                 EQU    157 
ERROR_NOT_LOCKED                EQU    158 
ERROR_BAD_THREADID_ADDR         EQU    159 
ERROR_BAD_ARGUMENTS             EQU    160 
ERROR_BAD_PATHNAME              EQU    161 
ERROR_SIGNAL_PENDING            EQU    162 
ERROR_UNCERTAIN_MEDIA           EQU    163 
ERROR_MAX_THRDS_REACHED         EQU    164 
ERROR_MONITORS_NOT_SUPPORTED    EQU    165 
ERROR_UNC_DRIVER_NOT_INSTALLED  EQU    166 
ERROR_LOCK_FAILED               EQU    167 
ERROR_SWAPIO_FAILED             EQU    168 
ERROR_SWAPIN_FAILED             EQU    169 
ERROR_BUSY                      EQU    170 
ERROR_INVALID_SEGMENT_NUMBER    EQU    180 
ERROR_INVALID_CALLGATE          EQU    181 
ERROR_INVALID_ORDINAL           EQU    182 
ERROR_ALREADY_EXISTS            EQU    183 
ERROR_NO_CHILD_PROCESS          EQU    184 
ERROR_CHILD_ALIVE_NOWAIT        EQU    185 
ERROR_INVALID_FLAG_NUMBER       EQU    186 
ERROR_SEM_NOT_FOUND             EQU    187 
ERROR_INVALID_STARTING_CODESEG  EQU    188 
ERROR_INVALID_STACKSEG          EQU    189 
ERROR_INVALID_MODULETYPE        EQU    190 
ERROR_INVALID_EXE_SIGNATURE     EQU    191 
ERROR_EXE_MARKED_INVALID        EQU    192 
ERROR_BAD_EXE_FORMAT            EQU    193 
ERROR_ITERATED_DATA_EXCEEDS_64k EQU    194 
ERROR_INVALID_MINALLOCSIZE      EQU    195 
ERROR_DYNLINK_FROM_INVALID_RING EQU    196 
ERROR_IOPL_NOT_ENABLED          EQU    197 
ERROR_INVALID_SEGDPL            EQU    198 
ERROR_AUTODATASEG_EXCEEDS_64k   EQU    199 
ERROR_RING2SEG_MUST_BE_MOVABLE  EQU    200 
ERROR_RELOC_CHAIN_XEEDS_SEGLIM  EQU    201 
ERROR_INFLOOP_IN_RELOC_CHAIN    EQU    202 
ERROR_ENVVAR_NOT_FOUND          EQU    203 
ERROR_NOT_CURRENT_CTRY          EQU    204 
ERROR_NO_SIGNAL_SENT            EQU    205 
ERROR_FILENAME_EXCED_RANGE      EQU    206      
ERROR_RING2_STACK_IN_USE        EQU    207      
ERROR_META_EXPANSION_TOO_LONG   EQU    208      
ERROR_INVALID_SIGNAL_NUMBER     EQU    209 
ERROR_THREAD_1_INACTIVE         EQU    210 
ERROR_INFO_NOT_AVAIL            EQU    211  
ERROR_LOCKED                    EQU    212 
ERROR_BAD_DYNALINK              EQU    213  
ERROR_TOO_MANY_MODULES          EQU    214 
ERROR_NESTING_NOT_ALLOWED       EQU    215 
ERROR_CANNOT_SHRINK             EQU    216  
ERROR_ZOMBIE_PROCESS            EQU    217 
ERROR_STACK_IN_HIGH_MEMORY      EQU    218 
ERROR_INVALID_EXITROUTINE_RING  EQU    219  
ERROR_GETBUF_FAILED             EQU    220 
ERROR_FLUSHBUF_FAILED           EQU    221 
ERROR_TRANSFER_TOO_LONG         EQU    222 
ERROR_NO_CHILDREN               EQU    228 
ERROR_INVALID_SCREEN_GROUP      EQU    229 
ERROR_BAD_PIPE                  EQU    230  
ERROR_PIPE_BUSY                 EQU    231  
ERROR_NO_DATA                   EQU    232  
ERROR_PIPE_NOT_CONNECTED        EQU    233  
ERROR_MORE_DATA                 EQU    234  
ERROR_VC_DISCONNECTED           EQU    240      
ERROR_CIRCULARITY_REQUESTED     EQU    250  
ERROR_DIRECTORY_IN_CDS          EQU    251  
ERROR_INVALID_FSD_NAME          EQU    252  
ERROR_INVALID_PATH              EQU    253  
ERROR_INVALID_EA_NAME           EQU    254  
ERROR_EA_LIST_INCONSISTENT      EQU    255  
ERROR_EA_LIST_TOO_LONG          EQU    256  
ERROR_NO_META_MATCH             EQU    257  
ERROR_FINDNOTIFY_TIMEOUT        EQU    258  
ERROR_NO_MORE_ITEMS             EQU    259  
ERROR_SEARCH_STRUC_REUSED       EQU    260  
ERROR_CHAR_NOT_FOUND            EQU    261  
ERROR_TOO_MUCH_STACK            EQU    262  
ERROR_INVALID_ATTR              EQU    263  
ERROR_INVALID_STARTING_RING     EQU    264  
ERROR_INVALID_DLL_INIT_RING     EQU    265  
ERROR_CANNOT_COPY               EQU    266  
ERROR_DIRECTORY                 EQU    267  
ERROR_OPLOCKED_FILE             EQU    268  
ERROR_OPLOCK_THREAD_EXISTS      EQU    269  
ERROR_VOLUME_CHANGED            EQU    270 
ERROR_FINDNOTIFY_HANDLE_IN_USE  EQU    271 
ERROR_FINDNOTIFY_HANDLE_CLOSED  EQU    272 
ERROR_NOTIFY_OBJECT_REMOVED     EQU    273 
ERROR_ALREADY_SHUTDOWN          EQU    274 
ERROR_EAS_DIDNT_FIT             EQU    275 
ERROR_EA_FILE_CORRUPT           EQU    276 
ERROR_EA_TABLE_FULL             EQU    277 
ERROR_INVALID_EA_HANDLE         EQU    278 
ERROR_NO_CLUSTER                EQU    279 
ERROR_CREATE_EA_FILE            EQU    280 
ERROR_CANNOT_OPEN_FILE          EQU    281 
ERROR_EAS_NOT_SUPPORTED         EQU    282 
ERROR_NEED_EAS_FOUND            EQU    283 
ERROR_VOLUME_EXISTS             EQU    284
ERROR_USER_DEFINED_BASE         EQU    0FF00H 
ERROR_I24_WRITE_PROTECT         EQU    0 
ERROR_I24_BAD_UNIT              EQU    1 
ERROR_I24_NOT_READY             EQU    2 
ERROR_I24_BAD_COMMAND           EQU    3 
ERROR_I24_CRC                   EQU    4 
ERROR_I24_BAD_LENGTH            EQU    5 
ERROR_I24_SEEK                  EQU    6 
ERROR_I24_NOT_DOS_DISK          EQU    7 
ERROR_I24_SECTOR_NOT_FOUND      EQU    8 
ERROR_I24_OUT_OF_PAPER          EQU    9 
ERROR_I24_WRITE_FAULT           EQU    0AH 
ERROR_I24_READ_FAULT            EQU    0BH 
ERROR_I24_GEN_FAILURE           EQU    0CH 
ERROR_I24_DISK_CHANGE           EQU    0DH 
ERROR_I24_WRONG_DISK            EQU    0FH 
ERROR_I24_UNCERTAIN_MEDIA       EQU    10H 
ERROR_I24_CHAR_CALL_INTERRUPTED EQU    11H 
ERROR_I24_NO_MONITOR_SUPPORT    EQU    12H 
ERROR_I24_INVALID_PARAMETER     EQU    13H 
ERROR_I24_DEVICE_IN_USE         EQU    14H 
ALLOWED_FAIL                    EQU    0001H 
ALLOWED_ABORT                   EQU    0002H 
ALLOWED_RETRY                   EQU    0004H 
ALLOWED_IGNORE                  EQU    0008H 
ALLOWED_ACKNOWLEDGE             EQU    0010H 
ALLOWED_DETACHED                EQU    8000H 
I24_OPERATION                   EQU    1H 
I24_AREA                        EQU    6H 
I24_CLASS                       EQU    80H 
ERRCLASS_OUTRES                 EQU    1          
ERRCLASS_TEMPSIT                EQU    2          
ERRCLASS_AUTH                   EQU    3          
ERRCLASS_INTRN                  EQU    4          
ERRCLASS_HRDFAIL                EQU    5          
ERRCLASS_SYSFAIL                EQU    6          
ERRCLASS_APPERR                 EQU    7          
ERRCLASS_NOTFND                 EQU    8          
ERRCLASS_BADFMT                 EQU    9          
ERRCLASS_LOCKED                 EQU    10         
ERRCLASS_MEDIA                  EQU    11         
ERRCLASS_ALREADY                EQU    12         
ERRCLASS_UNK                    EQU    13         
ERRCLASS_CANT                   EQU    14 
ERRCLASS_TIME                   EQU    15 
ERRACT_RETRY                    EQU    1          
ERRACT_DLYRET                   EQU    2          
ERRACT_USER                     EQU    3          
ERRACT_ABORT                    EQU    4          
ERRACT_PANIC                    EQU    5          
ERRACT_IGNORE                   EQU    6          
ERRACT_INTRET                   EQU    7          
ERRLOC_UNK                      EQU    1          
ERRLOC_DISK                     EQU    2          
ERRLOC_NET                      EQU    3          
ERRLOC_SERDEV                   EQU    4          
ERRLOC_MEM                      EQU    5          
TC_NORMAL                       EQU    0 
TC_HARDERR                      EQU    1 
TC_GP_TRAP                      EQU    2 
TC_SIGNAL                       EQU    3 
