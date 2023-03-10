!include <disable.mak>

# Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
TARGETOS=WINNT

# Define APPVER = 4.0 so executable will run on Windows NT 4.0
APPVER=4.0

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>


!IF "$(CPU)" == "IA64"
!MESSAGE Sorry, currently building this sample for 64bit platform is no supported
!ELSE

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\ntfilter.dll

LINK32_FLAGS= \
	

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- DLL ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for DLL
$(OUTDIR)\ntfilter.dll:  $(OUTDIR) $(OUTDIR)\ntfilter.obj $(OUTDIR)\ntfilter.res
    $(link) $(ldebug) $(dlllflags) /PDB:$(OUTDIR)\ntfilter.pdb \
	-out:$(OUTDIR)\ntfilter.dll $(OUTDIR)\ntfilter.obj \
	$(OUTDIR)\ntfilter.res $(guilibsmt) $(LINK32_FLAGS)  

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

COMP32_FLAGS = 

SOURCE=.\ntfilter.c

$(OUTDIR)\ntfilter.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\ntfilter.obj" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=ntfilter.rc

$(OUTDIR)\ntfilter.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\ntfilter.res $(SOURCE)


#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)


!ENDIF
