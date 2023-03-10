!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1998-1999.  Microsoft Corporation.  All rights reserved.

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

PROJ = CheckSFP

all: $(OUTDIR) $(OUTDIR)\$(PROJ).exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

PROJ_OBJS = $(OUTDIR)\Checksfp.obj
EXTRA_LIBS =  sfc.lib

.cpp{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) $(cvars) -D UNICODE -D _UNICODE /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $<

$(OUTDIR)\$(PROJ).exe: $(PROJ_OBJS)
    $(link) $(ldebug) $(conlflags) \
    $(PROJ_OBJS) \
    -out:$(OUTDIR)\$(PROJ).exe -entry:wmainCRTStartup \
    $(conlibs)  $(EXTRA_LIBS)

clean:
        $(CLEANUP)

!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
