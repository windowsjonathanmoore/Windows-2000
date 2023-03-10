!include <disable.mak>

!if "$(CPU)" != "IA64"

# Makefile - bpsamp.Exe
#
# Copyright 1999 Microsoft Corporation.
#
#
!Include <Win32.Mak>

all: $(OUTDIR) $(OUTDIR)\bpsamp.exe

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

$(OUTDIR)\main.Obj: main.c
    $(cc) $(cflags) $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" main.c

$(OUTDIR)\utils.Obj: utils.c
    $(cc) $(cflags) $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" utils.c

$(OUTDIR)\dbgcmd.Obj: dbgcmd.c
    $(cc) $(cflags) $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" dbgcmd.c


$(OUTDIR)\bpsamp.exe: $(OUTDIR)\main.obj $(OUTDIR)\utils.obj $(OUTDIR)\dbgcmd.obj
    $(link) $(conflags) -out:$(OUTDIR)\bpsamp.Exe $(OUTDIR)\main.obj $(OUTDIR)\utils.obj $(OUTDIR)\dbgcmd.obj $(conlibs)

clean:
        $(CLEANUP)
!else
!message Sorry this sample is currently not supported for 64bit
!endif
