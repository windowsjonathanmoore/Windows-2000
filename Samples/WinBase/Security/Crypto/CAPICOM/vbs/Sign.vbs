'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.
'
' Copyright (C) 2001.  Microsoft Corporation.  All rights reserved.
'******************************************************************************
'
' Sign.vbs
'
' This VBScript signs the content of a text file, and then save the signed
' message to a specified file.
'
' This script runs from the command prompt and takes two arguments,
' 
' 1) filename of a text file to be signed
' 2) filename to save the signed message
'
' To create a signature, a time valid certificate with access to a private 
' key is required in the current user MY store.
'
Option Explicit

Const ForReading = 1, ForWriting = 2

' Check syntax.
If Wscript.Arguments.Count <> 2 Then
    MsgBox "Usage: Sign.vbs ContentFileName SignedFileName"
    Wscript.Quit(1)
End If

' Sign content.
SignFile Wscript.Arguments(0), Wscript.Arguments(1)

MsgBox "The content of " & Wscript.Arguments(0) & " has been successfully " & _
       "signed, and the signed message was saved to " & _
       Wscript.Arguments(1) & "." & vbCrLf & vbCrLf & _
       "Please run Verify.vbs to verify the signed message."

Wscript.Quit(0)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' SignFile
'
' Sign content of InFile and save signed message to OutFile.
'
Sub SignFile (InFile, OutFile)
    Dim SignedData
    Dim Content
    Dim Message

    Set SignedData = CreateObject("CAPICOM.SignedData")
    LoadFile InFile, Content
    SignedData.Content = Content
    Message = SignedData.Sign(Nothing)
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


