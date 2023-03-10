!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\3DAudio.exe 

$(OUTDIR)\3DAudio.exe:	 $(OUTDIR)\3DAudio.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\3DAudio.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\3DAudio.exe $(guilflags) /PDB:$(OUTDIR)\3DAudio.pdb /MACHINE:$(CPU) $(OUTDIR)\3DAudio.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\3DAudio.res comctl32.lib dxerr8.lib winmm.lib dxguid.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\3DAudio.obj:	3DAudio.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\3DAudio.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include 3DAudio.cpp

$(OUTDIR)\dmutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\3DAudio.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\3DAudio.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\3DAudio.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\3daudio.res 3daudio.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
