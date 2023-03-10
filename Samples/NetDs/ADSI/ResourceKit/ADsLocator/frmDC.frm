VERSION 5.00
Begin VB.Form frmDC 
   Caption         =   "DC "
   ClientHeight    =   4245
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6810
   LinkTopic       =   "Form1"
   ScaleHeight     =   4245
   ScaleWidth      =   6810
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdClose 
      Caption         =   "Close"
      Height          =   375
      Left            =   5400
      TabIndex        =   2
      Top             =   360
      Width           =   1215
   End
   Begin VB.ListBox lstDC 
      Height          =   3570
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   5055
   End
   Begin VB.Label Label1 
      Caption         =   "DC Lists:"
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   120
      Width           =   2055
   End
End
Attribute VB_Name = "frmDC"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub cmdClose_Click()
 Me.Hide
End Sub

Public Sub SetDC(dcs As Variant)

lstDC.Clear

For Each dc In dcs
   lstDC.AddItem dc
Next

End Sub

