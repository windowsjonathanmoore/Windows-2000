!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\SimpleClient.exe 

$(OUTDIR)\SimpleClient.exe:	 $(OUTDIR) $(OUTDIR)\SimpleClient.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\netclient.obj $(OUTDIR)\SimpleClient.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\SimpleClient.exe $(guilflags) /PDB:$(OUTDIR)\SimpleClient.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\SimpleClient.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\netclient.obj $(OUTDIR)\SimpleClient.res dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\SimpleClient.obj:	SimpleClient.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\SimpleClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common SimpleClient.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\SimpleClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\netclient.obj:	"$(MSSDK)\Samples\Multimedia\common\src\netclient.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\SimpleClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common "$(MSSDK)\Samples\Multimedia\common\src\netclient.cpp"

$(OUTDIR)\SimpleClient.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\SimpleClient.res SimpleClient.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
