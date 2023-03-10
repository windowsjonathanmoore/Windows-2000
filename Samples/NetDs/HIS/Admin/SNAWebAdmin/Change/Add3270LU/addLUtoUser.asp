<%@ LANGUAGE="VBSCRIPT"%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<title>New Page 1</title>
</head>

<body>
<%
	UserName = Request.QueryString("UserName")
	NewLU = Request.QueryString("NewLU")
	quote=chr(34)
	Set WmiLocator = CreateObject("WbemScripting.SWBemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS")
	Set WmiObj = WmiNameSpace.Get("MsSNA_LUDisplayAssignedToUser")
	WmiObj.Security_.impersonationLevel = 3
	Set NewWmiObj = WmiObj.SpawnInstance_
	NewWmiObj.PathToLuDisplay = "MsSNA_LuDisplay.Name=" + quote + NewLU + quote
	NewWmiObj.PathToUser = "MsSNA_ConfiguredUser.Name=" + quote + UserName + quote
	%>
	<P><% =NewWmiObj.PathToLuDisplay %>
	<p><% =NewWmiObj.PathToUser %>
	<%
	NewWmiObj.Put_ wbemFlagReturnWhenComplete
	%>	
</body>

</html>

