!include <disable.mak>

All:
!IFDEF NODEBUG
   nmake /f account.mak CFG="account - Win32 Release MinSize" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f account.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF