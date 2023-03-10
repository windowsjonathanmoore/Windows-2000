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
<title>SNA Users ASP Query Page!</title>
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
		Set ServerClass = WmiNamespace.Get("MsSna_ConfiguredUser")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Users = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<div align="center">
  <center>

<table BORDER="1">
  <tr>
    <th>Name</th>
    <th>Default Local LU</th>
    <th>Default Remote LU</th>
    <th>Dynamic Remote</th>
    <th>Encryption?</th>
    <th>User Type</th>
    <th>Comment</th>
  </tr>
  
<%
	Dim strLU
	for each item in Users
%>
  <tr>
    <td> <%=item.Name%> </td>
<!-------------------------------------------------------------------------
    the following code checks to see if a Default
    Local LU is configured for the user
---------------------------------------------------------------------------->    
    <%
    strLU = item.DefLocalLU
    if (strLU = "<None>") then
    	strLU = "No Default"
    End if
    %>
    <td> <%=strLU%> </td>
<!-------------------------------------------------------------------------
    the following code checks to see if a Default
    Remote LU is configured for the user
---------------------------------------------------------------------------->    
    <%
    strLU = item.DefRemoteLU
    if (strLU = "<None>") then
    	strLU = "No Default"
    End if
    %>
    <td> <%=strLU%> </td>
<!-------------------------------------------------------------------------
    the following code checks to see if
    Dynamic LUs are set for the user
---------------------------------------------------------------------------->    
	<td> <%=item.Dynremote%> </td>
    <td> <%=item.Encryption%> </td>
    <td> <%=item.UserType%> </td>
    <td> <%=item.Comment%> </td>
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
