!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1990-1999.  Microsoft Corporation.  All rights reserved.
#
# Nmake macros for building Windows 32-Bit apps

!include <win32.mak>
!if "$(CPU)" != "IA64"

PROJ = wdbgexts

all: $(OUTDIR) $(OUTDIR)\$(PROJ).dll

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Update the object files if necessary

$(OUTDIR)\$(PROJ).obj: $(PROJ).c
    $(cc) $(cflags) $(cvarsdll) $(cdebug) $(scall) -I. -I..\..\sdktools\image\include /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(PROJ).c

# Update the import library

$(OUTDIR)\$(PROJ).lib: $(OUTDIR)\$(PROJ).obj $(PROJ).def
    $(implib) -machine:$(CPU) \
    -def:$(PROJ).def \
    $*.obj \
    -out:$*.lib

# Update the dynamic link library

$(OUTDIR)\$(PROJ).dll: $(OUTDIR)\$(PROJ).obj $(PROJ).def $(OUTDIR)\$(PROJ).lib
    $(link) $(ldebug) $(dlllflags) \
    -base:0x1C000000 \
    -out:$*.dll \
    $*.exp $*.obj $(conlibsdll)

clean:
        $(CLEANUP)

!else
!message Sorry building this sample for 64 bit is currently not supported.
!endif
