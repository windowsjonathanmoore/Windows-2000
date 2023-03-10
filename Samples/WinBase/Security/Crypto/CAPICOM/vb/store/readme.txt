CAPICOM sample Store
-----------------------
Date:  January 15, 2001

The source code in this directory creates a program to manage certificates and cetificate stores.
It then demonstrates:
    opening a certificate store including current user stores, local machine stores, and
      active directory stores. 
    displaying the certificates in an open store
    exporting the certiciates in a certificate store
    importing certicates into a store
    deleting certificates from a store
    adding cetificates to a store
    
This demonstration program runs on Windows 9x with IE 5.0 or later, Windows NT 4.0 with
SP4 or later, Windows 2000 and Whistler.  It uses CAPICOM.dll an ActiveX component, that must 
be registered.

Active directory stores can be used only with Windows 2000 with access to a domain supporting
active directory.

This deomstration program uses the following files:

readme.txt                -- this file

Manage Certificates.vbp   -- Visual Basic Project file

AuxFunctions.bas          -- File containing VB code for auxillary functions for this project.

Certificate Stores.frm    -- Defines the Cretificate Stores form which starts the program.

Cert Chains.frm           -- Defines the form used to create and display certificate trust cahins.


