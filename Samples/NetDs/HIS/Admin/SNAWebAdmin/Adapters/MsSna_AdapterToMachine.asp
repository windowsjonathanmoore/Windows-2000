<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays information in a table
   for each Adapter in the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>SNA Adapter To Machine ASP Query Page!</title>
</head>

<body>
<p align="center">
<IMG id=IMG1 src="../images/SNA.GIF" width="300" height="110" >
<%
	' Connect to the default namespace (root\MicrosoftHIS)
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS","", "","", "",0,Nothing)
	
	if Err = 0 then

		'Retrieve the SNA_Server class
		Set ServerClass = WmiNamespace.Get("MsSNA_AdapterOnMachine")
		Set Path = ServerClass.Path_

		' Enable impersonation before we retrieve
		' the Disk instances otherwise access will
		' be denied
		ServerClass.Security_.impersonationLevel = 3
		Set Adapters = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<center>

<table BORDER="1">
  <tr>
    <th>Path to Adapter</th>
    <th>Path to Connection</th>
  </tr>
  
<%
	for each item in Adapters
%>
  <tr>
    <td> <%=item.PathToAdapter%> </td>
    <td> <%=item.PathToServer%> </td>
  </tr>
<%
		Next
%>
</table>
</center>
<%
	End If
%>
</body>
</html>
