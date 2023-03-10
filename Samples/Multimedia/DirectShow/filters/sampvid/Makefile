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

all:	$(OUTDIR) $(OUTDIR)\sampvid.ax 

$(OUTDIR)\sampvid.ax:	$(OUTDIR)\sampvid.obj $(OUTDIR)\videotxt.obj $(OUTDIR)\vidprop.obj $(OUTDIR)\sampvid.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\sampvid.ax $(dlllflags) /DLL /PDB:$(OUTDIR)\sampvid.pdb /DEF:.\sampvid.def /IMPLIB:"$(OUTDIR)\sampvid.lib" /MACHINE:$(CPU) $(OUTDIR)\sampvid.obj $(OUTDIR)\videotxt.obj $(OUTDIR)\vidprop.obj $(OUTDIR)\sampvid.res $(STRMBASE) quartz.lib winmm.lib msvcrt.lib $(baselibs) user32.lib gdi32.lib comdlg32.lib ole32.lib oleaut32.lib uuid.lib /NODEFAULTLIB

$(OUTDIR)\sampvid.obj:	sampvid.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses sampvid.cpp

$(OUTDIR)\videotxt.obj:	videotxt.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses videotxt.cpp

$(OUTDIR)\vidprop.obj:	vidprop.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\BaseClasses vidprop.cpp

$(OUTDIR)\sampvid.res:	
	 $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\sampvid.res sampvid.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
