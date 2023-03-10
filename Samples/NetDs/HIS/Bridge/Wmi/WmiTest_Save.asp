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

<!-- set properties according to values passed from previous form -->
set WBEML = CreateObject("WbemScripting.SWbemLocator")
set WBEMS = WBEML.ConnectServer(".","root\MicrosoftHIS")
'get instance
if sObjectPath = OBJECT_PATH_NEW then
	'new instance
	set WBEMO2 = WBEMS.Get(sWmiClass)
	set WBEMO1 = WBEM02.SpawnInstance_()
else
	'existing instance
	set WBEMO1 = WBEMS.Get(sObjectPath)
end if
'write the values to the instance
iProperty = 0
for each WPROP1 in WBEMO1.Properties_
  'get property value
  iProperty = iProperty + 1
  sProperty = PROP_VALUE_VAR_PREFIX + CStr(iProperty)
  sValue = Request(sProperty)
  'determine this property is an embedded object
  for each WQUAL1 in WPROP1.Qualifiers_
	'determine cimtype of property (whether it is an embedded object)
	if WQUAL1.Name = QUALIFIER_CIMTYPE then
	  if Instr(WQUAL1.Value, PROPERTY_OBJECT_CIM) = 1 then
	    'embedded object
		bEmbeddedObject = true
		'format for embedded object in qualifier is "object:{class}"
		sEmbeddedObjectName = Right(WQUAL1.Value, Len(WQUAL1.Value) - Instr(WQUAL1.Value, ":"))
	  else
	    'not embedded object
		bEmbeddedObject = false
	  end if
	end if	
  next
  'enter property value
  if bEmbeddedObject = false then
	'not an embedded object - enter value for property
	WPROP1.Value = sValue
  else
	'embedded object - enter values for embedded properties
	'get values
	Set WBEMOE2 = WBEMS.Get(sEmbeddedObjectName)
	Set WBEMOE1 = WBEMOE2.SpawnInstance_()
	Set WBEMOE2 = Nothing
	iSubProperty = 0
				'response.write WPROP1.Name + "<BR>"
	for each WPROP2 in WBEMOE1.Properties_
	  iSubProperty = iSubProperty + 1
	  sSubValueVar = WPROP1.Name + EMBEDDED_VAL_PREFIX
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "2", "B") + CStr(iSubProperty)
	  sSubValue = Request(sSubValueVar)
				'response.write WPROP1.Name + "." + WPROP2.Name + " = "
				'response.write sSubValue + "<BR>"
	  WPROP2.Value = sSubValue
	next
	WPROP1.Value = WBEMOE1
	Set WBEMOE1 = Nothing
  end if
next
'commit changes to instance
on error resume next
	WBEMO1.Put_
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
		Response.Write "<B>Updated Successfully</B>" + "<BR><BR>"
	end if
	err.number = 0
on error goto 0
'display the values on the form
iProperty = 0
for each WPROP1 in WBEMO1.Properties_
  'get property name and value
  iProperty = iProperty + 1
  sPropertyVar = PROP_NAME_VAR_PREFIX + CStr(iProperty)
  sProperty = Request(sPropertyVar)
  sValueVar = PROP_VALUE_VAR_PREFIX + CStr(iProperty)
  sValue = Request(sValueVar)
  Response.Write sProperty + " = '" + sValue + "'" + "<BR>"
  'determine this property is an embedded object
  for each WQUAL1 in WPROP1.Qualifiers_
	'determine cimtype of property (whether it is an embedded object)
	if WQUAL1.Name = QUALIFIER_CIMTYPE then
	  if Instr(WQUAL1.Value, PROPERTY_OBJECT_CIM) = 1 then
	    'embedded object
		bEmbeddedObject = true
		'format for embedded object in qualifier is "object:{class}"
		sEmbeddedObjectName = Right(WQUAL1.Value, Len(WQUAL1.Value) - Instr(WQUAL1.Value, ":"))
	  else
	    'not embedded object
		bEmbeddedObject = false
	  end if
	end if	
  next
  'if this property is an embedded object then display embedded properties
  if bEmbeddedObject = true then
	'embedded object - enter values for embedded properties
	'get values
	Set WBEMOE1 = WBEMS.Get(sEmbeddedObjectName)
	iSubProperty = 0
	for each WPROP2 in WBEMOE1.Properties_
	  iSubProperty = iSubProperty + 1
	  sSubPropertyVar = sProperty + EMBEDDED_PROP_PREFIX
	  sSubValueVar = sProperty + EMBEDDED_VAL_PREFIX
	  'variable names aren't good with 0-9 in the middle of them so exchange for A-J
	  sSubPropertyVar = sExchangeSubstring(sSubPropertyVar, "1", "A")
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "1", "A")
	  sSubPropertyVar = sExchangeSubstring(sSubPropertyVar, "2", "B")
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "2", "B")
	  sSubPropertyVar = sExchangeSubstring(sSubPropertyVar, "3", "C")
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "3", "C")
	  sSubPropertyVar = sExchangeSubstring(sSubPropertyVar, "4", "D")
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "4", "D")
	  sSubPropertyVar = sExchangeSubstring(sSubPropertyVar, "5", "E")
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "5", "E")
	  sSubPropertyVar = sExchangeSubstring(sSubPropertyVar, "6", "F")
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "6", "F")
	  sSubPropertyVar = sExchangeSubstring(sSubPropertyVar, "7", "G")
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "7", "G")
	  sSubPropertyVar = sExchangeSubstring(sSubPropertyVar, "8", "H")
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "8", "H")
	  sSubPropertyVar = sExchangeSubstring(sSubPropertyVar, "9", "I")
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "9", "I")
	  sSubPropertyVar = sExchangeSubstring(sSubPropertyVar, "0", "J")
	  sSubValueVar = sExchangeSubstring(sSubValueVar, "0", "J")
	  'append number
	  sSubPropertyVar = sSubPropertyVar + CStr(iSubProperty)
	  sSubValueVar = sSubValueVar + CStr(iSubProperty)
	  'show value
	  sSubProperty = Request(sSubPropertyVar)
	  sSubValue = Request(sSubValueVar)
	  sTextLine = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"
	  sTextLine = sTextLine + sSubProperty + " = '" + sSubValue + "'" + "<BR>"
	  Response.Write sTextLine
	next
	Set WBEMOE1 = Nothing
  end if
next
%>

<BR><FORM ACTION=<%=PAGE_INSTANCES%> METHOD=POST id=form2 name=form2>
<INPUT TYPE=HIDDEN NAME=sWmiClass VALUE="<%=sWmiClass%>">
<BR><INPUT TYPE=SUBMIT NAME=btnReturn VALUE="Return">
</FORM>

<BR><BR>
<A HREF="WmiTest_Main.htm">Return To Main</A>

</BODY>
</HTML>




