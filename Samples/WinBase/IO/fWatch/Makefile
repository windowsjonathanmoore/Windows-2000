!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1996-1999.  Microsoft Corporation.  All rights reserved.
#

# Nmake macros for building Windows 32-Bit apps

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

all: $(OUTDIR) $(OUTDIR)\fwatch.exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

$(OUTDIR)\fwatch.obj: fwatch.c
     $(cc) $(cflags) $(cdebug) $(cvars) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" fwatch.c

$(OUTDIR)\fwatch.exe: $(OUTDIR)\fwatch.obj
    $(link) $(ldebug) $(conlflags) -out:$(OUTDIR)\fwatch.exe $(OUTDIR)\fwatch.obj $(conlibs) user32.lib

clean:
        $(CLEANUP)

!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
