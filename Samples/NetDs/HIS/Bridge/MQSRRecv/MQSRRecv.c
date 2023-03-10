/*//////////////////////////////////////////////////////////////////////////////////////////////
//  MSMQ-MQSeries Bridge                                                                      //
//  Copyright (c) Microsoft Corporation.  All rights reserved.                                //
//                                                                                            //
//  PROGRAM: MQSRRecv.c                                                                       //
//                                                                                            //
//  PURPOSE:                                                                                  //
//    Receive messages from IBM MQSeries queue using MQI channel.                             //
//                                                                                            //
//  PARAMETERS:                                                                               //
//    1. MQSeries queue manager to connect.                                                   //
//    2. MQSeries queue name (on the same queue manager) to receive from.                     //
//                                                                                            //
//////////////////////////////////////////////////////////////////////////////////////////////*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <cmqc.h>

void main(int argc, char *argv[]){
  PSTR      pszBuf = NULL;
  MQLONG    lCompCode,lReason,lBufferLength = 0,lDataLength;
  MQHCONN   hConn;
  MQHOBJ    hQueue;
  MQOD      MqOd = {MQOD_DEFAULT};
  MQMD      MqMdDef = {MQMD_DEFAULT},MqMd;
  MQGMO     MqGmo = {MQGMO_DEFAULT};
  MQCHAR48  szQMName;

  /* check for queue name */
  if (argc < 3) {
    printf("Usage: MQSRRecv <queue manager name> <queue name>\n");
    return;
  }

  /* connect to queue manager */
  strncpy(szQMName, argv[1], 48);
  MQCONN(szQMName,&hConn,&lCompCode,&lReason); 
  if (lCompCode != MQCC_OK){
    printf("ERROR: MQCONN %s CC = %lu RS = %lu\n",argv[1],lCompCode,lReason);
    return;
  }

  /* Open the queue for recieve */
  strncpy(MqOd.ObjectName,argv[2],sizeof(MqOd.ObjectName));
  strncpy(MqOd.ObjectQMgrName,argv[1],sizeof(MqOd.ObjectQMgrName));
  MQOPEN(hConn,&MqOd,MQOO_INPUT_SHARED,&hQueue,&lCompCode,&lReason); 
  if (lCompCode != MQCC_OK){
    printf("ERROR: MQOPEN QMNGR:%s QUEUE:%s CC = %lu RS = %lu\n",
            argv[1],argv[2],lCompCode,lReason);
    return;
  }

  printf("Use <CTL-C> to stop !\n");

  /* initialize put options */
  MqGmo.Options |= MQGMO_NO_SYNCPOINT | MQGMO_WAIT;
  MqGmo.WaitInterval = MQWI_UNLIMITED;

  /* receive all messages and print out */
  while (TRUE) {
    /* initialize message descriptor */
    memmove(&MqMd,&MqMdDef,sizeof(MqMd));
    /* receive message */
    MQGET(hConn,hQueue,&MqMd,&MqGmo,lBufferLength,pszBuf,&lDataLength,
      &lCompCode,&lReason);
    /* the buffer is too small for the message then realloc */
    if (lCompCode == MQCC_WARNING && lReason == MQRC_TRUNCATED_MSG_FAILED){
      if (pszBuf) free(pszBuf);
      pszBuf = malloc(lDataLength);
      lBufferLength = lDataLength;
    } else if (lCompCode != MQCC_OK){
      printf("ERROR: MQGET QMNGR:%s QUEUE:%s CC = %lu RS = %lu\n",
              argv[1],argv[2],lCompCode,lReason);
      return;
    } else {
      printf("%s\n", pszBuf);

    }
  }
}