!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on admin.dsp
!IF "$(CFG)" == ""
CFG=admin - Win32 Debug
!MESSAGE No configuration specified. Defaulting to admin - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "admin - Win32 Release" && "$(CFG)" != "admin - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "admin.mak" CFG="admin - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "admin - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "admin - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "admin - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\admin.exe"


CLEAN :
	-@erase "$(INTDIR)\ADMNDEMO.OBJ"
	-@erase "$(INTDIR)\ADMNDEMO.res"
	-@erase "$(INTDIR)\DIALOGS.OBJ"
	-@erase "$(INTDIR)\ERRCHECK.OBJ"
	-@erase "$(INTDIR)\EXECUTE.OBJ"
	-@erase "$(INTDIR)\INFO.OBJ"
	-@erase "$(INTDIR)\INI.OBJ"
	-@erase "$(INTDIR)\MENU.OBJ"
	-@erase "$(INTDIR)\RESULTS.OBJ"
	-@erase "$(INTDIR)\STANDARD.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\admin.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\admin.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ADMNDEMO.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\admin.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\admin.pdb" /machine:I386 /out:"$(OUTDIR)\admin.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ADMNDEMO.OBJ" \
	"$(INTDIR)\DIALOGS.OBJ" \
	"$(INTDIR)\ERRCHECK.OBJ" \
	"$(INTDIR)\EXECUTE.OBJ" \
	"$(INTDIR)\INFO.OBJ" \
	"$(INTDIR)\INI.OBJ" \
	"$(INTDIR)\MENU.OBJ" \
	"$(INTDIR)\RESULTS.OBJ" \
	"$(INTDIR)\STANDARD.OBJ" \
	"$(INTDIR)\ADMNDEMO.res"

"$(OUTDIR)\admin.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "admin - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\admin.exe"


CLEAN :
	-@erase "$(INTDIR)\ADMNDEMO.OBJ"
	-@erase "$(INTDIR)\ADMNDEMO.res"
	-@erase "$(INTDIR)\DIALOGS.OBJ"
	-@erase "$(INTDIR)\ERRCHECK.OBJ"
	-@erase "$(INTDIR)\EXECUTE.OBJ"
	-@erase "$(INTDIR)\INFO.OBJ"
	-@erase "$(INTDIR)\INI.OBJ"
	-@erase "$(INTDIR)\MENU.OBJ"
	-@erase "$(INTDIR)\RESULTS.OBJ"
	-@erase "$(INTDIR)\STANDARD.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\admin.exe"
	-@erase "$(OUTDIR)\admin.ilk"
	-@erase "$(OUTDIR)\admin.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\admin.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ADMNDEMO.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\admin.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib gtrtst32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\admin.pdb" /debug /machine:I386 /out:"$(OUTDIR)\admin.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ADMNDEMO.OBJ" \
	"$(INTDIR)\DIALOGS.OBJ" \
	"$(INTDIR)\ERRCHECK.OBJ" \
	"$(INTDIR)\EXECUTE.OBJ" \
	"$(INTDIR)\INFO.OBJ" \
	"$(INTDIR)\INI.OBJ" \
	"$(INTDIR)\MENU.OBJ" \
	"$(INTDIR)\RESULTS.OBJ" \
	"$(INTDIR)\STANDARD.OBJ" \
	"$(INTDIR)\ADMNDEMO.res"

"$(OUTDIR)\admin.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("admin.dep")
!INCLUDE "admin.dep"
!ELSE 
!MESSAGE Warning: cannot find "admin.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "admin - Win32 Release" || "$(CFG)" == "admin - Win32 Debug"
SOURCE=.\ADMNDEMO.C

"$(INTDIR)\ADMNDEMO.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ADMNDEMO.RC

"$(INTDIR)\ADMNDEMO.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DIALOGS.C

"$(INTDIR)\DIALOGS.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ERRCHECK.C

"$(INTDIR)\ERRCHECK.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\EXECUTE.C

"$(INTDIR)\EXECUTE.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\INFO.C

"$(INTDIR)\INFO.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\INI.C

"$(INTDIR)\INI.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MENU.C

"$(INTDIR)\MENU.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\RESULTS.C

"$(INTDIR)\RESULTS.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\STANDARD.C

"$(INTDIR)\STANDARD.OBJ" : $(SOURCE) "$(INTDIR)"



!ENDIF 

