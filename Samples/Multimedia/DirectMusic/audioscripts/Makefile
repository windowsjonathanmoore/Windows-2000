!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\AudioScripts.exe 

$(OUTDIR)\AudioScripts.exe:	 $(OUTDIR)\AudioScripts.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AudioScripts.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\AudioScripts.exe $(guilflags) /PDB:$(OUTDIR)\AudioScripts.pdb /MACHINE:$(CPU) $(OUTDIR)\AudioScripts.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AudioScripts.res dxerr8.lib winmm.lib dxguid.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\AudioScripts.obj:	AudioScripts.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\AudioScripts.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include AudioScripts.cpp

$(OUTDIR)\dmutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\AudioScripts.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\AudioScripts.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\AudioScripts.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\audioscripts.res audioscripts.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
