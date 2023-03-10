!include <disable.mak>

# Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
TARGETOS=BOTH

# Define APPVER = 4.0 so executable will run on Windows NT 4.0
APPVER=4.0

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>

!if "$(CPU)" == "IA64"
!message Sorry, building this sample for 64bit is not currently supported
!else

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\aremote.exe $(OUTDIR)\arsetup.exe

LINK32_OBJS= \
	$(OUTDIR)\client.obj \
	$(OUTDIR)\server.obj \
	$(OUTDIR)\queue.obj \
	$(OUTDIR)\appclib.obj

LINK32_FLAGS= \
	wappc32.lib wcpic32.lib wincsv32.lib

#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\aremote.exe:  $(OUTDIR) $(OUTDIR)\aremote.obj $(OUTDIR)\aremote.res $(LINK32_OBJS)
    $(link) $(ldebug) $(conlflags) /PDB:$(OUTDIR)\aremote.pdb \
	-out:$(OUTDIR)\aremote.exe $(OUTDIR)\aremote.obj \
	$(LINK32_OBJS) $(OUTDIR)\aremote.res $(conlibsmt) \
	$(LINK32_FLAGS) user32.lib

$(OUTDIR)\arsetup.exe:  $(OUTDIR) $(OUTDIR)\arsetup.obj $(OUTDIR)\arsetup.res
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\arsetup.pdb \
	-out:$(OUTDIR)\arsetup.exe $(OUTDIR)\arsetup.obj \
	$(OUTDIR)\arsetup.res $(guilibs) $(LINK32_FLAGS) 

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

COMP32_FLAGS= -DUNICODE -D_UNICODE

SOURCE=.\aremote.c

$(OUTDIR)\aremote.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(COMP32_FLAGS) $(cvarsmt) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\client.c

$(OUTDIR)\client.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(COMP32_FLAGS) $(cvarsmt) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\server.c

$(OUTDIR)\server.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(COMP32_FLAGS) $(cvarsmt) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\queue.c

$(OUTDIR)\queue.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(COMP32_FLAGS) $(cvarsmt) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\appclib.c

$(OUTDIR)\appclib.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(COMP32_FLAGS) $(cvarsmt) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\arsetup.c

$(OUTDIR)\arsetup.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=.\aremote.rc

$(OUTDIR)\aremote.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\aremote.res $(SOURCE)

SOURCE=.\arsetup.rc

$(OUTDIR)\arsetup.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\arsetup.res $(SOURCE)



#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!endif
