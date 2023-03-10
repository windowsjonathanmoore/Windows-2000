!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\fullduplexfilter.exe 

$(OUTDIR)\fullduplexfilter.exe:	 $(OUTDIR) $(OUTDIR)\fullduplexfilter.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\fullduplexfilter.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\fullduplexfilter.exe $(guilflags) /PDB:$(OUTDIR)\fullduplexfilter.pdb /MACHINE:$(CPU) $(OUTDIR)\fullduplexfilter.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\fullduplexfilter.res comctl32.lib dxerr8.lib winmm.lib dsound.lib dxguid.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\fullduplexfilter.obj:	fullduplexfilter.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\fullduplexfilter.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include fullduplexfilter.cpp

$(OUTDIR)\dsutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\fullduplexfilter.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\fullduplexfilter.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\fullduplexfilter.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\fullduplexfilter.res fullduplexfilter.rc 

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
