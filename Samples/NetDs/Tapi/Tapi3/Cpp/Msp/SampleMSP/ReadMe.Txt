--------------------------------------------------------------------------

  Copyright (C) 1998-2000 Microsoft Corporation. All rights reserved.

--------------------------------------------------------------------------

TAPI 3.0 Sample MSP


Overview:
~~~~~~~~~

SampMSP is a sample TAPI 3.0 MSP (media service provider) that shows how
to use the MSP base classes. It is set up to work with audio using
DirectShow, but it does not implement creation or connection of any
specific transport filters. It is meant as a starting point which can
be expanded to suit a particular type of transport.

The sample is of interest to devlopers of TSPs (telephony service
providers) who want to enable TAPI 3.0 applications to stream media with
their TSPs. A TSP that does not have an acoompanying MSP will be fully
functional for call control but will not support the media streaming
features of TAPI 3.0.  ATSP32.TSP in the Tapi2 sample directory tree 
is a Sample TSP that implements the necessary TSPI_ functions that link to 
this Sample MSP. Please see the Windows SDK documentation for more
information.

Developers of TAPI 3.0 applications, who are not involved in developing
or updating a TAPI TSP/MSP, will not find this sample to be directly
useful.


The following define and implement the sample MSP address object:
	sampaddr.h
	sampaddr.cpp

The following define and implement the sample MSP call object:
	sampcall.h
	sampcall.cpp

The following define and implement the sample MSP stream object:
	sampstrm.h
	sampstrm.cpp

The following implement the main DLL exports:
	sampmsp.cpp
	sampmsp.def 

The following show how to include the MSP base class header files, etc.:
	common.h
	stdafx.h

The following files declare the necessary info for COM server registration:
	sampmsp.idl
	sampmsp.rgc
	sampmsp.rc
	resource.h
 
How to build the sample:
~~~~~~~~~~~~~~~~~~~~~~~~

To build the sample:

- set the SDK build environment
- type "nmake" in ..\MSPBase directory. This will build MSP Base classes and 
produce ..\lib\MSPBaseSample.lib file that this sample will link to.
- type "nmake" in the sampmsp directory.  This will build sampmsp.dll.

Platform SDK includes MSPBase.lib file which was produced by building MSPBase 
classes with ATL2.1. If your MSP uses ATL2.1, you can link it to MSPBase.lib
without building MSPBase classes yourself.

How to use the sample:
~~~~~~~~~~~~~~~~~~~~~~

Please refer to the Windows SDK documentation for step-by-step
instructions on hooking an MSP into your existing TSP, as well
as information on using the MSP base classes. Don't forget to
assign a unique GUID to your MSP rather than using the GUID that
comes with the sample (see sampmsp.idl).

Once you have made the appropriate modifications to your TSP, you
should be able to make a call using a TAPI 3.0 app (for example, one
of the other samples included in the Windows SDK) and follow the
execution of the SampMSP using the trace output and/or a debugger.
No actual media streaming will occur without modifications to the
sample MSP, as the sample MSP does not know how to access any
specific media transport mechanism (see below).

What functionality does this sample show:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* How to derive a DirectShow-based MSP implementation from the MSP
  base classes
* How to indicate the media types that the MSP supports (in this
  case audio)
* How to keep the number of available streams on a call constant to
  simplify MSP implementation
* How to limit each stream to one selected terminal at a time, to
  simplify MSP implementation
* How to connect and disconnect terminals
* How to control the media streams while keeping track of DirectShow
  graph states, correctly maintaining stream operation across
  terminal selection and unselection, and correctly handling errors
* How to define and implement MSP-TSP communication
* How and when to fire events to the application
* How to catch DirectShow filter graph events, and how to forward them
  to the application

What this sample does not show:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* How to create and connect the transport filters used to implement
  the stream. The procedure for this will vary widely depending on the
  types of filters that the MSP wants to control. Placeholders are
  included to show where to do this.
* How to create new streams or remove existing streams during a call
* How to mix or split the same stream between terminals; i.e., have
  multiple terminals selected on the same stream at the same time
* How to override the terminal implementations (versus standard
  terminal implementations from the  base classes)
* How to expose additional terminals (in addition to standard terminals
  from the base classes)
* How to withhold certain terminals (versus exposing all the standard
  terminals from the base classes)


Additional Notes on how to build the sample: 

 How to build the MSP CPP sample with VC5:
Note:  This sample will build only under the 
VC 5 and on Win2k whistler release.
-	IMPORTANT: start a new command prompt 
	(cmd.exe), or start a new "Set Win32 Environment" 
	cmd window from Programs - Microsoft Platform SDK .
-	go to the path where you installed VC5 
	(e.g. C:\Program Files\DevStudio\VC\bin) 
	and type VCVARS32.BAT.
-	go to the path where you installed SDK 
	(e.g. C:\Program Files\Microsoft Platform SDK) 
	and type SetEnv.Bat.
-	check the following environment variables: 
	PATH, LIB, INCLUDE. You can see their current 
	values by typing "SET" at the command prompt. 
	You should see that they contain first the SDK 
	paths and then the VC5 paths.
-	modify the environment variable "PATH" by adding 
	at the beginning of it the location of the linker 
	(link.exe) that came with the SDK 
	(e.g. C:\Program Files\Microsoft Platform SDK\Bin\Link). 
	This step is needed because the link.exe that comes with 
	VC5 will fail to link some of the lib files from 
	the NT5 SDK (e.g. kernel32.lib), because these lib files 
	have a newer format which is not compatible with the older linkers. 
-	go to the path where the TAPI  MSP sample is installed and type NMAKE
-	this should build the SampleMSP. 



