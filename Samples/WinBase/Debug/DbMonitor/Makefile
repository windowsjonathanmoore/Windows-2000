!include <disable.mak>

# Makefile - DbMonitor.Exe
#
# Copyright 1998 Microsoft Corporation.
#
# requires: ImageHlp.Lib
#
!Include <Win32.Mak>

!if "$(CPU)" != "IA64"

all: $(OUTDIR) $(OUTDIR)\DbMonitor.Exe

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

$(OUTDIR)\DbMonitor.Obj: DbMonitor.c
    $(cc) $(cflags) $(cvars) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" DbMonitor.c

$(OUTDIR)\DbMonitor.Exe: $(OUTDIR)\DbMonitor.Obj
    $(link) $(conflags) -out:$(OUTDIR)\DbMonitor.Exe $(OUTDIR)\DbMonitor.Obj $(conlibs) ImageHlp.Lib

clean:
        $(CLEANUP)
!else
!message Sorry, this sample is currently not supported for 64bit platforms
!endif
