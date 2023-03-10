!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

!ifndef NODEBUG
cflags=$(cflags) /DDEBUG
!endif

all:	$(OUTDIR) $(OUTDIR)\dmosample.dll 

$(OUTDIR)\dmosample.dll:	 $(OUTDIR) $(OUTDIR)\StdAfx.obj $(OUTDIR)\sample.obj $(OUTDIR)\dmosample.obj  $(OUTDIR)\state.obj $(OUTDIR)\util.obj $(OUTDIR)\dmosample.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\dmosample.dll /DLL /PDB:$(OUTDIR)\dmosample.pdb /DEF:dmosample.def /MACHINE:$(CPU) /LIBPATH::"..\..\..\..\..\lib" $(OUTDIR)\dmosample.obj $(OUTDIR)\sample.obj $(OUTDIR)\state.obj $(OUTDIR)\StdAfx.obj $(OUTDIR)\util.obj $(OUTDIR)\dmosample.res shell32.lib $(ole2libs) odbc32.lib odbccp32.lib msdmo.lib dmoguids.lib strmiids.lib 

$(OUTDIR)\dmosample.obj:	dmosample.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /GX /Fp"$(OUTDIR)\\" /Yu"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /D"_USRDLL" /D"DMOSAMPLE_EXPORTS" dmosample.cpp

$(OUTDIR)\sample.obj:	sample.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /GX /Fp"$(OUTDIR)\\" /Yu"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /D"_USRDLL" /D"DMOSAMPLE_EXPORTS" sample.cpp

$(OUTDIR)\state.obj:	state.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /GX /Fp"$(OUTDIR)\\" /Yu"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /D"_USRDLL" /D"DMOSAMPLE_EXPORTS" state.cpp

$(OUTDIR)\StdAfx.obj:	StdAfx.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /GX /Fp"$(OUTDIR)\\" /Yc"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /D"_USRDLL" /D"DMOSAMPLE_EXPORTS" StdAfx.cpp

$(OUTDIR)\util.obj:	util.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /GX /Fp"$(OUTDIR)\\" /Yu"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /D"_USRDLL" /D"DMOSAMPLE_EXPORTS" util.cpp

$(OUTDIR)\dmosample.res:	
	$(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\\dmosample.res dmosample.rc 

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
