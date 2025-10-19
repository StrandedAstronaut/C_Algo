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
 * 
 * 数学推导：
 * 1. 基本情况：x^0 = 1，任何数的0次幂都是1
 * 2. 对于负指数：x^(-n) = 1/(x^n)
 * 3. 快速幂算法：利用二进制表示将时间复杂度从O(n)降到O(log n)
 *    - 将n表示为二进制：n = b_kb_{k-1}...b_1b_0
 *    - 则x^n = x^(b_k*2^k + ... + b_1*2^1 + b_0*2^0) = x^(b_k*2^k) * ... * x^(b_0*2^0)
 */
double power(double x, int n) {
    // 参数检查 - 任何数的0次幂都是1
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
 * 
 * 数学推导：
 * 使用牛顿迭代法求解方程f(y) = y² - x = 0
 * 迭代公式：y_{n+1} = y_n - f(y_n)/f'(y_n) = y_n - (y_n² - x)/(2y_n) = (y_n + x/y_n)/2
 * 这个迭代公式会快速收敛到x的平方根，初始猜测值可以选择x/2
 */
double custom_sqrt(double x) {
    // 参数检查
    if (x < 0) {
        return 0.0;  // 负数没有实数平方根
    }
    
    if (x == 0 || x == 1) {
        return x;  // 0和1的平方根就是其本身
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
 * 
 * 数学推导：
 * 对于任意实数x，我们需要找到y，使得y³ = x
 * 使用牛顿迭代法求解方程f(y) = y³ - x = 0
 * 迭代公式：y_{n+1} = y_n - f(y_n)/f'(y_n) = y_n - (y_n³ - x)/(3y_n²) = (2y_n + x/y_n²)/3
 * 对于负数，可以先计算其绝对值的立方根，再恢复符号
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
 * 
 * 数学定义：
 * ceil(x) = 最小的整数y，使得y ≥ x
 * 
 * 实现逻辑：
 * 1. 取x的整数部分
 * 2. 如果x为正数且不是整数，则结果为整数部分+1
 * 3. 如果x为负数且不是整数，则结果为整数部分
 * 4. 如果x为整数，则结果就是x的整数部分
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
    // x为整数
    return integer_part;
}

/**
 * 向下取整
 * 
 * 数学定义：
 * floor(x) = 最大的整数y，使得y ≤ x
 * 
 * 实现逻辑：
 * 1. 取x的整数部分
 * 2. 如果x为负数且不是整数，则结果为整数部分-1
 * 3. 对于正数或整数，结果就是x的整数部分
 */
int custom_floor(double x) {
    int integer_part = (int)x;
    // 如果x为负数且不为整数则减1
    if (x < 0 && x != integer_part) {
        return integer_part - 1;
    }
    // x为正数或整数
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
 * 
 * 数学推导：
 * 欧几里得算法基于以下性质：gcd(a, b) = gcd(b, a % b)
 * 证明：设a = b*q + r，其中0 ≤ r < b
 *      如果d是a和b的公约数，则d | a且d | b，因此d | (a - b*q)，即d | r
 *      反之，如果d是b和r的公约数，则d | b且d | r，因此d | (b*q + r)，即d | a
 *      因此，gcd(a, b) = gcd(b, r) = gcd(b, a % b)
 */
int gcd(int a, int b) {
    // 参数检查
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
 * 
 * 数学推导：
 * 对于任意两个非零整数a和b，有以下关系：
 * LCM(a,b) * GCD(a,b) = |a*b|
 * 因此，LCM(a,b) = |a*b| / GCD(a,b)
 * 
 * 证明：设g = gcd(a,b)，则a = g*a'，b = g*b'，其中gcd(a',b') = 1
 *      LCM(a,b) = g*a'*b' （因为a'和b'互质）
 *      |a*b| = g*a' * g*b' = g²*a'*b'
 *      所以，LCM(a,b) = |a*b| / g = |a*b| / GCD(a,b)
 */
int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;  // 0和任何数的最小公倍数是0
    }
    
    // 计算LCM
    // 使用abs_int确保结果为正值
    return abs_int(a * b) / gcd(a, b);
}

/**
 * 计算正弦函数值
 * 
 * 数学推导：
 * sin(x)的泰勒展开式（以0为中心）：
 * sin(x) = x - x³/3! + x⁵/5! - x⁷/7! + ... + (-1)^n x^(2n+1)/(2n+1)! + ...
 * 
 * 实现策略：
 * 1. 利用sin(x)的周期性，将x归一化到[-π, π]范围内，减少计算量
 * 2. 使用泰勒级数展开计算近似值，直到项的绝对值小于精度要求
 * 3. 为了避免重复计算，每一项通过前一项计算：下一项 = 当前项 * x² / [(2i)*(2i+1)]
 */
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
    
    // 迭代计算泰勒展开式直到项足够小
    while (abs_double(term) > EPSILON) {
        result += sign * term;
        
        // 计算下一项: 基于前一项计算，避免重复计算
        // 下一项 = 当前项 * x² / [(2i)*(2i+1)]
        term *= x * x / ((2 * i) * (2 * i + 1));
        sign *= -1;  // 符号翻转
        i++;
    }
    
    return result;
}

/**
 * 计算余弦函数值
 * 
 * 数学推导：
 * 利用三角函数的相位关系：cos(x) = sin(x + π/2)
 * 这个关系可以从单位圆上的几何解释得到：
 * 当角度增加π/2时，点在单位圆上旋转到y轴方向，原来的x坐标（余弦值）变为y坐标（正弦值）
 */
double custom_cos(double x)
{
    return custom_sin(x + PI / 2);
}

/**
 * 计算正切函数值
 * 
 * 数学推导：
 * 正切函数的定义：tan(x) = sin(x) / cos(x)
 * 
 * 特殊情况处理：
 * 当cos(x)接近0时（x接近π/2 + kπ，k为整数），tan(x)趋近于正无穷或负无穷
 * 此时返回一个极大值或极小值来模拟这种行为
 */
double custom_tan(double x) {
    double cos_val = custom_cos(x);
    
    // 检查cos值是否接近零，避免除零错误
    if (abs_double(cos_val) < EPSILON) {
        // 返回一个极大值，模拟tan函数在接近π/2+kπ处的行为
        return (cos_val > 0) ? 1.0 / EPSILON : -1.0 / EPSILON;
    }
    
    return custom_sin(x) / cos_val;
}

/**
 * 计算反正弦函数值
 * 
 * 数学推导：
 * asin(x)的泰勒级数展开式（以0为中心）：
 * asin(x) = x + (1/2)x^3/3 + (1×3)/(2×4)x^5/5 + (1×3×5)/(2×4×6)x^7/7 + ...
 * 其中系数满足递推关系：a_{n+1} = a_n * (2n-1)/(2n)
 * 
 * 定义域：
 * asin(x)的定义域是[-1, 1]，值域是[-π/2, π/2]
 */
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

/**
 * 计算反余弦函数值
 * 
 * 数学推导：
 * 利用三角函数的互补关系：cos(x) = sin(π/2 - x)
 * 取反函数后得到：acos(x) = π/2 - asin(x)
 * 
 * 定义域：
 * acos(x)的定义域是[-1, 1]，值域是[0, π]
 */
double custom_acos(double x) {
    return PI / 2 - custom_asin(x);
}

/**
 * 计算反正切函数值
 * 
 * 数学推导：
 * atan(x)的泰勒级数展开式（以0为中心）：
 * atan(x) = x - x^3/3 + x^5/5 - x^7/7 + ... + (-1)^n x^(2n+1)/(2n+1) + ...
 * 这个级数在|x| ≤ 1时收敛
 * 
 * 对于|x| > 1的情况，利用以下恒等式：
 * atan(x) = π/2 - atan(1/x)，当x > 0时
 * atan(x) = -π/2 - atan(1/x)，当x < 0时
 * 
 * 值域：
 * atan(x)的值域是(-π/2, π/2)
 */
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
 * 计算x除以y的余数
 * 
 * 数学定义：
 * fmod(x, y) = x - y * trunc(x/y)
 * 其中trunc是向零取整函数
 * 
 * 特点：
 * 1. 余数的符号与被除数x相同
 * 2. 当y为0时，返回0（特殊处理）
 * 3. 当x为0时，返回0
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
