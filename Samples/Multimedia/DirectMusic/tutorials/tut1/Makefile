!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\tutorial1.exe 

$(OUTDIR)\tutorial1.exe:	 $(OUTDIR)\tutorial1.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\tutorial1.exe $(guilflags) /PDB:$(OUTDIR)\tutorial1.pdb /MACHINE:$(CPU) $(OUTDIR)\tutorial1.obj winmm.lib dxerr8.lib dxguid.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\tutorial1.obj:	tutorial1.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\tutorial1.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include tutorial1.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
