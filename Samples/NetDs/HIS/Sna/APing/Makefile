!include <disable.mak>
# Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
TARGETOS=BOTH

# Define APPVER = 4.0 so executable will run on Windows NT 4.0
APPVER=4.0

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>

!if "$(CPU)" == "IA64"
!message Sorry, currently building this sample for 64bit platform is no supported
!else

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\aping.exe $(OUTDIR)\apingd.exe

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
$(OUTDIR)\aping.exe:  $(OUTDIR) $(OUTDIR)\aping.obj $(LINK32_OBJS) $(OUTDIR)\aping.res
    $(link) $(ldebug) $(conlflags) /PDB:$(OUTDIR)\aping.pdb \
	-out:$(OUTDIR)\aping.exe $(OUTDIR)\aping.obj $(LINK32_OBJS) \
	$(OUTDIR)\aping.res $(conlibs) $(LINK32_FLAGS) 

$(OUTDIR)\apingd.exe:  $(OUTDIR) $(OUTDIR)\apingd.obj $(LINK32_OBJS) $(OUTDIR)\apingd.res
    $(link) $(ldebug) $(conlflags) /PDB:$(OUTDIR)\apingd.pdb \
	-out:$(OUTDIR)\apingd.exe $(OUTDIR)\apingd.obj $(LINK32_OBJS) \
	$(OUTDIR)\apingd.res $(conlibs) $(LINK32_FLAGS) 

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

COMP32_FLAGS = /I $(SHARED)

SOURCE=.\aping.c

$(OUTDIR)\aping.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\apingd.c

$(OUTDIR)\apingd.obj : $(SOURCE) $(OUTDIR)
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
SOURCE=.\aping.rc

$(OUTDIR)\aping.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\aping.res $(SOURCE)

SOURCE=.\apingd.rc

$(OUTDIR)\apingd.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\apingd.res $(SOURCE)



#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!endif
