!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\MazeClient.exe 

$(OUTDIR)\MazeClient.exe:	 $(OUTDIR)\dplay8client.obj $(OUTDIR)\Main.obj $(OUTDIR)\Maze.obj $(OUTDIR)\MazeApp.obj $(OUTDIR)\MazeClient.obj $(OUTDIR)\MazeServer.obj $(OUTDIR)\MiscUtils.obj $(OUTDIR)\Module.obj $(OUTDIR)\ScreenSaverConfig.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\mazeclient.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\MazeClient.exe $(guilflags) /PDB:$(OUTDIR)\MazeClient.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\dplay8client.obj $(OUTDIR)\Main.obj $(OUTDIR)\Maze.obj $(OUTDIR)\MazeApp.obj $(OUTDIR)\MazeClient.obj $(OUTDIR)\MazeServer.obj $(OUTDIR)\MiscUtils.obj $(OUTDIR)\Module.obj $(OUTDIR)\ScreenSaverConfig.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\mazeclient.res ddraw.lib d3dx.lib dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\dplay8client.obj:	"$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\dplay8client.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\MazeClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\mazecommon "$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\dplay8client.cpp"

$(OUTDIR)\Main.obj:	Main.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\MazeClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\mazecommon Main.cpp

$(OUTDIR)\Maze.obj:	"$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\Maze.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\MazeClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\mazecommon "$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\Maze.cpp"

$(OUTDIR)\MazeApp.obj:	MazeApp.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\MazeClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\mazecommon MazeApp.cpp

$(OUTDIR)\MazeClient.obj:	"$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\MazeClient.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\MazeClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\mazecommon "$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\MazeClient.cpp"

$(OUTDIR)\MazeServer.obj:	"$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\MazeServer.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\MazeClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\mazecommon "$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\MazeServer.cpp"

$(OUTDIR)\MiscUtils.obj:	MiscUtils.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\MazeClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\mazecommon MiscUtils.cpp

$(OUTDIR)\Module.obj:	Module.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\MazeClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\mazecommon Module.cpp

$(OUTDIR)\ScreenSaverConfig.obj:	ScreenSaverConfig.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\MazeClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\mazecommon ScreenSaverConfig.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\MazeClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\..\common\include /I..\mazecommon "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\mazeclient.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\MazeClient.res MazeClient.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
