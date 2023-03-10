VERSION 5.00
Object = "{35C0E971-CA78-11D2-8114-0080C71B8071}#1.0#0"; "MSEIGFT.dll"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form Form1 
   Caption         =   "DDMIO File Transfer"
   ClientHeight    =   7305
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8040
   LinkTopic       =   "Form1"
   ScaleHeight     =   7305
   ScaleWidth      =   8040
   StartUpPosition =   3  'Windows Default
   Begin VB.OptionButton TCPConnection 
      Caption         =   "TCP/IP"
      Height          =   195
      Left            =   1800
      TabIndex        =   30
      Top             =   600
      Width           =   975
   End
   Begin VB.OptionButton APPCConnection 
      Caption         =   "APPC"
      Height          =   255
      Left            =   720
      TabIndex        =   29
      Top             =   600
      Width           =   855
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   6720
      Top             =   1200
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton BrowseCommand 
      Caption         =   "..."
      Height          =   375
      Left            =   7200
      TabIndex        =   28
      Top             =   3720
      Width           =   495
   End
   Begin VB.CheckBox chkCreate 
      Caption         =   "Create If Non-Existing"
      Height          =   255
      Left            =   240
      TabIndex        =   26
      Top             =   6000
      Width           =   2055
   End
   Begin VB.CheckBox chkAppend 
      Caption         =   "Append to End"
      Height          =   255
      Left            =   2400
      TabIndex        =   25
      Top             =   5640
      Width           =   1815
   End
   Begin VB.CheckBox chkOverwrite 
      Caption         =   "Overwrite Host File"
      Height          =   255
      Left            =   240
      TabIndex        =   24
      Top             =   5640
      Value           =   1  'Checked
      Width           =   1935
   End
   Begin VB.TextBox txLabel4 
      Height          =   285
      Left            =   1920
      TabIndex        =   22
      Text            =   "QPCSUPP"
      Top             =   2760
      Width           =   2295
   End
   Begin VB.TextBox txCodePage 
      Height          =   285
      Left            =   1920
      TabIndex        =   21
      Text            =   "437"
      Top             =   4920
      Width           =   2295
   End
   Begin VB.TextBox txCCSID 
      Height          =   285
      Left            =   1920
      TabIndex        =   20
      Text            =   "37"
      Top             =   4440
      Width           =   2295
   End
   Begin VB.TextBox txPassword 
      Height          =   285
      IMEMode         =   3  'DISABLE
      Left            =   1920
      PasswordChar    =   "*"
      TabIndex        =   19
      Top             =   3840
      Width           =   2295
   End
   Begin VB.TextBox txUserId 
      Height          =   285
      Left            =   1920
      TabIndex        =   18
      Top             =   3360
      Width           =   2295
   End
   Begin VB.TextBox txLabel3 
      Height          =   285
      Left            =   1920
      TabIndex        =   17
      Top             =   2280
      Width           =   2295
   End
   Begin VB.TextBox txLabel2 
      Height          =   285
      Left            =   1920
      TabIndex        =   16
      Top             =   1800
      Width           =   2295
   End
   Begin VB.TextBox txLabel1 
      Height          =   285
      Left            =   1920
      TabIndex        =   7
      Top             =   1290
      Width           =   2295
   End
   Begin VB.TextBox txHostFile 
      Height          =   375
      Left            =   4680
      TabIndex        =   4
      Top             =   4800
      Width           =   2415
   End
   Begin VB.TextBox txLocalFile 
      Height          =   375
      Left            =   4680
      TabIndex        =   3
      Top             =   3720
      Width           =   2415
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Upload"
      Height          =   495
      Left            =   6000
      TabIndex        =   2
      Top             =   5880
      Visible         =   0   'False
      Width           =   1695
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Download"
      Height          =   495
      Left            =   6000
      TabIndex        =   1
      Top             =   5280
      Visible         =   0   'False
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Connect"
      Height          =   495
      Left            =   6120
      TabIndex        =   0
      Top             =   240
      Width           =   1695
   End
   Begin VB.Frame Frame1 
      Caption         =   "Upload Options"
      Height          =   975
      Left            =   120
      TabIndex        =   27
      Top             =   5400
      Width           =   4215
   End
   Begin VB.Frame Frame2 
      Caption         =   "Connection Type"
      Height          =   735
      Left            =   360
      TabIndex        =   31
      Top             =   240
      Width           =   2535
   End
   Begin MSEIGFTLibCtl.EIGFileTransferCtl EIGFileTransferCtl1 
      Left            =   6720
      Top             =   1800
      ConnectionType  =   0
      Overwrite       =   1
      AppendTo        =   0
      Create          =   1
      RDBName         =   ""
      UserID          =   ""
      Password        =   ""
      PCCodePage      =   437
      HostCCSID       =   37
      LocalLU         =   ""
      RemoteLU        =   ""
      ModeName        =   "QPCSUPP"
      NetAddr         =   ""
      NetPort         =   "446"
   End
   Begin VB.Label Label3 
      Alignment       =   1  'Right Justify
      Caption         =   "Remote LU:"
      Height          =   255
      Left            =   240
      TabIndex        =   10
      Top             =   2280
      Width           =   1455
   End
   Begin VB.Label Label2 
      Alignment       =   1  'Right Justify
      Caption         =   "Local LU:"
      Height          =   255
      Left            =   240
      TabIndex        =   9
      Top             =   1800
      Width           =   1455
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      Caption         =   "RDB Name:"
      Height          =   255
      Left            =   240
      TabIndex        =   8
      Top             =   1320
      Width           =   1455
   End
   Begin VB.Label lbMsg 
      Alignment       =   2  'Center
      ForeColor       =   &H000000FF&
      Height          =   255
      Left            =   840
      TabIndex        =   23
      Top             =   6600
      Width           =   4815
   End
   Begin VB.Label Label4 
      Alignment       =   1  'Right Justify
      Caption         =   "Mode:"
      Height          =   255
      Left            =   240
      TabIndex        =   15
      Top             =   2760
      Width           =   1455
   End
   Begin VB.Label Label9 
      Alignment       =   1  'Right Justify
      Caption         =   "Local Code Page:"
      Height          =   255
      Left            =   240
      TabIndex        =   14
      Top             =   4920
      Width           =   1455
   End
   Begin VB.Label Label8 
      Alignment       =   1  'Right Justify
      Caption         =   "Host CCSID:"
      Height          =   255
      Left            =   240
      TabIndex        =   13
      Top             =   4440
      Width           =   1455
   End
   Begin VB.Label Label7 
      Alignment       =   1  'Right Justify
      Caption         =   "Password:"
      Height          =   255
      Left            =   240
      TabIndex        =   12
      Top             =   3840
      Width           =   1455
   End
   Begin VB.Label Label6 
      Alignment       =   1  'Right Justify
      Caption         =   "User ID:"
      Height          =   255
      Left            =   240
      TabIndex        =   11
      Top             =   3360
      Width           =   1455
   End
   Begin VB.Label Label98 
      Caption         =   "Host File Name:"
      Height          =   255
      Left            =   4680
      TabIndex        =   6
      Top             =   4440
      Width           =   1575
   End
   Begin VB.Label Label99 
      Caption         =   "Local File Name:"
      Height          =   255
      Left            =   4680
      TabIndex        =   5
      Top             =   3360
      Width           =   1695
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub BrowseCommand_Click()
    Dim sFile As String

    With CommonDialog1
        .DialogTitle = "Open"
        .CancelError = False
        .Filter = "All Files (*.*)|*.*"
        .ShowOpen
        If Len(.FileName) = 0 Then
            Exit Sub
        End If
        sFile = .FileName
        Me.txLocalFile.Text = Trim(sFile)
    End With

End Sub

Private Sub chkAppend_Click()
    If chkAppend.Value = 1 Then
        EIGFileTransferCtl1.AppendToEnd = eigAnswerYes
    Else
        EIGFileTransferCtl1.AppendToEnd = eigAnswerNo
    End If
    
    If EIGFileTransferCtl1.AppendToEnd = eigAnswerYes Then
        chkAppend.Value = 1
    Else
        chkAppend.Value = 0
    End If
    
    If EIGFileTransferCtl1.CreateIfNonExisting = eigAnswerYes Then
        chkCreate.Value = 1
    Else
        chkCreate.Value = 0
    End If
    
    If EIGFileTransferCtl1.OverwriteHostFile = eigAnswerYes Then
        chkOverwrite.Value = 1
    Else
        chkOverwrite.Value = 0
    End If
End Sub

Private Sub chkCreate_Click()
    If chkCreate.Value = 1 Then
        EIGFileTransferCtl1.CreateIfNonExisting = eigAnswerYes
    Else
        EIGFileTransferCtl1.CreateIfNonExisting = eigAnswerNo
    End If
    
    If EIGFileTransferCtl1.AppendToEnd = eigAnswerYes Then
        chkAppend.Value = 1
    Else
        chkAppend.Value = 0
    End If
    
    If EIGFileTransferCtl1.CreateIfNonExisting = eigAnswerYes Then
        chkCreate.Value = 1
    Else
        chkCreate.Value = 0
    End If
    
    If EIGFileTransferCtl1.OverwriteHostFile = eigAnswerYes Then
        chkOverwrite.Value = 1
    Else
        chkOverwrite.Value = 0
    End If
End Sub

Private Sub chkOverwrite_Click()
    If chkOverwrite.Value = 1 Then
        EIGFileTransferCtl1.OverwriteHostFile = eigAnswerYes
    Else
        EIGFileTransferCtl1.OverwriteHostFile = eigAnswerNo
    End If
    
    If EIGFileTransferCtl1.AppendToEnd = eigAnswerYes Then
        chkAppend.Value = 1
    Else
        chkAppend.Value = 0
    End If
    
    If EIGFileTransferCtl1.CreateIfNonExisting = eigAnswerYes Then
        chkCreate.Value = 1
    Else
        chkCreate.Value = 0
    End If
    
    If EIGFileTransferCtl1.OverwriteHostFile = eigAnswerYes Then
        chkOverwrite.Value = 1
    Else
        chkOverwrite.Value = 0
    End If
  
End Sub

Private Sub Command1_Click()
   lbMsg.Caption = ""
    If EIGFileTransferCtl1.ConnectionState = eigConnStateIdle Then
        If APPCConnection.Value = True Then
            EIGFileTransferCtl1.ConnectionType = eigConnTypeAPPC
            EIGFileTransferCtl1.LocalLU = txLabel2.Text
            EIGFileTransferCtl1.RemoteLU = txLabel3.Text
            EIGFileTransferCtl1.ModeName = txLabel4.Text
        Else
            EIGFileTransferCtl1.ConnectionType = eigConnTypeTCPIP
            EIGFileTransferCtl1.NetAddr = txLabel2.Text
            EIGFileTransferCtl1.NetPort = txLabel3.Text
        End If
        
        EIGFileTransferCtl1.RDBName = txLabel1.Text
            
        Rem EIGFileTransferCtl1.OverwriteHostFile = eigAnswerYes
        Rem EIGFileTransferCtl1.AppendToEnd = eigAnswerNo
        Rem EIGFileTransferCtl1.CreateIfNonExisting = eigAnswerNo
        
        Call Form_Load

        EIGFileTransferCtl1.UserID = txUserId.Text
        EIGFileTransferCtl1.Password = txPassword.Text

        EIGFileTransferCtl1.CCSID = Val(txCCSID.Text)
        EIGFileTransferCtl1.PCCodePage = Val(txCodePage.Text)
 
        
        Call EIGFileTransferCtl1.Connect
    Else
        If EIGFileTransferCtl1.ConnectionState = eigConnStateConnected Then
            Call EIGFileTransferCtl1.Disconnect
        End If
    End If
End Sub

Private Sub Command2_Click()
    Dim MyDir
    MyDir = Dir(txLocalFile.Text)
    
    If MyDir <> "" Then
        Dim Msg, Style, Title, Help, Ctxt, Response, MyString
        Msg = "File Exists, Overwrite?"
        Style = vbYesNo + vbCritical + vbDefaultButton2
        Title = "File Exists"
        Response = MsgBox(Msg, Style, Title)
        If Response = vbNo Then
            Exit Sub
        End If
    End If
        
    Dim bsLocalFile As String
    Dim bsHostFile As String
    
    If glConnState = eigConnStateConnected Then
        bsLocalFile = txLocalFile.Text
        bsHostFile = txHostFile.Text
        Command2.Enabled = False
        Command3.Enabled = False
        lbMsg.Caption = ""
        Call EIGFileTransferCtl1.GetFile(bsLocalFile, bsHostFile)
    End If
End Sub

Private Sub Command3_Click()
    Dim bsLocalFile As String
    Dim bsHostFile As String
    
    If glConnState = eigConnStateConnected Then
        bsLocalFile = txLocalFile.Text
        bsHostFile = txHostFile.Text
        Command2.Enabled = False
        Command3.Enabled = False
        lbMsg.Caption = ""
        Call EIGFileTransferCtl1.PutFile(bsHostFile, bsLocalFile)
    End If
End Sub


Private Sub Form_Load()
    If EIGFileTransferCtl1.OverwriteHostFile = eigAnswerYes Then
        chkOverwrite.Value = 1
    Else
        chkOverwrite.Value = 0
    End If
    If EIGFileTransferCtl1.AppendToEnd = eigAnswerYes Then
        chkAppend.Value = 1
    Else
        chkAppend.Value = 0
    End If
    If EIGFileTransferCtl1.CreateIfNonExisting = eigAnswerYes Then
        chkCreate.Value = 1
    Else
        chkCreate.Value = 0
    End If
    
    txCCSID.Text = EIGFileTransferCtl1.CCSID
    txCodePage.Text = EIGFileTransferCtl1.PCCodePage
    
    Rem now I will show the current configuration information to the user
    Call ShowCommInfo
End Sub

Private Sub EIGFileTransferCtl1_ConnectionStateChange(ByVal constate As MSEIGFTLibCtl.eigConnectionStateEnum)
    glConnState = constate
    If glConnState = eigConnStateConnected Then
        Command1.Caption = "Disconnect"
        Command1.Enabled = True
        Command2.Visible = True
        Command3.Visible = True
        'Changed by Pranav to fix bug#6599 (Dec 20th, 1999)
        Command2.Enabled = True
        Command3.Enabled = True
        
    Else
        Command2.Visible = False
        Command3.Visible = False
        If glConnState = eigConnStateIdle Then
            Command1.Caption = "Connect"
            Command1.Enabled = True
        Else
            Command1.Caption = "Wait a sec..."
            Command1.Enabled = False
        End If
    End If
End Sub

Private Sub EIGFileTransferCtl1_ReportError(ByVal hr As Long, ByVal Text As String)
    lbMsg.Caption = "ERROR (" + Format(hr) + ") " + Text
    Command2.Enabled = True
    Command3.Enabled = True
End Sub

Private Sub EIGFileTransferCtl1_TransferComplete()
    lbMsg.Caption = "File Transfer Complete"
    Command2.Enabled = True
    Command3.Enabled = True
End Sub

Private Sub EIGFileTransferCtl1_TransferProgress(ByVal PercentageDone As Integer)
    lbMsg.Caption = Format(PercentageDone) & "% done"
End Sub

Private Sub TCPConnection_Click()
    Label2.Caption = "Net Address:"
    Label3.Caption = "Port :"
    Label4.Visible = False
    txLabel4.Visible = False
    
    EIGFileTransferCtl1.ConnectionType = eigConnTypeTCPIP
    
    Call ShowCommInfo
    
End Sub

Private Sub APPCConnection_Click()
    Label2.Caption = "Local LU:"
    Label3.Caption = "Remote LU:"
    Label4.Visible = True
    txLabel4.Visible = True
    
    EIGFileTransferCtl1.ConnectionType = eigConnTypeAPPC
    
    Call ShowCommInfo
End Sub


Private Sub ShowCommInfo()
    If EIGFileTransferCtl1.ConnectionType = eigConnTypeAPPC Then
        APPCConnection.Value = True
        TCPConnection.Value = False
        
        txLabel2.Text = EIGFileTransferCtl1.RDBName
        txLabel2.Text = EIGFileTransferCtl1.LocalLU
        txLabel3.Text = EIGFileTransferCtl1.RemoteLU
        txLabel4.Text = EIGFileTransferCtl1.ModeName
    Else
        APPCConnection.Value = False
        TCPConnection.Value = True
        
        txLabel2.Text = EIGFileTransferCtl1.RDBName
        txLabel2.Text = EIGFileTransferCtl1.NetAddr
        txLabel3.Text = EIGFileTransferCtl1.NetPort
    End If
End Sub

