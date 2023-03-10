Attribute VB_Name = "Auxillary_Functions"
'******************************************************************************\
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.

' Copyright (C) 2000.  Microsoft Corporation.  All rights reserved.
' ******************************************************************************/
Option Explicit


'*****************************************************************************
'
'   FindIndex
'
' This function returns a number indicating the location of
' a highlighted entry in the list box passed in.
'
Function FindIndex(lstListBox As ListBox) As Long
' This function returns the index number of the highlighted
' certificate in a list of certificates.
   
    Dim i As Long
    Dim Index As Long
    
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

