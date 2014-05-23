@ECHO OFF

if not defined ALTERNATIVE_CPP_LIB_PATH set ALTERNATIVE_CPP_LIB_PATH=%CD%
set ALTERNATIVE_LIB_BUILD=%ALTERNATIVE_CPP_LIB_PATH%\build
set ALTERNATIVE_LIB_BIN=%ALTERNATIVE_CPP_LIB_PATH%\build\bin

if not exist %ALTERNATIVE_LIB_BIN% mkdir %ALTERNATIVE_LIB_BIN%
cd %ALTERNATIVE_LIB_BIN%
del CMakeCache.txt
cmake -G "Visual Studio 11" ..

for /D %%D in (%SYSTEMROOT%\Microsoft.NET\Framework\v4*) do set msbuildPath=%%D
cd %msbuildPath%
msbuild.exe %ALTERNATIVE_LIB_BIN%\AlterNativeLib.sln /p:PlatformToolset=v120_CTP_Nov2012

if not exist %ALTERNATIVE_LIB_BUILD%\libfiles mkdir %ALTERNATIVE_LIB_BUILD%\libfiles
::TODO -> How to fix these ugly paths ?
cd %ALTERNATIVE_LIB_BIN%
copy src\public\gc\Debug\gc-lib.lib ..\libfiles
copy src\Debug\System.lib ..\libfiles
cd %ALTERNATIVE_CPP_LIB_PATH%