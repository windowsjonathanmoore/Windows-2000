!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on nmft.dsp
!IF "$(CFG)" == ""
CFG=nmFt - Win32 Debug
!MESSAGE No configuration specified. Defaulting to nmFt - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "nmFt - Win32 Release" && "$(CFG)" != "nmFt - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "nmft.mak" CFG="nmFt - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "nmFt - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "nmFt - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "nmFt - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\nmft.exe" "$(OUTDIR)\imsconf2.tlb"


CLEAN :
	-@erase "$(INTDIR)\cConf.obj"
	-@erase "$(INTDIR)\clUtil.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\imsconf2.obj"
	-@erase "$(INTDIR)\imsconf2.tlb"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\msg.obj"
	-@erase "$(INTDIR)\res.res"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\nmft.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /WX /O1 /Ob2 /D "NDEBUG" /D "STRICT" /D "WIN32" /D "_WINDOWS" /Fp"$(INTDIR)\nmft.pch" /YX"precomp.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\res.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\nmft.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comctl32.lib /nologo /entry:"main" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\nmft.pdb" /machine:I386 /out:"$(OUTDIR)\nmft.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cConf.obj" \
	"$(INTDIR)\clUtil.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\imsconf2.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\msg.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\res.res"

"$(OUTDIR)\nmft.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "nmFt - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : ".\$(InpuName).h" ".\$(InpuName).c" "$(OUTDIR)\nmft.exe"


CLEAN :
	-@erase "$(INTDIR)\cConf.obj"
	-@erase "$(INTDIR)\clUtil.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\imsconf2.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\msg.obj"
	-@erase "$(INTDIR)\res.res"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\nmft.exe"
	-@erase "$(OUTDIR)\nmft.ilk"
	-@erase "$(OUTDIR)\nmft.pdb"
	-@erase ".\$(InpuName).c"
	-@erase ".\$(InpuName).h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "DEBUG" /D "_DEBUG" /D "STRICT" /D "WIN32" /D "_WINDOWS" /Fp"$(INTDIR)\nmft.pch" /YX"precomp.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\res.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\nmft.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comctl32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\nmft.pdb" /debug /machine:I386 /out:"$(OUTDIR)\nmft.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\cConf.obj" \
	"$(INTDIR)\clUtil.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\imsconf2.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\msg.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\res.res"

"$(OUTDIR)\nmft.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("nmft.dep")
!INCLUDE "nmft.dep"
!ELSE 
!MESSAGE Warning: cannot find "nmft.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "nmFt - Win32 Release" || "$(CFG)" == "nmFt - Win32 Debug"
SOURCE=.\cConf.cpp

"$(INTDIR)\cConf.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\clUtil.cpp

"$(INTDIR)\clUtil.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\debug.cpp

"$(INTDIR)\debug.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\imsconf2.c

"$(INTDIR)\imsconf2.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=..\..\Include\imsconf2.idl

!IF  "$(CFG)" == "nmFt - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\imsconf2.tlb" /mktyplib203 /o "NUL" /win32 

"$(INTDIR)\imsconf2.tlb" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "nmFt - Win32 Debug"

TargetDir=.\Debug
InputPath=..\..\Include\imsconf2.idl
InputName=imsconf2

".\.h"	".\.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /client none /server none /ms_ext /W1 /c_ext /env win32 /Oicf  /dlldata   $(TargetDir)\dlldata.rpc /proxy $(TargetDir)\$(InputName).rpc /header   $(InputName).h /iid $(InputName).c $(InputPath)
<< 
	

!ENDIF 

SOURCE=.\main.cpp

"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\msg.cpp

"$(INTDIR)\msg.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\res.rc

"$(INTDIR)\res.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\util.cpp

"$(INTDIR)\util.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

