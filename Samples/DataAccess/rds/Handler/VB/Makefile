!include <disable.mak>

#
# Copyright Microsoft Corp, 1997-2000
# Windows Platform SDK
#
!include <Win32.mak>

#
# all VB projects in the directory
#
ALL : Clean msdfmap_vb.dll

#
# remove existing files
#
Clean :
     if exist *.dll del *.dll
     if exist msdfmap_vb.tlb del msdfmap_vb.tlb
     if exist *.obj del *.obj
     if exist *.log del *.log
     if exist *.exp del *.exp
     if exist *.lib del *.lib
     if exist *.vbr del *.vbr
#
# project msdfmap.vbp builds msdfmap_vb.dll
#
msdfmap_vb.dll:           \
    msdfmap.bas        \
    msdfmap.cls        \
    "Events.cls"       \
    "msdfmap.Vbp"
    -$(bc) "msdfmap.vbp" $(bc_dll) /out comp.log
    @type comp.log
    @del comp.log
