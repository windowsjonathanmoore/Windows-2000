!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\audiofx.exe 

$(OUTDIR)\audiofx.exe:	 $(OUTDIR)\audiofx.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\audiofx.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\audiofx.exe $(guilflags) /PDB:$(OUTDIR)\audiofx.pdb /MACHINE:$(CPU) $(OUTDIR)\audiofx.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\audiofx.res shell32.lib $(ole2libs) odbc32.lib odbccp32.lib dxguid.lib dxerr8.lib comctl32.lib winmm.lib dsound.lib 

$(OUTDIR)\audiofx.obj:	audiofx.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\audiofx.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include audiofx.cpp

$(OUTDIR)\dmutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\audiofx.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"

$(OUTDIR)\dsutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\audiofx.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\audiofx.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\audiofx.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\audiofx.res audiofx.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
