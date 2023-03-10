!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on CrsrDemo.dsp
!IF "$(CFG)" == ""
CFG=CrsrDemo - Win32 Debug
!MESSAGE No configuration specified. Defaulting to CrsrDemo - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CrsrDemo - Win32 Release" && "$(CFG)" != "CrsrDemo - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CrsrDemo.mak" CFG="CrsrDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CrsrDemo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CrsrDemo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CrsrDemo - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CrsrDemo.exe"


CLEAN :
	-@erase "$(INTDIR)\child.obj"
	-@erase "$(INTDIR)\crsrdemo.obj"
	-@erase "$(INTDIR)\crsrdemo.res"
	-@erase "$(INTDIR)\dialogs.obj"
	-@erase "$(INTDIR)\frame.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CrsrDemo.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\CrsrDemo.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\crsrdemo.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CrsrDemo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\CrsrDemo.pdb" /machine:I386 /out:"$(OUTDIR)\CrsrDemo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\child.obj" \
	"$(INTDIR)\crsrdemo.obj" \
	"$(INTDIR)\crsrdemo.res" \
	"$(INTDIR)\dialogs.obj" \
	"$(INTDIR)\frame.obj" \
	"$(INTDIR)\headers.obj"

"$(OUTDIR)\CrsrDemo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CrsrDemo - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CrsrDemo.exe"


CLEAN :
	-@erase "$(INTDIR)\child.obj"
	-@erase "$(INTDIR)\crsrdemo.obj"
	-@erase "$(INTDIR)\crsrdemo.res"
	-@erase "$(INTDIR)\dialogs.obj"
	-@erase "$(INTDIR)\frame.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CrsrDemo.exe"
	-@erase "$(OUTDIR)\CrsrDemo.ilk"
	-@erase "$(OUTDIR)\CrsrDemo.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\CrsrDemo.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\crsrdemo.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CrsrDemo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\CrsrDemo.pdb" /debug /machine:I386 /out:"$(OUTDIR)\CrsrDemo.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\child.obj" \
	"$(INTDIR)\crsrdemo.obj" \
	"$(INTDIR)\crsrdemo.res" \
	"$(INTDIR)\dialogs.obj" \
	"$(INTDIR)\frame.obj" \
	"$(INTDIR)\headers.obj"

"$(OUTDIR)\CrsrDemo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

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


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("CrsrDemo.dep")
!INCLUDE "CrsrDemo.dep"
!ELSE 
!MESSAGE Warning: cannot find "CrsrDemo.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CrsrDemo - Win32 Release" || "$(CFG)" == "CrsrDemo - Win32 Debug"
SOURCE="..\..\..\..\Program Files\Microsoft Platform SDK\Samples\DataAccess\odbc\CrsrDemo\child.c"

"$(INTDIR)\child.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE="..\..\..\..\Program Files\Microsoft Platform SDK\Samples\DataAccess\odbc\CrsrDemo\crsrdemo.c"

"$(INTDIR)\crsrdemo.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE="..\..\..\..\Program Files\Microsoft Platform SDK\Samples\DataAccess\odbc\CrsrDemo\crsrdemo.Rc"

!IF  "$(CFG)" == "CrsrDemo - Win32 Release"


"$(INTDIR)\crsrdemo.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\crsrdemo.res" /i "\Program Files\Microsoft Platform SDK\Samples\DataAccess\odbc\CrsrDemo" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "CrsrDemo - Win32 Debug"


"$(INTDIR)\crsrdemo.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\crsrdemo.res" /i "\Program Files\Microsoft Platform SDK\Samples\DataAccess\odbc\CrsrDemo" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE="..\..\..\..\Program Files\Microsoft Platform SDK\Samples\DataAccess\odbc\CrsrDemo\dialogs.c"

"$(INTDIR)\dialogs.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE="..\..\..\..\Program Files\Microsoft Platform SDK\Samples\DataAccess\odbc\CrsrDemo\frame.c"

"$(INTDIR)\frame.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE="..\..\..\..\Program Files\Microsoft Platform SDK\Samples\DataAccess\odbc\CrsrDemo\headers.c"

"$(INTDIR)\headers.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

