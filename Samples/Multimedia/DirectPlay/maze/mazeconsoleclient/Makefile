!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\MazeConsoleClient.exe 

$(OUTDIR)\MazeConsoleClient.exe:	 $(OUTDIR) $(OUTDIR)\dplay8client.obj $(OUTDIR)\Main.obj $(OUTDIR)\Maze.obj $(OUTDIR)\MazeClient.obj $(OUTDIR)\dxutil.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\MazeConsoleClient.exe $(conlflags) /PDB:$(OUTDIR)\MazeConsoleClient.pdb /MACHINE:$(CPU) $(OUTDIR)\dplay8client.obj $(OUTDIR)\Main.obj $(OUTDIR)\Maze.obj $(OUTDIR)\MazeClient.obj $(OUTDIR)\dxutil.obj dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\dplay8client.obj:	"$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\dplay8client.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_CONSOLE" /D"_WIN32_DCOM" /I..\mazecommon /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\dplay8client.cpp"

$(OUTDIR)\Main.obj:	Main.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_CONSOLE" /D"_WIN32_DCOM" /I..\mazecommon /I..\..\..\common\include Main.cpp

$(OUTDIR)\Maze.obj:	"$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\Maze.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_CONSOLE" /D"_WIN32_DCOM" /I..\mazecommon /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\Maze.cpp"

$(OUTDIR)\MazeClient.obj:	"$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\MazeClient.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_CONSOLE" /D"_WIN32_DCOM" /I..\mazecommon /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\MazeClient.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_CONSOLE" /D"_WIN32_DCOM" /I..\mazecommon /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
