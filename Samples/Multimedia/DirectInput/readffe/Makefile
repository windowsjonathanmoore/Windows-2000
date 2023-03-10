!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\readffe.exe 

$(OUTDIR)\readffe.exe:	 $(OUTDIR)\dxutil.obj $(OUTDIR)\readffe.obj $(OUTDIR)\readffe.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\readffe.exe $(guilflags) /PDB:$(OUTDIR)\readffe.pdb /MACHINE:$(CPU) $(OUTDIR)\dxutil.obj $(OUTDIR)\readffe.obj $(OUTDIR)\readffe.res winmm.lib $(ole2libs) odbc32.lib odbccp32.lib dxguid.lib dxerr8.lib dinput8.lib shell32.lib 

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\readffe.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\readffe.obj:	readffe.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\readffe.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_MBCS /I..\..\common\include readffe.cpp

$(OUTDIR)\readffe.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\readffe.res readffe.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
