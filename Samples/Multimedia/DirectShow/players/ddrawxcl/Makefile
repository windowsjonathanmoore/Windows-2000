!include <disable.mak>

!ifdef NODEBUG
STRMBASE = strmbase.lib
!else
STRMBASE = strmbasd.lib
!endif

STRMBASE="$(MSSDK)\samples\multimedia\directshow\baseclasses\$(OUTDIR)\$(STRMBASE)"


#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>


all:	$(OUTDIR) $(OUTDIR)\ddrawxcl.exe 

$(OUTDIR)\ddrawxcl.exe:	$(OUTDIR)\ddrawobj.obj $(OUTDIR)\ddrawxcl.obj $(OUTDIR)\vidplay.obj $(OUTDIR)\ddrawxcl.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\ddrawxcl.exe $(guilflags) /MACHINE:$(CPU) /NODEFAULTLIB $(OUTDIR)\ddrawobj.obj $(OUTDIR)\ddrawxcl.obj $(OUTDIR)\vidplay.obj $(OUTDIR)\ddrawxcl.res $(STRMBASE) quartz.lib $(baselibs) user32.lib comdlg32.lib ole32.lib oleaut32.lib gdi32.lib ddraw.lib msvcrtd.lib uuid.lib winmm.lib 

$(OUTDIR)\ddrawobj.obj:	ddrawobj.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\BaseClasses ddrawobj.cpp

$(OUTDIR)\ddrawxcl.obj:	ddrawxcl.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\BaseClasses ddrawxcl.cpp

$(OUTDIR)\vidplay.obj:	vidplay.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\BaseClasses vidplay.cpp

$(OUTDIR)\ddrawxcl.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\ddrawxcl.res ddrawxcl.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
