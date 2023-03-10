VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "RecordSetSample"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Public Sub RecordSetSample(ByVal Ilog As Object)
On Error Resume Next
    
    Dim rsInvoices As ADODB.Recordset
    Dim objCustomerData As Object
    Dim strStepDesc As String
    Dim Customer_number As Long
    Dim Last_Name As String
    Dim First_name As String
    Dim NumRecords As Variant
    
    Dim fields(3) As Variant
    Dim Values(3) As Variant
    
    ' Create the COM object
    Set objCustomerData = CreateObject("Customer_Data.Sample")

    ' Create the recordset
    Set rsInvoices = objCustomerData.NewRecordset("Invoice_Row")
        
    ' The first three parameters
    Customer_number = 2468
    Last_Name = "Ruble"
    First_name = "Barney"
        
    ' Put three rows in the recordset object
    fields(0) = CStr("Invoice_Number")
    fields(1) = CStr("Invoice_Date")
    fields(2) = CStr("Invoice_Amount")
    fields(3) = CStr("Invoice_Description")
    
    Values(0) = CLng(11111)
    Values(1) = CDate("08/14/1997 01:11:11 AM")
    Values(2) = CCur(56.12)
    Values(3) = CStr("Clothes")
    rsInvoices.AddNew fields, Values
   
    Values(0) = CLng(22222)
    Values(1) = CDate("09/12/1997 01:11:11 AM")
    Values(2) = CCur(78.32)
    Values(3) = CStr("House Wares")
    rsInvoices.AddNew fields, Values
          
    Values(0) = CLng(33333)
    Values(1) = CDate("10/14/1997 01:11:11 AM")
    Values(2) = CCur(42.5)
    Values(3) = CStr("Tools")
    rsInvoices.AddNew fields, Values
    
    ' Make the call to the COMTI object
    Call objCustomerData.Customer_Data(Customer_number, Last_Name, First_name, rsInvoices)

    ' Parameters from the call now contains data from the host program
    
EndProgram:
      
End Sub







