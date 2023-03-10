!include <win32.mak>

!if "$(CPU)" == "IA64"
!message Sorry, this sample is not currently supported on 64bit platforms.
!else

all: $(OUTDIR)\makeddr.exe

LINK32_OBJS= \
	$(OUTDIR)\makeddr.obj

LINK32_LIBS= \
	..\utility\SMSRsGen.lib


#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

$(OUTDIR)\makeddr.exe:  $(OUTDIR) $(LINK32_OBJS)
    $(link) $(ldebug) $(conflags) /PDB:$(OUTDIR)\makeddr.pdb -out:$(OUTDIR)\makeddr.exe $(LINK32_OBJS) $(LINK32_LIBS) $(conlibs)



#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

SOURCE=.\makeddr.cpp

$(OUTDIR)\makeddr.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) /I "..\include" $(cvarsdll) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)



#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!endif