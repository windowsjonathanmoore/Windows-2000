
booksrvr.exe : booksrvr.obj
   link @<<
 booksrvr.obj mqmail.lib mqrt.lib
 kernel32.lib user32.lib advapi32.lib libcmt.lib
 /subsystem:console /nodefaultlib:libc
<<

booksrvr.obj : booksrvr.c
   cl /c /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" booksrvr.c
