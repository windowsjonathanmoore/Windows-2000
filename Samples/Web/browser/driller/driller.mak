# Microsoft Developer Studio Generated NMAKE File, Based on driller.dsp
!IF "$(CFG)" == ""
CFG=driller - Win32 Release
!MESSAGE No configuration specified. Defaulting to driller - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "driller - Win32 Release" && "$(CFG)" !=\
 "driller - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "driller.mak" CFG="driller - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "driller - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "driller - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "driller - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\driller.exe"

!ELSE 

ALL : "$(OUTDIR)\driller.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\custsite.obj"
	-@erase "$(INTDIR)\drilldlg.obj"
	-@erase "$(INTDIR)\driller.obj"
	-@erase "$(INTDIR)\driller.pch"
	-@erase "$(INTDIR)\driller.res"
	-@erase "$(INTDIR)\idispimp.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\webbro.obj"
	-@erase "$(OUTDIR)\driller.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\driller.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\"   /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\driller.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\driller.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=uuid.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\driller.pdb" /machine:I386 /out:"$(OUTDIR)\driller.exe" 
LINK32_OBJS= \
	"$(INTDIR)\custsite.obj" \
	"$(INTDIR)\drilldlg.obj" \
	"$(INTDIR)\driller.obj" \
	"$(INTDIR)\driller.res" \
	"$(INTDIR)\idispimp.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\webbro.obj"

"$(OUTDIR)\driller.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "driller - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\driller.exe" "$(OUTDIR)\driller.bsc"

!ELSE 

ALL : "$(OUTDIR)\driller.exe" "$(OUTDIR)\driller.bsc"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\custsite.obj"
	-@erase "$(INTDIR)\custsite.sbr"
	-@erase "$(INTDIR)\drilldlg.obj"
	-@erase "$(INTDIR)\drilldlg.sbr"
	-@erase "$(INTDIR)\driller.obj"
	-@erase "$(INTDIR)\driller.pch"
	-@erase "$(INTDIR)\driller.res"
	-@erase "$(INTDIR)\driller.sbr"
	-@erase "$(INTDIR)\idispimp.obj"
	-@erase "$(INTDIR)\idispimp.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(INTDIR)\webbro.obj"
	-@erase "$(INTDIR)\webbro.sbr"
	-@erase "$(OUTDIR)\driller.bsc"
	-@erase "$(OUTDIR)\driller.exe"
	-@erase "$(OUTDIR)\driller.ilk"
	-@erase "$(OUTDIR)\driller.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\driller.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\driller.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\driller.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\custsite.sbr" \
	"$(INTDIR)\drilldlg.sbr" \
	"$(INTDIR)\driller.sbr" \
	"$(INTDIR)\idispimp.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\webbro.sbr"

"$(OUTDIR)\driller.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=uuid.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\driller.pdb" /debug /machine:I386 /out:"$(OUTDIR)\driller.exe" 
LINK32_OBJS= \
	"$(INTDIR)\custsite.obj" \
	"$(INTDIR)\drilldlg.obj" \
	"$(INTDIR)\driller.obj" \
	"$(INTDIR)\driller.res" \
	"$(INTDIR)\idispimp.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\webbro.obj"

"$(OUTDIR)\driller.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "driller - Win32 Release" || "$(CFG)" ==\
 "driller - Win32 Debug"
SOURCE=.\custsite.cpp
DEP_CPP_CUSTS=\
	".\custsite.h"\
	".\driller.h"\
	".\idispimp.h"\
	".\resource.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"..\src\ocdb.h"\
	{$(INCLUDE)}"..\src\ocdbid.h"\
	{$(INCLUDE)}"..\src\olebind.h"\
	{$(INCLUDE)}"..\src\occimpl.h"\
	

!IF  "$(CFG)" == "driller - Win32 Release"


"$(INTDIR)\custsite.obj" : $(SOURCE) $(DEP_CPP_CUSTS) "$(INTDIR)"\
 "$(INTDIR)\driller.pch"


!ELSEIF  "$(CFG)" == "driller - Win32 Debug"


"$(INTDIR)\custsite.obj"	"$(INTDIR)\custsite.sbr" : $(SOURCE) $(DEP_CPP_CUSTS)\
 "$(INTDIR)" "$(INTDIR)\driller.pch"


!ENDIF 

SOURCE=.\drilldlg.cpp
DEP_CPP_DRILL=\
	".\drillDlg.h"\
	".\driller.h"\
	".\resource.h"\
	".\StdAfx.h"\
	".\webbro.h"\
	

!IF  "$(CFG)" == "driller - Win32 Release"


"$(INTDIR)\drilldlg.obj" : $(SOURCE) $(DEP_CPP_DRILL) "$(INTDIR)"\
 "$(INTDIR)\driller.pch"


!ELSEIF  "$(CFG)" == "driller - Win32 Debug"


"$(INTDIR)\drilldlg.obj"	"$(INTDIR)\drilldlg.sbr" : $(SOURCE) $(DEP_CPP_DRILL)\
 "$(INTDIR)" "$(INTDIR)\driller.pch"


!ENDIF 

SOURCE=.\driller.cpp
DEP_CPP_DRILLE=\
	".\custsite.h"\
	".\drillDlg.h"\
	".\driller.h"\
	".\idispimp.h"\
	".\resource.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"..\src\ocdb.h"\
	{$(INCLUDE)}"..\src\ocdbid.h"\
	{$(INCLUDE)}"..\src\olebind.h"\
	{$(INCLUDE)}"..\src\occimpl.h"\
	

!IF  "$(CFG)" == "driller - Win32 Release"


"$(INTDIR)\driller.obj" : $(SOURCE) $(DEP_CPP_DRILLE) "$(INTDIR)"\
 "$(INTDIR)\driller.pch"


!ELSEIF  "$(CFG)" == "driller - Win32 Debug"


"$(INTDIR)\driller.obj"	"$(INTDIR)\driller.sbr" : $(SOURCE) $(DEP_CPP_DRILLE)\
 "$(INTDIR)" "$(INTDIR)\driller.pch"


!ENDIF 

SOURCE=.\driller.rc
DEP_RSC_DRILLER=\
	".\resource.h"\
	
NODEP_RSC_DRILLER=\
	".\res\driller.ico"\
	

"$(INTDIR)\driller.res" : $(SOURCE) $(DEP_RSC_DRILLER) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\idispimp.cpp
DEP_CPP_IDISP=\
	".\idispimp.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "driller - Win32 Release"


"$(INTDIR)\idispimp.obj" : $(SOURCE) $(DEP_CPP_IDISP) "$(INTDIR)"\
 "$(INTDIR)\driller.pch"


!ELSEIF  "$(CFG)" == "driller - Win32 Debug"


"$(INTDIR)\idispimp.obj"	"$(INTDIR)\idispimp.sbr" : $(SOURCE) $(DEP_CPP_IDISP)\
 "$(INTDIR)" "$(INTDIR)\driller.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "driller - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\driller.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\"   /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\driller.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "driller - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\driller.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\driller.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\webbro.cpp
DEP_CPP_WEBBR=\
	".\StdAfx.h"\
	".\webbro.h"\
	

!IF  "$(CFG)" == "driller - Win32 Release"


"$(INTDIR)\webbro.obj" : $(SOURCE) $(DEP_CPP_WEBBR) "$(INTDIR)"\
 "$(INTDIR)\driller.pch"


!ELSEIF  "$(CFG)" == "driller - Win32 Debug"


"$(INTDIR)\webbro.obj"	"$(INTDIR)\webbro.sbr" : $(SOURCE) $(DEP_CPP_WEBBR)\
 "$(INTDIR)" "$(INTDIR)\driller.pch"


!ENDIF 


!ENDIF 

