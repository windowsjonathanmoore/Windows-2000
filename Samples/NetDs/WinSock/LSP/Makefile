!include <disable.mak>

TARGETOS=BOTH
#----- Include the PSDK's WIN32.MAK to pick up defines------------------------------------
!include <win32.mak>

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------

.cpp{$(OUTDIR)}.obj:	
        $(cc) $(cdebug) $(cflags) -DFD_SETSIZE=1024 $(cvarsmt) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

DLL_OBJS = $(OUTDIR)\spi.obj        \
           $(OUTDIR)\extension.obj  \
           $(OUTDIR)\overlap.obj    \
           $(OUTDIR)\provider.obj   \
           $(OUTDIR)\sockinfo.obj   \
           $(OUTDIR)\asyncselect.obj

INST_OBJS= $(OUTDIR)\instlsp.obj \
           $(OUTDIR)\provider.obj

all: $(OUTDIR)\lsp.dll $(OUTDIR)\instlsp.exe

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

#--------------------- DLL ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# Build rule for DLL
$(OUTDIR)\lsp.dll: $(OUTDIR) $(DLL_OBJS)
	$(link) $(linkdebug) $(dlllflags) -map -def:lsp.def \
	-out:$*.dll $(DLL_OBJS) -pdb:$*.pdb -pdbtype:sept $(guilibsdll) ws2_32.lib
        copy $*.dll %SYSTEMROOT%\System32

$(OUTDIR)/instlsp.exe: $(OUTDIR) $(INST_OBJS)
    $(link) $(linkdebug) $(conlflags) -out:$*.exe $(INST_OBJS) \
        $(conlibs) sporder.lib ws2_32.lib  rpcrt4.lib

clean:
     $(CLEANUP)