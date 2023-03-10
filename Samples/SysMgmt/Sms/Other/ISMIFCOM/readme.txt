****************************************************************
  Copyright (c)1999 Microsoft Corporation, All Rights Reserved
****************************************************************

ISMIFCOM.dll


1. What ISMIFCOM.dll Does & How

   ISMIFCOM.dll allows a Visual Basic or script application to create an SMS status MIF, using the functionality in the 'C' dll ISMIF32.dll. 
   ISMIFCOM.dll is simply an automation compatible wrapper around this dll and adds no other functionality for status MIF generation.   
   The SMS SDK documentation contains information on how to use ISMIF32.dll, and it applies equally to ISMIFCOM.dll.


2. Running the testMIFCOM.js Sample
   Ensure your machine is an SMS client and ISMIFCOM.dll has been registered. Simply invoke the test.js by double clicking it in explorer.  It will confirm a status MIF has been generated


3. Requirements

    Runs on:	Win 9X / NT 4.0+ 

    2 requirements: ISMIF32.DLL must be on the machine, and ISMIFCOM.dll must have been registered using regsvr32.

    The ISMIF32.DLL must be on the path or in the same directory as ISMIFCOM.dll. ISMIF32.DLL is installed as part of the SMS client and is placed in the windows directory, so provided an SMS client is installed on the machine then it will be found.
    
	

    