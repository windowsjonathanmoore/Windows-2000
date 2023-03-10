CAPICOM samples
-----------------------
Date:  January 15, 2001

All of the sample programs use CAPICOM.DLL. You must have this dll registered prior to using 
these samples.

Many of the sample programs require one or more test certificates. 

You can obtain a test certificate from a Certificate Authority such as Verisign.

Alternatively, you can create a self-signed cert using the SDK tool, makecert.exe

Download the signing tools from:
  http://msdn.microsoft.com/downloads/default.asp?URL=/code/sample.asp?url=/msdn-files/027/000/219/msdncompositedoc.xml

Once makecert.exe has be downloaded, run the following command at the command prompt. Substitute 
your name for xxx, your organization for yyy and your company name for zzz

  makecert -r -n "cn=xxx, ou=yyy, o=zzz" -ss my

The certificate is placed in the current user's MY store. Import the certificate created 
into your root store so that it is trusted.
