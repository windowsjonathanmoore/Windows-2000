# Microsoft Developer Studio Project File - Name="DQChatC" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=DQChatC - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DQChatC.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DQChatC.mak" CFG="DQChatC - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DQChatC - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DQChatC - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DQChatC - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "DQChatC - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "DQChatC - Win32 Release"
# Name "DQChatC - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ConfigDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DQChatC.cpp
# End Source File
# Begin Source File

SOURCE=.\DQChatC.rc
# End Source File
# Begin Source File

SOURCE=.\DQChatCDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\eigdataqueue.cpp
# End Source File
# Begin Source File

SOURCE=.\eigdataqueuectl.cpp
# End Source File
# Begin Source File

SOURCE=.\eigdataqueueitemw.cpp
# End Source File
# Begin Source File

SOURCE=.\MsgEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ConfigDlg.h
# End Source File
# Begin Source File

SOURCE=.\DQChatC.h
# End Source File
# Begin Source File

SOURCE=.\DQChatCDlg.h
# End Source File
# Begin Source File

SOURCE=.\eigdataqueue.h
# End Source File
# Begin Source File

SOURCE=.\eigdataqueuectl.h
# End Source File
# Begin Source File

SOURCE=.\eigdataqueueitemw.h
# End Source File
# Begin Source File

SOURCE=.\MsgEdit.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\DQChatC.ico
# End Source File
# Begin Source File

SOURCE=.\res\DQChatC.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section DQChatC : {0FC478A0-F77D-11D2-A6B6-0080C71B8071}
# 	2:21:DefaultSinkHeaderFile:eigdataqueuectl.h
# 	2:16:DefaultSinkClass:CEIGDataQueueCtl
# End Section
# Section DQChatC : {1A5E55A2-F77D-11D2-A6B6-0080C71B8071}
# 	2:5:Class:CEIGDataQueueItemW
# 	2:10:HeaderFile:eigdataqueueitemw.h
# 	2:8:ImplFile:eigdataqueueitemw.cpp
# End Section
# Section DQChatC : {0FC478A2-F77D-11D2-A6B6-0080C71B8071}
# 	2:5:Class:CEIGDataQueue
# 	2:10:HeaderFile:eigdataqueue.h
# 	2:8:ImplFile:eigdataqueue.cpp
# End Section
# Section DQChatC : {F82D83A0-F77C-11D2-A6B6-0080C71B8071}
# 	2:5:Class:CEIGDataQueueCtl
# 	2:10:HeaderFile:eigdataqueuectl.h
# 	2:8:ImplFile:eigdataqueuectl.cpp
# End Section
