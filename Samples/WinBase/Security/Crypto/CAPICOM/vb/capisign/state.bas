Attribute VB_Name = "state"
'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.

' Copyright (C) 2001.  Microsoft Corporation.  All rights reserved.
' ******************************************************************************
Option Explicit

Public filename As String
Public cert As Certificate
Public outfilename As String
Public attachedMode As Boolean
Public cosignMode As Boolean
Public lasterror As String


Public Function sign_file() As Boolean
On Error GoTo Err_Handler
    Dim retval As Boolean
    
    Dim sd As New SignedData
    Dim thesigner As New Signer
    Dim signedstring As String
    Dim attr1 As New CAPICOM.Attribute
    Dim attr2 As New CAPICOM.Attribute
    Dim fso As New FileSystemObject
    
    retval = True
    
    'Add authenticated attributes storing original document name and signing time
    attr1.Name = CAPICOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME
    attr1.Value = Now
    attr2.Name = CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_NAME
    attr2.Value = fso.GetFileName(filename)  'strip off path
    thesigner.Certificate = cert
    thesigner.AuthenticatedAttributes.Add attr1
    thesigner.AuthenticatedAttributes.Add attr2
    
    'Load the file and sign it
    sd.Content = LoadFile(filename)
    If cosignMode Then
        'We must perform a verify operation first
        sd.Verify LoadFile(filename), False, CAPICOM_VERIFY_SIGNATURE_AND_CERTIFICATE
        signedstring = sd.CoSign(thesigner, CAPICOM_ENCODE_BINARY)
    Else
        signedstring = sd.Sign(thesigner, Not attachedMode, CAPICOM_ENCODE_BINARY)
    End If
    
    'save resulting signed output
    SaveFile outfilename, signedstring
    sign_file = retval
    Exit Function
Err_Handler:
    retval = False
    lasterror = Err.Description
    sign_file = False
    Exit Function
    
End Function
Private Function LoadFile(ByVal filename As String) As String
    Dim s As String
    Open filename For Binary As #1
    ReDim buffer(LOF(1) - 1) As Byte
    Get #1, , buffer
    LoadFile = buffer
    Close #1
End Function
Private Sub SaveFile(ByVal filename As String, strdata As String)
    ReDim Data(Len(strdata)) As Byte
    Data = strdata
    Open filename For Binary As #1
    Put #1, , Data
    Close #1
End Sub

