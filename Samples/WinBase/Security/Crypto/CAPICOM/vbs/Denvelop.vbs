'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.
'
' Copyright (C) 2001.  Microsoft Corporation.  All rights reserved.
'******************************************************************************
'
' Denvelop.vbs
'
' This VBScript decrypts a previously enveloped message, and then saves the 
' decrypted content to a specified file.
'
' This script runs from the command prompt and takes two arguments,
' 
' 1) filename of a enveloped message to be decrypted
' 2) filename to save the decrypted content
'
' To decrypt an enveloped message, a time valid recipient's certificate with
' access to the private key is required in the current user My store.
'
Option Explicit

Const ForReading = 1, ForWriting = 2

' Check syntax.
If Wscript.Arguments.Count <> 2 Then
    MsgBox "Usage: Denvelop.vbs EnvelopedFileName DecryptedFileName"
    Wscript.Quit(1)
End If

' Decrypt the enveloped message.
DenvelopFile Wscript.Arguments(0), Wscript.Arguments(1)

MsgBox "The enveloped message of " & Wscript.Arguments(0) & " has been " & _
       "successfully decrypted, and the decrypted content was saved to " & _
       Wscript.Arguments(1) & "."

Wscript.Quit(0)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' DenvelopFile
'
' Decrypt an enveloped message of InFile and save decrypted content to OutFile.
'
Sub DenvelopFile (InFile, OutFile)
    Dim EnvelopedData
    Dim Message

    Set EnvelopedData = CreateObject("CAPICOM.EnvelopedData")
    LoadFile InFile, Message
    EnvelopedData.Decrypt Message
    SaveFile OutFile, EnvelopedData.Content
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
