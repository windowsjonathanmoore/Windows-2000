# Microsoft Developer Studio Project File - Name="TableCopy" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TableCopy - Win32 x86 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TableCopy.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TableCopy.mak" CFG="TableCopy - Win32 x86 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TableCopy - Win32 x86 Release" (based on "Win32 (x86) Application")
!MESSAGE "TableCopy - Win32 x86 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TableCopy - Win32 x86 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\TableCop"
# PROP BASE Intermediate_Dir ".\TableCop"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "x86\Release"
# PROP Intermediate_Dir "x86\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O1 /D "NDEBUG" /FR /YX /c
# ADD CPP /nologo /W3 /O1 /I "..\..\INCLUDE" /D "NDEBUG" /FD /c
# SUBTRACT CPP /WX /Fr /YX
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 oledb.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 oledb.lib msvcrt.lib kernel32.lib ole32.lib oleaut32.lib user32.lib uuid.lib comctl32.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib /libpath:"..\..\LIB\$(PROCESSOR_ARCHITECTURE)"

!ELSEIF  "$(CFG)" == "TableCopy - Win32 x86 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\TableCo0"
# PROP BASE Intermediate_Dir ".\TableCo0"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "x86\Debug"
# PROP Intermediate_Dir "x86\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "FINDLEAKS" /FR /YX /c
# ADD CPP /nologo /W3 /Gm /Gi /ZI /Od /I "..\..\INCLUDE" /D "_DEBUG" /D "FINDLEAKS" /FD /c
# SUBTRACT CPP /WX /Fr /YX
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 oledb.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 oledb.lib msvcrt.lib kernel32.lib ole32.lib oleaut32.lib user32.lib uuid.lib comctl32.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib /libpath:"..\..\LIB\$(PROCESSOR_ARCHITECTURE)"

!ENDIF 

# Begin Target

# Name "TableCopy - Win32 x86 Release"
# Name "TableCopy - Win32 x86 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\COMMON.CPP
# End Source File
# Begin Source File

SOURCE=.\DataSource.cpp
# End Source File
# Begin Source File

SOURCE=.\Error.cpp
# End Source File
# Begin Source File

SOURCE=.\PROGRESS.CPP
# End Source File
# Begin Source File

SOURCE=.\Property.cpp
# End Source File
# Begin Source File

SOURCE=.\Spy.cpp
# End Source File
# Begin Source File

SOURCE=.\STEP1.CPP
# End Source File
# Begin Source File

SOURCE=.\STEP2.CPP
# End Source File
# Begin Source File

SOURCE=.\STEP3.CPP
# End Source File
# Begin Source File

SOURCE=.\STEP4.CPP
# End Source File
# Begin Source File

SOURCE=.\Table.cpp
# End Source File
# Begin Source File

SOURCE=.\TableCopy.cpp
# End Source File
# Begin Source File

SOURCE=.\TableCopy.rc
# End Source File
# Begin Source File

SOURCE=.\WinMain.cpp
# End Source File
# Begin Source File

SOURCE=.\Wizard.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\COMMON.H
# End Source File
# Begin Source File

SOURCE=.\DataSource.h
# End Source File
# Begin Source File

SOURCE=.\Error.h
# End Source File
# Begin Source File

SOURCE=.\List.h
# End Source File
# Begin Source File

SOURCE=.\PROGRESS.H
# End Source File
# Begin Source File

SOURCE=.\Property.h
# End Source File
# Begin Source File

SOURCE=.\Spy.h
# End Source File
# Begin Source File

SOURCE=.\Table.h
# End Source File
# Begin Source File

SOURCE=.\TableCopy.h
# End Source File
# Begin Source File

SOURCE=.\version.h
# End Source File
# Begin Source File

SOURCE=.\WinMain.h
# End Source File
# Begin Source File

SOURCE=.\Wizard.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Catalog.ico
# End Source File
# Begin Source File

SOURCE=.\Column.ico
# End Source File
# Begin Source File

SOURCE=.\columnlong.ico
# End Source File
# Begin Source File

SOURCE=.\columnread.ico
# End Source File
# Begin Source File

SOURCE=.\Index.ico
# End Source File
# Begin Source File

SOURCE=.\PrimaryKey.ico
# End Source File
# Begin Source File

SOURCE=.\Schema.ico
# End Source File
# Begin Source File

SOURCE=.\SelTable.ico
# End Source File
# Begin Source File

SOURCE=.\SelType.ico
# End Source File
# Begin Source File

SOURCE=.\Synonym.ico
# End Source File
# Begin Source File

SOURCE=.\SysTable.ico
# End Source File
# Begin Source File

SOURCE=.\Table.ico
# End Source File
# Begin Source File

SOURCE=.\TABLE_CO.ICO
# End Source File
# Begin Source File

SOURCE=.\TableCopy.rc2
# End Source File
# Begin Source File

SOURCE=.\Type.ico
# End Source File
# Begin Source File

SOURCE=.\View.ico
# End Source File
# End Group
# End Target
# End Project
