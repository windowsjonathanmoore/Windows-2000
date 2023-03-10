# Microsoft Developer Studio Generated NMAKE File, Based on sclient.dsp
!IF "$(CFG)" == ""
CFG=sclient - Win32 AnsiDebug
!MESSAGE No configuration specified. Defaulting to sclient - Win32 AnsiDebug.
!ENDIF 

!IF "$(CFG)" != "sclient - Win32 Release" && "$(CFG)" != "sclient - Win32 Debug" && "$(CFG)" != "sclient - Win32 AnsiDebug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sclient.mak" CFG="sclient - Win32 AnsiDebug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sclient - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "sclient - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "sclient - Win32 AnsiDebug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "sclient - Win32 Release"

OUTDIR=.\..\bin\Release\x86
INTDIR=.\Release\x86
# Begin Custom Macros
OutDir=.\..\bin\Release\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\sclient.exe"

!ELSE 

ALL : "sserver - Win32 Release" "psidl - Win32 Release" "ps - Win32 Release" "$(OUTDIR)\sclient.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"ps - Win32 ReleaseCLEAN" "psidl - Win32 ReleaseCLEAN" "sserver - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\IAC.OBJ"
	-@erase "$(INTDIR)\SCLIENT.OBJ"
	-@erase "$(INTDIR)\server_i.obj"
	-@erase "$(INTDIR)\setparam.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\sclient.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\ps_win32" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_WIN32_DCOM" /D "UNICODE" /D "_UNICODE" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sclient.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\sclient.pdb" /machine:I386 /out:"$(OUTDIR)\sclient.exe" 
LINK32_OBJS= \
	"$(INTDIR)\IAC.OBJ" \
	"$(INTDIR)\SCLIENT.OBJ" \
	"$(INTDIR)\setparam.obj" \
	"$(INTDIR)\server_i.obj" \
	"$(OUTDIR)\ps.lib"

"$(OUTDIR)\sclient.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "sclient - Win32 Debug"

OUTDIR=.\..\bin\debug\x86
INTDIR=.\debug\x86
# Begin Custom Macros
OutDir=.\..\bin\debug\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\sclient.exe"

!ELSE 

ALL : "sserver - Win32 Debug" "psidl - Win32 Debug" "ps - Win32 Debug" "$(OUTDIR)\sclient.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"ps - Win32 DebugCLEAN" "psidl - Win32 DebugCLEAN" "sserver - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\IAC.OBJ"
	-@erase "$(INTDIR)\SCLIENT.OBJ"
	-@erase "$(INTDIR)\server_i.obj"
	-@erase "$(INTDIR)\setparam.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\sclient.exe"
	-@erase "$(OUTDIR)\sclient.ilk"
	-@erase "$(OUTDIR)\sclient.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\ps_win32" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "UNICODE" /D "_UNICODE" /D "_WIN32_DCOM" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sclient.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\sclient.pdb" /debug /machine:I386 /out:"$(OUTDIR)\sclient.exe" 
LINK32_OBJS= \
	"$(INTDIR)\IAC.OBJ" \
	"$(INTDIR)\SCLIENT.OBJ" \
	"$(INTDIR)\setparam.obj" \
	"$(INTDIR)\server_i.obj" \
	"$(OUTDIR)\ps.lib"

"$(OUTDIR)\sclient.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "sclient - Win32 AnsiDebug"

OUTDIR=.\..\bin\AnsiDebug\x86
INTDIR=.\AnsiDebug\x86
# Begin Custom Macros
OutDir=.\..\bin\AnsiDebug\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\sclient.exe"

!ELSE 

ALL : "sserver - Win32 AnsiDebug" "$(OUTDIR)\sclient.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"sserver - Win32 AnsiDebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\IAC.OBJ"
	-@erase "$(INTDIR)\SCLIENT.OBJ"
	-@erase "$(INTDIR)\server_i.obj"
	-@erase "$(INTDIR)\setparam.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\sclient.exe"
	-@erase "$(OUTDIR)\sclient.ilk"
	-@erase "$(OUTDIR)\sclient.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\ps_win32" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_WIN32_DCOM" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sclient.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\sclient.pdb" /debug /machine:I386 /out:"$(OUTDIR)\sclient.exe" 
LINK32_OBJS= \
	"$(INTDIR)\IAC.OBJ" \
	"$(INTDIR)\SCLIENT.OBJ" \
	"$(INTDIR)\setparam.obj" \
	"$(INTDIR)\server_i.obj"

"$(OUTDIR)\sclient.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("sclient.dep")
!INCLUDE "sclient.dep"
!ELSE 
!MESSAGE Warning: cannot find "sclient.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "sclient - Win32 Release" || "$(CFG)" == "sclient - Win32 Debug" || "$(CFG)" == "sclient - Win32 AnsiDebug"
SOURCE=.\IAC.CPP

"$(INTDIR)\IAC.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SCLIENT.CPP

"$(INTDIR)\SCLIENT.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=..\ps_win32\server_i.c

"$(INTDIR)\server_i.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\setparam.cpp

"$(INTDIR)\setparam.obj" : $(SOURCE) "$(INTDIR)"


!IF  "$(CFG)" == "sclient - Win32 Release"

"ps - Win32 Release" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps.mak CFG="ps - Win32 Release" 
   cd "..\sclient"

"ps - Win32 ReleaseCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps.mak CFG="ps - Win32 Release" RECURSE=1 CLEAN 
   cd "..\sclient"

!ELSEIF  "$(CFG)" == "sclient - Win32 Debug"

"ps - Win32 Debug" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps.mak CFG="ps - Win32 Debug" 
   cd "..\sclient"

"ps - Win32 DebugCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps.mak CFG="ps - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\sclient"

!ELSEIF  "$(CFG)" == "sclient - Win32 AnsiDebug"

!ENDIF 

!IF  "$(CFG)" == "sclient - Win32 Release"

"psidl - Win32 Release" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Release" 
   cd "..\sclient"

"psidl - Win32 ReleaseCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Release" RECURSE=1 CLEAN 
   cd "..\sclient"

!ELSEIF  "$(CFG)" == "sclient - Win32 Debug"

"psidl - Win32 Debug" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Debug" 
   cd "..\sclient"

"psidl - Win32 DebugCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\sclient"

!ELSEIF  "$(CFG)" == "sclient - Win32 AnsiDebug"

!ENDIF 

!IF  "$(CFG)" == "sclient - Win32 Release"

"sserver - Win32 Release" : 
   cd ".\..\sserver"
   $(MAKE) /$(MAKEFLAGS) /F .\sserver.mak CFG="sserver - Win32 Release" 
   cd "..\sclient"

"sserver - Win32 ReleaseCLEAN" : 
   cd ".\..\sserver"
   $(MAKE) /$(MAKEFLAGS) /F .\sserver.mak CFG="sserver - Win32 Release" RECURSE=1 CLEAN 
   cd "..\sclient"

!ELSEIF  "$(CFG)" == "sclient - Win32 Debug"

"sserver - Win32 Debug" : 
   cd ".\..\sserver"
   $(MAKE) /$(MAKEFLAGS) /F .\sserver.mak CFG="sserver - Win32 Debug" 
   cd "..\sclient"

"sserver - Win32 DebugCLEAN" : 
   cd ".\..\sserver"
   $(MAKE) /$(MAKEFLAGS) /F .\sserver.mak CFG="sserver - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\sclient"

!ELSEIF  "$(CFG)" == "sclient - Win32 AnsiDebug"

"sserver - Win32 AnsiDebug" : 
   cd ".\..\sserver"
   $(MAKE) /$(MAKEFLAGS) /F .\sserver.mak CFG="sserver - Win32 AnsiDebug" 
   cd "..\sclient"

"sserver - Win32 AnsiDebugCLEAN" : 
   cd ".\..\sserver"
   $(MAKE) /$(MAKEFLAGS) /F .\sserver.mak CFG="sserver - Win32 AnsiDebug" RECURSE=1 CLEAN 
   cd "..\sclient"

!ENDIF 


!ENDIF 

