'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.
'
' Copyright (C) 2001.  Microsoft Corporation.  All rights reserved.
'******************************************************************************
'
' CoSign.vbs
'
' This VBScript cosigns a signed message file previously created by Sign.vbs,
' and then save the cosigned message to a specified file.
'
' This script runs from the command prompt and takes two arguments,
' 
' 1) filename of a signed message to be cosigned
' 2) filename to save the cosigned message
'
' To create a signature, a time valid certificate with access to a private key 
' is required in the current user MY store.
'
Option Explicit

Const ForReading = 1, ForWriting = 2

' Check syntax
If Wscript.Arguments.Count <> 2 Then
    MsgBox "Usage: CoSign.vbs SignedFileName CoSignedFileName"
    Wscript.Quit(1)
End If

' CoSign signed message.
CoSignFile Wscript.Arguments(0), Wscript.Arguments(1)

MsgBox "The signed message of " & Wscript.Arguments(0) & " has been " & _
       "successfully cosigned, and the co-signed message was saved to " & _
       Wscript.Arguments(1) & "." & vbCrLf & vbCrLf & _
       "Please run Verify.vbs to verify the co-signed message."

Wscript.Quit(0)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' CoSignFile
'
' CoSign the signed message of InFile and save cosigned message to OutFile.
'
Sub CoSignFile (InFile, OutFile)
    Dim SignedData
    Dim Message

    Set SignedData = CreateObject("CAPICOM.SignedData")
    LoadFile InFile, Message
    SignedData.Verify Message
    Message = SignedData.CoSign(Nothing)
    SaveFile OutFile, Message
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
