!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\ChatPeer.exe 

$(OUTDIR)\ChatPeer.exe:	 $(OUTDIR) $(OUTDIR)\ChatPeer.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\NetConnect.obj $(OUTDIR)\ChatPeer.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\ChatPeer.exe $(guilflags) /PDB:$(OUTDIR)\ChatPeer.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\ChatPeer.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\NetConnect.obj $(OUTDIR)\ChatPeer.res dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\ChatPeer.obj:	ChatPeer.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\ChatPeer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include ChatPeer.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\ChatPeer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\NetConnect.obj:	"$(MSSDK)\Samples\Multimedia\common\src\NetConnect.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\ChatPeer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\NetConnect.cpp"

$(OUTDIR)\ChatPeer.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\ChatPeer.res ChatPeer.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
