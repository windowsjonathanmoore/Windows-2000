!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\Textures.exe 

$(OUTDIR)\Textures.exe:	 $(OUTDIR)\Textures.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\Textures.exe $(guilflags) /PDB:$(OUTDIR)\Textures.pdb /MACHINE:$(CPU) $(OUTDIR)\Textures.obj d3dx8.lib d3d8.lib winmm.lib $(winlibs) shell32.lib 

$(OUTDIR)\Textures.obj:	Textures.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\Textures.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS Textures.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
