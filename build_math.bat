@echo off
REM 简单的批处理脚本用于编译数学库和测试程序

REM 设置编译器和编译选项
set CC=gcc
set CFLAGS=-Wall -Wextra -Iinclude -O2
set LDFLAGS=-lm

REM 创建build目录
if not exist build mkdir build
if not exist build\math mkdir build\math
if not exist build\examples mkdir build\examples

REM 编译数学库源文件
echo 编译数学库源文件...
%CC% %CFLAGS% -c src\math\math.c -o build\math\math.o

REM 编译排序库源文件
echo 编译排序库源文件...
%CC% %CFLAGS% -c src\sort\quick_sort.c -o build\sort\quick_sort.o

REM 创建静态库
echo 创建静态库...
ar rcs build\libalgorithm.a build\math\math.o build\sort\quick_sort.o

REM 编译测试程序
echo 编译测试程序...
%CC% %CFLAGS% test\test_math.c build\libalgorithm.a -o build\test_math %LDFLAGS%

REM 编译示例程序
echo 编译示例程序...
%CC% %CFLAGS% examples\math_example.c build\libalgorithm.a -o build\examples\math_example %LDFLAGS%

echo 编译完成！
echo.