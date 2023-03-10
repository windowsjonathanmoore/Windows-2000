!include <disable.mak>

# Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
TARGETOS=BOTH

# Define APPVER = 4.0 so executable will run on Windows NT 4.0
APPVER=4.0

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>


!if "$(CPU)" == "IA64"
!message Sorry building this sample for 64bit platforms is not currently supported.
!else

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\mrcv.exe $(OUTDIR)\mrcvio.exe $(OUTDIR)\msend.exe $(OUTDIR)\msendrcv.exe

LINK32_FLAGS= \
	wappc32.lib wincsv32.lib 

#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\mrcv.exe:  $(OUTDIR) $(OUTDIR)\mrcv.obj $(OUTDIR)\mrcv.res mrcv.h
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\mrcv.pdb \
	-out:$(OUTDIR)\mrcv.exe $(OUTDIR)\mrcv.obj \
	$(OUTDIR)\mrcv.res $(LINK32_FLAGS) $(guilibsmt)  

$(OUTDIR)\mrcvio.exe:  $(OUTDIR) $(OUTDIR)\mrcvio.obj $(OUTDIR)\mrcvio.res mrcvio.h
    $(link) $(ldebug) $(conlflags) /PDB:$(OUTDIR)\mrcvio.pdb \
	-out:$(OUTDIR)\mrcvio.exe $(OUTDIR)\mrcvio.obj \
	$(OUTDIR)\mrcvio.res $(LINK32_FLAGS) $(conlibsmt)  

$(OUTDIR)\msend.exe:  $(OUTDIR) $(OUTDIR)\msend.obj $(OUTDIR)\msend.res msend.h
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\msend.pdb \
	-out:$(OUTDIR)\msend.exe $(OUTDIR)\msend.obj \
	$(OUTDIR)\msend.res $(LINK32_FLAGS) $(guilibsmt) 

$(OUTDIR)\msendrcv.exe:  $(OUTDIR) $(OUTDIR)\msendrcv.obj $(OUTDIR)\msendrcv.res msendrcv.h
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\msendrcv.pdb \
	-out:$(OUTDIR)\msendrcv.exe $(OUTDIR)\msendrcv.obj \
	$(OUTDIR)\msendrcv.res $(LINK32_FLAGS) $(guilibsmt) 

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

SOURCE=.\mrcv.c

$(OUTDIR)\mrcv.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX \
	/Fo"$(OUTDIR)\\mrcv.obj" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\mrcvio.c

$(OUTDIR)\mrcvio.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX \
	/Fo"$(OUTDIR)\\mrcvio.obj" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\msend.c

$(OUTDIR)\msend.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX \
	/Fo"$(OUTDIR)\\msend.obj" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\msendrcv.c

$(OUTDIR)\msendrcv.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX \
	/Fo"$(OUTDIR)\\msendrcv.obj" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=.\mrcv.rc

$(OUTDIR)\mrcv.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\mrcv.res $(SOURCE)

SOURCE=.\mrcvio.rc

$(OUTDIR)\mrcvio.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\mrcvio.res $(SOURCE)

SOURCE=.\msend.rc

$(OUTDIR)\msend.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\msend.res $(SOURCE)

SOURCE=.\msendrcv.rc

$(OUTDIR)\msendrcv.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\msendrcv.res $(SOURCE)


#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!endif
