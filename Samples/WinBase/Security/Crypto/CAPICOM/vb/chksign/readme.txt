CAPICOM sample chksign
-----------------------
Date:  January 15, 2001

chksign is a Visual Basic sample for the ActiveX control CAPICOM.
    
This demonstration program is designed to run on Windows 2000 and Whistler. While this 
program will run Windows NT4 and Win 9x, it will not exit upon completion.  Even though the program
finishes, it still shows up in task manager. A hot fix for Windows NT 4.0 can download  from:   

      http://support.microsoft.com/support/kb/articles/Q238/9/34.ASP

 
This sample program uses CAPICOM.dll, an ActiveX component that must 
be registered. 

Chksign is a Visual Basic application that will verify the signature
on PKCS#7 documents and report error information.  Note, it currently
only supports verifying PKCS#7 documents that store the signature and 
the content.  It does not support verification of "detached" signatures".

Requirements
------------
This sample requires the latest service pack for Visual Studio 6.0
Dependencies: 
  COMDLG32.OCX, minimum version 6.00.8418
  MSCOMCTL.OCX, minimum version 6.00.8862
  SCRRUN.DLL, 5.1.0.5010

