!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\tutorial2.exe 

$(OUTDIR)\tutorial2.exe:	 $(OUTDIR) $(OUTDIR)\tutorial2.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\tutorial2.exe $(guilflags) /PDB:$(OUTDIR)\tutorial2.pdb /MACHINE:$(CPU) $(OUTDIR)\tutorial2.obj winmm.lib dxerr8.lib dxguid.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\tutorial2.obj:	tutorial2.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\tutorial2.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include tutorial2.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
