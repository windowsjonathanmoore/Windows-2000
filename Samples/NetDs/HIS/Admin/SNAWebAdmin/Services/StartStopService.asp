<%@ LANGUAGE="VBSCRIPT"%>
<html>

<%
Service = Request.QueryString("Service")
Name = Request.QueryString("Name")
sName = Service & ".Name='" & Name & "'"
Method = Request.QueryString("Method")
%>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<title><%=Method%> <%=Service%> <%=Request.QueryString("Name")%> </title>
</head>

<body>
<p><%=Method%> & " " & <%=Service%> & " " & <%=Name%>
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
<% return = Service & ".asp" %>
<p> <a href=<%=return%>> Return</a> </p>
</body>

</html>
