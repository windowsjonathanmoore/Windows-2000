!include <disable.mak>

!IF ( ( "$(TARGETOS)" == "WINNT" ) && ("$(APPVER)" != "5.0") && ("$(APPVER)" != "4.0") )
#
# MAKEFILE
# WBEMDump make file
#
# Copyright (c)1998 Microsoft Corporation, All Rights Reserved
#

!include <win32.mak>
TARGET  = wbemdump.exe

goal:   $(TARGET)

OBJS   = $(OUTDIR)\wbemdump.obj

LIBS = uuid.lib ole32.lib oleaut32.lib wbemuuid.lib $(UTILDIR)\$(OUTDIR)\utillib.lib

UTILDIR = ..\utillib

#
# Compiler and link flags
#

!ifndef NODEBUG
LINK    = /nologo /entry:"wmainCRTStartup" /subsystem:console /debug 
CFLAGS  = /nologo -I$(UTILDIR) /DWIN32 /D_CONSOLE /c /W4 /MTd /Gm /GX /Zi /Od /D_DEBUG /Fd$(OUTDIR)\$(<B).pdb
!else
LINK    = /nologo /entry:"wmainCRTStartup" /subsystem:console /incremental:no 
CFLAGS  = /nologo -I$(UTILDIR) /DWIN32 /D_CONSOLE /c /W4 /MT /GX /O2          /DNDEBUG 
!endif #NODEBUG

cc = cl $(CFLAGS)

.cpp{$(OUTDIR)}.obj:
    if not exist $(OUTDIR) md $(OUTDIR)
    $(cc) $< -Fo$(OUTDIR)\$(<B).obj

$(UTILDIR)\$(OUTDIR)\utillib.lib:
	cd $(UTILDIR)
!ifndef NODEBUG
	nmake
!else
	nmake NODEBUG=1
!endif #NODEBUG
	cd ..\wbemdump

$(TARGET) : $(OBJS) $(DEFFILE) $(UTILDIR)\$(OUTDIR)\utillib.lib
    link @<<    
    $(LINK)
    -out:$(OUTDIR)\$(TARGET)
    $(OBJS)
    $(LIBS) 
<<

##### Dependencies #####

wbemdump.obj   : wbemdump.cpp   wbemdump.h

clean:
        $(CLEANUP)
!ELSE
!MESSAGE Sorry This sample only builds for the Pre32 and Pre64 platforms
!ENDIF
