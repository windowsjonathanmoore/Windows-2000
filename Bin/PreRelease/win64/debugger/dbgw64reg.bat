echo off
set RegistryRoot=Software\Microsoft\DbgW64\7.0

if %NoCase% "%1"=="/?" goto PrintSyntax
if %NoCase% "%1"=="-?" goto PrintSyntax
if %NoCase% "%1"=="/h" goto PrintSyntax
if %NoCase% "%1"=="-h" goto PrintSyntax

rem mdm does not get to run while we do this
net stop mdm

rem clean up registry
delkey "HKEY_LOCAL_MACHINE\Software\Microsoft\DbgW64" 2^>1
delkey "HKEY_CURRENT_USER\Software\Microsoft\DbgW64" 2^>1


echo Installing MSO10 and MSXML3
msiexec /qn /i mso10.msi
msiexec /qn /i msxml3.msi

echo Copying preferences file...
copy dbgw64.xml "%APPDATA%"\Microsoft\DbgW64\7.0\dbgw64.xml

set D=""
if exist vspkgs\vsslnd.dll set D="d"

echo Registering the files...

regit /root:%RegistryRoot% /v vspkgs\msenv.dll
regit /root:%RegistryRoot% /v vspkgs\cmddef.dll
regit /root:%RegistryRoot% /v DbgW64Pkgs\DbgW64mnu.dll
regit /root:%RegistryRoot% /v vspkgs\vssln%D%.dll
regit /root:%RegistryRoot% /v vspkgs\vsdebug.dll
regit /root:%RegistryRoot% /v vspkgs\vscontxt.dll
regit /root:%RegistryRoot% /v sdm2.dll
regit msdbg2.dll
regit /root:%RegistryRoot% /v natdbgde%D%.dll

if exist mdm.exe mdm -service

DbgW64.exe /setup /selfreg

cscript dbgw64fix.vbs

goto end

:PrintSyntax
echo Registers dlls for the Native 64-bit Debugger.
echo Must be run from a directory containing an installation of DbgW64.
goto end

:end
