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

all:	$(OUTDIR) $(OUTDIR)\scope.ax 

$(OUTDIR)\scope.ax:	$(OUTDIR)\scope.obj $(OUTDIR)\scope.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\scope.ax $(dlllflags) /DLL /PDB:$(OUTDIR)\scope.pdb /DEF:.\scope.def /IMPLIB:"$(OUTDIR)\scope.lib" $(guilflags) /MACHINE:$(CPU) $(OUTDIR)\scope.obj $(OUTDIR)\scope.res $(STRMBASE) quartz.lib vfw32.lib winmm.lib $(baselibs) version.lib largeint.lib user32.lib gdi32.lib comctl32.lib ole32.lib olepro32.lib oleaut32.lib uuid.lib msvcrt.lib /NODEFAULTLIB

$(OUTDIR)\scope.obj:	scope.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses scope.cpp

$(OUTDIR)\scope.res:	
	 $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\scope.res scope.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
