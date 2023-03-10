!include <disable.mak>

Proj = InvokObj

!include <Win32.Mak>

All: $(OUTDIR) $(OUTDIR)\InvokObj.Dll

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

$(OUTDIR)\InvokObj.Obj: InvokObj.cpp
  $(cc) $(cdebug) $(cflags) $(cvarsdll) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" InvokObj.cpp

$(OUTDIR)\InvokObj.Dll: $*.Obj $*.Exp
     $(link) $(linkdebug) $(dlllflags) -base:0x1C000000 -out:$(OUTDIR)\InvokObj.dll  \
      $(OUTDIR)\InvokObj.Obj $(OUTDIR)\InvokObj.Exp  $(guilibsdll) comsupp.lib ole32.lib oleaut32.lib uuid.lib

$(OUTDIR)\InvokObj.Exp: InvokObj.Def InvokObj.Obj
  $(implib) -machine:$(CPU) -nologo -Def:InvokObj.Def -Out:$(OUTDIR)\InvokObj.Lib $(OUTDIR)\InvokObj.Obj

clean:
        $(CLEANUP)

Cleanall:
    -@for %a in (*.obj *.exp InvokObj.dll *.lib *.ncb *.opt *.plg *.tlh *.tli) do del %a

