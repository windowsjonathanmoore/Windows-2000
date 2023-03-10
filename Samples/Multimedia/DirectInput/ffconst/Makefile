!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\ffconst.exe 

$(OUTDIR)\ffconst.exe:	 $(OUTDIR)\FFConst.obj $(OUTDIR)\FFConst.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\ffconst.exe $(guilflags) /PDB:$(OUTDIR)\ffconst.pdb /MACHINE:$(CPU) $(OUTDIR)\FFConst.obj $(OUTDIR)\FFConst.res dxguid.lib winmm.lib dxerr8.lib dinput8.lib $(winlibs) shell32.lib uuid.lib 

$(OUTDIR)\FFConst.obj:	FFConst.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\ffconst.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS FFConst.cpp

$(OUTDIR)\FFConst.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\ffconst.res ffconst.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
