!include <disable.mak>

# Nmake macros for building Windows 32-Bit apps

!include <Win32.Mak>

all: mypal.exe

# Update the resource if necessary

mypal.res: mypal.rc mypal.h
    rc -r mypal.rc

# Update the object file if necessary

mypal.obj: mypal.c mypal.h
    $(cc) $(cflags) $(cvars) $(cdebug) mypal.c

# Update the executable file if necessary, and if so, add the resource back in.

mypal.exe: mypal.obj mypal.res mypal.def
    $(link) $(linkdebug) $(guiflags) -out:mypal.exe mypal.obj mypal.res $(guilibs)
