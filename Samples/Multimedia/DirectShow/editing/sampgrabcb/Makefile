!include <disable.mak>

!ifdef NODEBUG
STRMBASE = strmbase.lib
!else
STRMBASE = strmbasd.lib
!endif

STRMBASE="$(MSSDK)\samples\multimedia\directshow\baseclasses\$(OUTDIR)\$(STRMBASE)"


#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\SampGrabCB.exe 

$(OUTDIR)\SampGrabCB.exe:	 $(OUTDIR) $(OUTDIR)\SampGrabCB.obj $(OUTDIR)\StdAfx.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\SampGrabCB.exe $(conlflags) /NODEFAULTLIB:LIBCMT.lib /PDB:$(OUTDIR)\SampGrabCB.pdb /MACHINE:$(CPU) $(OUTDIR)\SampGrabCB.obj $(OUTDIR)\StdAfx.obj $(STRMBASE) winmm.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\StdAfx.obj:	StdAfx.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_CONSOLE" /D"_MBCS" /I..\..\BaseClasses /I..\..\..\..\include StdAfx.cpp

$(OUTDIR)\SampGrabCB.obj:	SampGrabCB.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_CONSOLE" /D"_MBCS" /I..\..\BaseClasses /I..\..\..\..\include SampGrabCB.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
