!include <disable.mak>

# Windows-32 TTY Example
# Copyright 1992 - 1999 Microsoft Corporation

!include <WIN32.MAK>

proj = TTY

all: $(OUTDIR) $(OUTDIR)\$(proj).exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Update the resource if necessary
$(OUTDIR)\$(proj).res: $(proj).rc resource.h
    rc -r -fo $(OUTDIR)\$(proj).res $(proj).rc


# Update the object file if necessary
$(OUTDIR)\$(proj).obj: $(proj).c $(proj).h
    $(cc) $(cdebug) $(cflags) $(cvars) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(proj).c


# Update the EXE
$(OUTDIR)\$(proj).exe: $(OUTDIR)\$(proj).obj $(OUTDIR)\$(proj).res $(proj).def
    $(link) $(linkdebug) $(guiflags) $(OUTDIR)\$(proj).obj  $(guilibs) VERSION.LIB $(OUTDIR)\$(proj).res -out:$(OUTDIR)\$(proj).exe

clean:
        $(CLEANUP)
