<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays information in a table
   for each Server in the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>SNA_Server ASP Query Page!</title>
</head>

<body>
<p align="center">
<IMG id=IMG1 src="../images/SNA.GIF" width="300" height="110" >
<%
	' Connect to the default namespace (root\MicrosoftHIS)
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS",vbNullString, vbNullString,vbNullString, vbNullString,0,Nothing)
	
	if Err = 0 then

		'Retrieve the SNA_Server class
		Set ServerClass = WmiNamespace.Get("MsSna_Server")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Servers = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<div align="center">
  <center>

<table BORDER="1">
  <tr>
    <th>Node </th>
    <th>Role </th>
    <th>Status</th>
    <th>Transport</th>
    <th>Offline</th>
  </tr>
<%
	for each item in Servers
%>
  <tr>
    <td> <%=item.Name%></td>
    <td> <%=item.RoleName%></td>
    <td> <%=item.StatusText%></td>
    <td> <%=item.TransportString%></td>
    <td> <%=item.IsOffline%></td>
  </tr>
<%
		Next
%>
</table>
  </center>
</div>
<%
	End If
%>
<p>&nbsp;</p>
<p align="center">&nbsp;</p>
</body>
</html>


