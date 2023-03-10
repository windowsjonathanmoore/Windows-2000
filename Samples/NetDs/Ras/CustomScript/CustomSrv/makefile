!include <disable.mak>


!IF "$(TARGETOS)" == "WINNT"
!include <win32.mak>

all: customsrv.dll

customsrv.obj: customsrv.cpp customsrv.h
    $(cc) $(cdebug) $(cflags) $(cvarsdll) customsrv.cpp

customsrv.res: customsrv.rc
    $(rc) $(rcvars) -r -fo customsrv.res customsrv.rc

customsrv.dll: customsrv.obj customsrv.def customsrv.res
    $(link) $(linkdebug) $(dlllflags) \
    -def:customsrv.def   \
    -out:customsrv.dll    \
    customsrv.obj customsrv.res $(guilibsdll)
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
