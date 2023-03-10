!include <win32.mak>

!if "$(CPU)" == "IA64"
!message Sorry, this sample is not currently supported on 64bit platforms.
!else

all: $(OUTDIR)\multisitecfg.exe

LINK32_OBJS= \
	$(OUTDIR)\cmdfile.obj \
	$(OUTDIR)\configapp.obj \
	$(OUTDIR)\GetServerDlg.obj \
	$(OUTDIR)\modules.obj \
	$(OUTDIR)\multisitecfg.obj \
	$(OUTDIR)\multisitecfgdlg.obj \
	$(OUTDIR)\progressdlg.obj \
	$(OUTDIR)\stdpch.obj \
	$(OUTDIR)\SshWbemHelpers.obj \
	$(OUTDIR)\wbemsec.obj

LINK32_LIBS= \
	wbemuuid.lib 

#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)


#-------------------- Select appropriate MSVCRT file ----------------------------
!if "$(BLDTYPE1)"=="Retail"
MSVCRTLIB = msvcrt.lib
!else
MSVCRTLIB = msvcrtd.lib
!endif


#--------------------- EXE ---------------------------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Linker options WIN32.MAK provides

# $(OUTDIR)\multisitecfg.exe:  $(OUTDIR) $(LINK32_OBJS) $(LINK32_LIBS) $(OUTDIR)\MultiSiteCfg.res
#    $(link) $(ldebug) $(guilflags) /PDB:$(OUTDIR)\multisitecfg.pdb -out:$(OUTDIR)\multisitecfg.exe $(LINK32_OBJS)  $(LINK32_LIBS) $(OUTDIR)\MultiSiteCfg.res $(guilibs) 

$(OUTDIR)\multisitecfg.exe:  $(OUTDIR) $(LINK32_OBJS) $(OUTDIR)\MultiSiteCfg.res
    $(link) $(ldebug) $(guiflags) /PDB:$(OUTDIR)\multisitecfg.pdb -out:$(OUTDIR)\multisitecfg.exe $(LINK32_OBJS) $(LINK32_LIBS) $(OUTDIR)\MultiSiteCfg.res $(guilibs) 



#--------------------- Compiling C/CPP Files ---------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Compiler options WIN32.MAK provides

!if "$(BLDTYPE1)"=="Retail"
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(OUTDIR)\MultiSiteCfg.pch" /YX"stdpch.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /FD /c 
!else
CPP_PROJ=/nologo /MTd /W3 /Gm /GR /GX /ZI /Od /I "..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR"$(OUTDIR)\\" /Fp"$(OUTDIR)\MultiSiteCfg.pch" /YX"stdpch.h" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /FD /c 
!endif


SOURCE=.\cmdfile.cpp
$(OUTDIR)\cmdfile.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(CPP_PROJ) $(SOURCE)

SOURCE=.\configapp.cpp
$(OUTDIR)\configapp.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(CPP_PROJ) $(SOURCE)

SOURCE=.\GetServerDlg.cpp
$(OUTDIR)\GetServerDlg.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(CPP_PROJ) $(SOURCE)

SOURCE=.\modules.cpp
$(OUTDIR)\modules.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(CPP_PROJ) $(SOURCE)

SOURCE=.\MultiSiteCfg.cpp
$(OUTDIR)\MultiSiteCfg.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(CPP_PROJ) $(SOURCE)

SOURCE=.\MultiSiteCfgDlg.cpp
$(OUTDIR)\MultiSiteCfgDlg.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(CPP_PROJ) $(SOURCE)

SOURCE=.\ProgressDlg.cpp
$(OUTDIR)\ProgressDlg.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(CPP_PROJ) $(SOURCE)

SOURCE=.\stdpch.cpp
$(OUTDIR)\stdpch.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(CPP_PROJ) $(SOURCE)

SOURCE=..\utility\wbemsec.cpp
$(OUTDIR)\wbemsec.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(CPP_PROJ) $(SOURCE)

SOURCE=..\utility\SshWbemHelpers.cpp
$(OUTDIR)\SshWbemHelpers.obj : $(SOURCE) $(OUTDIR)
    $(cc) $(CPP_PROJ) $(SOURCE)




#--------------------- Compiling Resource Files ------------------------------------------
#PLEASE REFER TO WIN32.MAK for the different Resource Compiler options WIN32.MAK provides

# Build rule for resource file
SOURCE=.\MultiSiteCfg.rc

$(OUTDIR)\MultiSiteCfg.res: $(SOURCE) $(OUTDIR)
    $(rc) $(rcflags) $(rcvars) /fo $(OUTDIR)\MultiSiteCfg.res $(SOURCE)




#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)



!endif