!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on PlugTransport.dsp
!IF "$(CFG)" == ""
CFG=PlugTransport - Win32 Debug
!MESSAGE No configuration specified. Defaulting to PlugTransport - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "PlugTransport - Win32 Release" && "$(CFG)" != "PlugTransport - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PlugTransport.mak" CFG="PlugTransport - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PlugTransport - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PlugTransport - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "PlugTransport - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\PlugTransport.exe" "$(OUTDIR)\plugtransport.tlb"


CLEAN :
	-@erase "$(INTDIR)\nmsession.obj"
	-@erase "$(INTDIR)\nullmdm.obj"
	-@erase "$(INTDIR)\plugtransport.obj"
	-@erase "$(INTDIR)\plugtransport.tlb"
	-@erase "$(INTDIR)\plugxprt.obj"
	-@erase "$(INTDIR)\ui.obj"
	-@erase "$(INTDIR)\ui.res"
	-@erase "$(INTDIR)\utils.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\x224.obj"
	-@erase "$(OUTDIR)\PlugTransport.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\PlugTransport.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ui.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PlugTransport.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\PlugTransport.pdb" /machine:I386 /out:"$(OUTDIR)\PlugTransport.exe" 
LINK32_OBJS= \
	"$(INTDIR)\nmsession.obj" \
	"$(INTDIR)\nullmdm.obj" \
	"$(INTDIR)\plugtransport.obj" \
	"$(INTDIR)\plugxprt.obj" \
	"$(INTDIR)\ui.obj" \
	"$(INTDIR)\utils.obj" \
	"$(INTDIR)\x224.obj" \
	"$(INTDIR)\ui.res"

"$(OUTDIR)\PlugTransport.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PlugTransport - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\PlugTransport.exe" "$(OUTDIR)\PlugTransport.bsc"


CLEAN :
	-@erase "$(INTDIR)\nmsession.obj"
	-@erase "$(INTDIR)\nmsession.sbr"
	-@erase "$(INTDIR)\nullmdm.obj"
	-@erase "$(INTDIR)\nullmdm.sbr"
	-@erase "$(INTDIR)\plugtransport.obj"
	-@erase "$(INTDIR)\plugtransport.sbr"
	-@erase "$(INTDIR)\plugxprt.obj"
	-@erase "$(INTDIR)\plugxprt.sbr"
	-@erase "$(INTDIR)\ui.obj"
	-@erase "$(INTDIR)\ui.res"
	-@erase "$(INTDIR)\ui.sbr"
	-@erase "$(INTDIR)\utils.obj"
	-@erase "$(INTDIR)\utils.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\x224.obj"
	-@erase "$(INTDIR)\x224.sbr"
	-@erase "$(OUTDIR)\PlugTransport.bsc"
	-@erase "$(OUTDIR)\PlugTransport.exe"
	-@erase "$(OUTDIR)\PlugTransport.ilk"
	-@erase "$(OUTDIR)\PlugTransport.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PlugTransport.pch" /YX"precomp.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /GZ /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ui.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PlugTransport.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\nmsession.sbr" \
	"$(INTDIR)\nullmdm.sbr" \
	"$(INTDIR)\plugtransport.sbr" \
	"$(INTDIR)\plugxprt.sbr" \
	"$(INTDIR)\ui.sbr" \
	"$(INTDIR)\utils.sbr" \
	"$(INTDIR)\x224.sbr"

"$(OUTDIR)\PlugTransport.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\PlugTransport.pdb" /debug /machine:I386 /out:"$(OUTDIR)\PlugTransport.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\nmsession.obj" \
	"$(INTDIR)\nullmdm.obj" \
	"$(INTDIR)\plugtransport.obj" \
	"$(INTDIR)\plugxprt.obj" \
	"$(INTDIR)\ui.obj" \
	"$(INTDIR)\utils.obj" \
	"$(INTDIR)\x224.obj" \
	"$(INTDIR)\ui.res"

"$(OUTDIR)\PlugTransport.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("PlugTransport.dep")
!INCLUDE "PlugTransport.dep"
!ELSE 
!MESSAGE Warning: cannot find "PlugTransport.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "PlugTransport - Win32 Release" || "$(CFG)" == "PlugTransport - Win32 Debug"
SOURCE=.\nmsession.cpp

!IF  "$(CFG)" == "PlugTransport - Win32 Release"


"$(INTDIR)\nmsession.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PlugTransport - Win32 Debug"


"$(INTDIR)\nmsession.obj"	"$(INTDIR)\nmsession.sbr" : $(SOURCE) "$(INTDIR)" ".\plugtransport.h"


!ENDIF 

SOURCE=.\nullmdm.cpp

!IF  "$(CFG)" == "PlugTransport - Win32 Release"


"$(INTDIR)\nullmdm.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PlugTransport - Win32 Debug"


"$(INTDIR)\nullmdm.obj"	"$(INTDIR)\nullmdm.sbr" : $(SOURCE) "$(INTDIR)" ".\plugtransport.h"


!ENDIF 

SOURCE=.\plugtransport.c

!IF  "$(CFG)" == "PlugTransport - Win32 Release"


"$(INTDIR)\plugtransport.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PlugTransport - Win32 Debug"


"$(INTDIR)\plugtransport.obj"	"$(INTDIR)\plugtransport.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\plugxprt.cpp

!IF  "$(CFG)" == "PlugTransport - Win32 Release"


"$(INTDIR)\plugxprt.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PlugTransport - Win32 Debug"


"$(INTDIR)\plugxprt.obj"	"$(INTDIR)\plugxprt.sbr" : $(SOURCE) "$(INTDIR)" ".\plugtransport.h"


!ENDIF 

SOURCE=.\ui.cpp

!IF  "$(CFG)" == "PlugTransport - Win32 Release"


"$(INTDIR)\ui.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PlugTransport - Win32 Debug"


"$(INTDIR)\ui.obj"	"$(INTDIR)\ui.sbr" : $(SOURCE) "$(INTDIR)" ".\plugtransport.h"


!ENDIF 

SOURCE=.\utils.cpp

!IF  "$(CFG)" == "PlugTransport - Win32 Release"


"$(INTDIR)\utils.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PlugTransport - Win32 Debug"


"$(INTDIR)\utils.obj"	"$(INTDIR)\utils.sbr" : $(SOURCE) "$(INTDIR)" ".\plugtransport.h"


!ENDIF 

SOURCE=.\x224.cpp

!IF  "$(CFG)" == "PlugTransport - Win32 Release"


"$(INTDIR)\x224.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "PlugTransport - Win32 Debug"


"$(INTDIR)\x224.obj"	"$(INTDIR)\x224.sbr" : $(SOURCE) "$(INTDIR)" ".\plugtransport.h"


!ENDIF 

SOURCE=.\plugtransport.idl

!IF  "$(CFG)" == "PlugTransport - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\plugtransport.tlb" /mktyplib203 /win32 

"$(INTDIR)\plugtransport.tlb" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PlugTransport - Win32 Debug"

TargetDir=.\Debug
InputPath=.\plugtransport.idl
InputName=plugtransport

".\plugtransport.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /client none /server none /ms_ext /W1 /c_ext /env win32 /Oicf  /dlldata   $(TargetDir)\dlldata.rpc /proxy $(TargetDir)\$(InputName).rpc /header   $(InputName).h /iid $(InputName).c $(InputPath)
<< 
	

!ENDIF 

SOURCE=.\ui.rc

"$(INTDIR)\ui.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

