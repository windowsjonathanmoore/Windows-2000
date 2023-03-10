!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>



all:	$(OUTDIR) $(OUTDIR)\joystick.exe 

$(OUTDIR)\joystick.exe:	 $(OUTDIR)\Joystick.obj $(OUTDIR)\Joystick.res 
	$(link) $(ldebug) /OUT:$(OUTDIR)\joystick.exe $(guilflags) /PDB:$(OUTDIR)\joystick.pdb /MACHINE:$(CPU) $(OUTDIR)\Joystick.obj $(OUTDIR)\Joystick.res $(ole2libs) dxguid.lib dxerr8.lib dinput8.lib shell32.lib 

$(OUTDIR)\Joystick.obj:	Joystick.cpp
	$(cc) $(cflags) $(cdebug) $(cvars) /Gm /GX /Fp$(OUTDIR)\joystick.pch /YX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" Joystick.cpp

$(OUTDIR)\Joystick.res:	
	 $(rc) $(rcflags) /Fo$(OUTDIR)\joystick.res joystick.rc

        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

clean:
        $(CLEANUP)
