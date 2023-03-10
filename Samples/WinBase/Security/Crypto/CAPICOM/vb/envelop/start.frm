VERSION 5.00
Begin VB.Form frmEnvelop 
   Caption         =   "CAPICOM Enveloped Data Demonstration"
   ClientHeight    =   6945
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8790
   LinkTopic       =   "Form1"
   ScaleHeight     =   6945
   ScaleWidth      =   8790
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame FrameParams 
      Caption         =   "Envelop parameters"
      Height          =   1575
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   8295
      Begin VB.ComboBox comAlgo 
         Height          =   315
         Left            =   1800
         Style           =   2  'Dropdown List
         TabIndex        =   2
         Top             =   360
         Width           =   4575
      End
      Begin VB.ComboBox comKeyLength 
         Height          =   315
         Left            =   1800
         Style           =   2  'Dropdown List
         TabIndex        =   4
         Top             =   960
         Width           =   4575
      End
      Begin VB.CommandButton cmdAddRecipient 
         Caption         =   "Add Recipient"
         Default         =   -1  'True
         Height          =   375
         Left            =   6720
         TabIndex        =   5
         Top             =   360
         Width           =   1335
      End
      Begin VB.Label lblAlgo 
         Caption         =   "Encryption algorithm:"
         Height          =   255
         Left            =   240
         TabIndex        =   1
         Top             =   360
         Width           =   1575
      End
      Begin VB.Label lblKeyLength 
         Caption         =   "Key length:"
         Height          =   255
         Left            =   240
         TabIndex        =   3
         Top             =   960
         Width           =   1575
      End
   End
   Begin VB.CommandButton cmdReset 
      Caption         =   "Reset"
      Height          =   375
      Left            =   5400
      TabIndex        =   15
      Top             =   6360
      Width           =   1335
   End
   Begin VB.Frame FrameDecrypt 
      Caption         =   "Decrypt"
      Height          =   1935
      Left            =   240
      TabIndex        =   11
      Top             =   4200
      Width           =   8295
      Begin VB.TextBox txtEnveloped 
         Enabled         =   0   'False
         Height          =   1335
         Left            =   1800
         TabIndex        =   13
         Top             =   360
         Width           =   4575
      End
      Begin VB.CommandButton cmdDecrypt 
         Caption         =   "Decrypt"
         Enabled         =   0   'False
         Height          =   375
         Left            =   6720
         TabIndex        =   14
         Top             =   360
         Width           =   1335
      End
      Begin VB.Label lblEnveloped 
         Caption         =   "Enveloped content:"
         Height          =   255
         Left            =   240
         TabIndex        =   12
         Top             =   360
         Width           =   1455
      End
   End
   Begin VB.Frame FrameEncrypt 
      Caption         =   "Encrypt"
      Height          =   1935
      Left            =   240
      TabIndex        =   6
      Top             =   2040
      Width           =   8295
      Begin VB.CommandButton cmdRecipients 
         Caption         =   "Recipients"
         Enabled         =   0   'False
         Height          =   375
         Left            =   6720
         TabIndex        =   10
         Top             =   960
         Width           =   1335
      End
      Begin VB.TextBox txtContent 
         Height          =   1335
         Left            =   1800
         TabIndex        =   8
         Top             =   360
         Width           =   4575
      End
      Begin VB.CommandButton cmdEncrypt 
         Caption         =   "Encrypt"
         Enabled         =   0   'False
         Height          =   375
         Left            =   6720
         TabIndex        =   9
         Top             =   360
         Width           =   1335
      End
      Begin VB.Label lblContent 
         Caption         =   "Clear text content:"
         Height          =   255
         Left            =   240
         TabIndex        =   7
         Top             =   360
         Width           =   1455
      End
   End
   Begin VB.CommandButton cmdClose 
      Caption         =   "Close"
      Height          =   375
      Left            =   6960
      TabIndex        =   16
      Top             =   6360
      Width           =   1335
   End
End
Attribute VB_Name = "frmEnvelop"
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
' This program demonstrates the use of the EnvelopedData CAPICOM object
' to encrypt a message for one or more recipients. The message is encypted
' with a randomly generated encryption key. The encryption key is then
' encrypted separatly for each recipient using the public key form the
' recipient's certificate.
' The EnvelopedData object, then, contains the encryted message, information about the
' encryption algorithm and key length, certificate of each intended receiver, and a separate
' encryted encryption key for each recipient.
' When an enveloped message is recieved, a search is made of the recipeints MY certificate
' store. If a match is found between a certificate in the MY store and one of the
' certificates in the EnvelopedData object, and if the certificate in the MY store has
' an associated private key, the receivers private key is used to decrypt the encryption key
' and that decrypted key is used to decrypt the message.

'*******************************************************************************
'
' The following global variables are used.

Public EnvelopedData As EnvelopedData
Private EnvelopedContent() As Byte

'*******************************************************************************
'
'
'   This subroutine is called when

Private Sub txtContent_Change()
' This subroutine is used to enable the encryption button on
' the form if the content in the txtContent box exists and has been changed.
' If content of the txtContent box has been erased, the encrytion button
' is disabled.

    If Len(txtContent.Text) = 0 Then
        cmdEncrypt.Enabled = False
    Else
        cmdEncrypt.Enabled = True
    End If
End Sub

'*******************************************************************************
'
'
'   This subroutine is called when

Private Sub cmdAddRecipient_Click()
' This subroutine is used to display the form used to added recipeints
' and their certificates to the enveloped message.

    frmSelect.Show vbModal
End Sub

'*******************************************************************************
'
'
'   This subroutine is called when

Private Sub cmdEncrypt_Click()
' This subroutine encrypts the message and encrypts the encryption key
' separatly for each selected recipient.

    On Error GoTo ErrorHandler
' The text to be encrypted, the encryption algorithm, and
' the selected key length are set in the enveloped data object.

    EnvelopedData.Content = txtContent
    EnvelopedData.Algorithm.Name = comAlgo.ListIndex
    EnvelopedData.Algorithm.KeyLength = comKeyLength.ListIndex

' The message is encrypted and saved in the global byte array,
' EnvelopedContent.

    EnvelopedContent = EnvelopedData.Encrypt
' The text that has been encryted is cleard from the textContent
' box and the encrypted bytes are displayed in the txtEnveloped
' box. The content displayed in the txtEnveloped box will be
' gibberish.

    txtContent = ""
    txtEnveloped = EnvelopedContent
    
' Choosing an encryption algorithm, a key length, adding recipients
' and the encryption button are disabled.
' The decryption button is enabled.

    comAlgo.Enabled = False
    comKeyLength.Enabled = False
    
    cmdAddRecipient.Enabled = False
    cmdEncrypt.Enabled = False
    cmdRecipients.Enabled = False
    cmdDecrypt.Enabled = True
   
    txtContent.Enabled = False
    
' Free the EnvelopedData object.
    
    Set EnvelopedData = Nothing
    
    Exit Sub
    
ErrorHandler:
        MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Encrypt"
End Sub

'*******************************************************************************
'
'
'   This subroutine is called when

Private Sub cmdRecipients_Click()
' This subroutine shows the certificates of the selected recipients of
' the message.
    
    On Error GoTo ErrorHandler
    
    frmRecipients.Show vbModal
    
    Exit Sub
    
ErrorHandler:
        MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Recipients"
End Sub

'*******************************************************************************
'
'
'   This subroutine is called when

Private Sub cmdDecrypt_Click()
' This subroutine decrypts the enveloped message. If a match
' is not found between a certificate in the enveloped content
' and a certificate in the receiver's MY store that has access to
' the receiver's private key, an error is returned and decryption
' fails.

    On Error GoTo ErrorHandler
    
    Set EnvelopedData = New EnvelopedData

' Attempt to decrypt the message in the global byte array EnelopedContent.

    EnvelopedData.Decrypt EnvelopedContent
    
' If the message is decrypted, display the name of the
' encryption algorithm, the key length, and the decrypted
' message content.
' The gibberish in the txtEnveloped box is also cleared.

    comAlgo.Enabled = True
    comAlgo.ListIndex = EnvelopedData.Algorithm.Name
    comAlgo.SetFocus
    
    comKeyLength.Enabled = True
    comKeyLength.ListIndex = EnvelopedData.Algorithm.KeyLength
    
    txtContent.Enabled = True
    txtContent.Text = EnvelopedData.Content
    
    cmdAddRecipient.Enabled = True
    cmdEncrypt.Enabled = True
    cmdRecipients.Enabled = True
    cmdDecrypt.Enabled = False
    
    txtEnveloped.Enabled = False
    txtEnveloped.Text = ""

       
    Exit Sub
    
ErrorHandler:
        MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Decrypt"
End Sub

'*******************************************************************************
'
'
'   This subroutine is called when

Private Sub cmdReset_Click()
' This subroutine reset the program to create a new enveloped message.

    On Error GoTo ErrorHandler
    
    Set EnvelopedData = New EnvelopedData
    
    comAlgo.Enabled = True
    comAlgo.ListIndex = CAPICOM_ENCRYPTION_ALGORITHM_RC2
    comAlgo.SetFocus

    comKeyLength.Enabled = True
    comKeyLength.ListIndex = CAPICOM_ENCRYPTION_KEY_LENGTH_MAXIMUM

    txtContent.Enabled = True
    txtContent.Text = ""
   
    cmdAddRecipient.Enabled = True
    cmdEncrypt.Enabled = False
    cmdRecipients.Enabled = False
    cmdDecrypt.Enabled = False
    
    txtEnveloped.Enabled = False
    txtEnveloped.Text = ""
        
    Exit Sub
ErrorHandler:
        MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Reset"
End Sub

'*******************************************************************************
'
'
'   This subroutine is called when

Private Sub cmdClose_Click()
' This subroutine terminates the program.

    Unload Me
End Sub

'*******************************************************************************
'
'
'   This subroutine is called when

Private Sub Form_Load()
    
    Set EnvelopedData = New CAPICOM.EnvelopedData
    
    comAlgo.AddItem ("ENCRYPTION_ALGORITHM_RC2")
    comAlgo.AddItem ("ENCRYPTION_ALGORITHM_RC4")
    comAlgo.AddItem ("ENCRYPTION_ALGORITHM_DES")
    comAlgo.AddItem ("ENCRYPTION_ALGORITHM_3DES")
    comAlgo.ListIndex = CAPICOM_ENCRYPTION_ALGORITHM_RC2
    
    comKeyLength.AddItem ("KEY_LENGTH_MAXIMUM")
    comKeyLength.AddItem ("KEY_LENGTH_40_BITS")
    comKeyLength.AddItem ("KEY_LENGTH_56_BITS")
    comKeyLength.AddItem ("KEY_LENGTH_128_BITS")
    comKeyLength.ListIndex = CAPICOM_ENCRYPTION_KEY_LENGTH_MAXIMUM
    
End Sub
