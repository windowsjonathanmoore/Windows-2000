!include <disable.mak>

#*************************************************************#
#**                                                         **#
#**                 Microsoft RPC Examples                  **#
#**                   cxhndl Application                    **#
#**        Copyright 1992 - 1999 Microsoft Corporation      **#
#**                                                         **#
#*************************************************************#

!include <Win32.Mak>

!if "$(CPU)" == "i386"
cflags = $(cflags:G3=Gz)
cflags = $(cflags) -D_CRTAPI1=_cdecl -D_CRTAPI2=_cdecl
!else
cflags = $(cflags) -D_CRTAPI1= -D_CRTAPI2=
!endif

all : cxhndlc cxhndls

# Make the cxhndl client
cxhndlc : cxhndlc.exe
cxhndlc.exe : cxhndlc.obj cxhndl_c.obj
    $(link) $(linkdebug) $(conflags) -out:cxhndlc.exe \
      cxhndlc.obj cxhndl_c.obj \
      rpcrt4.lib $(conlibsdll)

# client main program
cxhndlc.obj : cxhndlc.c cxhndl.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

# client stub
cxhndl_c.obj : cxhndl_c.c cxhndl.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

# Make the cxhndl server
cxhndls : cxhndls.exe
cxhndls.exe : cxhndls.obj cxhndlp.obj cxhndl_s.obj
    $(link) $(linkdebug) $(conflags) -out:cxhndls.exe \
      cxhndls.obj cxhndlp.obj cxhndl_s.obj \
      rpcrt4.lib $(conlibsdll)

# server main loop
cxhndls.obj : cxhndls.c cxhndl.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

# remote procedures
cxhndlp.obj : cxhndlp.c cxhndl.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c

# server stub file
cxhndl_s.obj : cxhndl_s.c cxhndl.h
   $(cc) $(cdebug) $(cflags) $(cvarsdll) $*.c


# Stubs and header file from the IDL file
cxhndl.h cxhndl_c.c cxhndl_s.c : cxhndl.idl cxhndl.acf
    midl -oldnames -no_cpp cxhndl.idl

# Clean up everything
cleanall : clean
    -del *.exe

# Clean up everything but the .EXEs
clean :
    -del *.obj
    -del *.map
    -del cxhndl_c.c
    -del cxhndl_s.c
    -del cxhndl.h
