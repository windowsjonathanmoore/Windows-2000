@echo off
rem ********************************************************************
rem
rem     BUILD.BAT
rem
rem     Builds an autotest
rem
rem ********************************************************************
rem


if "%1" == "" goto err_usage
if "%2" == "" goto err_usage

rem @echo on
rem ********************************************************************
rem Determine platform
rem ********************************************************************
if '%PROCESSOR_ARCHITECTURE%'=='' set PROCESSOR_ARCHITECTURE=x86
set CPU=%PROCESSOR_ARCHITECTURE%
if '%CPU%' == 'x86' set CPU=i386

rem --- Check for environment space ---
set clean=
set typ=d32
set ok=N
set ver=INHOUSE30
set pok=N
set uni=NOUNICODE
set dbg=
set TSTNM=

if NOT "%ok%" == "N" goto err_env
if NOT "%pok%" == "N" goto err_env

if "%1" == "?" goto err_usage

set TSTNM=%1
shift

rem --- Parse arguments ---
:parse
if "%1" == "" goto doit
if "%1" == "clean" goto clean
if "%1" == "-clean" goto clean
if "%1" == "debug32" goto debug32
if "%1" == "-debug32" goto debug32
if "%1" == "ndebug32" goto ndebug32
if "%1" == "-ndebug32" goto ndebug32
if "%1" == "-?" goto err_usage
if "%1" == "?" goto err_usage
if "%1" == "debug" set dbg=/D /P
shift
goto parse

rem --- Handle "clean" ---
:clean
set clean=/a
shift
goto parse

rem --- Handle "debug32" ---
:debug32
if not exist debug32\nul mkdir debug32
if "%ok%" == "Y" goto err_usage
set ok=Y
set typ=d32
shift
goto parse

rem --- Handle "ndebug32" ---
:ndebug32
if not exist ndebug32\nul mkdir ndebug32
if "%ok%" == "Y" goto err_usage
set ok=Y
set typ=n32
shift
goto parse

rem --- Verify correctness of everything ---
:check
if NOT "%ok%" == "Y" goto err_usage
goto doit

rem --- Make the demo ---
:doit
if "%typ%" == "n32" goto n32
if "%typ%" == "d32" goto d32
goto end

:n32
if NOT "%dbg%"=="" echo nmake %dbg% %clean% /f qtmake.mak WIN32 %ver% %uni%
nmake %dbg% %clean% /f qtmake.mak WIN32= %ver%= %uni%=
goto end
:d32
if NOT "%dbg%"=="" echo nmake %dbg% %clean% /f qtmake.mak WIN32 DEBUG %ver% %uni%
nmake %dbg% %clean% /f qtmake.mak WIN32= DEBUG= %ver%= %uni%=
goto end

rem --- Out of environment space ---
:err_env
echo.
echo Error: out of environment space
echo.
goto end

rem --- Platform not supported ---
:err_cpu
echo.
echo Error: Platform not supported by QTBUILD.BAT
echo.
goto end

rem --- Usage message ---
:err_usage
echo.
echo Usage: QTBUILD TestName [OPTIONS]
echo.
echo Options: debug32    Generates debug 32 bit code
echo          ndebug32   Generates non-debug 32 bit code
echo          clean      Builds Clean
echo          ?          Displays Help
echo.
echo     Note: Make sure that your Windows and ODBC SDK environment
echo        are set up properly.
echo.
goto end

rem --- Clear environment variables ---
:end
set clean=
set typ=
set ok=
set app=
set pok=
set CPU=
set DNATOOLS=
set COMPILER=
set TOOLSBIN=
set TOOLSINC=
set TOOLSLIB=
set NMAKE=
set ver=
set dbg=
