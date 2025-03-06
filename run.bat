@echo off
echo =====================================================
echo     Virtual World Game Compilation and Execution
echo =====================================================
echo.

REM Check if src directory exists
if not exist src\ (
    echo ERROR: src directory not found!
    echo Please run this script from the project root directory.
    goto :exit
)

echo Compiling the game...
cd src
g++ -o ..\VirtualWorld.exe *.cpp Core\*.cpp Animals\*.cpp Plants\*.cpp
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo Compilation failed!
    goto :exit
)

echo.
echo =====================================================
echo Compilation successful!
echo =====================================================
echo.
echo Press any key to start the game...
pause > nul

echo Starting the game...
cd ..
VirtualWorld.exe

:exit
echo.
echo Press any key to exit...
pause > nul
