!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\VoicePosition.exe 

$(OUTDIR)\VoicePosition.exe:	$(OUTDIR)\VoicePosition.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\NetConnect.obj $(OUTDIR)\NetVoice.obj $(OUTDIR)\VoicePosition.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\VoicePosition.exe $(guilflags) /PDB:$(OUTDIR)\VoicePosition.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\VoicePosition.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\NetConnect.obj $(OUTDIR)\NetVoice.obj $(OUTDIR)\VoicePosition.res dplay.lib comctl32.lib dsound.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\VoicePosition.obj:	VoicePosition.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoicePosition.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include VoicePosition.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoicePosition.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\NetConnect.obj:	"$(MSSDK)\Samples\Multimedia\common\src\NetConnect.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoicePosition.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\NetConnect.cpp"

$(OUTDIR)\NetVoice.obj:	"$(MSSDK)\Samples\Multimedia\common\src\NetVoice.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoicePosition.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\NetVoice.cpp"

$(OUTDIR)\VoicePosition.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\VoicePosition.res VoicePosition.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
