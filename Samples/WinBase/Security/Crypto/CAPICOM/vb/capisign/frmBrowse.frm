VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmBrowse 
   Caption         =   "Document Signing Wizard"
   ClientHeight    =   4890
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7185
   Icon            =   "frmBrowse.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4890
   ScaleWidth      =   7185
   StartUpPosition =   2  'CenterScreen
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   5280
      Top             =   2640
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton cmdBrowse 
      Caption         =   "B&rowse..."
      Height          =   350
      Left            =   4920
      TabIndex        =   3
      Top             =   1920
      Width           =   1215
   End
   Begin VB.TextBox txtFilename 
      Height          =   375
      Left            =   480
      TabIndex        =   2
      Top             =   1920
      Width           =   4335
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
      TabIndex        =   5
      Top             =   4440
      Width           =   1200
   End
   Begin VB.CommandButton cmdNext 
      Caption         =   "&Next >"
      Default         =   -1  'True
      Height          =   350
      Index           =   1
      Left            =   4200
      TabIndex        =   6
      Top             =   4440
      Width           =   1215
   End
   Begin VB.CommandButton cmdFinish 
      Caption         =   "&Finish"
      Enabled         =   0   'False
      Height          =   350
      Index           =   0
      Left            =   5760
      TabIndex        =   7
      TabStop         =   0   'False
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
   Begin VB.Label Label2 
      Caption         =   "&File Name:"
      Height          =   255
      Left            =   480
      TabIndex        =   1
      Top             =   1680
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "Select the file you would like to digitally sign."
      Height          =   255
      Left            =   480
      TabIndex        =   8
      Top             =   360
      Width           =   3855
   End
End
Attribute VB_Name = "frmBrowse"
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
        txtFilename = CommonDialog1.filename
    End If
End Sub

Private Sub cmdCancel_Click(Index As Integer)
    End
End Sub

Private Sub cmdNext_Click(Index As Integer)
    Dim fso As New FileSystemObject

    If Len(txtFilename.Text) > 0 And fso.FileExists(txtFilename.Text) Then
        state.filename = txtFilename.Text
        frmOptions.Visible = True
        Me.Visible = False
    Else
       If Len(txtFilename.Text) > 0 Then
            MsgBox txtFilename.Text & " doesn't exist", vbOKOnly + vbCritical
        Else
            MsgBox "You must select a file.", vbOKOnly + vbCritical
        End If
    End If
End Sub

Private Sub cmdPrev_Click(Index As Integer)
    frmIntro.Visible = True
    Me.Visible = False
End Sub
