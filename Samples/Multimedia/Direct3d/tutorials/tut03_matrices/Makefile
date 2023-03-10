!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR)\Matrices.exe 

$(OUTDIR)\Matrices.exe:	 $(OUTDIR) $(OUTDIR)\Matrices.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\Matrices.exe $(guilflags) /PDB:$(OUTDIR)\Matrices.pdb /MACHINE:$(CPU) $(OUTDIR)\Matrices.obj d3dx8.lib d3d8.lib winmm.lib $(winlibs) shell32.lib 

$(OUTDIR)\Matrices.obj:	Matrices.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Od /Fp$(OUTDIR)\Matrices.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS Matrices.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
