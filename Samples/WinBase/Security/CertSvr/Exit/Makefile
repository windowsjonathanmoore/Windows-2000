!include <disable.mak>

# Nmake macros for building Windows 32-Bit apps

!IF "$(TARGETOS)" == "WINNT"

!include <win32.mak>


PROJNAME = CertXSam
OBJFILES = atl.Obj ceDebug.Obj ceError.Obj ceLib.Obj CertXSam.Obj Exit.Obj \
	CertXSam_i.Obj CertXSam.Res Module.Obj pch.Obj
EXTRA_LIBS = Certidl.Lib Crypt32.Lib

all: $(PROJNAME).Dll

CertXSam.Res: CertXSam.Rc CertXSam.Tlb
    $(rc) $(rcvars) -r -fo $*.Res $*.Rc

CertXSam.Rc: CertXSam.Tlb

CertXSam.Tlb: CertXSam.Idl
    midl CertXSam.Idl

CertXSam.Obj: CertXSam.Cpp Exit.h CertXSam.h

Exit.Obj: Exit.Cpp Exit.h CertXSam.h

CertXSam.h: CertXSam.Idl
    midl /h CertXSam.h CertXSam.Idl

CertXSam_i.c: CertXSam.Idl

.C.Obj:
    $(cc) $(cdebug) $(cflags) $(cvarsdll) -I. -DUNICODE $*.C

.Cpp.Obj:
    $(cc) $(cdebug) $(cflags) $(cvarsdll) -I. -DUNICODE $*.Cpp


$(PROJNAME).Dll: $(OBJFILES)
    $(link) $(linkdebug) $(dlllflags) -def:CertXSam.Def -out:$*.Dll $** $(olelibsdll) $(EXTRA_LIBS)


clean:
    del *.Obj *.Res
!ELSE
!MESSAGE Sorry this sample only builds for the Windows NT Platform
!ENDIF
