!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on AsyncDemo.dsp
!IF "$(CFG)" == ""
CFG=AsyncDemo - Win32 Debug
!MESSAGE No configuration specified. Defaulting to AsyncDemo - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "AsyncDemo - Win32 Release" && "$(CFG)" != "AsyncDemo - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AsyncDemo.mak" CFG="AsyncDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AsyncDemo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "AsyncDemo - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "AsyncDemo - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\AsyncDemo.exe"


CLEAN :
	-@erase "$(INTDIR)\AsyncDemo.obj"
	-@erase "$(INTDIR)\AsyncDemo.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\AsyncDemo.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\AsyncDemo.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AsyncDemo.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AsyncDemo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wininet.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\AsyncDemo.pdb" /machine:I386 /out:"$(OUTDIR)\AsyncDemo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AsyncDemo.obj" \
	"$(INTDIR)\AsyncDemo.res"

"$(OUTDIR)\AsyncDemo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "AsyncDemo - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\AsyncDemo.exe"


CLEAN :
	-@erase "$(INTDIR)\AsyncDemo.obj"
	-@erase "$(INTDIR)\AsyncDemo.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\AsyncDemo.exe"
	-@erase "$(OUTDIR)\AsyncDemo.ilk"
	-@erase "$(OUTDIR)\AsyncDemo.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\AsyncDemo.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AsyncDemo.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AsyncDemo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wininet.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\AsyncDemo.pdb" /debug /machine:I386 /out:"$(OUTDIR)\AsyncDemo.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AsyncDemo.obj" \
	"$(INTDIR)\AsyncDemo.res"

"$(OUTDIR)\AsyncDemo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("AsyncDemo.dep")
!INCLUDE "AsyncDemo.dep"
!ELSE 
!MESSAGE Warning: cannot find "AsyncDemo.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "AsyncDemo - Win32 Release" || "$(CFG)" == "AsyncDemo - Win32 Debug"
SOURCE=.\AsyncDemo.cpp

"$(INTDIR)\AsyncDemo.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\AsyncDemo.rc

"$(INTDIR)\AsyncDemo.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

