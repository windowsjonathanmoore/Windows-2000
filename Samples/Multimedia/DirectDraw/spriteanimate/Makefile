!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\spriteanimate.exe 

$(OUTDIR)\spriteanimate.exe:	 $(OUTDIR)\spriteanimate.obj $(OUTDIR)\ddutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\spriteanimate.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\spriteanimate.exe $(guilflags) /PDB:$(OUTDIR)\spriteanimate.pdb /MACHINE:$(CPU) $(OUTDIR)\spriteanimate.obj $(OUTDIR)\ddutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\spriteanimate.res winmm.lib dxguid.lib dxerr8.lib ddraw.lib shell32.lib $(ole2libs) 

$(OUTDIR)\spriteanimate.obj:	spriteanimate.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Od /Fp$(OUTDIR)\spriteanimate.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include spriteanimate.cpp

$(OUTDIR)\ddutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\ddutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Od /Fp$(OUTDIR)\spriteanimate.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\ddutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Od /Fp$(OUTDIR)\spriteanimate.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\spriteanimate.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\spriteanimate.res spriteanimate.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
