!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1997-1999.  Microsoft Corporation.  All rights reserved.
#
# Microsoft Developer Studio Generated NMAKE File, Based on scardagg.dsp
!IF "$(CFG)" == ""
CFG=scardagg - Win32 Debug
!MESSAGE No configuration specified. Defaulting to scardagg - Win32 Debug.
!ENDIF

!IF "$(CFG)" != "scardagg - Win32 Release" && "$(CFG)" != "scardagg - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE CFG="scardagg - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "scardagg - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "scardagg - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE
!ERROR An invalid configuration is specified.
!ENDIF

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF

!IF  "$(CFG)" == "scardagg - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0"

ALL : "$(OUTDIR)\scardagg.dll" "$(OUTDIR)\scardagg.tlb"

!ELSE

ALL : "scardcom - Win32 Release" "$(OUTDIR)\scardagg.dll" "$(OUTDIR)\scardagg.tlb"

!ENDIF

!IF "$(RECURSE)" == "1"
CLEAN :"scardcom - Win32 ReleaseCLEAN"
!ELSE
CLEAN :
!ENDIF
        -@erase "$(INTDIR)\preagg.obj"
        -@erase "$(INTDIR)\scardagg.obj"
        -@erase "$(INTDIR)\scardagg.res"
        -@erase "$(INTDIR)\scardagg.tlb"
        -@erase "$(INTDIR)\scardni.obj"
        -@erase "$(INTDIR)\vc60.idb"
        -@erase "$(OUTDIR)\scardagg.dll"
        -@erase "$(OUTDIR)\scardagg.exp"
        -@erase "$(OUTDIR)\scardagg.lib"
        -@erase ".\scardagg.h"
        -@erase ".\scardagg_i.c"
        -@erase ".\scardagg_p.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Gz /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SCARDAGG_EXPORTS" /D "_WINDLL" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\scardagg.res" /i "release" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\scardagg.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=/nologo /dll /incremental:no /pdb:"$(OUTDIR)\scardagg.pdb" /machine:I386 /def:".\scardagg.def" /out:"$(OUTDIR)\scardagg.dll" /implib:"$(OUTDIR)\scardagg.lib"
DEF_FILE= \
        ".\scardagg.def"
LINK32_OBJS= \
        "$(INTDIR)\preagg.obj" \
        "$(INTDIR)\scardagg.obj" \
        "$(INTDIR)\scardni.obj" \
        "$(INTDIR)\scardagg.res" \
        "..\scardcom\Release\scardcom.lib"

"$(OUTDIR)\scardagg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "scardagg - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0"

ALL : "$(OUTDIR)\scardagg.dll"

!ELSE

ALL : "scardcom - Win32 Debug" "$(OUTDIR)\scardagg.dll"

!ENDIF

!IF "$(RECURSE)" == "1"
CLEAN :"scardcom - Win32 DebugCLEAN"
!ELSE
CLEAN :
!ENDIF
        -@erase "$(INTDIR)\preagg.obj"
        -@erase "$(INTDIR)\scardagg.obj"
        -@erase "$(INTDIR)\scardagg.res"
        -@erase "$(INTDIR)\scardagg.tlb"
        -@erase "$(INTDIR)\scardni.obj"
        -@erase "$(INTDIR)\vc60.idb"
        -@erase "$(INTDIR)\vc60.pdb"
        -@erase "$(OUTDIR)\scardagg.dll"
        -@erase "$(OUTDIR)\scardagg.exp"
        -@erase "$(OUTDIR)\scardagg.ilk"
        -@erase "$(OUTDIR)\scardagg.lib"
        -@erase "$(OUTDIR)\scardagg.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Gz /MDd /W3 /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SCARDAGG_EXPORTS" /D "_WINDLL" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /GZ /c

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\scardagg.res" /i "debug" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\scardagg.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=/nologo /dll /incremental:yes /pdb:"$(OUTDIR)\scardagg.pdb" /debug /machine:I386 /def:".\scardagg.def" /out:"$(OUTDIR)\scardagg.dll" /implib:"$(OUTDIR)\scardagg.lib" /pdbtype:sept
DEF_FILE= \
        ".\scardagg.def"
LINK32_OBJS= \
        "$(INTDIR)\preagg.obj" \
        "$(INTDIR)\scardagg.obj" \
        "$(INTDIR)\scardni.obj" \
        "$(INTDIR)\scardagg.res" \
        "..\scardcom\Debug\scardcom.lib"

"$(OUTDIR)\scardagg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF


.\scardagg.h : \
        ".\scardagg.idl"\


.\scardagg_i.c : \
        ".\scardagg.idl"\


.\scardagg_p.c : \
        ".\scardagg.idl"\


.\preagg.cpp : \
        ".\preagg.h"\


.\scardagg.cpp : \
        "..\..\..\..\include\scardssp.h"\
        ".\dllaggx.h"\
        ".\preagg.h"\
        ".\resagg.h"\
        ".\scardagg.h"\
        ".\scardagg_i.c"\
        ".\scardni.h"\


.\scardagg.rc : \
        ".\Debug\scardagg.tlb"\
        ".\resagg.h"\


.\scardni.cpp : \
        "..\..\..\..\include\scardssp.h"\
        "..\..\..\..\include\scardssp_i.c"\
        ".\preagg.h"\
        ".\resagg.h"\
        ".\scardagg.h"\
        ".\scardni.h"\


!IF "$(CFG)" == "scardagg - Win32 Release" || "$(CFG)" == "scardagg - Win32 Debug"
SOURCE=.\preagg.cpp

"$(INTDIR)\preagg.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\scardagg.cpp

"$(INTDIR)\scardagg.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\scardagg.idl

!IF  "$(CFG)" == "scardagg - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\scardagg.tlb" /win32

"$(INTDIR)\scardagg.tlb" : $(SOURCE) "$(INTDIR)"
        $(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "scardagg - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\scardagg.tlb" /win32

"$(INTDIR)\scardagg.tlb" : $(SOURCE) "$(INTDIR)"
        $(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=.\scardagg.rc

"$(INTDIR)\scardagg.res" : $(SOURCE) "$(INTDIR)"
        $(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\scardni.cpp

"$(INTDIR)\scardni.obj" : $(SOURCE) "$(INTDIR)"


!IF  "$(CFG)" == "scardagg - Win32 Release"

"scardcom - Win32 Release" :
   cd "..\scardcom"
   $(MAKE) /$(MAKEFLAGS) CFG="scardcom - Win32 Release"
   cd "..\aggreg"

"scardcom - Win32 ReleaseCLEAN" :
   cd "..\scardcom"
   $(MAKE) /$(MAKEFLAGS) CFG="scardcom - Win32 Release" RECURSE=1 CLEAN
   cd "..\aggreg"

!ELSEIF  "$(CFG)" == "scardagg - Win32 Debug"

"scardcom - Win32 Debug" :
   cd "..\scardcom"
   $(MAKE) /$(MAKEFLAGS) CFG="scardcom - Win32 Debug"
   cd "..\aggreg"

"scardcom - Win32 DebugCLEAN" :
   cd "..\scardcom"
   $(MAKE) /$(MAKEFLAGS) CFG="scardcom - Win32 Debug" RECURSE=1 CLEAN
   cd "..\aggreg"

!ENDIF


!ENDIF

