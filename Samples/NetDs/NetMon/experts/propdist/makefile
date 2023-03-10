!include <disable.mak>

#=============================================================================
#  Microsoft (R) Network Monitor (tm). 
#  Copyright (C) 1997-1999. All rights reserved.
#
#  MODULE: makefile
#
#  This makefile builds the property distribution expert.
#=============================================================================

!IF "$(TARGETOS)" == "WINNT"
!include <win32.mak>
#if "$(CPU)" == "i386"
CVTRESCPU=IX86
#else
CVTRESCPU=$(CPU)
#endif

MODULE = PROPDIST

all: $(MODULE).dll

BLRPLATE_LIBS   = $(winlibs) msvcrt.lib nmapi.lib npptools.lib dprintf.lib
BLRPLATE_LFLAGS = $(lflags) $(ldebug) -debug:full -debugtype:both -machine:$(CPU) -dll 


##############################################################################
#   Object list
##############################################################################

OBJS = PropDist.obj  \
       PropPrint.obj \
       Tracker.obj   \
       TrackerRA.obj \
       PropConf.obj  \
       Version.rbj	\


##############################################################################
#   Inference rules.
##############################################################################

.c.obj:
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $*.c 

.cpp.obj:
    $(cc) $(cdebug) $(cflags) $(cvarsmt) -GX $*.cpp


##############################################################################
# Update the resources if necessary
##############################################################################

version.res: $*.rc
    rc -r $*.rc

version.rbj: $*.res
    cvtres -$(CVTRESCPU) $*.res -o $*.rbj


##############################################################################
#   Update the object files if necessary
##############################################################################

Propdist.obj  : propdist.h tracker.h propdist.cpp

PropPrint.obj : propdist.h tracker.h propprint.cpp

Tracker.obj   : tracker.h trackerRA.h tracker.cpp

TrackerRA.obj : trackerRA.h TrackerRA.cpp

PropConf.obj  : propdist.h PropConf.cpp Dialogs.h



##############################################################################
#   Update the dll.
##############################################################################

$(MODULE).dll: $(OBJS) $*.def
    $(link) $(BLRPLATE_LFLAGS) $(BLRPLATE_LIBS) $(OBJS) \
            -out:$*.dll -map:$*.map -def:$*.def


##############################################################################
#   Clean build
##############################################################################

clean:
    -del *.dll
    -del *.obj
    -del *.lib
    -del *.exp
    -del *.map
    -del *.sym
    -del *.pdb
    -del *.exp
    -del *.res
    -del *.rbj
    -del *.aps
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
