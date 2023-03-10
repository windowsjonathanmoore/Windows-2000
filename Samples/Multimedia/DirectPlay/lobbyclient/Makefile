!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\LobbyClient.exe 

$(OUTDIR)\LobbyClient.exe:	 $(OUTDIR)\LobbyClient.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\LobbyClient.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\LobbyClient.exe $(guilflags) /PDB:$(OUTDIR)\LobbyClient.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\LobbyClient.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\LobbyClient.res wsock32.lib dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\LobbyClient.obj:	LobbyClient.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\LobbyClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include LobbyClient.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\LobbyClient.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\LobbyClient.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\LobbyClient.res LobbyClient.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
