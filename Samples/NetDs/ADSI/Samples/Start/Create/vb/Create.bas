Attribute VB_Name = "Module1"
Sub Main()
Set cont = GetObject("WinNT://myLocalMachineName")

'---- Creating a local user account.
Set usr = cont.Create("user", "JohnD")
usr.FullName = "John Doe"
usr.SetPassword ("myPaswrd3")

usr.SetInfo

End Sub
