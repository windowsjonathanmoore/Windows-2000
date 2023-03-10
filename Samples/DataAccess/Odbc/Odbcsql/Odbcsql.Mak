!include <disable.mak>

##########################################################################
#
# Makefile -- Build ODBC command line sample
#
#
##########################################################################

##########################################################################
#
# Constants
#
##########################################################################
APP		= odbcsql
ODBCINC	=   ..\..\include

!include <win32.mak>	  # use the WIN32 makefile template
ODBCLIB	=   ..\..\lib32

INCLUDE	 =   $(ODBCINC);$(INCLUDE)
LIB		 =   $(ODBCLIB);$(LIB)

!IF "$(DEBUG)" == "YES"
CFLAGS		=   /c /nologo $(cflags) $(cvars) $(cdebug) /DDEBUG /Ze /Fd$$(OBJDIR)\(APP).pdb
OBJECT		=   debug32
RCFLAGS	=   /dDEBUG
!else # $(DEBUG) != YES
CFLAGS		=   /c /nologo $(cflags) $(cvars) /Gs /Oxw /Ze
OBJECT		=   ndebug32
RCFLAGS =
!endif # $(DEBUG)

!IF "$(UNICODE)" == "YES"
CFLAGS=$(CFLAGS) -DUNICODE -D_UNICODE
!endif

LFLAGS  = /ALIGN:16 $(LFLAGS)

APPDEP	  =		$(ODBCINC)\odbcinst.h	\
				$(ODBCINC)\sql.h		\
				$(ODBCINC)\sqlext.h

APPOBJ		=	$(OBJECT)\$(APP).obj

APPLIB		=	$(guilibs)	\
				odbc32.lib		\
				odbccp32.lib

APPLNK		=	$(APP).lnk


##########################################################################
#
#   Make rules
#
##########################################################################

all:	setenv $(OBJECT)\$(APP).exe
		
setenv:
		set CL=$(CFLAGS)
		set INCLUDE=$(INCLUDE)
		set LIB=$(LIB)

$(OBJECT)\$(APP).exe:	$(APPOBJ)
		$(link) $(linkdebug) $(OBJECT)\$(APP).obj $(APPLIB) /out:$@ /machine:$(CPU) -debugtype:both

clean:
	-@del $(OBJECT)\*.obj
	-@del $(OBJECT)\*.pch
	-@del $(OBJECT)\*.res
	-@del $(OBJECT)\*.exe
	-@del $(OBJECT)\*.dll
	-@del $(OBJECT)\*.map
	-@del $(OBJECT)\*.sbr

##########################################################################
#
# Dependencies
#
##########################################################################

$(OBJECT)\$(APP).obj	: $(APP).c
	$(cc) /Fo$*.obj $(@B).c
