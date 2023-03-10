<%@LANGUAGE=JavaScript%>
<%

// Generate the correct HTTP headers to signify that this is an XML stream 
Response.ContentType = "text/xml";
Response.Expires = 0;
%>
<?xml version="1.0"?>
<order>
<%

// The code here simply calculates the total and makes up a shipping verification #
var objXML = Server.CreateObject( "Microsoft.XMLDOM" );
var objAdapter = Server.CreateObject( "RequestExLib.RequestEx" );
objAdapter.Adapt( objXML );

// Retrieve a list of all of the prices sent from the client
var collItems = objXML.selectNodes( "//z:row/@price" );
var sum = 0;

for( var i = 0; i < collItems.length; i++ )
	sum += new Number( collItems.item( 0 ).text );
	
Response.Write( "<total>" + sum + "</total>" );
%>
</order>