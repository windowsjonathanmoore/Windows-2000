****************************************************************
  Copyright (c)1999 Microsoft Corporation, All Rights Reserved
****************************************************************

1. What CliStat Does & How

    After parsing the command line options and setting the appropriate values, 
    the CliStat tool uses the SMSCStat.dll file on a client machine to send a 
    status message to the client's parent sms site.  The sample starts by
    calling LoadLibrary() on the SMSCStat.dll, and then using GetProcAddress()
    to obtain the function pointers for several of the DLL's methods.  Last, the 
    clistat sample uses the values from the command line arguments, and the 
    imported DLL functions to raise status messages.

2. Running the Sample

    Command Line Arguments:

	CliStat <Message ID> <Module Name> [options]
	
	Requirements:
	  Message ID  : The ID of the status message string	
	  Module Name : The Module Name of the DLL containing the status message string

	Options:
	  -C:<Component Name>    : The name of the component raising the status message
	  -E:<Win32 Error Code>  : The Win32 Error code of the status message
	  -I:<ins string 1>,<ins string 2>,...,<ins string 10>:
				 : Specifies the insertion strings for\n"
				 :  the raised status message
	  -A:<attrib id>,<value> : Sets the status message attribute for <attrib id> 
				 : to <value> (attrib id range: 400-404)

3. Requirements

    Runs on: Any SMS Client machine, Win9x or WinNT

4. Building the Sample

    Using NMAKE:
	Running NMake at the command line will build the default "makefile" in
	the sample's directory.

    Using the VC++ IDE:
	Open the .DSP Project file and select Build -> Build
	

    