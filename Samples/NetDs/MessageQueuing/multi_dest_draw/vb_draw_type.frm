VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Queue Type Selection"
   ClientHeight    =   2625
   ClientLeft      =   2790
   ClientTop       =   4320
   ClientWidth     =   4650
   LinkTopic       =   "Form2"
   ScaleHeight     =   2625
   ScaleWidth      =   4650
   Begin VB.CommandButton Cancel 
      Caption         =   "&Cancel"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2880
      TabIndex        =   4
      Top             =   1920
      Width           =   1455
   End
   Begin VB.CommandButton Ok 
      Caption         =   "&Ok"
      Default         =   -1  'True
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   240
      TabIndex        =   3
      Top             =   1920
      Width           =   1455
   End
   Begin VB.Frame Frame1 
      Caption         =   "Please choose a type for your receiving queue "
      Height          =   1455
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   4095
      Begin VB.OptionButton Private 
         Caption         =   "Private  ( DS Disabled )"
         Height          =   255
         Left            =   240
         TabIndex        =   2
         Top             =   840
         Width           =   3135
      End
      Begin VB.OptionButton Public 
         Caption         =   "Public ( DS Enabled )"
         Height          =   255
         Left            =   240
         TabIndex        =   1
         Top             =   360
         Value           =   -1  'True
         Width           =   3015
      End
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Cancel_Click()
    End
End Sub

Private Sub Form_Load()
    dDirectMode = vbNo
End Sub

Private Sub Form_Unload(Cancel As Integer)
    End
End Sub

Private Sub Ok_Click()
    Form2.Hide
End Sub

Private Sub Private_Click()
    dDirectMode = vbYes
End Sub

Private Sub Public_Click()
    dDirectMode = vbNo
End Sub


