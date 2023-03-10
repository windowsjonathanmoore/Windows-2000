''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' (C) 1999 Microsoft Corporation.  All rights reserved.                        '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' This script lists basic data about all installed WTE applications
'

Sub ListApps()
    Set WTE = CreateObject("WTE.Root")
    Set Admin = WTE.Arrays.GetContainingArray
    Set Addresses = WTE.Arrays.GetContainingArray.Servers(1).Addresses
    Set applications = admin.applications
    output = ""

    For Each application In applications
        phones = ""
        output = output & "Application name: " & application.Name & vbCrLf & _
                 "Application description: " & application.Description & vbCrLf & _
                 "Home page: " & application.HomePage & vbCrLf & _
                 "Associated phone numbers: "
        For Each Address in Addresses
            If Address.AssignedApplication = application.Name Then
                phones  = phones & Address.DialableAddress & " "
            End If
        Next
        If phones = "" Then
            output = output & "none"
        Else
            output = output & phones
        End If
        output = output & vbCrLf & vbCrLf
    Next
    MsgBox output
End Sub

ListApps