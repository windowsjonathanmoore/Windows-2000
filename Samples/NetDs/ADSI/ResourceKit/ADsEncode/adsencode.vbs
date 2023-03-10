
Set con = CreateObject("ADODB.Connection")
Set com = CreateObject("ADODB.Command")

Set adsEncode = CreateObject("ADsEncode")
Set x = GetObject("LDAP://CN=John Smith,DC=ArcadiaBay,DC=com")
sid = x.Get("objectSID")

strEncoded = adsEncode.EncodeBinary(sid)


'Open a Connection object
con.Provider = "ADsDSOObject"
con.Open "Active Directory Provider"

' Create a command object on this connection
Set Com.ActiveConnection = con
'Com.CommandText = "select name from 'LDAP://andyhar06' where objectSID='" & strEncoded & "'"
Com.CommandText = "<LDAP://srvdc06>;(objectSID=" & strEncoded & ");Name;subtree"


Set rs = Com.Execute

'--------------------------------------
' Navigate the record set
'----------------------------------------
While Not rs.EOF
     wscript.echo rs.Fields("Name")
     rs.MoveNext
Wend


'-- Just to prove they are identical when we decode and encode again----
sid2 = adsEncode.DecodeBinary(strEncoded)
StrEncoded2 = adsEncode.EncodeBinary(sid2)

If (strEncode = strEncode2) Then
  wscript.echo "Identical"
End If

