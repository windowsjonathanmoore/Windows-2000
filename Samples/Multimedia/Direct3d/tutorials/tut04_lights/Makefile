!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\Lights.exe 

$(OUTDIR)\Lights.exe:	 $(OUTDIR) $(OUTDIR)\Lights.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\Lights.exe $(guilflags) /PDB:$(OUTDIR)\Lights.pdb /MACHINE:$(CPU) $(OUTDIR)\Lights.obj d3dx8.lib d3d8.lib winmm.lib $(winlibs) shell32.lib 

$(OUTDIR)\Lights.obj:	Lights.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\Lights.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS Lights.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
