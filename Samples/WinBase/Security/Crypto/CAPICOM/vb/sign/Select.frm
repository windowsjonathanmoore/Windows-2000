VERSION 5.00
Begin VB.Form frmSelect 
   Caption         =   "Select signer's certificate"
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
      Caption         =   $"Select.frx":0000
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
Option Explicit
Dim SigningCertificates As Collection

'*******************************************************************************
'
'   cmdCancel_Click
'   Close this frmSelect form.
'   This subroutine is called when the Cancel button is clicked.

Private Sub cmdCancel_Click()

    Unload Me
End Sub

'*******************************************************************************
'
'   cmdOK_Click
'   Select the highlighted certificate from the certificates displayed when the form loaded.
'   The selected certificate is added to the list of signer certificates, the global
'   bHasSigner varialbe is set to True and the form closes.
'   Note: Only certificate that have an available private key are
'   displayed.
'   If no certificate is highlighted, the first certificate in the display is
'   used.
'   This subroutine is called when the OK button is clicked.

Private Sub cmdOK_Click()

    On Error GoTo ErrorHandler
    
    Dim Index As Long
    Index = FindIndex(lstCertificates)
    
    If Index > 0 Then
        frmSignDemo.Signer.Certificate = SigningCertificates.Item(Index)
        frmSignDemo.bHasSigner = True
    End If
    
    Unload Me
    
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Select Signer's Certificate - OK"
    Unload Me
End Sub

'*******************************************************************************
'
'   Form_Load
'   Open the current user's MY certificate store and display informaition on all
'   of the certifcates in that store that have available private keys.
'   Note: the private key of the signer must be available in order
'   to create a signature.
'   This subroutine is called when the frmSelect form is loaded.

Private Sub Form_Load()

    On Error GoTo ErrorHandler

    frmSignDemo.bHasSigner = False
    
    Set SigningCertificates = New Collection
    
    Dim Store As New Store
    Store.Open CAPICOM_CURRENT_USER_STORE, "MY", CAPICOM_STORE_OPEN_READ_ONLY
        
    Dim i As Long
    Dim bAddBlankLine As Boolean
    Dim Certificate As Certificate
    
    i = 1
   
    For Each Certificate In Store.Certificates
                
        If Certificate.IsValid And Certificate.HasPrivateKey Then
   
   ' Display information for each certificate
   
            lstCertificates.AddItem "Cert #" & Str(i) & ": Valid with private key"
            lstCertificates.AddItem "    [Version]: " & Str(Certificate.Version)
            lstCertificates.AddItem "    [Serial Number]: " & Certificate.SerialNumber
            lstCertificates.AddItem "    [Subject]: " & Certificate.SubjectName
            lstCertificates.AddItem "    [Issuer]: " & Certificate.IssuerName
            lstCertificates.AddItem "    [Not Before]: " & Certificate.ValidFromDate
            lstCertificates.AddItem "    [Not After]: " & Certificate.ValidToDate
            lstCertificates.AddItem "    [Thumbprint]: " & Certificate.Thumbprint
            lstCertificates.AddItem " "
   
   ' Add the certificate to the collection of signer certificates.
   
            SigningCertificates.Add Certificate
            
            i = i + 1
        End If
    Next
    
   ' Close and free the store.
   
    Set Store = Nothing
    
    ' Don't display selection dialog if there is no certificate to be selected.
    ' Note the different that this sample filters out invalid certificates
    ' and certificates without private key, whereas, CAPICOM will ONLY filter
    ' out certificates that are time invalid. So, you may still see dialog box
    ' displayed later by CAPICOM to prompt user to select signing certificate.
    If SigningCertificates.Count = 0 Then
        Unload Me
    End If
    
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Select Signer's Certificate - Form Load"
    Unload Me
End Sub

'*******************************************************************************
'
'   Form_Unload
'   Release the collection of certificates and terminates the form,
'   This subroutine is called when when the frmSelect form is terminated.

Private Sub Form_Unload(Cancel As Integer)
    Set SigningCertificates = Nothing
End Sub
