!include <disable.mak>

All:
!IF "$(CPU)" == "IA64"
!IFDEF NODEBUG
   nmake /f VCExplore64.mak CFG="VCExplore - Win64 Release" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f VCExplore64.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF
!ELSE
!IFDEF NODEBUG
   nmake /f VCExplore.mak CFG="VCExplore - Win32 Release" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f VCExplore.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF
!ENDIF