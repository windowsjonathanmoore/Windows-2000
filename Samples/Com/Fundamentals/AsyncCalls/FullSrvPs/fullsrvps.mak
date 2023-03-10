# Microsoft Developer Studio Generated NMAKE File, Based on FullSrvps.dsp
!IF "$(CFG)" == ""
CFG=FullSrvps - Win32 Debug
!MESSAGE No configuration specified. Defaulting to FullSrvps - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "FullSrvps - Win32 Release" && "$(CFG)" != "FullSrvps - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FullSrvps.mak" CFG="FullSrvps - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FullSrvps - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "FullSrvps - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "FullSrvps - Win32 Release"

OUTDIR=.\..\Release\x86
INTDIR=.\Release\x86
# Begin Custom Macros
OutDir=.\..\Release\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\FullSrvps.dll"

!ELSE 

ALL : "idl - Win32 Release" "$(OUTDIR)\FullSrvps.dll"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"idl - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\dlldata.obj"
	-@erase "$(INTDIR)\FullSvr_i.obj"
	-@erase "$(INTDIR)\FullSvr_p.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\FullSrvps.dll"
	-@erase "$(OUTDIR)\FullSrvps.exp"
	-@erase "$(OUTDIR)\FullSrvps.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "FULLSRVPS_EXPORTS" /D "REGISTER_PROXY_DLL" /D _WIN32_WINNT=0x0500 /Fp"$(INTDIR)\FullSrvps.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\FullSrvps.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib uuid.lib odbc32.lib odbccp32.lib rpcrt4.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\FullSrvps.pdb" /machine:I386 /def:".\FullSvrps.def" /out:"$(OUTDIR)\FullSrvps.dll" /implib:"$(OUTDIR)\FullSrvps.lib" 
DEF_FILE= \
	".\FullSvrps.def"
LINK32_OBJS= \
	"$(INTDIR)\dlldata.obj" \
	"$(INTDIR)\FullSvr_i.obj" \
	"$(INTDIR)\FullSvr_p.obj"

"$(OUTDIR)\FullSrvps.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "FullSrvps - Win32 Debug"

OUTDIR=.\..\Debug\x86
INTDIR=.\Debug\x86
# Begin Custom Macros
OutDir=.\..\Debug\x86
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\FullSrvps.dll" ".\..\Debug\x86\regsvr32.trg"

!ELSE 

ALL : "idl - Win32 Debug" "$(OUTDIR)\FullSrvps.dll" ".\..\Debug\x86\regsvr32.trg"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"idl - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\dlldata.obj"
	-@erase "$(INTDIR)\FullSvr_i.obj"
	-@erase "$(INTDIR)\FullSvr_p.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\FullSrvps.dll"
	-@erase "$(OUTDIR)\FullSrvps.exp"
	-@erase "$(OUTDIR)\FullSrvps.ilk"
	-@erase "$(OUTDIR)\FullSrvps.lib"
	-@erase "$(OUTDIR)\FullSrvps.pdb"
	-@erase ".\..\Debug\x86\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "FULLSRVPS_EXPORTS" /D "REGISTER_PROXY_DLL" /D _WIN32_WINNT=0x0500 /Fp"$(INTDIR)\FullSrvps.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\FullSrvps.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib uuid.lib odbc32.lib odbccp32.lib rpcrt4.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\FullSrvps.pdb" /debug /machine:I386 /def:".\FullSvrps.def" /out:"$(OUTDIR)\FullSrvps.dll" /implib:"$(OUTDIR)\FullSrvps.lib" /pdbtype:sept 
DEF_FILE= \
	".\FullSvrps.def"
LINK32_OBJS= \
	"$(INTDIR)\dlldata.obj" \
	"$(INTDIR)\FullSvr_i.obj" \
	"$(INTDIR)\FullSvr_p.obj"

"$(OUTDIR)\FullSrvps.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\..\Debug\x86
TargetPath=.\..\Debug\x86\FullSrvps.dll
InputPath=.\..\Debug\x86\FullSrvps.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
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
!IF EXISTS("FullSrvps.dep")
!INCLUDE "FullSrvps.dep"
!ELSE 
!MESSAGE Warning: cannot find "FullSrvps.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "FullSrvps - Win32 Release" || "$(CFG)" == "FullSrvps - Win32 Debug"
SOURCE=..\idl\ps_win32\dlldata.c

"$(INTDIR)\dlldata.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\idl\ps_win32\FullSvr_i.c

"$(INTDIR)\FullSvr_i.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\idl\ps_win32\FullSvr_p.c

"$(INTDIR)\FullSvr_p.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!IF  "$(CFG)" == "FullSrvps - Win32 Release"

"idl - Win32 Release" : 
   cd ".\..\idl"
   $(MAKE) /$(MAKEFLAGS) /F .\idl.mak CFG="idl - Win32 Release" 
   cd "..\FullSrvps"

"idl - Win32 ReleaseCLEAN" : 
   cd ".\..\idl"
   $(MAKE) /$(MAKEFLAGS) /F .\idl.mak CFG="idl - Win32 Release" RECURSE=1 CLEAN 
   cd "..\FullSrvps"

!ELSEIF  "$(CFG)" == "FullSrvps - Win32 Debug"

"idl - Win32 Debug" : 
   cd ".\..\idl"
   $(MAKE) /$(MAKEFLAGS) /F .\idl.mak CFG="idl - Win32 Debug" 
   cd "..\FullSrvps"

"idl - Win32 DebugCLEAN" : 
   cd ".\..\idl"
   $(MAKE) /$(MAKEFLAGS) /F .\idl.mak CFG="idl - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\FullSrvps"

!ENDIF 


!ENDIF 

