!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

!IF !DEFINED(_WMVCore.lib)
!MESSAGE To build this sample, you must install the Microsoft Windows Media Format SDK and obtain a software certificate.  After you obtain the software certificate, build the sample by linking two additional libraries, WMStub.lib and WMVCore.lib.
!ELSE


all:	$(OUTDIR) $(OUTDIR)\ASFCopy.exe 

$(OUTDIR)\ASFCopy.exe:	$(OUTDIR)\asfcopy.obj 
	$(link) $(ldebug) /OUT:$(OUTDIR)\ASFCopy.exe $(conlflags) /PDB:$(OUTDIR)\ASFCopy.pdb /MACHINE:$(CPU) $(OUTDIR)\asfcopy.obj strmiids.lib shell32.lib $(ole2libs) odbc32.lib odbccp32.lib 

$(OUTDIR)\asfcopy.obj:	asfcopy.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /GX /Fp$(OUTDIR)\ASFCopy.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D_CONSOLE /D_MBCS /I. /I..\..\BaseClasses asfcopy.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)

!ENDIF
