



All:
!IF "$(CPU)" == "IA64"
!IFDEF NODEBUG
   nmake /f Framer64.mak CFG="Framer - Win64 Release" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f Framer64.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF
!ELSE
!IFDEF NODEBUG
   nmake /f Framer.mak CFG="Framer - Win32 Release" -nologo /$(MAKEFLAGS) $(makeopts)
!ELSE
   nmake /f Framer.mak -nologo /$(MAKEFLAGS) $(makeopts)
!ENDIF
!ENDIF