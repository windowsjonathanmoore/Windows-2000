!include <disable.mak>
#
# MAKEFILE
# Sample WBEM Dynamic Instance Provider 
#
# Copyright (c)1998 Microsoft Corporation, All Rights Reserved
#

TARGET  = instprov.dll

goal:   $(TARGET)

OBJS   = $(OBJDIR)\maindll.obj $(OBJDIR)\instprov.obj $(OBJDIR)\classfac.obj $(OBJDIR)\utils.obj

LIBS = msvcrt.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib \
 advapi32.lib ole32.lib oleaut32.lib uuid.lib wbemuuid.lib

#
# Compiler and link flags
#

!ifndef NODEBUG
OBJDIR=debug
LINK    = -debug:full /DLL -debugtype:cv /NOD 
CFLAGS  = -c -Od -Z7 -Ze -W3 -nologo \
 -DWIN32 -D_DLL -DWIN32ANSI -DSTRICT -DDEBUG
!else
OBJDIR=retail
LINK    = -debug:none /DLL /NOD
CFLAGS  = -c -Oat -Ze -W3 -nologo  \
 -DWIN32 -D_DLL -DWIN32ANSI -DSTRICT
!endif #NODEBUG

cc = cl $(CFLAGS)

.cpp{$(OBJDIR)}.obj:
    if not exist $(OBJDIR) md $(OBJDIR)
    $(cc) $< -Fo$(OBJDIR)\$(<B).obj

$(TARGET) : $(OBJS) $(DEFFILE)
    link @<<    
    $(LINK)
    -entry:LibMain32
    -def:instprov.def
    -out:$(OBJDIR)\$(TARGET)
    -subsystem:windows,4.0
    $(OBJS)
    $(LIBS) 
<<

##### Dependencies #####

maindll.obj   : maindll.cpp   sample.h
classfac.obj  : classfac.cpp  sample.h
instprov.obj   : instprov.cpp   sample.h
utils.obj   : utils.cpp   sample.h
