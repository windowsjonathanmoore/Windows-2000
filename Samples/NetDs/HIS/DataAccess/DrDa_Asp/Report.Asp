<%@ LANGUAGE="VBSCRIPT" %>
<HTML>
<HEAD>
<META NAME="GENERATOR" Content="Microsoft Visual InterDev 1.0">
<META HTTP-EQUIV="Content-Type" content="text/html; charset=iso-8859-1">
<TITLE>Microsoft OLE DB Provider for DB2 - Active Server Pages Sample</TITLE>
</HEAD>
<BODY BGCOLOR=#FFFFFF> 
<H2>Simple Example Retrieving All Results into an Array</H2>

<%
'This sample is based on host tables similar to those in the Microsoft SQL Server Pubs sample database
	'On Error Resume Next
	Set Conn = Nothing
	Set Conn = Server.CreateObject("ADODB.Connection")
	Conn.Open "Provider=DB2OLEDB;NetLib=SNA;NetAddr=;NetPort=;RemoteLU=DRDADEMO;LocalLU=LOCAL;ModeName=QPCSUPP;UID=SNA;PWD=SNA;InitCat=OLYMPIA;DefSch=PUBS;PkgCol=PUBS;TPName=0X07F9F9F9;AccMode=ReadWrite;CCSID=37;PCCodePage=1252;BinAsChar=NO;DSN=Sample;"
	Set RS = Nothing
	Set RS = Server.CreateObject("ADODB.Recordset")
	RS.Open "SELECT * FROM PUBS.AUTHORS", Conn, 0, 1, 1
	' Session.ScriptTimeOut = nMinutes
%>

Here are the results from the query:
<P>
<P>
<TABLE BORDER=1>
<TR>
<% For i = 0 to RS.Fields.Count - 1 %>
	<TD><B><% = RS(i).Name %></B></TD>
<% Next %>
</TR>
<%
' Put up to 10 rows in a 2d variant array
v=RS.GetRows(10) 
%>
<P>
<% For row = 0 to UBound(v,2)  ' iterate through the rows in the variant array %>
	<TR>
	<% For col = 0 to UBound(v,1) %>  
		<TD><% = v(col,row) %> </TD>
	<% Next %>
	</TR>
<% Next %>
</TABLE>
<%
RS.close
set RS = nothing
%>
<BR>
</BODY>
</HTML>

<!--
' Last updated on 03/31/2000.
' Copyright 2000 Microsoft Corporation
-->