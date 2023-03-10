VERSION 5.00
Begin VB.Form frmSelect 
   Caption         =   "Select recipient's certificate"
   ClientHeight    =   6255
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7935
   LinkTopic       =   "Form1"
   ScaleHeight     =   6255
   ScaleWidth      =   7935
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdCancel 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   6240
      TabIndex        =   3
      Top             =   5640
      Width           =   1455
   End
   Begin VB.CommandButton cmdOK 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   6240
      TabIndex        =   2
      Top             =   5040
      Width           =   1455
   End
   Begin VB.ListBox lstCertificates 
      Height          =   4545
      Left            =   240
      TabIndex        =   1
      Top             =   1440
      Width           =   5655
   End
   Begin VB.Label lblCertificate 
      BorderStyle     =   1  'Fixed Single
      Height          =   855
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   5655
   End
End
Attribute VB_Name = "frmSelect"
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

' The select form is used to select recipients for the enveloped message.

Option Explicit
Private RecipientCertificates As Collection

'*******************************************************************************
'
'   cmdCancel_Click
'   Close the form and return to the main form.
'   This subroutine is called when the cancel button is clicked.

Private Sub cmdCancel_Click()
    Unload Me
End Sub

'*******************************************************************************
'
'   cmdCancel_Click
'   Add the highlighted certificate
'   to collection of certificates of the intended recipients of the
'   enveloped message.
'   The intended recipient list is the Recipients collection
'   of the global EnvelopedData object form the frmEnvelop form.
'   This subroutine is called when the OK button is clicked.

Private Sub cmdOK_Click()


    On Error GoTo ErrorHandler
        
    Dim Index As Long
    Index = FindIndex(lstCertificates)
    
    If Index > 0 Then
        frmEnvelop.EnvelopedData.Recipients.Add RecipientCertificates(Index)
        frmEnvelop.cmdRecipients.Enabled = True
    End If
    
    Unload Me
    
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Select Recipient's Certificate"
    Unload Me
End Sub

'*******************************************************************************
'   Form_Load
'   Opens a certificate store, display information from
'   each certificate in the store, and add the certificate to the global
'   collection of possible message recipients.
'   For this demonstration program, because the certificates from the same
'   store will be used to decrypt the message, the store opened is the MY store.
'   In a working program, the envelop portion would work with
'   certificates where only the public key was available, such as the
'   CA or an Active Directory store.
'   The MY store would be opened to access certificates with private keys
'   to decrypt the enveloped message.
'
'   This subroutine is called when this form is shown.

Private Sub Form_Load()
    On Error GoTo ErrorHandler

    Set RecipientCertificates = New Collection
    
    Dim Store As Store
    Set Store = CreateObject("CAPICOM.Store")
    Store.Open CAPICOM_CURRENT_USER_STORE, "MY", CAPICOM_STORE_OPEN_READ_ONLY

    Dim i As Long
    Dim Certificate As Certificate
    
    i = 1
    For Each Certificate In Store.Certificates
                
        If Certificate.IsValid Then
            lstCertificates.AddItem "Cert #" & Str(i)
            lstCertificates.AddItem "    [Version]: " & Str(Certificate.Version)
            lstCertificates.AddItem "    [Serial Number]: " & Certificate.SerialNumber
            lstCertificates.AddItem "    [Subject]: " & Certificate.SubjectName
            lstCertificates.AddItem "    [Issuer]: " & Certificate.IssuerName
            lstCertificates.AddItem "    [Not Before]: " & Certificate.ValidFromDate
            lstCertificates.AddItem "    [Not After]: " & Certificate.ValidToDate
            lstCertificates.AddItem "    [Thumbprint]: " & Certificate.Thumbprint
            lstCertificates.AddItem ""
            RecipientCertificates.Add Certificate
            
            i = i + 1
        End If
    Next
    
    Set Store = Nothing
    
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Select Recipient Certificate - Form Load"
    Unload Me
End Sub

'*******************************************************************************
'
'   Form_Unload
'   Free the Recipients collection.
'   This subroutine is called when the form is unloaded.

Private Sub Form_Unload(Cancel As Integer)
    Set RecipientCertificates = Nothing
End Sub
