!include <disable.mak>

# Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
TARGETOS=BOTH

# Define APPVER = 4.0 so executable will run on Windows NT 4.0
APPVER=4.0

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>


!if "$(CPU)" == "IA64"
!message Sorry, building this sample for 64bit is not currently supported.
!else

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\arexec.exe $(OUTDIR)\arexecd.exe

LINK32_OBJS= \
	$(OUTDIR)\cpicport.obj $(OUTDIR)\cpicerr.obj \
	$(OUTDIR)\cpicinit.obj $(OUTDIR)\getopt.obj

LINK32_FLAGS= \
	wappc32.lib wcpic32.lib

SHARED = ..\shared

#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\arexec.exe:  $(OUTDIR) $(OUTDIR)\arexec.obj $(LINK32_OBJS) $(OUTDIR)\arexec.res
    $(link) $(ldebug) $(conlflags) /PDB:$(OUTDIR)\arexec.pdb \
	-out:$(OUTDIR)\arexec.exe $(OUTDIR)\arexec.obj $(LINK32_OBJS) \
	$(OUTDIR)\arexec.res $(conlibs) $(LINK32_FLAGS) 

$(OUTDIR)\arexecd.exe:  $(OUTDIR) $(OUTDIR)\arexecd.obj $(LINK32_OBJS) $(OUTDIR)\arexecd.res
    $(link) $(ldebug) $(conlflags) /PDB:$(OUTDIR)\arexecd.pdb \
	-out:$(OUTDIR)\arexecd.exe $(OUTDIR)\arexecd.obj $(LINK32_OBJS) \
	$(OUTDIR)\arexecd.res $(conlibs) $(LINK32_FLAGS) 


  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

COMP32_FLAGS = /I $(SHARED)

SOURCE=.\arexec.c

$(OUTDIR)\arexec.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\arexecd.c

$(OUTDIR)\arexecd.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE= $(SHARED)\cpicport.c

$(OUTDIR)\cpicport.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE= $(SHARED)\cpicerr.c

$(OUTDIR)\cpicerr.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE= $(SHARED)\cpicinit.c

$(OUTDIR)\cpicinit.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE= $(SHARED)\getopt.c

$(OUTDIR)\getopt.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=.\arexec.rc

$(OUTDIR)\arexec.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\arexec.res $(SOURCE)

SOURCE=.\arexecd.rc

$(OUTDIR)\arexecd.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\arexecd.res $(SOURCE)



#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)


!endif
