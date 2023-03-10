!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\donuts3d.exe 

$(OUTDIR)\donuts3d.exe:	$(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\diutil.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\donuts.obj $(OUTDIR)\gamemenu.obj $(OUTDIR)\donuts.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\donuts3d.exe $(guilflags) /PDB:$(OUTDIR)\donuts3d.pdb /MACHINE:$(CPU) $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\diutil.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\donuts.obj $(OUTDIR)\gamemenu.obj $(OUTDIR)\donuts.res d3dx8dt.lib d3d8.lib d3dxof.lib dxguid.lib dinput8.lib dsound.lib dxerr8.lib ole32.lib winmm.lib $(winlibs) shell32.lib 

$(OUTDIR)\d3dfile.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"

$(OUTDIR)\diutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\diutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\diutil.cpp"

$(OUTDIR)\dmutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\donuts.obj:	donuts.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include donuts.cpp

$(OUTDIR)\gamemenu.obj:	gamemenu.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include gamemenu.cpp

$(OUTDIR)\donuts.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\donuts.res donuts.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
