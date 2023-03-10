!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\refreshrate.exe 

$(OUTDIR)\refreshrate.exe:	 $(OUTDIR)\RefreshRate.obj $(OUTDIR)\RefreshRate.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\refreshrate.exe $(guilflags) /PDB:$(OUTDIR)\refreshrate.pdb /MACHINE:$(CPU) $(OUTDIR)\RefreshRate.obj $(OUTDIR)\RefreshRate.res odbc32.lib odbccp32.lib comctl32.lib dxerr8.lib ddraw.lib shell32.lib $(ole2libs) 

$(OUTDIR)\RefreshRate.obj:	RefreshRate.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\refreshrate.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include RefreshRate.cpp

$(OUTDIR)\RefreshRate.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\RefreshRate.res RefreshRate.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
