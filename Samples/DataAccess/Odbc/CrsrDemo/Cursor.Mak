!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on Cursor.dsp
!IF "$(CFG)" == ""
CFG=Cursor - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Cursor - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Cursor - Win32 Release" && "$(CFG)" != "Cursor - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Cursor.mak" CFG="Cursor - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Cursor - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Cursor - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Cursor - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Cursor.exe"


CLEAN :
	-@erase "$(INTDIR)\CHILD.OBJ"
	-@erase "$(INTDIR)\CRSRDEMO.OBJ"
	-@erase "$(INTDIR)\CRSRDEMO.res"
	-@erase "$(INTDIR)\DIALOGS.OBJ"
	-@erase "$(INTDIR)\FRAME.OBJ"
	-@erase "$(INTDIR)\HEADERS.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Cursor.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Cursor.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CRSRDEMO.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Cursor.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Cursor.pdb" /machine:I386 /out:"$(OUTDIR)\Cursor.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CHILD.OBJ" \
	"$(INTDIR)\CRSRDEMO.OBJ" \
	"$(INTDIR)\DIALOGS.OBJ" \
	"$(INTDIR)\FRAME.OBJ" \
	"$(INTDIR)\HEADERS.OBJ" \
	"$(INTDIR)\CRSRDEMO.res"

"$(OUTDIR)\Cursor.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Cursor - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Cursor.exe"


CLEAN :
	-@erase "$(INTDIR)\CHILD.OBJ"
	-@erase "$(INTDIR)\CRSRDEMO.OBJ"
	-@erase "$(INTDIR)\CRSRDEMO.res"
	-@erase "$(INTDIR)\DIALOGS.OBJ"
	-@erase "$(INTDIR)\FRAME.OBJ"
	-@erase "$(INTDIR)\HEADERS.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Cursor.exe"
	-@erase "$(OUTDIR)\Cursor.ilk"
	-@erase "$(OUTDIR)\Cursor.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Cursor.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /GZ /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CRSRDEMO.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Cursor.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Cursor.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Cursor.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\CHILD.OBJ" \
	"$(INTDIR)\CRSRDEMO.OBJ" \
	"$(INTDIR)\DIALOGS.OBJ" \
	"$(INTDIR)\FRAME.OBJ" \
	"$(INTDIR)\HEADERS.OBJ" \
	"$(INTDIR)\CRSRDEMO.res"

"$(OUTDIR)\Cursor.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Cursor.dep")
!INCLUDE "Cursor.dep"
!ELSE 
!MESSAGE Warning: cannot find "Cursor.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Cursor - Win32 Release" || "$(CFG)" == "Cursor - Win32 Debug"
SOURCE=.\CHILD.C

"$(INTDIR)\CHILD.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\CRSRDEMO.C

"$(INTDIR)\CRSRDEMO.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\CRSRDEMO.RC

"$(INTDIR)\CRSRDEMO.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DIALOGS.C

"$(INTDIR)\DIALOGS.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\FRAME.C

"$(INTDIR)\FRAME.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\HEADERS.C

"$(INTDIR)\HEADERS.OBJ" : $(SOURCE) "$(INTDIR)"



!ENDIF 

