# Microsoft Developer Studio Generated NMAKE File, Based on psidl.dsp
!IF "$(CFG)" == ""
CFG=psidl - Win32 Debug
!MESSAGE No configuration specified. Defaulting to psidl - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "psidl - Win32 Release" && "$(CFG)" != "psidl - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "psidl.mak" CFG="psidl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "psidl - Win32 Release" (based on "Win32 (x86) Generic Project")
!MESSAGE "psidl - Win32 Debug" (based on "Win32 (x86) Generic Project")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

OUTDIR=.
INTDIR=.\..\ps_win32\release\x86

ALL : "..\ps_win32\server.tlb"


CLEAN :
	-@erase "..\ps_win32\server.tlb"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe

!IF  "$(CFG)" == "psidl - Win32 Release"

!ELSEIF  "$(CFG)" == "psidl - Win32 Debug"

!ENDIF 

MTL_PROJ=/out "..\ps_win32" /env win32 

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("psidl.dep")
!INCLUDE "psidl.dep"
!ELSE 
!MESSAGE Warning: cannot find "psidl.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "psidl - Win32 Release" || "$(CFG)" == "psidl - Win32 Debug"
SOURCE=.\server.idl
MTL_SWITCHES=/tlb "$(OUTDIR)\server.tlb" /out "..\ps_win32" /env win32 

"..\ps_win32\server.tlb" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<



!ENDIF 

