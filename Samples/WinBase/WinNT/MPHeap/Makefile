!include <disable.mak>

!IF "$(TARGETOS)" == "WINNT"
SEHMAP=TRUE
!include <win32.mak>

!IF "$(TARGETLANG)" == "LANG_JAPANESE"
all: WARN_MSG
!ELSE
all: $(OUTDIR) $(OUTDIR)\mpheap.dll $(OUTDIR)\tmpheap.exe
!ENDIF


WARN_MSG:
 @echo "Warning:  MPHEAP sample works only on Windows NT 4.0"


$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Inference rule for updating the object files
$(OUTDIR)\tmpheap.obj: tmpheap.c
  $(cc) $(cdebug) $(cflags) $(cvars) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" tmpheap.c

$(OUTDIR)\mpheap.obj: mpheap.c
  $(cc) $(cdebug) $(cflags) $(cvarsdll) /WX /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" mpheap.c

# Build rule for EXE
$(OUTDIR)\tmpheap.exe: $(OUTDIR)\tmpheap.obj $(OUTDIR)\mpheap.lib
    $(link) $(linkdebug) $(conlflags) $(conlibs) $** -out:$(OUTDIR)\tmpheap.exe

# linker will build the import library as well
$(OUTDIR)\mpheap.dll: $(OUTDIR)\mpheap.obj
    $(link) $(linkdebug) $(dlllflags) $(conlibsdll) $** -out:$(OUTDIR)\mpheap.dll -def:mpheap.def

#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
