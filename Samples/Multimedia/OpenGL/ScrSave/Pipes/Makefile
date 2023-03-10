!include <disable.mak>


!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

all: $(OUTDIR) $(OUTDIR)\sspipes.scr

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)


#cflags=$(cflags) -DUNICODE -D_UNICODE -DWINVER=0x0400

include_paths = /I../common

.c{$(OUTDIR)}.obj:
    $(cc) $(include_paths) $(cdebug) $(cflags) $(cvars) $(scall) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

.cxx{$(OUTDIR)}.obj:
    $(cc) $(include_paths) $(cdebug) $(cflags) $(cvars) $(scall) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

$(OUTDIR)\sspipes.res: sspipes.rc 
    $(rc) $(include_paths) -r /fo $(OUTDIR)\sspipes.res sspipes.rc

$(OUTDIR)\sspipes.scr: $(OUTDIR)\dialog.obj  \
           $(OUTDIR)\sspipes.obj \
           $(OUTDIR)\state.obj   \
           $(OUTDIR)\nstate.obj  \
           $(OUTDIR)\fstate.obj  \
           $(OUTDIR)\pipe.obj    \
           $(OUTDIR)\npipe.obj   \
           $(OUTDIR)\fpipe.obj   \
           $(OUTDIR)\view.obj    \
           $(OUTDIR)\node.obj    \
           $(OUTDIR)\objects.obj \
           $(OUTDIR)\eval.obj    \
           $(OUTDIR)\xc.obj      \
           $(OUTDIR)\sspipes.res \
		   ..\common\$(OUTDIR)\sscommon.lib
	$(link) $(linkdebug) $(savlflags) -machine:$(CPU) -out:$*.scr $** $(guilibs) opengl32.lib glu32.lib glaux.lib scrnsave.lib comdlg32.lib comctl32.lib

clean:
        $(CLEANUP)
!ELSE
!MESSAGE Sorry this sample builds only for the Windows NT Platform
!ENDIF
