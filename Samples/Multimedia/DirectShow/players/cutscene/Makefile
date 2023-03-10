!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\Cutscene.exe 

$(OUTDIR)\Cutscene.exe:	$(OUTDIR)\cutscene.obj $(OUTDIR)\main.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\Cutscene.exe $(guilflags) /PDB:$(OUTDIR)\Cutscene.pdb /MACHINE:$(CPU) $(OUTDIR)\cutscene.obj $(OUTDIR)\main.obj strmiids.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\cutscene.obj:	cutscene.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\Cutscene.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\BaseClasses cutscene.cpp

$(OUTDIR)\main.obj:	main.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\Cutscene.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\BaseClasses main.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
