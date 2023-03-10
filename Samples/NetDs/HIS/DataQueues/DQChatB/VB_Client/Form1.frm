VERSION 5.00
Begin VB.Form MainForm 
   Caption         =   "Microsoft Host Integration Server 2000 AS/400 Data Queue Talk Demonstration"
   ClientHeight    =   9570
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   12030
   LinkTopic       =   "Form1"
   ScaleHeight     =   9570
   ScaleWidth      =   12030
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox txtLib 
      Height          =   375
      Left            =   1680
      TabIndex        =   40
      ToolTipText     =   "Enter the AS/400 library name to create the Data Queue in.  Must exist on AS/400."
      Top             =   1800
      Width           =   1815
   End
   Begin VB.Frame frmQReadOpt 
      Caption         =   "Data Queue Read Options"
      Height          =   1095
      Left            =   240
      TabIndex        =   36
      Top             =   8280
      Width           =   3615
      Begin VB.OptionButton optAsyncRcv 
         Caption         =   "Asynchronous/Event Notify"
         Height          =   255
         Left            =   240
         TabIndex        =   39
         ToolTipText     =   $"Form1.frx":0000
         Top             =   720
         Width           =   3015
      End
      Begin VB.OptionButton optPollRcv 
         Caption         =   "Poll Queue via Timer Event"
         Height          =   195
         Left            =   240
         TabIndex        =   38
         ToolTipText     =   "This will enable the timer event to poll the queue for new messages. "
         Top             =   480
         Width           =   3135
      End
      Begin VB.OptionButton optSyncRcv 
         Caption         =   "Synchronous Read via Receive Button"
         Height          =   255
         Left            =   240
         TabIndex        =   37
         ToolTipText     =   "Read messages ""manually"" off of the queue via Receive Button."
         Top             =   240
         Width           =   3255
      End
   End
   Begin VB.Frame frmTraceDebug 
      Caption         =   "Trace Debug Options"
      Height          =   975
      Left            =   240
      TabIndex        =   28
      Top             =   7200
      Width           =   3615
      Begin VB.OptionButton optNone 
         Caption         =   "None"
         Height          =   195
         Left            =   240
         TabIndex        =   35
         ToolTipText     =   "Do not display any program trace information"
         Top             =   720
         Width           =   1815
      End
      Begin VB.OptionButton optTrace 
         Caption         =   "Trace Messages"
         Height          =   195
         Left            =   240
         TabIndex        =   30
         ToolTipText     =   "Trace program progress in the Received Messages text window."
         Top             =   480
         Width           =   1695
      End
      Begin VB.OptionButton optMsgBox 
         Caption         =   "Message Boxes"
         Height          =   255
         Left            =   240
         TabIndex        =   29
         ToolTipText     =   "Prompt user with message boxes during course of program execution"
         Top             =   240
         Width           =   1575
      End
   End
   Begin VB.CommandButton cmdStopPoll 
      Caption         =   "Stop Poll"
      Height          =   375
      Left            =   6480
      TabIndex        =   27
      ToolTipText     =   "Disable timer event based polling of the queue"
      Top             =   7320
      Width           =   1335
   End
   Begin VB.Timer Timer1 
      Left            =   4080
      Top             =   360
   End
   Begin VB.CommandButton cmdExit 
      Caption         =   "Exit"
      Height          =   375
      Left            =   8520
      TabIndex        =   13
      ToolTipText     =   "Exit the Program"
      Top             =   8880
      Width           =   1215
   End
   Begin VB.CommandButton cmdClearStxt 
      Caption         =   "Clear"
      Height          =   375
      Left            =   7200
      TabIndex        =   12
      ToolTipText     =   "Clear all text in the send box"
      Top             =   8880
      Width           =   1335
   End
   Begin VB.CommandButton cmdDisconnect 
      Caption         =   "Disconnect"
      Height          =   375
      Left            =   480
      TabIndex        =   8
      ToolTipText     =   "Disconnect from the AS/400"
      Top             =   6000
      Width           =   1335
   End
   Begin VB.TextBox txtSnd 
      Height          =   495
      Left            =   5040
      ScrollBars      =   3  'Both
      TabIndex        =   7
      Top             =   8160
      Width           =   5775
   End
   Begin VB.CommandButton cmdConnect 
      Caption         =   "Connect"
      Height          =   375
      Left            =   480
      TabIndex        =   6
      ToolTipText     =   "Connect to the AS/400 System and its respective data queues"
      Top             =   5520
      Width           =   1335
   End
   Begin VB.TextBox txtRcv 
      Height          =   6015
      Left            =   5040
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   5
      ToolTipText     =   "Messages received from the AS/400 and if enabled, trace messages"
      Top             =   960
      Width           =   5775
   End
   Begin VB.TextBox txtScreenName 
      Height          =   375
      Left            =   1680
      TabIndex        =   4
      ToolTipText     =   "Enter the screen name you want to be identified under."
      Top             =   4200
      Width           =   1815
   End
   Begin VB.TextBox txtRemoteLU 
      Height          =   375
      Left            =   1680
      TabIndex        =   3
      ToolTipText     =   "Enter the SNA Name of the remote AS/400"
      Top             =   3600
      Width           =   1815
   End
   Begin VB.TextBox txtQFromHost 
      Height          =   375
      Left            =   1680
      TabIndex        =   2
      Text            =   "DQFIFOSND"
      ToolTipText     =   "This is the AS/400 Receive Queue name, relative to the AS/400"
      Top             =   2400
      Width           =   1815
   End
   Begin VB.TextBox txtPass 
      Height          =   375
      Left            =   1680
      TabIndex        =   1
      ToolTipText     =   "Enter the AS/400 Library that the queues reside in"
      Top             =   1200
      Width           =   1815
   End
   Begin VB.TextBox txtUser 
      Height          =   375
      Left            =   1680
      TabIndex        =   0
      ToolTipText     =   "Enter your AS/400 Username"
      Top             =   600
      Width           =   1815
   End
   Begin VB.Frame frmReceiveFromAS400 
      Caption         =   "Receive from AS/400"
      Height          =   6375
      Left            =   4920
      TabIndex        =   9
      Top             =   720
      Width           =   6015
   End
   Begin VB.Frame frmSendtoAS400 
      Caption         =   "Send to AS/400"
      Height          =   855
      Left            =   4920
      TabIndex        =   10
      Top             =   7920
      Width           =   6015
   End
   Begin VB.Frame frmConnectionCntrl 
      Caption         =   "AS/400 Connection"
      Height          =   1335
      Left            =   360
      TabIndex        =   11
      Top             =   5160
      Width           =   1695
   End
   Begin VB.Frame frmConfiguration 
      Caption         =   "Configuration"
      Height          =   6735
      Left            =   240
      TabIndex        =   14
      Top             =   240
      Width           =   3615
      Begin VB.Frame frmQCtrl 
         Caption         =   "Queue Control"
         Height          =   1335
         Left            =   1800
         TabIndex        =   31
         Top             =   4920
         Width           =   1695
         Begin VB.CommandButton cmdDelete 
            Caption         =   "Delete"
            Height          =   375
            Left            =   120
            TabIndex        =   33
            ToolTipText     =   "Delete the specified queues from the AS/400"
            Top             =   840
            Width           =   1455
         End
         Begin VB.CommandButton cmdCreate 
            Caption         =   "Create"
            Height          =   375
            Left            =   120
            TabIndex        =   32
            ToolTipText     =   "Create the specified queues on the AS/400"
            Top             =   360
            Width           =   1455
         End
      End
      Begin VB.TextBox txtQToHost 
         Height          =   375
         Left            =   1440
         TabIndex        =   23
         Text            =   "DQFIFORCV"
         ToolTipText     =   "This is the AS/400 Send Queue Name, Relative to the AS/400"
         Top             =   2760
         Width           =   1815
      End
      Begin VB.Label lblQtoHost 
         Caption         =   "Q To Host"
         Height          =   255
         Index           =   1
         Left            =   120
         TabIndex        =   22
         Top             =   2760
         Width           =   1215
      End
      Begin VB.Label lblQfrmHost 
         Caption         =   "Q From Host"
         Height          =   255
         Index           =   0
         Left            =   120
         TabIndex        =   21
         Top             =   2160
         Width           =   1215
      End
      Begin VB.Label lblLib 
         Caption         =   "Library"
         Height          =   255
         Left            =   120
         TabIndex        =   20
         Top             =   1560
         Width           =   1215
      End
      Begin VB.Label lblUser 
         Caption         =   "User Name"
         Height          =   255
         Left            =   120
         TabIndex        =   19
         Top             =   360
         Width           =   1215
      End
      Begin VB.Label lblPass 
         Caption         =   "Password"
         Height          =   255
         Left            =   120
         TabIndex        =   18
         Top             =   960
         Width           =   1215
      End
      Begin VB.Label lblRemoteLU 
         Caption         =   "RemoteLU"
         Height          =   255
         Left            =   120
         TabIndex        =   17
         Top             =   3360
         Width           =   1215
      End
      Begin VB.Label lblScreenName 
         Caption         =   "Screen Name"
         Height          =   255
         Left            =   120
         TabIndex        =   16
         Top             =   3960
         Width           =   1215
      End
   End
   Begin VB.Frame frmCommunications 
      Caption         =   "Communications"
      Height          =   9135
      Left            =   4680
      TabIndex        =   15
      Top             =   240
      Width           =   6615
      Begin VB.CommandButton cmdClearRtxt 
         Caption         =   "Clear Text"
         Height          =   375
         Left            =   3120
         TabIndex        =   34
         ToolTipText     =   "Clear all messages in the window"
         Top             =   7080
         Width           =   1335
      End
      Begin VB.CommandButton cmdReceive 
         Caption         =   "Receieve"
         Height          =   375
         Left            =   480
         TabIndex        =   26
         ToolTipText     =   "Read a message, if any, off of the queue, timeout after 5 seconds."
         Top             =   7080
         Width           =   1335
      End
      Begin VB.CommandButton cmdSendTxt 
         Caption         =   "Send"
         Height          =   375
         Left            =   1200
         TabIndex        =   25
         ToolTipText     =   "Press Send to send a Message to the AS/400 Queue"
         Top             =   8640
         Width           =   1335
      End
      Begin VB.CommandButton cmdClearTxtQ 
         Caption         =   "Clear All"
         Height          =   375
         Left            =   4440
         TabIndex        =   24
         ToolTipText     =   "Clear all messages in the window and clears out the queue"
         Top             =   7080
         Width           =   1215
      End
   End
End
Attribute VB_Name = "MainForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
'
'   Program:    DQCHAT
'   Author:     Nick Yannios
'   Date:       6/27/2000
'   Description:
'
'   Copyright (c) Microsoft Corporation.  All rights reserved.
'
'   This program demonstrates the HIS 2000 AS/400 Data Queues ActiveX Control Interface.
'   It allows the user to converse with another user on the AS/400 running
'   the DQChat CL program that is provided with this sample.
'
'   Both programs communicate via two AS/400 FIFO Data Queues that are created
'   either via this program or via the CL programs included with this sample.
'
'   To use, set up the CL programs on your AS/400.  Create the Queues either with
'   the supplied CL program or via the Create Queue command in the program.
'   To converse with the AS/400 user, the AS/400 user must run the DQTALK
'   CL program by issuing a "CALL DQTALK" command.
'
Dim WithEvents Q_DQCtrl As EIGDataQueueCtl      ' Queue Control for connecting to AS/400
Attribute Q_DQCtrl.VB_VarHelpID = -1
Dim WithEvents Q_DQueue As EIGDataQueue         ' Queue to the AS/400
Attribute Q_DQueue.VB_VarHelpID = -1
Dim WithEvents Q_DQueueFromHost As EIGDataQueue ' Queue from the AS/400
Attribute Q_DQueueFromHost.VB_VarHelpID = -1
Dim Q_DQItem As EIGDataQueueItem                ' Queue Item to Send to AS/400
Dim Q_DQItemFromHost As EIGDataQueueItem        ' Queue Item to Receive from AS/400
Dim state_DTAQReadMode As DTAQReadMode          ' Queue Item Read Mode
Dim state_DTAQConnState As DTAQConnState        ' Data Queue Connection State
'
'   Enumeration: DTAQReadMode
'   Description: Read AS/400 Data one of three ways
'
Public Enum DTAQReadMode
   DTAQSynch = 0            ' Blocking GetQueueItem Read Request
   DTAQPolled = 1           ' Poll Queue at regular interval for new messages
   DTAQAsync = 2                ' Post non-blocking Read Request, notify via event
End Enum                    '   when a Queue Item is present 
'
'   Enumeration: Connected State
'
Public Enum DTAQConnState
    DTAQCS_Idle = 0         ' Connection is not Available for use
    DTAQCS_Connecting = 1   ' Connection in progress
    DTAQCS_Connected = 2    ' Connection is usable
    DTAQCS_Disconnecting = 3 ' Disconnecting, not usable
    DTAQCS_Unspecified = 4  ' Undefined State
End Enum
'
'   Clear Received Text box
'
Private Sub cmdClearRTxt_Click()
    txtRcv.Text = ""
End Sub
'
'   Send a request to the AS/400
'   Prefix text to be sent with user's specified "screen name"
'
Private Sub cmdSendTxt_Click()
    If Len(txtSnd.Text) > 0 Then
        With Q_DQItem
            .ExtJobName = txtScreenName.Text
            .QItemType = eigQItem
            .Record = txtScreenName.Text & ": " & txtSnd.Text
            .ReplyRequested = eigAnswerNo
        End With
    Else
        MsgBox "Please Enter Message to Send to AS/400"
        Exit Sub
    End If
    ' Queue a Request
    Call Q_DQueue.AddQueueItem(Q_DQItem, eigAnswerNo)
End Sub

Private Sub cmdDelete_Click()
    On Error GoTo cmdDelete_error
    Q_DQueue.DeleteQueue
    Q_DQueueFromHost.DeleteQueue
    Exit Sub
cmdDelete_error:
    MsgBox "Queue Deletion Failed - " & Str(Err.Number) & Err.Description
End Sub
'
'   Disconnect network connection from the AS/400
'
Private Sub cmdDisconnect_Click()
    If optMsgBox.Enabled Then
        dbg "Disconnecting"
    End If
    Q_DQCtrl.Disconnect
End Sub
'
'   Clear Input Field
'
Private Sub cmdClearStxt_Click()
    txtSnd.Text = ""
End Sub
'
'   Exit Program
'
Private Sub cmdExit_Click()
    End
End Sub
'
'   Clear Queue, Received Text and Disable Timer Event
'
Private Sub cmdClearTxtQ_Click()
    Timer1.Enabled = False
    txtRcv.Text = ""
    Q_DQueueFromHost.ClearAll
    Q_DQueue.ClearAll
End Sub
'
'   Issue a GetItem Request from the AS/400
'
Private Sub cmdReceive_Click()
        ReadQueue
End Sub
'
'   Disable Timer Event
'
Private Sub cmdStopPoll_Click()
    Timer1.Enabled = False
    optSyncRcv.Value = True
    optAsyncRcv.Value = False
End Sub
'
'   Create The Queues Specified in Configuration Frame
'
Private Sub cmdCreate_Click()
    On Error GoTo cmdCreate_error
    If txtQFromHost.Text = "" Then
        MsgBox "Enter a valid Queue Name to Create for OUTBOUND Messages from the AS/400"
        Exit Sub
    End If
    If txtQToHost.Text = "" Then
        MsgBox "Enter a valid Queue name to Create for INBOUND Messages to the AS/400"
        Exit Sub
    End If
    Q_DQueue.CreateQueue 80, eigQAuthAll, eigQClassFIFO, eigAnswerYes, Q_DQCtrl.CCSID, 0, False, eigRecordLenFixed, txtQToHost.Text, eigAnswerNo, 0
    Q_DQueueFromHost.CreateQueue 80, eigQAuthAll, eigQClassFIFO, eigAnswerYes, Q_DQCtrl.CCSID, 255, False, eigRecordLenFixed, txtQFromHost.Text, eigAnswerNo, 0
    Exit Sub
cmdCreate_error:
    MsgBox "Queue Creation Failure - " & Str(Err.Number) & Err.Description
End Sub
'
'   Initialize elements on form load
'
Private Sub Form_Load()
    Set Q_DQItem = New EIGDataQueueItem
    Display "Initializing DQCHAT"
    '
    ' Initialize AS/400 Data Queue Objects
    '
    Set Q_DQCtrl = New EIGDataQueueCtl              ' Queue Control for container and connections
    Set Q_DQItem = New EIGDataQueueItem             ' Item to be placed/read from the queue
    Set Q_DQItemFromHost = New EIGDataQueueItem     ' Item from host
    '
    ' Initialize timer event firing interval
    '
    dbg "Initializing Timer..."
    Timer1.Interval = 1000   ' Set Timer interval (1 sec).
    Timer1.Enabled = False   ' wait for user to enable it
    optNone.Value = True     ' Default to no trace messages
    optSyncRcv.Value = True     ' Default to GetQueueItem manually requested by user
    txtPass.PasswordChar = "*"
    '
    ' Disable the commands to allow using the queues until we're connected.
    '
    ConnectedOptions (False)
 End Sub
'
'   Connect to AS/400 and create the send and receive queues specified.
'
Private Sub cmdConnect_Click()
    Dim rc As Integer
    Dim title As String
    Dim library As String
    Dim queuename As String
    Dim queue As String
    On Error GoTo Connect_error
    '
    ' Connect to the AS/400
    '
    dbg "Connecting..."
    If Not ConnectToAS400 Then
        Exit Sub
    End If
    dbg "Connected to host"
    '
    ' Create the Queue to the host
    '
    If Not CreateQContainers Then
        Exit Sub
    End If
    DisplayQueueAttributes Q_DQueue
    DisplayQueueAttributes Q_DQueueFromHost
    '
    ' Construct a Request to the Queue indicating we're connected
    '
    With Q_DQItem
        .ExtJobName = txtScreenName
        .QItemType = eigQItem
        .Record = txtScreenName.Text & "  Connected"
        .ReplyRequested = eigAnswerNo
    End With
    '
    ' Queue the Request indicating that we're connected
    '
    Call Q_DQueue.AddQueueItem(Q_DQItem, eigAnswerNo)
    Exit Sub
Connect_error:
    MsgBox "error - " & Str(Err.Number) & Err.Description
End Sub

' enable sync read only

Private Sub optSyncRcv_Click()
    state_DTAQReadMode = DTAQSynch
    Timer1.Enabled = False
    cmdStopPoll.Enabled = False
End Sub

' enable polled read only

Private Sub optPollRcv_click()
    state_DTAQReadMode = DTAQPolled
    Timer1.Enabled = True
    cmdStopPoll.Enabled = True
End Sub

' enable asynch read only

Private Sub optAsyncRcv_Click()
    state_DTAQReadMode = DTAQAsync
    cmdStopPoll.Enabled = False
    Timer1.Enabled = False
    '
    ' post async I/O here
    '
    Set Q_DQItemFromHost = Q_DQueueFromHost.GetQueueItem(eigQItem, _
                            eigAnswerNo, eigAnswerNo, eigAnswerNo, _
                            0, eigAnswerNo, eigAnswerNo, Nothing, _
                            0)
    MsgBox "Note: This feature will be available in a later version"
End Sub

' connection state event

Private Sub Q_DQCtrl_ConnectionStateChange(ByVal constate As DATAQUEUELib.eigConnectionStateEnum)
    Dim state As String
    Select Case constate
        Case eigConnStateIdle
            state = "Idle"
            state_DTAQConnState = DTAQCS_Idle
        Case eigConnStateConnecting
            state = "Connecting"
            state_DTAQConnState = DTAQCS_Connecting
        Case eigConnStateConnected
            state = "Connected"
            state_DTAQConnState = DTAQCS_Connected
            ConnectedOptions (True)
        Case eigConnStateDisconnecting
            state = "Disconnecting"
            state_DTAQConnState = DTAQCS_Disconnecting
            ConnectedOptions (False)
        Case eigConnStateUnspecified
            state = "Unspecified"
            state_DTAQConnState = DTAQCS_Unspecified
    End Select
    dbg "Queue Control Event: Connection State Change - " + state
End Sub

Private Sub Q_DQCtrl_ReportError(ByVal hr As Long, ByVal Text As String)
    MsgBox "Queue Control Event: Error Event - " + Text
End Sub

Private Sub Q_DQueue_ReportError(ByVal hr As Long, ByVal Text As String)
    MsgBox "Queue: Error Event - " + Text
End Sub

Private Sub Q_DQueue_RequestReceived(ByVal QItemAvilable As DATAQUEUELib.eigQItemTypeEnum)
    dbg "Queue: Message Recived"
    ' Read Message from AS/400 Queue
    Set Q_DQItem = Q_DQueue.GetQueueItem(eigQItem, eigAnswerYes, eigAnswerNo, eigAnswerNo, 0, eigAnswerNo, eigAnswerNo, 0, eigSearchKeyUnspecified)
    dbg "Message Received"
    dbg Q_DQItem.ExtUser & Q_DQItem.Record
    Set Q_DQItem = Q_DQueue.GetQueueItem(eigQItem, eigAnswerNo, eigAnswerNo, eigAnswerNo, 0, eigAnswerNo, eigAnswerNo, 0, eigSearchKeyUnspecified)
End Sub
'
' Send Request Completed
'
Private Sub Q_DQueue_SendComplete(ByVal ErrorCode As Long, ByVal Text As String, ByVal QueueItem As DATAQUEUELib.eigQItemTypeEnum)
    dbg "Queue: Send Completed - " + Text
End Sub
'
' Display text in receive window
'
Public Sub Display(MyString As String)
    Dim temp As String
    temp = txtRcv.Text
    temp = temp + MyString + Chr$(13) + Chr$(10)
    txtRcv.Text = temp
End Sub
'
' Data Received Event - When an Asynchronous GetQueueItem request has been posted
' this routine will be called when there is data available.  It requires an outstanding
' request.  When notified, call the GetQueueItem to get the queue item and then post
' another outstanding async GetQueueItem request in order to queue up a request to
' receive the next message if any.
'
' Note: As of this writing, this feature has been deferred to later version HIS 2000
'
Private Sub Q_DQueueFromHost_RequestReceived(ByVal QItemAvilable As DATAQUEUELib.eigQItemTypeEnum)
    dbg "ASYNC Notification of Message Recived"
    ' Read Message from AS/400 Queue
    Set Q_DQItemFromHost = Q_DQueueFromHost.GetQueueItem(eigQItem, eigAnswerYes, eigAnswerNo, eigAnswerNo, 0, eigAnswerNo, eigAnswerNo, 0, eigSearchKeyUnspecified)
    dbg "Message Received"
    dbg Q_DQItemFromHost.ExtUser & Q_DQItemFromHost.Record
    Set Q_DQItemFromHost = Q_DQueueFromHost.GetQueueItem(eigQItem, eigAnswerYes, eigAnswerYes, eigAnswerNo, 10, eigAnswerYes, eigAnswerYes, Nothing, 0)
End Sub
'
' Timer Event - Read Message(s), if any from the queue
' When selected, fires every sec and checks queue for presence of queue items
'
Private Sub Timer1_Timer()
    ' Read Message from AS/400 Queue
    If optTrace.Value Then
        Display "TRC: Timer"
    End If
    ReadQueue
End Sub
'
' Read Messages from the Queue
'
Private Sub ReadQueue()
    Dim strMessageFromHost As Variant
    Dim strAsciiFromHost As String
    Dim intRecordCount As Integer
    Dim intLength As Integer
    '
    ' Get an Item from the queue
    '
    Set Q_DQItemFromHost = Q_DQueueFromHost.GetQueueItem(eigQItem, eigAnswerYes, _
                   eigAnswerNo, eigAnswerYes, 0, eigAnswerYes, eigAnswerYes, _
                   Nothing, 0)
    strMessageFromHost = Q_DQItemFromHost.Record
    intLength = Q_DQItemFromHost.RecLength
    '
    ' Display details of message if trace options enabled.
    '
    If (optMsgBox.Value = True) Or (optTrace.Value = True) Then
        DumpRecord Q_DQItemFromHost
    End If
    '
    ' Display Message Received including username/terminal
    '
    If (Q_DQItemFromHost.RecLength > 0) Then
        strAsciiFromHost = Translate(Q_DQItemFromHost.Record, EBCDIC_To_ASCII_Table(), intLength)
        Display Trim$(Q_DQItemFromHost.ExtUser) & "/" & Trim$(Q_DQItemFromHost.ExtJobName) & ": " & strAsciiFromHost
    End If
End Sub
'
' For Debugging EBCDIC->ASCII Translation
'
Private Sub DumpRecord(Q_Item As EIGDataQueueItem)
    Dim i As Integer
    Dim intLength As Integer
    Dim intRecordCount As Integer
    intLength = Q_Item.RecLength
    intRecordCount = Q_Item.RecCount
    Display "Received Length: " & intLength
    Display "Record Count: " & intRecordCount
    Display "ExtJobName:" + Q_Item.ExtJobName
    Display "ExtJobNumber:" + Q_Item.ExtJobNumber
    Display "ExtUser:" + Q_Item.ExtUser
    Display "Dumping Record Contents"
    For i = 0 To intLength - 1
        Display "- " & Str(i) & " - " & " 0x" & Hex(Q_Item.Record(i)) & " - " & Asc(Q_Item.Record(i))
    Next i
End Sub
'
' EBCDIC->ASCII | ASCII->EBCDIC Translation Function
'
Function Translate(ByVal intext As Variant, xlatTable As String, intLen As Integer) As String
'
' Uses a translation table to map InText from one character set to another.
' (Adapted from KB Article Q216399)
'
Dim temp As String, i As Long
temp = Space$(intLen)
  For i = 0 To intLen - 1
    Mid$(temp, i + 1, 1) = Mid$(xlatTable, intext(i) + 1)
    Next i
  Translate = temp
End Function

Function ASCII_To_EBCDIC_Table() As String
'
' Returns the following table as a string for use by the Translate
' function to translate an EBCDIC string to an ASCII-ISO/ANSI string.
'
' 00 01 02 03 37 2D 2E 2F 16 05 25 0B 0C 0D 0E 0F
' 10 11 12 13 3C 3D 32 26 18 19 3F 27 1C 1D 1E 1F
' 40 5A 7F 7B 5B 6C 50 7D 4D 5D 5C 4E 6B 60 4B 61
' F0 F1 F2 F3 F4 F5 F6 F7 F8 F9 7A 5E 4C 7E 6E 6F
' 7C C1 C2 C3 C4 C5 C6 C7 C8 C9 D1 D2 D3 D4 D5 D6
' D7 D8 D9 E2 E3 E4 E5 E6 E7 E8 E9 AD E0 BD 5F 6D
' 79 81 82 83 84 85 86 87 88 89 91 92 93 94 95 96
' 97 98 99 A2 A3 A4 A5 A6 A7 A8 A9 C0 4F D0 A1 07
' 20 21 22 23 24 15 06 17 28 29 2A 2B 2C 09 0A 1B
' 30 31 1A 33 34 35 36 08 38 39 3A 3B 04 14 3E E1
' 41 42 43 44 45 46 47 48 49 51 52 53 54 55 56 57
' 58 59 62 63 64 65 66 67 68 69 70 71 72 73 74 75
' 76 77 78 80 8A 8B 8C 8D 8E 8F 90 9A 9B 9C 9D 9E
' 9F A0 AA AB AC 4A AE AF B0 B1 B2 B3 B4 B5 B6 B7
' B8 B9 BA BB BC 6A BE BF CA CB CC CD CE CF DA dB
' DC DD DE DF EA EB EC ED EE EF FA FB FC FD FE FF
'
  ASCII_To_EBCDIC_Table = _
  HexToStr("00010203372D2E2F1605250B0C0D0E0F101112133C3D322618193F271C1D1E1F") & _
  HexToStr("405A7F7B5B6C507D4D5D5C4E6B604B61F0F1F2F3F4F5F6F7F8F97A5E4C7E6E6F") & _
  HexToStr("7CC1C2C3C4C5C6C7C8C9D1D2D3D4D5D6D7D8D9E2E3E4E5E6E7E8E9ADE0BD5F6D") & _
  HexToStr("79818283848586878889919293949596979899A2A3A4A5A6A7A8A9C04FD0A107") & _
  HexToStr("202122232415061728292A2B2C090A1B30311A333435360838393A3B04143EE1") & _
  HexToStr("4142434445464748495152535455565758596263646566676869707172737475") & _
  HexToStr("767778808A8B8C8D8E8F909A9B9C9D9E9FA0AAABAC4AAEAFB0B1B2B3B4B5B6B7") & _
  HexToStr("B8B9BABBBC6ABEBFCACBCCCDCECFDADBDCDDDEDFEAEBECEDEEEFFAFBFCFDFEFF")
End Function

Function EBCDIC_To_ASCII_Table() As String
'
' Returns the following table as a string for use by the Translate
' function to traslate an EBCDIC string to an ASCII-ISO/ANSI string.
'
' 00 01 02 03 9C 09 86 7F 97 8D 8E 0B 0C 0D 0E 0F    ....ú.Üóçé.....
' 10 11 12 13 9D 85 08 87 18 19 92 8F 1C 1D 1E 1F    ....ùÖ.á..íè....
' 80 81 82 83 84 0A 17 1B 88 89 8A 8B 8C 05 06 07    ÄÅÇÉÑ...àâäãå...
' 90 91 16 93 94 95 96 04 98 99 9A 9B 14 15 9E 1A    êë.ìîïñ.òôöõ..û.
' 20 A0 A1 A2 A3 A4 A5 A6 A7 A8 D5 2E 3C 28 2B 7C    . °¢£§•¶ß...<(+|
' 26 A9 AA AB AC AD AE AF B0 B1 21 24 2A 29 3B 5E    &©™´¨≠ÆØ∞±!$*);^
' 2D 2F B2 B3 B4 B5 B6 B7 B8 B9 E5 2C 25 5F 3E 3F    -/≤≥¥µ∂∑∏π.,%_>?
' BA BB BC BD BE BF C0 C1 C2 60 3A 23 40 27 3D 22    ∫ªºΩæø...`:#@'="
' C3 61 62 63 64 65 66 67 68 69 C4 C5 C6 C7 C8 C9    .abcdefghi......
' CA 6A 6B 6C 6D 6E 6F 70 71 72 CB CC CD CE CF D0    .jklmnopqr......
' D1 7E 73 74 75 76 77 78 79 7A D2 D3 D4 5B D6 D7    .~stuvwxyz...[..
' D8 D9 DA DB DC DD DE DF E0 E1 E2 E3 E4 5D E6 E7    .............]..
' 7B 41 42 43 44 45 46 47 48 49 E8 E9 EA EB EC ED    {ABCDEFGHI......
' 7D 4A 4B 4C 4D 4E 4F 50 51 52 EE EF F0 F1 F2 F3    }JKLMNOPQR......
' 5C 9F 53 54 55 56 57 58 59 5A F4 F5 F6 F7 F8 F9    \.STUVWXYZ......
' 30 31 32 33 34 35 36 37 38 39 FA FB FC FD FE FF    0123456789......
'
  EBCDIC_To_ASCII_Table = _
  HexToStr("000102039C09867F978D8E0B0C0D0E0F101112139D8508871819928F1C1D1E1F") & _
  HexToStr("80818283840A171B88898A8B8C050607909116939495960498999A9B14159E1A") & _
  HexToStr("20A0A1A2A3A4A5A6A7A8D52E3C282B7C26A9AAABACADAEAFB0B121242A293B5E") & _
  HexToStr("2D2FB2B3B4B5B6B7B8B9E52C255F3E3FBABBBCBDBEBFC0C1C2603A2340273D22") & _
  HexToStr("C3616263646566676869C4C5C6C7C8C9CA6A6B6C6D6E6F707172CBCCCDCECFD0") & _
  HexToStr("D17E737475767778797AD2D3D45BD6D7D8D9DADBDCDDDEDFE0E1E2E3E45DE6E7") & _
  HexToStr("7B414243444546474849E8E9EAEBECED7D4A4B4C4D4E4F505152EEEFF0F1F2F3") & _
  HexToStr("5C9F535455565758595AF4F5F6F7F8F930313233343536373839FAFBFCFDFEFF")
End Function
'
' Generate Hexidecimal String sequence for Conversion
'
Function HexToStr(ByVal HexStr As String) As String
Dim temp As String, i As Long
  temp = Space$(Len(HexStr) \ 2)
  For i = 1 To Len(HexStr) \ 2
    Mid$(temp, i, 1) = Chr$(Val("&H" & Mid$(HexStr, i * 2 - 1, 2)))
  Next i
  HexToStr = temp
End Function
'
'   Display and/or print debug messages if user enables via option
'
Private Sub dbg(msg As String)
    If optNone.Value Then
        Exit Sub
    End If
    If optMsgBox.Value Then
        MsgBox msg
    End If
    If optTrace.Value Then
        Display "TRC: " & msg
    End If
End Sub
'
'   Depending on the status of the connection to the AS/400, enable/disable
'   these functions for the user.
'
Private Sub ConnectedOptions(fConnected As Boolean)
    '
    ' Enable the all of the following if connected
    '
    If fConnected Then
    
        cmdDisconnect.Enabled = True    ' Can disconnect
        cmdCreate.Enabled = True    ' Can Create a queue
        cmdDelete.Enabled = True   ' Can Delete
        optMsgBox.Enabled = True
        optTrace.Enabled = True
        optNone.Enabled = True
        optSyncRcv.Enabled = True
        optPollRcv.Enabled = True
        optAsyncRcv.Enabled = True
        cmdSendTxt.Enabled = True
        cmdClearStxt.Enabled = True
        cmdClearTxtQ.Enabled = True
        cmdReceive.Enabled = True
        cmdStopPoll.Enabled = False
        cmdClearRtxt.Enabled = True
    Else
        cmdDisconnect.Enabled = False    ' Can't disconnect, not connected
        cmdCreate.Enabled = False    ' Can't Create a queue yet
        cmdDelete.Enabled = False   ' Can't Delete, nothing to delete yet
        optMsgBox.Enabled = True
        optTrace.Enabled = True
        optNone.Enabled = True
        optSyncRcv.Enabled = False
        optPollRcv.Enabled = False
        optAsyncRcv.Enabled = False
        cmdSendTxt.Enabled = False
        cmdClearStxt.Enabled = False
        cmdClearTxtQ.Enabled = False
        cmdReceive.Enabled = False
        cmdStopPoll.Enabled = False
        cmdClearRtxt.Enabled = False
    End If
End Sub
'
' DisplayQueueAttributes displays the various attributes of the queue
' eigAttributeCCSID: Character Set ID
' eigAttributeMaxMsgLen: Maximum message size for queue
' eigAttributeTitle: Title of Queue
' eigAttributeQueueCls: Class of Queue: FIFO, FILO or Keyed.
'
Private Sub DisplayQueueAttributes(Q As EIGDataQueue)
    Dim rc As Integer
    Dim title As String
    dbg Q.queuename
    rc = Q.QueryAttribute(eigAttributeCCSID)
    dbg "CCSID:" + Str(rc)
    rc = Q.QueryAttribute(eigAttributeMaxMsgLen)
    dbg "Max Msg Len:" + Str(rc)
    title = Q.QueryAttribute(eigAttributeTitle)
    dbg "Title:" + title
    rc = Q.QueryAttribute(eigAttributeQueCls)
    dbg "Queue Class:" + Str(rc)
End Sub
'
'   ConnectToAS400 validates fields and
'   Connects to the AS/400 if everything is specified
'
Private Function ConnectToAS400() As Boolean
    If (state_DTAQConnState = DTAQCS_Connected) Or (state_DTAQConnState = DTAQCS_Connecting) _
        Or (state_DTAQConnState = DTAQCS_Disconnecting) Then
        dbg "Connection Active - can not reconnect in current state"
        Exit Function
    End If
    If txtUser.Text = "" Then
        MsgBox "Please Specify a Username"
        ConnectToAS400 = False
        Exit Function
    End If
    If txtPass.Text = "" Then
        MsgBox "Please Specify a Password"
        ConnectToAS400 = False
        Exit Function
    End If
    If txtRemoteLU.Text = "" Then
        MsgBox "Please specify the Remote LU that corresponds to the AS/400"
        ConnectToAS400 = False
        Exit Function
    End If
    If txtScreenName.Text = "" Then
        MsgBox "Please specify a Screen Name"
        Exit Function
    End If
    With Q_DQCtrl
        .UserID = txtUser.Text
        .Password = txtPass.Text
        .RemoteLU = txtRemoteLU.Text
    End With
    '
    ' Connect - success is determined based uppon connection state variable
    ' set by event
    '
    Q_DQCtrl.Connect
    ConnectToAS400 = True
End Function
'
'   CreateQContainers Creates the Initial Queue Containers for the send and
'   receive queues
'
Private Function CreateQContainers() As Boolean
    Dim queuename As String
    Dim library As String
    Dim queue As String
    '
    ' (1) Create first Queue Container and connect to queue to the host, create queue
    '
    queuename = txtQToHost
    library = txtLib
    If (queuename = "") Then
        MsgBox "Enter a Valid Queue Name"
        CreateQContainers = False
        Exit Function
    End If
    If (library = "") Then
        MsgBox "Enter a valid Library Name"
        CreateQContainers = False
        Exit Function
    End If
    queue = library & "/" & queuename
    dbg "queue container: " & queue
    Set Q_DQueue = Q_DQCtrl.CreateQueueContainer(queue)
    '
    ' (2) Create the second queue container and queue from the host
    '
    queuename = txtQFromHost
    library = txtLib
    If (queuename = "") Then
        MsgBox "Enter a Valid Queue Name"
        CreateQContainers = False
        Exit Function
    End If
    If (library = "") Then
        MsgBox "Enter a valid Library Name"
        CreateQContainers = False
        Exit Function
    End If
    queue = library & "/" & queuename
    '
    ' Create the Queue from the host
    '
    Set Q_DQueueFromHost = Q_DQCtrl.CreateQueueContainer(queue)
    CreateQContainers = True
End Function

