/**********************************************************************/
/**                       Microsoft Windows NT                       **/
/**                Copyright(c) Microsoft Corp., 1993-1999           **/
/**********************************************************************/

/*
    mdmsg.h

    This file is generated by the MC tool from the MDMSG.MC message
    file.


    FILE HISTORY:
        michth      26-Jun-1996 Created.

*/


#ifndef _MDMSG_H_
#define _MDMSG_H_

//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +-+-+-+-+-+---------------------+-------------------------------+
//  |S|R|C|N|r|    Facility         |               Code            |
//  +-+-+-+-+-+---------------------+-------------------------------+
//
//  where
//
//      S - Severity - indicates success/fail
//
//          0 - Success
//          1 - Fail (COERROR)
//
//      R - reserved portion of the facility code, corresponds to NT's
//              second severity bit.
//
//      C - reserved portion of the facility code, corresponds to NT's
//              C field.
//
//      N - reserved portion of the facility code. Used to indicate a
//              mapped NT status value.
//
//      r - reserved portion of the facility code. Reserved for internal
//              use. Used to indicate HRESULT values that are not status
//              values, but are instead message ids for display strings.
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: MD_ERROR_NOT_INITIALIZED
//
// MessageText:
//
//  MetaData has not been initialized.
//
#define MD_ERROR_NOT_INITIALIZED         0x800CC800L

//
// MessageId: MD_ERROR_DATA_NOT_FOUND
//
// MessageText:
//
//  The specified metadata was not found.
//
#define MD_ERROR_DATA_NOT_FOUND          0x800CC801L

//
// MessageId: MD_ERROR_INVALID_VERSION
//
// MessageText:
//
//  The version specified in metadata storage was not recognized.
//
#define MD_ERROR_INVALID_VERSION         0x800CC802L

//
// MessageId: MD_WARNING_PATH_NOT_FOUND
//
// MessageText:
//
//  A specified metaobject path was not found. The metaobject and associated metadata was ignored.
//
#define MD_WARNING_PATH_NOT_FOUND        0x000CC803L

//
// MessageId: MD_WARNING_DUP_NAME
//
// MessageText:
//
//  A metaobject or metadata was specified more than once. The duplicate ignored.
//
#define MD_WARNING_DUP_NAME              0x000CC804L

//
// MessageId: MD_WARNING_INVALID_DATA
//
// MessageText:
//
//  Invalid metadata was specified. The invalid metadata was ignored.
//
#define MD_WARNING_INVALID_DATA          0x000CC805L

//
// MessageId: MD_ERROR_SECURE_CHANNEL_FAILURE
//
// MessageText:
//
//  A secure communications channel could not be established with the target server.
//
#define MD_ERROR_SECURE_CHANNEL_FAILURE  0x800CC806L

//
// MessageId: MD_WARNING_PATH_NOT_INSERTED
//
// MessageText:
//
//  The path was not inserted into the string as requested. The probable cause is that the data is at an object at a higher level than the handle.
//
#define MD_WARNING_PATH_NOT_INSERTED     0x000CC807L

//
// MessageId: MD_ERROR_CANNOT_REMOVE_SECURE_ATTRIBUTE
//
// MessageText:
//
//  The METADATA_SECURE attribute cannot be removed from a data item via the GetData method. Use the DeleteData method to remove the secure data.
//
#define MD_ERROR_CANNOT_REMOVE_SECURE_ATTRIBUTE 0x800CC808L

//
// MessageId: MD_WARNING_SAVE_FAILED
//
// MessageText:
//
//  The metadata save prior to backup failed. The previous version of the data was backed up.
//
#define MD_WARNING_SAVE_FAILED           0x000CC809L

//
// MessageId: MD_ERROR_IISAO_INVALID_SCHEMA
//
// MessageText:
//
//  The schema information could not be loaded. A required key or property is missing from the metabase.
//
#define MD_ERROR_IISAO_INVALID_SCHEMA    0x800CC810L

//
// MessageId: MD_ERROR_READING_SCHEMA_BIN
//
// MessageText:
//
//  Schema information could not be read becuase could not fetch or read bin file where the information resides. Hence unable to read text edits.
//
#define MD_ERROR_READING_SCHEMA_BIN      0xC002C811L

//
// MessageId: MD_ERROR_NO_MATCHING_HISTORY_FILE
//
// MessageText:
//
//  Could not find a history file with the same major version number as the one being edited. Hence cannot process edits.
//
#define MD_ERROR_NO_MATCHING_HISTORY_FILE 0xC002C812L

//
// MessageId: MD_ERROR_PROCESSING_TEXT_EDITS
//
// MessageText:
//
//  An error occured while processing text edits to the metabase file. File is being copied into the history directory with the name errors appended to it.
//
#define MD_ERROR_PROCESSING_TEXT_EDITS   0xC002C813L

//
// MessageId: MD_ERROR_COMPUTING_TEXT_EDITS
//
// MessageText:
//
//  An error occured while determining what text edits occured to the metabase file. 
//
#define MD_ERROR_COMPUTING_TEXT_EDITS    0xC002C814L

//
// MessageId: MD_ERROR_READING_TEXT_EDITS
//
// MessageText:
//
//  An error occured while reading the text edits that occured to the metabase file. 
//
#define MD_ERROR_READING_TEXT_EDITS      0xC002C815L

//
// MessageId: MD_ERROR_APPLYING_TEXT_EDITS_TO_METABASE
//
// MessageText:
//
//  An error occured while applying text edits to the metabase.
//
#define MD_ERROR_APPLYING_TEXT_EDITS_TO_METABASE 0xC002C816L

//
// MessageId: MD_ERROR_APPLYING_TEXT_EDITS_TO_HISTORY
//
// MessageText:
//
//  An error occured while applying text edits to the history file.
//
#define MD_ERROR_APPLYING_TEXT_EDITS_TO_HISTORY 0xC002C817L

//
// MessageId: MD_ERROR_THREAD_THAT_PROCESS_TEXT_EDITS
//
// MessageText:
//
//  An error occured on the thread that processes text edits. The thread is being shut down and no further text edits will be processed. To restart the thread force a save of the metabase to disk after enabling edit while running, or restart the server.
//
#define MD_ERROR_THREAD_THAT_PROCESS_TEXT_EDITS 0xC002C818L

//
// MessageId: MD_ERROR_SHARING_VIOLATION
//
// MessageText:
//
//  Unable to read the edited file because of a sharing violation (tried 10 times). Check to see if it is write locked.
//
#define MD_ERROR_SHARING_VIOLATION       0xC002C819L

//
// MessageId: MD_ERROR_SAVING_APPLIED_TEXT_EDITS
//
// MessageText:
//
//  An error occured while saving the text edits that were applied to the metabase.
//
#define MD_ERROR_SAVING_APPLIED_TEXT_EDITS 0xC002C81AL

//
// MessageId: MD_ERROR_COPY_ERROR_FILE
//
// MessageText:
//
//  An error occured while processing text edits to the metabase file. But the erroneous file could not be copied into the history directory with the name errors appended to it.
//
#define MD_ERROR_COPY_ERROR_FILE         0xC002C81BL

//
// MessageId: MD_ERROR_UNABLE_TOSAVE_METABASE
//
// MessageText:
//
//  An error while saving the metabase file.
//
#define MD_ERROR_UNABLE_TOSAVE_METABASE  0xC002C81CL


#endif  // _MDMSG_H_

