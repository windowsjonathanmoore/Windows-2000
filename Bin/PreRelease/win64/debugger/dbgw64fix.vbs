REM this .vbs file fixes upt he registry for the Visual C++ Win64 Debugger

dim p
dim incpath
dim shell

set shell = wscript.CreateObject("WScript.Shell")
p = wscript.ScriptFullName
REM strip of the name of the script file
p = Left(p, Len(p)-Len(wscript.ScriptName))

REM assume we are running script from
REM z:\stuff\morestuff\bin\Win64\debugger then includes are at
REM z:\stuff\morestuff\include\Win64\<various>

REM 19 is length of "bin\Win64\debugger\"
incpath = Left(p, Len(p)-19 ) + "include\Win64\"

shell.RegWrite "HKLM\SOFTWARE\Microsoft\DbgW64\7.0\Source Directories",incpath + "mfc;" + incpath +"crt;" + incpath + "atl"

REM make the icon
strDesktop = shell.SpecialFolders("Desktop")
set oShellLink = shell.CreateShortcut(strDesktop & "\Win64 Debugger.lnk")
oShellLink.TargetPath = p & "DbgW64.exe"
oShellLink.WindowStyle = 1
oShellLink.IconLocation = p & "DbgW64.exe, 0"
oShellLink.Description = "Visual C++ Win64 Debugger"
oShellLink.WorkingDirectory = p
oShellLink.Save
