!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1997-1999  Microsoft Corporation.  All Rights Reserved.
#
#
# Processor independent makefile
APPVER=5.0

# Nmake macros for building Windows 32-Bit apps
!include <win32.mak>

PROJ = TAPIRecv

all: $(OUTDIR) $(OUTDIR)\$(PROJ).exe 

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Define project specific macros
PROJ_OBJS  = $(OUTDIR)\TAPIRecv.obj $(OUTDIR)\AVIFileWriter.obj $(OUTDIR)\Processing.obj $(OUTDIR)\WorkerThread.Obj
BASE_OBJS  =
EXTRA_LIBS = strmiids.lib amstrmid.lib strmbase.lib vfw32.lib user32.lib t3iid.lib
INCLUDE  = $(MSSDK)\samples\multimedia\directshow\baseclasses;$(INCLUDE)


# Inference rule for updating the object files
.cpp{$(OUTDIR)}.obj:
  $(cc) $(cdebug) $(cflags) -GX $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**


# Build rule for EXE
$(OUTDIR)\$(PROJ).EXE: $(BASE_OBJS) $(PROJ_OBJS)
    $(link) $(ldebug) $(conlflags) \
    $(BASE_OBJS) $(PROJ_OBJS) \
    $(EXTRA_LIBS) -out:$(OUTDIR)\$(PROJ).exe $(MAPFILE) $(olelibsdll) /NODEFAULTLIB:libcmt.lib


# Rules for cleaning out old files
clean:
        $(CLEANUP)
