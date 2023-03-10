# Microsoft Developer Studio Generated NMAKE File, Based on ps.dsp
!IF "$(CFG)" == ""
CFG=ps - Win32 Release
!MESSAGE No configuration specified. Defaulting to ps - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "ps - Win32 Release" && "$(CFG)" != "ps - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ps.mak" CFG="ps - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ps - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ps - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "ps - Win32 Release"

OUTDIR=.\..\bin\Release\x86
INTDIR=.\Release\x86
# Begin Custom Macros
OutDir=.\..\bin\Release\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\ps.dll"

!ELSE 

ALL : "psidl - Win32 Release" "$(OUTDIR)\ps.dll"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"psidl - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\dlldata.obj"
	-@erase "$(INTDIR)\server_i.obj"
	-@erase "$(INTDIR)\server_p.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ps.dll"
	-@erase "$(OUTDIR)\ps.exp"
	-@erase "$(OUTDIR)\ps.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "REGISTER_PROXY_DLL" /D "UNICODE" /D "_UNICODE" /Fp"$(INTDIR)\ps.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ps.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\ps.pdb" /machine:I386 /def:".\ps.def" /out:"$(OUTDIR)\ps.dll" /implib:"$(OUTDIR)\ps.lib" 
DEF_FILE= \
	".\ps.def"
LINK32_OBJS= \
	"$(INTDIR)\server_p.obj" \
	"$(INTDIR)\server_i.obj" \
	"$(INTDIR)\dlldata.obj"

"$(OUTDIR)\ps.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ps - Win32 Debug"

OUTDIR=.\..\bin\debug\x86
INTDIR=.\debug\x86
# Begin Custom Macros
OutDir=.\..\bin\debug\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\ps.dll"

!ELSE 

ALL : "psidl - Win32 Debug" "$(OUTDIR)\ps.dll"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"psidl - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\dlldata.obj"
	-@erase "$(INTDIR)\server_i.obj"
	-@erase "$(INTDIR)\server_p.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ps.dll"
	-@erase "$(OUTDIR)\ps.exp"
	-@erase "$(OUTDIR)\ps.ilk"
	-@erase "$(OUTDIR)\ps.lib"
	-@erase "$(OUTDIR)\ps.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /Gz /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "REGISTER_PROXY_DLL" /D "UNICODE" /D "_UNICODE" /D "_WIN32_DCOM" /Fp"$(INTDIR)\ps.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ps.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\ps.pdb" /debug /machine:I386 /def:".\ps.def" /out:"$(OUTDIR)\ps.dll" /implib:"$(OUTDIR)\ps.lib" 
DEF_FILE= \
	".\ps.def"
LINK32_OBJS= \
	"$(INTDIR)\server_p.obj" \
	"$(INTDIR)\server_i.obj" \
	"$(INTDIR)\dlldata.obj"

"$(OUTDIR)\ps.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("ps.dep")
!INCLUDE "ps.dep"
!ELSE 
!MESSAGE Warning: cannot find "ps.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ps - Win32 Release" || "$(CFG)" == "ps - Win32 Debug"
SOURCE=..\ps_win32\dlldata.c

"$(INTDIR)\dlldata.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\ps_win32\server_i.c

"$(INTDIR)\server_i.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\ps_win32\server_p.c

"$(INTDIR)\server_p.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!IF  "$(CFG)" == "ps - Win32 Release"

"psidl - Win32 Release" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Release" 
   cd "."

"psidl - Win32 ReleaseCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Release" RECURSE=1 CLEAN 
   cd "."

!ELSEIF  "$(CFG)" == "ps - Win32 Debug"

"psidl - Win32 Debug" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Debug" 
   cd "."

"psidl - Win32 DebugCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\psidl.mak CFG="psidl - Win32 Debug" RECURSE=1 CLEAN 
   cd "."

!ENDIF 


!ENDIF 

