@echo off
rem =======================================================================
rem
rem     BUILD.BAT
rem
rem     Builds demo application
rem
rem     "Syntax: build [debug32 | ndebug32]"
rem
rem =======================================================================
rem


rem --- Check for environment space ---
set typ=d16
set ok=N

if NOT "%ok%" == "N" goto err_env

rem --- Parse arguments ---
:parse
if "%1" == "" goto check
if "%1" == "debug32" goto debug32
if "%1" == "ndebug32" goto ndebug32
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
if "%typ%" == "n32" nmake /f cdsnbld.mak WIN32=YES
if "%typ%" == "d32" nmake /f cdsnbld.mak WIN32=YES DEBUG=YES
goto end


rem --- Out of environment space ---
:err_env
echo.
echo Error: out of environment space
echo.
goto end


rem --- Invalid operating system environment ---
:err_ops
echo.
echo Error: Windows NT or Windows 95 required to build debug32 or ndebug32
echo.
goto end


rem --- Usage message ---
:err_usage
echo.
echo "Usage: BUILD [debug32 | ndebug32]"
echo.
goto end


rem --- Clear environment variables ---
:end
set typ=
set ok=
