<%@ LANGUAGE="VBSCRIPT"%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<title>Add User To SNA Server</title>
</head>
<body>
<p align="center">
<IMG id=IMG1 src="../../images/SNA.GIF" width="300" height="110" >
<p align="left">Add User. Fill in fields and select Submit</p>

<p align="left">Configured Users:</p>
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
<table BORDER="1">
  <tr>
    <th>Name</th>
    <th>Comment</th>
    <th>Default Local LU</th>
    <th>Default Remote LU</th>
    <th>Dynamic Remote</th>
    <th>Encryption?</th>
    <th>User Type</th>
  </tr>
  
<%
	Dim strLU
	for each item in Users
%>
  <tr>
    <td> <%=item.Name%> </td>
    <td> <%=item.Comment%> </td>
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
  </tr>
<%
		Next
%>
</table>
<%
	End If
%>

<p align="left">Select New User:</p>

<form NAME="NEWUSER" method="GET" ACTION="../adduser/adduser.asp" target="_self">
	<p>User/Group Name :&nbsp;&nbsp;&nbsp; <select size="1" name="User">
	<option selected>Everyone</option>
	<%
	Set WmiLocator = CreateObject("WbemScripting.SWBemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\CIMV2")
	Set UserClass = WmiNamespace.Get("Win32_UserAccount")
	UserClass.Security_.impersonationLevel = 3
	Set Users = UserClass.Instances_
	For each item in Users
	%>
		<option><%=item.Caption%></option>
	<% next %>
	<%
	Set GroupClass = WmiNamespace.Get("Win32_Group")
	GroupClass.Security_.impersonationlevel = 3
	Set Groups = GroupClass.Instances_
	For each item in Groups
	%>
		<option><%=item.Caption%></option>
	<% next %>
	</select>

	<p>
	Local LU :&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <select size="1" name="LocalLU">
	<option selected>NO Default</option>
	<%
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS")
	Set ServerClass = WmiNamespace.Get("MsSna_LuAppcLocal")
	ServerClass.Security_.impersonationLevel = 3
	Set LocalLUs = ServerClass.Instances_
	for each item in LocalLUs
	%>
		<option><%=item.LUName%></option>
	<% next %>
	</select>
	<p>
	Remote LU :&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <select size="1" name="RemoteLU">
	<option selected>NO Default</option>
	<%
	Set ServerClass = WmiNamespace.Get("MsSna_LuAppcRemote")
	ServerClass.Security_.impersonationLevel = 3
	Set RemoteLUs = ServerClass.Instances_
	for each item in RemoteLUs
	%>
		<option><%=item.LUName%></option>
	<% next %>
	</select>
	<p>
	Encryption? :&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <select size="1" name="Encrypt">
	<option selected>No</option>
	<option>Yes</option>
	</select>
	<p>
	Dynamic Remote?&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <select size="1" name="DynRemote">
	<option selected>No</option>
	<option>Yes</option>
	</select><p>
	Comment :&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <input type="text" name="Comment" size="20" value="Created by WMI">
	<p><input type="submit" value="Submit" name="BtnSubmit"><input type="reset" value="Reset" name="BtmReset"></p>
</form>
</body>

</html>
