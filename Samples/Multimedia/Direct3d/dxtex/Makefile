!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\dxtex.exe 

$(OUTDIR)\dxtex.exe:	 $(OUTDIR)\ChildFrm.obj $(OUTDIR)\dialogs.obj $(OUTDIR)\Dxtex.obj $(OUTDIR)\DxtexDoc.obj $(OUTDIR)\DxtexView.obj $(OUTDIR)\MainFrm.obj $(OUTDIR)\StdAfx.obj $(OUTDIR)\Dxtex.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\dxtex.exe $(guilflags) /INCREMENTAL:yes /PDB:dxtex.pdb /MACHINE:$(CPU) $(OUTDIR)\ChildFrm.obj $(OUTDIR)\dialogs.obj $(OUTDIR)\Dxtex.obj $(OUTDIR)\DxtexDoc.obj $(OUTDIR)\DxtexView.obj $(OUTDIR)\MainFrm.obj $(OUTDIR)\StdAfx.obj $(OUTDIR)\Dxtex.res  \
        d3d8.lib d3dx8dt.lib dxguid.lib version.lib $(guilibsdll)

$(OUTDIR)\ChildFrm.obj:	ChildFrm.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\dxtex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_WINDOWS" /D_AFXDLL /D_MBCS ChildFrm.cpp

$(OUTDIR)\dialogs.obj:	dialogs.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\dxtex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_WINDOWS" /D_AFXDLL /D_MBCS dialogs.cpp

$(OUTDIR)\Dxtex.obj:	Dxtex.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\dxtex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_WINDOWS" /D_AFXDLL /D_MBCS Dxtex.cpp

$(OUTDIR)\DxtexDoc.obj:	DxtexDoc.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\dxtex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_WINDOWS" /D_AFXDLL /D_MBCS DxtexDoc.cpp

$(OUTDIR)\DxtexView.obj:	DxtexView.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\dxtex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_WINDOWS" /D_AFXDLL /D_MBCS DxtexView.cpp

$(OUTDIR)\MainFrm.obj:	MainFrm.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\dxtex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_WINDOWS" /D_AFXDLL /D_MBCS MainFrm.cpp

$(OUTDIR)\StdAfx.obj:	StdAfx.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\dxtex.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_WINDOWS" /D_AFXDLL /D_MBCS StdAfx.cpp

$(OUTDIR)\Dxtex.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\dxtex.res dxtex.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
