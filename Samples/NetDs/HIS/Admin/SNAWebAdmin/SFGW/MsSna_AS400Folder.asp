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
<title>SNA SFGW AS400 ASP Query Page!</title>
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
		Set ServerClass = WmiNamespace.Get("MsSna_AS400Folder")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Folders = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<center>

<table BORDER="1">
  <tr>
    <th>Comment</th>
    <th>Drive</th>
    <th>Name</th>
    <th>Parent AS400</th>
    <th>Permanent?</th>
    <th>Share</th>
  </tr>
  
<%
	for each item in Folders
%>
  <tr>
    <td> <%=item.Comment%> </td>
    <td> <%=item.Drive%> </td>
    <td> <%=item.Name%> </td>
    <td> <%=item.ParentAS400%> </td>
    <td> <%=item.Permanent%> </td>
    <td> <%=item.Share%> </td>
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
