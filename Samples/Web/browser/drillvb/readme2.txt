======================================================
Notes for "Drill" Sample
======================================================

There are two Drill samples, both do the same thing, however one is written using MFC and the other is written using Visual Basic.

OVERVIEW
========
The drill samples demonstrate hosting the WebBrowser control as part of another application. The buttons and address input are supplied by the hosting application and commands are sent to the WebBrowser control on the form. Entering a URL in the address field on the form will result in the WebBrowser control navigating to that page.

Additionally the Drill samples show how a hosting application can "drill" into the WebBrowser control and investigate the loaded HTML document. In this case the host walks the ALL collection of the document object of the loaded html page using Dynamic HTML and populate a list box with each element encountered.

NOTES on Driller
================
All the interfaces for the object model are defined
in MSHTML.h which is in the IE5 Headers.

Notes on DrillVB
================
The DrillVB sample is written using Visual Basic 4.0, and will also run in VB5.0. It populates a listbox with the elements that it finds on the all collection which is obtained using
   Set allCol = WebBrowser1.Document.All
 
