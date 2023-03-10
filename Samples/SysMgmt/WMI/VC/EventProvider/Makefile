!include <disable.mak>
# **************************************************************************
#
# Copyright (c) 1997-1999 Microsoft Corporation.
#
# File:  MAKEFILE
#
# Description: makefile for building the event provider sample
#
# History:
#
# **************************************************************************

target = evprov.dll

!ifndef NODEBUG
objdir=debug
!else
objdir=release
!endif

objlist = \
    $(objdir)\olesrvr.obj \
    $(objdir)\evprov.obj \
    
all: $(objdir)\$(target)


#---------------------------------------------------------------------


!if "$(CPU)"=="i386"
cc =  \
    cl -c -Od -D_MT -D_CONSOLE -DWIN32 -D_WIN32_DCOM -Z7 -GX \
   -W3 -Di386=1 -D_X86_=1 -I.

link = \
    link -nodefaultlib -dll -subsystem:console \
    -entry:_DllMainCRTStartup@12 -map:$(objdir)\mb.map -debug -debugtype:cv \
    -out:$(objdir)\$(target) \
    -def:evprov.def \
	$(objlist) \
    wbemuuid.lib \
    libcmt.lib \
    kernel32.lib \
    advapi32.lib \
    uuid.lib \
    ole32.lib \
    oleaut32.lib 

!else
cc =  \
    cl -c -Od -D_MT -D_CONSOLE -DWIN32 -D_WIN32_DCOM -Z7 -GX \
   -W3 -I.

link = \
    link -nodefaultlib -dll -subsystem:console \
    -entry:_DllMainCRTStartup -map:$(objdir)\mb.map -debug -debugtype:cv \
    -out:$(objdir)\$(target) \
    -def:evprov.def \
	$(objlist) \
    wbemuuid.lib \
    libcmt.lib \
    kernel32.lib \
    advapi32.lib \
    uuid.lib \
    ole32.lib \
    oleaut32.lib 

!endif

$(objdir)\$(target): $(objlist) 
   $(link) 

{.}.cpp{$(objdir)}.obj:
    if not exist $(objdir) md $(objdir)
    $(cc) $< -Fo$(objdir)\$(<B).obj

