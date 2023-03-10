'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.
'
' Copyright (C) 2001.  Microsoft Corporation.  All rights reserved.
'******************************************************************************
'
' Encrypt.vbs
'
' This VBScript encrypts the content of a text file, and then saves the
' encrypted message to a specified file.
'
' This script runs from the command prompt and takes three arguments,
' 
' 1) Password to use as the encryption key
' 2) filename of a text file to be encrypted
' 3) filename to save the encrypted message
'
'
Option Explicit

Const ForReading = 1, ForWriting = 2

On Error Resume Next

' Check syntax.
If Wscript.Arguments.Count <> 3 Then
    MsgBox "Usage: Encrypt.vbs Password ContentFileName EncryptedFileName"
    Wscript.Quit(1)
End If

' Encrypt content.
EncryptFile Wscript.Arguments(0), Wscript.Arguments(1), Wscript.Arguments(2)

MsgBox "The content of " & Wscript.Arguments(1) & " has been successfully " & _
       "encrypted, and the encrypted message was saved to " & _
       Wscript.Arguments(2) & "." & vbCrLf & vbCrLf & _
       "Please run Decrypt.vbs to decrypt the encrypted message."

Wscript.Quit(0)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' EncryptFile
'
' Encrypt content of InFile using Password as the encryption key and save 
' encrypted message to OutFile.
'
Sub EncryptFile (Password, InFile, OutFile)
    Dim EncryptedData
    Dim Content
    Dim Message

    Set EncryptedData = CreateObject("CAPICOM.EncryptedData")
    LoadFile InFile, Content
    EncryptedData.Content = Content
    EncryptedData.SetSecret Password

    ' Note: If you are running on Win95, Win98, NT 4.0 SP4, or NT 4.0 SP5, 
    '       together with IE 5.0, and only have the Microsoft Base 
    '       Cryptographic Provider v1.0 installed, the EncryptedData.Encrypt 
    '       method below may fail due to a known issue.  If that's the case, 
    '       uncomment the following two lines and try again.  Please see the 
    '       SDK documentation for more detail on this known problem.
    '
    ' EncryptedData.Algorithm.Name = 0
    ' EncryptedData.Algorithm.KeyLength = 1

    Message = EncryptedData.Encrypt
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
