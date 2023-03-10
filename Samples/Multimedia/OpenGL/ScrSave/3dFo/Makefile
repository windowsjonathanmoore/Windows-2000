!include <disable.mak>

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

all: $(OUTDIR) $(OUTDIR)\ss3dfo.scr

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

#cflags=$(cflags) -DUNICODE -D_UNICODE -DWINVER=0x0400

HINCLUDES= -I..  -I..\common 

.c{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(HINCLUDES) $(cflags) $(cvars) $(scall) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**


$(OUTDIR)\ss3dfo.res: ss3dfo.rc 
	$(rc) -r $(HINCLUDES) /fo $(OUTDIR)\ss3dfo.res ss3dfo.rc

$(OUTDIR)\ss3dfo.scr: $(OUTDIR)\ss3dfo.res \
	$(OUTDIR)\gendrop.obj\
	$(OUTDIR)\genexpld.obj \
	$(OUTDIR)\genlem.obj \
	$(OUTDIR)\genstrip.obj\
	$(OUTDIR)\gentex.obj \
    $(OUTDIR)\genwin.obj \
    $(OUTDIR)\mesh.obj \
    $(OUTDIR)\ss3dfo.obj \
	..\common\$(OUTDIR)\sscommon.lib
	$(link) $(linkdebug) $(savlflags) -machine:$(CPU) -out:$*.scr $** \
					$(guilibs) opengl32.lib glu32.lib glaux.lib \
					scrnsave.lib comdlg32.lib comctl32.lib 

clean:
        $(CLEANUP)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
