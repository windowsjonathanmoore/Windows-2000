      01  CUSTOMER-DATA.
          05  CUSTOMER-ID                          PIC X(10). 
          05  CUSTOMER-ID-PARTS REDEFINES CUSTOMER-ID. 
              10  LOCATION                         PIC X(3).
              10  NAME-ABREV                       PIC X(5).
