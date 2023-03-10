============================================
Instant Messaging Redistribution Information
============================================

The client component files consist of the following: 

msimcntl.dll  This file contains the Microsoft® ActiveX® controls that provide 
	      the Exchange Instant Messaging Service (IM) user interfaces for the 
              Contact View and Message View controls.
msimhost.exe  This executable file provides the IM client services and exposes 
	      interfaces for IM services, contacts, and message sessions.
msimmsgr.dll  This file provide IM client protocol services.
msimnetc.dll  This file provide IM client protocol services.

To distribute these files, you must register them on the client computer. 

To register the client component files Copy the files from the server’s 
Support directory to the client computer.

Register each of the three .dll files from the command prompt using the regsvr32 command. 

For example: 
C:\> regsvr32 <your install path>\msimcntl.dll

Register the executable file using the regserver command. 

For example: 
C:\> <your install path>\msimhost.exe /regserver

Before you remove the client component files, you must unregister them on the client computer.

To unregister the client component files

Unregister each of the three .dll files from the command prompt using the regsvr32 –u command. 

For example: 
C:\> regsvr32 -u <your install path>\msimcntl.dll

Unregister the executable file using the unregserver command. 

For example: 
C:\> <your install path>\msimhost.exe /unregserver

