<!-- prepare objects and constants -->
<%

Const PAGE_INSTANCES = "WmiTest_Instances.asp"
Const PAGE_SAVE = "WmiTest_Save.asp"
Const PAGE_DELETE = "WmiTest_Delete.asp"
Const PAGE_MAIN = "WmiTest_Main.htm"
Const TEST_IN_PROGRESS = "Running..."
Const PROP_NAME_VAR_PREFIX = "Property"
Const PROP_VALUE_VAR_PREFIX = "Value"
Const EMBEDDED_PROP_PREFIX = "EmbedProp"
Const EMBEDDED_VAL_PREFIX = "EmbedVal"
Const PROPERTY_OBJECT_CIM = "object"
Const PROPERTY_OBJECT_NAME = "{{Embedded Object}}"
Const QUALIFIER_KEY = "key"
Const QUALIFIER_CIMTYPE = "CIMTYPE"
Const OBJECT_PATH_NEW = "NEWOBJECT"
Const QUOTE_SUBSTITUTE = "!_!_!"
Const EXT_ERROR_TEXT = "Description"
Const EXT_ERROR_CODE = "StatusCode"

%>


<%
function sExchangeSubstring(sMain, sFind, sReplace)

'searches sMain for occurrences of sFind and replaces them with sReplace

'exit if variables not good
If Len(sMain) = 0 Or Len(sFind) > Len(sMain) Then
    sExchangeSubstring = sMain
    Exit Function
End If
'find/replace
iStrPos = InStr(sMain, sFind)
Do While iStrPos <> 0
    sNew = sNew + Left(sMain, iStrPos - 1) + sReplace
    sMain = Right(sMain, Len(sMain) - iStrPos - Len(sFind) + 1)
    iStrPos = InStr(sMain, sFind)
Loop
sNew = sNew + sMain
'return value
sExchangeSubstring = sNew

end function
%>




