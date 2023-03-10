!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\mouse.exe 

$(OUTDIR)\mouse.exe:	 $(OUTDIR)\mouse.obj $(OUTDIR)\mouse.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\mouse.exe $(guilflags) /PDB:$(OUTDIR)\mouse.pdb /MACHINE:$(CPU) $(OUTDIR)\mouse.obj $(OUTDIR)\mouse.res dxguid.lib dxerr8.lib dinput8.lib $(winlibs) shell32.lib uuid.lib 

$(OUTDIR)\mouse.obj:	mouse.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\mouse.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS mouse.cpp

$(OUTDIR)\mouse.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\mouse.res mouse.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
