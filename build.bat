@echo off

set VS2017PATH=D:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build

call "%VS2017PATH%\vcvarsall.bat" x86
devenv DuiLib.sln /Project DuiLib /Rebuild "Release|Win32"

:: include
if exist include rmdir include /s /q
mkdir include
mkdir include\Utils
mkdir include\Layout
mkdir include\Core
mkdir include\Control

copy DuiLib\UIlib.h include /y
copy DuiLib\Utils\*.h include\Utils /y
copy DuiLib\Layout\*.h include\Layout /y
copy DuiLib\Core\*.h include\Core /y
copy DuiLib\Control\*.h include\Control /y

::libs
if exist libs rmdir libs /s /q
mkdir libs

copy bin\DuiLib.lib libs\ /y
copy bin\DuiLib.dll libs\ /y


pause