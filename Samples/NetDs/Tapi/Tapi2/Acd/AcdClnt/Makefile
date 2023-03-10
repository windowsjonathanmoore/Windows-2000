!include <disable.mak>

# Define NODEBUG to build ACDSMPL without debugging information.
# Define UNICODE to build ACDSMPL with UNICODE characters.

!IF "$(TARGETOS)" == "WINNT"

!include <Win32.Mak>

!ifdef UNICODE
unicode = -DUNICODE
!else
unicode =
!endif

cflags=$(cflags) -DWIN32_LEAN_AND_MEAN

all: acdclnt.exe

# Update the resource if necessary

acdclnt.res: acdclnt.rc resource.h
    $(rc) $(rcvars) -r acdclnt.rc

# Update the object files if necessary

acdclnt.obj: acdclnt.c resource.h acdclnt.h
    $(cc) $(cdebug) $(cflags) $(cvars) $(unicode) acdclnt.c

# Update the executable file if necessary, and if so, add the resource back in.

acdclnt.exe: acdclnt.obj acdclnt.res
    $(link) $(linkdebug)  $(guiflags) -out:acdclnt.exe\
    acdclnt.obj acdclnt.res\
    version.lib tapi32.lib comctl32.lib $(guilibsmt)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
