!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1998-2001  Microsoft Corporation.  All Rights Reserved.
#
#
# Processor independent makefile

# Nmake macros for building Windows 32-Bit apps
!include <win32.mak>

!if ("$(TARGETOS)" == "WINNT") && ("$(APPVER)" == "5.01")

PROJ = FILETERM

all: $(OUTDIR) $(OUTDIR)\$(PROJ).exe 

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Define project specific macros
PROJ_OBJS  = $(OUTDIR)\fileterm.obj $(OUTDIR)\callnot.obj
BASE_OBJS  =
EXTRA_LIBS = version.lib ole32.lib oleaut32.lib uuid.lib strmiids.lib amstrmid.lib
GLOBAL_DEP = resource.h
RC_DEP     = resource.h

CFLG=$(cflags) -DUNICODE -D_UNICODE

# Inference rule for updating the object files
.cpp{$(OUTDIR)}.obj:
  $(cc) $(cdebug) $(CFLG) -GX $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

# Build rule for resource file
$(OUTDIR)\$(PROJ).res: $(PROJ).rc $(RC_DEP)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\$(PROJ).res $(PROJ).rc

# Build rule for EXE
$(OUTDIR)\$(PROJ).EXE: $(BASE_OBJS) $(PROJ_OBJS) $(OUTDIR)\$(PROJ).res
    $(link) $(linkdebug) $(guilflags) \
    $(BASE_OBJS) $(PROJ_OBJS) $(OUTDIR)\$(PROJ).res $(guilibs) $(EXTRA_LIBS) \
    -out:$(OUTDIR)\$(PROJ).exe $(MAPFILE)


# Rules for cleaning out those old files
clean:
        $(CLEANUP)
!else
!message Sorry this sample is only supported on the Pre32 Platform.
!endif
