!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>


all:	$(OUTDIR) $(OUTDIR)\gammacontrol.exe 

$(OUTDIR)\gammacontrol.exe:	 $(OUTDIR)\GammaControl.obj $(OUTDIR)\ddutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\GammaControl.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\gammacontrol.exe $(guilflags) /PDB:$(OUTDIR)\gammacontrol.pdb /MACHINE:$(CPU) $(OUTDIR)\GammaControl.obj $(OUTDIR)\ddutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\GammaControl.res winmm.lib dxguid.lib dxerr8.lib ddraw.lib shell32.lib $(ole2libs) 

$(OUTDIR)\GammaControl.obj:	GammaControl.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\gammacontrol.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include GammaControl.cpp

$(OUTDIR)\ddutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\ddutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\gammacontrol.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\ddutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\gammacontrol.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\GammaControl.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\GammaControl.res GammaControl.rc
        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
