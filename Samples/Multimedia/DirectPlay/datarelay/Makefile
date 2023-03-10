!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\datarelay.exe 

$(OUTDIR)\datarelay.exe:	 $(OUTDIR)\DataRelay.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\NetConnect.obj $(OUTDIR)\DataRelay.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\datarelay.exe $(guilflags) /PDB:$(OUTDIR)\datarelay.pdb /NODEFAULTLIB:LIBC /MACHINE:$(CPU) $(OUTDIR)\DataRelay.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\NetConnect.obj $(OUTDIR)\DataRelay.res dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\DataRelay.obj:	DataRelay.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\datarelay.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include DataRelay.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\datarelay.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\NetConnect.obj:	"$(MSSDK)\Samples\Multimedia\common\src\NetConnect.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\datarelay.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_WIN32_DCOM /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\NetConnect.cpp"

$(OUTDIR)\DataRelay.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\DataRelay.res DataRelay.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
