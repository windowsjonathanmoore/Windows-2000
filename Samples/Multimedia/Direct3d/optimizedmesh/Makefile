!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\optimizedmesh.exe 

$(OUTDIR)\optimizedmesh.exe:	 $(OUTDIR) $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\OptimizedMesh.obj $(OUTDIR)\WinMain.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\optimizedmesh.exe $(guilflags) /INCREMENTAL:yes /PDB:$(OUTDIR)\optimizedmesh.pdb /MACHINE:$(CPU) $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\OptimizedMesh.obj $(OUTDIR)\WinMain.res d3dx8dt.lib d3d8.lib winmm.lib dxguid.lib d3dxof.lib $(winlibs) shell32.lib 

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Od /FR /Fp$(OUTDIR)\optimizedmesh.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Od /FR /Fp$(OUTDIR)\optimizedmesh.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Od /FR /Fp$(OUTDIR)\optimizedmesh.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Od /FR /Fp$(OUTDIR)\optimizedmesh.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\OptimizedMesh.obj:	OptimizedMesh.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Od /FR /Fp$(OUTDIR)\optimizedmesh.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include OptimizedMesh.cpp

$(OUTDIR)\WinMain.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\winmain.res winmain.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
