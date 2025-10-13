/*
 * ��ѧ��ʾ������
 * չʾ���ʹ����ѧ���еĸ��ֺ���
 */
#include <stdio.h>
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
    printf("   round_double(3.14) = %d\n", round_double(3.14));
    printf("   round_double(3.7) = %d\n", round_double(3.7));
    printf("   ceil_double(3.14) = %d\n", ceil_double(3.14));
    printf("   floor_double(3.9) = %d\n\n", floor_double(3.9));
    
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
    
    printf("===== ʾ��������� =====\n");
    
    return 0;
}