VERSION 5.00
Begin VB.Form frmIntro 
   Caption         =   "Document Signing Wizard"
   ClientHeight    =   4890
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7185
   Icon            =   "frmIntro.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4890
   ScaleWidth      =   7185
   StartUpPosition =   2  'CenterScreen
   Begin VB.PictureBox Picture1 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   4215
      Left            =   0
      Picture         =   "frmIntro.frx":030A
      ScaleHeight     =   4185
      ScaleWidth      =   2145
      TabIndex        =   5
      Top             =   0
      Width           =   2175
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
      Enabled         =   0   'False
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
   Begin VB.Label Label3 
      Caption         =   "To begin, click Next."
      Height          =   375
      Left            =   2400
      TabIndex        =   8
      Top             =   3120
      Width           =   3735
   End
   Begin VB.Label Label2 
      Caption         =   "Welcome to the Digital Signature wizard."
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   2400
      TabIndex        =   7
      Top             =   120
      Width           =   4575
   End
   Begin VB.Label Label1 
      Caption         =   "This wizard helps you digitally sign a document."
      Height          =   375
      Left            =   2400
      TabIndex        =   6
      Top             =   1200
      Width           =   4215
   End
End
Attribute VB_Name = "frmIntro"
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
    frmBrowse.Visible = True
    Me.Visible = False
End Sub

