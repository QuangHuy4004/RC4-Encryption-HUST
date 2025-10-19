@echo off
gcc *.c -o main
if %errorlevel% neq 0 (
    echo Loi bien dich
    pause
    exit /b
)
echo.
main.exe
echo.
pause
