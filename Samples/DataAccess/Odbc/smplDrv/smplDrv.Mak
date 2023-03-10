!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on SmplDrv.dsp
!IF "$(CFG)" == ""
CFG=SmplDrv - Win32 Debug
!MESSAGE No configuration specified. Defaulting to SmplDrv - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "SmplDrv - Win32 Release" && "$(CFG)" != "SmplDrv - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SmplDrv.mak" CFG="SmplDrv - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SmplDrv - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SmplDrv - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "SmplDrv - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\SmplDrv.dll"


CLEAN :
	-@erase "$(INTDIR)\CONFDSN.OBJ"
	-@erase "$(INTDIR)\SMPLDRV.OBJ"
	-@erase "$(INTDIR)\SMPLDRV.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\SmplDrv.dll"
	-@erase "$(OUTDIR)\SmplDrv.exp"
	-@erase "$(OUTDIR)\SmplDrv.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SMPLDRV_EXPORTS" /Fp"$(INTDIR)\SmplDrv.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SMPLDRV.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SmplDrv.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\SmplDrv.pdb" /machine:I386 /out:"$(OUTDIR)\SmplDrv.dll" /implib:"$(OUTDIR)\SmplDrv.lib" 
LINK32_OBJS= \
	"$(INTDIR)\CONFDSN.OBJ" \
	"$(INTDIR)\SMPLDRV.OBJ" \
	"$(INTDIR)\SMPLDRV.res"

"$(OUTDIR)\SmplDrv.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "SmplDrv - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\SmplDrv.dll"


CLEAN :
	-@erase "$(INTDIR)\CONFDSN.OBJ"
	-@erase "$(INTDIR)\SMPLDRV.OBJ"
	-@erase "$(INTDIR)\SMPLDRV.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\SmplDrv.dll"
	-@erase "$(OUTDIR)\SmplDrv.exp"
	-@erase "$(OUTDIR)\SmplDrv.ilk"
	-@erase "$(OUTDIR)\SmplDrv.lib"
	-@erase "$(OUTDIR)\SmplDrv.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SMPLDRV_EXPORTS" /Fp"$(INTDIR)\SmplDrv.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SMPLDRV.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SmplDrv.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\SmplDrv.pdb" /debug /machine:I386 /out:"$(OUTDIR)\SmplDrv.dll" /implib:"$(OUTDIR)\SmplDrv.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\CONFDSN.OBJ" \
	"$(INTDIR)\SMPLDRV.OBJ" \
	"$(INTDIR)\SMPLDRV.res"

"$(OUTDIR)\SmplDrv.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("SmplDrv.dep")
!INCLUDE "SmplDrv.dep"
!ELSE 
!MESSAGE Warning: cannot find "SmplDrv.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "SmplDrv - Win32 Release" || "$(CFG)" == "SmplDrv - Win32 Debug"
SOURCE=.\CONFDSN.C

"$(INTDIR)\CONFDSN.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SMPLDRV.C

"$(INTDIR)\SMPLDRV.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SMPLDRV.RC

"$(INTDIR)\SMPLDRV.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

