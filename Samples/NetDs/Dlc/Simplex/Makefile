!include <disable.mak>

# Some nmake macros for Win32 apps development

!IF "$(TARGETOS)" == "WINNT"
SEHMAP=TRUE

!include <Win32.Mak>

# application specific C defines

cf = -DDBG

all: simplex.exe

# Update the object file if necessary

simplex.obj: simplex.c
    $(cc) $(cflags) $(cvars) $(cdebug) $(cf) simplex.c

dlcdebug.obj: dlcdebug.c dlcdebug.h 
    $(cc) $(cflags) $(cvars) $(cdebug) $(cf) dlcdebug.c

# Update the executable file if necessary

simplex.exe: simplex.obj dlcdebug.obj
    $(link) $(linkdebug) $(conflags) -out:simplex.exe simplex.obj dlcdebug.obj $(conlibs) dlcapi.lib
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
