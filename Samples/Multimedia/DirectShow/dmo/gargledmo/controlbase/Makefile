!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\controlbase.lib 

$(OUTDIR)\controlbase.lib:	 $(OUTDIR) $(OUTDIR)\controlhelp.obj 
	$(link) /lib /OUT:$(OUTDIR)\controlbase.lib /MACHINE:$(CPU) $(OUTDIR)\controlhelp.obj 

$(OUTDIR)\controlhelp.obj:	controlhelp.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\controlbase.pch /YX /GZ /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /D"_LIB" controlhelp.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
