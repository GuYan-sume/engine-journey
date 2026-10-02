@echo off
rem ============================================================
rem  Compile & run one .c file in this folder.
rem
rem  Three ways to use it:
rem    1) c-lang\run.bat 01_hello.c      (run from the repo root)
rem    2) run.bat 01_hello.c              (run from inside c-lang)
rem    3) drag a .c file onto run.bat
rem
rem  With no argument it just lists the .c files in this folder.
rem  This forwards to ..\tools\build_run.bat, which picks
rem  /std:c17 + _CRT_SECURE_NO_WARNINGS for .c files.
rem ============================================================
if "%~1"=="" (
    echo Usage  : run.bat ^<file.c^>
    echo Example: run.bat 01_hello.c
    echo Tip    : you can also drag a .c file onto this file
    echo.
    echo .c files in this folder:
    for %%f in ("%~dp0*.c") do echo    %%~nxf
    exit /b 1
)
set "SRC=%~1"
if exist "%~dp0%~1" set "SRC=%~dp0%~1"
call "%~dp0..\tools\build_run.bat" "%SRC%"