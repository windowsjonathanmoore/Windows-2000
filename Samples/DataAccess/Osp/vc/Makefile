!include <disable.mak>

# Nmake macros for building Win32 apps
!include <win32.mak>

PROJ = SampleOSProvider

all: $(PROJ).dll

# Define project specific macros
PROJ_OBJS  = Common.obj MyClassFactory.obj MyDataSource.obj MyOSPObject.obj
EXTRA_LIBS = Ole32.Lib OleAut32.Lib
RC_FILE    = SampleOSP


# Inference rule for updating the object files
.c.obj:
  $(cc) $(cdebug) $(cflags) $(cvars) $*.c

# Build rule for resource file
$(RC_FILE).res: $(RC_FILE).rc
    $(rc) $(rcflags) $(rcvars) /fo $(RC_FILE).res $(RC_FILE).rc

# Build rule for DLL
$(PROJ).DLL: $(BASE_OBJS) $(PROJ_OBJS) $(RC_FILE).res
    $(link) $(linkdebug) $(dlllflags) \
    $(PROJ_OBJS) $(RC_FILE).res  $(guilibsdll) $(EXTRA_LIBS) \
    -base:0x1C000000  \
    -out:$(PROJ).dll $(MAPFILE)


# Rules for cleaning out those old files
clean:
    del *.bak *.pdb *.obj *.res *.exp *.map *.sbr *.bsc $(PROJ).DLL
