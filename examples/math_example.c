/*
 * 数学库示例程序
 * 展示如何使用数学库中的各种函数
 */
#include <stdio.h>
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
    printf("   round_double(3.14) = %d\n", round_double(3.14));
    printf("   round_double(3.7) = %d\n", round_double(3.7));
    printf("   ceil_double(3.14) = %d\n", ceil_double(3.14));
    printf("   floor_double(3.9) = %d\n\n", floor_double(3.9));
    
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
    
    printf("===== 示例程序结束 =====\n");
    
    return 0;
}