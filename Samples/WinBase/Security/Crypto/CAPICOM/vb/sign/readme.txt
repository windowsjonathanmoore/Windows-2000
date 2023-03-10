CAPICOM sample sign
-----------------------
Date:  January 15, 2001

The source code in this directory creates a program to sign a block of data and to verify that 
signature.
    
This demonstration program runs on Windows 9x with IE 5.0 or later, Windows NT 4.0 with
SP4 or later, Windows 2000 and Whistler.  It uses CAPICOM.dll an ActiveX component, that must 
be registered.

To run this demonstration program, all of the files must be in the same directory and Visual Basic 
must be available. Double click on the project file, Signing Demo.vbp.

This deomstration program uses the following files:

readme.txt                  -- this file

Signing Demo.vbp            -- Project file for this program

AuxFunctions.bas            -- VB code for auxillary functions used by this program.

Start Demo.frm              -- Definition of the main form used by this program.

Select Certificate.frm      -- Definition of the form used to display the certificates from
                               the MY certificate store and allow the user to select a certificate
                               to be used to create the signature.

Display Certificates.frm    -- Definition of the form used to display the certificates of all of
                               the signers of the data.
