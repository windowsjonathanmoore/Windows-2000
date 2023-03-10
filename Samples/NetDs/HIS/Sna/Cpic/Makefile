!include <disable.mak>

# Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
TARGETOS=BOTH

# Define APPVER = 4.0 so executable will run on Windows NT 4.0
APPVER=4.0

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>


!if "$(CPU)" == "IA64"
!message Sorry building this sample for 64bit is not currently supported.
!else

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\cpicsend.exe $(OUTDIR)\cpicrecv.exe

LINK32_FLAGS= \
	wcpic32.lib 

#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\cpicrecv.exe:  $(OUTDIR) $(OUTDIR)\cpicrecv.obj $(OUTDIR)\cpicrecv.res
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\cpicrecv.pdb \
	-out:$(OUTDIR)\cpicrecv.exe $(OUTDIR)\cpicrecv.obj \
	$(OUTDIR)\cpicrecv.res $(LINK32_FLAGS) $(guilibs) 

$(OUTDIR)\cpicsend.exe:  $(OUTDIR) $(OUTDIR)\cpicsend.obj $(OUTDIR)\cpicsend.res
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\cpicsend.pdb \
	-out:$(OUTDIR)\cpicsend.exe $(OUTDIR)\cpicsend.obj \
	$(OUTDIR)\cpicsend.res $(LINK32_FLAGS) $(guilibs) 


  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

SOURCE=.\cpicsr.c

$(OUTDIR)\cpicrecv.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) -DCPICRECV \
	/Fo"$(OUTDIR)\\cpicrecv.obj" /Fd"$(OUTDIR)\\" $(SOURCE)


SOURCE=.\cpicsr.c

$(OUTDIR)\cpicsend.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) -DCPICSEND \
	/Fo"$(OUTDIR)\\cpicsend.obj" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=.\cpicrecv.rc

$(OUTDIR)\cpicrecv.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\cpicrecv.res $(SOURCE)


SOURCE=.\cpicsend.rc

$(OUTDIR)\cpicsend.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\cpicsend.res $(SOURCE)



#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!endif
