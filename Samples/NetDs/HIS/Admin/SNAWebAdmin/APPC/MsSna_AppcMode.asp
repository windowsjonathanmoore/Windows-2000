<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays APPC Mode information in a table
   for each mode in the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>SNA_APPC_Mode ASP Query Page!</title>
</head>

<body>
<p align="center">
<IMG id=IMG1 src="../images/SNA.GIF" width="300" height="110" >
<%
	' Connect to the default namespace (root\MicrosoftHIS)
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS","", "","", "",0,Nothing)
	
	if Err = 0 then

		'Retrieve the SNA_Server class
		Set ServerClass = WmiNamespace.Get("MsSna_AppcMode")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Modes = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<center>

<table BORDER="1">
  <tr>
    <th>Name</th>
    <th>AllowLZandRLE</th>
    <th>AutoActivate</th>
    <th>Comment</th>
    <th>EndpointOnly</th>
    <th>MaxRcvCompression</th>
    <th>MaxSendCompression</th>
    <th>MinContWin</th>
    <th>PartMinContWin</th>
    <th>Priority</th>
    <th>RxPacing</th>
    <th>RxRu</th>
    <th>SessionLimit</th>
    <th>TxPacing</th>
    <th>TxRu</th>
  </tr>
  
<%
	for each item in Modes
%>
  <tr>
    <td> <%=item.Name%> </td>
    <td> <%=item.AllowLZandRLE%> </td>
    <td> <%=item.AutoActivate%> </td>
    <td> <%=item.Comment%> </td>
    <td> <%=item.EndpointOnly%> </td>
    <td> <%=item.MaxRcvCompression%> </td>
    <td> <%=item.MaxSendCompression%> </td>
    <td> <%=item.MinContWin%> </td>
    <td> <%=item.PartMinContWin%> </td>
    <td> <%=item.Priority%> </td>
    <td> <%=item.RxPacing%> </td>
    <td> <%=item.RxRu%> </td>
    <td> <%=item.SessionLimit%> </td>
    <td> <%=item.TxPacing%> </td>
    <td> <%=item.TxRu%> </td>
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
