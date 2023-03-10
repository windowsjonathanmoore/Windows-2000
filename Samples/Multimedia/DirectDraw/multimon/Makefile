!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\multimon.exe 

$(OUTDIR)\multimon.exe:	 $(OUTDIR)\multimon.obj $(OUTDIR)\multimon.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\multimon.exe $(guilflags) /PDB:$(OUTDIR)\multimon.pdb /MACHINE:$(CPU) $(OUTDIR)\multimon.obj $(OUTDIR)\multimon.res dxguid.lib odbc32.lib odbccp32.lib dxerr8.lib ddraw.lib shell32.lib $(ole2libs) 

$(OUTDIR)\multimon.obj:	multimon.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /FR /Fp$(OUTDIR)\multimon.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include multimon.cpp

$(OUTDIR)\multimon.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\MultiMon.res MultiMon.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
