certreq.hta illustrates how to use the xenroll.dll ActiveX control to
generate an offline certificate request.  It is an HTML application that
would be used in an environment when no network connectivity exists to
a Windows Certificate Authority.

Some of the constants used in the sample file are defined in wincypt.h


Files included in this sample
=============================

1) ReadMe.txt   - This file
2) certreq.hta  - Sample program


Functions used in this sample
===================================

- CreateObject
- IControl
- GetCSPList


How to compile
==============

This sample assumes Internet Explorer 5.0 or later.  It is not necessary
to compile this application.  It will run natively when opened by Internet
Explorer with the *.hta extension.
