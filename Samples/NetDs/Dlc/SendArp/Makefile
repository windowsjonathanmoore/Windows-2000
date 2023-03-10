!include <disable.mak>

# Some nmake macros for Win32 apps development

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

# application specific C defines

cf = -DDBG 

all: SendArp.exe

# Update the object file if necessary

sendarp.obj: sendarp.c
    $(cc) $(cflags) $(cvars) $(cdebug) $(cf) sendarp.c

# Update the executable file if necessary

SendArp.exe: sendarp.obj 
    $(link) $(ldebug) $(conlflags) -out:sendarp.exe sendarp.obj $(conlibs) dlcapi.lib ws2_32.lib
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
