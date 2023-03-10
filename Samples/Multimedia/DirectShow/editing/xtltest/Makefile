!include <disable.mak>

!ifdef NODEBUG
STRMBASE = strmbase.lib
!else
STRMBASE = strmbasd.lib
!endif

STRMBASE="$(MSSDK)\samples\multimedia\directshow\baseclasses\$(OUTDIR)\$(STRMBASE)"


#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\xtltest.exe 

$(OUTDIR)\xtltest.exe:	 $(OUTDIR) $(OUTDIR)\xmltltst.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\xtltest.exe $(conlflags) /NODEFAULTLIB:libcmt.lib msvcrt.lib /PDB:$(OUTDIR)\xtltest.pdb /MACHINE:$(CPU) $(OUTDIR)\xmltltst.obj $(STRMBASE) shell32.lib $(ole2libs) odbc32.lib odbccp32.lib quartz.lib winmm.lib

$(OUTDIR)\xmltltst.obj:	xmltltst.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Fp$(OUTDIR)\xtltest.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_CONSOLE" /D"_MBCS" /I..\..\BaseClasses /I..\BaseClasses xmltltst.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
