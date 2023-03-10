!include <disable.mak>

!if "$(CPU)" == "IA64"
!message Sorry building this sample for 64bit is not currently supported
!else
booksrvr.exe : booksrvr.obj
   link @<<
 booksrvr.obj mqmail.lib mqrt.lib
 kernel32.lib user32.lib advapi32.lib libcmt.lib
 /subsystem:console /machine:$(CPU) /nodefaultlib:libc
<<

booksrvr.obj : booksrvr.c
   cl /c /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" booksrvr.c

!endif
