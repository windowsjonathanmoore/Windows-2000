!include <disable.mak>

!include <Win32.Mak>

all: $(OUTDIR) $(OUTDIR)\console.exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

$(OUTDIR)\console.exe: $(OUTDIR)\console.obj $(OUTDIR)\alocfree.obj $(OUTDIR)\create.obj $(OUTDIR)\fillatt.obj $(OUTDIR)\fillchar.obj \
                       $(OUTDIR)\flush.obj $(OUTDIR)\cursor.obj $(OUTDIR)\conmode.obj $(OUTDIR)\coninfo.obj $(OUTDIR)\contitle.obj \
                       $(OUTDIR)\getnumev.obj $(OUTDIR)\getlrgst.obj $(OUTDIR)\numbut.obj $(OUTDIR)\readout.obj $(OUTDIR)\readchar.obj \
                       $(OUTDIR)\scroll.obj $(OUTDIR)\size.obj $(OUTDIR)\handler.obj $(OUTDIR)\writein.obj $(OUTDIR)\codepage.obj $(OUTDIR)\console.res
  $(link) $(ldebug) $(conlflags) -out:$*.exe $** $(conlibs) \
    user32.lib advapi32.lib

.c{$(OUTDIR)}.obj:
  $(cc) $(cdebug) $(cflags) $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

$(OUTDIR)\console.res: console.rc console.ico
    $(rc) $(rcvars) -r -fo $(OUTDIR)\console.res console.rc

clean:
        $(CLEANUP)
