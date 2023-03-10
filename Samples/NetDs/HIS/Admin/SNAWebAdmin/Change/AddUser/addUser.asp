<%@ LANGUAGE="VBSCRIPT"%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<META http-equiv="refresh" content="0; URL=../adduser/Add_User.asp">
<title>New Page 1</title>
</head>

<body>
<%
On Error Resume Next
	Username = Request.QueryString("User")
	LocalLU = Request.QueryString("LocalLU")
	if (LocalLU = "NO Default") then
		LocalLU = ""
	End If
	RemoteLU = Request.QueryString("RemoteLU")
	if (RemoteLU = "NO Default") then
		RemoteLU = ""
	End If
	Encryption = Request.QueryString("Encrypt")
	if (Encryption = "Yes") then
		Encryption = 1
	else
		Encryption = 0
	End If
	DynRemote = Request.QueryString("DynRemote")
	if (DynRemote = "Yes") then
		DynRemote = 1
	else
		DynRemote = 0
	End If
	Comment = Request.QueryString("Comment")
	
	Set WmiLocator = CreateObject("WbemScripting.SWBemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS")
	Set WmiObj = WmiNameSpace.Get("MsSna_ConfiguredUser")
	WmiObj.Security_.impersonationLevel = 3
	Set NewWmiObj = WmiObj.SpawnInstance_

' following is not needed. UserType is configured automatically
'	Set NewWmiObj.UserType=1

	NewWmiObj.Comment = Comment
	NewWmiObj.DefLocalLu = LocalLU
	NewWmiObj.Name = Username
	NewWmiObj.DefRemoteLu = RemoteLU
	NewWmiObj.DynRemote = DynRemote
	NewWmiObj.Encryption = Encryption
	NewWmiObj.Put_ wbemFlagReturnWhenComplete

	
if Err <> 0 Then
	MsgBox Hex(Err.Number) & "---" & Err.Description & "---" & Err.Source

	Set WBEMERR = CreateObject("WbemScripting.SWbemLastError")
	sExtErrNo = WBEMERR.Properties_("StatusCode")
	sExtErrText = WBEMERR.Properties_("Description")
	MsgBox sExtErrNo & "---" & sExtErrText & "<BR>"
	Err.Clear
End if	
%>
</body>

</html>

