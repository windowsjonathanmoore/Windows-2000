@ECHO OFF
REM --------------------------------------------------------------------------------------------
REM File    : SetEnv.Bat
REM
REM Abstract: This batch file sets the appropriate environment
REM           variables for the Platform SDK build envionment with
REM           respect to OS and platform type.
REM
REM "Usage:    Setenv [/2000 | /me | /pre32 | /pre64] [/cc=compiler location][/DEBUG | /RETAIL]"
REM
REM                  /2000 (default) - target Windows 2000 and IE 5.0
REM                  /me - target Windows Millennium
REM                  /pre32 - target all 32bit pre-release content
REM                  /pre64 - target Windows 64bit pre-release content
REM                  /cc - location of compilation .exes.
REM                  /DEBUG - set the environment to DEBUG
REM                  /RETAIL - set the environment to RETAIL
REM 
REM --------------------------------------------------------------------------------------------


:Chk_MSSdk
REM Need to set the CPU here
set CPU=i386
IF "%1" == "/pre64" set CPU=IA64

REM Set the common env. variables
Goto Set_Common

:Chk_SetEnv
REM Verify that we have %MSSdk%\SetEnv.Bat
IF NOT EXIST "%MSSdk%\SetEnv.Bat" Goto ErrorBadPath

REM Check for the presence of MsVC5 or MsVC6.
goto Chk_MsVC

:Chk_OS
REM Set OS/platform-specific variables
goto Set_OS

:Finish
Goto end


REM -------------------------------------------------------------------
REM Set common variables
:Set_Common
REM -------------------------------------------------------------------
Set MSSdk=[PSDKDIR]
Set Bkoffice=%MSSdk%\
Set Basemake=%MSSdk%\Include\BKOffice.Mak
Set DXSDKROOT=%MSSdk%
Set INETSDK=%MSSdk%
Set MSSdk=%MSSdk%
Set Mstools=%MSSdk%

REM Default to DEBUG
goto set_DEBUG
:Done_Debug

REM Are we building DEBUG or RETAIL
if "%1" == "/RETAIL" goto set_RETAIL
if "%2" == "/RETAIL" goto set_RETAIL
if "%3" == "/RETAIL" goto set_RETAIL
if "%4" == "/RETAIL" goto set_RETAIL
:Done_Retail

goto Chk_SetEnv


REM -------------------------------------------------------------------
REM Set OS/platform-specific variables
:Set_OS
REM -------------------------------------------------------------------

IF "x%OS%x" == "xWindows_NTx" Goto Set_WinNT

REM Check to make sure we aren't attempting to open a 64bit build window
if "%1" == "/pre64" goto ErrorUsage9x_IA64

Echo Setting SDK environment relative to %MSSdk%. 

REM check if the first parameter exists
if "%1"== "" goto Set_2000
if "%1" == "/DEBUG" goto Set_2000
if "%1" == "/RETAIL" goto Set_2000
if "%1" == "/2000" goto Set_2000
if "%1" == "/cc" goto Set_2000
if "%1" == "/me" goto Set_WinME
if "%1" == "/pre32" goto Set_pre32

REM Usage not correct leave
goto ErrorUsage9x


REM -------------------------------------------------------------------
REM Set Windows Me specific variables
:Set_WinME
REM -------------------------------------------------------------------
Echo Targeting Windows ME and IE 5.5 %DEBUGMSG%
Echo.
Set Lib=%MSSdk%\Lib;%Lib%
Set Include=%MSSdk%\Include;%Include%
Set Path="%MSSdk%\Bin;%MSSdk%\Bin\win95;%path%"
Set CPU=i386
set _WIN32_IE=0x0501
set TARGETOS=WIN95
set APPVER=5.0
doskey > Nul
Goto Finish


REM -------------------------------------------------------------------
REM Set Windows 2000 specific variables
:Set_2000
REM -------------------------------------------------------------------
Echo Targeting Windows 2000 and IE 5.0 %DEBUGMSG%
Echo.
Set Lib=%MSSdk%\Lib;%Lib%
Set Include=%MSSdk%\Include;%Include%
Set Path="%MSSdk%\Bin;%MSSdk%\Bin\win95;%path%"
Set CPU=i386
set TARGETOS=WINNT
set APPVER=5.0
doskey > Nul
Goto Finish


REM -------------------------------------------------------------------
REM Set Windows pre32 specific variables
:Set_pre32
REM -------------------------------------------------------------------
Echo Targeting Windows Pre32 %DEBUGMSG%
Echo.
Set Lib=%MSSdk%\Lib\prerelease;%MSSdk%\Lib;%Lib%
Set Include=%MSSdk%\Include\prerelease;%MSSdk%\Include;%Include%
Set Path="%MSSdk%\Bin\prerelease;%MSSdk%\Bin;%MSSdk%\Bin\win95;%path%"
Set CPU=i386
set TARGETOS=WINNT
set APPVER=5.01
doskey > Nul
Goto Finish


REM -------------------------------------------------------------------
REM Set Windows NT specific variables
:Set_WinNT
REM -------------------------------------------------------------------
IF /i "%PROCESSOR_ARCHITECTURE%" == "ALPHA" (Set CPU=ALPHA) else (Set CPU=i386)
IF "%1" == "/pre64" SET CPU=IA64

REM Verify that we aren't building pre64 on Windows NT Version 4.0
For /F "delims=;" %%i IN ('Cmd /c Ver') DO (
    IF "%%i"=="Windows NT Version 4.0  " (
        IF "%CPU%" == "IA64" goto ErrorUsage9x_IA64
        )
    )

REM check if the first parameter exists
if "%1"== "" goto Set2000_2000
if "%1" == "/DEBUG" goto Set2000_2000
if "%1" == "/RETAIL" goto Set2000_2000
if "%1" == "/2000" goto Set2000_2000
if "%1" == "/cc" goto Set2000_2000
if "%1" == "/me" goto Set2000_WinME
if "%1" == "/pre32" goto Set2000_pre32
if "%1" == "/pre64" goto Set2000_pre64

REM Usage not correct leave
goto ErrorUsage


REM -------------------------------------------------------------------
REM Patch path to put Bin\WinNT\NT4 in path ahead of NT5 tools that don't run on NT4
:Set_WinNT_Cont
REM -------------------------------------------------------------------
REM Patch path to put Bin\WinNT\NT4 in path ahead of NT5 tools that don't run on NT4
For /F "delims=;" %%i IN ('Cmd /c Ver') DO (
    IF "%%i"=="Windows NT Version 4.0" (
        Set Path=%MSSdk%\Bin\WinNT\NT4;%Path%
        Goto Finish
        )
    )
Goto Finish


REM -------------------------------------------------------------------
REM Set Windows Me specific variables
:Set2000_WinME
REM -------------------------------------------------------------------
Echo Targeting Windows ME and IE5.5 %DEBUGMSG%
Echo.
Set Lib=%MSSdk%\Lib;%Lib%
Set Include=%MSSdk%\Include;%Include%
Set Path=%MSSdk%\Bin;%MSSdk%\Bin\WinNT;%path%
set _WIN32_IE=0x0501
set TARGETOS=WIN95
set APPVER=5.0
Title Microsoft Platform SDK Windows Me IE 5.5 %DEBUGMSG% Build Environment
Goto Set_WinNT_Cont


REM -------------------------------------------------------------------
REM Set Windows 2000 specific variables
:Set2000_2000
REM -------------------------------------------------------------------
Echo Targeting Windows 2000 and IE 5.0 %DEBUGMSG%
Echo.
Set Lib=%MSSdk%\Lib;%Lib%
Set Include=%MSSdk%\Include;%Include%
Set Path=%MSSdk%\Bin;%MSSdk%\Bin\WinNT;%path%
set APPVER=5.0
set TARGETOS=WINNT
Title Microsoft Platform SDK Windows 2000 IE 5.0 %DEBUGMSG% Build Environment
Goto Set_WinNT_Cont


REM -------------------------------------------------------------------
REM Set Windows pre32 specific variables
:Set2000_pre32
REM -------------------------------------------------------------------
Echo Targeting Windows Pre32 %DEBUGMSG%
Echo.
Set Lib=%MSSdk%\Lib\prerelease;%MSSdk%\Lib;%Lib%
Set Include=%MSSdk%\Include\prerelease;%MSSdk%\Include;%Include%
Set Path=%MSSdk%\Bin\prerelease;%MSSdk%\Bin;%MSSdk%\Bin\WinNT;%path%
set APPVER=5.01
set TARGETOS=WINNT
Title Microsoft Platform SDK PreRelease 32-bit IE 5.5 %DEBUGMSG% Build Environment
Goto Set_WinNT_Cont


REM -------------------------------------------------------------------
REM Set Windows pre64 specific variables
:Set2000_pre64
REM -------------------------------------------------------------------
Echo Targeting Windows pre64 %DEBUGMSG%
Echo.
Set Lib=%MSSdk%\Lib\prerelease\IA64;%MSSdk%\Lib\prerelease\IA64\CRT;%MSSdk%\Lib\prerelease\IA64\MFC;%MSSdk%\Lib\prerelease\IA64\ATL
SET Include=%MSSdk%\Include\prerelease;%MSSdk%\Include\prerelease\Win64\crt;%MSSdk%\Include\prerelease\Win64\crt\sys;%MSSdk%\Include\prerelease\Win64\mfc;%MSSdk%\Include\prerelease\Win64\atl;%MSSdk%\Include
Set Path=%MSSdk%\Bin\prerelease\Win64;%MSSdk%\Bin\prerelease;%MSSdk%\Bin\prerelease\WinNT;%MSSdk%\Bin\Win64;%MSSdk%\Bin;%MSSdk%\Bin\WinNT;%path%
set APPVER=5.01
set TARGETOS=WINNT
Title Microsoft Platform SDK PreRelease 64-bit IE 5.5 %DEBUGMSG% Build Environment
Goto Set_WinNT_Cont

REM -------------------------------------------------------------------
:Chk_MsVC
REM -------------------------------------------------------------------
if "%CPU%" == "IA64" goto Chk_OS
If "x%MSVCDir%x" == "xx" Goto NotMsVcDirExists
If "x%MSDevDir%x" == "xx" Goto NotMsDevDirExists
REM We have MSDevDir and MSVCDir
goto Chk_OS


REM -------------------------------------------------------------------
:NotMsVcDirExists
REM -------------------------------------------------------------------
REM MSVCDir does not exist, does MSDevDir Exist?
IF "x%MSDevDir%x"=="xx" Goto DetectVC6

REM MSDevDir Exists. Can we derive MSVCDir from MSDevDir?
REM Check for VC6
IF NOT EXIST "%MSDevDir%\..\..\vc98\." Goto ChkVC5_MsVCDir
set MSVCDir=%MSDevDir%\..\..\vc98
goto Chk_OS

REM Check for VC5
:ChkVC5_MsVCDir
IF NOT EXIST "%MSDevDir%\..\VC\." Goto DetectVC6
set MSVCDir=%MSDevDir%\..\VC
goto Chk_OS


REM -------------------------------------------------------------------
:NotMsDevDirExists
REM -------------------------------------------------------------------
REM MSDevDir does not exist, does MSVCDir Exist?
IF "x%MSVCDir%x"=="xx" Goto DetectVC6

REM MSVCDir Exists. Can we derive MSDevDir from MSVCDir?
REM Check for VC6
IF NOT EXIST "%MSVCDir%\..\Common\msdev98\." Goto ChkVC5_MSDevDir

set MSDevDir=%MSVCDir%\..\Common\msdev98
goto Chk_OS

REM Check for VC5
:ChkVC5_MSDevDir
IF NOT EXIST "%MSVCDir%\..\SharedIDE\." Goto DetectVC6
set MSDevDir=%MSVCDir%\..\SharedIDE
goto Chk_OS


REM -------------------------------------------------------------------
REM Set RETAIL
REM -------------------------------------------------------------------
:set_RETAIL
set NODEBUG=1
set DEBUGMSG=RETAIL
goto Done_Retail


REM -------------------------------------------------------------------
REM Set DEBUG
REM -------------------------------------------------------------------
:set_DEBUG
set NODEBUG=
set DEBUGMSG=DEBUG
goto Done_Debug


REM -------------------------------------------------------------------
:DetectVC6
REM -------------------------------------------------------------------
Echo.
Echo Attempting to detect a Visual Studio 6 installation
Echo.
Call "setup\VCDetect.exe" "setup\VCInit.bat"
IF NOT EXIST "setup\VCInit.bat" goto ErrorVCEnv
Call "setup\VCInit.bat"
Echo.
goto Chk_OS


REM -------------------------------------------------------------------
:ErrorVCEnv
REM -------------------------------------------------------------------
Echo.
Echo Warning: The environmental variables MSDevDir and MSVCDir
Echo  were not found to exist. Check your Lib, Include and PATH to
Echo  verify that the SDK Lib, Include, and Bin directories precede
Echo  the compiler directories in the environment.
Echo.
Echo Note: Microsoft Visual Studio provides VCVARS32.BAT to Set them.
Echo  You must run VCVARS32.BAT first and then run SETENV.BAT.
Echo.
Echo Current settings:
Echo Lib=%Lib%
Echo Include=%Include%
Echo PATH=%PATH%
Echo.
Goto Finish

REM -------------------------------------------------------------------
:ErrorBadPath
REM -------------------------------------------------------------------
Echo.
Echo Error: The file "%MSSdk%\setenv.bat" does not appear to exist, or
Echo        an existing MSSdk env. variable does not match the expected
Echo        value encoded in this batch file by Platform SDK Setup.
Echo        Please check the path and an existing MSSdk variable
Echo        for correctness.
Echo.
Goto Finish

REM -------------------------------------------------------------------
:ErrorUsage9x_IA64
REM -------------------------------------------------------------------
echo.
echo Building Samples for the IA64 Platform is not currently supported on 
echo Windows 95, 98, Millennium or NT 4.0 Platforms.
echo.

REM -------------------------------------------------------------------
:ErrorUsage9x
REM -------------------------------------------------------------------
echo  "Usage Setenv [/2000 | /me | /pre32] [/DEBUG | /RETAIL]"
echo.
echo                 /2000 (default) - target Windows 2000 and IE 5.0
echo                 /me - target Windows Millennium
echo                 /pre32 - target all 32bit pre-release content
echo                 /DEBUG - set the environment to DEBUG
echo                 /RETAIL - set the environment to RETAIL
Goto Finish

REM -------------------------------------------------------------------
:ErrorUsage
REM -------------------------------------------------------------------
echo  "Usage Setenv [/2000 | /me | /pre32 | /pre64] [/DEBUG | /RETAIL]"
echo.
echo                 /2000 (default) - target Windows 2000 and IE 5.0
echo                 /me - target Windows Millennium
echo                 /pre32 - target all 32bit pre-release content
echo                 /pre64 - target Windows 64bit pre-release content not available on 9x or Me platforms
echo                 /DEBUG - set the environment to DEBUG
echo                 /RETAIL - set the environment to RETAIL
Goto Finish


REM -------------------------------------------------------------------
:end
set DEBUGMSG=
REM -------------------------------------------------------------------