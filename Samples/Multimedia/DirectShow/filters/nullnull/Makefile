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

all:	$(OUTDIR) $(OUTDIR)\nullnull.ax 

$(OUTDIR)\nullnull.ax:	$(OUTDIR)\nullnull.obj $(OUTDIR)\nullnull.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\nullnull.ax $(dlllflags) /DLL /PDB:$(OUTDIR)\none /DEF:.\nullnull.def /IMPLIB:"$(OUTDIR)\nullnull.lib" $(guilflags) /MACHINE:$(CPU) $(OUTDIR)\nullnull.obj $(OUTDIR)\nullnull.res $(STRMBASE) msvcrtd.lib quartz.lib vfw32.lib winmm.lib $(baselibs) version.lib largeint.lib user32.lib gdi32.lib comctl32.lib ole32.lib olepro32.lib oleaut32.lib uuid.lib /NODEFAULTLIB

$(OUTDIR)\nullnull.obj:	nullnull.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses nullnull.cpp

$(OUTDIR)\nullnull.res:	
	 $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\NULLNULL.res NULLNULL.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
