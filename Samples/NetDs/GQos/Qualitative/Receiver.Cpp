
#include <winsock2.h>
#include <commctrl.h>
#include <ws2tcpip.h>
#include <qos.h>
#include <qossp.h>
#include <qospol.h>
#include <TCHAR.H >
#include <stdio.h>

#include    "resource.h"


#define VERSION         MAKEWORD ( 2, 2 )
#define DATA_SIZE       1024
        
TCHAR   szServerIP[20];
struct  sockaddr_in     dest;
struct  hostent         * hp;
int     AddFlow         = 0; 
QOS     QoS;
UCHAR   Buffer[10000];


typedef struct _extendedol
{

    WSAOVERLAPPED   ol;
    SOCKET          s;
    HWND            hDlg;

} EOL;
    

WSAOVERLAPPED       wsol;
EOL         qosol;
WSAEVENT    wsevent = NULL;


DWORD WINAPI Query( LPVOID lpParameter );
SOCKET OpenQoSSocket( INT iSocketType );

void CALLBACK IoctlCompletionRoutine (
  IN DWORD dwError, 
  IN DWORD cbTransferred, 
  IN LPWSAOVERLAPPED lpOverlapped, 
  IN DWORD dwFlags 
);

void DisplayQoSInList (HWND hDlg, int nIDDlgItem, QOS *qos);

void DisplayError (LPTSTR title, DWORD error)
{

    TCHAR szError [1024];
    
    wsprintf (szError, "Error# %d", error);
    MessageBox (NULL, szError, title, MB_OK);

}


INT_PTR CALLBACK  Dlg_Proc ( HWND hDlg, UINT uMsg, 
   WPARAM wParam, LPARAM lParam ) 
{
   UNREFERENCED_PARAMETER(lParam);
   
   ULONG    ThreadId;
   HANDLE   hThread;

   switch ( uMsg ) 
   {
      case WM_INITDIALOG:
         SetWindowPos ( hDlg, HWND_TOPMOST, 200, 200, -1, -1,
            SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE );
         SendDlgItemMessage ( hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"Qualitative QoS Demo" );
         return TRUE;

      
      case WM_COMMAND:
         switch ( LOWORD ( wParam ) )
         {
            case IDOK:
                EndDialog ( hDlg, 0 );
                return TRUE;
            
            case IDC_QoS_BUTTON:
            case IDC_NonQoS_BUTTON:
                
                SendMessage( GetDlgItem ( hDlg, IDC_PROGRESS), PBM_SETPOS,  0, 0 ); 
                SendDlgItemMessage ( hDlg, IDC_STATUS_LIST, LB_RESETCONTENT , 0, 0);
                
                GetDlgItemText ( hDlg, IDC_SERVER_IP, szServerIP, 20 );
                if ( _tcslen ( szServerIP ) > 0 )
                {
                    // get server IP address

                    dest.sin_family = AF_INET;
                    if ((dest.sin_addr.s_addr = inet_addr(szServerIP)) == INADDR_NONE)
                    {
                        if ((hp = gethostbyname(szServerIP)) != NULL)
                        {
                            memcpy(&(dest.sin_addr), hp->h_addr, hp->h_length);
                            dest.sin_family = hp->h_addrtype;
                        }
                        else
                        {
                            DisplayError ("Incorrect remote server IP", GetLastError() ); 
                            break;
                        }
                    }

                    // for simplicity, hard-code port number

                    dest.sin_port = htons (8888); 

                    // disallow another query when one is in progress

                    EnableWindow ( GetDlgItem ( hDlg, IDC_NonQoS_BUTTON ) , FALSE );
                    EnableWindow ( GetDlgItem ( hDlg, IDC_QoS_BUTTON ) , FALSE );
                    
                    if ( LOWORD ( wParam ) == IDC_QoS_BUTTON ) 
                        AddFlow = 1;
                    else 
                        AddFlow = 0;
                    

                    hThread = CreateThread ( 
                            NULL,
                            0,
                            Query,
                            (void *) hDlg,
                            0,
                            &ThreadId ) ;

                    if ( hThread == NULL ) 
                        DisplayError ("IFailed to create query thread", GetLastError() ); 
                    
                    // Create the query thread. Close the handel returned so that
                    // when the thread function exits, the underlying thread object
                    // could go away

                    CloseHandle ( hThread );

                }
                else
                    MessageBox ( NULL, "Please specify the remote server IP", "Error", MB_OK );

                break;
         }
         break;

      case WM_CLOSE:
         EndDialog ( hDlg, 0);
         return TRUE;
   } 
    

   return FALSE;
}



int APIENTRY WinMain (HINSTANCE hInstance, 
   HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) 
{
   UNREFERENCED_PARAMETER(nCmdShow);
   UNREFERENCED_PARAMETER(lpszCmdLine);
   UNREFERENCED_PARAMETER(hPrevInstance);
   
   WSADATA  wsaData;

   WSAStartup ( VERSION, &wsaData );

   InitCommonControls();
   DialogBox(hInstance, MAKEINTRESOURCE(IDD_CLIENT_DIALOG), 
      NULL, Dlg_Proc);

   WSACleanup();

   return(0);
}

DWORD WINAPI Query(
  LPVOID lpParameter   // thread data
)
{
    HWND hDlg =  (HWND) lpParameter;
    SOCKET      s = INVALID_SOCKET;
    int         result;
    DWORD       BytesRet;
    WSABUF      WsaBuf, *lpWsaBuf;
    ULONG       Flags;
    QOS         Qos;
    ULONG       TotalBytes = 0;
    ULONG       RecvBytes = 0;
    ULONG       End = 0;

    memset ( &WsaBuf, 0, sizeof (WSABUF) );

    __try 
    {
        if ((wsevent = WSACreateEvent()) == WSA_INVALID_EVENT) {
            
            DisplayError ("WSACreateEvent Failed", GetLastError() ); 
            __leave;
        }
        
        
        memset(&wsol, 0, sizeof(WSAOVERLAPPED));
        memset(&qosol, 0, sizeof(EOL));
         
        wsol.hEvent= wsevent;

        s = OpenQoSSocket ( SOCK_STREAM );

        if ( s == INVALID_SOCKET)
        {
            DisplayError ("Failed to create QOS socket", GetLastError() ); 
            __leave;
        }

        result =        
        WSAConnect( s,
                    (SOCKADDR *) &dest,
                    sizeof(SOCKADDR),
                    NULL,
                    NULL,
                    NULL,
                    NULL);

        if ( result == SOCKET_ERROR )
        {
            DisplayError ( "WSAConnect Failed", WSAGetLastError() ); 
            __leave;
        }


        memset ( &Qos, QOS_NOT_SPECIFIED, sizeof(QOS) );
    
        Qos.SendingFlowspec.ServiceType         = SERVICETYPE_NOTRAFFIC;
    
        Qos.ReceivingFlowspec.ServiceType       = SERVICETYPE_QUALITATIVE; 
        Qos.ReceivingFlowspec.TokenRate         = QOS_NOT_SPECIFIED;
        Qos.ReceivingFlowspec.TokenBucketSize   = QOS_NOT_SPECIFIED; 
        Qos.ReceivingFlowspec.PeakBandwidth     = QOS_NOT_SPECIFIED;
        Qos.ReceivingFlowspec.MinimumPolicedSize = QOS_NOT_SPECIFIED;
        Qos.ReceivingFlowspec.MaxSduSize        = QOS_NOT_SPECIFIED;
        Qos.ProviderSpecific.len =              0;
        Qos.ProviderSpecific.buf =              NULL;

        if(AddFlow)
        {
            // Non-blocking SIO_SET_QOS

            result = 
            WSAIoctl(s,
                     SIO_SET_QOS, 
                     &Qos,
                     sizeof(QOS),
                     NULL,
                     0, 
                     &BytesRet, 
                     NULL,
                     NULL);


            if ( result != NO_ERROR )
            {
                DisplayError ( "WSAIoctl SIO_SET_QOS Failed", GetLastError() ); 
                __leave;
            }

            qosol.s = s;
            qosol.hDlg = hDlg;

            // Overlapped SIO_GET_QOS with completion routine callback

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
                    __leave;
                }
            }
            
    
        }

        WsaBuf.len = DATA_SIZE;
        WsaBuf.buf= (char*)malloc(DATA_SIZE);
        
        lpWsaBuf = &WsaBuf;
        
        Flags = 0;

        /* Recv */

        TotalBytes = 0;
        do
        {
            result =
                WSARecv( s, lpWsaBuf, 1, &RecvBytes, &Flags, &wsol,NULL );

            if ( result == SOCKET_ERROR )
            {
                DWORD dwError;
                dwError = WSAGetLastError();
                if (dwError != ERROR_IO_PENDING )
                {
                    DisplayError ( "WSARecv", dwError ); 
                    __leave;
                }
            }
            
            // we need the alertable wait to get QoS notification callbacks

            if (WSAWaitForMultipleEvents(
                        1, 
                        &wsevent, 
                        TRUE, 
                        WSA_INFINITE, 
                        TRUE
                        ) == WSA_WAIT_FAILED ) 
            {

                DisplayError ( "WSAWaitForMultipleEvents Failed", WSAGetLastError() ); 
                __leave;
            } 

            if (WSAGetOverlappedResult(
                        s, 
                        &wsol, 
                        &RecvBytes, 
                        TRUE, 
                        &Flags
                        ) == FALSE ) 
            {

                DisplayError ( "WSAGetOverlappedResult Failed", WSAGetLastError() ); 
                __leave;
            }

            /* First time only op */
            if(TotalBytes == 0)
            {
                End = (int)(lpWsaBuf->buf[0]);
                SendMessage( GetDlgItem ( hDlg, IDC_PROGRESS), PBM_SETRANGE, 0, MAKELPARAM(0, End) );
            }

            TotalBytes += RecvBytes;

             
            if(RecvBytes == 0)
            {
                // Got a 0 byte, the other end point has closed, bailing...
                
                __leave;
            }
            RecvBytes = 0;

            SendMessage( GetDlgItem ( hDlg, IDC_PROGRESS), PBM_SETPOS,  TotalBytes / DATA_SIZE, 0 ); 

            memset( &wsol, 0, sizeof(WSAOVERLAPPED) );
            wsol.hEvent = wsevent;
            WSAResetEvent( wsevent );
        
        } while ( TotalBytes < End*DATA_SIZE );

        // We don't really need to Sleep here.
        // For demo purpose, just delay closing socket to catch the tear message for the other side
        
        SleepEx ( 1000, TRUE );
    }
    __finally
    {

        if ( wsevent != NULL ) WSACloseEvent ( wsevent );

        if ( s != INVALID_SOCKET ) closesocket(s);

        if ( WsaBuf.buf ) free ( WsaBuf.buf );

    }

    EnableWindow ( GetDlgItem ( hDlg, IDC_NonQoS_BUTTON ) , TRUE );
    EnableWindow ( GetDlgItem ( hDlg, IDC_QoS_BUTTON ) , TRUE );

    return 1;
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
    
    TCHAR   szError [1024];
    DWORD   result, BytesRet;
    EOL     *pEOL;

    
    pEOL = (EOL *)lpOverlapped;
    
    if ( !pEOL->hDlg ) return;

    switch  (dwError)
    {

        case  WSA_QOS_RECEIVERS:  
         /* at least one Reserve has arrived */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"RESV arrived: WSA_QOS_RECEIVERS " );
            DisplayQoSInList ( pEOL->hDlg, IDC_STATUS_LIST, (QOS *)Buffer );
            break;

        case  WSA_QOS_SENDERS: 
         /* at least one Path has arrived */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"PATH arrived: WSA_QOS_SENDERS " );
            DisplayQoSInList ( pEOL->hDlg, IDC_STATUS_LIST, (QOS *)Buffer );
            break;

        case  WSA_QOS_NO_SENDERS:             
         /* there are no senders */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"PATH_TEAR: WSA_QOS_NO_SENDERS " );
            break;

        case  WSA_QOS_NO_RECEIVERS:
         /* there are no receivers */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"RESV_TEAR: WSA_QOS_NO_RECEIVERS " );
            break;

        case  WSA_QOS_REQUEST_CONFIRMED:
         /* Reserve has been confirmed */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"RESV_CONFIRM: WSA_QOS_REQUEST_CONFIRMED " );
            DisplayQoSInList ( pEOL->hDlg, IDC_STATUS_LIST, (QOS *)Buffer );
            break;

        case  WSA_QOS_ADMISSION_FAILURE:      
         /* error due to lack of resources */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_ADMISSION_FAILURE " );
            break;

        case  WSA_QOS_POLICY_FAILURE:         
         /* rejected for administrative reasons - bad credentials */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_POLICY_FAILURE " );
            break;

        case  WSA_QOS_BAD_STYLE:               
         /* unknown or conflicting style */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_BAD_STYLE " );
            break;

        case  WSA_QOS_BAD_OBJECT:              
         /* problem with some part of the filterspec or providerspecific
          * buffer in general */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_BAD_OBJECT " );
            break;

        case  WSA_QOS_TRAFFIC_CTRL_ERROR:     
         /* problem with some part of the flowspec */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_TRAFFIC_CTRL_ERROR " );
            break;

        case  WSA_QOS_GENERIC_ERROR:           
         /* general error */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_GENERIC_ERROR " );
            break;

        case  WSA_QOS_ESERVICETYPE:            
         /* invalid service type in flowspec */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_ESERVICETYPE " );
            break;

        case  WSA_QOS_EFLOWSPEC:               
         /* invalid flowspec */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EFLOWSPEC " );
            break;

        case  WSA_QOS_EPROVSPECBUF:            
         /* invalid provider specific buffer */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EPROVSPECBUF " );
            break;

        case  WSA_QOS_EFILTERSTYLE:            
         /* invalid filter style */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EFILTERSTYLE " );
            break;

        case  WSA_QOS_EFILTERTYPE:             
         /* invalid filter type */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EFILTERTYPE " );
            break;

        case  WSA_QOS_EFILTERCOUNT:           
         /* incorrect number of filters */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EFILTERCOUNT " );
            break;

        case  WSA_QOS_EOBJLENGTH:              
         /* invalid object length */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EOBJLENGTH " );
            break;

        case  WSA_QOS_EFLOWCOUNT:              
         /* incorrect number of flows */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EFLOWCOUNT " );
            break;

        case  WSA_QOS_EUNKOWNPSOBJ:            
         /* unknown object in provider specific buffer */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EUNKOWNPSOBJ " );
            break;

        case  WSA_QOS_EPOLICYOBJ:              
         /* invalid policy object in provider specific buffer */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EPOLICYOBJ " );
            break;

        case  WSA_QOS_EFLOWDESC:               
         /* invalid flow descriptor in the list */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EFLOWDESC " );
            break;

        case  WSA_QOS_EPSFLOWSPEC:             
         /* inconsistent flow spec in provider specific buffer */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EPSFLOWSPEC " );
            break;

        case  WSA_QOS_EPSFILTERSPEC:           
         /* invalid filter spec in provider specific buffer */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_EPSFILTERSPEC " );
            break;

        case  WSA_QOS_ESDMODEOBJ:              
         /* invalid shape discard mode object in provider specific buffer */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_ESDMODEOBJ " );
            break;

        case  WSA_QOS_ESHAPERATEOBJ:           
         /* invalid shaping rate object in provider specific buffer */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_ESHAPERATEOBJ " );
            break;

        case  WSA_QOS_RESERVED_PETYPE :        
         /* reserved policy element in provider specific buffer */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"WSA_QOS_RESERVED_PETYPE " );
            break;

        case  ERROR_OPERATION_ABORTED: 
         /* overlapped SIO_GET_QOS aborted */
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)"overlapped SIO_GET_QOS aborted " );
            break;

        default:
            wsprintf(szError, "Unknown SIO_GET_QOS completion error %d", dwError);
            SendDlgItemMessage ( pEOL->hDlg, IDC_STATUS_LIST, LB_ADDSTRING, 0, (LPARAM)szError );
            return;
    }


    memset ( lpOverlapped, 0, sizeof (WSAOVERLAPPED) );
    
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
            DisplayError ( "Please Exit Process! WSAIoctl SIO_GET_QOS", dwError ); 
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

static void PrintFlowspec(FLOWSPEC *pFlowspec, CHAR *lpszIndent, HWND hDlg, int nIDDlgItem)
    {
    TCHAR szTemp [1024];
    TCHAR szIndent[24];


    strncpy(szIndent, lpszIndent, sizeof(szIndent));
    strncat(szIndent, "  ", sizeof(szIndent));
    szIndent[sizeof(szIndent)-1] = '\0';


    if (QOS_NOT_SPECIFIED == pFlowspec->TokenRate)
        wsprintf(szTemp, "%sTokenRate          = QOS_NOT_SPECIFIED", szIndent);
    else
        wsprintf(szTemp, "%sTokenRate          = %d", szIndent, pFlowspec->TokenRate);
    
    SendDlgItemMessage ( hDlg, nIDDlgItem, LB_ADDSTRING, 0, (LPARAM)szTemp );

    if (QOS_NOT_SPECIFIED == pFlowspec->TokenBucketSize)
        wsprintf(szTemp, "%sTokenBucketSize    = QOS_NOT_SPECIFIED", szIndent);
    else
        wsprintf(szTemp, "%sTokenBucketSize    = %d", szIndent, pFlowspec->TokenBucketSize);
    
    SendDlgItemMessage ( hDlg, nIDDlgItem, LB_ADDSTRING, 0, (LPARAM)szTemp );

    if (QOS_NOT_SPECIFIED == pFlowspec->PeakBandwidth)
        wsprintf(szTemp, "%sPeakBandwidth      = QOS_NOT_SPECIFIED", szIndent);
    else
        wsprintf(szTemp, "%sPeakBandwidth      = %d", szIndent, pFlowspec->PeakBandwidth);

    SendDlgItemMessage ( hDlg, nIDDlgItem, LB_ADDSTRING, 0, (LPARAM)szTemp );

    if (QOS_NOT_SPECIFIED == pFlowspec->Latency)
        wsprintf(szTemp, "%sLatency            = QOS_NOT_SPECIFIED", szIndent);
    else
        wsprintf(szTemp, "%sLatency            = %d", szIndent, pFlowspec->Latency);

    SendDlgItemMessage ( hDlg, nIDDlgItem, LB_ADDSTRING, 0, (LPARAM)szTemp );

    if (QOS_NOT_SPECIFIED == pFlowspec->DelayVariation)
        wsprintf(szTemp, "%sDelayVariation     = QOS_NOT_SPECIFIED", szIndent);
    else
        wsprintf(szTemp, "%sDelayVariation     = %d", szIndent, pFlowspec->DelayVariation);

    SendDlgItemMessage ( hDlg, nIDDlgItem, LB_ADDSTRING, 0, (LPARAM)szTemp );

    wsprintf(szTemp, "%sServiceType        = %s", 
        szIndent, ServiceTypeToStr(pFlowspec->ServiceType));

    SendDlgItemMessage ( hDlg, nIDDlgItem, LB_ADDSTRING, 0, (LPARAM)szTemp );

    if (QOS_NOT_SPECIFIED == pFlowspec->MaxSduSize)
        wsprintf(szTemp, "%sMaxSduSize         = QOS_NOT_SPECIFIED", szIndent);
    else
        wsprintf(szTemp, "%sMaxSduSize         = %d", szIndent, pFlowspec->MaxSduSize);

    SendDlgItemMessage ( hDlg, nIDDlgItem, LB_ADDSTRING, 0, (LPARAM)szTemp );

    if (QOS_NOT_SPECIFIED == pFlowspec->MinimumPolicedSize)
        wsprintf(szTemp, "%sMinimumPolicedSize = QOS_NOT_SPECIFIED", szIndent);
    else
        wsprintf(szTemp, "%sMinimumPolicedSize = %d", szIndent, pFlowspec->MinimumPolicedSize);

    SendDlgItemMessage ( hDlg, nIDDlgItem, LB_ADDSTRING, 0, (LPARAM)szTemp );

    return;
    }



void DisplayQoSInList (HWND hDlg, int nIDDlgItem, QOS *qos)
{

    if (NULL == qos) return;

    SendDlgItemMessage ( hDlg, nIDDlgItem, LB_ADDSTRING, 0, (LPARAM)"SendingFlowSpec" );
    PrintFlowspec( &qos->SendingFlowspec, "    ", hDlg, nIDDlgItem );
    SendDlgItemMessage ( hDlg, nIDDlgItem, LB_ADDSTRING, 0, (LPARAM)"ReceivingFlowspec" );
    PrintFlowspec( &qos->SendingFlowspec, "    ", hDlg, nIDDlgItem );

    return;

}
