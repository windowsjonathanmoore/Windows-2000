!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1997-1999.  Microsoft Corporation.  All rights reserved.
#
# Microsoft Developer Studio Generated NMAKE File, Based on scardcom.dsp
!IF "$(CFG)" == ""
CFG=scardcom - Win32 Debug
!MESSAGE No configuration specified. Defaulting to scardcom - Win32 Debug.
!ENDIF

!IF "$(CFG)" != "scardcom - Win32 Release" && "$(CFG)" != "scardcom - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE CFG="scardcom - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "scardcom - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "scardcom - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE
!ERROR An invalid configuration is specified.
!ENDIF

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF

!IF  "$(CFG)" == "scardcom - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\scardcom.dll" "$(OUTDIR)\scardcom.tlb"


CLEAN :
        -@erase "$(INTDIR)\scardath.obj"
        -@erase "$(INTDIR)\scardcom.obj"
        -@erase "$(INTDIR)\scardcom.res"
        -@erase "$(INTDIR)\scardcom.tlb"
        -@erase "$(INTDIR)\scardfil.obj"
        -@erase "$(INTDIR)\scardman.obj"
        -@erase "$(INTDIR)\scardver.obj"
        -@erase "$(INTDIR)\stdafx.obj"
        -@erase "$(INTDIR)\vc60.idb"
        -@erase "$(INTDIR)\wrphelp.obj"
        -@erase "$(OUTDIR)\scardcom.dll"
        -@erase "$(OUTDIR)\scardcom.exp"
        -@erase "$(OUTDIR)\scardcom.lib"
        -@erase ".\scardcom.h"
        -@erase ".\scardcom_i.c"
        -@erase ".\scardcom_p.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Gz /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SCARDCOM_EXPORTS" /D "_WINDLL" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /win32
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\scardcom.res" /i "release" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\scardcom.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=/nologo /dll /incremental:no /pdb:"$(OUTDIR)\scardcom.pdb" /machine:I386 /def:".\scardcom.def" /out:"$(OUTDIR)\scardcom.dll" /implib:"$(OUTDIR)\scardcom.lib"
DEF_FILE= \
        ".\scardcom.def"
LINK32_OBJS= \
        "$(INTDIR)\scardath.obj" \
        "$(INTDIR)\scardcom.obj" \
        "$(INTDIR)\scardfil.obj" \
        "$(INTDIR)\scardman.obj" \
        "$(INTDIR)\scardver.obj" \
        "$(INTDIR)\stdafx.obj" \
        "$(INTDIR)\wrphelp.obj" \
        "$(INTDIR)\scardcom.res"

"$(OUTDIR)\scardcom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "scardcom - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\scardcom.dll"


CLEAN :
        -@erase "$(INTDIR)\scardath.obj"
        -@erase "$(INTDIR)\scardcom.obj"
        -@erase "$(INTDIR)\scardcom.res"
        -@erase "$(INTDIR)\scardcom.tlb"
        -@erase "$(INTDIR)\scardfil.obj"
        -@erase "$(INTDIR)\scardman.obj"
        -@erase "$(INTDIR)\scardver.obj"
        -@erase "$(INTDIR)\stdafx.obj"
        -@erase "$(INTDIR)\vc60.idb"
        -@erase "$(INTDIR)\vc60.pdb"
        -@erase "$(INTDIR)\wrphelp.obj"
        -@erase "$(OUTDIR)\scardcom.dll"
        -@erase "$(OUTDIR)\scardcom.exp"
        -@erase "$(OUTDIR)\scardcom.ilk"
        -@erase "$(OUTDIR)\scardcom.lib"
        -@erase "$(OUTDIR)\scardcom.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Gz /MDd /W3 /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SCARDCOM_EXPORTS" /D "_WINDLL" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /GZ /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /win32
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\scardcom.res" /i "debug" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\scardcom.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=/nologo /dll /incremental:yes /pdb:"$(OUTDIR)\scardcom.pdb" /debug /machine:I386 /def:".\scardcom.def" /out:"$(OUTDIR)\scardcom.dll" /implib:"$(OUTDIR)\scardcom.lib" /pdbtype:sept
DEF_FILE= \
        ".\scardcom.def"
LINK32_OBJS= \
        "$(INTDIR)\scardath.obj" \
        "$(INTDIR)\scardcom.obj" \
        "$(INTDIR)\scardfil.obj" \
        "$(INTDIR)\scardman.obj" \
        "$(INTDIR)\scardver.obj" \
        "$(INTDIR)\stdafx.obj" \
        "$(INTDIR)\wrphelp.obj" \
        "$(INTDIR)\scardcom.res"

"$(OUTDIR)\scardcom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF


.\scardcom.h : \
        ".\scardcom.idl"\


.\scardcom_i.c : \
        ".\scardcom.idl"\


.\scardcom_p.c : \
        ".\scardcom.idl"\


.\scardath.cpp : \
        "..\..\..\..\include\scardssp.h"\
        ".\resource.h"\
        ".\scardath.h"\
        ".\scardcom.h"\
        ".\scarddef.h"\
        ".\scardman.h"\
        ".\stdafx.h"\
        ".\wrphelp.h"\


.\scardcom.cpp : \
        "..\..\..\..\include\scardssp.h"\
        ".\resource.h"\
        ".\scardath.h"\
        ".\scardcom.h"\
        ".\scardcom_i.c"\
        ".\scardfil.h"\
        ".\scardman.h"\
        ".\scardver.h"\
        ".\stdafx.h"\
        ".\wrphelp.h"\


.\scardcom.rc : \
        ".\Debug\scardcom.tlb"\
        ".\resource.h"\
        ".\SCardCom.rc2"\


.\scardfil.cpp : \
        "..\..\..\..\include\scardssp.h"\
        ".\resource.h"\
        ".\scardcom.h"\
        ".\scarddef.h"\
        ".\scardfil.h"\
        ".\scardman.h"\
        ".\stdafx.h"\
        ".\wrphelp.h"\


.\scardman.cpp : \
        "..\..\..\..\include\scardssp.h"\
        "..\..\..\..\include\scardssp_i.c"\
        ".\resource.h"\
        ".\scardcom.h"\
        ".\scardman.h"\
        ".\stdafx.h"\
        ".\wrphelp.h"\


.\scardver.cpp : \
        "..\..\..\..\include\scardssp.h"\
        ".\resource.h"\
        ".\scardcom.h"\
        ".\scarddef.h"\
        ".\scardman.h"\
        ".\scardver.h"\
        ".\stdafx.h"\
        ".\wrphelp.h"\


.\stdafx.cpp : \
        "..\..\..\..\include\scardssp.h"\
        ".\stdafx.h"\
        ".\wrphelp.h"\


.\wrphelp.cpp : \
        "..\..\..\..\include\scardssp.h"\
        ".\scarddef.h"\
        ".\stdafx.h"\
        ".\wrphelp.h"\


!IF "$(CFG)" == "scardcom - Win32 Release" || "$(CFG)" == "scardcom - Win32 Debug"
SOURCE=.\scardath.cpp

"$(INTDIR)\scardath.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\scardcom.cpp

"$(INTDIR)\scardcom.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\scardcom.idl

!IF  "$(CFG)" == "scardcom - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\scardcom.tlb" /win32

"$(INTDIR)\scardcom.tlb" : $(SOURCE) "$(INTDIR)"
        $(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "scardcom - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\scardcom.tlb" /win32

"$(INTDIR)\scardcom.tlb" : $(SOURCE) "$(INTDIR)"
        $(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=.\scardcom.rc

"$(INTDIR)\scardcom.res" : $(SOURCE) "$(INTDIR)"
        $(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\scardfil.cpp

"$(INTDIR)\scardfil.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\scardman.cpp

"$(INTDIR)\scardman.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\scardver.cpp

"$(INTDIR)\scardver.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\stdafx.cpp

"$(INTDIR)\stdafx.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\wrphelp.cpp

"$(INTDIR)\wrphelp.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF

