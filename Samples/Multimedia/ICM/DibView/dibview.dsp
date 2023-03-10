# Microsoft Developer Studio Project File - Name="dibview" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=dibview - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "dibview.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dibview.mak" CFG="dibview - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dibview - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "dibview - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "dibview - Win32 Release ICM Inside DC" (based on "Win32 (x86) Application")
!MESSAGE "dibview - Win32 Debug ICM Inside DC " (based on "Win32 (x86) Application")
!MESSAGE "dibview - Win32 Release ICM Outside DC " (based on "Win32 (x86) Application")
!MESSAGE "dibview - Win32 Debug ICM Outside DC " (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "dibview - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /Zi /O2 /I "..\inc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "MULTIMON_ENABLED" /Yu"pch.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL"
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL"
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_UNICODE" /d "UNICODE" /d "MULTIMON_ENABLED"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 comctl32.lib version.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib /nologo /subsystem:windows /debug /machine:I386

!ELSEIF  "$(CFG)" == "dibview - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /ZI /Od /I "..\inc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "MULTIMON_ENABLED" /FR /Yu"pch.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL"
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL"
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "MULTIMON_ENABLED"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 comctl32.lib version.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ELSEIF  "$(CFG)" == "dibview - Win32 Release ICM Inside DC"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "InRelease"
# PROP BASE Intermediate_Dir "InRelease"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "InRelease"
# PROP Intermediate_Dir "InRelease"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /Zi /O2 /I "..\inc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "MULTIMON_ENABLED" /D "ICM_INSIDE_DC" /Yu"pch.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL"
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL"
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_UNICODE" /d "UNICODE" /d "MULTIMON_ENABLED" /d "ICM_INSIDE_DC"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib mscms.lib icmui.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 comctl32.lib version.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib /nologo /subsystem:windows /debug /machine:I386

!ELSEIF  "$(CFG)" == "dibview - Win32 Debug ICM Inside DC "

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "InDebug"
# PROP BASE Intermediate_Dir "InDebug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "InDebug"
# PROP Intermediate_Dir "InDebug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /ZI /Od /I "..\inc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "MULTIMON_ENABLED" /D "ICM_INSIDE_DC" /FR /Yu"pch.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL"
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL"
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "MULTIMON_ENABLED" /d "ICM_INSIDE_DC"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib mscms.lib icmui.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 comctl32.lib version.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ELSEIF  "$(CFG)" == "dibview - Win32 Release ICM Outside DC "

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "OutRelease"
# PROP BASE Intermediate_Dir "OutRelease"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "OutRelease"
# PROP Intermediate_Dir "OutRelease"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /Zi /O2 /I "..\inc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "MULTIMON_ENABLED" /D "ICM_OUTSIDE_DC" /Yu"pch.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL"
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL"
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "ICM_ENABLED"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_UNICODE" /d "UNICODE" /d "MULTIMON_ENABLED" /d "ICM_OUTSIDE_DC"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 mscms.lib icmui.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 comctl32.lib version.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib /nologo /subsystem:windows /debug /machine:I386

!ELSEIF  "$(CFG)" == "dibview - Win32 Debug ICM Outside DC "

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "OutDebug"
# PROP BASE Intermediate_Dir "OutDebug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "OutDebug"
# PROP Intermediate_Dir "OutDebug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /ZI /Od /I "..\inc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "MULTIMON_ENABLED" /D "ICM_OUTSIDE_DC" /FR /Yu"pch.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL"
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL"
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "ICM_ENABLED"
# ADD RSC /l 0x409 /d "_DEBUG" /d "MULTIMON_ENABLED" /d "ICM_OUTSIDE_DC"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 mscms.lib icmui.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 comctl32.lib version.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "dibview - Win32 Release"
# Name "dibview - Win32 Debug"
# Name "dibview - Win32 Release ICM Inside DC"
# Name "dibview - Win32 Debug ICM Inside DC "
# Name "dibview - Win32 Release ICM Outside DC "
# Name "dibview - Win32 Debug ICM Outside DC "
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\about.c
# End Source File
# Begin Source File

SOURCE=.\clipboard.c
# End Source File
# Begin Source File

SOURCE=.\CMMman.c
# End Source File
# Begin Source File

SOURCE=.\construct.c
# End Source File
# Begin Source File

SOURCE=.\convert.c
# End Source File
# Begin Source File

SOURCE=.\dib.c
# End Source File
# Begin Source File

SOURCE=.\dibview.c
# End Source File
# Begin Source File

SOURCE=.\document.c
# End Source File
# Begin Source File

SOURCE=.\ffilter.c
# End Source File
# Begin Source File

SOURCE=.\global.c
# End Source File
# Begin Source File

SOURCE=.\icm.c
# End Source File
# Begin Source File

SOURCE=.\icon.c
# End Source File
# Begin Source File

SOURCE=.\implement.c
# End Source File
# Begin Source File

SOURCE=.\mmon.c
# End Source File
# Begin Source File

SOURCE=.\pch.c
# ADD CPP /Yc"pch.h"
# End Source File
# Begin Source File

SOURCE=.\print.c
# End Source File
# Begin Source File

SOURCE=.\SelSource.c
# End Source File
# Begin Source File

SOURCE=.\settings.c
# End Source File
# Begin Source File

SOURCE=.\twain.c
# End Source File
# Begin Source File

SOURCE=.\window.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\bitmapwin.h
# End Source File
# Begin Source File

SOURCE=..\inc\check.h
# End Source File
# Begin Source File

SOURCE=.\CMMman.h
# End Source File
# Begin Source File

SOURCE=..\inc\conv.h
# End Source File
# Begin Source File

SOURCE=.\Convert.h
# End Source File
# Begin Source File

SOURCE=.\dibview.h
# End Source File
# Begin Source File

SOURCE=.\ffilter.h
# End Source File
# Begin Source File

SOURCE=.\global.h
# End Source File
# Begin Source File

SOURCE=..\inc\ICMStubs.h
# End Source File
# Begin Source File

SOURCE=.\inline.h
# End Source File
# Begin Source File

SOURCE=..\inc\MMStubs.h
# End Source File
# Begin Source File

SOURCE=..\inc\pch.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\SelSource.h
# End Source File
# Begin Source File

SOURCE=..\inc\STIStubs.h
# End Source File
# Begin Source File

SOURCE=..\inc\TwainStubs.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\dibview.rc
# End Source File
# Begin Source File

SOURCE=.\imagelist.bmp
# End Source File
# End Group
# End Target
# End Project
