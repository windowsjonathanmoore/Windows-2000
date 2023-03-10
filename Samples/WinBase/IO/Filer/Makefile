!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1993-1999.  Microsoft Corporation.  All rights reserved.
#
# Nmake macros for building FILER
# Define NODEBUG to build FILER without debugging information.
# Define UNICODE to build FILER with UNICODE characters.

!IF "$(TARGETOS)" == "WINNT"

!include <Win32.Mak>

!ifdef UNICODE
unicode = -DUNICODE
!else
unicode =
!endif

#cflags=$(cflags) -DDEVL=1

all: $(OUTDIR) $(OUTDIR)\filer.exe

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Update the resource if necessary

$(OUTDIR)\filer.res: filer.rc filer.dlg filer.h globals.h *.bmp filer.ico
    $(rc) $(rcvars) -r /fo $(OUTDIR)\filer.res  filer.rc

# Update the object files if necessary

$(OUTDIR)\enumdrv.obj: enumdrv.c enumdrv.h globals.h
    $(cc) $(cdebug) $(cflags) $(cvars) $(unicode) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" enumdrv.c

$(OUTDIR)\drvproc.obj: drvproc.c drvproc.h globals.h expdir.h filer.h
    $(cc) $(cdebug) $(cflags) $(cvars) $(unicode) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" drvproc.c

$(OUTDIR)\expdir.obj: expdir.c expdir.h filer.h drvproc.h globals.h
    $(cc) $(cdebug) $(cflags) $(cvars) $(unicode) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" expdir.c

$(OUTDIR)\filer.obj: filer.c filer.h enumdrv.h globals.h
    $(cc) $(cdebug) $(cflags) $(cvars) $(unicode) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" filer.c

# Update the executable file if necessary, and if so, add the resource back in.

$(OUTDIR)\filer.exe: $(OUTDIR)\filer.obj $(OUTDIR)\enumdrv.obj $(OUTDIR)\drvproc.obj $(OUTDIR)\expdir.obj $(OUTDIR)\filer.res makefile
    $(link) $(ldebug)  $(guilflags) -out:$(OUTDIR)\filer.exe\
    $(OUTDIR)\filer.obj $(OUTDIR)\enumdrv.obj $(OUTDIR)\drvproc.obj $(OUTDIR)\expdir.obj $(OUTDIR)\filer.res\
    version.lib $(guilibs)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
