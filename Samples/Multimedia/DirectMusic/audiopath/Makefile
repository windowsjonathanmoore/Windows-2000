!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\audiopath.exe 

$(OUTDIR)\audiopath.exe:	 $(OUTDIR)\AudioPath.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AudioPath.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\audiopath.exe $(guilflags) /PDB:$(OUTDIR)\audiopath.pdb /MACHINE:$(CPU) $(OUTDIR)\AudioPath.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AudioPath.res comctl32.lib dxerr8.lib winmm.lib dxguid.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\AudioPath.obj:	AudioPath.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\audiopath.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include AudioPath.cpp

$(OUTDIR)\dmutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\audiopath.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\audiopath.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\AudioPath.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\audiopath.res audiopath.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
