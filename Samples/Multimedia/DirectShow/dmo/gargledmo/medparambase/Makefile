!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\medparambase.lib 

$(OUTDIR)\medparambase.lib:	 $(OUTDIR) $(OUTDIR)\alist.obj $(OUTDIR)\param.obj 
	$(link) /lib /OUT:$(OUTDIR)\medparambase.lib /MACHINE:$(CPU) $(OUTDIR)\alist.obj $(OUTDIR)\param.obj 

$(OUTDIR)\alist.obj:	alist.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\medparambase.pch /YX /GZ /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /D"_LIB" /I..\..\..\..\..\..\include alist.cpp

$(OUTDIR)\param.obj:	param.cpp
	$(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /GX /Fp$(OUTDIR)\medparambase.pch /YX /GZ /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /D"_MBCS" /D"_LIB" /I..\..\..\..\..\..\include param.cpp

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
