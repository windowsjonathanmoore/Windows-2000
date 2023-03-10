!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\CreateDevice.exe 

$(OUTDIR)\CreateDevice.exe:	 $(OUTDIR)\CreateDevice.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\CreateDevice.exe $(guilflags) /PDB:$(OUTDIR)\CreateDevice.pdb /MACHINE:$(CPU) $(OUTDIR)\CreateDevice.obj d3d8.lib $(winlibs) shell32.lib 

$(OUTDIR)\CreateDevice.obj:	CreateDevice.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\CreateDevice.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS CreateDevice.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
