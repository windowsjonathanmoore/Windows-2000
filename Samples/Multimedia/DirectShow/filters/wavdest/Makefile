!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

!ifdef NODEBUG
STRMBASE = strmbase.lib
!else
STRMBASE = strmbasd.lib
cflags=$(cflags) /DDEBUG
!endif

STRMBASE="$(MSSDK)\samples\multimedia\directshow\baseclasses\$(OUTDIR)\$(STRMBASE)"

all:	$(OUTDIR) $(OUTDIR)\wavdest.ax 

$(OUTDIR)\wavdest.ax:	$(OUTDIR)\wavdest.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\wavdest.ax $(dlllflags) /DLL /PDB:$(OUTDIR)\wavdest.pdb /DEF:.\wavdest.def /IMPLIB:"$(OUTDIR)\wavdest.lib" $(guilflags) /MACHINE:$(CPU) $(OUTDIR)\wavdest.obj $(STRMBASE) msvcrt.lib quartz.lib vfw32.lib winmm.lib $(baselibs) version.lib largeint.lib user32.lib gdi32.lib comctl32.lib ole32.lib olepro32.lib oleaut32.lib uuid.lib /NODEFAULTLIB

$(OUTDIR)\wavdest.obj:	wavdest.cpp
	$(cc) $(cflags) $(cdebug) /Gz $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses wavdest.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
