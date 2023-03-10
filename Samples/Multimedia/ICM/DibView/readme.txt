DIBVIEW


SUMMARY
-------

DIBVIEW is a sample application for the demonstration of the image color 
management (ICM), multiple display monitors (multimon) and still image (STI)
application programming interfaces (API). DIBVIEW uses the following APIs;


Basic ICM functions for use within a device context;

ColorCorrectPalette
EnumColorProfiles
EnumColorProfilesCallback
GetICMProfile
SetColorSpace
SetICMMode
SetICMProfile


Advanced ICM functions for use outside of a device context;

CreateColorTransform
CreateMultiProfileTransform
DeleteColorTransform
SelectCMM
SetupColorMatching
TranslateBitmapBits


Device calibration and characterization functions;

CloseColorProfile
IsColorProfileValid
OpenColorProfile


Profile management functions;

CreateProfileFromLogColorSpace
EnumColorProfiles
GetColorDirectory
GetStandardColorSpaceProfile
RegisterCMM
UnregisterCMM


Multiple display monitors functions;

EnumDisplayMonitors
GetMonitorInfo
MonitorEnumProc
MonitorFromWindow


Still image functions;

StiCreateInstance
IStillImage::GetDeviceList
IStillImage::GetDeviceValue
IStillImage::GetSTILaunchInformation
IStillImage::RegisterLaunchApplication
IStillImage::UnregisterLaunchApplication



To Compile DIBVIEW
------------------

To compile the sample without any ICM functionality, use the following 
command:

   nmake -f dibview.mak ICM=ICM_NONE


To compile the sample that uses inside DC ICM functionality, use the 
following command:

   nmake -f dibview.mak ICM=ICM_INSIDE_DC


To compile the sample that uses outside DC ICM functionality, use the 
following command:

   nmake -f dibview.mak ICM=ICM_OUTSIDE_DC


To compile all three versions of DIBVIEW, use the following command:

   nmake


To clean up between builds which use different options, use the
following command:

   nmake clean


To compile with the TWAIN functionality, you need to get the twain.h header
file from the TWAIN web site; http://www.twain.org. Currently this file is at
http://www.twain.org/docs/twain.h. After you get twain.h, copy it to a 
common include directory and edit dibview.mak to add -DTWAIN_ENABLED to 
CFLAGS=... and RFLAGS=... lines, i.e. change lines 33-34 in dibview.mak to;

CFLAGS = -DTWAIN_ENABLED -D$(ICM) -DMULTIMON_ENABLED $(cdebug) $(cflags) $(cvars)
RFLAGS = -DTWAIN_ENABLED -D$(ICM) -DMULTIMON_ENABLED $(rcflags) $(rcvars)



To build the project under Visual C++ 6.0, open the project file DIBVIEW.DSP


Use "Win32 Debug" or "Win32 Release" configurations to compile the sample
without any ICM functionality.


Use "Win32 Debug ICM Inside DC" or "Win32 Release ICM Inside DC" to compile
the sample that uses inside DC ICM functionality.


Use "Win32 Debug ICM Outside DC" or "Win32 Release ICM Outside DC" to compile
the sample that uses outside DC ICM functionality.


To compile with the TWAIN functionality under Visual C++ 6.0, first get the
twain.h header from the TWAIN web site, then open the "Project / Settings"
dialog, go to the "C/C++ / General" tab and add the "TWAIN_ENABLED" symbol 
to the "Preprocessor definititions" field.



To Run DIBVIEW
--------------

If you have compiled the sample using nmake,
   
   for the non-icm version, run 
       obj\no_icm\DIBVIEW.EXE

   for the version that uses inside DC ICM functions, run
       obj\in_dc_icm\DIBVIEW.EXE

   for the version that uses outside DC ICM functions, run
       obj\out_dc__icm\DIBVIEW.EXE 


If you have compiled the sample using Visual C++,
   
   for the non-icm version, run 
       Debug\DIBVIEW.EXE or Release\DIBVIEW.EXE 

   for the version that uses inside DC ICM functions, run
       InDebug\DIBVIEW.EXE or InRelease\DIBVIEW.EXE 

   for the version that uses outside DC ICM functions, run
       OutDebug\DIBVIEW.EXE or OutRelease\DIBVIEW.EXE 



DIBVIEW Files
-------------

about.c        Implementation of the about dialog
bitmapwin.h    Header file for the BITMAPWINDOW struct
clipboard.c    Implementation of the clipboard operations
cmmman.c       Implements a dialog for manipulating the default CMM
cmmman.h       Header file for CMMman.c
construct.c    Implementation of the BITMAPWINDOW struct contruction / destruction
convert.c      Implementation of the profile to profile conversion operations
convert.h      Header file for convert.c
dib.c          Implementation of the bitmap manipulation functions
dibview.c      main function
dibview.dsp    VC 6.0 project settings file
dibview.h      Header file for dibview.c
dibview.mak    Makefile
dibview.rc     Project resources
document.c     Implementation of the image file handling operations
ffilter.c      Image file read filter functions
ffilter.h      Header file for ffilter.c
global.c       Definition of the global variables
global.h       Declerations the global variables
icm.c          Implementation of the ICM functions
icon.c         Implementation of the window icon drawing
imagelist.bmp  Bitmap for the check mark
implement.c    This file forces the implemantation of the stub functions
inline.h       Header file that contains the inline functions
makefile       Makefile for the project
mmon.c         Implementation of the multi monitor support functions
pch.c          Precompiled headers file
print.c        Implementation of the printing functions
resource.h     Header file for the definitions of the resouce identifiers
selsource.c    Implements a dialog for selecting a TWAIN data source and ICM profile
selsource.h    Header file for selsource.c
settings.c     Implementation of the user defined settings operations
twain.c        Implementation of the TWAIN interface functions
window.c       Implementation of the window message handling functions
