/******************************************************************************\
*       This is a part of the Microsoft Source Code Samples.
*       Copyright (C) 1999 Microsoft Corporation.
*       All rights reserved.
*       This source code is only intended as a supplement to
*       Microsoft Development Tools and/or WinHelp documentation.
*       See these sources for detailed information regarding the
*       Microsoft samples programs.
\******************************************************************************/


//
// Includes
//
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>

#include <mq.h>
#include <mqmail.h>
//
//helper macro to define MQ props
//
#define SizedMQProps(_QUEUE_or_MSG_, _cProps_, _Name_)			\
    _QUEUE_or_MSG_##PROPID	_Name_##rgPropID[_cProps_];			\
    MQPROPVARIANT			_Name_##rgPropVar[_cProps_];		\
    HRESULT					_Name_##rgStatus[_cProps_];			\
    MQ##_QUEUE_or_MSG_##PROPS	_Name_ =						\
     {0, _Name_##rgPropID, _Name_##rgPropVar, _Name_##rgStatus}

char * szBookList = "Lonely Hearts, Arthur C. Van Haven, NorthStar & co.\r\n"
    				"Magnetic Forces, Nathan Axelrod, Science Inc.\r\n"
    				"Dual Balance, Big John Array, Marshal & Sons\r\n"
    				"Bake It!, Sarah McBarney, Spoon Publishers\r\n";

char * szBookListInStock =
    				"Magnetic Forces, Nathan Axelrod, Science Inc.\r\n"
    				"Bake It!, Sarah McBarney, Spoon Publishers\r\n";
//
// Various defines
//
#define BOOKSRVR_MSG_INIT_BUFSIZE			10000
#define BOOKSRVR_RE_SUBJECT_INIT_BUFSIZE	200
#define MAX_VAR                             10
#define MAX_FMTNAME                         512
#define MAX_QPATH                           512


//
//control structure
//
typedef struct BOOKSRVR_tag
{
    /* store command line arguments     */  int			argc;
                                            char **		argv;
    /* input queue label                */  char *		szQLabelIn;
    /* a handle to the thread 
       synchronization event            */  HANDLE		hToExitEvent;
    /* a handle to the receive queue    */  QUEUEHANDLE	hQueue;
    /* a handle to the async 
       receive event                    */  HANDLE		hRcvEvent;
    /* received message buffer size     */  ULONG		cbBuffer;
    /* received message buffer          */  LPBYTE		lpbBuffer;
                                            OVERLAPPED	sOverlapped;
                                            LPMQMailEMail	pEMail;
    /* reply message subject size       */  ULONG		cbReSubject;
    /* reply message subject            */  char *		pszReSubject;
    /* reply message body size          */  ULONG		cbRetBuffer;
    /* reply message body               */  LPBYTE		lpbRetBuffer;
                                            QUEUEHANDLE	hSendQueue;
} BOOKSRVR, *LPBOOKSRVR;


//
//create unicode string from ansi
//
BOOL FCreateUnicodeStr(LPSTR pszAnsi, LPWSTR * ppwszUnicode)
{
    LPWSTR pwszUnicode;
    int cchUnicode;

    //alloc unicode string
    cchUnicode = strlen(pszAnsi) + 1;
    pwszUnicode = (LPWSTR)malloc(cchUnicode*sizeof(WCHAR));
    if (pwszUnicode == NULL)
    {
    	printf("Error %lx allocating unicode string\n", GetLastError());
    	return(FALSE);
    }

    //convert to unicode
    if (!MultiByteToWideChar(CP_ACP, 0, pszAnsi, -1, pwszUnicode, cchUnicode))
    {
    	printf("Error %lx in MultiByteToWideChar\n", GetLastError());
    	free(pwszUnicode);
    	return(FALSE);
    }
    
    //return unicode string
    *ppwszUnicode = pwszUnicode;
    return(TRUE);
}


LPMQMailFormField lpFindFieldByName(LPMQMailEMail pEMail,
    								char * pszName,
    								MQMailFormFieldType iType)
{
    ULONG ulTmp;
    BOOL fNotFound;
    LPMQMailFormField lpField;

    for (ulTmp = 0, fNotFound = TRUE;
    	 (ulTmp < pEMail->form.pFields->cFields) && fNotFound;
    	 ulTmp++)
    {		
    	lpField = pEMail->form.pFields->apField[ulTmp];
    	if ((strcmpi(lpField->szName, pszName) == 0) &&
    		(lpField->iType == iType))
    	{
    		fNotFound = FALSE;
    	}
    }

    if (fNotFound)
    	return(NULL);
    else
    	return(lpField);
}


enum
{
    LOCATE_Q_INSTANCE,
    COUNT_LOCATE_PROPS
};



BOOL FOpenQueueByLabel(LPBOOKSRVR pBookSrvr, LPSTR szQLabel, DWORD dwAccess, QUEUEHANDLE * phQueue)
{
    HRESULT hr;
    MQRESTRICTION res;
    MQPROPERTYRESTRICTION aresToAnd[2];
    MQCOLUMNSET sColSet;
    PROPID rgPropSpec[COUNT_LOCATE_PROPS];
    MQPROPVARIANT rgPropVar[COUNT_LOCATE_PROPS];
    ULONG ulTmp;
    CLSID clsidQueue;
    WCHAR wszFmtName[MAX_FMTNAME];
    DWORD cFmtName = MAX_FMTNAME * sizeof(WCHAR);
    CLSID clsidFalc = CLSID_MQMailQueueType;
    DWORD cProps;
    LPWSTR pwszUnicodeQLabel;
    HANDLE hEnum;

    //create unicode string for locate
    if (!FCreateUnicodeStr(szQLabel, &pwszUnicodeQLabel))
    	return(FALSE);

    // Restriction for locate - Label==pszQLabel & Type==CLSID_MQMailQueueType
    aresToAnd[0].rel = PREQ;
    aresToAnd[0].prop = PROPID_Q_LABEL;
    aresToAnd[0].prval.vt = VT_LPWSTR;
    aresToAnd[0].prval.pwszVal = pwszUnicodeQLabel;
    aresToAnd[1].rel = PREQ;
    aresToAnd[1].prop = PROPID_Q_TYPE;
    aresToAnd[1].prval.vt = VT_CLSID;
    aresToAnd[1].prval.puuid = &clsidFalc;
    res.cRes = 2;
    res.paPropRes = aresToAnd;

    // Columns for locate
    rgPropSpec[0] = PROPID_Q_INSTANCE;
    sColSet.cCol = COUNT_LOCATE_PROPS;
    sColSet.aCol = rgPropSpec;

    //locate
    hr = MQLocateBegin(NULL, &res, &sColSet, NULL, &hEnum);
    if (FAILED(hr))
    {
    	printf("Error %lx in MQLocateBegin\n", hr);
    	free(pwszUnicodeQLabel);
    	return(FALSE);
    }

    //prepare for locate next
    cProps = COUNT_LOCATE_PROPS;
    for (ulTmp = 0; ulTmp < COUNT_LOCATE_PROPS; ulTmp++)
    	rgPropVar[ulTmp].vt = VT_NULL;

    //locate next
    hr = MQLocateNext(hEnum, &cProps, rgPropVar);
    if (FAILED(hr))
    {
    	printf("Error %lx in MQLocateNext\n", hr);
    	MQLocateEnd(hEnum);
    	free(pwszUnicodeQLabel);
    	return(FALSE);
    }

    //check if queue was found
    if (cProps != COUNT_LOCATE_PROPS)
    {
    	MQLocateEnd(hEnum);
    	free(pwszUnicodeQLabel);
    	return(FALSE);
    }

    //get clsid and free resources
    memcpy(&clsidQueue, rgPropVar[LOCATE_Q_INSTANCE].puuid, sizeof(CLSID));
    MQFreeMemory(rgPropVar[LOCATE_Q_INSTANCE].puuid);
    MQLocateEnd(hEnum);
    free(pwszUnicodeQLabel);

    //convert clsid to format name for MQOpenQueue
    hr = MQInstanceToFormatName(&clsidQueue, wszFmtName, &cFmtName);
    if (FAILED(hr))
    {
    	printf("Error %lx in MQInstanceToFormatName\n", hr);
    	return(FALSE);
    }
    
    //open queue
    hr = MQOpenQueue(wszFmtName, dwAccess, 0, phQueue);
    if (FAILED(hr))
    {
    	printf("Error %lx in MQOpenQueue\n", hr);
    	return(FALSE);
    }

    return(TRUE);
}



enum
{
    CREATE_Q_LABEL,
    CREATE_Q_TYPE,
    CREATE_Q_PATHNAME,
    COUNT_CREATE_Q_PROPS
};


BOOL FCreateQueue(LPBOOKSRVR pBookSrvr, LPSTR szQLabel)
{
    HRESULT hr;
    SizedMQProps(QUEUE, COUNT_CREATE_Q_PROPS, sCreateQProps);
    WCHAR wszUnicodeComputerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD dwTmp = MAX_COMPUTERNAME_LENGTH;
    WCHAR wszUnicodeQPath[MAX_QPATH + 1];
    LPWSTR pwszUnicodeQLabel;
CLSID clsidFalc = CLSID_MQMailQueueType;
    WCHAR wszFmtName[MAX_FMTNAME];
    DWORD cFmtName = MAX_FMTNAME;

    wcscpy(wszUnicodeComputerName, L".");
    
    //create unicode queue label
    if (!FCreateUnicodeStr(szQLabel, &pwszUnicodeQLabel))
    	return(FALSE);

    //Falcon queue path is <machine-name>\<queue-name>
    swprintf(wszUnicodeQPath, L"%s\\%s",
    			wszUnicodeComputerName, pwszUnicodeQLabel);

    //fill props
    sCreateQProps.cProp = COUNT_CREATE_Q_PROPS;
    sCreateQProps.aPropID[CREATE_Q_LABEL] = PROPID_Q_LABEL;
    sCreateQProps.aPropVar[CREATE_Q_LABEL].vt = VT_LPWSTR;
    sCreateQProps.aPropVar[CREATE_Q_LABEL].pwszVal = pwszUnicodeQLabel;
    sCreateQProps.aPropID[CREATE_Q_TYPE] = PROPID_Q_TYPE;
    sCreateQProps.aPropVar[CREATE_Q_TYPE].vt = VT_CLSID;
    sCreateQProps.aPropVar[CREATE_Q_TYPE].puuid = &clsidFalc;
    sCreateQProps.aPropID[CREATE_Q_PATHNAME] = PROPID_Q_PATHNAME;
    sCreateQProps.aPropVar[CREATE_Q_PATHNAME].vt = VT_LPWSTR;
    sCreateQProps.aPropVar[CREATE_Q_PATHNAME].pwszVal = wszUnicodeQPath;

    //create queue
    hr = MQCreateQueue(NULL, &sCreateQProps, wszFmtName, &cFmtName);
    free(pwszUnicodeQLabel);
    if (FAILED(hr))
    {
    	printf("Error %lx in MQCreateQueue\n", hr);
    	return(FALSE);
    }
    
    return(TRUE);
}

BOOL FOpenCreateQueueByLabel(
                 LPBOOKSRVR pBookSrvr,
                 LPSTR szQLabel,
                 DWORD dwAccess,
                 QUEUEHANDLE * phQueue
                 )
{
    //try to open the queue
    if (!FOpenQueueByLabel(pBookSrvr, szQLabel, dwAccess, phQueue))
    {
    	//open failed, create it, and try to open again
    	if (FCreateQueue(pBookSrvr, szQLabel))
    		return(FOpenQueueByLabel(pBookSrvr, szQLabel, dwAccess, phQueue));
    	else //create failed
    		return(FALSE);
    }

    return(TRUE);
}
    
enum
{
    SEND_M_BODY,
    SEND_M_DELIVERY,
    COUNT_SEND_M_PROPS
};


//
//send body to sender queue
//
BOOL FSendBody(LPBOOKSRVR pBookSrvr, ULONG cbBuffer, LPBYTE lpbBuffer, LPSTR szQueueLabel)
{
    HRESULT hr;
    SizedMQProps(MSG, COUNT_SEND_M_PROPS, sSendMsgProps);

    //open queue for send
    if (!FOpenQueueByLabel(pBookSrvr, szQueueLabel, MQ_SEND_ACCESS, &pBookSrvr->hSendQueue))
    	return(FALSE);

    sSendMsgProps.cProp = COUNT_SEND_M_PROPS;
    // Body
    sSendMsgProps.aPropID[SEND_M_BODY] = PROPID_M_BODY;
    sSendMsgProps.aPropVar[SEND_M_BODY].vt = VT_VECTOR | VT_UI1;
    sSendMsgProps.aPropVar[SEND_M_BODY].caub.cElems = cbBuffer;
    sSendMsgProps.aPropVar[SEND_M_BODY].caub.pElems = lpbBuffer;
    // Persistent
    sSendMsgProps.aPropID[SEND_M_DELIVERY] = PROPID_M_DELIVERY;
    sSendMsgProps.aPropVar[SEND_M_DELIVERY].vt = VT_UI1;
    sSendMsgProps.aPropVar[SEND_M_DELIVERY].bVal = MQMSG_DELIVERY_RECOVERABLE;
    
    //send message
    hr = MQSendMessage(pBookSrvr->hSendQueue, &sSendMsgProps, NULL);
    if (FAILED(hr))
    {
    	printf("Error %lx in MQSendMessage", hr);
    	return(FALSE);
    }
    
    //close send queue
    MQCloseQueue(pBookSrvr->hSendQueue);
    pBookSrvr->hSendQueue = NULL;

    return(TRUE);
}



BOOL FReplyToQuery(LPBOOKSRVR pBookSrvr, char * pszBookList,
    			   LPMQMailFormField pOrigInStock,
    			   LPMQMailFormField pOrigQuery)
{
    MQMailRecip sFrom;
    MQMailRecip sTo;
    LPMQMailRecip apRecip[1];
    MQMailRecipList sRecipList;
    MQMailEMail sEMail;
    FILETIME ft;
    MQMailFormField sFieldResults;
    LPMQMailFormField apField[3];
    MQMailFormFieldList sFieldList;
    HRESULT hr;
    ULONG ulNeededReSubject;

    //init reply email
    ZeroMemory(&sEMail, sizeof(MQMailEMail));

    //fill in subject from original mail with RE: before
    ulNeededReSubject = strlen(pBookSrvr->pEMail->szSubject) + 5;
    //realloc if necessary
    if (ulNeededReSubject > pBookSrvr->cbReSubject)
    {
    	pBookSrvr->pszReSubject = realloc(pBookSrvr->pszReSubject, ulNeededReSubject);
    	if (pBookSrvr->pszReSubject == NULL)
    	{
    		printf("Error %s realocating reply subject", GetLastError());
    		return(FALSE);
    	}
    	pBookSrvr->cbReSubject = ulNeededReSubject;
    }
    sprintf(pBookSrvr->pszReSubject, "Re: %s", pBookSrvr->pEMail->szSubject);
    sEMail.szSubject = pBookSrvr->pszReSubject;

    //time
    GetSystemTimeAsFileTime(&ft);
    sEMail.pftDate = &ft;
    
    //reports
    sEMail.fRequestDeliveryReport = FALSE;
    sEMail.fRequestNonDeliveryReport = FALSE;

	//fill in our attributes in the From recip
	ZeroMemory(&sFrom, sizeof(MQMailRecip));
    sFrom.szName = "Book Server";
    sFrom.szQueueLabel = pBookSrvr->szQLabelIn;
    sFrom.szAddress = pBookSrvr->szQLabelIn;
    sEMail.pFrom = &sFrom;

    //fill in To attributes out of original From
    sTo = *(pBookSrvr->pEMail->pFrom);
    sTo.iType = MQMailRecip_TO;
    apRecip[0] = &sTo;
    sRecipList.cRecips = 1;
    sRecipList.apRecip = apRecip;
    sEMail.pRecips = &sRecipList;

    //type is form
    sEMail.iType = MQMailEMail_FORM;

    //form name
    sEMail.form.szName = "IPM.BOOKS.RESULTS";

    //form fields
    sFieldResults.szName = "results";
    sFieldResults.iType = MQMailFormField_STRING;
    sFieldResults.Value.lpsz = pszBookList;
    apField[0] = pOrigQuery;
    apField[1] = pOrigInStock;
    apField[2] = &sFieldResults;
    sFieldList.cFields = 3;
    sFieldList.apField = apField;
    sEMail.form.pFields = &sFieldList;

    //reserved should be NULL
    sEMail.pReserved = NULL;

    //compose body out of EMail structure
    hr = MQMailComposeBody(&sEMail, &pBookSrvr->cbRetBuffer,
    						&pBookSrvr->lpbRetBuffer);
    if (FAILED(hr))
    {
    	printf("Error %lx in MQMailComposeBody\n", hr);
    	return(FALSE);
    }

    //send body to sender queue
    if (!FSendBody(pBookSrvr, pBookSrvr->cbRetBuffer, pBookSrvr->lpbRetBuffer,
    				pBookSrvr->pEMail->pFrom->szQueueLabel))
    	return(FALSE);
    
    //free body
    MQMailFreeMemory(pBookSrvr->lpbRetBuffer);
    pBookSrvr->lpbRetBuffer = NULL;

    return(TRUE);
}


BOOL FHandleBody(LPBOOKSRVR pBookSrvr, ULONG ulBodySize)
{
    HRESULT hr;
    BOOL fIgnore;
    LPMQMailFormField lpQueryField, lpInStockField;
    LPSTR szRetList;

    //parse the body into an email structure
    hr = MQMailParseBody(ulBodySize, pBookSrvr->lpbBuffer, &pBookSrvr->pEMail);
    if (FAILED(hr))
    {
    	printf("Error %lx parsing message, ignoring message\n", hr);
    	return(TRUE);
    }

    //make sure this is our form, if not, ignore
    if (pBookSrvr->pEMail->iType != MQMailEMail_FORM)
    	fIgnore = TRUE;
    else if (pBookSrvr->pEMail->form.szName == NULL)
    	fIgnore = TRUE;
    else if (strcmpi(pBookSrvr->pEMail->form.szName, "IPM.BOOKS.QUERY") != 0)
    	fIgnore = TRUE;
    else
    	fIgnore = FALSE;
    if (fIgnore)
    {
    	printf("Can't recognize form, ignoring message\n", hr);
    	return(TRUE);
    }

    //find the form field named "query" with type string, and
    // the form field named "instock" with type boolean.
    lpQueryField = lpFindFieldByName(pBookSrvr->pEMail, "query", MQMailFormField_STRING);
    lpInStockField = lpFindFieldByName(pBookSrvr->pEMail, "instock", MQMailFormField_BOOL);	
    if ((lpQueryField == NULL) || (lpInStockField == NULL))
    {
    	printf("Can't find requested fields in form, ignoring message\n", hr);
    	return(TRUE);
    }

    //got a query, reply with a book list (...)
    printf("\nRECEIVED from %s<%s> the following query: %s\n",
    	pBookSrvr->pEMail->pFrom->szName,
    	pBookSrvr->pEMail->pFrom->szAddress,
    	lpQueryField->Value.lpsz);
    if (lpInStockField->Value.b)
    {
    	printf("Information is requested only for books in stock\n");
    	szRetList = szBookListInStock;
    }
    else
    	szRetList = szBookList;

    printf("Replying with the following list:\n%s\n", szRetList);
    if (!FReplyToQuery(pBookSrvr, szRetList, lpQueryField, lpInStockField))
    	return(FALSE);

    //free returned EMail structure
    MQMailFreeMemory(pBookSrvr->pEMail);
    pBookSrvr->pEMail = NULL;

    return(TRUE);
}


enum
{
    RECEIVE_M_BODY,
    RECEIVE_M_BODY_SIZE,
    COUNT_RECEIVE_M_PROPS
};


BOOL FHandleMessage(LPBOOKSRVR pBookSrvr, MQMSGPROPS * pRcvMsgProps)
{
    HRESULT hr;
    
    //result of async is in overlapped structure
    hr = pBookSrvr->sOverlapped.Internal;
    if (FAILED(hr))
    {
    	ULONG ulNewBodySize;

    	//if error not related to buffer overflow, exit
    	if (hr != MQ_ERROR_BUFFER_OVERFLOW)
    	{
    		printf("Error %lx in async receive", hr);
    		return(FALSE);
    	}
    	
    	//there was a buffer overflow, realloc buffer
    	ulNewBodySize = pRcvMsgProps->aPropVar[RECEIVE_M_BODY_SIZE].ulVal;
    	printf("Message is too big, reallocating buffer to size %l\n", ulNewBodySize);
    	pBookSrvr->lpbBuffer = realloc(pBookSrvr->lpbBuffer, ulNewBodySize);
    	if (pBookSrvr->lpbBuffer == NULL)
    	{
    		printf("Error %lx in realloc body buffer", GetLastError());
    		return(FALSE);
    	}
    	pBookSrvr->cbBuffer = ulNewBodySize;
    	
    	//update props & buffer in rcv props, and call receive again
    	pRcvMsgProps->aPropVar[RECEIVE_M_BODY].caub.cElems = pBookSrvr->cbBuffer;
    	pRcvMsgProps->aPropVar[RECEIVE_M_BODY].caub.pElems = pBookSrvr->lpbBuffer;
    	hr = MQReceiveMessage(pBookSrvr->hQueue, 0, MQ_ACTION_RECEIVE,
    							pRcvMsgProps, NULL, NULL, NULL, NULL);
    	if (FAILED(hr))
    	{
    		printf("Error %lx in MQReceiveMessage", hr);
    		return(FALSE);
    	}
    }

    //now we have a body, call a routine to handle it
    if (!FHandleBody(pBookSrvr, pRcvMsgProps->aPropVar[RECEIVE_M_BODY_SIZE].ulVal))
    	return(FALSE);

    return(TRUE);
}



DWORD WINAPI dwBookSrvrThread(LPVOID lpParameter)
{
    LPBOOKSRVR pBookSrvr = (LPBOOKSRVR) lpParameter;
    DWORD dwWait;	
    BOOL fFinished = FALSE;
    HANDLE ahWait[2];
    HRESULT hr;
    SizedMQProps(MSG, COUNT_RECEIVE_M_PROPS, sRcvMsgProps);

    //open/create input queue for receive
    if (!FOpenCreateQueueByLabel(pBookSrvr, pBookSrvr->szQLabelIn, MQ_RECEIVE_ACCESS, &pBookSrvr->hQueue))
    	return(1);

    //create async receive event
    pBookSrvr->hRcvEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (pBookSrvr->hRcvEvent == NULL)
    {
    	printf("Error %lx creating async receive event\n", GetLastError());
    	return(1);
    }

    //init overlapped
    pBookSrvr->sOverlapped.hEvent = pBookSrvr->hRcvEvent;

    //allocate memory for body
    pBookSrvr->cbBuffer = BOOKSRVR_MSG_INIT_BUFSIZE;	
    pBookSrvr->lpbBuffer = malloc(pBookSrvr->cbBuffer);
    if (pBookSrvr->lpbBuffer == NULL)
    {
    	printf("Error %lx allocating body buffer\n");
    	return(1);
    }

    //allocate memory for reply subject
    pBookSrvr->cbReSubject = BOOKSRVR_RE_SUBJECT_INIT_BUFSIZE;
    pBookSrvr->pszReSubject = malloc(pBookSrvr->cbReSubject);
    if (pBookSrvr->pszReSubject == NULL)
    {
    	printf("Error %lx allocating re: subject buffer\n");
    	return(1);
    }

    //prepare handle array for WaitForMultipleObjects
    ahWait[0] = pBookSrvr->hToExitEvent;
    ahWait[1] = pBookSrvr->hRcvEvent;

    //loop until we are asked to exit
    while (!fFinished)
    {
    	//request async message
    	sRcvMsgProps.cProp	= COUNT_RECEIVE_M_PROPS;
    	sRcvMsgProps.aPropID [RECEIVE_M_BODY]				= PROPID_M_BODY;
    	sRcvMsgProps.aPropVar[RECEIVE_M_BODY].vt			= VT_VECTOR | VT_UI1;
    	sRcvMsgProps.aPropVar[RECEIVE_M_BODY].caub.cElems	= pBookSrvr->cbBuffer;
    	sRcvMsgProps.aPropVar[RECEIVE_M_BODY].caub.pElems	= pBookSrvr->lpbBuffer;
    	sRcvMsgProps.aPropID [RECEIVE_M_BODY_SIZE]			= PROPID_M_BODY_SIZE;
    	sRcvMsgProps.aPropVar[RECEIVE_M_BODY_SIZE].vt		= VT_UI4;
    	hr = MQReceiveMessage
    			(pBookSrvr->hQueue, INFINITE, MQ_ACTION_RECEIVE, &sRcvMsgProps,
    			 &pBookSrvr->sOverlapped, NULL, NULL, NULL);
        //
		// If not FAILED(hr), either there is already a message received (MQ_OK) 
        // and the event is triggered, or it is pending and the event will be
		// triggered when something happens. In both cases the result is handled 
        // by the event handler as wanted.
		// If FAILED(hr), the event is not triggered, so we force it to be handled 
        // by the event handler by triggering the event, and setting the overlapped
		// status to what we got.
        //
		if (FAILED(hr))
    	{
			pBookSrvr->sOverlapped.Internal = hr;
			SetEvent(pBookSrvr->sOverlapped.hEvent);
    	}

    	//wait for falcon message or exit event from main program
    	dwWait = WaitForMultipleObjects(2, ahWait, FALSE, INFINITE);
    	switch(dwWait)
    	{
    	case WAIT_OBJECT_0:			//exit event from main program
    		fFinished = TRUE;
    		break;
    	case WAIT_OBJECT_0 + 1:		//MSMQ message
    		if (!FHandleMessage(pBookSrvr, &sRcvMsgProps))
    			return(1);
    		break;
    	default:
    		printf("Error %lx occured in WaitForMultipleObjects\n", GetLastError());
    		return(1);
    		break;
    	}
    }// while

    return(0);
}



//-----------------------------------------------------------------
//start worker thread
//-----------------------------------------------------------------
BOOL FBookSrvr(LPBOOKSRVR pBookSrvr)
{
    DWORD dwThreadId, dwWait;
    HANDLE hThread;

    //create synchronization event with working thread		
    pBookSrvr->hToExitEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (pBookSrvr->hToExitEvent == NULL)
    {
    	printf("Error %lx creating synchronization event\n", GetLastError());
    	return(FALSE);
    }	

    //Start worker thread
    hThread = CreateThread(NULL, 0, dwBookSrvrThread, pBookSrvr,
    						CREATE_SUSPENDED, &dwThreadId);
    if (hThread == NULL)
    {
    	printf("Error %lx creating worker thread\n", GetLastError());
    	return(FALSE);
    }
    printf("Booksrvr is running, use your mail client to send Book Search forms and look for response(s) (Press <Enter> to quit)\n");
    ResumeThread(hThread);

    //wait for <Enter> key
    getchar();
    printf("Quiting...\n");

    //signal worker thread to exit
    SetEvent(pBookSrvr->hToExitEvent);

    //wait for it to exit
    dwWait = WaitForSingleObject(hThread, 100000);

    //if thread not terminated yet, kill it
    if (dwWait != WAIT_OBJECT_0)
    	TerminateThread(hThread, 0);

    return(TRUE);
}



//-----------------------------------------------------------------
//cleanup control structure
//-----------------------------------------------------------------
void CleanupBookSrvr(LPBOOKSRVR pBookSrvr)
{
    if (pBookSrvr->hQueue != NULL)
    	MQCloseQueue(pBookSrvr->hQueue);
    if (pBookSrvr->hSendQueue != NULL)
    	MQCloseQueue(pBookSrvr->hSendQueue);
    if (pBookSrvr->lpbRetBuffer != NULL)
    	MQMailFreeMemory(pBookSrvr->lpbRetBuffer);
    if (pBookSrvr->pszReSubject != NULL)
    	free(pBookSrvr->pszReSubject);
    if (pBookSrvr->pEMail != NULL)
    	MQMailFreeMemory(pBookSrvr->pEMail);
    if (pBookSrvr->lpbBuffer != NULL)
    	free(pBookSrvr->lpbBuffer);
    if (pBookSrvr->hRcvEvent != NULL)
    	CloseHandle(pBookSrvr->hRcvEvent);
    if (pBookSrvr->hToExitEvent != NULL)
    	CloseHandle(pBookSrvr->hToExitEvent);
}



//-----------------------------------------------------------------
//check arguments
//-----------------------------------------------------------------
BOOL FCheckArgs(LPBOOKSRVR pBookSrvr)
{
    if (pBookSrvr->argc < 2)
    	return(FALSE);

    pBookSrvr->szQLabelIn = pBookSrvr->argv[1];
    return(TRUE);
}



//-----------------------------------------------------
// Check if local computer is DS enabled or DS disabled
//----------------------------------------------------- 
BOOL DetectDsConnection(void)
{

    MQPRIVATEPROPS PrivateProps;
    QMPROPID       aPropId[MAX_VAR];
    MQPROPVARIANT  aPropVar[MAX_VAR];
    HRESULT        aStatus[MAX_VAR];
    DWORD          cProp;

    HRESULT        hr;


    // Prepare ds-enabled property
    cProp = 0;

    aPropId[cProp] = PROPID_PC_DS_ENABLED;
    aPropVar[cProp].vt = VT_NULL;
    ++cProp;	

    // Create a PRIVATEPROPS structure
    PrivateProps.cProp = cProp;
	PrivateProps.aPropID = aPropId;
	PrivateProps.aPropVar = aPropVar;
    PrivateProps.aStatus = aStatus;

    //
    // Retrieve the information
    //
	hr = MQGetPrivateComputerInformation(
				     NULL,
					 &PrivateProps);
	if(FAILED(hr))
    {
        printf("Unable to detect DS connection: %lx", hr);
        exit(1);
    }
	   
    return PrivateProps.aPropVar[0].boolVal;
}



//-----------------------------------------------------------------
//main
//-----------------------------------------------------------------
int main(int argc, char * argv[])
{
    BOOKSRVR sBookSrvr;
    BOOL fRet;

    //Fail if local computer is DS disabled
    if(DetectDsConnection() == FALSE)
    {
        printf("DS disabled mode not supported.\n");
        exit(1);
    }
    
    //initialize conrol structure
    ZeroMemory(&sBookSrvr, sizeof(BOOKSRVR));
    sBookSrvr.argc = argc;
    sBookSrvr.argv = argv;

    //check arguments
    if (!FCheckArgs(&sBookSrvr))
    {
    	printf("Usage: booksrvr <input-queue-label>\n");
    	printf("  <input-queue-label> - label of a queue where book requests arrive\n");
    	exit(1);
    }

    //do the real work
    fRet = FBookSrvr(&sBookSrvr);

    //cleanup
    CleanupBookSrvr(&sBookSrvr);

    if (fRet)
    	exit(0);
    else
    	exit(2);

    //needed for compilation 
    return(0);
}