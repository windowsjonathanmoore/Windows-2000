!include <disable.mak>

#*************************************************************#
#**                                                         **#
#**                 Microsoft RPC Examples                  **#
#**                    yield Application                    **#
#**          Copyright 1991 - 1998 Microsoft Corporation    **#
#**                                                         **#
#*************************************************************#

!include <Win32.Mak>

!if "$(CPU)" == "i386"
cflags = $(cflags) -D_CRTAPI1=_cdecl -D_CRTAPI2=_cdecl
!else
cflags = $(cflags) -D_CRTAPI1= -D_CRTAPI2=
!endif

all: yields

# Make the yield server
yields : yields.exe
yields.exe : yields.obj yieldp.obj yield_s.obj
    $(link) $(linkdebug) $(conflags) -out:yields.exe -map:yields.map \
      yields.obj yieldp.obj yield_s.obj \
      rpcrt4.lib $(conlibsdll)

yields.obj : yields.c yield.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

yieldp.obj : yieldp.c yield.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

yield_s.obj : yield_s.c yield.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

# Make the stubs source
yield.h yield_s.c : yield.idl yield.acf
    midl -oldnames -cpp_cmd $(cc) -cpp_opt "-E" yield.idl

# Clean up everything
cleanall : clean
    -del *.exe

# Clean up everything but the .EXEs
clean :
    -del *.obj
    -del *.map
    -del yield_s.c
    -del yield.h
