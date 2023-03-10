!include <disable.mak>

#---------------------------------------------------------------------------------
#       File:           MAKEFILE
#               Copyright (c) 1991 - 1999 Microsoft Corp., All rights reserved
#
#       Purpose:
#               This makefile will compile both 16 and 32-bit auto test DLL's.  See
#               the documentation for the BUILD.EXE utility program for more details.
#---------------------------------------------------------------------------------



#-------------------------------------------------------------------------
#       Set platform compiler and linker flags
#-------------------------------------------------------------------------

!if "$(CPU)" == "x86"
CPU=i386
!endif
LPLATFORM = $(CPU)

!IF "$(CPU)" == "i386"
!IFDEF DEBUG
DEVLIB = $(PROJDIR)\DM\DEBUG32
CPANEL_LIBDIR = $(PROJDIR)\CPANEL\DEBUG32
!ELSE
DEVLIB = $(PROJDIR)\DM\NDEBUG32
CPANEL_LIBDIR = $(PROJDIR)\CPANEL\NDEBUG32
!ENDIF
CPLATFORM = _X86_
!ELSE
CPLATFORM = _$(CPU)_
!IFDEF DEBUG
DEVLIB = $(PROJDIR)\DM\$(CPU)\DEBUG32
CPANEL_LIBDIR = $(PROJDIR)\CPANEL\$(CPU)\DEBUG32
!ELSE
DEVLIB = $(PROJDIR)\DM\$(CPU)\NDEBUG32
CPANEL_LIBDIR = $(PROJDIR)\CPANEL\$(CPU)\NDEBUG32
!ENDIF
!ENDIF

#-------------------------------------------------------------------------
#       Set Unicode flags
#------------------------------------------------------------------------
!IFDEF UNICODE
UNICODE_FLAGS=/DUNICODE /D_UNICODE
GTRTST_LIB=gtrts32w.lib
OUTFILE=QUIKTSTW
!ELSE
GTRTST_LIB=gtrtst32.lib
OUTFILE=QUIKTEST
!ENDIF



TSTNM=QUIKTEST
PROJDIR=.
SRCDIR=$(PROJDIR)\$(TSTNM)
INCDIR=$(PROJDIR)\$(TSTNM)
RCDIR=$(PROJDIR)\$(TSTNM)

#********************************************************************
# compiler
#********************************************************************

cc = cl
LINK = link -entry:TstLibMain$(DLLENTRY) -machine:$(LPLATFORM) /PDB:NONE $(LDEBUG)
LIBS  = user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib ole32.lib shell32.lib $(DEVLIB)\odbc32.lib $(LIBDIR)\$(GTRTST_LIB)
!IFDEF DEBUG
CDBG = /nologo /W3 /Zi /D "$(CPLATFORM)" /D "_DEBUG" /D "WIN32" /DDLL_INVOKED /MT $(UNICODE_FLAGS)
LDEBUG = -debug:full -debugtype:cv
RDEBUG = -d_DEBUG
!IFDEF UNICODE
OBJDIR = $(SRCDIR)\$(CPU_DIR)DEBUG32W
EXEDIR = $(SRCDIR)\$(CPU_DIR)DEBUG32W
LIBDIR = $(PROJDIR)\GATORTST\$(CPU_DIR)DEBUG32W
!ELSE
OBJDIR = $(SRCDIR)\$(CPU_DIR)DEBUG32
EXEDIR = $(SRCDIR)\$(CPU_DIR)DEBUG32
LIBDIR = $(PROJDIR)\GATORTST\$(CPU_DIR)DEBUG32
!ENDIF
!ELSE
CDBG = /nologo /W3 /D "$(CPLATFORM)" /D "WIN32" -DDLL_INVOKED /MT $(UNICODE_FLAGS)
LDEBUG = 
!IFDEF UNICODE
OBJDIR = $(SRCDIR)\$(CPU_DIR)NDBUG32W
EXEDIR = $(SRCDIR)\$(CPU_DIR)NDBUG32W
LIBDIR = $(PROJDIR)\GATORTST\$(CPU_DIR)NDBUG32W
!ELSE
OBJDIR = $(SRCDIR)\$(CPU_DIR)NDEBUG32
EXEDIR = $(SRCDIR)\$(CPU_DIR)NDEBUG32
LIBDIR = $(PROJDIR)\GATORTST\$(CPU_DIR)NDEBUG32
!ENDIF
!ENDIF


#-------------------------------------------------------------------------
#       List common dependencies
#-------------------------------------------------------------------------
SQLINC  =  $(PROJDIR)\INCLUDE
INCTEST =       $(SQLINC)\sql.h \
		$(SQLINC)\sqlext.h \
		$(SRCDIR)\autotest.h


#-------------------------------------------------------------------------
#       Entire makefile is dependent on the test DLL and the correct environment
#-------------------------------------------------------------------------
all: setenv \
	$(EXEDIR)\$(OUTFILE).dll 

setenv:
  set PATH=$(TOOLSBIN);
  set INCLUDE=$(INCDIR);$(SRCDIR);$(SQLINC);$(TOOLSINC)
  set LIB=$(LIBDIR);$(DEVLIB);$(CPANEL_LIBDIR);$(GATOROUTDIR);$(TOOLSLIB)


#-------------------------------------------------------------------------
#    Create the TEST.DEF file based on our values
#-------------------------------------------------------------------------
$(EXEDIR)\TEST.DEF:  
	@echo LIBRARY                   $(OUTFILE)                                                                                                >       $@
	@echo DESCRIPTION               '$(TSTNM) Test DLL'                                                             >>      $@
	@echo CODE                              PRELOAD MOVEABLE LOADONCALL DISCARDABLE >>      $@
	@echo   DATA                            PRELOAD MOVEABLE                                                                        >>      $@
	@echo HEAPSIZE                  5120                                                                                                    >> $@
	@echo   PROTMODE                                                                                                                                        >> $@
	@echo   SEGMENTS                                                                                                                                        >> $@
	@echo EXPORTS                                                                                                                                   >> $@
	@echo                   TstLibMain                                                                                                              >> $@
	@echo                   AutoTestName                                                                                                    >> $@
	@echo                   AutoTestDesc                                                                                                    >> $@
	@echo                   AutoTestFunc                                                                                                    >> $@


#-------------------------------------------------------------------------
#    List the .OBJ dependencies
#-------------------------------------------------------------------------

#
#  The following will always be used
#
$(OBJDIR)\$(TSTNM).obj: $(SRCDIR)\$(TSTNM).C \
								$(SRCDIR)\quiktest.h \
								$(SRCDIR)\DLLSTUB.C \
								$(SRCDIR)\QUIKTEST.MAK \
								$(INCTEST)
	$(cc) $(CDBG) -I$(INCDIR) -Fo$(OBJDIR)\$(@B).obj -c $(SRCDIR)\$(TSTNM).c


#
#  The stub is required to make a full DLL
#
$(OBJDIR)\DLLSTUB.obj:  $(SRCDIR)\DLLSTUB.C 
	$(cc) $(CDBG) -Fo$(OBJDIR)\$(@B).obj -c $(SRCDIR)\$(@B).c




#-------------------------------------------------------------------------
#    Build .res file
#-------------------------------------------------------------------------
!IF EXIST($(RCDIR)\$(TSTNM).RC)
$(OBJDIR)\$(TSTNM).res: $(RCDIR)\$(TSTNM).rc \
				$(SRCDIR)\quiktest.h
		rc $(RDEBUG) -r -i $(INCDIR) -FO$(OBJDIR)\$(TSTNM).res $(RCDIR)\$(TSTNM).rc
!ENDIF

			  
#-------------------------------------------------------------------------
#    Now do the executable
#-------------------------------------------------------------------------
$(EXEDIR)\$(OUTFILE).dll: $(OBJDIR)\$(TSTNM).OBJ $(OBJDIR)\DLLSTUB.OBJ $(LIBDIR)\$(GTRTST_LIB) $(EXEDIR)\TEST.DEF \
!IF EXIST($(RCDIR)\$(TSTNM).rc)
								$(OBJDIR)\$(TSTNM).res \
!ENDIF
								$(SRCDIR)\QUIKTEST.MAK
	echo >NUL @<<$(TSTNM).CRF
$(OBJDIR)\$(TSTNM).OBJ
$(OBJDIR)\DLLSTUB.OBJ
-DLL -OUT:$(EXEDIR)\$(OUTFILE).dll
!IF EXIST($(RCDIR)\$(TSTNM).rc)
$(OBJDIR)\$(TSTNM).res
!ENDIF
-def:$(OBJDIR)\TEST.DEF -implib:$(OBJDIR)\$(OUTFILE).LIB
<<
   $(LINK) $(LIBS) @$(TSTNM).CRF

 -@del $(OBJDIR)\TEST.DEF

clean: 
	-del /Q $(OBJDIR)\*.*
