#****************************** File Header ******************************\
# File Name: Sources.inc for keyboard layouts
#
# Copyright (c) 1999, Microsoft Corporation
#
# Project specific SOURCES file.
#***************************************************************************/

C_DEFINES=
UMTYPE=nt
UMTEST=
UMAPPL=
UMBASE=0x1000000
UMLIBS=
TARGETLIBS=

!if $(IA64)
SECTION_ALIGNMENT=0x4000
!endif
LINKER_FLAGS = -merge:.edata=.data -merge:.rdata=.data -merge:.text=.data -merge:.bss=.data -section:.data,re


