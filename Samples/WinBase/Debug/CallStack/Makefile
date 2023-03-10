!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1999.  Microsoft Corporation.  All rights reserved.

!include <win32.mak>

!if "$(CPU)" != "IA64"

PROJ1 = CallStack

all: $(OUTDIR) $(OUTDIR)\$(PROJ1).exe

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

PROJ1_OBJS = $(OUTDIR)\CallStack.obj

.cpp{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) $(cvars) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

$(OUTDIR)\$(PROJ1).exe: $(PROJ1_OBJS)
    $(link) $(ldebug) $(conlflags) $(PROJ1_OBJS) -out:$(OUTDIR)\$(PROJ1).exe $(conlibs)

clean:
        $(CLEANUP)

cleaner: clean
    del $(OUTDIR)\*.exe
!else
!message Sorry this sample is not currently supported for 64bit platoforms
!endif
