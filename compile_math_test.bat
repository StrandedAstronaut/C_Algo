@echo off
REM �򵥱���ű�

mkdir build 2>nul
mkdir build\math 2>nul

REM ������ѧ��Դ�ļ�
gcc -Wall -Wextra -Iinclude -O2 -c src\math\math.c -o build\math\math.o

REM ������Գ���
gcc -Wall -Wextra -Iinclude -O2 test\test_math.c build\math\math.o -o build\test_math -lm

if %ERRORLEVEL% EQU 0 (
    echo ����ɹ������Գ���λ�� build\test_math.exe
) else (
    echo ����ʧ�ܣ�
)