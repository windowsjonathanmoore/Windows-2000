<!-- 
 File:         rdstest.asp
 Copyright:    Copyright (c) 1991-1999 Microsoft Corporation
-->
<HTML>
<HEAD>
<TITLE>RDS Sample Query Page</TITLE>
</HEAD>
<BODY BACKGROUND="../AddrBook/Arcadia.gif">

<CENTER>
<H1>Remote Data Service Sample Query Page</H1>

<table>
	<tr><td>RDS Server: </td><td><INPUT NAME=Server   SIZE=70> </td></tr>
	<tr><td>Connection: </td><td><INPUT NAME=Connect  SIZE=70> </td></tr>
	<tr><td>Query:      </td><td><INPUT NAME=SQL      SIZE=70> </td></tr>
	<tr><td>Execute Opt:</td><td><INPUT NAME=ExecType SIZE=70> </td></tr>
</table>

<!--Result columns -->
<INPUT TYPE=TEXT NAME=Name0 SIZE=15> <INPUT TYPE=TEXT NAME=COL0 SIZE=30 DATASRC="#DC1"><br>
<INPUT TYPE=TEXT NAME=Name1 SIZE=15> <INPUT TYPE=TEXT NAME=COL1 SIZE=30 DATASRC="#DC1"><br>
<INPUT TYPE=TEXT NAME=Name2 SIZE=15> <INPUT TYPE=TEXT NAME=COL2 SIZE=30 DATASRC="#DC1"><br>
<INPUT TYPE=TEXT NAME=Name3 SIZE=15> <INPUT TYPE=TEXT NAME=COL3 SIZE=30 DATASRC="#DC1"><br>
<INPUT TYPE=TEXT NAME=Name4 SIZE=15> <INPUT TYPE=TEXT NAME=COL4 SIZE=30 DATASRC="#DC1"><br>
<INPUT TYPE=TEXT NAME=Name5 SIZE=15> <INPUT TYPE=TEXT NAME=COL5 SIZE=30 DATASRC="#DC1"><br>
<INPUT TYPE=TEXT NAME=Name6 SIZE=15> <INPUT TYPE=TEXT NAME=COL6 SIZE=30 DATASRC="#DC1"><br>
<INPUT TYPE=TEXT NAME=Name7 SIZE=15> <INPUT TYPE=TEXT NAME=COL7 SIZE=30 DATASRC="#DC1"><br>
<INPUT TYPE=TEXT NAME=Name8 SIZE=15> <INPUT TYPE=TEXT NAME=COL8 SIZE=30 DATASRC="#DC1"><br>
<INPUT TYPE=TEXT NAME=Name9 SIZE=15> <INPUT TYPE=TEXT NAME=COL9 SIZE=30 DATASRC="#DC1">
<HR>

<INPUT TYPE=BUTTON NAME="Requery"   VALUE="Run!">
<INPUT TYPE=BUTTON NAME="MoveFirst" VALUE="First">
<INPUT TYPE=BUTTON NAME="MovePrev"  VALUE="Prev">
<INPUT TYPE=BUTTON NAME="MoveNext"  VALUE="Next">
<INPUT TYPE=BUTTON NAME="MoveLast"  VALUE="Last"> 
<HR>

<INPUT TYPE=BUTTON NAME="Update"    VALUE="Save Changes">
<INPUT TYPE=BUTTON NAME="Cancel"    VALUE="Cancel Changes">
<HR>

<INPUT TYPE=BUTTON NAME="Stop"      VALUE="Cancel Query">
<INPUT TYPE=BUTTON NAME="Asynchoff" VALUE="Turn Asynch off">
<INPUT TYPE=BUTTON NAME="Asynchon"  VALUE="Turn Asynch on">

<OBJECT classid="clsid:BD96C556-65A3-11D0-983A-00C04FC29E33" 
        ID=DC1 HEIGHT=1 WIDTH=1>
</OBJECT>

<SCRIPT LANGUAGE="VBScript">
'---- enum Values ----
Const adcExecSync = 1
Const adcExecAsync = 2

'---- enum Values ----
Const adcFetchUpFront = 1
Const adcFetchBackground = 2
Const adcFetchAsync = 3

'---- enum Values ----
Const adcStateClosed = &H00000000
Const adcStateOpen = &H00000001
Const adcStateConnecting = &H00000002
Const adcStateExecuting = &H00000004
Const adcStateFetching = &H00000008

'---- enum Values ----
Const adcReadyStateUninitialized = 0
Const adcReadyStateLoading = 1
Const adcReadyStateLoaded = 2
Const adcReadyStateInteractive = 3
Const adcReadyStateComplete = 4


Sub Window_OnLoad
	Dim sProvider
	Dim sDataSrc
	Dim sDataSrcPath
	Dim sConnString
    
	sProvider = "Microsoft.Jet.OLEDB.4.0"
  
 ' The following lines assign a value to the datasource parameter of the connection string.
 ' The code derives the path from the URL path of this asp file. 
 ' The default is C:\Program Files\Platform SDK\samples\dataaccess\rds\rdstest.
 ' If the AdvWorks.mdb file is located somewhere else on your web server, 
 ' replace sDataSrc value with the correct path on your web server.
 
	sDataSrcPath = "<%= Left(Request.ServerVariables("PATH_TRANSLATED"), InStrRev(Request.ServerVariables("PATH_TRANSLATED"),"\"))%>"
  	sDataSrc  = sDataSrcPath & "AdvWorks.mdb"
	sConnString = "Provider=" & sProvider & ";Data Source=" & sDataSrc & ";"

	Server.Value  = "http://<%=Request.ServerVariables("SERVER_NAME")%>"
   	Connect.Value = sConnString  	
   	SQL.Value = "Select * from Products"
   	
	If DC1.ExecuteOptions = adcExecSync Then 
		ExecType.value="Synchronous" 
	Else 
		ExecType.value="Asynchronous"
	End If
End Sub

Sub DC1_OnDataSetChanged
  'Fires after execution is done
  ' Set the names of each field.
  If (DC1.Recordset.Fields.count) > 0 Then Name0.Value=DC1.Recordset.Fields(0).name
  If (DC1.Recordset.Fields.count) > 1 Then Name1.Value=DC1.Recordset.Fields(1).name
  If (DC1.Recordset.Fields.count) > 2 Then Name2.Value=DC1.Recordset.Fields(2).name
  If (DC1.Recordset.Fields.count) > 3 Then Name3.Value=DC1.Recordset.Fields(3).name
  If (DC1.Recordset.Fields.count) > 4 Then Name4.Value=DC1.Recordset.Fields(4).name
  If (DC1.Recordset.Fields.count) > 5 Then Name5.Value=DC1.Recordset.Fields(5).name
  If (DC1.Recordset.Fields.count) > 6 Then Name6.Value=DC1.Recordset.Fields(6).name
  If (DC1.Recordset.Fields.count) > 7 Then Name7.Value=DC1.Recordset.Fields(7).name
  If (DC1.Recordset.Fields.count) > 8 Then Name8.Value=DC1.Recordset.Fields(8).name
  If (DC1.Recordset.Fields.count) > 9 Then Name9.Value=DC1.Recordset.Fields(9).name
End Sub

Sub DC1_OnDataSetComplete
  'Fires after fetching is complete
  If (DC1.Recordset.Fields.count) > 0 Then COL0.DATAFLD=DC1.Recordset.Fields(0).name
  If (DC1.Recordset.Fields.count) > 1 Then COL1.DATAFLD=DC1.Recordset.Fields(1).name
  If (DC1.Recordset.Fields.count) > 2 Then COL2.DATAFLD=DC1.Recordset.Fields(2).name
  If (DC1.Recordset.Fields.count) > 3 Then COL3.DATAFLD=DC1.Recordset.Fields(3).name
  If (DC1.Recordset.Fields.count) > 4 Then COL4.DATAFLD=DC1.Recordset.Fields(4).name
  If (DC1.Recordset.Fields.count) > 5 Then COL5.DATAFLD=DC1.Recordset.Fields(5).name
  If (DC1.Recordset.Fields.count) > 6 Then COL6.DATAFLD=DC1.Recordset.Fields(6).name
  If (DC1.Recordset.Fields.count) > 7 Then COL7.DATAFLD=DC1.Recordset.Fields(7).name
  If (DC1.Recordset.Fields.count) > 8 Then COL8.DATAFLD=DC1.Recordset.Fields(8).name
  If (DC1.Recordset.Fields.count) > 9 Then COL9.DATAFLD=DC1.Recordset.Fields(9).name  
End Sub

Sub DC1_onReadyStateChange
  'Move to first record when available.
  If DC1.ReadyState = adcReadyStateComplete Then
    Move "First"
  End If
End Sub

Sub Move (strDirection)
	'Custom Sub to handle Asyncronous fetching
	'Asynchronous fetching allows you to cancel in the middle of fetching a large
	'recordset
	If DC1.Recordset.State = adcStateClosed Then
		If DC1.ReadyState = adcReadyStateComplete Then
			msgbox "Query results failed to arrive, please rerun query synchronously and check for errors."
		End If
		If DC1.ReadyState = adcReadyStateLoaded Then
			msgbox "Query results have not yet arrived"	
		End If
	Else
		If DC1.Recordset.State = adcStateOpen Then	
			Select Case strDirection
				Case "First"
					DC1.Recordset.MoveFirst
				Case "Next"
					If Not DC1.Recordset.EOF Then
						DC1.Recordset.MoveNext
					End If
				Case "Last"
					DC1.Recordset.MoveLast
				Case "Prev"
					If Not DC1.Recordset.BOF Then
						DC1.Recordset.MovePrevious
					End If
 			End Select
		Else
     			msgbox "The state is unexpected, an error has occurred"   'Very General error msg. 
   		End If
	End If
End Sub

Sub MoveFirst_OnClick
	'Call to Custom Sub, Move, to handle attempts to move the record pointer during asynch fetches
	move "First"
End Sub

Sub MoveNext_OnClick
	'Call to Custom Sub, Move, to handle attempts to move the record pointer during asynch fetches
	Move "Next"
End Sub

Sub MovePrev_OnClick
	'Call to Custom Sub, Move, to handle attempts to move the record pointer during asynch fetches
	Move "Prev"
End Sub

Sub MoveLast_OnClick
	'Call to Custom Sub, Move, to handle attempts to move the record pointer during asynch fetches
	Move "Last"
End Sub

'Submits edits made and pulls a clean copy of the new data.
Sub Update_OnClick
	If DC1.ReadyState <> adcReadyStateLoaded Then
  		DC1.SubmitChanges
		DC1.Refresh
	Else
		MsgBox "Query results still arriving, Please wait"
	End If
End Sub

'Cancel edits and restores original values.
Sub Cancel_OnClick
	If DC1.ReadyState <> adcReadyStateLoaded Then
	  	DC1.CancelUpdate
  	Else
		MsgBox "Query results still arriving, Please wait"
	End If
End Sub

Sub Requery_OnClick
	If DC1.ReadyState <> adcReadyStateComplete Then
		MsgBox "Query results still arriving, Please wait"
	Else
		DC1.Server = Server.Value
	   	DC1.Connect = Connect.Value
   		DC1.SQL = SQL.Value

		' Clear the column names.
		Name0.Value=""
		Name1.Value=""
		Name2.Value=""
		Name3.Value=""
		Name4.Value=""
		Name5.Value=""
		Name6.Value=""
		Name7.Value=""
		Name8.Value=""
		Name9.Value=""
		
		' Clear the text box bindings
		COL0.DATAFLD=""
		COL1.DATAFLD=""
		COL2.DATAFLD=""
		COL3.DATAFLD=""
		COL4.DATAFLD=""
		COL5.DATAFLD=""
		COL6.DATAFLD=""
		COL7.DATAFLD=""
		COL8.DATAFLD=""
		COL9.DATAFLD=""
		
		' Clear the values  
		COL0.VALUE=""
		COL1.VALUE=""
		COL2.VALUE=""
		COL3.VALUE=""
		COL4.VALUE=""
		COL5.VALUE=""
		COL6.VALUE=""
		COL7.VALUE=""
		COL8.VALUE=""
		COL9.VALUE=""

		DC1.Refresh
	End If
End Sub

Sub Stop_OnClick
  'If an asychronous query is taking too long to execute you can use this to cancel the query
  DC1.Cancel
End Sub

Sub Asynchoff_OnClick
  'In cases where there are problems querying the database you may need to switch to synchronous mode
  'in order to get the error
  DC1.ExecuteOptions = adcExecSync
  DC1.FetchOptions   = adcFetchBackground
  ExecType.value     = "Synchronous" 
End Sub

Sub Asynchon_OnClick
  'In cases where there are problems querying the database you may need to switch to synchronous mode
  'in order to get the error
  DC1.ExecuteOptions = adcExecAsync
  DC1.FetchOptions   = adcFetchAsync
  ExecType.value     = "Asynchronous" 
End Sub

</SCRIPT>
</BODY>
</HTML>
