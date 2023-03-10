!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\dotproduct3.exe 

$(OUTDIR)\dotproduct3.exe:	 $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\DotProduct3.obj $(OUTDIR)\WinMain.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\dotproduct3.exe $(guilflags) /INCREMENTAL:yes /PDB:$(OUTDIR)\dotproduct3.pdb /MACHINE:$(CPU) $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\DotProduct3.obj $(OUTDIR)\WinMain.res d3dx8dt.lib d3d8.lib ddraw.lib d3dxof.lib dxguid.lib winmm.lib $(winlibs) shell32.lib 

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\dotproduct3.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"

$(OUTDIR)\d3dfile.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\dotproduct3.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\dotproduct3.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\dotproduct3.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\dotproduct3.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\DotProduct3.obj:	DotProduct3.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\dotproduct3.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include DotProduct3.cpp

$(OUTDIR)\WinMain.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\winmain.res winmain.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
