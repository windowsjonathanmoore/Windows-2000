============================================
Reusing Browser Technology - Binary Behavior
============================================
Last Updated: Jan. 21, 2001


SUMMARY
========
This sample illustrates how to attach a binary DHTML behavior to an HTML 
element, implement a binary DHTML behavior for Internet Explorer 5, access 
the document object model, and handle events from the document object model.      


USAGE
======
 - This sample requires that the Internet Explorer 5 header and library files 
   are installed. These are available from the Platform SDK Download.

Note: You must first download the sample to your own computer to run it.

The source code for this sample is included in a Microsoft® Visual C++ 6 workspace.
Note:  You will need to include the Internet Explorer 5.0 header and library files, and the 
Windows 2000 Header and Library files from the Platform SDK in your development path when building the sample source code.

For the IE 5.0 Headers and Library files and the Win32 Header and Library files for Windows 2000, go to: http://www.microsoft.com/msdownload/platformsdk/setuplauncher.htm. Install over the network and select "Custom Install". To obtain the full set of header and library files necessary to build the C/C++ projects, you will need, at minimum, to install the 'Build Environment' section of the Platform SDK.

The source code development path for Header files will be:
C:\Program Files\Microsoft Platform SDK\Include
C:\Program Files\Microsoft Visual Studio\VC98\INCLUDE
C:\Program Files\Microsoft Visual Studio\VC98\MFC\INCLUDE
C:\Program Files\Microsoft Visual Studio\VC98\ATL\INCLUDE

The source code development path for Library files will be:
C:\Program Files\Microsoft Platform SDK\Lib
C:\Program Files\Microsoft Visual Studio\VC98\LIB
C:\Program Files\Microsoft Visual Studio\VC98\MFC\LIB

RUNNING THE SAMPLE
------------------
 - Open BEHAVE.HTM.

 - Moving the mouse over the main text will show the attached behavior. In this 
   sample, the selected system colors are used to highlight the text.

 - Use the two listboxes to select a different system color to be used as the 
   background or text color.

NOTES
-----
This sample overrides the default ATL implementation of 
ObjectSafety::SetInterfaceSafetyOptions() so you are not presented with 
a Security Alert dialog box on opening the sample HTML page. This is 
because Internet Explorer 5 queries the behavior factory to set the safety 
options for the IDispatchEx/IDispatch and IPersistPropertyBag interfaces 
and IPersistPropertyBag is not implemented in this sample.

This sample does not support providing the two properties 
(backColor and textColor) as expando properties, for example:

<SPAN ID=target STYLE="behavior:url(#behave1); font-size:xx-large"  backColor=5 textColor=24>


BROWSER/PLATFORM COMPATIBILITY
===============================
This binary behaviors sample is supported on Internet Explorer 5 with the 
Win32 platform. 


SOURCE FILES
=============
This is a Visual C++ 5.0 or 6.0 project.
 
 - FACTORY.CPP,FACTORY.H - IElementBehaviorFactory interface implementation.
 - BEHAVIOR.CPP,BEHAVIOR.H - IElementBehavior interface implementation.
 - EVENTSINK.CPP,EVENTSINK.H - HTMLElementEvents event sink implementation.
 - BEHAVE_VBS.HTM,BEHAVE_JS.HTM - test HTML files which demonstrates the sample 
   behavior.

AltBehave.cpp
AltBehave.def
AltBehave.dsp
AltBehave.dsw
AltBehave.h
AltBehave.idl
altbehave.inf
AltBehave.rc
AltBehave_i.c
AltBehave_p.c
Behavior.rgs
dlldata.c
EventSink.rgs
Factory.rgs
Resource.h
StdAfx.cpp
StdAfx.h

OTHER FILES
-----------
demo.gif
readme.txt


SEE ALSO
=========
For more information on DHTML Behaviors in Internet Explorer 5 go to:
http://msdn.microsoft.com/workshop/essentials/versions/ie5behave.asp.


==================================
Copyright (c) Microsoft Corporation. All rights reserved.
