!include <disable.mak>
# Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
TARGETOS=BOTH

# Define APPVER = 4.0 so executable will run on Windows NT 4.0
APPVER=4.0

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>


!if "$(CPU)" == "IA64"
!message Sorry, building this sample for 64 bit is not supported.
!else

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\sendtp.exe $(OUTDIR)\recvtp.exe

LINK32_FLAGS= \
	wappc32.lib wincsv32.lib 

#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\sendtp.exe:  $(OUTDIR) $(OUTDIR)\sendtp.obj $(OUTDIR)\sendtp.res
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\sendtp.pdb \
	-out:$(OUTDIR)\sendtp.exe $(OUTDIR)\sendtp.obj \
	$(OUTDIR)\sendtp.res $(LINK32_FLAGS) $(guilibs) 

$(OUTDIR)\recvtp.exe:  $(OUTDIR) $(OUTDIR)\recvtp.obj $(OUTDIR)\recvtp.res
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\recvtp.pdb \
	-out:$(OUTDIR)\recvtp.exe $(OUTDIR)\recvtp.obj \
	$(OUTDIR)\recvtp.res $(LINK32_FLAGS) $(guilibs)  

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

SOURCE=.\sendrecv.c

$(OUTDIR)\recvtp.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) -DRECVTP /WX \
	/Fo"$(OUTDIR)\\recvtp.obj" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\sendrecv.c

$(OUTDIR)\sendtp.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) -DSENDTP /WX \
	/Fo"$(OUTDIR)\\sendtp.obj" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=.\recvtp.rc

$(OUTDIR)\recvtp.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\recvtp.res $(SOURCE)

SOURCE=.\sendtp.rc

$(OUTDIR)\sendtp.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\sendtp.res $(SOURCE)




#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!endif
