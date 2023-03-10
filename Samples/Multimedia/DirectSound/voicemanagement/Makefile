!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\voicemanagement.exe 

$(OUTDIR)\voicemanagement.exe:	 $(OUTDIR) $(OUTDIR)\voicemanagement.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\voicemanagement.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\voicemanagement.exe $(guilflags) /PDB:$(OUTDIR)\voicemanagement.pdb /MACHINE:$(CPU) $(OUTDIR)\voicemanagement.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\voicemanagement.res comctl32.lib dxerr8.lib winmm.lib dsound.lib dxguid.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\voicemanagement.obj:	voicemanagement.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\voicemanagement.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include voicemanagement.cpp

$(OUTDIR)\dsutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\voicemanagement.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\voicemanagement.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\voicemanagement.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\voicemanagement.res voicemanagement.rc 

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
