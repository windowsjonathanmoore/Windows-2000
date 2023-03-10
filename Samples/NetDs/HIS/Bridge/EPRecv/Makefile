#!include <disable.mak>

# Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
TARGETOS=BOTH

# Define APPVER = 4.0 so executable will run on Windows NT 4.0
APPVER=4.0

!IF !DEFINED(MQS_INC)
!MESSAGE Sorry this sample requires that MQS_INC be defined pointing to MQSeries header files
!ELSE

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>


!IF "$(CPU)" == "IA64"
!MESSAGE Sorry, currently building this sample for 64bit platform is no supported
!ELSE

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\EPRecv.exe 

LINK32_OBJS= \
	$(OUTDIR)\EPRecv.obj 

LINK32_FLAGS= \
	user32.lib gdi32.lib winspool.lib \
	comdlg32.lib shell32.lib ole32.lib oleaut32.lib \
	uuid.lib odbc32.lib odbccp32.lib msmqep.lib mqrt.lib

#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\EPRecv.exe:  $(OUTDIR) $(LINK32_OBJS) $(OUTDIR)\EPRecv.res
    $(link) $(ldebug) $(conlflags) /PDB:$(OUTDIR)\EPRecv.pdb \
	-out:$(OUTDIR)\EPRecv.exe $(LINK32_OBJS) $(OUTDIR)\EPRecv.res \
	$(conlibs) $(LINK32_FLAGS) 

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

COMP32_FLAGS = /I $(MQS_INC)

SOURCE=.\EPRecv.c

$(OUTDIR)\EPRecv.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource file
SOURCE=.\EPRecv.rc

$(OUTDIR)\EPRecv.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\EPRecv.res $(SOURCE)



#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!ENDIF


!ENDIF

