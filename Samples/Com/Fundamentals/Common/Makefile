!include <disable.mak>

#+---------------------------------------------------------------------------
#
#  Microsoft Windows
#  Copyright 1994 - 1998 Microsoft Corporation.
#
#  File:        makefile
#
#----------------------------------------------------------------------------

!include <$(MSTOOLS)\samples\com\fundamentals\include\olesampl.mak>

#
#       builds the sdkutil.LIB library
#

OLEFLAGS =

all: sdkutil.lib

clean:
    -del *.lib
    -del *.obj

stablize.obj: stablize.cxx
    $(cc) $(cvars) $(cflags) $(UFLAGS) $(cdebug) $(OLEFLAGS) stablize.cxx

altassrt.obj: altassrt.cxx
    $(cc) $(cvars) $(cflags) $(UFLAGS) $(cdebug) $(OLEFLAGS) altassrt.cxx

sdkutil.lib: altassrt.obj stablize.obj
    lib -out:sdkutil.lib altassrt.obj stablize.obj
    if not exist ..\lib mkdir ..\lib
    copy sdkutil.lib ..\lib
