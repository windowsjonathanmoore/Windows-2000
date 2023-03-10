VERSION 5.00
Object = "{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}#1.1#0"; "SHDOCVW.DLL"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5535
   ClientLeft      =   1140
   ClientTop       =   1515
   ClientWidth     =   8685
   LinkTopic       =   "Form1"
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   5535
   ScaleWidth      =   8685
   Begin VB.CommandButton List 
      Caption         =   "List"
      Height          =   375
      Left            =   5520
      TabIndex        =   7
      Top             =   480
      Width           =   1455
   End
   Begin VB.ListBox List1 
      Height          =   4155
      Left            =   4800
      TabIndex        =   6
      Top             =   1080
      Width           =   3615
   End
   Begin VB.CommandButton Refresh 
      Caption         =   "&Refresh"
      Height          =   375
      Index           =   1
      Left            =   2160
      TabIndex        =   5
      Top             =   600
      Width           =   855
   End
   Begin VB.CommandButton Forward 
      Caption         =   "&Forward"
      Height          =   375
      Index           =   0
      Left            =   1080
      TabIndex        =   4
      Top             =   600
      Width           =   855
   End
   Begin VB.CommandButton Back 
      Caption         =   "&Back"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   600
      Width           =   735
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Top             =   120
      Width           =   3135
   End
   Begin VB.CommandButton Go 
      Caption         =   "&Go"
      Height          =   375
      Left            =   3600
      TabIndex        =   1
      Top             =   120
      Width           =   855
   End
   Begin SHDocVwCtl.WebBrowser WebBrowser1 
      Height          =   4215
      Left            =   120
      TabIndex        =   0
      Top             =   1080
      Width           =   4335
      ExtentX         =   7435
      ExtentY         =   7646
      ViewMode        =   1
      Offline         =   0
      Silent          =   0
      RegisterAsBrowser=   0
      RegisterAsDropTarget=   1
      AutoArrange     =   -1  'True
      NoClientEdge    =   0   'False
      AlignLeft       =   0   'False
      ViewID          =   "{0057D0E0-3573-11CF-AE69-08002B2E1262}"
      Location        =   ""
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command2_Click()

End Sub


Private Sub Command3_Click()

End Sub


Private Sub Command4_Click()

End Sub


Private Sub Back_Click()
On Error Resume Next
WebBrowser1.GoBack
End Sub

Private Sub Form_Load()
WebBrowser1.Navigate2 ("http://www.microsoft.com")
End Sub

Private Sub Forward_Click(Index As Integer)
On Error Resume Next
WebBrowser1.GoForward
End Sub

Private Sub Go_Click()
WebBrowser1.Navigate2 (Text1)
End Sub


Private Sub List_Click()
 Dim allCol
  Dim TagName As String
  List1.Clear
  Set allCol = WebBrowser1.Document.All
  allcount = allCol.length
  For i = 0 To allcount - 1
    TagName = allCol.Item(i).TagName
    If TagName = "IMG" Or TagName = "A" Then
       TagName = TagName & " - " & allCol.Item(i).href
    End If
    List1.AddItem (TagName)
  Next
End Sub

Private Sub Refresh_Click(Index As Integer)
WebBrowser1.Refresh2
End Sub

Private Sub WebBrowser1_NavigateComplete2(ByVal pDisp As Object, URL As Variant)
Text1.Text = URL
List1.Clear
End Sub

