!include <disable.mak>

#
# Copyright Microsoft Corp, 1997-2001
# Windows Platform SDK
#
!include <Win32.mak>

#
# All VB Projects in the directory
#
ALL :  TestExt.exe

#
# Project TestExt.VBP builds TestExt.EXE
#
TestExt.exe :  \
    TestExt.frm \
    TestExt.vbp
    $(bc) $(bc_exe) TestExt.vbp /out comp.log
    @type comp.log
    @del comp.log

clean:
	@del ..\TestExt.exe
