<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays APPC Mode information in a table
   for each mode in the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>SNA APPC Partnership ASP Query Page!</title>
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
		Set ServerClass = WmiNamespace.Get("MsSna_AppcPartner")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Partners = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<center>

<table BORDER="1">
  <tr>
    <th>Connection</th>
    <th>Local LU Alias</th>
    <th>Mode</th>
    <th>Partner LU Alias</th>
    <th>Server</th>
  </tr>
  
<%
	for each item in Partners
%>
  <tr>
    <td> <%=item.Connection%> </td>
    <td> <%=item.LocalLUAlias%> </td>
    <td> <%=item.Mode%> </td>
    <td> <%=item.PartnerLUAlias%> </td>
    <td> <%=item.Server%> </td>
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
