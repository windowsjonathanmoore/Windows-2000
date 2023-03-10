
# Microsoft Developer Studio Generated NMAKE File, Based on psidl.dsp
!IF "$(CFG)" == ""
CFG=psidl - Win64 Debug
!MESSAGE No configuration specified. Defaulting to psidl - Win64 Debug.
!ENDIF 

!IF "$(CFG)" != "psidl - Win64 Release" && "$(CFG)" != "psidl - Win64 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "psidl64.mak" CFG="psidl - Win64 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "psidl - Win64 Release" (based on "Win64 (IA64) Generic Project")
!MESSAGE "psidl - Win64 Debug" (based on "Win64 (IA64) Generic Project")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

OUTDIR=.
INTDIR=.\..\ps_win64\release\IA64

ALL : "..\ps_win64\server.tlb"


CLEAN :
	-@erase "..\ps_win64\server.tlb"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe

!IF  "$(CFG)" == "psidl - Win64 Release"

!ELSEIF  "$(CFG)" == "psidl - Win64 Debug"

!ENDIF 

MTL_PROJ=/out "..\ps_win64" /env win64 

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("psidl.dep")
!INCLUDE "psidl.dep"
!ELSE 
!MESSAGE Warning: cannot find "psidl.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "psidl - Win64 Release" || "$(CFG)" == "psidl - Win64 Debug"
SOURCE=.\server.idl
MTL_SWITCHES=/tlb "$(OUTDIR)\server.tlb" /out "..\ps_win64" /env win64 

"..\ps_win64\server.tlb" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<



!ENDIF 
