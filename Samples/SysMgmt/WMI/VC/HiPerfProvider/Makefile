!include <disable.mak>
#
# MAKEFILE
# Sample WINMGMT BasicHiPerf High Performance Provider 
#
# Copyright (c)1998 Microsoft Corporation, All Rights Reserved
#

TARGET  = 	basichiperf.dll

goal:   $(TARGET)

OBJS	= 	$(OBJDIR)\BasicHiPerf.obj\
		$(OBJDIR)\Factory.obj\
		$(OBJDIR)\server.obj

LIBS 	= 	msvcrt.lib\
		kernel32.lib\
		user32.lib\
		gdi32.lib\
		comdlg32.lib\
		advapi32.lib\
		ole32.lib\
		oleaut32.lib\
		uuid.lib\
		wbemuuid.lib\

#
# Compiler and link flags
#

!ifndef NODEBUG
OBJDIR=debug
LINK    = -debug:full /DLL -debugtype:cv /NOD 
CFLAGS  = -c -MTd -Od -Z7 -Ze -W3 -nologo \
 -DWIN32 -D_DLL -DWIN32ANSI -DSTRICT -DDEBUG
!else
OBJDIR=retail
LINK    = -debug:none /DLL /NOD
CFLAGS  = -c -MT -Oat -Ze -W3 -nologo  \
 -DWIN32 -D_DLL -DWIN32ANSI -DSTRICT
!endif #NODEBUG

cc = cl $(CFLAGS)

.cpp{$(OBJDIR)}.obj:
    if not exist $(OBJDIR) md $(OBJDIR)
    $(cc) $< -Fo$(OBJDIR)\$(<B).obj

$(TARGET) : $(OBJS) $(DEFFILE)
    link @<<    
    $(LINK)
    -def:BasicHiPerf.def
    -out:$(OBJDIR)\$(TARGET)
    -subsystem:windows,5.0
    $(OBJS)
    $(LIBS) 
<<

##### Dependencies #####

BasicHiPerf.obj : BasicHiPerf.cpp BasicHiPerf.h
Factory.obj 	: Factory.cpp Factory.h
server.obj	: server.cpp
