       IDENTIFICATION DIVISION.
       PROGRAM-ID. CICSCS.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
      *****************************************************************
      ** MVS TCP/IP REQUIRED DEFINITIONS                              *
      *****************************************************************
       01 SOKET-FUNCTIONS.
          05 SOKET-CLOSE           PIC X(16) VALUE 'CLOSE           '.
          05 SOKET-RECV            PIC X(16) VALUE 'RECV            '.
          05 SOKET-SHUTDOWN        PIC X(16) VALUE 'SHUTDOWN        '.
          05 SOKET-TAKESOCKET      PIC X(16) VALUE 'TAKESOCKET      '.
          05 SOKET-WRITE           PIC X(16) VALUE 'WRITE           '.

       01 TCP-FLAGS-CONSTANTS.
          05 TCP-FLAGS-NO-FLAG              PIC S9(4) COMP VALUE 0.
          05 TCP-FLAGS-OOB                  PIC S9(4) COMP VALUE 1.
          05 TCP-FLAGS-PEEK                 PIC S9(4) COMP VALUE 2.

       01 TCP-HOW                           PIC 9(8) COMP.
       01 TCP-HOW-CODES.
          05 THC-END-FROM                   PIC 9(8) COMP VALUE 0.
          05 THC-END-TO                     PIC 9(8) COMP VALUE 1.
          05 THC-END-BOTH                   PIC 9(8) COMP VALUE 2.

       01 CLIENT-IN-DATA                    PIC X(35).
       01 FILLER REDEFINES CLIENT-IN-DATA.
          05 CID-USERID                     PIC X(8).
          05 CID-PASSWORD                   PIC X(8).
          05 FILLER                         PIC X(19).

       01 TCPSOCKET-PARM.
          05 GIVE-TAKE-SOCKET               PIC 9(8) COMP.
          05 LSTN-NAME                      PIC X(8).
          05 LSTN-SUBTASKNAME               PIC X(8).
          05 LSTN-CLIENT-IN-DATA            PIC X(35).
          05 FILLER                         PIC X(1).
          05 SOCKADDR-IN.
             10 SIN-FAMILY                  PIC 9(4)  COMP.
             10 SIN-PORT                    PIC 9(4)  COMP.
             10 SIN-ADDR                    PIC 9(8)  COMP.
             10 SIN-ZERO                    PIC X(8).

       01 AF-INET                           PIC 9(8)  COMP VALUE 2.
       01 LISTENER-ID.
          05 LI-DOMAIN                      PIC 9(8)  COMP.
          05 LI-NAME                        PIC X(8).
          05 LI-SUBTASKNAME                 PIC X(8).
          05 LI-RESERVED                    PIC X(20).

       01 TCP-IDENT.
          05 TCP-IDENT-TCPNAME              PIC X(8)  VALUE 'TCPIP31'.
          05 TCP-IDENT-ADSNAME              PIC X(8)  VALUE SPACES.

       01 TCP-SUBTASK.
          05 TCP-SUBTASK-NUM                PIC 9(7).
          05 TCP-SUBTASK-CHAR               PIC X.

       01 TCP-MAXSNO                        PIC 9(8)  COMP.
       01 TCP-MAXSOC                        PIC 9(4)  COMP  VALUE 50.
       01 TCP-SOCKET                        PIC 9(4)  COMP.
       01 TCP-FLAGS                         PIC 9(8)  COMP.
       01 TCP-NBYTES                        PIC 9(8)  COMP.
       01 TCP-ERRNO                         PIC 9(8)  COMP.
       01 TCP-RETCODE                       PIC S9(8) COMP.

       01 TCP-BUF                           PIC X(32776)  VALUE SPACES.
       01 FILLER REDEFINES TCP-BUF.
          05 TCP-BUF-CHAR OCCURS 32776 TIMES PIC X.

       01 TRACE-ID                      PIC S9(4) COMP VALUE 0.
       01 TRACE-POINTS-IDS.
          05 TP-RETRIEVE-1              PIC S9(4) COMP VALUE 1.
          05 TP-RETRIEVE-2              PIC S9(4) COMP VALUE 2.
          05 TP-TAKESOC-1               PIC S9(4) COMP VALUE 3.
          05 TP-RECVREQ-1               PIC S9(4) COMP VALUE 4.
          05 TP-RECV-1                  PIC S9(4) COMP VALUE 5.
          05 TP-RECV-2                  PIC S9(4) COMP VALUE 6.
          05 TP-RECV-3                  PIC S9(4) COMP VALUE 7.
          05 TP-WRI2SOC-2               PIC S9(4) COMP VALUE 8.
          05 TP-WRI2SOC-3               PIC S9(4) COMP VALUE 9.
          05 TP-BUF2SOC-1               PIC S9(4) COMP VALUE 10.
          05 TP-SHUTDOWN-1              PIC S9(4) COMP VALUE 11.
          05 TP-CLOSE-1                 PIC S9(4) COMP VALUE 12.

       01 CICSCS-VERSION.
          05 CV-LEN                         PIC S9(4) COMP VALUE 0.
          05 FILLER                         PIC X(8)
              VALUE 'CICSCS'.
          05 FILLER                         PIC X(1)  VALUE SPACE.
          05 FILLER                         PIC X(17)
              VALUE 'CONCURRENT SERVER'.

       01 ENABLE-LOGGING                    PIC X          VALUE 'N'.
          88 LOGGING-IS-ENABLED                            VALUE 'Y'.
          88 LOGGING-IS-DISABLED                           VALUE 'N'.
       01 SOCKET-OPENED                     PIC X          VALUE 'N'.
          88 SOCKET-IS-OPENED                              VALUE 'Y'.
          88 SOCKET-IS-CLOSED                              VALUE 'N'.

       01 HW-LENGTH                         PIC 9(4)  COMP.
       01 BUF-BYTE-INDEX                    PIC S9(8) COMP VALUE 0.
       01 BYTES-RECEIVED                    PIC S9(8) COMP.
       01 BYTES-TO-SEND                     PIC S9(8) COMP.
       01 SNDRCV-BUF-LEN                    PIC S9(8) COMP.
       01 SNDRCV-BUF-AT-BYTE                PIC S9(8) COMP VALUE 0.

       01 EDIT-NUM-8                        PIC +9(8).
       01 EDIT-NUM-8-1                      PIC +9(8).
       01 EDIT-NUM-8-NS                     PIC 9(8).
       01 EDIT-NUM-15                       PIC +9(12).
       01 CMD-RESP                          PIC S9(8) COMP.

       01 LOG-MSG.
          05 LOG-ID                         PIC X(7)   VALUE 'TASK #'.
          05 TASK-NUMBER                    PIC 9(7).
          05 FILLER                         PIC X      VALUE SPACE.
          05 LOG-MSG-BUFFER                 PIC X(80) VALUE SPACES.

       01 TCP-ERROR-INFO.
          05  TCP-ERROR-MSG             PIC X(24).
          05  FILLER                    PIC X(9) VALUE ' RETCODE='.
          05  TCP-ERROR-RETCODE         PIC +9(4).
          05  FILLER                    PIC X(7) VALUE ' ERRNO='.
          05  TCP-ERROR-ERRNO           PIC +9(6).

       01 CURRENT-STATE                 PIC S9(4) COMP VALUE 0.
       01 NEXT-STATE                    PIC S9(4) COMP VALUE 9.
       01 SERVER-STATES.
          05 SS-RETR-TIM                PIC S9(4) COMP VALUE 0.
          05 SS-TAKE-SOCKET             PIC S9(4) COMP VALUE 1.
          05 SS-SEND-TRM-REPLY          PIC S9(4) COMP VALUE 2.
          05 SS-RECV-REQUEST            PIC S9(4) COMP VALUE 3.
          05 SS-PROCESS-REQUEST         PIC S9(4) COMP VALUE 4.
          05 SS-SEND-REPLY              PIC S9(4) COMP VALUE 5.
          05 SS-SHUTDOWN                PIC S9(4) COMP VALUE 6.
          05 SS-CLOSE-SOCKET            PIC S9(4) COMP VALUE 7.
          05 SS-DONE                    PIC S9(4) COMP VALUE 8.

       01 CHILD-SERVER-ERROR            PIC S9(4) COMP VALUE 0.
       01 CS-ERRORS.
          05 CS-ERROR-NO-ERROR          PIC S9(4) COMP VALUE 0.
          05 CS-ERROR-UNKNOWN-STATE     PIC S9(4) COMP VALUE -1.
          05 CS-ERROR-BAD-RETRIEVE      PIC S9(4) COMP VALUE -2.
          05 CS-ERROR-TAKESOCKET-FAILED PIC S9(4) COMP VALUE -3.
          05 CS-ERROR-WRITE-FAILED      PIC S9(4) COMP VALUE -4.
          05 CS-ERROR-RECV-FAILED       PIC S9(4) COMP VALUE -5.
          05 CS-ERROR-CICS-INVREQ       PIC S9(4) COMP VALUE -6.
          05 CS-ERROR-CICS-IOREQ        PIC S9(4) COMP VALUE -7.
          05 CS-ERROR-CICS-LENGERR      PIC S9(4) COMP VALUE -8.
          05 CS-ERROR-CICS-ENDDATA      PIC S9(4) COMP VALUE -9.
          05 CS-ERROR-SHUTDOWN          PIC S9(4) COMP VALUE -12.

      *****************************************************************
      *  PROCEDURE DIVISION AND MAINLINE CODE                         *
      *****************************************************************
       PROCEDURE DIVISION.
           EXEC CICS HANDLE CONDITION INVREQ  (INVREQ-ERR-SEC)
                                      IOERR   (IOERR-SEC)
                                      ENDDATA (ENDDATA-SEC)
                                      LENGERR (LENGERR-SEC)
                                      END-EXEC.

           MOVE 'CONCURRENT SERVER STARTED' TO LOG-MSG-BUFFER.
           PERFORM WRITE-LOG-MSG.

           PERFORM UNTIL CURRENT-STATE = SS-DONE
              EVALUATE CURRENT-STATE
                 WHEN SS-RETR-TIM
                      PERFORM RETRIEVE-THE-TIM THRU
                              RETRIEVE-THE-TIM-EXIT
                      IF CHILD-SERVER-ERROR < 0 THEN
                         MOVE SS-CLOSE-SOCKET TO NEXT-STATE
                      ELSE
                         MOVE SS-TAKE-SOCKET TO NEXT-STATE
                      END-IF

                 WHEN SS-TAKE-SOCKET
                      PERFORM TAKE-THE-SOCKET THRU
                              TAKE-THE-SOCKET-EXIT
                      IF CHILD-SERVER-ERROR < 0 THEN
                         MOVE SS-CLOSE-SOCKET TO NEXT-STATE
                      ELSE
                         MOVE SS-SEND-TRM-REPLY TO NEXT-STATE
                      END-IF

                 WHEN SS-SEND-TRM-REPLY
                      PERFORM SEND-TRM-REPLY THRU
                              SEND-TRM-REPLY-EXIT
                      IF CHILD-SERVER-ERROR < 0 THEN
                         MOVE SS-CLOSE-SOCKET TO NEXT-STATE
                      ELSE
                         MOVE SS-RECV-REQUEST TO NEXT-STATE
                      END-IF

                 WHEN SS-RECV-REQUEST
                      PERFORM RECEIVE-REQUEST THRU
                              RECEIVE-REQUEST-EXIT
                      IF CHILD-SERVER-ERROR < 0 THEN
                         MOVE SS-CLOSE-SOCKET TO NEXT-STATE
                      ELSE
                         MOVE SS-PROCESS-REQUEST   TO NEXT-STATE
                      END-IF

                 WHEN SS-PROCESS-REQUEST
                      PERFORM PROCESS-REQUEST THRU
                              PROCESS-REQUEST-EXIT
                      IF CHILD-SERVER-ERROR < 0 THEN
                         MOVE SS-CLOSE-SOCKET TO NEXT-STATE
                      ELSE
                         MOVE SS-SEND-REPLY TO NEXT-STATE
                      END-IF

                 WHEN SS-SEND-REPLY
                      PERFORM SEND-REPLY THRU
                              SEND-REPLY-EXIT
                      IF CHILD-SERVER-ERROR < 0 THEN
                         MOVE SS-CLOSE-SOCKET TO NEXT-STATE
                      ELSE
                         MOVE SS-SHUTDOWN TO NEXT-STATE
                      END-IF

                 WHEN SS-SHUTDOWN
                      PERFORM SHUTDOWN-SOCKET THRU
                              SHUTDOWN-SOCKET-EXIT
                      MOVE SS-CLOSE-SOCKET TO NEXT-STATE

                 WHEN SS-CLOSE-SOCKET
                      PERFORM CLOSE-THE-SOCKET THRU
                              CLOSE-THE-SOCKET-EXIT
                      MOVE SS-DONE TO NEXT-STATE

                 WHEN OTHER
                      MOVE CS-ERROR-UNKNOWN-STATE TO CHILD-SERVER-ERROR
                      MOVE SS-CLOSE-SOCKET TO NEXT-STATE
              END-EVALUATE

              MOVE NEXT-STATE TO CURRENT-STATE
           END-PERFORM.

           GO TO EXIT-THE-PROGRAM.

      *****************************************************************
      *  RETREIVE THE TRANSACTION INITIATION MESSAGE FROM THE IBM     *
      *  SUPPLIED DEFAULT LISTENER                                    *
      *****************************************************************
       RETRIEVE-THE-TIM.
           MOVE LENGTH OF TCPSOCKET-PARM TO HW-LENGTH.
           EXEC CICS RETRIEVE INTO(TCPSOCKET-PARM)
                              LENGTH(HW-LENGTH)
                              END-EXEC.

           IF HW-LENGTH NOT = LENGTH OF TCPSOCKET-PARM THEN
              MOVE TP-RETRIEVE-1 TO TRACE-ID
              PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT
              MOVE CS-ERROR-BAD-RETRIEVE TO CHILD-SERVER-ERROR
              GO TO RETRIEVE-THE-TIM-EXIT
           END-IF.

           MOVE LSTN-CLIENT-IN-DATA TO CLIENT-IN-DATA.

           MOVE TP-RETRIEVE-2 TO TRACE-ID.
           PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT.

       RETRIEVE-THE-TIM-EXIT.
           EXIT.

      *****************************************************************
      *   ISSUE 'TAKESOCKET' CALL TO ACQUIRE A SOCKET WHICH WAS       *
      *   GIVEN BY THE LISTENER PROGRAM.                              *
      *****************************************************************
       TAKE-THE-SOCKET.
           MOVE AF-INET          TO LI-DOMAIN.
           MOVE LSTN-NAME        TO LI-NAME.
           MOVE LSTN-SUBTASKNAME TO LI-SUBTASKNAME.
           MOVE LOW-VALUES       TO LI-RESERVED.

           MOVE GIVE-TAKE-SOCKET TO TCP-SOCKET.
           MOVE ZERO             TO TCP-ERRNO TCP-RETCODE.
           CALL 'EZASOKET' USING SOKET-TAKESOCKET
                                 TCP-SOCKET
                                 LISTENER-ID
                                 TCP-ERRNO
                                 TCP-RETCODE.

           IF TCP-RETCODE < 0 THEN
              MOVE TP-TAKESOC-1 TO TRACE-ID
              PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT
              MOVE CS-ERROR-TAKESOCKET-FAILED TO CHILD-SERVER-ERROR
              GO TO TAKE-THE-SOCKET-EXIT
           END-IF.

           MOVE 'Y'         TO SOCKET-OPENED.
           MOVE TCP-RETCODE TO TCP-SOCKET.

       TAKE-THE-SOCKET-EXIT.
           EXIT.

      *****************************************************************
      *   ISSUE 'WRITE' TO SEND THE TRM REPLY                         *
      *****************************************************************
       SEND-TRM-REPLY.
      *****************************************************************
           MOVE LENGTH OF CICSCS-VERSION TO CV-LEN.
           MOVE CICSCS-VERSION TO TCP-BUF.

           MOVE CV-LEN TO SNDRCV-BUF-LEN.
           PERFORM WRITE-BUF-TO-SOCKET THRU
                   WRITE-BUF-TO-SOCKET-EXIT.
           IF CHILD-SERVER-ERROR < 0 THEN
              GO TO SEND-TRM-REPLY-EXIT
           END-IF.

       SEND-TRM-REPLY-EXIT.
           EXIT.

      *****************************************************************
      *  SHUTDOWN THE SENDING SIDE OF THE SOCKET                      *
      *****************************************************************
       SHUTDOWN-SOCKET.
           MOVE THC-END-TO TO TCP-HOW.
           CALL 'EZASOKET' USING SOKET-SHUTDOWN
                                 TCP-SOCKET
                                 TCP-HOW
                                 TCP-ERRNO
                                 TCP-RETCODE.

           IF TCP-RETCODE < 0 THEN
              MOVE TP-SHUTDOWN-1 TO TRACE-ID
              PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT
              MOVE CS-ERROR-SHUTDOWN TO CHILD-SERVER-ERROR
              GO TO SHUTDOWN-SOCKET-EXIT
           END-IF.

       SHUTDOWN-SOCKET-EXIT.
           EXIT.

      *****************************************************************
      *  ISSUE 'RECV' SOCKET TO RECEIVE INPUT DATA FROM CLIENT        *
      *****************************************************************
       RECEIVE-REQUEST.
           MOVE LENGTH OF TCP-BUF TO SNDRCV-BUF-LEN.

           PERFORM RECV-BUF-FROM-SOCKET THRU
                   RECV-BUF-FROM-SOCKET-EXIT.
           IF CHILD-SERVER-ERROR < 0 THEN
              GO TO RECEIVE-REQUEST-EXIT
           END-IF.

           MOVE TP-RECVREQ-1 TO TRACE-ID.
           PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT.

       RECEIVE-REQUEST-EXIT.
           EXIT.

      *****************************************************************
      *  LINK TO THE USER PROGRAM TO PROCESS THE REQUEST DATA         *
      *****************************************************************
       PROCESS-REQUEST.

      * THE DATA IS NOW IN TCP-BUF
      * THE LENGTH OF THE RECEIVED DATA IS IN BYTES-RECEIVED

           MOVE BYTES-RECEIVED TO BYTES-TO-SEND.

       PROCESS-REQUEST-EXIT.
           EXIT.

      *****************************************************************
      *  ISSUE 'WRITE' SOCKET TO SEND THE REPLY DATA BACK TO THE CLIENT
      *****************************************************************
       SEND-REPLY.
           COMPUTE SNDRCV-BUF-LEN = BYTES-TO-SEND.

           PERFORM WRITE-BUF-TO-SOCKET THRU
                   WRITE-BUF-TO-SOCKET-EXIT.
           IF CHILD-SERVER-ERROR < 0 THEN
              GO TO SEND-REPLY-EXIT
           END-IF.

       SEND-REPLY-EXIT.
           EXIT.

      *****************************************************************
      *   ISSUE 'CLOSE' SOCKET TO CLOSE THE SOCKET DESCRIPTOR         *
      *****************************************************************
       CLOSE-THE-SOCKET.
           IF SOCKET-IS-CLOSED THEN
             GO TO CLOSE-THE-SOCKET-EXIT
           END-IF.

           CALL 'EZASOKET' USING SOKET-CLOSE
                                 TCP-SOCKET
                                 TCP-ERRNO
                                 TCP-RETCODE.

           IF TCP-RETCODE < 0 THEN
              MOVE TP-CLOSE-1 TO TRACE-ID
              PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT
           END-IF.

           MOVE 'N' TO SOCKET-OPENED.

       CLOSE-THE-SOCKET-EXIT.
           EXIT.

      *****************************************************************
      ** WRITE SOME DATA IN TCP-BUF TO THE SOCKET                     *
      *****************************************************************
       WRITE-BUF-TO-SOCKET.
           MOVE TP-BUF2SOC-1 TO TRACE-ID
           PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT

           MOVE SNDRCV-BUF-LEN TO TCP-NBYTES.
           MOVE 1 TO SNDRCV-BUF-AT-BYTE.

           PERFORM UNTIL TCP-NBYTES <= 0
              PERFORM WRITE-TO-SOCKET THRU
                      WRITE-TO-SOCKET-EXIT

              IF CHILD-SERVER-ERROR < 0 THEN
                 GO TO WRITE-BUF-TO-SOCKET-EXIT
              END-IF

              COMPUTE TCP-NBYTES = TCP-NBYTES - TCP-RETCODE
              COMPUTE SNDRCV-BUF-AT-BYTE = SNDRCV-BUF-AT-BYTE +
                                           TCP-RETCODE
           END-PERFORM.

       WRITE-BUF-TO-SOCKET-EXIT.
           EXIT.

      *****************************************************************
      ** WRITE TO THE SOCKET                                          *
      *****************************************************************
       WRITE-TO-SOCKET.
           MOVE ZERO TO TCP-ERRNO TCP-RETCODE.
           CALL 'EZASOKET' USING SOKET-WRITE
                                 TCP-SOCKET
                                 TCP-NBYTES
                                 TCP-BUF-CHAR(SNDRCV-BUF-AT-BYTE)
                                 TCP-ERRNO
                                 TCP-RETCODE.

           IF TCP-RETCODE < 0 THEN
              MOVE TP-WRI2SOC-2 TO TRACE-ID
              PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT
              MOVE CS-ERROR-WRITE-FAILED TO CHILD-SERVER-ERROR
              GO TO WRITE-TO-SOCKET-EXIT
           END-IF.

           MOVE TP-WRI2SOC-3 TO TRACE-ID.
           PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT.

       WRITE-TO-SOCKET-EXIT.
           EXIT.

      *****************************************************************
      ** RECEIVE SOME DATA FROM THE SOCKET INTO TCP-BUF               *
      *****************************************************************
       RECV-BUF-FROM-SOCKET.
           MOVE SNDRCV-BUF-LEN TO TCP-NBYTES.
           MOVE TCP-FLAGS-NO-FLAG TO TCP-FLAGS.
           MOVE 1 TO SNDRCV-BUF-AT-BYTE.
           MOVE 0 TO BYTES-RECEIVED.

           PERFORM UNTIL SNDRCV-BUF-LEN <= 0
              PERFORM RECV-FROM-SOCKET THRU RECV-FROM-SOCKET-EXIT

      ******* AN ERROR OCCURRED
              IF CHILD-SERVER-ERROR < 0 THEN
                 GO TO RECV-BUF-FROM-SOCKET-EXIT
              END-IF

      ******* SOCKET WAS CLOSED BUT ALL IS OK
              IF TCP-RETCODE = 0 THEN
                 GO TO RECV-BUF-FROM-SOCKET-EXIT
              END-IF

              COMPUTE TCP-NBYTES = TCP-NBYTES - TCP-RETCODE
              COMPUTE SNDRCV-BUF-LEN = SNDRCV-BUF-LEN - TCP-RETCODE
              COMPUTE SNDRCV-BUF-AT-BYTE = SNDRCV-BUF-AT-BYTE +
                                           TCP-RETCODE
              COMPUTE BYTES-RECEIVED = BYTES-RECEIVED + TCP-RETCODE

           END-PERFORM.

       RECV-BUF-FROM-SOCKET-EXIT.
           EXIT.

      *****************************************************************
      ** ISSUE A 'RECV' FOR THE SOCKET                                *
      *****************************************************************
       RECV-FROM-SOCKET.
           MOVE ZERO TO TCP-ERRNO TCP-RETCODE.
           CALL 'EZASOKET' USING
                           SOKET-RECV
                           TCP-SOCKET
                           TCP-FLAGS
                           TCP-NBYTES
                           TCP-BUF-CHAR(SNDRCV-BUF-AT-BYTE)
                           TCP-ERRNO
                           TCP-RETCODE.

           IF TCP-RETCODE = 0 THEN
              MOVE TP-RECV-1 TO TRACE-ID
              PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT
              GO TO RECV-FROM-SOCKET-EXIT
           END-IF.

           IF TCP-RETCODE < 0 THEN
              MOVE TP-RECV-2 TO TRACE-ID
              PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT
              MOVE CS-ERROR-RECV-FAILED TO CHILD-SERVER-ERROR
              GO TO RECV-FROM-SOCKET-EXIT
           END-IF.

           MOVE TP-RECV-3 TO TRACE-ID.
           PERFORM TRACE-POINTS THRU TRACE-POINTS-EXIT.

       RECV-FROM-SOCKET-EXIT.
           EXIT.

      *****************************************************************
      *  FORMAT AND WRITE TRACE MESSAGES                              *
      *****************************************************************
       TRACE-POINTS.
           IF LOGGING-IS-DISABLED
              GO TO TRACE-POINTS-EXIT
           END-IF.

           MOVE SPACES TO LOG-MSG-BUFFER.

           EVALUATE TRACE-ID
              WHEN TP-TAKESOC-1
                 MOVE 'TAKESOCKET FAILED' TO TCP-ERROR-MSG
                 MOVE TCP-RETCODE         TO TCP-ERROR-RETCODE
                 MOVE TCP-ERRNO           TO TCP-ERROR-ERRNO
                 MOVE TCP-ERROR-INFO      TO LOG-MSG-BUFFER
                 PERFORM WRITE-LOG-MSG

              WHEN TP-SHUTDOWN-1
                 MOVE ' SHUTDOWN FAILED' TO TCP-ERROR-MSG
                 MOVE TCP-RETCODE        TO TCP-ERROR-RETCODE
                 MOVE TCP-ERRNO          TO TCP-ERROR-ERRNO
                 MOVE TCP-ERROR-INFO     TO LOG-MSG-BUFFER
                 PERFORM WRITE-LOG-MSG

              WHEN TP-RECVREQ-1
                 MOVE BYTES-RECEIVED  TO EDIT-NUM-8-1
                 STRING ' DATA RECEIVED= ' DELIMITED SIZE
                        EDIT-NUM-8-1 DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

              WHEN TP-CLOSE-1
                 MOVE ' CLOSE FAILED'  TO TCP-ERROR-MSG
                 MOVE TCP-RETCODE      TO TCP-ERROR-RETCODE
                 MOVE TCP-ERRNO        TO TCP-ERROR-ERRNO
                 MOVE TCP-ERROR-INFO   TO LOG-MSG-BUFFER
                 PERFORM WRITE-LOG-MSG

              WHEN TP-BUF2SOC-1
                 MOVE SNDRCV-BUF-LEN TO EDIT-NUM-15
                 STRING ' SEND LEN=' DELIMITED SIZE
                        EDIT-NUM-15    DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

              WHEN TP-WRI2SOC-2
                  MOVE ' WRITE FAILED' TO TCP-ERROR-MSG
                  MOVE TCP-RETCODE     TO TCP-ERROR-RETCODE
                  MOVE TCP-ERRNO       TO TCP-ERROR-ERRNO
                  MOVE TCP-ERROR-INFO  TO LOG-MSG-BUFFER
                  PERFORM WRITE-LOG-MSG

              WHEN TP-WRI2SOC-3
                 MOVE TCP-RETCODE TO EDIT-NUM-8
                 MOVE SPACES TO LOG-MSG-BUFFER
                 STRING ' BYTES SENT=' DELIMITED SIZE
                        EDIT-NUM-8     DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

                 MOVE SPACES TO LOG-MSG-BUFFER
                 STRING ' DATA SENT='     DELIMITED SIZE
                     TCP-BUF(SNDRCV-BUF-AT-BYTE:TCP-RETCODE)
                                          DELIMITED SIZE
                     INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

              WHEN TP-RECV-1
                 MOVE ' ''SOCKET CLOSED'' STATUS RETURNED ON RECV'
                        TO LOG-MSG-BUFFER
                 PERFORM WRITE-LOG-MSG

              WHEN TP-RECV-2
                 MOVE ' RECV FAILED' TO TCP-ERROR-MSG
                 MOVE TCP-RETCODE    TO TCP-ERROR-RETCODE
                 MOVE TCP-ERRNO      TO TCP-ERROR-ERRNO
                 MOVE TCP-ERROR-INFO TO LOG-MSG-BUFFER
                 PERFORM WRITE-LOG-MSG

              WHEN TP-RECV-3
                 MOVE TCP-RETCODE TO EDIT-NUM-8
                 MOVE SPACES TO LOG-MSG-BUFFER
                 STRING ' BYTES RECVD=' DELIMITED SIZE
                        EDIT-NUM-8      DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

                 MOVE SPACES TO LOG-MSG-BUFFER
                 STRING ' DATA RECVD='   DELIMITED SIZE
                     TCP-BUF(SNDRCV-BUF-AT-BYTE:TCP-RETCODE)
                                         DELIMITED SIZE
                     INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

              WHEN TP-RETRIEVE-1
                 MOVE LENGTH OF TCPSOCKET-PARM TO EDIT-NUM-8
                 MOVE HW-LENGTH                TO EDIT-NUM-8-1
                 MOVE SPACES TO LOG-MSG-BUFFER
                 STRING ' RETRIEVE TCPSOCKET-PARM ERROR' DELIMITED SIZE
                        ', EXPECTED='                    DELIMITED SIZE
                        EDIT-NUM-8                       DELIMITED SIZE
                        ', ACTUAL='                      DELIMITED SIZE
                        EDIT-NUM-8-1                     DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

              WHEN TP-RETRIEVE-2
                 MOVE SPACES TO LOG-MSG-BUFFER
                 MOVE GIVE-TAKE-SOCKET TO EDIT-NUM-8
                 STRING ' LSTN GIVE-TAKE-SOCKET=' DELIMITED SIZE
                        EDIT-NUM-8                DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

                 MOVE SPACES TO LOG-MSG-BUFFER
                 STRING ' LSTN NAME=' DELIMITED SIZE
                        LSTN-NAME     DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

                 MOVE SPACES TO LOG-MSG-BUFFER
                 STRING ' LSTN SUBTASKNAME=' DELIMITED SIZE
                        LSTN-SUBTASKNAME     DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

                 MOVE SPACES TO LOG-MSG-BUFFER
                 STRING ' LSTN CID-USERID='     DELIMITED SIZE
                        CID-USERID              DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

                 MOVE SPACES TO LOG-MSG-BUFFER
                 MOVE SIN-FAMILY TO EDIT-NUM-8
                 STRING ' LSTN SIN-FAMILY=' DELIMITED SIZE
                        EDIT-NUM-8          DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

                 MOVE SPACES TO LOG-MSG-BUFFER
                 MOVE SIN-PORT TO EDIT-NUM-8
                 STRING ' LSTN SIN-PORT=' DELIMITED SIZE
                        EDIT-NUM-8        DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

                 MOVE SPACES TO LOG-MSG-BUFFER
                 MOVE SIN-ADDR TO EDIT-NUM-15
                 STRING ' LSTN SIN-ADDR=' DELIMITED SIZE
                        EDIT-NUM-15       DELIMITED SIZE
                        INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

              WHEN OTHER
                 MOVE TRACE-ID TO EDIT-NUM-8
                 STRING ' UNKNOWN TRACE-ID VALUE OF: ' DELIMITED SIZE
                    EDIT-NUM-8 DELIMITED SIZE
                    INTO LOG-MSG-BUFFER
                 END-STRING
                 PERFORM WRITE-LOG-MSG

           END-EVALUATE.

       TRACE-POINTS-EXIT.
           EXIT.

      *****************************************************************
      *  WRITE A MESSAGE OUT TO A CICS TRANSIENT DATA QUEUE           *
      *****************************************************************
       WRITE-LOG-MSG.
           IF LOGGING-IS-ENABLED THEN
              MOVE LENGTH OF LOG-MSG TO HW-LENGTH
              MOVE EIBTASKN          TO TASK-NUMBER
              EXEC CICS WRITEQ TD QUEUE('CSMT')
                                  FROM(LOG-MSG)
                                  LENGTH(HW-LENGTH)
                                  NOHANDLE
                                  END-EXEC
           END-IF.

      *****************************************************************
      ** ERROR HANDLING ROUTINES                                      *
      *****************************************************************
       INVREQ-ERR-SEC.
           MOVE ' CICS COMMAND RETURNED ''INVREQ''' TO LOG-MSG-BUFFER.
           PERFORM WRITE-LOG-MSG.
           MOVE CS-ERROR-CICS-INVREQ TO CHILD-SERVER-ERROR.
           PERFORM CLOSE-THE-SOCKET THRU CLOSE-THE-SOCKET-EXIT.
           GO TO EXIT-THE-PROGRAM.

       IOERR-SEC.
           MOVE ' CICS COMMAND RETURNED ''IOREQ''' TO LOG-MSG-BUFFER.
           PERFORM WRITE-LOG-MSG.
           MOVE CS-ERROR-CICS-IOREQ TO CHILD-SERVER-ERROR.
           PERFORM CLOSE-THE-SOCKET THRU CLOSE-THE-SOCKET-EXIT.
           GO TO EXIT-THE-PROGRAM.

       LENGERR-SEC.
           MOVE ' CICS COMMAND RETURNED ''LENGERR''' TO LOG-MSG-BUFFER.
           PERFORM WRITE-LOG-MSG.
           MOVE CS-ERROR-CICS-LENGERR TO CHILD-SERVER-ERROR.
           PERFORM CLOSE-THE-SOCKET THRU CLOSE-THE-SOCKET-EXIT.
           GO TO EXIT-THE-PROGRAM.

       ENDDATA-SEC.
           MOVE ' CICS COMMAND RETURNED ''ENDDATA''' TO LOG-MSG-BUFFER.
           PERFORM WRITE-LOG-MSG.
           MOVE CS-ERROR-CICS-ENDDATA TO CHILD-SERVER-ERROR.
           PERFORM CLOSE-THE-SOCKET THRU CLOSE-THE-SOCKET-EXIT.
           GO TO EXIT-THE-PROGRAM.

      *****************************************************************
      ** EXIT PGM                                                     *
      *****************************************************************
       EXIT-THE-PROGRAM.
           MOVE SPACES TO LOG-MSG-BUFFER.
           MOVE 'END OF CONCURRENT SERVER' TO LOG-MSG-BUFFER.
           PERFORM WRITE-LOG-MSG.
           EXEC CICS RETURN END-EXEC.
           GOBACK.
