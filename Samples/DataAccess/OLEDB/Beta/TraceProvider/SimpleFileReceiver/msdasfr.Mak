!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on msdasfr.dsp
!IF "$(CFG)" == ""
CFG=msdasfr - Win32 Debug
!MESSAGE No configuration specified. Defaulting to msdasfr - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "msdasfr - Win32 Release" && "$(CFG)" != "msdasfr - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "msdasfr.mak" CFG="msdasfr - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "msdasfr - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "msdasfr - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "msdasfr - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\msdasfr.dll"


CLEAN :
	-@erase "$(INTDIR)\msdasfr.obj"
	-@erase "$(INTDIR)\SimpleFileReceiver.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\msdasfr.dll"
	-@erase "$(OUTDIR)\msdasfr.exp"
	-@erase "$(OUTDIR)\msdasfr.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MSDASFR_EXPORTS" /D "UNICODE" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\msdasfr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\msdasfr.pdb" /machine:I386 /def:".\msdasfr.def" /out:"$(OUTDIR)\msdasfr.dll" /implib:"$(OUTDIR)\msdasfr.lib" 
DEF_FILE= \
	".\msdasfr.def"
LINK32_OBJS= \
	"$(INTDIR)\SimpleFileReceiver.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\msdasfr.obj"

"$(OUTDIR)\msdasfr.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "msdasfr - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\msdasfr.dll"


CLEAN :
	-@erase "$(INTDIR)\msdasfr.obj"
	-@erase "$(INTDIR)\SimpleFileReceiver.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\msdasfr.dll"
	-@erase "$(OUTDIR)\msdasfr.exp"
	-@erase "$(OUTDIR)\msdasfr.ilk"
	-@erase "$(OUTDIR)\msdasfr.lib"
	-@erase "$(OUTDIR)\msdasfr.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MSDASFR_EXPORTS" /D "UNICODE" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /GZ  /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\msdasfr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\msdasfr.pdb" /debug /machine:I386 /def:".\msdasfr.def" /out:"$(OUTDIR)\msdasfr.dll" /implib:"$(OUTDIR)\msdasfr.lib" /pdbtype:sept 
DEF_FILE= \
	".\msdasfr.def"
LINK32_OBJS= \
	"$(INTDIR)\SimpleFileReceiver.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\msdasfr.obj"

"$(OUTDIR)\msdasfr.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("msdasfr.dep")
!INCLUDE "msdasfr.dep"
!ELSE 
!MESSAGE Warning: cannot find "msdasfr.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "msdasfr - Win32 Release" || "$(CFG)" == "msdasfr - Win32 Debug"
SOURCE=.\msdasfr.cpp

"$(INTDIR)\msdasfr.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SimpleFileReceiver.cpp

"$(INTDIR)\SimpleFileReceiver.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\StdAfx.cpp

"$(INTDIR)\StdAfx.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

