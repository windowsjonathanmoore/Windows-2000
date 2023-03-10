!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\simplepeer.exe 

$(OUTDIR)\simplepeer.exe:	 $(OUTDIR)\SimplePeer.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\NetConnect.obj $(OUTDIR)\SimplePeer.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\simplepeer.exe $(guilflags) /PDB:$(OUTDIR)\simplepeer.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\SimplePeer.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\NetConnect.obj $(OUTDIR)\SimplePeer.res dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\SimplePeer.obj:	SimplePeer.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\simplepeer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include SimplePeer.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\simplepeer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\NetConnect.obj:	"$(MSSDK)\Samples\Multimedia\common\src\NetConnect.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\simplepeer.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\NetConnect.cpp"

$(OUTDIR)\SimplePeer.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\SimplePeer.res SimplePeer.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
