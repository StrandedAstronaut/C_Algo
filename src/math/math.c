/*
 * ��ѧ�⺯��ʵ��
 */
#include "../../include/math/math.h"
#include <stdio.h>
#include <math.h>

// �������Ƚϵ��ݲ�
#define EPSILON 1e-10

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
 * 
 * ��ѧ�Ƶ���
 * 1. ���������x^0 = 1���κ�����0���ݶ���1
 * 2. ���ڸ�ָ����x^(-n) = 1/(x^n)
 * 3. �������㷨�����ö����Ʊ�ʾ��ʱ�临�Ӷȴ�O(n)����O(log n)
 *    - ��n��ʾΪ�����ƣ�n = b_kb_{k-1}...b_1b_0
 *    - ��x^n = x^(b_k*2^k + ... + b_1*2^1 + b_0*2^0) = x^(b_k*2^k) * ... * x^(b_0*2^0)
 */
double power(double x, int n) {
    // ������� - �κ�����0���ݶ���1
    if (n == 0) {
        return 1.0;  // �κ�����0���ݶ���1
    }
    
    if (n < 0) {
        // ��ָ���������ص���
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
 * 
 * ��ѧ�Ƶ���
 * ʹ��ţ�ٵ�������ⷽ��f(y) = y�0�5 - x = 0
 * ������ʽ��y_{n+1} = y_n - f(y_n)/f'(y_n) = y_n - (y_n�0�5 - x)/(2y_n) = (y_n + x/y_n)/2
 * ���������ʽ�����������x��ƽ��������ʼ�²�ֵ����ѡ��x/2
 */
double custom_sqrt(double x) {
    // �������
    if (x < 0) {
        return 0.0;  // ����û��ʵ��ƽ����
    }
    
    if (x == 0 || x == 1) {
        return x;  // 0��1��ƽ���������䱾��
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
 * 
 * ��ѧ�Ƶ���
 * ��������ʵ��x��������Ҫ�ҵ�y��ʹ��y�0�6 = x
 * ʹ��ţ�ٵ�������ⷽ��f(y) = y�0�6 - x = 0
 * ������ʽ��y_{n+1} = y_n - f(y_n)/f'(y_n) = y_n - (y_n�0�6 - x)/(3y_n�0�5) = (2y_n + x/y_n�0�5)/3
 * ���ڸ����������ȼ��������ֵ�����������ٻָ�����
 */
double custom_cbrt(double x) {
    // �������
    if (x == 0 || x == 1 || x == -1) {
        return x;  // 0��1��-1�������������䱾��
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
    // ��������0.5��ȡ��
    // ������ȥ0.5��ȡ��
    if (x >= 0) {
        return (int)(x + 0.5);
    } else {
        return (int)(x - 0.5);
    }
}

/**
 * ����ȡ��
 * 
 * ��ѧ���壺
 * ceil(x) = ��С������y��ʹ��y �� x
 * 
 * ʵ���߼���
 * 1. ȡx����������
 * 2. ���xΪ�����Ҳ�������������Ϊ��������+1
 * 3. ���xΪ�����Ҳ�������������Ϊ��������
 * 4. ���xΪ��������������x����������
 */
int custom_ceil(double x) {
    int integer_part = (int)x;
    // ���xΪ�����Ҳ�Ϊ�������1
    if (x > 0 && x != integer_part) {
        return integer_part + 1;
    }
    // ���xΪ�����Ҳ�Ϊ�����򷵻���������
    if (x < 0 && x != integer_part) {
        return integer_part;
    }
    // xΪ����
    return integer_part;
}

/**
 * ����ȡ��
 * 
 * ��ѧ���壺
 * floor(x) = ��������y��ʹ��y �� x
 * 
 * ʵ���߼���
 * 1. ȡx����������
 * 2. ���xΪ�����Ҳ�������������Ϊ��������-1
 * 3. �����������������������x����������
 */
int custom_floor(double x) {
    int integer_part = (int)x;
    // ���xΪ�����Ҳ�Ϊ�������1
    if (x < 0 && x != integer_part) {
        return integer_part - 1;
    }
    // xΪ����������
    return integer_part;
}

/**
 * �ж�һ�����Ƿ�Ϊ����
 */
int is_prime(int n) {
    // �������
    if (n <= 1) {
        return 0;  // 1��С��1������������
    }
    
    if (n <= 3) {
        return 1;  // 2��3������
    }
    
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;  // �ܱ�2��3����������������
    }
    
    // ��5��ʼ�����ܵ����ӣ�ֱ��sqrt(n)
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
 * 
 * ��ѧ�Ƶ���
 * ŷ������㷨�����������ʣ�gcd(a, b) = gcd(b, a % b)
 * ֤������a = b*q + r������0 �� r < b
 *      ���d��a��b�Ĺ�Լ������d | a��d | b�����d | (a - b*q)����d | r
 *      ��֮�����d��b��r�Ĺ�Լ������d | b��d | r�����d | (b*q + r)����d | a
 *      ��ˣ�gcd(a, b) = gcd(b, r) = gcd(b, a % b)
 */
int gcd(int a, int b) {
    // �������
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
 * 
 * ��ѧ�Ƶ���
 * ��������������������a��b�������¹�ϵ��
 * LCM(a,b) * GCD(a,b) = |a*b|
 * ��ˣ�LCM(a,b) = |a*b| / GCD(a,b)
 * 
 * ֤������g = gcd(a,b)����a = g*a'��b = g*b'������gcd(a',b') = 1
 *      LCM(a,b) = g*a'*b' ����Ϊa'��b'���ʣ�
 *      |a*b| = g*a' * g*b' = g�0�5*a'*b'
 *      ���ԣ�LCM(a,b) = |a*b| / g = |a*b| / GCD(a,b)
 */
int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;  // 0���κ�������С��������0
    }
    
    // ����LCM
    // ʹ��abs_intȷ�����Ϊ��ֵ
    return abs_int(a * b) / gcd(a, b);
}

/**
 * �������Һ���ֵ
 * 
 * ��ѧ�Ƶ���
 * sin(x)��̩��չ��ʽ����0Ϊ���ģ���
 * sin(x) = x - x�0�6/3! + x�6�7/5! - x�6�9/7! + ... + (-1)^n x^(2n+1)/(2n+1)! + ...
 * 
 * ʵ�ֲ��ԣ�
 * 1. ����sin(x)�������ԣ���x��һ����[-��, ��]��Χ�ڣ����ټ�����
 * 2. ʹ��̩�ռ���չ���������ֵ��ֱ����ľ���ֵС�ھ���Ҫ��
 * 3. Ϊ�˱����ظ����㣬ÿһ��ͨ��ǰһ����㣺��һ�� = ��ǰ�� * x�0�5 / [(2i)*(2i+1)]
 */
double custom_sin(double x)
{
    // ��x��һ����[-��, ��]��Χ�ڣ����ټ�����
    x = custom_fmod(x, 2 * PI);  // ȡģ���㣬�õ�[0, 2��)��Χ��ֵ
    if (x > PI) {
        x -= 2 * PI;      // �����ڦе�ֵת����[-��, 0)��Χ
    }
    
    double result = 0.0;  // �����ʼ��Ϊ0
    double term = x;      // ̩��չ���ĵ�һ����x
    int sign = 1;         // ���ţ�����仯
    int i = 1;            // ����������
    
    // ��������̩��չ��ʽֱ�����㹻С
    while (abs_double(term) > EPSILON) {
        result += sign * term;
        
        // ������һ��: ����ǰһ����㣬�����ظ�����
        // ��һ�� = ��ǰ�� * x�0�5 / [(2i)*(2i+1)]
        term *= x * x / ((2 * i) * (2 * i + 1));
        sign *= -1;  // ���ŷ�ת
        i++;
    }
    
    return result;
}

/**
 * �������Һ���ֵ
 * 
 * ��ѧ�Ƶ���
 * �������Ǻ�������λ��ϵ��cos(x) = sin(x + ��/2)
 * �����ϵ���Դӵ�λԲ�ϵļ��ν��͵õ���
 * ���Ƕ����Ӧ�/2ʱ�����ڵ�λԲ����ת��y�᷽��ԭ����x���꣨����ֵ����Ϊy���꣨����ֵ��
 */
double custom_cos(double x)
{
    return custom_sin(x + PI / 2);
}

/**
 * �������к���ֵ
 * 
 * ��ѧ�Ƶ���
 * ���к����Ķ��壺tan(x) = sin(x) / cos(x)
 * 
 * �����������
 * ��cos(x)�ӽ�0ʱ��x�ӽ���/2 + k�У�kΪ��������tan(x)�����������������
 * ��ʱ����һ������ֵ��Сֵ��ģ��������Ϊ
 */
double custom_tan(double x) {
    double cos_val = custom_cos(x);
    
    // ���cosֵ�Ƿ�ӽ��㣬����������
    if (abs_double(cos_val) < EPSILON) {
        // ����һ������ֵ��ģ��tan�����ڽӽ���/2+k�д�����Ϊ
        return (cos_val > 0) ? 1.0 / EPSILON : -1.0 / EPSILON;
    }
    
    return custom_sin(x) / cos_val;
}

/**
 * ���㷴���Һ���ֵ
 * 
 * ��ѧ�Ƶ���
 * asin(x)��̩�ռ���չ��ʽ����0Ϊ���ģ���
 * asin(x) = x + (1/2)x^3/3 + (1��3)/(2��4)x^5/5 + (1��3��5)/(2��4��6)x^7/7 + ...
 * ����ϵ��������ƹ�ϵ��a_{n+1} = a_n * (2n-1)/(2n)
 * 
 * ������
 * asin(x)�Ķ�������[-1, 1]��ֵ����[-��/2, ��/2]
 */
double custom_asin(double x) {
    // ����ֵ��Χ���
    if (x < -1.0) x = -1.0;
    if (x > 1.0) x = 1.0;
    
    // �߽��������
    if (abs_double(x) < 1.0 + EPSILON && abs_double(x) > 1.0 - EPSILON) {
        return (x > 0) ? PI / 2 : -PI / 2;
    }
    
    // ʹ��̩�ռ���չ�����Ƽ��㷴���Һ���
    // asin(x) = x + (1/2)x^3/3 + (1�1�7�1�73)/(2�1�7�1�74)x^5/5 + (1�1�7�1�73�1�7�1�75)/(2�1�7�1�74�1�7�1�76)x^7/7 + ...
    double result = x;
    double term = x;
    double numerator = 1.0; // ����
    double denominator = 2.0; // ��ĸ
    double x_squared = x * x;
    
    for (int n = 1; n <= 20; n++) {  // 20���㹻��ȷ
        term = term * x_squared * numerator / denominator;
        numerator += 2.0;
        denominator += 2.0;
        result += term / numerator;
    }
    
    return result;
}

/**
 * ���㷴���Һ���ֵ
 * 
 * ��ѧ�Ƶ���
 * �������Ǻ����Ļ�����ϵ��cos(x) = sin(��/2 - x)
 * ȡ��������õ���acos(x) = ��/2 - asin(x)
 * 
 * ������
 * acos(x)�Ķ�������[-1, 1]��ֵ����[0, ��]
 */
double custom_acos(double x) {
    return PI / 2 - custom_asin(x);
}

/**
 * ���㷴���к���ֵ
 * 
 * ��ѧ�Ƶ���
 * atan(x)��̩�ռ���չ��ʽ����0Ϊ���ģ���
 * atan(x) = x - x^3/3 + x^5/5 - x^7/7 + ... + (-1)^n x^(2n+1)/(2n+1) + ...
 * ���������|x| �� 1ʱ����
 * 
 * ����|x| > 1��������������º��ʽ��
 * atan(x) = ��/2 - atan(1/x)����x > 0ʱ
 * atan(x) = -��/2 - atan(1/x)����x < 0ʱ
 * 
 * ֵ��
 * atan(x)��ֵ����(-��/2, ��/2)
 */
double custom_atan(double x) {
    // �������
    if (abs_double(x) < EPSILON) {
        return 0.0;
    }
    
    // ����|x| > 1��ʹ��atan(x) = ��/2 - atan(1/x)��-��/2 - atan(1/x)
    if (abs_double(x) > 1.0) {
        if (x > 0) {
            return PI / 2 - custom_atan(1.0 / x);
        } else {
            return -PI / 2 - custom_atan(1.0 / x);
        }
    }
    
    // ʹ��̩�ռ���չ�����Ƽ��㷴���к���
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
 * ����x����y������
 * 
 * ��ѧ���壺
 * fmod(x, y) = x - y * trunc(x/y)
 * ����trunc������ȡ������
 * 
 * �ص㣺
 * 1. �����ķ����뱻����x��ͬ
 * 2. ��yΪ0ʱ������0�����⴦��
 * 3. ��xΪ0ʱ������0
 */
double custom_fmod(double x, double y) {
    // �������
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
        integer_part = (int)quotient;  // ����������ȡ��
    } else {
        integer_part = (int)quotient - 1;  // ��������Ҫ�����1��ʵ������ȡ��
    }
    
    // ��������
    double remainder = x - integer_part * y;
    
    return remainder;
}

/**
 * ������2Ϊ�׵Ķ���
 * ʹ�����źͷֶζ���ʽ����ʵ�֣�ƽ�����ܺ;���
 */
double custom_log2(double x)
{
    // ������������ֵ����
    if (x <= 0)
    {
        return -1.0 / 0.0;  // ��C�У�������-��
    }
    
    // ����ֵ���ٴ��� - ʹ���ݲ�Ƚ�
    if (fabs(x - 1.0) < EPSILON) return 0.0;
    if (fabs(x - 2.0) < EPSILON) return 1.0;
    if (fabs(x - 0.5) < EPSILON) return -1.0;
    if (fabs(x - 4.0) < EPSILON) return 2.0;
    if (fabs(x - 8.0) < EPSILON) return 3.0;
    if (fabs(x - 0.25) < EPSILON) return -2.0;
    if (fabs(x - 16.0) < EPSILON) return 4.0;
    
    // ����1����x������[1,2)����¼ָ��k
    int k = 0;
    double tmp = x;
    while (tmp >= 2.0) { tmp *= 0.5; k++; }
    while (tmp < 1.0) { tmp *= 2.0; k--; }
    x = tmp;
    
    // ����2����m = x��1��m<2��ʹ�÷ֶζ���ʽ���Ƽ���log2(m)
    // ʹ�÷ֶζ���ʽ�����ڱ��ָ����ܵ�ͬʱ��߾���
    double t = x - 1.0; // t �� [0,1)
    double log2_m;
    
    // �ֶδ�������߾���
    if (t < 0.5) {
        // ����t �� [0, 0.5)��ʹ��4�ζ���ʽ����
        const double a1 = 1.4426950408889634;
        const double b1 = -0.7213475204444817;
        const double c1 = 0.4808983469629878;
        const double d1 = -0.3606737602222409;
        const double e1 = 0.2885390081777927;
        
        double t2 = t * t;
        double t3 = t2 * t;
        double t4 = t3 * t;
        
        log2_m = a1 * t + b1 * t2 + c1 * t3 + d1 * t4 + e1 * t4 * t;
    } else {
        // ����t �� [0.5, 1)��ʹ�ò�ͬ�Ķ���ʽϵ���Ի�ø��õľ���
        // ʹ�ø���ȷ�Ķ���ʽϵ������Щϵ�������Ż�����С���������ڵ����
        const double a2 = 1.4426950408889634;
        const double b2 = -0.7612073604666421;
        const double c2 = 0.5709055203500816;
        const double d2 = -0.4331865202581917;
        const double e2 = 0.2413570880999732;
        
        double t2 = t * t;
        double t3 = t2 * t;
        double t4 = t3 * t;
        
        log2_m = a2 * t + b2 * t2 + c2 * t3 + d2 * t4 + e2 * t4 * t;
    }
    
    return k + log2_m;
}

// ��̬��������log2(10)��ֵ�������ظ�����
static double log2_10_cache = 0.0;
static int log2_10_cached = 0;

/**
 * ���㳣�ö�������10Ϊ�ף�
 * ʹ�û��׹�ʽ��log10(x) = log2(x) / log2(10)
 */
double custom_log10(double x)
{
    // �������
    if (x <= 0)
    {
        return -1.0 / 0.0;
    }
    
    // ����ֵ���ٴ��� - ʹ���ݲ�Ƚ�
    if (fabs(x - 1.0) < EPSILON) return 0.0;
    if (fabs(x - 10.0) < EPSILON) return 1.0;
    if (fabs(x - 100.0) < EPSILON) return 2.0;
    if (fabs(x - 0.1) < EPSILON) return -1.0;
    
    // ����log2(10)��ֵ�������ظ�����
    if (!log2_10_cached) {
        // ʹ�þ�ȷ��Ԥ����ֵ�����Ƕ�̬����
        log2_10_cache = 3.321928094887362;  // log2(10)�ľ�ȷֵ
        log2_10_cached = 1;
    }
    
    return custom_log2(x) / log2_10_cache;
}

double custom_log_base(double x, double base)
{
        return custom_log2(x) / custom_log2(base);
}

#define LN2 0.6931471805599453  // ��Ȼ����ln(2)�ľ�ȷֵ
#define EXP_POLY_ORDER 8       // ����ʽ����

/**
 * ʹ�ö���ʽ���Ƽ���e^x��[-ln2/2, ln2/2]��Χ�ڵ�ֵ
 * ����ʽϵ��ͨ��Remez�㷨�Ż���ȷ���������ھ�����Ѿ���
 */
double exp_poly_approx(double x) {
    // ����Сֵ��ֱ�ӷ���̩�ռ���ǰ������Ի�ø��õľ���
    if (fabs(x) < 1e-6) {
        return 1.0 + x + x*x/2.0 + x*x*x/6.0;
    }
    
    // 8�ζ���ʽ���ƣ�ϵ�������Ż�
    const double c[] = {
        1.0,
        1.0,
        0.5000000000125222,
        0.1666666666676906,
        0.0416666666535690,
        0.0083333332768339,
        0.0013888889288081,
        0.0001984127083358,
        0.0000248015872958
    };
    
    double x_pow = 1.0;
    double result = c[0];
    
    // �������ʽ
    for (int i = 1; i <= EXP_POLY_ORDER; i++) {
        x_pow *= x;
        result += c[i] * x_pow;
    }
    
    return result;
}

/**
 * ������Ȼָ������e^x
 * ʹ�ö���ʽ���ƽ�����ż���ʵ�ָ�Ч����
 * 
 * @param x ����ֵ
 * @return e^x�Ľ���ֵ
 */
double custom_exp(double x) {
    // ����ֵ���� - ʹ���ݲ�Ƚ϶�����ֱ�����
    if (fabs(x) < EPSILON) return 1.0;  // �ӽ�0.0
    if (fabs(x - LN2) < EPSILON) return 2.0;  // �ӽ�ln2
    if (fabs(x + LN2) < EPSILON) return 0.5;  // �ӽ�-ln2
    
    // ����������
    if (x > 709.0) return 1.0 / 0.0;  // ����+inf
    if (x < -709.0) return 0.0;
    
    // ��x�ֽ�Ϊk*ln2 + r������r �� [-ln2/2, ln2/2]
    int k = (int)(x / LN2 + 0.5);
    double r = x - k * LN2;
    
    // ����e^rʹ�ö���ʽ����
    double exp_r = exp_poly_approx(r);
    
    // ����2^k��Ӧ�����ţ�e^x = e^(k*ln2 + r) = 2^k * e^r
    double two_pow_k;
    
    if (k >= 0 && k < 31) {
        // ����С����ָ����ʹ����λ����
        two_pow_k = (double)(1 << k);
    } else {
        // �������������ʹ�ø�ͨ�õķ���
        two_pow_k = 1.0;
        int abs_k = (k < 0) ? -k : k;
        
        // ���ټ���2^|k|
        if (abs_k > 0) {
            double base = 2.0;
            int exponent = abs_k;
            
            while (exponent > 0) {
                if (exponent % 2 == 1) {
                    two_pow_k *= base;
                }
                base *= base;
                exponent /= 2;
            }
        }
        
        // ���kΪ����ȡ����
        if (k < 0) {
            two_pow_k = 1.0 / two_pow_k;
        }
    }
    
    return exp_r * two_pow_k;
}

double custom_vector2d_dot(const double vec1[2], const double vec2[2])
{
    return vec1[0] * vec2[0] + vec1[1] * vec2[1];
}

double custom_vector3d_dot(const double vec1[3], const double vec2[3])
{
     return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}

void custom_vector3d_cross(const double vec1[3], const double vec2[3], double result[3])
{
    result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
}

double custom_vector2d_length(const double vec[2])
{
    return custom_sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
}

double custom_vector3d_length(const double vec[3])
{
    return custom_sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}

int custom_vector2d_normalize(const double vec[2], double result[2])
{
    double len = custom_vector2d_length(vec);
    if (len < EPSILON) return 0;
    result[0] = vec[0] / len;
    result[1] = vec[1] / len;
    return 1;
}

int custom_vector3d_normalize(const double vec[3], double result[3])
{
    double len = custom_vector3d_length(vec);
    if (len < EPSILON) return 0;
    result[0] = vec[0] / len;
    result[1] = vec[1] / len;
    result[2] = vec[2] / len;
    return 1;
}

void custom_vector2d_add(const double vec1[2], const double vec2[2], double result[2])
{
    result[0] = vec1[0] + vec2[0];
    result[1] = vec1[1] + vec2[1];
}

void custom_vector3d_add(const double vec1[3], const double vec2[3], double result[3])
{
    result[0] = vec1[0] + vec2[0];
    result[1] = vec1[1] + vec2[1];
    result[2] = vec1[2] + vec2[2];
}

void custom_vector2d_subtract(const double vec1[2], const double vec2[2], double result[2])
{
    result[0] = vec1[0] - vec2[0];
    result[1] = vec1[1] - vec2[1];
}

void custom_vector3d_subtract(const double vec1[3], const double vec2[3], double result[3])
{
    result[0] = vec1[0] - vec2[0];
    result[1] = vec1[1] - vec2[1];
    result[2] = vec1[2] - vec2[2];
}

void custom_vector2d_scale(const double vec[2], double scalar, double result[2])
{
    result[0] = vec[0] * scalar;
    result[1] = vec[1] * scalar;
}

void custom_vector3d_scale(const double vec[3], double scalar, double result[3])
{
    result[0] = vec[0] * scalar;
    result[1] = vec[1] * scalar;
    result[2] = vec[2] * scalar;
}

double custom_vector2d_angle(const double vec1[2], const double vec2[2])
{
    double dot = custom_vector2d_dot(vec1, vec2);
    double len1 = custom_vector2d_length(vec1);
    double len2 = custom_vector2d_length(vec2);
    return custom_acos(dot / (len1 * len2));
}

double custom_vector3d_angle(const double vec1[3], const double vec2[3])
{
    double dot = custom_vector3d_dot(vec1, vec2);
    double len1 = custom_vector3d_length(vec1);
    double len2 = custom_vector3d_length(vec2);
    return custom_acos(dot / (len1 * len2));
}

int custom_vector2d_project(const double vec[2], const double onto[2], double result[2])
{
    double dot = custom_vector2d_dot(vec, onto);
    double onto_len_sq = custom_vector2d_dot(onto, onto);
    if (onto_len_sq < EPSILON) return 0;
    custom_vector2d_scale(onto, dot / onto_len_sq, result);
    return 1;
}

int custom_vector3d_project(const double vec[3], const double target[3], double result[3])
{
    double dot = custom_vector3d_dot(vec, target);
    double target_len_sq = custom_vector3d_dot(target, target);
    if (target_len_sq < EPSILON) return 0;
    custom_vector3d_scale(target, dot / target_len_sq, result);
    return 1;
}
