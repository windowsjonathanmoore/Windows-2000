@echo off

rem *** set directory locations HERE ***************
set PLATFORM_SDK=c:\mssdk

set LIB=%PLATFORM_SDK%\lib;%LIB%
set INCLUDE=%PLATFORM_SDK%\include;%INCLUDE%
nmake /f booksrvr.mk
