@echo off
setlocal
set "EXE=%~dp0build\Debug\week01_mario.exe"

if not exist "%EXE%" (
    echo [!] 还没编译过。请用 Visual Studio 打开 week01.sln 后按 Ctrl+Shift+B。
    echo.
    pause
    exit /b 1
)

"%EXE%"
echo.
echo ========== 程序跑完了，按任意键关掉这个窗口 ==========
pause >nul
