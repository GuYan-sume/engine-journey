@echo off
setlocal
rem Switch the console to UTF-8 so Chinese output is not garbled.
chcp 65001 >nul
rem ============================================================
rem  Optional shortcut: build and run a .c or .cpp without
rem  creating a Visual Studio project (VS project is still the
rem  main way).
rem  Usage: tools\build_run.bat month01\week01\hello.cpp
rem         tools\build_run.bat month01\week03\demo.c
rem  Uses /utf-8 so Chinese comments do not raise warning C4819.
rem    .c   -> /std:c17 + _CRT_SECURE_NO_WARNINGS (keeps scanf usable)
rem    .cpp -> /EHsc + /std:c++17
rem ============================================================
if "%~1"=="" (
    echo Usage  : tools\build_run.bat ^<source.c or source.cpp^>
    echo Example: tools\build_run.bat month01\week01\hello.cpp
    exit /b 1
)
set "VSDIR="
for /f "usebackq tokens=*" %%i in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSDIR=%%i"
if "%VSDIR%"=="" set "VSDIR=C:\Program Files\Microsoft Visual Studio\2022\Community"
if not exist "%VSDIR%\Common7\Tools\VsDevCmd.bat" (
    echo [ERROR] Visual Studio C++ tools not found. Install VS 2022 Community with the C++ workload.
    exit /b 1
)
call "%VSDIR%\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64 -no_logo >nul

set "BUILDFLAGS=/nologo /utf-8 /W4 /EHsc /std:c++17"
if /i "%~x1"==".c" set "BUILDFLAGS=/nologo /utf-8 /W4 /D_CRT_SECURE_NO_WARNINGS /std:c17"

pushd "%~dp1"
echo [BUILD] %~nx1  [%BUILDFLAGS%]
cl %BUILDFLAGS% "%~nx1"
if errorlevel 1 (
    echo.
    echo [FAILED] Read the FIRST error line only the rest is usually noise.
    popd
    exit /b 1
)
echo.
echo [RUN] %~n1.exe
echo ----------------------------------------
"%~n1.exe"
echo ----------------------------------------
popd
endlocal