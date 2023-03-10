=============================================
Reusing Browser Technology -- MFCIEEvtSpy
=============================================
Last Updated: November 10, 1999.


SUMMARY
========
The MFCIEEvtSpy sample application demonstrates handling Internet Explorer 
events that are fired by the WebBrowser Control hosted in an MFC 
application, or by a separate, remote instance of Internet Explorer. 

This sample application requires Internet Explorer 4.0x or Internet 
Explorer 5. While you are not required to utilize Internet Explorer 
as your default browser of choice, it must be installed on the target 
computer. Hence, MFC applications that host the WebBrowser Control 
(or start separate running instances of Internet Explorer) must also 
redistribute Internet Explorer. Refer to the Licensing & Distribution 
article at http://msdn.microsoft.com/workshop/browser/license/Licensing.asp
for more information about redistributing Internet Explorer with your 
application.


USAGE
======
Building the sample application requires Visual C++ 5.0 or 6.0 with 
the MFC libraries installed.

There are two common scenarios for hosting the WebBrowser Control 
in an application: 

 - Web-browsing applications host the WebBrowser control in order to focus
   development efforts on new and original browsing features. The advantages
   to basing browser applications on the WebBrowser control stem from avoiding 
   the drudgery of implementing functionality already provided, as well as 
   benefiting from the control's extensibility and customization features.
   This approach also leverages the control's standards compliance and provides 
   compatibility with Web pages designed to take advantage of Internet Explorer. 
	
 - Traditional applications host the WebBrowser Control in order to integrate a
   browsing experience. This ranges from browsing targeted content on the Web to
   presenting a rich user interface based upon Dynamic HTML. The advantages to
   creating elements of the application's user interface with Dynamic HTML include
   easier localization of content, built-in presentation and printing support,and
   streamlining the development process by allowing user interface specialists
   complete control over presentation elements. 
	
** For more of an overview of Application Types, go to:
   http://msdn.microsoft.com/workshop/browser/reusebovw.asp

** For more information on Reusing Browser Technology, go to:
   http://msdn.microsoft.com/workshop/browser/default.asp


DETAILS
========
One of the most important ways for an application to control Internet Explorer 
is by monitoring what it is doing. For this reason, Internet Explorer exposes 
an event interface so applications can monitor its activity and perform certain 
actions. For example, by intercepting the BeforeNavigate2 event, an application 
can examine the requested URL and prevent the browser from navigating there. Thus, 
this sample application shows you how to implement event handling in your MFC 
application in order to receive events from Internet Explorer. By hosting an 
instance of the WebBrowser Control, the sample application demonstrates how 
applications wishing to directly integrate Web browsing capabilities can receive 
and respond to the Internet Explorer events that are fired as a result of actions 
taken in the embedded WebBrowser Control. In addition, the sample application also 
shows how to start (and control) a new, separate instance of Internet Explorer and 
receive events from it.

Source files:

  - IEEvents.cpp
  - IEEvents.h
  - makefile
  - MFCIEEvtSpy.clw
  - MFCIEEvtSpy.cpp
  - MFCIEEvtSpy.dep
  - MFCIEEvtSpy.dsp
  - MFCIEEvtSpy.dsw
  - MFCIEEvtSpy.h
  - MFCIEEvtSpy.rc
  - MFCIEEvtSpyDlg.cpp
  - MFCIEEvtSpyDlg.h
  - resource.h
  - StdAfx.cpp
  - StdAfx.h
  - webbrowser2.cpp
  - webbrowser2.h

Other files:

  - MFCIEEvtSpy.ico
  - MFCIEEvtspy.rc2



==============================
© Microsoft Corporation 1999
