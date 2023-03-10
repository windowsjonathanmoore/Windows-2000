!include <disable.mak>

TARGETOS=BOTH

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\ping.exe 

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)
    
SOURCE=.\ping.c

$(OUTDIR)\ping.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsdll) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\ping.exe:  $(OUTDIR) $(OUTDIR)\ping.obj
    $(link) $(ldebug) $(conflags) /PDB:$(OUTDIR)\ping.pdb -out:$(OUTDIR)\ping.exe $(OUTDIR)\ping.obj user32.lib ws2_32.lib

#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)
