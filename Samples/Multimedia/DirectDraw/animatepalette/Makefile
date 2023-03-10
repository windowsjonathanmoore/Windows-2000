!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\animatepalette.exe 

$(OUTDIR)\animatepalette.exe:	 $(OUTDIR)\AnimatePalette.obj $(OUTDIR)\ddutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AnimatePalette.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\animatepalette.exe $(guilflags) /PDB:$(OUTDIR)\animatepalette.pdb /MACHINE:$(CPU) $(OUTDIR)\AnimatePalette.obj $(OUTDIR)\ddutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AnimatePalette.res winmm.lib dxguid.lib dxerr8.lib ddraw.lib shell32.lib $(ole2libs) 

$(OUTDIR)\AnimatePalette.obj:	AnimatePalette.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\animatepalette.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include AnimatePalette.cpp

$(OUTDIR)\ddutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\ddutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\animatepalette.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\ddutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\animatepalette.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\AnimatePalette.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\animatepalette.res animatepalette.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
