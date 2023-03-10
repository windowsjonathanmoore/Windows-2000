VERSION 5.00
Begin VB.Form frmChain 
   Caption         =   "CryptCOM - Chain"
   ClientHeight    =   6000
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8340
   LinkTopic       =   "Form2"
   ScaleHeight     =   6000
   ScaleWidth      =   8340
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnDisplay 
      Caption         =   "Display"
      Height          =   375
      Left            =   240
      TabIndex        =   24
      Top             =   5040
      Width           =   1335
   End
   Begin VB.Frame Status 
      Caption         =   "Status"
      Height          =   4095
      Left            =   5280
      TabIndex        =   3
      Top             =   600
      Width           =   2775
      Begin VB.CheckBox chkCTLInvalidUsage 
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   22
         Top             =   3600
         Width           =   255
      End
      Begin VB.CheckBox chkCTLInvalidSignature 
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   20
         Top             =   3240
         Width           =   255
      End
      Begin VB.CheckBox chkCTLInvalidTime 
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   18
         Top             =   2880
         Width           =   255
      End
      Begin VB.CheckBox chkPartialChain 
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   16
         Top             =   2520
         Width           =   255
      End
      Begin VB.CheckBox chkUnknownRevocation 
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   14
         Top             =   2160
         Width           =   255
      End
      Begin VB.CheckBox chkUntrustedRoot 
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   12
         Top             =   1800
         Width           =   255
      End
      Begin VB.CheckBox chkInvalidUsage 
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   10
         Top             =   1440
         Width           =   255
      End
      Begin VB.CheckBox chkInvalidSignature 
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   8
         Top             =   1080
         Width           =   255
      End
      Begin VB.CheckBox chkRevoked 
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   6
         Top             =   720
         Width           =   255
      End
      Begin VB.CheckBox chkInvalidTime 
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   4
         Top             =   360
         Width           =   255
      End
      Begin VB.Label Label1 
         Caption         =   "CTL invalid usage"
         Height          =   255
         Left            =   600
         TabIndex        =   23
         Top             =   3600
         Width           =   1815
      End
      Begin VB.Label lblCTLInvalidSignature 
         Caption         =   "CTL invalid signature"
         Height          =   255
         Left            =   600
         TabIndex        =   21
         Top             =   3240
         Width           =   1815
      End
      Begin VB.Label lblCTLInvalidTime 
         Caption         =   "CTL invalid time"
         Height          =   255
         Left            =   600
         TabIndex        =   19
         Top             =   2880
         Width           =   1815
      End
      Begin VB.Label lblPartialChain 
         Caption         =   "Partial chain"
         Height          =   255
         Left            =   600
         TabIndex        =   17
         Top             =   2520
         Width           =   1815
      End
      Begin VB.Label lblUnknownRevocation 
         Caption         =   "Unknown revocation"
         Height          =   255
         Left            =   600
         TabIndex        =   15
         Top             =   2160
         Width           =   1815
      End
      Begin VB.Label lblUntrustedRoot 
         Caption         =   "Untrusted root"
         Height          =   255
         Left            =   600
         TabIndex        =   13
         Top             =   1800
         Width           =   1815
      End
      Begin VB.Label lblInvalidUsage 
         Caption         =   "Invalid usage"
         Height          =   255
         Left            =   600
         TabIndex        =   11
         Top             =   1440
         Width           =   1815
      End
      Begin VB.Label lblInvalidSignature 
         Caption         =   "Invalid signature"
         Height          =   255
         Left            =   600
         TabIndex        =   9
         Top             =   1080
         Width           =   1815
      End
      Begin VB.Label lblRevoked 
         Caption         =   "Revoked"
         Height          =   255
         Left            =   600
         TabIndex        =   7
         Top             =   720
         Width           =   1815
      End
      Begin VB.Label lblInvalidTime 
         Caption         =   "Invalid time"
         Height          =   255
         Left            =   600
         TabIndex        =   5
         Top             =   360
         Width           =   1815
      End
   End
   Begin VB.ListBox lstChain 
      Height          =   3960
      Left            =   240
      TabIndex        =   2
      Top             =   720
      Width           =   4815
   End
   Begin VB.CommandButton bntClose2 
      Caption         =   "Close"
      Height          =   375
      Left            =   6720
      TabIndex        =   25
      Top             =   5040
      Width           =   1335
   End
   Begin VB.Label lblStatus 
      BorderStyle     =   1  'Fixed Single
      Height          =   255
      Left            =   0
      TabIndex        =   26
      Top             =   5760
      Width           =   8415
   End
   Begin VB.Label lblNumCerts 
      BorderStyle     =   1  'Fixed Single
      Height          =   255
      Left            =   2640
      TabIndex        =   1
      Top             =   240
      Width           =   855
   End
   Begin VB.Label lblChain 
      Caption         =   "Number of certificates in chain:"
      Height          =   255
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   2295
   End
End
Attribute VB_Name = "frmChain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.

' Copyright (C) 2000.  Microsoft Corporation.  All rights reserved.
' ******************************************************************************
Option Explicit
Private Chain As Chain

'*****************************************************************************
'
' bntClose2_Click
'
' Close the certificate verification form and return to
' the main certificate store management form.
' This subroutine is called weh the Close button is clicked.
'

Private Sub bntClose2_Click()

    Unload Me
End Sub

'*****************************************************************************
'
'  btnDisplay_Click
'
' Display all of the certificates in the certificate trust
' verification chain.
' This subroutine is called when the Display button is clicked.
'

Private Sub btnDisplay_Click()

    On Error GoTo ErrorHandler
    
    Dim Index As Long
    Index = FindIndex(lstChain)
    If Index > 0 Then
        Dim Certificate As Certificate
        Set Certificate = Chain.Certificates.Item(Index)
        Certificate.Display
    End If
        
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Display"

End Sub

'*****************************************************************************
'
' Sub Form_Load
'
' Initalize the form and build a certificate trust verification
' chain for a selected certificate.
'
' This subroutine is called when the form is loaded.

Private Sub Form_Load()

    On Error GoTo ErrorHandler
    
    Dim Certificates As Certificates
    Set Certificates = frmStore.Store.Certificates
    
    Dim Certificate As Certificate
    Set Certificate = Certificates.Item(frmStore.CertificateIndex)
   
    Set Chain = CreateObject("CAPICOM.Chain")
    
    Dim Result As Boolean
    
    Result = Chain.Build(Certificate)
    
    Set Certificates = Chain.Certificates
    lblNumCerts = Certificates.Count()
    
    Dim i As Long
    
    i = 1
    For Each Certificate In Certificates
        If i > 1 Then
            lstChain.AddItem ""
        End If
        
        lstChain.AddItem "Cert #" & Str(i)
        lstChain.AddItem "    [Version]: " & Str(Certificate.Version)
        lstChain.AddItem "    [Serial Number]: " & Certificate.SerialNumber
        lstChain.AddItem "    [Subject]: " & Certificate.SubjectName
        lstChain.AddItem "    [Issuer]: " & Certificate.IssuerName
        lstChain.AddItem "    [Not Before]: " & Certificate.ValidFromDate
        lstChain.AddItem "    [Not After]: " & Certificate.ValidToDate
        lstChain.AddItem "    [Thumbprint]: " & Certificate.Thumbprint
       
        i = i + 1
    Next
    
    Dim Status As Long
    
    Status = Chain.Status
    
    If (Status And CAPICOM_TRUST_IS_NOT_TIME_VALID) = CAPICOM_TRUST_IS_NOT_TIME_VALID Then
        chkInvalidTime.Value = 1
    End If
    If (Status And CAPICOM_TRUST_IS_REVOKED) = CAPICOM_TRUST_IS_REVOKED Then
        chkRevoked.Value = 1
    End If
    If (Status And CAPICOM_TRUST_IS_NOT_SIGNATURE_VALID) = CAPICOM_TRUST_IS_NOT_SIGNATURE_VALID Then
        chkInvalidSignature.Value = 1
    End If
    If (Status And CAPICOM_TRUST_IS_NOT_VALID_FOR_USAGE) = CAPICOM_TRUST_IS_NOT_VALID_FOR_USAGE Then
        chkInvalidUsage.Value = 1
    End If
    If (Status And CAPICOM_TRUST_IS_UNTRUSTED_ROOT) = CAPICOM_TRUST_IS_UNTRUSTED_ROOT Then
        chkUntrustedRoot.Value = 1
    End If
    If (Status And CAPICOM_TRUST_REVOCATION_STATUS_UNKNOWN) = CAPICOM_TRUST_REVOCATION_STATUS_UNKNOWN Then
        chkUnknownRevocation.Value = 1
    End If
    If (Status And CAPICOM_TRUST_IS_PARTIAL_CHAIN) = CAPICOM_TRUST_IS_PARTIAL_CHAIN Then
        chkPartialChain.Value = 1
    End If
    If (Status And CAPICOM_TRUST_CTL_IS_NOT_TIME_VALID) = CAPICOM_TRUST_CTL_IS_NOT_TIME_VALID Then
        chkCTLInvalidTime.Value = 1
    End If
    If (Status And CAPICOM_TRUST_CTL_IS_NOT_SIGNATURE_VALID) = CAPICOM_TRUST_CTL_IS_NOT_SIGNATURE_VALID Then
        chkCTLInvalidSignature.Value = 1
    End If
    If (Status And CAPICOM_TRUST_CTL_IS_NOT_VALID_FOR_USAGE) = CAPICOM_TRUST_CTL_IS_NOT_VALID_FOR_USAGE Then
        chkCTLInvalidUsage.Value = 1
    End If
    
    If Result = True Then
        lblStatus.Caption = "Overall chain status is valid."
    Else
        lblStatus.Caption = "Overall chain status is not valid."
    End If
    Exit Sub
    
    Set Chain = Nothing
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Chain Form"
    Unload Me

End Sub

