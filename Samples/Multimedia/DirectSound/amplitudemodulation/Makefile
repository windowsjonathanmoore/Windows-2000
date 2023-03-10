!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\amplitudemodulation.exe 

$(OUTDIR)\amplitudemodulation.exe:	 $(OUTDIR) $(OUTDIR)\AmplitudeModulation.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AmplitudeModulation.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\amplitudemodulation.exe $(guilflags) /PDB:$(OUTDIR)\amplitudemodulation.pdb /MACHINE:$(CPU) $(OUTDIR)\AmplitudeModulation.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AmplitudeModulation.res comctl32.lib dxerr8.lib winmm.lib dsound.lib dxguid.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\AmplitudeModulation.obj:	AmplitudeModulation.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\amplitudemodulation.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include AmplitudeModulation.cpp

$(OUTDIR)\dsutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\amplitudemodulation.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dsutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\amplitudemodulation.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\AmplitudeModulation.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\amplitudemodulation.res amplitudemodulation.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
