!include <disable.mak>

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

all: $(OUTDIR) $(OUTDIR)\ssmaze.scr

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)


cflags=$(cflags) -DFX_SINGLE 
#cflags=$(cflags) -DFX_SINGLE -DUNICODE -D_UNICODE -DWINVER=0x0400

HINCLUDES= -I..  -I..\common 

.c{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(HINCLUDES) $(cflags) $(cvars) $(scall) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

.cxx{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(HINCLUDES) $(cflags) $(cvars) $(scall) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

$(OUTDIR)\maze.res: maze.rc 
	$(rc) -r $(HINCLUDES) /fo $(OUTDIR)\maze.res maze.rc

#ssmaze.scr: maze.res \
$(OUTDIR)\ssmaze.scr: $(OUTDIR)\genmaze.obj\
	$(OUTDIR)\glmaze.obj \
	$(OUTDIR)\ssmaze.obj \
	$(OUTDIR)\slvmaze.obj\
	$(OUTDIR)\dialog.obj \
    $(OUTDIR)\maze.res\
	..\common\$(OUTDIR)\sscommon.lib
	$(link) $(linkdebug) $(savlflags) -machine:$(CPU) -out:$*.scr $** \
					$(guilibs) opengl32.lib glu32.lib glaux.lib \
					scrnsave.lib comdlg32.lib comctl32.lib 

clean:
        $(CLEANUP)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
