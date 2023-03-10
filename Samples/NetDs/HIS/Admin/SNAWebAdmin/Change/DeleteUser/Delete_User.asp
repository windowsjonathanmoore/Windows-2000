<%@ LANGUAGE="VBSCRIPT"%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<title>Delete User From SNA Server</title>
</head>
<body>
<p align="center">
<IMG id=IMG1 src="../../images/SNA.GIF" width="300" height="110" >
<p align="left">Delete User. Select the user you want to delete by highlighting the name and
clicking</p>

<p align="left">Installed Users:</p>
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
<div align="center">
  <center>
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
  <td>
  <%
  	UserName=item.Name
  	i=Instr(UserName,"\")
  	if i then
  		l=Len(UserName)
  		tempstr=UserName
  		LeftStr=Left(tempstr,i-1)
  		RightStr=Right(tempstr,l-i)
  		UserName=LeftStr & "\\" & RightStr
  	End If
  %>
  	<applet code="fphover.class" codebase="../../../" width="180" height="24">
  		<param name="text" value=<%=item.Name%>>
  		<param name="textcolor" value="#008000">
  		<param name="hovercolor" value="#FF0000">
  		<param name="effect" value="glow">
  		<param name="target" value="_self">
  		<param name="url" valuetype="ref" value="DeleteUser.asp?UserName=<%=UserName%>">
  		<param name="fontsize" value="12">
  		<param name="fontstyle" value="regular">
  	</applet>
  </td>
  <td><%=item.Comment%></td>
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
  </center>
</div>
<%
	End If
%>

</body>

</html>
