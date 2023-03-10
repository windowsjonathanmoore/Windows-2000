!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\duel.exe 

$(OUTDIR)\duel.exe:	$(OUTDIR)\ddutil.obj $(OUTDIR)\diutil.obj $(OUTDIR)\dpconnect.obj $(OUTDIR)\dputil.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\duel.obj $(OUTDIR)\gameproc.obj $(OUTDIR)\gfx.obj $(OUTDIR)\lobby.obj $(OUTDIR)\util.obj $(OUTDIR)\duel.res
	$(link) $(ldebug) /OUT:$(OUTDIR)\duel.exe $(guilflags) /PDB:$(OUTDIR)\duel.pdb /MACHINE:$(CPU) $(OUTDIR)\ddutil.obj $(OUTDIR)\diutil.obj $(OUTDIR)\dpconnect.obj $(OUTDIR)\dputil.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\duel.obj $(OUTDIR)\gameproc.obj $(OUTDIR)\gfx.obj $(OUTDIR)\lobby.obj $(OUTDIR)\util.obj $(OUTDIR)\duel.res uuid.lib comctl32.lib dplayx.lib ddraw.lib dinput.lib dsound.lib dxguid.lib dxerr8.lib ole32.lib winmm.lib $(baselibs) user32.lib gdi32.lib comdlg32.lib shell32.lib 

$(OUTDIR)\ddutil.obj:	ddutil.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duel.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" ddutil.cpp

$(OUTDIR)\diutil.obj:	diutil.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duel.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" diutil.cpp

$(OUTDIR)\dpconnect.obj:	dpconnect.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duel.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" dpconnect.cpp

$(OUTDIR)\dputil.obj:	dputil.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duel.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" dputil.cpp

$(OUTDIR)\dsutil.obj:	dsutil.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duel.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" dsutil.cpp

$(OUTDIR)\duel.obj:	duel.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duel.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" duel.cpp

$(OUTDIR)\gameproc.obj:	gameproc.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duel.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" gameproc.cpp

$(OUTDIR)\gfx.obj:	gfx.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duel.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" gfx.cpp

$(OUTDIR)\lobby.obj:	lobby.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duel.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" lobby.cpp

$(OUTDIR)\util.obj:	util.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duel.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" util.cpp

$(OUTDIR)\duel.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\duel.res duel.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
