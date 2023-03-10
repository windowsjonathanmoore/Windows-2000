!include <disable.mak>

!ifdef NODEBUG
STRMBASE = strmbase.lib
!else
STRMBASE = strmbasd.lib
!endif

STRMBASE="$(MSSDK)\samples\multimedia\directshow\baseclasses\$(OUTDIR)\$(STRMBASE)"


#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\TimelineTest.exe 

$(OUTDIR)\TimelineTest.exe:	 $(OUTDIR) $(OUTDIR)\StdAfx.obj $(OUTDIR)\TimelineTest.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\TimelineTest.exe $(guilflags) /NODEFAULTLIB:libcmt.lib libcmtd.lib /PDB:$(OUTDIR)\TimelineTest.pdb /MACHINE:$(CPU) $(OUTDIR)\StdAfx.obj $(OUTDIR)\TimelineTest.obj $(STRMBASE) shell32.lib $(ole2libs) odbc32.lib odbccp32.lib winmm.lib  

$(OUTDIR)\StdAfx.obj:	StdAfx.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gi /GX /Fp$(OUTDIR)\TimelineTest.pch /Yc"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\BaseClasses /I..\..\..\common\include /I..\..\..\common\src StdAfx.cpp

$(OUTDIR)\TimelineTest.obj:	TimelineTest.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsmt) /Gi /GX /Fp$(OUTDIR)\TimelineTest.pch /Yu"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /I..\..\BaseClasses /I..\..\..\common\include /I..\..\..\common\src TimelineTest.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
