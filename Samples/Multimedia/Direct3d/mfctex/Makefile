!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\mfctex.exe 

$(OUTDIR)\mfctex.exe:	 $(OUTDIR) $(OUTDIR)\stdafx.obj $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\MFCForm.obj $(OUTDIR)\MFCTex.obj $(OUTDIR)\mtexture.obj $(OUTDIR)\winmain.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\mfctex.exe $(guilflags) /PDB:$(OUTDIR)\mfctex.pdb /MACHINE:$(CPU) $(OUTDIR)\stdafx.obj $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dfont.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\MFCForm.obj $(OUTDIR)\MFCTex.obj $(OUTDIR)\mtexture.obj $(OUTDIR)\winmain.res d3dx8dt.lib d3d8.lib d3dxof.lib dxguid.lib ddraw.lib winmm.lib 

$(OUTDIR)\stdafx.obj:	stdafx.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfctex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include stdafx.cpp

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfctex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"

$(OUTDIR)\d3dfile.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfctex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"

$(OUTDIR)\d3dfont.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfctex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfont.cpp"

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfctex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfctex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\MFCForm.obj:	MFCForm.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfctex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include MFCForm.cpp

$(OUTDIR)\MFCTex.obj:	MFCTex.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfctex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include MFCTex.cpp

$(OUTDIR)\mtexture.obj:	mtexture.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfctex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include mtexture.cpp

$(OUTDIR)\winmain.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\winmain.res winmain.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
