!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\BumpEarth.exe 

$(OUTDIR)\BumpEarth.exe:	 $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\BumpEarth.obj $(OUTDIR)\winmain.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\BumpEarth.exe $(guilflags) /PDB:$(OUTDIR)\BumpEarth.pdb /MACHINE:$(CPU) $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\BumpEarth.obj $(OUTDIR)\winmain.res \
        d3dx8dt.lib d3d8.lib d3dxof.lib dxguid.lib winmm.lib $(winlibs) shell32.lib 

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp" 
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\BumpEarth.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp" 

$(OUTDIR)\d3dfile.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp" 
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\BumpEarth.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp" 

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp" 
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\BumpEarth.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp" 

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp" 
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\BumpEarth.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp" 

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp" 
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\BumpEarth.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp" 

$(OUTDIR)\BumpEarth.obj:  BumpEarth.cpp 
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\BumpEarth.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\..\common\include BumpEarth.cpp 

$(OUTDIR)\winmain.res:	$(OUTDIR) 
	 $(rc) /Fo$(OUTDIR)\winmain.res winmain.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
