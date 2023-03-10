!include <disable.mak>

##############################################################################
#   MODULE: BLRPLATE.dll
#
#   Modification History
#
#   Your Name Here      01/01/70    Created
##############################################################################

!IF "$(TARGETOS)" == "WINNT"
!include <win32.mak>
#if "$(CPU)" == "i386"
CVTRESCPU=IX86
#else
CVTRESCPU=$(CPU)
#endif

MODULE = BLRPLATE

all: $(MODULE).dll

BLRPLATE_LIBS   = $(winlibs) msvcrt.lib nmapi.lib npptools.lib dprintf.lib
BLRPLATE_LFLAGS = $(lflags) $(ldebug) -debug:full -debugtype:both -machine:$(CPU)  -dll 


##############################################################################
#   Object list
##############################################################################

OBJS = BLRPLATE.obj  \
       config.obj    \
       $(MODULE).rbj \


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

$(MODULE).res: $*.rc resrc1.h
    rc -r $*.rc

$(MODULE).rbj: $*.res
    cvtres -$(CVTRESCPU) $*.res -o $*.rbj


##############################################################################
#   Update the object files if necessary
##############################################################################

BLRPLATE.obj  : BLRPLATE.h BLRPLATE.cpp

config.obj    : BLRPLATE.h config.cpp


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
