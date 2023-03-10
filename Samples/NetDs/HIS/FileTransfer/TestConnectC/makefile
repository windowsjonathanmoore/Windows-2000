#!include <disable.mak>

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
all: $(OUTDIR)\TestAppC.exe

LINK32_OBJS= \
	$(OUTDIR)\eigfiletransferctl.obj \
	$(OUTDIR)\StdAfx.obj \
	$(OUTDIR)\TestAppC.obj \
	$(OUTDIR)\TestAppCDlg.obj \


LINK32_FLAGS= \


#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\TestAppC.exe:  $(OUTDIR) $(LINK32_OBJS) $(OUTDIR)\TestAppC.res
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\TestAppC.pdb \
	-out:$(OUTDIR)\TestAppC.exe $(LINK32_OBJS) \
	$(OUTDIR)\TestAppC.res $(guilibsmt) $(LINK32_FLAGS) 

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

COMP32_FLAGS = -GX

SOURCE=.\eigfiletransferctl.cpp

$(OUTDIR)\eigfiletransferctl.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE= .\StdAfx.cpp

$(OUTDIR)\stdAfx.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\TestAppC.cpp

$(OUTDIR)\TestAppC.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE= .\TestAppCDlg.cpp

$(OUTDIR)\TestAppCDlg.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=.\TestAppC.rc

$(OUTDIR)\TestAppC.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\TestAppC.res $(SOURCE)



#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)


!ENDIF

