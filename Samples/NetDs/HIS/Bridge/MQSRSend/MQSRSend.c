/*//////////////////////////////////////////////////////////////////////////////////////////////
//  MSMQ-MQSeries Bridge                                                                      //
//  Copyright (c) Microsoft Corporation.  All rights reserved.                                //
//                                                                                            //
//  PROGRAM: MQSRSend.c                                                                       //
//                                                                                            //
//  PURPOSE:                                                                                  //
//    Send 10 messages from IBM MQSeries using MQI channel.                                   //
//                                                                                            //
//  PARAMETERS:                                                                               //
//    1. MQSeries queue manager to connect (server side of the MQI channel).                  //
//    2. Destination queue manager for the message(s).                                        //
//    3. Destination queue name for the message(s).                                           //
//                                                                                            //
//////////////////////////////////////////////////////////////////////////////////////////////*/

#include <windows.h>
#include <stdio.h>
#include <cmqc.h>

void main( int argc, char *argv[]){
  DWORD     i;
  char      szMessage[256];
  MQLONG    lCompCode,lReason;
  MQHCONN   hConn;
  MQHOBJ    hQueue;
  MQOD      MqOd = {MQOD_DEFAULT};
  MQMD      MqMdDef = {MQMD_DEFAULT},MqMd;
  MQPMO     MqPmo = {MQPMO_DEFAULT};

  /* check for queue name */
  if (argc < 4) {
    printf("Usage: MQSRSend <server Qmngr> <queue manager name> <queue name>\n");
    return;
  }

  /* connect to queue manager */
  MQCONN(argv[1],&hConn,&lCompCode,&lReason); 
  if (lCompCode != MQCC_OK){
    printf("ERROR: MQCONN %s CC = %lu RS = %lu\n",argv[1],lCompCode,lReason);
    return;
  }

  /* Open the queue for send */
  strncpy(MqOd.ObjectName,argv[3],sizeof(MqOd.ObjectName));
  strncpy(MqOd.ObjectQMgrName,argv[2],sizeof(MqOd.ObjectQMgrName));
  MQOPEN(hConn,&MqOd,MQOO_OUTPUT,&hQueue,&lCompCode,&lReason); 
  if (lCompCode != MQCC_OK){
    printf("ERROR: MQOPEN QMNGR:%s QUEUE:%s CC = %lu RS = %lu\n",
            argv[1],argv[2],lCompCode,lReason);
    MQDISC(&hConn, &lCompCode, &lReason);
    return;
  }

  /* initialize put options */
  MqPmo.Options |= MQPMO_NO_SYNCPOINT;

  /* Send 10 messages */
  for (i = 0 ; i < 10 ; i++) {
    /* build message body */
    sprintf(szMessage,"Test Message %lu - ",i);
    GetTimeFormat((LCID)NULL,0,NULL,"HH':'mm':'ss",
      szMessage+strlen(szMessage),256-strlen(szMessage));
    /* initialize message descriptor */
    memmove(&MqMd,&MqMdDef,sizeof(MqMd));

    /* send the message */
    MQPUT(hConn,hQueue,&MqMd,&MqPmo,sizeof(szMessage),szMessage,&lCompCode,&lReason);
    if (lCompCode != MQCC_OK){
      printf("ERROR: MQPUT QMNGR:%s QUEUE:%s CC = %lu RS = %lu\n",
              argv[1],argv[2],lCompCode,lReason);
      MQDISC(&hConn, &lCompCode, &lReason);
      return;
    }

    /* print the sent message */
    printf("%s\n",szMessage);
  }
  MQDISC(&hConn, &lCompCode, &lReason);
}