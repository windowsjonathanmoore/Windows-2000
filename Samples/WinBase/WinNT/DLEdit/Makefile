!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1999 Microsoft Corporation.  All rights reserved.

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

PROJ = DLEDIT

all: $(OUTDIR) $(OUTDIR)\$(PROJ).exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

PROJ_OBJS = $(OUTDIR)\dledit.obj

.cpp{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) $(cvars) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $<

$(OUTDIR)\$(PROJ).exe: $(PROJ_OBJS)
    $(link) $(ldebug) $(conlflags)\
    $(PROJ_OBJS) \
    -out:$(OUTDIR)\$(PROJ).exe \
    $(conlibs)

clean:
    del $(OUTDIR)\*.bak
    del $(OUTDIR)\*.opt
    del $(OUTDIR)\*.pdb
    del $(OUTDIR)\*.obj

cleaner: clean
    del $(OUTDIR)\*.exe

!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
