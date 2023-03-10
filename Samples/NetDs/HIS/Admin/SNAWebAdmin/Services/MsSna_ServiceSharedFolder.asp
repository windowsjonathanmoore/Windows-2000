<%@ LANGUAGE="VBSCRIPT"%>
<html>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays information in a table
   about the SNA AS400 Service.
   
   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<head>
<meta http-equiv="refresh" content="10">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<title>SNA AS400 Service ASP Query Page!</title>
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

		'Retrieve the SNA_Service_Share class
		Set ServerClass = WmiNamespace.Get("MsSna_ServiceSharedFolder")
		Set Path = ServerClass.Path_
		ServerClass.Security_.impersonationLevel = 3
		Set AS400Services = ServerClass.Instances_
%>

<p align="center">Path of object is <%=Path.DisplayName%></p>

<center>

<table BORDER="1">
  <tr>
    <th>Name</th>
    <th>StatusText</th>
    <th>Comment</th>
  </tr>
<%
	for each item in AS400Services
%>
  <tr>
    <td> <%=item.Name%></td>
    <td>
    <%
    	Name = item.Name
    	Status = item.StatusText
    	if (Status = "Active") then
    		%>
              <applet code="fphover.class" codebase="../../" width="120" height="24">
                <param name="text" value=<%=Status%>>
                <param name="textcolor" value="#008000">
                <param name="hovercolor" value="#FF0000">
                <param name="effect" value="glow">
                <param name="url" valuetype="ref" value="StartStopService.asp?Service=MsSna_ServiceSharedFolder&Name=<%=Name%>&Method=Stop">
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
                <param name="url" valuetype="ref" value="StartStopService.asp?Service=MsSna_ServiceSharedFolder&Name=<%=Name%>&Method=Start">
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






































