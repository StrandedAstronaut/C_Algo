/**
 * C�����㷨�� - �ۺ�ʾ������
 * չʾ���ʹ���㷨���еĶ����㷨�������˲�������
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algorithm_lib.h"

// ��ӡ��������
void print_int_array(int arr[], int n, const char* label) {
    printf("%s: ", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ��ӡ����������
void print_double_array(double arr[], int n, const char* label) {
    printf("%s: ", label);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("===== C�����㷨�� - �ۺ�ʾ������ =====\n\n");
    
    // ==========================
    // 1. �����㷨ʾ�� - ð������
    // ==========================
    printf("1. ð������ʾ��:\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    print_int_array(arr, n, "����ǰ");
    bubble_sort(arr, n);
    print_int_array(arr, n, "�����");
    printf("\n");
    
    // ==========================
    // 2. �����㷨ʾ�� - ���ֲ���
    // ==========================
    printf("2. ���ֲ���ʾ��:\n");
    int sorted_arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int sorted_n = sizeof(sorted_arr) / sizeof(sorted_arr[0]);
    int target = 25;
    
    print_int_array(sorted_arr, sorted_n, "��������");
    int index = binary_search(sorted_arr, sorted_n, target);
    
    if (index != -1) {
        printf("����ֵ %d: ������ %d ���ҵ�\n", target, index);
    } else {
        printf("����ֵ %d: δ�ҵ�\n", target);
    }
    
    target = 22;  // ���������е�ֵ
    index = binary_search(sorted_arr, sorted_n, target);
    if (index != -1) {
        printf("����ֵ %d: ������ %d ���ҵ�\n", target, index);
    } else {
        printf("����ֵ %d: δ�ҵ�\n", target);
    }
    printf("\n");
    
    // ==========================
    // 3. �˲��㷨ʾ�� - ��ֵ�˲�
    // ==========================
    printf("3. ��ֵ�˲�ʾ��:\n");
    // ����һ�����������ź�
    double noisy_signal[20];
    double filtered_signal[20];
    
    // ����һ��ƽ�������Ҳ������������
    srand(time(NULL));  // ��ʼ�������������
    printf("ԭʼ�ź�: ");
    for (int i = 0; i < 20; i++) {
        // ����0-10�����Ҳ�ֵ������-1��1֮����������
        noisy_signal[i] = 5 * (1 + sin(i * 0.5)) + ((double)rand() / RAND_MAX) * 2 - 1;
        printf("%.2f ", noisy_signal[i]);
    }
    printf("\n");
    
    // Ӧ�þ�ֵ�˲������ڴ�СΪ3
    int window_size = 3;
    mean_filter_1d(noisy_signal, filtered_signal, 20, window_size);
    
    printf("�˲����ź� (���ڴ�С=%d): ", window_size);
    for (int i = 0; i < 20; i++) {
        printf("%.2f ", filtered_signal[i]);
    }
    printf("\n");
    
    // ==========================
    // 4. ��ѧ�⺯��ʾ��
    // ==========================
    printf("\n4. ��ѧ�⺯��ʾ��:\n");
    printf("����ֵ: abs_int(-10) = %d\n", abs_int(-10));
    printf("���ֵ: max_int(5, 10) = %d\n", max_int(5, 10));
    printf("ƽ����: sqrt(16) = %.2f\n", sqrt(16));
    printf("������: power(2, 3) = %.2f\n", power(2, 3));
    printf("�����ж�: is_prime(97) = %s\n", is_prime(97) ? "������" : "��������");
    printf("���Լ��: gcd(48, 36) = %d\n", gcd(48, 36));
    printf("��С������: lcm(48, 36) = %d\n", lcm(48, 36));
    
    printf("\n===== ʾ��������� =====\n");
    return 0;
}