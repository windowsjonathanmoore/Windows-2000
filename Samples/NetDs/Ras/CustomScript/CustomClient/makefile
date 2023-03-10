!include <disable.mak>

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>

LIBS = kernel32.lib user32.lib rasapi32.lib rasdlg.lib 

all: custom.dll

custom.obj: custom.c 
    $(cc) $(cdebug) $(cflags) $(cvarsdll) -DUNICODE -D_UNICODE custom.c

custom.res: custom.rc
    $(rc) $(rcvars) -r -fo custom.res custom.rc

custom.dll: custom.obj custom.def custom.res
    $(link) $(linkdebug) $(dlllflags) \
    -def:custom.def   \
    -out:custom.dll    \
    custom.obj custom.res $(guilibsdll)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
