!include <disable.mak>

All:
!IFDEF NODEBUG
   nmake /f EventMonPublisher.mak CFG="EventMonPublisher - Win32 Release" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f EventMonPublisher.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF