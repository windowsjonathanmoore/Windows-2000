!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\billboard.exe 

$(OUTDIR)\billboard.exe: $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\billboard.obj $(OUTDIR)\winmain.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\billboard.exe $(guilflags) $(lflags) /PDB:billboard.pdb /MACHINE:$(CPU) /LIBPATH::"..\..\framework\lib" $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\billboard.obj $(OUTDIR)\winmain.res d3dx8dt.lib d3d8.lib d3dxof.lib winmm.lib dxguid.lib shell32.lib $(ole2libs) 

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\billboard.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp" 

$(OUTDIR)\d3dfile.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp" 
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\billboard.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp" 

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp" 
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\billboard.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp" 

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp" 
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\billboard.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp" 

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\billboard.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp" 

$(OUTDIR)\billboard.obj: billboard.cpp 
	$(cc) $(cvars) $(cdebug) $(cflags) /Gm /GX /Fp$(OUTDIR)\billboard.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_DEBUG" /D"_WINDOWS" /I..\..\common\include billboard.cpp 

$(OUTDIR)\winmain.res:	$(OUTDIR) 
	 $(rc) $(rcflags) /Fo$(OUTDIR)\winmain.res  winmain.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
