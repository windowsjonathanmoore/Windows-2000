//******************************************************************************
//
//  Copyright (c) 1999, Microsoft Corporation
//
//  FILE: smscstat.h
//
//  This file defines C APIs that applications may use to report Microsoft
//  Systems Management Server (SMS) version 2.x status messages.  See note
//  below for the version of SMS 2.0 that supports this API. 
//
//  This file contains detailed instructions for using these APIs.  Please
//  review the comments further on in this file.
//
//  For general information about SMS 2.x and status messages, please see the
//  Microsoft Systems Management Server Administrator's Guide.  For more
//  information about these APIs, please see the Microsoft Systems Management
//  Server Software Development Kit (the SMS SDK).
//
//
//******************************************************************************

#ifndef _SMSCSTAT_H_
#define _SMSCSTAT_H_

#include <wtypes.h>

//******************************************************************************
//
//  Introduction
//  ============
//
//  In SMS 2.x, status messages are the universal means for components to
//  communicate information about their health to the SMS administrator.  Status
//  messages are similar to Windows NT Events; they have a severity, ID,
//  description, and so on.
//
//  The SMS 2.x Status System is a fully-distributed, enterprise-wide
//  aggregation and summarization system for status messages.  Status messages
//  flow from components to the SMS site servers and up the SMS site hierarchy.
//  The administrator configures how SMS processes the status messages at each
//  site server in the hierarchy.  This processing can include storing the
//  status messages in a SQL database, replicating the messages to the parent
//  SMS site, reporting the messages as Windows NT Events on the site server,
//  exporting the messages to another eventing or alerting application, and so
//  on.
//
//  Certain kinds of status messages are automatically processed by Summarizer
//  components running on the site servers.  The Summarizers produce high-level
//  data about the raw flows of status messages.  Administrators monitor this
//  data in the SMS Administrator console, which is a snap-in to the Microsoft
//  Management Console.
//
//  Administrators view SMS 2.x status messages stored in a SQL database using
//  the SMS Status Message Viewer.  This application is not an MMC snap-in; it
//  is a stand-alone application similar to the Windows NT Event Viewer.
//  Administrators define queries in the SMS Administrator console.  When the
//  query is executed, MMC starts the Status Message Viewer to display the
//  results.
//
//  The SMS 2.x status system is highly scalable.  It is designed to process
//  up to several million status messages per day in a high-performance,
//  properly-tuned SMS site hierarchy.  Only the largest site hierarchies
//  (having several hundred-thousand client machines) that aggressively use the
//  SMS software distribution features will ever see a load this size.
//
//  What is SMSCSTAT.DLL?
//  =====================
//
//  SMSCSTAT.DLL is a library of 32-bit C APIs for reporting SMS 2.x status
//  messages from an application running on an SMS client machine.  SMSCSTAT.DLL
//  will only be present and only function properly on Windows 9x, Windows NT,
//  and Windows 2000 machines that have the SMS client software installed on
//  them.
//
//  SMSCSTAT.DLL was first released with SMS 2.0 Service Pack 1 and will be
//  included in all following releases.  SMSCSTAT.DLL was not released with the
//  original SMS 2.0 release (build 1239).
//
//  The APIs exported by SMSCSTAT.DLL will not change in any future releases of
//  SMS 2.x.  Applications using SMSCSTAT.DLL will not be affected when the SMS
//  client software is upgraded to a future release.
//
//  How to access the status message reporting APIs exported by SMSCSTAT.DLL
//  ========================================================================
//
//  SMSCSTAT.DLL exists in the %windir%\ms\sms\core\bin directory.  Applications
//  should explicitly load SMSCSTAT.DLL using the Win32 LoadLibrary() API, and
//  then call Win32 GetProcAddress() to retrieve function pointers to the status
//  message APIs.  GetProcAddress() returns a pointer of type FARPROC.  For your
//  convenience, SMSCSTAT.H defines C function prototypes for the status message
//  APIs.  Your application should cast the pointer returned by GetProcAddress()
//  to the appropriate prototype and then call the function through the pointer.
//
//  As mentioned above, SMSCSTAT.DLL will not exist on SMS client machines that
//  have the original SMS 2.0 release installed on them.  Your application
//  should be prepared to deal with this.  If SMSCSTAT.DLL does not exist, Win32
//  LoadLibrary() will fail.  A subsequent call to Win32 GetLastError() will
//  return an error code indicating that the file does not exist.  (Most likely
//  this will be error 126: "The specified module could not be found.")
//
//  When your application is done using the status reporting APIs, use Win32
//  FreeLibrary() to unload SMSCSTAT.DLL.
//
//  Using the status message reporting APIs
//  =======================================
//
//  First create a status message object by calling the CreateSMSStatusMessage()
//  function.  This function will allocate an object and return a handle to the
//  caller.
//
//  Next, add any needed status message attributes to the object using the
//  AddAttributeToSMSStatusMessage() function.  Note: status message attributes
//  are optional and are only required if your application needs to integrate
//  with particular SMS features.  Most applications will not do this.
//
//  Next, call ReportSMSStatusMessage to submit the status message to the SMS
//  status system and deallocate the object.
//
//  For more information about these functions, see the documentation below for
//  each.
//
//==============================================================================
//
//  CreateSMSStatusMessage()
//
//  This function allocates a status message object, initializes it with the
//  caller's parameters, and returns a handle to it to the caller.
//
//  The caller should only call CreateSMSStatusMessage() at the exact moment
//  that the caller wants to report a status message.  This is because the
//  status message contains a time stamp that is set at creation time.
//
//  The caller supplies a pointer to a variable of type HANDLE.  On successful
//  exit, this function populates that variable with a handle to the status
//  message object.  On unsuccessful exit, the variable is left unchanged.  The
//  caller will use this handle when calling the other status message reporting
//  functions.  Note that the ONLY way to deallocate the object associated with
//  the handle is to call the ReportSMSStatusMessage() function, which will
//  submit the status message into the SMS status system.  The caller should NOT
//  pass this handle to Win32 CloseHandle() or any other similar function.
//
//  The caller supplies a status message "module name".  This is a null-
//  terminated, ASCII string representing the DLL that contains the display
//  string for the calling application's status messages.  The module name
//  is displayed in the SMS Status Message Viewer and the Windows NT Event
//  Viewer as the "Source" of the status message.  The module name is NOT the
//  name of the DLL.  Instead, the SMS Site Server contains a mapping of module
//  names to DLL names.  For example, the SMS client components report status
//  messages using the "SMS Client" module name.  The SMS Site Server knows that
//  "SMS Client" corresponds to the file CLIMSGS.DLL.  Please see the SMS SDK
//  documentation for more information about how to register a mapping of module
//  names to DLL names with the SMS Site Server.
//
//  The module name is not localizable to other languages.  This is because the
//  SMS administrator creates queries and filter rules based on the module name.
//  This assists the administrator in quickly retrieving just your status
//  messages and in configuring SMS to handle your status messages in special
//  ways.
//
//  The caller supplies a status message ID.  As part of the procedure for
//  instrumenting your application to report SMS status messages, you created a
//  .MC file that defined all of the messages.  When you compiled the .MC file,
//  a .H file was produced.  This .H file contains a #define for each status
//  message you defined.  You should supply the #define symbol here as the
//  message ID.  When the SMS Status Message Viewer or Windows NT Event Viewer
//  wants to display your message, it uses the message ID you supply here to
//  look up the message text in your DLL.
//
//  The caller supplies an optional Win32 error code returned by calling Win32
//  GetLastError().  When the SMS Status Message Viewer or Windows NT Event
//  Viewer displays the status message, it replaces insertion string 12 (%12) in
//  the status message with the following text:
//
//      The operating system reported error X: Y.
//
//  Where X is the error code supplied here and Y is the Win32 error text
//  associated with that error code.  For example, error code 5 is "Access is
//  deinied."  Callers typically supply a Win32 error code when they're
//  reporting a status message immediately following a Win32 API failure.  The
//  caller should supply zero to indicate to the status system that no Win32
//  error code is associated with the status message, in which case insertion
//  string 12 will be blank.
//
//  The caller supplies between zero and ten null-terminated, ASCII insertion
//  strings.  These strings correspond to the %1, %2, %3, etc., escape sequences
//  in the status message definition.  When the SMS Status Message Viewer or
//  Windows NT Event Viewer displays the status message, it replaces the escape
//  sequences with the values supplied to this function.  For example, if the
//  status message text is defined in the .MC file as:
//
//      %11Component Foo detected that service "%1" did not start.%0
//
//  the status system will replace %1 with insertion string #1 supplied to this
//  function.  (Note that %0 is not an insertion string, that the status system
//  uses %12 for an operating system error code, and that %11 is reserved but
//  required to be in all status messages.  Please see the SMS SDK documentation
//  for more information.)  If the caller is not using a particular insertion
//  string, the caller should supply NULL for it.
//
//  PARAMETERS:
//
//      PHANDLE phStatusMessageObject   Pointer to a variable to store the object handle.
//      LPCSTR  pszModuleName           Status message module name.
//      DWORD   dwID                    Status message ID.
//      DWORD   dwWin32Error            Win32 error code returned by GetLastError().
//      LPCSTR  pszInsStr1              Status message insertion string #1.
//      LPCSTR  pszInsStr2              Status message insertion string #2.
//      LPCSTR  pszInsStr3              Status message insertion string #3.
//      LPCSTR  pszInsStr4              Status message insertion string #4.
//      LPCSTR  pszInsStr5              Status message insertion string #5.
//      LPCSTR  pszInsStr6              Status message insertion string #6.
//      LPCSTR  pszInsStr7              Status message insertion string #7.
//      LPCSTR  pszInsStr8              Status message insertion string #8.
//      LPCSTR  pszInsStr9              Status message insertion string #9.
//      LPCSTR  pszInsStr10             Status message insertion string #10.
//
//  RETURNS:
//
//      SMSSTATMSG_SUCCESS              Object successfully created.
//
//      SMSSTATMSG_OUT_OF_MEMORY        This function failed to allocate enough
//                                      memory to create the object.
//
//      SMSSTATMSG_ERROR_INVALID_MODULE_NAME    The caller supplied NULL or a
//                                              string that exceeded
//                                              SMSSTATMSG_MAX_MODULE_NAME_LENGTH
//                                              characters in length for the
//                                              pszModuleName parameter.
//
//      STATMSG_ERROR_INVALID_INSSTR    The caller supplied a string that
//                                      exceeded SMSSTATMSG_MAX_INSSTR_LENGTH
//                                      characters in length for one of the
//                                      insertion string paramters.
//
//      SMSSTATMSG_ERROR_UNKNOWN        This function encountered an unknown
//                                      error while trying to create the object.
//
//==============================================================================
//
//  AddAttributeToSMSStatusMessage()
//
//  This function adds a single optional status message attribute ID/value pair
//  to a status message object.
//
//  All SMS status messages include a set of mandatory properties, such as the
//  name of the component that reported the message, the message ID, the time
//  the message was reported, the message's insertion strings, and so on.  These
//  mandatory properties are initialized when the object is created and by the
//  parameters passed into the status message reporting API functions.  In
//  addition to the mandatory properties, a status message has zero or more
//  "optional" properties associated with it.  Within the internals of the
//  status system, these optional properties are called "attribute ID/value
//  pairs", or simply "attributes".  In the SMS Status Message Viewer, these
//  optional properties appear in the "Properties" box when you double-click a
//  status message to bring up the Status Message Details box.
//
//  Attribute ID/value pairs are associated with status messages to facilitate
//  the construction of efficient status message queries.  For example, when any
//  SMS component reports a status message related to a particular SMS
//  Package (a software distribution object in SMS), the status message includes
//  the Package ID as an attribute ID/value pair.  The administrator can execute
//  a query to retrieve all of the status messages associated with the Package.
//  The status message tables in the SMS SQL database are indexed to allow
//  messages to be retrieved by attribute ID/value pairs very efficiently.
//
//  An attribute ID/value pair is composed of a DWORD as the attribute ID and a
//  null-terminated, ASCII string as the attribute value.  The attribute ID
//  specifies what the attribute value is.  The attribute value contains the
//  real data of interest.
//
//  The possible attribute IDs are defined by Microsoft and are listed below.
//  They also appear as #defines at the bottom of this file.  Microsoft may add
//  to this list in future SMS releases.
//
//  IMPORTANT NOTE: The possible attribute IDs currently all specify object
//  identifiers for SMS-specific objects associated with SMS's software
//  distribution features.  Unless your application is integrating with the SMS
//  software distribution functionality, it is HIGHLY UNLIKELY that it needs
//  to associate any attribute ID/value pairs with any of the status messages it
//  reports.  Therefore it is highly unlikely that your application will ever
//  need to call this function.
//
//  Attribute ID: SMSSTATMSG_ATTR_ID_PACKAGE_ID (400)
//
//      The attribute value is the eight character ID of an SMS Package.
//
//  Attribute ID: SMSSTATMSG_ATTR_ID_ADVERTISEMENT_ID (401)
//
//      The attribute value is the eight character ID of an SMS Advertisement.
//
//  Attribute ID: SMSSTATMSG_ATTR_ID_COLLECTION_ID (402)
//
//      The attribute value is the eight character ID of an SMS Collection.
//
//  Attribute ID: SMSSTATMSG_ATTR_ID_USER_NAME (403)
//
//      The attribute value is a Windows NT user name and domain of the form
//      "DOMAIN\username".  In situations where the domain is not available,
//      the attribute value takes the form simply of "username".
//
//  Attribute ID: SMSSTATMSG_ATTR_ID_DISTRIBUTION_POINT (404)
//
//      The attribute value is an SMS "NAL path" for an SMS Distribution Point.
//      Please see the SMS SDK documentation for the exact format of NAL paths.
//
//  PARAMETERS:
//
//      HANDLE hStatusMessageObject     Handle to the status message object.
//      DWORD  dwAttributeID            Status message attribute ID.
//      LPCSTR pszAttributeValue        Status message attribute value.
//
//  RETURNS:
//
//      SMSSTATMSG_SUCCESS              The attribute ID/value pair was
//                                      successfully added to the object.
//
//      SMSSTATMSG_OUT_OF_MEMORY        This function failed to allocate enough
//                                      memory to add the attribute ID/value
//                                      pair to the object.
//
//      STATMSG_ERROR_INVALID_ATTR_VALUE    The caller supplied NULL or a string
//                                          that exceeded
//                                          SMSSTATMSG_MAX_ATTR_VALUE_LENGTH
//                                          characters in length for the
//                                          pszAttributeValue parameter.
//
//      SMSSTATMSG_ERROR_MAX_ATTR_LIMIT The object already has
//                                      SMSSTATMSG_MAX_NUM_ATTRS attribute ID/
//                                      value pairs associated with it, which is
//                                      the maximum permitted number.
//
//      SMSSTATMSG_ERROR_UNKNOWN        This function encountered an unknown
//                                      error while trying to add the attribute
//                                      ID/value pair.
//
//==============================================================================
//
//  ReportSMSStatusMessage()
//
//  This function submits a status message object to the SMS status system and
//  then deallocates the object.
//
//  The caller supplied a handle of the status message to report; the handle is
//  returned by CreateSMSStatusMessage.  The caller should take care to supply a
//  valid handle.  The behavior of this function is undefined for invalid
//  handles; often this function will throw an access violation exception.
//
//  When this function returns, the supplied object is guaranteed to be
//  deallocated, whether or not this function was successful.  If the function
//  was unsuccessful and the caller wants to try again, the caller should create
//  a new status message before calling this function.
//
//  The caller supplies a null-terminated, ASCII component name.  This is the
//  name of the component reporting the status message.  This name appears in
//  the SMS Status Message Viewer in the "Component" column and in the Windows
//  NT Event Viewer in the "Category" column.
//
//  The component name is not localizable to other languages.  This is because
//  the SMS administrator creates queries and filter rules based on the
//  component name.  This assists the administrator in quickly retrieving just
//  your status messages and in configuring SMS to handle your status messages
//  in special ways.
//
//  The caller supplies a null-terminated, ASCII SMS site code.  SMS site codes
//  are exactly three characters long; please see the SMS documentation for more
//  information about site codes.  The site code parameter tells the status
//  system the SMS site to submit the message to.  The site code must be one of
//  the sites that the SMS client currently belongs to.  Normally, callers
//  should supply NULL for this parameter, indicating that the status message
//  should be reported to ALL SMS sites that the SMS client belongs to.
//
//  The caller supplies a null-terminated, ASCII SMS site code as the "top
//  level" site code.  The top level site code specifies the highest SMS site in
//  the site hierarchy that this message can be replicated to.  The status
//  system WILL STOP replication at that site no matter HOW the administrator
//  has configured the replication rules.  Normally, callers should supply NULL
//  for this parameter, indicating that there is no top level site code, and
//  that the message is free to replicate all the way to the top of the
//  hierarchy.  But if the caller has some special knowledge or reason to
//  prevent the replication past a certain site, the caller can supply the site
//  code of that site as this parameter.
//
//  PARAMETERS:
//
//      HANDLE hStatusMessageObject     Handle to the status message object.
//      LPCSTR pszComponentName         Name of the component reporting the status message.
//      LPCSTR pszSiteCode              Site code to report the status message to.
//      LPCSTR pszTopLevelSiteCode      Highest site in the hierarchy that this message can replicate to.
//
//  RETURNS:
//
//      SMSSTATMSG_SUCCESS              The object was successfully submitted to
//                                      the SMS status system.
//
//      SMSSTATMSG_ERROR_INVALID_COMPONENT_NAME The caller supplied NULL or a
//                                              string that exceeded
//                                              SMSSTATMSG_MAX_COMPONENT_NAME_LENGTH
//                                              characters in length for the
//                                              pszComponentName parameter.
//
//      SMSSTATMSG_ERROR_INVALID_SITE_CODE  The caller supplied a non-NULL,
//                                          invalid string for pszSiteCode.
//
//      SMSSTATMSG_ERROR_INVALID_TOP_LEVEL_SC  The caller supplied a non-NULL,
//                                             invalid string for
//                                             pszTopLevelSiteCode.
//
//      SMSSTATMSG_OUT_OF_MEMORY        This function failed to allocate enough
//                                      memory to submit the object to the SMS
//                                      status system.
//
//      SMSSTATMSG_ERROR_NOT_SMS_CLIENT This function was failed to submit the
//                                      object to the SMS status system because
//                                      the SMS client software is not properly
//                                      installed on this machine.
//
//      SMSSTATMSG_ERROR_UNKNOWN        This function encountered an unknown
//                                      error while trying to submit the object
//                                      to the SMS status system.
//
//******************************************************************************

//******************************************************************************
//
//  FUNCTION PROTOTYPES
//
//******************************************************************************

typedef DWORD (WINAPI *PROC_CREATESMSSTATUSMESSAGE)(PHANDLE phStatusMessageObject,
                                                    LPCSTR  pszModuleName,
                                                    DWORD   dwID,
                                                    DWORD   dwWin32Error,
                                                    LPCSTR  pszInsStr1,
                                                    LPCSTR  pszInsStr2,
                                                    LPCSTR  pszInsStr3,
                                                    LPCSTR  pszInsStr4,
                                                    LPCSTR  pszInsStr5,
                                                    LPCSTR  pszInsStr6,
                                                    LPCSTR  pszInsStr7,
                                                    LPCSTR  pszInsStr8,
                                                    LPCSTR  pszInsStr9,
                                                    LPCSTR  pszInsStr10);

typedef DWORD (WINAPI *PROC_ADDATTRIBUTETOSMSSTATUSMESSAGE)(HANDLE hStatusMessageObject,
                                                            DWORD  dwAttributeID,
                                                            LPCSTR pszAttributeValue);

typedef DWORD (WINAPI *PROC_REPORTSMSSTATUSMESSAGE)(HANDLE hStatusMessageObject,
                                                    LPCSTR pszComponentName,
                                                    LPCSTR pszSiteCode,
                                                    LPCSTR pszTopLevelSiteCode);

//******************************************************************************
//
//  CONSTANTS
//
//******************************************************************************

// Names of the functions exported by SMSCSTAT.DLL.  Your application should
// pass these to Win32 GetProcAddress().
// =========================================================================

#define PROCNAME_CREATESMSSTATUSMESSAGE         "CreateSMSStatusMessage"
#define PROCNAME_ADDATTRIBUTETOSMSSTATUSMESSAGE "AddAttributeToSMSStatusMessage"
#define PROCNAME_REPORTSMSSTATUSMESSAGE         "ReportSMSStatusMessage"

// Maximum lengths, in characters, of strings passed to the functions exported
// by SMSCSTAT.DLL.
// ===========================================================================

#define SMSSTATMSG_MAX_MODULE_NAME_LENGTH       127
#define SMSSTATMSG_MAX_INSSTR_LENGTH            255
#define SMSSTATMSG_MAX_ATTR_VALUE_LENGTH        255
#define SMSSTATMSG_MAX_COMPONENT_NAME_LENGTH    127

// Error codes returned by the functions exported by SMSCSTAT.DLL.  For the
// exact meanings of these codes, please see the documentation above for each
// function.
// ==========================================================================

#define SMSSTATMSG_SUCCESS                      0
#define SMSSTATMSG_OUT_OF_MEMORY                1
#define SMSSTATMSG_ERROR_INVALID_MODULE_NAME    2
#define SMSSTATMSG_ERROR_INVALID_SITE_CODE      3
#define SMSSTATMSG_ERROR_INVALID_TOP_LEVEL_SC   4
#define SMSSTATMSG_ERROR_INVALID_COMPONENT_NAME 5
#define SMSSTATMSG_ERROR_INVALID_INSSTR         6
#define SMSSTATMSG_ERROR_INVALID_ATTR_VALUE     7
#define SMSSTATMSG_ERROR_MAX_ATTR_LIMIT         8
#define SMSSTATMSG_ERROR_NOT_SMS_CLIENT         9
#define SMSSTATMSG_ERROR_UNKNOWN                10

// Reserved module names.  These names are used by SMS components; your
// application should not supply any of these as the pszModuleName parameter to
// the CreateSMSStatusMessage() function.
// ============================================================================

#define SMSSTATMSG_SERVER_MODULE_NAME           "SMS Server"
#define SMSSTATMSG_CLIENT_MODULE_NAME           "SMS Client"
#define SMSSTATMSG_PROVIDER_MODULE_NAME         "SMS Provider"

// Currently-defined attribute IDs.  Please see the documentation for the
// AddAttributeToSMSStatusMessage() function above for more information.
// ======================================================================

#define SMSSTATMSG_ATTR_ID_PACKAGE_ID           400
#define SMSSTATMSG_ATTR_ID_ADVERTISEMENT_ID     401
#define SMSSTATMSG_ATTR_ID_COLLECTION_ID        402
#define SMSSTATMSG_ATTR_ID_USER_NAME            403
#define SMSSTATMSG_ATTR_ID_DISTRIBUTION_POINT   404

// Maximum number attributes associated with a single status message.  Please
// see the documentation for the AddAttributeToSMSStatusMessage() function above
// for more information.
// =============================================================================

#define SMSSTATMSG_MAX_NUM_ATTRS                1000

#endif //_SMSCSTAT_H_

