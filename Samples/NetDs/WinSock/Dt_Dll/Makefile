!include <disable.mak>

!IF "$(TARGETOS)" == "WIN95"

!include <win32.mak>

all: dt_dll.dll

dt_dll.dll: dt_dll.obj huerror.obj handlers.obj dt_dll.res
	$(link) $(linkdebug) $(dlllflags) \
	-export:WSAPreApiNotify -export:WSAPostApiNotify \
	-out:$*.dll $** $(guilibsdll)
	

.cpp.obj:
    $(cc) $(cdebug) $(cflags) -DSTRICT $(cvarsdll) $*.cpp

dt_dll.res: dt_dll.rc
    $(rc) $(rcflags) $(rcvars)  dt_dll.rc
!ELSE
!MESSAGE Sorry this sample only builds for the Windows 9x Platform
!ENDIF
