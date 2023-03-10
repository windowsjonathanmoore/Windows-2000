!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\SimpleServer.exe 

$(OUTDIR)\SimpleServer.exe:	 $(OUTDIR)\SimpleServer.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\SimpleServer.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\SimpleServer.exe $(guilflags) /PDB:$(OUTDIR)\SimpleServer.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\SimpleServer.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\SimpleServer.res dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\SimpleServer.obj:	SimpleServer.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\SimpleServer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common SimpleServer.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\SimpleServer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\common "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\SimpleServer.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\SimpleServer.res SimpleServer.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
