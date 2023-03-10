#!include <disable.mak>

# Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
TARGETOS=BOTH

# Define APPVER = 4.0 so executable will run on Windows NT 4.0
APPVER=4.0

!IF !DEFINED(MQS_INC)
!MESSAGE Sorry this sample requires that MQS_INC and MQS_LIB be defined pointing to MQSeries h/lib files
!ELSEIF !DEFINED(MQS_LIB)
!MESSAGE Sorry this sample requires that MQS_INC and MQS_LIB be defined pointing to MQSeries h/lib files
!ELSE

#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>


!IF "$(CPU)" == "IA64"
!MESSAGE Sorry, currently building this sample for 64bit platform is no supported
!ELSE

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\MQSRSend.exe 

LINK32_OBJS= \
	$(OUTDIR)\MQSRSend.obj 

LINK32_FLAGS= \
	user32.lib gdi32.lib winspool.lib \
	comdlg32.lib shell32.lib ole32.lib oleaut32.lib \
	uuid.lib odbc32.lib odbccp32.lib \
	"$(MQS_LIB)\mqic32.lib"

#----- If OUTDIR does not exist, then create directory
"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

  
#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for EXE
$(OUTDIR)\MQSRSend.exe:  $(OUTDIR) $(LINK32_OBJS) $(OUTDIR)\MQSRSend.res
    $(link) $(ldebug) $(conlflags) /PDB:$(OUTDIR)\MQSRSend.pdb \
	-out:$(OUTDIR)\MQSRSend.exe $(LINK32_OBJS) $(OUTDIR)\MQSRSend.res \
	$(conlibs) $(LINK32_FLAGS) 

  
#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

COMP32_FLAGS = /I $(MQS_INC)

SOURCE=.\MQSRSend.c

$(OUTDIR)\MQSRSend.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) $(cvars) $(COMP32_FLAGS) /WX \
	/Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource file
SOURCE=.\MQSRSend.rc

$(OUTDIR)\MQSRSend.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\MQSRSend.res $(SOURCE)



#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)


!ENDIF

!ENDIF

