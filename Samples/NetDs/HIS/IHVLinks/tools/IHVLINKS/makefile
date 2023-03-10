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
all: $(OUTDIR)\IHVLinks.exe

LINK32_OBJS= \
	$(OUTDIR)\IHVLinks.obj \
	$(OUTDIR)\IHVIntro.obj \
	$(OUTDIR)\IHVLinksDlg.obj \
	$(OUTDIR)\IHVWizardSheet.obj \
	$(OUTDIR)\wizstatic.obj \
	$(OUTDIR)\IHVFinish.obj \
	$(OUTDIR)\StdAfx.obj


LINK32_FLAGS= \
	/NODEFAULTLIB:library \
	comctl32.lib \
	oldnames.lib \
	ole32.lib \
	oleaut32.lib \
	olepro32.lib \
	uuid.lib \
	shell32.lib \
	msi.lib \
	version.lib \


#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\IHVLinks.exe:  $(OUTDIR) $(LINK32_OBJS) $(OUTDIR)\IHVLinks.res
    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\IHVLinks.pdb \
	-out:$(OUTDIR)\IHVLinks.exe $(LINK32_OBJS) \
	$(OUTDIR)\IHVLinks.res $(LINK32_FLAGS)  

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

COMP32_FLAGS = -DNLSENABLE -DDBCSENABLE -DASYNCTRACE

SOURCE=.\IHVLinks.cpp

$(OUTDIR)\IHVLinks.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\IHVIntro.cpp

$(OUTDIR)\IHVIntro.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\IHVLinksDlg.cpp

$(OUTDIR)\IHVLinksDlg.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\IHVWizardSheet.cpp

$(OUTDIR)\IHVWizardSheet.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\wizstatic.cpp

$(OUTDIR)\wizstatic.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\IHVFinish.cpp

$(OUTDIR)\IHVFinish.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\StdAfx.cpp

$(OUTDIR)\StdAfx.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvarsmt) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource files
SOURCE=.\IHVLinks.rc

$(OUTDIR)\IHVLinks.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\IHVLinks.res $(SOURCE)


#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)


!ENDIF


