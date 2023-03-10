!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\SkinnedMesh.exe 

$(OUTDIR)\SkinnedMesh.exe:	 $(OUTDIR) $(OUTDIR)\mdraw.obj $(OUTDIR)\mload.obj $(OUTDIR)\skinnedmesh.obj $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\skinnedmesh.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\SkinnedMesh.exe $(guilflags) /PDB:$(OUTDIR)\SkinnedMesh.pdb /MACHINE:$(CPU) $(OUTDIR)\mdraw.obj $(OUTDIR)\mload.obj $(OUTDIR)\skinnedmesh.obj $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\skinnedmesh.res shell32.lib $(ole2libs) odbc32.lib odbccp32.lib d3dx8dt.lib d3dxof.lib d3d8.lib winmm.lib dxguid.lib 

$(OUTDIR)\mdraw.obj:	mdraw.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include mdraw.cpp

$(OUTDIR)\mload.obj:	mload.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include mload.cpp

$(OUTDIR)\skinnedmesh.obj:	skinnedmesh.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include skinnedmesh.cpp

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\skinnedmesh.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\skinnedmesh.res skinnedmesh.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
