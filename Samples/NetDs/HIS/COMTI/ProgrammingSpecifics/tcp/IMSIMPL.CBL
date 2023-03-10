      **************************************************************     
      * IMS COBOL COMPLETING CLIENT STUB                           *     
      **************************************************************     
       IDENTIFICATION DIVISION.                                          
       PROGRAM-ID. IMSIMPL.                                              
                                                                         
       ENVIRONMENT DIVISION.                                             
                                                                         
       DATA DIVISION.                                                    
                                                                         
       WORKING-STORAGE SECTION.                                          
      **************************************************************       
      * USER DATA DEFINITIONS.                                     *     
      **************************************************************     
       01  DATA-AREA.
           05  LL                               PIC S9(4) COMP.
           05  ZZ                               PIC S9(4) COMP.
           05  USER-DATA                        PIC X(32755).

       01  IMS-VALUES.
           02  END-OF-MSG     PIC X(2)       VALUE 'QD'.
           02  QUEUE-EMPTY    PIC X(2)       VALUE 'QC'.
           02  GU             PIC X(4)       VALUE 'GU  '.
           02  GN             PIC X(4)       VALUE 'GN  '.
           02  ISRT           PIC X(4)       VALUE 'ISRT'.

       01  DONE                                       PIC X VALUE 'N'.
       01  STR-STATUS-CODE                            PIC X(2).
       01  COMP-STATUS-CODE REDEFINES STR-STATUS-CODE PIC S9(4) COMP.
       01  RECV-DATA-LEN                              PIC S9(4) COMP.
       01  COMP-STATUS-CODE-DISP                      PIC S9(8).

       01  I                                          PIC S9(4) COMP.
       01  HEX-BYTE-VALUE-DISP                        PIC  9(4).
       01  HEX-BYTE-VALUE                             PIC S9(4) COMP.
       01  FILLER REDEFINES HEX-BYTE-VALUE.
           05 FILLER                                  PIC X.
           05 HEX-BYTE                                PIC X.

       LINKAGE SECTION.                                                  
       01  IOTP-PCB.                                                     
           05  IOTP-LTERM                           PIC X(8).            
           05  IOTP-RESERVED                        PIC X(2).            
           05  IOTP-STATUS                          PIC X(2).            
           05  IOTP-PREFIX.                                              
               10  IOTP-DATE                        PIC S9(7) COMP-3.    
               10  IOTP-TIME                        PIC S9(7) COMP-3.    
               10  IOTP-MSG-NUMBER                  PIC S9(4) COMP.      
               10  FILLER                           PIC X(2).            
           05  IOTP-MOD-NAME                        PIC X(8).            
           05  IOTP-USER-ID                         PIC X(8).            
                                                                         
       PROCEDURE DIVISION.                                               
           ENTRY 'DLITCBL' USING IOTP-PCB.                               

           DISPLAY 'IMSIMPL SERVER STARTED'.

      ****************************************************
      * CONTINUE GETTING MESSAGES FROM THE MESSAGE QUEUE *
      * UNTIL THERE ARE NO MORE. THIS ALSO ENSURES THAT  *
      * A GU IS ALWAYS ISSUED TO FORCE THE ASSIST MODULE *
      * TO SEND THE EOM AND CSMOKY TO COMTI FOR THE PRIOR*
      * REQUEST.                                         *
      ****************************************************
           PERFORM UNTIL DONE = 'Y'
              PERFORM GET-MESSAGE THRU GET-MESSAGE-EXIT
              IF DONE NOT = 'Y'
                 PERFORM CHECK-FOR-LAST-SEG THRU 
                         CHECK-FOR-LAST-SEG-EXIT
 
                 PERFORM PROCESS-REQUEST THRU 
                         PROCESS-REQUEST-EXIT

                 PERFORM SEND-REPLY THRU 
                         SEND-REPLY-EXIT
              END-IF
           END-PERFORM.

           GO TO EXIT-THE-PROGRAM.

      ****************************************************
      * GET THE FIRST DATA SEGMENT. THE ASSIST MODULE    *
      * REMOVES THE TRANSACTION ID THAT WAS DELIVERED    *
      * IN THE TCP TRM. THEREFORE THE RECEIVED DATA IS   *
      * THE REAL USER DATA.                              *
      ****************************************************
       GET-MESSAGE.
           CALL 'CBLADLI' USING GU IOTP-PCB DATA-AREA.

           IF IOTP-STATUS = QUEUE-EMPTY
              DISPLAY 'IMSIMPL GU QUEUE EMPTY, IOTP-STATUS = '
                      QUEUE-EMPTY
              MOVE 'Y' TO DONE
              GO TO GET-MESSAGE-EXIT
           END-IF.

           IF IOTP-STATUS = 'ZZ'
              MOVE IOTP-RESERVED TO STR-STATUS-CODE
              IF COMP-STATUS-CODE >= 0
      *          TCP ERROR
                 MOVE COMP-STATUS-CODE TO COMP-STATUS-CODE-DISP
                 DISPLAY 'IMSIMPL GU CALL FAILED, TCP ERROR = '
                                    COMP-STATUS-CODE-DISP
              ELSE
      *          IMS ERROR CODE
                 DISPLAY 'IMSIMPL GU CALL FAILED IOTP-RESERVED= '
                         IOTP-RESERVED
              END-IF
              MOVE 'Y' TO DONE
              GO TO GET-MESSAGE-EXIT
           END-IF.

           IF IOTP-STATUS NOT = ' '
              DISPLAY 'IMSIMPL GU CALL FAILED IOTP-STATUS = '
                      IOTP-STATUS
              MOVE 'Y' TO DONE
              GO TO GET-MESSAGE-EXIT
           END-IF.

           DISPLAY 'IMSIMPL GU LTERM="' IOTP-LTERM '"'.
           DISPLAY 'IMSIMPL GU DATA LEN=' LL OF DATA-AREA.
           DISPLAY 'IMSIMPL RECEIVED FROM CLIENT=' USER-DATA(1:50).

           IF USER-DATA(1:8) = '*LISTNR*'
              COMPUTE RECV-DATA-LEN = 0
           ELSE
              COMPUTE RECV-DATA-LEN = LL -
                                      LENGTH OF LL -
                                      LENGTH OF ZZ
           END-IF.

       GET-MESSAGE-EXIT.
           EXIT.

      ****************************************************
      * THIS SHOULD RETURN A QD
      ****************************************************
       CHECK-FOR-LAST-SEG.
           CALL 'CBLADLI' USING GN IOTP-PCB DATA-AREA.

           IF IOTP-STATUS = 'ZZ'
              MOVE IOTP-RESERVED TO STR-STATUS-CODE
              IF COMP-STATUS-CODE >= 0
      *          TCP ERROR
                 MOVE COMP-STATUS-CODE TO COMP-STATUS-CODE-DISP
                 DISPLAY 'IMSIMPL GN CALL FAILED, TCP ERROR = '
                                    COMP-STATUS-CODE-DISP
              ELSE
      *          IMS ERROR CODE
                 DISPLAY 'IMSIMPL GN CALL FAILED IOTP-RESERVED= '
                         IOTP-RESERVED
              END-IF
              GO TO EXIT-THE-PROGRAM
           END-IF.

           IF IOTP-STATUS  = 'QD'
              DISPLAY 'IMSIMPL GN CALL RETURNED QD'
           ELSE
              IF IOTP-STATUS NOT = ' '
                 DISPLAY 'IMSIMPL GN CALL FAILED IOTP-STATUS = '
                         IOTP-STATUS
              ELSE
                 DISPLAY 'IMSIMPL GN INPUT LEN=' LL OF DATA-AREA
              END-IF
              GO TO EXIT-THE-PROGRAM
           END-IF.

       CHECK-FOR-LAST-SEG-EXIT.
           EXIT.

      ****************************************************
      * PROCESS THE REQUEST DATA
      ****************************************************
       PROCESS-REQUEST.

      * USER DATA RECEIVED IS IN USER-DATA
      * LENGTH OF USER DATA RECEIVED IS IN RECV-DATA-LEN

       PROCESS-REQUEST-EXIT.
           EXIT.

      ****************************************************
      * SEND THE REPLY DATA
      ****************************************************
       SEND-REPLY.
           COMPUTE LL  = RECV-DATA-LEN +
                         LENGTH OF LL +
                         LENGTH OF ZZ.

           PERFORM INSERT-RESP THRU INSERT-RESP-EXIT.

       SEND-REPLY-EXIT.
           EXIT.

      ****************************************************
      * ISSUE THE INSERT DLI COMMAND
      ****************************************************
       INSERT-RESP.
           CALL 'CBLADLI' USING ISRT IOTP-PCB DATA-AREA.

           IF IOTP-STATUS = 'ZZ'
              MOVE IOTP-RESERVED TO STR-STATUS-CODE
              IF COMP-STATUS-CODE >= 0
      *          TCP ERROR
                 MOVE COMP-STATUS-CODE TO COMP-STATUS-CODE-DISP
                 DISPLAY 'IMSIMPL ISRT CALL FAILED, TCP ERROR = '
                                    COMP-STATUS-CODE-DISP
              ELSE
      *          IMS ERROR CODE
                 DISPLAY 'IMSIMPL ISRT CALL FAILED IOTP-RESERVED= '
                         IOTP-RESERVED
              END-IF
              GO TO EXIT-THE-PROGRAM
           END-IF.

           IF IOTP-STATUS NOT = ' '
              DISPLAY 'IMSIMPL ISRT FAILED IOTP-STATUS = '
                       IOTP-STATUS
              GO TO EXIT-THE-PROGRAM
           END-IF.

       INSERT-RESP-EXIT.
           EXIT.

      ****************************************************
      * EXIT THE PROGRAM
      ****************************************************
       EXIT-THE-PROGRAM.
           DISPLAY 'IMSIMPL SERVER ENDED'.
           GOBACK.
