/*==========================================================================;
 *
 *  mmddk.h -- Include file for Multimedia Device Development
 *
 *  Version 4.00
 *
 *  Copyright (C) 1992-1995 Microsoft Corporation.  All rights reserved.
 *
 *--------------------------------------------------------------------------;
 *  Note: You must include the WINDOWS.H and MMSYSTEM.H header files
 *        before including this file.
 *
 *  Define:         Prevent inclusion of:
 *  --------------  --------------------------------------------------------
 *  MMNOMIDIDEV     MIDI support
 *  MMNOWAVEDEV     Waveform support
 *  MMNOAUXDEV      Auxiliary output support
 *  MMNOMIXERDEV    Mixer support
 *  MMNOTIMERDEV    Timer support
 *  MMNOJOYDEV      Joystick support
 *  MMNOMCIDEV      MCI support
 *  MMNOTASKDEV     Task support
 *
 *==========================================================================;
 */

/*XLATOFF*/							/* ;Internal*/
#if 0								/* ;BeginInternal*/
/* Used to create the INC version of the struct */
/*XLATON*/
typedef struct OFFSEL {
	WORD	Off;
	WORD	Sel;
} OFFSEL;
typedef struct LOHI {
	WORD	Lo;
	WORD	Hi;
} LOHI;
/*XLATOFF*/
#endif								/* ;EndInternal*/


#ifndef _INC_MMDDK
#define _INC_MMDDK   /* #defined if mmddk.h has been included */

#ifndef RC_INVOKED
#pragma pack(1)         /* Assume byte packing throughout */
#endif

#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif  /* __cplusplus */

/***************************************************************************

                       Helper functions for drivers

***************************************************************************/

#ifdef _WIN32

#ifndef NODRIVERS
#define DRV_LOAD                0x0001
#define DRV_ENABLE              0x0002
#define DRV_OPEN                0x0003
#define DRV_CLOSE               0x0004
#define DRV_DISABLE             0x0005
#define DRV_FREE                0x0006
#define DRV_CONFIGURE           0x0007
#define DRV_QUERYCONFIGURE      0x0008
#define DRV_INSTALL             0x0009
#define DRV_REMOVE              0x000A

#define DRV_RESERVED            0x0800
#define DRV_USER                0x4000

#define DRIVERS_SECTION  TEXT("DRIVERS32")     // Section name for installed drivers
#define MCI_SECTION      TEXT("MCI32")         // Section name for installed MCI drivers

#ifndef _WIN32_VXD
WINMMAPI LRESULT   WINAPI DefDriverProc(DWORD dwDriverIdentifier, HDRVR hdrvr, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
#endif
#endif /* !NODRIVERS */

#endif /* ifdef _WIN32 */

#if (WINVER < 0x0400)
#define DCB_NOSWITCH   0x0008           /* obsolete switch */
#endif
/*XLATON*/							/* ;Internal*/
#define DCB_TYPEMASK   0x0007           /* callback type mask */
#define DCB_NULL       0x0000           /* unknown callback type */

/* flags for wFlags parameter of DriverCallback() */
#define DCB_WINDOW     0x0001           /* dwCallback is a HWND */
#define DCB_TASK       0x0002           /* dwCallback is a HTASK */
#define DCB_FUNCTION   0x0003           /* dwCallback is a FARPROC */
#define DCB_THUNK      0x0004           /* dwCallback is a 16->32 thunk */ /* ;Internal */
#define DCB_EVENT      0x0005           /* dwCallback is an EVENT */
#define DCB_EVENT16    0x0006           /* dwCallback is an EVENT under Win16 */ /* ;Internal */

/*XLATOFF*/							/* ;Internal*/
#ifndef _WIN32_VXD
WINMMAPI BOOL WINAPI DriverCallback(DWORD dwCallback, UINT uFlags,
    HANDLE hDevice, UINT uMessage, DWORD dwUser, DWORD dwParam1, DWORD dwParam2);
#endif

#if (WINVER < 0x0400)
void WINAPI StackEnter(void);
void WINAPI StackLeave(void);
#endif

/* generic prototype for audio device driver entry-point functions */
/* midMessage(), modMessage(), widMessage(), wodMessage(), auxMessage() */
#ifndef _WIN32_VXD
typedef DWORD (CALLBACK SOUNDDEVMSGPROC)(UINT uDeviceID, UINT uMessage,
    DWORD dwInstance, DWORD dwParam1, DWORD dwParam2);
typedef SOUNDDEVMSGPROC FAR *LPSOUNDDEVMSGPROC;
#endif

/* 
 * Message sent by mmsystem to media specific entry points when it first
 * initializes the drivers, and when they are closed.
 */

/*XLATON*/							/* ;Internal*/
#define DRVM_INIT               0x64
#define DRVM_EXIT		0x65
/*XLATOFF*/							/* ;Internal*/

#if (WINVER >= 0x0400)

#define	DRVM_DISABLE		0x66
#define	DRVM_ENABLE		0x67

// messages that have IOCTL format
//    dw1 = NULL or handle
//    dw2 = NULL or ptr to DRVM_IOCTL_DATA
//    return is MMRESULT
//
#define DRVM_IOCTL                0x100
#define DRVM_ADD_THRU             (DRVM_IOCTL+1)
#define DRVM_REMOVE_THRU          (DRVM_IOCTL+2)
#define DRVM_IOCTL_LAST           (DRVM_IOCTL+5)

typedef struct {
    DWORD  dwSize; // size of this structure (inclusive)
    DWORD  dwCmd;  // IOCTL command code, 0x80000000 and above reserved for system
    } DRVM_IOCTL_DATA, FAR * LPDRVM_IOCTL_DATA;

// command code ranges for dwCmd field of DRVM_IOCTL message
// codes from 0 to 0x7FFFFFFF are user defined
// codes from 0x80000000 to 0xFFFFFFFF are reserved for future
// definition by microsoft
//
#define DRVM_IOCTL_CMD_USER   0x00000000L
#define DRVM_IOCTL_CMD_SYSTEM 0x80000000L
//

// message base for driver specific messages.
// 
/*XLATON*/							/* ;Internal*/
#define DRVM_MAPPER             0x2000
#define DRVM_USER               0x4000
/*XLATOFF*/							/* ;Internal*/
#define DRVM_MAPPER_STATUS              (DRVM_MAPPER+0)
#define	DRVM_MAPPER_RECONFIGURE	        (DRVM_MAPPER+1)
#define	DRVM_MAPPER_QUERYDEST	        (DRVM_MAPPER+20)        /* ;Internal*/
#define DRVM_MAPPER_PREFERRED_GET       (DRVM_MAPPER+21)
#define DRVM_MAPPER_PREFERRED_SET       (DRVM_MAPPER+22)        /* ;Internal */
#define DRVM_MAPPER_CONSOLEVOICECOM_GET (DRVM_MAPPER+23)
#define DRVM_MAPPER_CONSOLEVOICECOM_SET (DRVM_MAPPER+24)        /* ;Internal */

#ifndef _WIN32
#define DRV_QUERYDRVENTRY    (DRV_RESERVED + 1)
#define DRV_QUERYDEVNODE     (DRV_RESERVED + 2)
#define DRV_QUERYNAME        (DRV_RESERVED + 3)
#define DRV_QUERYDRIVERIDS   (DRV_RESERVED + 4)
#define DRV_QUERYMAPPABLE    (DRV_RESERVED + 5)
#else								/* ;Internal*/
#define DRV_QUERYDRVENTRY    (DRV_RESERVED + 1)			/* ;Internal*/
#define DRV_QUERYDEVNODE     (DRV_RESERVED + 2)			/* ;Internal*/
#define DRV_QUERYNAME        (DRV_RESERVED + 3)			/* ;Internal*/
#define DRV_QUERYDRIVERIDS   (DRV_RESERVED + 4)			/* ;Internal*/
#define DRV_QUERYMAPPABLE    (DRV_RESERVED + 5)			/* ;Internal*/
#endif

//
// DRVM_MAPPER_PREFERRED_GET flags
//
#define DRVM_MAPPER_PREFERRED_FLAGS_PREFERREDONLY   0x00000001

#define	DRV_F_ADD	0x00000000
#define	DRV_F_REMOVE	0x00000001
#define	DRV_F_CHANGE	0x00000002
#define DRV_F_PROP_INSTR 0x00000004
#define DRV_F_NEWDEFAULTS 0x00000008
#define DRV_F_PARAM_IS_DEVNODE 0x10000000
#endif

/* PnP version of media device caps */
typedef struct {
    DWORD	cbSize;
    LPVOID	pCaps;
} MDEVICECAPSEX;

/*XLATON*/							/* ;Internal*/
#ifndef MMNOWAVEDEV
/****************************************************************************
 
                       Waveform device driver support
 
****************************************************************************/

/* maximum number of wave device drivers loaded */
#define MAXWAVEDRIVERS          10
/*XLATOFF*/							/* ;Internal*/

#if 0								/* ;BeginInternal*/
/* Used to create the INC version of the struct */
/*XLATON*/
typedef struct WAVEOPENDESC {
	WORD	wod_hWave;
	DWORD	wod_lpFormat;
	DWORD	wod_dwCallback;
	DWORD	wod_dwInstance;
	WORD	wod_uMappedDeviceID;
	DWORD	wod_dnDevNode;
} WAVEOPENDESC;
/*XLATOFF*/
#endif								/* ;EndInternal*/

/* waveform input and output device open information structure */
typedef struct waveopendesc_tag {
    HWAVE          hWave;             /* handle */
    const WAVEFORMATEX FAR* lpFormat; /* format of wave data */
    DWORD          dwCallback;        /* callback */
    DWORD          dwInstance;        /* app's private instance information */
    UINT           uMappedDeviceID;   /* device to map to if WAVE_MAPPED set */
    DWORD          dnDevNode;         /* if device is PnP */
} WAVEOPENDESC;
typedef WAVEOPENDESC FAR *LPWAVEOPENDESC;

/*XLATON*/							/* ;Internal*/
#define WODM_USER               DRVM_USER
#define WIDM_USER               DRVM_USER
#define WODM_MAPPER             DRVM_MAPPER
#define WIDM_MAPPER             DRVM_MAPPER

#define WODM_INIT               DRVM_INIT
#define WIDM_INIT               DRVM_INIT

/* messages sent to wodMessage() entry-point function */
#define WODM_GETNUMDEVS         3
#define WODM_GETDEVCAPS         4
#define WODM_OPEN               5
#define WODM_CLOSE              6
#define WODM_PREPARE            7
#define WODM_UNPREPARE          8
#define WODM_WRITE              9
#define WODM_PAUSE              10
#define WODM_RESTART            11
#define WODM_RESET              12 
#define WODM_GETPOS             13
#define WODM_GETPITCH           14
#define WODM_SETPITCH           15
#define WODM_GETVOLUME          16
#define WODM_SETVOLUME          17
#define WODM_GETPLAYBACKRATE    18
#define WODM_SETPLAYBACKRATE    19
#define WODM_BREAKLOOP          20
#define WODM_PREFERRED          21
/*XLATOFF*/							/* ;Internal*/
#if (WINVER >= 0x0400)
#define WODM_MAPPER_STATUS              (DRVM_MAPPER_STATUS + 0)
#define WAVEOUT_MAPPER_STATUS_DEVICE    0
#define WAVEOUT_MAPPER_STATUS_MAPPED    1
#define WAVEOUT_MAPPER_STATUS_FORMAT    2
#endif

/*XLATON*/							/* ;Internal*/
/* messages sent to widMessage() entry-point function */
#define WIDM_GETNUMDEVS         50
#define WIDM_GETDEVCAPS         51
#define WIDM_OPEN               52
#define WIDM_CLOSE              53
#define WIDM_PREPARE            54
#define WIDM_UNPREPARE          55
#define WIDM_ADDBUFFER          56
#define WIDM_START              57
#define WIDM_STOP               58
#define WIDM_RESET              59
#define WIDM_GETPOS             60
#define WIDM_PREFERRED          61
/*XLATOFF*/							/* ;Internal*/
#if (WINVER >= 0x0400)
#define WIDM_MAPPER_STATUS              (DRVM_MAPPER_STATUS + 0)
#define WAVEIN_MAPPER_STATUS_DEVICE     0
#define WAVEIN_MAPPER_STATUS_MAPPED     1
#define WAVEIN_MAPPER_STATUS_FORMAT     2
#endif
/*XLATON*/							/* ;Internal*/
#endif  /*ifndef MMNOWAVEDEV */


#ifndef MMNOMIDIDEV
/****************************************************************************

                          MIDI device driver support

****************************************************************************/

/* maximum number of MIDI device drivers loaded */
/*XLATON*/							/* ;Internal*/
#define MAXMIDIDRIVERS 10

#define MODM_USER      DRVM_USER
#define MIDM_USER      DRVM_USER
#define MODM_MAPPER    DRVM_MAPPER
#define MIDM_MAPPER    DRVM_MAPPER

#define MODM_INIT      DRVM_INIT
#define MIDM_INIT      DRVM_INIT
/*XLATOFF*/							/* ;Internal*/

#if 0								/* ;BeginInternal*/
/* Used to create the INC version of the struct */
/*XLATON*/
typedef struct MIDIOPENDESC {
	WORD	mod_hMidi;
	DWORD	mod_dwCallback;
	DWORD	mod_dwInstance;
} MIDIOPENDESC;
/*XLATOFF*/
#endif								/* ;EndInternal*/

typedef struct midiopenstrmid_tag {
    DWORD          dwStreamID;
    WORD           wDeviceID;
} MIDIOPENSTRMID;
/* MIDI input and output device open information structure */
typedef struct midiopendesc_tag {
    HMIDI          hMidi;             /* handle */
    DWORD          dwCallback;        /* callback */
    DWORD          dwInstance;        /* app's private instance information */
    WORD           uReserved;         /* Remove me */
    DWORD          dnDevNode;         /* if device is PnP */
    DWORD          cIds;              /* If stream open, # stream ids */
    MIDIOPENSTRMID rgIds[1];          /* Array of device ID's (actually [cIds])*/
} MIDIOPENDESC;
typedef MIDIOPENDESC FAR *LPMIDIOPENDESC;

#if (WINVER >= 0x0400)
/* structure pointed to by lParam1 for MODM_GET/MODM_SETTIMEPARMS */

typedef struct miditimeparms_tag {
    DWORD	    dwTimeDivision;   /* time division ala MIDI file spec */
    DWORD	    dwTempo;	      /* tempo ala MIDI file spec */
} MIDITIMEPARMS,
  FAR *LPMIDITIMEPARMS;

/* Flags for MODM_OPEN */
#define MIDI_IO_PACKED      0x00000000L     /* Compatibility mode */
#define MIDI_IO_COOKED      0x00000002L

#endif


/*XLATON*/							/* ;Internal*/
/* messages sent to modMessage() entry-point function */
#define MODM_GETNUMDEVS             1
#define MODM_GETDEVCAPS             2
#define MODM_OPEN                   3
#define MODM_CLOSE                  4
#define MODM_PREPARE                5
#define MODM_UNPREPARE              6
#define MODM_DATA                   7
#define MODM_LONGDATA               8
#define MODM_RESET                  9
#define MODM_GETVOLUME              10
#define MODM_SETVOLUME              11
#define MODM_CACHEPATCHES           12      
#define MODM_CACHEDRUMPATCHES	    13
/*XLATOFF*/							/* ;Internal*/

#if (WINVER >= 0x0400)
#define MODM_STRMDATA               14
#define MODM_GETPOS                 17
#define MODM_PAUSE                  18
#define MODM_RESTART                19
#define MODM_STOP                   20
#define MODM_PROPERTIES             21
#define MODM_PREFERRED              22
#define MODM_RECONFIGURE	    (MODM_USER+0x0768)
#endif



/*XLATON*/							/* ;Internal*/
/* messages sent to midMessage() entry-point function */
#define MIDM_GETNUMDEVS             53
#define MIDM_GETDEVCAPS             54
#define MIDM_OPEN                   55
#define MIDM_CLOSE                  56
#define MIDM_PREPARE                57
#define MIDM_UNPREPARE              58
#define MIDM_ADDBUFFER              59
#define MIDM_START                  60
#define MIDM_STOP                   61
#define MIDM_RESET                  62
#endif  /*ifndef MMNOMIDIDEV */


#ifndef MMNOAUXDEV
/****************************************************************************

                    Auxiliary audio device driver support

****************************************************************************/

/* maximum number of auxiliary device drivers loaded */
#define MAXAUXDRIVERS           10

#define AUXM_INIT               DRVM_INIT
#define AUXM_USER               DRVM_USER
#define AUXDM_MAPPER            DRVM_MAPPER

/* messages sent to auxMessage() entry-point function */
#define AUXDM_GETNUMDEVS        3
#define AUXDM_GETDEVCAPS        4
#define AUXDM_GETVOLUME         5
#define AUXDM_SETVOLUME         6

#endif  /*ifndef MMNOAUXDEV */
/*XLATOFF*/							/* ;Internal*/




#ifndef MMNOMIXERDEV
#if (WINVER >= 0x0400)
/****************************************************************************

                        Mixer Driver Support

****************************************************************************/

//
//  maximum number of mixer drivers that can be loaded by MSMIXMGR.DLL
//
#define MAXMIXERDRIVERS         10

//
//  mixer device open information structure
//
//
typedef struct tMIXEROPENDESC
{
    HMIXER          hmx;            // handle that will be used
    LPVOID          pReserved0;     // reserved--driver should ignore
    DWORD           dwCallback;     // callback
    DWORD           dwInstance;     // app's private instance information
    DWORD           dnDevNode;      // if device is PnP

} MIXEROPENDESC, *PMIXEROPENDESC, FAR *LPMIXEROPENDESC;

//
//
//
//
#define MXDM_INIT                  DRVM_INIT
#define MXDM_USER                  DRVM_USER
#define MXDM_MAPPER                DRVM_MAPPER

#define MXDM_BASE                   (1)
#define MXDM_GETNUMDEVS             (MXDM_BASE + 0)
#define MXDM_GETDEVCAPS             (MXDM_BASE + 1)
#define MXDM_OPEN                   (MXDM_BASE + 2)
#define MXDM_CLOSE                  (MXDM_BASE + 3)
#define MXDM_GETLINEINFO            (MXDM_BASE + 4)
#define MXDM_GETLINECONTROLS        (MXDM_BASE + 5)
#define MXDM_GETCONTROLDETAILS      (MXDM_BASE + 6)
#define MXDM_SETCONTROLDETAILS      (MXDM_BASE + 7)

#endif /* ifdef WINVER >= 0x0400 */
#endif /* ifndef MMNOMIXERDEV */


/*XLATON*/							/* ;Internal*/
#ifndef MMNOTIMERDEV
#ifndef _WIN32_VXD                
/*XLATOFF*/							/* ;Internal*/
/****************************************************************************

                        Timer device driver support

****************************************************************************/


#if 0								/* ;BeginInternal*/
/* Used to create the INC version of the struct */
/*XLATON*/
typedef struct TIMEREVENT {
	WORD	te_wDelay;
	WORD	te_wResolution;
	DWORD	te_lpFunction;
	DWORD	te_dwUser;
	WORD	te_wFlags;
} TIMEREVENT;
/*XLATOFF*/
#endif								/* ;EndInternal*/

typedef struct timerevent_tag {
    UINT                wDelay;         /* delay required */
    UINT                wResolution;    /* resolution required */
    LPTIMECALLBACK      lpFunction;     /* ptr to callback function */
    DWORD               dwUser;         /* user DWORD */
    UINT                wFlags;         /* defines how to program event */
} TIMEREVENT;
typedef TIMEREVENT FAR *LPTIMEREVENT;

/*XLATON*/							/* ;Internal*/
/* messages sent to tddMessage() function */
#define TDD_KILLTIMEREVENT      (DRV_RESERVED + 0)  /* indices into a table of */
#define TDD_SETTIMEREVENT       (DRV_RESERVED + 4)  /* functions; thus offset by */
#define TDD_GETSYSTEMTIME       (DRV_RESERVED + 8)  /* four each time... */
#define TDD_GETDEVCAPS          (DRV_RESERVED + 12) /* room for future expansion */
#define TDD_BEGINMINPERIOD      (DRV_RESERVED + 16) /* room for future expansion */
#define TDD_ENDMINPERIOD        (DRV_RESERVED + 20) /* room for future expansion */
#endif  /* ifndef _WIN32_VXD */
#endif  /*ifndef MMNOTIMERDEV */


#ifndef MMNOJOYDEV
/*XLATOFF*/							/* ;Internal*/
/****************************************************************************

                       Joystick device driver support

****************************************************************************/

/*XLATON*/							/* ;Internal*/
/* RegisterWindowMessage with this to get msg id of config changes */
#define JOY_CONFIGCHANGED_MSGSTRING	"MSJSTICK_VJOYD_MSGSTR"

/* pre-defined joystick types */
#define JOY_HW_NONE			0
#define JOY_HW_CUSTOM			1
#define JOY_HW_2A_2B_GENERIC		2
#define JOY_HW_2A_4B_GENERIC		3
#define JOY_HW_2B_GAMEPAD		4
#define JOY_HW_2B_FLIGHTYOKE		5
#define JOY_HW_2B_FLIGHTYOKETHROTTLE	6
#define JOY_HW_3A_2B_GENERIC		7
#define JOY_HW_3A_4B_GENERIC		8
#define JOY_HW_4B_GAMEPAD		9
#define JOY_HW_4B_FLIGHTYOKE		10
#define JOY_HW_4B_FLIGHTYOKETHROTTLE	11
#define JOY_HW_LASTENTRY		12

/* calibration flags */
#define	JOY_ISCAL_XY		0x00000001l	/* XY are calibrated */
#define	JOY_ISCAL_Z		0x00000002l	/* Z is calibrated */
#define	JOY_ISCAL_R		0x00000004l	/* R is calibrated */
#define	JOY_ISCAL_U		0x00000008l	/* U is calibrated */
#define	JOY_ISCAL_V		0x00000010l	/* V is calibrated */
#define	JOY_ISCAL_POV		0x00000020l	/* POV is calibrated */

/* point of view constants */
#define JOY_POV_NUMDIRS          4
#define JOY_POVVAL_FORWARD       0
#define JOY_POVVAL_BACKWARD      1
#define JOY_POVVAL_LEFT          2
#define JOY_POVVAL_RIGHT         3

/* Specific settings for joystick hardware */
#define JOY_HWS_HASZ		0x00000001l	/* has Z info? */
#define JOY_HWS_HASPOV		0x00000002l	/* point of view hat present */
#define JOY_HWS_POVISBUTTONCOMBOS 0x00000004l	/* pov done through combo of buttons */
#define JOY_HWS_POVISPOLL	0x00000008l	/* pov done through polling */
#define JOY_HWS_ISYOKE		0x00000010l	/* joystick is a flight yoke */
#define JOY_HWS_ISGAMEPAD	0x00000020l	/* joystick is a game pad */
#define JOY_HWS_ISCARCTRL	0x00000040l	/* joystick is a car controller */
/* X defaults to J1 X axis */
#define JOY_HWS_XISJ1Y		0x00000080l	/* X is on J1 Y axis */
#define JOY_HWS_XISJ2X		0x00000100l	/* X is on J2 X axis */
#define JOY_HWS_XISJ2Y		0x00000200l	/* X is on J2 Y axis */
/* Y defaults to J1 Y axis */
#define JOY_HWS_YISJ1X		0x00000400l	/* Y is on J1 X axis */
#define JOY_HWS_YISJ2X		0x00000800l	/* Y is on J2 X axis */
#define JOY_HWS_YISJ2Y		0x00001000l	/* Y is on J2 Y axis */
/* Z defaults to J2 Y axis */
#define JOY_HWS_ZISJ1X		0x00002000l	/* Z is on J1 X axis */
#define JOY_HWS_ZISJ1Y		0x00004000l	/* Z is on J1 Y axis */
#define JOY_HWS_ZISJ2X		0x00008000l	/* Z is on J2 X axis */
/* POV defaults to J2 Y axis, if it is not button based */
#define JOY_HWS_POVISJ1X	0x00010000l	/* pov done through J1 X axis */
#define JOY_HWS_POVISJ1Y	0x00020000l	/* pov done through J1 Y axis */
#define JOY_HWS_POVISJ2X	0x00040000l	/* pov done through J2 X axis */
/* R defaults to J2 X axis */
#define JOY_HWS_HASR		0x00080000l	/* has R (4th axis) info */
#define JOY_HWS_RISJ1X		0x00100000l	/* R done through J1 X axis */
#define JOY_HWS_RISJ1Y		0x00200000l	/* R done through J1 Y axis */
#define JOY_HWS_RISJ2Y		0x00400000l	/* R done through J2 X axis */
/* U & V for future hardware */
#define JOY_HWS_HASU		0x00800000l	/* has U (5th axis) info */
#define JOY_HWS_HASV		0x01000000l	/* has V (6th axis) info */

/* Usage settings */
#define JOY_US_HASRUDDER	0x00000001l	/* joystick configured with rudder */
#define JOY_US_PRESENT		0x00000002l	/* is joystick actually present? */
#define JOY_US_ISOEM		0x00000004l	/* joystick is an OEM defined type */
/*XLATOFF*/							/* ;Internal*/

#if 0								/* ;BeginInternal*/
/* Used to create the INC version of the structs */
/*XLATON*/
typedef struct JOYCALIBRATE {
	WORD	jcal_wXbase;
	WORD	jcal_wXdelta;
	WORD	jcal_wYbase;
	WORD	jcal_wYdelta;
	WORD	jcal_wZbase;
	WORD	jcal_wZdelta;
} JOYCALIBRATE;

typedef struct joypos_tag {
    DWORD	jpos_dwX;
    DWORD	jpos_dwY;
    DWORD	jpos_dwZ;
    DWORD	jpos_dwR;
    DWORD	jpos_dwU;
    DWORD	jpos_dwV;
} JOYPOS;

typedef struct joyrange_tag {
    joypos_tag	jrange_jpMin;
    joypos_tag	jrange_jpMax;
    joypos_tag	jrange_jpCenter;
} JOYRANGE;

typedef struct joyreguservalues_tag {
    DWORD	jreguv_dwTimeOut;
    joyrange_tag jreguv_jrvRanges;
    joypos_tag	jreguv_jpDeadZone;
} JOYREGUSERVALUES;

typedef struct joyreghwsettings_tag {
    DWORD	jreghws_dwFlags;
    DWORD	jreghws_dwNumButtons;
} JOYREGHWSETTINGS;

typedef struct joyreghwvalues_tag {
    joyrange_tag jreghwv_jrvHardware;
    DWORD	jreghwv_dwPOVValues[JOY_POV_NUMDIRS];
    DWORD	reghwv_dwCalFlags;
} JOYREGHWVALUES;

typedef struct joyreghwconfig_tag {
    joyreghwsettings_tag jreghwc_hws;
    DWORD		jreghwc_dwUsageSettings;
    joyreghwvalues_tag	jreghwc_hwv;
    DWORD		jreghwc_dwType;
} JOYREGHWCONFIG, FAR *LPJOYREGHWCONFIG;
/*XLATOFF*/
#endif								/* ;EndInternal*/

/* struct for storing x,y, z, and rudder values */
typedef struct joypos_tag {
    DWORD	dwX;
    DWORD	dwY;
    DWORD	dwZ;
    DWORD	dwR;
    DWORD	dwU;
    DWORD	dwV;
} JOYPOS, FAR *LPJOYPOS;

/* struct for storing ranges */
typedef struct joyrange_tag {
    JOYPOS	jpMin;
    JOYPOS	jpMax;
    JOYPOS	jpCenter;
} JOYRANGE,FAR *LPJOYRANGE;

typedef struct joyreguservalues_tag {
    DWORD	dwTimeOut;	/* value at which to timeout joystick polling */
    JOYRANGE	jrvRanges;	/* range of values app wants returned for axes */
    JOYPOS	jpDeadZone;	/* area around center to be considered
    				   as "dead". specified as a percentage
				   (0-100). Only X & Y handled by system driver */
} JOYREGUSERVALUES, FAR *LPJOYREGUSERVALUES;

typedef struct joyreghwsettings_tag {
    DWORD	dwFlags;
    DWORD	dwNumButtons;		/* number of buttons */
} JOYREGHWSETTINGS, FAR *LPJOYHWSETTINGS;

/* range of values returned by the hardware (filled in by calibration) */
typedef struct joyreghwvalues_tag {
    JOYRANGE	jrvHardware;		/* values returned by hardware */
    DWORD	dwPOVValues[JOY_POV_NUMDIRS];/* POV values returned by hardware */
    DWORD	dwCalFlags;		/* what has been calibrated */
} JOYREGHWVALUES, FAR *LPJOYREGHWVALUES;

/* hardware configuration */
typedef struct joyreghwconfig_tag {
    JOYREGHWSETTINGS	hws;		/* hardware settings */
    DWORD		dwUsageSettings;/* usage settings */
    JOYREGHWVALUES	hwv;		/* values returned by hardware */
    DWORD		dwType;		/* type of joystick */
    DWORD		dwReserved;	/* reserved for OEM drivers */
} JOYREGHWCONFIG, FAR *LPJOYREGHWCONFIG;

/* joystick calibration info structure */
typedef struct joycalibrate_tag {
    UINT    wXbase;
    UINT    wXdelta;
    UINT    wYbase;
    UINT    wYdelta;
    UINT    wZbase;
    UINT    wZdelta;
} JOYCALIBRATE;
typedef JOYCALIBRATE FAR *LPJOYCALIBRATE;

/* prototype for joystick message function */
#ifndef _WIN32_VXD
typedef UINT (CALLBACK JOYDEVMSGPROC)(DWORD dwID, UINT uMessage, LPARAM lParam1, LPARAM lParam2);
typedef JOYDEVMSGPROC FAR *LPJOYDEVMSGPROC;
#endif

/*XLATON*/							/* ;Internal*/
/* messages sent to joystick driver's DriverProc() function */
#define JDD_GETNUMDEVS          (DRV_RESERVED + 0x0001)
#define JDD_GETDEVCAPS          (DRV_RESERVED + 0x0002)
#define JDD_GETPOS              (DRV_RESERVED + 0x0101)
#define JDD_SETCALIBRATION      (DRV_RESERVED + 0x0102)
#define JDD_CONFIGCHANGED       (DRV_RESERVED + 0x0103)
#define JDD_GETPOSEX            (DRV_RESERVED + 0x0104)

#endif  /*ifndef MMNOJOYDEV */


#ifndef MMNOMCIDEV
#ifndef _WIN32_VXD
/****************************************************************************

                        MCI device driver support

****************************************************************************/

/* internal MCI messages */
#define MCI_OPEN_DRIVER         (DRV_RESERVED + 0x0001)
#define MCI_CLOSE_DRIVER        (DRV_RESERVED + 0x0002)

#define MAKEMCIRESOURCE(wRet, wRes) MAKELRESULT((wRet), (wRes))

/* string return values only used with MAKEMCIRESOURCE */
#define MCI_FALSE                   (MCI_STRING_OFFSET + 19)
#define MCI_TRUE                    (MCI_STRING_OFFSET + 20)

/* resource string return values */
#define MCI_FORMAT_RETURN_BASE      MCI_FORMAT_MILLISECONDS_S
#define MCI_FORMAT_MILLISECONDS_S   (MCI_STRING_OFFSET + 21)
#define MCI_FORMAT_HMS_S            (MCI_STRING_OFFSET + 22)
#define MCI_FORMAT_MSF_S            (MCI_STRING_OFFSET + 23)
#define MCI_FORMAT_FRAMES_S         (MCI_STRING_OFFSET + 24)
#define MCI_FORMAT_SMPTE_24_S       (MCI_STRING_OFFSET + 25)
#define MCI_FORMAT_SMPTE_25_S       (MCI_STRING_OFFSET + 26)
#define MCI_FORMAT_SMPTE_30_S       (MCI_STRING_OFFSET + 27)
#define MCI_FORMAT_SMPTE_30DROP_S   (MCI_STRING_OFFSET + 28)
#define MCI_FORMAT_BYTES_S          (MCI_STRING_OFFSET + 29)
#define MCI_FORMAT_SAMPLES_S        (MCI_STRING_OFFSET + 30)
#define MCI_FORMAT_TMSF_S           (MCI_STRING_OFFSET + 31)

#define MCI_VD_FORMAT_TRACK_S       (MCI_VD_OFFSET + 5)

#define WAVE_FORMAT_PCM_S           (MCI_WAVE_OFFSET + 0)
#define WAVE_MAPPER_S               (MCI_WAVE_OFFSET + 1)

#define MCI_SEQ_MAPPER_S            (MCI_SEQ_OFFSET + 5)
#define MCI_SEQ_FILE_S              (MCI_SEQ_OFFSET + 6)
#define MCI_SEQ_MIDI_S              (MCI_SEQ_OFFSET + 7)
#define MCI_SEQ_SMPTE_S             (MCI_SEQ_OFFSET + 8)
#define MCI_SEQ_FORMAT_SONGPTR_S    (MCI_SEQ_OFFSET + 9)
#define MCI_SEQ_NONE_S              (MCI_SEQ_OFFSET + 10)
#define MIDIMAPPER_S                (MCI_SEQ_OFFSET + 11)
/*XLATOFF*/							/* ;Internal*/
#if 0								/* ;BeginInternal*/
/* Used to create the INC version of the struct */
/*XLATON*/
typedef struct MCI_OPEN_DRIVER_PARMS {
	WORD	mciodrv_wDeviceID;
	DWORD	mciodrv_lpstrParams;
	WORD	mciodrv_wCustomCommandTable;
	WORD	mciodrv_wType;
} MCI_OPEN_DRIVER_PARMS;
/*XLATOFF*/
#endif								/* ;EndInternal*/

/* parameters for internal version of MCI_OPEN message sent from */
/* mciOpenDevice() to the driver */
typedef struct {
    MCIDEVICEID wDeviceID;         /* device ID */
    LPCSTR  lpstrParams;           /* parameter string for entry in SYSTEM.INI */
    UINT    wCustomCommandTable;   /* custom command table (0xFFFF if none) */
                                   /* filled in by the driver */
    UINT    wType;                 /* driver type */
                                   /* filled in by the driver */
} MCI_OPEN_DRIVER_PARMS,
FAR *LPMCI_OPEN_DRIVER_PARMS;

/*XLATON*/							/* ;Internal*/
/* maximum length of an MCI device type */
#define MCI_MAX_DEVICE_TYPE_LENGTH 80

/* flags for mciSendCommandInternal() which direct mciSendString() how to */
/* interpret the return value */
#define MCI_RESOURCE_RETURNED   0x00010000  /* resource ID */
#define MCI_COLONIZED3_RETURN   0x00020000  /* colonized ID, 3 bytes data */
#define MCI_COLONIZED4_RETURN   0x00040000  /* colonized ID, 4 bytes data */
#define MCI_INTEGER_RETURNED    0x00080000  /* integer conversion needed */
#define MCI_RESOURCE_DRIVER     0x00100000  /* driver owns returned resource */

/* invalid command table ID */
#define MCI_NO_COMMAND_TABLE    -1

/* command table information type tags */
#define MCI_COMMAND_HEAD        0
#define MCI_STRING              1
#define MCI_INTEGER             2
#define MCI_END_COMMAND         3
#define MCI_RETURN              4
#define MCI_FLAG                5
#define MCI_END_COMMAND_LIST    6
#define MCI_RECT                7
#define MCI_CONSTANT            8
#define MCI_END_CONSTANT        9

/*XLATOFF*/							/* ;Internal*/
/* function prototypes for MCI driver functions */
WINMMAPI DWORD WINAPI mciGetDriverData(UINT uDeviceID);
WINMMAPI BOOL  WINAPI mciSetDriverData(UINT uDeviceID, DWORD dwData);
WINMMAPI UINT  WINAPI mciDriverYield(UINT uDeviceID);
WINMMAPI BOOL  WINAPI mciDriverNotify(HWND hwndCallback, UINT uDeviceID,
    UINT uStatus);
#ifdef _WIN32
WINMMAPI UINT  WINAPI mciLoadCommandResource(HINSTANCE hInstance, LPCWSTR lpResName, UINT uType);
#else
UINT  WINAPI mciLoadCommandResource(HINSTANCE hInstance, LPCSTR lpResName, UINT uType);
#endif
WINMMAPI BOOL  WINAPI mciFreeCommandResource(UINT uTable);
/*XLATON*/							/* ;Internal*/

#endif  /*ifndef _WIN32_VXD */
#endif  /*ifndef MMNOMCIDEV */


#ifndef MMNOTASKDEV
/*XLATOFF*/							/* ;Internal*/
#ifndef _WIN32_VXD
#ifndef _WIN32
/*****************************************************************************

                               Task support

*****************************************************************************/

/* error return values */
/*XLATON*/							/* ;Internal*/
#define TASKERR_NOTASKSUPPORT   1
#define TASKERR_OUTOFMEMORY     2
/*XLATOFF*/							/* ;Internal*/

/* task support function prototypes */
#ifdef  BUILDDLL                                        /* ;Internal */
typedef void (FAR PASCAL TASKCALLBACK) (DWORD dwInst);  /* ;Internal */
#else   /*ifdef BUILDDLL*/                              /* ;Internal */
typedef void (CALLBACK TASKCALLBACK) (DWORD dwInst);
#endif  /*ifdef BUILDDLL*/                              /* ;Internal */

typedef TASKCALLBACK FAR *LPTASKCALLBACK;

WINMMAPI UINT    WINAPI mmTaskCreate(LPTASKCALLBACK lpfnTaskProc, HTASK FAR * lphTask, DWORD dwInst);
WINMMAPI UINT    WINAPI mmTaskBlock(HTASK h);
WINMMAPI BOOL    WINAPI mmTaskSignal(HTASK h);
WINMMAPI void    WINAPI mmTaskYield(void);
WINMMAPI HTASK   WINAPI mmGetCurrentTask(void);

/* mmThread function prototypes and defines */		/* ;Internal */
UINT  WINAPI mmThreadCreate(LPTASKCALLBACK lpfn, LPHANDLE lphmt, DWORD dwParam, DWORD dwFlags);   /* ;Internal */
VOID  WINAPI mmThreadSignal(HANDLE hmt);		/* ;Internal */
VOID  WINAPI mmThreadBlock(HANDLE hmt);			/* ;Internal */
BOOL  WINAPI mmThreadIsCurrent(HANDLE hmt);		/* ;Internal */
BOOL  WINAPI mmThreadIsValid(HANDLE hmt);		/* ;Internal */
HTASK WINAPI mmThreadGetTask(HANDLE hmt);		/* ;Internal */

#endif  /*infdef _WIN32 */
#define MMTHREAD_CREATEF_16BIT	    (0x00000001)	/* ;Internal */
#define MMTHREAD_CREATEF_KERNEL	    (0x00000002)	/* ;Internal */
#endif /* ifndef _WIN32_VXD */
/*XLATON*/							/* ;Internal*/
#endif  /*ifndef MMNOTASKDEV */
/*XLATOFF*/							/* ;Internal*/

#define MMDDKINC                /* ;Internal */

#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif  /* __cplusplus */

#ifndef RC_INVOKED
#pragma pack()          /* Revert to default packing */
#endif

#endif  /* _INC_MMDDK */
