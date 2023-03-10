ReadMe.txt - Connection Manager Sample (CMSample.dll)
Date 01/18/2001

Development environment: 
  VC 6.0 - compiled as Non-UNICODE
  Platform SDK - Oct 2000
========================================


The CMSAMPLE contains these files:
-------------------------------------
cmsample.cpp	Main entry point, custom action function (SetProxyUsingTunnelAddress) and other utility functions
cmsample.def	Contains DLL function exports
cmsample.mak	makfile - generated from VC
ReadMe.txt	This text file

The CMSAMPLE SDK sample demonstrates how to write a dynamic-link library custom action to be used with Microsoft Connection Manager.  CM is Microsoft's managed remote access client.  It allows an administrator to build a remote access configuration package to be distributed to the administratorís remote users.  One of the most powerful features of CM is to add custom actions at various points during the connection process.  More details on Connection Manager and its administration kit (Connection Manager Administration Kit) can be found in the help for Microsoft Whistler Server or Microsoft Windows 2000 Server.

This particular custom action can be used to help integrate the tunnel endpoint selection feature of CM with the proxy management feature of CM.  Normally CM only allows one proxy server setting per configuration package.  However, your network might have a different proxy server configuration for every branch office network.  Thus you want to change the proxy server setting per Virtual Private Networking (VPN) server address in your configuration package.  This custom action (cmsample.dll) solves that problem.  Perhaps more importantly, however, this sample provides a building block for others who might want to create a CM custom action.

In order to run the cmsample.dll once it is compiled, you will need two additional files:  the tunnel file (input) and the ProxyFile (output)

TunnelFile
----------
The TunnelFile contains the tunnel addresses mapped to a proxy server. The file format is the following:

[Tunnel Address]
my.domain.com=myproxy1:80
my.domain2.com=myproxy2:80
my.domain3.com=myproxy1:80

ProxyFile
---------
The ProxyFile contains the configuration information for your proxy client.  This file is normally consumed by cmproxy.dll (a built in CM custom action) and will be included in your configuration package if this option was selected in CMAK. The file format is the following:

[Manual Proxy]
ProxyEnable=1
ProxyOverride=<local>
ProxyServer=someproxy:80

Thus if you were to call cmsample.dll with the above input/output files and specify that the tunnel address selected by the user was my.domain.com, then the ProxyFile would change from the above to the following:

[Manual Proxy]
ProxyEnable=1
ProxyOverride=<local>
ProxyServer=myproxy1:80

Note that the ProxyServer entry has changed based on the tunnel selection.  This is a very simple example of the power of CM custom actions.

The syntax for the main entry point for each custom action is:

HRESULT WINAPI <functionName>
	[IN] HWND hWndParent
	[IN] HINSTANCE hinstDll
	[IN] LPCSTR pszCommandLine
	[IN] DWORD dwReserved

In this sample <function> is replaced by: SetProxyUsingTunnelAddress. The SetProxyUsingTunnelAddress is the main entry point into the DLL which contains all of the functionality needed to perform by this custom action DLL.

Supported DLL parameters are:

Parameter 	Result 
------------------------
hWndParent 	Handle to the Connection Manager logon dialog box or NULL; 
hinstDll 	Handle to the instance of this DLL. 
pszCommandLine 	String pointer to the command-line arguments. 
dwReserved 	Reserved for future use. 


Functionality Summary
---------------------
First, parse the command line. The command line is of the form: 
	/ServiceDir %SERVICEDIR% /TunnelAddress %TUNNELADDRESS% /ProxyFile <PROXYFILE> /TunnelFile <TUNNELFILE>

	The GetArgV utility function helps to parse the command line arguments. This is just one way of parsing the command line.

Second, read the Proxy Server name by looking up the Tunnel Address from the TunnelFile.
Third, write out the looked-up Proxy Server name to the ProxyFile.


Macros
------
CMSample uses two special command-line parameter macros. These are %SERVICEDIR% and %TUNNELADDRESS%. If you use these special macros,  
Connection Manager replaces them with the actual run-time information for the parameter.  For testing purposes, you can replace %SERVICEDIR% with the path to the directory where the input and output files are located (normally the CM profile directory).  Similarly, %TUNNELADDRESS% can be replaced by one of the tunnel address items in the TunnelFile (vpn.mydomain.com or whatever).  For more information on CM command-line macros please refer to the "Incorporating custom actions" page of the CMAK help.


Enabling Cmsample.dll as a Custom Action
----------------------------------------
To enable CMSample you need to configure it as a Post-connect action when you create a connection profile using CMAK. You should make sure that the cmsample.dll custom action runs before the built-in cmproxy.dll custom action.  When CM is ready to execute the Post-connect actions, it will load the CMSample.dll and call the entry function using the parameters that you specified.




