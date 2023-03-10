!include <disable.mak>

# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
# ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# Copyright (C) 1998-1999.  Microsoft Corporation.  All rights reserved.
#

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

proj=superusr

all: $(proj).exe

.c.obj:
    $(cc) $(cflags) $(cvars) $(cdebug) $<

$(proj).exe: $(proj).obj
    $(link) $(ldebug) $(conlflags) $(proj).obj \
    -out:$(proj).exe \
    $(conlibs) advapi32.lib
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
