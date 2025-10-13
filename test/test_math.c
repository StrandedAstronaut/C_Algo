/*
 * ��ѧ����Գ���
 * ��֤��ѧ�������к�������ȷ��
 */
#include <stdio.h>
#include <stdbool.h>
#include "algorithm_lib.h"

// ���Խ��ͳ��
int total_tests = 0;
int passed_tests = 0;

// ���Ժ궨��
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
    printf("===== ��ѧ����Գ��� =====\n\n");
    
    // ���Ծ���ֵ����
    printf("���Ծ���ֵ����:\n");
    TEST(abs_int, 10, -10);
    TEST(abs_int, 5, 5);
    TEST(abs_int, 0, 0);
    TEST_DOUBLE(abs_double, 3.14, 0.000001, -3.14);
    TEST_DOUBLE(abs_double, 2.5, 0.000001, 2.5);
    TEST_DOUBLE(abs_double, 0.0, 0.000001, 0.0);
    printf("\n");
    
    // �������/��Сֵ����
    printf("�������/��Сֵ����:\n");
    TEST(max_int, 10, 5, 10);
    TEST(max_int, 5, 5, 3);
    TEST_DOUBLE(max_double, 3.14, 0.000001, 2.5, 3.14);
    TEST_DOUBLE(max_double, 2.5, 0.000001, 2.5, 1.5);
    TEST(min_int, 5, 5, 10);
    TEST(min_int, 3, 5, 3);
    TEST_DOUBLE(min_double, 2.5, 0.000001, 2.5, 3.14);
    TEST_DOUBLE(min_double, 1.5, 0.000001, 2.5, 1.5);
    printf("\n");
    
    // �����ݺ���
    printf("�����ݺ���:\n");
    TEST_DOUBLE(power, 8.0, 0.000001, 2, 3);
    TEST_DOUBLE(power, 0.25, 0.000001, 2, -2);
    TEST_DOUBLE(power, 1.0, 0.000001, 5, 0);
    TEST_DOUBLE(power, 1000000.0, 0.000001, 10, 6);
    printf("\n");
    
    // ����ƽ����������������
    printf("����ƽ����������������:\n");
    TEST_DOUBLE(sqrt, 4.0, 0.000001, 16);
    TEST_DOUBLE(sqrt, 1.414214, 0.000001, 2);
    TEST_DOUBLE(sqrt, 0.0, 0.000001, 0);
    TEST_DOUBLE(cbrt, 2.0, 0.000001, 8);
    TEST_DOUBLE(cbrt, -3.0, 0.000001, -27);
    TEST_DOUBLE(cbrt, 0.0, 0.000001, 0);
    printf("\n");
    
    // ����ȡ������
    printf("����ȡ������:\n");
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
    
    // ���������жϺ���
    printf("���������жϺ���:\n");
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
    
    // �������Լ������С����������
    printf("�������Լ������С����������:\n");
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
    
    // ������Խ��
    printf("===== ���Խ������ =====\n");
    printf("�ܲ�����: %d\n", total_tests);
    printf("ͨ��������: %d\n", passed_tests);
    printf("ʧ�ܲ�����: %d\n", total_tests - passed_tests);
    printf("ͨ����: %.2f%%\n", (float)passed_tests / total_tests * 100);
    
    return (total_tests == passed_tests) ? 0 : 1;
}