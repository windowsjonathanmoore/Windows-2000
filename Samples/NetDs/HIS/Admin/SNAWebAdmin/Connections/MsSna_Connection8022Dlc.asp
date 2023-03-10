<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays 802.2 Connection information in a table
   for the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<title>SNA 802.2 Connection ASP Query Page!</title>
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
		Set ServerClass = WmiNamespace.Get("MsSna_Connection8022Dlc")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set Connections = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<div align="center">
  <center>

<table BORDER="1">
  <tr>
    <th>Service</th>
    <th>Name</th>
    <th>Status</th>
    <th>Comment</th>
    <th>Adapter</th>
    <th>Address</th>
    <th>DlcLocalSap</th>
    <th>DlcRecvThresh</th>
    <th>DlcRemoteSAP</th>
    <th>DlcRetryLimit</th>
    <th>DlcSendLimit</th>
    <th>DlcTimerT1</th>
    <th>DlcTimerT2</th>
    <th>DlcTimerTi</th>
    <th>DlcType</th>
    <th>DlcXidRetry</th>
  </tr>
<%
	for each item in Connections
%>
  <tr>
    <td> <%=item.Service%></td>
    <td> <%=item.Name%></td>
    <td>
    <%
    	Name = item.Name
    	Status = item.StatusText
    	Service = item.Service
    	if (Status = "Active") then
    		%>
              <applet code="fphover.class" codebase="../../" width="120" height="24">
                <param name="text" value=<%=Status%>>
                <param name="textcolor" value="#008000">
                <param name="hovercolor" value="#FF0000">
                <param name="effect" value="glow">
                <param name="url" valuetype="ref" value="StartStopConnection.asp?Connection=MsSna_Connection8022Dlc&Name=<%=Name%>&Service=<%=Service%>&Method=Stop">
                <param name="target" value="_self">
              </applet>
    		<%
    	elseif (Status = "Inactive") then
			%>
             	<applet code="fphover.class" codebase="../../" width="120" height="24">
                <param name="text" value=<%=Status%>>
                <param name="textcolor" value="#FF0000">
                <param name="hovercolor" value="#008000">
                <param name="effect" value="glow">
                <param name="url" valuetype="ref" value="StartStopConnection.asp?Connection=MsSna_Connection8022Dlc&Name=<%=Name%>&Service=<%=Service%>&Method=Start">
                <param name="target" value="_self">
             	 </applet>
			<%
    	else
			%>
			<center><strong><%=Status%></strong></center>
			<%
		end if
   %>
    </td>    
    <td> <%=item.Comment%></td>
    <td> <%=item.Adapter%></td>
    <td> <%=item.Address%></td>
    <td> <%=item.DlcLocalSap%></td>
    <td> <%=item.DlcRecvThresh%></td>
    <td> <%=item.DlcRemoteSAP%></td>
    <td> <%=item.DlcRetryLimit%></td>
    <td> <%=item.DlcSendLimit%></td>
    <td> <%=item.DlcTimerT1%></td>
    <td> <%=item.DlcTimerT2%></td>
    <td> <%=item.DlcTimerTi%></td>
    <td> <%=item.DlcType%></td>
    <td> <%=item.DlcXidRetry%></td>
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
