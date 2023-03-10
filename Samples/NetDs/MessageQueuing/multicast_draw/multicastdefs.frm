VERSION 5.00
Begin VB.Form MulticastDefs 
   Caption         =   "Please supply the following:"
   ClientHeight    =   3930
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5370
   LinkTopic       =   "Form2"
   ScaleHeight     =   3930
   ScaleWidth      =   5370
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame QueueType 
      Caption         =   "Please choose a type for your receiving queue "
      Height          =   615
      Left            =   480
      TabIndex        =   8
      Top             =   840
      Width           =   4695
      Begin VB.OptionButton optPrivate 
         Caption         =   "Private"
         Height          =   255
         Left            =   120
         TabIndex        =   10
         Top             =   240
         Value           =   -1  'True
         Width           =   1695
      End
      Begin VB.OptionButton optPublic 
         Caption         =   "Public"
         Height          =   255
         Left            =   2160
         TabIndex        =   9
         Top             =   240
         Width           =   1815
      End
   End
   Begin VB.CommandButton btnExit 
      Caption         =   "Exit"
      Height          =   495
      Left            =   240
      TabIndex        =   7
      Top             =   3360
      Width           =   1455
   End
   Begin VB.CommandButton btnOk 
      Caption         =   "Ok"
      Height          =   495
      Left            =   3600
      TabIndex        =   6
      Top             =   3360
      Width           =   1575
   End
   Begin VB.TextBox txtPortNumber 
      Height          =   285
      Left            =   2640
      TabIndex        =   5
      Top             =   2400
      Width           =   2415
   End
   Begin VB.TextBox txtIPAddress 
      Height          =   285
      Left            =   2640
      TabIndex        =   3
      Top             =   1920
      Width           =   2415
   End
   Begin VB.TextBox txtQueueName 
      Height          =   285
      Left            =   2640
      TabIndex        =   1
      Top             =   360
      Width           =   2535
   End
   Begin VB.Label Label3 
      Caption         =   "Multicast port number:"
      Height          =   255
      Left            =   480
      TabIndex        =   4
      Top             =   2400
      Width           =   1815
   End
   Begin VB.Label Label2 
      Caption         =   "Multicast IP address:"
      Height          =   255
      Left            =   480
      TabIndex        =   2
      Top             =   1920
      Width           =   1575
   End
   Begin VB.Label Label1 
      Caption         =   "Local Queue Name:"
      Height          =   255
      Left            =   480
      TabIndex        =   0
      Top             =   360
      Width           =   1575
   End
End
Attribute VB_Name = "MulticastDefs"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
' this form is responsible for recieving some initialization parameters.

Private Sub btnExit_Click()
    End
End Sub

Private Sub btnOk_Click()
    If txtPortNumber = "" Or txtIPAddress = "" Or txtQueueName = "" Then
        MsgBox ("Please fill all the fields.")
    Else
        MulticastDefs.Hide
    End If
End Sub

Private Sub Form_Load()
    dDirectMode = vbYes
End Sub

' The user chose Private queue

Private Sub optPrivate_Click()
    dDirectMode = vbYes
End Sub

' The user chose Public queue

Private Sub optPublic_Click()
    dDirectMode = vbNo
End Sub
