VERSION 5.00
Begin VB.Form frmDomainTrust 
   Caption         =   "Domain Trust"
   ClientHeight    =   8715
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5280
   LinkTopic       =   "Form1"
   ScaleHeight     =   8715
   ScaleWidth      =   5280
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox txtFlags 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   2040
      TabIndex        =   26
      Top             =   7800
      Width           =   2415
   End
   Begin VB.TextBox txtDomainSID 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   2040
      TabIndex        =   23
      Top             =   7440
      Width           =   2415
   End
   Begin VB.TextBox txtDomainGUID 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   2040
      TabIndex        =   21
      Top             =   7080
      Width           =   2415
   End
   Begin VB.TextBox txtParentIndex 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   2040
      TabIndex        =   19
      Top             =   6720
      Width           =   2415
   End
   Begin VB.TextBox txtTrustType 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   2040
      TabIndex        =   17
      Top             =   6360
      Width           =   2415
   End
   Begin VB.Frame Frame2 
      Caption         =   "Detail Result"
      Height          =   2775
      Left            =   240
      TabIndex        =   14
      Top             =   5640
      Width           =   4575
      Begin VB.TextBox txtTrustAttribute 
         BackColor       =   &H8000000F&
         Height          =   285
         Left            =   1800
         TabIndex        =   16
         Top             =   360
         Width           =   2415
      End
      Begin VB.Label Label8 
         Alignment       =   1  'Right Justify
         Caption         =   "Flags"
         Height          =   255
         Left            =   360
         TabIndex        =   25
         Top             =   2160
         Width           =   975
      End
      Begin VB.Label Label7 
         Alignment       =   1  'Right Justify
         Caption         =   "Domain SID"
         Height          =   255
         Left            =   360
         TabIndex        =   24
         Top             =   1800
         Width           =   1095
      End
      Begin VB.Label Label6 
         Alignment       =   1  'Right Justify
         Caption         =   "Domain GUID"
         Height          =   255
         Left            =   120
         TabIndex        =   22
         Top             =   1440
         Width           =   1335
      End
      Begin VB.Label Label5 
         Alignment       =   1  'Right Justify
         Caption         =   "Parent Index"
         Height          =   255
         Left            =   360
         TabIndex        =   20
         Top             =   1080
         Width           =   1095
      End
      Begin VB.Label Label4 
         Alignment       =   1  'Right Justify
         Caption         =   "Trust Type"
         Height          =   255
         Left            =   120
         TabIndex        =   18
         Top             =   720
         Width           =   1335
      End
      Begin VB.Label Label3 
         Alignment       =   1  'Right Justify
         Caption         =   "Trust Attribute"
         Height          =   255
         Left            =   240
         TabIndex        =   15
         Top             =   360
         Width           =   1335
      End
   End
   Begin VB.CommandButton cmdExecute 
      Caption         =   "Execute"
      Default         =   -1  'True
      Height          =   375
      Left            =   4080
      TabIndex        =   13
      Top             =   720
      Width           =   1095
   End
   Begin VB.CommandButton cmdClose 
      Caption         =   "Close"
      Height          =   375
      Left            =   4080
      TabIndex        =   12
      Top             =   240
      Width           =   1095
   End
   Begin VB.TextBox txtServerName 
      Height          =   285
      Left            =   1560
      TabIndex        =   11
      Top             =   240
      Width           =   2415
   End
   Begin VB.CheckBox chkNativeMode 
      Caption         =   "Domain Native Mode"
      Height          =   255
      Left            =   480
      TabIndex        =   9
      Top             =   2760
      Width           =   2175
   End
   Begin VB.CheckBox chkDirectInbound 
      Caption         =   "Direct Inbound"
      Height          =   255
      Left            =   480
      TabIndex        =   10
      Top             =   3120
      Width           =   2175
   End
   Begin VB.CheckBox chkDomainPrimary 
      Caption         =   "Domain Primary"
      Height          =   255
      Left            =   480
      TabIndex        =   8
      Top             =   2400
      Width           =   2175
   End
   Begin VB.CheckBox chkTreeRoot 
      Caption         =   "Tree Root"
      Height          =   255
      Left            =   480
      TabIndex        =   7
      Top             =   2040
      Width           =   2175
   End
   Begin VB.CheckBox chkDirectOutbound 
      Caption         =   "Direct Outbound"
      Height          =   255
      Left            =   480
      TabIndex        =   6
      Top             =   1680
      Width           =   2175
   End
   Begin VB.CheckBox chkDirectTrust 
      Caption         =   "Direct Trust"
      Height          =   255
      Left            =   480
      TabIndex        =   5
      Top             =   1320
      Width           =   2175
   End
   Begin VB.ListBox lstTrust 
      Height          =   1425
      Left            =   240
      TabIndex        =   2
      Top             =   4080
      Width           =   4575
   End
   Begin VB.Frame Frame1 
      Caption         =   "Trust Flags"
      Height          =   2775
      Left            =   240
      TabIndex        =   0
      Top             =   720
      Width           =   2895
      Begin VB.CheckBox chkDomainInForest 
         Caption         =   "Domain In Forest"
         Height          =   255
         Left            =   240
         TabIndex        =   4
         Top             =   240
         Width           =   2175
      End
   End
   Begin VB.Label Label2 
      Caption         =   "ServerName"
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   240
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "Results"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   3720
      Width           =   1935
   End
End
Attribute VB_Name = "frmDomainTrust"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Dim x As New ADsLocator
Dim trustObject() As Object


Private Sub cmdClose_Click()
 frmDomainTrust.Hide
End Sub

Private Sub cmdExecute_Click()
Dim Flags As Long
Dim trust As IADsDomainTrust
Dim sServerName As String

Call ResetValues

sServerName = ""
Flags = 0

If txtServerName <> "" Then
  sServerName = txtServerName
End If


If chkDomainInForest = 1 Then
  Flags = Flags Or ADS_DOMAIN_IN_FOREST
End If

If chkDirectTrust = 1 Then
 Flags = Flags Or ADS_DOMAIN_DIRECT_TRUST
End If

If chkDirectOutbound = 1 Then
  Flags = Flags Or ADS_DOMAIN_DIRECT_OUTBOUND
End If

If chkTreeRoot = 1 Then
  Flags = Flags Or ADS_DOMAIN_TREE_ROOT
End If

If chkDomainPrimary = 1 Then
 Flags = Flags Or ADS_DOMAIN_PRIMARY
End If

If chkNativeMode = 1 Then
 Flags = Flags Or ADS_DOMAIN_NATIVE_MODE
End If

If chkDirectInbound = 1 Then
 Flags = Flags Or ADS_DOMAIN_DIRECT_INBOUND
End If

Set domTrusts = x.DsEnumerateDomainTrusts(sServerName, Flags)
ReDim trustObject(domTrusts.Count)
i = 1
For Each trust In domTrusts
  lstTrust.AddItem trust.NetbiosDomainName & "(" & trust.DnsDomainName & ")"
  Set trustObject(i) = trust 'Save this for future use
  i = i + 1
Next

End Sub

Private Sub ResetValues()
lstTrust.Clear
End Sub

Private Sub ResetFlags()
chkDomainInForest = 0
chkDirectTrust = 0
chkDirectOutbound = 0
chkTreeRoot = 0
chkDomainPrimary = 0
chkNativeMode = 0
chkDirectInbound = 0
End Sub




Private Sub lstTrust_Click()
Dim obj As IADsDomainTrust
Dim parentDomain As IADsDomainTrust


  idx = lstTrust.ListIndex
  Set obj = trustObject(idx + 1)
  
  
  '--- Trust Type ---------
  Select Case obj.TrustType
  
   Case ADS_TRUST_TYPE_DOWNLEVEL
      txtTrustType = "Downlevel (NT4 Style)"
   Case ADS_TRUST_TYPE_UPLEVEL
     txtTrustType = "UpLevel (Windows 2000)"
    Case ADS_TRUST_TYPE_MIT
     txtTrustType = "MIT"
    Case ADS_TRUST_TYPE_DCE
      txtTrustType = "DCE"
   Case Else
     txtTrustType = "Unknown"
  End Select
  
  
  
  '---Trust Attributes-------------
  trustAttr = obj.TrustAttributes
  trustAttrText = ""
  If (trustAttr And ADS_TRUST_ATTRIBUTE_NON_TRANSITIVE) Then
    trustAttrText = trustAttrText & "-NonTransitive "
  End If
  
  If (trustAttr And ADS_TRUST_ATTRIBUTE_UPLEVEL_ONLY) Then
     trustAttrText = trustAttrText & "-UpLevel "
  End If
  
  If (trustAttr And ADS_TRUST_ATTRIBUTE_TREE_PARENT) Then
     trustAttrText = trustAttrText & "-Parent "
  End If
  
  If (trustAttr And ADS_TRUST_ATTRIBUTE_TREE_ROOT) Then
     trustAttrText = trustAttrText & "-Root "
  End If
  
  If (trustAttr And ADS_TRUST_ATTRIBUTES_VALID) Then
     trustAttrText = trustAttrText & "-Valid)"
  End If
  
  If (trustAttr And ADS_TRUST_ATTRIBUTES_USER) Then
     trustAttrText = trustAttrText & "-User"
  End If
  
        
        
  txtTrustAttribute = trustAttrText
  
  '---- Parent Index--------------------
  parentIdx = obj.ParentIndex
  If (obj.TrustType = ADS_TRUST_TYPE_DOWNLEVEL) Then
    txtParentIndex = "None-(It's downlevel)"
  ElseIf (obj.Flags And ADS_DOMAIN_TREE_ROOT) Then
    txtParentIndex = "Tree Root"
  Else
   Set parentDomain = trustObject(obj.ParentIndex + 1)
   txtParentIndex = parentDomain.DnsDomainName
  End If
  
  
  '---- GUID and SID-----
  txtDomainGUID = obj.DomainGuid
  txtDomainSID = obj.DomainSid
  Debug.Print obj.NetbiosDomainName
  
  '--- Flags---------
  strFlag = ""
  
  If (obj.Flags And ADS_DOMAIN_IN_FOREST) Then
     strFlag = strFlags + "In-Forest "
  End If
  
  If (obj.Flags And ADS_DOMAIN_DIRECT_TRUST) Then
    strFlag = strFlag + "Direct-Trust "
  End If
  
  If (obj.Flags And ADS_DOMAIN_DIRECT_OUTBOUND) Then
    strFlag = strFlag + "Direct-Outbound "
  End If
  
  If (obj.Flags And ADS_DOMAIN_TREE_ROOT) Then
    strFlag = strFlag + "Tree-Root "
  End If
  If (obj.Flags And ADS_DOMAIN_PRIMARY) Then
    strFlag = strFlag + "Primary "
  End If
  
  If (obj.Flags And ADS_DOMAIN_NATIVE_MODE) Then
    strFlag = strFlag + "Native "
  End If
  
  If (obj.Flags And ADS_DOMAIN_DIRECT_INBOUND) Then
    strFlag = strFlag + "Direct-Inbound "
  End If
  
  txtFlags = strFlag
         
         

  
End Sub


Private Sub lstTrust_DblClick()
Dim obj As IADsDomainTrust

idx = lstTrust.ListIndex
If (idx = -1) Then
  Return
End If

Set obj = trustObject(idx + 1)
If (obj.DnsDomainName <> "") Then
  domains = x.DsGetDCNamesInDomain(obj.DnsDomainName)
  frmDC.SetDC (domains)
  frmDC.Show vbModal, Me
Else
 Beep
End If
  
End Sub

