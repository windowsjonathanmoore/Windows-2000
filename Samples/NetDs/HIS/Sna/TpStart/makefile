!include <disable.mak>

# Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
TARGETOS=BOTH

# Define APPVER = 4.0 so executable will run on Windows NT 4.0
APPVER=4.0

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>


!IF "$(CPU)" == "IA64"
!MESSAGE Sorry, currently building this sample for 64bit platform is no supported
!ELSE

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\tpstart.exe 

LINK32_FLAGS= 


#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\tpstart.exe:  $(OUTDIR) $(OUTDIR)\tpstart.obj $(OUTDIR)\tpstart.res
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\tpstart.pdb \
	-out:$(OUTDIR)\tpstart.exe $(OUTDIR)\tpstart.obj \
	$(OUTDIR)\tpstart.res $(LINK32_FLAGS) $(guilibs) 

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

SOURCE=.\tpstart.c

$(OUTDIR)\tpstart.obj : $(SOURCE) $(OUTDIR) tpstart.h verdlg.h
    $(cc) $(cdebug) $(cflags) $(cvars) /WX \
	/Fo"$(OUTDIR)\\tpstart.obj" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=.\tpstart.rc

$(OUTDIR)\tpstart.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\tpstart.res $(SOURCE)


#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)


!ENDIF

