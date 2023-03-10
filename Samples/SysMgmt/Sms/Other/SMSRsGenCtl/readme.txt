****************************************************************
  Copyright (c)1999 Microsoft Corporation, All Rights Reserved
****************************************************************

SMSRsGenCtl.dll


1. What SMSRsGenCtl.dll Does & How

   SMSRsGenCtl.dll allows a Visual Basic or script application to create a Discovery Data Record (DDR), using the functionality in the 'C' dll SMSRsGen.dll. 
   SMSRsGenCtl.dll is simply an automation compatible wrapper around this dll and adds no other functionality for DDR generation.   
   See the SMS SDK sample VC\MakeDDR for detail on the functionality offered by SMSRsGen.dll.


2. Running the testRsGenCtl.vbs Sample
   Ensure SMSRsGenCtl.dll has been registered and that SMSRsGen.dll is in the same directory or on the path.  This sample will create an example DDR and write it to the current directory.


3. Requirements

    Runs on:	Win 9X / NT 4.0+ 

    SMSRsGen.dll may be found in SMS SDK under VC\MakeDDR

    2 requirements: SMSRsGen.dll must be on the path or in the same directory, and SMSRsGenCtl.dll must have been registered using regsvr32.

    
    
	

    