!include <disable.mak>

!include <win32.mak>

LIBS = kernel32.lib user32.lib oldnames.lib ws2_32.lib mswsock.lib

.cpp{$(OUTDIR)}.obj:
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\"  $**

all:$(OUTDIR) $(OUTDIR)\iocpserver.exe $(OUTDIR)\iocpserverex.exe $(OUTDIR)\iocpclient.exe

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

$(OUTDIR)\iocpserver.exe: $(OUTDIR)\iocpserver.obj
    $(link) $(ldebug) $(conlflags) -out:$*.exe $** $(LIBS)

$(OUTDIR)\iocpserverex.exe:  $(OUTDIR)\iocpserverex.obj
    $(link) $(ldebug) $(conlflags) -out:$*.exe $** $(LIBS)

$(OUTDIR)\iocpclient.exe: $(OUTDIR)\iocpclient.obj
    $(link) $(ldebug) $(conlflags) -out:$*.exe $** $(LIBS)

clean:
        $(CLEANUP)

cleanall:clean
	-del *.exe
