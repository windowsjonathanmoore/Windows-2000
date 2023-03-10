<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays information in a table
   for each Server in the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>SNA_LU_APPC_Remote ASP Query Page!</title>
</head>

<body>
<p align="center">
<IMG id=IMG1 src="../images/SNA.GIF" width="300" height="110" >
<%
	' Connect to the default namespace (root\MicrosoftHIS)
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS",vbNullString, vbNullString,vbNullString, vbNullString,0,Nothing)
	
	if Err = 0 then

		'Retrieve the SNA_LU_APPC_Local class
		Set ServerClass = WmiNamespace.Get("MsSna_LuAppcRemote")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set RemoteLUs = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<center>

<table BORDER="1">
  <tr>
    <th>Alias            </th>
    <th>Comment          </th>
    <th>Connection       </th>
    <th>Incoming Mode    </th>
    <th>LU Name          </th>
    <th>NetName          </th>
    <th>Parallel         </th>
    <th>Security         </th>
    <th>UnName           </th>
  </tr>
<%
	for each item in RemoteLUs
%>
  <tr>
    <td> <%=item.Alias%></td>
    <%
    	strLU = item.Comment
    	if (strLU = "") then
    		strLU = "none"
    	end if
    %>
    <td> <%=strLU%></td>
    <td> <%=item.Connection%></td>
    <%
    	strLU = item.IncomingMode
    	if (strLU = "<None>") then
    		strLU = "none"
    	end if
    %>
    <td> <%=strLU%></td>
    <td> <%=item.LUName%></td>
    <td> <%=item.NetName%></td>
    <td> <%=item.Parallel%></td>
    <td> <%=item.Security%></td>
    <td> <%=item.UnName%></td>
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
















