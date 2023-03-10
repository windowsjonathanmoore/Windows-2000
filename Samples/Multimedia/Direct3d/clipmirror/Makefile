!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\clipmirror.exe 

$(OUTDIR)\clipmirror.exe:	$(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\ClipMirror.obj $(OUTDIR)\winmain.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\clipmirror.exe $(guilflags) /PDB:$(OUTDIR)\clipmirror.pdb /MACHINE:$(CPU) /LIBPATH::"..\..\lib" $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\ClipMirror.obj $(OUTDIR)\winmain.res d3dx8dt.lib d3d8.lib dxguid.lib winmm.lib d3dxof.lib $(winlibs) shell32.lib uuid.lib 

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\clipmirror.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"

$(OUTDIR)\d3dfile.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\clipmirror.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\clipmirror.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\clipmirror.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\clipmirror.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\ClipMirror.obj:	ClipMirror.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\clipmirror.pch  /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_MBCS" /I..\..\common\include ClipMirror.cpp

$(OUTDIR)\winmain.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\winmain.res winmain.rc
        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
