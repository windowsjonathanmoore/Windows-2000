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

all:	$(OUTDIR) $(OUTDIR)\textout.ax 

$(OUTDIR)\textout.ax:	$(OUTDIR)\textout.obj $(OUTDIR)\textout.res
	$(link) $(ldebug) /OUT:$(OUTDIR)\textout.ax $(dlllflags) /DLL /PDB:$(OUTDIR)\textout.pdb /DEF:.\textout.def /IMPLIB:"$(OUTDIR)\textout.lib" $(guilflags) /MACHINE:$(CPU) $(OUTDIR)\textout.obj $(OUTDIR)\textout.res $(STRMBASE) msvcrt.lib quartz.lib vfw32.lib winmm.lib $(baselibs) version.lib largeint.lib user32.lib gdi32.lib comctl32.lib ole32.lib olepro32.lib oleaut32.lib uuid.lib /NODEFAULTLIB

$(OUTDIR)\textout.obj:	textout.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gy /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses textout.cpp

$(OUTDIR)\textout.res:	
	 $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\textout.res textout.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
