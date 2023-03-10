<%@ LANGUAGE="VBSCRIPT"%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<META http-equiv="refresh" content="0; URL=../Deleteuser/Delete_User.asp">
<title>New Page 1</title>
</head>

<body>
<%
	UserName=Request.QueryString("UserName")
	Set WmiLocator = CreateObject("WbemScripting.SWBemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS")
	
	strQuery = "SELECT * FROM MsSna_ConfiguredUser WHERE Name =" &  "'" & UserName & "'"
	
	Call ExecuteQuery(WmiNameSpace, strQuery)	

Private Sub ExecuteQuery(objService, strQuery)
'	On Error Resume Next
	Dim objEnumerator, objInstance, strMessage
	Set objEnumerator = objService.ExecQuery(strQuery)		
	For Each objInstance in objEnumerator				' line 33
		If Err.Number then
			Err.Clear
		Else							
			if objInstance is nothing Then			
				Exit Sub
			Else
				objInstance.Delete_		
			End If						
		End If
	Next
	if Err <> 0 then	
		strMsg = Hex(Err.Number) & "---" & Err.Description & "---" & Err.Source
		Set WBEMERR = CreateObject("WbemScripting.SWbemLastError")
		sExtErrNo = WBEMERR.Properties_("StatusCode")
		sExtErrText = WBEMERR.Properties_("Description")
		strMsg = strMsg & vbCR & vbLF & sExtErrNo & "---" & sExtErrText
		MsgBox strMsg
	End If
End Sub
%>
</body>

</html>

