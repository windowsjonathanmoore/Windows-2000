
# Microsoft Developer Studio Generated NMAKE File, Based on sserver.dsp
!IF "$(CFG)" == ""
CFG=sserver - Win64 AnsiDebug
!MESSAGE No configuration specified. Defaulting to sserver - Win64 AnsiDebug.
!ENDIF 

!IF "$(CFG)" != "sserver - Win64 Release" && "$(CFG)" != "sserver - Win64 Debug" && "$(CFG)" != "sserver - Win64 AnsiDebug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sserver64.mak" CFG="sserver - Win64 AnsiDebug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sserver - Win64 Release" (based on "Win64 (IA64) Console Application")
!MESSAGE "sserver - Win64 Debug" (based on "Win64 (IA64) Console Application")
!MESSAGE "sserver - Win64 AnsiDebug" (based on "Win64 (IA64) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "sserver - Win64 Release"

OUTDIR=.\..\bin\Release\IA64
INTDIR=.\Release\IA64
# Begin Custom Macros
OutDir=.\..\bin\Release\IA64
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\sserver.exe"

!ELSE 

ALL : "psidl - Win64 Release" "ps - Win64 Release" "$(OUTDIR)\sserver.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"ps - Win64 ReleaseCLEAN" "psidl - Win64 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\IAC.OBJ"
	-@erase "$(INTDIR)\server_i.obj"
	-@erase "$(INTDIR)\setparam.obj"
	-@erase "$(INTDIR)\SSERVER.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\sserver.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /ML /W3 /Wp64 /GX /O2 /I "..\ps_win64" /D "NDEBUG" /D "WIN64" /D "WIN32"  /D "_CONSOLE" /D "_WIN32_DCOM" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sserver.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib atl21asm.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\sserver.pdb" /machine:IA64 /out:"$(OUTDIR)\sserver.exe" 
LINK32_OBJS= \
	"$(INTDIR)\IAC.OBJ" \
	"$(INTDIR)\setparam.obj" \
	"$(INTDIR)\SSERVER.OBJ" \
	"$(INTDIR)\server_i.obj" \
	"$(OUTDIR)\ps.lib"

"$(OUTDIR)\sserver.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "sserver - Win64 Debug"

OUTDIR=.\..\bin\debug\IA64
INTDIR=.\debug\IA64
# Begin Custom Macros
OutDir=.\..\bin\debug\IA64
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\sserver.exe"

!ELSE 

ALL : "psidl - Win64 Debug" "ps - Win64 Debug" "$(OUTDIR)\sserver.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"ps - Win64 DebugCLEAN" "psidl - Win64 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\IAC.OBJ"
	-@erase "$(INTDIR)\server_i.obj"
	-@erase "$(INTDIR)\setparam.obj"
	-@erase "$(INTDIR)\SSERVER.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\sserver.exe"
	-@erase "$(OUTDIR)\sserver.ilk"
	-@erase "$(OUTDIR)\sserver.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Wp64 /Gm /GX /Zi /Od /I "..\ps_win64" /D "_DEBUG" /D "WIN64" /D "WIN32"  /D "_CONSOLE" /D "_WIN32_DCOM" /D "UNICODE" /D "_UNICODE" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sserver.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib atl21asm.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\sserver.pdb" /debug /machine:IA64 /out:"$(OUTDIR)\sserver.exe" 
LINK32_OBJS= \
	"$(INTDIR)\IAC.OBJ" \
	"$(INTDIR)\setparam.obj" \
	"$(INTDIR)\SSERVER.OBJ" \
	"$(INTDIR)\server_i.obj" \
	"$(OUTDIR)\ps.lib"

"$(OUTDIR)\sserver.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "sserver - Win64 AnsiDebug"

OUTDIR=.\..\bin\AnsiDebug\IA64
INTDIR=.\AnsiDebug\IA64
# Begin Custom Macros
OutDir=.\..\bin\AnsiDebug\IA64
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\sserver.exe"

!ELSE 

ALL : "$(OUTDIR)\sserver.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\IAC.OBJ"
	-@erase "$(INTDIR)\server_i.obj"
	-@erase "$(INTDIR)\setparam.obj"
	-@erase "$(INTDIR)\SSERVER.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\sserver.exe"
	-@erase "$(OUTDIR)\sserver.ilk"
	-@erase "$(OUTDIR)\sserver.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Wp64 /Gm /GX /Zi /Od /I "..\ps_win64" /D "_DEBUG" /D "WIN64" /D "WIN32"  /D "_CONSOLE" /D "_WIN32_DCOM" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sserver.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib atl21asm.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\sserver.pdb" /debug /machine:IA64 /out:"$(OUTDIR)\sserver.exe" 
LINK32_OBJS= \
	"$(INTDIR)\IAC.OBJ" \
	"$(INTDIR)\setparam.obj" \
	"$(INTDIR)\SSERVER.OBJ" \
	"$(INTDIR)\server_i.obj"

"$(OUTDIR)\sserver.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("sserver.dep")
!INCLUDE "sserver.dep"
!ELSE 
!MESSAGE Warning: cannot find "sserver.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "sserver - Win64 Release" || "$(CFG)" == "sserver - Win64 Debug" || "$(CFG)" == "sserver - Win64 AnsiDebug"
SOURCE=.\IAC.CPP

"$(INTDIR)\IAC.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=..\ps_win64\server_i.c

"$(INTDIR)\server_i.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\setparam.cpp

"$(INTDIR)\setparam.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SSERVER.CPP

"$(INTDIR)\SSERVER.OBJ" : $(SOURCE) "$(INTDIR)"


!IF  "$(CFG)" == "sserver - Win64 Release"

"ps - Win64 Release" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps64.mak CFG="ps - Win64 Release" 
   cd "..\sserver"

"ps - Win64 ReleaseCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps64.mak CFG="ps - Win64 Release" RECURSE=1 CLEAN 
   cd "..\sserver"

!ELSEIF  "$(CFG)" == "sserver - Win64 Debug"

"ps - Win64 Debug" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps64.mak CFG="ps - Win64 Debug" 
   cd "..\sserver"

"ps - Win64 DebugCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps64.mak CFG="ps - Win64 Debug" RECURSE=1 CLEAN 
   cd "..\sserver"

!ELSEIF  "$(CFG)" == "sserver - Win64 AnsiDebug"

!ENDIF 

!IF  "$(CFG)" == "sserver - Win64 Release"

"psidl - Win64 Release" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl64.mak CFG="psidl - Win64 Release" 
   cd "..\sserver"

"psidl - Win64 ReleaseCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl64.mak CFG="psidl - Win64 Release" RECURSE=1 CLEAN 
   cd "..\sserver"

!ELSEIF  "$(CFG)" == "sserver - Win64 Debug"

"psidl - Win64 Debug" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl64.mak CFG="psidl - Win64 Debug" 
   cd "..\sserver"

"psidl - Win64 DebugCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl64.mak CFG="psidl - Win64 Debug" RECURSE=1 CLEAN 
   cd "..\sserver"

!ELSEIF  "$(CFG)" == "sserver - Win64 AnsiDebug"

!ENDIF 


!ENDIF 
