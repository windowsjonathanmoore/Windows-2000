!include <disable.mak>


!IF "$(TARGETOS)" == "WINNT"

!include <Win32.Mak>

opengllibs	= opengl32.lib glu32.lib glaux.lib

EXES	= taccum.exe \
	tbitmap1.exe \
	tbitmap2.exe \
	tcopy.exe \
	tdepth.exe \
	teval.exe \
	tfog.exe \
	tline.exe \
	tlogo.exe \
	tnurb.exe \
	tpoint.exe \
	tprim.exe \
	tquad.exe \
	tselect.exe \
	tspeed.exe \
	tsphere.exe \
	tstar.exe \
	tstencil.exe \
	tstretch.exe \
	ttexture.exe \
	ttri.exe \
	twave.exe

all: $(EXES)

.c.exe:
    $(cc) $(cflags) $(cdebug) $(cvars) $<
    $(link) $(linkdebug) $(guiflags) -subsystem:windows -entry:mainCRTStartup -out:$*.exe $*.obj $(opengllibs) $(guilibs)
!ELSE
!MESSAGE Sorry these samples only build for the Windows NT Platform
!ENDIF
