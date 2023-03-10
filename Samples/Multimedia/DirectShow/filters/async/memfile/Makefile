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

all:	$(OUTDIR) $(OUTDIR)\memfile.exe 

$(OUTDIR)\memfile.exe:	$(OUTDIR)\memfile.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\memfile.exe $(conlflags) /PDB:$(OUTDIR)\memfile.pdb /MACHINE:$(CPU) $(OUTDIR)\memfile.obj $(STRMBASE) strmiids.lib winmm.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib ..\base\$(OUTDIR)\asynbase.lib /NODEFAULTLIB:libcmt.lib msvcrt.lib

$(OUTDIR)\memfile.obj:	memfile.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Fp$(OUTDIR)\memfile.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_CONSOLE /DINC_OLE2 /D_MT /D_DLL /Dtry=__try /Dexcept=__except /Dleave=__leave /Dfinally=__finally /I..\..\..\BaseClasses /I..\include memfile.cpp
        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
