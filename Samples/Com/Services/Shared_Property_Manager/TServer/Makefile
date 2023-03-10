!include <disable.mak>

All:
!IFDEF NODEBUG
   nmake /f tServer.mak CFG="tServer - Win32 Release MinDependency" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f tServer.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF