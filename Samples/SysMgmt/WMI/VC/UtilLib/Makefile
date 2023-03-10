!include <disable.mak>

!IF ( ( "$(TARGETOS)" == "WINNT" ) && ("$(APPVER)" != "5.0") && ("$(APPVER)" != "4.0") )
#
# MAKEFILE
# Sample WBEM Dynamic Instance Provider 
#
# Copyright (c)1998 Microsoft Corporation, All Rights Reserved
#
!include <win32.mak>

TARGET  = utillib.lib

goal:   $(TARGET)

OBJS   = $(OUTDIR)\utils.obj $(OUTDIR)\wbemsec.obj

#
# Compiler and link flags
#

!ifndef NODEBUG
LINK    = /nologo 
CFLAGS  = /nologo /W3 /GX /D "WIN32" /D "_WINDOWS" /c /MTd /Z7 /Od /D "_DEBUG" 
!else
LINK    = /nologo 
CFLAGS  = /nologo /W3 /GX /D "WIN32" /D "_WINDOWS" /c /MT /O2 /D "NDEBUG" 
!endif #NODEBUG

cc = cl $(CFLAGS)

.cpp{$(OUTDIR)}.obj:
    if not exist $(OUTDIR) md $(OUTDIR)
    $(cc) $< -Fo$(OUTDIR)\$(<B).obj

$(TARGET) : $(OBJS)
    link -lib @<<    
    $(LINK)
    -out:$(OUTDIR)\$(TARGET)
    -subsystem:windows,4.0
    $(OBJS)
<<

##### Dependencies #####

utils.obj   : utils.cpp   utillib.h
wbemsec.obj  : wbemsec.cpp  wbemsec.h

clean:
        $(CLEANUP)
!ELSE
!MESSAGE Sorry This sample only builds for the Pre32 and Pre64 platforms
!ENDIF
