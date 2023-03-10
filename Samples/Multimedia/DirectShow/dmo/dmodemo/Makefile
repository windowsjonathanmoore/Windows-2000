!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

!ifndef NODEBUG
cflags=$(cflags) /DDEBUG
!endif

all:	$(OUTDIR) $(OUTDIR)\dmodemo.exe 

$(OUTDIR)\dmodemo.exe:	 $(OUTDIR) $(OUTDIR)\appstream.obj $(OUTDIR)\dmodemo.obj $(OUTDIR)\wave.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\dmodemo.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\dmodemo.exe /PDB:$(OUTDIR)\dmodemo.pdb /MACHINE:$(CPU) $(OUTDIR)\appstream.obj $(OUTDIR)\dmodemo.obj $(OUTDIR)\wave.obj $(OUTDIR)\dsutil.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\dmodemo.res comctl32.lib dsound.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib winmm.lib amstrmid.lib msdmo.lib dmoguids.lib dxguid.lib shlwapi.lib dxerr8.lib 

$(OUTDIR)\appstream.obj:	appstream.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\dmodemo.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\BaseClasses /I..\..\..\common\include  /D_WIN32_DCOM appstream.cpp

$(OUTDIR)\dmodemo.obj:	dmodemo.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\dmodemo.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\BaseClasses /I..\..\..\common\include  /D_WIN32_DCOM dmodemo.cpp

$(OUTDIR)\wave.obj:	wave.c
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\dmodemo.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\BaseClasses /I..\..\..\common\include  /D_WIN32_DCOM wave.c

$(OUTDIR)\dsutil.obj:	"$(MSSDK)\Samples\Multimedia\\Common\src\dsutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\dmodemo.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\BaseClasses /I..\..\..\common\include  /D_WIN32_DCOM "$(MSSDK)\Samples\Multimedia\Common\src\dsutil.cpp"

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\Common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\dmodemo.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I..\..\BaseClasses /I..\..\..\common\include  /D_WIN32_DCOM "$(MSSDK)\Samples\Multimedia\Common\src\dxutil.cpp"

$(OUTDIR)\dmodemo.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\\dmodemo.res dmodemo.rc 

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
