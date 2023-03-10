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
<IMG id=IMG1 src="../images/SNA.GIF" width="300" height="110" >
<%
	' Connect to the default namespace
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS","", "","", "",0,Nothing)
	
	if Err = 0 then

		'Retrieve the SNA_LU_Display class
		Set ServerClass = WmiNamespace.Get("MsSNA_LuDisplay")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set LU3270 = ServerClass.Instances_
%>
<center>

<table BORDER="1">
  <tr>
    <th>Name</th>
    <th>AssociatedLU</th>
    <th>Comment</th>
    <th>Compression</th>
    <th>ConnectionName</th>
    <th>Number</th>
    <th>PoolName</th>
    <th>UserWksSecure</th>
  </tr>
  
<%
	for each item in LU3270
%>
  <tr>
    <td> <%=item.Name%> </td>
    <td> <%=item.AssociatedLU%> </td>
    <td> <%=item.Comment%> </td>
    <td> <%=item.Compression%> </td>
    <td> <%=item.ConnectionName%> </td>
    <td> <%=item.Number%> </td>
    <td> <%=item.PoolName%> </td>
    <td> <%=item.UserWksSecure%> </td>
  </tr>
<%
		Next
%>
</table>
</center>
<%
	End If
%>
</body>
</html>
