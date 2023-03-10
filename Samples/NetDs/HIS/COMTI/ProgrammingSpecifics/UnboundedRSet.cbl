      ***********************************************************
      * Example of sending unbounded recordsets to the client
      ***********************************************************
       IDENTIFICATION DIVISION.

       ENVIRONMENT DIVISION.

       DATA DIVISION.

       WORKING-STORAGE SECTION.

      * INPUT AREA
       01  CUSTOMER-INPUT-NUMBER                PIC 9(9).

      * OUTPUT AREA
       01  CUSTOMER-DATA.
           05  LAST-NAME                        PIC X(20).
           05  FIRST-NAME                       PIC X(20).

      * ONE ROW IN A DATABASE TABLE
       01  INVOICES.
           05  INVOICE-NUMBER                   PIC 9(10).
           05  INVOICE-DATE                     PIC 9(7) COMP-3.
           05  INVOICE-AMOUNT                   PIC S9(13)V9(2) COMP-3.
           05  INVOICE-DESCRIPTION              PIC X(40).

       LINKAGE SECTION.

       PROCEDURE DIVISION.
      *
      *   Get the input customer account number from the client AP
      *
           MOVE LENGTH OF CUSTOMER-INPUT-NUMBER TO RECEIVE-LENGTH
           EXEC-CICS RECEIVE INTO(CUSTOMER-INPUT-NUMBER)
                     LENGTH(RECEIVE-LENGTH)
                     END-EXEC.
      *
      *   Do some work then send the first and last name back
      *
           MOVE LENGTH OF CUSTOMER-DATA TO SEND-LENGTH
           EXEC-CICS SEND FROM(CUSTOMER-DATA)
                     LENGTH(SEND-LENGTH)
                     END-EXEC.
      *
      *   Follow regular data with unbounded table data which
      *   the client Ap sees as a recordset.
      *
           MOVE LENGTH OF INVOICES TO SEND-LENGTH
           PERFORM UNTIL	NO-MORE-INVOICES
      *
      *   Do some work to get the next row
      *
           MOVE DB-INVOICE-NUMBER TO INVOICE-NUMBER
           MOVE DB-INVOICE-DATE   TO INVOICE-DATE
           MOVE DB-INVOICE-AMOUNT TO INVOICE-AMOUNT
           MOVE DB-INVOICE-DESC   TO INVOICE-DESCRIPTION
      *
      *   Send the row
      *
           EXEC-CICS SEND FROM(INVOICES)
                     LENGTH(SEND-LENGTH)
                     END-EXEC.
           END-PERFORM.
