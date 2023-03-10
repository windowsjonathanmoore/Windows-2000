!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1996-1999.  Microsoft Corporation.  All rights reserved.
#

!IF "$(TARGETOS)" == "WINNT"

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\cfiler.exe $(OUTDIR)\cf.hlp

LINK32_OBJS= \
	$(OUTDIR)\cfiler.obj \
	$(OUTDIR)\crp.obj \
	$(OUTDIR)\drvproc.obj \
	$(OUTDIR)\enumdrv.obj \
	$(OUTDIR)\expdir.obj \
	$(OUTDIR)\fillfile.obj \
	$(OUTDIR)\table.obj
        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Build rule for resource file
SOURCE=.\cfiler.rc

$(OUTDIR)\cfiler.res: $(SOURCE) $(OUTDIR) *.bmp *.ico
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\cfiler.res $(SOURCE)

# Generic rule for building ALL CPP files and placing their OBJ's in the OUTDIR
.c{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**


# Update the help file if necessary
$(OUTDIR)\cf.hlp : cf.rtf cf.hpj
    $(hc) -o .\$(OUTDIR)\cf.hlp $(hcvars) cf.hpj 


# Build rule for EXE
$(OUTDIR)\cfiler.exe:  $(OUTDIR) $(LINK32_OBJS) $(OUTDIR)\cfiler.res
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\cfiler.pdb -out:$(OUTDIR)\cfiler.exe $(LINK32_OBJS) $(OUTDIR)\cfiler.res $(guilibsmt)

#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)
        
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
