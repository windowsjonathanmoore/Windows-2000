!include <disable.mak>

All:
!IFDEF NODEBUG
   nmake /f EventMonSubscriber.mak CFG="EventMonSubscriber - Win32 Release MinSize" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f EventMonSubscriber.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF