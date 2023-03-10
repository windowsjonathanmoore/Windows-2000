!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1997-1999.  Microsoft Corporation.  All rights reserved.
#
# Microsoft Developer Studio Generated NMAKE File, Based on aggtest.dsp
!IF "$(CFG)" == ""
CFG=aggtest - Win32 Debug
!MESSAGE No configuration specified. Defaulting to aggtest - Win32 Debug.
!ENDIF

!IF "$(CFG)" != "aggtest - Win32 Release" && "$(CFG)" != "aggtest - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE CFG="aggtest - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "aggtest - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "aggtest - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE
!ERROR An invalid configuration is specified.
!ENDIF

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF

!IF  "$(CFG)" == "aggtest - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0"

ALL : "$(OUTDIR)\aggtest.exe"

!ELSE

ALL : "scardagg - Win32 Release" "$(OUTDIR)\aggtest.exe"

!ENDIF

!IF "$(RECURSE)" == "1"
CLEAN :"scardagg - Win32 ReleaseCLEAN"
!ELSE
CLEAN :
!ENDIF
        -@erase "$(INTDIR)\aggtest.obj"
        -@erase "$(INTDIR)\vc60.idb"
        -@erase "$(OUTDIR)\aggtest.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Gz /MD /W3 /GX /O1 /I ".." /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c

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

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\aggtest.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=ole32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\aggtest.pdb" /machine:I386 /out:"$(OUTDIR)\aggtest.exe"
LINK32_OBJS= \
        "$(INTDIR)\aggtest.obj" \
        "..\Release\scardagg.lib"

"$(OUTDIR)\aggtest.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "aggtest - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0"

ALL : "$(OUTDIR)\aggtest.exe"

!ELSE

ALL : "scardagg - Win32 Debug" "$(OUTDIR)\aggtest.exe"

!ENDIF

!IF "$(RECURSE)" == "1"
CLEAN :"scardagg - Win32 DebugCLEAN"
!ELSE
CLEAN :
!ENDIF
        -@erase "$(INTDIR)\aggtest.obj"
        -@erase "$(INTDIR)\vc60.idb"
        -@erase "$(INTDIR)\vc60.pdb"
        -@erase "$(OUTDIR)\aggtest.exe"
        -@erase "$(OUTDIR)\aggtest.ilk"
        -@erase "$(OUTDIR)\aggtest.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Gz /MDd /W3 /GX /ZI /Od /I ".." /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /GZ /c

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

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\aggtest.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=ole32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\aggtest.pdb" /debug /machine:I386 /out:"$(OUTDIR)\aggtest.exe" /pdbtype:sept
LINK32_OBJS= \
        "$(INTDIR)\aggtest.obj" \
        "..\Debug\scardagg.lib"

"$(OUTDIR)\aggtest.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF


.\aggtest.cpp : \
        "..\..\..\..\..\include\scardssp.h"\
        "..\scardagg.h"\
        "..\scardagg_i.c"\


!IF "$(CFG)" == "aggtest - Win32 Release" || "$(CFG)" == "aggtest - Win32 Debug"
SOURCE=.\aggtest.cpp

"$(INTDIR)\aggtest.obj" : $(SOURCE) "$(INTDIR)"


!IF  "$(CFG)" == "aggtest - Win32 Release"

"scardagg - Win32 Release" :
   cd ".."
   $(MAKE) /$(MAKEFLAGS) CFG="scardagg - Win32 Release"
   cd ".\TEST"

"scardagg - Win32 ReleaseCLEAN" :
   cd ".."
   $(MAKE) /$(MAKEFLAGS) CFG="scardagg - Win32 Release" RECURSE=1 CLEAN
   cd ".\TEST"

!ELSEIF  "$(CFG)" == "aggtest - Win32 Debug"

"scardagg - Win32 Debug" :
   cd ".."
   $(MAKE) /$(MAKEFLAGS) CFG="scardagg - Win32 Debug"
   cd ".\TEST"

"scardagg - Win32 DebugCLEAN" :
   cd ".."
   $(MAKE) /$(MAKEFLAGS) CFG="scardagg - Win32 Debug" RECURSE=1 CLEAN
   cd ".\TEST"

!ENDIF


!ENDIF

