!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1997  Microsoft Corporation.  All Rights Reserved.
#
#
# Processor independent makefile

# Nmake macros for building Windows 32-Bit apps
!include <win32.mak>

!IF "$(TARGETOS)" == "WIN95"
cflags = -D_WIN32_DCOM $(cflags)
!ENDIF

PROJ = CLIENT

all: $(OUTDIR)\$(PROJ).exe 

# Define project specific macros
PROJ_OBJS  = $(OUTDIR)\client.obj $(OUTDIR)\callnot.obj
BASE_OBJS  =

!IF "$(APPVER)" == "5.01"
EXTRA_LIBS = version.lib ole32.lib oleaut32.lib uuid.lib
!ELSE
EXTRA_LIBS = version.lib ole32.lib oleaut32.lib uuid.lib t3iid.lib
!ENDIF

GLOBAL_DEP = resource.h
RC_DEP     = resource.h



# Inference rule for updating the object files
#.cpp.obj:
#  $(cc) $(cdebug) $(cflags) -GX $(cvars) $*.cpp

# Build rule for resource file
$(PROJ).res: $(PROJ).rc $(RC_DEP)
    $(rc) $(rcflags) $(rcvars) /fo $(PROJ).res $(PROJ).rc

# Build rule for EXE
$(OUTDIR)\$(PROJ).EXE: $(BASE_OBJS) $(PROJ_OBJS) $(PROJ).res $(OUTDIR)
    $(link) $(linkdebug) $(guilflags) \
    $(BASE_OBJS) $(PROJ_OBJS) $(PROJ).res $(guilibs) $(EXTRA_LIBS) \
    -out:$(OUTDIR)\$(PROJ).exe $(MAPFILE)

SOURCE=.\client.cpp

"$(OUTDIR)\client.obj" : $(SOURCE) "$(OUTDIR)"
    $(cc) $(cdebug) $(cflags) -GX $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\callnot.cpp

"$(OUTDIR)\callnot.obj" : $(SOURCE) "$(OUTDIR)"
    $(cc) $(cdebug) $(cflags) -GX $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"


# Rules for cleaning out those old files
clean:
    del *.bak *.pdb *.obj *.res *.exp *.map *.sbr *.bsc
