Attribute VB_Name = "Module1"
Sub Main()

'Bind to the parent container.
Set cont = GetObject("LDAP://CN=Users,DC=microsoft,DC=com")

'---- Renaming an object within the same container.
Set usr = cont.MoveHere("LDAP://CN=Jeff Smith,CN=Users,DC=microsoft,DC=com", "CN=J. Smith")


End Sub
