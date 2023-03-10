!include <disable.mak>

!if ("$(TARGETOS)" == "WINNT") && ("$(APPVER)" == "5.01")
##########################################################################
#
# Makefile for MSPBaseSample.LIB
#
# Usage:    NMAKE           (builds DEBUG library)
#    or:    NMAKE RELEASE=1 (builds RELEASE library -- no debug symbols)
#
##########################################################################

!include <win32.mak>

!IF "$(TARGETLANG)" == "LANG_JAPANESE"
LANG=JPN
!ELSE
LANG=USA
!ENDIF

!ifndef LIBRARY
LIBRARY=MSPBaseSample
!endif

all: $(OUTDIR) $(OUTDIR)\$(LIBRARY).lib

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ----------------------------------------------------------------------------
#                      O B J E C T   F I L E   L I S T
# ----------------------------------------------------------------------------

MSP_OBJS =  $(OUTDIR)\dtevntsk.OBJ \
            $(OUTDIR)\mspaddr.OBJ  \
            $(OUTDIR)\mspcall.OBJ  \
            $(OUTDIR)\msplog.OBJ   \
            $(OUTDIR)\mspstrm.OBJ  \
            $(OUTDIR)\mspterm.OBJ  \
            $(OUTDIR)\mspthrd.OBJ  \
            $(OUTDIR)\msptrmac.OBJ \
            $(OUTDIR)\msptrmar.OBJ \
            $(OUTDIR)\msptrmvc.OBJ \
            $(OUTDIR)\msputils.OBJ


# ----------------------------------------------------------------------------
#                 D E B U G   M A K E   P A R A M E T E R S
# ----------------------------------------------------------------------------

MSPBASE_FLAGS = /DMSPLOG /DUNICODE /GR /GX

!ifndef NODEBUG
MSPBASE_FLAGS = $(MSPBASE_FLAGS) /DDBG /D_DEBUG
!endif



.SUFFIXES: .c .asm .obj .res .rc .def .bmp .ico .exe .dll .cod .str

# ----------------------------------------------------------------------------
#                     I N F E R E N C E   R U L E S
# ----------------------------------------------------------------------------
# compile CPP file without precompiled headers into object
#

.cpp{$(OUTDIR)}.obj:
    @echo Compiling $(@B).cpp
    $(cc) $(cflags) $(cvars) $(cdebug) $(MSPBASE_FLAGS) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**


.cpp{$(OUTDIR)}.cod:
    @echo Making $(@B).cod
    $(cc) $(cflags) $(cvars) $(cdebug) $(MSPBASE_FLAGS) -f- -Fc /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

#
# Build .LIB static library
#

$(OUTDIR)\$(LIBRARY).lib: $(MSP_OBJS)
    lib -out:$*.lib -machine:$(CPU) $(MSP_OBJS)
    if not exist ..\lib\$(OUTDIR) mkdir ..\lib\$(OUTDIR)
    copy $(OUTDIR)\$(LIBRARY).LIB ..\lib\$(OUTDIR)

clean:
        $(CLEANUP)

!else
!message Sorry this sample is only supported on the NT platform version 5.01 and greater
!endif
