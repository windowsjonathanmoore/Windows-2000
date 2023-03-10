VERSION 5.00
Object = "{5E9E78A0-531B-11CF-91F6-C2863C385E30}#1.0#0"; "MSFLXGRD.OCX"
Begin VB.Form frmGetAllInvoices 
   Caption         =   "Programming Specifics Samples"
   ClientHeight    =   5655
   ClientLeft      =   1140
   ClientTop       =   1515
   ClientWidth     =   7905
   LinkTopic       =   "Form1"
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   5655
   ScaleWidth      =   7905
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   WhatsThisHelp   =   -1  'True
   Begin VB.CommandButton cmdExit 
      Caption         =   "Exit"
      Height          =   375
      Left            =   6240
      TabIndex        =   8
      Top             =   5040
      Width           =   1215
   End
   Begin VB.Frame Frame1 
      Caption         =   "Customer ID:"
      Height          =   975
      Left            =   120
      TabIndex        =   5
      Top             =   120
      Width           =   7335
      Begin VB.CommandButton cmdGO 
         Caption         =   "GO"
         Default         =   -1  'True
         Height          =   375
         Left            =   4920
         TabIndex        =   7
         Top             =   240
         Width           =   1095
      End
      Begin VB.TextBox txtCustomerNumber 
         Height          =   285
         Left            =   240
         TabIndex        =   6
         Top             =   360
         Width           =   3855
      End
   End
   Begin VB.TextBox txtLastName 
      Height          =   285
      Left            =   1680
      TabIndex        =   1
      Top             =   1800
      Width           =   2295
   End
   Begin MSFlexGridLib.MSFlexGrid grdInvoices 
      Height          =   2175
      Left            =   360
      TabIndex        =   0
      Top             =   2400
      Width           =   6855
      _ExtentX        =   12091
      _ExtentY        =   3836
      _Version        =   327680
      Rows            =   1
      Cols            =   1
      FixedRows       =   0
      FixedCols       =   0
      AllowBigSelection=   0   'False
      AllowUserResizing=   1
   End
   Begin VB.Frame Frame2 
      Caption         =   "Show Invoices:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3615
      Left            =   120
      TabIndex        =   2
      Top             =   1200
      Width           =   7335
      Begin VB.TextBox txtFirstName 
         Height          =   285
         Left            =   4080
         TabIndex        =   4
         Top             =   600
         Width           =   2655
      End
      Begin VB.Label lblCustomer 
         Caption         =   "Customer Name:"
         Height          =   255
         Left            =   240
         TabIndex        =   3
         Top             =   600
         Width           =   1335
      End
   End
End
Attribute VB_Name = "frmGetAllInvoices"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdExit_Click()
    Hide
End Sub
'Runs OK
Private Sub cmdGO_Click()

Dim objCustomer As Object   'Uses late binding
Dim objInvoices As ADODB.Recordset
Dim lCustomerNumber As Long
Dim strLastName As String
Dim strFirstName As String
Dim iRow As Integer
Dim iCol As Integer

'create an instance of the invoicing object
On Error GoTo ErrorHandler1
Set objCustomer = CreateObject("Customer.Invoicing.1")

lCustomerNumber = CLng(txtCustomerNumber)

'invoke the GetAllInvoices method
On Error GoTo ErrorHandler2
objCustomer.GetAllInvoices lCustomerNumber, objInvoices _
    , strLastName, strFirstName
'
' Transfer the Recordset data to a variant array in a single operation.
' This is efficient, but may not be suitable for larger Recordsets.
'
Dim Data As Variant

Data = objInvoices.GetRows
grdInvoices.Rows = UBound(Data, 2) + 1
grdInvoices.Cols = UBound(Data, 1) + 1
For iRow = 0 To UBound(Data, 2)
    grdInvoices.Row = iRow
    For iCol = 0 To UBound(Data, 1)
        grdInvoices.Col = iCol
        grdInvoices.Text = Data(iCol, iRow)
    Next iCol
Next iRow

txtLastName = strLastName
txtFirstName = strFirstName

Exit Sub

ErrorHandler1:
    MsgBox Err.Description, vbOKOnly, "Object creation failed"
    Exit Sub
    
ErrorHandler2:
    frmError.Show 1
    Exit Sub

End Sub
