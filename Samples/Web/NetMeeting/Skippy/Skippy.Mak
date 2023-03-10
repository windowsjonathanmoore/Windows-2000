!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on skippy.dsp
!IF "$(CFG)" == ""
CFG=skippy - Win32 Release
!MESSAGE No configuration specified. Defaulting to skippy - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "skippy - Win32 Release" && "$(CFG)" != "skippy - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "skippy.mak" CFG="skippy - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "skippy - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "skippy - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "skippy - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : ".\ILS.h" "$(OUTDIR)\skippy.exe"


CLEAN :
	-@erase "$(INTDIR)\attrib.obj"
	-@erase "$(INTDIR)\filter.obj"
	-@erase "$(INTDIR)\ils.obj"
	-@erase "$(INTDIR)\MAIN.OBJ"
	-@erase "$(INTDIR)\notify.obj"
	-@erase "$(INTDIR)\oblist.obj"
	-@erase "$(INTDIR)\proto.obj"
	-@erase "$(INTDIR)\skippy.res"
	-@erase "$(INTDIR)\svrinfo.obj"
	-@erase "$(INTDIR)\USERS.OBJ"
	-@erase "$(INTDIR)\usrinfo.obj"
	-@erase "$(INTDIR)\UTILS.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\skippy.exe"
	-@erase ".\ILS.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\skippy.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\skippy.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\skippy.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\skippy.pdb" /machine:I386 /out:"$(OUTDIR)\skippy.exe" 
LINK32_OBJS= \
	"$(INTDIR)\attrib.obj" \
	"$(INTDIR)\filter.obj" \
	"$(INTDIR)\ils.obj" \
	"$(INTDIR)\MAIN.OBJ" \
	"$(INTDIR)\notify.obj" \
	"$(INTDIR)\oblist.obj" \
	"$(INTDIR)\proto.obj" \
	"$(INTDIR)\svrinfo.obj" \
	"$(INTDIR)\USERS.OBJ" \
	"$(INTDIR)\usrinfo.obj" \
	"$(INTDIR)\UTILS.OBJ" \
	"$(INTDIR)\skippy.res"

"$(OUTDIR)\skippy.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"

OUTDIR=.\debug
INTDIR=.\debug
# Begin Custom Macros
OutDir=.\debug
# End Custom Macros

ALL : "$(OUTDIR)\skippy.exe" "$(OUTDIR)\skippy.bsc"


CLEAN :
	-@erase "$(INTDIR)\attrib.obj"
	-@erase "$(INTDIR)\attrib.sbr"
	-@erase "$(INTDIR)\filter.obj"
	-@erase "$(INTDIR)\filter.sbr"
	-@erase "$(INTDIR)\ils.obj"
	-@erase "$(INTDIR)\ils.sbr"
	-@erase "$(INTDIR)\MAIN.OBJ"
	-@erase "$(INTDIR)\MAIN.SBR"
	-@erase "$(INTDIR)\notify.obj"
	-@erase "$(INTDIR)\notify.sbr"
	-@erase "$(INTDIR)\oblist.obj"
	-@erase "$(INTDIR)\oblist.sbr"
	-@erase "$(INTDIR)\proto.obj"
	-@erase "$(INTDIR)\proto.sbr"
	-@erase "$(INTDIR)\skippy.res"
	-@erase "$(INTDIR)\svrinfo.obj"
	-@erase "$(INTDIR)\svrinfo.sbr"
	-@erase "$(INTDIR)\USERS.OBJ"
	-@erase "$(INTDIR)\USERS.SBR"
	-@erase "$(INTDIR)\usrinfo.obj"
	-@erase "$(INTDIR)\usrinfo.sbr"
	-@erase "$(INTDIR)\UTILS.OBJ"
	-@erase "$(INTDIR)\UTILS.SBR"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\skippy.bsc"
	-@erase "$(OUTDIR)\skippy.exe"
	-@erase "$(OUTDIR)\skippy.ilk"
	-@erase "$(OUTDIR)\skippy.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\skippy.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\skippy.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\skippy.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\attrib.sbr" \
	"$(INTDIR)\filter.sbr" \
	"$(INTDIR)\ils.sbr" \
	"$(INTDIR)\MAIN.SBR" \
	"$(INTDIR)\notify.sbr" \
	"$(INTDIR)\oblist.sbr" \
	"$(INTDIR)\proto.sbr" \
	"$(INTDIR)\svrinfo.sbr" \
	"$(INTDIR)\USERS.SBR" \
	"$(INTDIR)\usrinfo.sbr" \
	"$(INTDIR)\UTILS.SBR"

"$(OUTDIR)\skippy.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\skippy.pdb" /debug /machine:I386 /out:"$(OUTDIR)\skippy.exe" 
LINK32_OBJS= \
	"$(INTDIR)\attrib.obj" \
	"$(INTDIR)\filter.obj" \
	"$(INTDIR)\ils.obj" \
	"$(INTDIR)\MAIN.OBJ" \
	"$(INTDIR)\notify.obj" \
	"$(INTDIR)\oblist.obj" \
	"$(INTDIR)\proto.obj" \
	"$(INTDIR)\svrinfo.obj" \
	"$(INTDIR)\USERS.OBJ" \
	"$(INTDIR)\usrinfo.obj" \
	"$(INTDIR)\UTILS.OBJ" \
	"$(INTDIR)\skippy.res"

"$(OUTDIR)\skippy.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("skippy.dep")
!INCLUDE "skippy.dep"
!ELSE 
!MESSAGE Warning: cannot find "skippy.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "skippy - Win32 Release" || "$(CFG)" == "skippy - Win32 Debug"
SOURCE=.\attrib.cpp

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\attrib.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\attrib.obj"	"$(INTDIR)\attrib.sbr" : $(SOURCE) "$(INTDIR)" ".\ILS.h"


!ENDIF 

SOURCE=.\filter.cpp

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\filter.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\filter.obj"	"$(INTDIR)\filter.sbr" : $(SOURCE) "$(INTDIR)" ".\ILS.h"


!ENDIF 

SOURCE=.\ils.c

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\ils.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\ils.obj"	"$(INTDIR)\ils.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\MAIN.CPP

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\MAIN.OBJ" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\MAIN.OBJ"	"$(INTDIR)\MAIN.SBR" : $(SOURCE) "$(INTDIR)" ".\ILS.h"


!ENDIF 

SOURCE=.\notify.cpp

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\notify.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\notify.obj"	"$(INTDIR)\notify.sbr" : $(SOURCE) "$(INTDIR)" ".\ILS.h"


!ENDIF 

SOURCE=.\oblist.cpp

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\oblist.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\oblist.obj"	"$(INTDIR)\oblist.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\proto.cpp

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\proto.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\proto.obj"	"$(INTDIR)\proto.sbr" : $(SOURCE) "$(INTDIR)" ".\ILS.h"


!ENDIF 

SOURCE=.\skippy.rc

"$(INTDIR)\skippy.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\svrinfo.cpp

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\svrinfo.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\svrinfo.obj"	"$(INTDIR)\svrinfo.sbr" : $(SOURCE) "$(INTDIR)" ".\ILS.h"


!ENDIF 

SOURCE=.\USERS.CPP

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\USERS.OBJ" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\USERS.OBJ"	"$(INTDIR)\USERS.SBR" : $(SOURCE) "$(INTDIR)" ".\ILS.h"


!ENDIF 

SOURCE=.\usrinfo.cpp

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\usrinfo.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\usrinfo.obj"	"$(INTDIR)\usrinfo.sbr" : $(SOURCE) "$(INTDIR)" ".\ILS.h"


!ENDIF 

SOURCE=.\UTILS.CPP

!IF  "$(CFG)" == "skippy - Win32 Release"


"$(INTDIR)\UTILS.OBJ" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"


"$(INTDIR)\UTILS.OBJ"	"$(INTDIR)\UTILS.SBR" : $(SOURCE) "$(INTDIR)" ".\ILS.h"


!ENDIF 

SOURCE=.\ILS.IDL

!IF  "$(CFG)" == "skippy - Win32 Release"

TargetDir=.\Release
InputPath=.\ILS.IDL
InputName=ILS

".\ILS.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /client none /server none /ms_ext /W1 /c_ext /env win32 /Oicf  /dlldata  $(TargetDir)\dlldata.rpc /proxy $(TargetDir)\$(InputName).rpc /header  $(InputName).h /iid $(InputName).c $(InputPath)
<< 
	

!ELSEIF  "$(CFG)" == "skippy - Win32 Debug"

TargetDir=.\debug
InputPath=.\ILS.IDL
InputName=ILS

".\ILS.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /client none /server none /ms_ext /D INIT_OFFICE /W1 /c_ext /env win32   /Oicf  /dlldata      $(TargetDir)\dlldata.rpc /proxy   $(TargetDir)\$(InputName).rpc /header      $(InputName).h /iid $(InputName).c   $(InputPath)
<< 
	

!ENDIF 


!ENDIF 

