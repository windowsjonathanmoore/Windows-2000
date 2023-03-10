/*++

Copyright (c) 1999 Microsoft Corporation

--*/

TAPI 3.0
Sample ACD proxy application

Overview:

This application demonstrates the working of an ACD proxy application.
This application allows creation of ACD groups and software call 
queues, handles proxy request messages from clients and sends status 
messages back to TAPI to reflect any changes in status. You can set 
the users who will be allowed to create agents on this proxy. All the
above details should be specified in a file proxy.ini. Edit this file 
to replace GoodAgentName in 

"[Users]
Name=GoodAgentName"

with the user name you want to create acd agent with say your account name.


Also, make sure you modify the following value in proxy.ini:
"[General]
NumProxies=10"

to be value bigger than 10, if you have more then 10 tapi lines 
on your system. Otherwise the app will only work with the first 10 ones.


After you are done modifying proxy.ini, before starting this application, 
copy proxy.ini file to %windir%.

    

This app detects incoming calls and adds the calls to appropriate queues.
Periodically (every 5 seconds) it also checks queues for calls to 
be answered, if any are found, it looks for a free agent and agent
session and if any are found, it uses these to service the call.

ACDPROXY.CPP is the implementation of the proxy server.

How to build the sample:

namke command will build the sample (set up sdk build environment first).

How to use the sample:


What functionality does this sample show:

The ACD proxy sample application primarily demonstrates how to open lines 
with proxy previlages, create acdgroups, acd queues, acd agent, acd agent 
sessions, and ditribute calls among different agent sessions.



Notes:

One of the applications that can be run in order to use the ACDClient 
application under sdk\sample\netds\tapi\tapi3\cpp\acd\acdclient



--------------------------------------------------------------------------

  Copyright (C) 1998-1999 Microsoft Corporation. All rights reserved.

--------------------------------------------------------------------------

TAPI 2 atsp.c Sample Application


Overview:
~~~~~~~~~

Atsp.c is a sample TAPI application that illustrates how to write a 
telephony service provider (TSP) for a modem.  The TSP is used 
by the TAPI application to interface with the telephony devices. This sample 
will initiate outgoing modem calls and interactive voice.  Call control is accomplished 
through communication with the TSP interface.  For more details on the TAPI
TSPI, see the TAPI SDK documentation.  The sample will not run by itself, but can 
be used with a full TAPI application.


How to build the sample:
~~~~~~~~~~~~~~~~~~~~~~~~

To run the atsp sample, set the SDK build environment, then
type "nmake" in the atsp directory.  This will build atsp.tsp.


How to use the sample:
~~~~~~~~~~~~~~~~~~~~~~

After the sample is built, run the TAPI  application and attempt to open a line.  Tb20 will
look for a device for theis command....


What functionality does this sample show:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The incoming sample application demonstrates how to create a tapi TSP
for device manufacturers.  This sample illustrates many of the
TSP interface (TSPI) line functions such as TSPI_LineClose,  TSPI_LineGetCallInfo, 
TSPI_LineGetDevCaps and TSPI_LineMakeCall.  The TSPI provider functions are 
shown for TSPI_providerInit(), TSPI_providerEnumDevices(), TSPI_providerInstall(),
and TSPI_providerConfig among others. Also shows how to get the lines configuration
from the register and the number of devices configuration from the registry.   


What this sample does not show:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
This sample TSP will not process an incoming call. 


Hints:
~~~~~~

This sample should be able to run as long as you have TAPI devices
installed.  Many computers have a modem.  If the modem is installed 
correctly, it will show up as a TAPI device. Also, there are TAPI
devices corresponding to various IP telephony services that are
present on most systems.


Additional Notes on how to build the sample: 

 How to build the samples with VC6 or VC5:
-	IMPORTANT: start a new command prompt 
	(cmd.exe), or start a new "Set Win32 Environment" 
	cmd window from Programs - Microsoft Platform SDK .
-	go to the path where you installed VC6 
	(e.g. C:\ Program Files\Microsoft Visual Studio\VC98\Bin) 
	and type VCVARS32.BAT.
-	go to the path where you installed SDK 
	(e.g. C:\Program Files\Microsoft Platform SDK) 
	and type SetEnv.Bat.
-	check the following environment variables: 
	PATH, LIB, INCLUDE. You can see their current 
	values by typing "SET" at the command prompt. 
	You should see that they contain first the SDK 
	paths and then the VC6 paths.
-	go to the path where the TAPI sample 
	(TAPI2 and TAPI3) is installed and type NMAKE. 


