!include <disable.mak>

!include <win32.mak>

cflags = -DWINNT $(cflags) /Fo"$(OUTDIR)\\" 

all: $(OUTDIR)\reitp.exe

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(OUTDIR)\reitp.obj: reitp.c
    $(cc) $(cdebug) $(cflags) $(cvars) reitp.c

$(OUTDIR)\frmtbar.obj: frmtbar.c
    $(cc) $(cdebug) $(cflags) $(cvars) frmtbar.c

$(OUTDIR)\oleutl.obj: oleutl.c
    $(cc) $(cdebug) $(cflags) $(cvars) oleutl.c

$(OUTDIR)\drawicon.obj: drawicon.c
    $(cc) $(cdebug) $(cflags) $(cvars) drawicon.c

$(OUTDIR)\olestd.obj: olestd.c
    $(cc) $(cdebug) $(cflags) $(cvars) olestd.c

$(OUTDIR)\reitp.res: reitp.rc reitp.h reitp.dlg
    $(rc) $(rcvars) -r -fo $(OUTDIR)\reitp.res reitp.rc

$(OUTDIR)\reitp.exe: $(OUTDIR) $(OUTDIR)\reitp.obj $(OUTDIR)\reitp.res $(OUTDIR)\frmtbar.obj $(OUTDIR)\olestd.obj $(OUTDIR)\drawicon.obj $(OUTDIR)\oleutl.obj
    $(link) $(linkdebug) $(guiflags) /pdb:"$(OUTDIR)\reitp.pdb" -out:$(OUTDIR)\reitp.exe $(OUTDIR)\reitp.obj $(OUTDIR)\reitp.res $(OUTDIR)\frmtbar.obj $(OUTDIR)\olestd.obj $(OUTDIR)\drawicon.obj $(OUTDIR)\oleutl.obj $(olelibs) comctl32.lib shell32.lib oledlg.lib
