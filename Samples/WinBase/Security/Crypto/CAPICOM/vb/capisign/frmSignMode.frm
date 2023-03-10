VERSION 5.00
Begin VB.Form frmSignMode 
   Caption         =   "Document Signing Wizard"
   ClientHeight    =   4890
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7185
   Icon            =   "frmSignMode.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4890
   ScaleWidth      =   7185
   StartUpPosition =   2  'CenterScreen
   Begin VB.OptionButton optAttached 
      Caption         =   "&Attached: Certificates, signature, and file contents are saved as a PKCS#7 file."
      Height          =   255
      Left            =   480
      TabIndex        =   6
      Top             =   1080
      Value           =   -1  'True
      Width           =   5985
   End
   Begin VB.OptionButton optDetached 
      Caption         =   "&Detached: Certificates and signature are stored in a separate file."
      Height          =   255
      Left            =   480
      TabIndex        =   5
      Top             =   1680
      Width           =   5895
   End
   Begin VB.CommandButton cmdCancel 
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   350
      Index           =   3
      Left            =   1440
      TabIndex        =   4
      Top             =   4440
      Width           =   1215
   End
   Begin VB.CommandButton cmdPrev 
      Caption         =   "< &Previous"
      Height          =   350
      Index           =   2
      Left            =   3000
      TabIndex        =   3
      Top             =   4440
      Width           =   1200
   End
   Begin VB.CommandButton cmdNext 
      Caption         =   " &Next >"
      Height          =   350
      Index           =   1
      Left            =   4200
      TabIndex        =   2
      Top             =   4440
      Width           =   1215
   End
   Begin VB.CommandButton cmdFinish 
      Caption         =   "&Finish"
      Default         =   -1  'True
      Height          =   350
      Index           =   0
      Left            =   5760
      TabIndex        =   1
      Top             =   4440
      Width           =   1215
   End
   Begin VB.Frame Frame1 
      Height          =   135
      Left            =   120
      TabIndex        =   0
      Top             =   4200
      Width           =   6855
   End
   Begin VB.Label Label1 
      Caption         =   "Select how you would like the signature stored."
      Height          =   375
      Left            =   480
      TabIndex        =   7
      Top             =   240
      Width           =   4995
   End
End
Attribute VB_Name = "frmSignMode"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private Sub cmdCancel_Click(Index As Integer)
    End
End Sub

Private Sub cmdNext_Click(Index As Integer)
    Me.Visible = False
    frmFinish.Visible = True
End Sub

Private Sub Form_Load()

End Sub


