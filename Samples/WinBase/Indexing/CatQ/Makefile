!include <disable.mak>

# Nmake macros for building Windows 32-Bit apps

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

# define project specific macros, PROJNAME is simply a name for our executable,
#  OBJFILES are the object files resulting from our source code files, and
#  EXTRA_LIBS are the libraries provided with the compiler or SDK.

PROJNAME = CATQ
all: $(OUTDIR) $(OUTDIR)\$(PROJNAME).exe

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

OBJFILES = $(OUTDIR)\main.obj $(OUTDIR)\service.obj $(OUTDIR)\ciquery.obj $(OUTDIR)\statbar.obj $(OUTDIR)\progress.obj
EXTRA_LIBS = oledb.lib ntquery.lib shell32.lib comctl32.lib pdh.lib

#define the file to be built by default


# Update the resource if necessary
$(OUTDIR)\res.res: res.rc $(PROJNAME).h
    $(rc) $(rcvars) -r -fo $(OUTDIR)\res.res res.rc


# Inference rule for updating the object files
#  This is all standard, except that we are explicitly defining UNICODE
.c{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) $(cvars) -DUNICODE /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

.cxx{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) $(cvars) -DUNICODE /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**


# Update the executable file if necessary, and if so, add the resource back in.
$(OUTDIR)\$(PROJNAME).exe: $(OBJFILES) $(OUTDIR)\res.res
    $(link) $(linkdebug) $(guiflags) -out:$(OUTDIR)\$(PROJNAME).exe $** $(olelibs) $(EXTRA_LIBS)


# Clean up everything except .exe file
clean:
        $(CLEANUP)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
