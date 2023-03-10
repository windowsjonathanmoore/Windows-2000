!include <disable.mak>
!include <win32.mak>
# **************************************************************************
# Copyright (c) 1998 Microsoft Corporation.
#
# File:  makefile.
#
# Description:
#    WMIDiskPerf
#
# History:
#
# **************************************************************************

TARGET  = WMIDiskPerf
OUTFILE = WMIDiskPerf.exe

!ifndef NODEBUG

LINK = oleaut32.lib ole32.lib msvcrtd.lib /nologo /NOD /subsystem:console\
 /incremental:yes /pdb:"$(OUTDIR)\WMIDiskPerf.pdb" /debug /machine:$(CPU)\
 /out:"$(OUTDIR)\WMIDiskPerf.exe"

CFLAGS  = /nologo -I..\..\..\include /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WIN32_DCOM" /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /c

!else

LINK = oleaut32.lib ole32.lib msvcrt.lib /nologo /NOD /subsystem:console\
 /incremental:no /pdb:"$(OUTDIR)\WMIDiskPerf.pdb" /machine:$(CPU)\
 /out:"$(OUTDIR)\WMIDiskPerf.exe" 

CFLAGS = /nologo -I..\..\..\include /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" \
 /D "_WIN32_DCOM" /Fp"$(OUTDIR)\WMIDiskPerf.pch" /YX\ /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /c /Zl

!endif #NODEBUG


#
#obj list.
#

OBJS = WMIDiskPerf.obj \
	dpdetail.obj \

LINK_OBJS = $(OUTDIR)\WMIDiskPerf.obj \
	$(OUTDIR)\dpdetail.obj \

LIBS = kernel32.lib user32.lib \
 advapi32.lib uuid.lib wbemuuid.lib

.SUFFIXES: .h .obj .dll .cpp  

!ifdef CLEAN
goal:   clean
!else
goal:   $(OUTFILE)
!endif #CLEAN

.cpp.obj:
	if not exist $(OUTDIR) md $(OUTDIR)
    cl $(CFLAGS) $*.cpp

$(OUTFILE) : $(OBJS) $(DEFFILE)
    link @<<    
    $(LINK)
    $(LINK_OBJS)
    $(LIBS) 
<<

##### Dependencies #####

WMIDiskPerf.obj : WMIDiskPerf.cpp
dpdetail.obj : dpdetail.cpp

clean:
        $(CLEANUP)
