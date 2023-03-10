!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\MultiMapper.exe 

$(OUTDIR)\MultiMapper.exe:	 $(OUTDIR)\multimapper.obj $(OUTDIR)\MultiMapper.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\MultiMapper.exe $(guilflags) /PDB:$(OUTDIR)\MultiMapper.pdb /MACHINE:$(CPU) $(OUTDIR)\multimapper.obj $(OUTDIR)\MultiMapper.res shell32.lib $(ole2libs) odbc32.lib odbccp32.lib dinput8.lib dxguid.lib 

$(OUTDIR)\multimapper.obj:	multimapper.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\MultiMapper.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS multimapper.cpp

$(OUTDIR)\MultiMapper.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\multimapper.res multimapper.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
