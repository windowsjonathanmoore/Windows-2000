!include <disable.mak>

!ifdef NODEBUG
STRMBASE = strmbase.lib
!else
STRMBASE = strmbasd.lib
!endif

STRMBASE="$(MSSDK)\samples\multimedia\directshow\baseclasses\$(OUTDIR)\$(STRMBASE)"


#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\StillCap.exe 

$(OUTDIR)\StillCap.exe:	 $(OUTDIR) $(OUTDIR)\StdAfx.obj $(OUTDIR)\StillCap.obj $(OUTDIR)\StillCapDlg.obj $(OUTDIR)\StillCap.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\StillCap.exe $(guilflags) /NODEFAULTLIB:LIBCMT.lib MSVCRT.lib LIBCMTD.lib MSVCRTD.lib /PDB:$(OUTDIR)\StillCap.pdb /MACHINE:$(CPU) $(OUTDIR)\StdAfx.obj $(OUTDIR)\StillCap.obj $(OUTDIR)\StillCapDlg.obj $(OUTDIR)\StillCap.res $(STRMBASE) winmm.lib 

$(OUTDIR)\StdAfx.obj:	StdAfx.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_AFXDLL" /D"_MBCS" /I..\..\BaseClasses StdAfx.cpp

$(OUTDIR)\StillCap.obj:	StillCap.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_AFXDLL" /D"_MBCS" /I..\..\BaseClasses StillCap.cpp

$(OUTDIR)\StillCapDlg.obj:	StillCapDlg.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_AFXDLL" /D"_MBCS" /I..\..\BaseClasses StillCapDlg.cpp

$(OUTDIR)\StillCap.res:	
	$(rc) $(rcflags) /Fo$(OUTDIR)\StillCap.res StillCap.rc 

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
