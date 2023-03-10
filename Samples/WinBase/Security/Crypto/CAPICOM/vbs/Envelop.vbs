'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.
'
' Copyright (C) 2001.  Microsoft Corporation.  All rights reserved.
'******************************************************************************
'
' Envelop.vbs
'
' This VBScript envelops the content of a text file, and then saves the
' enveloped message to a specified file.
'
' This script runs from the command prompt and takes two arguments,
' 
' 1) filename of a text file whose content is to be enveloped
' 2) filename to save the enveloped message
'
' To envelop to a recipient, a time valid recipient's certificate is required
' in the current user AddressBook (Other People) store.
'
Option Explicit

Const ForReading = 1, ForWriting = 2

' Check syntax.
If Wscript.Arguments.Count <> 2 Then
    MsgBox "Usage: Envelop.vbs ContentFileName EnvelopedFileName"
    Wscript.Quit(1)
End If

' Envelop content.
EnvelopFile Wscript.Arguments(0), Wscript.Arguments(1)

MsgBox "The content of " & Wscript.Arguments(0) & " has been successfully " & _
       "enveloped, and the enveloped message was saved to " & _
       Wscript.Arguments(1) & "." & vbCrLf & vbCrLf & _
       "Please run Denvelop.vbs to decrypt the enveloped message."

Wscript.Quit(0)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' EnvelopFile
'
' Envelop content of InFile and save enveloped message to OutFile.
'
Sub EnvelopFile (InFile, OutFile)
    Dim EnvelopedData
    Dim Content
    Dim Message

    Set EnvelopedData = CreateObject("CAPICOM.EnvelopedData")
    LoadFile InFile, Content
    EnvelopedData.Content = Content
    Message = EnvelopedData.Encrypt
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
