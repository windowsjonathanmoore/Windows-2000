<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays 3270 LUA LU information in a table
   for each LUA LU in the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>SNA 3270 LUA LU ASP Query Page!</title>
</head>

<body>
<p align="center">
<IMG id=IMG1 src="../images/SNA.GIF" width="300" height="110" >
<%
	' Connect to the default namespace
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS","", "","", "",0,Nothing)
	
	if Err = 0 then
		'Retrieve the SNA_LU_Lua class
		Set ServerClass = WmiNamespace.Get("MsSNA_LuLua")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set LU3270 = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<center>

<table BORDER="1">
  <tr>
    <th>Name</th>
    <th>Number</th>
    <th>Comment</th>
    <th>Compression</th>
    <th>Connection Name</th>
    <th>Pool Name</th>
    <th>UserWksSecure</th>
  </tr>
  
<%
	Dim strLu
	for each item in LU3270
%>
  <tr>
    <td> <%=item.Name%> </td>
    <td> <%=item.Number%> </td>
    <%    
    	strLU = item.Comment
	    if (strLU = "") then
	    	strLU = "none"
	    End if
    %>
    <td> <%=strLU%> </td>
    <td> <%=item.Compression%> </td>
    <td> <%=item.ConnectionName%> </td>
    <% 
    	strLU = item.PoolName
    	if (strLU = "<None>") then
    		strLU = "none"
    	end if
    %>
    <td> <%=strLU%> </td>
    <td> <%=item.UserWksSecure%> </td>
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
