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

all:	$(OUTDIR) $(OUTDIR)\gargle.ax 

$(OUTDIR)\gargle.ax:	$(OUTDIR)\gargle.obj $(OUTDIR)\gargprop.obj $(OUTDIR)\gargprop.res  
	$(link) $(ldebug) /OUT:$(OUTDIR)\gargle.ax $(dlllflags) /DLL /PDB:$(OUTDIR)\gargle.pdb /DEF:.\gargle.def /IMPLIB:"$(OUTDIR)\gargle.lib" $(guilflags) /MACHINE:$(CPU) $(OUTDIR)\gargle.obj $(OUTDIR)\gargprop.obj $(OUTDIR)\gargprop.res $(STRMBASE) msvcrtd.lib quartz.lib vfw32.lib winmm.lib $(baselibs) version.lib largeint.lib user32.lib gdi32.lib comctl32.lib ole32.lib olepro32.lib oleaut32.lib uuid.lib /NODEFAULTLIB

$(OUTDIR)\gargle.obj:	gargle.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Oid /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses gargle.cpp

$(OUTDIR)\gargprop.obj:	gargprop.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Oid /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses gargprop.cpp

$(OUTDIR)\gargprop.res:	
	 $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\gargprop.res gargprop.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
