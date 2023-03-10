!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\bgmusic.exe 

$(OUTDIR)\bgmusic.exe:	$(OUTDIR)\bgmusic.obj $(OUTDIR)\bgmusic.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\bgmusic.exe $(guilflags) /PDB:$(OUTDIR)\bgmusic.pdb /MACHINE:$(CPU) $(OUTDIR)\bgmusic.obj $(OUTDIR)\bgmusic.res shell32.lib $(ole2libs) strmiids.lib 

$(OUTDIR)\bgmusic.obj:	bgmusic.CPP
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\BaseClasses bgmusic.CPP

$(OUTDIR)\bgmusic.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\bgmusic.res bgmusic.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
