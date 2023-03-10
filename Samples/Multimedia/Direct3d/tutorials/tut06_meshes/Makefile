!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\Meshes.exe 

$(OUTDIR)\Meshes.exe:	 $(OUTDIR)\Meshes.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\Meshes.exe $(guilflags) /PDB:$(OUTDIR)\Meshes.pdb /MACHINE:$(CPU) $(OUTDIR)\Meshes.obj d3dx8.lib d3d8.lib winmm.lib $(winlibs) shell32.lib 

$(OUTDIR)\Meshes.obj:	Meshes.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\Meshes.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS Meshes.cpp
        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
