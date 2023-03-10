!include <win32.mak>

!if "$(CPU)" == "IA64"
!message Sorry, this sample is not currently supported on 64bit platforms.
!else

all: $(OUTDIR)\clistat.exe

LINK32_OBJS= \
	$(OUTDIR)\clistat.obj


#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

$(OUTDIR)\clistat.exe:  $(OUTDIR) $(LINK32_OBJS)
    $(link) $(ldebug) $(conflags) /PDB:$(OUTDIR)\clistat.pdb -out:$(OUTDIR)\clistat.exe $(LINK32_OBJS) $(conlibs)



#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

SOURCE=.\clistat.cpp

$(OUTDIR)\clistat.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) /I "..\include" $(cvarsdll) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)



#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!endif