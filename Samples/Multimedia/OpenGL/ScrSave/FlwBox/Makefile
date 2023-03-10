!include <disable.mak>


!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>


all: $(OUTDIR) $(OUTDIR)\ssflwbox.scr

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)


#cflags=$(cflags) -DUNICODE -D_UNICODE -DWINVER=0x0400

include_paths = /I../common

.c{$(OUTDIR)}.obj:
    $(cc) $(include_paths) $(cdebug) $(cflags) $(cvars) $(scall) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

$(OUTDIR)\ssflwbox.res: ssflwbox.rc 
    $(rc) $(include_paths) -r /fo $(OUTDIR)\ssflwbox.res ssflwbox.rc

$(OUTDIR)\ssflwbox.scr: $(OUTDIR)\ssflwbox.res      \
                        $(OUTDIR)\geom.obj          \
                        $(OUTDIR)\ssflwbox.obj      \
			..\common\$(OUTDIR)\sscommon.lib
    $(link) $(linkdebug) $(savlflags) -machine:$(CPU) -out:$*.scr $** $(guilibs) opengl32.lib glu32.lib glaux.lib scrnsave.lib comdlg32.lib comctl32.lib

clean:
        $(CLEANUP)

!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
