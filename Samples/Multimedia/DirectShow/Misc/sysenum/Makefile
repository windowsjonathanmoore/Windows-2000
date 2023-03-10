!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

!ifdef NODEBUG
STRMBASE = strmbase.lib
!else
STRMBASE = strmbasd.lib
cflags=$(cflags) /DDEBUG
!endif

all:	$(OUTDIR) $(OUTDIR)\SysEnum.exe 

$(OUTDIR)\SysEnum.exe:	$(OUTDIR)\StdAfx.obj $(OUTDIR)\SysEnum.obj $(OUTDIR)\SysEnumDlg.obj $(OUTDIR)\SysEnum.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\SysEnum.exe $(guilflags) /PDB:$(OUTDIR)\SysEnum.pdb /MACHINE:$(CPU) $(OUTDIR)\StdAfx.obj $(OUTDIR)\SysEnum.obj $(OUTDIR)\SysEnumDlg.obj $(OUTDIR)\SysEnum.res strmiids.lib 

$(OUTDIR)\StdAfx.obj:	StdAfx.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Yc"Stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_AFXDLL /D_MBCS /I..\..\BaseClasses StdAfx.cpp

$(OUTDIR)\SysEnum.obj:	SysEnum.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Yu"Stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_AFXDLL" /D"_MBCS" /I..\..\BaseClasses SysEnum.cpp

$(OUTDIR)\SysEnumDlg.obj:	SysEnumDlg.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /GX /Yu"Stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"WIN32" /D"_DEBUG" /D"_WINDOWS" /D"_AFXDLL" /D"_MBCS" /I..\..\BaseClasses SysEnumDlg.cpp

$(OUTDIR)\SysEnum.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\sysenum.res sysenum.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
