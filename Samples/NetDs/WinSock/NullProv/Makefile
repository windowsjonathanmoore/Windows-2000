!include <disable.mak>

!include <win32.mak>

all: $(OUTDIR) $(OUTDIR)\srtest.exe $(OUTDIR)\nullprov.dll

$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

$(OUTDIR)\srtest.obj:
  $(cc) $(cdebug) $(cflags) $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" srtest.cpp

$(OUTDIR)\nullprov.obj:
  $(cc) $(cdebug) $(cflags) $(cvars) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" nullprov.cpp

$(OUTDIR)\srtest.exe: $(OUTDIR)\srtest.obj
    $(link) $(ldebug) -out:$*.exe $** $(conlibs) ws2_32.lib 


nullprov.lib: nullprov.obj nullprov.def
    $(implib) -machine:$(CPU) -def:nullprov.def -out:$(OUTDIR)\nullprov.lib

$(OUTDIR)\nullprov.dll: $(OUTDIR)\nullprov.obj
    $(link) $(linkdebug) $(dlllflags) \
      $** -out:$(OUTDIR)\nullprov.dll -def:nullprov.def \
      $(conlibsdll) ws2_32.lib

clean:
        $(CLEANUP)
