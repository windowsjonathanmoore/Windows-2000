!include <disable.mak>

TARGETOS=BOTH

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\receiver.exe $(OUTDIR)\sender.exe

# Update the resource if necessary

$(OUTDIR)\receiver.res: receiver.rc $(OUTDIR) resource.h
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\receiver.res receiver.rc


# Update the object file if necessary


$(OUTDIR)\receiver.obj : receiver.cpp $(OUTDIR) resource.h
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" receiver.cpp

$(OUTDIR)\sender.obj : sender.cpp $(OUTDIR) 
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" sender.cpp

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Update the executable file if necessary, and if so, add the resource back in.


#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE

LIBS = kernel32.lib user32.lib oldnames.lib  ws2_32.lib mswsock.lib

$(OUTDIR)\receiver.exe:  $(OUTDIR) $(OUTDIR)\receiver.obj $(OUTDIR)\receiver.res
    $(link) $(ldebug) $(guiflags) /PDB:$(OUTDIR)\receiver.pdb -out:$(OUTDIR)\receiver.exe $(OUTDIR)\receiver.obj $(OUTDIR)\receiver.res $(guilibs) comctl32.lib

$(OUTDIR)\sender.exe:  $(OUTDIR) $(OUTDIR)\sender.obj 
    $(link) $(ldebug) $(conflags) /PDB:$(OUTDIR)\sender.pdb -out:$(OUTDIR)\sender.exe $(OUTDIR)\sender.obj $(conlibs) $(LIBS)

clean:
	rd /s /q $(OUTDIR)


