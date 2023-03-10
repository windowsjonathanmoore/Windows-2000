!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on avphone3.dsp
!IF "$(CFG)" == ""
CFG=avphone3 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to avphone3 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "avphone3 - Win32 Release" && "$(CFG)" != "avphone3 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "avphone3.mak" CFG="avphone3 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "avphone3 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "avphone3 - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "avphone3 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\avphone3.exe"


CLEAN :
	-@erase "$(INTDIR)\avphone3.obj"
	-@erase "$(INTDIR)\avphone3.res"
	-@erase "$(INTDIR)\callntfy.obj"
	-@erase "$(INTDIR)\clutil.obj"
	-@erase "$(INTDIR)\cnfntfy.obj"
	-@erase "$(INTDIR)\conf.obj"
	-@erase "$(INTDIR)\imsconf2.obj"
	-@erase "$(INTDIR)\mgrntfy.obj"
	-@erase "$(INTDIR)\NetMeeting.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\avphone3.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\avphone3.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\avphone3.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\avphone3.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\avphone3.pdb" /machine:I386 /out:"$(OUTDIR)\avphone3.exe" 
LINK32_OBJS= \
	"$(INTDIR)\avphone3.obj" \
	"$(INTDIR)\callntfy.obj" \
	"$(INTDIR)\clutil.obj" \
	"$(INTDIR)\cnfntfy.obj" \
	"$(INTDIR)\conf.obj" \
	"$(INTDIR)\imsconf2.obj" \
	"$(INTDIR)\mgrntfy.obj" \
	"$(INTDIR)\NetMeeting.obj" \
	"$(INTDIR)\avphone3.res"

"$(OUTDIR)\avphone3.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\avphone3.exe" "$(OUTDIR)\avphone3.bsc"


CLEAN :
	-@erase "$(INTDIR)\avphone3.obj"
	-@erase "$(INTDIR)\avphone3.res"
	-@erase "$(INTDIR)\avphone3.sbr"
	-@erase "$(INTDIR)\callntfy.obj"
	-@erase "$(INTDIR)\callntfy.sbr"
	-@erase "$(INTDIR)\clutil.obj"
	-@erase "$(INTDIR)\clutil.sbr"
	-@erase "$(INTDIR)\cnfntfy.obj"
	-@erase "$(INTDIR)\cnfntfy.sbr"
	-@erase "$(INTDIR)\conf.obj"
	-@erase "$(INTDIR)\conf.sbr"
	-@erase "$(INTDIR)\imsconf2.obj"
	-@erase "$(INTDIR)\imsconf2.sbr"
	-@erase "$(INTDIR)\mgrntfy.obj"
	-@erase "$(INTDIR)\mgrntfy.sbr"
	-@erase "$(INTDIR)\NetMeeting.obj"
	-@erase "$(INTDIR)\NetMeeting.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\avphone3.bsc"
	-@erase "$(OUTDIR)\avphone3.exe"
	-@erase "$(OUTDIR)\avphone3.ilk"
	-@erase "$(OUTDIR)\avphone3.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\avphone3.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\avphone3.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\avphone3.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\avphone3.sbr" \
	"$(INTDIR)\callntfy.sbr" \
	"$(INTDIR)\clutil.sbr" \
	"$(INTDIR)\cnfntfy.sbr" \
	"$(INTDIR)\conf.sbr" \
	"$(INTDIR)\imsconf2.sbr" \
	"$(INTDIR)\mgrntfy.sbr" \
	"$(INTDIR)\NetMeeting.sbr"

"$(OUTDIR)\avphone3.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\avphone3.pdb" /debug /machine:I386 /out:"$(OUTDIR)\avphone3.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\avphone3.obj" \
	"$(INTDIR)\callntfy.obj" \
	"$(INTDIR)\clutil.obj" \
	"$(INTDIR)\cnfntfy.obj" \
	"$(INTDIR)\conf.obj" \
	"$(INTDIR)\imsconf2.obj" \
	"$(INTDIR)\mgrntfy.obj" \
	"$(INTDIR)\NetMeeting.obj" \
	"$(INTDIR)\avphone3.res"

"$(OUTDIR)\avphone3.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("avphone3.dep")
!INCLUDE "avphone3.dep"
!ELSE 
!MESSAGE Warning: cannot find "avphone3.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "avphone3 - Win32 Release" || "$(CFG)" == "avphone3 - Win32 Debug"
SOURCE=.\avphone3.cpp

!IF  "$(CFG)" == "avphone3 - Win32 Release"


"$(INTDIR)\avphone3.obj" : $(SOURCE) "$(INTDIR)" ".\imsconf2.h" ".\netmeeting.h"


!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"


"$(INTDIR)\avphone3.obj"	"$(INTDIR)\avphone3.sbr" : $(SOURCE) "$(INTDIR)" ".\netmeeting.h" ".\imsconf2.h"


!ENDIF 

SOURCE=.\avphone3.rc

"$(INTDIR)\avphone3.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\callntfy.cpp

!IF  "$(CFG)" == "avphone3 - Win32 Release"


"$(INTDIR)\callntfy.obj" : $(SOURCE) "$(INTDIR)" ".\imsconf2.h" ".\netmeeting.h"


!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"


"$(INTDIR)\callntfy.obj"	"$(INTDIR)\callntfy.sbr" : $(SOURCE) "$(INTDIR)" ".\netmeeting.h" ".\imsconf2.h"


!ENDIF 

SOURCE=.\clutil.cpp

!IF  "$(CFG)" == "avphone3 - Win32 Release"


"$(INTDIR)\clutil.obj" : $(SOURCE) "$(INTDIR)" ".\imsconf2.h" ".\netmeeting.h"


!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"


"$(INTDIR)\clutil.obj"	"$(INTDIR)\clutil.sbr" : $(SOURCE) "$(INTDIR)" ".\netmeeting.h" ".\imsconf2.h"


!ENDIF 

SOURCE=.\cnfntfy.cpp

!IF  "$(CFG)" == "avphone3 - Win32 Release"


"$(INTDIR)\cnfntfy.obj" : $(SOURCE) "$(INTDIR)" ".\imsconf2.h" ".\netmeeting.h"


!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"


"$(INTDIR)\cnfntfy.obj"	"$(INTDIR)\cnfntfy.sbr" : $(SOURCE) "$(INTDIR)" ".\netmeeting.h" ".\imsconf2.h"


!ENDIF 

SOURCE=.\conf.cpp

!IF  "$(CFG)" == "avphone3 - Win32 Release"


"$(INTDIR)\conf.obj" : $(SOURCE) "$(INTDIR)" ".\imsconf2.h" ".\netmeeting.h"


!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"


"$(INTDIR)\conf.obj"	"$(INTDIR)\conf.sbr" : $(SOURCE) "$(INTDIR)" ".\netmeeting.h" ".\imsconf2.h"


!ENDIF 

SOURCE=.\imsconf2.c

!IF  "$(CFG)" == "avphone3 - Win32 Release"


"$(INTDIR)\imsconf2.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"


"$(INTDIR)\imsconf2.obj"	"$(INTDIR)\imsconf2.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\..\Include\imsconf2.idl

!IF  "$(CFG)" == "avphone3 - Win32 Release"

TargetDir=.\Release
InputPath=..\..\Include\imsconf2.idl
InputName=imsconf2

".\imsconf2.h"	".\imsconf2.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /client none /server none /ms_ext /W1 /c_ext /env win32 /Oicf  /dlldata   $(TargetDir)\dlldata.rpc /proxy $(TargetDir)\$(InputName).rpc /header   $(InputName).h /iid $(InputName).c $(InputPath)
<< 
	

!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"

TargetDir=.\Debug
InputPath=..\..\Include\imsconf2.idl
InputName=imsconf2

".\imsconf2.h"	".\imsconf2.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /client none /server none /ms_ext /W1 /c_ext /env win32 /Oicf  /dlldata   $(TargetDir)\dlldata.rpc /proxy $(TargetDir)\$(InputName).rpc /header   $(InputName).h /iid $(InputName).c $(InputPath)
<< 
	

!ENDIF 

SOURCE=.\mgrntfy.cpp

!IF  "$(CFG)" == "avphone3 - Win32 Release"


"$(INTDIR)\mgrntfy.obj" : $(SOURCE) "$(INTDIR)" ".\imsconf2.h" ".\netmeeting.h"


!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"


"$(INTDIR)\mgrntfy.obj"	"$(INTDIR)\mgrntfy.sbr" : $(SOURCE) "$(INTDIR)" ".\netmeeting.h" ".\imsconf2.h"


!ENDIF 

SOURCE=.\NetMeeting.c

!IF  "$(CFG)" == "avphone3 - Win32 Release"


"$(INTDIR)\NetMeeting.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"


"$(INTDIR)\NetMeeting.obj"	"$(INTDIR)\NetMeeting.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\..\Include\netmeeting.idl

!IF  "$(CFG)" == "avphone3 - Win32 Release"

TargetDir=.\Release
InputPath=..\..\Include\netmeeting.idl
InputName=netmeeting

".\netmeeting.h"	".\NetMeeting.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /client none /server none /ms_ext /W1 /c_ext /env win32 /Oicf  /dlldata   $(TargetDir)\dlldata.rpc /proxy $(TargetDir)\$(InputName).rpc /header   $(InputName).h /iid $(InputName).c $(InputPath)
<< 
	

!ELSEIF  "$(CFG)" == "avphone3 - Win32 Debug"

TargetDir=.\Debug
InputPath=..\..\Include\netmeeting.idl
InputName=netmeeting

".\netmeeting.h"	".\NetMeeting.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /client none /server none /ms_ext /W1 /c_ext /env win32 /Oicf  /dlldata   $(TargetDir)\dlldata.rpc /proxy $(TargetDir)\$(InputName).rpc /header   $(InputName).h /iid $(InputName).c $(InputPath)
<< 
	

!ENDIF 


!ENDIF 

