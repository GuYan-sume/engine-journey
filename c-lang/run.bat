@echo off
setlocal
rem ============================================================
rem  c-lang : compile and run a .c file in this folder.
rem
rem  Four ways to use it:
rem    1) double-click run.bat        - it asks which file to run
rem    2) drag a .c file onto run.bat
rem    3) c-lang\run.bat 01_hello.c   (from the repo root)
rem    4) run.bat 01_hello.c          (from inside c-lang)
rem
rem  It always pauses at the end so you can read the output.
rem  Forwards to ..\tools\build_run.bat, which picks
rem  /std:c17 + _CRT_SECURE_NO_WARNINGS for .c files.
rem ============================================================
chcp 65001 >nul

if not "%~1"=="" goto runfile

echo.
echo  ==================================================
echo    c-lang  -  choose a .c file to compile and run
echo  ==================================================
echo.
echo  .c files in this folder:
for %%f in ("%~dp0*.c") do echo       %%~nxf
echo.
set "PICK="
set /p "PICK= Type a name (example: 01_hello.c) then press Enter: "
for /f "tokens=1 delims= " %%a in ("%PICK%") do set "PICK=%%a"
if "%PICK%"=="" goto done

set "SRC=%~dp0%PICK%"
if not exist "%SRC%" set "SRC=%~dp0%PICK%.c"
if not exist "%SRC%" (
    echo.
    echo  [ERROR] File not found: %PICK%
    goto done
)
call "%~dp0..\tools\build_run.bat" "%SRC%"
goto done

:runfile
set "SRC=%~1"
if exist "%~dp0%~1" set "SRC=%~dp0%~1"
call "%~dp0..\tools\build_run.bat" "%SRC%"

:done
echo.
pause
endlocal