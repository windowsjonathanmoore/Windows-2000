!include <disable.mak>
#---------------------------------------------------------------------
#
# Copyright (c) 1997-1999 Microsoft Corporation.
#
# PingWBEM.exe
#
#---------------------------------------------------------------------

!if "$(CPU)"=="IA64"

!MESSAGE This sample is not yet supported for IA64 environment

!else

TARGET  = PingWBEM
OUTFILE = PingWBEM.exe

#
#obj list.
#

OUTDIR=.\Debug   # where to put the exe.
INTDIR=.\Debug   # where to put the objs.

CFLAGS = /nologo /MLd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_CONSOLE"\
 /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /c 

LINK = \
    -nodefaultlib -subsystem:console /nologo\
    -map:$(INTDIR)\mb.map -debug -debugtype:cv \
    -out:$(INTDIR)\$(OUTFILE) \

LIBS = shell32.lib \
    user32.lib \
    libcmt.lib \
    kernel32.lib \
    gdi32.lib \
    advapi32.lib \
    oldnames.lib \
    oleaut32.lib \
    ole32.lib \
    uuid.lib \
    mpr.lib \
    wbemuuid.lib

OBJS = \
    main.obj \

LINK_OBJS = \
    $(INTDIR)\main.obj \

.SUFFIXES: .h .obj .dll .cpp  

!ifdef CLEAN
goal:   clean
!else
goal:   $(OUTFILE)
!endif #CLEAN

clean:
    if exist *.pch del *.pch
    if exist *.obj del *.obj
    if exist *.exe del *.exe
    if exist *.dll del *.dll
    if exist *.pdb del *.pdb
    if exist *.exp del *.exp
    if exist *.lib del *.lib
    if exist *.ilk del *.ilk
    if exist *.map del *.map
    if exist *.vcp del *.vcp

.cpp.obj:
	if not exist $(INTDIR) md $(INTDIR)
    cl $(CFLAGS) $*.cpp

$(OUTFILE) : $(OBJS) $(DEFFILE)
    link @<<    
    $(LINK)
    $(LINK_OBJS)
    $(LIBS) 
<<


##### Dependencies #####

main.obj : main.cpp

!endif #CPU
