CAPICOM sample Envelop
-----------------------
Date:  January 15, 2001

The source code in this directory creates a program that demonstrates the use of the EnvelopedData 
CAPICOM object to encrypt a message for one or more recipients. The message is encypted
with a randomly generated encryption key. The encryption key is then encrypted separatly 
for each recipient using the public key form the
recipient's certificate.

The EnvelopedData object contains the encryted message, information about the
encryption algorithm and key length, certificate of each intended receiver, and a separate
encryted encryption key for each recipient.

When an enveloped message is recieved, a search is made of the recipeints MY certificate
store. If a match is found between a certificate in the MY store and one of the
certificates in the EnvelopedData object, and if the certificate in the MY store has
an associated private key, the receivers private key is used to decrypt the encryption key
and that decrypted key is used to decrypt the message.

    
This demonstration program runs on Windows 9x with IE 5.0 or later, Windows NT 4.0 with
SP4 or later, Windows 2000 and Whistler.  It uses CAPICOM.dll an ActiveX component, that must 
be registered.

To run this demonstration program, all of the files must be in the same directory and Visual Basic 
must be available. Double click on the project file, envelop demo.vbp.

This deomstration program uses the following files:

readme.txt                 -- This file

auxFunctions.bas           -- code for auxillary functions

envelop start.frm          -- definition for the envelop start form

load certificates.frm      -- definition for the from used to load and select recipient
                              certificates.

show recipients.frm        -- definition of the from used to display the certificates of
                              intended receivers of the enveloped message.

envelop demo.vbp           -- Visual Basic Project file


