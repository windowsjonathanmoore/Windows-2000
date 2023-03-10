!include <disable.mak>

PROJ = ConGUI
OBJ = $(OUTDIR)\CONSOLE.OBJ $(OUTDIR)\GUI.OBJ

# Nmake macros for building Windows 32-Bit apps
!include <Win32.Mak>

all: $(OUTDIR) $(OUTDIR)\$(PROJ).exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Inference Rules:

.c{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) $(cvars) $(cf) /Fo"$(OUTDIR)\\" $**

.rc{$(OUTDIR)}.res:
    $(rc) $(rcvars) -r /fo $(OUTDIR)\$(PROJ).res $**

$(OUTDIR)\$(PROJ).hlp: $(PROJ).rtf $(PROJ).hpj
    $(hc) -o .\$(OUTDIR)\$(PROJ).hlp $(hcvars) $(PROJ).hpj 

$(OUTDIR)\$(PROJ).exe: $(OBJ) $(OUTDIR)\$(PROJ).res $(OUTDIR)\$(PROJ).hlp
    $(link) $(linkdebug) $(conflags) -out:$(OUTDIR)\$(PROJ).exe $(OBJ) $(OUTDIR)\$(PROJ).res $(guilibs)

clean:
        $(CLEANUP)
