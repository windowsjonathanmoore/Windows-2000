<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays information in a table
   for each Pool in the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>SNA_Pool_Lua ASP Query Page!</title>
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

		'Retrieve the SNA_LU_APPC_Local class
		Set ServerClass = WmiNamespace.Get("MsSna_Pool")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Pool = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<center>
<p>Configured Pools
<table BORDER="1">
  <tr>
    <th>Name</th>
    <th>Comment</th>
  </tr>
<%
	for each item in Pool
%>
  <tr>
    <td> <%=item.Name%></td>
    <td> <%=item.Comment%></td>
  </tr>
<%
		Next
%>
</table>

<%
		Set ServerClass = nothing
		Set Path = nothing
		Set Pool = nothing
		Set ServerClass = WmiNamespace.Get("MsSna_PoolDisplay")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Pool = ServerClass.Instances_
		Set PoolDisplay = ServerClass.Instances_
%>
<p align="center">Path of object is <%=Path.DisplayName%>
<p>Display Pools
<table BORDER = "1">
	<tr>
    <th>Name</th>
    <th>Comment</th>
    <th>Model</th>
    <th>Model Override?</th>
    <th>Associated Printers?</th>
	</tr>
<%
	for each item in PoolDisplay
%>
	<tr>
		<td><%=item.Name%></td>
		<td><%=item.Comment%></td>
		<td><%=item.Model%></td>
		<td><%=item.ModelOverride%></td>
		<td><%=item.AssocPrint%></td>
	</tr>
<%
	next
%>
	
</table>

<%
		Set ServerClass = nothing
		Set Path = nothing
		Set Pool3270 = nothing
		Set ServerClass = WmiNamespace.Get("MsSna_PoolDown")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Pool = ServerClass.Instances_
		Set PoolDown = ServerClass.Instances_
%>
<p align="center">Path of object is <%=Path.DisplayName%>
<p>DownStream Pools
<table BORDER = "1">
	<tr>
    <th>Name</th>
    <th>Comment</th>
    <th>Model</th>
    <th>Model Override?</th>
    <th>Associated Printers?</th>
	</tr>
<%
	for each item in PoolDown
%>
	<tr>
		<td><%=item.Name%></td>
		<td><%=item.Comment%></td>
		<td><%=item.Model%></td>
		<td><%=item.ModelOverride%></td>
		<td><%=item.AssocPrint%></td>
	</tr>
<%
	next
%>
	
</table>

<%
		Set ServerClass = nothing
		Set Path = nothing
		Set PoolDown = nothing
		Set ServerClass = WmiNamespace.Get("MsSna_PoolLua")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Pool = ServerClass.Instances_
		Set PoolLua = ServerClass.Instances_
%>
<p align="center">Path of object is <%=Path.DisplayName%>
<p>LUA Pools
<table BORDER = "1">
	<tr>
    <th>Name</th>
    <th>Comment</th>
	</tr>
<%
	for each item in PoolLua
%>
	<tr>
		<td><%=item.Name%></td>
		<td><%=item.Comment%></td>
	</tr>
<%
	next
%>
	
</table>



  </center>

<%
	End If
%>
</body>
