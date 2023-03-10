VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Events"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'-----------------------------------------------------------------------------
'
' File:         Events.cls
'
' Copyright:    Copyright (c) 1991-1999 Microsoft Corporation
'
' Contents:
'
' Comments:
'
'-----------------------------------------------------------------------------

Public conn As New ADODB.Connection
Public rs As New ADODB.Recordset
'Private WithEvents connEvh As ADODB.Connection
'Private WithEvents rsEvh As ADODB.Recordset

Private Sub Class_Initialize()
    'Set connEvh = conn
    'Set rsEvh = rs
End Sub

Private Sub Class_Terminate()
    Set conn = Nothing
    Set rs = Nothing
End Sub
