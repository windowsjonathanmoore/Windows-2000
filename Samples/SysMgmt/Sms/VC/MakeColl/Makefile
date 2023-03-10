!include <win32.mak>

!if "$(CPU)" == "IA64"
!message Sorry, this sample is not currently supported on 64bit platforms.
!else

all: $(OUTDIR)\makecoll.exe

LINK32_OBJS= \
	$(OUTDIR)\makecoll.obj \
	$(OUTDIR)\stdpch.obj \
	$(OUTDIR)\wbemsec.obj \
	$(OUTDIR)\SshWbemHelpers.obj

LINK32_LIBS= \
	wbemuuid.lib



#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

$(OUTDIR)\makecoll.exe:  $(OUTDIR) $(LINK32_OBJS)
    $(link) $(ldebug) $(conflags) /PDB:$(OUTDIR)\makecoll.pdb -out:$(OUTDIR)\makecoll.exe $(LINK32_OBJS) $(LINK32_LIBS) $(conlibs)



#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

SOURCE=.\makecoll.cpp
$(OUTDIR)\makecoll.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) /I "..\include" $(cvarsdll) -GX /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=.\stdpch.cpp
$(OUTDIR)\stdpch.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) /I "..\include" $(cvarsdll) -GX /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=..\utility\wbemsec.cpp
$(OUTDIR)\wbemsec.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) /I "..\include" $(cvarsdll) -GX /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)

SOURCE=..\utility\SshWbemHelpers.cpp
$(OUTDIR)\SshWbemHelpers.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(cdebug) $(cflags) /I "..\include" $(cvarsdll) -GX /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(SOURCE)


#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)

!endif