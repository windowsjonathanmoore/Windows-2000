#!include <disable.mak>

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
all: $(OUTDIR)\GenSet.dll

LINK32_FLAGS= \
	msi.lib \
	oldnames.lib \
	kernel32.lib \
	user32.lib \
	gdi32.lib \
	comdlg32.lib \
	winspool.lib \
	advapi32.lib \
	shell32.lib \
	netapi32.lib \
	ole32.lib \
	uuid.lib \
	version.lib \
	oleaut32.lib \
	comctl32.lib


#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- DLL ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for DLL
$(OUTDIR)\GenSet.dll:  $(OUTDIR) $(OUTDIR)\GenSet.obj $(OUTDIR)\GenSet.res
    $(link) $(ldebug) $(dlllflags) /PDB:$(OUTDIR)\GenSet.pdb \
	-out:$(OUTDIR)\GenSet.dll $(OUTDIR)\GenSet.obj \
	$(OUTDIR)\GenSet.res $(LINK32_FLAGS)  

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

COMP32_FLAGS = -DWIN32 -D_WINDOWS -D_WINDLL -D_USRDLL -DHILINKS -DUNICODE -D_UNICODE

SOURCE=.\GenSet.cpp

$(OUTDIR)\GenSet.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\GenSet.obj" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=.\GenSet.rc

$(OUTDIR)\GenSet.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\GenSet.res $(SOURCE)


#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)


!ENDIF

