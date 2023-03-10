!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\scrawl.exe 

$(OUTDIR)\scrawl.exe:	 $(OUTDIR)\scrawl.obj $(OUTDIR)\scrawl.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\scrawl.exe $(guilflags) /PDB:$(OUTDIR)\scrawl.pdb /MACHINE:$(CPU) $(OUTDIR)\scrawl.obj $(OUTDIR)\scrawl.res $(ole2libs) dxguid.lib dxerr8.lib dinput8.lib shell32.lib 

$(OUTDIR)\scrawl.obj:	scrawl.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\scrawl.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" scrawl.cpp

$(OUTDIR)\scrawl.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\scrawl.res scrawl.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
