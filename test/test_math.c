/*
 * 数学库测试程序
 * 验证数学库中所有函数的正确性
 */
#include <stdio.h>
#include <stdbool.h>
#include "algorithm_lib.h"

// 测试结果统计
int total_tests = 0;
int passed_tests = 0;

// 测试宏定义
#define TEST(func, expected, ...) \
    do { \
        total_tests++; \
        bool result = (func(__VA_ARGS__) == expected); \
        if (result) { \
            passed_tests++; \
            printf("[PASS] %s\n", #func); \
        } else { \
            printf("[FAIL] %s: expected %d, got %d\n", #func, expected, func(__VA_ARGS__)); \
        } \
    } while(0)

#define TEST_DOUBLE(func, expected, tolerance, ...) \
    do { \
        total_tests++; \
        double result = func(__VA_ARGS__); \
        bool passed = (abs_double(result - expected) <= tolerance); \
        if (passed) { \
            passed_tests++; \
            printf("[PASS] %s\n", #func); \
        } else { \
            printf("[FAIL] %s: expected %.6f, got %.6f\n", #func, expected, result); \
        } \
    } while(0)

#define TEST_BOOL(func, expected, ...) \
    do { \
        total_tests++; \
        int result = func(__VA_ARGS__); \
        bool passed = (result == expected); \
        if (passed) { \
            passed_tests++; \
            printf("[PASS] %s\n", #func); \
        } else { \
            printf("[FAIL] %s: expected %d, got %d\n", #func, expected, result); \
        } \
    } while(0)

int main() {
    printf("===== 数学库测试程序 =====\n\n");
    
    // 测试绝对值函数
    printf("测试绝对值函数:\n");
    TEST(abs_int, 10, -10);
    TEST(abs_int, 5, 5);
    TEST(abs_int, 0, 0);
    TEST_DOUBLE(abs_double, 3.14, 0.000001, -3.14);
    TEST_DOUBLE(abs_double, 2.5, 0.000001, 2.5);
    TEST_DOUBLE(abs_double, 0.0, 0.000001, 0.0);
    printf("\n");
    
    // 测试最大/最小值函数
    printf("测试最大/最小值函数:\n");
    TEST(max_int, 10, 5, 10);
    TEST(max_int, 5, 5, 3);
    TEST_DOUBLE(max_double, 3.14, 0.000001, 2.5, 3.14);
    TEST_DOUBLE(max_double, 2.5, 0.000001, 2.5, 1.5);
    TEST(min_int, 5, 5, 10);
    TEST(min_int, 3, 5, 3);
    TEST_DOUBLE(min_double, 2.5, 0.000001, 2.5, 3.14);
    TEST_DOUBLE(min_double, 1.5, 0.000001, 2.5, 1.5);
    printf("\n");
    
    // 测试幂函数
    printf("测试幂函数:\n");
    TEST_DOUBLE(power, 8.0, 0.000001, 2, 3);
    TEST_DOUBLE(power, 0.25, 0.000001, 2, -2);
    TEST_DOUBLE(power, 1.0, 0.000001, 5, 0);
    TEST_DOUBLE(power, 1000000.0, 0.000001, 10, 6);
    printf("\n");
    
    // 测试平方根和立方根函数
    printf("测试平方根和立方根函数:\n");
    TEST_DOUBLE(sqrt, 4.0, 0.000001, 16);
    TEST_DOUBLE(sqrt, 1.414214, 0.000001, 2);
    TEST_DOUBLE(sqrt, 0.0, 0.000001, 0);
    TEST_DOUBLE(cbrt, 2.0, 0.000001, 8);
    TEST_DOUBLE(cbrt, -3.0, 0.000001, -27);
    TEST_DOUBLE(cbrt, 0.0, 0.000001, 0);
    printf("\n");
    
    // 测试取整函数
    printf("测试取整函数:\n");
    TEST(round_double, 3, 3.14);
    TEST(round_double, 4, 3.7);
    TEST(round_double, -3, -3.14);
    TEST(round_double, -4, -3.7);
    TEST(ceil_double, 4, 3.14);
    TEST(ceil_double, 4, 3.9);
    TEST(ceil_double, -3, -3.14);
    TEST(floor_double, 3, 3.9);
    TEST(floor_double, -4, -3.14);
    printf("\n");
    
    // 测试素数判断函数
    printf("测试素数判断函数:\n");
    TEST_BOOL(is_prime, 1, 2);
    TEST_BOOL(is_prime, 1, 3);
    TEST_BOOL(is_prime, 1, 5);
    TEST_BOOL(is_prime, 1, 7);
    TEST_BOOL(is_prime, 1, 11);
    TEST_BOOL(is_prime, 1, 13);
    TEST_BOOL(is_prime, 1, 17);
    TEST_BOOL(is_prime, 1, 19);
    TEST_BOOL(is_prime, 1, 23);
    TEST_BOOL(is_prime, 1, 29);
    TEST_BOOL(is_prime, 1, 31);
    TEST_BOOL(is_prime, 1, 37);
    TEST_BOOL(is_prime, 1, 41);
    TEST_BOOL(is_prime, 1, 43);
    TEST_BOOL(is_prime, 1, 47);
    TEST_BOOL(is_prime, 0, 1);
    TEST_BOOL(is_prime, 0, 4);
    TEST_BOOL(is_prime, 0, 6);
    TEST_BOOL(is_prime, 0, 8);
    TEST_BOOL(is_prime, 0, 9);
    TEST_BOOL(is_prime, 0, 10);
    TEST_BOOL(is_prime, 0, 100);
    TEST_BOOL(is_prime, 0, -5);
    printf("\n");
    
    // 测试最大公约数和最小公倍数函数
    printf("测试最大公约数和最小公倍数函数:\n");
    TEST(gcd, 12, 48, 36);
    TEST(gcd, 1, 7, 13);
    TEST(gcd, 5, 15, 25);
    TEST(gcd, 10, 30, 40);
    TEST(gcd, 1, 1, 1);
    TEST(gcd, 5, -15, 25);
    TEST(lcm, 144, 48, 36);
    TEST(lcm, 91, 7, 13);
    TEST(lcm, 75, 15, 25);
    TEST(lcm, 120, 30, 40);
    TEST(lcm, 1, 1, 1);
    TEST(lcm, 75, -15, 25);
    TEST(lcm, 0, 0, 5);
    printf("\n");
    
    // 测试向量运算函数
    printf("测试向量运算函数:\n");
    
    // 2D向量测试数据
    double vec2d_1[2] = {3.0, 4.0};
    double vec2d_2[2] = {1.0, 2.0};
    double vec2d_zero[2] = {0.0, 0.0};
    double vec2d_result[2];
    
    // 3D向量测试数据
    double vec3d_1[3] = {1.0, 2.0, 3.0};
    double vec3d_2[3] = {4.0, 5.0, 6.0};
    double vec3d_zero[3] = {0.0, 0.0, 0.0};
    double vec3d_result[3];
    
    // 测试2D点积
    TEST_DOUBLE(custom_vector2d_dot, 11.0, 0.000001, vec2d_1, vec2d_2);
    TEST_DOUBLE(custom_vector2d_dot, 0.0, 0.000001, vec2d_1, vec2d_zero);
    
    // 测试3D点积
    TEST_DOUBLE(custom_vector3d_dot, 32.0, 0.000001, vec3d_1, vec3d_2);
    TEST_DOUBLE(custom_vector3d_dot, 0.0, 0.000001, vec3d_1, vec3d_zero);
    
    // 测试3D叉积
    custom_vector3d_cross(vec3d_1, vec3d_2, vec3d_result);
    TEST_DOUBLE(abs_double, -3.0, 0.000001, vec3d_result[0]);
    TEST_DOUBLE(abs_double, 6.0, 0.000001, vec3d_result[1]);
    TEST_DOUBLE(abs_double, -3.0, 0.000001, vec3d_result[2]);
    
    // 测试向量长度
    TEST_DOUBLE(custom_vector2d_length, 5.0, 0.000001, vec2d_1);
    TEST_DOUBLE(custom_vector2d_length, 0.0, 0.000001, vec2d_zero);
    TEST_DOUBLE(custom_vector3d_length, sqrt(14.0), 0.000001, vec3d_1);
    TEST_DOUBLE(custom_vector3d_length, 0.0, 0.000001, vec3d_zero);
    
    // 测试向量归一化
    TEST_BOOL(custom_vector2d_normalize, 1, vec2d_1, vec2d_result);
    TEST_DOUBLE(custom_vector2d_length, 1.0, 0.000001, vec2d_result);
    TEST_BOOL(custom_vector2d_normalize, 0, vec2d_zero, vec2d_result);
    
    TEST_BOOL(custom_vector3d_normalize, 1, vec3d_1, vec3d_result);
    TEST_DOUBLE(custom_vector3d_length, 1.0, 0.000001, vec3d_result);
    TEST_BOOL(custom_vector3d_normalize, 0, vec3d_zero, vec3d_result);
    
    // 测试向量加法
    custom_vector2d_add(vec2d_1, vec2d_2, vec2d_result);
    TEST_DOUBLE(abs_double, 4.0, 0.000001, vec2d_result[0]);
    TEST_DOUBLE(abs_double, 6.0, 0.000001, vec2d_result[1]);
    
    custom_vector3d_add(vec3d_1, vec3d_2, vec3d_result);
    TEST_DOUBLE(abs_double, 5.0, 0.000001, vec3d_result[0]);
    TEST_DOUBLE(abs_double, 7.0, 0.000001, vec3d_result[1]);
    TEST_DOUBLE(abs_double, 9.0, 0.000001, vec3d_result[2]);
    
    // 测试向量减法
    custom_vector2d_subtract(vec2d_1, vec2d_2, vec2d_result);
    TEST_DOUBLE(abs_double, 2.0, 0.000001, vec2d_result[0]);
    TEST_DOUBLE(abs_double, 2.0, 0.000001, vec2d_result[1]);
    
    custom_vector3d_subtract(vec3d_1, vec3d_2, vec3d_result);
    TEST_DOUBLE(abs_double, -3.0, 0.000001, vec3d_result[0]);
    TEST_DOUBLE(abs_double, -3.0, 0.000001, vec3d_result[1]);
    TEST_DOUBLE(abs_double, -3.0, 0.000001, vec3d_result[2]);
    
    // 测试向量缩放
    custom_vector2d_scale(vec2d_1, 2.0, vec2d_result);
    TEST_DOUBLE(abs_double, 6.0, 0.000001, vec2d_result[0]);
    TEST_DOUBLE(abs_double, 8.0, 0.000001, vec2d_result[1]);
    
    custom_vector3d_scale(vec3d_1, 0.5, vec3d_result);
    TEST_DOUBLE(abs_double, 0.5, 0.000001, vec3d_result[0]);
    TEST_DOUBLE(abs_double, 1.0, 0.000001, vec3d_result[1]);
    TEST_DOUBLE(abs_double, 1.5, 0.000001, vec3d_result[2]);
    
    // 测试向量夹角
    double angle_2d = custom_vector2d_angle(vec2d_1, vec2d_2);
    double expected_2d = acos(11.0 / (5.0 * sqrt(5.0)));
    TEST_DOUBLE(abs_double, expected_2d, 0.000001, angle_2d);
    
    double angle_3d = custom_vector3d_angle(vec3d_1, vec3d_2);
    double expected_3d = acos(32.0 / (sqrt(14.0) * sqrt(77.0)));
    TEST_DOUBLE(abs_double, expected_3d, 0.000001, angle_3d);
    
    // 测试向量投影
    TEST_BOOL(custom_vector2d_project, 1, vec2d_1, vec2d_2, vec2d_result);
    double expected_proj_2d_x = 11.0 * 1.0 / 5.0;
    double expected_proj_2d_y = 11.0 * 2.0 / 5.0;
    TEST_DOUBLE(abs_double, expected_proj_2d_x, 0.000001, vec2d_result[0]);
    TEST_DOUBLE(abs_double, expected_proj_2d_y, 0.000001, vec2d_result[1]);
    
    TEST_BOOL(custom_vector2d_project, 0, vec2d_1, vec2d_zero, vec2d_result);
    
    TEST_BOOL(custom_vector3d_project, 1, vec3d_1, vec3d_2, vec3d_result);
    double expected_proj_3d_x = 32.0 * 4.0 / 77.0;
    double expected_proj_3d_y = 32.0 * 5.0 / 77.0;
    double expected_proj_3d_z = 32.0 * 6.0 / 77.0;
    TEST_DOUBLE(abs_double, expected_proj_3d_x, 0.000001, vec3d_result[0]);
    TEST_DOUBLE(abs_double, expected_proj_3d_y, 0.000001, vec3d_result[1]);
    TEST_DOUBLE(abs_double, expected_proj_3d_z, 0.000001, vec3d_result[2]);
    
    TEST_BOOL(custom_vector3d_project, 0, vec3d_1, vec3d_zero, vec3d_result);
    
    printf("\n");
    
    // 输出测试结果
    printf("===== 测试结果汇总 =====\n");
    printf("总测试数: %d\n", total_tests);
    printf("通过测试数: %d\n", passed_tests);
    printf("失败测试数: %d\n", total_tests - passed_tests);
    printf("通过率: %.2f%%\n", (float)passed_tests / total_tests * 100);
    
    return (total_tests == passed_tests) ? 0 : 1;
}