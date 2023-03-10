!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\VoiceServer.exe 

$(OUTDIR)\VoiceServer.exe:	$(OUTDIR)\VoiceServer.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\netvoice.obj $(OUTDIR)\VoiceServer.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\VoiceServer.exe $(guilflags) /PDB:$(OUTDIR)\VoiceServer.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\VoiceServer.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\netvoice.obj $(OUTDIR)\VoiceServer.res dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\VoiceServer.obj:	VoiceServer.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoiceServer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common VoiceServer.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoiceServer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\netvoice.obj:	"$(MSSDK)\Samples\Multimedia\common\src\netvoice.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoiceServer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common "$(MSSDK)\Samples\Multimedia\common\src\netvoice.cpp"

$(OUTDIR)\VoiceServer.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\VoiceServer.res VoiceServer.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
