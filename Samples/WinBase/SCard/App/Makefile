!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1997-1999.  Microsoft Corporation.  All rights reserved.
#
# Microsoft Developer Studio Generated NMAKE File, Based on scardtst.dsp
!IF "$(CFG)" == ""
CFG=scardtst - Win32 Debug
!MESSAGE No configuration specified. Defaulting to scardtst - Win32 Debug.
!ENDIF

!IF "$(CFG)" != "scardtst - Win32 Release" && "$(CFG)" != "scardtst - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE CFG="scardtst - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "scardtst - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "scardtst - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE
!ERROR An invalid configuration is specified.
!ENDIF

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF

!IF  "$(CFG)" == "scardtst - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0"

ALL : "$(OUTDIR)\scardtst.exe"

!ELSE

ALL : "scardcom - Win32 Release" "$(OUTDIR)\scardtst.exe"

!ENDIF

!IF "$(RECURSE)" == "1"
CLEAN :"scardcom - Win32 ReleaseCLEAN"
!ELSE
CLEAN :
!ENDIF
        -@erase "$(INTDIR)\PreApp.obj"
        -@erase "$(INTDIR)\SCardDG.obj"
        -@erase "$(INTDIR)\SCardTst.obj"
        -@erase "$(INTDIR)\SCardTst.res"
        -@erase "$(INTDIR)\scardwrp.obj"
        -@erase "$(INTDIR)\vc60.idb"
        -@erase "$(OUTDIR)\scardtst.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Gz /MD /W3 /GX /O1 /I "." /I "..\scardcom" /I "..\scardcom\cppwrap" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SCardTst.res" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\scardtst.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\scardtst.pdb" /machine:I386 /out:"$(OUTDIR)\scardtst.exe"
LINK32_OBJS= \
        "$(INTDIR)\PreApp.obj" \
        "$(INTDIR)\SCardDG.obj" \
        "$(INTDIR)\SCardTst.obj" \
        "$(INTDIR)\scardwrp.obj" \
        "$(INTDIR)\SCardTst.res" \
        "..\scardcom\Release\scardcom.lib"

"$(OUTDIR)\scardtst.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "scardtst - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0"

ALL : "$(OUTDIR)\scardtst.exe"

!ELSE

ALL : "scardcom - Win32 Debug" "$(OUTDIR)\scardtst.exe"

!ENDIF

!IF "$(RECURSE)" == "1"
CLEAN :"scardcom - Win32 DebugCLEAN"
!ELSE
CLEAN :
!ENDIF
        -@erase "$(INTDIR)\PreApp.obj"
        -@erase "$(INTDIR)\SCardDG.obj"
        -@erase "$(INTDIR)\SCardTst.obj"
        -@erase "$(INTDIR)\SCardTst.res"
        -@erase "$(INTDIR)\scardwrp.obj"
        -@erase "$(INTDIR)\vc60.idb"
        -@erase "$(INTDIR)\vc60.pdb"
        -@erase "$(OUTDIR)\scardtst.exe"
        -@erase "$(OUTDIR)\scardtst.ilk"
        -@erase "$(OUTDIR)\scardtst.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Gz /MDd /W3 /GX /ZI /Od /I "." /I "..\scardcom" /I "..\scardcom\cppwrap" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /GZ /c

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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SCardTst.res" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\scardtst.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\scardtst.pdb" /debug /machine:I386 /out:"$(OUTDIR)\scardtst.exe" /pdbtype:sept
LINK32_OBJS= \
        "$(INTDIR)\PreApp.obj" \
        "$(INTDIR)\SCardDG.obj" \
        "$(INTDIR)\SCardTst.obj" \
        "$(INTDIR)\scardwrp.obj" \
        "$(INTDIR)\SCardTst.res" \
        "..\scardcom\Debug\scardcom.lib"

"$(OUTDIR)\scardtst.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF


.\PreApp.Cpp : \
        ".\preapp.h"\


.\SCardDG.Cpp : \
        "..\..\..\..\include\scardssp.h"\
        "..\scardcom\cppwrap\scardwrp.h"\
        "..\scardcom\scardcom.h"\
        ".\preapp.h"\
        ".\resapp.h"\
        ".\scarddg.h"\
        ".\scardtst.h"\


.\SCardTst.Cpp : \
        ".\preapp.h"\
        ".\resapp.h"\
        ".\scarddg.h"\
        ".\scardtst.h"\


.\SCardTst.Rc : \
        ".\res\SCardTst.ico"\
        ".\res\SCardTst.rc2"\
        ".\resapp.h"\


..\scardcom\cppwrap\scardwrp.cpp : \
        "..\..\..\..\include\scardssp.h"\
        "..\..\..\..\include\scardssp_i.c"\
        "..\scardcom\cppwrap\scardwrp.h"\
        "..\scardcom\scardcom.h"\
        "..\scardcom\scardcom_i.c"\
        ".\preapp.h"\


!IF "$(CFG)" == "scardtst - Win32 Release" || "$(CFG)" == "scardtst - Win32 Debug"
SOURCE=.\PreApp.Cpp

"$(INTDIR)\PreApp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SCardDG.Cpp

"$(INTDIR)\SCardDG.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SCardTst.Cpp

"$(INTDIR)\SCardTst.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SCardTst.Rc

"$(INTDIR)\SCardTst.res" : $(SOURCE) "$(INTDIR)"
        $(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=..\scardcom\cppwrap\scardwrp.cpp

"$(INTDIR)\scardwrp.obj" : $(SOURCE) "$(INTDIR)"
        $(CPP) $(CPP_PROJ) $(SOURCE)


!IF  "$(CFG)" == "scardtst - Win32 Release"

"scardcom - Win32 Release" :
   cd "..\scardcom"
   $(MAKE) /$(MAKEFLAGS) CFG="scardcom - Win32 Release"
   cd "..\app"

"scardcom - Win32 ReleaseCLEAN" :
   cd "..\scardcom"
   $(MAKE) /$(MAKEFLAGS) CFG="scardcom - Win32 Release" RECURSE=1 CLEAN
   cd "..\app"

!ELSEIF  "$(CFG)" == "scardtst - Win32 Debug"

"scardcom - Win32 Debug" :
   cd "..\scardcom"
   $(MAKE) /$(MAKEFLAGS) CFG="scardcom - Win32 Debug"
   cd "..\app"

"scardcom - Win32 DebugCLEAN" :
   cd "..\scardcom"
   $(MAKE) /$(MAKEFLAGS) CFG="scardcom - Win32 Debug" RECURSE=1 CLEAN
   cd "..\app"

!ENDIF


!ENDIF

