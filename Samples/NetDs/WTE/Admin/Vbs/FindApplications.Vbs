''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' (C) 1999 Microsoft Corporation.  All rights reserved.                        '
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' This script will show what applicatin is using a given phone number
'
' Syntax:
' FindApplication.vbs phonenumber [phonenumber [...] ]
'

' Declarations
Dim admin
Dim applications
Dim Addresses
Dim output

Sub FindApplication(num)
    currentoutput = ""
    For each Address in Addresses
        If Address.DialableAddress = num Then
            If Address.AssignedApplication <> "" Then
                currentoutput = currentoutput & "Address: " & num & ", " & _
                    "Application name: " & Address.AssignedApplication & vbCrLf
            End If
        End If
    Next
    
    If currentoutput = "" Then
        REM output = "" 
        output = output & "Address: " & num & ", no application detected" & vbCrLf
    Else
        output = output & currentoutput
    End If
End Sub

Sub FindApplications()
    Set WTE = CreateObject("WTE.Root")
    Set Admin = WTE.Arrays.GetContainingArray
    Set Addresses = WTE.Arrays.GetContainingArray.Servers(1).Addresses
    Set applications = admin.applications
 
    Set args = Wscript.Arguments

    If args.Count = 0 Then
        MsgBox "Usage:" & vbCrLf & "FindApplications.vbs phonenumber [phonenumber [...] ]"
        Exit Sub
    End If

    For i = 0 To args.Count - 1
        FindApplication args(i)
    Next

    If output = "" Then
        MsgBox "No applications found for the specified Addresses"
    Else
        MsgBox output
    End If
End Sub

FindApplications

