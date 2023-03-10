VERSION 5.00
Begin VB.Form frmError 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "OLE Automation Exception"
   ClientHeight    =   3105
   ClientLeft      =   4140
   ClientTop       =   3210
   ClientWidth     =   5790
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   3105
   ScaleWidth      =   5790
   ShowInTaskbar   =   0   'False
   Begin VB.CommandButton Command1 
      Caption         =   "E&xit"
      Height          =   375
      Left            =   2280
      TabIndex        =   8
      Top             =   2520
      Width           =   1215
   End
   Begin VB.TextBox txtNumber 
      Enabled         =   0   'False
      Height          =   285
      Left            =   2640
      TabIndex        =   5
      Top             =   600
      Width           =   2655
   End
   Begin VB.TextBox txtDescription 
      Enabled         =   0   'False
      Height          =   975
      Left            =   240
      MultiLine       =   -1  'True
      TabIndex        =   3
      Top             =   1320
      Width           =   5295
   End
   Begin VB.TextBox txtSource 
      Enabled         =   0   'False
      Height          =   285
      Left            =   2640
      TabIndex        =   1
      Top             =   240
      Width           =   2655
   End
   Begin VB.CommandButton cmdOK 
      Caption         =   "&Ignore"
      Default         =   -1  'True
      Height          =   375
      Left            =   360
      TabIndex        =   6
      Top             =   2520
      Width           =   1215
   End
   Begin VB.CommandButton cmdHelp 
      Caption         =   "&Help"
      Height          =   375
      Left            =   4200
      TabIndex        =   7
      Top             =   2520
      Width           =   1215
   End
   Begin VB.Label Label3 
      Alignment       =   1  'Right Justify
      Caption         =   "Error Number:"
      Height          =   255
      Left            =   1320
      TabIndex        =   4
      Top             =   600
      Width           =   1095
   End
   Begin VB.Label Label2 
      Alignment       =   1  'Right Justify
      Caption         =   "Description:"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   1080
      Width           =   975
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      Caption         =   "Source:"
      Height          =   255
      Left            =   1680
      TabIndex        =   0
      Top             =   240
      Width           =   735
   End
End
Attribute VB_Name = "frmError"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

' Commands to pass WinHelp()
Const HELP_CONTEXT = &H1          '  Display topic in ulTopic
Const HELP_QUIT = &H2             '  Terminate help
Const HELP_INDEX = &H3            '  Display index
Const HELP_CONTENTS = &H3&
Const HELP_HELPONHELP = &H4       '  Display help on using help
Const HELP_SETINDEX = &H5         '  Set current Index for multi index help
Const HELP_SETCONTENTS = &H5&
Const HELP_CONTEXTPOPUP = &H8&
Const HELP_FORCEFILE = &H9&
Const HELP_KEY = &H101            '  Display topic for keyword
Const HELP_COMMAND = &H102&
Const HELP_PARTIALKEY = &H105&
Const HELP_MULTIKEY = &H201&
Const HELP_SETWINPOS = &H203&

Private Declare Function WinHelp Lib "user32" Alias "WinHelpA" (ByVal hwnd As Long, ByVal lpHelpFile As String, ByVal wCommand As Long, ByVal dwData As Long) As Long

Private Sub Command1_Click()
    End
End Sub

Private Sub cmdHelp_Click()
    WinHelp frmError.hwnd, Err.HelpFile, HELP_CONTEXT, Err.HelpContext
End Sub


Private Sub cmdOK_Click()
    WinHelp frmError.hwnd, Err.HelpFile, HELP_QUIT, 0
    Unload frmError
End Sub

Private Sub Form_Load()
    txtSource = Err.Source
    txtDescription = Err.Description
    txtNumber = Err.Number & " (0x" & Hex(Err.Number) & ")"
    ' txtHelpFile = Err.HelpFile
    ' txtContext = Err.HelpContext
End Sub


