!include <disable.mak>

# Makefile for the multilingual sample
#
# Nmake macros for building Win32 & Win64 apps
!include <Win32.Mak>

RESDIR=$(OUTDIR)\resources

RES401=.\res401
RES409=.\res409
RES407=.\res407
RES40D=.\res40d
RES411=.\res411
RES439=.\res439
RES449=.\res449

LINK_OBJS=\
	$(OUTDIR)\multilingual.obj\
	$(OUTDIR)\umhandlers.obj\
	$(OUTDIR)\uapiinit.obj\
	$(OUTDIR)\gentextout.obj\
	$(OUTDIR)\updtlang.obj 

all:    $(OUTDIR) $(OUTDIR)\multilingual.exe $(RESDIR) \
	$(RESDIR)\res401.dll\
	$(RESDIR)\res407.dll\
	$(RESDIR)\res409.dll\
	$(RESDIR)\res40d.dll\
	$(RESDIR)\res411.dll\
	$(RESDIR)\res439.dll\
	$(RESDIR)\res449.dll\
	$(OUTDIR)\uniansi.dll

# Create directories if necessary
$(OUTDIR) :
	if not exist "$(OUTDIR)" mkdir "$(OUTDIR)"

$(RESDIR) :
	if not exist "$(RESDIR)" mkdir "$(RESDIR)"

# Compile the resource files if necessary

# Saudi Arabic
$(OUTDIR)\res401.res: $(RES401)\res401.rc .\resource.h  "$(OUTDIR)"
    $(rc) $(rcflags) $(rcvars) /fo"$(OUTDIR)\res401.res" .\res401\res401.rc 

$(OUTDIR)\res401.obj: $(RES401)\res401.cpp "$(OUTDIR)"
    $(cc) $(cflags) $(cvars) $(cdebug) $(RES401)\res401.cpp /Fo"$(OUTDIR)\res401.obj" 

# German
$(OUTDIR)\res407.res: $(RES407)\res407.rc .\resource.h "$(OUTDIR)"
    $(rc) $(rcflags) $(rcvars) /fo"$(OUTDIR)\res407.res" .\res407\res407.rc 

$(OUTDIR)\res407.obj: $(RES407)\res407.cpp "$(OUTDIR)"
    $(cc) $(cflags) $(cvars) $(cdebug) $(RES407)\res407.cpp /Fo"$(OUTDIR)\res407.obj" 

# US English
$(OUTDIR)\res409.res: $(RES409)\res409.rc .\resource.h "$(OUTDIR)"
    $(rc) $(rcflags) $(rcvars) /fo"$(OUTDIR)\res409.res" .\res409\res409.rc 

$(OUTDIR)\res409.obj: $(RES409)\res409.cpp
    $(cc) $(cflags) $(cvars) $(cdebug) $(RES409)\res409.cpp /Fo"$(OUTDIR)\res409.obj" 

# Hebrew
$(OUTDIR)\res40d.res: $(RES40D)\res40d.rc .\resource.h "$(OUTDIR)"
    $(rc) $(rcflags) $(rcvars) /fo"$(OUTDIR)\res40d.res" .\res40d\res40d.rc 

$(OUTDIR)\res40d.obj: $(RES40D)\res40d.cpp "$(OUTDIR)"
    $(cc) $(cflags) $(cvars) $(cdebug) $(RES40D)\res40d.cpp /Fo"$(OUTDIR)\res40d.obj" 

# Japanese
$(OUTDIR)\res411.res: $(RES411)\res411.rc .\resource.h "$(OUTDIR)"
    $(rc) $(rcflags) $(rcvars) /fo"$(OUTDIR)\res411.res" .\res411\res411.rc 

$(OUTDIR)\res411.obj: $(RES411)\res411.cpp "$(OUTDIR)"
    $(cc) $(cflags) $(cvars) $(cdebug) $(RES411)\res411.cpp /Fo"$(OUTDIR)\res411.obj" 

# Hindi
$(OUTDIR)\res439.res: $(RES439)\res439.rc .\resource.h "$(OUTDIR)"
    $(rc) $(rcflags) $(rcvars) /fo"$(OUTDIR)\res439.res" .\res439\res439.rc 

$(OUTDIR)\res439.obj: $(RES439)\res439.cpp "$(OUTDIR)"
    $(cc) $(cflags) $(cvars) $(cdebug) $(RES439)\res439.cpp /Fo"$(OUTDIR)\res439.obj" 

# Tamil
$(OUTDIR)\res449.res: $(RES449)\res449.rc .\resource.h "$(OUTDIR)"
    $(rc) $(rcflags) $(rcvars) /fo"$(OUTDIR)\res449.res" .\res449\res449.rc 

$(OUTDIR)\res449.obj: $(RES449)\res449.cpp "$(OUTDIR)"
    $(cc) $(cflags) $(cvars) $(cdebug) $(RES449)\res449.cpp /Fo"$(OUTDIR)\res449.obj" 

#Header dependencies
multilingual.cpp: uapi.h umhandlers.h uniansi.h updtlang.h 
uapiinit.cpp: uapi.h uniansi.h 
umhandlers.cpp: gentextout.h uapi.h umhandlers.h uniansi.h updtlang.h 
updtlang.cpp: uapi.h uniansi.h updtlang.h 
uniansi.cpp: uapi.h uniansi.h 

#Generic compiler command line
.cpp{$(OUTDIR)}.obj::
   $(cc) @<<
   $(cflags) /Fo"$(OUTDIR)\\" $(cvars) $(cdebug)  $< 
<<

# Update modules if necessary

#main exe
$(OUTDIR)\multilingual.exe: $(LINK_OBJS) 
    $(link) $(linkdebug) $(guiflags) -out:"$(OUTDIR)\multilingual.exe" $(guilibs) $(LINK_OBJS)

#Unicode<-> ANSI conversion layer
$(OUTDIR)\uniansi.dll: $(OUTDIR)\uniansi.obj
    $(link) $(linkdebug) $(guiflags) $(guilibs) /dll /out:"$(OUTDIR)\uniansi.dll" /def:"uniansi.def" $(OUTDIR)\uniansi.obj 

#Resource DLLs
$(RESDIR)\res401.dll: $(OUTDIR)\res401.obj $(OUTDIR)\res401.res
    $(link) /dll /out:"$(RESDIR)\res401.dll" $(OUTDIR)\res401.obj $(OUTDIR)\res401.res 

$(RESDIR)\res407.dll: $(OUTDIR)\res407.obj $(OUTDIR)\res407.res
    $(link) /dll /out:"$(RESDIR)\res407.dll" $(OUTDIR)\res407.obj $(OUTDIR)\res407.res 

$(RESDIR)\res409.dll: $(OUTDIR)\res409.obj $(OUTDIR)\res409.res
    $(link) /dll /out:"$(RESDIR)\res409.dll" $(OUTDIR)\res409.obj $(OUTDIR)\res409.res 

$(RESDIR)\res40d.dll: $(OUTDIR)\res40d.obj $(OUTDIR)\res40d.res
    $(link) /dll /out:"$(RESDIR)\res40d.dll" $(OUTDIR)\res40d.obj $(OUTDIR)\res40d.res 

$(RESDIR)\res411.dll: $(OUTDIR)\res411.obj $(OUTDIR)\res411.res
    $(link) /dll /out:"$(RESDIR)\res411.dll" $(OUTDIR)\res411.obj $(OUTDIR)\res411.res 

$(RESDIR)\res439.dll: $(OUTDIR)\res439.obj $(OUTDIR)\res439.res
    $(link) /dll /out:"$(RESDIR)\res439.dll" $(OUTDIR)\res439.obj $(OUTDIR)\res439.res 

$(RESDIR)\res449.dll: $(OUTDIR)\res449.obj $(OUTDIR)\res449.res
    $(link) /dll /out:"$(RESDIR)\res449.dll" $(OUTDIR)\res449.obj $(OUTDIR)\res449.res 


CLEAN :
	-@erase "$(OUTDIR)\*.obj"
	-@erase "$(OUTDIR)\*.res"
	-@erase "$(OUTDIR)\*.exe"
	-@erase "$(OUTDIR)\*.pdb"
	-@erase "$(OUTDIR)\uniansi.dll"
	-@erase "$(OUTDIR)\uniansi.lib"
	-@erase "$(OUTDIR)\uniansi.exp"
	-@erase "$(RESDIR)\*.dll"
