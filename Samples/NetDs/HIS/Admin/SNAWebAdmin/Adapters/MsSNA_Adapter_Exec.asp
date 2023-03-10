<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays information in a table
   for each Adapter in the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>ALL SNA Adapters Page!</title>
</head>

<body>
<%
Response.Write "<p align=center>"
%>
<center>
<IMG id=IMG1 src="../images/SNA.GIF" width="300" height="110" >
<%
	' Connect to the default namespace
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWBemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS")
	
	' setup the query string we are going to use here
	strQuery = "Select * FROM MsSna_Adapter"
	
	'Now execute the query.
	Call ExecuteQuery( WmiNameSpace , strQuery)

Private Sub ExecuteQuery(objService, strQuery)
    Dim objEnumerator, objInstance, strMessage
    Set objEnumerator = objService.ExecQuery(strQuery)

	Response.Write "<p>"
	Response.Write "<center>"
	Response.Write "<table BORDER=1>"
	Response.Write "<tr>"
	Response.Write "<th>Name</th>"
	Response.Write "<th>Server</th>"
	Response.Write "<th>Connection type</th>"
	Response.Write "</tr>"

	For Each objInstance in objEnumerator
		If Err.Number Then
			Err.Clear
		Else
			If objInstance is nothing Then
				Exit Sub
			Else
				Response.Write "<tr>"
					Response.Write "<td>" & objInstance.Name & "</td>"
					Response.Write "<td>" & objInstance.Server & "</td>"
					Set objPath = objInstance.Path_
					strClassName = objPath.Class
					if (strClassName = "MsSna_Adapter8022Dlc") then
						Response.Write"<td> 802.2 (DLC) Connection </td>"
					ElseIf (strClassName = "MsSna_AdapterChannel") then
						Response.Write"<td> Channel Connection </td>"
					ElseIf (strClassName = "MsSna_AdapterDFT") then
						Response.Write"<td> DFT Connection </td>"
					ElseIf (strClassName = "MsSna_AdapterSdlc") then
						Response.Write"<td> SDLC Connection </td>"
					ElseIf (strClassName = "MsSna_AdapterTwinax") then
						Response.Write"<td> Twinax Connection </td>"
					ElseIf (strClassName = "MsSna_AdapterX25") then
						Response.Write"<td> Twinax Connection </td>"
					Else
						Response.Write"<td> Unknown Class type returned </td>"
					End if
				Response.Write "</tr>"
			End If
		End If
	Next
	Response.Write "</table>"
	Response.Write "</center>"
End Sub
%>

</body>
</html>
