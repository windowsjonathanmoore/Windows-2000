<%@ LANGUAGE="VBSCRIPT"%>
<html>

<%
Connection = Request.QueryString("Connection")
Service = Request.QueryString("Service")
Name = Request.QueryString("Name")
if (Connection = "0") then
  sName = Service & ".Name='" & Name & "'"
else
  sName = Connection & ".Name='" & Name & "'"
end if  
Method = Request.QueryString("Method")
stitle = Method & " " & Service & " " & Name
' \\CHARLIEE\root\MicrosoftHIS:SNA_Service_SNA.Name="CHARLIEE"
%>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<META http-equiv="refresh" content="0; URL=All_SNA_Services_Status.asp">
<title><%=stitle%></title>
</head>

<body>
<p><%=stitle%>
<p>Name = <%=sName%>
<p>Method = <%=Method%></p>
<%
Set WmiLocator = CreateObject("WbemScripting.SWBemLocator")
Set WmiNameSpace = WmiLocator.ConnectServer("","root\MicrosoftHIS")
Set ServerClass = WmiNamespace.Get(sName)
ServerClass.Security_.impersonationLevel = 3
ServerClass.ExecMethod_(Method)%>

<%
if Err <> 0 then
%>
<P><%=Err.Description%>
<P><%=Hex(Err.Number)%>
<P><%=Err.Source%>
<%
end if
%>
<% return = "All_SNA_Services_Status.asp" %>
<p> <a href=<%=return%>> Return</a> </p>
</body>

</html>
