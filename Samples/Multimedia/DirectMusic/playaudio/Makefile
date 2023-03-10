!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\PlayAudio.exe 

$(OUTDIR)\PlayAudio.exe:	 $(OUTDIR)\PlayAudio.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\PlayAudio.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\PlayAudio.exe $(guilflags) /PDB:$(OUTDIR)\PlayAudio.pdb /MACHINE:$(CPU) $(OUTDIR)\PlayAudio.obj $(OUTDIR)\dmutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\PlayAudio.res comctl32.lib dxerr8.lib winmm.lib dxguid.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\PlayAudio.obj:	PlayAudio.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\PlayAudio.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include PlayAudio.cpp

$(OUTDIR)\dmutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\PlayAudio.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dmutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\PlayAudio.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\PlayAudio.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\PlayAudio.res PlayAudio.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
