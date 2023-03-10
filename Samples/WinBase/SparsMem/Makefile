!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1998-1999.  Microsoft Corporation.  All rights reserved.

!include <win32.mak>

PROJ = SparsMem

all: $(OUTDIR) $(OUTDIR)\$(PROJ).exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

PROJ_OBJS = $(OUTDIR)\sparsmem.obj
RC_DEP    = resource.h
EXTRA_LIBS = advapi32.lib

$(OUTDIR)\sparsmem.obj: sparsmem.c resource.h

.c{$(OUTDIR)}.obj:
   $(cc) $(cdebug) $(cflags) $(cvars) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $<


$(OUTDIR)\$(PROJ).res: $(PROJ).rc $(RC_DEP)
    $(rc) $(rcflags) $(rcvars) -fo $(OUTDIR)\$(PROJ).res $(PROJ).rc


$(OUTDIR)\$(PROJ).exe: $(PROJ_OBJS) $(OUTDIR)\$(PROJ).res
    $(link) $(ldebug) $(guilflags) $(PROJ_OBJS) \
    -out:$(OUTDIR)\$(PROJ).exe  \
    $(OUTDIR)\$(PROJ).res $(guilibs) $(EXTRA_LIBS)

clean:
        $(CLEANUP)
