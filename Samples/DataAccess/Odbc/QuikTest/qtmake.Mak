!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on QuikTest.dsp
!IF "$(CFG)" == ""
CFG=QuikTest - Win32 Debug
!MESSAGE No configuration specified. Defaulting to QuikTest - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "QuikTest - Win32 Release" && "$(CFG)" != "QuikTest - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Qtmake.mak" CFG="QuikTest - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "QuikTest - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "QuikTest - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "QuikTest - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\QuikTest.dll"


CLEAN :
	-@erase "$(INTDIR)\dllstub.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\QuikTest.dll"
	-@erase "$(OUTDIR)\QuikTest.exp"
	-@erase "$(OUTDIR)\QuikTest.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "QUIKTEST_EXPORTS" /Fp"$(INTDIR)\QuikTest.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\QuikTest.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\QuikTest.pdb" /machine:I386 /out:"$(OUTDIR)\QuikTest.dll" /implib:"$(OUTDIR)\QuikTest.lib" 
LINK32_OBJS= \
	"$(INTDIR)\dllstub.obj"

"$(OUTDIR)\QuikTest.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "QuikTest - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\QuikTest.dll"


CLEAN :
	-@erase "$(INTDIR)\dllstub.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\QuikTest.dll"
	-@erase "$(OUTDIR)\QuikTest.exp"
	-@erase "$(OUTDIR)\QuikTest.ilk"
	-@erase "$(OUTDIR)\QuikTest.lib"
	-@erase "$(OUTDIR)\QuikTest.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "QUIKTEST_EXPORTS" /Fp"$(INTDIR)\QuikTest.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\QuikTest.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\QuikTest.pdb" /debug /machine:I386 /out:"$(OUTDIR)\QuikTest.dll" /implib:"$(OUTDIR)\QuikTest.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\dllstub.obj"

"$(OUTDIR)\QuikTest.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("QuikTest.dep")
!INCLUDE "QuikTest.dep"
!ELSE 
!MESSAGE Warning: cannot find "QuikTest.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "QuikTest - Win32 Release" || "$(CFG)" == "QuikTest - Win32 Debug"
SOURCE=..\dllstub.c

"$(INTDIR)\dllstub.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

