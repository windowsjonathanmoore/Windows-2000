'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.
'
' Copyright (C) 2001.  Microsoft Corporation.  All rights reserved.
'******************************************************************************
'
' Verify.vbs
'
' This VBScript verifies the signature(s) of a previously signed/cosigned 
' message, and then saves the verified content to a specified file.
'
' This script runs from the command prompt and takes two arguments,
' 
' 1) filename of a signed/cosigned message to be verified
' 2) filename to save the verified content
'
' Note: For Win95, Win98, WinME, and NT 4.0, this script may sometime 
'       trigger a known deadlock situation in CRYPT32.DLL, and thus 
'       not exit completely.
'       Please see Q238934 for more information about this problem.
'
Option Explicit

Const ForReading = 1, ForWriting = 2

' Check syntax.
If Wscript.Arguments.Count <> 2 Then
    MsgBox "Usage: Verify.vbs SignedFileName ContentFileName"
    Wscript.Quit(1)
End If

' Verify signed message.
ReDim SignerNames(0)
VerifyFile Wscript.Arguments(0), Wscript.Arguments(1), SignerNames

' Format signer names.
Dim Index
Dim Names
For Index = 0 to UBound(SignerNames)
    If Index > 0 Then
        Names = Names + ", "
    End If   
    If UBound(SignerNames) > 0 And Index = UBound(SignerNames) Then
        Names = Names + "and "
    End If
    Names = Names + SignerNames(Index)
Next
Names = Names + "."

MsgBox "The signed message of " & Wscript.Arguments(0) & " has been " & _
       "successfully verified, and the verified content was saved to " & _
       Wscript.Arguments(1) & "." & vbCrLf & vbCrLf & _
       "The message was signed by " & Names

Wscript.Quit(0)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' VerifyFile
'
' Verify signed message of InFile, save verified content to OutFile, and
' return the list of signer's names to SignerNames.
'
Sub VerifyFile (InFile, OutFile, SignerNames)
    Dim SignedData
    Dim Message

    ' Verify signed message.
    Set SignedData = CreateObject("CAPICOM.SignedData")
    LoadFile InFile, Message
    SignedData.Verify Message
    SaveFile OutFile, SignedData.Content

    ' Retrieve signer's names.
    Dim Signer
    Dim Index : Index = 0
    ReDim SignerNames(SignedData.Signers.Count - 1)
    For Each Signer In SignedData.Signers
        SignerNames(Index) = Signer.Certificate.GetInfo(0)
        Index = Index + 1
    Next  
End Sub

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' LoadFile
'
' Read content of FileName and assign to Buffer as string.
'
Sub LoadFile (FileName, Buffer)   
    Dim fso
    Set fso = CreateObject("Scripting.FileSystemObject")

    If Not fso.FileExists(FileName) Then
        MsgBox "Error: " & FileName & " file not found."
        Exit Sub
    End If
   
    Dim ts
    Set ts = fso.OpenTextFile(FileName, ForReading)  
    Buffer = ts.ReadAll
End Sub

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' SaveFile
'
' Save string Buffer to FileName.
'
Sub SaveFile (FileName, Buffer)
    Dim fso
    Set fso = CreateObject("Scripting.FileSystemObject")
    
    Dim ts
    Set ts = fso.OpenTextFile(FileName, ForWriting, True)
    ts.Write Buffer
End Sub
