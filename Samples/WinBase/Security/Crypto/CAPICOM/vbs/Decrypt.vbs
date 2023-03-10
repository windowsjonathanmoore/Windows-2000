'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.
'
' Copyright (C) 2001.  Microsoft Corporation.  All rights reserved.
'******************************************************************************
'
' Decrypt.vbs
'
' This VBScript decrypts a previously encrypted file, and then saves the
' decrypted content to a specified file.
'
' This script runs from the command prompt and takes three arguments,
' 
' 1) Password to use as the decryption key
' 2) filename of an encrypted message to be decrypted
' 3) filename to save the decrypted message
'
'
Option Explicit

Const ForReading = 1, ForWriting = 2

' Check syntax.
If Wscript.Arguments.Count <> 3 Then
    MsgBox "Usage: Decrypt.vbs Password EncryptedFileName DecryptedFileName"
    Wscript.Quit(1)
End If

' Decrypt encrypted message.
DecryptFile Wscript.Arguments(0), Wscript.Arguments(1), Wscript.Arguments(2)

MsgBox "The encrypted message of " & Wscript.Arguments(1) & " has been " & _
       "successfully decrypted, and the decrypted content was saved to " & _
       Wscript.Arguments(2) & "."

Wscript.Quit(0)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' DecryptFile
'
' Decrypt content of InFile using Password as the decryption key and save 
' decrypted message to OutFile.
'
Sub DecryptFile (Password, InFile, OutFile)
    Dim EncryptedData
    Dim Message

    Set EncryptedData = CreateObject("CAPICOM.EncryptedData")
    LoadFile InFile, Message
    EncryptedData.SetSecret Password
    EncryptedData.Decrypt Message
    SaveFile OutFile, EncryptedData.Content
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
