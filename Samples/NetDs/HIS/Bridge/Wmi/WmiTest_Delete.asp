<%@ Language=VBScript %>
<HTML>
<HEAD></HEAD>
<BODY BGCOLOR=ffffff>


<!-- #INCLUDE FILE="WmiTest_Support.asp" -->

<!-- retrieve class name from previous form -->
<%
sWmiClass = Request("sWmiClass")
Response.Write "<B><FONT SIZE=6 COLOR=0000FF>" + sWmiClass + "</FONT></B><BR><BR>"
'get object path
sObjectPath = Request("sObjectPath") 
sObjectPath = sExchangeSubstring(sObjectPath, QUOTE_SUBSTITUTE, chr(34))
Response.Write "<B>Instance:</B>  " + sObjectPath + "<BR><BR>"

<!-- set properties according to values passed from previous form -->
set WBEML = CreateObject("WbemScripting.SWbemLocator")
set WBEMS = WBEML.ConnectServer(".","root\MicrosoftHIS")
'get instance
if sObjectPath = OBJECT_PATH_NEW then
	'new instance
	Response.Write "<B>Cannot Delete:  </B>No Instance Selected<BR><BR>"
else
	'existing instance
	'delete the instance
	on error resume next
		set WBEMO1 = WBEMS.Get(sObjectPath)
		WBEMO1.Delete_
		if err.number <> 0 then
			'write error text to form
			Response.write "<B>Error:</B>  " + err.description + "<BR>"
			'get extended error
	        Set WBEMERR = CreateObject("WbemScripting.SWbemLastError")
	        If Not IsNull(WBEMERR.Properties_(EXT_ERROR_CODE)) And Not IsNull(WBEMERR.Properties_(EXT_ERROR_TEXT).Value) Then
	            sExtendedErr = "(" + LTrim(CStr(WBEMERR.Properties_(EXT_ERROR_CODE))) + ")  " + WBEMERR.Properties_(EXT_ERROR_TEXT).Value
	            Response.Write "<B>Extended:</B>  " + sExtendedErr
	        Else
	            Response.Write "<B>Extended:</B>  " + "Not Available"
	        End If
			Response.Write "<BR><BR>"
		else
			'no error
			Response.Write "<B>Deleted Successfully</B>" + "<BR><BR>"
		end if
		err.number = 0
	on error goto 0
end if
%>

<BR><FORM ACTION=<%=PAGE_INSTANCES%> METHOD=POST id=form2 name=form2>
<INPUT TYPE=HIDDEN NAME=sWmiClass VALUE="<%=sWmiClass%>">
<INPUT TYPE=SUBMIT NAME=btnReturn VALUE="Return">
</FORM>

<BR><BR>
<A HREF="WmiTest_Main.htm">Return To Main</A>

</BODY>
</HTML>




