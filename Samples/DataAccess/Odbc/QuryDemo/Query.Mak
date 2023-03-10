!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on Query.dsp
!IF "$(CFG)" == ""
CFG=Query - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Query - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Query - Win32 Release" && "$(CFG)" != "Query - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Query.mak" CFG="Query - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Query - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Query - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Query - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Query.exe"


CLEAN :
	-@erase "$(INTDIR)\MAIN.OBJ"
	-@erase "$(INTDIR)\QUERY.OBJ"
	-@erase "$(INTDIR)\QURYDEMO.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Query.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Query.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\QURYDEMO.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Query.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Query.pdb" /machine:I386 /out:"$(OUTDIR)\Query.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MAIN.OBJ" \
	"$(INTDIR)\QUERY.OBJ" \
	"$(INTDIR)\QURYDEMO.res"

"$(OUTDIR)\Query.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Query - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Query.exe"


CLEAN :
	-@erase "$(INTDIR)\MAIN.OBJ"
	-@erase "$(INTDIR)\QUERY.OBJ"
	-@erase "$(INTDIR)\QURYDEMO.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Query.exe"
	-@erase "$(OUTDIR)\Query.ilk"
	-@erase "$(OUTDIR)\Query.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Query.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\QURYDEMO.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Query.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Query.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Query.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\MAIN.OBJ" \
	"$(INTDIR)\QUERY.OBJ" \
	"$(INTDIR)\QURYDEMO.res"

"$(OUTDIR)\Query.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Query.dep")
!INCLUDE "Query.dep"
!ELSE 
!MESSAGE Warning: cannot find "Query.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Query - Win32 Release" || "$(CFG)" == "Query - Win32 Debug"
SOURCE=.\MAIN.C

"$(INTDIR)\MAIN.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\QUERY.C

"$(INTDIR)\QUERY.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\QURYDEMO.RC

"$(INTDIR)\QURYDEMO.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

