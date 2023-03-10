!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\duelvoice.exe 

$(OUTDIR)\duelvoice.exe:	$(OUTDIR)\ddutil.obj $(OUTDIR)\diutil.obj $(OUTDIR)\dpconnect.obj $(OUTDIR)\dputil.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\duel.obj $(OUTDIR)\gameproc.obj $(OUTDIR)\gfx.obj $(OUTDIR)\lobby.obj $(OUTDIR)\util.obj $(OUTDIR)\duelvoice.res
	$(link) $(ldebug) /OUT:$(OUTDIR)\duelvoice.exe $(guilflags) /PDB:$(OUTDIR)\duelvoice.pdb /MACHINE:$(CPU) $(OUTDIR)\ddutil.obj $(OUTDIR)\diutil.obj $(OUTDIR)\dpconnect.obj $(OUTDIR)\dputil.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\duel.obj $(OUTDIR)\gameproc.obj $(OUTDIR)\gfx.obj $(OUTDIR)\lobby.obj $(OUTDIR)\util.obj $(OUTDIR)\duelvoice.res uuid.lib comctl32.lib ddraw.lib dinput.lib dsound.lib dplayx.lib dxguid.lib dxerr8.lib ole32.lib winmm.lib $(baselibs) user32.lib gdi32.lib comdlg32.lib shell32.lib 

$(OUTDIR)\ddutil.obj:	ddutil.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duelvoice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include ddutil.cpp

$(OUTDIR)\diutil.obj:	diutil.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duelvoice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include diutil.cpp

$(OUTDIR)\dpconnect.obj:	dpconnect.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duelvoice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include dpconnect.cpp

$(OUTDIR)\dputil.obj:	dputil.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duelvoice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include dputil.cpp

$(OUTDIR)\dsutil.obj:	dsutil.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duelvoice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include dsutil.cpp

$(OUTDIR)\duel.obj:	duel.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duelvoice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include duel.cpp

$(OUTDIR)\gameproc.obj:	gameproc.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duelvoice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include gameproc.cpp

$(OUTDIR)\gfx.obj:	gfx.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duelvoice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include gfx.cpp

$(OUTDIR)\lobby.obj:	lobby.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duelvoice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include lobby.cpp

$(OUTDIR)\util.obj:	util.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\duelvoice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include util.cpp

$(OUTDIR)\duelvoice.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\duelvoice.res duelvoice.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
