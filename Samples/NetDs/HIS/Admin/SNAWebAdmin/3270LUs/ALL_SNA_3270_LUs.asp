<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays 3270 Display LU information in a table
   for each Display LU in the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>SNA 3270 Display LU ASP Query Page!</title>
</head>

<body>
<p align="center">
<IMG id=IMG1 src="../../SNAWebAdmin/images/SNA.GIF" width="300" height="110" >
<%
	' Connect to the default namespace
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS","", "","", "",0,Nothing)
	
	if Err = 0 then
		'Let's get all 3270 LUs
		strQuery = "Select * FROM MsSNA_Lu3270"
		'Now execute the query.
		Call ExecuteQuery( WmiNameSpace , strQuery)
	End If
%>

<%
Private Sub ExecuteQuery(objService, strQuery)
%>
	<center>
	<p>
	<table BORDER=1>
		<tr>
			<th>Name</th>
			<th>Number</th>
			<th>Comment</th>
			<th>Compression</th>
			<th>ConnectionName</th>
			<th>PoolName</th>
			<th>UserWksSecure</th>
		</tr>
		<%
		Dim objEnumerator, objInstance, strMessage
		Set objEnumerator = objService.ExecQuery(strQuery)
		For Each objInstance in objEnumerator
			If objInstance is nothing Then
				Exit Sub
			Else
				Set objPath = objInstance.Path_
				strClassName = objPath.Class
				%>
				<tr>
					<td><%=objInstance.Name%></td>
					<td><%=objInstance.Number%></td>
					<td><%=objInstance.Comment%></td>
					<td><%=objInstance.Compression%></td>
					<td><%=objInstance.ConnectionName%></td>
					<td><%=objInstance.PoolName%></td>
					<td><%=objInstance.UserWksSecure%></td>
				</tr>
				<%
			End If
		Next
		%>
	</table>
	</center>
	<%
End Sub
%>
</body>
</html>
