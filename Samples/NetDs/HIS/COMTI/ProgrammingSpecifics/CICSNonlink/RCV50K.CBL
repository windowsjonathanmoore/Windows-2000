      **********************************************************
      * THIS SAMPLE PROGRAM DEMONSTRATES HOW TO RECEIVE A COMTI*
      * FIXED SIZED DATA AREA THAT IS GREATER THAN 32767. THIS *
      * SAMPLE PROGRAM IS NOT INTENDED TO BE A COMPLETE        *
      * END-TO-END SAMPLE. IT ONLY DEMONSTRATES THE RECEIVING  *
      * SIDE LOGIC OF A COMTI NON-LINK SERVER APPLICATION      *
      * PROGRAM.                                               *
      **********************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. RCV50K.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.

       01  RECEIVE-AT-BYTE             PIC S9(8) COMP VALUE 1.
       01  RCV-DATA-SIZE               PIC S9(8) COMP VALUE 0.
       01  RCV50K-MAX-SIZE             PIC S9(8) COMP VALUE 51200.
       01  MAX-LEN                     PIC S9(8) COMP VALUE 32767.
       01  RCV-LEN                     PIC S9(8) COMP VALUE 0.
       01  CMD-RESP                    PIC S9(8) COMP VALUE 0.

       01  RCV50K-DATA-AREA.
           05  RCV50K-USER-DATA        PIC X(51200).
           05  FILLER REDEFINES RCV50K-USER-DATA.
               10 RCV50K-CHAR  OCCURS 51200 TIMES PIC X.

       LINKAGE SECTION.
       PROCEDURE DIVISION.

      **** SET UP HOW MUCH DATA NEEDS TO BE RECEIVED
           MOVE RCV50K-MAX-SIZE TO RCV-DATA-SIZE.

      **** ENTER A LOOP UNTIL ALL OF THE DATA IS RECEIVED
           PERFORM UNTIL RCV-DATA-SIZE <= 0
      ****    DON'T TRY TO RECEIVE MORE THAN WHAT CICS ALLOWS
              IF RCV-DATA-SIZE > MAX-LEN
                 COMPUTE RCV-LEN = MAX-LEN
              ELSE
                 COMPUTE RCV-LEN = RCV-DATA-SIZE
              END-IF

      ****   GO GET THE DATA FROM CICS
             EXEC CICS RECEIVE
                 INTO(RCV50K-CHAR(RECEIVE-AT-BYTE))
                 FLENGTH(RCV-LEN)
                 MAXFLENGTH(MAX-LEN)
                 NOTRUNCATE
                 RESP(CMD-RESP)
                 END-EXEC

      ****   CHECK THE STATUS OF THE RECEIVE COMMAND
             IF CMD-RESP NOT = DFHRESP(NORMAL) AND
                CMD-RESP NOT = DFHRESP(EOC)
      ****      THE RECEIVE FAILED SO DO APPROPRIATE ERROR RECOVERY
                EXEC CICS ABEND ABCODE('BADR') END-EXEC
             END-IF

      ****   SEE IF WE HAVE MORE DATA TO RECEIVE
             IF EIBRECV = X'FF'
      ****      THERE IS MORE DATA SO SET UP FOR THE NEXT RECEIVE
                COMPUTE RCV-DATA-SIZE = RCV-DATA-SIZE - RCV-LEN
                COMPUTE RECEIVE-AT-BYTE = RECEIVE-AT-BYTE + RCV-LEN
             ELSE
      ****      ALL DONE SO EXIT THE PERFORM UNTIL LOOP
                COMPUTE RCV-DATA-SIZE = 0
             END-IF
           END-PERFORM.

           IF EIBRECV = X'FF' OR
              RCV-DATA-SIZE < 0 OR
              RECEIVE-AT-BYTE > RCV50K-MAX-SIZE
      ****    TOO MUCH DATA WAS SENT BY THE CLIENT
      ****    DO APPROPRIATE ERROR RECOVERY
              EXEC CICS ABEND ABCODE('TOOM') END-EXEC
           END-IF.

      **** THIS IS AN INTENTIONAL ABEND SINCE THIS IS AN INCOMPLETE
      **** END-TO-END APPLICATION
           EXEC CICS ABEND ABCODE('SAMP') END-EXEC

           EXEC CICS RETURN END-EXEC.

           EXIT.
