<%@ LANGUAGE="VBSCRIPT"%>
<html>

<%
Connection = Request.QueryString("Connection")
Name = Request.QueryString("Name")
Service = Request.QueryString("Service")
sName = Connection & ".Name='" & Name & "'"
Method = Request.QueryString("Method")
stitle = Method & " " & Service & " " & Name
%>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
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
ServerClass.ExecMethod_(Method)
%>

<%
if Err <> 0 then
%>
<P><%=Err.Description%>
<P><%=Hex(Err.Number)%>
<P><%=Err.Source%>
<%
end if
%>
<% return = Connection & ".asp" %>
<p> <a href=<%=return%>> Return</a> </p>
</body>

</html>
