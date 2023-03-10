VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmSign 
   Caption         =   "Document Signing Wizard"
   ClientHeight    =   4890
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7185
   Icon            =   "frmSign.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4890
   ScaleWidth      =   7185
   StartUpPosition =   2  'CenterScreen
   Begin VB.Frame Frame3 
      Caption         =   "Select options for the signature format"
      Height          =   1335
      Left            =   360
      TabIndex        =   7
      Top             =   600
      Width           =   6375
      Begin VB.OptionButton optDetached 
         Caption         =   "&Detached: Certificates and signature are stored in a separate file."
         Height          =   255
         Left            =   120
         TabIndex        =   9
         Top             =   840
         Width           =   5895
      End
      Begin VB.OptionButton optAttached 
         Caption         =   "&Attached: Certificates, signature, and file contents are saved as a PKCS#7 file."
         Height          =   255
         Left            =   120
         TabIndex        =   8
         Top             =   360
         Value           =   -1  'True
         Width           =   5985
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "Select how you would like to sign this file"
      Height          =   1935
      Left            =   360
      TabIndex        =   6
      Top             =   2160
      Width           =   6375
      Begin VB.OptionButton optCosign 
         Caption         =   "&Cosign (only valid for already signed documents)"
         Height          =   255
         Left            =   240
         TabIndex        =   13
         Top             =   720
         Width           =   4575
      End
      Begin VB.OptionButton optSign 
         Caption         =   "&Sign"
         Height          =   255
         Left            =   240
         TabIndex        =   12
         Top             =   360
         Value           =   -1  'True
         Width           =   3135
      End
      Begin VB.CommandButton cmdBrowse 
         Caption         =   "B&rowse..."
         Height          =   350
         Left            =   4440
         TabIndex        =   11
         Top             =   1320
         Width           =   1095
      End
      Begin VB.TextBox txtOutfilename 
         Height          =   405
         Left            =   240
         TabIndex        =   10
         Top             =   1320
         Width           =   4095
      End
      Begin MSComDlg.CommonDialog CommonDialog1 
         Left            =   5400
         Top             =   480
         _ExtentX        =   847
         _ExtentY        =   847
         _Version        =   393216
      End
      Begin VB.Label Label4 
         Caption         =   "Output &File Name:"
         Height          =   255
         Left            =   240
         TabIndex        =   14
         Top             =   1080
         Width           =   1575
      End
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
   Begin VB.Label Label1 
      Caption         =   "Select signing options."
      Height          =   255
      Left            =   480
      TabIndex        =   5
      Top             =   240
      Width           =   4995
   End
End
Attribute VB_Name = "frmSign"
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

Private Sub cmdBrowse_Click()
    CommonDialog1.ShowOpen
    If Not CommonDialog1.CancelError Then
        txtOutfilename.Text = CommonDialog1.filename
    Else
        txtOutfilename.Text = ""
    End If
End Sub

Private Sub cmdCancel_Click(Index As Integer)
    End
End Sub

Private Sub cmdNext_Click(Index As Integer)
    If optSign Then
        state.cosignMode = False
    Else
        state.cosignMode = True
    End If
    
    If optDetached Then
        state.attachedMode = False
    Else
        state.attachedMode = True
    End If
    
    If Len(txtOutfilename) = 0 Then
        MsgBox "You must specify an output file name.", vbOKOnly + vbCritical
    Else
        state.outfilename = txtOutfilename
        Me.Visible = False
        frmFinish.Visible = True
    End If
End Sub

Private Sub cmdPrev_Click(Index As Integer)
    frmOptions.Visible = True
    Me.Visible = False
End Sub

Private Sub Form_Load()
    Dim fso As New FileSystemObject
    If Not fso.GetExtensionName(state.filename) = "p7z" Then
        txtOutfilename.Text = state.filename & ".p7z"
    Else
        txtOutfilename.Text = state.filename
    End If
    
End Sub


Private Sub optAttached_Click()
    optCosign.Enabled = True
End Sub

Private Sub optDetached_Click()
    'This wizard doesn't support cosigning a detached signature.
    optSign.Value = True
    optCosign.Enabled = False
End Sub


