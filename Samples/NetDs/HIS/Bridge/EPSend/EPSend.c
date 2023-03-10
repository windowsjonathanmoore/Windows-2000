/*//////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  MSMQ-MQSeries Bridge                                                                      //
//  Copyright (c) Microsoft Corporation.  All rights reserved.                                //
//                                                                                            //
//  PROGRAM: EPSend.c                                                                         //
//                                                                                            //
//  PURPOSE:                                                                                  //
//    Sends messages to MSMQ queue, filling in the MQMD extension field values.               //
//    MQMD.MsgType is set to MQMT_REPLY.                                                      //
//                                                                                            //
//  PARAMETERS:                                                                               //
//    2. MSMQ queue name to send to.                                                          //
//                                                                                            //
//////////////////////////////////////////////////////////////////////////////////////////////*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmqc.h>
#include <mq.h>
#include "MSMQExt.h"
#include "MQSRExt.h"

void Error(char *szFuncName, HRESULT hRes)
{
  printf("Error in %s: %X.\n", szFuncName, hRes);
  exit(1);
}



void main(unsigned int argc, char *argv[])
{
WCHAR wszFormatName[256], wszPathName[256];
HRESULT hRes;
DWORD dwSize;
QUEUEHANDLE hQueue;
MSGPROPID     PropIds[3] = { PROPID_M_LABEL, PROPID_M_BODY, PROPID_M_EXTENSION };
MQPROPVARIANT PropVars[3];
MQMSGPROPS    MsgProps = { 3, PropIds, PropVars, NULL };
char szBody[80], szLabel[80], szBuffer[1024];
char szQMName[48], szQName[48];
WCHAR wszLabel[80];
HANDLE hExt;
MQMD TheMQMD, MQMDDef = { MQMD_DEFAULT };

  /* check for queue name */
  if (argc != 2) {
    printf("Usage: EPSend <queue name>\n");
    return;
  }

  memset(szQMName, 0, sizeof(szQMName));
  memset(szQName, 0, sizeof(szQName));

  wsprintf((LPTSTR)wszPathName, TEXT("%S"), argv[1]);
  dwSize = 256;
  if((hRes = MQPathNameToFormatName(wszPathName, wszFormatName, &dwSize)) != MQ_OK)
    Error("MQPathNameToFormatName", hRes);
  
  if((hRes = MQOpenQueue(wszFormatName, MQ_SEND_ACCESS, 0, &hQueue)) != MQ_OK)
    Error("MQOpenQueue", hRes);
  
  printf("Queue opened.\n");

  printf("Reply Q Manager Name : "); gets(szQMName);
  printf("Reply Q Name : "); gets(szQName);

  while(1) {
    printf("------> Sending message (Use CTRL-C to stop).");
    printf("Label: ");  gets(szLabel);
    printf("Body: ");   gets(szBody);
	
    wsprintf((LPTSTR)wszLabel, TEXT("%S"), szLabel);
    PropVars[0].vt = VT_LPWSTR;  PropVars[0].pwszVal = wszLabel;
    PropVars[1].vt = VT_VECTOR|VT_UI1;
    PropVars[1].caub.cElems = strlen(szBody) + 1;
    PropVars[1].caub.pElems = szBody;


    memcpy(&TheMQMD, &MQMDDef, sizeof(MQMD));
    TheMQMD.MsgType = MQMT_REPLY;
	memcpy(TheMQMD.ReplyToQMgr, szQMName, sizeof(szQMName));
	memcpy(TheMQMD.ReplyToQ, szQName, sizeof(szQName));

    if((hRes = EPOpen(&hExt, NULL, 0)) != MQ_OK)
      Error("EPOpen", hRes);
    if((hRes = EPAdd(hExt, &sg_MSMQExtMQMD, &TheMQMD, sizeof(MQMD), NULL)) != MQ_OK)
      Error("EPAdd", hRes);
    dwSize = 1024;
    if((hRes = EPGetBuffer(hExt, szBuffer, &dwSize)) != MQ_OK)
      Error("EPGetBuffer", hRes);
    EPClose(&hExt);

    PropVars[2].vt = VT_VECTOR|VT_UI1;
    PropVars[2].caub.cElems = dwSize;
    PropVars[2].caub.pElems = szBuffer;

    if((hRes = MQSendMessage(hQueue, &MsgProps, NULL)) != MQ_OK)
      Error("MQSendMessage", hRes);
  }

  MQCloseQueue(hQueue);
  exit(0);
}
