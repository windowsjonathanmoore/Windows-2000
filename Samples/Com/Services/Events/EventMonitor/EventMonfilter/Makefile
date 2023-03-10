!include <disable.mak>

All:
!IFDEF NODEBUG
   nmake /f EventMonFilter.mak CFG="EventMonFilter - Win32 Release MinSize" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f EventMonFilter.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF