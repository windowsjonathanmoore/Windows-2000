!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\adjustsound.exe 

$(OUTDIR)\adjustsound.exe:	 $(OUTDIR) $(OUTDIR)\adjustsound.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AdjustSound.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\adjustsound.exe $(guilflags) /PDB:$(OUTDIR)\adjustsound.pdb /MACHINE:$(CPU) $(OUTDIR)\adjustsound.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AdjustSound.res comctl32.lib dxerr8.lib winmm.lib dsound.lib dxguid.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\adjustsound.obj:	adjustsound.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\adjustsound.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include adjustsound.cpp

$(OUTDIR)\dsutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\adjustsound.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\adjustsound.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\AdjustSound.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\adjustsound.res adjustsound.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
