<%@ Language=VBScript %>
<%

' Generate the correct HTTP headers to signify that this is an XML stream 
Response.ContentType = "text/xml"
Response.Expires = 0
%>
<?xml version="1.0"?>
<%
dim strConn, strSQL, objRS

' Generate the OLE DB connection string
strConn = "Provider=SQLOLEDB.1;Persist Security Info=False;User ID=sa;"
strConn = strConn + "Initial Catalog=" + Request( "txtDatabase" )
strConn = strConn + ";Data Source=" + Request( "txtComputer" )

' Retrieve the SQL statement
strSQL = Request( "txtSQL" )

' Create the ADO Recordset object
set objRS = Server.CreateObject( "ADODB.Recordset" )
objRS.Open strSQL, strConn 

' Save the ADO recordset to the HTTP response stream

' Note that we have a conditional here to allow this sample to run using both
' IIS 4.0 and IIS 5.0

if Request.ServerVariables( "SERVER_SOFTWARE" ) = "Microsoft-IIS/5.0" then
	objRS.Save Response, adPersistXML 
else
	dim objFS, strFilename, strTempFolder, objTextStream
	set objFS = Server.CreateObject( "Scripting.FileSystemObject" )
	strTempFolder = objFS.GetSpecialFolder( TemporaryFolder ) + "\"
	strFilename = objFS.GetTempName()
	objRS.Save strTempFolder + strFilename, adPersistXML 
	set objTextStream = objFS.OpenTextFile( strTempFolder + strFilename, ForReading ) 
	Response.Write objTextStream.ReadAll()	
	objTextStream.Close()
	
	' NOTE: if you get a Permission Denied message here, you must edit the
	' DACL for your winnt\temp folder to allow IUSR_MACHINENAME and 
	' IWAM_MACHINENAME to be able to delete temporary files created here
	objFS.DeleteFile strTempFolder + strFilename, False
end if

%>