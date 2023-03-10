<%@ LANGUAGE="VBSCRIPT"%>
<HEAD>
<TITLE>Host Integration Server Services Status Page!</TITLE>
<!-------------------------------------------------------------------------
 
	This sample illustrates the use of the WMI Scripting API within
   an ASP, using VBScript.  It displays the status information for each SNA
   Service in the local domain.

   To run this sample, 

   1. Place it in a directory accessible to your web server
   2. Ensure that the registry value:-

        HKEY_LOCAL_MACHINE\Software\Microsoft\WBEM\Scripting\Enable for ASP

      is set to 1.
 
---------------------------------------------------------------------------->
<META content=10 http-equiv=refresh>
<META content="Microsoft FrontPage 4.0" name=GENERATOR>
</HEAD>
<BODY>
<CENTER>
<IMG SRC="../../SNAWebAdmin/images/SNA.GIF" WIDTH=300px HEIGHT=110px BORDER=none>
<P align=center>This Page refreshes every 10 seconds.
<%
	' Connect to the default namespace (root\MicrosoftHIS)
	' on the local host
	Set WmiLocator = CreateObject("WbemScripting.SWbemLocator")
	Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS")
	
	if Err = 0 then

		'First, let's get the Host Integration Server Services (snaservr, snasrv02, etc)
		Set ServerClass = WmiNamespace.Get("MsSna_ServiceSna")
		ServerClass.Security_.impersonationLevel = 3
		Set ServerService = ServerClass.Instances_
		counter = 0
%>
<CENTER>
<P><STRONG>Services</STRONG></P>
<TABLE border=1>
	<TBODY>
		<TR>
			<TH>Service</TH>
			<TH>Name</TH>
			<TH>Status</TH>
		</TR>
		<%
			for each item in ServerService
				'Increment the counter
				counter = counter + 1
				'Alternate background color for enhancing the appearance
				md = counter mod 2
				if ( md = 0 ) then
					bkColor = "#C9C9C9"
				else
					bkColor = "#E8E8E8"
				end if 
		%>
		<TR>
			<TD bgcolor="<%=bkColor%>">Host Integration Server Service</TD>
			<TD bgcolor="<%=bkColor%>"><%=item.Name%></TD>
			<TD bgcolor="<%=bkColor%>">
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
						<param name="target" value="_self">
						<PARAM NAME="url" VALUE="StartStop.asp?Connection=0&amp;Service=MsSna_ServiceSna&amp;Name=<%=Name%>&amp;Method=Stop">
					</APPLET>
			<%
				elseif (Status = "Inactive") then
			%>
					<applet code="fphover.class" codebase="../../" width="120" height="24">
						<param name="text" value=<%=Status%>>
						<param name="textcolor" value="#FF0000">
						<param name="hovercolor" value="#008000">
						<param name="effect" value="glow">
						<param name="target" value="_self">
						<PARAM NAME="url" VALUE="StartStop.asp?Connection=0&amp;Service=MsSna_ServiceSna&amp;Name=<%=Name%>&amp;Method=Start">
					</APPLET>
			<%
				else
			%>
				<CENTER><STRONG><%=Status%></STRONG></CENTER>
			<%
				end if
			%>
			</TD>
		</TR>
		<%
			Next
			'Now, let's get the SNA Print Service Status
			Set ServerClass = WmiNamespace.Get("MsSna_ServicePrint")
			ServerClass.Security_.impersonationLevel = 3
			Set PrintService = ServerClass.Instances_
		%>
		<%
			for each item in PrintService
				counter = counter + 1
				'Alternate background color for enhancing the appearance
				md = counter mod 2
				if ( md = 0 ) then
					bkColor = "#C9C9C9"
				else
					bkColor = "#E8E8E8"
				end if 
		%>
		<TR>
			<TD bgcolor="<%=bkColor%>">SNA Print Service</TD>
			<TD bgcolor="<%=bkColor%>"><%=item.Name%></TD>
			<TD bgcolor="<%=bkColor%>">
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
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=0&amp;Service=MsSna_ServicePrint&amp;Name=<%=Name%>&amp;Method=Stop">
				</APPLET>
			<%
				elseif (Status = "Inactive") then
			%>
				<applet code="fphover.class" codebase="../../" width="120" height="24">
					<param name="text" value=<%=Status%>>
					<param name="textcolor" value="#FF0000">
					<param name="hovercolor" value="#008000">
					<param name="effect" value="glow">
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=0&amp;Service=MsSna_ServicePrint&amp;Name=<%=Name%>&amp;Method=Start">
				</APPLET>
			<%
				else
			%>
				<CENTER><STRONG><%=Status%></STRONG></CENTER>
			<%
				end if
			%>
			</TD>
		</TR>
		<%
			Next
			'Now, let's get the TN3270 Server Status
			Set ServerClass = WmiNamespace.Get("MsSna_ServiceTN3270")
			ServerClass.Security_.impersonationLevel = 3
			Set TN3270Service = ServerClass.Instances_
		%>
		<%
			for each item in TN3270Service
				counter = counter + 1
				'Alternate background color for enhancing the appearance
				md = counter mod 2
				if ( md = 0 ) then
					bkColor = "#C9C9C9"
				else
					bkColor = "#E8E8E8"
				end if 
		%>
		<TR>
			<TD bgcolor="<%=bkColor%>">SNA TN3270 Service</TD>
			<TD bgcolor="<%=bkColor%>"><%=item.Name%></TD>
			<TD bgcolor="<%=bkColor%>">
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
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=0&amp;Service=MsSna_ServiceTN3270&amp;Name=<%=Name%>&amp;Method=Stop">
				</APPLET>
			<%
				elseif (Status = "Inactive") then
			%>
				<applet code="fphover.class" codebase="../../" width="120" height="24">
					<param name="text" value=<%=Status%>>
					<param name="textcolor" value="#FF0000">
					<param name="hovercolor" value="#008000">
					<param name="effect" value="glow">
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=0&amp;Service=MsSna_ServiceTN3270&amp;Name=<%=Name%>&amp;Method=Start">
				</APPLET>
			<%
				else
			%>
				<CENTER><STRONG><%=Status%></STRONG></CENTER>
			<%
				end if
			%>
			</TD>
		</TR>
		<%
			Next
			'Now, let's get the TN5250 Server Status
			Set ServerClass = WmiNamespace.Get("MsSna_ServiceTN5250")
			ServerClass.Security_.impersonationLevel = 3
			Set TN5250Service = ServerClass.Instances_
		%>
		<%
			for each item in TN5250Service
				counter = counter + 1
				'Alternate background color for enhancing the appearance
				md = counter mod 2
				if ( md = 0 ) then
					bkColor = "#C9C9C9"
				else
					bkColor = "#E8E8E8"
				end if 
		%>
		<TR>
			<TD bgcolor="<%=bkColor%>">SNA TN5250 Service</TD>
			<TD bgcolor="<%=bkColor%>"><%=item.Name%></TD>
			<TD bgcolor="<%=bkColor%>">
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
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=0&amp;Service=MsSna_ServiceTN5250&amp;Name=<%=Name%>&amp;Method=Stop">
				</APPLET>
			<%
				elseif (Status = "Inactive") then
			%>
				<applet code="fphover.class" codebase="../../" width="120" height="24">
					<param name="text" value=<%=Status%>>
					<param name="textcolor" value="#FF0000">
					<param name="hovercolor" value="#008000">
					<param name="effect" value="glow">
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=0&amp;Service=MsSna_ServiceTN5250&amp;Name=<%=Name%>&amp;Method=Start">
				</APPLET>
			<%
				else
			%>
				<CENTER><STRONG><%=Status%></STRONG></CENTER>
			<%
				end if
			%>
			</TD>
		</TR>
		<%
			Next
			'Now, let's get the AS400 SFGW Status
			Set ServerClass = WmiNamespace.Get("MsSna_ServiceSharedFolder")
			ServerClass.Security_.impersonationLevel = 3
			Set AS400Share = ServerClass.Instances_
		%>
		<%
			for each item in AS400Share
				counter = counter + 1
				'Alternate background color for enhancing the appearance
				md = counter mod 2
				if ( md = 0 ) then
					bkColor = "#C9C9C9"
				else
					bkColor = "#E8E8E8"
				end if 
		%>
		<TR>
			<TD bgcolor="<%=bkColor%>">SNA Shared Folder Gateway</TD>
			<TD bgcolor="<%=bkColor%>"><%=item.Name%></TD>
			<TD bgcolor="<%=bkColor%>">
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
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=0&amp;Service=MsSna_ServiceSharedFolder&amp;Name=<%=Name%>&amp;Method=Stop">
				</APPLET>
			<%
				elseif (Status = "Inactive") then
			%>
				<applet code="fphover.class" codebase="../../" width="120" height="24">
					<param name="text" value=<%=Status%>>
					<param name="textcolor" value="#FF0000">
					<param name="hovercolor" value="#008000">
					<param name="effect" value="glow">
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=0&amp;Service=MsSna_ServiceSharedFolder&amp;Name=<%=Name%>&amp;Method=Start">
				</APPLET>
			<%
				else
			%>
				<CENTER><STRONG><%=Status%></STRONG></CENTER>
			<%
				end if
			%>
			</TD>
		</TR>
		<%
			Next
		%>
	</TBODY>
</TABLE>
<%
	'Now, let's get the 802.2 Connection Status
	Set ServerClass = WmiNamespace.Get("MsSnaStatus_Connection")
	ServerClass.Security_.impersonationLevel = 3
	Set Connections = ServerClass.Instances_
%>
<P><STRONG>Connections</STRONG></P>
<DIV align=center>
<CENTER>
<TABLE border=1>
	<TBODY>
		<TR>
			<TH>Service</TH>
			<TH>Name</TH>
			<TH>Status</TH>
		</TR>
		<%
			for each item in Connections
				counter = counter + 1
				'Alternate background color for enhancing the appearance
				md = counter mod 2
				if ( md = 0 ) then
					bkColor = "#C9C9C9"
				else
					bkColor = "#E8E8E8"
				end if 
		%>
		<TR>
			<TD bgcolor="<%=bkColor%>"><%=item.ServiceName%></TD>
			<TD bgcolor="<%=bkColor%>"><%=item.Name%></TD>
			<TD bgcolor="<%=bkColor%>">
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
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=MsSnaStatus_Connection&amp;Service=0&amp;Name=<%=Name%>&amp;Method=Stop">
				</APPLET>
			<%
				elseif (Status = "Inactive") then
			%>
				<applet code="fphover.class" codebase="../../" width="120" height="24">
					<param name="text" value=<%=Status%>>
					<param name="textcolor" value="#FF0000">
					<param name="hovercolor" value="#008000">
					<param name="effect" value="glow">
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=MsSnaStatus_Connection&amp;Service=0&amp;Name=<%=Name%>&amp;Method=Start">
				</APPLET>
			<%
				elseif (Status = "OnDemand") then
			%>
					<applet code="fphover.class" codebase="../../" width="120" height="24">
					<param name="text" value=<%=Status%>>
					<param name="textcolor" value="#FF0000">
					<param name="hovercolor" value="#008000">
					<param name="effect" value="glow">
					<param name="target" value="_self">
					<PARAM NAME="url" VALUE="StartStop.asp?Connection=MsSnaStatus_Connection&amp;Service=0&amp;Name=<%=Name%>&amp;Method=Start">
				</APPLET>
			<%else%>
				<CENTER><STRONG><%=Status%></STRONG></CENTER>
			<%
				end if
			%>
			</TD>
		</TR>
		<%
			Next
		%>
	</TBODY>
</TABLE>
</CENTER>
<%
	End If
%>
</DIV>
</CENTER>
</BODY>
</HTML>


















