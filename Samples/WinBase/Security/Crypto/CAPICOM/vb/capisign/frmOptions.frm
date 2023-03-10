VERSION 5.00
Begin VB.Form frmOptions 
   Caption         =   "Document Signing Wizard"
   ClientHeight    =   4890
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7185
   Icon            =   "frmOptions.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4890
   ScaleWidth      =   7185
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton cmdView 
      Caption         =   "&View Certificate"
      Enabled         =   0   'False
      Height          =   350
      Left            =   3840
      TabIndex        =   8
      Top             =   2160
      Width           =   1815
   End
   Begin VB.CommandButton cmdSelect 
      Caption         =   "&Select from Store..."
      Height          =   350
      Left            =   3840
      TabIndex        =   7
      Top             =   1680
      Width           =   1815
   End
   Begin VB.CommandButton cmdCancel 
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   350
      Index           =   3
      Left            =   1440
      TabIndex        =   4
      Top             =   4440
      Width           =   1215
   End
   Begin VB.CommandButton cmdPrev 
      Caption         =   "< &Previous"
      Height          =   350
      Index           =   2
      Left            =   3000
      TabIndex        =   3
      Top             =   4440
      Width           =   1200
   End
   Begin VB.CommandButton cmdNext 
      Caption         =   " &Next >"
      Default         =   -1  'True
      Height          =   350
      Index           =   1
      Left            =   4200
      TabIndex        =   2
      Top             =   4440
      Width           =   1215
   End
   Begin VB.CommandButton cmdFinish 
      Caption         =   "&Finish"
      Enabled         =   0   'False
      Height          =   350
      Index           =   0
      Left            =   5760
      TabIndex        =   1
      Top             =   4440
      Width           =   1215
   End
   Begin VB.Frame Frame1 
      Height          =   135
      Left            =   120
      TabIndex        =   0
      Top             =   4200
      Width           =   6855
   End
   Begin VB.Label lblCert 
      BackColor       =   &H80000005&
      BorderStyle     =   1  'Fixed Single
      Height          =   855
      Left            =   480
      TabIndex        =   9
      Top             =   1680
      Width           =   3255
   End
   Begin VB.Label Label2 
      Caption         =   "Use this certificate:"
      Height          =   255
      Left            =   480
      TabIndex        =   6
      Top             =   1440
      Width           =   2055
   End
   Begin VB.Label Label1 
      Caption         =   "You can attach a certificate to the signature.  The corresponding private key will be used to sign the file."
      Height          =   615
      Left            =   480
      TabIndex        =   5
      Top             =   360
      Width           =   5295
   End
End
Attribute VB_Name = "frmOptions"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.

' Copyright (C) 2001.  Microsoft Corporation.  All rights reserved.
' ******************************************************************************
Option Explicit
Private Sub cmdCancel_Click(Index As Integer)
    End
End Sub

Private Sub cmdNext_Click(Index As Integer)
    If state.cert Is Nothing Then
        MsgBox "You must select a certificate.", vbOKOnly + vbCritical
    Else
        Me.Visible = False
        frmSign.Visible = True
    End If
End Sub


Private Sub cmdPrev_Click(Index As Integer)
    frmBrowse.Visible = True
    Me.Visible = False
End Sub

Private Sub cmdSelect_Click()
    dlgCertSelect.Show (vbModal)
    If Not state.cert Is Nothing Then
        lblCert.Caption = "Issued To:          " & state.cert.GetInfo(CAPICOM_CERT_INFO_SUBJECT_SIMPLE_NAME) & vbCrLf & _
            "Issued By:          " & state.cert.GetInfo(CAPICOM_CERT_INFO_ISSUER_SIMPLE_NAME) & vbCrLf & _
            "Expiration Date: " & state.cert.ValidToDate
        cmdView.Enabled = True
    Else
        lblCert.Caption = ""
        cmdView.Enabled = False
    End If
End Sub

Private Sub cmdView_Click()
    state.cert.Display
End Sub

Private Sub Form_Load()
    'Pick the first cert in the store as the default cert
    Dim mysto As New Store
    
    mysto.Open
    If mysto.Certificates.Count > 0 Then
        Set state.cert = mysto.Certificates(1)
        lblCert.Caption = "Issued To:          " & state.cert.GetInfo(CAPICOM_CERT_INFO_SUBJECT_SIMPLE_NAME) & vbCrLf & _
            "Issued By:          " & state.cert.GetInfo(CAPICOM_CERT_INFO_ISSUER_SIMPLE_NAME) & vbCrLf & _
            "Expiration Date: " & state.cert.ValidToDate
        cmdView.Enabled = True
    End If
    
End Sub
