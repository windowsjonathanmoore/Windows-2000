!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

!ifdef NODEBUG
STRMBASE = strmbase.lib
!else
STRMBASE = strmbasd.lib
cflags=$(cflags) /DDEBUG
!endif

STRMBASE="$(MSSDK)\samples\multimedia\directshow\baseclasses\$(OUTDIR)\$(STRMBASE)"

all:	$(OUTDIR) $(OUTDIR)\DVApp.exe 

$(OUTDIR)\DVApp.exe:	 $(OUTDIR) $(OUTDIR)\dvapp.obj $(OUTDIR)\dvapp.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\DVApp.exe $(guilflags) /NODEFAULTLIB:libcmt.lib /PDB:$(OUTDIR)\DVApp.pdb /MACHINE:$(CPU) $(OUTDIR)\dvapp.obj $(OUTDIR)\dvapp.res $(STRMBASE) comctl32.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib winmm.lib 

$(OUTDIR)\dvapp.obj:	dvapp.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\DVApp.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I. /I..\..\BaseClasses dvapp.cpp

$(OUTDIR)\dvapp.res:	
	$(rc) $(rcflags) $(rcvars) /I..\..\baseclasses /Fo$(OUTDIR)\DVApp.res DVApp.rc  

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
