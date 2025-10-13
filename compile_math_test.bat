@echo off
REM 简单编译脚本

mkdir build 2>nul
mkdir build\math 2>nul

REM 编译数学库源文件
gcc -Wall -Wextra -Iinclude -O2 -c src\math\math.c -o build\math\math.o

REM 编译测试程序
gcc -Wall -Wextra -Iinclude -O2 test\test_math.c build\math\math.o -o build\test_math -lm

if %ERRORLEVEL% EQU 0 (
    echo 编译成功！测试程序位于 build\test_math.exe
) else (
    echo 编译失败！
)