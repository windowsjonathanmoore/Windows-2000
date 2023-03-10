CAPICOM VB Script samples
-----------------------
Date:  January 15, 2001

These demonstration scripts run on Windows 9x with IE 5.0 or later, Windows 
NT 4.0 with SP4 or later, Windows 2000 and later.  It uses CAPICOM.dll, an 
ActiveX component, that must be registered.

Many of the sample programs require one or more test certificates. 

You can obtain a test certificate from a Certificate Authority such as 
Verisign.

Alternatively, you can create a self-signed certificate using MAKECERT.EXE 
from the signing tools.

Download the signing tools from:

  http://msdn.microsoft.com/downloads/default.asp?URL=/code/sample.asp?url=/msdn-files/027/000/219/msdncompositedoc.xml

Once MAKECERT.EXE has be downloaded, run the following command at the command 
prompt to create a self-signed certificate.  Substitute your name for xxx, 
your organization for yyy, and your company name for zzz.

    makecert -r -n "cn=xxx, ou=yyy, o=zzz" -ss my

The self-sined certificate is placed in the current user's MY store.  You must 
also import the self-signed certificate into your Root store so that it is 
trusted.

Follow the steps below to import your self-signed certificate to the Root 
store:

    1. Start Internet Explorer
    2. Click on Tools/Internet Options
    3. Click on Content tab
    4. Click on Certificates button
    5. Select the self-signed certificate, Click Export, and follow the screen 
       to export the certificate
    6. Click Import and follow the screen to import the self-signed 
       certificate to the Root store 

This directory contains the following files:

    1. ReadMe.txt   - This file
    2. Store.vbs    - Display all of the certificate in the current 
                      user MY certificate store.
    3. Sign.vbs     - Sign the contents of a file
    4. CoSign.vsb   - Cosign a previously signed message
    5. Verify.vbs   - Verify the signature(s) of a previously 
                      signed/cosigned message
    6. Envelop.vbs  - Envelop the contents of a file
    7. Denvelop.vbs - Decrypt a previously enveloped message
    8. Encrypt.vbs  - Encrypt the contents of a file
    9. Decrypt.vbs  - Decrypt a previously encrypted message
