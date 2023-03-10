      01  CUSTOMER-DATA.
          05  CUSTOMER-NUMBER                  PIC 9(9).
          05  INVOICES OCCURS 50 TIMES.                         
              10  INVOICE-NUMBER               PIC 9(9).
              10  INVOICE-DATE                 PIC 9(7) COMP-3.
              10  INVOICE-AMOUNT               PIC S9(13)V9(2) COMP-3.
              10  INVOICE-DESCIPTION           PIC X(40).
          05  LAST-NAME                        PIC X(20).
          05  FIRST-NAME                       PIC X(20).