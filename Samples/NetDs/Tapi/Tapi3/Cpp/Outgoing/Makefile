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

# Nmake macros for building Windows 32-Bit apps
!include <win32.mak>

#!if "$(TARGETOS)" == "WINNT" && "APPVER" == "5.01"

PROJ = T3OUT

all: $(OUTDIR) $(OUTDIR)\$(PROJ).exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Define project specific macros
PROJ_OBJS  = $(OUTDIR)\outgoing.obj
BASE_OBJS  =
!if "$(TARGETOS)" == "WINNT" && "APPVER" == "5.01"
EXTRA_LIBS = version.lib ole32.lib oleaut32.lib uuid.lib strmiids.lib
!else
EXTRA_LIBS = version.lib ole32.lib oleaut32.lib uuid.lib strmiids.lib t3iid.lib
!endif
GLOBAL_DEP = resource.h
RC_DEP     = resource.h



# Inference rule for updating the object files
.cpp{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) -GX $(cvars) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $<

# Build rule for resource file
$(OUTDIR)\$(PROJ).res: outgoing.rc $(RC_DEP)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\$(PROJ).res outgoing.rc

# Build rule for EXE
$(OUTDIR)\$(PROJ).EXE: $(BASE_OBJS) $(PROJ_OBJS) $(OUTDIR)\$(PROJ).res
    $(link) $(linkdebug) $(guilflags) \
    $(BASE_OBJS) $(PROJ_OBJS) $(OUTDIR)\$(PROJ).res $(guilibs) $(EXTRA_LIBS) \
    -out:$(OUTDIR)\$(PROJ).exe $(MAPFILE)


# Rules for cleaning out those old files
clean:
        $(CLEANUP)

#!else
#!message Sorry this sample is only supported on the Prerelease build environments
#!endif
