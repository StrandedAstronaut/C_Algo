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
double custom_sqrt(double x) {
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
double custom_cbrt(double x) {
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
int custom_round(double x) {
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
int custom_ceil(double x) {
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
int custom_floor(double x) {
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

double custom_sin(double x)
{
    // 1. ��x��һ����[-��, ��]���䣬���ټ������
    x = custom_fmod(x, 2 * PI);  // ȡģ���㣬�õ�[0, 2��)�����ֵ
    if (x > PI) {
        x -= 2 * PI;      // �����ڦе�ֵת����[-��, 0)����
    }
    
    double result = 0.0;  // �����ʼ��Ϊ0
    double term = x;      // ̩�ռ����ĵ�һ����x
    int sign = 1;         // ���ţ�����仯
    int i = 1;            // ����������
    
    // 2. ��������̩�ռ�����ֱ�����㹻С
    while (abs_double(term) > EPSILON) {
        result += sign * term;
        
        // ������һ��: ����ǰһ����㣬�����ظ�����
        // ��һ�� = ��ǰ�� * x�0�5 / [(2i)*(2i+1)]
        term *= x * x / ((2 * i) * (2 * i + 1));
        sign *= -1;  // ���Ž���
        i++;
    }
    
    return result;
}

double custom_cos(double x)
{
    return custom_sin(x + PI / 2);
}

// ���к���ͨ��sin(x)/cos(x)ʵ��
double custom_tan(double x) {
    double cos_val = custom_cos(x);
    
    // ���cosֵ�Ƿ�ӽ��㣬����������
    if (abs_double(cos_val) < EPSILON) {
        // ����һ����ֵ�������ģ����ʵtan�����ڽӽ���/2+k�д�����Ϊ
        return (cos_val > 0) ? 1.0 / EPSILON : -1.0 / EPSILON;
    }
    
    return custom_sin(x) / cos_val;
}

// �����Һ��� - ʹ��̩�ռ���ʵ��
double custom_asin(double x) {
    // �������뷶Χ���
    if (x < -1.0) x = -1.0;
    if (x > 1.0) x = 1.0;
    
    // �����������
    if (abs_double(x) == 1.0) {
        return (x > 0) ? PI / 2 : -PI / 2;
    }
    
    // ʹ��̩�ռ���չ�����㷴���Һ���
    // asin(x) = x + (1/2)x^3/3 + (1��3)/(2��4)x^5/5 + (1��3��5)/(2��4��6)x^7/7 + ...
    double result = x;
    double term = x;
    double numerator = 1.0;
    double denominator = 2.0;
    double x_squared = x * x;
    
    for (int n = 1; n <= 20; n++) {  // 20���㹻��ȷ
        term = term * x_squared * numerator / denominator;
        numerator += 2.0;
        denominator += 2.0;
        result += term / numerator;
    }
    
    return result;
}

// �����Һ���ͨ����/2 - asin(x)ʵ��
double custom_acos(double x) {
    return PI / 2 - custom_asin(x);
}

// �����к��� - ʹ��̩�ռ���ʵ��
double custom_atan(double x) {
    // �����������
    if (abs_double(x) < EPSILON) {
        return 0.0;
    }
    
    // ����|x| > 1�������ʹ��atan(x) = ��/2 - atan(1/x)��-��/2 - atan(1/x)
    if (abs_double(x) > 1.0) {
        if (x > 0) {
            return PI / 2 - atan(1.0 / x);
        } else {
            return -PI / 2 - atan(1.0 / x);
        }
    }
    
    // ʹ��̩�ռ���չ�����㷴���к���
    // atan(x) = x - x^3/3 + x^5/5 - x^7/7 + ...
    double result = x;
    double term = x;
    double x_squared = x * x;
    
    for (int n = 1; n <= 20; n++) {  // 20���㹻��ȷ
        term = -term * x_squared;
        result += term / (2 * n + 1);
    }
    
    return result;
}

/**
 * @brief ����x����y������
 * 
 * @param x ������
 * @param y ����
 * @return double x����y��������������x��ͬ
 */
double custom_fmod(double x, double y) {
    // �����������
    if (y == 0) {
        return 0.0;  // ����Ϊ0ʱ����0
    }
    
    if (x == 0) {
        return 0.0;  // ������Ϊ0ʱ����0
    }
    
    // �����̲�ȡ��
    double quotient = x / y;
    int integer_part;
    
    if (quotient >= 0) {
        integer_part = (int)quotient;  // ��������������ȡ��
    } else {
        integer_part = (int)quotient - 1;  // ���ڸ���������ȡ��
    }
    
    // ��������
    double remainder = x - integer_part * y;
    
    return remainder;
}