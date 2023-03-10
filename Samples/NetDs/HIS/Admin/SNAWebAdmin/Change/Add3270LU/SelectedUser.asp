<%@ LANGUAGE="VBSCRIPT"%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<title>Selected User</title>
</head>

<body>
<p align="center">
<IMG id=IMG1 src="../../images/SNA.GIF" width="300" height="110" >
<h1 align="center"> Add 3270 LU's to User</h1>
<h2 align="center"> Step 2</h2>
<p align="center">Select LU and click Submit:</p>

<%
' OK, we have user, so now we have to get the Display LU's assigned to this user
UserName = Request.QueryString("User")
DIM LUset() ' array of LUs already configured for the user
DIM numLUset ' number of LU's in Array

numLUset = 0
' Connect to the default namespace (root\MicrosoftHIS)
' on the local host
Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS")
if Err = 0 then
	' lets find any Display LU's already configured for this user
	quote=chr(34)
	strQ1 = "ASSOCIATORS OF {MsSNA_ConfiguredUser.Name="
	strQ2 = quote & UserName & quote
	strQ3 = "} WHERE AssocClass=MsSNA_LUDisplayAssignedToUser  ResultClass=MsSNA_LuDisplay"
	strQuery = strQ1 & strQ2 & strQ3
' This next is a debug statement to verify the query is correct
'	Response.Write strQuery
'	Now execute the query.
%>
	<p> <%=Username%> is configured for the following LUs
	<table>
		<%
		Dim objEnumerator, objInstance, strMessage
		Set objEnumerator = WmiNameSpace.ExecQuery(strQuery)
		if Err = 0 Then
		%>
		<tr>
		<%
		For Each objInstance in objEnumerator 
			If objInstance is nothing Then
				Exit For
			Else
				%>
					<td><%=objInstance.Name%></td>
				<%
				' add the LU to the array for later use
				numLUset = numLUset + 1
				ReDim Preserve LUset(numLUset)
				LUset(numLUset) = objInstance.Name
			End If
		Next
		%> </tr> <%
		End if
		%>
	</table>
	<p>
	<%	
	' Now that we have the configured LUs, let's get all the LUs on this box
	%>
	<form name="SelectLU" target="_self" method="GET" action="AddLUtoUser.asp">
	<p align="center">Select LU to Add <select size="1" name="NewLU">
	<%
	' Already connected, so don't have to do the following
	' Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	' Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS","", "","", "",0,Nothing)
	' Retrieve the SNA_Server class
	Set ServerClass = WmiNamespace.Get("MsSNA_LUDisplay")
	Set Path = ServerClass.Path_
	ServerClass.Security_.impersonationLevel = 3
	Set DisplayLUs = ServerClass.Instances_
	For each item in DisplayLUs
		' set a variable so we can get out of here
		notfound=-1
		' probably a better way, but this works.
		for i=1 to numLUset
			if (LUset(i)=item.Name) then
				notfound=0
				exit for
			end if
		next
		if notfound then
			' let's add the LU to the drop down list %>
			<option><%=item.Name%></option>
			<%
		end if
		next
		%>
		</select>
		<INPUT TYPE="Hidden" NAME="UserName" VALUE=<%=UserName%>>

		<p align="center"><input type="submit" value="Submit" name="B1"><input type="reset" value="Reset" name="B2"></p>
		</form>
		<%
	End If
	%>
</body>

</html>
