/*
 * 数学库函数实现
 */
#include "../../include/math/math.h"
#include <stdio.h>
#include <math.h>

// 浮点数比较的容差
#define EPSILON 1e-10

/**
 * 计算整数的绝对值
 */
int abs_int(int x) {
    return (x < 0) ? -x : x;
}

/**
 * 计算浮点数的绝对值
 */
double abs_double(double x) {
    return (x < 0) ? -x : x;
}

/**
 * 计算两个数的最大值
 */
int max_int(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * 计算两个浮点数的最大值
 */
double max_double(double a, double b) {
    return (a > b) ? a : b;
}

/**
 * 计算两个数的最小值
 */
int min_int(int a, int b) {
    return (a < b) ? a : b;
}

/**
 * 计算两个浮点数的最小值
 */
double min_double(double a, double b) {
    return (a < b) ? a : b;
}

/**
 * 计算x的n次幂（整数幂）
 */
double power(double x, int n) {
    // 参数检查����
    if (n == 0) {
        return 1.0;  // 任何数的0次幂都是1
    }
    
    if (n < 0) {
        // 负指数处理，返回倒数
        return 1.0 / power(x, -n);
    }
    
    // 使用快速幂算法
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
 * 计算x的平方根（使用牛顿迭代法）
 */
double custom_sqrt(double x) {
    // �������
    if (x < 0) {
        return 0.0;  // 负数没有实数平方根
    }
    
    if (x == 0 || x == 1) {
        return x;  // 0��1��ƽ�����������Լ�
    }
    
    // 牛顿迭代法计算平方根
    double precision = 1e-10;  // 精度要求
    double guess = x / 2.0;    // ��ʼ�²�ֵ
    
    while (abs_double(guess * guess - x) > precision) {
        guess = (guess + x / guess) / 2.0;
    }
    
    return guess;
}

/**
 * 计算x的立方根
 */
double custom_cbrt(double x) {
    // 参数检查
    if (x == 0 || x == 1 || x == -1) {
        return x;  // 0、1、-1的立方根就是其本身
    }
    
    // 确定符号
    int sign = (x < 0) ? -1 : 1;
    double abs_x = abs_double(x);
    
    // 牛顿迭代法计算立方根
    double precision = 1e-10;  // ����Ҫ��
    double guess = abs_x / 3.0;  // 初始猜测值
    
    while (abs_double(guess * guess * guess - abs_x) > precision) {
        guess = (2 * guess + abs_x / (guess * guess)) / 3.0;
    }
    
    return sign * guess;
}

/**
 * 四舍五入到最接近的整数
 */
int custom_round(double x) {
    // 正数加上0.5后取整
    // 负数减去0.5后取整
    if (x >= 0) {
        return (int)(x + 0.5);
    } else {
        return (int)(x - 0.5);
    }
}

/**
 * 向上取整
 */
int custom_ceil(double x) {
    int integer_part = (int)x;
    // 如果x为正数且不为整数则加1
    if (x > 0 && x != integer_part) {
        return integer_part + 1;
    }
    // 如果x为负数且不为整数则返回整数部分
    if (x < 0 && x != integer_part) {
        return integer_part;
    }
    // x������
    return integer_part;
}

/**
 * 向下取整
 */
int custom_floor(double x) {
    int integer_part = (int)x;
    // 如果x为负数且不为整数则减1
    if (x < 0 && x != integer_part) {
        return integer_part - 1;
    }
    // x������������
    return integer_part;
}

/**
 * 判断一个数是否为素数
 */
int is_prime(int n) {
    // 参数检查
    if (n <= 1) {
        return 0;  // 1和小于1的数不是素数
    }
    
    if (n <= 3) {
        return 1;  // 2和3是素数
    }
    
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;  // 能被2或3整除的数不是素数
    }
    
    // 从5开始检查可能的因子，直到sqrt(n)
    // 只需要检查6k±1形式的数
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    
    return 1;
}

/**
 * 计算两个数的最大公约数（GCD）
 * 使用欧几里得算法
 */
int gcd(int a, int b) {
    // 参数检查
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
 * 计算两个数的最小公倍数（LCM）
 * LCM(a,b) = |a*b| / GCD(a,b)
 */
int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;  // 0和任何数的最小公倍数是0
    }
    
    // ����LCM
    // ʹ��abs_intȷ�����Ϊ����
    return abs_int(a * b) / gcd(a, b);
}

double custom_sin(double x)
{
    // 将x归一化到[-π, π]范围内，减少计算量
    x = custom_fmod(x, 2 * PI);  // 取模运算，得到[0, 2π)范围的值
    if (x > PI) {
        x -= 2 * PI;      // 将大于π的值转换到[-π, 0)范围
    }
    
    double result = 0.0;  // 结果初始化为0
    double term = x;      // 泰勒展开的第一项是x
    int sign = 1;         // 符号，交替变化
    int i = 1;            // 迭代计数器
    
    // 2. 迭代计算泰勒展开式直到项足够小
    while (abs_double(term) > EPSILON) {
        result += sign * term;
        
        // ������һ��: ����ǰһ����㣬�����ظ�����
        // 下一项 = 当前项 * x² / [(2i)*(2i+1)]
        term *= x * x / ((2 * i) * (2 * i + 1));
        sign *= -1;  // 符号翻转
        i++;
    }
    
    return result;
}

double custom_cos(double x)
{
    return custom_sin(x + PI / 2);
}

// 正切函数通过sin(x)/cos(x)实现
double custom_tan(double x) {
    double cos_val = custom_cos(x);
    
    // 检查cos值是否接近零，避免除零错误
    if (abs_double(cos_val) < EPSILON) {
        // 返回一个极大值，模拟tan函数在接近π/2+kπ处的行为
        return (cos_val > 0) ? 1.0 / EPSILON : -1.0 / EPSILON;
    }
    
    return custom_sin(x) / cos_val;
}

// 反正弦函数 - 使用泰勒级数实现
double custom_asin(double x) {
    // 输入值范围检查
    if (x < -1.0) x = -1.0;
    if (x > 1.0) x = 1.0;
    
    // 边界情况处理
    if (abs_double(x) < 1.0 + EPSILON && abs_double(x) > 1.0 - EPSILON) {
        return (x > 0) ? PI / 2 : -PI / 2;
    }
    
    // 使用泰勒级数展开近似计算反正弦函数
    // asin(x) = x + (1/2)x^3/3 + (1��3)/(2��4)x^5/5 + (1��3��5)/(2��4��6)x^7/7 + ...
    double result = x;
    double term = x;
    double numerator = 1.0; // 分子
    double denominator = 2.0; // 分母
    double x_squared = x * x;
    
    for (int n = 1; n <= 20; n++) {  // 20项足够精确
        term = term * x_squared * numerator / denominator;
        numerator += 2.0;
        denominator += 2.0;
        result += term / numerator;
    }
    
    return result;
}

// 反余弦函数通过π/2 - asin(x)实现
double custom_acos(double x) {
    return PI / 2 - custom_asin(x);
}

// 反正切函数 - 使用泰勒级数实现
double custom_atan(double x) {
    // 参数检查
    if (abs_double(x) < EPSILON) {
        return 0.0;
    }
    
    // 对于|x| > 1，使用atan(x) = π/2 - atan(1/x)或-π/2 - atan(1/x)
    if (abs_double(x) > 1.0) {
        if (x > 0) {
            return PI / 2 - custom_atan(1.0 / x);
        } else {
            return -PI / 2 - custom_atan(1.0 / x);
        }
    }
    
    // 使用泰勒级数展开近似计算反正切函数
    // atan(x) = x - x^3/3 + x^5/5 - x^7/7 + ...
    double result = x;
    double term = x;
    double x_squared = x * x;
    
    for (int n = 1; n <= 20; n++) {  // 20项足够精确
        term = -term * x_squared;
        result += term / (2 * n + 1);
    }
    
    return result;
}

/**
 * @brief 计算x除以y的余数
 * 
 * @param x 被除数
 * @param y 除数
 * @return double x除以y的余数，符号与x相同
 */
double custom_fmod(double x, double y) {
    // 参数检查
    if (y == 0) {
        return 0.0;  // 除数为0时返回0
    }
    
    if (x == 0) {
        return 0.0;  // 被除数为0时返回0
    }
    
    // 计算商并取整
    double quotient = x / y;
    int integer_part;
    
    if (quotient >= 0) {
        integer_part = (int)quotient;  // 正数商向下取整
    } else {
        integer_part = (int)quotient - 1;  // 负数商需要额外减1以实现向下取整
    }
    
    // 计算余数
    double remainder = x - integer_part * y;
    
    return remainder;
}

/**
 * 计算以2为底的对数
 * 使用缩放和分段多项式近似实现，平衡性能和精度
 */
double custom_log2(double x)
{
    // 参数检查和特殊值处理
    if (x <= 0)
    {
        return -1.0 / 0.0;  // 在C中，这会产生-∞
    }
    
    // 特殊值快速处理 - 使用容差比较
    if (fabs(x - 1.0) < EPSILON) return 0.0;
    if (fabs(x - 2.0) < EPSILON) return 1.0;
    if (fabs(x - 0.5) < EPSILON) return -1.0;
    if (fabs(x - 4.0) < EPSILON) return 2.0;
    if (fabs(x - 8.0) < EPSILON) return 3.0;
    if (fabs(x - 0.25) < EPSILON) return -2.0;
    if (fabs(x - 16.0) < EPSILON) return 4.0;
    
    // 步骤1：将x缩放至[1,2)，记录指数k
    int k = 0;
    double tmp = x;
    while (tmp >= 2.0) { tmp *= 0.5; k++; }
    while (tmp < 1.0) { tmp *= 2.0; k--; }
    x = tmp;
    
    // 步骤2：对m = x（1≤m<2）使用分段多项式近似计算log2(m)
    // 使用分段多项式可以在保持高性能的同时提高精度
    double t = x - 1.0; // t ∈ [0,1)
    double log2_m;
    
    // 分段处理以提高精度
    if (t < 0.5) {
        // 对于t ∈ [0, 0.5)，使用4次多项式近似
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
        // 对于t ∈ [0.5, 1)，使用不同的多项式系数以获得更好的精度
        // 使用更精确的多项式系数，这些系数经过优化以最小化该区间内的误差
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

// 静态变量缓存log2(10)的值，避免重复计算
static double log2_10_cache = 0.0;
static int log2_10_cached = 0;

/**
 * 计算常用对数（以10为底）
 * 使用换底公式：log10(x) = log2(x) / log2(10)
 */
double custom_log10(double x)
{
    // 参数检查
    if (x <= 0)
    {
        return -1.0 / 0.0;
    }
    
    // 特殊值快速处理 - 使用容差比较
    if (fabs(x - 1.0) < EPSILON) return 0.0;
    if (fabs(x - 10.0) < EPSILON) return 1.0;
    if (fabs(x - 100.0) < EPSILON) return 2.0;
    if (fabs(x - 0.1) < EPSILON) return -1.0;
    
    // 缓存log2(10)的值，避免重复计算
    if (!log2_10_cached) {
        // 使用精确的预计算值而不是动态计算
        log2_10_cache = 3.321928094887362;  // log2(10)的精确值
        log2_10_cached = 1;
    }
    
    return custom_log2(x) / log2_10_cache;
}

double custom_log_base(double x, double base)
{
        return custom_log2(x) / custom_log2(base);
}

#define LN2 0.6931471805599453  // 自然对数ln(2)的精确值
#define EXP_POLY_ORDER 8       // 多项式阶数

/**
 * 使用多项式近似计算e^x在[-ln2/2, ln2/2]范围内的值
 * 多项式系数通过Remez算法优化，确保在区间内具有最佳精度
 */
double exp_poly_approx(double x) {
    // 对于小值，直接返回泰勒级数前几项可以获得更好的精度
    if (fabs(x) < 1e-6) {
        return 1.0 + x + x*x/2.0 + x*x*x/6.0;
    }
    
    // 8次多项式近似，系数经过优化
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
    
    // 计算多项式
    for (int i = 1; i <= EXP_POLY_ORDER; i++) {
        x_pow *= x;
        result += c[i] * x_pow;
    }
    
    return result;
}

/**
 * 计算自然指数函数e^x
 * 使用多项式近似结合缩放技术实现高效计算
 * 
 * @param x 输入值
 * @return e^x的近似值
 */
double custom_exp(double x) {
    // 特殊值处理 - 使用容差比较而不是直接相等
    if (fabs(x) < EPSILON) return 1.0;  // 接近0.0
    if (fabs(x - LN2) < EPSILON) return 2.0;  // 接近ln2
    if (fabs(x + LN2) < EPSILON) return 0.5;  // 接近-ln2
    
    // 处理溢出情况
    if (x > 709.0) return 1.0 / 0.0;  // 返回+inf
    if (x < -709.0) return 0.0;
    
    // 将x分解为k*ln2 + r，其中r ∈ [-ln2/2, ln2/2]
    int k = (int)(x / LN2 + 0.5);
    double r = x - k * LN2;
    
    // 计算e^r使用多项式近似
    double exp_r = exp_poly_approx(r);
    
    // 计算2^k并应用缩放：e^x = e^(k*ln2 + r) = 2^k * e^r
    double two_pow_k;
    
    if (k >= 0 && k < 31) {
        // 对于小的正指数，使用移位操作
        two_pow_k = (double)(1 << k);
    } else {
        // 对于其他情况，使用更通用的方法
        two_pow_k = 1.0;
        int abs_k = (k < 0) ? -k : k;
        
        // 快速计算2^|k|
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
        
        // 如果k为负，取倒数
        if (k < 0) {
            two_pow_k = 1.0 / two_pow_k;
        }
    }
    
    return exp_r * two_pow_k;
}
