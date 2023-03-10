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

all:	$(OUTDIR) $(OUTDIR)\bdasample.exe 

$(OUTDIR)\bdasample.exe:	 $(OUTDIR) $(OUTDIR)\bdasampl.obj $(OUTDIR)\graph.obj $(OUTDIR)\bdasampl.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\bdasample.exe $(guilflags) /NODEFAULTLIB /PDB:$(OUTDIR)\none /MACHINE:$(CPU) $(OUTDIR)\bdasampl.obj $(OUTDIR)\graph.obj $(OUTDIR)\bdasampl.res $(STRMBASE) quartz.lib msvcrtd.lib $(baselibs) user32.lib gdi32.lib comdlg32.lib ole32.lib winmm.lib msacm32.lib olepro32.lib oleaut32.lib uuid.lib 

$(OUTDIR)\bdasampl.obj:	bdasampl.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\BaseClasses bdasampl.cpp

$(OUTDIR)\graph.obj:	graph.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\BaseClasses graph.cpp

$(OUTDIR)\bdasampl.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\bdasampl.res bdasampl.rc 

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
