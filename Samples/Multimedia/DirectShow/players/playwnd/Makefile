!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\PlayWnd.exe 

$(OUTDIR)\PlayWnd.exe:	$(OUTDIR)\playwnd.obj $(OUTDIR)\playwnd.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\PlayWnd.exe $(guilflags) /NODEFAULTLIB:msvcrt.lib /PDB:$(OUTDIR)\PlayWnd.pdb /MACHINE:$(CPU) $(OUTDIR)\playwnd.obj $(OUTDIR)\playwnd.res quartz.lib msvcrtd.lib winmm.lib msacm32.lib olepro32.lib strmiids.lib $(baselibs) user32.lib gdi32.lib comdlg32.lib ole32.lib oleaut32.lib uuid.lib 

$(OUTDIR)\playwnd.obj:	playwnd.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Fp$(OUTDIR)\PlayWnd.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\BaseClasses playwnd.cpp

$(OUTDIR)\playwnd.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\playwnd.res playwnd.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
