!include <disable.mak>

# Microsoft Developer Studio Generated NMAKE File, Based on nmchat.dsp
!IF "$(CFG)" == ""
CFG=nmChat - Win32 Debug
!MESSAGE No configuration specified. Defaulting to nmChat - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "nmChat - Win32 Release" && "$(CFG)" != "nmChat - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "nmchat.mak" CFG="nmChat - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "nmChat - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "nmChat - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "nmChat - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\nmchat.exe" "$(OUTDIR)\IMSCONF2.tlb"


CLEAN :
	-@erase "$(INTDIR)\cConf.obj"
	-@erase "$(INTDIR)\cData.obj"
	-@erase "$(INTDIR)\clUtil.obj"
	-@erase "$(INTDIR)\cmd.obj"
	-@erase "$(INTDIR)\cMemb.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\imsconf2.obj"
	-@erase "$(INTDIR)\IMSCONF2.tlb"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\msg.obj"
	-@erase "$(INTDIR)\res.res"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\nmchat.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /WX /GX /O1 /Ob2 /D "NDEBUG" /D "STRICT" /D "WIN32" /D "_WINDOWS" /Fp"$(INTDIR)\nmchat.pch" /YX"precomp.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\res.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\nmchat.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comctl32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\nmchat.pdb" /machine:I386 /out:"$(OUTDIR)\nmchat.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cConf.obj" \
	"$(INTDIR)\cData.obj" \
	"$(INTDIR)\clUtil.obj" \
	"$(INTDIR)\cmd.obj" \
	"$(INTDIR)\cMemb.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\imsconf2.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\msg.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\res.res"

"$(OUTDIR)\nmchat.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "nmChat - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\nmchat.exe"


CLEAN :
	-@erase "$(INTDIR)\cConf.obj"
	-@erase "$(INTDIR)\cData.obj"
	-@erase "$(INTDIR)\clUtil.obj"
	-@erase "$(INTDIR)\cmd.obj"
	-@erase "$(INTDIR)\cMemb.obj"
	-@erase "$(INTDIR)\debug.obj"
	-@erase "$(INTDIR)\imsconf2.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\msg.obj"
	-@erase "$(INTDIR)\res.res"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\nmchat.exe"
	-@erase "$(OUTDIR)\nmchat.ilk"
	-@erase "$(OUTDIR)\nmchat.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /WX /Gm /GX /ZI /Od /D "DEBUG" /D "_DEBUG" /D "STRICT" /D "WIN32" /D "_WINDOWS" /Fp"$(INTDIR)\nmchat.pch" /YX"precomp.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"   /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\res.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\nmchat.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comctl32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\nmchat.pdb" /debug /machine:I386 /out:"$(OUTDIR)\nmchat.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\cConf.obj" \
	"$(INTDIR)\cData.obj" \
	"$(INTDIR)\clUtil.obj" \
	"$(INTDIR)\cmd.obj" \
	"$(INTDIR)\cMemb.obj" \
	"$(INTDIR)\debug.obj" \
	"$(INTDIR)\imsconf2.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\msg.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\res.res"

"$(OUTDIR)\nmchat.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("nmchat.dep")
!INCLUDE "nmchat.dep"
!ELSE 
!MESSAGE Warning: cannot find "nmchat.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "nmChat - Win32 Release" || "$(CFG)" == "nmChat - Win32 Debug"
SOURCE=.\cConf.cpp

"$(INTDIR)\cConf.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\cData.cpp

"$(INTDIR)\cData.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\clUtil.cpp

"$(INTDIR)\clUtil.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\cmd.cpp

"$(INTDIR)\cmd.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\cMemb.cpp

"$(INTDIR)\cMemb.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\debug.cpp

"$(INTDIR)\debug.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\imsconf2.c

"$(INTDIR)\imsconf2.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\IMSCONF2.IDL

!IF  "$(CFG)" == "nmChat - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\IMSCONF2.tlb" /mktyplib203 /o "NUL" /win32 

"$(INTDIR)\IMSCONF2.tlb" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "nmChat - Win32 Debug"

TargetDir=.\Debug
InputPath=.\IMSCONF2.IDL
InputName=IMSCONF2

".\imsconf2.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /client none /server none /ms_ext /W1 /c_ext /env win32 /Oicf  /dlldata  $(TargetDir)\dlldata.rpc /proxy $(TargetDir)\$(InputName).rpc /header  $(InputName).h /iid $(InputName).c $(InputPath)
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

