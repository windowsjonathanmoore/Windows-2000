<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays SNA Domain information in a table
   for the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>SNA_Domain ASP Query Page!</title>
</head>

<body>
<p align="center">
<IMG id=IMG1 src="../images/SNA.GIF" width="300" height="110" >
        		
<%
	' Connect to the default namespace (root\MicrosoftHIS)
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	' Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS","", "","", "",0,Nothing)
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS", vbNullString, vbNullString, vbNullString, vbNullString,0, Nothing)

	if Err = 0 then

		'Retrieve the SNA_Server class
		Set ServerClass = WmiNamespace.Get("MsSna_Domain")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Domains = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<div align="center">
  <center>

<table BORDER="1">
  <tr>
    <th>Domain</th>
    <th>Audit Level</th>
    <th>Broadcast Mean Time</th>
    <th>Config Server</th>
    <th>Client Backup Sponsor Names</th>
    <th>Client Domain Backup Type</th>
    <th>3270Security</th>
    <th>Domain Security?</th>
  </tr>
<%
	for each item in Domains
%>
  <tr>
    <td> <%=item.Name%></td>
    <td> <%=item.AuditLevel%></td>
    <td> <%=item.BroadCastMeanTime%></td>
    <td> <%=item.ConfigServer%></td>
    <td> <%=item.ClientBackupSponsorNames%></td>
    <td> <%=item.ClientDomainBackupType%></td>
    <td> <%=item.Security3270%></td>
    <td> <%=item.Domainsecurity%></td>
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
</body>
</html>
