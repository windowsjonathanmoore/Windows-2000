      01  CUSTOMER-DATA.
          05  CUSTOMER-NUMBER                  PIC 9(9).
          05  LAST-NAME                        PIC X(20).
          05  FIRST-NAME                       PIC X(20).
          05  INVOICE-COUNT                    PIC 9(7) COMP-3.
          05  INVOICES OCCURS 50 TIMES DEPENDING ON INVOICE-COUNT.                         
              10  INVOICE-NUMBER               PIC 9(10).
              10  INVOICE-DATE                 PIC 9(7) COMP-3.
              10  INVOICE-AMOUNT               PIC S9(13)V9(2) COMP-3.
              10  INVOICE-DESCRIPTION          PIC X(40).
