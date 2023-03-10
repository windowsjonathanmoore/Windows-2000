<%@ LANGUAGE="VBSCRIPT"%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
</head>

<body>
<p align="center">
<IMG id=IMG1 src="../../images/SNA.GIF" width="300" height="110" >
<h1 align="center"> Add 3270 LU's to User</h1>
<h2 align="center"> Step 1</h2>
<p align="center">Select User and click Submit:</p>

<form method="GET" name="SelectedUser" target="_self" action="SelectedUser.asp">
	<p align="center">User/Group Name : <select size="1" name="USER">
	<%
	' Connect to the default namespace (root\MicrosoftHIS)
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS","", "","", "",0,Nothing)
	
	if Err = 0 then

		'Retrieve the SNA_Server class
		Set ServerClass = WmiNamespace.Get("MsSNA_ConfiguredUser")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Users = ServerClass.Instances_
		For each item in Users
			UserName=item.Name
'			i=Instr(UserName,"\")
'			if i then
'				l=Len(UserName)
'				tempstr=UserName
'				LeftStr=Left(tempstr,i-1)
'				RightStr=Right(tempstr,l-i)
'				UserName=LeftStr & "\\" & RightStr
'			End If
			Dim re
			Set re = New RegExp
			re.Pattern = "\\"
			re.Global = True
			Username = re.Replace(UserName, "\\")
			%>
			<option><%=UserName%></option>
		<% next %>
		</select>
	<% End if%>
	<p align="center"><input type="submit" value="Submit" name="B1"><input type="reset" value="Reset" name="B2"></p>
</form>
</body>

</html>
