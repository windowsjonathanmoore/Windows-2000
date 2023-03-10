VERSION 5.00
Begin VB.Form frmRecipients 
   Caption         =   "Recipients"
   ClientHeight    =   5280
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7815
   LinkTopic       =   "Form1"
   ScaleHeight     =   5280
   ScaleWidth      =   7815
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox lstRecipients 
      Height          =   5325
      Left            =   0
      TabIndex        =   1
      Top             =   0
      Width           =   5775
   End
   Begin VB.CommandButton cmdClose 
      Caption         =   "Close"
      Default         =   -1  'True
      Height          =   375
      Left            =   6120
      TabIndex        =   0
      Top             =   4680
      Width           =   1455
   End
End
Attribute VB_Name = "frmRecipients"
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

' The Recipients form is used  to display infomation from the certificates of
' recipients selected to receive the encrypted message.

Option Explicit

'*******************************************************************************
'
'   cmdClose_Click
'
'   Terminate the show recipients form and returns to the main form.
'   This subroutine is called when when the Close button is clicked

Private Sub cmdClose_Click()
    Unload Me
End Sub

'*******************************************************************************
'
'   Form_Load
'   Display information from the certificates of selected recipients.
'
'   This subroutine is called when this form is shown.

Private Sub Form_Load()

    On Error GoTo ErrorHandler

    Dim i As Long
    Dim Recipient As Certificate
    
    i = 1
    
    For Each Recipient In frmEnvelop.EnvelopedData.Recipients
              
        lstRecipients.AddItem "Recipient #" & Str(i)
        lstRecipients.AddItem "    [Version]: " & Str(Recipient.Version)
        lstRecipients.AddItem "    [Serial Number]: " & Recipient.SerialNumber
        lstRecipients.AddItem "    [Subject]: " & Recipient.SubjectName
        lstRecipients.AddItem "    [Issuer]: " & Recipient.IssuerName
        lstRecipients.AddItem "    [Not Before]: " & Recipient.ValidFromDate
        lstRecipients.AddItem "    [Not After]: " & Recipient.ValidToDate
        lstRecipients.AddItem "    [Thumbprint]: " & Recipient.Thumbprint
        lstRecipients.AddItem ""
        i = i + 1
    Next
       
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "View Recipients - Form Load"
    Unload Me

End Sub
