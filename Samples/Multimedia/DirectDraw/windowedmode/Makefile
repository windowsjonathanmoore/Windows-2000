!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\windowedmode.exe 

$(OUTDIR)\windowedmode.exe:	 $(OUTDIR)\WindowedMode.obj $(OUTDIR)\ddutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\WindowedMode.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\windowedmode.exe $(guilflags) /PDB:$(OUTDIR)\windowedmode.pdb /MACHINE:$(CPU) $(OUTDIR)\WindowedMode.obj $(OUTDIR)\ddutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\WindowedMode.res winmm.lib dxguid.lib dxerr8.lib ddraw.lib shell32.lib $(ole2libs) 

$(OUTDIR)\WindowedMode.obj:	WindowedMode.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\windowedmode.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include WindowedMode.cpp

$(OUTDIR)\ddutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\ddutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\windowedmode.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\ddutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\windowedmode.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\WindowedMode.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\windowedmode.res windowedmode.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
