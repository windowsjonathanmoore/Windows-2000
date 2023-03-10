VERSION 5.00
Begin VB.Form frmEncrypt 
   Caption         =   "CAPICOM Encrypt Data Demonstration"
   ClientHeight    =   7050
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8790
   LinkTopic       =   "Form1"
   ScaleHeight     =   7050
   ScaleWidth      =   8790
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame FrameParams 
      Caption         =   "Encryption Parameters"
      Height          =   1815
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   8295
      Begin VB.Frame FrameKeyLength 
         Caption         =   "Key length"
         Height          =   1335
         Left            =   6720
         TabIndex        =   5
         Top             =   240
         Width           =   1335
         Begin VB.OptionButton rb128Bits 
            Caption         =   "128 bits"
            Height          =   315
            Left            =   120
            TabIndex        =   19
            Top             =   960
            Width           =   975
         End
         Begin VB.OptionButton rb56Bits 
            Caption         =   "56 bits"
            Height          =   315
            Left            =   120
            TabIndex        =   8
            Top             =   720
            Width           =   975
         End
         Begin VB.OptionButton rb40Bits 
            Caption         =   "40 bits"
            Height          =   255
            Left            =   120
            TabIndex        =   7
            Top             =   480
            Width           =   975
         End
         Begin VB.OptionButton rbMaximum 
            Caption         =   "Maximum"
            Height          =   255
            Left            =   120
            TabIndex        =   6
            Top             =   240
            Value           =   -1  'True
            Width           =   975
         End
      End
      Begin VB.TextBox txtPassword 
         Height          =   285
         IMEMode         =   3  'DISABLE
         Left            =   1800
         MaxLength       =   64
         PasswordChar    =   "*"
         TabIndex        =   4
         Top             =   960
         Width           =   4575
      End
      Begin VB.ComboBox comAlgo 
         Height          =   315
         Left            =   1800
         Style           =   2  'Dropdown List
         TabIndex        =   2
         Top             =   360
         Width           =   4575
      End
      Begin VB.Label lblPassword 
         Caption         =   "Encryption password:"
         Height          =   375
         Left            =   240
         TabIndex        =   3
         Top             =   960
         Width           =   1575
      End
      Begin VB.Label lblAlgo 
         Caption         =   "Encryption Algorithm:"
         Height          =   255
         Left            =   240
         TabIndex        =   1
         Top             =   360
         Width           =   1575
      End
   End
   Begin VB.CommandButton cmdReset 
      Caption         =   "Reset"
      Height          =   375
      Left            =   5400
      TabIndex        =   17
      Top             =   6480
      Width           =   1335
   End
   Begin VB.Frame FrameDecrypt 
      Caption         =   "Decrypt"
      Height          =   1935
      Left            =   240
      TabIndex        =   13
      Top             =   4320
      Width           =   8295
      Begin VB.TextBox txtEncrypted 
         Enabled         =   0   'False
         Height          =   1335
         Left            =   1800
         TabIndex        =   15
         Top             =   360
         Width           =   4575
      End
      Begin VB.CommandButton cmdDecrypt 
         Caption         =   "Decrypt"
         Enabled         =   0   'False
         Height          =   375
         Left            =   6720
         TabIndex        =   16
         Top             =   360
         Width           =   1335
      End
      Begin VB.Label lblEnveloped 
         Caption         =   "Encrypted content:"
         Height          =   255
         Left            =   240
         TabIndex        =   14
         Top             =   360
         Width           =   1455
      End
   End
   Begin VB.Frame FrameEncrypt 
      Caption         =   "Encrypt"
      Height          =   1815
      Left            =   240
      TabIndex        =   9
      Top             =   2280
      Width           =   8295
      Begin VB.CommandButton cmdEncrypt 
         Caption         =   "Encrypt"
         Enabled         =   0   'False
         Height          =   375
         Left            =   6720
         TabIndex        =   12
         Top             =   360
         Width           =   1335
      End
      Begin VB.TextBox txtContent 
         Height          =   1215
         Left            =   1800
         TabIndex        =   11
         Top             =   360
         Width           =   4575
      End
      Begin VB.Label lblContent 
         Caption         =   "Clear text content:"
         Height          =   255
         Left            =   240
         TabIndex        =   10
         Top             =   360
         Width           =   1455
      End
   End
   Begin VB.CommandButton cmdClose 
      Caption         =   "Close"
      Height          =   375
      Left            =   6960
      TabIndex        =   18
      Top             =   6480
      Width           =   1335
   End
End
Attribute VB_Name = "frmEncrypt"
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

'*******************************************************************************
'
' This program demonstrates the encryption and decryption of a text. For
' encryption, an encryption algormithm is selected, key length may be set,
' and an encryption secret password used to generate the encryption key
' is entered.
' When the text is encrypted. the plain text is hidden.
' To decrypt, the same secert password must be entered. The
' same algormith as used to encrypt the data is used for decription.
' If the correct password is entered, the decrypted message appears in
' the text box.


Private EncryptedMessage() As Byte


'*******************************************************************************
'
' txtPassword_Change
' Enable the encryption button if
'      (1) there is a non empty string in the txtContent box
'      (2) there is a non empty string in the txtPassword box.
'
' This subroutine is called if the value of txtPassword is changed.
'


Private Sub txtPassword_Change()

    If txtContent.Text <> "" And txtPassword.Text <> "" Then
        cmdEncrypt.Enabled = True
        cmdEncrypt.Default = True
    End If

End Sub

'*******************************************************************************
' txtContent_Change
' Enable the encryption button if
'      (1) there is a non empty string in the txtContent box
'      (2) there is a non empty string in the txtPassword box.
'
' This subroutine is called if the value of txtContent is changed.
'

Private Sub txtContent_Change()
    If txtContent.Text <> "" And txtPassword.Text <> "" Then
        cmdEncrypt.Enabled = True
        cmdEncrypt.Default = True
    End If
    
End Sub

'*******************************************************************************
'
' cmdEncrypt_Click
' Encrypt the text contents of txtContent
' using the text in txtPassword to generate an encryption key.
' It also clears the content of txtContent and txtPassword, and
' it enables the decryption button.
' The encrypted data, including information on the algorithm used,
' the key length, and the secert password used to generate the
' encryption key is stored in the global byte array variable, EncryptedMessage.
' This subroutine is called when Encrypt button is clicked.

Private Sub cmdEncrypt_Click()

    On Error GoTo ErrorHandler
     
    Dim EncryptedData As New EncryptedData

    EncryptedData.Content = txtContent
    EncryptedData.SetSecret txtPassword
    EncryptedData.Algorithm.Name = comAlgo.ListIndex
    If rb40Bits = True Then
        EncryptedData.Algorithm.KeyLength = CAPICOM_ENCRYPTION_KEY_LENGTH_40_BITS
    Else
        If rb56Bits = True Then
            EncryptedData.Algorithm.KeyLength = CAPICOM_ENCRYPTION_KEY_LENGTH_56_BITS
        Else
            If rb128Bits = True Then
                EncryptedData.Algorithm.KeyLength = CAPICOM_ENCRYPTION_KEY_LENGTH_128_BITS
            End If
        End If
    End If
    
    ' Encrypt the data and store the encrypted data
    ' along with the name of the encryption algorithm,
    ' the key length, and the secret password used to
    ' generate the encryption key in the global byte
    ' array, EncryptedMessage.
    
    EncryptedMessage = EncryptedData.Encrypt
    
    ' Display the contents of the global byte array
    ' in the txtEncrypted box on the form. The contents
    ' display will be gibbish.
    
    txtEncrypted.Text = EncryptedMessage
    
    ' Reset the form to show the default encryption algorithm
    ' name and the default key length. Setting the algorithm
    ' and the key length is disabled.

    comAlgo.ListIndex = 0
    comAlgo.Enabled = False
    
    rbMaximum.Value = True
    FrameKeyLength.Enabled = False
    
    ' Clear the contents of the txtPassword and txtContent
    ' boxes on the form. Adding to the contents of txtContent
    ' is disabled, the encypt button is disabled, and the decryption
    ' button is enabled.
    
    txtPassword.Text = ""
    txtContent.Text = ""
    txtContent.Enabled = False
    
    cmdEncrypt.Enabled = False
    cmdDecrypt.Enabled = True
    cmdDecrypt.SetFocus
    
    ' Free the EncryptedData object.
    
    Set EncryptedData = Nothing
    
    Exit Sub
    
ErrorHandler:
        MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Encrypt"
End Sub

'*******************************************************************************
'
'  cmdDecrypt_Click
' This subroutine attempts to decrypt the encrypted data.
' A new EncyptedData object is created. The contents of
' the txtPassword box is set as the secret password used to
' genearate the decryption key. Decryption is done to the global
' byte array, EncryptedMessage that contains the encrypted data along
' with information about the encryption algorithm and key length.
' If the contents of txtPassword are not exactly the same
' as the secert password used to generate the encryption key,
' decryption fails.
' This subroutine is called when Decrypt button is clicked.

Private Sub cmdDecrypt_Click()

    On Error GoTo ErrorHandler
    
    Dim EncryptedData As New EncryptedData
       
    EncryptedData.SetSecret txtPassword
    EncryptedData.Decrypt EncryptedMessage
    
    ' If decrption succeeds, the name of the algorithm used
    ' and the key length are displayed.
    
    comAlgo.Enabled = True
    comAlgo.ListIndex = EncryptedData.Algorithm.Name
    
    FrameKeyLength.Enabled = True
    If EncryptedData.Algorithm.KeyLength = CAPICOM_ENCRYPTION_KEY_LENGTH_40_BITS Then
        rb40Bits = True
    Else
        If EncryptedData.Algorithm.KeyLength = CAPICOM_ENCRYPTION_KEY_LENGTH_56_BITS Then
            rb56Bits = True
        Else
            If EncryptedData.Algorithm.KeyLength = CAPICOM_ENCRYPTION_KEY_LENGTH_128_BITS Then
                rb128Bits = True
            Else
                rbMaximum = True
            End If
        End If
    End If
    
    ' The contents of the txtPassword box is cleared
    ' and the decrypted data is displayed in the txtContent
    ' box. The display of the encrypted data is cleared, the
    ' encrypt button is enabled, and the decrypt button
    ' is disabled.
    
    txtPassword.Text = ""
    txtPassword.SetFocus
    
    txtContent.Enabled = True
    txtContent.Text = EncryptedData.Content
    
    cmdEncrypt.Enabled = True
    cmdEncrypt.SetFocus
    cmdDecrypt.Enabled = False
    
    txtEncrypted.Enabled = False
    txtEncrypted.Text = ""
        
    ' The EncryptedData object is freed.
    Set EncryptedData = Nothing
    
    Exit Sub
    
ErrorHandler:
        MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Decrypt"
End Sub

'*******************************************************************************
'
' cmdReset_Click
' Clear the form and resets all default values.
'
' This subroutine is called when the Reset button is clicked.

Private Sub cmdReset_Click()

    On Error GoTo ErrorHandler
    
    comAlgo.Enabled = True
    comAlgo.ListIndex = CAPICOM_ENCRYPTION_ALGORITHM_RC2
    comAlgo.SetFocus
    
    rbMaximum.Value = True
    
    txtContent.Enabled = True
    txtContent.Text = ""
    
    txtPassword.Enabled = True
    txtPassword.Text = ""
    
    cmdEncrypt.Enabled = False
    cmdDecrypt.Enabled = False
    
    txtEncrypted.Enabled = False
    txtEncrypted.Text = ""
          
    Exit Sub
ErrorHandler:
        MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Reset"
End Sub

'*******************************************************************************
'
' cmdClose_Click
' This subroutine terminates the program.
' This subroutine is called when the close button is clicked.

Private Sub cmdClose_Click()
    Unload Me
End Sub

'*******************************************************************************
'
'  Form_Load
'  Establish the choices of encryption algorithms.
'  This subroutine is called before the form is shown
'  for the first time.

Private Sub Form_Load()

    comAlgo.AddItem ("ENCRYPTION_ALGORITHM_RC2")
    comAlgo.AddItem ("ENCRYPTION_ALGORITHM_RC4")
    comAlgo.AddItem ("ENCRYPTION_ALGORITHM_DES")
    comAlgo.AddItem ("ENCRYPTION_ALGORITHM_3DES")
    comAlgo.ListIndex = CAPICOM_ENCRYPTION_ALGORITHM_RC2
    
End Sub
