!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\keyboard.exe 

$(OUTDIR)\keyboard.exe:	 $(OUTDIR)\keyboard.obj $(OUTDIR)\keyboard.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\keyboard.exe $(guilflags) /PDB:$(OUTDIR)\keyboard.pdb /MACHINE:$(CPU) $(OUTDIR)\keyboard.obj $(OUTDIR)\keyboard.res dxguid.lib dxerr8.lib dinput8.lib $(winlibs) shell32.lib uuid.lib 

$(OUTDIR)\keyboard.obj:	keyboard.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\keyboard.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS keyboard.cpp

$(OUTDIR)\keyboard.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\keyboard.res keyboard.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
