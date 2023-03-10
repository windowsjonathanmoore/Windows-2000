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
all: $(OUTDIR)\wrui3270.exe

LINK32_FLAGS= \
	winrui32.lib wincsv32.lib fmistr32.lib

#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\wrui3270.exe:  $(OUTDIR) $(OUTDIR)\rui3270.obj $(OUTDIR)\wrui3270.res
    $(link) $(ldebug) $(conlflags) /PDB:$(OUTDIR)\wrui3270.pdb \
	-out:$(OUTDIR)\wrui3270.exe $(OUTDIR)\rui3270.obj \
	$(OUTDIR)\wrui3270.res $(LINK32_FLAGS) $(conlibsmt)  

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

SOURCE=..\rui3270.c

$(OUTDIR)\rui3270.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX \
	/Fo"$(OUTDIR)\\rui3270.obj" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=.\wrui3270.rc

$(OUTDIR)\wrui3270.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\wrui3270.res $(SOURCE)


#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)


!ENDIF
