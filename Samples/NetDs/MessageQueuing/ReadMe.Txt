MSMQ 2.0 can be setup in two distinct modes of operation with regards to access to Active Directory - 
DS enabled and DS disabled (also known as workgroup mode). 
The readme files for each sample in this directory explain in detail what setup mode is required and/or 
what the differences are in the expected behavior when running the samples in different modes.
When you run MSMQ 2.0 setup on a computer belonging to a workgroup, setup automatically installs 
MSMQ 2.0  in DS disabled mode. Note however that if, after MSMQ 2.0  has been setup, the computer 
joins a Windows 2000 domain with MSMQ 2.0 deployed, the MSMQ service will automatically attempt to 
join the MSMQ 2.0 deployment and, if successful, switch to DS enabled mode.

When you run MSMQ 2.0 setup on a computer belonging to a Windows 2000 domain you can explicitly 
choose to install in either of the modes by checking “Manually select access mode to Active Directory” 
tab on the first page of the setup.


This directory contains several sub-directories for MSMQ sample programs:

Sub-directory	Description
-------------	              ---------------
booksrvr	              This application demonstrates how to use the MSMQ Mail components with C.
                            Can be compiled and run on MSMQ 2.0 or later.

C_DRAW		C++ distributed drawing application.  
                            Port of VB_DRAW implemented with the MSMQ SDK C API.
                            Interops with VB_DRAW and IMP_DRAW.
                            Can be compiled and run on MSMQ 1.0 or later.

direncrypt  	This application demonstrates how to encrypt and send an MSMQ message using 
                            Direct mode. The message is encrypted by the application itself.
                            Can be compiled and run on MSMQ 2.0 or later.

Imp_Draw	              C++ distributed drawing application.
		Port of VB_DRAW implemented with the MSMQ COM components.
		Interops with C_DRAW and VB_DRAW.
		Can be compiled and run on MSMQ 1.0 or later.

JavaDraw	              Java distributed drawing application. Does not interoperate with C_DRAW, 
		IMP_DRAW and VB_DRAW.
		Implemented with the MSMQ COM components.
		Requires Java SDK 3.2.
		Can be compiled and run on MSMQ 2.0 or later.

MQAPITST	GUI application to interactively invoke MSMQ C APIs.
		Can be compiled and run on MSMQ 1.0 or later.

MQASP 		Shows how to perform basic server-side message queuing operations 
		using the MSMQ COM components.  Demonstrates IIS server-side scripting 
		with ASP/VBS.
		The server side has to be a DS enabled computer, running MSMQ 1.0 or later.

MqPers		C++ console application that demonstrates how to build and send a 
		persistable COM object using MSMQ.
		Implemented in terms of ATL and the MSMQ COM components.
		Can be compiled and run on MSMQ 2.0 or later.

mqport		C++ console application demonstrating how to use completion ports
		to asynchronously receive MSMQ messages.  Implemented with
		both the MSMQ SDK C API and the MSMQ COM components.
		Can be compiled and run on MSMQ 2.0 or later.

MQTESTOA	C++ console app that demonstrates how to send and receive messages
		between processes.  Implemented with the MSMQ COM components.  Interops
		with msmqtest.
		Can be compiled and run on MSMQ 2.0 or later.

MQTRANS             C++ console app that demonstrates how to send/receive coordinated 
		transactions that include MSMQ messages and SQL database updates.
		Can be compiled and run on MSMQ 1.0 or later.

mqtrigger	              VB and C++ application that shows how to use NT MSMQ PerfMon counters
		in order to implement trigger functionality. 
		NOTE: this sample is unrelated to the "MSMQ Triggers" component that is
		available on the Windows 2000 Resource Kit.
		Can be compiled and run on MSMQ 2.0 or later.

msmqtest	              C++ console app that demonstrates how to send and receive messages
		between processes. Implemented with the MSMQ SDK C API.  Interops 
		with MQTESTOA.
		Can be compiled and run on MSMQ 2.0 or later.

replyall 	              Demonstrates how to use the MSMQ Mail COM object library from VB.
		Can be compiled and run on MSMQ 1.0 or later, on a DS enabled computer only.

VB_DRAW             VB distributed drawing application.  Interops with C_DRAW and IMP_DRAW.
		Can be compiled and run on MSMQ 2.0 or later.

VBTrans		VB application that sends and receives transactional messages.
		Demonstrates how the receiver can identify which transactions the 
		messages belong to.
		Can be compiled and run on MSMQ 2.0 or later.