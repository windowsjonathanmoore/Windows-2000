!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\switchscreenmode.exe 

$(OUTDIR)\switchscreenmode.exe:	 $(OUTDIR)\SwitchScreenMode.obj $(OUTDIR)\ddutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\SwitchScreenMode.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\switchscreenmode.exe $(guilflags) /PDB:$(OUTDIR)\switchscreenmode.pdb /MACHINE:$(CPU) $(OUTDIR)\SwitchScreenMode.obj $(OUTDIR)\ddutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\SwitchScreenMode.res winmm.lib dxguid.lib dxerr8.lib ddraw.lib shell32.lib $(ole2libs) 

$(OUTDIR)\SwitchScreenMode.obj:	SwitchScreenMode.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\switchscreenmode.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include SwitchScreenMode.cpp

$(OUTDIR)\ddutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\ddutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\switchscreenmode.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\ddutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\switchscreenmode.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\SwitchScreenMode.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\switchscreenmode.res switchscreenmode.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
