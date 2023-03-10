!include <disable.mak>

#
# Copyright Microsoft Corp, 1997-2000
# Windows Platform SDK
#
!include <Win32.mak>

#
# all VB projects in the directory
#
ALL : Clean ospsampb.dll

#
# remove existing files
#
Clean :
     if exist *.dll del *.dll
     if exist *.obj del *.obj
     if exist *.log del *.log
     if exist *.exp del *.exp
     if exist *.lib del *.lib
     if exist *.tlb del *.tlb
     if exist *.vbr del *.vbr
#
# project Sampleosp_VB.vbp builds ospsampb.dll
#
ospsampb.dll:           \
    MyDataSource.cls        \
    "myOSPObject.cls"       \
    "Sampleosp_VB.Vbp"
    -$(bc) "Sampleosp_VB.vbp" $(bc_dll) /out comp.log
    @type comp.log
    @del comp.log
