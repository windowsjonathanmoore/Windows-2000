!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\dmboids.exe 

$(OUTDIR)\dmboids.exe:	$(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\boids.obj $(OUTDIR)\flock.obj $(OUTDIR)\music.obj $(OUTDIR)\dmboids.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\dmboids.exe $(guilflags) /PDB:$(OUTDIR)\dmboids.pdb /MACHINE:$(CPU) $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\boids.obj $(OUTDIR)\flock.obj $(OUTDIR)\music.obj $(OUTDIR)\dmboids.res d3dx8dt.lib d3d8.lib d3dxof.lib dinput.lib dxguid.lib dxerr8.lib $(ole2libs) winmm.lib shell32.lib 

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"

$(OUTDIR)\d3dfile.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"

$(OUTDIR)\dmutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\boids.obj:	boids.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include boids.cpp

$(OUTDIR)\flock.obj:	flock.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include flock.cpp

$(OUTDIR)\music.obj:	music.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include music.cpp

$(OUTDIR)\dmboids.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\dmboids.res dmboids.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
