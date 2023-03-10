!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\AddressOverride.exe 

$(OUTDIR)\AddressOverride.exe:	 $(OUTDIR)\AddressOverride.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AddressOverride.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\AddressOverride.exe $(guilflags) /PDB:$(OUTDIR)\AddressOverride.pdb /NODEFAULTLIB:LIBC \
        /MACHINE:$(CPU) $(OUTDIR)\AddressOverride.obj $(OUTDIR)\dxutil.obj $(OUTDIR)\AddressOverride.res wsock32.lib dplay.lib dxguid.lib shell32.lib odbc32.lib odbccp32.lib dxerr8.lib winmm.lib $(ole2libs) 

$(OUTDIR)\AddressOverride.obj:	AddressOverride.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\AddressOverride.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_WIN32_DCOM" /I..\..\common\include AddressOverride.cpp

$(OUTDIR)\dxutil.obj:	"$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gm /GX /Fp$(OUTDIR)\AddressOverride.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_WIN32_DCOM" /I..\..\common\include "$(MSSDK)\Samples\Multimedia\common\src\dxutil.cpp"

$(OUTDIR)\AddressOverride.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\AddressOverride.res AddressOverride.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
