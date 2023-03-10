#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <Qos.h>
#include <qossp.h> 
#include <qos.h>
#include <qospol.h>

#define VERSION         MAKEWORD ( 2, 2 )
#define APPNAME			"TestSoft"
#define POLICYLOCATOR	"TestERP"
#define DATA_SIZE       1024
#define PS_BUF_SIZE     1024
// COUNT limit is 64 as receiver uses a DWORD to hold count * 1024 bytes.
#define COUNT           10     
UCHAR   Buffer[10000];


typedef struct _extendedol
{

    WSAOVERLAPPED   ol;
    SOCKET          s;

} EOL;
    

WSAOVERLAPPED       wsol;
EOL                 qosol;
WSAEVENT            wsevent = NULL;
ULONG               count   = COUNT;


void BuildPsBuf( char   *buf, int usRsvp_buf_len );

SOCKET OpenQoSSocket( INT iSocketType );

void CALLBACK IoctlCompletionRoutine (
  IN DWORD dwError, 
  IN DWORD cbTransferred, 
  IN LPWSAOVERLAPPED lpOverlapped, 
  IN DWORD dwFlags 
);

void PrintQoS ( QOS *qos );

void DisplayError (LPTSTR title, DWORD error)
{
    printf ("%s, Error# %d\n\n", title,  error);
}
 

void main ( int argc, char *argv[] )
{
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);
	
    WSADATA     WsaData;
    WSABUF      WsaBuf, *lpWsaBuf = NULL;
    SOCKET      ListenSocket = INVALID_SOCKET, s = INVALID_SOCKET;
    QOS         Qos = {0};
    ULONG       TotalBytes = 0;
    int         result ;
    DWORD       BytesRet;   
    ULONG       SentBytes;
    ULONG       nZero = 0;
    ULONG       Flags = 0;
    struct      sockaddr_in     local;


    WSAStartup( VERSION,&WsaData );

    __try 
    {

        if ((wsevent = WSACreateEvent()) == WSA_INVALID_EVENT) {
            
            DisplayError ("WSACreateEvent Failed", GetLastError() ); 
            __leave;
        }
        
        
        lpWsaBuf = &WsaBuf;
        memset (lpWsaBuf, 0, sizeof (WSABUF));
        memset(&wsol, 0, sizeof(WSAOVERLAPPED));
        memset(&qosol, 0, sizeof(EOL));
         
        wsol.hEvent= wsevent;

        WsaBuf.len = DATA_SIZE;
        WsaBuf.buf= (char *)malloc(DATA_SIZE);

        if (!WsaBuf.buf) {
            
            DisplayError ( "WsaBuf Failed", GetLastError() ); 
            __leave;
        }

        ListenSocket = OpenQoSSocket ( SOCK_STREAM );

        if ( ListenSocket == INVALID_SOCKET)
        {
            DisplayError ("Failed to create QOS listening socket", GetLastError() ); 
            __leave;
        }

        local.sin_family = AF_INET;
        local.sin_addr.s_addr = INADDR_ANY; 

        // For simplicity hard-code the port number
        local.sin_port = htons (8888);
        
        result = 
        bind ( ListenSocket, (struct sockaddr*)&local,sizeof(local) );

        if ( result == SOCKET_ERROR )
        {
            DisplayError ( "bind Failed", WSAGetLastError() ); 
            __leave;
        }


        result =
        listen( ListenSocket, 5 );

        if ( result == SOCKET_ERROR )
        {
            DisplayError ( "listen Failed", WSAGetLastError() ); 
            __leave;
        }
    
        memset ( &Qos, QOS_NOT_SPECIFIED, sizeof(QOS) );
    
        Qos.ReceivingFlowspec.ServiceType           = SERVICETYPE_NOTRAFFIC; 
        Qos.ReceivingFlowspec.TokenRate             = QOS_NOT_SPECIFIED; 
        Qos.ReceivingFlowspec.TokenBucketSize       = QOS_NOT_SPECIFIED; 
        Qos.ReceivingFlowspec.PeakBandwidth         = QOS_NOT_SPECIFIED; 
        Qos.ReceivingFlowspec.MinimumPolicedSize    = QOS_NOT_SPECIFIED;
        Qos.ReceivingFlowspec.MaxSduSize            = QOS_NOT_SPECIFIED; 

    
        Qos.SendingFlowspec.ServiceType             = SERVICETYPE_QUALITATIVE; 
        Qos.SendingFlowspec.TokenRate               = QOS_NOT_SPECIFIED; 
        Qos.SendingFlowspec.TokenBucketSize         = QOS_NOT_SPECIFIED; 
        Qos.SendingFlowspec.PeakBandwidth           = QOS_NOT_SPECIFIED; 
        Qos.SendingFlowspec.MinimumPolicedSize      = QOS_NOT_SPECIFIED;
        Qos.SendingFlowspec.MaxSduSize              = QOS_NOT_SPECIFIED; 
        Qos.ProviderSpecific.buf                    = ( char * )malloc ( PS_BUF_SIZE );

        if (!Qos.ProviderSpecific.buf) {
            
            DisplayError ( "Qos.ProviderSpecific.buf Alloc Failed", GetLastError() ); 
            __leave;
        }

        memset( Qos.ProviderSpecific.buf, 0, PS_BUF_SIZE);
        BuildPsBuf( Qos.ProviderSpecific.buf, PS_BUF_SIZE);

        Qos.ProviderSpecific.len = ((LPRSVP_RESERVE_INFO)(Qos.ProviderSpecific.buf))->ObjectHdr.ObjectLength;

AcceptAgain:
        printf ("Waiting for Receiver to connect and send query...\n\n");

        s = WSAAccept( ListenSocket, NULL, NULL, NULL,0 );

        if ( s == INVALID_SOCKET)
        {
            DisplayError ( "WSAAccept Failed", WSAGetLastError() ); 
            __leave;
        }

                    
        result = 
            WSAIoctl(s,SIO_SET_QOS, &Qos,sizeof(QOS),NULL, 0,&BytesRet, NULL,NULL);

        if ( result == SOCKET_ERROR )
        {
            DisplayError ( "WSAIoctl SIO_SET_QOS Failed", WSAGetLastError() ); 
        }

        // to make sure send completion only when entire buffer is complete
        result = 
            setsockopt(s, SOL_SOCKET, SO_SNDBUF, (char *)&nZero, sizeof(nZero));
        
        if ( result == SOCKET_ERROR )
        {
            DisplayError ( "setsockopt SO_SNDBUF 0 Failed", WSAGetLastError() ); 
            __leave;
        }

        
        qosol.s = s;

        result = 
        WSAIoctl(s,
                 SIO_GET_QOS, 
                 NULL,
                 0,
                 Buffer,
                 sizeof (Buffer),
                 &BytesRet, 
                 (WSAOVERLAPPED *)&qosol,
                 IoctlCompletionRoutine);


        if ( result == SOCKET_ERROR )
        {
            DWORD dwError;
            dwError = WSAGetLastError();
            if (dwError != ERROR_IO_PENDING )
            {
                DisplayError ( "WSAIoctl SIO_GET_QOS", dwError ); 
            }
        }
        

        lpWsaBuf = &WsaBuf;
        lpWsaBuf->buf[0] = ( char ) count;

        while(count)
        {

            result =
            WSASend(    s, 
                    lpWsaBuf,
                    1,
                    &SentBytes,
                    0,
                    &wsol,
                    NULL);
        
            
            if ( result == SOCKET_ERROR )
            {
                DWORD dwError;
                dwError = WSAGetLastError();
                if (dwError != ERROR_IO_PENDING )
                {
                    DisplayError ( "WSASend", dwError ); 
                    __leave;
                }
            }


            if (WSAWaitForMultipleEvents(
                        1, 
                        &wsevent, 
                        TRUE, 
                        WSA_INFINITE, 
                        TRUE
                        ) == WSA_WAIT_FAILED) 
            {

                DisplayError ( "WSAWaitForMultipleEvents Failed", WSAGetLastError() ); 
                __leave;
            } 

            if (WSAGetOverlappedResult(
                        s, 
                        &wsol, 
                        &SentBytes, 
                        TRUE, 
                        &Flags
                        ) == FALSE) 
            {

                DisplayError ( "WSAGetOverlappedResult Failed", WSAGetLastError() ); 
                __leave;
            }

            
            TotalBytes+=SentBytes;
            printf("Sent #%d bytes\n", SentBytes);
            printf("				Total so far = %d\n", TotalBytes);
            count--;
            
            memset( &wsol, 0, sizeof(WSAOVERLAPPED) );
            wsol.hEvent = wsevent;
            WSAResetEvent( wsevent );
        }
            
        closesocket( s);
        s = INVALID_SOCKET;
        printf("Successfully sent %d bytes\n", TotalBytes);
        count = COUNT;
        TotalBytes = 0;

        goto AcceptAgain;

    }
    __finally
    {

        if ( wsevent != NULL ) WSACloseEvent ( wsevent );

        if ( s != INVALID_SOCKET ) closesocket( s );

        if ( ListenSocket != INVALID_SOCKET ) closesocket( s );

        if (lpWsaBuf->buf) free ( lpWsaBuf->buf );
    
        if ( Qos.ProviderSpecific.buf ) free ( Qos.ProviderSpecific.buf ) ;
    }

    WSACleanup();

}




USHORT 
ConstructAppIdPe(
    IN      char    *szAppName, 
    IN      char    *szPolicyLocator,
    IN OUT  USHORT  *pusAppIdPeBufLen,
    IN OUT  char    *pszAppIdPeBuf)
/*+++
 *  Description:
 *      This routine generates the application identity PE give the name
 *      and policy locator strings for the application. 
 *          
 *      The first argument szAppName is used to construct the CREDENTIAL 
 *      attribute of the Identity PE. The subtype is set to ASCII_ID.
 *      The second argument szPolicyLocator is used to construct the
 *      POLICY_LOCATOR attribute of the Identity PE. They subtype is
 *      set to ASCII_DN.
 *          
 *      Refer to draft-ietf-rap-rsvp-identity-03.txt and 
 *           draft-bernet-appid-00.txt
 *      for details on the Identity Policy Elements. 
 *          
 *      Also draft-bernet-appid-00.txt contains some examples for the
 *      first two arguments to this function.
 *          
 *      The PE is generated in the supplied buffer. If the length of
 *      the buffer is not enough required length is returned.
 *          
 *  Parameters:  szAppName          app name, string, caller supply
 *               szPolicyLocator    Policy Locator string, caller supply
 *               pusAppIdPeBufLen   length of caller allocated buffer
 *               pszAppIdPeBuf      pointer to caller allocated buffer
 *               
 *  Return Values:
 *       0 : Fail, pusAppIdPeBufLen will hold number of bytes needed
 *      >0 : Length of the application indetity PE
--*/
{
    LPRSVP_POLICY_INFO  pPolicyInfo = (LPRSVP_POLICY_INFO)pszAppIdPeBuf;
    RSVP_POLICY *pAppIdPe = (RSVP_POLICY *)pPolicyInfo->PolicyElement;
    IDPE_ATTR   *pRsvp_pe_app_attr;
    USHORT      usAppIdAttrLen;
    USHORT      usPolicyLocatorAttrLen;
    USHORT      usTotalPaddedLen;


    pPolicyInfo->NumPolicyElement = 1;
    pPolicyInfo->ObjectHdr.ObjectType = RSVP_OBJECT_POLICY_INFO;
    pPolicyInfo->ObjectHdr.ObjectLength = sizeof(RSVP_POLICY_INFO) - sizeof(RSVP_POLICY);    
    
    if ( !szAppName ||  !szPolicyLocator )
        return 0;

    usPolicyLocatorAttrLen = (USHORT) (IDPE_ATTR_HDR_LEN + strlen(szPolicyLocator));
    usAppIdAttrLen         = (USHORT) (IDPE_ATTR_HDR_LEN + strlen(szAppName));
    
    // Calculcate the length of the buffer required
    usTotalPaddedLen = (USHORT) (RSVP_POLICY_HDR_LEN + 
                       RSVP_BYTE_MULTIPLE(usAppIdAttrLen) +
                       RSVP_BYTE_MULTIPLE(usPolicyLocatorAttrLen));
           
    // If the supplied buffer is not long enough, return error and the
    // required buffer length
    if (*pusAppIdPeBufLen < usTotalPaddedLen) {
            *pusAppIdPeBufLen = usTotalPaddedLen;
        return 0;
    }
    memset(pAppIdPe, 0, usTotalPaddedLen);
    
    // Set up RSVP_POLICY header
    pAppIdPe->Len  = usTotalPaddedLen;
    pAppIdPe->Type = PE_TYPE_APPID;
    
    // Application ID Policy Element (PE) attributes follow the PE header
    pRsvp_pe_app_attr = (IDPE_ATTR *)((char*)pAppIdPe + RSVP_POLICY_HDR_LEN);

    // Construct the POLICY_LOCATOR attribute with simple ASCII_DN 
    //  subtype using the supplied Policy Locator.  Since the RSVP service 
    //  does not look into the attributes, set the attribute length in 
    //  network order.
    pRsvp_pe_app_attr->PeAttribLength  = htons(usPolicyLocatorAttrLen);
    pRsvp_pe_app_attr->PeAttribType    = PE_ATTRIB_TYPE_POLICY_LOCATOR;
    pRsvp_pe_app_attr->PeAttribSubType = POLICY_LOCATOR_SUB_TYPE_ASCII_DN;
    strcpy((char *)pRsvp_pe_app_attr->PeAttribValue, szPolicyLocator);
    
    // Advance pRsvp_pe_app_attr 
    pRsvp_pe_app_attr = (IDPE_ATTR *)
       (((char*)pAppIdPe + 
           RSVP_POLICY_HDR_LEN + 
       RSVP_BYTE_MULTIPLE(usPolicyLocatorAttrLen)));
           
    // Construct the CREDENTIALS attribute with simple ASCII_ID subtype 
    //  using the supplied Application name.  Since the RSVP service does 
    //  not look into the attributes, set the attribute length in 
    //  network order.
    pRsvp_pe_app_attr->PeAttribLength   = htons(usAppIdAttrLen);
    pRsvp_pe_app_attr->PeAttribType     = PE_ATTRIB_TYPE_CREDENTIAL;
    pRsvp_pe_app_attr->PeAttribSubType  = CREDENTIAL_SUB_TYPE_ASCII_ID;
    strcpy((char *)pRsvp_pe_app_attr->PeAttribValue, szAppName);

    pPolicyInfo->ObjectHdr.ObjectLength = pPolicyInfo->ObjectHdr.ObjectLength+usTotalPaddedLen;
    
    return usTotalPaddedLen;
}



void
BuildPsBuf( char    *buf, int usRsvp_buf_len)
{
    USHORT  usAppIdPeBufLen; 
    LPRSVP_RESERVE_INFO     rsvp_reserve_info = (LPRSVP_RESERVE_INFO)buf;

	usAppIdPeBufLen = (USHORT) (usRsvp_buf_len - sizeof (RSVP_RESERVE_INFO) - sizeof (RSVP_POLICY_INFO) + sizeof(RSVP_POLICY));
    // Init RSVP_RESERVE_INFO with appropriate values
    rsvp_reserve_info->Style = RSVP_FIXED_FILTER_STYLE;
    rsvp_reserve_info->ConfirmRequest = 0;
    rsvp_reserve_info->NumFlowDesc = 0;
    rsvp_reserve_info->FlowDescList = NULL;
    rsvp_reserve_info->PolicyElementList = (LPRSVP_POLICY_INFO)(buf+sizeof(RSVP_RESERVE_INFO));


    // Construct the policy element that holds app id 
    //   and policy locator attributes (as per RFC 2750)

    ConstructAppIdPe( APPNAME,  POLICYLOCATOR, &usAppIdPeBufLen, (char *)(rsvp_reserve_info->PolicyElementList));

    // Set the type and length of the RSVP_RESERVE_INFO finally
    rsvp_reserve_info->ObjectHdr.ObjectLength = 
        sizeof(RSVP_RESERVE_INFO) + rsvp_reserve_info->PolicyElementList->ObjectHdr.ObjectLength;
    rsvp_reserve_info->ObjectHdr.ObjectType = RSVP_OBJECT_RESERVE_INFO; 
}

SOCKET OpenQoSSocket(INT iSocketType)
{
    DWORD bufferSize = 0;
    DWORD numProtocols, i;
    LPWSAPROTOCOL_INFO installedProtocols, qosProtocol; 
    SOCKET fd;
    
    //
    // Call WSAEnumProtocols to determine buffer size required
    //
    numProtocols = WSAEnumProtocols(NULL, NULL, &bufferSize);
    if((numProtocols != SOCKET_ERROR) && (WSAGetLastError() != WSAENOBUFS)){
        DisplayError ( "WSAEnumProtocols Failed", WSAGetLastError() ); 
        return(INVALID_SOCKET);
    } else {
        //
        // Allocate a buffer to hold the list of protocol info structures
        //
        installedProtocols = (LPWSAPROTOCOL_INFO)malloc(bufferSize);
   
        //
        // Enumerate the protocols, find the QoS enabled one
        //
        numProtocols = WSAEnumProtocols(NULL,
                                        installedProtocols,
                                        &bufferSize);
        if(numProtocols == SOCKET_ERROR){
            DisplayError ( "WSAEnumProtocols Failed", WSAGetLastError() ); 
            return(INVALID_SOCKET);
        } 
        else 
        {
            qosProtocol = installedProtocols;

            for( i=0 ; i < numProtocols ; qosProtocol++, i++)
            {
                if  ((qosProtocol->dwServiceFlags1 & XP1_QOS_SUPPORTED) &&
                    (qosProtocol->iSocketType    == iSocketType) &&
                    (qosProtocol->iAddressFamily == AF_INET))
                {
                    break;
                }
                     
            }
        }
    
        //
        // Now open the socket.
        //
        fd = WSASocket(0, 
                       iSocketType, 
                       0, 
                       qosProtocol,          // Use the QoS SP we found
                       0, 
                       WSA_FLAG_OVERLAPPED); // *MUST* be overlapped!
    
        //
        // De-allocate protocol info buffer
        //
        free(installedProtocols);

        return(fd);
    }        
}

void CALLBACK IoctlCompletionRoutine (
  IN DWORD dwError, 
  IN DWORD cbTransferred, 
  IN LPWSAOVERLAPPED lpOverlapped, 
  IN DWORD dwFlags 
)
{
	UNREFERENCED_PARAMETER(dwFlags);
	UNREFERENCED_PARAMETER(cbTransferred);
	
    DWORD   result, BytesRet;
    EOL     *pEOL;


    pEOL = (EOL *)lpOverlapped;
    
    switch  (dwError)
    {

        case  WSA_QOS_RECEIVERS:  
         /* at least one Reserve has arrived */
            printf ( "RESV arrived: WSA_QOS_RECEIVERS \n" );
            PrintQoS ((QOS *)Buffer );
            break;

        case  WSA_QOS_SENDERS: 
         /* at least one Path has arrived */
            printf ( "PATH arrived: WSA_QOS_SENDERS \n" );
            PrintQoS ( (QOS *)Buffer );
            break;

        case  WSA_QOS_NO_SENDERS:             
         /* there are no senders */
            printf ("PATH_TEAR: WSA_QOS_NO_SENDERS \n" );
            break;

        case  WSA_QOS_NO_RECEIVERS:
         /* there are no receivers */
            printf ("RESV_TEAR: WSA_QOS_NO_RECEIVERS \n" );
            break;

        case  WSA_QOS_REQUEST_CONFIRMED:
         /* Reserve has been confirmed */
            printf ("RESV_CONFIRM: WSA_QOS_REQUEST_CONFIRMED \n" );
            PrintQoS ( (QOS *)Buffer );
            break;

        case  WSA_QOS_ADMISSION_FAILURE:      
         /* error due to lack of resources */
            printf ("WSA_QOS_ADMISSION_FAILURE \n" );
            break;

        case  WSA_QOS_POLICY_FAILURE:         
         /* rejected for administrative reasons - bad credentials */
            printf ("WSA_QOS_POLICY_FAILURE \n" );
            break;

        case  WSA_QOS_BAD_STYLE:               
         /* unknown or conflicting style */
            printf ("WSA_QOS_BAD_STYLE \n" );
            break;

        case  WSA_QOS_BAD_OBJECT:              
         /* problem with some part of the filterspec or providerspecific
          * buffer in general */
            printf ("WSA_QOS_BAD_OBJECT \n" );
            break;

        case  WSA_QOS_TRAFFIC_CTRL_ERROR:     
         /* problem with some part of the flowspec */
            printf ("WSA_QOS_TRAFFIC_CTRL_ERROR \n" );
            break;

        case  WSA_QOS_GENERIC_ERROR:           
         /* general error */
            printf ("WSA_QOS_GENERIC_ERROR \n" );
            break;

        case  WSA_QOS_ESERVICETYPE:            
         /* invalid service type in flowspec */
            printf ("WSA_QOS_ESERVICETYPE \n" );
            break;

        case  WSA_QOS_EFLOWSPEC:               
         /* invalid flowspec */
            printf ("WSA_QOS_EFLOWSPEC \n" );
            break;

        case  WSA_QOS_EPROVSPECBUF:            
         /* invalid provider specific buffer */
            printf ("WSA_QOS_EPROVSPECBUF \n" );
            break;

        case  WSA_QOS_EFILTERSTYLE:            
         /* invalid filter style */
            printf ("WSA_QOS_EFILTERSTYLE \n" );
            break;

        case  WSA_QOS_EFILTERTYPE:             
         /* invalid filter type */
            printf ("WSA_QOS_EFILTERTYPE \n" );
            break;

        case  WSA_QOS_EFILTERCOUNT:           
         /* incorrect number of filters */
            printf ("WSA_QOS_EFILTERCOUNT \n" );
            break;

        case  WSA_QOS_EOBJLENGTH:              
         /* invalid object length */
            printf ("WSA_QOS_EOBJLENGTH \n" );
            break;

        case  WSA_QOS_EFLOWCOUNT:              
         /* incorrect number of flows */
            printf ("WSA_QOS_EFLOWCOUNT \n" );
            break;

        case  WSA_QOS_EUNKOWNPSOBJ:            
         /* unknown object in provider specific buffer */
            printf ("WSA_QOS_EUNKOWNPSOBJ \n" );
            break;

        case  WSA_QOS_EPOLICYOBJ:              
         /* invalid policy object in provider specific buffer */
            printf ("WSA_QOS_EPOLICYOBJ \n" );
            break;

        case  WSA_QOS_EFLOWDESC:               
         /* invalid flow descriptor in the list */
            printf ("WSA_QOS_EFLOWDESC \n" );
            break;

        case  WSA_QOS_EPSFLOWSPEC:             
         /* inconsistent flow spec in provider specific buffer */
            printf ("WSA_QOS_EPSFLOWSPEC \n" );
            break;

        case  WSA_QOS_EPSFILTERSPEC:           
         /* invalid filter spec in provider specific buffer */
            printf ("WSA_QOS_EPSFILTERSPEC \n" );
            break;

        case  WSA_QOS_ESDMODEOBJ:              
         /* invalid shape discard mode object in provider specific buffer */
            printf ("WSA_QOS_ESDMODEOBJ \n" );
            break;

        case  WSA_QOS_ESHAPERATEOBJ:           
         /* invalid shaping rate object in provider specific buffer */
            printf ("WSA_QOS_ESHAPERATEOBJ \n" );
            break;

        case  WSA_QOS_RESERVED_PETYPE :        
         /* reserved policy element in provider specific buffer */
            printf ("WSA_QOS_RESERVED_PETYPE \n" );
            break;

        case  ERROR_OPERATION_ABORTED: 
         /* overlapped SIO_GET_QOS aborted */
            printf ( "overlapped SIO_GET_QOS aborted \n" );
            break;
        
        default:
            printf ( "Unknown SIO_GET_QOS completion error %d\n", dwError);
            return;
    }


    memset ( lpOverlapped, 0, sizeof (OVERLAPPED) );
    
    // Done with previous SIO_GET_QOS, queue another one

    result = 
    WSAIoctl(pEOL->s,
             SIO_GET_QOS, 
             NULL,
             0,
             Buffer,
             sizeof (Buffer),
             &BytesRet, 
             lpOverlapped,
             IoctlCompletionRoutine);


    if ( result == SOCKET_ERROR )
    {
        DWORD dwError;
        dwError = WSAGetLastError();
        if (dwError != ERROR_IO_PENDING )
        {
            DisplayError ( "WSAIoctl SIO_GET_QOS", dwError ); 
        }
    }

}



// DisplayQoSList code are adapted from the printqos.cpp from the QoSEvent sample
//
static CHAR *ServiceTypeToStr(SERVICETYPE ServiceType)
    {
    static CHAR szServiceType[128];

    if (QOS_NOT_SPECIFIED == ServiceType)
    {
        strcpy(szServiceType, "QOS_NOT_SPECIFIED");
        return(szServiceType);
        }
        
    switch ((ServiceType & 0x0000FFFF))
            {
            case SERVICETYPE_NOTRAFFIC : 
                strcpy(szServiceType, "SERVICETYPE_NOTRAFFIC"); 
                break;
            case SERVICETYPE_BESTEFFORT : 
                strcpy(szServiceType, "SERVICETYPE_BESTEFFORT"); 
                break;
            case SERVICETYPE_CONTROLLEDLOAD : 
                strcpy(szServiceType, "SERVICETYPE_CONTROLLEDLOAD"); 
                break;
            case SERVICETYPE_GUARANTEED : 
                strcpy(szServiceType, "SERVICETYPE_GUARANTEED"); 
                break;
            case SERVICETYPE_NETWORK_UNAVAILABLE : 
                strcpy(szServiceType, "SERVICETYPE_NETWORK_UNAVAILABLE"); 
                break;
            case SERVICETYPE_GENERAL_INFORMATION : 
                strcpy(szServiceType, "SERVICETYPE_GENERAL_INFORMATION"); 
                break;
            case SERVICETYPE_NOCHANGE : 
                strcpy(szServiceType, "SERVICETYPE_NOCHANGE"); 
                break;
            case SERVICETYPE_NONCONFORMING :
                strcpy(szServiceType, "SERVICETYPE_NONCONFORMING"); 
                break;
            case SERVICETYPE_NETWORK_CONTROL :
                strcpy(szServiceType, "SERVICETYPE_NETWORK_CONTROL");
                break;
            case SERVICETYPE_QUALITATIVE :
                strcpy(szServiceType, "SERVICETYPE_QUALITATIVE");
                break;
            default:
                sprintf(szServiceType, "Unknown service type %lu  zzz", ServiceType);
                break;
            }
    
    if (ServiceType & SERVICE_NO_TRAFFIC_CONTROL)
        strcat(szServiceType, " | SERVICE_NO_TRAFFIC_CONTROL");
    else if (ServiceType & SERVICE_NO_QOS_SIGNALING)
        strcat(szServiceType, " | SERVICE_NO_QOS_SIGNALING");
    

    return(szServiceType);
    }

static void PrintFlowspec(FLOWSPEC *pFlowspec, CHAR *lpszIndent)
    {
    TCHAR szIndent[24];


    strncpy(szIndent, lpszIndent, sizeof(szIndent));
    strncat(szIndent, "  ", sizeof(szIndent));
    szIndent[sizeof(szIndent)-1] = '\0';


    if (QOS_NOT_SPECIFIED == pFlowspec->TokenRate)
        printf ( "%sTokenRate          = QOS_NOT_SPECIFIED\n", szIndent);
    else
        printf ( "%sTokenRate          = %d\n", szIndent, pFlowspec->TokenRate);
    

    if (QOS_NOT_SPECIFIED == pFlowspec->TokenBucketSize)
        printf ( "%sTokenBucketSize    = QOS_NOT_SPECIFIED\n", szIndent);
    else
        printf ( "%sTokenBucketSize    = %d\n", szIndent, pFlowspec->TokenBucketSize);
    

    if (QOS_NOT_SPECIFIED == pFlowspec->PeakBandwidth)
        printf ( "%sPeakBandwidth      = QOS_NOT_SPECIFIED\n", szIndent);
    else
        printf ( "%sPeakBandwidth      = %d\n", szIndent, pFlowspec->PeakBandwidth);


    if (QOS_NOT_SPECIFIED == pFlowspec->Latency)
        printf ( "%sLatency            = QOS_NOT_SPECIFIED\n", szIndent);
    else
        printf ( "%sLatency            = %d\n", szIndent, pFlowspec->Latency);


    if (QOS_NOT_SPECIFIED == pFlowspec->DelayVariation)
        printf ( "%sDelayVariation     = QOS_NOT_SPECIFIED\n", szIndent);
    else
        printf ( "%sDelayVariation     = %d\n", szIndent, pFlowspec->DelayVariation);


    printf ( "%sServiceType        = %s\n", 
        szIndent, ServiceTypeToStr(pFlowspec->ServiceType));


    if (QOS_NOT_SPECIFIED == pFlowspec->MaxSduSize)
        printf ( "%sMaxSduSize         = QOS_NOT_SPECIFIED\n", szIndent);
    else
        printf ( "%sMaxSduSize         = %d\n", szIndent, pFlowspec->MaxSduSize);


    if (QOS_NOT_SPECIFIED == pFlowspec->MinimumPolicedSize)
        printf ( "%sMinimumPolicedSize = QOS_NOT_SPECIFIED\n", szIndent);
    else
        printf ( "%sMinimumPolicedSize = %d\n", szIndent, pFlowspec->MinimumPolicedSize);


    return;
    }



void PrintQoS (QOS *qos)
{

    if (NULL == qos) return;

    printf ("SendingFlowSpec:\n" );
    PrintFlowspec( &qos->SendingFlowspec, "    ");
    printf ( "ReceivingFlowspec:\n" );
    PrintFlowspec( &qos->SendingFlowspec, "    " );
    printf ("\n");
    return;

}

