!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\MazeServer.exe 

$(OUTDIR)\MazeServer.exe:	 $(OUTDIR) $(OUTDIR)\Main.obj $(OUTDIR)\Maze.obj $(OUTDIR)\MazeServer.obj $(OUTDIR)\server.obj $(OUTDIR)\dxutil.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\MazeServer.exe $(conlflags) /PDB:$(OUTDIR)\MazeServer.pdb /MACHINE:$(CPU) $(OUTDIR)\Main.obj $(OUTDIR)\Maze.obj $(OUTDIR)\MazeServer.obj $(OUTDIR)\server.obj $(OUTDIR)\dxutil.obj dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\Main.obj:	Main.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_CONSOLE /D_WIN32_DCOM /I..\mazecommon /I..\..\..\common\include Main.cpp

$(OUTDIR)\Maze.obj:	"$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\Maze.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_CONSOLE /D_WIN32_DCOM /I..\mazecommon /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\Maze.cpp"

$(OUTDIR)\MazeServer.obj:	"$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\MazeServer.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_CONSOLE /D_WIN32_DCOM /I..\mazecommon /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\DirectPlay\maze\mazecommon\MazeServer.cpp"

$(OUTDIR)\server.obj:	server.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_CONSOLE /D_WIN32_DCOM /I..\mazecommon /I..\..\..\common\include server.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_CONSOLE /D_WIN32_DCOM /I..\mazecommon /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
