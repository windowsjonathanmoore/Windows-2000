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

!IF ("$(CPU)" != "IA64")

PROJ = msqscan

all: $(OUTDIR) $(OUTDIR)\$(PROJ).exe

# Define project specific macros
PROJ_OBJS  = $(OUTDIR)\stdafx.obj \
             $(OUTDIR)\ADFDlg.obj \
             $(OUTDIR)\cwia.obj \
             $(OUTDIR)\MSQSCAN.obj \
             $(OUTDIR)\MSQSCANDlg.obj \
             $(OUTDIR)\Preview.obj \
             $(OUTDIR)\ProgressDlg.obj \
             $(OUTDIR)\uitables.obj 

BASE_OBJS  =
EXTRA_LIBS = wiaguid.lib
GLOBAL_DEP = 
RC_DEP     = resource.h

$(OUTDIR) :
  if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Inference rule for updating the object files
.cpp{$(OUTDIR)}.obj:
  $(cc) $(cdebug) $(cflags) $(cvarsdll) /D_AFXDLL /D_MBCS /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

# Build rule for resource file
$(OUTDIR)\$(PROJ).res: $(PROJ).rc $(RC_DEP)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\$(PROJ).res $(PROJ).rc

# Build rule for EXE
$(OUTDIR)\$(PROJ).EXE: $(BASE_OBJS) $(PROJ_OBJS) $(OUTDIR)\$(PROJ).res
    $(link) $(linkdebug) $(guilflags) \
    $(BASE_OBJS) $(PROJ_OBJS) $(OUTDIR)\$(PROJ).res $(guilibs) $(EXTRA_LIBS) \
    -out:$(OUTDIR)\$(PROJ).exe $(MAPFILE)

clean:
    $(CLEANUP)

!ELSE
!MESSAGE Sample not supported on 64 bit platforms
!ENDIF