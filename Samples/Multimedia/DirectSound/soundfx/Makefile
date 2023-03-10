!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\soundfx.exe 

$(OUTDIR)\soundfx.exe:	 $(OUTDIR) $(OUTDIR)\soundfx.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\soundfx.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\soundfx.exe $(guilflags) /PDB:$(OUTDIR)\soundfx.pdb /MACHINE:$(CPU) $(OUTDIR)\soundfx.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\soundfx.res dsound.lib dxguid.lib winmm.lib dxerr8.lib comctl32.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\soundfx.obj:	soundfx.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\soundfx.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include soundfx.cpp

$(OUTDIR)\dsutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\soundfx.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\soundfx.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\soundfx.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\soundfx.res soundfx.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
