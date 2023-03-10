
# Nmake macros for building Windows 32-Bit apps

!if "$(TARGETOS)" == "WIN95"

!include <win32.mak>

#----- OUTDIR is defined in WIN32.MAK This is the name of the destination directory-------
all: $(OUTDIR)\sample.hlp 
        
#----- If OUTDIR does not exist, then create directory
$(OUTDIR) :
    if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)

# Build rule for help file
$(OUTDIR)\sample.hlp: $(OUTDIR) sample.hpj sample6.rtf
    $(hc) -o .\$(OUTDIR)\sample.hlp $(hcvars) sample.hpj 

#--------------------- Clean Rule --------------------------------------------------------
# Rules for cleaning out those old files
clean:
        $(CLEANUP)
        
!ELSE
!MESSAGE This sample is not designed for the Windows 2000 family
!ENDIF
