!include <disable.mak>

!include <$(MSTOOLS)\samples\com\fundamentals\include\olesampl.mak>

INCLUDE=.;$(INCLUDE)


all: oleapt.exe


oleapt.exe: oleapt.obj
  $(link) $(linkdebug) $(guiflags) -machine:$(CPU) -out:$*.exe $** $(olelibs)

.cpp.obj:
    $(cc) -GX $(cdebug) -W3 -c -D_$(CPU)_=1 $(cvars) $*.cpp
# Rules for cleaning out those old files
clean:
    del *.exe *.obj 
