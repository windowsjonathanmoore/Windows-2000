
PURPOSE :
=========

The purpose of this sample is to demonstrate the use the CustomScripting Ras Api
available on the RasClients and how it can be used with the other 3rd party
security apis on ther server side.

This Sample will work only on Win2k.

DATES :
=======

Oct 28'th 1999 - SamirM
(samirm@microsoft.com)

REQUIREMENTS TO RUN THE SAMPLE :
================================

1) NT Wks/Srv
2) NT Wks/Srv
3) Modems on each machine with phone line.


WHAT DOES THE SAMPLE DO :
=========================

There are three directories under this sample.

1) customentry : This creates a exe "customentry.exe". This exe will create a
   customentry which has the RASEO_CustomScript Flag set and will use the dll
   build by customclient to dial out.

2) customclient : This creates a dll custom.dll.  This dll needs to be registered
   at following place in the registry.

   (a) Make sure that the path to the customscripting dll is set in 
       \\HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\Rasman\Parameters\ 
       REG_EXPAND_SZ: CustomScriptDllPath.

   (b) The CustomScriptDll should export the entrypoint as below - RasCustomScriptExecute.

   (c) For the defination of the RasCustomScriptExecute see the spec.txt

3) customsrv : This uses the 3rd party security dll mechanism provided by the
   RasServer. See the readme file provided under the rashost sample in sdk.
   It defines in detail how the 3rd party security stuff works.


HOW DOES THE SAMPLE WORK ?
==========================

On the server side register the dll "customsrv.dll" using the ini file provided
in the sample or by manually editing the registry. Stop remoteaccess service and
restart it. ( net stop remoteaccess and then net start remoteaccess). 
Now the control will be passed to this dll before PPP kicks in for any modem
connection made to this server. 

The client creates a custom connectoid ( one in which the RASEO_CustomScript flag is
set). When we dial out from the client the RasCustomScriptExecute Entry Point in the
dll registered at the above registry location gets called. 

The RASDIALPARAMS get passed to the RasCustomScript Api also. 
The application internally modifies the username to "Administrator" and
password to "", to demonstrate that the RasDialParams can be changed
by this RasCustomScript Api as needed.

The Client Sends a string "Whassup Dude!" to the server. 
The Server Responds back saying "Nothing Much".


STEPS TO RUN THE SAMPLE :
=========================


1) Build the customentry.exe and run customentry <entry_name> <phoneNumberTobeDialed>

2) On the server side register the customsrv.dll in the registry at the following 
   reg location.

  - Edit the registry on the server:

  - Go to  HKLM\SOFTWARE\Microsoft\RAS.
  - Add a key SecurityHost
  - To that key, add a value named DLLPath of type REG_SZ and give full path
    to the security dll.  (example:  d:\customsrv\customsrv.dll)

    Example regini script:

    \Registry\Machine
        Software
           Microsoft
              RAS
                 SecurityHost
                    DLLPath = REG_SZ d:\customsrv\customsrv.dll


    Stop the remote access service and restart it.
    (Or just reboot the machine).

3) On the Client Side register the custom.dll at the location specified above.

   \\HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\Rasman\Parameters\
    REG_EXPAND_SZ: CustomScriptDllPath. 

    Give the full path where the custom dll can be found.

4) Dial out using the entry created in one.


You will see that client is sending the string "Whassup dude!" and the
server replying with "Nothing Much".

If you attach a ntsd to the svchost running remoteaccess service on the
server side then you will see that server actually receives the above mentioned
string. This all happens before the PPP kicks in.

5) On the Client Side the RasCustomScriptExecute changes the password and
   username to   "" and Administrator resepectively.  
    So to dial with a different username and password you will have to change
    the code in "custom.dll".

