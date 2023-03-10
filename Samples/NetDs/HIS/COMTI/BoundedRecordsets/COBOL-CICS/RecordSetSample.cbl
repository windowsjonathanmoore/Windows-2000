       IDENTIFICATION DIVISION.
       PROGRAM-ID. RSETSAMP.

       ENVIRONMENT DIVISION.

       DATA DIVISION.

       WORKING-STORAGE SECTION.

       01  OUTPUT-ROW-COUNT                     PIC S9(4) COMP.

       01  CUSTOMER-DATA.
           05  CUSTOMER-NUMBER                  PIC 9(9).
           05  LAST-NAME                        PIC X(20).
           05  FIRST-NAME                       PIC X(20).
           05  INVOICES OCCURS 30 TIMES.
               10  SIZE-OF-INVOICE-ROW          PIC S9(4) COMP.
               10  INVOICE-ROW.
                   15  INVOICE-NUMBER           PIC 9(10).
                   15  INVOICE-DATE             PIC 9(7) COMP-3.
                   15  INVOICE-AMOUNT           PIC S9(13)V9(2) COMP-3.
                   15  INVOICE-DESCRIPTION      PIC X(4096).


       LINKAGE SECTION.


       PROCEDURE DIVISION.
      *
      *  GET THE INPUT
      *
           CALL 'GET-INPUT' USING DFHEIBLK CUSTOMER-DATA.
      *
      *  THE INPUT AREA IS NOW POPULATED
      *
           PERFORM DO-SOMTHING-WITH-THE-INPUT.

           PERFORM GET-THE-DATA-FOR-OUTPUT.

      *
      *  THE OUTPUT AREA IS NOW POPULATED
      *

           CALL 'SEND-OUTPUT' USING DFHEIBLK
                                    CUSTOMER-DATA OUTPUT-ROW-COUNT.

           EXEC CICS RETURN END-EXEC.



       DO-SOMTHING-WITH-THE-INPUT.
      *
      *  I DECIDED NOT TO DO ANYTHING WITH THE INPUT
      *


       GET-THE-DATA-FOR-OUTPUT.
           MOVE 2 TO OUTPUT-ROW-COUNT.

           INITIALIZE INVOICE-ROW(1).
           MOVE 12345           TO CUSTOMER-NUMBER.
           MOVE 'SMITH'         TO LAST-NAME.
           MOVE 'FRED'          TO FIRST-NAME.
           MOVE 35              TO SIZE-OF-INVOICE-ROW(1).
           MOVE 54321           TO INVOICE-NUMBER(1).
           MOVE 270897          TO INVOICE-DATE(1).
           MOVE 213.99          TO INVOICE-AMOUNT(1).
           MOVE 'MENS CLOTHING' TO INVOICE-DESCRIPTION(1).

           INITIALIZE INVOICE-ROW(2).
           MOVE 41              TO SIZE-OF-INVOICE-ROW(2).
           MOVE 98765           TO INVOICE-NUMBER(2)
           MOVE 020997          TO INVOICE-DATE(2)
           MOVE 613.99          TO INVOICE-AMOUNT(2)
           MOVE 'HOME THEATER SYSTEM'
                                TO INVOICE-DESCRIPTION(2).

       IDENTIFICATION DIVISION.
       PROGRAM-ID. GET-INPUT.

       DATA DIVISION.

       WORKING-STORAGE SECTION.

       01  WS-LENGTHS.
           05  RECEIVE-LENGTH                 PIC S9(4) COMP.

       01  WS-COUNTS.
           05  ROW                            PIC S9(9) COMP.

       01  WS-FLAGS.
           05  MORE-DATA-FLAG                 PIC X.
               88 MORE-DATA                   VALUE 'Y'.
               88 NO-MORE-DATA                VALUE 'N'.
       01  CMD-RESP                           PIC S9(4) COMP VALUE +0.
       LINKAGE SECTION.

       01  CUSTOMER-DATA-INPUT-AREA.
           05  CUSTOMER-NUMBER                  PIC 9(9).
           05  LAST-NAME                        PIC X(20).
           05  FIRST-NAME                       PIC X(20).
           05  INVOICES OCCURS 30 TIMES.
               10  SIZE-OF-INVOICE-ROW          PIC S9(4) COMP.
               10  INVOICE-ROW.
                   15  INVOICE-NUMBER           PIC 9(10).
                   15  INVOICE-DATE             PIC 9(7) COMP-3.
                   15  INVOICE-AMOUNT           PIC S9(13)V9(2) COMP-3.
                   15  INVOICE-DESCRIPTION      PIC X(4096).




       PROCEDURE DIVISION USING DFHEIBLK CUSTOMER-DATA-INPUT-AREA.

      *
      *  RECEIVE THE FIRST PART OF THE IO AREA
      *
           MOVE 49 TO RECEIVE-LENGTH.

           EXEC CICS RECEIVE INTO(CUSTOMER-DATA-INPUT-AREA)
                 LENGTH(RECEIVE-LENGTH)
                 MAXLENGTH(RECEIVE-LENGTH)
                 NOTRUNCATE
                 RESP(CMD-RESP)
           END-EXEC.

      *
      *  RECEIVE EACH ROW LENGTH AND THEN THE ROW
      *
           PERFORM VARYING ROW FROM 1 BY 1 UNTIL NO-MORE-DATA OR
                                                 ROW > 30
               MOVE 2 TO RECEIVE-LENGTH
               EXEC CICS RECEIVE
                   INTO(SIZE-OF-INVOICE-ROW(ROW))
                   LENGTH(RECEIVE-LENGTH)
                   MAXLENGTH(RECEIVE-LENGTH)
                   NOTRUNCATE
                   RESP(CMD-RESP)
               END-EXEC
      *
      *  USE THE LENGTH THAT WAS JUST RECEIVED TO GET THE NEXT ROW
      *
               MOVE SIZE-OF-INVOICE-ROW(ROW) TO RECEIVE-LENGTH
               EXEC CICS RECEIVE
                   INTO(INVOICE-ROW(ROW))
                   NOTRUNCATE
                   LENGTH(RECEIVE-LENGTH)
                   MAXLENGTH(RECEIVE-LENGTH)
                   RESP(CMD-RESP)
               END-EXEC

               IF EIBFREE = X'FF'
                   EXEC CICS FREE END-EXEC
                   EXEC CICS ABEND ABCODE('CDR3') END-EXEC
               END-IF
               IF EIBERR = X'FF'
                   EXEC CICS ABEND ABCODE('CDR4') END-EXEC
               END-IF

               IF EIBRECV = X'FF'
                  MOVE 'Y' TO MORE-DATA-FLAG
               ELSE
                  MOVE 'N' TO MORE-DATA-FLAG
               END-IF

           END-PERFORM.

       END PROGRAM GET-INPUT.

       IDENTIFICATION DIVISION.
       PROGRAM-ID. SEND-OUTPUT.

       DATA DIVISION.

       WORKING-STORAGE SECTION.

       01  WS-LENGTHS.
           05  SEND-LENGTH                    PIC S9(4) COMP.

       01  WS-COUNTS.
           05  ROW                            PIC S9(9) COMP.

       01  CMD-RESP                           PIC S9(4) COMP VALUE +0.

       LINKAGE SECTION.
       01  CUSTOMER-DATA-OUTPUT-AREA.
           05  CUSTOMER-NUMBER                  PIC 9(9).
           05  LAST-NAME                        PIC X(20).
           05  FIRST-NAME                       PIC X(20).
           05  INVOICES OCCURS 30 TIMES.
               10  SIZE-OF-INVOICE-ROW          PIC S9(4) COMP.
               10  INVOICE-ROW.
                   15  INVOICE-NUMBER           PIC 9(10).
                   15  INVOICE-DATE             PIC 9(7) COMP-3.
                   15  INVOICE-AMOUNT           PIC S9(13)V9(2) COMP-3.
                   15  INVOICE-DESCRIPTION      PIC X(4096).

       01  OUTPUT-ROW-COUNT                     PIC S9(4) COMP.

       PROCEDURE DIVISION USING DFHEIBLK CUSTOMER-DATA-OUTPUT-AREA
                                         OUTPUT-ROW-COUNT.

      *
      *  SEND THE FIRST PART OF THE IO AREA
      *
           MOVE 49 TO SEND-LENGTH.

           EXEC CICS SEND FROM(CUSTOMER-DATA-OUTPUT-AREA)
                          LENGTH(SEND-LENGTH)
                          END-EXEC.
      *
      *  COMPUTE SEND-LENGTH REMEMBERING TO ADD 2 BYTES 
      *  FOR SIZE-OF-INVOICE-ROW
      *
           PERFORM VARYING ROW FROM 1 BY 1 UNTIL ROW > OUTPUT-ROW-COUNT

               COMPUTE SEND-LENGTH = SIZE-OF-INVOICE-ROW(ROW) + 2

               EXEC CICS SEND FROM(INVOICES(ROW))
                              LENGTH(SEND-LENGTH)
               END-EXEC

           END-PERFORM.

       END PROGRAM  SEND-OUTPUT.

       END PROGRAM  RSETSAMP.
