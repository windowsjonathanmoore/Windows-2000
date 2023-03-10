<%@ Language=VBScript %>
<HTML>
<HEAD></HEAD>
<BODY BGCOLOR=ffffff>

<!-- #INCLUDE FILE="WmiTest_Support.asp" -->

<!-- retrieve values passed from previous form -->
<%
'get wmi class
sWmiClass = Request("sWmiClass")
Response.Write "<B><FONT SIZE=6 COLOR=0000FF>" + sWmiClass + "</FONT></B>"
'get instance number
sGetInstance = Request("sGetInstance")
if sGetInstance = "" then
	'no instance
	iGetInstance = 0
else
	'instance specified
	iGetInstance = CInt(sGetInstance)
end if

%>

<!-- create form --> 
<FORM ACTION=<%=PAGE_SAVE%> METHOD=POST>

<!-- create text boxes for the properties of this object -->
<%
'get wmi class
set WBEML = CreateObject("WbemScripting.SWbemLocator")
set WBEMS = WBEML.ConnectServer(".","root\MicrosoftHIS")
set WBEMOS1 = WBEMS.InstancesOf(sWmiClass)
set WBEMO1 = WBEMS.Get(sWmiClass)
'get instance information
iInstances = WBEMOS1.Count
if iGetInstance = 0 then
	'no instance specified
	sObjectPath = OBJECT_PATH_NEW
	sTextLine = "(" + "*" + "/" + CStr(iInstances) + ")"
	iNext = 1
	iPrev = iInstances
else
	'select specified instance 
	iFind = 0
	for each WBEMO1 in WBEMOS1
		iFind = iFind + 1
		if iFind = iGetInstance then
			sObjectPath = WBEMO1.Path_.Path
			sObjectPath = sExchangeSubstring(sObjectPath, chr(34), QUOTE_SUBSTITUTE)
			exit for
		end if
	next
	sTextLine = "(" + CStr(iGetInstance) + "/" + CStr(iInstances) + ")"
	iNext = iGetInstance + 1
	iPrev = iGetInstance - 1
	if iNext > iInstances then iNext = iInstances
	if iPrev < 1 then iPrev = 1
end if
if iInstances = 0 then
	iNext = 0
	iPrev = 0
end if
'write instance information to form
sTextLine = sTextLine + "&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp"
sTextLine = sTextLine + "<A HREF=" + PAGE_INSTANCES + "?sWmiClass=" + sWmiClass + "&sGetInstance=" + CStr(iPrev) + ">Prev</A>"
sTextLine = sTextLine + "&nbsp;&nbsp;&nbsp"
sTextLine = sTextLine + "<A HREF=" + PAGE_INSTANCES + "?sWmiClass=" + sWmiClass + "&sGetInstance=" + CStr(iNext) + ">Next</A>"
sTextLine = sTextLine + "&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp"
sTextLine = sTextLine + "<A HREF=" + PAGE_INSTANCES + "?sWmiClass=" + sWmiClass + "&sGetInstance=0>New</A>"
Response.Write sTextLine
Response.Write "<BR><BR>"
if iGetInstance = 0 then
	Response.Write "<FONT COLOR =0000ff>NEW RECORD</FONT>" + "<BR><BR>" 
end if
'get properties of wmi class
for each WPROP1 in WBEMO1.Properties_
  'keep property count
  iPropertiesCount = iPropertiesCount + 1
  sPropertyName = WPROP1.Name
  'determine if  property is an index for this object, and determine cimtype of property
  bKey = false
  for each WQUAL1 in WPROP1.Qualifiers_
	'determine if  property is an index for this object
	if WQUAL1.Name = QUALIFIER_KEY then
	  if WQUAL1.Value = True then
		bKey = True
	  end if
	end if
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
  if bKey = True then
	'key property  (blue)
	sPropertyNameText = "<B><FONT COLOR=" + chr(34) + "0000ff" + chr(34) + ">" + sPropertyName + ":</FONT></B>"
  else
	'non-key property  (black)
	sPropertyNameText = "<FONT COLOR=" + chr(34) + "000000" + chr(34) + ">" + sPropertyName + ":</FONT>"
  end if	
  'determine the property's value if instance is specified
  if iGetInstance = 0 then
	'instance not specified
	if bEmbeddedObject = false then
	  sValue = ""
	else
	  sValue = PROPERTY_OBJECT_NAME
	end if
  else
    if bEmbeddedObject = false then
      'not embedded object - get property value
      sValue = WPROP1.Value
    else
	  'embedded object - don't get property value
	  sValue = PROPERTY_OBJECT_NAME
	end if
  end if
  'add text box to form
  sPropertyNameVar = PROP_NAME_VAR_PREFIX + CStr(iPropertiesCount)
  sPropertyValueVar = PROP_VALUE_VAR_PREFIX + CStr(iPropertiesCount)
  sTextLine = sPropertyNameText + "<INPUT TYPE=HIDDEN NAME=" + chr(34) + sPropertyNameVar + chr(34) 
  sTextLine = sTextLine + " VALUE=" + chr(34) + sPropertyName + chr(34) + ">" + "<INPUT TYPE=TEXT NAME=" + chr(34) + sPropertyValueVar + chr(34) 
  sTextLine = sTextLine + " VALUE=" + chr(34) + CStr(sValue) + chr(34) + ">" + "<BR>"
  Response.Write sTextLine
  'if this property is an embedded object then include inputs for it's properties
  if bEmbeddedObject = true then
	if iGetInstance = 0 then
		'new instance
		Set WBEMOE1 = WBEMS.Get(sEmbeddedObjectName)
	else
		'existing instance
		Set WBEMOE1 = WPROP1.Value
	end if
	iSubProperties = 0
	for each WPROP2 IN WBEMOE1.Properties_
	  'add input for each embedded property
	  iSubProperties = iSubProperties + 1
	  sSubPropertyNameVar = sPropertyName + EMBEDDED_PROP_PREFIX
	  sSubPropertyValueVar = sPropertyName + EMBEDDED_VAL_PREFIX
	  'variable names aren't good with 0-9 in the middle of them so exchange for A-J
	  sSubPropertyNameVar = sExchangeSubstring(sSubPropertyNameVar, "1", "A")
	  sSubPropertyValueVar = sExchangeSubstring(sSubPropertyValueVar, "1", "A")
	  sSubPropertyNameVar = sExchangeSubstring(sSubPropertyNameVar, "2", "B")
	  sSubPropertyValueVar = sExchangeSubstring(sSubPropertyValueVar, "2", "B")
	  sSubPropertyNameVar = sExchangeSubstring(sSubPropertyNameVar, "3", "C")
	  sSubPropertyValueVar = sExchangeSubstring(sSubPropertyValueVar, "3", "C")
	  sSubPropertyNameVar = sExchangeSubstring(sSubPropertyNameVar, "4", "D")
	  sSubPropertyValueVar = sExchangeSubstring(sSubPropertyValueVar, "4", "D")
	  sSubPropertyNameVar = sExchangeSubstring(sSubPropertyNameVar, "5", "E")
	  sSubPropertyValueVar = sExchangeSubstring(sSubPropertyValueVar, "5", "E")
	  sSubPropertyNameVar = sExchangeSubstring(sSubPropertyNameVar, "6", "F")
	  sSubPropertyValueVar = sExchangeSubstring(sSubPropertyValueVar, "6", "F")
	  sSubPropertyNameVar = sExchangeSubstring(sSubPropertyNameVar, "7", "G")
	  sSubPropertyValueVar = sExchangeSubstring(sSubPropertyValueVar, "7", "G")
	  sSubPropertyNameVar = sExchangeSubstring(sSubPropertyNameVar, "8", "H")
	  sSubPropertyValueVar = sExchangeSubstring(sSubPropertyValueVar, "8", "H")
	  sSubPropertyNameVar = sExchangeSubstring(sSubPropertyNameVar, "9", "I")
	  sSubPropertyValueVar = sExchangeSubstring(sSubPropertyValueVar, "9", "I")
	  sSubPropertyNameVar = sExchangeSubstring(sSubPropertyNameVar, "0", "J")
	  sSubPropertyValueVar = sExchangeSubstring(sSubPropertyValueVar, "0", "J")
	  'append number
	  sSubPropertyNameVar = sSubPropertyNameVar + CStr(iSubProperties)
	  sSubPropertyValueVar = sSubPropertyValueVar + CStr(iSubProperties)
	  'add input
	  sSubPropertyName = WPROP2.Name
	  if iGetInstance = 0 then
		'new instance
	    sSubPropertyValue = ""
	  else
		'existing instance
		sSubPropertyValue = WPROP2.Value
	  end if
	  sTextLine = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" + sSubPropertyName + ":"
	  sTextLine = sTextLine + "<INPUT TYPE=HIDDEN NAME=" + chr(34) + sSubPropertyNameVar + chr(34) 
	  sTextLine = sTextLine + " VALUE=" + chr(34) + sSubPropertyName + chr(34) + ">" + "<INPUT TYPE=TEXT NAME=" + chr(34) + sSubPropertyValueVar + chr(34) 
	  sTextLine = sTextLine + " VALUE=" + chr(34) + CStr(sSubPropertyValue) + chr(34) + ">" + "<BR>"
	  Response.Write sTextLine
	  Set WBEMOE1 = Nothing
	next
  end if
next

%>

<INPUT TYPE=HIDDEN NAME=sWmiClass VALUE="<%=sWmiClass%>">
<INPUT TYPE=HIDDEN NAME=sObjectPath VALUE="<%=sObjectPath%>">
<BR><BR><INPUT TYPE=SUBMIT NAME=btnSubmit VALUE="Save">
</FORM>
<FORM ACTION=<%=PAGE_DELETE%> METHOD=POST id=form2 name=form2>
<INPUT TYPE=HIDDEN NAME=sWmiClass VALUE="<%=sWmiClass%>">
<INPUT TYPE=HIDDEN NAME=sObjectPath VALUE="<%=sObjectPath%>">
<BR><INPUT TYPE=SUBMIT NAME=btnDelete VALUE="Delete">
</FORM>

<BR><BR>
<A HREF="WmiTest_Main.htm">Return To Main</A>

</BODY>
</HTML>




