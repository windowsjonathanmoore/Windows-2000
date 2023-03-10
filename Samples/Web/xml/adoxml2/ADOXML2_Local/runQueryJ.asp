<%@ Language=JavaScript %>
<%

// Generate the correct HTTP headers to signify that this is an XML stream 
Response.ContentType = "text/xml";
Response.Expires = 0;
%>
<?xml version="1.0"?>
<%
// Create an instance of the XML Parser object
var objXMLParser = Server.CreateObject( "Microsoft.XMLDOM" );
var objAdapter = Server.CreateObject( "RequestExLib.RequestEx" );

// Retrieve the body of the HTTP Post request
objAdapter.Adapt( objXMLParser );

// Retrieve the parameters passed from the client
var strComputer = objXMLParser.selectSingleNode( "//computer" ).text;
var strDatabase = objXMLParser.selectSingleNode( "//database" ).text;
var strWhere = objXMLParser.selectSingleNode( "//where" ).text;

// Create an ADO recordset object
var objRS = new ActiveXObject( "ADODB.Recordset" );

// Build a hierarchical recordset using the data shape component
var strSQL = "SHAPE { SELECT titles.* FROM TITLES ";

if( strWhere != "" )
	strSQL += "WHERE " + strWhere;

strSQL += "} AS TITLES1 APPEND ";
strSQL += "( { SELECT authors.*, titleauthor.title_id AS title_id FROM titleauthor ";
strSQL += "INNER JOIN authors ON titleauthor.au_id = authors.au_id } AS AUTHORS1 ";
strSQL += "RELATE 'title_id' to 'title_id' ) AS AUTHORS1";

// Generate the MS Data Shape Provider OLE DB connection string
var strConn = "Provider=MSDataShape; data provider=SQLOLEDB.1; ";
strConn += "Persist Security Info=False; Initial Catalog=" + strDatabase;
strConn += "; Data Source=" + strComputer + "; User ID=sa";

// NOTE: usage of .valueOf() is essential to ensure that value is converted to 
// the appropriate type (string) that ADO is expecting. The type that it was 
// going in was an IDispatch objref.
objRS.Open( strSQL.valueOf(), strConn );

// Note that we have a conditional here to allow this sample to run using both
// IIS 4.0 and IIS 5.0
if( Request.ServerVariables( "SERVER_SOFTWARE" ) == "Microsoft-IIS/5.0" ) {
	objRS.Save( Response, adPersistXML );
} else {
	var objFS, strFilename, strTempFolder, objTextStream;
	objFS = Server.CreateObject( "Scripting.FileSystemObject" );
	strTempFolder = objFS.GetSpecialFolder( TemporaryFolder ) + "\\";
	strFilename = objFS.GetTempName();
	objRS.Save( strTempFolder + strFilename, adPersistXML );
	objTextStream = objFS.OpenTextFile( strTempFolder + strFilename, ForReading );
	Response.Write( objTextStream.ReadAll()	);
	objTextStream.Close();
	
	// NOTE: if you get a Permission Denied message here, you must edit the
	// DACL for your winnt\temp folder to allow IUSR_MACHINENAME and 
	// IWAM_MACHINENAME to be able to delete temporary files created here
	objFS.DeleteFile( strTempFolder + strFilename, false );
}
%>