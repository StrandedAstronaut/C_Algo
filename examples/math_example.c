/*
 * 数学库示例程序
 * 展示如何使用数学库中的各种函数
 */
#include <stdio.h>
#include <time.h>  // 用于计时功能
#include <math.h>  // 先包含libc的math.h

// 给libc的sin和cos函数起别名
#define libc_sin sin
#define libc_cos cos

// 取消对libc sin和cos的直接使用，避免与我们自己的实现冲突
#undef sin
#undef cos

// 然后包含我们的algorithm_lib.h，它会包含我们实现的sin和cos函数
#include "algorithm_lib.h"

int main() {
    printf("===== C语言算法库 - 数学函数示例 =====\n\n");
    
    // 测试绝对值函数
    printf("1. 绝对值函数测试:\n");
    printf("   abs_int(-10) = %d\n", abs_int(-10));
    printf("   abs_double(-3.14) = %.2f\n\n", abs_double(-3.14));
    
    // 测试最大/最小值函数
    printf("2. 最大/最小值函数测试:\n");
    printf("   max_int(5, 10) = %d\n", max_int(5, 10));
    printf("   max_double(2.5, 3.14) = %.2f\n", max_double(2.5, 3.14));
    printf("   min_int(5, 10) = %d\n", min_int(5, 10));
    printf("   min_double(2.5, 3.14) = %.2f\n\n", min_double(2.5, 3.14));
    
    // 测试幂函数
    printf("3. 幂函数测试:\n");
    printf("   power(2, 3) = %.0f\n", power(2, 3));
    printf("   power(2, -2) = %.2f\n", power(2, -2));
    printf("   power(10, 6) = %.0f\n\n", power(10, 6));
    
    // 测试平方根和立方根函数
    printf("4. 平方根和立方根函数测试:\n");
    printf("   sqrt(16) = %.0f\n", sqrt(16));
    printf("   sqrt(2) = %.6f\n", sqrt(2));
    printf("   cbrt(8) = %.0f\n", cbrt(8));
    printf("   cbrt(-27) = %.0f\n\n", cbrt(-27));
    
    // 测试取整函数
    printf("5. 取整函数测试:\n");
    printf("   custom_round(3.14) = %d\n", custom_round(3.14));
    printf("   custom_round(3.7) = %d\n", custom_round(3.7));
    printf("   custom_ceil(3.14) = %d\n", custom_ceil(3.14));
    printf("   custom_floor(3.9) = %d\n\n", custom_floor(3.9));
    
    // 测试素数判断函数
    printf("6. 素数判断函数测试:\n");
    printf("   is_prime(2) = %s\n", is_prime(2) ? "是素数" : "不是素数");
    printf("   is_prime(97) = %s\n", is_prime(97) ? "是素数" : "不是素数");
    printf("   is_prime(100) = %s\n\n", is_prime(100) ? "是素数" : "不是素数");
    
    // 测试最大公约数和最小公倍数函数
    printf("7. 最大公约数和最小公倍数函数测试:\n");
    printf("   gcd(48, 36) = %d\n", gcd(48, 36));
    printf("   gcd(7, 13) = %d\n", gcd(7, 13));
    printf("   lcm(48, 36) = %d\n", lcm(48, 36));
    printf("   lcm(7, 13) = %d\n\n", lcm(7, 13));
    
    // 测试正弦函数
    printf("8. 正弦函数测试:\n");
    double angles[] = {0.0, 1.5708, 3.1416, 4.7124, 6.2832, 1.0, -1.0}; // 0, π/2, π, 3π/2, 2π 以及其他值
    int num_angles = sizeof(angles) / sizeof(angles[0]);
    
    printf("   角度值\t我们的sin\t\tlibc的sin\t\t差值\n");
    printf("   ----------------------------------------\n");
    for (int i = 0; i < num_angles; i++) {
        double angle = angles[i];
        double result = custom_sin(angle);             // 我们实现的sin函数
        double libc_result = libc_sin(angle);      // libc的sin函数
        double diff = fabs(result - libc_result);  // 计算差值
        
        printf("   %.4f\t%.10f\t%.10f\t%.10f\n", 
               angle, result, libc_result, diff);
    }
    printf("\n");
    
    // 测试余弦函数
    printf("9. 余弦函数测试:\n");
    printf("   角度值\t我们的cos\t\tlibc的cos\t\t差值\n");
    printf("   ----------------------------------------\n");
    for (int i = 0; i < num_angles; i++) {
        double angle = angles[i];
        double result = custom_cos(angle);             // 我们实现的cos函数
        double libc_result = libc_cos(angle);      // libc的cos函数
        double diff = fabs(result - libc_result);  // 计算差值
        
        printf("   %.4f\t%.10f\t%.10f\t%.10f\n", 
               angle, result, libc_result, diff);
    }
    printf("\n");
    
    printf("10. 性能测试（10000000次调用）:\n");
    printf("    ----------------------------------------\n");
    printf("    函数        | 我们的实现 (ms) | libc实现 (ms) | 性能比(libc/我们)\n");
    printf("    ----------------------------------------\n");
    
    // 性能测试：比较我们实现的sin函数与libc版本的执行时间
    const int ITERATIONS = 10000000;  // 迭代次数
    double test_angle = 1.2345;  // 测试角度
    clock_t start, end;
    double our_time, libc_time;
    double result;  // 用于存储计算结果
    
    // 测试我们的sin函数
    start = clock();
    double total_sin = 0.0; // 用于累加结果，避免未使用变量警告
    for (int i = 0; i < ITERATIONS; i++) {
        result = custom_sin(test_angle);
        total_sin += result; // 使用result变量
    }
    end = clock();
    our_time = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    
    // 测试libc的sin函数
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = libc_sin(test_angle);
    }
    end = clock();
    libc_time = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    
    printf("    sin函数    | %.3f         | %.3f        | %.2f\n", 
           our_time, libc_time, our_time / libc_time);
    
    // 测试我们的cos函数
    start = clock();
    double total_cos = 0.0; // 用于累加结果，避免未使用变量警告
    for (int i = 0; i < ITERATIONS; i++) {
        result = custom_cos(test_angle);
        total_cos += result; // 使用result变量
    }
    end = clock();
    our_time = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    
    // 测试libc的cos函数
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = libc_cos(test_angle);
    }
    end = clock();
    libc_time = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    
    printf("    cos函数    | %.3f         | %.3f        | %.2f\n", 
           our_time, libc_time, our_time / libc_time);
    printf("    ----------------------------------------\n");
    printf("    注意：数值小于1表示我们的实现更快，大于1表示libc更快\n");
    
    // 给libc的其他三角函数起别名
    #define libc_tan tan
    #define libc_asin asin
    #define libc_acos acos
    #define libc_atan atan
    
    // 取消对libc其他三角函数的直接使用
    #undef tan
    #undef asin
    #undef acos
    #undef atan
    
    // 包含算法库中的PI常量定义
    #ifndef PI
    #define PI 3.14159265358979323846
    #endif
    
    // 测试其他三角函数
    printf("\n11. 其他三角函数测试:\n");
    printf("    --------------------------------------------------\n");
    printf("    函数        | 输入值       | 我们的实现    | libc实现      | 差值\n");
    printf("    --------------------------------------------------\n");
    
    // 测试tan函数
    double tan_angles[] = {0.0, PI/6, PI/4, PI/3, PI/2-0.1, -PI/4};
    int tan_count = sizeof(tan_angles)/sizeof(tan_angles[0]);
    
    for (int i = 0; i < tan_count; i++) {
        double angle = tan_angles[i];
        double custom = custom_tan(angle);
        double libc_val = libc_tan(angle);
        double diff = fabs(custom - libc_val);
        printf("    tan函数    | %.4f     | %.10f | %.10f | %.10f\n", 
               angle, custom, libc_val, diff);
    }
    
    // 测试asin函数
    double asin_values[] = {-1.0, -0.75, -0.5, 0.0, 0.5, 0.75, 1.0};
    int asin_count = sizeof(asin_values)/sizeof(asin_values[0]);
    
    for (int i = 0; i < asin_count; i++) {
        double val = asin_values[i];
        double custom = custom_asin(val);
        double libc_val = libc_asin(val);
        double diff = fabs(custom - libc_val);
        printf("    asin函数   | %.4f     | %.10f | %.10f | %.10f\n", 
               val, custom, libc_val, diff);
    }
    
    // 测试acos函数
    double acos_values[] = {-1.0, -0.75, -0.5, 0.0, 0.5, 0.75, 1.0};
    int acos_count = sizeof(acos_values)/sizeof(acos_values[0]);
    
    for (int i = 0; i < acos_count; i++) {
        double val = acos_values[i];
        double custom = custom_acos(val);
        double libc_val = libc_acos(val);
        double diff = fabs(custom - libc_val);
        printf("    acos函数   | %.4f     | %.10f | %.10f | %.10f\n", 
               val, custom, libc_val, diff);
    }
    
    // 测试atan函数
    double atan_values[] = {-10.0, -1.0, -0.5, 0.0, 0.5, 1.0, 10.0};
    int atan_count = sizeof(atan_values)/sizeof(atan_values[0]);
    
    for (int i = 0; i < atan_count; i++) {
        double val = atan_values[i];
        double custom = custom_atan(val);
        double libc_val = libc_atan(val);
        double diff = fabs(custom - libc_val);
        printf("    atan函数   | %.4f     | %.10f | %.10f | %.10f\n", 
               val, custom, libc_val, diff);
    }
    
    printf("    --------------------------------------------------\n");
    
    printf("\n===== 示例程序结束 =====\n");
    
    return 0;
}