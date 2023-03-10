!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\text3d.exe 

$(OUTDIR)\text3d.exe:	 $(OUTDIR) $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\text3d.obj $(OUTDIR)\winmain.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\text3d.exe $(guilflags) /PDB:$(OUTDIR)\text3d.pdb /MACHINE:$(CPU) $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\text3d.obj $(OUTDIR)\winmain.res d3dx8dt.lib d3d8.lib d3dxof.lib dxguid.lib winmm.lib $(winlibs) shell32.lib uuid.lib 

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\text3d.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\text3d.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\text3d.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\text3d.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\text3d.obj:	text3d.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\text3d.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include text3d.cpp

$(OUTDIR)\winmain.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\winmain.res winmain.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
