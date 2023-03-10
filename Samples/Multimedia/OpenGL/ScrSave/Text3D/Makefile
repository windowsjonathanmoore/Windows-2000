!include <disable.mak>


!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

all: $(OUTDIR) $(OUTDIR)\sstext3d.scr

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)


#cflags=$(cflags) -DUNICODE -D_UNICODE -DWINVER=0x0400

include_paths = /I../common

.c{$(OUTDIR)}.obj:
    $(cc) $(include_paths) $(cdebug) $(cflags) $(cvars) $(scall) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**


$(OUTDIR)\sstext3d.res: sstext3d.rc 
    $(rc) $(include_paths) -r /fo $(OUTDIR)\sstext3d.res sstext3d.rc

$(OUTDIR)\sstext3d.scr: $(OUTDIR)\sstext3d.res \
              $(OUTDIR)\dialog.obj   \
              $(OUTDIR)\sstext3d.obj \
              $(OUTDIR)\font.obj     \
              ..\common\$(OUTDIR)\sscommon.lib
    $(link) $(linkdebug) $(savlflags) -machine:$(CPU) -out:$*.scr $** $(guilibs) opengl32.lib glu32.lib glaux.lib scrnsave.lib comdlg32.lib comctl32.lib

clean:
        $(CLEANUP)

!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
