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


all:	$(OUTDIR) $(OUTDIR)\ezrgb24.ax 

$(OUTDIR)\ezrgb24.ax:	$(OUTDIR)\ezprop.obj $(OUTDIR)\ezrgb24.obj $(OUTDIR)\ezprop.res  
	$(link) $(ldebug) /OUT:$(OUTDIR)\ezrgb24.ax $(dlllflags) /DLL /PDB:$(OUTDIR)\ezrgb24.pdb /DEF:.\ezrgb24.def /IMPLIB:"$(OUTDIR)\ezrgb24.lib" $(guilflags) /MACHINE:$(CPU) $(OUTDIR)\ezprop.obj $(OUTDIR)\ezrgb24.obj $(OUTDIR)\ezprop.res $(STRMBASE) msvcrtd.lib quartz.lib vfw32.lib winmm.lib $(baselibs) version.lib largeint.lib user32.lib gdi32.lib comctl32.lib ole32.lib olepro32.lib oleaut32.lib uuid.lib /NODEFAULTLIB

$(OUTDIR)\ezprop.obj:	ezprop.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /DSTRICT /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses ezprop.cpp

$(OUTDIR)\ezrgb24.obj:	ezrgb24.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /DSTRICT /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses ezrgb24.cpp

$(OUTDIR)\ezprop.res:	
	 $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\ezprop.res ezprop.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
