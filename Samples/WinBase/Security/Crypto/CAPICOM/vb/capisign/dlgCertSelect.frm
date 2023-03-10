VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form dlgCertSelect 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Select a Certificate"
   ClientHeight    =   5745
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   6225
   Icon            =   "dlgCertSelect.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5745
   ScaleWidth      =   6225
   ShowInTaskbar   =   0   'False
   Begin MSComctlLib.ImageList ImageList1 
      Left            =   1800
      Top             =   5160
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   32
      ImageHeight     =   24
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   1
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "dlgCertSelect.frx":030A
            Key             =   "bigcert"
         EndProperty
      EndProperty
   End
   Begin VB.CommandButton cmdView 
      Caption         =   "&View"
      Height          =   375
      Left            =   120
      TabIndex        =   5
      Top             =   5280
      Width           =   1215
   End
   Begin MSComctlLib.ListView ListView2 
      Height          =   2415
      Left            =   120
      TabIndex        =   4
      Top             =   2760
      Width           =   6015
      _ExtentX        =   10610
      _ExtentY        =   4260
      View            =   3
      LabelEdit       =   1
      LabelWrap       =   -1  'True
      HideSelection   =   -1  'True
      FullRowSelect   =   -1  'True
      _Version        =   393217
      ForeColor       =   -2147483640
      BackColor       =   -2147483643
      BorderStyle     =   1
      Appearance      =   1
      NumItems        =   2
      BeginProperty ColumnHeader(1) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         Text            =   "Field"
         Object.Width           =   3175
      EndProperty
      BeginProperty ColumnHeader(2) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         SubItemIndex    =   1
         Text            =   "Value"
         Object.Width           =   7056
      EndProperty
   End
   Begin MSComctlLib.ListView ListView1 
      Height          =   2175
      Left            =   120
      TabIndex        =   3
      Top             =   120
      Width           =   6015
      _ExtentX        =   10610
      _ExtentY        =   3836
      Arrange         =   1
      LabelEdit       =   1
      LabelWrap       =   -1  'True
      HideSelection   =   -1  'True
      PictureAlignment=   5
      _Version        =   393217
      Icons           =   "ImageList1"
      ForeColor       =   -2147483640
      BackColor       =   -2147483643
      BorderStyle     =   1
      Appearance      =   1
      NumItems        =   0
   End
   Begin VB.CommandButton CancelButton 
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4800
      TabIndex        =   1
      Top             =   5280
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   3360
      TabIndex        =   0
      Top             =   5280
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Certificate Details:"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   2400
      Width           =   1575
   End
End
Attribute VB_Name = "dlgCertSelect"
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

Private Sub CancelButton_Click()
    Me.Visible = False
End Sub
Private Sub cmdView_Click()
    If Not ListView1.SelectedItem Is Nothing Then
        ListView1.SelectedItem.Tag.Display
    End If
End Sub

Private Sub Form_Load()
    Dim st As New Store
    Dim i As Integer
    Dim cert As Certificate
    Dim li As ListItem
    Dim certs As Certificates
 
    ListView1.Icons = ImageList1
    st.Open
    Set certs = st.Certificates
    For i = 1 To certs.Count
        Set cert = certs.Item(i)
        Set li = ListView1.ListItems.Add(, , cert.GetInfo(CAPICOM_CERT_INFO_SUBJECT_SIMPLE_NAME), "bigcert")
        Set li.Tag = cert
    Next i
    ListView1.Arrange = lvwAutoLeft
End Sub



Private Sub ListView1_ItemClick(ByVal Item As MSComctlLib.ListItem)
    Dim li As ListItem
    Dim cert As Certificate
    Dim streku As String
    Dim theEKUs As EKUs
    Dim i As Integer
    Dim picname As String
    
    Set cert = Item.Tag
    ListView2.ListItems.Clear
    
    Set li = ListView2.ListItems.Add(, , "Version")
    li.SubItems(1) = cert.Version
    Set li = ListView2.ListItems.Add(, , "Subject Name")
    li.SubItems(1) = cert.SubjectName
    Set li = ListView2.ListItems.Add(, , "Issuer Name")
    li.SubItems(1) = cert.IssuerName
    Set li = ListView2.ListItems.Add(, , "Valid From")
    li.SubItems(1) = cert.ValidFromDate
    Set li = ListView2.ListItems.Add(, , "Valid To")
    li.SubItems(1) = cert.ValidToDate
    Set li = ListView2.ListItems.Add(, , "Thumbprint")
    li.SubItems(1) = cert.Thumbprint
    Set theEKUs = cert.ExtendedKeyUsage.EKUs
    For i = 1 To theEKUs.Count
        If theEKUs(i).Name = CAPICOM_EKU_CLIENT_AUTH Then
            streku = streku & "Client Authentication" & "(" & theEKUs.Item(i).OID & ") "
        ElseIf theEKUs(i).Name = CAPICOM_EKU_CODE_SIGNING Then
            streku = streku & "Code Signing" & "(" & theEKUs.Item(i).OID & ") "
        ElseIf theEKUs(i).Name = CAPICOM_EKU_EMAIL_PROTECTION Then
            streku = streku & "Email" & "(" & theEKUs.Item(i).OID & ") "
        ElseIf theEKUs(i).Name = CAPICOM_EKU_CODE_SIGNING Then
            streku = streku & "Code Signing" & "(" & theEKUs.Item(i).OID & ") "
        ElseIf theEKUs(i).Name = CAPICOM_EKU_SERVER_AUTH Then
            streku = streku & "Server Authentication" & "(" & theEKUs.Item(i).OID & ") "
        Else
            streku = streku & "Unknown" & "(" & theEKUs.Item(i).OID & ") "
        End If
    Next i
    Set li = ListView2.ListItems.Add(, , "EKU")
    li.SubItems(1) = streku
    Set li = ListView2.ListItems.Add(, , "Serial Number")
    li.SubItems(1) = cert.SerialNumber
    Set li = ListView2.ListItems.Add(, , "Private Key")
    li.SubItems(1) = IIf(cert.HasPrivateKey, "Yes", "No")

End Sub


Private Sub OKButton_Click()
    If Not ListView1.SelectedItem Is Nothing Then
        Set state.cert = ListView1.SelectedItem.Tag
    End If
    Me.Visible = False
End Sub
