!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\Vertices.exe 

$(OUTDIR)\Vertices.exe:	 $(OUTDIR)\Vertices.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\Vertices.exe $(guilflags) /PDB:$(OUTDIR)\Vertices.pdb /MACHINE:$(CPU) $(OUTDIR)\Vertices.obj d3d8.lib $(winlibs) shell32.lib 

$(OUTDIR)\Vertices.obj:	Vertices.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Od /Fp$(OUTDIR)\Vertices.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS Vertices.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
