@echo off
echo [SYNCE BUILD] Building Synce compiler...
make

@echo off
setlocal
set CXX=g++
set FLAGS=-std=c++20 -O2 -Wall
set LINK=-lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32

echo Building VACU Runtime...
g++ %FLAGS% ^
    core\\*.cpp ^
    render\\*.cpp ^
    audio\\*.cpp ^
    optimize\\*.cpp ^
    ai\\*.cpp ^
    runtime\\*.cpp ^
    compiler\\*.cpp ^
    -o vacu_runtime.exe %LINK%

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)

echo Build successful!
endlocal
