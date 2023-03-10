!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\RTPatch.exe 

$(OUTDIR)\RTPatch.exe:	 $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\rtpatch.obj $(OUTDIR)\winmain.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\RTPatch.exe $(guilflags) /PDB:$(OUTDIR)\RTPatch.pdb /MACHINE:$(CPU) $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\rtpatch.obj $(OUTDIR)\winmain.res dxguid.lib d3d8.lib d3dx8dt.lib winmm.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\RTPatch.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\RTPatch.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\RTPatch.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\RTPatch.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\rtpatch.obj:	rtpatch.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\RTPatch.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include rtpatch.cpp

$(OUTDIR)\winmain.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\winmain.res winmain.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
