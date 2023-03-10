!include <disable.mak>


!IF "$(TARGETOS)" == "WINNT"

!include <Win32.Mak>

!if "$(CPU)" == "i386"
cflags = $(cflags) -D_CRTAPI1=_cdecl -D_CRTAPI2=_cdecl
!else
cflags = $(cflags) -D_CRTAPI1= -D_CRTAPI2=
!endif

opengllibs	    = opengl32.lib glu32.lib glaux.lib

EXES	=  vasphere.exe

all: $(EXES)

.c.exe:
    $(cc) $(cflags) $(cdebug) -DSILENT_WARN $(cvars) $<
    $(link) $(linkdebug) $(guiflags) -subsystem:windows -entry:mainCRTStartup -out:$*.exe $*.obj $(opengllibs) $(guilibs)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
