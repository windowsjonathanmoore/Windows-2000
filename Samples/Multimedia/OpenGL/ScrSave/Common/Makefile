!include <disable.mak>

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

all: $(OUTDIR) $(OUTDIR)\sscommon.lib

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

#cflags=$(cflags) -DUNICODE -D_UNICODE -DWINVER=0x0400

.c{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) $(cvars) $(scall) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

.cxx{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) $(cvars) $(scall) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

$(OUTDIR)\sscommon.res: sscommon.rc 
    $(rc) -r /fo $(OUTDIR)\sscommon.res sscommon.rc

$(OUTDIR)\sscommon.lib: $(OUTDIR)\material.obj \
		$(OUTDIR)\color.obj \
		$(OUTDIR)\ssdib.obj \
		$(OUTDIR)\texture.obj \
		$(OUTDIR)\ssimage.obj \
		$(OUTDIR)\ssa8.obj \
		$(OUTDIR)\math.obj \
		$(OUTDIR)\dialog.obj \
		$(OUTDIR)\fastdib.obj \
		$(OUTDIR)\scrnsave.obj \
		$(OUTDIR)\ssinit.obj \
		$(OUTDIR)\sswindow.obj \
		$(OUTDIR)\sswproc.obj \
		$(OUTDIR)\ssutil.obj \
		$(OUTDIR)\dlgdraw.obj \
		$(OUTDIR)\glscrnsv.obj \
		$(OUTDIR)\clear.obj \
		$(OUTDIR)\palette.obj \
		$(OUTDIR)\util.obj
	$(implib) -machine:$(CPU) -out:$*.lib $** 

clean:
        $(CLEANUP)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
