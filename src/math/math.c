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
double sqrt(double x) {
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
double cbrt(double x) {
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
int round_double(double x) {
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
int ceil_double(double x) {
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
int floor_double(double x) {
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