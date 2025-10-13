@echo off
REM �򵥵�������ű����ڱ�����ѧ��Ͳ��Գ���

REM ���ñ������ͱ���ѡ��
set CC=gcc
set CFLAGS=-Wall -Wextra -Iinclude -O2
set LDFLAGS=-lm

REM ����buildĿ¼
if not exist build mkdir build
if not exist build\math mkdir build\math
if not exist build\examples mkdir build\examples

REM ������ѧ��Դ�ļ�
echo ������ѧ��Դ�ļ�...
%CC% %CFLAGS% -c src\math\math.c -o build\math\math.o

REM ���������Դ�ļ�
echo ���������Դ�ļ�...
%CC% %CFLAGS% -c src\sort\quick_sort.c -o build\sort\quick_sort.o

REM ������̬��
echo ������̬��...
ar rcs build\libalgorithm.a build\math\math.o build\sort\quick_sort.o

REM ������Գ���
echo ������Գ���...
%CC% %CFLAGS% test\test_math.c build\libalgorithm.a -o build\test_math %LDFLAGS%

REM ����ʾ������
echo ����ʾ������...
%CC% %CFLAGS% examples\math_example.c build\libalgorithm.a -o build\examples\math_example %LDFLAGS%

echo ������ɣ�
echo.