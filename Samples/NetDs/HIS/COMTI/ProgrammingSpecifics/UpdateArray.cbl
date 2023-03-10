       01  UPDATEARRAY-INPUT-AREA.
           05  CUSTOMER-NUMBER                  PIC 9(9) DISPLAY.
           05  LAST-NAME                        PIC X(20).
           05  FIRST-NAME                       PIC X(20).
           05  TABLE-LENGTH                     PIC 9(7) COMP-3.
           05  TABLE OCCURS 10 TIMES
                     DEPENDING ON TABLE-LENGTH
                               OF UPDATEARRAY-INPUT-AREA
                                                PIC S9(4) COMP.
 