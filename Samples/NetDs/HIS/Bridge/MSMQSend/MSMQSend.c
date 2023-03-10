/*//////////////////////////////////////////////////////////////////////////////////////////////
//  MSMQ-MQSeries Bridge                                                                      //
//  Copyright (c) Microsoft Corporation.  All rights reserved.                                //
//                                                                                            //
//  PROGRAM: MSMQSend.c                                                                       //
//                                                                                            //
//  PURPOSE:                                                                                  //
//    Send 10 messages from Microsoft MSMQ.                                                   //
//                                                                                            //
//  PARAMETERS:                                                                               //
//    1. Destination machine name.                                                            //
//    2. Destination queue name.                                                              //
//                                                                                            //
//////////////////////////////////////////////////////////////////////////////////////////////*/

#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#include <mq.h>

void main(int argc, char *argv[]){
  HRESULT       hRes;
  QUEUEHANDLE   hQueue;
  WCHAR         wszFormatName[256];
  DWORD         dwFormatNameLen = 256,i;
  char          szMessage[256];
  WCHAR         wszArgv[256];
  MSGPROPID     aPropID[1] = {PROPID_M_BODY};
  MQPROPVARIANT aPropVar[1] = {{VT_VECTOR|VT_UI1,0,0,0,0}} ;
  MQMSGPROPS    MessageProps = {1,aPropID,aPropVar,NULL};

  /* check for queue name */
  if (argc < 2) {
    wprintf(L"Usage: MSMQSend <machine name>\\<queue name>\n");
    return;
  }
  mbstowcs(wszArgv,argv[1], strlen(argv[1])+1);

  /* get the queue format name */
  hRes = MQPathNameToFormatName(wszArgv,wszFormatName,&dwFormatNameLen);
  if (hRes != MQ_OK) {
    wprintf(L"ERROR: MQPathNameToFormatName %s RC = %p\n",wszArgv,hRes);
    return;
  }

  /* Open the queue for send */
  hRes = MQOpenQueue(wszFormatName,MQ_SEND_ACCESS,0,&hQueue);
  if (hRes != MQ_OK) {
    wprintf(L"ERROR: MQOpenQueue %s RC = %p\n",wszArgv,hRes);
    return;
  }

  /* initialize message body property */
  aPropVar[0].caub.pElems = (PBYTE)szMessage;
  aPropVar[0].caub.cElems = sizeof(szMessage);

  /* Send 10 messages */
  for (i = 0 ; i < 10 ; i++) {
    /* build message body */
    sprintf(szMessage,"Test Message %lu - ",i);
    GetTimeFormat((LCID)NULL,0,NULL,"HH':'mm':'ss",
      szMessage+strlen(szMessage),256-strlen(szMessage));

    /* send the message */
    hRes = MQSendMessage(hQueue,&MessageProps,NULL);

    if (hRes != MQ_OK) {
        wprintf(L"MQSendMessage failed for queue %s RC = %p\n",wszArgv,hRes);
        return;
    }

    /* print the sent message */
    printf("%s\n",szMessage);
  }
}