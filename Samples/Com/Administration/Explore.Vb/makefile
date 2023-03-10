#VB Project Make File

PROJNAME=Explore
PROJECT=$(PROJNAME).vbp
BINROOT=$(MSSDK)Samples\Com\Administration\Explore.VB
TARGET="$(BINROOT)\$(PROJNAME).exe"
VBLOG="$(PROJNAME) BUILD.LOG"
SOURCE= \
	About.frm \
	About.frx \
	AppExport.frm \
	AppExport.frx \
	AppInstall.frm \
	AppInstall.frx \
	AppUtil.frm \
	AppUtil.frx \
	CompImp.frm \
	CompImp.frx \
	CompInst.frm \
	CompInst.frx \
	Connect.frm \
	Connect.frx \
	Explorer.frm \
	Explorer.frx \
	Utility.frm \
	Utility.frx \
	Common.bas \
	Registry.bas \
	Stack.bas \
	Explore.vbp

#VB Must be accessible from your path
VB6=vb6.exe

$(TARGET) : $(SOURCE)	
	-@erase $(VBLOG)
	$(SDKBUILD)\BIN\fixvbpref $(PROJECT) $(BINROOT)
	$(SDKBUILD)\BIN\UpdateVBRev $(PROJECT)
	$(VB6) /make /out $(VBLOG) $(PROJECT)

