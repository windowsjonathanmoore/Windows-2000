!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright 1993 - 1999 Microsoft Corporation.  All Rights Reserved.
#
# Processor independent makefile

!include <win32.mak>

# This is a unicode project, so make it as such.
cflags=$(cflags) -D UNICODE -D _UNICODE
conflags=$(conflags) -entry:wmainCRTStartup

PROJ = SAMPLE1

all: $(OUTDIR) $(OUTDIR)\$(PROJ).exe

# Define project specific macros
PROJ_OBJS  = $(OUTDIR)\stdafx.obj \
             $(OUTDIR)\sample1.obj \
             $(OUTDIR)\iauth.obj \
             $(OUTDIR)\guids.obj

EXTRA_LIBS = ole32.lib oledb.lib user32.lib

$(OUTDIR) :
  if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Inference rule for updating the object files
.cpp{$(OUTDIR)}.obj:
  $(cc) $(cdebug) $(cflags) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

# Build rule for EXE
$(OUTDIR)\$(PROJ).EXE: $(BASE_OBJS) $(PROJ_OBJS)
    $(link) $(ldebug) $(conflags) $(conlibsdll)\
    $(BASE_OBJS) $(PROJ_OBJS) $(conlibs) $(EXTRA_LIBS) \
    -out:$(OUTDIR)\$(PROJ).exe

clean:
    $(CLEANUP)