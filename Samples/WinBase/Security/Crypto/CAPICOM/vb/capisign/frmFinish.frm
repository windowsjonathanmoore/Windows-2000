VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmFinish 
   Caption         =   "Document Signing Wizard"
   ClientHeight    =   4890
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7185
   Icon            =   "frmFinish.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4890
   ScaleWidth      =   7185
   StartUpPosition =   2  'CenterScreen
   Begin MSComctlLib.ListView ListView1 
      Height          =   1815
      Left            =   480
      TabIndex        =   7
      Top             =   1440
      Width           =   5535
      _ExtentX        =   9763
      _ExtentY        =   3201
      View            =   3
      LabelEdit       =   1
      LabelWrap       =   -1  'True
      HideSelection   =   -1  'True
      HideColumnHeaders=   -1  'True
      FullRowSelect   =   -1  'True
      _Version        =   393217
      ForeColor       =   -2147483640
      BackColor       =   -2147483643
      BorderStyle     =   1
      Appearance      =   1
      NumItems        =   2
      BeginProperty ColumnHeader(1) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         Text            =   "setting"
         Object.Width           =   3528
      EndProperty
      BeginProperty ColumnHeader(2) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         SubItemIndex    =   1
         Text            =   "value"
         Object.Width           =   5821
      EndProperty
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
      Enabled         =   0   'False
      Height          =   350
      Index           =   1
      Left            =   4200
      TabIndex        =   2
      Top             =   4440
      Width           =   1215
   End
   Begin VB.CommandButton cmdFinish 
      Caption         =   "&Finish"
      Default         =   -1  'True
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
      Caption         =   "You have specified the following settings:"
      Height          =   255
      Left            =   480
      TabIndex        =   6
      Top             =   1080
      Width           =   4455
   End
   Begin VB.Label lblSuccess 
      Caption         =   "You have succesfully completed the digital signature wizard."
      Height          =   375
      Left            =   480
      TabIndex        =   5
      Top             =   240
      Width           =   5775
   End
End
Attribute VB_Name = "frmFinish"
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

Private Sub cmdFinish_Click(Index As Integer)
    Me.Visible = False
    If sign_file() Then
        MsgBox "You successfully digitally signed the file.", vbOKOnly
    Else
        MsgBox "You digitally signing failed:  " & state.lasterror, vbExclamation + vbOKOnly
    End If
    End
End Sub


Private Sub cmdPrev_Click(Index As Integer)
    frmSign.Visible = True
    Me.Visible = False
End Sub

Private Sub Form_Activate()
    Dim li As ListItem
    ListView1.ListItems.Clear
    Set li = ListView1.ListItems.Add(, , "File name")
    li.SubItems(1) = state.filename
    Set li = ListView1.ListItems.Add(, , "      Issued To")
    li.SubItems(1) = state.cert.GetInfo(CAPICOM_CERT_INFO_SUBJECT_SIMPLE_NAME)
    Set li = ListView1.ListItems.Add(, , "      Issued By")
    li.SubItems(1) = state.cert.GetInfo(CAPICOM_CERT_INFO_ISSUER_SIMPLE_NAME)
    Set li = ListView1.ListItems.Add(, , "      Expiration Date")
    li.SubItems(1) = state.cert.ValidToDate
    Set li = ListView1.ListItems.Add(, , "Output File name")
    li.SubItems(1) = state.outfilename
    Set li = ListView1.ListItems.Add(, , "Attached Signature")
    li.SubItems(1) = state.attachedMode
    Set li = ListView1.ListItems.Add(, , "Cosign")
    li.SubItems(1) = state.cosignMode

End Sub

