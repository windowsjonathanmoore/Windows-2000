VERSION 5.00
Begin VB.Form frmStore 
   Caption         =   "CAPICOM - Manage Certificate Stores"
   ClientHeight    =   6255
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   11220
   LinkTopic       =   "Form1"
   ScaleHeight     =   6255
   ScaleWidth      =   11220
   StartUpPosition =   3  'Windows Default
   Begin VB.ComboBox comStoreName 
      Height          =   315
      Left            =   1440
      TabIndex        =   3
      Top             =   840
      Width           =   3255
   End
   Begin VB.ComboBox comStoreLocation 
      Height          =   315
      Left            =   1440
      Style           =   2  'Dropdown List
      TabIndex        =   1
      Top             =   240
      Width           =   3255
   End
   Begin VB.CommandButton btnVerify 
      Caption         =   "Verify"
      Enabled         =   0   'False
      Height          =   375
      Left            =   3480
      TabIndex        =   10
      Top             =   5640
      Width           =   855
   End
   Begin VB.CommandButton btnDisplay 
      Caption         =   "Display"
      Enabled         =   0   'False
      Height          =   375
      Left            =   4560
      TabIndex        =   11
      Top             =   5640
      Width           =   855
   End
   Begin VB.ListBox lstDeleted 
      Height          =   4740
      Left            =   7800
      TabIndex        =   15
      Top             =   720
      Width           =   3135
   End
   Begin VB.CommandButton btnRemove 
      Caption         =   "Remove"
      Enabled         =   0   'False
      Height          =   375
      Left            =   6720
      TabIndex        =   13
      TabStop         =   0   'False
      Top             =   2400
      Width           =   855
   End
   Begin VB.CommandButton btnAdd 
      Caption         =   "Add"
      Enabled         =   0   'False
      Height          =   375
      Left            =   6720
      TabIndex        =   14
      TabStop         =   0   'False
      Top             =   3240
      Width           =   855
   End
   Begin VB.CommandButton btnExport 
      Caption         =   "Export"
      Enabled         =   0   'False
      Height          =   375
      Left            =   1320
      TabIndex        =   8
      Top             =   5640
      Width           =   855
   End
   Begin VB.CommandButton btnImport 
      Caption         =   "Import"
      Enabled         =   0   'False
      Height          =   375
      Left            =   2400
      TabIndex        =   9
      Top             =   5640
      Width           =   855
   End
   Begin VB.ListBox lstCertificates 
      Height          =   3960
      Left            =   240
      TabIndex        =   6
      Top             =   1320
      Width           =   6255
   End
   Begin VB.CommandButton btnClose 
      Caption         =   "Close"
      Height          =   375
      Left            =   9720
      TabIndex        =   16
      Top             =   5640
      Width           =   1215
   End
   Begin VB.CommandButton btnReset 
      Caption         =   "Reset"
      Height          =   375
      Left            =   5640
      TabIndex        =   12
      Top             =   5640
      Width           =   855
   End
   Begin VB.CommandButton btnOpen 
      Caption         =   "Open"
      Default         =   -1  'True
      Height          =   375
      Left            =   240
      TabIndex        =   7
      Top             =   5640
      Width           =   855
   End
   Begin VB.Label lblStoreName 
      Caption         =   "Store Name:"
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   840
      Width           =   975
   End
   Begin VB.Label lblNumDeleted 
      BorderStyle     =   1  'Fixed Single
      Height          =   255
      Left            =   9360
      TabIndex        =   18
      Top             =   240
      Width           =   735
   End
   Begin VB.Label lblDeleted 
      Caption         =   "Deleted certificates:"
      Height          =   255
      Left            =   7800
      TabIndex        =   17
      Top             =   240
      Width           =   1575
   End
   Begin VB.Label lblNumCerts 
      BorderStyle     =   1  'Fixed Single
      Height          =   255
      Left            =   5760
      TabIndex        =   5
      Top             =   840
      Width           =   735
   End
   Begin VB.Label Label2 
      Caption         =   "Certificates:"
      Height          =   255
      Left            =   4800
      TabIndex        =   4
      Top             =   840
      Width           =   1095
   End
   Begin VB.Label lblStoreLocation 
      Caption         =   "Store Location:"
      Height          =   255
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   1215
   End
End
Attribute VB_Name = "frmStore"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'******************************************************************************
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.

' Copyright (C) 2000.  Microsoft Corporation.  All rights reserved.
' ******************************************************************************
Option Explicit

Public Store As Store
Public CertificateIndex As Long
Dim ExportedStore As String
Private DeletedCerts As New Collection

'******************************************************************************
'
' DisplayBasicConstraints
'
' Display the basic constraints property of a certificate.
'
Public Sub DisplayBasicConstraints(Certificate As Certificate)

    On Error GoTo ErrorHandler

    If Certificate.BasicConstraints.IsPresent Then
        lstCertificates.AddItem "    [Basic Constraints]: " & IIf(Certificate.BasicConstraints.IsCritical, "Critical", "Not Critical")
        
        lstCertificates.AddItem "                                   Certificate Authority - " & IIf(Certificate.BasicConstraints.IsCertificateAuthority, "Yes", "No")
        lstCertificates.AddItem "                                   Path Length Constraint - " & IIf(Certificate.BasicConstraints.IsPathLenConstraintPresent, Certificate.BasicConstraints.PathLenConstraint, "Not present")
    Else
        lstCertificates.AddItem "    [Basic Constraints]: " & "Not present"
    End If
        
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Display Basci Constraints"
 
End Sub
    
'******************************************************************************
'
' DisplayExtendedKeyUsages
'
' Display the extented key usages property of a certificate.
'
Public Sub DisplayExtendedKeyUsages(Certificate As Certificate)
    
    On Error GoTo ErrorHandler

    If Certificate.ExtendedKeyUsage.IsPresent Then
        Dim EKU As EKU
        
        lstCertificates.AddItem "    [Extended Key Usage]: " & IIf(Certificate.ExtendedKeyUsage.IsCritical, "Critical", "Not Critical")
        
        For Each EKU In Certificate.ExtendedKeyUsage.EKUs
            lstCertificates.AddItem "                                         " & EKU.OID
        Next
    Else
        lstCertificates.AddItem "    [Extended Key Usage]: Not present"
    End If
 
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Display Extended Key Usages"
 
End Sub

'******************************************************************************
'
' DisplayKeyUsages
'
' Display the key usages property of a certificate.
'
Public Sub DisplayKeyUsages(Certificate As Certificate)
    
    On Error GoTo ErrorHandler
 
    If Certificate.KeyUsage.IsPresent Then
        lstCertificates.AddItem "    [Key Usage]: " & IIf(Certificate.KeyUsage.IsCritical, "Critical", "Not Critical")
        lstCertificates.AddItem "                         " & "CRL Sign - " & IIf(Certificate.KeyUsage.IsCRLSignEnabled, "Yes", "No")
        lstCertificates.AddItem "                         " & "Data Encipherment - " & IIf(Certificate.KeyUsage.IsDataEnciphermentEnabled, "Yes", "No")
        lstCertificates.AddItem "                         " & "Decipher Only - " & IIf(Certificate.KeyUsage.IsDecipherOnlyEnabled, "Yes", "No")
        lstCertificates.AddItem "                         " & "Digital Signature - " & IIf(Certificate.KeyUsage.IsDigitalSignatureEnabled, "Yes", "No")
        lstCertificates.AddItem "                         " & "Encipher Only - " & IIf(Certificate.KeyUsage.IsEncipherOnlyEnabled, "Yes", "No")
        lstCertificates.AddItem "                         " & "Key Agreement - " & IIf(Certificate.KeyUsage.IsKeyAgreementEnabled, "Yes", "No")
        lstCertificates.AddItem "                         " & "Key Cert Sign - " & IIf(Certificate.KeyUsage.IsKeyCertSignEnabled, "Yes", "No")
        lstCertificates.AddItem "                         " & "Key Encipherment - " & IIf(Certificate.KeyUsage.IsKeyEnciphermentEnabled, "Yes", "No")
        lstCertificates.AddItem "                         " & "Non Repudiation - " & IIf(Certificate.KeyUsage.IsNonRepudiationEnabled, "Yes", "No")
    Else
        lstCertificates.AddItem "    [Key Usage]: Not present"
    End If
 
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Display Key Usages"
 
End Sub

'******************************************************************************
'
' UpdateDisplay
'
' Display the certificates in a certificate store.
' This subroutine is called when a store is opened or
' the open store is changed in any way.
'
Private Sub UpdateDisplay()

    On Error GoTo ErrorHandler
    
    Dim Certificates As Certificates
    Set Certificates = Store.Certificates
    lblNumCerts.Caption = Str(Certificates.Count)
    lblNumDeleted.Caption = Str(DeletedCerts.Count)
    lstCertificates.Clear
    lstDeleted.Clear
        
    Dim i As Long
    Dim Certificate As Certificate
    
    i = 1
    
    ' Loop through all the certificates in the store.
    For Each Certificate In Certificates
        If i > 1 Then
            lstCertificates.AddItem ""
        End If
        
        If Certificate.IsValid Then
            lstCertificates.AddItem "Cert #" & Str(i) & IIf(Certificate.HasPrivateKey(), ": Valid with private key", ": Valid without private key")
        Else
            lstCertificates.AddItem "Cert #" & Str(i) & IIf(Certificate.HasPrivateKey(), ": Invalid with private key", ": Invalid without private key")
        End If
        lstCertificates.AddItem "    [Version]: " & Str(Certificate.Version)
        lstCertificates.AddItem "    [Serial Number]: " & Certificate.SerialNumber
        lstCertificates.AddItem "    [Subject]: " & Certificate.SubjectName
        lstCertificates.AddItem "    [Subject's simple name]: " & Certificate.GetInfo(CAPICOM_CERT_INFO_SUBJECT_SIMPLE_NAME)
        lstCertificates.AddItem "    [Issuer]: " & Certificate.IssuerName
        lstCertificates.AddItem "    [Issuer's simple name]: " & Certificate.GetInfo(CAPICOM_CERT_INFO_ISSUER_SIMPLE_NAME)
        lstCertificates.AddItem "    [Not Before]: " & Certificate.ValidFromDate
        lstCertificates.AddItem "    [Not After]: " & Certificate.ValidToDate
        lstCertificates.AddItem "    [Thumbprint]: " & Certificate.Thumbprint
    
        ' If the current certificate has key usages, extended key usages, or
        ' Basic constraints, the following subs display them.

        DisplayKeyUsages Certificate
        
        DisplayExtendedKeyUsages Certificate
        
        DisplayBasicConstraints Certificate
                
        i = i + 1
    Next
    
    ' Buttons on the form that can be used on the certificates in the store
    ' are enabled appropriately.

    If lstCertificates.ListCount > 0 Then
        btnExport.Enabled = True
        
        ' The remove button is not enabled for system My store because CAPICOM at
        ' this time does not support private key management and it can be difficult
        ' to re-associate the private key of a deleted certificate even
        ' if the certificate is added back into the store.
        
        btnRemove.Enabled = IIf((comStoreLocation.ListIndex = CAPICOM_LOCAL_MACHINE_STORE Or _
                                 comStoreLocation.ListIndex = CAPICOM_CURRENT_USER_STORE) And _
                                 UCase(comStoreName.Text) = "MY", False, True)
        btnVerify.Enabled = True
        btnDisplay.Enabled = True
        lstCertificates.ListIndex = 0
    Else
        btnExport.Enabled = False
        btnRemove.Enabled = False
    End If
    
    ' If certifcates have been deleted from the store and can be put back into
    ' the store, information on those deleted certificates is displayed.
    Dim Base64EncodedCert As Variant
    i = 1
    For Each Base64EncodedCert In DeletedCerts
        lstDeleted.AddItem "Cert #" & Str(i)
        lstDeleted.AddItem "    " & Base64EncodedCert
        i = i + 1
    Next
        
    ' If there are deleted certificates that can be added to the store,
    ' the Add button is enabled.
    If lstDeleted.ListCount > 0 Then
        btnAdd.Enabled = True
        lstDeleted.ListIndex = 0
    Else
        btnAdd.Enabled = False
    End If
    
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Update Display"

End Sub

'******************************************************************************
'
' btnOpen_Click
'
' Open the certificate store .
' This subroutine is called when the Open button is clicked.
'
Private Sub btnOpen_Click()
    On Error GoTo ErrorHandler
    
    Set Store = New Store
    
    ' The location of the store to be openned, that is Memory, Local Machine,
    ' Current User, or Active directory is detemined by the choice made in the
    ' StoreLocation combo box on the form.
    ' The name of the store to be open comes from the text in the StoreName
    ' combo box. Note that for Active Directory store, the store name is the
    ' LDAP query form, such as (CN=John Doe). See MSDN for detail information.
    ' The store is openned for read and write if that is allowed, or is open as
    ' a read only store if not.
    Store.Open comStoreLocation.ListIndex, comStoreName.Text, CAPICOM_STORE_OPEN_MAXIMUM_ALLOWED
    
    UpdateDisplay
    
    ' Once the store has been opened, neither the location of the store nor the name
    ' of the store can be changed. The button used to open a store is also disabled.
    ' The combo boxes for store location and store name and the open button are enabled again
    ' when the reset button is clicked.
    comStoreLocation.Enabled = False
    comStoreName.Enabled = False
    btnOpen.Enabled = False
    btnImport.Enabled = IIf(IsEmpty(ExportedStore), False, True)
   
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Open"

End Sub

'******************************************************************************
'
' btnExport_Click
'
' Export all of the certificates in the open store.
' This subroutine is called when the Export button is
' clicked.
'
' The certificates in the store are written to the global string variable,
' ExportedStore.
'
Private Sub btnExport_Click()
  
    ' Prompt user if they want the result in binary or base64 format.
    If MsgBox("Click 'Yes' to export the certificates as Base64. Click 'No' to export as binary.", vbYesNo) = vbYes Then
        ExportedStore = Store.Export(CAPICOM_STORE_SAVE_AS_PKCS7, CAPICOM_ENCODE_BASE64)
    Else
        ExportedStore = Store.Export(CAPICOM_STORE_SAVE_AS_SERIALIZED, CAPICOM_ENCODE_BINARY)
    End If
    
    UpdateDisplay
    
    btnImport.Enabled = True
    
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Export"
    
End Sub

'******************************************************************************
'
' btnImport_Click
'
' Import all of the certificates in that was previously exported .
' This subroutine is called when the Import button is clicked.
'
' Certifcate are imported into the store from the global string variable,
' ExportedStore.
'
Private Sub btnImport_Click()

    On Error GoTo ErrorHandler

    Store.Import ExportedStore
    
    UpdateDisplay
    
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Import"

End Sub

'******************************************************************************
'
' btnVerify_Click
'
' Verify the validity of the hilighted certificate.
' This subroutine is called when the Verify button is
' clicked.
'
' The results of this chain building and other certificate validity checks are
' shown on the ChainForm form.
'
Private Sub btnVerify_Click()

    On Error GoTo ErrorHandler
    
    CertificateIndex = FindIndex(lstCertificates)
    
    If CertificateIndex > 0 Then
        frmChain.Show vbModal
    End If
    
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Varify"

End Sub

'******************************************************************************
'
' btnDisplay_Click
'
' Display the currently highlighted certificate.
' This subroutine is called when the Display button is
' clicked.
'
Private Sub btnDisplay_Click()
    
    On Error GoTo ErrorHandler
    
    Dim Index As Long
    Index = FindIndex(lstCertificates)
    If Index > 0 Then
        Dim Certificates As Certificates
        Set Certificates = Store.Certificates
    
        Dim Certificate As Certificate
        Set Certificate = Certificates.Item(Index)
        Certificate.Display
    End If
        
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Display"

End Sub

'******************************************************************************
'
' btnReset_Click
'
' Close the opened certificate store and enable/disable all buttons
' appropriately.
' This subroutine is called  when the Reset button is clicked.
'
Private Sub btnReset_Click()

    On Error GoTo ErrorHandler

    Set Store = Nothing
    lblNumCerts.Caption = ""
    lstCertificates.Clear
    lstDeleted.Clear
    lblNumDeleted.Caption = ""
    
    comStoreLocation.Enabled = True
    comStoreLocation.Text = "CURRENT USER STORE"
    comStoreLocation.SetFocus
    comStoreName.Enabled = True
    comStoreName.Text = CAPICOM_MY_STORE
    btnOpen.Enabled = True
    btnExport.Enabled = False
    btnImport.Enabled = False
    btnVerify.Enabled = False
    btnDisplay.Enabled = False
    btnAdd.Enabled = False
    btnRemove.Enabled = False

    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Reset"

End Sub

'******************************************************************************
'
' btnAdd_Click
'
' Add the hilighted certificate from the deleted list to the opened store.
' This subroutine is called when the Add button is clicked.
'
Private Sub btnAdd_Click()

    On Error GoTo ErrorHandler
    
    Dim Index As Long
    Index = FindIndex(lstDeleted)
    If Index > 0 Then
        Dim Base64EncodedCert() As Byte
        Base64EncodedCert = DeletedCerts.Item(Index)
        
        Dim Certificate As New Certificate
        Certificate.Import Base64EncodedCert ', CAPICOM_BINARY_ENCODE
        Store.Add Certificate
        
        DeletedCerts.Remove Index
    
        UpdateDisplay
    End If
    
    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Add"

End Sub

'******************************************************************************
'
' btnRemove_Click
'
' Remove the hilighted certificate from the opened store.
' This subroutine is called when the Remove
' button is clicked.
'
' The removed certificate is also added to the global collection variable
' DeleteCertificaets, so that it is available for adding back later, if
' desired.
'
Private Sub btnRemove_Click()

    On Error GoTo ErrorHandler
    
    Dim Index As Long
    Index = FindIndex(lstCertificates)
    If Index > 0 Then
        Dim Certificate As Certificate
        Set Certificate = Store.Certificates.Item(Index)
        
        If (Certificate.HasPrivateKey) Then
            If vbOK <> MsgBox("You will NOT be able to recover the private key associate with this certificate if you decide to remove it from the store. Do you want to continue to remove the certificate?", vbOKCancel) Then
                Exit Sub
            End If
        End If
        
        Dim Base64EncodedCert As String
        Base64EncodedCert = Certificate.Export
        DeletedCerts.Add Base64EncodedCert
        
        Store.Remove Certificate

        UpdateDisplay
    End If

    Exit Sub
    
ErrorHandler:

    MsgBox "Error [" & Hex(Err.Number) & "]: " & Err.Description, vbOKOnly, "Remove"

End Sub

'******************************************************************************
'
' btnClose_Click
'
' End the program.
' This subroutine is called when the Close button is closed.
'
Private Sub btnClose_Click()
    Unload Me
End Sub

'******************************************************************************
'
' Form_Load
'
' Initialization.
'
Private Sub Form_Load()

    Dim MySettings As New CAPICOM.Settings

    MySettings.ActiveDirectorySearchLocation = CAPICOM_SEARCH_GLOBAL_CATALOG
    
    lblNumCerts.Caption = ""
    lblNumDeleted.Caption = ""
    lstCertificates.Clear
    lstDeleted.Clear
    
    comStoreLocation.AddItem "MEMORY STORE", CAPICOM_MEMORY_STORE
    comStoreLocation.AddItem "LOCAL MACHINE STORE", CAPICOM_LOCAL_MACHINE_STORE
    comStoreLocation.AddItem "CURRENT USER STORE", CAPICOM_CURRENT_USER_STORE
    comStoreLocation.AddItem "ACTIVE DIRECTORY USERSTORE", CAPICOM_ACTIVE_DIRECTORY_USER_STORE
    comStoreLocation.Text = "CURRENT USER STORE"
    
    comStoreName.AddItem CAPICOM_MY_STORE
    comStoreName.AddItem CAPICOM_CA_STORE
    comStoreName.AddItem CAPICOM_ROOT_STORE
    comStoreName.AddItem CAPICOM_OTHER_STORE
    comStoreName.Text = CAPICOM_MY_STORE
    
End Sub
