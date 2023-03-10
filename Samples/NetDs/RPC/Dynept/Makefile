!include <disable.mak>

#*************************************************************#
#**                                                         **#
#**                 Microsoft RPC Examples                  **#
#**                   dynept Application                    **#
#**       Copyright 1992 - 1999 Microsoft Corporation       **#
#**                                                         **#
#*************************************************************#

!include <Win32.Mak>

!if "$(CPU)" == "i386"
cflags = $(cflags) -D_CRTAPI1=_cdecl -D_CRTAPI2=_cdecl
!else
cflags = $(cflags) -D_CRTAPI1= -D_CRTAPI2=
!endif


all : dyneptc dynepts

# Make the client side application dyneptc
dyneptc : dyneptc.exe
dyneptc.exe : dyneptc.obj dynept_c.obj
    $(link) $(linkdebug) $(conflags) -out:dyneptc.exe \
      dyneptc.obj dynept_c.obj \
      rpcrt4.lib $(conlibsdll)

# dyneptc main program
dyneptc.obj : dyneptc.c dynept.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

# dyneptc stub
dynept_c.obj : dynept_c.c dynept.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c


# Make the server side application
dynepts : dynepts.exe
dynepts.exe : dynepts.obj dyneptp.obj dynept_s.obj
    $(link) $(linkdebug) $(conflags) -out:dynepts.exe \
      dynepts.obj dynept_s.obj dyneptp.obj \
      rpcrt4.lib $(conlibsdll)

# dynept server main program
dynepts.obj : dynepts.c dynept.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

# remote procedures
dyneptp.obj : dyneptp.c dynept.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

# dynepts stub file
dynept_s.obj : dynept_s.c dynept.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

# Stubs and header file from the IDL file
dynept.h dynept_c.c dynept_s.c : dynept.idl dynept.acf
    midl -oldnames -cpp_cmd $(cc) -cpp_opt "-E" dynept.idl

# Clean up everything
cleanall : clean
    -del *.exe

# Clean up everything but the .EXEs
clean :
    -del *.obj
    -del *.map
    -del dynept_c.c
    -del dynept_s.c
    -del dynept.h
