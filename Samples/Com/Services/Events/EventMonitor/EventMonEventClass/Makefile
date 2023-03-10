!include <disable.mak>

All:
!IFDEF NODEBUG
   nmake /f EventMonEventClass.mak CFG="EventMonEventClass - Win32 Release MinSize" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f EventMonEventClass.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF