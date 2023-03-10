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

all:	$(OUTDIR) $(OUTDIR)\nullip.ax 

$(OUTDIR)\nullip.ax:	$(OUTDIR)\nullip.obj $(OUTDIR)\nullprop.obj $(OUTDIR)\texttype.obj $(OUTDIR)\nullprop.res  
	$(link) $(ldebug) /OUT:$(OUTDIR)\nullip.ax $(dlllflags) /DLL /PDB:$(OUTDIR)\none /DEF:.\nullip.def /IMPLIB:"$(OUTDIR)\nullip.lib" $(guilflags) /MACHINE:$(CPU) $(OUTDIR)\nullip.obj $(OUTDIR)\nullprop.obj $(OUTDIR)\texttype.obj $(OUTDIR)\nullprop.res $(STRMBASE) msvcrtd.lib quartz.lib vfw32.lib winmm.lib $(baselibs) version.lib largeint.lib user32.lib gdi32.lib comctl32.lib ole32.lib olepro32.lib oleaut32.lib uuid.lib /NODEFAULTLIB

$(OUTDIR)\nullip.obj:	nullip.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses nullip.cpp

$(OUTDIR)\nullprop.obj:	nullprop.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses nullprop.cpp

$(OUTDIR)\texttype.obj:	texttype.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses texttype.cpp

$(OUTDIR)\nullprop.res:	
	 $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\nullprop.res nullprop.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
