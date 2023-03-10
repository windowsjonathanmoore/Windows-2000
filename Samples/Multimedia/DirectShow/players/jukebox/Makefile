!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:	$(OUTDIR) $(OUTDIR)\Jukebox.exe 

$(OUTDIR)\Jukebox.exe:	$(OUTDIR)\StdAfx.obj $(OUTDIR)\globals.obj $(OUTDIR)\Jukebox.obj $(OUTDIR)\JukeboxDlg.obj $(OUTDIR)\playvideo.obj $(OUTDIR)\StdAfx.obj $(OUTDIR)\Jukebox.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\Jukebox.exe $(guilflags) /PDB:$(OUTDIR)\Jukebox.pdb /MACHINE:$(CPU) $(OUTDIR)\globals.obj $(OUTDIR)\Jukebox.obj $(OUTDIR)\JukeboxDlg.obj $(OUTDIR)\playvideo.obj $(OUTDIR)\StdAfx.obj $(OUTDIR)\Jukebox.res strmiids.lib 

$(OUTDIR)\StdAfx.obj:	StdAfx.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Yc"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_AFXDLL /D_MBCS /I..\..\BaseClasses StdAfx.cpp

$(OUTDIR)\globals.obj:	globals.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Yu"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_AFXDLL" /D"_MBCS" /I..\..\BaseClasses globals.cpp

$(OUTDIR)\Jukebox.obj:	Jukebox.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Yu"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_AFXDLL" /D"_MBCS" /I..\..\BaseClasses Jukebox.cpp

$(OUTDIR)\JukeboxDlg.obj:	JukeboxDlg.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Yu"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_AFXDLL" /D"_MBCS" /I..\..\BaseClasses JukeboxDlg.cpp

$(OUTDIR)\playvideo.obj:	playvideo.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Yu"stdafx.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_AFXDLL" /D"_MBCS" /I..\..\BaseClasses playvideo.cpp

$(OUTDIR)\Jukebox.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\jukebox.res jukebox.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
