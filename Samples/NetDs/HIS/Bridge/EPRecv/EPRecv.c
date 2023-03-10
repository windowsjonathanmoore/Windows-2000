/*//////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  MSMQ-MQSeries Bridge                                                                      //
//  Copyright (c) Microsoft Corporation.  All rights reserved.                                //
//                                                                                            //
//  PROGRAM: EPRecv.c                                                                         //
//                                                                                            //
//  PURPOSE:                                                                                  //
//    Receives messages from MSMQ queue, prints extension fields values.                      //
//    Recognizes and prints MQMD structure, if it's stored in PROPID_M_EXTENSION.             //
//                                                                                            //
//  PARAMETERS:                                                                               //
//    2. MSMQ queue name to receive from.                                                     //
//                                                                                            //
/////////////////////////////////////////////////////////////////////////////////////////////*/

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

void DumpByteField(BYTE *pField, DWORD dwSize)
{
DWORD i;
  for(i=0; i<dwSize; i++) {
    printf("%02X", pField[i]);
    if(i%8==7 && i<dwSize-1) printf(" ");
  }
}

void DumpGUID(GUID *pGUID)
{
  printf("{%08X-%04X-%04X-%04X-%02X%02X%02X%02X%02X%02X}",
         pGUID->Data1, pGUID->Data2, pGUID->Data3, *(WORD *)pGUID->Data4,
         pGUID->Data4[2], pGUID->Data4[3], pGUID->Data4[4],
         pGUID->Data4[5], pGUID->Data4[6], pGUID->Data4[7]);
}

void DumpCharField(char *pField, DWORD dwSize)
{
char s[80];
  memcpy(s, pField, dwSize);  s[dwSize] = '\0';
  printf("%s", s);
}

void DumpExtensionProperty(DWORD dwSize, void *pExtBuffer)
{
HANDLE hExt;
HANDLE hCursor;
HRESULT hRes;
BYTE *pField;
MQMD1 *pMQMD1;
MQMDE *pMQMDE;
DWORD dwFieldSize;
GUID FieldGUID;
  if((hRes = EPOpen(&hExt, pExtBuffer, dwSize)) != MQ_OK)
    Error("EPOpen", hRes);

  hCursor = NULL;
  while((hRes = EPGet(hExt, EP_NEXT_FIELD, &hCursor, NULL, NULL, &dwFieldSize)) == MQ_OK) {
    pField = malloc(dwFieldSize);
    if((hRes = EPGet(hExt, EP_CURRENT_FIELD, &hCursor, &FieldGUID, pField, &dwFieldSize)) != MQ_OK)
      Error("EPGet", hRes);

    if(!memcmp(&FieldGUID, &sg_MSMQExtMQMD, sizeof(GUID)))
	{
      pMQMD1 = (MQMD1 *)pField;
      printf("    MQMD1 Extension Field found.  Dumping values:\n"
             "        MQMD1.Report = %08X   MQMD1.MsgType = %08X\n"
             "        MQMD1.Feedback = %08X   MQMD1.Priority = %d\n",
                 pMQMD1->Report, pMQMD1->MsgType, pMQMD1->Feedback, pMQMD1->Priority);
	  printf("        MQMD1.Version = %08X  MQMD1.Expiry = %d\n", pMQMD1->Version, pMQMD1->Expiry);

      printf("        MQMD1.ReplyToQMgr = '");       DumpCharField(pMQMD1->ReplyToQMgr, 48);       printf("'\n");
      printf("        MQMD1.ReplyToQ    = '");       DumpCharField(pMQMD1->ReplyToQ,    48);       printf("'\n");
      printf("        MQMD1.UserIdentifier = '");    DumpCharField(pMQMD1->UserIdentifier, 12);    printf("'\n");
      printf("        MQMD1.ApplIdentityData = '");  DumpCharField(pMQMD1->ApplIdentityData, 12);  printf("'\n");
      printf("        MQMD1.PutApplName = '");       DumpCharField(pMQMD1->PutApplName, 12);       printf("'\n");
      printf("        MQMD1.PutDate = '");           DumpCharField(pMQMD1->PutDate, 8);            printf("'\n");
      printf("        MQMD1.PutTime = '");           DumpCharField(pMQMD1->PutTime, 8);            printf("'\n");
      printf("        MQMD1.MsgId = '");             DumpByteField(pMQMD1->MsgId, 24);             printf("'\n");
      printf("        MQMD1.CorrelId = '");          DumpByteField(pMQMD1->CorrelId, 24);          printf("'\n");
    } 
	else if(!memcmp(&FieldGUID, &sg_MSMQExtMQMDE, sizeof(GUID)))
	{
      pMQMDE = (MQMDE *)pField;
      printf("    MQMDE Extension Field found.  Dumping values:\n");
	  printf("        MQMDE.StrucId = '");       DumpCharField(pMQMDE->StrucId, 4);       printf("'\n");
	  printf("        MQMDE.Version = %08X\n", pMQMDE->Version);
	  printf("        MQMDE.StrucLength = %08X\n", pMQMDE->StrucLength);
	  printf("        MQMDE.Encoding = %08X\n", pMQMDE->Encoding);
	  printf("        MQMDE.CodedCharSetId = %08X\n", pMQMDE->CodedCharSetId);
	  printf("        MQMDE.Format = '");    DumpCharField(pMQMDE->Format, 8);    printf("'\n");
	  printf("        MQMDE.Flag = '");    DumpByteField(pMQMDE->Format, 4);    printf("'\n");
      printf("        MQMDE.GroupId = '");    DumpByteField(pMQMDE->GroupId, 24);    printf("'\n");
	  printf("        MQMDE.MsgSeqNumber = %08X\n", pMQMDE->MsgSeqNumber);
	  printf("        MQMDE.Offset = %08X\n", pMQMDE->Offset);
	  printf("        MQMDE.MsgFlags = %08X\n", pMQMDE->MsgFlags);
	  printf("        MQMDE.OriginalLength = %08X\n", pMQMDE->OriginalLength);
    } 
	else 
	{
      printf("    Unknown Field: ");  DumpGUID(&FieldGUID);  printf("\n");
      printf("        Data = '");  DumpByteField(pField, dwFieldSize);  printf("'\n");
    }

    free(pField);
  }

  if(hRes != MQ_ERROR_EXTENSION_FIELD_NOT_FOUND)
    Error("EPGet", hRes);

  EPClose(&hExt);
}

void main(unsigned int argc, char *argv[])
{
WCHAR wszFormatName[256], wszPathName[256];
HRESULT hRes;
QUEUEHANDLE hQueue;
MSGPROPID     PropIds[7] = { PROPID_M_LABEL, PROPID_M_LABEL_LEN, PROPID_M_BODY, PROPID_M_BODY_SIZE, PROPID_M_EXTENSION, PROPID_M_EXTENSION_LEN, PROPID_M_BODY_TYPE };
MQPROPVARIANT PropVars[7];
HRESULT       PropStatus[7];
MQMSGPROPS    MsgProps = { 7, PropIds, PropVars, PropStatus };
WCHAR			wszLabel[256];
char			szBody[256], szExt[1024];
PBYTE			pBuffer=NULL;
DWORD			dwSize;
DWORD			dwMsgSize=0;

  /* check for queue name */
  if (argc != 2) {
    printf("Usage: EPRecv <queue name>\n");
    return;
  }

  wsprintf((LPTSTR)wszPathName, TEXT("%S"), argv[1]);
  dwSize = 256;
  if((hRes = MQPathNameToFormatName(wszPathName, wszFormatName, &dwSize)) != MQ_OK)
    Error("MQPathNameToFormatName", hRes);
  
  if((hRes = MQOpenQueue(wszFormatName, MQ_RECEIVE_ACCESS, MQ_DENY_RECEIVE_SHARE, &hQueue)) != MQ_OK)
    Error("MQOpenQueue", hRes);
  
  printf("Queue opened.\n" 
         "Waiting for messages to arrive.\n"
         "Use CTLR-C to stop.\n");

  while(1) {
    PropVars[0].vt = VT_LPWSTR;
    PropVars[0].pwszVal = wszLabel;
    PropVars[1].vt = VT_UI4;
    PropVars[1].ulVal = 256;
    PropVars[2].vt = VT_UI1|VT_VECTOR;
    PropVars[2].caub.cElems = 256;
    PropVars[2].caub.pElems = szBody;
    PropVars[3].vt = VT_UI4;
    PropVars[3].ulVal = 256;
    PropVars[4].vt = VT_UI1|VT_VECTOR;
    PropVars[4].caub.cElems = 1024;
    PropVars[4].caub.pElems = szExt;
    PropVars[5].vt = VT_UI4;
    PropVars[5].ulVal = 1024;
	PropVars[6].vt = VT_UI4;

    if((hRes = MQReceiveMessage(hQueue, INFINITE, MQ_ACTION_RECEIVE, &MsgProps, NULL, NULL, NULL, NULL)) != MQ_OK)
      Error("MQReceiveMessage", hRes);

    printf("-------> Message arrived:\n");

	if(dwMsgSize < PropVars[3].ulVal+1)
	{
		if(pBuffer)
		{
			LocalFree(pBuffer);
		}

		pBuffer = (PBYTE)LocalAlloc(LPTR, PropVars[3].ulVal+1);

		if(pBuffer)
		{
			dwMsgSize = PropVars[3].ulVal+1;
		}
		else
			dwMsgSize = 0;
	}

	if(pBuffer)
	{
		memcpy(pBuffer, PropVars[2].caub.pElems, PropVars[3].ulVal);
		*(pBuffer+PropVars[3].ulVal) = 0;	// Null termination
	}

    printf("Label = '%S'\n", PropVars[0].pwszVal);
    printf("Body (%d) = '%s'\n", PropVars[3].ulVal, pBuffer);
	printf("Body Type (%d) %s\n", PropVars[6].ulVal, (PropVars[6].ulVal == VT_BSTR)?"VT_BSTR":"");
	

    if(PropVars[5].ulVal) {
      printf("Extension property found.  Dumping values:\n");
      DumpExtensionProperty(PropVars[5].ulVal, PropVars[4].caub.pElems);
    }

    printf("\n");
  }

  MQCloseQueue(hQueue);
  exit(0);
}
