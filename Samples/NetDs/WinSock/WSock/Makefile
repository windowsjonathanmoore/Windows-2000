!include <disable.mak>

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>

!IF "$(TARGETOS)" == "WINNT"

all: $(OUTDIR)\wsock.exe

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)
    
#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource file
SOURCE=.\wsock.rc

$(OUTDIR)\wsock.res: $(SOURCE) $(OUTDIR) wsock.dlg wsock.h
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\wsock.res $(SOURCE)

#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

SOURCE=.\wsock.c

$(OUTDIR)\wsock.obj : $(SOURCE) $(OUTDIR) wsock.h
    $(cc) $(cdebug) $(cflags) $(cvarsdll) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\dialogs.c

$(OUTDIR)\dialogs.obj : $(SOURCE) $(OUTDIR) wsock.h
    $(cc) $(cdebug) $(cflags) $(cvarsdll) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\wsock.exe:  $(OUTDIR) $(OUTDIR)\wsock.obj $(OUTDIR)\dialogs.obj $(OUTDIR)\wsock.res wsock.def
    $(link) $(ldebug) $(guiflags) /PDB:$(OUTDIR)\wsock.pdb -out:$(OUTDIR)\wsock.exe $(OUTDIR)\wsock.obj $(OUTDIR)\dialogs.obj $(OUTDIR)\wsock.res $(guilibsmt)


#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
