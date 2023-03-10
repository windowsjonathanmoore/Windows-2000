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


all:	$(OUTDIR) $(OUTDIR)\ball.ax 

$(OUTDIR)\ball.ax:	$(OUTDIR)\ball.obj $(OUTDIR)\fball.obj $(OUTDIR)\ball.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\ball.ax $(dlllflags) /DLL /DEF:.\ball.def /IMPLIB:"$(OUTDIR)\ball.lib" /MACHINE:$(CPU) $(OUTDIR)\ball.obj $(OUTDIR)\fball.obj $(OUTDIR)\ball.res $(STRMBASE) quartz.lib vfw32.lib winmm.lib $(baselibs) version.lib largeint.lib user32.lib gdi32.lib comctl32.lib ole32.lib olepro32.lib oleaut32.lib uuid.lib /NODEFAULTLIB:libcmt.lib

$(OUTDIR)\ball.obj:	ball.cpp
	$(cc) $(cflags) $(cdebug) /Gz $(cvarsdll) /Gy /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /DSTRICT /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses ball.cpp

$(OUTDIR)\fball.obj:	fball.cpp
	$(cc) $(cflags) $(cdebug) /Gz $(cvarsdll) /Gy /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /DSTRICT /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses fball.cpp

$(OUTDIR)\ball.res:	
	 $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\ball.res ball.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
