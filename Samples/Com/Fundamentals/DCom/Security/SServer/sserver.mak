# Microsoft Developer Studio Generated NMAKE File, Based on sserver.dsp
!IF "$(CFG)" == ""
CFG=sserver - Win32 AnsiDebug
!MESSAGE No configuration specified. Defaulting to sserver - Win32 AnsiDebug.
!ENDIF 

!IF "$(CFG)" != "sserver - Win32 Release" && "$(CFG)" != "sserver - Win32 Debug" && "$(CFG)" != "sserver - Win32 AnsiDebug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sserver.mak" CFG="sserver - Win32 AnsiDebug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sserver - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "sserver - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "sserver - Win32 AnsiDebug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "sserver - Win32 Release"

OUTDIR=.\..\bin\Release\x86
INTDIR=.\Release\x86
# Begin Custom Macros
OutDir=.\..\bin\Release\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\sserver.exe"

!ELSE 

ALL : "psidl - Win32 Release" "ps - Win32 Release" "$(OUTDIR)\sserver.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"ps - Win32 ReleaseCLEAN" "psidl - Win32 ReleaseCLEAN" 
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

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\ps_win32" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_WIN32_DCOM" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sserver.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\sserver.pdb" /machine:I386 /out:"$(OUTDIR)\sserver.exe" 
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

!ELSEIF  "$(CFG)" == "sserver - Win32 Debug"

OUTDIR=.\..\bin\debug\x86
INTDIR=.\debug\x86
# Begin Custom Macros
OutDir=.\..\bin\debug\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\sserver.exe"

!ELSE 

ALL : "psidl - Win32 Debug" "ps - Win32 Debug" "$(OUTDIR)\sserver.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"ps - Win32 DebugCLEAN" "psidl - Win32 DebugCLEAN" 
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

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\ps_win32" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_WIN32_DCOM" /D "UNICODE" /D "_UNICODE" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sserver.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\sserver.pdb" /debug /machine:I386 /out:"$(OUTDIR)\sserver.exe" 
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

!ELSEIF  "$(CFG)" == "sserver - Win32 AnsiDebug"

OUTDIR=.\..\bin\AnsiDebug\x86
INTDIR=.\AnsiDebug\x86
# Begin Custom Macros
OutDir=.\..\bin\AnsiDebug\x86
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

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\ps_win32" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_WIN32_DCOM" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sserver.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\sserver.pdb" /debug /machine:I386 /out:"$(OUTDIR)\sserver.exe" 
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


!IF "$(CFG)" == "sserver - Win32 Release" || "$(CFG)" == "sserver - Win32 Debug" || "$(CFG)" == "sserver - Win32 AnsiDebug"
SOURCE=.\IAC.CPP

"$(INTDIR)\IAC.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=..\ps_win32\server_i.c

"$(INTDIR)\server_i.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\setparam.cpp

"$(INTDIR)\setparam.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SSERVER.CPP

"$(INTDIR)\SSERVER.OBJ" : $(SOURCE) "$(INTDIR)"


!IF  "$(CFG)" == "sserver - Win32 Release"

"ps - Win32 Release" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps.mak CFG="ps - Win32 Release" 
   cd "..\sserver"

"ps - Win32 ReleaseCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps.mak CFG="ps - Win32 Release" RECURSE=1 CLEAN 
   cd "..\sserver"

!ELSEIF  "$(CFG)" == "sserver - Win32 Debug"

"ps - Win32 Debug" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps.mak CFG="ps - Win32 Debug" 
   cd "..\sserver"

"ps - Win32 DebugCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\ps.mak CFG="ps - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\sserver"

!ELSEIF  "$(CFG)" == "sserver - Win32 AnsiDebug"

!ENDIF 

!IF  "$(CFG)" == "sserver - Win32 Release"

"psidl - Win32 Release" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Release" 
   cd "..\sserver"

"psidl - Win32 ReleaseCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Release" RECURSE=1 CLEAN 
   cd "..\sserver"

!ELSEIF  "$(CFG)" == "sserver - Win32 Debug"

"psidl - Win32 Debug" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Debug" 
   cd "..\sserver"

"psidl - Win32 DebugCLEAN" : 
   cd ".\..\ps"
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\sserver"

!ELSEIF  "$(CFG)" == "sserver - Win32 AnsiDebug"

!ENDIF 


!ENDIF 

