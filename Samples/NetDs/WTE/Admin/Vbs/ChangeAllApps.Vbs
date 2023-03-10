''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' (C) 1999 Microsoft Corporation.  All rights reserved.                        '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' This script shows how to change a property of all the applications to a fixed
' predetermined value
'

Sub ChangeAllApps()
    Set WTE = CreateObject("WTE.Root")
    Set admin = WTE.Arrays.GetContainingArray
    Set applications = admin.Applications

    On Error Resume Next
    For Each app in applications
        app.OperatorExtension = "1160"
    Next

    admin.Save
    If err.Number <> 0 Then
        MsgBox err.Description
        Exit Sub
    End If

    MsgBox "All applications' operator extensions were changed"
End Sub

ChangeAllApps
