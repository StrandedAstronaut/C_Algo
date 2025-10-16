/*
 * ��ѧ��ʾ������
 * չʾ���ʹ����ѧ���еĸ��ֺ���
 */
#include <stdio.h>
#include <time.h>  // ���ڼ�ʱ����
#include <math.h>  // �Ȱ���libc��math.h

// ��libc��sin��cos���������
#define libc_sin sin
#define libc_cos cos

// ȡ����libc sin��cos��ֱ��ʹ�ã������������Լ���ʵ�ֳ�ͻ
#undef sin
#undef cos

// Ȼ��������ǵ�algorithm_lib.h�������������ʵ�ֵ�sin��cos����
#include "algorithm_lib.h"

int main() {
    printf("===== C�����㷨�� - ��ѧ����ʾ�� =====\n\n");
    
    // ���Ծ���ֵ����
    printf("1. ����ֵ��������:\n");
    printf("   abs_int(-10) = %d\n", abs_int(-10));
    printf("   abs_double(-3.14) = %.2f\n\n", abs_double(-3.14));
    
    // �������/��Сֵ����
    printf("2. ���/��Сֵ��������:\n");
    printf("   max_int(5, 10) = %d\n", max_int(5, 10));
    printf("   max_double(2.5, 3.14) = %.2f\n", max_double(2.5, 3.14));
    printf("   min_int(5, 10) = %d\n", min_int(5, 10));
    printf("   min_double(2.5, 3.14) = %.2f\n\n", min_double(2.5, 3.14));
    
    // �����ݺ���
    printf("3. �ݺ�������:\n");
    printf("   power(2, 3) = %.0f\n", power(2, 3));
    printf("   power(2, -2) = %.2f\n", power(2, -2));
    printf("   power(10, 6) = %.0f\n\n", power(10, 6));
    
    // ����ƽ����������������
    printf("4. ƽ��������������������:\n");
    printf("   sqrt(16) = %.0f\n", sqrt(16));
    printf("   sqrt(2) = %.6f\n", sqrt(2));
    printf("   cbrt(8) = %.0f\n", cbrt(8));
    printf("   cbrt(-27) = %.0f\n\n", cbrt(-27));
    
    // ����ȡ������
    printf("5. ȡ����������:\n");
    printf("   custom_round(3.14) = %d\n", custom_round(3.14));
    printf("   custom_round(3.7) = %d\n", custom_round(3.7));
    printf("   custom_ceil(3.14) = %d\n", custom_ceil(3.14));
    printf("   custom_floor(3.9) = %d\n\n", custom_floor(3.9));
    
    // ���������жϺ���
    printf("6. �����жϺ�������:\n");
    printf("   is_prime(2) = %s\n", is_prime(2) ? "������" : "��������");
    printf("   is_prime(97) = %s\n", is_prime(97) ? "������" : "��������");
    printf("   is_prime(100) = %s\n\n", is_prime(100) ? "������" : "��������");
    
    // �������Լ������С����������
    printf("7. ���Լ������С��������������:\n");
    printf("   gcd(48, 36) = %d\n", gcd(48, 36));
    printf("   gcd(7, 13) = %d\n", gcd(7, 13));
    printf("   lcm(48, 36) = %d\n", lcm(48, 36));
    printf("   lcm(7, 13) = %d\n\n", lcm(7, 13));
    
    // �������Һ���
    printf("8. ���Һ�������:\n");
    double angles[] = {0.0, 1.5708, 3.1416, 4.7124, 6.2832, 1.0, -1.0}; // 0, ��/2, ��, 3��/2, 2�� �Լ�����ֵ
    int num_angles = sizeof(angles) / sizeof(angles[0]);
    
    printf("   �Ƕ�ֵ\t���ǵ�sin\t\tlibc��sin\t\t��ֵ\n");
    printf("   ----------------------------------------\n");
    for (int i = 0; i < num_angles; i++) {
        double angle = angles[i];
        double result = custom_sin(angle);             // ����ʵ�ֵ�sin����
        double libc_result = libc_sin(angle);      // libc��sin����
        double diff = fabs(result - libc_result);  // �����ֵ
        
        printf("   %.4f\t%.10f\t%.10f\t%.10f\n", 
               angle, result, libc_result, diff);
    }
    printf("\n");
    
    // �������Һ���
    printf("9. ���Һ�������:\n");
    printf("   �Ƕ�ֵ\t���ǵ�cos\t\tlibc��cos\t\t��ֵ\n");
    printf("   ----------------------------------------\n");
    for (int i = 0; i < num_angles; i++) {
        double angle = angles[i];
        double result = custom_cos(angle);             // ����ʵ�ֵ�cos����
        double libc_result = libc_cos(angle);      // libc��cos����
        double diff = fabs(result - libc_result);  // �����ֵ
        
        printf("   %.4f\t%.10f\t%.10f\t%.10f\n", 
               angle, result, libc_result, diff);
    }
    printf("\n");
    
    printf("10. ���ܲ��ԣ�10000000�ε��ã�:\n");
    printf("    ----------------------------------------\n");
    printf("    ����        | ���ǵ�ʵ�� (ms) | libcʵ�� (ms) | ���ܱ�(libc/����)\n");
    printf("    ----------------------------------------\n");
    
    // ���ܲ��ԣ��Ƚ�����ʵ�ֵ�sin������libc�汾��ִ��ʱ��
    const int ITERATIONS = 10000000;  // ��������
    double test_angle = 1.2345;  // ���ԽǶ�
    clock_t start, end;
    double our_time, libc_time;
    double result;  // ���ڴ洢������
    
    // �������ǵ�sin����
    start = clock();
    double total_sin = 0.0; // �����ۼӽ��������δʹ�ñ�������
    for (int i = 0; i < ITERATIONS; i++) {
        result = custom_sin(test_angle);
        total_sin += result; // ʹ��result����
    }
    end = clock();
    our_time = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    
    // ����libc��sin����
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = libc_sin(test_angle);
    }
    end = clock();
    libc_time = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    
    printf("    sin����    | %.3f         | %.3f        | %.2f\n", 
           our_time, libc_time, our_time / libc_time);
    
    // �������ǵ�cos����
    start = clock();
    double total_cos = 0.0; // �����ۼӽ��������δʹ�ñ�������
    for (int i = 0; i < ITERATIONS; i++) {
        result = custom_cos(test_angle);
        total_cos += result; // ʹ��result����
    }
    end = clock();
    our_time = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    
    // ����libc��cos����
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = libc_cos(test_angle);
    }
    end = clock();
    libc_time = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    
    printf("    cos����    | %.3f         | %.3f        | %.2f\n", 
           our_time, libc_time, our_time / libc_time);
    printf("    ----------------------------------------\n");
    printf("    ע�⣺��ֵС��1��ʾ���ǵ�ʵ�ָ��죬����1��ʾlibc����\n");
    
    // ��libc���������Ǻ��������
    #define libc_tan tan
    #define libc_asin asin
    #define libc_acos acos
    #define libc_atan atan
    
    // ȡ����libc�������Ǻ�����ֱ��ʹ��
    #undef tan
    #undef asin
    #undef acos
    #undef atan
    
    // �����㷨���е�PI��������
    #ifndef PI
    #define PI 3.14159265358979323846
    #endif
    
    // �����������Ǻ���
    printf("\n11. �������Ǻ�������:\n");
    printf("    --------------------------------------------------\n");
    printf("    ����        | ����ֵ       | ���ǵ�ʵ��    | libcʵ��      | ��ֵ\n");
    printf("    --------------------------------------------------\n");
    
    // ����tan����
    double tan_angles[] = {0.0, PI/6, PI/4, PI/3, PI/2-0.1, -PI/4};
    int tan_count = sizeof(tan_angles)/sizeof(tan_angles[0]);
    
    for (int i = 0; i < tan_count; i++) {
        double angle = tan_angles[i];
        double custom = custom_tan(angle);
        double libc_val = libc_tan(angle);
        double diff = fabs(custom - libc_val);
        printf("    tan����    | %.4f     | %.10f | %.10f | %.10f\n", 
               angle, custom, libc_val, diff);
    }
    
    // ����asin����
    double asin_values[] = {-1.0, -0.75, -0.5, 0.0, 0.5, 0.75, 1.0};
    int asin_count = sizeof(asin_values)/sizeof(asin_values[0]);
    
    for (int i = 0; i < asin_count; i++) {
        double val = asin_values[i];
        double custom = custom_asin(val);
        double libc_val = libc_asin(val);
        double diff = fabs(custom - libc_val);
        printf("    asin����   | %.4f     | %.10f | %.10f | %.10f\n", 
               val, custom, libc_val, diff);
    }
    
    // ����acos����
    double acos_values[] = {-1.0, -0.75, -0.5, 0.0, 0.5, 0.75, 1.0};
    int acos_count = sizeof(acos_values)/sizeof(acos_values[0]);
    
    for (int i = 0; i < acos_count; i++) {
        double val = acos_values[i];
        double custom = custom_acos(val);
        double libc_val = libc_acos(val);
        double diff = fabs(custom - libc_val);
        printf("    acos����   | %.4f     | %.10f | %.10f | %.10f\n", 
               val, custom, libc_val, diff);
    }
    
    // ����atan����
    double atan_values[] = {-10.0, -1.0, -0.5, 0.0, 0.5, 1.0, 10.0};
    int atan_count = sizeof(atan_values)/sizeof(atan_values[0]);
    
    for (int i = 0; i < atan_count; i++) {
        double val = atan_values[i];
        double custom = custom_atan(val);
        double libc_val = libc_atan(val);
        double diff = fabs(custom - libc_val);
        printf("    atan����   | %.4f     | %.10f | %.10f | %.10f\n", 
               val, custom, libc_val, diff);
    }
    
    printf("    --------------------------------------------------\n");
    
    printf("\n===== ʾ��������� =====\n");
    
    return 0;
}