@echo off
setlocal
rem ============================================================
rem  Optional shortcut: build and run a .cpp without creating a
rem  Visual Studio project (VS project is still the main way).
rem  Usage: tools\build_run.bat month01\week01\hello.cpp
rem  Uses /utf-8 so Chinese comments do not raise warning C4819.
rem ============================================================
if "%~1"=="" (
    echo Usage  : tools\build_run.bat ^<source.cpp^>
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
pushd "%~dp1"
echo [BUILD] %~nx1
cl /nologo /EHsc /std:c++17 /utf-8 /W4 "%~nx1"
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