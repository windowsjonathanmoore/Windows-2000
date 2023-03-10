VERSION 5.00
Begin VB.Form frmVBClient 
   Caption         =   "Programming Specifics Samples"
   ClientHeight    =   4095
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   4095
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdUpdateArray 
      Caption         =   "In/Out Variable Length Table"
      Height          =   375
      Left            =   240
      TabIndex        =   7
      Top             =   3120
      Width           =   2655
   End
   Begin VB.CommandButton cmdGetAllInvoices 
      Caption         =   "Unbounded Recordsets"
      Height          =   372
      Left            =   240
      TabIndex        =   6
      Top             =   2640
      Width           =   2655
   End
   Begin VB.CommandButton cmdCustomerDemographics 
      Caption         =   "Handling Filler"
      Height          =   372
      Left            =   240
      TabIndex        =   5
      Top             =   2160
      Width           =   2655
   End
   Begin VB.CommandButton cmdCustomerInformation 
      Caption         =   "Variably Sized Strings"
      Height          =   372
      Left            =   240
      TabIndex        =   4
      Top             =   1680
      Width           =   2655
   End
   Begin VB.CommandButton cmdCreateCustomerID 
      Caption         =   "Handling Redefines Clauses"
      Height          =   372
      Left            =   240
      TabIndex        =   3
      Top             =   1200
      Width           =   2655
   End
   Begin VB.CommandButton cmdSendInvoices 
      Caption         =   "Variable Length Tables"
      Height          =   372
      Left            =   240
      TabIndex        =   2
      Top             =   720
      Width           =   2655
   End
   Begin VB.CommandButton cmdExit 
      Caption         =   "Exit"
      Height          =   375
      Left            =   3360
      TabIndex        =   1
      Top             =   240
      Width           =   975
   End
   Begin VB.CommandButton cmdGetInvoices 
      Caption         =   "Returning a Recordset"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   2655
   End
End
Attribute VB_Name = "frmVBClient"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'Runs OK
Private Sub cmdCreateCustomerID_Click()
    'Associated COBOL: CreateCustomerID.cbl
    'Demonstrate that redefines clauses don't affect automation side
    Dim objCustomer As Object
    Dim strLocation As String
    Dim strNameAbrev As String
    
    strLocation = "101"
    strNameAbrev = "SPORT"
    
    'create an instance of the invoicing object
    On Error GoTo ErrorHandler1
    Set objCustomer = CreateObject("Customer.Invoicing.1")
    
    'invoke the CreateCustomerID method
    On Error GoTo ErrorHandler2
    objCustomer.CreateCustomerID strLocation, strNameAbrev
    
    Exit Sub

ErrorHandler1:
    MsgBox Err.Description, vbOKOnly, "Object creation failed"
    Exit Sub
    
ErrorHandler2:
    frmError.Show 1
    Exit Sub
    
End Sub
'Runs OK
Private Sub cmdCustomerDemographics_Click()
    'Associated COBOL:  CustomerDemographics.cbl
    'Demonstrate that FILLER isn't visible on automation side
    Dim objCustomer As Object
    Dim strLastName As String
    Dim strFirstName As String
    Dim iAge As Integer
    Dim curIncome As Currency
    Dim strSex As String
    Dim strMStatus As String
    
    strLastName = "Doe"
    strFirstName = "John"
    
    'create an instance of the invoicing object
    On Error GoTo ErrorHandler1
    Set objCustomer = CreateObject("Customer.Invoicing.1")
    
    'invoke the SetInvoices method
    On Error GoTo ErrorHandler2
    objCustomer.CustomerDemographics strLastName, strFirstName _
        , iAge, curIncome, strSex, strMStatus
    
    Exit Sub

ErrorHandler1:
    MsgBox Err.Description, vbOKOnly, "Object creation failed"
    Exit Sub
    
ErrorHandler2:
    frmError.Show 1
    Exit Sub

End Sub
' RUNS OK
Private Sub cmdCustomerInformation_Click()
    'Associated COBOL:  CustomerInformation.cbl
    'Demonstrate variably sized strings as the last parameter
    Dim objCustomer As Object
    Dim lCustomerNo As Long
    Dim strLastName As String
    Dim strFirstName As String
    Dim strComments As String
    
    lCustomerNo = 100231
    
    'create an instance of the invoicing object
    On Error GoTo ErrorHandler1
    Set objCustomer = CreateObject("Customer.Invoicing.1")
    
    'invoke the SetInvoices method
    On Error GoTo ErrorHandler2
    objCustomer.CustomerInformation lCustomerNo, strLastName _
        , strFirstName, strComments
    
    Exit Sub

ErrorHandler1:
    MsgBox Err.Description, vbOKOnly, "Object creation failed"
    Exit Sub
    
ErrorHandler2:
    frmError.Show 1
    Exit Sub

End Sub

Private Sub cmdExit_Click()
    End
End Sub
' Runs OK
Private Sub cmdGetAllInvoices_Click()
    'Associated COBOL:  GetAllInvoices.cbl
    'Demonstrates how to use unbounded recordsets
    frmGetAllInvoices.Show 1
End Sub
' Runs OK
Private Sub cmdGetInvoices_Click()
    'Associated COBOL: GetInvoices.cbl
    'Demonstrates how to return recordset objects
    frmGetInvoices.Show 1
End Sub
'Runs OK
Private Sub cmdSendInvoices_Click()
    'Associated COBOL:  SendInvoices.cbl
    'Demonstrates how to send a bounded recordset (variable length table)
    Dim strCustomerNo As String
    Dim i As Integer
    Dim rgInvNums(2)
    Dim rgInvDates(2)
    Dim rgInvAmts(2)
    Dim rgInvDescs(2)
    
    rgInvNums(0) = CLng(1001021110)
    rgInvNums(1) = CLng(1001022110)
    rgInvNums(2) = CLng(1001023110)
    rgInvDates(0) = CDate("07/05/94")
    rgInvDates(1) = CDate("11/07/94")
    rgInvDates(2) = CDate("12/10/94")
    rgInvAmts(0) = CCur(23.95)
    rgInvAmts(1) = CCur(107.34)
    rgInvAmts(2) = CCur(2.78)
    rgInvDescs(0) = CStr("Std 12in widget sprocket")
    rgInvDescs(1) = CStr("High pressure hose-end replacement")
    rgInvDescs(2) = CStr("Half inch grommet")
    
    ' Recordset variables
    Dim objInvoices As ADODB.Recordset
    Dim column(3) As Variant
    Dim element(3) As Variant
    ' Customer.Invoicing variables
    Dim objCustomer As Object
    Dim lCustomerNo As Long
    Dim strLastName As String
    Dim strFirstName As String
    Dim lcInvoices As Long
    
    'create an instance of the invoicing object
    On Error GoTo ErrorHandler1
    Set objCustomer = CreateObject("Customer.Invoicing.1")
    
    lCustomerNo = 100231001
    strLastName = "Doe"
    strFirstName = "John"
    lcInvoices = 3
    
    'Create the recordset
    Set objInvoices = objCustomer.NewRecordset("INVOICES")

    column(0) = CStr("INVOICE_NUMBER")
    column(1) = CStr("INVOICE_DATE")
    column(2) = CStr("INVOICE_AMOUNT")
    column(3) = CStr("INVOICE_DESCRIPTION")
    
    For i = 0 To lcInvoices - 1
        'For sample use a comment that data comes from somewhere
        element(0) = CLng(rgInvNums(i))
        element(1) = CDate(rgInvDates(i))
        element(2) = CCur(rgInvAmts(i))
        element(3) = CStr(rgInvDescs(i))
        
        objInvoices.AddNew column, element
    Next i
    
    'invoke the SetInvoices method
    On Error GoTo ErrorHandler2
    objCustomer.SendInvoices lCustomerNo, strLastName, strFirstName _
        , lcInvoices, objInvoices
    
    Exit Sub

ErrorHandler1:
    MsgBox Err.Description, vbOKOnly, "Object creation failed"
    Exit Sub
    
ErrorHandler2:
    frmError.Show 1
    Exit Sub

End Sub
'Runs OK
Private Sub cmdUpdateArray_Click()
    'Associated COBOL: UpdateArray.cbl
    'Demonstrates in/out arrays associated with variable length tables
    Dim objCustomer As Object
    Dim i
    Dim rgTable() As Integer
    Dim lCustomerNo As Long
    Dim strLastName As String
    Dim strFirstName As String
    Dim lcElements As Long
    
    'create an instance of the invoicing object
    On Error GoTo ErrorHandler1
    Set objCustomer = CreateObject("Customer.Invoicing.1")
    
    lCustomerNo = 100231001
    strLastName = "Doe"
    strFirstName = "John"
    
    'Send over 5 elements
    lcElements = 5
    ReDim rgTable(lcElements)
    For i = 0 To lcElements - 1
        rgTable(0) = i
    Next i
    
    'invoke the UpdateArray method
    On Error GoTo ErrorHandler2
    objCustomer.UpdateArray lCustomerNo, strLastName, strFirstName _
        , lcElements, rgTable
    
    'lcElements now contains the number of elements returned in rgTable
    
    i = UBound(rgTable) + 1
    
    Exit Sub

ErrorHandler1:
    MsgBox Err.Description, vbOKOnly, "Object creation failed"
    Exit Sub
    
ErrorHandler2:
    frmError.Show 1
    Exit Sub


End Sub
