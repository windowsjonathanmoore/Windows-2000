!IF 0

Copyright (c) 1994-1996  Microsoft Corporation

Module Name:

    i386mk.inc

Abstract:

        This module contains the x86 specific build controls.  It is included
        by makefile.def.

Revision History:

!ENDIF

DELAYLOAD_SUPPORTED=1
!ifndef DELAYLOAD_VERSION
DELAYLOAD_VERSION=0x0100
!endif

#
# x86 option control
#
UMBASE=$(UMBASE:*=i386)
UMLIBS=$(UMLIBS:*=i386)
NTRES=$(NTRES:*=i386)
UMRES=$(UMRES:*=i386)
UMOBJS=$(UMOBJS:*=i386)
LINKLIBS=$(LINKLIBS:*=i386)
GDI_DRIVER_LIBS=$(GDI_DRIVER_LIBS:*=i386)
DLLBASE=$(DLLBASE:*=i386)
DLLDEF=$(DLLDEF:*=i386)
MACHINE_TARGETLIBS=$(MACHINE_TARGETLIBS:*=i386)
!ifdef USE_MSHTML_PDB_RULES
MACHINE_TARGETLIBS=$(MACHINE_TARGETLIBS:????????=*)
!endif
TARGET=$(TARGET:*=i386)
DYNLINK_LIB=$(DYNLINK_LIB:*=i386)
TARGETEXEFILES=$(TARGETEXEFILES:*=i386)
TARGETLIBFILES=$(TARGETLIBFILES:*=i386)
TARGETOBJFILES=$(TARGETOBJFILES:*=i386)
UMOBJFILES=$(UMOBJFILES:*=i386)
UMEXEFILES=$(UMEXEFILES:*=i386)
HEADERFILE=$(HEADERFILE:*=i386)
HEADEROBJNAME=$(HEADEROBJNAME:*=i386)
HEADEROBJ=$(HEADEROBJ:*=i386)
PRECOMPILED=$(PRECOMPILED:*=i386)
PRECOMPILED_CXX=$(PRECOMPILED_CXX:*=i386)
PRECOMPILED_TARGET=$(PRECOMPILED_TARGET:*=i386)
MFC_STATIC_LIB=$(MFC_STATIC_LIB:*=i386)
CRT_LIB_PATH=$(CRT_LIB_PATH:*=i386)
SDK_LIB_PATH=$(SDK_LIB_PATH:*=i386)
ORDER=$(ORDER:*=i386)
OBJLIBFILES=$(OBJLIBFILES:*=i386)
MISCFILES=$(MISCFILES) $(I386_MISCFILES)

!ifdef CHICAGO_PRODUCT
USE_MAPSYM=1
!endif

# "$(TARGETTYPE)"=="DRIVER"     ||
# "$(TARGETTYPE)" == "HAL" ||
# "$(TARGETTYPE)" == "EXPORT_DRIVER" ||

!IF "$(TARGETTYPE)"=="GDI_DRIVER" || \
    "$(TARGETTYPE)"=="MINIPORT"
#
#Drivers don't link with link libs.
#
MACHINE_TARGETLIBS=$(SDK_LIB_PATH)\int64.lib $(MACHINE_TARGETLIBS)
!ELSE
!IF defined(USE_NTDLL) || defined (USE_NOLIBS)
MACHINE_TARGETLIBS=$(SDK_LIB_PATH)\int64.lib $(MACHINE_TARGETLIBS)
!ENDIF
!ENDIF

!ifdef NTTARGETFILES
NTTARGETFILES=$(NTTARGETFILES:*=i386)
!endif
!ifdef NTTARGETFILE0
NTTARGETFILE0=$(NTTARGETFILE0:*=i386)
!endif
!ifdef NTTARGETFILE1
NTTARGETFILE1=$(NTTARGETFILE1:*=i386)
!endif

!IF "$(DLLENTRY)" != "-noentry"
!   IF "$(DLLENTRY:@12=)" == "$(DLLENTRY)"
DLLENTRY=$(DLLENTRY)@12
!   ENDIF
!ENDIF

!IFDEF STD_CALL_ENTRY
UMENTRY=$(UMENTRY)@4
!ENDIF

ENTRY_SUFFIX=@8
GDI_ENTRY_SUFFIX=@12

ADDITIONAL_ATL_LIBS = $(ADDITIONAL_ATL_LIBS)

!IFDEF 386_WARNING_LEVEL
MSC_WARNING_LEVEL=$(386_WARNING_LEVEL)
!ENDIF

!ifdef 386_PERFFLAGS
PERFFLAGS = $(386_PERFFLAGS)
!endif

# Set MSC_OPTIMIZATION.
# Order of precedence:
#   Platform specific override
#   Environment variable
#   System Default

!if defined(386_OPTIMIZATION)
MSC_OPTIMIZATION=$(386_OPTIMIZATION)
!elseif !defined(MSC_OPTIMIZATION)
MSC_OPTIMIZATION=$(DEFAULT_MSC_OPT)
!endif

DBGFLAGS=$(DBGFLAGS) $(MSC_OPTIMIZATION)

!IFDEF 386_CPPFLAGS
MSC_CPPFLAGS=$(386_CPPFLAGS)
!ENDIF

!ifdef NO_STRING_POOLING
STRING_POOLING =
!else
!ifdef NO_READONLY_STRINGS
STRING_POOLING = /Gf
!else
STRING_POOLING = /GF
!endif
!endif

!ifdef USE_NATIVE_EH
EH_FLAGS=/GX
!else
EH_FLAGS=/GX-
!endif

! ifdef USE_RTTI
RTTI_FLAGS=/GR
! else
RTTI_FLAGS=/GR-
! endif


!ifdef USE_INCREMENTAL_COMPILING
C_INCREMENTAL_FLAG = /Gi /Gm
USE_PDB_TO_COMPILE = 1
!else
C_INCREMENTAL_FLAG = /Gi- /Gm-
!endif

!ifndef X86_CPU_OPTIMIZATION
X86_CPU_OPTIMIZATION=/GB
!endif

# Undocumented switch definitions
# /QIfdiv- : Don't emit code to test for bad pentiums
# /QIf     : Emit FPO records for every function
# /QI0f    : Workaround Pentium bug

# ERATTA_FLAGS=/QIfdiv- /QIf
ERATTA_FLAGS=/QIfdiv- /QIf /QI0f

!ifdef NEWCOMPILER
# /d2compflag : Emit VC5 compatible S_COMPILE symbolic records.
ERATTA_FLAGS=$(ERATTA_FLAGS) /d2compflag

!if [set __GUIDLIB_CL_FLAGS=/d2compflag]
!endif
!endif

STDFLAGS= /c /Zel /Zp8 /Gy $(CBSTRING) $(MSC_WARNING_LEVEL) $(MSC_CALL_TYPE) \
          $(ERATTA_FLAGS) $(X86_CPU_OPTIMIZATION) $(C_INCREMENTAL_FLAG) $(EH_FLAGS) \
          $(RTTI_FLAGS) $(STRING_POOLING)

!IF "$(386_STDCALL)" == "0"
MSC_CALL_TYPE=/Gd
MSC_CALL_DEFINE=
!ELSE
!   IF "$(386_STDCALL)" == "2"
MSC_CALL_TYPE=/Gr
MSC_CALL_DEFINE=
!   ELSE
MSC_CALL_TYPE=/Gz
MSC_CALL_DEFINE=-DSTD_CALL
!   ENDIF
!ENDIF

!IF $(FREEBUILD)
ASM_DBG_DEFINES=-DDBG=0
!   IFDEF NTNOFPO
!MESSAGE $(NTMAKEENV)\i386mk.inc(1) : Overriding FPO default with NTNOFPO
TARGET_DBG_DEFINES= $(TARGET_DBG_DEFINES) -DFPO=0
DBGFLAGS=$(DBGFLAGS) /Oy-
!   ELSE
TARGET_DBG_DEFINES= $(TARGET_DBG_DEFINES) -DFPO=1
DBGFLAGS=$(DBGFLAGS) /Oy
!   ENDIF
!ELSE
TARGET_DBG_DEFINES= $(TARGET_DBG_DEFINES) -DFPO=0
DBGFLAGS=$(DBGFLAGS) /Oy-
386_ADBGFLAGS=$(386_ADBGFLAGS) /Zi
!ENDIF


!ifndef USE_PDB_TO_COMPILE
DBGFLAGS=$(DBGFLAGS:/Zi=-Z7)
DBGFLAGS=$(DBGFLAGS:-Zi=-Z7)
!else
! ifndef USE_MSHTML_PDB_RULES
!  if "$(TARGETTYPE)" == "LIBRARY"
DBGFLAGS=$(DBGFLAGS) /Fd$(TARGETPATH)\$(TARGET_DIRECTORY)\$(TARGETNAME).pdb
!  else
DBGFLAGS=$(DBGFLAGS) /Fd$(MAKEDIR)\$(_OBJ_DIR)\i386^\
!  endif
! else
!  ifndef TARGETPDB
TARGETPDB=$(TARGETNAME)
!  endif
!  ifndef ROOT
ROOT=$(MAKEDIR)
!  endif
DBGFLAGS=$(DBGFLAGS) /Fd$(ROOT)\$(_OBJ_DIR)\i386\$(TARGETPDB).pdb
! endif
!endif

!ifndef NO_BROWSER_INFO
! ifdef BROWSER_INFO
DBGFLAGS=$(DBGFLAGS) /FR$(MAKEDIR)\$(_OBJ_DIR)\i386^\
! endif
!endif

#
# 386 option control
#

ENV_DEFINES= $(MSC_CPPFLAGS) $(NTCPPFLAGS)

!IF "$(HALTYPE)" == ""
HALDEF=
!ELSE
HALDEF=-D$(HALTYPE)=1
!ENDIF

STD_DEFINES= -D_X86_=1 -Di386=1 $(HALDEF) $(MSC_CALL_DEFINE) $(STD_DEFINES)

CDEFINES=$(STD_DEFINES) $(TARGET_DBG_DEFINES) $(ENV_DEFINES) \
              $(LIBC_DEFINES) $(C_DEFINES) $(NET_C_DEFINES) $(MFC_DEFINES)
CFLAGS=$(386_FLAGS) $(NT386FLAGS) $(STDFLAGS) $(DBGFLAGS) $(PERFFLAGS) $(USER_C_FLAGS)
386_ASMFLAGS=$(386_ADBGFLAGS) $(STD_DEFINES) $(ASM_DBG_DEFINES)\
              $(TARGET_DBG_DEFINES) $(ENV_DEFINES) $(ASM_DEFINES)

386_CDEFINES=$(CDEFINES)
386_CFLAGS=$(CFLAGS)

!if "$(SUBSTITUTE_386_CC)" != ""
CC_NAME = $(SUBSTITUTE_386_CC) -nologo
!else
CC_NAME = cl -nologo
!endif

C_COMPILER_NAME     = $(CC_NAME)
CXX_COMPILER_NAME   = $(CC_NAME)
C_PREPROCESSOR_NAME = $(CC_NAME)
!ifndef 386_ASSEMBLER_NAME
386_ASSEMBLER_NAME  = ml
!endif

GLOBAL_C_FLAGS = -Ii386\ -I. $(INCPATH1) $(CDEFINES) $(CFLAGS)

NP_COMPILER_FLAGS = $(GLOBAL_C_FLAGS) $(COMPILER_WARNINGS)

C_COMPILER_FLAGS = $(NP_COMPILER_FLAGS) $(PRECOMPILED)
CXX_COMPILER_FLAGS = $(NP_COMPILER_FLAGS) $(PRECOMPILED_CXX)
C_PREPROCESSOR_FLAGS = $(GLOBAL_C_FLAGS) -EP -Tc

C_PREPROCESSOR = $(C_PREPROCESSOR_NAME) $(C_PREPROCESSOR_FLAGS)
C_COMPILER     = $(C_COMPILER_NAME) $(C_COMPILER_FLAGS)
NP_C_COMPILER  = $(C_COMPILER_NAME) $(NP_COMPILER_FLAGS)
CXX_COMPILER   = $(CXX_COMPILER_NAME) $(CXX_COMPILER_FLAGS)

!if defined(NOMASMCOMPATIBILITY)
386_ASSEMBLER=$(386_ASSEMBLER_NAME) -c -coff -Cx -nologo -Ii386\ -I. $(INCPATH1) $(386_ASMFLAGS)
!else
386_ASSEMBLER=$(386_ASSEMBLER_NAME) -c -coff -Cx -nologo -Ii386\ -I. $(INCPATH1) -Zm $(386_ASMFLAGS)
!endif

ECHO_MSG=$(C_COMPILER) $<
ECHO_MSG_P=$(NP_C_COMPILER) $**
ECHO_CXX_MSG=$(CXX_COMPILER) $<

ECHO_PRECOMPILED_MSG1=$(C_COMPILER_NAME) $(PRECOMPILED_FLAG) $(PRECOMPILED_SOURCEFILE) \
               $(C_COMPILER_FLAGS) /Yl$(TARGETNAME) /Yc$(?F) $(HEADERFILE) $(HEADEROBJ)

ECHO_PRECOMPILED_MSG2=$(C_COMPILER_NAME) $(PRECOMPILED_FLAG) \
               $(C_COMPILER_FLAGS) /Yl$(TARGETNAME) /Yc$(?F) $(HEADERFILE) $(HEADEROBJ)


{}.c{}.asm:
    $(C_COMPILER_NAME) @<< /Fa $(MAKEDIR)\$(<F)
$(C_COMPILER_FLAGS: =
)
$(C_COMPILER_FLAGS:##= )
<<NOKEEP

{..\i386\}.asm{}.lst:
    $(386_ASSEMBLER) /Fl$@ /Fo$(_OBJ_DIR)\i386\$(@B).obj $<

{i386\}.asm{}.lst:
    $(386_ASSEMBLER) /Fl$@ /Fo$(MAKEDIR)\$(_OBJ_DIR)\i386\$(@B).obj $<

{..\i386\}.asm{$(_OBJ_DIR)\i386\}.obj:
    $(386_ASSEMBLER) -Fo$(MAKEDIR)\$@ $<

{$(_OBJ_DIR)\i386\}.asm{$(_OBJ_DIR)\i386\}.obj:
    $(386_ASSEMBLER) -Fo$(MAKEDIR)\$@ $<

{i386\}.asm{$(_OBJ_DIR)\i386\}.obj:
    $(386_ASSEMBLER) -Fo$(MAKEDIR)\$@ $<

!IFDEF _NT386LIBS
_NTLIBS=$(_NT386LIBS)
!ENDIF

COPYDST=$(386COPYDST)
LIB_COPY=nti386cp.cmd

!IF "$(NTDEBUGTYPE)" == "windbg" || "$(NTDEBUGTYPE)" == "both"
NTTEST_LINK_OPTIONS=-entry:main
!ELSE
NTTEST_LINK_OPTIONS=-base:0x80100000 -entry:main
!ENDIF

!if 0
!if defined(LINKER_WIN98OPT) || defined (CHICAGO_PRODUCT)
LINKER_FLAGS=$(LINKER_FLAGS) /opt:win98
!else
LINKER_FLAGS=$(LINKER_FLAGS) /opt:nowin98
!endif
!endif
