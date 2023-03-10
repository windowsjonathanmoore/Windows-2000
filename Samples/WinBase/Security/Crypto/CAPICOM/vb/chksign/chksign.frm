VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmChksign 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Verify Digital Signature"
   ClientHeight    =   5040
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5640
   Icon            =   "chksign.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5040
   ScaleWidth      =   5640
   StartUpPosition =   2  'CenterScreen
   Begin VB.TextBox txtDetails 
      Height          =   1215
      Left            =   240
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      TabIndex        =   9
      Top             =   3720
      Width           =   3615
   End
   Begin VB.CommandButton cmdExtract 
      Caption         =   "&Launch Content..."
      Enabled         =   0   'False
      Height          =   615
      Left            =   4200
      TabIndex        =   5
      Top             =   1560
      Width           =   1335
   End
   Begin VB.CommandButton cmdVerify 
      Caption         =   "&Verify"
      Default         =   -1  'True
      Height          =   375
      Left            =   4200
      TabIndex        =   4
      Top             =   1080
      Width           =   1335
   End
   Begin VB.CommandButton cmdClose 
      Cancel          =   -1  'True
      Caption         =   "Exit"
      Height          =   375
      Left            =   4200
      TabIndex        =   6
      Top             =   4560
      Width           =   1335
   End
   Begin VB.CommandButton cmdView 
      Caption         =   "View &Certificate..."
      Enabled         =   0   'False
      Height          =   375
      Left            =   2280
      TabIndex        =   8
      Top             =   3240
      Width           =   1575
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   4320
      Top             =   3360
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton cmdBrowse 
      Caption         =   "B&rowse..."
      Height          =   375
      Left            =   4200
      TabIndex        =   3
      Top             =   360
      Width           =   1335
   End
   Begin VB.TextBox txtFilename 
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   360
      Width           =   3615
   End
   Begin MSComctlLib.ImageList ImageList1 
      Left            =   4920
      Top             =   3360
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   18
      ImageHeight     =   15
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   3
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "chksign.frx":030A
            Key             =   "valid"
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "chksign.frx":0450
            Key             =   "invalid"
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "chksign.frx":085A
            Key             =   "list"
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.TreeView TreeView1 
      Height          =   2055
      Left            =   240
      TabIndex        =   7
      Top             =   1080
      Width           =   3615
      _ExtentX        =   6376
      _ExtentY        =   3625
      _Version        =   393217
      LabelEdit       =   1
      Style           =   7
      Appearance      =   1
   End
   Begin VB.Label Label2 
      Caption         =   "Signature Details:"
      Height          =   255
      Left            =   240
      TabIndex        =   0
      Top             =   3480
      Width           =   3495
   End
   Begin VB.Label Label1 
      Caption         =   "&File Name"
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   120
      Width           =   975
   End
End
Attribute VB_Name = "frmChksign"
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
Private shellexVerb As String
Public lasterror As String
Private Const SW_SHOWNORMAL = 1
Private Declare Function ShellExecute Lib "shell32.dll" _
    Alias "ShellExecuteA" (ByVal hwnd As Long, _
    ByVal lpOperation As String, ByVal lpFile As String, _
    ByVal lpParameters As String, ByVal lpDirectory As String, _
    ByVal nShowCmd As Long) As Long
Private Sub cmdBrowse_Click()
    CommonDialog1.ShowOpen
    If Not CommonDialog1.CancelError Then
        txtFilename = CommonDialog1.filename
    Else
        txtFilename = ""
    End If
    cmdExtract.Enabled = False
End Sub

Private Sub cmdClose_Click()
    End
End Sub

Public Function recursesig(p7 As String) As Boolean

On Error GoTo Err_Fn
    Dim tvNode As Node
    Dim fAllValid As Boolean
    
    Set tvNode = TreeView1.Nodes.Add(, , , "Signatures")
    fAllValid = RecurseSig1(tvNode, p7)
    tvNode.Image = "list"
    tvNode.Expanded = True
    recursesig = fAllValid
    Exit Function

Err_Fn:
    MsgBox Err & ":" & Err.Description
    recursesig = fAllValid
End Function

Private Function RecurseSig1(inode As Node, p7 As String) As Boolean
On Error GoTo Err_Fn
    Dim i As Integer
    Dim tvNode As Node
    Dim ch As New Chain
    Dim cer As Certificate
    Dim signer As signer
    Dim sd As New SignedData
    Dim retval As Boolean
    
    sd.Verify p7
    retval = True
    For i = 1 To sd.Signers.Count
        Set signer = sd.Signers(i)
        Set cer = signer.Certificate
        Set tvNode = TreeView1.Nodes.Add(inode.Index, tvwChild, , cer.GetInfo(CAPICOM_CERT_INFO_SUBJECT_SIMPLE_NAME))
        Set tvNode.Tag = signer
        tvNode.Expanded = True
        If cer.IsValid Then
            tvNode.Image = "valid"
        Else
            tvNode.Image = "invalid"
            retval = False
            ch.Build cer
            lasterror = GetChainError(ch.Status(0))
        End If
    Next i
    RecurseSig1 = retval And RecurseSig1(tvNode, sd.Content)
    Exit Function

Err_Fn:
    'If we have any error, assume it's because we have hit the original content.
    'Note, there are other errors that could get us here, but this sample ignores those cases.
    RecurseSig1 = True
End Function


Private Sub cmdExtract_Click()
    Dim defaultfilename As String
    
    defaultfilename = txtFilename.Text & ".noext"
    shellexVerb = "openas"  'This pops up the shell "Open With... dialog"
    extract_content LoadFile(txtFilename), defaultfilename
End Sub

Private Sub cmdVerify_Click()
    Dim retval As Boolean
    
    If Len(txtFilename) = 0 Then
        MsgBox "You must select a file.", vbCritical + vbOKOnly
    Else
        'reset the form
        TreeView1.Nodes.Clear
        cmdView.Enabled = False
        txtDetails.Text = ""
        
        retval = recursesig(LoadFile(txtFilename))
        If Not retval Then
            MsgBox "The signature could not be verified: " & lasterror, vbCritical + vbOKOnly
        Else
            MsgBox "The signature verified successfully.", vbOKOnly
        End If
        cmdExtract.Enabled = True
    End If
End Sub

Private Function LoadFile(ByVal filename As String) As String
    Dim s As String
    Open filename For Binary As #1
    ReDim buffer(LOF(1) - 1) As Byte
    Get #1, , buffer
    LoadFile = buffer
    Close #1
End Function
Private Sub SaveFile(ByVal filename As String, strdata As String)
    ReDim Data(Len(strdata)) As Byte
    Data = strdata
    Open filename For Binary As #1
    Put #1, , Data
    Close #1
End Sub

Private Sub cmdView_Click()
    TreeView1.SelectedItem.Tag.Certificate.Display
End Sub

Private Sub Form_Load()
    TreeView1.ImageList = ImageList1
End Sub


Private Sub Form_Unload(Cancel As Integer)
    End
End Sub

Private Sub TreeView1_NodeClick(ByVal Node As MSComctlLib.Node)
    Dim signtime As String
    Dim filename As String
    Dim filedes As String
    Dim attrs As Attributes
    
    Dim s As signer
    Dim i As Integer
    
    Dim ch As New Chain
    
    If Node.Index = 1 Then
        cmdView.Enabled = False
        txtDetails = ""
    Else
        Set s = Node.Tag
        Set attrs = s.AuthenticatedAttributes
        For i = 1 To attrs.Count
            If attrs.Item(i).Name = CAPICOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME Then
                signtime = attrs.Item(i).Value
            End If
            If attrs.Item(i).Name = CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_NAME Then
                filename = attrs.Item(i).Value
            End If
            If attrs.Item(i).Name = CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_DESCRIPTION Then
                filedes = attrs.Item(i).Value
            End If
        Next i
        If Len(signtime) = 0 Then
            txtDetails = "Signing Time: Not available" & vbCrLf
        Else
            txtDetails = "Signing Time: " & signtime & vbCrLf
        End If
        If Len(filename) = 0 Then
            txtDetails = txtDetails & "File Name: Not available" & vbCrLf
        Else
            txtDetails = txtDetails & "File Name: " & filename & vbCrLf
        End If
        If Len(filedes) = 0 Then
            txtDetails = txtDetails & "File Description: Not available" & vbCrLf
        Else
            txtDetails = txtDetails & "File Description: " & filedes & vbCrLf
        End If
        cmdView.Enabled = True
  
        If Node.Image = "invalid" Then
            ch.Build s.Certificate
            txtDetails = txtDetails & GetChainError(ch.Status(0))
        End If
    End If
    
End Sub

Public Sub extract_content(p7 As String, fname As String)
On Error GoTo Err_Fn
    Dim attr As CAPICOM.Attribute
    Dim i, j As Integer
    Dim sd As New SignedData
    Dim sgns As Signers
    Dim attrs As Attributes
    sd.Verify p7
    
    Set sgns = sd.Signers
    ' check for an authenticated attribute containing filename.  if found, override passed in filename.
    For i = 1 To sgns.Count
        Set attrs = sgns.Item(i).AuthenticatedAttributes
        For j = 1 To attrs.Count
            If attrs.Item(j).Name = CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_NAME Then
                fname = attrs.Item(j).Value
                shellexVerb = "open" 'now that we know a filename, just open it.
            End If
        Next j
    Next i
    extract_content sd.Content, fname
    Exit Sub
Err_Fn:
    Dim fso As FileSystemObject
    'If we have any error, assume it's because we have hit the original content.
    'Note, there are other errors that could get us here, but this sample ignores those cases.
    SaveFile fname, p7
    ShellExecute 0, shellexVerb, fname, "", "", SW_SHOWNORMAL
End Sub


Function GetChainError(code As Long) As String
    
    Select Case code
        Case CAPICOM_TRUST_IS_PARTIAL_CHAIN
            GetChainError = "All the certificates in the certificate chain could not be found."
        Case CAPICOM_TRUST_IS_NOT_SIGNATURE_VALID
            GetChainError = "The signature is not valid."
        Case CAPICOM_TRUST_IS_NOT_TIME_VALID
            GetChainError = "The certificate is not time valid."
        Case CAPICOM_TRUST_IS_REVOKED
            GetChainError = "One or more certificates have been revoked."
        Case CAPICOM_TRUST_IS_UNTRUSTED_ROOT
            GetChainError = "The root certificate is not trusted."
        Case CAPICOM_TRUST_REVOCATION_STATUS_UNKNOWN
            GetChainError = "Certificate Revocation status is unknown."
        Case Else
            GetChainError = code & ": Error validating chain."
    End Select

End Function
