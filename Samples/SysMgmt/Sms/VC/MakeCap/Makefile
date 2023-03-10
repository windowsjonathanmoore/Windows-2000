!include <win32.mak>

!if "$(CPU)" == "IA64"
!message Sorry, this sample is not currently supported on 64bit platforms.
!else

all: $(OUTDIR)\makecap.exe

LINK32_OBJS= \
	$(OUTDIR)\makecap.obj \
	$(OUTDIR)\wbemsec.obj

LINK32_LIBS= \
	wbemuuid.lib



#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

$(OUTDIR)\makecap.exe:  $(OUTDIR) $(LINK32_OBJS)
    $(link) $(ldebug) $(conflags) /PDB:$(OUTDIR)\makecap.pdb -out:$(OUTDIR)\makecap.exe $(LINK32_OBJS) $(LINK32_LIBS) $(conlibs)



#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

SOURCE=.\makecap.cpp

$(OUTDIR)\makecap.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) /I "..\include" $(cvarsdll) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=..\utility\wbemsec.cpp

$(OUTDIR)\wbemsec.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) /I "..\include" $(cvarsdll) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)



#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!endif