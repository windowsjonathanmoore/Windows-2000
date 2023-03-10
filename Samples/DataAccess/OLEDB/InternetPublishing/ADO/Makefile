!include <disable.mak>

#
# Copyright Microsoft Corp, 1997-2000
# Windows Platform SDK
#
!include <Win32.mak>

#
# all VB projects in the directory
#
ALL : Clean sdksample.exe

#
# remove existing files
#
Clean :
     if exist *.exe del *.exe
     if exist *.obj del *.obj
     if exist *.log del *.log
     if exist *.exp del *.exp
     if exist *.lib del *.lib
     if exist *.tlb del *.tlb
     if exist *.vbr del *.vbr
#
# project sdksample.vbp builds sdksample.exe
#
sdksample.exe:           \
    ModADO.Bas           \
    "SDK Sample.Frm"     \
    "SDK sample.Vbp"
    -$(bc) "sdk sample.vbp" $(bc_exe) /out comp.log
    @type comp.log
    @del comp.log
