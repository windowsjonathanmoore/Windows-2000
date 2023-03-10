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

CDB_6_byte	EQU	6
CDB_10_byte	EQU	10
SCSI_Test_Unit_Ready	EQU	00H
SCSI_Rezero_Unit	EQU	01H
SCSI_Rewind	EQU	01H
SCSI_Request_Sense	EQU	03H
SCSI_Read_Blk_Limits	EQU	05H
SCSI_Req_Aux_Sense	EQU	06H
SCSI_Read_6	EQU	08H
SCSI_Write_6	EQU	0AH
SCSI_Write_Filemarks	EQU	10H
SCSI_Space	EQU	11H
SCSI_Inquiry	EQU	12H
SCSI_Recover_Buffer	EQU	14H
SCSI_Mode_Select	EQU	15H
SCSI_Reserve_Unit	EQU	16H
SCSI_Release_Unit	EQU	17H
SCSI_Erase	EQU	19H
SCSI_Mode_Sense	EQU	1AH
SCSI_Start_Stop_Unit	EQU	1BH
SCSI_Load_Unload	EQU	1BH
SCSI_Lock_Unlock	EQU	1EH
SCSI_Read_Capacity	EQU	25H
SCSI_Read_10	EQU	28H
SCSI_Write_10	EQU	2AH
SCSI_Seek_10	EQU	2BH
SCSI_Locate	EQU	2BH
SCSI_Write_Verify_10	EQU	2EH
SCSI_Verify_10	EQU	2FH
SCSI_Read_Sub_Chan	EQU	42H
SCSI_Read_TOC	EQU	43H
SCSI_Play_MSF	EQU	47H
SCSI_Pause_Resume	EQU	4BH
SCSI_CHECK_CONDITION	EQU	02H
SCSI_TARGET_BUSY	EQU	08H
SCSI_GOOD_STATUS	EQU	00H
SCSI_CONDITION_MET	EQU	04H
SCSI_INTERMEDIATE_GOOD	EQU	14H
SCSI_RESERVATION_CONFLICT	EQU	18H
SCSI_QUEUE_FULL	EQU	28H
SCSI_SENSE_KEY_MASK	EQU	0fH
SCSI_SENSE_NO_SENSE	EQU	00H
SCSI_RECOVERED_ERROR	EQU	01H
SCSI_NOT_READY	EQU	02H
SCSI_MEDIUM_ERROR	EQU	03H
SCSI_HARDWARE_ERROR	EQU	04H
SCSI_ILLEGAL_REQUEST	EQU	05H
SCSI_UNIT_ATTENTION	EQU	06H
SCSI_ABORTED_ERROR	EQU	0BH

Request_Sense	STRUC
RSB_ErrCode	DB	?
RSB_Segment	DB	?
RSB_Sense_key	DB	?
RSB_Information	DD	?
RSB_Add_sns_len	DB	?
RSB_Cmd_specific_info	DD	?
RSB_Add_sns_code	DB	?
RSB_Add_sns_qualifier	DB	?
RSB_FRU_Code	DB	?
RSB_Sns_key_Specific	DW	?
RSB_Addtl_Sense_Bytes	DB	?
Request_Sense	ENDS
SSC_LUN_NOT_READY	EQU	04H
ifdef  NEC_98
ifdef        MO
SSQ_MAN_INTERV_REQUIRED	EQU	00H
SSQ_FORMAT_IN_PROG	EQU	00H
else
SSQ_MAN_INTERV_REQUIRED	EQU	03H
SSQ_FORMAT_IN_PROG	EQU	04H
endif
else
SSQ_MAN_INTERV_REQUIRED	EQU	03H
SSQ_FORMAT_IN_PROG	EQU	04H
endif

InqFlags	STRUC
INQ_Dev_Type	DB	?
INQ_Dev_Type_Mod	DB	?
INQ_Version	DB	?
INQ_Response_Data	DB	?
INQ_Additional_Len	DB	?
INQ_Reserved_1	DB	?
INQ_Reserved_2	DB	?
INQ_Dev_Flags	DB	?
InqFlags	ENDS
INQ_mod_removable	EQU	80H
INQ_Rel_Adr	EQU	80H
INQ_Wide_32	EQU	40H
INQ_Wide_16	EQU	20H
INQ_Synch_Supp	EQU	10H
INQ_Linked_Cmd	EQU	08H
INQ_Cmd_Queue	EQU	02H
INQ_Sft_Reset	EQU	01H
SCSI_DASD_TYPE	EQU	00H
SCSI_SEQUENTIAL_TYPE	EQU	01H
SCSI_PRINTER_TYPE	EQU	02H
SCSI_PROCESSOR_TYPE	EQU	03H
SCSI_WORM_TYPE	EQU	04H
SCSI_CDROM_TYPE	EQU	05H
SCSI_SCANNER_TYPE	EQU	06H
SCSI_OPTICAL_TYPE	EQU	07H
SCSI_MEDIACHANGER_TYPE	EQU	08H
SCSI_COMMUNICATIONS_TYPE	EQU	09H
SCSI_UNKNOWN_TYPE	EQU	1FH
SCSI_FLOPPY_TYPE	EQU	1EH
REAL_MAPPER_TYPE	EQU	1DH
ifdef	NEC_98
SCSI_OPTICAL_NEC_TYPE	EQU	1CH
endif
