!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1995-1999.  Microsoft Corporation.  All rights reserved.
#
# Fibers are supported on Windows NT 3.51 service pack 3 and beyond.

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

#detect build time environment
!IF "$(OS)" == "Windows_NT"
all: $(OUTDIR) $(OUTDIR)\fibers.exe
!else
all: WARN_MSG
!endif

WARN_MSG:
    @echo "This sample will work only on Windows NT"

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

$(OUTDIR)\fibers.obj: fibers.c
    $(cc) $(cflags) $(cvars) $(cdebug) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" fibers.c

$(OUTDIR)\fibers.exe: $(OUTDIR)\fibers.obj
    $(link) $(ldebug) $(conlflags) -out:$(OUTDIR)\fibers.exe $(OUTDIR)\fibers.obj $(conlibs)

clean:
        $(CLEANUP)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
