# Microsoft Developer Studio Project File - Name="WMI" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=WMI - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "snapin.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "snapin.mak" CFG="WMI - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WMI - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "WMI - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WMI - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "WMI_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "WMI_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 COMCTL32.LIB kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib uuid.lib mmc.lib wbemuuid.lib /nologo /base:"0x11000000" /dll /machine:I386

!ELSEIF  "$(CFG)" == "WMI - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "WMI_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 COMCTL32.LIB kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib uuid.lib mmc.lib wbemuuid.lib /nologo /base:"0x11000000" /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Performing Registrations
OutDir=.\Debug
TargetPath=.\Debug\snapin.dll
InputPath=.\Debug\snapin.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "WMI - Win32 Release"
# Name "WMI - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\about.cpp
# End Source File
# Begin Source File

SOURCE=.\basesnap.cpp
# End Source File
# Begin Source File

SOURCE=.\comp.cpp
# End Source File
# Begin Source File

SOURCE=.\compdata.cpp
# End Source File
# Begin Source File

SOURCE=.\dataobj.cpp
# End Source File
# Begin Source File

SOURCE=.\delebase.cpp
# End Source File
# Begin Source File

SOURCE=.\equipment.cpp
# End Source File
# Begin Source File

SOURCE=.\mmccrack.cpp
# End Source File
# Begin Source File

SOURCE=.\registry.cpp
# End Source File
# Begin Source File

SOURCE=.\Resource.rc
# End Source File
# Begin Source File

SOURCE=.\snapin.def
# End Source File
# Begin Source File

SOURCE=.\statnode.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\about.h
# End Source File
# Begin Source File

SOURCE=.\basesnap.h
# End Source File
# Begin Source File

SOURCE=.\comp.h
# End Source File
# Begin Source File

SOURCE=.\compdata.h
# End Source File
# Begin Source File

SOURCE=.\dataobj.h
# End Source File
# Begin Source File

SOURCE=.\delebase.h
# End Source File
# Begin Source File

SOURCE=.\equipment.h
# End Source File
# Begin Source File

SOURCE=.\globals.h
# End Source File
# Begin Source File

SOURCE=.\guids.h
# End Source File
# Begin Source File

SOURCE=.\localres.h
# End Source File
# Begin Source File

SOURCE=.\registry.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\SimpleArray.h
# End Source File
# Begin Source File

SOURCE=.\statnode.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\lgbmp.bmp
# End Source File
# Begin Source File

SOURCE=.\lgicons.bmp
# End Source File
# Begin Source File

SOURCE=.\smbmp.bmp
# End Source File
# Begin Source File

SOURCE=.\smicons.bmp
# End Source File
# Begin Source File

SOURCE=.\smopen.bmp
# End Source File
# Begin Source File

SOURCE=.\snapin.ico
# End Source File
# End Group
# End Target
# End Project
