VERSION 5.00
Begin VB.Form frmSignDemo 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "CAPICOM  Sign Data Demonstration"
   ClientHeight    =   7035
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   10350
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7035
   ScaleWidth      =   10350
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton cmdClose 
      Caption         =   "Close"
      Default         =   -1  'True
      Height          =   375
      Left            =   8640
      TabIndex        =   12
      Top             =   6480
      Width           =   1455
   End
   Begin VB.CommandButton cmdReset 
      Caption         =   "Reset"
      Height          =   375
      Left            =   6840
      TabIndex        =   11
      Top             =   6480
      Width           =   1455
   End
   Begin VB.Frame Frame2 
      Caption         =   "Verify Operation"
      Height          =   2895
      Left            =   240
      TabIndex        =   6
      Top             =   3360
      Width           =   9855
      Begin VB.TextBox txtSignedContent 
         Enabled         =   0   'False
         Height          =   2295
         Left            =   1800
         MultiLine       =   -1  'True
         TabIndex        =   8
         Top             =   360
         Width           =   6255
      End
      Begin VB.CommandButton cmdSigners 
         Caption         =   "Signers"
         Enabled         =   0   'False
         Height          =   375
         Left            =   8400
         TabIndex        =   10
         Top             =   960
         Width           =   1215
      End
      Begin VB.CommandButton cmdVerify 
         Caption         =   "Verify"
         Enabled         =   0   'False
         Height          =   375
         Left            =   8400
         TabIndex        =   9
         Top             =   360
         Width           =   1215
      End
      Begin VB.Label lblSignedContent 
         Caption         =   "Signed content:"
         Height          =   255
         Left            =   120
         TabIndex        =   7
         Top             =   360
         Width           =   1575
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Sign Operation"
      Height          =   2895
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   9855
      Begin VB.CheckBox chkBinaryEncode 
         Caption         =   "Binary encode"
         Height          =   255
         Left            =   8400
         TabIndex        =   13
         Top             =   720
         Width           =   1335
      End
      Begin VB.CommandButton cmdCoSign 
         Caption         =   "CoSign"
         Enabled         =   0   'False
         Height          =   375
         Left            =   8400
         TabIndex        =   5
         Top             =   1920
         Width           =   1215
      End
      Begin VB.CheckBox chkDetached 
         Caption         =   "Detached"
         Height          =   255
         Left            =   8400
         TabIndex        =   3
         Top             =   360
         Width           =   1335
      End
      Begin VB.CommandButton cmdSign 
         Caption         =   "Sign"
         Enabled         =   0   'False
         Height          =   375
         Left            =   8400
         TabIndex        =   4
         Top             =   1320
         Width           =   1215
      End
      Begin VB.TextBox txtContent 
         Height          =   2295
         Left            =   1800
         MultiLine       =   -1  'True
         TabIndex        =   2
         Top             =   360
         Width           =   6255
      End
      Begin VB.Label lblContent 
         Caption         =   "Content to be signed:"
         Height          =   255
         Left            =   120
         TabIndex        =   1
         Top             =   360
         Width           =   1575
      End
   End
End
Attribute VB_Name = "frmSignDemo"
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

Public SignedData As SignedData
Public Signer As Signer
Public bHasSigner As Boolean
Private SignedMessage() As Byte

'*******************************************************************************
'
'   txtContent_Change
'   If there is text in the txtContent box, enable the sign button and the Detachedcheck box.
'   This subroutine is called when the contents of the txtContent box is changed.

Private Sub txtContent_Change()

If txtContent.Text <> "" Then
    chkDetached.Enabled = True
    cmdSign.Enabled = True
    cmdSign.Default = True
Else
    chkDetached.Enabled = False
    cmdSign.Enabled = False
    
End If
End Sub

'*******************************************************************************
'
'   cmdSign_Click
'   Create a signature for the contents of the txtContent box.
'   This subroutine is called when the Sign button is clicked.

Private Sub cmdSign_Click()

    On Error GoTo ErrorHandler
    
    Set Signer = New CAPICOM.Signer
    

    SignedData.Content = txtContent.Text
    
' Display the form to choose the certificate of the signer of
' the data.

    frmSelect.Show vbModal
      
    If bHasSigner = True Then
' If a signer has been selected, sign the data.
' First, some optional attributes are set. In this case,
' The signing time, a name for the data signed and a description
' of the data signed are added to the signature.

        Dim SigningTime As New CAPICOM.Attribute
        Dim DocumentName As New CAPICOM.Attribute
        Dim DocumentDescription As New CAPICOM.Attribute
        
        SigningTime.Name = CAPICOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME
        SigningTime.Value = Now
        Signer.AuthenticatedAttributes.Add SigningTime
           
        DocumentName.Name = CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_NAME
        DocumentName.Value = "My Document Name"
        Signer.AuthenticatedAttributes.Add DocumentName
           
        DocumentDescription.Name = CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_DESCRIPTION
        DocumentDescription.Value = "My Document Description"
        Signer.AuthenticatedAttributes.Add DocumentDescription
        
'Display the value of the attributes.
        
        Dim i As Long
        Dim AuthAttr As CAPICOM.Attribute
    
        i = 0
        Dim msgstr As String
        msgstr = ""
        For Each AuthAttr In Signer.AuthenticatedAttributes
            i = i + 1
            msgstr = msgstr & "AuthAttr[" & i & "].Value= " & CStr(AuthAttr.Value) & vbCrLf
        Next
        MsgBox msgstr
        
        Set SigningTime = Nothing
        Set DocumentName = Nothing
        Set DocumentDescription = Nothing
        
        SignedMessage = SignedData.Sign(Signer, chkDetached, IIf(chkBinaryEncode, CAPICOM_ENCODE_BINARY, CAPICOM_ENCODE_BASE64))
    Else
        SignedMessage = SignedData.Sign(, chkDetached, IIf(chkBinaryEncode, CAPICOM_ENCODE_BINARY, CAPICOM_ENCODE_BASE64))
    End If
    
' Display the signature in the txtSignedContent box.
' This content will be gibberish.
    
    If chkBinaryEncode Then
        txtSignedContent.Text = StrConv(SignedMessage, vbUnicode)
    Else
        txtSignedContent.Text = SignedMessage
    End If
    
    chkDetached.Enabled = False
    txtContent.Enabled = False
    
    cmdSign.Enabled = False
    cmdCoSign.Enabled = True
    cmdVerify.Enabled = True
    cmdSigners.Enabled = True
  
    
    cmdVerify.SetFocus
    
    Set Signer = Nothing
    
    Exit Sub
    
ErrorHandler:
    ' Don't bill out if the form was voluntarily unloaded because no certificate
    ' is availabe for user selection.
    If Err.Number = 364 Then
        Resume Next
    End If
    
    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Sign"
End Sub

'*******************************************************************************
'
'   cmdCoSign_Click
'   Create an additional signature on an already signed text.
'   This subroutine is called when the CoSign button is clicked.

Private Sub cmdCoSign_Click()

    On Error GoTo ErrorHandler
    
    Set Signer = New CAPICOM.Signer
    
    frmSelect.Show vbModal
      
    If bHasSigner = True Then
        If chkBinaryEncode Then
            SignedMessage = SignedData.CoSign(Signer, CAPICOM_ENCODE_BINARY)
        Else
            SignedMessage = SignedData.CoSign(Signer)
        End If
    Else
        If chkBinaryEncode Then
            SignedMessage = SignedData.CoSign(, CAPICOM_ENCODE_BINARY)
        Else
            SignedMessage = SignedData.CoSign
        End If
    End If
    
    If chkBinaryEncode Then
        txtSignedContent.Text = StrConv(SignedMessage, vbUnicode)
    Else
        txtSignedContent.Text = SignedMessage
    End If
 
    cmdVerify.SetFocus
        
    Set Signer = Nothing
    
    Exit Sub
    
ErrorHandler:
        MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "CoSign"
End Sub

'*******************************************************************************
'
'   cmdVerify_Click
'   Verify the signature and any co-signature.
'   If the signature is verified, the text that was signed and is verified
'   is displayed along with the value of any attributes stored with the signature.
'   This subroutine is called when the Verify button is clicked.

Private Sub cmdVerify_Click()
    On Error GoTo ErrorHandler

    Set SignedData = New SignedData
    
    If (chkDetached) Then
        SignedData.Content = txtContent.Text
    End If
    
    SignedData.Verify SignedMessage, chkDetached
    
' Display a message indicating that the signature
' is valid and the attributes of the signature.
    
    Dim i As Long
    Dim AuthAttr As CAPICOM.Attribute
    
    i = 0
    Dim msgstr As String
    msgstr = ""
    For Each AuthAttr In SignedData.Signers.Item(0).AuthenticatedAttributes
        i = i + 1
        msgstr = msgstr & "AuthAttr[" & i & "].Value= " & CStr(AuthAttr.Value) & vbCrLf
    Next
    MsgBox "All signature(s) in this message are cryptograhically valid." & vbCrLf & msgstr
    
' Re- display the content that was signed.
' Clear the gibberish from the txtSignedContent box
' and reset for the creation of a new signature.
    
    txtContent = SignedData.Content
    txtContent.Enabled = True
    chkDetached.Enabled = True
    chkDetached.Value = False
    chkBinaryEncode.Value = False
    cmdSign.Enabled = True
    cmdCoSign.Enabled = False
        
    txtSignedContent = ""
    cmdVerify.Enabled = False
    cmdSigners.Enabled = False
     
    
    Exit Sub
    
ErrorHandler:
        MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Verify"
End Sub


'*******************************************************************************
'
'   cmdSigners_Click
'   Display information from the certificates of all signers of the data.
'   This subroutine is called when the Signers button is clicked.

Private Sub cmdSigners_Click()
    On Error GoTo ErrorHandler

    frmDisplayCerts.Show vbModal
    
    Exit Sub
ErrorHandler:
        MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "View Signers"
End Sub

'*******************************************************************************
'
'   cmdReset_Click
'   Clear any text from the txtContent and txtSignedContent boxes
'   and prepare for the signing of another message.
'   This subroutine is called when Reset button is clicked.
 
Private Sub cmdReset_Click()
       
    txtContent.Text = ""
    txtSignedContent.Text = ""
        
    txtContent.Enabled = True
    txtContent.SetFocus
    
    chkDetached.Enabled = True
    chkDetached.Value = False
    
    cmdSign.Enabled = False
    cmdCoSign.Enabled = False
    cmdVerify.Enabled = False
    cmdSigners.Enabled = False
        
    Set SignedData = New SignedData
    Set Signer = New Signer
   
End Sub

'*******************************************************************************
'
'   cmdClose_Click
'   Terminate the program.
'   This subroutine is called when the Close button is clicked.

Private Sub cmdClose_Click()
    Unload Me
End Sub

'*******************************************************************************
'
'   Form_Load
'   Create a SignedData object.
'   This subroutine is called when the program begins.

Private Sub Form_Load()
    Set SignedData = New CAPICOM.SignedData
End Sub
