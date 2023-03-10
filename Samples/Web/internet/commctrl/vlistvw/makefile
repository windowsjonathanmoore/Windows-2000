!include <disable.mak>

!include <Win32.Mak>

all: VListVw.Exe

# Update the resource if necessary

VListVw.Res: VListVw.Rc VListVw.h Resource.h
    $(rc) $(rcflags) $(rcvars) VListVw.Rc

# Update the object file if necessary

VListVw.Obj: VListVw.c VListVw.h Resource.h
    $(cc) $(cflags) $(cvars) $(cdebug) VListVw.c

# Update the executable if necessary

VListVw.Exe: VListVw.Obj VListVw.Res
    $(link) $(linkdebug) $(guiflags) -out:VListVw.Exe VListVw.Obj VListVw.Res $(guilibs) ComCtl32.Lib
