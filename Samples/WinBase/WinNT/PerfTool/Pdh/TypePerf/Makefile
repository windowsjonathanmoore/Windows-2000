!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
#Copyright (C) 1996-1999.  Microsoft Corporation.  All rights reserved.
#
# Nmake macros for building Windows 32-Bit apps

!IF "$(TARGETOS)" == "WINNT"

!include <Win32.Mak>

all: $(OUTDIR) $(OUTDIR)\typeperf.exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

$(OUTDIR)\typeperf.obj: typeperf.c
    $(cc) $(cflags) $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" typeperf.c

$(OUTDIR)\typeperf.res: typeperf.rc
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\typeperf.res typeperf.rc

$(OUTDIR)\typeperf.exe: $(OUTDIR)\typeperf.obj $(OUTDIR)\typeperf.res
    $(link) $(ldebug) $(conlflags) -out:$(OUTDIR)\typeperf.exe $(OUTDIR)\typeperf.obj $(OUTDIR)\typeperf.res $(conlibs) pdh.lib

clean:
        $(CLEANUP)

!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
