VERSION 5.00
Begin VB.Form frmDisplayCerts 
   Caption         =   "Certificates"
   ClientHeight    =   5280
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7815
   LinkTopic       =   "Form1"
   ScaleHeight     =   5280
   ScaleWidth      =   7815
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdDisplay 
      Caption         =   "Display"
      Default         =   -1  'True
      Height          =   375
      Left            =   6120
      TabIndex        =   2
      Top             =   4080
      Width           =   1455
   End
   Begin VB.CommandButton cmdCancel 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   6120
      TabIndex        =   1
      Top             =   4680
      Width           =   1455
   End
   Begin VB.ListBox lstCertificates 
      Height          =   5325
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   5775
   End
End
Attribute VB_Name = "frmDisplayCerts"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'******************************************************************************\
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.

' Copyright (C) 2000.  Microsoft Corporation.  All rights reserved.
' ******************************************************************************/
Option Explicit

'*******************************************************************************
'
'   cmdCancel_Click
'   Terminate the form display.
'   This subroutine is called when the Cancel button is clicked.

Private Sub cmdCancel_Click()
    Unload Me
End Sub

'*******************************************************************************
'
'   cmdDisplay_Click
'   Show information from of the selected certificate.
'   This subroutine is called when the Display button is clicked.

Private Sub cmdDisplay_Click()

    On Error GoTo ErrorHandler
    
    Dim Index As Long
    
    Index = FindIndex(lstCertificates)
    
    If Index > 0 Then
        Dim Certificate As Certificate
        Set Certificate = frmSignDemo.SignedData.Certificates.Item(Index)
        
        Certificate.Display
    
        Set Certificate = Nothing
    End If
        
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Display"
End Sub

'*******************************************************************************
'
'   Form_Load
'   Show information from all the signer certificates in the SignedData.Certificates collection.
'   This subroutine is called when when the frmDisplyCerts form is loaded.

Private Sub Form_Load()

    On Error GoTo ErrorHandler

    Dim Certificate As Certificate
    Dim i As Long
    
    i = 1
    
    For Each Certificate In frmSignDemo.SignedData.Certificates
               
        lstCertificates.AddItem "Cert #" & Str(i)
        lstCertificates.AddItem "    [Version]: " & Str(Certificate.Version)
        lstCertificates.AddItem "    [Serial Number]: " & Certificate.SerialNumber
        lstCertificates.AddItem "    [Subject]: " & Certificate.SubjectName
        lstCertificates.AddItem "    [Issuer]: " & Certificate.IssuerName
        lstCertificates.AddItem "    [Not Before]: " & Certificate.ValidFromDate
        lstCertificates.AddItem "    [Not After]: " & Certificate.ValidToDate
        lstCertificates.AddItem "    [Thumbprint]: " & Certificate.Thumbprint
        lstCertificates.AddItem ""
        i = i + 1
    Next
    
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "View Certificates - Form Load"
    Unload Me

End Sub
