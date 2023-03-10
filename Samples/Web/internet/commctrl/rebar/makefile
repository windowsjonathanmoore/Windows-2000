!include <disable.mak>

!include <Win32.Mak>

all: Rebar.Exe

# Update the resource if necessary

Rebar.Res: Rebar.Rc Resource.h
    $(rc) $(rcflags) $(rcvars) Rebar.Rc

# Update the object file if necessary

Rebar.Obj: Rebar.c Resource.h
    $(cc) $(cflags) $(cvars) $(cdebug) Rebar.c

# Update the executable if necessary

Rebar.Exe: Rebar.Obj Rebar.Res
    $(link) $(linkdebug) $(guiflags) -out:Rebar.Exe Rebar.Obj Rebar.Res $(guilibs) ComCtl32.Lib
