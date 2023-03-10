'******************************************************************************\
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
' ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
' TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.

' Copyright (C) 2000.  Microsoft Corporation.  All rights reserved.
' ******************************************************************************/

' Store.vbs
'
' VBScript to display all certificates in the current user MY store.
'

'
Option Explicit

Dim Store
Dim Certificate

Set Store = CreateObject("CAPICOM.Store")

Store.Open

For Each Certificate In Store.Certificates
    Certificate.Display
Next

Set Store = Nothing
