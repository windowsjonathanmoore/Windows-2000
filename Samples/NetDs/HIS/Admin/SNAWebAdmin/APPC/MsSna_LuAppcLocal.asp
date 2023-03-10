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
<title>SNA_LU_APPC_Local ASP Query Page!</title>
</head>

<body>
<p align="center">
<IMG id=IMG1 src="../images/SNA.GIF" width="300" height="110" >
<%
	' Connect to the default namespace (root/eig)
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS",vbNullString, vbNullString,vbNullString, vbNullString,0,Nothing)
	
	if Err = 0 then

		'Retrieve the SNA_LU_APPC_Local class
		Set ServerClass = WmiNamespace.Get("MsSNA_LuAppcLocal")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set LocalLUs = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<center>

<table BORDER="1">
  <tr>
    <th>Alias            </th>
    <th>Comment          </th>
    <th>Incoming Lu      </th>
    <th>LU Name          </th>
    <th>NetName          </th>
    <th>PoolMember       </th>
    <th>Service          </th>
    <th>Sync Point       </th>
    <th>Sync Point Client</th>
    <th>Tp Timeout       </th>
  </tr>
<%
	for each item in LocalLUs
%>
  <tr>
    <td> <%=item.Alias%></td>
    <td> <%=item.Comment%></td>
    <%
    	strLU = item.IncomingLU
    	if (strLU = "<None>") then
    		strLU = "none"
    	end if
    %>
    <td> <%=strLU%></td>
    <td> <%=item.LUName%></td>
    <td> <%=item.NetName%></td>
    <td> <%=item.PoolMember%></td>
    <td> <%=item.Service%></td>
    <td> <%=item.SyncPoint%></td>
    <%
    	strLU = item.SyncPointClient
	    if (strLU = "") then
	    	strLU = "none"
	    End if
    %>
    <td> <%=strLU%></td>
    <td> <%=item.TpTimeout%></td>
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



















