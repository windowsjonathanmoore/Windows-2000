!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\stagedpeer.exe 

$(OUTDIR)\stagedpeer.exe:	 $(OUTDIR)\NetStage.obj $(OUTDIR)\StagedPeer.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\NetConnect.obj $(OUTDIR)\StagedPeer.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\stagedpeer.exe $(guilflags) /PDB:$(OUTDIR)\stagedpeer.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\NetStage.obj $(OUTDIR)\StagedPeer.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\NetConnect.obj $(OUTDIR)\StagedPeer.res dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\NetStage.obj:	NetStage.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\stagedpeer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include NetStage.cpp

$(OUTDIR)\StagedPeer.obj:	StagedPeer.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\stagedpeer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include StagedPeer.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\stagedpeer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\NetConnect.obj:	"$(MSSDK)\Samples\Multimedia\common\src\NetConnect.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\stagedpeer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\NetConnect.cpp"

$(OUTDIR)\StagedPeer.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\StagedPeer.res StagedPeer.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
