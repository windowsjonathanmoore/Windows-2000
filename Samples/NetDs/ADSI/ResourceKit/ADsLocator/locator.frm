VERSION 5.00
Begin VB.Form frmLocator 
   Caption         =   "Locator"
   ClientHeight    =   9360
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6375
   LinkTopic       =   "Form1"
   ScaleHeight     =   9360
   ScaleWidth      =   6375
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdDCDomain 
      Caption         =   "DCs In Domain..."
      Height          =   375
      Left            =   3720
      TabIndex        =   42
      Top             =   3960
      Width           =   1695
   End
   Begin VB.TextBox rstDCName 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   1800
      TabIndex        =   40
      Top             =   6600
      Width           =   3975
   End
   Begin VB.TextBox txtReturnedFlags 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   1800
      TabIndex        =   39
      Top             =   7680
      Width           =   3975
   End
   Begin VB.CommandButton cmdEnumTrust 
      Caption         =   "EnumDomainTrust..."
      Default         =   -1  'True
      Height          =   375
      Left            =   3720
      TabIndex        =   36
      Top             =   3000
      Width           =   1695
   End
   Begin VB.CommandButton cmdSiteCoverage 
      Caption         =   "GetDCSiteCoverage"
      Height          =   375
      Left            =   3720
      TabIndex        =   33
      Top             =   2520
      Width           =   1695
   End
   Begin VB.CommandButton cmdGetSiteName 
      Caption         =   "GetSiteName"
      Height          =   375
      Left            =   3720
      TabIndex        =   31
      Top             =   2040
      Width           =   1695
   End
   Begin VB.TextBox rstDomainGUID 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   1800
      TabIndex        =   29
      Top             =   7320
      Width           =   3975
   End
   Begin VB.TextBox rstDomainName 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   1800
      TabIndex        =   27
      Top             =   6960
      Width           =   3975
   End
   Begin VB.TextBox rstDCAddressType 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   1800
      TabIndex        =   25
      Top             =   6240
      Width           =   3975
   End
   Begin VB.TextBox rstDCAddress 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   1800
      TabIndex        =   23
      Top             =   5880
      Width           =   3975
   End
   Begin VB.TextBox rstForestName 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   1800
      TabIndex        =   21
      Top             =   5520
      Width           =   3975
   End
   Begin VB.TextBox rstSiteName 
      BackColor       =   &H8000000F&
      Height          =   285
      Left            =   1800
      TabIndex        =   19
      Top             =   5160
      Width           =   3975
   End
   Begin VB.CommandButton cmdOK 
      Caption         =   "Close"
      Height          =   375
      Left            =   4800
      TabIndex        =   15
      Top             =   240
      Width           =   1455
   End
   Begin VB.CommandButton cmdExecute 
      Caption         =   "GetDCName"
      Height          =   375
      Left            =   3720
      TabIndex        =   14
      Top             =   1560
      Width           =   1695
   End
   Begin VB.CheckBox chkReturnFlat 
      Caption         =   "Return Flat Name"
      Height          =   255
      Left            =   360
      TabIndex        =   12
      Top             =   3840
      Width           =   2655
   End
   Begin VB.CheckBox chkReturnDNS 
      Caption         =   "Return DNS Name"
      Height          =   255
      Left            =   360
      TabIndex        =   11
      Top             =   3480
      Width           =   2655
   End
   Begin VB.CheckBox chkIsDNS 
      Caption         =   "Is DNS Name"
      Height          =   255
      Left            =   360
      TabIndex        =   10
      Top             =   3120
      Width           =   2655
   End
   Begin VB.CheckBox chkIsFlat 
      Caption         =   "Is Flat Name"
      Height          =   255
      Left            =   360
      TabIndex        =   9
      Top             =   2760
      Width           =   2655
   End
   Begin VB.CheckBox chkPDC 
      Caption         =   "PDC Required"
      Height          =   255
      Left            =   360
      TabIndex        =   8
      Top             =   2400
      Width           =   2655
   End
   Begin VB.CheckBox chkGCServer 
      Caption         =   "GC Server Required"
      Height          =   255
      Left            =   360
      TabIndex        =   7
      Top             =   2040
      Width           =   2655
   End
   Begin VB.CheckBox chkForceDiscovery 
      Caption         =   "Force Discovery"
      Height          =   255
      Left            =   360
      TabIndex        =   6
      Top             =   1680
      Width           =   2775
   End
   Begin VB.TextBox txtSiteName 
      Height          =   285
      Left            =   1800
      TabIndex        =   2
      Top             =   960
      Width           =   2775
   End
   Begin VB.TextBox txtDomainName 
      Height          =   285
      Left            =   1800
      TabIndex        =   1
      Top             =   600
      Width           =   2775
   End
   Begin VB.TextBox txtComputerName 
      Height          =   285
      Left            =   1800
      TabIndex        =   0
      Top             =   240
      Width           =   2775
   End
   Begin VB.Frame Frame1 
      Caption         =   "Flag"
      Height          =   3015
      Left            =   240
      TabIndex        =   13
      Top             =   1320
      Width           =   3135
   End
   Begin VB.Frame Frame2 
      Caption         =   "Results"
      Height          =   4815
      Left            =   240
      TabIndex        =   16
      Top             =   4440
      Width           =   5895
      Begin VB.ListBox lstSiteCoverages 
         Height          =   645
         Left            =   1440
         TabIndex        =   35
         Top             =   3720
         Width           =   3975
      End
      Begin VB.TextBox rstClientSite 
         BackColor       =   &H8000000F&
         Height          =   285
         Left            =   1560
         TabIndex        =   18
         Top             =   360
         Width           =   3975
      End
      Begin VB.Label Label13 
         Alignment       =   1  'Right Justify
         Caption         =   "DC Name"
         Height          =   255
         Left            =   240
         TabIndex        =   41
         Top             =   2160
         Width           =   1095
      End
      Begin VB.Label Label12 
         Caption         =   "Returned Flags"
         Height          =   255
         Left            =   240
         TabIndex        =   38
         Top             =   3240
         Width           =   1215
      End
      Begin VB.Label Label11 
         Alignment       =   1  'Right Justify
         Caption         =   "Site Coverages"
         Height          =   255
         Left            =   120
         TabIndex        =   34
         Top             =   3720
         Width           =   1215
      End
      Begin VB.Label Label10 
         Alignment       =   1  'Right Justify
         Caption         =   "Domain GUID"
         Height          =   255
         Left            =   120
         TabIndex        =   30
         Top             =   2880
         Width           =   1215
      End
      Begin VB.Label Label9 
         Alignment       =   1  'Right Justify
         Caption         =   "Domain Name"
         Height          =   255
         Left            =   360
         TabIndex        =   28
         Top             =   2520
         Width           =   1095
      End
      Begin VB.Label Label8 
         Alignment       =   1  'Right Justify
         Caption         =   "DC Address Type"
         Height          =   255
         Left            =   120
         TabIndex        =   26
         Top             =   1800
         Width           =   1335
      End
      Begin VB.Label Label7 
         Alignment       =   1  'Right Justify
         Caption         =   "DC Address"
         Height          =   255
         Left            =   360
         TabIndex        =   24
         Top             =   1440
         Width           =   1095
      End
      Begin VB.Label Label6 
         Alignment       =   1  'Right Justify
         Caption         =   "Forest Name"
         Height          =   255
         Left            =   360
         TabIndex        =   22
         Top             =   1080
         Width           =   1095
      End
      Begin VB.Label Label5 
         Alignment       =   1  'Right Justify
         Caption         =   "DC Site Name"
         Height          =   255
         Left            =   360
         TabIndex        =   20
         Top             =   720
         Width           =   1095
      End
      Begin VB.Label Label4 
         Alignment       =   1  'Right Justify
         Caption         =   "Client Site"
         Height          =   255
         Left            =   480
         TabIndex        =   17
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame3 
      Caption         =   "Functions"
      Height          =   3135
      Left            =   3600
      TabIndex        =   32
      Top             =   1320
      Width           =   1935
      Begin VB.CommandButton cmdDsRole 
         Caption         =   "Ds Role..."
         Height          =   375
         Left            =   120
         TabIndex        =   37
         Top             =   2160
         Width           =   1695
      End
   End
   Begin VB.Label Label3 
      Alignment       =   1  'Right Justify
      Caption         =   "Site Name:"
      Height          =   255
      Left            =   240
      TabIndex        =   5
      Top             =   960
      Width           =   1455
   End
   Begin VB.Label Label2 
      Alignment       =   1  'Right Justify
      Caption         =   "Domain Name:"
      Height          =   255
      Left            =   240
      TabIndex        =   4
      Top             =   600
      Width           =   1455
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      Caption         =   "Computer Name:"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   240
      Width           =   1455
   End
End
Attribute VB_Name = "frmLocator"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Dim loc As New ADsLocator

Private Sub cmdDCDomain_Click()
  domains = loc.DsGetDCNamesInDomain(txtDomainName.Text)
  frmDC.SetDC (domains)
  frmDC.Show vbModal, Me
End Sub

Private Sub cmdDsRole_Click()
 frmDsRole.Show vbModel, Me
End Sub

Private Sub cmdEnumTrust_Click()
  frmDomainTrust.Show vbModal, Me
  
End Sub

Private Sub cmdExecute_Click()
Dim dc As ADsDCInfo
Dim flag As Long


flag = 0
If chkForceDiscovery = 1 Then
  flag = flag Or ADS_FORCE_REDISCOVERY
End If

If chkGCServer = 1 Then
  flag = flag Or ADS_GC_SERVER_REQUIRED
End If

If chkPDC = 1 Then
  flag = flag Or ADS_PDC_REQUIRED
End If

If chkIsFlat = 1 Then
  flag = flag Or ADS_IS_FLAT_NAME
End If

If chkIsDNS = 1 Then
  flag = flag Or ADS_IS_DNS_NAME
End If

If chkReturnFlat = 1 Then
  flag = flag Or ADS_RETURN_FLAT_NAME
End If

If chkReturnDNS = 1 Then
  flag = flag Or ADS_RETURN_DNS_NAME
End If

Call ResetValues

Set dc = loc.DsGetDcName(txtComputerName.Text, txtDomainName.Text, txtSiteName.Text, flag)
rstClientSite = dc.ClientSiteName
rstSiteName = dc.DcSiteName
rstForestName = dc.DnsForestName
rstDCAddress = dc.DomainControllerAddress

If (dc.DomainControllerAddressType = ADS_INET_ADDRESS) Then
 rstDCAddressType = "INET-ADDRESS"
ElseIf (dc.DomainControllerAddressType = ADS_NETBIOS_ADDRESS) Then
 rstDCAddressType = "NETBIOS-ADDRESS"
End If

rstDCName = dc.DomainControllerName
rstDomainName = dc.DomainName
rstDomainGUID = dc.DomainGuid

'---Returned Flags-----
strFlags = ""


If (dc.Flags And ADS_PDC_FLAG) Then
  strFlags = strFlags + "PDC "
End If
  
If (dc.Flags And ADS_GC_FLAG) Then
  strFlags = strFlags + "GC "
End If
 
If (dc.Flags And ADS_LDAP_FLAG) Then
    'Server supports an LDAP server
  strFlags = strFlags + "LDAP "
End If

If (dc.Flags And ADS_DS_FLAG) Then
    '  DC supports a DS and is a Domain Controller
  strFlags = strFlags + "DS "
End If

If (dc.Flags And ADS_KDC_FLAG) Then
    'ADS_KDC_FLAG  DC is running KDC service
  strFlags = strFlags + "KDC "
End If

If (dc.Flags And ADS_TIMESERV_FLAG) Then
    'ADS_TIMESERV_FLAG DC is running time service
  strFlags = strFlags + "TIME "
End If

If (dc.Flags And ADS_CLOSEST_FLAG) Then
    'ADS_CLOSEST_FLAG  DC is in closest site to client
  strFlags = strFlags + "CLOSEST "
End If
    
If (dc.Flags And ADS_WRITABLE_FLAG) Then
    'DC has a writable DS
  strFlags = strFlags + "WRITABLE "
End If

If (dc.Flags And ADS_GOOD_TIMESERV_FLAG) Then
    'DC is running time service (and has clock hardware)
  strFlags = strFlags + "GOODTIMESRV "
End If

If (dc.Flags And ADS_PING_FLAGS) Then
    'DC is running time service (and has clock hardware)
  strFlags = strFlags + "PING "
End If
    
If (dc.Flags And ADS_DNS_CONTROLLER_FLAG) Then
    'DomainControllerName is a DNS name
  strFlags = strFlags + "DNS-DC "
End If
    
If (dc.Flags And ADS_DNS_DOMAIN_FLAG) Then
    'DomainName is a DNS name
  strFlags = strFlags + "DNS-DOM "
End If
    
If (dc.Flags And DS_DNS_FOREST_FLAG) Then
    'A DnsForestName is a DNS name
  strFlags = strFlags + "DNS-DOM "
End If
    
txtReturnedFlags = strFlags

    



End Sub

Private Sub cmdGetSiteName_Click()
 Call ResetValues
 sComputer = ""
 If (txtComputerName <> "") Then
    sComputer = txtComputerName
  End If
  rstSiteName = loc.DsGetSiteName(sComputer)
End Sub

Private Sub cmdOK_Click()
 End
End Sub

Private Sub ResetValues()
rstClientSite = ""
rstSiteName = ""
rstForestName = ""
rstDCAddress = ""
rstDCAddressType = ""
rstDCName = ""
rstDomainGUID = ""
txtReturnedFlags = ""
lstSiteCoverages.Clear

End Sub

Private Sub cmdSiteCoverage_Click()
 Call ResetValues
 sComputer = ""
 If (txtComputerName <> "") Then
    sComputer = txtComputerName
  End If
 sites = loc.DsGetDcSiteCoverage(sComputer)
 If (VarType(sites) = vbString) Then
   lstSiteCoverages.AddItem sites
 ElseIf (VarType(sites) Or vbArray) Then
    For Each site In sites
      lstSiteCoverages.AddItem site
    Next
 End If
 
End Sub

