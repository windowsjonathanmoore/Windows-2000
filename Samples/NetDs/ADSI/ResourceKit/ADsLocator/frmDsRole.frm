VERSION 5.00
Begin VB.Form frmDsRole 
   Caption         =   "Ds Role"
   ClientHeight    =   7425
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6870
   LinkTopic       =   "Form1"
   ScaleHeight     =   7425
   ScaleWidth      =   6870
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox chkDsMixedMode 
      Caption         =   "DS in Mixed Mode"
      Height          =   255
      Left            =   720
      TabIndex        =   17
      Top             =   5640
      Width           =   2655
   End
   Begin VB.TextBox txtForestName 
      BackColor       =   &H8000000F&
      Height          =   315
      Left            =   480
      TabIndex        =   15
      Top             =   1440
      Width           =   3615
   End
   Begin VB.CommandButton cmdExecute 
      Caption         =   "Execute"
      Default         =   -1  'True
      Height          =   375
      Left            =   5280
      TabIndex        =   12
      Top             =   720
      Width           =   1455
   End
   Begin VB.TextBox txtMachineRole 
      BackColor       =   &H8000000F&
      Height          =   315
      Left            =   480
      TabIndex        =   11
      Top             =   3600
      Width           =   3615
   End
   Begin VB.TextBox txtDomainNameFlat 
      BackColor       =   &H8000000F&
      Height          =   315
      Left            =   480
      TabIndex        =   9
      Top             =   2880
      Width           =   3615
   End
   Begin VB.TextBox txtDomainNameDns 
      BackColor       =   &H8000000F&
      Height          =   315
      Left            =   480
      TabIndex        =   7
      Top             =   2160
      Width           =   3615
   End
   Begin VB.Frame Frame1 
      Caption         =   "Results"
      Height          =   6375
      Left            =   240
      TabIndex        =   3
      Top             =   840
      Width           =   4575
      Begin VB.Frame Frame2 
         Caption         =   "Flags"
         Height          =   2055
         Left            =   240
         TabIndex        =   13
         Top             =   4080
         Width           =   3735
         Begin VB.CheckBox chkDsUpgrade 
            Caption         =   "Upgrade in Process"
            Height          =   375
            Left            =   240
            TabIndex        =   19
            Top             =   1440
            Width           =   2415
         End
         Begin VB.CheckBox chkDomainGuid 
            Caption         =   "Domain Guid Present"
            Height          =   255
            Left            =   240
            TabIndex        =   18
            Top             =   1080
            Width           =   2055
         End
         Begin VB.CheckBox chkDsRunning 
            Caption         =   "DS is running"
            Height          =   255
            Left            =   240
            TabIndex        =   16
            Top             =   360
            Width           =   2655
         End
      End
      Begin VB.TextBox txtDomainGuid 
         BackColor       =   &H8000000F&
         Height          =   315
         Left            =   240
         TabIndex        =   5
         Top             =   3480
         Width           =   3615
      End
      Begin VB.Label Label6 
         Caption         =   "Domain Guid"
         Height          =   255
         Left            =   240
         TabIndex        =   14
         Top             =   3240
         Width           =   1215
      End
      Begin VB.Label Label5 
         Caption         =   "Machine Role"
         Height          =   255
         Left            =   240
         TabIndex        =   10
         Top             =   2520
         Width           =   1455
      End
      Begin VB.Label Label4 
         Caption         =   "Domain Flat Name"
         Height          =   255
         Left            =   240
         TabIndex        =   8
         Top             =   1800
         Width           =   1455
      End
      Begin VB.Label Label3 
         Caption         =   "Domain DNS Name"
         Height          =   255
         Left            =   240
         TabIndex        =   6
         Top             =   1080
         Width           =   1455
      End
      Begin VB.Label Label2 
         Caption         =   "Forest Name"
         Height          =   255
         Left            =   240
         TabIndex        =   4
         Top             =   360
         Width           =   1695
      End
   End
   Begin VB.CommandButton cmdOK 
      Caption         =   "Close"
      Height          =   375
      Left            =   5280
      TabIndex        =   2
      Top             =   240
      Width           =   1455
   End
   Begin VB.TextBox txtServerName 
      Height          =   285
      Left            =   1560
      TabIndex        =   0
      Top             =   240
      Width           =   3255
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      Caption         =   "Server Name:"
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   240
      Width           =   1095
   End
End
Attribute VB_Name = "frmDsRole"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Dim x As New ADsLocator

Private Sub cmdExecute_Click()

Dim sServerName As String
Dim role As IADsDsRoleInfo

sServerName = ""
Flags = 0

If txtServerName <> "" Then
  sServerName = txtServerName
End If
Set role = x.DsRoleGetPrimaryDomainInformation(sServerName)



txtForestName = role.DomainForestName
txtDomainNameDns = role.DomainNameDns
txtDomainNameFlat = role.DomainNameFlat
If (role.Flags And ADS_ROLE_PRIMARY_DOMAIN_GUID_PRESENT) Then
    txtDomainGuid = role.DomainGuid
Else
    txtDomainGuid = ""
End If
'--- Machine Role
Select Case role.MachineRole
Case ADS_ROLE_STANDALONE_WORKSTATION
txtMachineRole = "Standalone Workstation"
 Case ADS_ROLE_MEMBER_WORKSTATION
 txtMachineRole = "Member Workstation"
Case ADS_ROLE_STANDALONE_SERVER
txtMachineRole = "Standalone Server"
 Case ADS_ROLE_MEMBER_SERVER
   txtMachineRole = "Member Server"
Case ADS_ROLE_BACKUP_DOMAIN_CONTROLLER
  txtMachineRole = "Backup Domain Controller"
Case ADS_ROLE_PRIMARY_DOMAIN_CONTROLLER
   txtMachineRole = "Primary Domain Controller"
Case Else
    txtMachineRole = "Unknown"

End Select

If (role.Flags And ADS_ROLE_PRIMARY_DS_RUNNING) Then
   chkDsRunning = 1
Else
   chkDsRunning = 0
End If

If (role.Flags And ADS_ROLE_PRIMARY_DS_MIXED_MODE) Then
  chkDsMixedMode = 1
Else
  chkDsMixedMode = 0
End If

If (role.Flags And ADS_ROLE_PRIMARY_DOMAIN_GUID_PRESENT) Then
  chkDomainGuid = 1
Else
   chkDomainGuid = 0
End If
    
    
If (role.Flags And ADS_ROLE_UPGRADE_IN_PROGRESS) Then
  chkDsUpgrade = 1
Else
   chkDsUpgrade = 0
End If


End Sub

Private Sub cmdOK_Click()
  Me.Hide
  
  
End Sub

