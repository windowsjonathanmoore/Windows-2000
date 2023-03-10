!include <disable.mak>

##########################################################################
#
# Makefile -- Build Admin Demo Application
#
##########################################################################

##########################################################################
#
# Constants
#
##########################################################################

!include <win32.mak> # use the WIN32 makefile template

APP             = ADMNDEMO
ODBCINC         = ..\..\..\include\odbc
ODBCLIB32       = ..\..\..\lib\odbc\odbc32.lib
CPANELLIB	= ..\..\..\lib\odbc\odbccp32.lib

!IF "$(DEBUG)" == "YES"
CFLAGS		=   /c /nologo $(cflags) $(cvarsdll) $(cdebug) /DDEBUG /Ze
OBJDIR		=   debug32
RCFLAGS	=   /dDEBUG
!else # $(DEBUG) != YES
CFLAGS		=   /c /nologo $(cflags) $(cvarsdll) /Gs /Oxw /Ze
OBJDIR		=   ndebug32
RCFLAGS =
!endif # $(DEBUG)

LFLAGS          = /ALIGN:16 $(LFLAGS) $(LINKDEBUG)

APPDEP          = child.h \
						dialogs.h \
						errcheck.h \
						execute.h \
						info.h \
						ini.h \
						menu.h \
						results.h \
						admndemo.h \
						standard.h \
						strings.h

APPOBJ          = $(OBJDIR)\DIALOGS.OBJ \
						$(OBJDIR)\ERRCHECK.OBJ \
						$(OBJDIR)\EXECUTE.OBJ \
						$(OBJDIR)\INFO.OBJ \
						$(OBJDIR)\INI.OBJ \
						$(OBJDIR)\MENU.OBJ \
						$(OBJDIR)\RESULTS.OBJ \
						$(OBJDIR)\admndemo.OBJ \
						$(OBJDIR)\STANDARD.OBJ

APPLNK          = $(OBJDIR)\$(APP).lnk

##########################################################################
#
#   Make rules
#
##########################################################################

all:            setenv $(OBJDIR)\$(APP).exe

setenv:
		set CL=$(CFLAGS)
		set INCLUDE=$(ODBCINC);$(INCLUDE)
		set LIB=$(ODBCLIB32);$(CPANELLIB);$(LIB)

$(OBJDIR)\$(APP).exe: $(APP).def $(OBJDIR)\$(APP).res $(APPOBJ)
			@echo $(guiflags)               >  $(APPLNK)
!ifdef DEBUG
			@echo $(linkdebug)              >> $(APPLNK)
!endif # DEBUG
			@echo $(OBJDIR)\dialogs.obj    >> $(APPLNK)
			@echo $(OBJDIR)\errcheck.obj   >> $(APPLNK)
			@echo $(OBJDIR)\execute.obj    >> $(APPLNK)
			@echo $(OBJDIR)\info.obj       >> $(APPLNK)
			@echo $(OBJDIR)\ini.obj        >> $(APPLNK)
			@echo $(OBJDIR)\menu.obj       >> $(APPLNK)
			@echo $(OBJDIR)\results.obj    >> $(APPLNK)
			@echo $(OBJDIR)\admndemo.obj   >> $(APPLNK)
			@echo $(OBJDIR)\standard.obj   >> $(APPLNK)
			@echo $(OBJDIR)\$(APP).res     >> $(APPLNK)
			@echo /out:$@                   >> $(APPLNK)
			@echo /machine:$(CPU)           >> $(APPLNK)
			@echo /map:$*.map               >> $(APPLNK)
			@echo $(winlibs) msvcrt.lib   $(ODBCLIB32) $(CPANELLIB)             >> $(APPLNK)
			$(link) @$(APPLNK)
			@del $(APPLNK)

$(OBJDIR)\$(APP).res:  $(APP).rc $(APPDEP)
		rc $(RCFLAGS) -r -DWIN32 -Fo $(OBJDIR)\$(APP).res $(APP).rc

clean:
    -@del $(OBJDIR)\*.obj
    -@del $(OBJDIR)\*.pch
    -@del $(OBJDIR)\*.res
    -@del $(OBJDIR)\*.exe
    -@del $(OBJDIR)\*.dll
    -@del $(OBJDIR)\*.map
    -@del $(OBJDIR)\*.sbr

##########################################################################
#
# Dependencies
#
##########################################################################


$(OBJDIR)\dialogs.obj:    $(@B).c $(APPDEP)
    $(CC) /Fo$*.obj /FR$*.sbr /Fd$(OBJDIR)\$(APP).pdb /c $(@B).c

$(OBJDIR)\errcheck.obj:    $(@B).c $(APPDEP)
    $(CC) /Fo$*.obj /FR$*.sbr /Fd$(OBJDIR)\$(APP).pdb /c $(@B).c

$(OBJDIR)\execute.obj:    $(@B).c $(APPDEP)
    $(CC) /Fo$*.obj /FR$*.sbr /Fd$(OBJDIR)\$(APP).pdb /c $(@B).c

$(OBJDIR)\info.obj:    $(@B).c $(APPDEP)
    $(CC) /Fo$*.obj /FR$*.sbr /Fd$(OBJDIR)\$(APP).pdb /c $(@B).c

$(OBJDIR)\ini.obj:    $(@B).c $(APPDEP)
    $(CC) /Fo$*.obj /FR$*.sbr /Fd$(OBJDIR)\$(APP).pdb /c $(@B).c

$(OBJDIR)\menu.obj:    $(@B).c $(APPDEP)
    $(CC) /Fo$*.obj /FR$*.sbr /Fd$(OBJDIR)\$(APP).pdb /c $(@B).c

$(OBJDIR)\results.obj:    $(@B).c $(APPDEP)
    $(CC) /Fo$*.obj /FR$*.sbr /Fd$(OBJDIR)\$(APP).pdb /c $(@B).c

$(OBJDIR)\admndemo.obj:    $(@B).c $(APPDEP)
    $(CC) /Fo$*.obj /FR$*.sbr /Fd$(OBJDIR)\$(APP).pdb /c $(@B).c

$(OBJDIR)\standard.obj:    $(@B).c $(APPDEP)
    $(CC) /Fo$*.obj /FR$*.sbr /Fd$(OBJDIR)\$(APP).pdb /c $(@B).c


