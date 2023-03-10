!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\VoiceClient.exe 

$(OUTDIR)\VoiceClient.exe:	 $(OUTDIR)\VoiceClient.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\netclient.obj $(OUTDIR)\netvoice.obj $(OUTDIR)\VoiceClient.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\VoiceClient.exe $(guilflags) /PDB:$(OUTDIR)\VoiceClient.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\VoiceClient.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\netclient.obj $(OUTDIR)\netvoice.obj $(OUTDIR)\VoiceClient.res dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) comctl32.lib 

$(OUTDIR)\VoiceClient.obj:	VoiceClient.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoiceClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common VoiceClient.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoiceClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\netclient.obj:	"$(MSSDK)\Samples\Multimedia\common\src\netclient.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoiceClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common "$(MSSDK)\Samples\Multimedia\common\src\netclient.cpp"

$(OUTDIR)\netvoice.obj:	"$(MSSDK)\Samples\Multimedia\common\src\netvoice.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\VoiceClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common "$(MSSDK)\Samples\Multimedia\common\src\netvoice.cpp"

$(OUTDIR)\VoiceClient.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\VoiceClient.res VoiceClient.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
