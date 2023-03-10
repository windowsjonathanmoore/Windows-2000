!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\ddenum.exe 

$(OUTDIR)\ddenum.exe:	 $(OUTDIR)\ddenum.obj $(OUTDIR)\ddenum.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\ddenum.exe $(guilflags) /PDB:$(OUTDIR)\ddenum.pdb /MACHINE:$(CPU) $(OUTDIR)\ddenum.obj $(OUTDIR)\ddenum.res dxguid.lib dxerr8.lib ddraw.lib shell32.lib $(ole2libs) 

$(OUTDIR)\ddenum.obj:	ddenum.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\ddenum.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include ddenum.cpp

$(OUTDIR)\ddenum.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\ddenum.res ddenum.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
