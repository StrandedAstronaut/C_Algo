#ifndef MATH_H
#define MATH_H

#define PI 3.14159265358979323846  // 定义π值
#define EPSILON 1e-10              // 精度控制值
/**
 * @file math.h
 * @brief 数学库函数接口定义
 */

/**
 * @brief 计算整数的绝对值
 * 
 * @param x 输入整数
 * @return int x的绝对值
 */
int abs_int(int x);

/**
 * @brief 计算浮点数的绝对值
 * 
 * @param x 输入浮点数
 * @return double x的绝对值
 */
double abs_double(double x);

/**
 * @brief 计算两个数的最大值
 * 
 * @param a 第一个数
 * @param b 第二个数
 * @return int 较大的数
 */
int max_int(int a, int b);

/**
 * @brief 计算两个浮点数的最大值
 * 
 * @param a 第一个浮点数
 * @param b 第二个浮点数
 * @return double 较大的浮点数
 */
double max_double(double a, double b);

/**
 * @brief 计算两个数的最小值
 * 
 * @param a 第一个数
 * @param b 第二个数
 * @return int 较小的数
 */
int min_int(int a, int b);

/**
 * @brief 计算两个浮点数的最小值
 * 
 * @param a 第一个浮点数
 * @param b 第二个浮点数
 * @return double 较小的浮点数
 */
double min_double(double a, double b);

/**
 * @brief 计算x的n次幂（整数幂）
 * 
 * @param x 底数
 * @param n 指数
 * @return double x的n次幂结果
 * @note 当n为负数时，返回1.0 / (x的|n|次幂)
 */
double power(double x, int n);

/**
 * @brief 计算x的平方根（使用牛顿迭代法）
 * 
 * @param x 非负数
 * @return double x的平方根
 * @warning x必须为非负数，否则返回0
 */
double custom_sqrt(double x);

/**
 * @brief 计算x的立方根
 * 
 * @param x 输入数
 * @return double x的立方根
 */
double custom_cbrt(double x);

/**
 * @brief 四舍五入到最接近的整数
 * 
 * @param x 输入浮点数
 * @return int 四舍五入后的整数
 */
int custom_round(double x);

/**
 * @brief 向上取整
 * 
 * @param x 输入浮点数
 * @return int 向上取整后的整数
 */
int custom_ceil(double x);

/**
 * @brief 向下取整
 * 
 * @param x 输入浮点数
 * @return int 向下取整后的整数
 */
int custom_floor(double x);

/**
 * @brief 判断一个数是否为素数
 * 
 * @param n 输入整数
 * @return int 如果是素数返回1，否则返回0
 */
int is_prime(int n);

/**
 * @brief 计算两个数的最大公约数（GCD）
 * 
 * @param a 第一个数
 * @param b 第二个数
 * @return int 最大公约数
 */
int gcd(int a, int b);

/**
 * @brief 计算两个数的最小公倍数（LCM）
 * 
 * @param a 第一个数
 * @param b 第二个数
 * @return int 最小公倍数
 */
int lcm(int a, int b);

// =============================================================================
// 以下是尚未实现的数学算法接口定义
// 后续可以根据需要实现这些功能
// =============================================================================

/**
 * @brief 计算正弦值
 * 
 * @param x 弧度值
 * @return double sin(x)的近似值
 */
double custom_sin(double x);

/**
 * @brief 计算余弦值
 * 
 * @param x 弧度值
 * @return double cos(x)的近似值
 */
double custom_cos(double x);

/**
 * @brief 计算正切值
 * 
 * @param x 弧度值
 * @return double tan(x)的近似值
 */
double custom_tan(double x);

/**
 * @brief 计算反正弦值
 * 
 * @param x 输入值，范围[-1,1]
 * @return double asin(x)的弧度值，范围[-π/2, π/2]
 */
double custom_asin(double x);

/**
 * @brief 计算反余弦值
 * 
 * @param x 输入值，范围[-1,1]
 * @return double acos(x)的弧度值，范围[0, π]
 */
double custom_acos(double x);

/**
 * @brief 计算反正切值
 * 
 * @param x 输入值
 * @return double atan(x)的弧度值，范围[-π/2, π/2]
 */
double custom_atan(double x);

/**
 * @brief 计算自然对数
 * 
 * @param x 输入正数
 * @return double ln(x)的近似值
 */
// double ln(double x);

/**
 * @brief 计算x除以y的余数
 * 
 * @param x 被除数
 * @param y 除数
 * @return double x除以y的余数，符号与x相同
 */
double custom_fmod(double x, double y);

/**
 * @brief 计算以2为底的对数
 * 
 * @param x 输入正数
 * @return double log2(x)的近似值，x≤0时返回-∞
 */
double custom_log2(double x);

/**
 * @brief 计算常用对数（以10为底）
 * 
 * @param x 输入正数
 * @return double log10(x)的近似值，x≤0时返回-∞
 */
double custom_log10(double x);

/**
 * @brief 计算以base为底的对数
 * 
 * @param x 输入正数
 * @param base 对数的底
 * @return double log_base(x)的近似值
 */
double custom_log_base(double x, double base);

/**
 * @brief 计算指数函数（e的x次方）
 * 
 * @param x 指数值
 * @return double e^x的近似值
 */
double custom_exp(double x);

/**
 * @brief 生成[0,1)范围内的随机数
 * 
 * @return double 随机浮点数
 */
// double random_double();

/**
 * @brief 生成[a,b]范围内的随机整数
 * 
 * @param a 最小值
 * @param b 最大值
 * @return int 随机整数
 */
// int random_int(int a, int b);

/**
 * @brief 计算阶乘
 * 
 * @param n 非负整数
 * @return long long n的阶乘
 */
// long long factorial(int n);

/**
 * @brief 计算斐波那契数列的第n项
 * 
 * @param n 项数
 * @return long long 第n项的值
 */
// long long fibonacci(int n);

/**
 * @brief 计算组合数C(n,k)
 * 
 * @param n 总数
 * @param k 选择数
 * @return long long 组合数结果
 */
// long long combination(int n, int k);

/**
 * @brief 计算排列数P(n,k)
 * 
 * @param n 总数
 * @param k 选择数
 * @return long long 排列数结果
 */
// long long permutation(int n, int k);

/**
 * @brief 计算两点之间的距离
 * 
 * @param x1 第一个点的x坐标
 * @param y1 第一个点的y坐标
 * @param x2 第二个点的x坐标
 * @param y2 第二个点的y坐标
 * @return double 两点之间的欧几里得距离
 */
// double distance(double x1, double y1, double x2, double y2);

/**
 * @brief 多项式求值（霍纳法则）
 * 
 * @param coefficients 多项式系数数组（从低次项到高次项）
 * @param degree 多项式次数
 * @param x 自变量值
 * @return double 多项式在x处的值
 */
// double polynomial(double coefficients[], int degree, double x);

/**
 * @brief 线性插值
 * 
 * @param x0 第一个点的x坐标
 * @param y0 第一个点的y坐标
 * @param x1 第二个点的x坐标
 * @param y1 第二个点的y坐标
 * @param x 要插值的x坐标
 * @return double 插值结果
 */
// double linear_interpolation(double x0, double y0, double x1, double y1, double x);

/**
 * @brief 角度转换：弧度转角度
 * 
 * @param radians 弧度值
 * @return double 角度值
 */
// double radians_to_degrees(double radians);

/**
 * @brief 角度转换：角度转弧度
 * 
 * @param degrees 角度值
 * @return double 弧度值
 */
// double degrees_to_radians(double degrees);

// =============================================================================
// 向量运算函数接口定义
// =============================================================================

/**
 * @brief 计算两个2D向量的点积
 * 
 * @param vec1 第一个向量 [x, y]
 * @param vec2 第二个向量 [x, y]
 * @return double 点积结果
 */
double custom_vector2d_dot(const double vec1[2], const double vec2[2]);

/**
 * @brief 计算两个3D向量的点积
 * 
 * @param vec1 第一个向量 [x, y, z]
 * @param vec2 第二个向量 [x, y, z]
 * @return double 点积结果
 */
double custom_vector3d_dot(const double vec1[3], const double vec2[3]);

/**
 * @brief 计算两个3D向量的叉积
 * 
 * @param vec1 第一个向量 [x, y, z]
 * @param vec2 第二个向量 [x, y, z]
 * @param result 输出参数，存储叉积结果的三个分量 [rx, ry, rz]
 */
void custom_vector3d_cross(const double vec1[3], const double vec2[3], double result[3]);

/**
 * @brief 计算2D向量的长度（模长）
 * 
 * @param vec 向量 [x, y]
 * @return double 向量的长度
 */
double custom_vector2d_length(const double vec[2]);

/**
 * @brief 计算3D向量的长度（模长）
 * 
 * @param vec 向量 [x, y, z]
 * @return double 向量的长度
 */
double custom_vector3d_length(const double vec[3]);

/**
 * @brief 归一化2D向量
 * 
 * @param vec 输入向量 [x, y]
 * @param result 输出参数，存储归一化后的向量 [nx, ny]
 * @return int 成功返回1，向量为零向量返回0
 */
int custom_vector2d_normalize(const double vec[2], double result[2]);

/**
 * @brief 归一化3D向量
 * 
 * @param vec 输入向量 [x, y, z]
 * @param result 输出参数，存储归一化后的向量 [nx, ny, nz]
 * @return int 成功返回1，向量为零向量返回0
 */
int custom_vector3d_normalize(const double vec[3], double result[3]);

/**
 * @brief 2D向量加法
 * 
 * @param vec1 第一个向量 [x, y]
 * @param vec2 第二个向量 [x, y]
 * @param result 输出参数，存储加法结果 [rx, ry]
 */
void custom_vector2d_add(const double vec1[2], const double vec2[2], double result[2]);

/**
 * @brief 3D向量加法
 * 
 * @param vec1 第一个向量 [x, y, z]
 * @param vec2 第二个向量 [x, y, z]
 * @param result 输出参数，存储加法结果 [rx, ry, rz]
 */
void custom_vector3d_add(const double vec1[3], const double vec2[3], double result[3]);

/**
 * @brief 2D向量减法
 * 
 * @param vec1 被减向量 [x, y]
 * @param vec2 减向量 [x, y]
 * @param result 输出参数，存储减法结果 [rx, ry]
 */
void custom_vector2d_subtract(const double vec1[2], const double vec2[2], double result[2]);

/**
 * @brief 3D向量减法
 * 
 * @param vec1 被减向量 [x, y, z]
 * @param vec2 减向量 [x, y, z]
 * @param result 输出参数，存储减法结果 [rx, ry, rz]
 */
void custom_vector3d_subtract(const double vec1[3], const double vec2[3], double result[3]);

/**
 * @brief 2D向量与标量乘法
 * 
 * @param vec 输入向量 [x, y]
 * @param scalar 标量值
 * @param result 输出参数，存储乘法结果 [rx, ry]
 */
void custom_vector2d_scale(const double vec[2], double scalar, double result[2]);

/**
 * @brief 3D向量与标量乘法
 * 
 * @param vec 输入向量 [x, y, z]
 * @param scalar 标量值
 * @param result 输出参数，存储乘法结果 [rx, ry, rz]
 */
void custom_vector3d_scale(const double vec[3], double scalar, double result[3]);

/**
 * @brief 计算两个2D向量之间的夹角（弧度）
 * 
 * @param vec1 第一个向量 [x, y]
 * @param vec2 第二个向量 [x, y]
 * @return double 夹角（弧度值，范围[0, π]）
 */
double custom_vector2d_angle(const double vec1[2], const double vec2[2]);

/**
 * @brief 计算两个3D向量之间的夹角（弧度）
 * 
 * @param vec1 第一个向量 [x, y, z]
 * @param vec2 第二个向量 [x, y, z]
 * @return double 夹角（弧度值，范围[0, π]）
 */
double custom_vector3d_angle(const double vec1[3], const double vec2[3]);

/**
 * @brief 计算2D向量在另一个2D向量上的投影
 * 
 * @param vec 要投影的向量 [x, y]
 * @param target 投影目标向量 [x, y]
 * @param result 输出参数，存储投影向量 [px, py]
 * @return int 成功返回1，投影目标为零向量返回0
 */
int custom_vector2d_project(const double vec[2], const double target[2], double result[2]);

/**
 * @brief 计算3D向量在另一个3D向量上的投影
 * 
 * @param vec 要投影的向量 [x, y, z]
 * @param target 投影目标向量 [x, y, z]
 * @param result 输出参数，存储投影向量 [px, py, pz]
 * @return int 成功返回1，投影目标为零向量返回0
 */
int custom_vector3d_project(const double vec[3], const double target[3], double result[3]);

#endif // MATH_H