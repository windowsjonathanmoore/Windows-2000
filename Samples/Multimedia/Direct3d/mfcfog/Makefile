!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\mfcfog.exe 

$(OUTDIR)\mfcfog.exe:	 $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\fog.obj $(OUTDIR)\stdafx.obj $(OUTDIR)\fog.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\mfcfog.exe $(guilflags) /PDB:$(OUTDIR)\mfcfog.pdb /MACHINE:$(CPU) $(OUTDIR)\d3dapp.obj $(OUTDIR)\d3dfile.obj $(OUTDIR)\d3dutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\fog.obj $(OUTDIR)\stdafx.obj $(OUTDIR)\fog.res d3dx8dt.lib d3d8.lib d3dxof.lib dxguid.lib winmm.lib 

$(OUTDIR)\d3dapp.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfcfog.pch /YX"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dapp.cpp"

$(OUTDIR)\d3dfile.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfcfog.pch /YX"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dfile.cpp"

$(OUTDIR)\d3dutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfcfog.pch /YX"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\d3dutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfcfog.pch /YX"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\fog.obj:	fog.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfcfog.pch /YX"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include fog.cpp

$(OUTDIR)\stdafx.obj:	stdafx.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\mfcfog.pch /YX"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /D_AFXDLL /I..\..\common\include stdafx.cpp

$(OUTDIR)\fog.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\fog.res fog.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
