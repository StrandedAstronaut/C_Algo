/*
 * ��ѧ�⺯��ʵ��
 */
#include "../../include/math/math.h"
#include <stdio.h>

/**
 * ���������ľ���ֵ
 */
int abs_int(int x) {
    return (x < 0) ? -x : x;
}

/**
 * ���㸡�����ľ���ֵ
 */
double abs_double(double x) {
    return (x < 0) ? -x : x;
}

/**
 * ���������������ֵ
 */
int max_int(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * �������������������ֵ
 */
double max_double(double a, double b) {
    return (a > b) ? a : b;
}

/**
 * ��������������Сֵ
 */
int min_int(int a, int b) {
    return (a < b) ? a : b;
}

/**
 * ������������������Сֵ
 */
double min_double(double a, double b) {
    return (a < b) ? a : b;
}

/**
 * ����x��n���ݣ������ݣ�
 */
double power(double x, int n) {
    // �����������
    if (n == 0) {
        return 1.0;  // �κ�����0���ݶ���1
    }
    
    if (n < 0) {
        // ��ָ�������㵹��
        return 1.0 / power(x, -n);
    }
    
    // ʹ�ÿ������㷨
    double result = 1.0;
    double base = x;
    
    while (n > 0) {
        if (n % 2 == 1) {
            result *= base;
        }
        base *= base;
        n /= 2;
    }
    
    return result;
}

/**
 * ����x��ƽ������ʹ��ţ�ٵ�������
 */
double sqrt(double x) {
    // �������
    if (x < 0) {
        return 0.0;  // ����û��ʵ��ƽ����
    }
    
    if (x == 0 || x == 1) {
        return x;  // 0��1��ƽ�����������Լ�
    }
    
    // ţ�ٵ���������ƽ����
    double precision = 1e-10;  // ����Ҫ��
    double guess = x / 2.0;    // ��ʼ�²�ֵ
    
    while (abs_double(guess * guess - x) > precision) {
        guess = (guess + x / guess) / 2.0;
    }
    
    return guess;
}

/**
 * ����x��������
 */
double cbrt(double x) {
    // �����������
    if (x == 0 || x == 1 || x == -1) {
        return x;  // 0��1��-1���������������Լ�
    }
    
    // ȷ������
    int sign = (x < 0) ? -1 : 1;
    double abs_x = abs_double(x);
    
    // ţ�ٵ���������������
    double precision = 1e-10;  // ����Ҫ��
    double guess = abs_x / 3.0;  // ��ʼ�²�ֵ
    
    while (abs_double(guess * guess * guess - abs_x) > precision) {
        guess = (2 * guess + abs_x / (guess * guess)) / 3.0;
    }
    
    return sign * guess;
}

/**
 * �������뵽��ӽ�������
 */
int round_double(double x) {
    // ��������������0.5������ȡ��
    // ���ڸ�������ȥ0.5������ȡ��
    if (x >= 0) {
        return (int)(x + 0.5);
    } else {
        return (int)(x - 0.5);
    }
}

/**
 * ����ȡ��
 */
int ceil_double(double x) {
    int integer_part = (int)x;
    // ���x����������Ϊ���������1
    if (x > 0 && x != integer_part) {
        return integer_part + 1;
    }
    // ���x�Ǹ����Ҳ����������򷵻���������
    if (x < 0 && x != integer_part) {
        return integer_part;
    }
    // x������
    return integer_part;
}

/**
 * ����ȡ��
 */
int floor_double(double x) {
    int integer_part = (int)x;
    // ���x�Ǹ����Ҳ������������1
    if (x < 0 && x != integer_part) {
        return integer_part - 1;
    }
    // x������������
    return integer_part;
}

/**
 * �ж�һ�����Ƿ�Ϊ����
 */
int is_prime(int n) {
    // �����������
    if (n <= 1) {
        return 0;  // 1��С��1������������
    }
    
    if (n <= 3) {
        return 1;  // 2��3������
    }
    
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;  // �ܱ�2��3����������������
    }
    
    // ����5��ʼ�����п������ӣ�ֱ��sqrt(n)
    // ֻ��Ҫ���6k��1��ʽ����
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    
    return 1;
}

/**
 * ���������������Լ����GCD��
 * ʹ��ŷ������㷨
 */
int gcd(int a, int b) {
    // ���������
    a = abs_int(a);
    b = abs_int(b);
    
    // ŷ������㷨
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

/**
 * ��������������С��������LCM��
 * LCM(a,b) = |a*b| / GCD(a,b)
 */
int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;  // 0���κ�������С��������0
    }
    
    // ����LCM
    // ʹ��abs_intȷ�����Ϊ����
    return abs_int(a * b) / gcd(a, b);
}