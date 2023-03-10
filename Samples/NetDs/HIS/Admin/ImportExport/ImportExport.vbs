
'********************************************************************
'*
'* File:    HISCFG.VBS - version 1.2
'* 
'* Purpose:	Import/Export the SNA configuration in MOF format
'*			(nb: relies on "mofcomp.exe" for importing)
'* 
'* Usage: 
'*			HISCFG [/S:server] [/N:namespace] [/C:class] [/O:outputfile] [/U:username] [/W:password] [/Q]
'*
'*									or			
'*
'*			HISCFG [/I:inputfilename]
'*
'* Copyright (C) Microsoft Corporation. All rights reserved.
'*
'********************************************************************

OPTION EXPLICIT
ON ERROR RESUME NEXT

'Define constants
CONST CONST_ERROR				= 0
CONST CONST_WSCRIPT             = 1
CONST CONST_CSCRIPT             = 2
CONST CONST_SHOW_USAGE          = 3
CONST CONST_EXPORT	            = 4
CONST CONST_IMPORT				= 5

CONST WMI_IMPERSONATE_LEVEL     = 3 'objects will use credentials of the caller
CONST IMPORT_COMMAND			= "%SystemRoot%\system32\WBEM\mofcomp.exe"

'Declare variables
Dim strFile, intOpMode, blnQuiet, i
Dim strServer, strNameSpace, strClass, strUserName, strPassword
ReDim strArgumentArray(0)

'Initialize variables
strArgumentArray(0) = ""
blnQuiet			= False
strClass			= ""
strServer			= ""
strNameSpace		= "root\microsoftHis"
strUserName			= ""
strPassword			= ""
strFile				= ""

'********************************************************************
'*
'* Main program
'*
'********************************************************************

	'Get the command line arguments
	For i = 0 to Wscript.arguments.count - 1
		ReDim Preserve strArgumentArray(i)
		strArgumentArray(i) = Wscript.arguments.Item(i)
	Next
	
	'Check whether the script is run using CScript
	intChkProgram()

	'Parse the command line
	intOpMode = intParseCmdLine(strArgumentArray, strServer, strNameSpace, strClass, _
				strUserName, strPassword, strFile, blnQuiet)
	If Err.Number then
		Print "Error 0x" & CStr(Hex(Err.Number)) & " occurred in parsing the command line."
		If Err.Description <> "" Then
			Print "Error description: " & Err.Description & "."
		End If
		WScript.Quit
	End If

	'Perform the requested actions
	Select Case intOpMode
		Case CONST_SHOW_USAGE
			Call ShowUsage()
		Case CONST_IMPORT
			Call Import(strFile)
		Case CONST_EXPORT
			Call Export(strServer, strNameSpace, strClass, strUserName, strPassword, strFile)
		Case CONST_ERROR
			'Do nothing.
		Case Else                    'Default -- should never happen
			Print "Error occurred in passing parameters."
	End Select


'********************************************************************
'*
'* Sub ImportInstances()
'* Purpose: Import instances of WBEM classes from a file.
'* Input:   strFile			a file name uses for output/input
'*
'********************************************************************
Private Sub Import(strFile)

    ON ERROR RESUME NEXT
	
	Dim shell, nRetCode, strCommand

	'Create the Shell object which allows us to run commands
	set shell = CreateObject("WScript.Shell")
    If Err.Number then
        Print "Error 0x" & CStr(Hex(Err.Number)) & " creating the Shell object."
        If Err.Description <> "" Then
            Print "Error description: " & Err.Description & "."
        End If
        Exit Sub
    End If

	'Execute mofcomp on the file and namespace specified
	strCommand = IMPORT_COMMAND & " /n:" & strNameSpace & " " & strFile

	nRetCode = shell.Run(strCommand, 0, true)

	If nRetCode = 0 then
		Print strFile & " was successfully imported into the " & strNameSpace _
			& " namespace."
	Else
		Print "Error 0x" & CStr(Hex(nRetCode)) & " while importing."
		Print "Error description: An error occurred while processing items into the " & _
			strNameSpace & " namespace from file " & strFile &"."
	End If

End Sub

'********************************************************************
'*
'* Sub Export()
'* Purpose: Enumerates instances of a WBEM class or classes within a namespace.
'* Input:   strServer       a machine name
'*          strNameSpace    a namespace
'*          strClass        a class name
'*          strUserName     the current user's name
'*          strPassword     the current user's password
'*          strFile			a file name uses for output/input
'* Output:  Results of the search are either printed on screen or saved in strFile.
'*
'********************************************************************
Private Sub Export(strServer, strNameSpace, strClass, strUserName, strPassword, strFile)

    ON ERROR RESUME NEXT

    Dim objFileSystem, objOutputFile, objService, objClass

    If strFile = "" Then
        objOutputFile = ""
    Else

        'Create a file object
        set objFileSystem = CreateObject("Scripting.FileSystemObject")
        If Err.Number then
            Print "Error 0x" & CStr(Hex(Err.Number)) & " opening a filesystem object."
            If Err.Description <> "" Then
                Print "Error description: " & Err.Description & "."
            End If
            Exit Sub
        End If

        'Open the file for output
		set objOutputFile = objFileSystem.OpenTextFile(strFile, 2, True)
        If Err.Number then
            Print "Error 0x" & CStr(Hex(Err.Number)) & " opening file " & strFile
            If Err.Description <> "" Then
                Print "Error description: " & Err.Description & "."
            End If
            Exit Sub
        End If
    End If

    'Establish a connection with the server.
    If blnConnect(objService, strServer, strNameSpace, strUserName, strPassword) Then
        Exit Sub
    End If

	'If no class is specified, export all the msSna_Config classes and their associations
	If strClass <> "" Then
		Call EnumInstancesRecursive(objService, strClass, objOutputFile)
	Else
	'These must be exported in this speceifc order to satisfy dependancy issues
		Call EnumInstancesRecursive(objService, "MsSna_Server", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_Connection", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_LuPrint", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_PoolDisplay", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_LuDisplay", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_PoolLua", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_LuLua", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_TN3270Session", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_PoolDown", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_LuDown", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_AppcMode", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_LuAppcRemote", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_LuAppcLocal", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_Cpic", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_PrintSession", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_TN5250Definition", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_AS400", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_AS400Folder", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_AppcPartner", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_ConfiguredUser", objOutputFile)
		Call EnumInstancesRecursive(objService, "MsSna_Workstation", objOutputFile)
		Call EnumInstancesRecursive(objService, "Mssna_ResourceAssignedToUser ", objOutputFile)
		Call EnumInstancesRecursive(objService, "Mssna_ResourceAssignedToWorkstation", objOutputFile)
		Call EnumInstancesRecursive(objService, "Mssna_LU3270AssignedToPool", objOutputFile)
	End If

	If strFile <> "" Then
        objOutputFile.Close
        If intResult > 0 Then
            Print "Results are saved in file " & strFile & "."
        End If
    End If

End Sub

'********************************************************************
'*
'* Function blnConnect()
'* Purpose: Connects to machine strServer.
'* Input:   strServer       a machine name
'*          strNameSpace    a namespace
'*          strUserName     name of the current user
'*          strPassword     password of the current user
'* Output:  objService is returned  as a service object.
'*
'********************************************************************
Private Function blnConnect(objService, strServer, strNameSpace, strUserName, strPassword)

    ON ERROR RESUME NEXT

    Dim objLocator

    blnConnect = False     'There is no error.

    ' Create Locator object to connect to remote CIM object manager
    Set objLocator = CreateObject("WbemScripting.SWbemLocator")
    If Err.Number then
        Print "Error 0x" & CStr(Hex(Err.Number)) & " occurred in creating a locator object."
        If Err.Description <> "" Then
            Print "Error description: " & Err.Description & "."
        End If
        Err.Clear
        blnConnect = True     'An error occurred
        Exit Function
    End If

    ' Connect to the namespace which is either local or remote
    Set objService = objLocator.ConnectServer (strServer, strNameSpace, _
        strUserName, strPassword)
	ObjService.Security_.ImpersonationLevel = WMI_IMPERSONATE_LEVEL
    If Err.Number then
        Print "Error 0x" & CStr(Hex(Err.Number)) & " occurred in connecting to server " _
            & strServer & "."
        If Err.Description <> "" Then
            Print "Error description: " & Err.Description & "."
        End If
        Err.Clear
        blnConnect = True     'An error occurred
    End If

End Function

'********************************************************************
'*
'* Sub EnumInstancesRecursive()
'* Purpose: Recursively enumerates instances of a WBEM class or classes within a namespace.
'* Input:   objService      the service object
'*          strClass        the name of a class
'*          objOutputFile   an output file object
'* Output:  Results of the query are either printed on screen or saved in objOutputFile.
'*
'********************************************************************
Private Sub EnumInstancesRecursive(objService, ByVal strClass, objOutputFile)

    ON ERROR RESUME NEXT

    Dim colInstances, objInstance, objSubClass, strSubClass, strMessage

    Set colInstances = objService.InstancesOf(strClass)
    For Each objInstance in colInstances
        WriteLine objInstance.GetObjectText_(), objOutputFile
    Next
    If Err.Number Then
		If Err.Description <> "" Then
			Print "Error description: " & Err.Description & "."
		End If
		Err.Clear
    End If

End Sub

'********************************************************************
'*
'* Function intChkProgram()
'* Purpose: Determines which program is used to run this script.
'* Input:   None
'* Output:  intChkProgram is set to one of CONST_ERROR, CONST_WSCRIPT,
'*          and CONST_CSCRIPT.
'*
'********************************************************************
Private Function intChkProgram()

    ON ERROR RESUME NEXT

    Dim strFullName, strCommand, i, j

    'strFullName should be something like C:\WINDOWS\COMMAND\CSCRIPT.EXE
    strFullName = WScript.FullName
    If Err.Number then
        Print "Error 0x" & CStr(Hex(Err.Number)) & " occurred."
        If Err.Description <> "" Then
            If Err.Description <> "" Then
                Print "Error description: " & Err.Description & "."
            End If
        End If
        intChkProgram =  CONST_ERROR
        Exit Function
    End If

    i = InStr(1, strFullName, ".exe", 1)
    If i = 0 Then
        intChkProgram =  CONST_ERROR
        Exit Function
    Else
        j = InStrRev(strFullName, "\", i, 1)
        If j = 0 Then
            intChkProgram =  CONST_ERROR
            Exit Function
        Else
            strCommand = Mid(strFullName, j+1, i-j-1)
            Select Case LCase(strCommand)
                Case "cscript"
                    intChkProgram = CONST_CSCRIPT
                Case "wscript"
		            intChkProgram =  CONST_WSCRIPT
					WScript.Echo "Please run this script using CScript." & vbCRLF & _
					"This can be achieved by" & vbCRLF & _
					"1. Using ""CScript [scriptname] [arguments]"" or" & vbCRLF & _
					"2. Changing the default Windows Scripting Host setting to CScript" & vbCRLF & _
					"    using ""CScript //H:CScript //S"" and then running the script." & vbCRLF
					WScript.Quit
                Case Else       'should never happen
                    Print "An unexpected program is used to run this script."
                    Print "Only CScript.Exe or WScript.Exe can be used to run this script."
            End Select
        End If
    End If

End Function

'********************************************************************
'*
'* Function intParseCmdLine()
'* Purpose: Parses the command line.
'* Input:   strArgumentArray    an array containing input from the command line
'* Output:  strServer           a machine name
'*          strNameSpace        a namespace
'*          strClass            a class name
'*          strFile				a file name used for output/input
'*          strUserName         the current user's name
'*          strPassword         the current user's password
'*          blnQuiet            specifies whether to suppress messages
'*          intParseCmdLine     is set to one of CONST_ERROR, CONST_SHOW_USAGE, CONST_EXPORT.
'*
'********************************************************************
Private Function intParseCmdLine(strArgumentArray, strServer, strNameSpace, strClass, _
    strUserName, strPassword, strFile, blnQuiet)

    ON ERROR RESUME NEXT

    Dim strFlag, i

    strFlag = strArgumentArray(0)

    If strFlag = "" then                'No arguments have been received
        intParseCmdLine = CONST_EXPORT
        Exit Function
    End If

    If (strFlag="help") OR (strFlag="/h") OR (strFlag="\h") OR (strFlag="-h") _
        OR (strFlag = "\?") OR (strFlag = "/?") OR (strFlag = "?") OR (strFlag="h") Then
        intParseCmdLine = CONST_SHOW_USAGE
        Exit Function
    End If

    For i = 0 to UBound(strArgumentArray)
        strFlag = LCase(Left(strArgumentArray(i), InStr(1, strArgumentArray(i), ":")-1))
        If Err.Number Then            'An error occurs if there is no : in the string
            Err.Clear
            Select Case LCase(strArgumentArray(i))
                Case "/q"
                    blnQuiet = True
                Case Else
                    Print strArgumentArray(i) & " is not a valid input."
                    Print "Please check the input and try again."
                    intParseCmdLine = CONST_ERROR
                    Exit Function
            End Select
        Else
            Select Case strFlag
                Case "/s"
                    strServer = Right(strArgumentArray(i), Len(strArgumentArray(i))-3)
                Case "/n"
                    strNameSpace = Right(strArgumentArray(i), Len(strArgumentArray(i))-3)
                Case "/c"
                    strClass = Right(strArgumentArray(i), Len(strArgumentArray(i))-3)
                Case "/u"
                    strUserName = Right(strArgumentArray(i), Len(strArgumentArray(i))-3)
                Case "/w"
                    strPassword = Right(strArgumentArray(i), Len(strArgumentArray(i))-3)
                Case "/o"
                    strFile = Right(strArgumentArray(i), Len(strArgumentArray(i))-3)
                Case "/i"
                    strFile = Right(strArgumentArray(i), Len(strArgumentArray(i))-3)
                    intParseCmdLine = CONST_IMPORT
                    Exit Function
                Case else
                    Print "Invalid flag " & """" & strFlag & ":""" & "."
                    Print "Please check the input and try again."
                    intParseCmdLine = CONST_ERROR
                    Exit Function
                End Select
        End If
    Next

    intParseCmdLine = CONST_EXPORT

End Function

'********************************************************************
'*
'* Sub ShowUsage()
'* Purpose: Shows the correct usage to the user.
'* Input:   None
'* Output:  Help messages are displayed on screen.
'*
'********************************************************************
Private Sub ShowUsage()

	Wscript.echo "Microsoft (R) Microsoft Host Integration Server Command Line Configurator"
	Wscript.echo "Copyright (C) Microsoft Corporation 1996-2000. All rights reserved."
    Wscript.echo 
	Wscript.echo "HISCFG [/C:class] [/O:outputfile] [/I:inputfile] [/S:server] [/U:username] [/W:password] [/Q]"
    Wscript.echo 
	Wscript.Echo "   class         Name of the parent class. Default is MsSna_Config."
    Wscript.Echo "   outputfile    The output file name to export to."
    Wscript.Echo "   inputfile     The input file name to import from."
	Wscript.Echo "   server        A machine name."
	Wscript.Echo "   username      The current user's name."
    Wscript.Echo "   password      Password of the current user."
    Wscript.Echo "   quiet         Does not display any status/error messages."
	Wscript.echo 
	Wscript.echo "Default settings will export entire SNA configuration to the screen."
	Wscript.echo 
End Sub

'********************************************************************
'*
'* Sub WriteLine()
'* Purpose: Writes a text line either to a file or on screen.
'* Input:   strMessage  the string to print
'*          objFile     an output file object
'* Output:  strMessage is either displayed on screen or written to a file.
'*
'********************************************************************
Sub WriteLine(ByRef strMessage, ByRef objFile)

	Dim search, lPos, sTemp
	
	If IsObject(objFile) then        'objFile should be a file object
		lPos = InStr(strMessage, CHR(10))
		while lPos > 0
			sTemp = Left(strMessage, lPos - 1) 'get rid of the \n 
			strMessage = Mid(strMessage, lPos + 1)
			lPos = InStr(strMessage, CHR(10))
			objFile.WriteLine sTemp
		Wend
	Else
        Wscript.Echo (strMessage)
    End If

End Sub

'********************************************************************
'*
'* Sub Print()
'* Purpose: Prints a message on screen if blnQuiet = False.
'* Input:   strMessage      the string to print
'* Output:  strMessage is printed on screen if blnQuiet = False.
'*
'********************************************************************
Sub Print(ByRef strMessage)
    If Not blnQuiet then
        Wscript.Echo  strMessage
    End If
End Sub

'********************************************************************
'*                                                                  *
'*                           End of File                            *
'*                                                                  *
'********************************************************************

