






All:
!IF "$(CPU)" == "IA64"
!IFDEF NODEBUG
   nmake /f ps64.mak CFG="ps - Win64 Release" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f ps64.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF
!ELSE
!IFDEF NODEBUG
   nmake /f ps.mak CFG="ps - Win32 Release" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f ps.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF
!ENDIF