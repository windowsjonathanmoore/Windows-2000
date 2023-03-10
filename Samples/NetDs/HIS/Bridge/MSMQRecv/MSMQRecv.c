/*//////////////////////////////////////////////////////////////////////////////////////////////
//  MSMQ-MQSeries Bridge                                                                      //
//  Copyright (c) Microsoft Corporation.  All rights reserved.                                //
//                                                                                            //
//  PROGRAM: MSMQRecv.c                                                                       //
//                                                                                            //
//  PURPOSE:                                                                                  //
//    Receive messages from Microsoft MSMQ queue.                                             //
//                                                                                            //
//  PARAMETERS:                                                                               //
//    1. Source machine name.                                                                 //
//    2. Source queue name.                                                                   //
//                                                                                            //
//////////////////////////////////////////////////////////////////////////////////////////////*/

#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#include <mq.h>

void main( int argc, char *argv[]){
  HRESULT       hRes;
  QUEUEHANDLE   hQueue;
  WCHAR         wszArgv[256];
  WCHAR         wszFormatName[256];
  DWORD         dwFormatNameLen = 256;
  MSGPROPID     aPropID[2] = {PROPID_M_BODY,PROPID_M_BODY_SIZE};
  MQPROPVARIANT aPropVar[2] = {{VT_VECTOR|VT_UI1,0,0,0,0},{VT_UI4,0,0,0,0}} ;
  MQMSGPROPS    MessageProps = {2,aPropID,aPropVar,NULL};

  /* check for queue name */
  if (argc < 2) {
    printf("Usage: MSMQRecv <machine name>\\<queue name>\n");
    return;
  }
  mbstowcs(wszArgv,argv[1], strlen(argv[1])+1);

  /* get the queue format name */
  hRes = MQPathNameToFormatName(wszArgv,wszFormatName,&dwFormatNameLen);
  if (hRes != MQ_OK) {
    wprintf(L"ERROR: MQPathNameToFormatName %s RC = %p\n",wszArgv,hRes);
    return;
  }

  /* Open the queue for recieve */
  hRes = MQOpenQueue(wszFormatName,MQ_RECEIVE_ACCESS,0,&hQueue);
  if (hRes != MQ_OK) {
    wprintf(L"ERROR: MQOpenQueue %s RC = %p\n",wszArgv,hRes);
    return;
  }

  printf("Use <CTL-C> to stop !\n");

  /* receive all messages and print out */
  while (TRUE) {
    hRes = MQReceiveMessage(hQueue,INFINITE,MQ_ACTION_RECEIVE,
      &MessageProps,NULL,NULL,NULL,NULL);
    /* the buffer is too small for the message then realloc */
    if (hRes == MQ_ERROR_BUFFER_OVERFLOW) {
      if (aPropVar[0].caub.pElems) free(aPropVar[0].caub.pElems);
      aPropVar[0].caub.pElems = malloc(aPropVar[1].ulVal);
      aPropVar[0].caub.cElems = aPropVar[1].ulVal;
    } else if (hRes != MQ_OK) {
        wprintf(L"MQReceiveMessage failed for queue %s RC = %p\n",wszArgv,hRes);
        return;
    } else {
      printf("%s\n",aPropVar[0].caub.pElems);
    }
  }
}