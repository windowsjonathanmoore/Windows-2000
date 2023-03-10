!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright 1993 - 1999 Microsoft Corporation.  All Rights Reserved.
#
#
# Processor independent makefile

# Nmake macros for building Windows 32-Bit apps
!include <Win32.Mak>

PROJ = rasberry

all: $(OUTDIR) $(OUTDIR)\$(PROJ).exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# Define project specific macros
PROJ_OBJS  = $(OUTDIR)\rasberry.obj $(OUTDIR)\statdlg.obj $(OUTDIR)\phbkdlg.obj $(OUTDIR)\dialdlg.obj $(OUTDIR)\authdlg.obj $(OUTDIR)\rasutil.obj
BASE_OBJS  = $(OUTDIR)\winmain.obj $(OUTDIR)\init.obj $(OUTDIR)\misc.obj $(OUTDIR)\about.obj $(OUTDIR)\dispatch.obj
EXTRA_LIBS = version.lib rasapi32.lib
GLOBAL_DEP = win16ext.h globals.h
RC_DEP     = globals.h about.dlg statdlg.dlg phbkdlg.obj dialdlg.dlg authdlg.dlg

# Inference rule for updating the object files
.c{$(OUTDIR)}.obj:
  $(cc) $(cdebug) $(cflags) $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

# Build rule for resource file
$(OUTDIR)\$(PROJ).res: $(PROJ).rc $(RC_DEP)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\$(PROJ).res $(PROJ).rc

# Build rule for EXE
$(OUTDIR)\$(PROJ).EXE: $(BASE_OBJS) $(PROJ_OBJS) $(OUTDIR)\$(PROJ).res
    $(link) $(linkdebug) $(guiflags) \
    $(BASE_OBJS) $(PROJ_OBJS) $(OUTDIR)\$(PROJ).res $(guilibs) $(EXTRA_LIBS) \
    -out:$(OUTDIR)\$(PROJ).exe $(MAPFILE)



# Rules for cleaning out those old files
clean:
        $(CLEANUP)
