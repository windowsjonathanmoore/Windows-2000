Attribute VB_Name = "AuxFunctions"
'******************************************************************************\
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.

' Copyright (C) 2000.  Microsoft Corporation.  All rights reserved.
' ******************************************************************************/
Option Explicit

'Private Sub SaveFile(ByVal filename As String, Data() As Byte)
'  Open filename For Binary As #1
' Put #1, , Data
'Close #1
'End Sub

'Private Function LoadFile(ByVal filename As String) As Byte()
'    Open filename For Binary As #1
'    ReDim buffer(LOF(1) - 1) As Byte
'    Get #1, , buffer
'    LoadFile = buffer
'    Close #1
'End Function

Function FindIndex(lstListBox As ListBox) As Long

    Dim i As Long
    Dim Index As Long
 MsgBox "find index "
    
    Index = 0
    For i = 0 To lstListBox.ListCount - 1
        Dim Title As String
        Title = Left(lstListBox.List(i), 6)
        
        If Title = "Cert #" Then
            Index = Index + 1
        End If
        
        If i >= lstListBox.ListIndex Then
            Exit For
        End If
    Next i

    FindIndex = Index
    
End Function

