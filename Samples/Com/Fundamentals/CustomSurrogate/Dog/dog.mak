# Microsoft Developer Studio Generated NMAKE File, Based on dog.dsp
!IF "$(CFG)" == ""
CFG=dog - Win32 Release
!MESSAGE No configuration specified. Defaulting to dog - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "dog - Win32 Debug" && "$(CFG)" != "dog - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dog.mak" CFG="dog - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dog - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "dog - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "dog - Win32 Debug"

OUTDIR=.\..\Debug\x86
INTDIR=.\Debug\x86
# Begin Custom Macros
OutDir=.\..\Debug\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\dog.dll"

!ELSE 

ALL : "idl - Win32 Debug" "dogps - Win32 Debug" "$(OUTDIR)\dog.dll"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"dogps - Win32 DebugCLEAN" "idl - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\dog.obj"
	-@erase "$(INTDIR)\dogcf.obj"
	-@erase "$(INTDIR)\idog.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\dog.dll"
	-@erase "$(OUTDIR)\dog.exp"
	-@erase "$(OUTDIR)\dog.ilk"
	-@erase "$(OUTDIR)\dog.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MTd /W3 /GX /ZI /Od /I "..\idl\ps_win32" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\dog.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\dog.pdb" /debug /machine:I386 /out:"$(OUTDIR)\dog.dll" /implib:"$(OUTDIR)\dog.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\dog.obj" \
	"$(INTDIR)\dogcf.obj" \
	"$(INTDIR)\idog.obj" \
	"$(OUTDIR)\dogps.lib"

"$(OUTDIR)\dog.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "dog - Win32 Release"

OUTDIR=.\..\Release\x86
INTDIR=.\Release\x86
# Begin Custom Macros
OutDir=.\..\Release\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\dog.dll"

!ELSE 

ALL : "idl - Win32 Release" "dogps - Win32 Release" "$(OUTDIR)\dog.dll"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"dogps - Win32 ReleaseCLEAN" "idl - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\dog.obj"
	-@erase "$(INTDIR)\dogcf.obj"
	-@erase "$(INTDIR)\idog.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\dog.dll"
	-@erase "$(OUTDIR)\dog.exp"
	-@erase "$(OUTDIR)\dog.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /I "..\idl\ps_win32" /D "WIN32" /D "NDEBUG" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\dog.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\dog.pdb" /machine:I386 /out:"$(OUTDIR)\dog.dll" /implib:"$(OUTDIR)\dog.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\dog.obj" \
	"$(INTDIR)\dogcf.obj" \
	"$(INTDIR)\idog.obj" \
	"$(OUTDIR)\dogps.lib"

"$(OUTDIR)\dog.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("dog.dep")
!INCLUDE "dog.dep"
!ELSE 
!MESSAGE Warning: cannot find "dog.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "dog - Win32 Debug" || "$(CFG)" == "dog - Win32 Release"
SOURCE=.\dog.cpp

"$(INTDIR)\dog.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\dogcf.cpp

"$(INTDIR)\dogcf.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\idog.cpp

"$(INTDIR)\idog.obj" : $(SOURCE) "$(INTDIR)"


!IF  "$(CFG)" == "dog - Win32 Debug"

"dogps - Win32 Debug" : 
   cd ".\..\dogps"
   $(MAKE) /$(MAKEFLAGS) /F .\dogps.mak CFG="dogps - Win32 Debug" 
   cd "..\dog"

"dogps - Win32 DebugCLEAN" : 
   cd ".\..\dogps"
   $(MAKE) /$(MAKEFLAGS) /F .\dogps.mak CFG="dogps - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\dog"

!ELSEIF  "$(CFG)" == "dog - Win32 Release"

"dogps - Win32 Release" : 
   cd ".\..\dogps"
   $(MAKE) /$(MAKEFLAGS) /F .\dogps.mak CFG="dogps - Win32 Release" 
   cd "..\dog"

"dogps - Win32 ReleaseCLEAN" : 
   cd ".\..\dogps"
   $(MAKE) /$(MAKEFLAGS) /F .\dogps.mak CFG="dogps - Win32 Release" RECURSE=1 CLEAN 
   cd "..\dog"

!ENDIF 

!IF  "$(CFG)" == "dog - Win32 Debug"

"idl - Win32 Debug" : 
   cd ".\..\idl"
   $(MAKE) /$(MAKEFLAGS) /F .\idl.mak CFG="idl - Win32 Debug" 
   cd "..\dog"

"idl - Win32 DebugCLEAN" : 
   cd ".\..\idl"
   $(MAKE) /$(MAKEFLAGS) /F .\idl.mak CFG="idl - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\dog"

!ELSEIF  "$(CFG)" == "dog - Win32 Release"

"idl - Win32 Release" : 
   cd ".\..\idl"
   $(MAKE) /$(MAKEFLAGS) /F .\idl.mak CFG="idl - Win32 Release" 
   cd "..\dog"

"idl - Win32 ReleaseCLEAN" : 
   cd ".\..\idl"
   $(MAKE) /$(MAKEFLAGS) /F .\idl.mak CFG="idl - Win32 Release" RECURSE=1 CLEAN 
   cd "..\dog"

!ENDIF 


!ENDIF 

