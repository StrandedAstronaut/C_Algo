/*
 * 数学库函数实现
 */
#include "../../include/math/math.h"
#include <stdio.h>

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
    // 处理特殊情况
    if (n == 0) {
        return 1.0;  // 任何数的0次幂都是1
    }
    
    if (n < 0) {
        // 负指数：计算倒数
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
    // 参数检查
    if (x < 0) {
        return 0.0;  // 负数没有实数平方根
    }
    
    if (x == 0 || x == 1) {
        return x;  // 0和1的平方根是它们自己
    }
    
    // 牛顿迭代法计算平方根
    double precision = 1e-10;  // 精度要求
    double guess = x / 2.0;    // 初始猜测值
    
    while (abs_double(guess * guess - x) > precision) {
        guess = (guess + x / guess) / 2.0;
    }
    
    return guess;
}

/**
 * 计算x的立方根
 */
double custom_cbrt(double x) {
    // 处理特殊情况
    if (x == 0 || x == 1 || x == -1) {
        return x;  // 0、1、-1的立方根是它们自己
    }
    
    // 确定符号
    int sign = (x < 0) ? -1 : 1;
    double abs_x = abs_double(x);
    
    // 牛顿迭代法计算立方根
    double precision = 1e-10;  // 精度要求
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
    // 对于正数，加上0.5后向下取整
    // 对于负数，减去0.5后向上取整
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
    // 如果x不是整数且为正数，则加1
    if (x > 0 && x != integer_part) {
        return integer_part + 1;
    }
    // 如果x是负数且不是整数，则返回整数部分
    if (x < 0 && x != integer_part) {
        return integer_part;
    }
    // x是整数
    return integer_part;
}

/**
 * 向下取整
 */
int custom_floor(double x) {
    int integer_part = (int)x;
    // 如果x是负数且不是整数，则减1
    if (x < 0 && x != integer_part) {
        return integer_part - 1;
    }
    // x是正数或整数
    return integer_part;
}

/**
 * 判断一个数是否为素数
 */
int is_prime(int n) {
    // 处理特殊情况
    if (n <= 1) {
        return 0;  // 1和小于1的数不是素数
    }
    
    if (n <= 3) {
        return 1;  // 2和3是素数
    }
    
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;  // 能被2或3整除的数不是素数
    }
    
    // 检查从5开始的所有可能因子，直到sqrt(n)
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
    // 处理负数情况
    a = abs_int(a);
    b = abs_int(b);
    
    // 欧几里得算法
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
    
    // 计算LCM
    // 使用abs_int确保结果为正数
    return abs_int(a * b) / gcd(a, b);
}

double custom_sin(double x)
{
    // 1. 将x归一化到[-π, π]区间，减少计算误差
    x = custom_fmod(x, 2 * PI);  // 取模运算，得到[0, 2π)区间的值
    if (x > PI) {
        x -= 2 * PI;      // 将大于π的值转换到[-π, 0)区间
    }
    
    double result = 0.0;  // 结果初始化为0
    double term = x;      // 泰勒级数的第一项是x
    int sign = 1;         // 符号，交替变化
    int i = 1;            // 迭代计数器
    
    // 2. 迭代计算泰勒级数，直到项足够小
    while (abs_double(term) > EPSILON) {
        result += sign * term;
        
        // 计算下一项: 基于前一项计算，避免重复计算
        // 下一项 = 当前项 * x² / [(2i)*(2i+1)]
        term *= x * x / ((2 * i) * (2 * i + 1));
        sign *= -1;  // 符号交替
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
        // 返回一个大值或无穷大，模拟真实tan函数在接近π/2+kπ处的行为
        return (cos_val > 0) ? 1.0 / EPSILON : -1.0 / EPSILON;
    }
    
    return custom_sin(x) / cos_val;
}

// 反正弦函数 - 使用泰勒级数实现
double custom_asin(double x) {
    // 处理输入范围检查
    if (x < -1.0) x = -1.0;
    if (x > 1.0) x = 1.0;
    
    // 处理特殊情况
    if (abs_double(x) == 1.0) {
        return (x > 0) ? PI / 2 : -PI / 2;
    }
    
    // 使用泰勒级数展开计算反正弦函数
    // asin(x) = x + (1/2)x^3/3 + (1·3)/(2·4)x^5/5 + (1·3·5)/(2·4·6)x^7/7 + ...
    double result = x;
    double term = x;
    double numerator = 1.0;
    double denominator = 2.0;
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
    // 处理特殊情况
    if (abs_double(x) < EPSILON) {
        return 0.0;
    }
    
    // 对于|x| > 1的情况，使用atan(x) = π/2 - atan(1/x)或-π/2 - atan(1/x)
    if (abs_double(x) > 1.0) {
        if (x > 0) {
            return PI / 2 - atan(1.0 / x);
        } else {
            return -PI / 2 - atan(1.0 / x);
        }
    }
    
    // 使用泰勒级数展开计算反正切函数
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
    // 处理特殊情况
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
        integer_part = (int)quotient;  // 对于正数，向下取整
    } else {
        integer_part = (int)quotient - 1;  // 对于负数，向下取整
    }
    
    // 计算余数
    double remainder = x - integer_part * y;
    
    return remainder;
}